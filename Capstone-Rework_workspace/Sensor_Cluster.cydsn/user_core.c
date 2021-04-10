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
    ADC_StartConvert();
}

void UserCore_Run(void)
{   
    float fv5_input, fv12_input;
    uint16 mv5_input;
    uint16 v5_input;
    uint16 mv12_input;
    uint16 v12_input;
    
    sadc_values[0] = ADC_GetResult16(0);
    sadc_values[1] = ADC_GetResult16(1);
    
    mv12_input = ADC_CountsTo_mVolts(0, sadc_values[0]);
    mv5_input = ADC_CountsTo_mVolts(1, sadc_values[1]);
    
    sprintf(sdata, "12V_ADCmV: %d\t 5V_ADCmV: %d\r\n", mv12_input, mv5_input);
    Uart_Write(sdata, NO_CLEAR);

    v12_input = mv12_input * V12_VOLTAGE;
    //v12_input = fv12_input;
        
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
        sprintf(sdata, "12V: %d\t 5V: %d\r\n", v12_input, v5_input);
        Uart_Write(sdata, NO_CLEAR);
    //} 
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
