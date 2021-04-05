/*******************************************************************************
* File Name: LCD_K.h  
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

#if !defined(CY_PINS_LCD_K_H) /* Pins LCD_K_H */
#define CY_PINS_LCD_K_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LCD_K_aliases.h"


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
} LCD_K_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   LCD_K_Read(void);
void    LCD_K_Write(uint8 value);
uint8   LCD_K_ReadDataReg(void);
#if defined(LCD_K__PC) || (CY_PSOC4_4200L) 
    void    LCD_K_SetDriveMode(uint8 mode);
#endif
void    LCD_K_SetInterruptMode(uint16 position, uint16 mode);
uint8   LCD_K_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void LCD_K_Sleep(void); 
void LCD_K_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(LCD_K__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define LCD_K_DRIVE_MODE_BITS        (3)
    #define LCD_K_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LCD_K_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the LCD_K_SetDriveMode() function.
         *  @{
         */
        #define LCD_K_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define LCD_K_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define LCD_K_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define LCD_K_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define LCD_K_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define LCD_K_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define LCD_K_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define LCD_K_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define LCD_K_MASK               LCD_K__MASK
#define LCD_K_SHIFT              LCD_K__SHIFT
#define LCD_K_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LCD_K_SetInterruptMode() function.
     *  @{
     */
        #define LCD_K_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define LCD_K_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define LCD_K_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define LCD_K_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(LCD_K__SIO)
    #define LCD_K_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(LCD_K__PC) && (CY_PSOC4_4200L)
    #define LCD_K_USBIO_ENABLE               ((uint32)0x80000000u)
    #define LCD_K_USBIO_DISABLE              ((uint32)(~LCD_K_USBIO_ENABLE))
    #define LCD_K_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define LCD_K_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define LCD_K_USBIO_ENTER_SLEEP          ((uint32)((1u << LCD_K_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << LCD_K_USBIO_SUSPEND_DEL_SHIFT)))
    #define LCD_K_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << LCD_K_USBIO_SUSPEND_SHIFT)))
    #define LCD_K_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << LCD_K_USBIO_SUSPEND_DEL_SHIFT)))
    #define LCD_K_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(LCD_K__PC)
    /* Port Configuration */
    #define LCD_K_PC                 (* (reg32 *) LCD_K__PC)
#endif
/* Pin State */
#define LCD_K_PS                     (* (reg32 *) LCD_K__PS)
/* Data Register */
#define LCD_K_DR                     (* (reg32 *) LCD_K__DR)
/* Input Buffer Disable Override */
#define LCD_K_INP_DIS                (* (reg32 *) LCD_K__PC2)

/* Interrupt configuration Registers */
#define LCD_K_INTCFG                 (* (reg32 *) LCD_K__INTCFG)
#define LCD_K_INTSTAT                (* (reg32 *) LCD_K__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define LCD_K_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(LCD_K__SIO)
    #define LCD_K_SIO_REG            (* (reg32 *) LCD_K__SIO)
#endif /* (LCD_K__SIO_CFG) */

/* USBIO registers */
#if !defined(LCD_K__PC) && (CY_PSOC4_4200L)
    #define LCD_K_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define LCD_K_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define LCD_K_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define LCD_K_DRIVE_MODE_SHIFT       (0x00u)
#define LCD_K_DRIVE_MODE_MASK        (0x07u << LCD_K_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins LCD_K_H */


/* [] END OF FILE */
