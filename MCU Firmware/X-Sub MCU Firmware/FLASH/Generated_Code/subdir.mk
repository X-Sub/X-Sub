################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/ADC.c" \
"../Generated_Code/Aux_Int.c" \
"../Generated_Code/Cpu.c" \
"../Generated_Code/IO_Map.c" \
"../Generated_Code/M2_ESC.c" \
"../Generated_Code/M3_ESC.c" \
"../Generated_Code/M4_ESC.c" \
"../Generated_Code/PE_Timer.c" \
"../Generated_Code/RESET_INTERRUPT.c" \
"../Generated_Code/S_PanCamera.c" \
"../Generated_Code/S_TiltCamera.c" \
"../Generated_Code/SerialCom.c" \
"../Generated_Code/Vectors.c" \
"../Generated_Code/sCom_In.c" \
"../Generated_Code/sMCU_OK.c" \
"../Generated_Code/sPC_OK.c" \
"../Generated_Code/testMotor.c" \

C_SRCS += \
../Generated_Code/ADC.c \
../Generated_Code/Aux_Int.c \
../Generated_Code/Cpu.c \
../Generated_Code/IO_Map.c \
../Generated_Code/M2_ESC.c \
../Generated_Code/M3_ESC.c \
../Generated_Code/M4_ESC.c \
../Generated_Code/PE_Timer.c \
../Generated_Code/RESET_INTERRUPT.c \
../Generated_Code/S_PanCamera.c \
../Generated_Code/S_TiltCamera.c \
../Generated_Code/SerialCom.c \
../Generated_Code/Vectors.c \
../Generated_Code/sCom_In.c \
../Generated_Code/sMCU_OK.c \
../Generated_Code/sPC_OK.c \
../Generated_Code/testMotor.c \

OBJS += \
./Generated_Code/ADC_c.obj \
./Generated_Code/Aux_Int_c.obj \
./Generated_Code/Cpu_c.obj \
./Generated_Code/IO_Map_c.obj \
./Generated_Code/M2_ESC_c.obj \
./Generated_Code/M3_ESC_c.obj \
./Generated_Code/M4_ESC_c.obj \
./Generated_Code/PE_Timer_c.obj \
./Generated_Code/RESET_INTERRUPT_c.obj \
./Generated_Code/S_PanCamera_c.obj \
./Generated_Code/S_TiltCamera_c.obj \
./Generated_Code/SerialCom_c.obj \
./Generated_Code/Vectors_c.obj \
./Generated_Code/sCom_In_c.obj \
./Generated_Code/sMCU_OK_c.obj \
./Generated_Code/sPC_OK_c.obj \
./Generated_Code/testMotor_c.obj \

OBJS_QUOTED += \
"./Generated_Code/ADC_c.obj" \
"./Generated_Code/Aux_Int_c.obj" \
"./Generated_Code/Cpu_c.obj" \
"./Generated_Code/IO_Map_c.obj" \
"./Generated_Code/M2_ESC_c.obj" \
"./Generated_Code/M3_ESC_c.obj" \
"./Generated_Code/M4_ESC_c.obj" \
"./Generated_Code/PE_Timer_c.obj" \
"./Generated_Code/RESET_INTERRUPT_c.obj" \
"./Generated_Code/S_PanCamera_c.obj" \
"./Generated_Code/S_TiltCamera_c.obj" \
"./Generated_Code/SerialCom_c.obj" \
"./Generated_Code/Vectors_c.obj" \
"./Generated_Code/sCom_In_c.obj" \
"./Generated_Code/sMCU_OK_c.obj" \
"./Generated_Code/sPC_OK_c.obj" \
"./Generated_Code/testMotor_c.obj" \

C_DEPS += \
./Generated_Code/ADC_c.d \
./Generated_Code/Aux_Int_c.d \
./Generated_Code/Cpu_c.d \
./Generated_Code/IO_Map_c.d \
./Generated_Code/M2_ESC_c.d \
./Generated_Code/M3_ESC_c.d \
./Generated_Code/M4_ESC_c.d \
./Generated_Code/PE_Timer_c.d \
./Generated_Code/RESET_INTERRUPT_c.d \
./Generated_Code/S_PanCamera_c.d \
./Generated_Code/S_TiltCamera_c.d \
./Generated_Code/SerialCom_c.d \
./Generated_Code/Vectors_c.d \
./Generated_Code/sCom_In_c.d \
./Generated_Code/sMCU_OK_c.d \
./Generated_Code/sPC_OK_c.d \
./Generated_Code/testMotor_c.d \

