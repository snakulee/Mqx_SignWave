################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 54
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := "$(GNU_Make_Install_DirEnv)/rm -rf"

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Sources/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include MQXLITE/psp/cortex_m/subdir.mk
-include MQXLITE/psp/cortex_m/core/M0/subdir.mk
-include MQXLITE/kernel/subdir.mk
-include Generated_Code/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(SX_DEPS)),)
-include $(SX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Mqx_Lite_Test.elf \

EXECUTABLES_QUOTED += \
"Mqx_Lite_Test.elf" \

EXECUTABLES_OS_FORMAT += \
Mqx_Lite_Test.elf \

SECONDARY_FLASH += \
Mqx_Lite_Test.hex \

SECONDARY_FLASH_QUOTED += \
"Mqx_Lite_Test.hex" \

SECONDARY_FLASH_OS_FORMAT += \
Mqx_Lite_Test.hex \

SECONDARY_SIZE += \
Mqx_Lite_Test.siz \

SECONDARY_SIZE_QUOTED += \
"Mqx_Lite_Test.siz" \

SECONDARY_SIZE_OS_FORMAT += \
Mqx_Lite_Test.siz \


# All Target
all: Mqx_Lite_Test.elf secondary-outputs

# Tool invocations
Mqx_Lite_Test.elf: $(OBJS) $(USER_OBJS) ../Project_Settings/Linker_Files/ProcessorExpert.ld
	@echo 'Building target: $@'
	@echo 'Executing target #55 $@'
	@echo 'Invoking: ARM Ltd Windows GCC C Linker'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-gcc" $(OBJS_QUOTED) $(USER_OBJS_QUOTED) $(LIBS_QUOTED) -T"$(ProjDirPath)/Project_Settings/Linker_Files/ProcessorExpert.ld" -Xlinker --gc-sections -L"$(MCUToolsBaseDirEnv)/ARM_GCC_Support/ewl/lib/armv6-m" -Wl,-Map,Mqx_Lite_Test.map -n -specs=ewl_c.specs -Xlinker --undefined=__pformatter_ -Xlinker --defsym=__pformatter=__pformatter_ -Xlinker --undefined=__sformatter -Xlinker --defsym=__sformatter=__sformatter -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Mqx_Lite_Test.elf"
	@echo 'Finished building target: $@'
	@echo ' '

Mqx_Lite_Test.hex: Mqx_Lite_Test.elf
	@echo 'Executing target #56 $@'
	@echo 'Invoking: ARM Ltd Windows GNU Create Flash Image'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-objcopy"  -O ihex Mqx_Lite_Test.elf "Mqx_Lite_Test.hex"
	@echo 'Finished building: $@'
	@echo ' '

Mqx_Lite_Test.siz: Mqx_Lite_Test.elf
	@echo 'Executing target #57 $@'
	@echo 'Invoking: ARM Ltd Windows GNU Print Size'
	"$(CWInstallLocationEnv)/Cross_Tools/arm-none-eabi-gcc-4_7_3/bin/arm-none-eabi-size"  --format=berkeley Mqx_Lite_Test.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(S_DEPS_QUOTED) $(SECONDARY_FLASH_QUOTED) "./*/*.obj" "./*/*/*.obj" "./*/*/*/*/*/*.obj" "./*/*/*/*.obj"  "./*/*/*/*/*/*.d"  $(ASM_DEPS_QUOTED) $(SECONDARY_SIZE_QUOTED) $(ASM_UPPER_DEPS_QUOTED) $(SX_DEPS_QUOTED) $(EXECUTABLES_QUOTED) "./*/*.d" "./*/*/*.d" "./*/*/*/*.d"  $(ProjDirPath)/FLASH/Mqx_Lite_Test.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
