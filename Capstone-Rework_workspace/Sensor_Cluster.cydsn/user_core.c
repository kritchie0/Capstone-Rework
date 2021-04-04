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

extern void user_core_initalize(void)
{
   uart_open();
}

extern void uart_open(void)
{
    UART_Start();
}

extern void uart_close(void)
{
    UART_Stop();
}

extern void uart_read(void)
{
    //
}

extern void uart_write(char *data, int clear)
{ 
    if(clear == TRUE){
        UART_UartPutString(CLEAR_TERMINAL);
        UART_UartPutString(CURSOR_HOME_TERMINAL);
    }
    
    UART_UartPutString(data);
}


/* [] END OF FILE */
