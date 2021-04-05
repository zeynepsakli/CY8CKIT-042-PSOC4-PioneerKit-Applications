/*******************************************************************************
* File Name: led_red.c  
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
#include "led_red.h"

static led_red_BACKUP_STRUCT  led_red_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: led_red_Sleep
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
*  \snippet led_red_SUT.c usage_led_red_Sleep_Wakeup
*******************************************************************************/
void led_red_Sleep(void)
{
    #if defined(led_red__PC)
        led_red_backup.pcState = led_red_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            led_red_backup.usbState = led_red_CR1_REG;
            led_red_USB_POWER_REG |= led_red_USBIO_ENTER_SLEEP;
            led_red_CR1_REG &= led_red_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(led_red__SIO)
        led_red_backup.sioState = led_red_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        led_red_SIO_REG &= (uint32)(~led_red_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: led_red_Wakeup
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
*  Refer to led_red_Sleep() for an example usage.
*******************************************************************************/
void led_red_Wakeup(void)
{
    #if defined(led_red__PC)
        led_red_PC = led_red_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            led_red_USB_POWER_REG &= led_red_USBIO_EXIT_SLEEP_PH1;
            led_red_CR1_REG = led_red_backup.usbState;
            led_red_USB_POWER_REG &= led_red_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(led_red__SIO)
        led_red_SIO_REG = led_red_backup.sioState;
    #endif
}


/* [] END OF FILE */
