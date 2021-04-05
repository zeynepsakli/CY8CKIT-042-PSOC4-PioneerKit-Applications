/*******************************************************************************
* File Name: echo_rise.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_echo_rise_H)
#define CY_ISR_echo_rise_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void echo_rise_Start(void);
void echo_rise_StartEx(cyisraddress address);
void echo_rise_Stop(void);

CY_ISR_PROTO(echo_rise_Interrupt);

void echo_rise_SetVector(cyisraddress address);
cyisraddress echo_rise_GetVector(void);

void echo_rise_SetPriority(uint8 priority);
uint8 echo_rise_GetPriority(void);

void echo_rise_Enable(void);
uint8 echo_rise_GetState(void);
void echo_rise_Disable(void);

void echo_rise_SetPending(void);
void echo_rise_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the echo_rise ISR. */
#define echo_rise_INTC_VECTOR            ((reg32 *) echo_rise__INTC_VECT)

/* Address of the echo_rise ISR priority. */
#define echo_rise_INTC_PRIOR             ((reg32 *) echo_rise__INTC_PRIOR_REG)

/* Priority of the echo_rise interrupt. */
#define echo_rise_INTC_PRIOR_NUMBER      echo_rise__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable echo_rise interrupt. */
#define echo_rise_INTC_SET_EN            ((reg32 *) echo_rise__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the echo_rise interrupt. */
#define echo_rise_INTC_CLR_EN            ((reg32 *) echo_rise__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the echo_rise interrupt state to pending. */
#define echo_rise_INTC_SET_PD            ((reg32 *) echo_rise__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the echo_rise interrupt. */
#define echo_rise_INTC_CLR_PD            ((reg32 *) echo_rise__INTC_CLR_PD_REG)



#endif /* CY_ISR_echo_rise_H */


/* [] END OF FILE */
