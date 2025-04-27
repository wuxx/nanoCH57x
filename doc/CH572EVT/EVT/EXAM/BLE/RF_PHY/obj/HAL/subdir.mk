################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/BLE/HAL/MCU.c \
F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/BLE/HAL/RTC.c \
F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/BLE/HAL/SLEEP.c 

OBJS += \
./HAL/MCU.o \
./HAL/RTC.o \
./HAL/SLEEP.o 

C_DEPS += \
./HAL/MCU.d \
./HAL/RTC.d \
./HAL/SLEEP.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/MCU.o: F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/BLE/HAL/MCU.c
	@	@	riscv-none-elf-gcc -march=rv32imc_zba_zbb_zbc_zbs_xw -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common --param=highcode-gen-section-name=1  -g -DDEBUG=0 -DCLK_OSC32K=2 -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\Startup" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\BLE\RF_PHY\APP\include" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\BLE\RF_PHY\Profile\include" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\BLE\HAL\include" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\Ld" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\BLE\LIB" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
HAL/RTC.o: F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/BLE/HAL/RTC.c
	@	@	riscv-none-elf-gcc -march=rv32imc_zba_zbb_zbc_zbs_xw -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common --param=highcode-gen-section-name=1  -g -DDEBUG=0 -DCLK_OSC32K=2 -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\Startup" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\BLE\RF_PHY\APP\include" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\BLE\RF_PHY\Profile\include" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\BLE\HAL\include" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\Ld" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\BLE\LIB" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
HAL/SLEEP.o: F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/BLE/HAL/SLEEP.c
	@	@	riscv-none-elf-gcc -march=rv32imc_zba_zbb_zbc_zbs_xw -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common --param=highcode-gen-section-name=1  -g -DDEBUG=0 -DCLK_OSC32K=2 -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\Startup" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\BLE\RF_PHY\APP\include" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\BLE\RF_PHY\Profile\include" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\BLE\HAL\include" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\Ld" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\BLE\LIB" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

