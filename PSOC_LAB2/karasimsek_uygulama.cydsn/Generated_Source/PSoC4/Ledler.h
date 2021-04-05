/*******************************************************************************
* File Name: Ledler.h  
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

#if !defined(CY_PINS_Ledler_H) /* Pins Ledler_H */
#define CY_PINS_Ledler_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Ledler_aliases.h"


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
} Ledler_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Ledler_Read(void);
void    Ledler_Write(uint8 value);
uint8   Ledler_ReadDataReg(void);
#if defined(Ledler__PC) || (CY_PSOC4_4200L) 
    void    Ledler_SetDriveMode(uint8 mode);
#endif
void    Ledler_SetInterruptMode(uint16 position, uint16 mode);
uint8   Ledler_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Ledler_Sleep(void); 
void Ledler_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Ledler__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Ledler_DRIVE_MODE_BITS        (3)
    #define Ledler_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Ledler_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Ledler_SetDriveMode() function.
         *  @{
         */
        #define Ledler_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Ledler_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Ledler_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Ledler_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Ledler_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Ledler_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Ledler_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Ledler_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Ledler_MASK               Ledler__MASK
#define Ledler_SHIFT              Ledler__SHIFT
#define Ledler_WIDTH              8u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Ledler_SetInterruptMode() function.
     *  @{
     */
        #define Ledler_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Ledler_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Ledler_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Ledler_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Ledler__SIO)
    #define Ledler_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Ledler__PC) && (CY_PSOC4_4200L)
    #define Ledler_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Ledler_USBIO_DISABLE              ((uint32)(~Ledler_USBIO_ENABLE))
    #define Ledler_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Ledler_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Ledler_USBIO_ENTER_SLEEP          ((uint32)((1u << Ledler_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Ledler_USBIO_SUSPEND_DEL_SHIFT)))
    #define Ledler_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Ledler_USBIO_SUSPEND_SHIFT)))
    #define Ledler_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Ledler_USBIO_SUSPEND_DEL_SHIFT)))
    #define Ledler_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Ledler__PC)
    /* Port Configuration */
    #define Ledler_PC                 (* (reg32 *) Ledler__PC)
#endif
/* Pin State */
#define Ledler_PS                     (* (reg32 *) Ledler__PS)
/* Data Register */
#define Ledler_DR                     (* (reg32 *) Ledler__DR)
/* Input Buffer Disable Override */
#define Ledler_INP_DIS                (* (reg32 *) Ledler__PC2)

/* Interrupt configuration Registers */
#define Ledler_INTCFG                 (* (reg32 *) Ledler__INTCFG)
#define Ledler_INTSTAT                (* (reg32 *) Ledler__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Ledler_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Ledler__SIO)
    #define Ledler_SIO_REG            (* (reg32 *) Ledler__SIO)
#endif /* (Ledler__SIO_CFG) */

/* USBIO registers */
#if !defined(Ledler__PC) && (CY_PSOC4_4200L)
    #define Ledler_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Ledler_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Ledler_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Ledler_DRIVE_MODE_SHIFT       (0x00u)
#define Ledler_DRIVE_MODE_MASK        (0x07u << Ledler_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Ledler_H */


/* [] END OF FILE */
