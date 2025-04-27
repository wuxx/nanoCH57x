################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_clk.c \
F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_cmp.c \
F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_flash.c \
F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_gpio.c \
F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_i2c.c \
F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_keyscan.c \
F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_pwm.c \
F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_pwr.c \
F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_spi.c \
F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_sys.c \
F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_timer.c \
F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_uart.c \
F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_usbdev.c \
F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_usbhostBase.c \
F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_usbhostClass.c 

OBJS += \
./StdPeriphDriver/CH57x_clk.o \
./StdPeriphDriver/CH57x_cmp.o \
./StdPeriphDriver/CH57x_flash.o \
./StdPeriphDriver/CH57x_gpio.o \
./StdPeriphDriver/CH57x_i2c.o \
./StdPeriphDriver/CH57x_keyscan.o \
./StdPeriphDriver/CH57x_pwm.o \
./StdPeriphDriver/CH57x_pwr.o \
./StdPeriphDriver/CH57x_spi.o \
./StdPeriphDriver/CH57x_sys.o \
./StdPeriphDriver/CH57x_timer.o \
./StdPeriphDriver/CH57x_uart.o \
./StdPeriphDriver/CH57x_usbdev.o \
./StdPeriphDriver/CH57x_usbhostBase.o \
./StdPeriphDriver/CH57x_usbhostClass.o 

C_DEPS += \
./StdPeriphDriver/CH57x_clk.d \
./StdPeriphDriver/CH57x_cmp.d \
./StdPeriphDriver/CH57x_flash.d \
./StdPeriphDriver/CH57x_gpio.d \
./StdPeriphDriver/CH57x_i2c.d \
./StdPeriphDriver/CH57x_keyscan.d \
./StdPeriphDriver/CH57x_pwm.d \
./StdPeriphDriver/CH57x_pwr.d \
./StdPeriphDriver/CH57x_spi.d \
./StdPeriphDriver/CH57x_sys.d \
./StdPeriphDriver/CH57x_timer.d \
./StdPeriphDriver/CH57x_uart.d \
./StdPeriphDriver/CH57x_usbdev.d \
./StdPeriphDriver/CH57x_usbhostBase.d \
./StdPeriphDriver/CH57x_usbhostClass.d 


# Each subdirectory must supply rules for building sources it contributes
StdPeriphDriver/CH57x_clk.o: F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_clk.c
	@	@	riscv-none-elf-gcc -march=rv32imc_zba_zbb_zbc_zbs_xw -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common --param=highcode-gen-section-name=1  -g -DDEBUG=1 -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\UART\src" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_cmp.o: F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_cmp.c
	@	@	riscv-none-elf-gcc -march=rv32imc_zba_zbb_zbc_zbs_xw -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common --param=highcode-gen-section-name=1  -g -DDEBUG=1 -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\UART\src" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_flash.o: F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_flash.c
	@	@	riscv-none-elf-gcc -march=rv32imc_zba_zbb_zbc_zbs_xw -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common --param=highcode-gen-section-name=1  -g -DDEBUG=1 -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\UART\src" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_gpio.o: F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_gpio.c
	@	@	riscv-none-elf-gcc -march=rv32imc_zba_zbb_zbc_zbs_xw -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common --param=highcode-gen-section-name=1  -g -DDEBUG=1 -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\UART\src" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_i2c.o: F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_i2c.c
	@	@	riscv-none-elf-gcc -march=rv32imc_zba_zbb_zbc_zbs_xw -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common --param=highcode-gen-section-name=1  -g -DDEBUG=1 -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\UART\src" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_keyscan.o: F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_keyscan.c
	@	@	riscv-none-elf-gcc -march=rv32imc_zba_zbb_zbc_zbs_xw -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common --param=highcode-gen-section-name=1  -g -DDEBUG=1 -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\UART\src" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_pwm.o: F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_pwm.c
	@	@	riscv-none-elf-gcc -march=rv32imc_zba_zbb_zbc_zbs_xw -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common --param=highcode-gen-section-name=1  -g -DDEBUG=1 -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\UART\src" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_pwr.o: F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_pwr.c
	@	@	riscv-none-elf-gcc -march=rv32imc_zba_zbb_zbc_zbs_xw -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common --param=highcode-gen-section-name=1  -g -DDEBUG=1 -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\UART\src" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_spi.o: F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_spi.c
	@	@	riscv-none-elf-gcc -march=rv32imc_zba_zbb_zbc_zbs_xw -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common --param=highcode-gen-section-name=1  -g -DDEBUG=1 -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\UART\src" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_sys.o: F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_sys.c
	@	@	riscv-none-elf-gcc -march=rv32imc_zba_zbb_zbc_zbs_xw -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common --param=highcode-gen-section-name=1  -g -DDEBUG=1 -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\UART\src" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_timer.o: F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_timer.c
	@	@	riscv-none-elf-gcc -march=rv32imc_zba_zbb_zbc_zbs_xw -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common --param=highcode-gen-section-name=1  -g -DDEBUG=1 -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\UART\src" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_uart.o: F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_uart.c
	@	@	riscv-none-elf-gcc -march=rv32imc_zba_zbb_zbc_zbs_xw -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common --param=highcode-gen-section-name=1  -g -DDEBUG=1 -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\UART\src" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_usbdev.o: F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_usbdev.c
	@	@	riscv-none-elf-gcc -march=rv32imc_zba_zbb_zbc_zbs_xw -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common --param=highcode-gen-section-name=1  -g -DDEBUG=1 -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\UART\src" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_usbhostBase.o: F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_usbhostBase.c
	@	@	riscv-none-elf-gcc -march=rv32imc_zba_zbb_zbc_zbs_xw -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common --param=highcode-gen-section-name=1  -g -DDEBUG=1 -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\UART\src" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
StdPeriphDriver/CH57x_usbhostClass.o: F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/StdPeriphDriver/CH57x_usbhostClass.c
	@	@	riscv-none-elf-gcc -march=rv32imc_zba_zbb_zbc_zbs_xw -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common --param=highcode-gen-section-name=1  -g -DDEBUG=1 -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\StdPeriphDriver\inc" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\UART\src" -I"F:\private\nanoCH57x-private\doc\CH572EVT\EVT\EXAM\SRC\RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

