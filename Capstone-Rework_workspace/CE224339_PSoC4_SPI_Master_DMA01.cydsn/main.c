/*******************************************************************************
* File Name: main.c
*
* Version: 1.50
*
* Description:
*  This example shows how to use the DMA to transfer data from an array to
*  the Master SPI TX buffer and from the RX buffer to an array. This requires
*  a slave device, from code example CE224463 - PSoC 4 SPI Slave.
*
* Related Document: CE224339.pdf
*
* Hardware Dependency: See CE224339.pdf
*
*
*****************************************************************************
*(Copyright 2020), Cypress Semiconductor Corporation. All rights reserved.
*****************************************************************************
*This software, including source code, documentation and related materials
*("Software"), is owned by Cypress Semiconductor Corporation or one of its
*subsidiaries ("Cypress") and is protected by and subject to worldwide patent
*protection (United States and foreign),United States copyright laws and
*international treaty provisions. Therefore, you may use this Software only
*as provided in the license agreement accompanying the software package from
*which you obtained this Software ("EULA").
*
*If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
*non-transferable license to copy, modify, and compile the Software source
*code solely for use in connection with Cypress’s integrated circuit products.
*Any reproduction, modification, translation, compilation, or representation
*of this Software except as specified above is prohibited without the express
*written permission of Cypress.
*
*Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
*EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
*WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
*reserves the right to make changes to the Software without notice. Cypress
*does not assume any liability arising out of the application or use of the
*Software or any product or circuit described in the Software. Cypress does
*not authorize its products for use in any products where a malfunction or
*significant property damage, injury or death ("High Risk Product"). By
*including Cypress's product in a High Risk Product, the manufacturer of such
*system or application assumes all risk of such use and in doing so agrees to
*indemnify Cypress against all liability.
*****************************************************************************/

#include <project.h>

/***************************************
*            Constants
****************************************/
#define     DESCR0              0
#define     PACKET_SIZE         3

/* Start and end of the packet markers */
#define PACKET_SOP      (0x01u)
#define PACKET_EOP      (0x17u)

/* Command byte location */
#define PACKET_CMD_POS  (1u)

/* Commands */
#define CMD_SET_OFF     (0u)
#define CMD_SET_RED     (1u)
#define CMD_SET_RG      (2u)
#define CMD_SET_GREEN   (3u)
#define CMD_SET_GB      (4u)
#define CMD_SET_BLUE    (5u)
#define CMD_END         (6u)
#define CMD_SET_UNKNOWN (0xFFu)

/* Command execution status */
#define STS_CMD_DONE    (0x07u)
#define STS_CMD_FAIL    (0xFFu)

/* Controls the frequency at which the light changes */
#define CMD_TO_CMD_DELAY    (500u)
#define CMD_STALL           (20u)

/* Data buffers */
static int8 masterTxBuffer[PACKET_SIZE] = {PACKET_SOP, CMD_SET_RED, PACKET_EOP};
static int8 masterRxBuffer[PACKET_SIZE] = {0};

/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
*  The main function performs the following actions:
*   1. Initializes the SPI
*   2. Connects the arrays to the DMA to store the data
*   3. Check status and change command
*   4. Check if transfer is complete, clear array and resart DMA
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
int main()
{
    /* Initializes the SPIM component */
    SPIM_Start();

    /* Initializes DMA channels to begin data transfer. */
    RxDmaM_Start((void *)SPIM_RX_FIFO_RD_PTR, (void *)masterRxBuffer);
    TxDmaM_Start((void *)masterTxBuffer, (void *)SPIM_TX_FIFO_WR_PTR);


    for(;;)
    {
        /* Checks if the status is correct */
        if(STS_CMD_DONE == masterRxBuffer[1])
        {
            /* Cycle through LED colors */
            masterTxBuffer[PACKET_CMD_POS] = (masterTxBuffer[PACKET_CMD_POS] + 1) % CMD_END;

            /* Controls the frequency at which the light changes */
            CyDelay(CMD_TO_CMD_DELAY);
        }

        /* Checks if the data transfer was completed */
        if(0u == (CyDmaGetInterruptSourceMasked() ^ (RxDmaM_CHANNEL_MASK)))
        {
            /* Clears the interrupt source for the next data to be sent */
            CyDmaClearInterruptSource(RxDmaM_CHANNEL_MASK);

            /* Sets all memory in array to 0 */
            memset((void *) masterRxBuffer, 0, PACKET_SIZE);

            /* Resets the DMA */
            TxDmaM_ValidateDescriptor(DESCR0);
            TxDmaM_ChEnable();
        }
        /* Allows the slave to prepare for next data transfer */
        CyDelayUs(CMD_STALL/*µsec*/);
    }
}
