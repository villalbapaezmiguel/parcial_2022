################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Albumes.c \
../src/Listar.c \
../src/Parcial_1_Laboratorio.c \
../src/utn.c 

OBJS += \
./src/Albumes.o \
./src/Listar.o \
./src/Parcial_1_Laboratorio.o \
./src/utn.o 

C_DEPS += \
./src/Albumes.d \
./src/Listar.d \
./src/Parcial_1_Laboratorio.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


