/*******************************************************************************
* File Name: Led_blink.c  
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
#include "Led_blink.h"

static Led_blink_BACKUP_STRUCT  Led_blink_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Led_blink_Sleep
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
*  \snippet Led_blink_SUT.c usage_Led_blink_Sleep_Wakeup
*******************************************************************************/
void Led_blink_Sleep(void)
{
    #if defined(Led_blink__PC)
        Led_blink_backup.pcState = Led_blink_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Led_blink_backup.usbState = Led_blink_CR1_REG;
            Led_blink_USB_POWER_REG |= Led_blink_USBIO_ENTER_SLEEP;
            Led_blink_CR1_REG &= Led_blink_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Led_blink__SIO)
        Led_blink_backup.sioState = Led_blink_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Led_blink_SIO_REG &= (uint32)(~Led_blink_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Led_blink_Wakeup
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
*  Refer to Led_blink_Sleep() for an example usage.
*******************************************************************************/
void Led_blink_Wakeup(void)
{
    #if defined(Led_blink__PC)
        Led_blink_PC = Led_blink_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Led_blink_USB_POWER_REG &= Led_blink_USBIO_EXIT_SLEEP_PH1;
            Led_blink_CR1_REG = Led_blink_backup.usbState;
            Led_blink_USB_POWER_REG &= Led_blink_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Led_blink__SIO)
        Led_blink_SIO_REG = Led_blink_backup.sioState;
    #endif
}


/* [] END OF FILE */
