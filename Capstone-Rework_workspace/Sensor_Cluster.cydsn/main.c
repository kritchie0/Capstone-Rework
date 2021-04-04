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

#define VERSION "0.0.0"

char sdata[MESSAGE_LENGTH];

int main(void)
{
    user_core_initalize();
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    sprintf(sdata, "Welcome to Sensor Cluster Firmware Version %s\r\n", VERSION);
    uart_write(sdata, TRUE);
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
