cmake_minimum_required(VERSION 3.26.0)  # CMake version check
project(ClassicGames C CXX)               # Create project 
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES GameSelector.cpp)

add_library(pdcurses
            ${SOURCE_FILES})

# Export for external inclusion
export(TARGETS pdcurses FILE pdcurses-targets.cmake)
set(PDCURSES_TARGETS_FILE ${CMAKE_BINARY_DIR}/pdcurses-targets.cmake)
configure_file(pdcurses-config.cmake.in pdcurses-config.cmake)
export(PACKAGE pdcurses)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(ClassicGames ${SOURCE_FILES})