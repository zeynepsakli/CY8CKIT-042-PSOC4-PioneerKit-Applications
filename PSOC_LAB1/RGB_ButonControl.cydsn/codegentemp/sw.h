/*******************************************************************************
* File Name: sw.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_sw_H) /* Pins sw_H */
#define CY_PINS_sw_H

#include "cytypes.h"
#include "cyfitter.h"
#include "sw_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} sw_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   sw_Read(void);
void    sw_Write(uint8 value);
uint8   sw_ReadDataReg(void);
#if defined(sw__PC) || (CY_PSOC4_4200L) 
    void    sw_SetDriveMode(uint8 mode);
#endif
void    sw_SetInterruptMode(uint16 position, uint16 mode);
uint8   sw_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void sw_Sleep(void); 
void sw_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(sw__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define sw_DRIVE_MODE_BITS        (3)
    #define sw_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - sw_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the sw_SetDriveMode() function.
         *  @{
         */
        #define sw_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define sw_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define sw_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define sw_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define sw_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define sw_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define sw_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define sw_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define sw_MASK               sw__MASK
#define sw_SHIFT              sw__SHIFT
#define sw_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in sw_SetInterruptMode() function.
     *  @{
     */
        #define sw_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define sw_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define sw_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define sw_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(sw__SIO)
    #define sw_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(sw__PC) && (CY_PSOC4_4200L)
    #define sw_USBIO_ENABLE               ((uint32)0x80000000u)
    #define sw_USBIO_DISABLE              ((uint32)(~sw_USBIO_ENABLE))
    #define sw_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define sw_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define sw_USBIO_ENTER_SLEEP          ((uint32)((1u << sw_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << sw_USBIO_SUSPEND_DEL_SHIFT)))
    #define sw_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << sw_USBIO_SUSPEND_SHIFT)))
    #define sw_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << sw_USBIO_SUSPEND_DEL_SHIFT)))
    #define sw_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(sw__PC)
    /* Port Configuration */
    #define sw_PC                 (* (reg32 *) sw__PC)
#endif
/* Pin State */
#define sw_PS                     (* (reg32 *) sw__PS)
/* Data Register */
#define sw_DR                     (* (reg32 *) sw__DR)
/* Input Buffer Disable Override */
#define sw_INP_DIS                (* (reg32 *) sw__PC2)

/* Interrupt configuration Registers */
#define sw_INTCFG                 (* (reg32 *) sw__INTCFG)
#define sw_INTSTAT                (* (reg32 *) sw__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define sw_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(sw__SIO)
    #define sw_SIO_REG            (* (reg32 *) sw__SIO)
#endif /* (sw__SIO_CFG) */

/* USBIO registers */
#if !defined(sw__PC) && (CY_PSOC4_4200L)
    #define sw_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define sw_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define sw_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define sw_DRIVE_MODE_SHIFT       (0x00u)
#define sw_DRIVE_MODE_MASK        (0x07u << sw_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins sw_H */


/* [] END OF FILE */
