################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../MQXLITE/kernel/idletask.c" \
"../MQXLITE/kernel/int.c" \
"../MQXLITE/kernel/klog.c" \
"../MQXLITE/kernel/lwevent.c" \
"../MQXLITE/kernel/lwlog.c" \
"../MQXLITE/kernel/lwmsgq.c" \
"../MQXLITE/kernel/lwsem.c" \
"../MQXLITE/kernel/lwtimer.c" \
"../MQXLITE/kernel/mqx_utils.c" \
"../MQXLITE/kernel/mqxlite.c" \
"../MQXLITE/kernel/mutex.c" \
"../MQXLITE/kernel/qu_test.c" \
"../MQXLITE/kernel/sched.c" \
"../MQXLITE/kernel/task.c" \
"../MQXLITE/kernel/time_ticks.c" \

C_SRCS += \
../MQXLITE/kernel/idletask.c \
../MQXLITE/kernel/int.c \
../MQXLITE/kernel/klog.c \
../MQXLITE/kernel/lwevent.c \
../MQXLITE/kernel/lwlog.c \
../MQXLITE/kernel/lwmsgq.c \
../MQXLITE/kernel/lwsem.c \
../MQXLITE/kernel/lwtimer.c \
../MQXLITE/kernel/mqx_utils.c \
../MQXLITE/kernel/mqxlite.c \
../MQXLITE/kernel/mutex.c \
../MQXLITE/kernel/qu_test.c \
../MQXLITE/kernel/sched.c \
../MQXLITE/kernel/task.c \
../MQXLITE/kernel/time_ticks.c \

OBJS += \
./MQXLITE/kernel/idletask_c.obj \
./MQXLITE/kernel/int_c.obj \
./MQXLITE/kernel/klog_c.obj \
./MQXLITE/kernel/lwevent_c.obj \
./MQXLITE/kernel/lwlog_c.obj \
./MQXLITE/kernel/lwmsgq_c.obj \
./MQXLITE/kernel/lwsem_c.obj \
./MQXLITE/kernel/lwtimer_c.obj \
./MQXLITE/kernel/mqx_utils_c.obj \
./MQXLITE/kernel/mqxlite_c.obj \
./MQXLITE/kernel/mutex_c.obj \
./MQXLITE/kernel/qu_test_c.obj \
./MQXLITE/kernel/sched_c.obj \
./MQXLITE/kernel/task_c.obj \
./MQXLITE/kernel/time_ticks_c.obj \

OBJS_QUOTED += \
"./MQXLITE/kernel/idletask_c.obj" \
"./MQXLITE/kernel/int_c.obj" \
"./MQXLITE/kernel/klog_c.obj" \
"./MQXLITE/kernel/lwevent_c.obj" \
"./MQXLITE/kernel/lwlog_c.obj" \
"./MQXLITE/kernel/lwmsgq_c.obj" \
"./MQXLITE/kernel/lwsem_c.obj" \
"./MQXLITE/kernel/lwtimer_c.obj" \
"./MQXLITE/kernel/mqx_utils_c.obj" \
"./MQXLITE/kernel/mqxlite_c.obj" \
"./MQXLITE/kernel/mutex_c.obj" \
"./MQXLITE/kernel/qu_test_c.obj" \
"./MQXLITE/kernel/sched_c.obj" \
"./MQXLITE/kernel/task_c.obj" \
"./MQXLITE/kernel/time_ticks_c.obj" \

C_DEPS += \
./MQXLITE/kernel/idletask.d \
./MQXLITE/kernel/int.d \
./MQXLITE/kernel/klog.d \
./MQXLITE/kernel/lwevent.d \
./MQXLITE/kernel/lwlog.d \
./MQXLITE/kernel/lwmsgq.d \
./MQXLITE/kernel/lwsem.d \
./MQXLITE/kernel/lwtimer.d \
./MQXLITE/kernel/mqx_utils.d \
./MQXLITE/kernel/mqxlite.d \
./MQXLITE/kernel/mutex.d \
./MQXLITE/kernel/qu_test.d \
./MQXLITE/kernel/sched.d \
./MQXLITE/kernel/task.d \
./MQXLITE/kernel/time_ticks.d \

OBJS_OS_FORMAT += \
./MQXLITE/kernel/idletask_c.obj \
./MQXLITE/kernel/int_c.obj \
./MQXLITE/kernel/klog_c.obj \
./MQXLITE/kernel/lwevent_c.obj \
./MQXLITE/kernel/lwlog_c.obj \
./MQXLITE/kernel/lwmsgq_c.obj \
./MQXLITE/kernel/lwsem_c.obj \
./MQXLITE/kernel/lwtimer_c.obj \
./MQXLITE/kernel/mqx_utils_c.obj \
./MQXLITE/kernel/mqxlite_c.obj \
./MQXLITE/kernel/mutex_c.obj \
./MQXLITE/kernel/qu_test_c.obj \
./MQXLITE/kernel/sched_c.obj \
./MQXLITE/kernel/task_c.obj \
./MQXLITE/kernel/time_ticks_c.obj \

