################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ReversePoem.cpp \
../ReversePoemTester.cpp \
../Stack.cpp \
../StackTester.cpp \
../main.cpp 

CPP_DEPS += \
./ReversePoem.d \
./ReversePoemTester.d \
./Stack.d \
./StackTester.d \
./main.d 

OBJS += \
./ReversePoem.o \
./ReversePoemTester.o \
./Stack.o \
./StackTester.o \
./main.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./ReversePoem.d ./ReversePoem.o ./ReversePoemTester.d ./ReversePoemTester.o ./Stack.d ./Stack.o ./StackTester.d ./StackTester.o ./main.d ./main.o

.PHONY: clean--2e-

