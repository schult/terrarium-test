cmake_minimum_required(VERSION 3.20)
project(TerrariumTest VERSION 1.0.0)

set(FIRMWARE_NAME TerrariumTest)
set(FIRMWARE_SOURCES
    main.cpp
    syscalls.c
    util/Led.h
    util/Led.cpp
    util/Terrarium.h
    util/Terrarium.cpp
)
set(LIBDAISY_DIR ${CMAKE_SOURCE_DIR}/lib/libDaisy)
include(${LIBDAISY_DIR}/cmake/default_build.cmake)

target_include_directories(${FIRMWARE_NAME} PRIVATE ${CMAKE_SOURCE_DIR})

target_link_options(${FIRMWARE_NAME} PRIVATE
    -u _printf_float
    -flto=auto
    LINKER:--no-warn-rwx-segments
)
