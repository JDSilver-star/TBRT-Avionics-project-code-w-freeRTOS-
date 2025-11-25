## prereqs

1. Clone https://github.com/FreeRTOS/FreeRTOS-Kernel
2. Clone https://github.com/raspberrypi/pico-sdk
    - Set PICO_SDK_PATH environment variable (optional)
3. Download CMAKE https://cmake.org/download/
    - Add to PATH
4. Download Ninja https://github.com/ninja-build/ninja/releases
    - Add to PATH
5. Download Arm GNU toolchain https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads
    - Download arm-gnu-toolchain-14.3.rel1-mingw-w64-i686-arm-none-eabi.exe
    - Add to PATH

## build commands

```bash
# Navigate to project directory
cd TBRT-Avionics-project-code-w-freeRTOS-

# Create build directory
mkdir build
cd build

# Configure with CMake
cmake -G Ninja -DCMAKE_BUILD_TYPE=Release ..

# Build
ninja


