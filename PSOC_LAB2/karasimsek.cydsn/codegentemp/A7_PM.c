/*******************************************************************************
* File Name: A7.c  
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
#include "A7.h"

static A7_BACKUP_STRUCT  A7_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: A7_Sleep
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
*  \snippet A7_SUT.c usage_A7_Sleep_Wakeup
*******************************************************************************/
void A7_Sleep(void)
{
    #if defined(A7__PC)
        A7_backup.pcState = A7_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            A7_backup.usbState = A7_CR1_REG;
            A7_USB_POWER_REG |= A7_USBIO_ENTER_SLEEP;
            A7_CR1_REG &= A7_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(A7__SIO)
        A7_backup.sioState = A7_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        A7_SIO_REG &= (uint32)(~A7_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: A7_Wakeup
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
*  Refer to A7_Sleep() for an example usage.
*******************************************************************************/
void A7_Wakeup(void)
{
    #if defined(A7__PC)
        A7_PC = A7_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            A7_USB_POWER_REG &= A7_USBIO_EXIT_SLEEP_PH1;
            A7_CR1_REG = A7_backup.usbState;
            A7_USB_POWER_REG &= A7_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(A7__SIO)
        A7_SIO_REG = A7_backup.sioState;
    #endif
}


/* [] END OF FILE */
