################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BRapp.cpp \
../src/Controller.cpp \
../src/Motor.cpp \
../src/Network.cpp 

OBJS += \
./src/BRapp.o \
./src/Controller.o \
./src/Motor.o \
./src/Network.o 

CPP_DEPS += \
./src/BRapp.d \
./src/Controller.d \
./src/Motor.d \
./src/Network.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


