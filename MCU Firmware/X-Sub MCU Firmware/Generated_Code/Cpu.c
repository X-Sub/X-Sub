/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Cpu.c
**     Project     : X-Sub MCU Firmware
**     Processor   : MCF51QE128CLK
**     Component   : MCF51QE128_80
**     Version     : Component 01.014, Driver 01.12, CPU db: 3.00.078
**     Datasheet   : MCF51QE128RM, Rev. 3, 9/2007
**     Compiler    : CodeWarrior ColdFireV1 C Compiler
**     Date/Time   : 2015-07-11, 23:17, # CodeGen: 34
**     Abstract    :
**         This component "MCF51QE128_80" contains initialization of the
**         CPU and provides basic methods and events for CPU core
**         settings.
**     Settings    :
**
**     Contents    :
**         EnableInt  - void Cpu_EnableInt(void);
**         DisableInt - void Cpu_DisableInt(void);
**         Delay100US - void Cpu_Delay100US(word us100);
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
** @file Cpu.c
** @version 01.12
** @brief
**         This component "MCF51QE128_80" contains initialization of the
**         CPU and provides basic methods and events for CPU core
**         settings.
*/         
/*!
**  @addtogroup Cpu_module Cpu module documentation
**  @{
*/         

/* MODULE Cpu. */
#include "M1_ESC.h"
#include "M2_ESC.h"
#include "M3_ESC.h"
#include "M4_ESC.h"
#include "S_PanCamera.h"
#include "S_TiltCamera.h"
#include "sMCU_OK.h"
#include "sCom_In.h"
#include "sPC_OK.h"
#include "Aux_Int.h"
#include "SerialCom.h"
#include "RESET_INTERRUPT.h"
#include "ADC.h"
#include "LedLight1.h"
#include "LedLight2.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"
#include "Events.h"
#include "Cpu.h"

/* Global variables */
volatile far word SR_reg;              /* Current CCR register */
volatile byte SR_lock;


/*
** ===================================================================
**     Method      :  Cpu_Cpu_Interrupt (component MCF51QE128_80)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(Cpu_Interrupt)
{
  /* This code can be changed using the CPU component property "Build Options / Unhandled int code" */
  /* asm (HALT) */
}


/*
** ===================================================================
**     Method      :  Cpu_Delay100US (component MCF51QE128_80)
**     Description :
**         This method realizes software delay. The length of delay is
**         at least 100 microsecond multiply input parameter [us100].
**         As the delay implementation is not based on real clock, the
**         delay time may be increased by interrupt service routines
**         processed during the delay. The method is independent on
**         selected speed mode.
**     Parameters  :
**         NAME            - DESCRIPTION
**         us100           - Number of 100 us delay repetitions.
**     Returns     : Nothing
** ===================================================================
*/
#pragma aligncode on

__declspec(register_abi) void Cpu_Delay100US(word us100:__D0)
{
  /* irremovable one time overhead (ignored): 11 cycles */
  /* move: 1 cycle overhead (load parameter into register) */
  /* jsr:  3 cycles overhead (jump to subroutine) */
  /* andi: 1 cycle overhead (clear upper word of d0) */
  /* tpf: 1 cycle overhead (alignment) */
  /* rts:  5 cycles overhead (return from subroutine) */

  /* aproximate irremovable overhead for each 100us cycle (counted) : 3 cycles */
  /* subq.l 1 cycles overhead  */
  /* bne.b  2 cycles overhead  */

  /* Disable MISRA rule 55 checking - Non-case label used */
  /*lint -esym( 961, 55)   */
#pragma unused(us100)
  asm {
    naked
    andi.l #0xFFFF,d0                  /* parameter is word - clear the rest of d0 register */
    tpf                                /* alignment */
loop:
    /* 100 us delay block begin */
    /*
     * Delay
     *   - requested                  : 100 us @ 14.942208MHz,
     *   - possible                   : 1494 c, 99985.22 ns, delta -14.78 ns
     *   - without removable overhead : 1491 c, 99784.45 ns
     */
    move.l #0x01F0,d1                  /* (1 c: 66.92 ns) number of iterations */
label0:
    subq.l #1,d1                       /* (1 c: 66.92 ns) decrement d1 */
    bne.b label0                       /* (2 c: 133.85 ns) repeat 496x */
    tpf                                /* (1 c: 66.92 ns) wait for 1 c */
    /* 100 us delay block end */
    subq.l #1,d0                       /* parameter is passed via d0 register */
    bne.w loop                         /* next loop */
    rts                                /* return from subroutine */
  }
  /* Restore MISRA rule 55 checking - Non-case label used */
  /*lint +esym( 961, 55)   */
}

