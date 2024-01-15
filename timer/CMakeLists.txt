cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(timer C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(timer timer.c)

pico_enable_stdio_usb(timer 1)
pico_enable_stdio_uart(timer 1)
pico_add_extra_outputs(timer)

target_link_libraries(timer pico_stdlib)
