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

// User-Core Headers
#include "user_core.h"

#define VERSION "0.0.4" 


int main(void)
{
    UserCore_Initalize();
    CyGlobalIntEnable; /* Enable global interrupts. */

    sprintf(sdata, "Welcome to Sensor Cluster Firmware Version %s\r\n", VERSION);
    Uart_Write(sdata, TRUE);
    
    for(;;)
    {
        UserCore_Run();
    }
}

/* [] END OF FILE */
