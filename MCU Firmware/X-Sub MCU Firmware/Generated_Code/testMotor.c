/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : testMotor.c
**     Project     : X-Sub MCU Firmware
**     Processor   : MCF51QE128CLK
**     Component   : PPG
**     Version     : Component 02.195, Driver 01.27, CPU db: 3.00.078
**     Compiler    : CodeWarrior ColdFireV1 C Compiler
**     Date/Time   : 2015-06-25, 10:51, # CodeGen: 20
**     Abstract    :
**         This component "PPG" implements a programmable
**         pulse generator that generates signal with variable
**         duty and variable cycle (period).
**     Settings    :
**         Used output pin             : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       24            |  PTC3_RGPIO11_TPM3CH3
**             ----------------------------------------------------
**
**         Timer name                  : TPM3_PPG [16-bit]
**         Counter                     : TPM3CNT   [0xFFFF8061]
**         Mode register               : TPM3SC    [0xFFFF8060]
**         Run register                : TPM3SC    [0xFFFF8060]
**         Prescaler                   : TPM3SC    [0xFFFF8060]
**         Compare 1 register          : TPM3MOD   [0xFFFF8063]
**         Compare 2 register          : TPM3C3V   [0xFFFF806F]
**         Flip-flop 1 register        : TPM3SC    [0xFFFF8060]
**         Flip-flop 2 register        : TPM3C3SC  [0xFFFF806E]
**
**         Priority                    : 660
**         Interrupt 2 name            : Vtpm3ovf
**         Interrupt enable reg.       : TPM3SC    [0xFFFF8060]
**         Priority                    : 660
**         User handling procedure     : testMotor_OnEnd
**         This event is called when the 1 of cycles is generated
**
**         Output pin
**
**         Port name                   : PTC
**         Bit number (in port)        : 3
**         Bit mask of the port        : 0x0008
**         Port data register          : PTCD      [0xFFFF8004]
**         Port control register       : PTCDD     [0xFFFF8005]
**
**         Runtime setting period      : none
**         Runtime setting ratio       : calculated
**         Initialization:
**              Output level           : low
**              Timer                  : Enabled
**              Event                  : Enabled
**         High speed mode
**             Prescaler               : divide-by-8
**             Clock                   : 1867776 Hz
**           Initial value of            period        pulse width (ratio 0%)
**             Xtal ticks              : 655           0
**             microseconds            : 20000         0
**             milliseconds            : 20            0
**             seconds (real)          : 0.02000025699 0.0
**
**     Contents    :
**         Enable     - byte testMotor_Enable(void);
**         Disable    - byte testMotor_Disable(void);
**         SetRatio8  - byte testMotor_SetRatio8(byte Ratio);
**         SetRatio16 - byte testMotor_SetRatio16(word Ratio);
**         SetDutyUS  - byte testMotor_SetDutyUS(word Time);
**         SetDutyMS  - byte testMotor_SetDutyMS(word Time);
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
** @file testMotor.c
** @version 01.27
** @brief
**         This component "PPG" implements a programmable
**         pulse generator that generates signal with variable
**         duty and variable cycle (period).
*/         
/*!
**  @addtogroup testMotor_module testMotor module documentation
**  @{
*/         


/* MODULE testMotor. */

#include "Events.h"
#include "PE_Error.h"
#include "testMotor.h"


static bool EnUser;                    /* Enable/Disable device by user */
static word ActualRatio;               /* Ratio of L-level to H-level - 16-bit unsigned number */

/* Internal method prototypes */

/*
** ===================================================================
**     Method      :  SetPV (component PPG)
**
**     Description :
**         The method sets prescaler of the device.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void SetPV(byte Val);
/*
** ===================================================================
**     Method      :  HWEnDi (component PPG)
**
**     Description :
**         Enables or disables the peripheral(s) associated with the 
**         component. The method is called automatically as a part of the 
**         Enable and Disable methods and several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void HWEnDi(void);
/*
** ===================================================================
**     Method      :  SetRatio (component PPG)
**
**     Description :
**         The method stores duty value to compare register(s) and sets 
**         necessary bits or (in List mode) call SetCmpRegs method for 
**         duty value storing.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void SetRatio(void);

/* End of Internal methods declarations */

