cmake_minimum_required(VERSION 3.13)

# Set path to Pico SDK
set(PICO_SDK_PATH "C:/Users/jonat/Downloads/TBRT stuff/PicoFreeRTOS code/pico-sdk-master")
include("${PICO_SDK_PATH}/pico_sdk_import.cmake")

project(PicoFreeRTOSProj C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize Pico SDK
pico_sdk_init()

# Create executable
add_executable(main main.c)

# Include directories for FreeRTOS, FreeRTOSConfig.h, and Pico SDK
target_include_directories(main PRIVATE
    "C:/Users/jonat/Downloads/TBRT stuff/PicoFreeRTOS code/FreeRTOS-LTS-202406-LTS/FreeRTOS/FreeRTOS-Kernel/include"
    "C:/Users/jonat/Downloads/TBRT stuff/PicoFreeRTOS code/FreeRTOS-LTS-202406-LTS/FreeRTOS/FreeRTOS-Kernel/portable/template"
    "${CMAKE_CURRENT_LIST_DIR}"  # <-- this picks up FreeRTOSConfig.h in project folder
    "${PICO_SDK_PATH}/src/common/pico_stdlib/include"
)


# Link libraries
target_link_libraries(main pico_stdlib FreeRTOS-Kernel)

# Enable USB output, disable UART
pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)

# Generate UF2 file for flashing Pico
pico_add_extra_outputs(main)
