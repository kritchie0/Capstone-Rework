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
#define CLEAR (1u)
#define NO_CLEAR (0u)

#define CLEAR_TERMINAL "\x1b[2J"
#define CURSOR_HOME_TERMINAL "\x1b[H"

#define V12_VOLTAGE 5.7
#define V5_VOLTAGE ((983 + 978) / 978)

uint16 sadc_values[ADC_SEQUENCED_CHANNELS_NUM];


char sdata[MESSAGE_LENGTH];

// Externals

void UserCore_Initalize(void);
void UserCore_Run(void);
void Adc_Open(void);
void Uart_Open(void);
void Uart_Close(void);
void Uart_Read(void);
void Uart_Write(char *data, int clear);

/* [] END OF FILE */
