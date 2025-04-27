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
-include Profile/subdir.mk
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
HID_Consumer.hex \

SECONDARY_LIST += \
HID_Consumer.lst \

SECONDARY_SIZE += \
HID_Consumer.siz \


# All Target
all: HID_Consumer.elf secondary-outputs

# Tool invocations
HID_Consumer.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-elf-gcc -march=rv32imc_zba_zbb_zbc_zbs_xw -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common --param=highcode-gen-section-name=1  -g -T "F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -L"../" -L"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\BLE\LIB" -L"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\StdPeriphDriver" -Xlinker --print-memory-usage -Wl,-Map,"HID_Consumer.map" --specs=nano.specs --specs=nosys.specs -o "HID_Consumer.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
HID_Consumer.hex: HID_Consumer.elf
	@	riscv-none-elf-objcopy -O ihex "HID_Consumer.elf"  "HID_Consumer.hex"
	@	@
HID_Consumer.lst: HID_Consumer.elf
	@	riscv-none-elf-objdump --source --all-headers --demangle --line-numbers --wide -M xw "HID_Consumer.elf" > "HID_Consumer.lst"
	@	@
HID_Consumer.siz: HID_Consumer.elf
	@	riscv-none-elf-size --format=berkeley "HID_Consumer.elf"
	@	@
# Other Targets
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) HID_Consumer.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
