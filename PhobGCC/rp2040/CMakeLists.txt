cmake_minimum_required(VERSION 3.12)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(phobgcc_rp2040 CXX C ASM)

pico_sdk_init()
include(FetchContent)

FetchContent_Declare(
    pico_rectangle
    GIT_REPOSITORY https://github.com/JulienBernard3383279/pico-rectangle.git
    GIT_TAG master
)

FetchContent_GetProperties(pico_rectangle)

if(NOT pico_rectangle_POPULATED)
    FetchContent_Populate(pico_rectangle)
endif()

set(CMAKE_CXX_FLAGS "-O3 -mcpu=cortex-m0plus -mthumb")

include_directories(
	include
	../common
	../extras
	)

add_executable(phobgcc_rp2040
	src/cvideo.cpp
	src/drawGraphics.cpp
	src/drawImage.cpp
	src/drawMenu.cpp
	src/graph.cpp
	src/joybus.cpp
	src/main.cpp
	src/navigateMenu.cpp
	src/ws2812.cpp
	src/storage.cpp
	src/games/ping.cpp
	)

target_sources(phobgcc_rp2040 PRIVATE
    ${pico_rectangle_SOURCE_DIR}/src/communication_protocols/usb.cpp
    ${pico_rectangle_SOURCE_DIR}/src/usb_configurations/gcc_to_usb_adapter.cpp
)

target_include_directories(phobgcc_rp2040 PRIVATE
    ${pico_rectangle_SOURCE_DIR}/include
)

pico_generate_pio_header(phobgcc_rp2040 ${CMAKE_CURRENT_LIST_DIR}/pio/joybus.pio)
pico_generate_pio_header(phobgcc_rp2040 ${CMAKE_CURRENT_LIST_DIR}/pio/cvideo.pio)
pico_generate_pio_header(phobgcc_rp2040 ${CMAKE_CURRENT_LIST_DIR}/pio/ws2812.pio)

add_custom_command(OUTPUT ${CMAKE_CURRENT_LIST_DIR}/generated/joybus.pio.h
	DEPENDS ${CMAKE_CURRENT_LIST_DIR}/joybus.pio
	COMMAND Pioasm ${CMAKE_CURRENT_LIST_DIR}/joybus.pio ${CMAKE_CURRENT_LIST_DIR}/generated/joybus.pio.h
	)

add_custom_command(OUTPUT ${CMAKE_CURRENT_LIST_DIR}/generated/cvideo.pio.h
	DEPENDS ${CMAKE_CURRENT_LIST_DIR}/cvideo.pio
	COMMAND Pioasm ${CMAKE_CURRENT_LIST_DIR}/cvideo.pio ${CMAKE_CURRENT_LIST_DIR}/generated/cvideo.pio.h
	)

add_custom_command(OUTPUT ${CMAKE_CURRENT_LIST_DIR}/generated/ws2812.pio.h
	DEPENDS ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio
	COMMAND Pioasm ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio ${CMAKE_CURRENT_LIST_DIR}/generated/ws2812.pio.h
	)

target_compile_definitions(phobgcc_rp2040
	PRIVATE
	PICO_XOSC_STARTUP_DELAY_MULTIPLIER=64
	#PICO_DEFAULT_BOOT_STAGE2=boot2_generic_03h
	#PICO_FLASH_SPI_CLKDIV=8
	)

target_link_libraries(phobgcc_rp2040
	PRIVATE
	pico_stdlib
	pico_bootrom
	pico_multicore
	pico_platform
	hardware_adc
	hardware_dma
	hardware_flash
	hardware_pio
	hardware_pwm
	hardware_spi
	hardware_sync
	hardware_timer
	hardware_resets
	hardware_irq)

pico_add_extra_outputs(phobgcc_rp2040)
pico_enable_stdio_usb(phobgcc_rp2040 0)
