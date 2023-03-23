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

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(ClassicGames ${SOURCE_FILES})


set(CMAKE_TOOLCHAIN_FILE C:/Users/jgrot/vcpkg/scripts/buildsystems/vcpkg.cmake)
find_package(pdcurses CONFIG REQUIRED)

target_link_libraries(ClassicGames PRIVATE pdcurses)