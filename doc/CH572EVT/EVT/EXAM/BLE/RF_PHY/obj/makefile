################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include StdPeriphDriver/subdir.mk
-include Startup/subdir.mk
-include HAL/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
RF_PHY.hex \

SECONDARY_LIST += \
RF_PHY.lst \

SECONDARY_SIZE += \
RF_PHY.siz \


# All Target
all: RF_PHY.elf secondary-outputs

# Tool invocations
RF_PHY.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-elf-gcc -march=rv32imc_zba_zbb_zbc_zbs_xw -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common --param=highcode-gen-section-name=1  -g -T "F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -L"../" -L"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\BLE\LIB" -L"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\StdPeriphDriver" -Xlinker --print-memory-usage -Wl,-Map,"RF_PHY.map" --specs=nano.specs --specs=nosys.specs -o "RF_PHY.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
RF_PHY.hex: RF_PHY.elf
	@	riscv-none-elf-objcopy -O ihex "RF_PHY.elf"  "RF_PHY.hex"
	@	@
RF_PHY.lst: RF_PHY.elf
	@	riscv-none-elf-objdump --source --all-headers --demangle --line-numbers --wide -M xw "RF_PHY.elf" > "RF_PHY.lst"
	@	@
RF_PHY.siz: RF_PHY.elf
	@	riscv-none-elf-size --format=berkeley "RF_PHY.elf"
	@	@
# Other Targets
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) RF_PHY.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
