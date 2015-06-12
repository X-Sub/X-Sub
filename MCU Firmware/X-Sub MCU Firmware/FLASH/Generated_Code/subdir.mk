################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/Cpu.c" \
"../Generated_Code/IO_Map.c" \
"../Generated_Code/M1_ESC.c" \
"../Generated_Code/M2_ESC.c" \
"../Generated_Code/M3_ESC.c" \
"../Generated_Code/M4_ESC.c" \
"../Generated_Code/PE_Timer.c" \
"../Generated_Code/Vectors.c" \
"../Generated_Code/sMCU_OK.c" \

C_SRCS += \
../Generated_Code/Cpu.c \
../Generated_Code/IO_Map.c \
../Generated_Code/M1_ESC.c \
../Generated_Code/M2_ESC.c \
../Generated_Code/M3_ESC.c \
../Generated_Code/M4_ESC.c \
../Generated_Code/PE_Timer.c \
../Generated_Code/Vectors.c \
../Generated_Code/sMCU_OK.c \

OBJS += \
./Generated_Code/Cpu_c.obj \
./Generated_Code/IO_Map_c.obj \
./Generated_Code/M1_ESC_c.obj \
./Generated_Code/M2_ESC_c.obj \
./Generated_Code/M3_ESC_c.obj \
./Generated_Code/M4_ESC_c.obj \
./Generated_Code/PE_Timer_c.obj \
./Generated_Code/Vectors_c.obj \
./Generated_Code/sMCU_OK_c.obj \

OBJS_QUOTED += \
"./Generated_Code/Cpu_c.obj" \
"./Generated_Code/IO_Map_c.obj" \
"./Generated_Code/M1_ESC_c.obj" \
"./Generated_Code/M2_ESC_c.obj" \
"./Generated_Code/M3_ESC_c.obj" \
"./Generated_Code/M4_ESC_c.obj" \
"./Generated_Code/PE_Timer_c.obj" \
"./Generated_Code/Vectors_c.obj" \
"./Generated_Code/sMCU_OK_c.obj" \

C_DEPS += \
./Generated_Code/Cpu_c.d \
./Generated_Code/IO_Map_c.d \
./Generated_Code/M1_ESC_c.d \
./Generated_Code/M2_ESC_c.d \
./Generated_Code/M3_ESC_c.d \
./Generated_Code/M4_ESC_c.d \
./Generated_Code/PE_Timer_c.d \
./Generated_Code/Vectors_c.d \
./Generated_Code/sMCU_OK_c.d \

OBJS_OS_FORMAT += \
./Generated_Code/Cpu_c.obj \
./Generated_Code/IO_Map_c.obj \
./Generated_Code/M1_ESC_c.obj \
./Generated_Code/M2_ESC_c.obj \
./Generated_Code/M3_ESC_c.obj \
./Generated_Code/M4_ESC_c.obj \
./Generated_Code/PE_Timer_c.obj \
./Generated_Code/Vectors_c.obj \
./Generated_Code/sMCU_OK_c.obj \

C_DEPS_QUOTED += \
"./Generated_Code/Cpu_c.d" \
"./Generated_Code/IO_Map_c.d" \
"./Generated_Code/M1_ESC_c.d" \
"./Generated_Code/M2_ESC_c.d" \
"./Generated_Code/M3_ESC_c.d" \
"./Generated_Code/M4_ESC_c.d" \
"./Generated_Code/PE_Timer_c.d" \
"./Generated_Code/Vectors_c.d" \
"./Generated_Code/sMCU_OK_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/Cpu_c.obj: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/Cpu.args" -o "Generated_Code/Cpu_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/%.d: ../Generated_Code/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Generated_Code/IO_Map_c.obj: ../Generated_Code/IO_Map.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/IO_Map.args" -o "Generated_Code/IO_Map_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/M1_ESC_c.obj: ../Generated_Code/M1_ESC.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/M1_ESC.args" -o "Generated_Code/M1_ESC_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/M2_ESC_c.obj: ../Generated_Code/M2_ESC.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/M2_ESC.args" -o "Generated_Code/M2_ESC_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/M3_ESC_c.obj: ../Generated_Code/M3_ESC.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/M3_ESC.args" -o "Generated_Code/M3_ESC_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/M4_ESC_c.obj: ../Generated_Code/M4_ESC.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/M4_ESC.args" -o "Generated_Code/M4_ESC_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PE_Timer_c.obj: ../Generated_Code/PE_Timer.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/PE_Timer.args" -o "Generated_Code/PE_Timer_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors_c.obj: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/Vectors.args" -o "Generated_Code/Vectors_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/sMCU_OK_c.obj: ../Generated_Code/sMCU_OK.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Generated_Code/sMCU_OK.args" -o "Generated_Code/sMCU_OK_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

