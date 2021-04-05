/*******************************************************************************
* File Name: buton.h  
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

#if !defined(CY_PINS_buton_ALIASES_H) /* Pins buton_ALIASES_H */
#define CY_PINS_buton_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define buton_0			(buton__0__PC)
#define buton_0_PS		(buton__0__PS)
#define buton_0_PC		(buton__0__PC)
#define buton_0_DR		(buton__0__DR)
#define buton_0_SHIFT	(buton__0__SHIFT)
#define buton_0_INTR	((uint16)((uint16)0x0003u << (buton__0__SHIFT*2u)))

#define buton_INTR_ALL	 ((uint16)(buton_0_INTR))


#endif /* End Pins buton_ALIASES_H */


/* [] END OF FILE */
