/*******************************************************************************
* File Name: EXT_TEMP_ADC.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_EXT_TEMP_ADC_H) /* Pins EXT_TEMP_ADC_H */
#define CY_PINS_EXT_TEMP_ADC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "EXT_TEMP_ADC_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} EXT_TEMP_ADC_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   EXT_TEMP_ADC_Read(void);
void    EXT_TEMP_ADC_Write(uint8 value);
uint8   EXT_TEMP_ADC_ReadDataReg(void);
#if defined(EXT_TEMP_ADC__PC) || (CY_PSOC4_4200L) 
    void    EXT_TEMP_ADC_SetDriveMode(uint8 mode);
#endif
void    EXT_TEMP_ADC_SetInterruptMode(uint16 position, uint16 mode);
uint8   EXT_TEMP_ADC_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void EXT_TEMP_ADC_Sleep(void); 
void EXT_TEMP_ADC_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(EXT_TEMP_ADC__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define EXT_TEMP_ADC_DRIVE_MODE_BITS        (3)
    #define EXT_TEMP_ADC_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - EXT_TEMP_ADC_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the EXT_TEMP_ADC_SetDriveMode() function.
         *  @{
         */
        #define EXT_TEMP_ADC_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define EXT_TEMP_ADC_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define EXT_TEMP_ADC_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define EXT_TEMP_ADC_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define EXT_TEMP_ADC_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define EXT_TEMP_ADC_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define EXT_TEMP_ADC_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define EXT_TEMP_ADC_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define EXT_TEMP_ADC_MASK               EXT_TEMP_ADC__MASK
#define EXT_TEMP_ADC_SHIFT              EXT_TEMP_ADC__SHIFT
#define EXT_TEMP_ADC_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in EXT_TEMP_ADC_SetInterruptMode() function.
     *  @{
     */
        #define EXT_TEMP_ADC_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define EXT_TEMP_ADC_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define EXT_TEMP_ADC_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define EXT_TEMP_ADC_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(EXT_TEMP_ADC__SIO)
    #define EXT_TEMP_ADC_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(EXT_TEMP_ADC__PC) && (CY_PSOC4_4200L)
    #define EXT_TEMP_ADC_USBIO_ENABLE               ((uint32)0x80000000u)
    #define EXT_TEMP_ADC_USBIO_DISABLE              ((uint32)(~EXT_TEMP_ADC_USBIO_ENABLE))
    #define EXT_TEMP_ADC_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define EXT_TEMP_ADC_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define EXT_TEMP_ADC_USBIO_ENTER_SLEEP          ((uint32)((1u << EXT_TEMP_ADC_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << EXT_TEMP_ADC_USBIO_SUSPEND_DEL_SHIFT)))
    #define EXT_TEMP_ADC_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << EXT_TEMP_ADC_USBIO_SUSPEND_SHIFT)))
    #define EXT_TEMP_ADC_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << EXT_TEMP_ADC_USBIO_SUSPEND_DEL_SHIFT)))
    #define EXT_TEMP_ADC_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(EXT_TEMP_ADC__PC)
    /* Port Configuration */
    #define EXT_TEMP_ADC_PC                 (* (reg32 *) EXT_TEMP_ADC__PC)
#endif
/* Pin State */
#define EXT_TEMP_ADC_PS                     (* (reg32 *) EXT_TEMP_ADC__PS)
/* Data Register */
#define EXT_TEMP_ADC_DR                     (* (reg32 *) EXT_TEMP_ADC__DR)
/* Input Buffer Disable Override */
#define EXT_TEMP_ADC_INP_DIS                (* (reg32 *) EXT_TEMP_ADC__PC2)

/* Interrupt configuration Registers */
#define EXT_TEMP_ADC_INTCFG                 (* (reg32 *) EXT_TEMP_ADC__INTCFG)
#define EXT_TEMP_ADC_INTSTAT                (* (reg32 *) EXT_TEMP_ADC__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define EXT_TEMP_ADC_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(EXT_TEMP_ADC__SIO)
    #define EXT_TEMP_ADC_SIO_REG            (* (reg32 *) EXT_TEMP_ADC__SIO)
#endif /* (EXT_TEMP_ADC__SIO_CFG) */

/* USBIO registers */
#if !defined(EXT_TEMP_ADC__PC) && (CY_PSOC4_4200L)
    #define EXT_TEMP_ADC_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define EXT_TEMP_ADC_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define EXT_TEMP_ADC_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define EXT_TEMP_ADC_DRIVE_MODE_SHIFT       (0x00u)
#define EXT_TEMP_ADC_DRIVE_MODE_MASK        (0x07u << EXT_TEMP_ADC_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins EXT_TEMP_ADC_H */


/* [] END OF FILE */