/*
** ===================================================================
**     Method      :  SetPV (component PPG)
**
**     Description :
**         The method sets prescaler of the device.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void SetPV(byte Val)
{
  TPM3SC = (byte)0x00U;                /* Stop counter */
  TPM3CNTH = 0x00U;                    /* Reset HW Counter */
  TPM3SC |= Val;                       /* Store given value to the prescaler and run counter */
}

/*
** ===================================================================
**     Method      :  HWEnDi (component PPG)
**
**     Description :
**         Enables or disables the peripheral(s) associated with the 
**         component. The method is called automatically as a part of the 
**         Enable and Disable methods and several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void HWEnDi(void)
{
  if (EnUser) {
    /* TPM3SC: TOIE=1,CLKSA=1 */
    setReg8Bits(TPM3SC, 0x48U);        /* Run the counter (set CLKSB:CLKSA) */ 
  } else {
    /* TPM3SC: CLKSB=0,CLKSA=0 */
    clrReg8Bits(TPM3SC, 0x18U);        /* Stop counter (CLKSB:CLKSA = 00) */ 
    /* TPM3CNTH: BIT15=0,BIT14=0,BIT13=0,BIT12=0,BIT11=0,BIT10=0,BIT9=0,BIT8=0 */
    setReg8(TPM3CNTH, 0x00U);          /* Reset HW Counter */ 
  }
}

/*
** ===================================================================
**     Method      :  SetRatio (component PPG)
**
**     Description :
**         The method stores duty value to compare register(s) and sets 
**         necessary bits or (in List mode) call SetCmpRegs method for 
**         duty value storing.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void SetRatio(void)
{
  if (ActualRatio == 0xFFFFU) {        /* Duty = 100%? */
    TPM3C3V = 0xFFFFU;                 /* Store new value to the compare reg. */
  } else {
    TPM3C3V = (word)(((TPM3MOD + 0x01U) * (dword)ActualRatio + 0x8000UL) >> 0x10U); /* Calculate new value of compare register according to the given ratio */
  }
}