/*
** ===================================================================
**     Method      :  Cpu_DisableInt (component MCF51QE128_80)
**     Description :
**         Disables maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_DisableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_EnableInt (component MCF51QE128_80)
**     Description :
**         Enables maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_EnableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  __initialize_hardware (component MCF51QE128_80)
**
**     Description :
**         Configure the basic system functions (timing, etc.).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/*** !!! Here you can place your own code using property "User data declarations" on the build options tab of the CPU component. !!! ***/


void __initialize_hardware(void)
{

  /*** !!! Here you can place your own code using property "User code before PE initialization" on the build options tab of the CPU component. !!! ***/

  /* ### MCF51QE128_80 "Cpu" init code ... */
  /*  PE initialization code after reset */
  /* Common initialization of the write once registers */
  /* SOPT1: COPE=0,COPT=1,STOPE=0,WAITE=1,??=0,RSTOPE=0,BKGDPE=1,RSTPE=0 */
  setReg8(SOPT1, 0x52U);                
  /* SPMSC1: LVDF=0,LVDACK=0,LVDIE=0,LVDRE=1,LVDSE=1,LVDE=1,??=0,BGBE=0 */
  setReg8(SPMSC1, 0x1CU);               
  /* SPMSC2: LPR=0,LPRS=0,LPWUI=0,??=0,PPDF=0,PPDACK=0,PPDE=1,PPDC=0 */
  setReg8(SPMSC2, 0x02U);               
  /* SPMSC3: LVDV=0,LVWV=0,LVWIE=0 */
  clrReg8Bits(SPMSC3, 0x38U);           
  /* Initialization of CPU registers */
  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */
  asm {
    /* VBR: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,ADDRESS=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
    clr.l d0
    movec d0,VBR
    /* CPUCR: ARD=0,IRD=0,IAE=0,IME=0,BWD=0,??=0,FSD=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
    clr.l d0
    movec d0,CPUCR
  }
  /*lint -restore Enable MISRA rule (1.1) checking. */
  /*  System clock initialization */
  /*lint -save  -e923 Disable MISRA rule (11.3) checking. */
  if (*(unsigned char*)0x03FFU != 0xFFU) { /* Test if the device trim value is stored on the specified address */
    ICSTRM = *(unsigned char*)0x03FFU; /* Initialize ICSTRM register from a non volatile memory */
    ICSSC = (unsigned char)((*(unsigned char*)0x03FEU) & (unsigned char)0x01U); /* Initialize ICSSC register from a non volatile memory */
  }
  /*lint -restore Enable MISRA rule (11.3) checking. */
  /* ICSC1: CLKS=0,RDIV=0,IREFS=1,IRCLKEN=1,IREFSTEN=0 */
  setReg8(ICSC1, 0x06U);               /* Initialization of the ICS control register 1 */ 
  /* ICSC2: BDIV=1,RANGE=0,HGO=0,LP=0,EREFS=0,ERCLKEN=0,EREFSTEN=0 */
  setReg8(ICSC2, 0x40U);               /* Initialization of the ICS control register 2 */ 
  while(ICSSC_IREFST == 0U) {          /* Wait until the source of reference clock is internal clock */
  }
  /* ICSSC: DRST_DRS=2,DMX32=1 */
  clrSetReg8Bits(ICSSC, 0x40U, 0xA0U); /* Initialization of the ICS status and control */ 
  while((ICSSC & 0xC0U) != 0x80U) {    /* Wait until the FLL switches to High range DCO mode */
  }

  /*** End of PE initialization code after reset ***/

  /*** !!! Here you can place your own code using property "User code after PE initialization" on the build options tab of the CPU component. !!! ***/

}

/*
** ===================================================================
**     Method      :  PE_low_level_init (component MCF51QE128_80)
**
**     Description :
**         Initializes components and provides common register 
**         initialization. The method is called automatically as a part 
**         of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PE_low_level_init(void)
{
  /* SCGC1: TPM3=1,TPM2=1,TPM1=1,ADC=1,IIC2=1,IIC1=1,SCI2=1,SCI1=1 */
  setReg8(SCGC1, 0xFFU);                
  /* SCGC2: ??=1,FLS=1,IRQ=1,KBI=1,ACMP=1,RTC=1,SPI2=1,SPI1=1 */
  setReg8(SCGC2, 0xFFU);                
  /* Common initialization of the CPU registers */
  /* PTADD: PTADD7=1,PTADD6=1,PTADD5=0,PTADD1=1,PTADD0=1 */
  clrSetReg8Bits(PTADD, 0x20U, 0xC3U);  
  /* PTAD: PTAD7=0,PTAD6=0,PTAD1=0,PTAD0=0 */
  clrReg8Bits(PTAD, 0xC3U);             
  /* PTBDD: PTBDD5=1,PTBDD4=1,PTBDD1=1,PTBDD0=0 */
  clrSetReg8Bits(PTBDD, 0x01U, 0x32U);  
  /* PTBD: PTBD5=0,PTBD4=0,PTBD1=1 */
  clrSetReg8Bits(PTBD, 0x30U, 0x02U);   
  /* PTCD: PTCD4=1,PTCD3=1,PTCD2=1,PTCD1=0,PTCD0=0 */
  clrSetReg8Bits(PTCD, 0x03U, 0x1CU);   
  /* PTCPE: PTCPE4=0,PTCPE3=0,PTCPE2=0 */
  clrReg8Bits(PTCPE, 0x1CU);            
  /* PTCDD: PTCDD4=1,PTCDD3=1,PTCDD2=1,PTCDD1=1,PTCDD0=1 */
  setReg8Bits(PTCDD, 0x1FU);            
  /* PTAPE: PTAPE5=1 */
  setReg8Bits(PTAPE, 0x20U);            
  /* APCTL2: ADPC10=1 */
  setReg8Bits(APCTL2, 0x04U);           
  /* PTASE: PTASE7=0,PTASE6=0,PTASE4=0,PTASE3=0,PTASE2=0,PTASE1=0,PTASE0=0 */
  clrReg8Bits(PTASE, 0xDFU);            
  /* PTBSE: PTBSE7=0,PTBSE6=0,PTBSE5=0,PTBSE4=0,PTBSE3=0,PTBSE2=0,PTBSE1=0,PTBSE0=0 */
  setReg8(PTBSE, 0x00U);                
  /* PTCSE: PTCSE7=0,PTCSE6=0,PTCSE5=0,PTCSE4=0,PTCSE3=0,PTCSE2=0,PTCSE1=0,PTCSE0=0 */
  setReg8(PTCSE, 0x00U);                
  /* PTDSE: PTDSE7=0,PTDSE6=0,PTDSE5=0,PTDSE4=0,PTDSE3=0,PTDSE2=0,PTDSE1=0,PTDSE0=0 */
  setReg8(PTDSE, 0x00U);                
  /* PTESE: PTESE7=0,PTESE6=0,PTESE5=0,PTESE4=0,PTESE3=0,PTESE2=0,PTESE1=0,PTESE0=0 */
  setReg8(PTESE, 0x00U);                
  /* PTFSE: PTFSE7=0,PTFSE6=0,PTFSE5=0,PTFSE4=0,PTFSE3=0,PTFSE2=0,PTFSE1=0,PTFSE0=0 */
  setReg8(PTFSE, 0x00U);                
  /* PTGSE: PTGSE7=0,PTGSE6=0,PTGSE5=0,PTGSE4=0,PTGSE3=0,PTGSE2=0,PTGSE1=0,PTGSE0=0 */
  setReg8(PTGSE, 0x00U);                
  /* PTHSE: PTHSE7=0,PTHSE6=0,PTHSE5=0,PTHSE4=0,PTHSE3=0,PTHSE2=0,PTHSE1=0,PTHSE0=0 */
  setReg8(PTHSE, 0x00U);                
  /* PTJSE: PTJSE7=0,PTJSE6=0,PTJSE5=0,PTJSE4=0,PTJSE3=0,PTJSE2=0,PTJSE1=0,PTJSE0=0 */
  setReg8(PTJSE, 0x00U);                
  /* PTADS: PTADS7=1,PTADS6=1,PTADS5=0,PTADS4=1,PTADS3=1,PTADS2=1,PTADS1=1,PTADS0=1 */
  setReg8(PTADS, 0xDFU);                
  /* PTBDS: PTBDS7=1,PTBDS6=1,PTBDS5=1,PTBDS4=1,PTBDS3=1,PTBDS2=1,PTBDS1=1,PTBDS0=1 */
  setReg8(PTBDS, 0xFFU);                
  /* PTCDS: PTCDS7=1,PTCDS6=1,PTCDS5=1,PTCDS4=1,PTCDS3=1,PTCDS2=1,PTCDS1=1,PTCDS0=1 */
  setReg8(PTCDS, 0xFFU);                
  /* PTDDS: PTDDS7=1,PTDDS6=1,PTDDS5=1,PTDDS4=1,PTDDS3=1,PTDDS2=1,PTDDS1=1,PTDDS0=1 */
  setReg8(PTDDS, 0xFFU);                
  /* PTEDS: PTEDS7=1,PTEDS6=1,PTEDS5=1,PTEDS4=1,PTEDS3=1,PTEDS2=1,PTEDS1=1,PTEDS0=1 */
  setReg8(PTEDS, 0xFFU);                
  /* PTFDS: PTFDS7=1,PTFDS6=1,PTFDS5=1,PTFDS4=1,PTFDS3=1,PTFDS2=1,PTFDS1=1,PTFDS0=1 */
  setReg8(PTFDS, 0xFFU);                
  /* PTGDS: PTGDS7=1,PTGDS6=1,PTGDS5=1,PTGDS4=1,PTGDS3=1,PTGDS2=1,PTGDS1=1,PTGDS0=1 */
  setReg8(PTGDS, 0xFFU);                
  /* PTHDS: PTHDS7=1,PTHDS6=1,PTHDS5=1,PTHDS4=1,PTHDS3=1,PTHDS2=1,PTHDS1=1,PTHDS0=1 */
  setReg8(PTHDS, 0xFFU);                
  /* PTJDS: PTJDS7=1,PTJDS6=1,PTJDS5=1,PTJDS4=1,PTJDS3=1,PTJDS2=1,PTJDS1=1,PTJDS0=1 */
  setReg8(PTJDS, 0xFFU);                
  /* ### Shared modules init code ... */
  /* ### Programable pulse generation "M1_ESC" init code ... */
  M1_ESC_Init();
  /* ### Programable pulse generation "M2_ESC" init code ... */
  M2_ESC_Init();
  /* ### Programable pulse generation "M3_ESC" init code ... */
  M3_ESC_Init();
  /* ### Programable pulse generation "M4_ESC" init code ... */
  M4_ESC_Init();
  /* ### Programable pulse generation "S_PanCamera" init code ... */
  S_PanCamera_Init();
  /* ### Programable pulse generation "S_TiltCamera" init code ... */
  S_TiltCamera_Init();
  /* ### BitIO "sMCU_OK" init code ... */
  /* ### BitIO "sCom_In" init code ... */
  /* ### BitIO "sPC_OK" init code ... */
  /* ### TimerInt "Aux_Int" init code ... */
  Aux_Int_Init();
  /* ### Asynchro serial "SerialCom" init code ... */
  SerialCom_Init();
  /* ### External interrupt "RESET_INTERRUPT" init code ... */
  /* IRQSC: ??=0,IRQPDD=0,IRQEDG=0,IRQPE=1,IRQF=0,IRQACK=0,IRQIE=0,IRQMOD=0 */
  setReg8(IRQSC, 0x10U);                
  /* IRQSC: IRQACK=1 */
  setReg8Bits(IRQSC, 0x04U);            
  /* IRQSC: IRQIE=1 */
  setReg8Bits(IRQSC, 0x02U);            
  /* ###  "ADC" init code ... */
  ADC_Init();
  /* ### Programable pulse generation "LedLight1" init code ... */
  LedLight1_Init();
  /* ### Programable pulse generation "LedLight2" init code ... */
  LedLight2_Init();
  /* Common peripheral initialization - ENABLE */
  /* TPM1SC: CLKSB=0,CLKSA=1,PS1=1,PS0=1 */
  clrSetReg8Bits(TPM1SC, 0x10U, 0x0BU); 
  /* TPM2SC: CLKSB=0,CLKSA=1 */
  clrSetReg8Bits(TPM2SC, 0x10U, 0x08U); 
  /* TPM3SC: CLKSB=0,CLKSA=1,PS1=1 */
  clrSetReg8Bits(TPM3SC, 0x10U, 0x0AU); 
  /* Initialize priority of ivVsci1rx interrupt */
  /* INTC_PL6P6: ??=0,??=0,??=0,REQN=0x0D */
  setReg8(INTC_PL6P6, 0x0DU);           
  /* Initialize priority of ivVsci1tx interrupt */
  /* INTC_PL6P6: ??=0,??=0,??=0,REQN=0x0E */
  setReg8(INTC_PL6P6, 0x0EU);           
  /* Initialize priority of ivVrtc interrupt */
  /* INTC_PL6P6: ??=0,??=0,??=0,REQN=0x16 */
  setReg8(INTC_PL6P6, 0x16U);           
  /* INTC_WCR: ENB=0,??=0,??=0,??=0,??=0,MASK=0 */
  setReg8(INTC_WCR, 0x00U);             
  SR_lock = 0x00;
  /* Set initial interrupt priority 0 */
  asm {
    move.w SR,D0;
    andi.l #0xF8FF,D0;
    move.w D0,SR;
  }
}

/* Initialization of the CPU registers in FLASH */
/* NVPROT: FPS6=1,FPS5=1,FPS4=1,FPS3=1,FPS2=1,FPS1=1,FPS0=1,FPOPEN=1 */
static unsigned char NVPROT_INIT @0x0000040D = 0xFFU;
/* NVOPT: KEYEN1=0,KEYEN0=1,??=1,??=1,??=1,??=1,SEC1=1,SEC0=1 */
static unsigned char NVOPT_INIT @0x0000040F = 0x7FU;
/* END Cpu. */

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
