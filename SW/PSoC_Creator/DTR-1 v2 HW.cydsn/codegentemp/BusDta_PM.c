/*******************************************************************************
* File Name: BusDta_PM.c
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

#include "BusDta.h"

/* Check for removal by optimization */
#if !defined(BusDta_Sync_ctrl_reg__REMOVED)

static BusDta_BACKUP_STRUCT  BusDta_backup = {0u};

    
/*******************************************************************************
* Function Name: BusDta_SaveConfig
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
void BusDta_SaveConfig(void) 
{
    BusDta_backup.controlState = BusDta_Control;
}


/*******************************************************************************
* Function Name: BusDta_RestoreConfig
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
void BusDta_RestoreConfig(void) 
{
     BusDta_Control = BusDta_backup.controlState;
}


/*******************************************************************************
* Function Name: BusDta_Sleep
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
void BusDta_Sleep(void) 
{
    BusDta_SaveConfig();
}


/*******************************************************************************
* Function Name: BusDta_Wakeup
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
void BusDta_Wakeup(void)  
{
    BusDta_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
