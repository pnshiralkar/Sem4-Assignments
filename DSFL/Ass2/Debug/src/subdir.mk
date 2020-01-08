################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Ass2.cpp \
../src/LinkedList.cpp \
../src/PriorityQueue.cpp 

OBJS += \
./src/Ass2.o \
./src/LinkedList.o \
./src/PriorityQueue.o 

CPP_DEPS += \
./src/Ass2.d \
./src/LinkedList.d \
./src/PriorityQueue.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


