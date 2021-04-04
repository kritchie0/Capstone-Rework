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

#include "project.h"
#include <stdio.h>

// Definitions
#define MESSAGE_LENGTH (255u)
#define TRUE (1u)
#define FALSE (0u)

#define CLEAR_TERMINAL "\x1b[2J"
#define CURSOR_HOME_TERMINAL "\x1b[H"


typedef struct{
    int v12;
    int v5;
    int external_temperature;
    int mcu_temperature;
}sadc_values;


char sdata[MESSAGE_LENGTH];

// Externals

void UserCore_Initalize(void);
void UserCore_Run(void);
void ADC_Open(void);
void UART_Open(void);
void UART_Close(void);
void UART_Read(void);
void UART_Write(char *data, int clear);

/* [] END OF FILE */
