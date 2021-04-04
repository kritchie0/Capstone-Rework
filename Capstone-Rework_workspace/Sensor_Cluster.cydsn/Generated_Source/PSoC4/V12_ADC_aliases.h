/*******************************************************************************
* File Name: V12_ADC.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_V12_ADC_ALIASES_H) /* Pins V12_ADC_ALIASES_H */
#define CY_PINS_V12_ADC_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define V12_ADC_0			(V12_ADC__0__PC)
#define V12_ADC_0_PS		(V12_ADC__0__PS)
#define V12_ADC_0_PC		(V12_ADC__0__PC)
#define V12_ADC_0_DR		(V12_ADC__0__DR)
#define V12_ADC_0_SHIFT	(V12_ADC__0__SHIFT)
#define V12_ADC_0_INTR	((uint16)((uint16)0x0003u << (V12_ADC__0__SHIFT*2u)))

#define V12_ADC_INTR_ALL	 ((uint16)(V12_ADC_0_INTR))


#endif /* End Pins V12_ADC_ALIASES_H */


/* [] END OF FILE */
