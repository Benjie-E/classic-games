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



set(
CURSES_FILES dependencies/PDCurses-3.9/curses.h
dependencies/PDCurses-3.9/curspriv.h
dependencies/PDCurses-3.9/panel.h
dependencies/PDCurses-3.9/pdcurses/addch.c
dependencies/PDCurses-3.9/pdcurses/addchstr.c
dependencies/PDCurses-3.9/pdcurses/addstr.c
dependencies/PDCurses-3.9/pdcurses/attr.c
dependencies/PDCurses-3.9/pdcurses/beep.c
dependencies/PDCurses-3.9/pdcurses/bkgd.c
dependencies/PDCurses-3.9/pdcurses/border.c
dependencies/PDCurses-3.9/pdcurses/clear.c
dependencies/PDCurses-3.9/pdcurses/color.c
dependencies/PDCurses-3.9/pdcurses/debug.c
dependencies/PDCurses-3.9/pdcurses/delch.c
dependencies/PDCurses-3.9/pdcurses/deleteln.c
dependencies/PDCurses-3.9/pdcurses/getch.c
dependencies/PDCurses-3.9/pdcurses/getstr.c
dependencies/PDCurses-3.9/pdcurses/getyx.c
dependencies/PDCurses-3.9/pdcurses/inch.c
dependencies/PDCurses-3.9/pdcurses/inchstr.c
dependencies/PDCurses-3.9/pdcurses/initscr.c
dependencies/PDCurses-3.9/pdcurses/inopts.c
dependencies/PDCurses-3.9/pdcurses/insch.c
dependencies/PDCurses-3.9/pdcurses/insstr.c
dependencies/PDCurses-3.9/pdcurses/instr.c
dependencies/PDCurses-3.9/pdcurses/kernel.c
dependencies/PDCurses-3.9/pdcurses/keyname.c
dependencies/PDCurses-3.9/pdcurses/mouse.c
dependencies/PDCurses-3.9/pdcurses/move.c
dependencies/PDCurses-3.9/pdcurses/outopts.c
dependencies/PDCurses-3.9/pdcurses/overlay.c
dependencies/PDCurses-3.9/pdcurses/pad.c
dependencies/PDCurses-3.9/pdcurses/panel.c
dependencies/PDCurses-3.9/pdcurses/printw.c
dependencies/PDCurses-3.9/pdcurses/refresh.c
dependencies/PDCurses-3.9/pdcurses/scanw.c
dependencies/PDCurses-3.9/pdcurses/scr_dump.c
dependencies/PDCurses-3.9/pdcurses/scroll.c
dependencies/PDCurses-3.9/pdcurses/slk.c
dependencies/PDCurses-3.9/pdcurses/termattr.c
dependencies/PDCurses-3.9/pdcurses/touch.c
dependencies/PDCurses-3.9/pdcurses/util.c
dependencies/PDCurses-3.9/pdcurses/window.c
)

add_library(pdcurses ${CURSES_FILES})


# Add executable target with source files listed in SOURCE_FILES variable
add_executable(ClassicGames ${SOURCE_FILES})

target_link_libraries(ClassicGames PRIVATE pdcurses)