/*******************************************************************************
* File Name: Back_Light_On_N.c  
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
#include "Back_Light_On_N.h"

static Back_Light_On_N_BACKUP_STRUCT  Back_Light_On_N_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Back_Light_On_N_Sleep
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
*  \snippet Back_Light_On_N_SUT.c usage_Back_Light_On_N_Sleep_Wakeup
*******************************************************************************/
void Back_Light_On_N_Sleep(void)
{
    #if defined(Back_Light_On_N__PC)
        Back_Light_On_N_backup.pcState = Back_Light_On_N_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Back_Light_On_N_backup.usbState = Back_Light_On_N_CR1_REG;
            Back_Light_On_N_USB_POWER_REG |= Back_Light_On_N_USBIO_ENTER_SLEEP;
            Back_Light_On_N_CR1_REG &= Back_Light_On_N_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Back_Light_On_N__SIO)
        Back_Light_On_N_backup.sioState = Back_Light_On_N_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Back_Light_On_N_SIO_REG &= (uint32)(~Back_Light_On_N_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Back_Light_On_N_Wakeup
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
*  Refer to Back_Light_On_N_Sleep() for an example usage.
*******************************************************************************/
void Back_Light_On_N_Wakeup(void)
{
    #if defined(Back_Light_On_N__PC)
        Back_Light_On_N_PC = Back_Light_On_N_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Back_Light_On_N_USB_POWER_REG &= Back_Light_On_N_USBIO_EXIT_SLEEP_PH1;
            Back_Light_On_N_CR1_REG = Back_Light_On_N_backup.usbState;
            Back_Light_On_N_USB_POWER_REG &= Back_Light_On_N_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Back_Light_On_N__SIO)
        Back_Light_On_N_SIO_REG = Back_Light_On_N_backup.sioState;
    #endif
}


/* [] END OF FILE */
