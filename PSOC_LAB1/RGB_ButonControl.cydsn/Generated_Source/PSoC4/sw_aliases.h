/*******************************************************************************
* File Name: sw.h  
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

#if !defined(CY_PINS_sw_ALIASES_H) /* Pins sw_ALIASES_H */
#define CY_PINS_sw_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define sw_0			(sw__0__PC)
#define sw_0_PS		(sw__0__PS)
#define sw_0_PC		(sw__0__PC)
#define sw_0_DR		(sw__0__DR)
#define sw_0_SHIFT	(sw__0__SHIFT)
#define sw_0_INTR	((uint16)((uint16)0x0003u << (sw__0__SHIFT*2u)))

#define sw_INTR_ALL	 ((uint16)(sw_0_INTR))


#endif /* End Pins sw_ALIASES_H */


/* [] END OF FILE */
