################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/interacciones.cpp \
../src/juego.cpp \
../src/jugadores.cpp \
../src/principal.cpp \
../src/tablero.cpp 

OBJS += \
./src/interacciones.o \
./src/juego.o \
./src/jugadores.o \
./src/principal.o \
./src/tablero.o 

CPP_DEPS += \
./src/interacciones.d \
./src/juego.d \
./src/jugadores.d \
./src/principal.d \
./src/tablero.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


