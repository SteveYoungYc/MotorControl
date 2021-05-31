################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(MCUToolsBaseDirEnv)/ProcessorExpert/PESL/56800/56F82xx/MSCAN.c" \

C_SRCS += \
$(MCUToolsBaseDirEnv_ESCAPED)/ProcessorExpert/PESL/56800/56F82xx/MSCAN.c \

OBJS += \
./External_Modules/MSCAN_c.obj \

OBJS_QUOTED += \
"./External_Modules/MSCAN_c.obj" \

C_DEPS += \
./External_Modules/MSCAN_c.d \

C_DEPS_QUOTED += \
"./External_Modules/MSCAN_c.d" \

OBJS_OS_FORMAT += \
./External_Modules/MSCAN_c.obj \


# Each subdirectory must supply rules for building sources it contributes
External_Modules/MSCAN_c.obj: $(MCUToolsBaseDirEnv_ESCAPED)/ProcessorExpert/PESL/56800/56F82xx/MSCAN.c
	@echo 'Building file: $<'
	@echo 'Executing target #33 $<'
	@echo 'Invoking: DSC Compiler'
	"$(DSC_ToolsDirEnv)/mwcc56800e" -c @@"External_Modules/MSCAN.args" -o "External_Modules/MSCAN_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

External_Modules/MSCAN_c.d: $(MCUToolsBaseDirEnv_ESCAPED)/ProcessorExpert/PESL/56800/56F82xx/MSCAN.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


