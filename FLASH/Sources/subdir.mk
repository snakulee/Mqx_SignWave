################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Events.c" \
"../Sources/ProcessorExpert.c" \
"../Sources/mqx_tasks.c" \
"../Sources/sa_mtb.c" \

C_SRCS += \
../Sources/Events.c \
../Sources/ProcessorExpert.c \
../Sources/mqx_tasks.c \
../Sources/sa_mtb.c \

OBJS += \
./Sources/Events_c.obj \
./Sources/ProcessorExpert_c.obj \
./Sources/mqx_tasks_c.obj \
./Sources/sa_mtb_c.obj \

OBJS_QUOTED += \
"./Sources/Events_c.obj" \
"./Sources/ProcessorExpert_c.obj" \
"./Sources/mqx_tasks_c.obj" \
"./Sources/sa_mtb_c.obj" \

C_DEPS += \
./Sources/Events.d \
./Sources/ProcessorExpert.d \
./Sources/mqx_tasks.d \
./Sources/sa_mtb.d \

OBJS_OS_FORMAT += \
./Sources/Events_c.obj \
./Sources/ProcessorExpert_c.obj \
./Sources/mqx_tasks_c.obj \
./Sources/sa_mtb_c.obj \

C_DEPS_QUOTED += \
"./Sources/Events.d" \
"./Sources/ProcessorExpert.d" \
"./Sources/mqx_tasks.d" \
"./Sources/sa_mtb.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/Events_c.obj: ../Sources/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"Sources/Events.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/Events_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/ProcessorExpert_c.obj: ../Sources/ProcessorExpert.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"Sources/ProcessorExpert.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/ProcessorExpert_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mqx_tasks_c.obj: ../Sources/mqx_tasks.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"Sources/mqx_tasks.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/mqx_tasks_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/sa_mtb_c.obj: ../Sources/sa_mtb.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"Sources/sa_mtb.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/sa_mtb_c.obj"
	@echo 'Finished building: $<'
	@echo ' '


