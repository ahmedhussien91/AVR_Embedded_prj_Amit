################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../Buzzer_LED.c \
../DIO.c \
../Door_locker_project.c \
../HMI_SYS.c \
../Keypad.c \
../LCD.c \
../UART.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
Buzzer_LED.o \
DIO.o \
Door_locker_project.o \
HMI_SYS.o \
Keypad.o \
LCD.o \
UART.o

OBJS_AS_ARGS +=  \
Buzzer_LED.o \
DIO.o \
Door_locker_project.o \
HMI_SYS.o \
Keypad.o \
LCD.o \
UART.o

C_DEPS +=  \
Buzzer_LED.d \
DIO.d \
Door_locker_project.d \
HMI_SYS.d \
Keypad.d \
LCD.d \
UART.d

C_DEPS_AS_ARGS +=  \
Buzzer_LED.d \
DIO.d \
Door_locker_project.d \
HMI_SYS.d \
Keypad.d \
LCD.d \
UART.d

OUTPUT_FILE_PATH +=Door_locker_HMI_ECU.elf

OUTPUT_FILE_PATH_AS_ARGS +=Door_locker_HMI_ECU.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

# AVR32/GNU C Compiler















./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 3.4.2
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.1002\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -funsigned-char -funsigned-bitfields -DDEBUG  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<"
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 3.4.2
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.1002\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="Door_locker_HMI_ECU.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega32 
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.1002\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "Door_locker_HMI_ECU.elf" "Door_locker_HMI_ECU.hex"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.1002\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "Door_locker_HMI_ECU.elf" "Door_locker_HMI_ECU.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.1002\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "Door_locker_HMI_ECU.elf" > "Door_locker_HMI_ECU.lss"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.1002\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature  "Door_locker_HMI_ECU.elf" "Door_locker_HMI_ECU.srec"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.1002\avr8-gnu-toolchain\bin\avr-size.exe" "Door_locker_HMI_ECU.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "Door_locker_HMI_ECU.elf" "Door_locker_HMI_ECU.a" "Door_locker_HMI_ECU.hex" "Door_locker_HMI_ECU.lss" "Door_locker_HMI_ECU.eep" "Door_locker_HMI_ECU.map" "Door_locker_HMI_ECU.srec"
	