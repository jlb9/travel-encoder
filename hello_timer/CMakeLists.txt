cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(hello_timer C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(hello_timer
        hello_timer.c
        )

# pull in common dependencies
target_link_libraries(hello_timer pico_stdlib)

# create map/bin/hex file etc.
pico_enable_stdio_usb(hello_timer 1)
pico_enable_stdio_uart(hello_timer 1)
pico_add_extra_outputs(hello_timer pico_stdlib)

# add url via pico_set_program_url
#example_auto_set_url(hello_timer)
