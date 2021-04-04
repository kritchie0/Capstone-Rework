/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "user_core.h"

void UserCore_Initalize(void)
{
    UART_Open();
    ADC_Open();
}

void UserCore_Run(void)
{
    sadc_values sadc_raw;
    
    DMA_Start((void *)ADC_SAR_CHAN0_RESULT_PTR, (void *)&sadc_raw.v12);
    DMA_Start((void *)ADC_SAR_CHAN1_RESULT_PTR, (void *)&sadc_raw.v5);
    DMA_Start((void *)ADC_SAR_CHAN2_RESULT_PTR, (void *)&sadc_raw.external_temperature);
    DMA_Start((void *)ADC_SAR_CHAN3_RESULT_PTR, (void *)&sadc_raw.mcu_temperature);
    
    ADC_StartConvert();
    
    if(0u != CyDmaGetInterruptSourceMasked())
    {
        /* Once asserted, interrupt remains high (active) until cleared. */
        CyDmaClearInterruptSource(DMA_CHANNEL_MASK);
        
        sprintf(sdata, "12V: %d\t 5V: %d\t Ext_Temp: %d\t MCU_Temp: %d\r\n", sadc_raw.v12, sadc_raw.v5, 
            sadc_raw.external_temperature, sadc_raw.mcu_temperature);
    }
 
}

// ADC Functionality
void ADC_Open(void)
{
    ADC_Start();
}

void ADC_Read(void)
{
    
    //DMA_Start((void *)ADC_SAR_CHAN0_RESULT_PTR, (void *)&adc_sample);
    //ADC_StartConvert();
}


// UART Functionality
void UART_Open(void)
{
    UART_Start();
}

void UART_Close(void)
{
    UART_Stop();
}

void UART_Read(void)
{
    // TODO Add read functionality
}

void UART_Write(char *data, int clear)
{ 
    if(clear == TRUE){
        UART_UartPutString(CLEAR_TERMINAL);
        UART_UartPutString(CURSOR_HOME_TERMINAL);
    }
    
    UART_UartPutString(data);
}


/* [] END OF FILE */
