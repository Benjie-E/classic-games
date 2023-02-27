cmake_minimum_required(VERSION 3.26.0)  # CMake version check
project(ClassicGames C CXX)               # Create project 
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add source files
set(SOURCE_FILES GameSelector.cpp
main.cpp
HangmanCode/HangmanGameManager.cpp
HangmanCode/Hangman.cpp
HangmanCode/HangmanScreenManager.cpp
connect4/connect4.cpp
connect4/DisplayManager.cpp
connect4/connect4GameManager.cpp
TicTacToeCode/ttt.cpp
TicTacToeCode/ttt_functions.cpp
WordleCode/WordleGameManager.cpp
WordleCode/main.cpp
WordleCode/WordleScreenManager.cpp)

# add .h files
include_directories(connect4/DisplayManager.h
connect4/GameManager.h
HangmanCode/Hangman/Hangman.h
HangmanCode/Hangman/GameManager.h
HangmanCode/Hangman/ScreenManager.h
TicTacToeCode/TicTacToe/TicTacToe/ttt_functions.h
WordleCode/Wordle/Wordle/GameManager.h
WordleCode/Wordle/Wordle/ScreenManager.h)



add_library(pdcurses
            ${SOURCE_FILES})

add_subdirectory(pdcurses)


# Export for external inclusion
export(TARGETS pdcurses FILE pdcurses-targets.cmake)
set(PDCURSES_TARGETS_FILE ${CMAKE_BINARY_DIR}/pdcurses-targets.cmake)
configure_file(pdcurses-config.cmake.in pdcurses-config.cmake)
export(PACKAGE pdcurses)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(ClassicGames ${SOURCE_FILES})

target_link_libraries(ClassicGames PUBLIC pdcurses)
target_include_directories(dependencies/PDcurses-3.9/curses.h
dependencies/PDcurses-3.9/curspriv.h
dependencies?PDCurses-3.9/panel.h)