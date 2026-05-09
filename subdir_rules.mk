################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
ADC1.o: /Users/yashas_bv/Documents/MSPM0_ValvanoWare\ (1)/inc/ADC1.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs2040/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9" -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9/Debug" -I"/Applications/ti/mspm0_sdk_2_09_00_01/source/third_party/CMSIS/Core/Include" -I"/Applications/ti/mspm0_sdk_2_09_00_01/source" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"ADC1.d_raw" -MT"ADC1.o" -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Arabic.o: /Users/yashas_bv/Documents/MSPM0_ValvanoWare\ (1)/inc/Arabic.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs2040/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9" -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9/Debug" -I"/Applications/ti/mspm0_sdk_2_09_00_01/source/third_party/CMSIS/Core/Include" -I"/Applications/ti/mspm0_sdk_2_09_00_01/source" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"Arabic.d_raw" -MT"Arabic.o" -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Clock.o: /Users/yashas_bv/Documents/MSPM0_ValvanoWare\ (1)/inc/Clock.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs2040/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9" -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9/Debug" -I"/Applications/ti/mspm0_sdk_2_09_00_01/source/third_party/CMSIS/Core/Include" -I"/Applications/ti/mspm0_sdk_2_09_00_01/source" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"Clock.d_raw" -MT"Clock.o" -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs2040/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9" -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9/Debug" -I"/Applications/ti/mspm0_sdk_2_09_00_01/source/third_party/CMSIS/Core/Include" -I"/Applications/ti/mspm0_sdk_2_09_00_01/source" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)" -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

DAC5.o: /Users/yashas_bv/Documents/MSPM0_ValvanoWare\ (1)/inc/DAC5.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs2040/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9" -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9/Debug" -I"/Applications/ti/mspm0_sdk_2_09_00_01/source/third_party/CMSIS/Core/Include" -I"/Applications/ti/mspm0_sdk_2_09_00_01/source" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"DAC5.d_raw" -MT"DAC5.o" -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

LaunchPad.o: /Users/yashas_bv/Documents/MSPM0_ValvanoWare\ (1)/inc/LaunchPad.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs2040/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9" -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9/Debug" -I"/Applications/ti/mspm0_sdk_2_09_00_01/source/third_party/CMSIS/Core/Include" -I"/Applications/ti/mspm0_sdk_2_09_00_01/source" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"LaunchPad.d_raw" -MT"LaunchPad.o" -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

SPI.o: /Users/yashas_bv/Documents/MSPM0_ValvanoWare\ (1)/inc/SPI.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs2040/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9" -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9/Debug" -I"/Applications/ti/mspm0_sdk_2_09_00_01/source/third_party/CMSIS/Core/Include" -I"/Applications/ti/mspm0_sdk_2_09_00_01/source" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"SPI.d_raw" -MT"SPI.o" -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

ST7735.o: /Users/yashas_bv/Documents/MSPM0_ValvanoWare\ (1)/inc/ST7735.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs2040/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9" -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9/Debug" -I"/Applications/ti/mspm0_sdk_2_09_00_01/source/third_party/CMSIS/Core/Include" -I"/Applications/ti/mspm0_sdk_2_09_00_01/source" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"ST7735.d_raw" -MT"ST7735.o" -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

TExaS.o: /Users/yashas_bv/Documents/MSPM0_ValvanoWare\ (1)/inc/TExaS.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs2040/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9" -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9/Debug" -I"/Applications/ti/mspm0_sdk_2_09_00_01/source/third_party/CMSIS/Core/Include" -I"/Applications/ti/mspm0_sdk_2_09_00_01/source" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"TExaS.d_raw" -MT"TExaS.o" -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Timer.o: /Users/yashas_bv/Documents/MSPM0_ValvanoWare\ (1)/inc/Timer.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs2040/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang" -c -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9" -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9/Debug" -I"/Applications/ti/mspm0_sdk_2_09_00_01/source/third_party/CMSIS/Core/Include" -I"/Applications/ti/mspm0_sdk_2_09_00_01/source" -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"Timer.d_raw" -MT"Timer.o" -I"/Users/yashas_bv/Documents/MSPM0_ValvanoWare (1)/ECE319K_Lab9/Debug/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


