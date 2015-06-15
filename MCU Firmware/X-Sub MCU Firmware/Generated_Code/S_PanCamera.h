/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : S_PanCamera.h
**     Project     : X-Sub MCU Firmware
**     Processor   : MCF51QE128CLK
**     Component   : PWM
**     Version     : Component 02.240, Driver 01.28, CPU db: 3.00.078
**     Compiler    : CodeWarrior ColdFireV1 C Compiler
**     Date/Time   : 2015-06-15, 15:15, # CodeGen: 10
**     Abstract    :
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
**     Settings    :
**         Used output pin             : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       23            |  PTB4_TPM2CH1_MISO1
**             ----------------------------------------------------
**
**         Timer name                  : TPM2 [16-bit]
**         Counter                     : TPM2CNT   [0xFFFF8051]
**         Mode register               : TPM2SC    [0xFFFF8050]
**         Run register                : TPM2SC    [0xFFFF8050]
**         Prescaler                   : TPM2SC    [0xFFFF8050]
**         Compare register            : TPM2C1V   [0xFFFF8059]
**         Flip-flop register          : TPM2C1SC  [0xFFFF8058]
**
**         User handling procedure     : not specified
**
**         Port name                   : PTB
**         Bit number (in port)        : 4
**         Bit mask of the port        : 0x0010
**         Port data register          : PTBD      [0xFFFF8002]
**         Port control register       : PTBDD     [0xFFFF8003]
**
**         Initialization:
**              Output level           : low
**              Timer                  : Enabled
**              Event                  : Enabled
**         High speed mode
**             Prescaler               : divide-by-2
**             Clock                   : 12582912 Hz
**           Initial value of            period     pulse width
**             Xtal ticks              : 109        0
**             microseconds            : 3333       0
**             milliseconds            : 3          0
**             seconds (real)          : 0.003333330154 0.0
**
**     Contents    :
**         Enable     - byte S_PanCamera_Enable(void);
**         Disable    - byte S_PanCamera_Disable(void);
**         SetRatio8  - byte S_PanCamera_SetRatio8(byte Ratio);
**         SetRatio16 - byte S_PanCamera_SetRatio16(word Ratio);
**         SetDutyUS  - byte S_PanCamera_SetDutyUS(word Time);
**         SetDutyMS  - byte S_PanCamera_SetDutyMS(word Time);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file S_PanCamera.h
** @version 01.28
** @brief
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
*/         
/*!
**  @addtogroup S_PanCamera_module S_PanCamera module documentation
**  @{
*/         

#ifndef __S_PanCamera
#define __S_PanCamera

/* MODULE S_PanCamera. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"
#include "Cpu.h"

#define S_PanCamera_PERIOD_VALUE              0xA3D6U /* Initial period value in ticks of the timer in high speed mode */
#define S_PanCamera_PERIOD_VALUE_HIGH         0xA3D6U /* Period value in ticks of the timer in high speed mode */


byte S_PanCamera_Enable(void);
/*
** ===================================================================
**     Method      :  S_PanCamera_Enable (component PWM)
**     Description :
**         This method enables the component - it starts the signal
**         generation. Events may be generated (<DisableEvent>
**         /<EnableEvent>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

byte S_PanCamera_Disable(void);
/*
** ===================================================================
**     Method      :  S_PanCamera_Disable (component PWM)
**     Description :
**         This method disables the component - it stops the signal
**         generation and events calling. When the timer is disabled,
**         it is possible to call <ClrValue> and <SetValue> methods.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

byte S_PanCamera_SetRatio8(byte Ratio);
/*
** ===================================================================
**     Method      :  S_PanCamera_SetRatio8 (component PWM)
**     Description :
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as an 8-bit unsigned integer number. 0 - FF value is
**         proportional to ratio 0 - 100%. The method is available
**         only if it is not selected list of predefined values in
**         <Starting pulse width> property. 
**         Note: Calculated duty depends on the timer capabilities and
**         on the selected period.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ratio           - Ratio to set. 0 - 255 value is
**                           proportional to ratio 0 - 100%
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

byte S_PanCamera_SetRatio16(word Ratio);
/*
** ===================================================================
**     Method      :  S_PanCamera_SetRatio16 (component PWM)
**     Description :
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as a 16-bit unsigned integer number. 0 - FFFF value is
**         proportional to ratio 0 - 100%. The method is available
**         only if it is not selected list of predefined values in
**         <Starting pulse width> property. 
**         Note: Calculated duty depends on the timer possibilities and
**         on the selected period.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ratio           - Ratio to set. 0 - 65535 value is
**                           proportional to ratio 0 - 100%
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

byte S_PanCamera_SetDutyUS(word Time);
/*
** ===================================================================
**     Method      :  S_PanCamera_SetDutyUS (component PWM)
**     Description :
**         This method sets the new duty value of the output signal.
**         The duty is expressed in microseconds as a 16-bit
**         unsigned integer number.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Time            - Duty to set [in microseconds]
**                      (0 to 3333 us in high speed mode)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/

byte S_PanCamera_SetDutyMS(word Time);
/*
** ===================================================================
**     Method      :  S_PanCamera_SetDutyMS (component PWM)
**     Description :
**         This method sets the new duty value of the output signal.
**         The duty is expressed in milliseconds as a 16-bit
**         unsigned integer number.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Time            - Duty to set [in milliseconds]
**                      (0 to 3 ms in high speed mode)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/

void S_PanCamera_Init(void);
/*
** ===================================================================
**     Method      :  S_PanCamera_Init (component PWM)
**
**     Description :
**         Initializes the associated peripheral(s) and the components 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/


/* END S_PanCamera. */

#endif /* ifndef __S_PanCamera */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale ColdFireV1 series of microcontrollers.
**
** ###################################################################
*/