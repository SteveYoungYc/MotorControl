################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Events.c" \
"../Sources/PID.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/Events.c \
../Sources/PID.c \
../Sources/main.c \

OBJS += \
./Sources/Events_c.obj \
./Sources/PID_c.obj \
./Sources/main_c.obj \

OBJS_QUOTED += \
"./Sources/Events_c.obj" \
"./Sources/PID_c.obj" \
"./Sources/main_c.obj" \

C_DEPS += \
./Sources/Events_c.d \
./Sources/PID_c.d \
./Sources/main_c.d \

C_DEPS_QUOTED += \
"./Sources/Events_c.d" \
"./Sources/PID_c.d" \
"./Sources/main_c.d" \

OBJS_OS_FORMAT += \
./Sources/Events_c.obj \
./Sources/PID_c.obj \
./Sources/main_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/Events_c.obj: ../Sources/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: DSC Compiler'
	"$(DSC_ToolsDirEnv)/mwcc56800e" -c @@"Sources/Events.args" -o "Sources/Events_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/PID_c.obj: ../Sources/PID.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: DSC Compiler'
	"$(DSC_ToolsDirEnv)/mwcc56800e" -c @@"Sources/PID.args" -o "Sources/PID_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: DSC Compiler'
	"$(DSC_ToolsDirEnv)/mwcc56800e" -c @@"Sources/main.args" -o "Sources/main_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