/*
** ===================================================================
**     Method      :  testMotor_Enable (component PPG)
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
byte testMotor_Enable(void)
{
  if (!EnUser) {                       /* Is the device disabled by user? */
    EnUser = TRUE;                     /* If yes then set the flag "device enabled" */
    HWEnDi();                          /* Enable the device */
  }
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  testMotor_Disable (component PPG)
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
byte testMotor_Disable(void)
{
  if (EnUser) {                        /* Is the device enabled by user? */
    EnUser = FALSE;                    /* If yes then set the flag "device disabled" */
    HWEnDi();                          /* Disable the device */
  }
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  testMotor_SetRatio8 (component PPG)
**     Description :
**         This method sets a new duty-cycle ratio. The ratio is
**         expressed as an 8-bit unsigned integer number. Value 0 - 255
**         is proportional to ratio 0 - 100%. 
**         Note: Calculated duty depends on the timer possibilities and
**         on the selected period.
**         The method is available only if method <SetPeriodMode> is
**         not selected.
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
byte testMotor_SetRatio8(byte Ratio)
{
  ActualRatio = ((word)Ratio << 8U) + Ratio; /* Store new value of the ratio */
  SetRatio();                          /* Calculate and set up new appropriate values of the compare and modulo registers */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  testMotor_SetRatio16 (component PPG)
**     Description :
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as a 16-bit unsigned integer number. Value 0 - 65535 value
**         is proportional to ratio 0 - 100%. 
**         Note: Calculated duty depends on the timer possibilities and
**         on the selected period.
**         The method is available only if method <SetPeriodMode> is
**         not selected.
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
byte testMotor_SetRatio16(word Ratio)
{
  ActualRatio = Ratio;                 /* Store new value of the ratio */
  SetRatio();                          /* Calculate and set up new appropriate values of the compare and modulo registers */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  testMotor_SetDutyUS (component PPG)
**     Description :
**         This method sets the new duty value of the output signal. The
**         duty is expressed in microseconds as a 16-bit unsigned integer
**         number.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Time       - Duty to set [in microseconds]
**                      (0 to 20000 us in high speed mode)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte testMotor_SetDutyUS(word Time)
{
  dlong rtval;                         /* Result of two 32-bit numbers multiplication */

  if (Time > 0x4E20U) {                /* Is the given value out of range? */
    return ERR_RANGE;                  /* If yes then error */
  }
  PE_Timer_LngMul((dword)Time, 0x0346D99BLU, &rtval); /* Multiply given value and High speed CPU mode coefficient */
  if (PE_Timer_LngHi3(rtval[0], rtval[1], &ActualRatio)) { /* Is the result greater or equal than 65536 ? */
    ActualRatio = 0xFFFFU;             /* If yes then use maximal possible value */
  }
  SetRatio();                          /* Calculate and set up new appropriate values of the compare and modulo registers */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  testMotor_SetDutyMS (component PPG)
**     Description :
**         This method sets the new duty value of the output signal. The
**         duty is expressed in milliseconds as a 16-bit unsigned integer
**         number.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Time       - Duty to set [in milliseconds]
**                      (0 to 20 ms in high speed mode)
**     Returns     :
**         ---        - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/
byte testMotor_SetDutyMS(word Time)
{
  #pragma unused (Time)

  dlong rtval;                         /* Result of two 32-bit numbers multiplication */

  if (Time > 0x14U) {                  /* Is the given value out of range? */
    return ERR_RANGE;                  /* If yes then error */
  }
  PE_Timer_LngMul((dword)Time, 0x0CCCC205UL, &rtval); /* Multiply given value and High speed CPU mode coefficient */
  if (PE_Timer_LngHi2(rtval[0], rtval[1], &ActualRatio)) { /* Is the result greater or equal than 65536 ? */
    ActualRatio = 0xFFFFU;             /* If yes then use maximal possible value */
  }
  SetRatio();                          /* Calculate and set up new appropriate values of the compare and modulo registers */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  testMotor_Init (component PPG)
**
**     Description :
**         Initializes the associated peripheral(s) and the components 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void testMotor_Init(void)
{
  /* TPM3SC: TOF=0,TOIE=1,CPWMS=0,CLKSB=0,CLKSA=0,PS2=0,PS1=0,PS0=0 */
  setReg8(TPM3SC, 0x40U);              /* Disable device and enable interrupt */ 
  /* TPM3C3SC: CH3F=0,CH3IE=0,MS3B=1,MS3A=1,ELS3B=1,ELS3A=1,??=0,??=0 */
  setReg8(TPM3C3SC, 0x3CU);            /* Set up PWM mode with output signal level low */ 
  ActualRatio = 0x00U;                 /* Store initial value of the ratio */
  EnUser = TRUE;                       /* Enable device */
  SetPV((byte)0x03U);                  /* Set prescaler register according to the selected High speed CPU mode */
  /* TPM3C3V: BIT15=0,BIT14=0,BIT13=0,BIT12=0,BIT11=0,BIT10=0,BIT9=0,BIT8=0,BIT7=0,BIT6=0,BIT5=0,BIT4=0,BIT3=0,BIT2=0,BIT1=0,BIT0=0 */
  setReg16(TPM3C3V, 0x00U);             
  /* TPM3MOD: BIT15=1,BIT14=0,BIT13=0,BIT12=1,BIT11=0,BIT10=0,BIT9=0,BIT8=1,BIT7=1,BIT6=1,BIT5=1,BIT4=0,BIT3=1,BIT2=0,BIT1=1,BIT0=1 */
  setReg16(TPM3MOD, 0x91EBU);           
  HWEnDi();                            /* Enable/disable device according to status flags */
}


/*
** ===================================================================
**     Method      :  testMotor_Interrupt (component PPG)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(testMotor_Interrupt)
{
  (void)TPM3SC;
  TPM3SC_TOF = 0U;                     /* Reset interrupt request flag */
  testMotor_OnEnd();                   /* Invoke user event */
}


/* END testMotor. */

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
