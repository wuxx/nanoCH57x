################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/Startup/startup_CH572.S 

OBJS += \
./Startup/startup_CH572.o 

S_UPPER_DEPS += \
./Startup/startup_CH572.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/startup_CH572.o: F:/private/nanoCH57x-private/doc/CH572EVT/EVT/EXAM/SRC/Startup/startup_CH572.S
	@	@	riscv-none-elf-gcc -march=rv32imc_zba_zbb_zbc_zbs_xw -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common --param=highcode-gen-section-name=1  -g -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

