/*!
 * \file      main.c
 *
 * \brief     Ping-Pong implementation
 *
 * \copyright Revised BSD License, see section \ref LICENSE.
 *
 * \code
 *                ______                              _
 *               / _____)             _              | |
 *              ( (____  _____ ____ _| |_ _____  ____| |__
 *               \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 *               _____) ) ____| | | || |_| ____( (___| | | |
 *              (______/|_____)_|_|_| \__)_____)\____)_| |_|
 *              (C)2013-2017 Semtech
 *
 * \endcode
 *
 * \author    Miguel Luis ( Semtech )
 *
 * \author    Gregory Cristian ( Semtech )
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "board.h"
#include "gpio.h"
#include "delay.h"
#include "timer.h"
#include "radio.h"

#if defined( REGION_AS923 )

#define RF_FREQUENCY                                923000000 // Hz

#elif defined( REGION_AU915 )

#define RF_FREQUENCY                                915000000 // Hz

#elif defined( REGION_CN470 )

#define RF_FREQUENCY                                470000000 // Hz

#elif defined( REGION_CN779 )

#define RF_FREQUENCY                                779000000 // Hz

#elif defined( REGION_EU433 )

#define RF_FREQUENCY                                433000000 // Hz

#elif defined( REGION_EU868 )

#define RF_FREQUENCY                                868000000 // Hz

#elif defined( REGION_KR920 )

#define RF_FREQUENCY                                920000000 // Hz

#elif defined( REGION_IN865 )

#define RF_FREQUENCY                                865000000 // Hz

#elif defined( REGION_US915 )

#define RF_FREQUENCY                                915000000 // Hz

#elif defined( REGION_RU864 )

#define RF_FREQUENCY                                864000000 // Hz

#else
    #error "Please define a frequency band in the compiler options."
#endif

#define TX_OUTPUT_POWER                             14        // dBm

#if defined( USE_MODEM_LORA )

#define LORA_BANDWIDTH                              1         // [0: 125 kHz,
                                                              //  1: 250 kHz,
                                                              //  2: 500 kHz,
                                                              //  3: Reserved]
#define LORA_SPREADING_FACTOR                       10         // [SF7..SF12]
#define LORA_CODINGRATE                             1         // [1: 4/5,
                                                              //  2: 4/6,
                                                              //  3: 4/7,
                                                              //  4: 4/8]
#define LORA_PREAMBLE_LENGTH                        8         // Same for Tx and Rx
#define LORA_SYMBOL_TIMEOUT                         0         // Symbols
#define LORA_FIX_LENGTH_PAYLOAD_ON                  false
#define LORA_IQ_INVERSION_ON                        false

#elif defined( USE_MODEM_FSK )

#define FSK_FDEV                                    25000     // Hz
#define FSK_DATARATE                                50000     // bps

#if defined( SX1272MB2DAS ) || defined( SX1276MB1LAS ) || defined( SX1276MB1MAS )

#define FSK_BANDWIDTH                               50000     // Hz >> SSB in sx127x
#define FSK_AFC_BANDWIDTH                           83333     // Hz

#elif defined( SX1261MBXBAS ) || defined( SX1262MBXCAS ) || defined( SX1262MBXDAS )

#define FSK_BANDWIDTH                               100000    // Hz >> DSB in sx126x
#define FSK_AFC_BANDWIDTH                           166666    // Hz >> Unused in sx126x

#elif defined( LR1110MB1XXS )

#define FSK_BANDWIDTH                               100000    // Hz >> DSB in LR1110
#define FSK_AFC_BANDWIDTH                           166666    // Hz >> Unused in LR1110

#else
    #error "Please define a mbed shield in the compiler options."
#endif

#define FSK_PREAMBLE_LENGTH                         5         // Same for Tx and Rx
#define FSK_FIX_LENGTH_PAYLOAD_ON                   false

#else
    #error "Please define a modem in the compiler options."
#endif

typedef enum
{
    LOWPOWER,
    RX,
    RX_TIMEOUT,
    RX_ERROR,
    TX,
    TX_TIMEOUT,
}States_t;

#if(LORA_SPREADING_FACTOR<=10)
    #define RX_TIMEOUT_VALUE                            5000 
    #define MAX_RNADOM                                  5
#else
    #define RX_TIMEOUT_VALUE                            10000 
    #define MAX_RNADOM                                  10
#endif

#define BUFFER_SIZE                                 20 // Define the payload size here

#define TIMER_LED_ON_BOARD_VALUE                    100

const uint8_t PingMsg[] = "PINGPINGPINGPINGPINGPINGPINGPINGPINGPINGPINGPINGPINGPINGPINGPING";
const uint8_t PongMsg[] = "PONGPONGPONGPONGPONGPONGPONGPONGPONGPONGPONGPONGPONGPONGPONGPONG";

uint16_t BufferSize = BUFFER_SIZE;
uint8_t Buffer[BUFFER_SIZE];

States_t State = LOWPOWER;

int8_t RssiValue = 0;
int8_t SnrValue = 0;

/*!
 * Radio events function pointer
 */
static RadioEvents_t RadioEvents;