OBJS_OS_FORMAT += \
./Generated_Code/ADC_c.obj \
./Generated_Code/Aux_Int_c.obj \
./Generated_Code/Cpu_c.obj \
./Generated_Code/IO_Map_c.obj \
./Generated_Code/M2_ESC_c.obj \
./Generated_Code/M3_ESC_c.obj \
./Generated_Code/M4_ESC_c.obj \
./Generated_Code/PE_Timer_c.obj \
./Generated_Code/RESET_INTERRUPT_c.obj \
./Generated_Code/S_PanCamera_c.obj \
./Generated_Code/S_TiltCamera_c.obj \
./Generated_Code/SerialCom_c.obj \
./Generated_Code/Vectors_c.obj \
./Generated_Code/sCom_In_c.obj \
./Generated_Code/sMCU_OK_c.obj \
./Generated_Code/sPC_OK_c.obj \
./Generated_Code/testMotor_c.obj \

C_DEPS_QUOTED += \
"./Generated_Code/ADC_c.d" \
"./Generated_Code/Aux_Int_c.d" \
"./Generated_Code/Cpu_c.d" \
"./Generated_Code/IO_Map_c.d" \
"./Generated_Code/M2_ESC_c.d" \
"./Generated_Code/M3_ESC_c.d" \
"./Generated_Code/M4_ESC_c.d" \
"./Generated_Code/PE_Timer_c.d" \
"./Generated_Code/RESET_INTERRUPT_c.d" \
"./Generated_Code/S_PanCamera_c.d" \
"./Generated_Code/S_TiltCamera_c.d" \
"./Generated_Code/SerialCom_c.d" \
"./Generated_Code/Vectors_c.d" \
"./Generated_Code/sCom_In_c.d" \
"./Generated_Code/sMCU_OK_c.d" \
"./Generated_Code/sPC_OK_c.d" \
"./Generated_Code/testMotor_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/ADC_c.obj: ../Generated_Code/ADC.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/ADC.args" -o "Generated_Code/ADC_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/%.d: ../Generated_Code/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Generated_Code/Aux_Int_c.obj: ../Generated_Code/Aux_Int.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/Aux_Int.args" -o "Generated_Code/Aux_Int_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Cpu_c.obj: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/Cpu.args" -o "Generated_Code/Cpu_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/IO_Map_c.obj: ../Generated_Code/IO_Map.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/IO_Map.args" -o "Generated_Code/IO_Map_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/M2_ESC_c.obj: ../Generated_Code/M2_ESC.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/M2_ESC.args" -o "Generated_Code/M2_ESC_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/M3_ESC_c.obj: ../Generated_Code/M3_ESC.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/M3_ESC.args" -o "Generated_Code/M3_ESC_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/M4_ESC_c.obj: ../Generated_Code/M4_ESC.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/M4_ESC.args" -o "Generated_Code/M4_ESC_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PE_Timer_c.obj: ../Generated_Code/PE_Timer.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/PE_Timer.args" -o "Generated_Code/PE_Timer_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/RESET_INTERRUPT_c.obj: ../Generated_Code/RESET_INTERRUPT.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/RESET_INTERRUPT.args" -o "Generated_Code/RESET_INTERRUPT_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/S_PanCamera_c.obj: ../Generated_Code/S_PanCamera.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/S_PanCamera.args" -o "Generated_Code/S_PanCamera_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/S_TiltCamera_c.obj: ../Generated_Code/S_TiltCamera.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/S_TiltCamera.args" -o "Generated_Code/S_TiltCamera_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/SerialCom_c.obj: ../Generated_Code/SerialCom.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/SerialCom.args" -o "Generated_Code/SerialCom_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors_c.obj: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/Vectors.args" -o "Generated_Code/Vectors_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/sCom_In_c.obj: ../Generated_Code/sCom_In.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/sCom_In.args" -o "Generated_Code/sCom_In_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/sMCU_OK_c.obj: ../Generated_Code/sMCU_OK.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/sMCU_OK.args" -o "Generated_Code/sMCU_OK_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/sPC_OK_c.obj: ../Generated_Code/sPC_OK.c
	@echo 'Building file: $<'
	@echo 'Executing target #21 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/sPC_OK.args" -o "Generated_Code/sPC_OK_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/testMotor_c.obj: ../Generated_Code/testMotor.c
	@echo 'Building file: $<'
	@echo 'Executing target #22 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/testMotor.args" -o "Generated_Code/testMotor_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


