/*******************************************************************************
* File Name: A7.h  
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

#if !defined(CY_PINS_A7_H) /* Pins A7_H */
#define CY_PINS_A7_H

#include "cytypes.h"
#include "cyfitter.h"
#include "A7_aliases.h"


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
} A7_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   A7_Read(void);
void    A7_Write(uint8 value);
uint8   A7_ReadDataReg(void);
#if defined(A7__PC) || (CY_PSOC4_4200L) 
    void    A7_SetDriveMode(uint8 mode);
#endif
void    A7_SetInterruptMode(uint16 position, uint16 mode);
uint8   A7_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void A7_Sleep(void); 
void A7_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(A7__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define A7_DRIVE_MODE_BITS        (3)
    #define A7_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - A7_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the A7_SetDriveMode() function.
         *  @{
         */
        #define A7_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define A7_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define A7_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define A7_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define A7_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define A7_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define A7_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define A7_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define A7_MASK               A7__MASK
#define A7_SHIFT              A7__SHIFT
#define A7_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in A7_SetInterruptMode() function.
     *  @{
     */
        #define A7_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define A7_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define A7_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define A7_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(A7__SIO)
    #define A7_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(A7__PC) && (CY_PSOC4_4200L)
    #define A7_USBIO_ENABLE               ((uint32)0x80000000u)
    #define A7_USBIO_DISABLE              ((uint32)(~A7_USBIO_ENABLE))
    #define A7_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define A7_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define A7_USBIO_ENTER_SLEEP          ((uint32)((1u << A7_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << A7_USBIO_SUSPEND_DEL_SHIFT)))
    #define A7_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << A7_USBIO_SUSPEND_SHIFT)))
    #define A7_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << A7_USBIO_SUSPEND_DEL_SHIFT)))
    #define A7_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(A7__PC)
    /* Port Configuration */
    #define A7_PC                 (* (reg32 *) A7__PC)
#endif
/* Pin State */
#define A7_PS                     (* (reg32 *) A7__PS)
/* Data Register */
#define A7_DR                     (* (reg32 *) A7__DR)
/* Input Buffer Disable Override */
#define A7_INP_DIS                (* (reg32 *) A7__PC2)

/* Interrupt configuration Registers */
#define A7_INTCFG                 (* (reg32 *) A7__INTCFG)
#define A7_INTSTAT                (* (reg32 *) A7__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define A7_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(A7__SIO)
    #define A7_SIO_REG            (* (reg32 *) A7__SIO)
#endif /* (A7__SIO_CFG) */

/* USBIO registers */
#if !defined(A7__PC) && (CY_PSOC4_4200L)
    #define A7_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define A7_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define A7_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define A7_DRIVE_MODE_SHIFT       (0x00u)
#define A7_DRIVE_MODE_MASK        (0x07u << A7_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins A7_H */


/* [] END OF FILE */
