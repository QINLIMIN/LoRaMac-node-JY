/*!
 * \file      adc-board.c
 *
 * \brief     Target board ADC driver implementation
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
#include <stdint.h>
#include <stdbool.h>
#include "stm32f0xx.h"
#include "stm32f0xx_hal_conf.h"
#include "board-config.h"
#include "adc-board.h"
//#include "stm32f0xx_hal_adc.h"
#define  ADC_CHANNEL_TOTAL                  2
ADC_HandleTypeDef AdcHandle;
uint32_t aADCxConvertedValues[ADC_CHANNEL_TOTAL];

void AdcMcuInit( Adc_t *obj, PinNames adcInput )
{
    AdcHandle.Instance = ( ADC_TypeDef* )ADC1_BASE;

    __HAL_RCC_ADC1_CLK_ENABLE( );

    HAL_ADC_DeInit( &AdcHandle );

    if( adcInput != NC )
    {
        GpioInit(&obj->AdcInput, adcInput, PIN_ANALOGIC, PIN_PUSH_PULL, PIN_NO_PULL, 0);
    }
}

void AdcMcuConfig( void )
{
    ADC_ChannelConfTypeDef   sConfig;
    HAL_ADC_DeInit(&AdcHandle);
    AdcHandle.Init.ClockPrescaler        = ADC_CLOCK_ASYNC_DIV1;
    AdcHandle.Init.Resolution            = ADC_RESOLUTION_12B;
    AdcHandle.Init.DataAlign             = ADC_DATAALIGN_RIGHT;
    AdcHandle.Init.ScanConvMode          = ADC_SCAN_DIRECTION_FORWARD;    /* Sequencer will convert the number of channels configured below, successively from the lowest to the highest channel number */
    AdcHandle.Init.EOCSelection          = ADC_EOC_SINGLE_CONV;
    AdcHandle.Init.LowPowerAutoWait      = DISABLE;
    AdcHandle.Init.LowPowerAutoPowerOff  = DISABLE;
    AdcHandle.Init.ContinuousConvMode    = DISABLE;                       /* Continuous mode disabled to have only 1 rank converted at each conversion trig, and because discontinuous mode is enabled */
    AdcHandle.Init.DiscontinuousConvMode = ENABLE;                        /* Sequencer of regular group will convert the sequence in several sub-divided sequences */
    AdcHandle.Init.ExternalTrigConv      = ADC_SOFTWARE_START;            /* Software start to trig the 1st conversion manually, without external event */
    AdcHandle.Init.ExternalTrigConvEdge  = ADC_EXTERNALTRIGCONVEDGE_NONE; /* Parameter discarded because trig of conversion by software start (no external event) */
    AdcHandle.Init.DMAContinuousRequests = DISABLE;//ENABLE;              /* ADC-DMA continuous requests to match with DMA configured in circular mode */
    AdcHandle.Init.Overrun               = ADC_OVR_DATA_OVERWRITTEN;
    AdcHandle.Init.SamplingTimeCommon    = ADC_SAMPLETIME_239CYCLES_5;

    HAL_ADC_Init(&AdcHandle);

    // Run the ADC calibration 
    HAL_ADCEx_Calibration_Start(&AdcHandle);

   /* sConfig.Channel      = ADC_CHANNEL_0;
    sConfig.Rank         = ADC_RANK_CHANNEL_NUMBER;
    HAL_ADC_ConfigChannel(&AdcHandle, &sConfig);
    sConfig.Channel      = ADC_CHANNEL_1;
    HAL_ADC_ConfigChannel(&AdcHandle, &sConfig);
    // Run the ADC calibration 
    HAL_ADCEx_Calibration_Start(&AdcHandle);
    HAL_ADC_Start_DMA(&AdcHandle, (uint32_t *)aADCxConvertedValues, ADC_CHANNEL_TOTAL);
    HAL_ADC_Start(&AdcHandle); */
}

uint16_t AdcMcuReadChannel( Adc_t *obj, uint32_t channel )
{
    ADC_ChannelConfTypeDef adcConf = { 0 };
    uint16_t adcData = 0;
   // uint32_t tickStart = 0;
    bool isAdcReady = true;
    // Enable HSI
   // __HAL_RCC_HSI_ENABLE( );  wzh pingbi

    // Wait till HSI is ready
   // while( __HAL_RCC_GET_FLAG( RCC_FLAG_HSIRDY ) == RESET );  wzh pingbi

   // __HAL_RCC_ADC1_CLK_ENABLE( );   //wzh pingbi
    while(ADC_IS_CONVERSION_ONGOING_REGULAR(&AdcHandle) != RESET)
    {

    }
    // Deselects all channels
    adcConf.Channel = 0x7FFFF;//ADC_CHANNEL_MASK;
    adcConf.Rank = ADC_RANK_NONE; 
    HAL_ADC_ConfigChannel( &AdcHandle, &adcConf );

    adcConf.Channel = channel;
    adcConf.Rank = ADC_RANK_CHANNEL_NUMBER;
    HAL_ADC_ConfigChannel( &AdcHandle, &adcConf );

    // Enable ADC1
    //HAL_ADC_Start(&AdcHandle);   //wzh pingbi
    //if(ADC_Enable(&AdcHandle)){  //wzh pingbi
    //   isAdcReady = false;
   // }
    if( isAdcReady != false )
    {
        // Start ADC Software Conversion
        HAL_ADC_Start( &AdcHandle );
        HAL_ADC_PollForConversion( &AdcHandle, HAL_MAX_DELAY );
        adcData = HAL_ADC_GetValue( &AdcHandle );
    }
   // __HAL_ADC_DISABLE( &AdcHandle );  wzh pingbi

    if( ( adcConf.Channel == ADC_CHANNEL_TEMPSENSOR ) || ( adcConf.Channel == ADC_CHANNEL_VREFINT ) )
    {
        HAL_ADC_DeInit( &AdcHandle );
    }
   // __HAL_RCC_ADC1_CLK_DISABLE( );// wzh pingbi

    // Disable HSI
    //__HAL_RCC_HSI_DISABLE( );     wzh pingbi

   return adcData;
  /* if(channel < ADC_CHANNEL_TOTAL){
      return aADCxConvertedValues[channel];
   } */ 
}

void ChangeAdcChannel(uint32_t NewChannel)
{
    ADC_ChannelConfTypeDef adcConf = { 0 };
    while(ADC_IS_CONVERSION_ONGOING_REGULAR(&AdcHandle) != RESET);
    adcConf.Channel = 0x7FFFF;//ADC_CHANNEL_MASK;
    adcConf.Rank = ADC_RANK_NONE; 
    HAL_ADC_ConfigChannel( &AdcHandle, &adcConf );
    while(ADC_IS_CONVERSION_ONGOING_REGULAR(&AdcHandle) != RESET);
    adcConf.Channel = NewChannel;
    adcConf.Rank = ADC_RANK_CHANNEL_NUMBER;
    HAL_ADC_ConfigChannel( &AdcHandle, &adcConf );
}

uint16_t ReadCurrentChannelAdc(void)
{
    uint16_t adcData = 0;
    HAL_ADC_Start( &AdcHandle );
    HAL_ADC_PollForConversion( &AdcHandle, HAL_MAX_DELAY );
    adcData = HAL_ADC_GetValue( &AdcHandle );
    return adcData;
}
/*
void DMA1_Channel1_IRQHandler(void)
{
    HAL_DMA_IRQHandler(AdcHandle.DMA_Handle);
}*/

