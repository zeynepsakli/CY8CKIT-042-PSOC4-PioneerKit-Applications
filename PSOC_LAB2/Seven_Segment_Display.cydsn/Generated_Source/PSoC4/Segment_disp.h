/*******************************************************************************
* File Name: Segment_disp.h  
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

#if !defined(CY_PINS_Segment_disp_H) /* Pins Segment_disp_H */
#define CY_PINS_Segment_disp_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Segment_disp_aliases.h"


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
} Segment_disp_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Segment_disp_Read(void);
void    Segment_disp_Write(uint8 value);
uint8   Segment_disp_ReadDataReg(void);
#if defined(Segment_disp__PC) || (CY_PSOC4_4200L) 
    void    Segment_disp_SetDriveMode(uint8 mode);
#endif
void    Segment_disp_SetInterruptMode(uint16 position, uint16 mode);
uint8   Segment_disp_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Segment_disp_Sleep(void); 
void Segment_disp_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Segment_disp__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Segment_disp_DRIVE_MODE_BITS        (3)
    #define Segment_disp_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Segment_disp_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Segment_disp_SetDriveMode() function.
         *  @{
         */
        #define Segment_disp_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Segment_disp_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Segment_disp_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Segment_disp_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Segment_disp_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Segment_disp_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Segment_disp_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Segment_disp_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Segment_disp_MASK               Segment_disp__MASK
#define Segment_disp_SHIFT              Segment_disp__SHIFT
#define Segment_disp_WIDTH              7u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Segment_disp_SetInterruptMode() function.
     *  @{
     */
        #define Segment_disp_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Segment_disp_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Segment_disp_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Segment_disp_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Segment_disp__SIO)
    #define Segment_disp_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Segment_disp__PC) && (CY_PSOC4_4200L)
    #define Segment_disp_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Segment_disp_USBIO_DISABLE              ((uint32)(~Segment_disp_USBIO_ENABLE))
    #define Segment_disp_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Segment_disp_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Segment_disp_USBIO_ENTER_SLEEP          ((uint32)((1u << Segment_disp_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Segment_disp_USBIO_SUSPEND_DEL_SHIFT)))
    #define Segment_disp_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Segment_disp_USBIO_SUSPEND_SHIFT)))
    #define Segment_disp_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Segment_disp_USBIO_SUSPEND_DEL_SHIFT)))
    #define Segment_disp_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Segment_disp__PC)
    /* Port Configuration */
    #define Segment_disp_PC                 (* (reg32 *) Segment_disp__PC)
#endif
/* Pin State */
#define Segment_disp_PS                     (* (reg32 *) Segment_disp__PS)
/* Data Register */
#define Segment_disp_DR                     (* (reg32 *) Segment_disp__DR)
/* Input Buffer Disable Override */
#define Segment_disp_INP_DIS                (* (reg32 *) Segment_disp__PC2)

/* Interrupt configuration Registers */
#define Segment_disp_INTCFG                 (* (reg32 *) Segment_disp__INTCFG)
#define Segment_disp_INTSTAT                (* (reg32 *) Segment_disp__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Segment_disp_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Segment_disp__SIO)
    #define Segment_disp_SIO_REG            (* (reg32 *) Segment_disp__SIO)
#endif /* (Segment_disp__SIO_CFG) */

/* USBIO registers */
#if !defined(Segment_disp__PC) && (CY_PSOC4_4200L)
    #define Segment_disp_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Segment_disp_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Segment_disp_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Segment_disp_DRIVE_MODE_SHIFT       (0x00u)
#define Segment_disp_DRIVE_MODE_MASK        (0x07u << Segment_disp_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Segment_disp_H */


/* [] END OF FILE */