/*!
 * Timer to handle the state of LedOnBoard
 */
static TimerEvent_t LedOnBoardTimer;

/*!
 * LED GPIO pins objects
 */
extern Gpio_t Led1;
extern Gpio_t Led2;
extern Gpio_t LedOnBoard;

/*!
 * the status of receive
 */
uint16_t sumTimerValue = 0;

/*!
 * \brief Function to be executed on Radio Tx Done event
 */
void OnTxDone( void );

/*!
 * \brief Function to be executed on Radio Rx Done event
 */
void OnRxDone( uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr );

/*!
 * \brief Function executed on Radio Tx Timeout event
 */
void OnTxTimeout( void );

/*!
 * \brief Function executed on Radio Rx Timeout event
 */
void OnRxTimeout( void );

/*!
 * \brief Function executed on Radio Rx Error event
 */
void OnRxError( void );

/*!
 * \brief Function executed on Led On Board Timeout event
 */
static void OnLedOnBoardTimerEvent( void* context );

/**
 * Main application entry point.
 */
int main( void )
{
    bool isMaster = true;
    // uint8_t i;

    // Target board initialization
    BoardInitMcu( );
    BoardInitPeriph( );

    // Radio initialization
    RadioEvents.TxDone = OnTxDone;
    RadioEvents.RxDone = OnRxDone;
    RadioEvents.TxTimeout = OnTxTimeout;
    RadioEvents.RxTimeout = OnRxTimeout;
    RadioEvents.RxError = OnRxError;

    Radio.Init( &RadioEvents );

    Radio.SetChannel( RF_FREQUENCY );

    // Jimmy begin
    // Timer initialization
    TimerInit( &LedOnBoardTimer, OnLedOnBoardTimerEvent );
    TimerSetValue( &LedOnBoardTimer, TIMER_LED_ON_BOARD_VALUE );
    TimerStart( &LedOnBoardTimer );
    // Jimmy end

#if defined( USE_MODEM_LORA )

    Radio.SetTxConfig( MODEM_LORA, TX_OUTPUT_POWER, 0, LORA_BANDWIDTH,
                                   LORA_SPREADING_FACTOR, LORA_CODINGRATE,
                                   LORA_PREAMBLE_LENGTH, LORA_FIX_LENGTH_PAYLOAD_ON,
                                   true, 0, 0, LORA_IQ_INVERSION_ON, 5000 );

    Radio.SetRxConfig( MODEM_LORA, LORA_BANDWIDTH, LORA_SPREADING_FACTOR,
                                   LORA_CODINGRATE, 0, LORA_PREAMBLE_LENGTH,
                                   LORA_SYMBOL_TIMEOUT, LORA_FIX_LENGTH_PAYLOAD_ON,
                                   0, true, 0, 0, LORA_IQ_INVERSION_ON, true );

    Radio.SetMaxPayloadLength( MODEM_LORA, BUFFER_SIZE );

#elif defined( USE_MODEM_FSK )

    Radio.SetTxConfig( MODEM_FSK, TX_OUTPUT_POWER, FSK_FDEV, 0,
                                  FSK_DATARATE, 0,
                                  FSK_PREAMBLE_LENGTH, FSK_FIX_LENGTH_PAYLOAD_ON,
                                  true, 0, 0, 0, 3000 );

    Radio.SetRxConfig( MODEM_FSK, FSK_BANDWIDTH, FSK_DATARATE,
                                  0, FSK_AFC_BANDWIDTH, FSK_PREAMBLE_LENGTH,
                                  0, FSK_FIX_LENGTH_PAYLOAD_ON, 0, true,
                                  0, 0,false, true );

    Radio.SetMaxPayloadLength( MODEM_FSK, BUFFER_SIZE );

#else
    #error "Please define a frequency band in the compiler options."
#endif

    // 初始化随机数
    srand1( BoardGetRandomSeed( ) );
    Radio.Rx( RX_TIMEOUT_VALUE + randr(0,MAX_RNADOM)*1000 );

    printf("Ping-Pong Ready GO!/r/n");
    print("Ping-Pong Ready GO!");

    for(int i=0; i<10; i++) {
        GpioToggle( &Led1 );
        GpioToggle( &Led2 );
        DelayMs( 100 );
    }

    while( 1 )
    {
        switch( State )
        {
        case RX:
            if( isMaster == true )
            {
                if( BufferSize > 0 )
                {
                    if( strncmp( ( const char* )Buffer, ( const char* )PongMsg, BUFFER_SIZE ) == 0 )
                    {
                        // Indicates on a LED that the received frame is a PONG
                        GpioToggle( &Led2 );
                        //print(Buffer);

                        // Send the next PING frame
                        memcpy( Buffer, PingMsg, BUFFER_SIZE );
                        DelayMs( 1 );
                        Radio.Send( Buffer, BufferSize );
                        GpioWrite(&Led1, 1);
                    }
                    else if( strncmp( ( const char* )Buffer, ( const char* )PingMsg, BUFFER_SIZE ) == 0 )
                    { // A master already exists then become a slave
                        isMaster = false;
                        GpioToggle( &Led2 ); // Set LED off
                        //print(Buffer);
                        // 随机产生超时时间
                        Radio.Rx( RX_TIMEOUT_VALUE + randr(0,MAX_RNADOM)*1000 );
                    }
                    else // valid reception but neither a PING or a PONG message
                    {    // Set device as master ans start again
                        isMaster = true;
                        // 随机产生超时时间
                        Radio.Rx( RX_TIMEOUT_VALUE + randr(0,MAX_RNADOM)*1000 );
                    }
                }
            }
            else
            {
                if( BufferSize > 0 )
                {
                    if( strncmp( ( const char* )Buffer, ( const char* )PingMsg, BUFFER_SIZE ) == 0 )
                    {
                        // Indicates on a LED that the received frame is a PING
                        GpioToggle( &Led2 );
                        //print(Buffer);

                        // Send the reply to the PONG string
                        memcpy( Buffer, PongMsg, BUFFER_SIZE );
                        DelayMs( 1 );
                        Radio.Send( Buffer, BufferSize );
                        GpioWrite(&Led1, 1);
                    }
                    else // valid reception but not a PING as expected
                    {    // Set device as master and start again
                        isMaster = true;
                        // 随机产生超时时间
                        Radio.Rx( RX_TIMEOUT_VALUE + randr(0,MAX_RNADOM)*1000 );
                    }
                }
            }
            State = LOWPOWER;
            break;
        case TX:
            // Indicates on a LED that we have sent a PING [Master]
            // Indicates on a LED that we have sent a PONG [Slave]
            //GpioToggle( &Led2 );
            GpioWrite(&Led1, 0);
            // 随机产生超时时间
            Radio.Rx( RX_TIMEOUT_VALUE + randr(0,MAX_RNADOM)*1000 );
            State = LOWPOWER;
            break;
        case RX_TIMEOUT:
        case RX_ERROR:
            //GpioToggle(&LedOnBoard);
            if( isMaster == true )
            {
                // Send the next PING frame
                memcpy( Buffer, PingMsg, BUFFER_SIZE );
                DelayMs( 1 );
                Radio.Send( Buffer, BufferSize );
                GpioWrite(&Led1, 1);
            }
            else
            {
                // 随机产生超时时间
                Radio.Rx( RX_TIMEOUT_VALUE + randr(0,MAX_RNADOM)*1000 );
            }
            State = LOWPOWER;
            break;
        case TX_TIMEOUT:
            GpioWrite(&Led1, 0);
            // 随机产生超时时间
            Radio.Rx( RX_TIMEOUT_VALUE + randr(0,MAX_RNADOM)*1000 );
            State = LOWPOWER;
            break;
        case LOWPOWER:
        default:
            // Set low power
            break;
        }

        BoardLowPowerHandler( );
        // Process Radio IRQ
        if( Radio.IrqProcess != NULL )
        {
            Radio.IrqProcess( );
        }
    }
}

