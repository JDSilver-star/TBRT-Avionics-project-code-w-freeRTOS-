cmake_minimum_required(VERSION 3.13)

# Set path to Pico SDK - use environment variable or local path
if(DEFINED ENV{PICO_SDK_PATH})
    set(PICO_SDK_PATH $ENV{PICO_SDK_PATH})
else()
    set(PICO_SDK_PATH "${CMAKE_CURRENT_LIST_DIR}/pico-sdk")
endif()

# Include Pico SDK
include("${PICO_SDK_PATH}/external/pico_sdk_import.cmake")

# Set FreeRTOS Kernel path
set(FREERTOS_KERNEL_PATH "${CMAKE_CURRENT_LIST_DIR}/FreeRTOS-Kernel")

# Include FreeRTOS Kernel import
include("${FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake")

# Project definition
project(PicoFreeRTOSProj C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize Pico SDK
pico_sdk_init()

# Create main executable
add_executable(main
    main.c
)

# Add FreeRTOSConfig.h to include path
target_include_directories(main PRIVATE ${CMAKE_CURRENT_LIST_DIR})

# Link libraries to main
target_link_libraries(main
    pico_stdlib
    hardware_gpio
    FreeRTOS-Kernel
    FreeRTOS-Kernel-Heap4
)

# Enable USB output, disable UART
pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)

# Generate UF2 file for flashing Pico
pico_add_extra_outputs(main)
