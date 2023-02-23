list(APPEND SOURCES
     addch.c
     addchstr.c
     addstr.c
     attr.c
     beep.c
     bkgd.c
     border.c
     clear.c
     color.c
     debug.c
     delch.c
     deleteln.c
     deprec.c
     getch.c
     getstr.c
     getyx.c
     inch.c
     inchstr.c
     initscr.c
     inopts.c
     insch.c
     insstr.c
     instr.c
     kernel.c
     keyname.c
     mouse.c
     move.c
     outopts.c
     overlay.c
     pad.c
     panel.c
     printw.c
     refresh.c
     scanw.c
     scr_dump.c
     scroll.c
     slk.c
     termattr.c
     terminfo.c
     touch.c
     util.c
     window.c)
foreach(file ${SOURCES})
  list(APPEND MAIN_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/${file})
endforeach()
set(MAIN_SOURCES ${MAIN_SOURCES} PARENT_SCOPE)

