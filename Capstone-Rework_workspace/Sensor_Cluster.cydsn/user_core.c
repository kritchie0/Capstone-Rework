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

double v12_adc, v5_adc, ext_temp_adc, mcu_temp_adc;

void UserCore_Initalize(void)
{
    Uart_Open();
    Adc_Open();
    DMA_Start((void*)ADC_SAR_CHAN_RESULT_PTR, &sadc_values);
}

void UserCore_Run(void)
{   
    int v5_input;
    int v12_input;
    
    //DMA_Start((void *)ADC_SAR_CHAN2_RESULT_PTR, (void *)&sadc_raw.external_temperature);
    //DMA_Start((void *)ADC_SAR_CHAN3_RESULT_PTR, (void *)&sadc_raw.mcu_temperature);
    
    ADC_StartConvert();
    
    //v12_input = (5 / 4095) * sadc_raw.v12;
    //v12_input *= V12_VOLTAGE;    
    //v5_input = (5 / 4095) * sadc_raw.v5;
    //v5_input *= V5_VOLTAGE;

    
    if(0u != CyDmaGetInterruptSourceMasked())
    {
        /* Once asserted, interrupt remains high (active) until cleared. */
        CyDmaClearInterruptSource(DMA_CHANNEL_MASK);
        
        //sprintf(sdata, "12V: %d\t 5V: %d\t Ext_Temp: %d\t MCU_Temp: %d\r\n", sadc_raw.v12, sadc_raw.v5, 
        //    sadc_raw.external_temperature, sadc_raw.mcu_temperature);
#if 0        
        if(sadc_raw.v12 < 1140)
        {
            Uart_Write("LOW VOLTAGE\r\n", CLEAR);
        }
        if(sadc_raw.v12 > 2129)
        {
            Uart_Write("OVER VOLTAGE\r\n", CLEAR);
        }
#endif
        //else
        //{
            sprintf(sdata, "12V: %d\t 5V: %d\r\n", sadc_values[0], sadc_values[1]);
            Uart_Write(sdata, NO_CLEAR);
        //}
    }
 
}

// ADC Functionality
void Adc_Open(void)
{
    ADC_Start();
}

void Adc_Read(void)
{
    
    //DMA_Start((void *)ADC_SAR_CHAN0_RESULT_PTR, (void *)&adc_sample);
    //ADC_StartConvert();
}


// UART Functionality
void Uart_Open(void)
{
    UART_Start();
}

void Uart_Close(void)
{
    UART_Stop();
}

void Uart_Read(void)
{
    // TODO Add read functionality
}

void Uart_Write(char *data, int clear)
{ 
    if(clear == TRUE){
        UART_UartPutString(CLEAR_TERMINAL);
        UART_UartPutString(CURSOR_HOME_TERMINAL);
    }
    
    UART_UartPutString(data);
}


/* [] END OF FILE */