void OnTxDone( void )
{
    Radio.Sleep( );
    State = TX;
}

void OnRxDone( uint8_t *payload, uint16_t size, int16_t rssi, int8_t snr )
{
    Radio.Sleep( );
    BufferSize = size;
    memcpy( Buffer, payload, BufferSize );
    RssiValue = rssi;
    SnrValue = snr;
    State = RX;

    sumTimerValue = 0;
    TimerStart( &LedOnBoardTimer );
}

void OnTxTimeout( void )
{
    Radio.Sleep( );
    State = TX_TIMEOUT;
}

void OnRxTimeout( void )
{
    Radio.Sleep( );
    State = RX_TIMEOUT;
}

void OnRxError( void )
{
    Radio.Sleep( );
    State = RX_ERROR;
}

/*!
 * \brief Function executed on Led On Board Timeout event
 */
static void OnLedOnBoardTimerEvent( void* context )
{
    uint16_t timerValue = 0;
    static bool ONOFF = true;
    
    // stop this timer loop
    TimerStop( &LedOnBoardTimer );

    if(ONOFF) {
        ONOFF = false;
        // 如果接收信号强度为负值，则用负值绝对值作为指示灯灭灯时长。
        // 如果接收信号值强度为正值，说明信号值很强，灭灯时长为0.
        if(RssiValue < 0) {
            timerValue = ~(RssiValue - 1);      // 将接收信号强度dBm转换为正值
            timerValue = timerValue*10;
        }
        else timerValue = 0;
        // turn off
        GpioWrite(&LedOnBoard, 0);
    }
    else
    {
        ONOFF = true;
        timerValue = TIMER_LED_ON_BOARD_VALUE;
        // turn on
        GpioWrite(&LedOnBoard, 1);
    }
    
    // start up next timer loop
    TimerSetValue( &LedOnBoardTimer, timerValue );
    TimerStart( &LedOnBoardTimer );

    sumTimerValue += timerValue;
    if(sumTimerValue > 3000){
        sumTimerValue = 0;
        // turn off
        GpioWrite(&LedOnBoard, 0);
        // stop this timer loop
        TimerStop( &LedOnBoardTimer );
    }
}
