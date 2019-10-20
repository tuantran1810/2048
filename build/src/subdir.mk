################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
CPP_SRCS += \
../src/board_game.cpp \
../src/game_controller.cpp \
../src/main.cpp \
../src/tile.cpp \
../src/tile_array.cpp

OBJS += \
./src/board_game.o \
./src/game_controller.o \
./src/main.o \
./src/tile.o \
./src/tile_array.o

CPP_DEPS += \
./src/board_game.d \
./src/game_controller.d \
./src/main.d \
./src/tile.d \
./src/tile_array.d


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"./../inc" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++14 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