C_DEPS_QUOTED += \
"./MQXLITE/kernel/idletask.d" \
"./MQXLITE/kernel/int.d" \
"./MQXLITE/kernel/klog.d" \
"./MQXLITE/kernel/lwevent.d" \
"./MQXLITE/kernel/lwlog.d" \
"./MQXLITE/kernel/lwmsgq.d" \
"./MQXLITE/kernel/lwsem.d" \
"./MQXLITE/kernel/lwtimer.d" \
"./MQXLITE/kernel/mqx_utils.d" \
"./MQXLITE/kernel/mqxlite.d" \
"./MQXLITE/kernel/mutex.d" \
"./MQXLITE/kernel/qu_test.d" \
"./MQXLITE/kernel/sched.d" \
"./MQXLITE/kernel/task.d" \
"./MQXLITE/kernel/time_ticks.d" \


# Each subdirectory must supply rules for building sources it contributes
MQXLITE/kernel/idletask_c.obj: ../MQXLITE/kernel/idletask.c
	@echo 'Building file: $<'
	@echo 'Executing target #27 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"MQXLITE/kernel/idletask.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"MQXLITE/kernel/idletask_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

MQXLITE/kernel/int_c.obj: ../MQXLITE/kernel/int.c
	@echo 'Building file: $<'
	@echo 'Executing target #28 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"MQXLITE/kernel/int.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"MQXLITE/kernel/int_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

MQXLITE/kernel/klog_c.obj: ../MQXLITE/kernel/klog.c
	@echo 'Building file: $<'
	@echo 'Executing target #29 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"MQXLITE/kernel/klog.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"MQXLITE/kernel/klog_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

MQXLITE/kernel/lwevent_c.obj: ../MQXLITE/kernel/lwevent.c
	@echo 'Building file: $<'
	@echo 'Executing target #30 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"MQXLITE/kernel/lwevent.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"MQXLITE/kernel/lwevent_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

MQXLITE/kernel/lwlog_c.obj: ../MQXLITE/kernel/lwlog.c
	@echo 'Building file: $<'
	@echo 'Executing target #31 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"MQXLITE/kernel/lwlog.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"MQXLITE/kernel/lwlog_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

MQXLITE/kernel/lwmsgq_c.obj: ../MQXLITE/kernel/lwmsgq.c
	@echo 'Building file: $<'
	@echo 'Executing target #32 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"MQXLITE/kernel/lwmsgq.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"MQXLITE/kernel/lwmsgq_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

MQXLITE/kernel/lwsem_c.obj: ../MQXLITE/kernel/lwsem.c
	@echo 'Building file: $<'
	@echo 'Executing target #33 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"MQXLITE/kernel/lwsem.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"MQXLITE/kernel/lwsem_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

MQXLITE/kernel/lwtimer_c.obj: ../MQXLITE/kernel/lwtimer.c
	@echo 'Building file: $<'
	@echo 'Executing target #34 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"MQXLITE/kernel/lwtimer.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"MQXLITE/kernel/lwtimer_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

MQXLITE/kernel/mqx_utils_c.obj: ../MQXLITE/kernel/mqx_utils.c
	@echo 'Building file: $<'
	@echo 'Executing target #35 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"MQXLITE/kernel/mqx_utils.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"MQXLITE/kernel/mqx_utils_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

MQXLITE/kernel/mqxlite_c.obj: ../MQXLITE/kernel/mqxlite.c
	@echo 'Building file: $<'
	@echo 'Executing target #36 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"MQXLITE/kernel/mqxlite.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"MQXLITE/kernel/mqxlite_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

MQXLITE/kernel/mutex_c.obj: ../MQXLITE/kernel/mutex.c
	@echo 'Building file: $<'
	@echo 'Executing target #37 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"MQXLITE/kernel/mutex.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"MQXLITE/kernel/mutex_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

MQXLITE/kernel/qu_test_c.obj: ../MQXLITE/kernel/qu_test.c
	@echo 'Building file: $<'
	@echo 'Executing target #38 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"MQXLITE/kernel/qu_test.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"MQXLITE/kernel/qu_test_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

MQXLITE/kernel/sched_c.obj: ../MQXLITE/kernel/sched.c
	@echo 'Building file: $<'
	@echo 'Executing target #39 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"MQXLITE/kernel/sched.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"MQXLITE/kernel/sched_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

MQXLITE/kernel/task_c.obj: ../MQXLITE/kernel/task.c
	@echo 'Building file: $<'
	@echo 'Executing target #40 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"MQXLITE/kernel/task.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"MQXLITE/kernel/task_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

MQXLITE/kernel/time_ticks_c.obj: ../MQXLITE/kernel/time_ticks.c
	@echo 'Building file: $<'
	@echo 'Executing target #41 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" "$<" @"MQXLITE/kernel/time_ticks.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"MQXLITE/kernel/time_ticks_c.obj"
	@echo 'Finished building: $<'
	@echo ' '


