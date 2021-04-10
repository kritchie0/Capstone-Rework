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
#include "Core.h"

#define VERSION "0.0.5" 


int main(void)
{
    sprintf(sdata, "Welcome to Sensor Cluster Firmware Version %s\r\n", VERSION);
    Uart_Write(sdata, TRUE);
    
    UserCore_Initalize();
    CyGlobalIntEnable; /* Enable global interrupts. */


    
    for(;;)
    {
        UserCore_Run();
    }
}

/* [] END OF FILE */
