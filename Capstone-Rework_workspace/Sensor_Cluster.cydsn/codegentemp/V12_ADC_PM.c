/*******************************************************************************
* File Name: V12_ADC.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "V12_ADC.h"

static V12_ADC_BACKUP_STRUCT  V12_ADC_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: V12_ADC_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet V12_ADC_SUT.c usage_V12_ADC_Sleep_Wakeup
*******************************************************************************/
void V12_ADC_Sleep(void)
{
    #if defined(V12_ADC__PC)
        V12_ADC_backup.pcState = V12_ADC_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            V12_ADC_backup.usbState = V12_ADC_CR1_REG;
            V12_ADC_USB_POWER_REG |= V12_ADC_USBIO_ENTER_SLEEP;
            V12_ADC_CR1_REG &= V12_ADC_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(V12_ADC__SIO)
        V12_ADC_backup.sioState = V12_ADC_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        V12_ADC_SIO_REG &= (uint32)(~V12_ADC_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: V12_ADC_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to V12_ADC_Sleep() for an example usage.
*******************************************************************************/
void V12_ADC_Wakeup(void)
{
    #if defined(V12_ADC__PC)
        V12_ADC_PC = V12_ADC_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            V12_ADC_USB_POWER_REG &= V12_ADC_USBIO_EXIT_SLEEP_PH1;
            V12_ADC_CR1_REG = V12_ADC_backup.usbState;
            V12_ADC_USB_POWER_REG &= V12_ADC_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(V12_ADC__SIO)
        V12_ADC_SIO_REG = V12_ADC_backup.sioState;
    #endif
}


/* [] END OF FILE */
