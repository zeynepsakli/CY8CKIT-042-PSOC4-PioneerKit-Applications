/*******************************************************************************
* File Name: Segment_disp.c  
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
#include "Segment_disp.h"

static Segment_disp_BACKUP_STRUCT  Segment_disp_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Segment_disp_Sleep
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
*  \snippet Segment_disp_SUT.c usage_Segment_disp_Sleep_Wakeup
*******************************************************************************/
void Segment_disp_Sleep(void)
{
    #if defined(Segment_disp__PC)
        Segment_disp_backup.pcState = Segment_disp_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Segment_disp_backup.usbState = Segment_disp_CR1_REG;
            Segment_disp_USB_POWER_REG |= Segment_disp_USBIO_ENTER_SLEEP;
            Segment_disp_CR1_REG &= Segment_disp_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Segment_disp__SIO)
        Segment_disp_backup.sioState = Segment_disp_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Segment_disp_SIO_REG &= (uint32)(~Segment_disp_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Segment_disp_Wakeup
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
*  Refer to Segment_disp_Sleep() for an example usage.
*******************************************************************************/
void Segment_disp_Wakeup(void)
{
    #if defined(Segment_disp__PC)
        Segment_disp_PC = Segment_disp_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Segment_disp_USB_POWER_REG &= Segment_disp_USBIO_EXIT_SLEEP_PH1;
            Segment_disp_CR1_REG = Segment_disp_backup.usbState;
            Segment_disp_USB_POWER_REG &= Segment_disp_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Segment_disp__SIO)
        Segment_disp_SIO_REG = Segment_disp_backup.sioState;
    #endif
}


/* [] END OF FILE */
