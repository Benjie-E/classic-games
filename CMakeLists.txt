cmake_minimum_required(VERSION 3.24)  # CMake version check
set(VCPKG_TARGET_ARCHITECTURE x64)

project(ClassicGames)               # Create project 
set(CMAKE_CXX_STANDARD 20)            # Enable c++20 standard

# Add source files
set(SOURCE_FILES WordleCode/WordleGameManager.cpp
WordleCode/WordleScreenManager.cpp
WordleCode/Wordle.cpp
GameSelector.cpp
main.cpp
HangmanCode/HangmanGameManager.cpp
HangmanCode/Hangman.cpp
HangmanCode/HangmanScreenManager.cpp
connect4/connect4.cpp
connect4/DisplayManager.cpp
connect4/connect4GameManager.cpp
TicTacToeCode/ttt.cpp
TicTacToeCode/ttt_functions.cpp
common/Location.cpp
SnakeCode/Apple.cpp
SnakeCode/Snake.cpp
SnakeCode/SnakeGame.cpp
SnakeCode/SnakeGameManager.cpp
SnakeCode/SnakeScreenManager.cpp
SnakeCode/Timer.cpp
)

# add .h files
include_directories(connect4/DisplayManager.h
connect4/GameManager.h
HangmanCode/Hangman/Hangman.h
HangmanCode/Hangman/GameManager.h
HangmanCode/Hangman/ScreenManager.h
TicTacToeCode/TicTacToe/TicTacToe/ttt_functions.h
WordleCode/Wordle/Wordle/GameManager.h
WordleCode/Wordle/Wordle/ScreenManager.h
path.h
SnakeCode/Apple.h
SnakeCode/Snake.h
SnakeCode/SnakeGame.h
SnakeCode/SnakeGameManager.h
SnakeCode/SnakeScreenManager.h
SnakeCode/Timer.h)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(ClassicGames ${SOURCE_FILES})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/HangmanCode/hangmanWords.txt ${CMAKE_CURRENT_BINARY_DIR}/hangmanWords.txt COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/WordleCode/wordleWords.txt ${CMAKE_CURRENT_BINARY_DIR}/wordleWords.txt COPYONLY)

	 
find_path(PDC_INCLUDES curses.h)
find_library(PDC_LIBS pdcurses REQUIRED)
target_include_directories(ClassicGames PRIVATE ${PDC_INCLUDES})
target_link_libraries(ClassicGames PRIVATE ${PDC_LIBS})