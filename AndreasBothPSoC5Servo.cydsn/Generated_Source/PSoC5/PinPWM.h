/*******************************************************************************
* File Name: PinPWM.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_PinPWM_H) /* Pins PinPWM_H */
#define CY_PINS_PinPWM_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PinPWM_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PinPWM__PORT == 15 && ((PinPWM__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PinPWM_Write(uint8 value);
void    PinPWM_SetDriveMode(uint8 mode);
uint8   PinPWM_ReadDataReg(void);
uint8   PinPWM_Read(void);
void    PinPWM_SetInterruptMode(uint16 position, uint16 mode);
uint8   PinPWM_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PinPWM_SetDriveMode() function.
     *  @{
     */
        #define PinPWM_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PinPWM_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PinPWM_DM_RES_UP          PIN_DM_RES_UP
        #define PinPWM_DM_RES_DWN         PIN_DM_RES_DWN
        #define PinPWM_DM_OD_LO           PIN_DM_OD_LO
        #define PinPWM_DM_OD_HI           PIN_DM_OD_HI
        #define PinPWM_DM_STRONG          PIN_DM_STRONG
        #define PinPWM_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PinPWM_MASK               PinPWM__MASK
#define PinPWM_SHIFT              PinPWM__SHIFT
#define PinPWM_WIDTH              1u

/* Interrupt constants */
#if defined(PinPWM__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PinPWM_SetInterruptMode() function.
     *  @{
     */
        #define PinPWM_INTR_NONE      (uint16)(0x0000u)
        #define PinPWM_INTR_RISING    (uint16)(0x0001u)
        #define PinPWM_INTR_FALLING   (uint16)(0x0002u)
        #define PinPWM_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PinPWM_INTR_MASK      (0x01u) 
#endif /* (PinPWM__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PinPWM_PS                     (* (reg8 *) PinPWM__PS)
/* Data Register */
#define PinPWM_DR                     (* (reg8 *) PinPWM__DR)
/* Port Number */
#define PinPWM_PRT_NUM                (* (reg8 *) PinPWM__PRT) 
/* Connect to Analog Globals */                                                  
#define PinPWM_AG                     (* (reg8 *) PinPWM__AG)                       
/* Analog MUX bux enable */
#define PinPWM_AMUX                   (* (reg8 *) PinPWM__AMUX) 
/* Bidirectional Enable */                                                        
#define PinPWM_BIE                    (* (reg8 *) PinPWM__BIE)
/* Bit-mask for Aliased Register Access */
#define PinPWM_BIT_MASK               (* (reg8 *) PinPWM__BIT_MASK)
/* Bypass Enable */
#define PinPWM_BYP                    (* (reg8 *) PinPWM__BYP)
/* Port wide control signals */                                                   
#define PinPWM_CTL                    (* (reg8 *) PinPWM__CTL)
/* Drive Modes */
#define PinPWM_DM0                    (* (reg8 *) PinPWM__DM0) 
#define PinPWM_DM1                    (* (reg8 *) PinPWM__DM1)
#define PinPWM_DM2                    (* (reg8 *) PinPWM__DM2) 
/* Input Buffer Disable Override */
#define PinPWM_INP_DIS                (* (reg8 *) PinPWM__INP_DIS)
/* LCD Common or Segment Drive */
#define PinPWM_LCD_COM_SEG            (* (reg8 *) PinPWM__LCD_COM_SEG)
/* Enable Segment LCD */
#define PinPWM_LCD_EN                 (* (reg8 *) PinPWM__LCD_EN)
/* Slew Rate Control */
#define PinPWM_SLW                    (* (reg8 *) PinPWM__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PinPWM_PRTDSI__CAPS_SEL       (* (reg8 *) PinPWM__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PinPWM_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PinPWM__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PinPWM_PRTDSI__OE_SEL0        (* (reg8 *) PinPWM__PRTDSI__OE_SEL0) 
#define PinPWM_PRTDSI__OE_SEL1        (* (reg8 *) PinPWM__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PinPWM_PRTDSI__OUT_SEL0       (* (reg8 *) PinPWM__PRTDSI__OUT_SEL0) 
#define PinPWM_PRTDSI__OUT_SEL1       (* (reg8 *) PinPWM__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PinPWM_PRTDSI__SYNC_OUT       (* (reg8 *) PinPWM__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PinPWM__SIO_CFG)
    #define PinPWM_SIO_HYST_EN        (* (reg8 *) PinPWM__SIO_HYST_EN)
    #define PinPWM_SIO_REG_HIFREQ     (* (reg8 *) PinPWM__SIO_REG_HIFREQ)
    #define PinPWM_SIO_CFG            (* (reg8 *) PinPWM__SIO_CFG)
    #define PinPWM_SIO_DIFF           (* (reg8 *) PinPWM__SIO_DIFF)
#endif /* (PinPWM__SIO_CFG) */

/* Interrupt Registers */
#if defined(PinPWM__INTSTAT)
    #define PinPWM_INTSTAT            (* (reg8 *) PinPWM__INTSTAT)
    #define PinPWM_SNAP               (* (reg8 *) PinPWM__SNAP)
    
	#define PinPWM_0_INTTYPE_REG 		(* (reg8 *) PinPWM__0__INTTYPE)
#endif /* (PinPWM__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PinPWM_H */


/* [] END OF FILE */
