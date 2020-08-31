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

#define LORA_BANDWIDTH                              0         // [0: 125 kHz,
                                                              //  1: 250 kHz,
                                                              //  2: 500 kHz,
                                                              //  3: Reserved]
#define LORA_SPREADING_FACTOR                       12         // [SF7..SF12]
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

#define RX_TIMEOUT_VALUE                            10000 // 1000
#define BUFFER_SIZE                                 64 // Define the payload size here

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
 * LED GPIO pins objects
 */
extern Gpio_t Led1;
extern Gpio_t Led2;
extern Gpio_t LedOnBoard;

time_t t;
int time();

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
    Radio.Rx( RX_TIMEOUT_VALUE + randr(0,10)*1000 );

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
                        print(Buffer);

                        // Send the next PING frame
                        memcpy( Buffer, PingMsg, BUFFER_SIZE );
                        // Buffer[0] = 'P';Buffer[1] = 'I';Buffer[2] = 'N';Buffer[3] = 'G';
                        // Buffer[4] = 'P';Buffer[5] = 'I';Buffer[6] = 'N';Buffer[7] = 'G';
                        // Buffer[8] = 'P';Buffer[9] = 'I';Buffer[10] = 'N';Buffer[11] = 'G';
                        // Buffer[12] = 'P';Buffer[13] = 'I';Buffer[14] = 'N';Buffer[15] = 'G';
                        // Buffer[16] = 'P';Buffer[17] = 'I';Buffer[18] = 'N';Buffer[19] = 'G';
                        // Buffer[20] = 'P';Buffer[21] = 'I';Buffer[22] = 'N';Buffer[23] = 'G';
                        // Buffer[24] = 'P';Buffer[25] = 'I';Buffer[26] = 'N';Buffer[27] = 'G';
                        // Buffer[28] = 'P';Buffer[29] = 'I';Buffer[30] = 'N';Buffer[31] = 'G';
                        // Buffer[32] = 'P';Buffer[33] = 'I';Buffer[34] = 'N';Buffer[35] = 'G';
                        // Buffer[36] = 'P';Buffer[37] = 'I';Buffer[38] = 'N';Buffer[39] = 'G';

                        // We fill the buffer with numbers for the payload
                        // for( i = 40; i < BufferSize; i++ )
                        // {
                        //     Buffer[i] = i - 40;
                        // }
                        DelayMs( 1 );
                        Radio.Send( Buffer, BufferSize );
                        GpioWrite(&Led1, 1);
                    }
                    else if( strncmp( ( const char* )Buffer, ( const char* )PingMsg, BUFFER_SIZE ) == 0 )
                    { // A master already exists then become a slave
                        isMaster = false;
                        GpioToggle( &Led2 ); // Set LED off
                        print(Buffer);
                        // 随机产生超时时间
                        Radio.Rx( RX_TIMEOUT_VALUE + randr(0,10)*1000 );
                    }
                    else // valid reception but neither a PING or a PONG message
                    {    // Set device as master ans start again
                        isMaster = true;
                        // 随机产生超时时间
                        Radio.Rx( RX_TIMEOUT_VALUE + randr(0,10)*1000 );
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
                        print(Buffer);

                        // Send the reply to the PONG string
                        memcpy( Buffer, PongMsg, BUFFER_SIZE );
                        // Buffer[0] = 'P';Buffer[1] = 'O';Buffer[2] = 'N';Buffer[3] = 'G';
                        // Buffer[4] = 'P';Buffer[5] = 'O';Buffer[6] = 'N';Buffer[7] = 'G';
                        // Buffer[8] = 'P';Buffer[9] = 'O';Buffer[10] = 'N';Buffer[11] = 'G';
                        // Buffer[12] = 'P';Buffer[13] = 'O';Buffer[14] = 'N';Buffer[15] = 'G';
                        // Buffer[16] = 'P';Buffer[17] = 'O';Buffer[18] = 'N';Buffer[19] = 'G';
                        // Buffer[20] = 'P';Buffer[21] = 'O';Buffer[22] = 'N';Buffer[23] = 'G';
                        // Buffer[24] = 'P';Buffer[25] = 'O';Buffer[26] = 'N';Buffer[27] = 'G';
                        // Buffer[28] = 'P';Buffer[29] = 'O';Buffer[30] = 'N';Buffer[31] = 'G';
                        // Buffer[32] = 'P';Buffer[33] = 'O';Buffer[34] = 'N';Buffer[35] = 'G';
                        // Buffer[36] = 'P';Buffer[37] = 'O';Buffer[38] = 'N';Buffer[39] = 'G';

                        // We fill the buffer with numbers for the payload
                        // for( i = 40; i < BufferSize; i++ )
                        // {
                        //     Buffer[i] = i - 40;
                        // }
                        DelayMs( 1 );
                        Radio.Send( Buffer, BufferSize );
                        GpioWrite(&Led1, 1);
                    }
                    else // valid reception but not a PING as expected
                    {    // Set device as master and start again
                        isMaster = true;
                        // 随机产生超时时间
                        Radio.Rx( RX_TIMEOUT_VALUE + randr(0,10)*1000 );
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
            Radio.Rx( RX_TIMEOUT_VALUE + randr(0,10)*1000 );
            State = LOWPOWER;
            break;
        case RX_TIMEOUT:
        case RX_ERROR:
            GpioToggle(&LedOnBoard);
            if( isMaster == true )
            {
                // Send the next PING frame
                memcpy( Buffer, PingMsg, BUFFER_SIZE );
                // Buffer[0] = 'P';Buffer[1] = 'I';Buffer[2] = 'N';Buffer[3] = 'G';
                // Buffer[4] = 'P';Buffer[5] = 'I';Buffer[6] = 'N';Buffer[7] = 'G';
                // Buffer[8] = 'P';Buffer[9] = 'I';Buffer[10] = 'N';Buffer[11] = 'G';
                // Buffer[12] = 'P';Buffer[13] = 'I';Buffer[14] = 'N';Buffer[15] = 'G';
                // Buffer[16] = 'P';Buffer[17] = 'I';Buffer[18] = 'N';Buffer[19] = 'G';
                // Buffer[20] = 'P';Buffer[21] = 'I';Buffer[22] = 'N';Buffer[23] = 'G';
                // Buffer[24] = 'P';Buffer[25] = 'I';Buffer[26] = 'N';Buffer[27] = 'G';
                // Buffer[28] = 'P';Buffer[29] = 'I';Buffer[30] = 'N';Buffer[31] = 'G';
                // Buffer[32] = 'P';Buffer[33] = 'I';Buffer[34] = 'N';Buffer[35] = 'G';
                // Buffer[36] = 'P';Buffer[37] = 'I';Buffer[38] = 'N';Buffer[39] = 'G';
                // for( i = 40; i < BufferSize; i++ )
                // {
                //     Buffer[i] = i - 40;
                // }
                DelayMs( 1 );
                Radio.Send( Buffer, BufferSize );
                GpioWrite(&Led1, 1);
            }
            else
            {
                // 随机产生超时时间
                Radio.Rx( RX_TIMEOUT_VALUE + randr(0,10)*1000 );
            }
            State = LOWPOWER;
            break;
        case TX_TIMEOUT:
            GpioWrite(&Led1, 0);
            // 随机产生超时时间
            Radio.Rx( RX_TIMEOUT_VALUE + randr(0,10)*1000 );
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
