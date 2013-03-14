################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/Console.c" \
"../Generated_Code/Cpu.c" \
"../Generated_Code/DrvDac2V.c" \
"../Generated_Code/DrvI2c0.c" \
"../Generated_Code/DrvI2c1.c" \
"../Generated_Code/DrvPwmTimerB.c" \
"../Generated_Code/DrvPwmTimerRG.c" \
"../Generated_Code/IO1.c" \
"../Generated_Code/MQX1.c" \
"../Generated_Code/PE_LDD.c" \
"../Generated_Code/SystemTimer1.c" \
"../Generated_Code/Vectors.c" \
"../Generated_Code/task_template_list.c" \

C_SRCS += \
../Generated_Code/Console.c \
../Generated_Code/Cpu.c \
../Generated_Code/DrvDac2V.c \
../Generated_Code/DrvI2c0.c \
../Generated_Code/DrvI2c1.c \
../Generated_Code/DrvPwmTimerB.c \
../Generated_Code/DrvPwmTimerRG.c \
../Generated_Code/IO1.c \
../Generated_Code/MQX1.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/SystemTimer1.c \
../Generated_Code/Vectors.c \
../Generated_Code/task_template_list.c \

OBJS += \
./Generated_Code/Console_c.obj \
./Generated_Code/Cpu_c.obj \
./Generated_Code/DrvDac2V_c.obj \
./Generated_Code/DrvI2c0_c.obj \
./Generated_Code/DrvI2c1_c.obj \
./Generated_Code/DrvPwmTimerB_c.obj \
./Generated_Code/DrvPwmTimerRG_c.obj \
./Generated_Code/IO1_c.obj \
./Generated_Code/MQX1_c.obj \
./Generated_Code/PE_LDD_c.obj \
./Generated_Code/SystemTimer1_c.obj \
./Generated_Code/Vectors_c.obj \
./Generated_Code/task_template_list_c.obj \

OBJS_QUOTED += \
"./Generated_Code/Console_c.obj" \
"./Generated_Code/Cpu_c.obj" \
"./Generated_Code/DrvDac2V_c.obj" \
"./Generated_Code/DrvI2c0_c.obj" \
"./Generated_Code/DrvI2c1_c.obj" \
"./Generated_Code/DrvPwmTimerB_c.obj" \
"./Generated_Code/DrvPwmTimerRG_c.obj" \
"./Generated_Code/IO1_c.obj" \
"./Generated_Code/MQX1_c.obj" \
"./Generated_Code/PE_LDD_c.obj" \
"./Generated_Code/SystemTimer1_c.obj" \
"./Generated_Code/Vectors_c.obj" \
"./Generated_Code/task_template_list_c.obj" \

C_DEPS += \
./Generated_Code/Console.d \
./Generated_Code/Cpu.d \
./Generated_Code/DrvDac2V.d \
./Generated_Code/DrvI2c0.d \
./Generated_Code/DrvI2c1.d \
./Generated_Code/DrvPwmTimerB.d \
./Generated_Code/DrvPwmTimerRG.d \
./Generated_Code/IO1.d \
./Generated_Code/MQX1.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/SystemTimer1.d \
./Generated_Code/Vectors.d \
./Generated_Code/task_template_list.d \

OBJS_OS_FORMAT += \
./Generated_Code/Console_c.obj \
./Generated_Code/Cpu_c.obj \
./Generated_Code/DrvDac2V_c.obj \
./Generated_Code/DrvI2c0_c.obj \
./Generated_Code/DrvI2c1_c.obj \
./Generated_Code/DrvPwmTimerB_c.obj \
./Generated_Code/DrvPwmTimerRG_c.obj \
./Generated_Code/IO1_c.obj \
./Generated_Code/MQX1_c.obj \
./Generated_Code/PE_LDD_c.obj \
./Generated_Code/SystemTimer1_c.obj \
./Generated_Code/Vectors_c.obj \
./Generated_Code/task_template_list_c.obj \

C_DEPS_QUOTED += \
"./Generated_Code/Console.d" \
"./Generated_Code/Cpu.d" \
"./Generated_Code/DrvDac2V.d" \
"./Generated_Code/DrvI2c0.d" \
"./Generated_Code/DrvI2c1.d" \
"./Generated_Code/DrvPwmTimerB.d" \
"./Generated_Code/DrvPwmTimerRG.d" \
"./Generated_Code/IO1.d" \
"./Generated_Code/MQX1.d" \
"./Generated_Code/PE_LDD.d" \
"./Generated_Code/SystemTimer1.d" \
"./Generated_Code/Vectors.d" \
"./Generated_Code/task_template_list.d" \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/Console_c.obj: ../Generated_Code/Console.c
	@echo 'Building file: $<'
	@echo 'Executing target #42 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"Generated_Code/Console.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/Console_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Cpu_c.obj: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #43 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"Generated_Code/Cpu.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/Cpu_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/DrvDac2V_c.obj: ../Generated_Code/DrvDac2V.c
	@echo 'Building file: $<'
	@echo 'Executing target #44 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"Generated_Code/DrvDac2V.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/DrvDac2V_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/DrvI2c0_c.obj: ../Generated_Code/DrvI2c0.c
	@echo 'Building file: $<'
	@echo 'Executing target #45 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"Generated_Code/DrvI2c0.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/DrvI2c0_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/DrvI2c1_c.obj: ../Generated_Code/DrvI2c1.c
	@echo 'Building file: $<'
	@echo 'Executing target #46 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"Generated_Code/DrvI2c1.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/DrvI2c1_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/DrvPwmTimerB_c.obj: ../Generated_Code/DrvPwmTimerB.c
	@echo 'Building file: $<'
	@echo 'Executing target #47 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"Generated_Code/DrvPwmTimerB.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/DrvPwmTimerB_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/DrvPwmTimerRG_c.obj: ../Generated_Code/DrvPwmTimerRG.c
	@echo 'Building file: $<'
	@echo 'Executing target #48 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"Generated_Code/DrvPwmTimerRG.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/DrvPwmTimerRG_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/IO1_c.obj: ../Generated_Code/IO1.c
	@echo 'Building file: $<'
	@echo 'Executing target #49 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"Generated_Code/IO1.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/IO1_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/MQX1_c.obj: ../Generated_Code/MQX1.c
	@echo 'Building file: $<'
	@echo 'Executing target #50 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"Generated_Code/MQX1.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/MQX1_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PE_LDD_c.obj: ../Generated_Code/PE_LDD.c
	@echo 'Building file: $<'
	@echo 'Executing target #51 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"Generated_Code/PE_LDD.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/PE_LDD_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/SystemTimer1_c.obj: ../Generated_Code/SystemTimer1.c
	@echo 'Building file: $<'
	@echo 'Executing target #52 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"Generated_Code/SystemTimer1.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/SystemTimer1_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors_c.obj: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #53 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"Generated_Code/Vectors.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/Vectors_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/task_template_list_c.obj: ../Generated_Code/task_template_list.c
	@echo 'Building file: $<'
	@echo 'Executing target #54 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"Generated_Code/task_template_list.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/task_template_list_c.obj"
	@echo 'Finished building: $<'
	@echo ' '


