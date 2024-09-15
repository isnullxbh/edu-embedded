set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR cortex-m4)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mthumb -mcpu=cortex-m4 -std=c2x -ffreestanding -nostdlib -Wl,-Map=output.map")
set(CMAKE_EXE_LINKER_FLAGS "-T ${CMAKE_CURRENT_SOURCE_DIR}/scripts/linker/stm32f407vg.ld")
