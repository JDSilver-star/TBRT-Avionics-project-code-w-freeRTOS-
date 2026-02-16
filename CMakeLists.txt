cmake_minimum_required(VERSION 3.13)

# Tell CMake this is an embedded (bare-metal) build
set(CMAKE_SYSTEM_NAME Generic)

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

# Select Cortex-M33 Non-TrustZone port (for Pico 2 / RP2350)
set(FREERTOS_PORT GCC_ARM_CM33_NTZ CACHE STRING "" FORCE)

# Project definition
project(PicoFreeRTOSProj C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize Pico SDK
pico_sdk_init()

# Add FreeRTOS Kernel
add_subdirectory(${FREERTOS_KERNEL_PATH})

# Create main executable
add_executable(main
    main.c
)

# Add current directory to include path (for FreeRTOSConfig.h)
target_include_directories(main PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Link libraries
target_link_libraries(main
    pico_stdlib
    hardware_gpio
    FreeRTOS-Kernel
    FreeRTOS-Kernel-Heap4
)

# Enable USB output, disable UART
pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)

# Generate UF2
pico_add_extra_outputs(main)