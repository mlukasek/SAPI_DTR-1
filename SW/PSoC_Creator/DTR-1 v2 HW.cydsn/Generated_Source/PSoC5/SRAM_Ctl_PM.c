/*******************************************************************************
* File Name: SRAM_Ctl_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "SRAM_Ctl.h"

/* Check for removal by optimization */
#if !defined(SRAM_Ctl_Sync_ctrl_reg__REMOVED)

static SRAM_Ctl_BACKUP_STRUCT  SRAM_Ctl_backup = {0u};

    
/*******************************************************************************
* Function Name: SRAM_Ctl_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SRAM_Ctl_SaveConfig(void) 
{
    SRAM_Ctl_backup.controlState = SRAM_Ctl_Control;
}


/*******************************************************************************
* Function Name: SRAM_Ctl_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void SRAM_Ctl_RestoreConfig(void) 
{
     SRAM_Ctl_Control = SRAM_Ctl_backup.controlState;
}


/*******************************************************************************
* Function Name: SRAM_Ctl_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SRAM_Ctl_Sleep(void) 
{
    SRAM_Ctl_SaveConfig();
}


/*******************************************************************************
* Function Name: SRAM_Ctl_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SRAM_Ctl_Wakeup(void)  
{
    SRAM_Ctl_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
