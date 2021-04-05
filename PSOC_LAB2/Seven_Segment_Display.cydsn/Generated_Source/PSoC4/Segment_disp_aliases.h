/*******************************************************************************
* File Name: Segment_disp.h  
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

#if !defined(CY_PINS_Segment_disp_ALIASES_H) /* Pins Segment_disp_ALIASES_H */
#define CY_PINS_Segment_disp_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Segment_disp_0			(Segment_disp__0__PC)
#define Segment_disp_0_PS		(Segment_disp__0__PS)
#define Segment_disp_0_PC		(Segment_disp__0__PC)
#define Segment_disp_0_DR		(Segment_disp__0__DR)
#define Segment_disp_0_SHIFT	(Segment_disp__0__SHIFT)
#define Segment_disp_0_INTR	((uint16)((uint16)0x0003u << (Segment_disp__0__SHIFT*2u)))

#define Segment_disp_1			(Segment_disp__1__PC)
#define Segment_disp_1_PS		(Segment_disp__1__PS)
#define Segment_disp_1_PC		(Segment_disp__1__PC)
#define Segment_disp_1_DR		(Segment_disp__1__DR)
#define Segment_disp_1_SHIFT	(Segment_disp__1__SHIFT)
#define Segment_disp_1_INTR	((uint16)((uint16)0x0003u << (Segment_disp__1__SHIFT*2u)))

#define Segment_disp_2			(Segment_disp__2__PC)
#define Segment_disp_2_PS		(Segment_disp__2__PS)
#define Segment_disp_2_PC		(Segment_disp__2__PC)
#define Segment_disp_2_DR		(Segment_disp__2__DR)
#define Segment_disp_2_SHIFT	(Segment_disp__2__SHIFT)
#define Segment_disp_2_INTR	((uint16)((uint16)0x0003u << (Segment_disp__2__SHIFT*2u)))

#define Segment_disp_3			(Segment_disp__3__PC)
#define Segment_disp_3_PS		(Segment_disp__3__PS)
#define Segment_disp_3_PC		(Segment_disp__3__PC)
#define Segment_disp_3_DR		(Segment_disp__3__DR)
#define Segment_disp_3_SHIFT	(Segment_disp__3__SHIFT)
#define Segment_disp_3_INTR	((uint16)((uint16)0x0003u << (Segment_disp__3__SHIFT*2u)))

#define Segment_disp_4			(Segment_disp__4__PC)
#define Segment_disp_4_PS		(Segment_disp__4__PS)
#define Segment_disp_4_PC		(Segment_disp__4__PC)
#define Segment_disp_4_DR		(Segment_disp__4__DR)
#define Segment_disp_4_SHIFT	(Segment_disp__4__SHIFT)
#define Segment_disp_4_INTR	((uint16)((uint16)0x0003u << (Segment_disp__4__SHIFT*2u)))

#define Segment_disp_5			(Segment_disp__5__PC)
#define Segment_disp_5_PS		(Segment_disp__5__PS)
#define Segment_disp_5_PC		(Segment_disp__5__PC)
#define Segment_disp_5_DR		(Segment_disp__5__DR)
#define Segment_disp_5_SHIFT	(Segment_disp__5__SHIFT)
#define Segment_disp_5_INTR	((uint16)((uint16)0x0003u << (Segment_disp__5__SHIFT*2u)))

#define Segment_disp_6			(Segment_disp__6__PC)
#define Segment_disp_6_PS		(Segment_disp__6__PS)
#define Segment_disp_6_PC		(Segment_disp__6__PC)
#define Segment_disp_6_DR		(Segment_disp__6__DR)
#define Segment_disp_6_SHIFT	(Segment_disp__6__SHIFT)
#define Segment_disp_6_INTR	((uint16)((uint16)0x0003u << (Segment_disp__6__SHIFT*2u)))

#define Segment_disp_INTR_ALL	 ((uint16)(Segment_disp_0_INTR| Segment_disp_1_INTR| Segment_disp_2_INTR| Segment_disp_3_INTR| Segment_disp_4_INTR| Segment_disp_5_INTR| Segment_disp_6_INTR))


#endif /* End Pins Segment_disp_ALIASES_H */


/* [] END OF FILE */
