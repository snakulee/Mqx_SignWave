################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS_QUOTED += \
"../MQXLITE/psp/cortex_m/core/M0/boot.S" \
"../MQXLITE/psp/cortex_m/core/M0/dispatch.S" \

S_UPPER_SRCS += \
../MQXLITE/psp/cortex_m/core/M0/boot.S \
../MQXLITE/psp/cortex_m/core/M0/dispatch.S \

OBJS += \
./MQXLITE/psp/cortex_m/core/M0/boot_S.obj \
./MQXLITE/psp/cortex_m/core/M0/dispatch_S.obj \

S_UPPER_DEPS += \
./MQXLITE/psp/cortex_m/core/M0/boot.d \
./MQXLITE/psp/cortex_m/core/M0/dispatch.d \

OBJS_QUOTED += \
"./MQXLITE/psp/cortex_m/core/M0/boot_S.obj" \
"./MQXLITE/psp/cortex_m/core/M0/dispatch_S.obj" \

S_UPPER_DEPS_QUOTED += \
"./MQXLITE/psp/cortex_m/core/M0/boot.d" \
"./MQXLITE/psp/cortex_m/core/M0/dispatch.d" \

OBJS_OS_FORMAT += \
./MQXLITE/psp/cortex_m/core/M0/boot_S.obj \
./MQXLITE/psp/cortex_m/core/M0/dispatch_S.obj \


# Each subdirectory must supply rules for building sources it contributes
MQXLITE/psp/cortex_m/core/M0/boot_S.obj: ../MQXLITE/psp/cortex_m/core/M0/boot.S
	@echo 'Building file: $<'
	@echo 'Executing target #25 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"MQXLITE/psp/cortex_m/core/M0/boot.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"MQXLITE/psp/cortex_m/core/M0/boot_S.obj"
	@echo 'Finished building: $<'
	@echo ' '

MQXLITE/psp/cortex_m/core/M0/dispatch_S.obj: ../MQXLITE/psp/cortex_m/core/M0/dispatch.S
	@echo 'Building file: $<'
	@echo 'Executing target #26 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"MQXLITE/psp/cortex_m/core/M0/dispatch.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"MQXLITE/psp/cortex_m/core/M0/dispatch_S.obj"
	@echo 'Finished building: $<'
	@echo ' '


