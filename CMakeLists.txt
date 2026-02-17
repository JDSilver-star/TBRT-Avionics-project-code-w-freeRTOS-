cmake_minimum_required(VERSION 3.13)

set(CMAKE_SYSTEM_NAME Generic)

if(DEFINED ENV{PICO_SDK_PATH})
    set(PICO_SDK_PATH $ENV{PICO_SDK_PATH})
else()
    set(PICO_SDK_PATH "${CMAKE_CURRENT_LIST_DIR}/pico-sdk")
endif()

include("${PICO_SDK_PATH}/external/pico_sdk_import.cmake")

project(PicoFreeRTOSProj C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

# Select correct FreeRTOS port for Pico 2 (RP2350 Cortex-M33 NTZ)
set(FREERTOS_PORT GCC_ARM_CM33_NTZ CACHE STRING "" FORCE)

add_subdirectory(FreeRTOS-Kernel)

add_executable(main
    main.c
)

target_include_directories(main PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(main
    pico_stdlib
    hardware_gpio
    FreeRTOS-Kernel
    FreeRTOS-Kernel-Heap4
)

pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)

pico_add_extra_outputs(main)
