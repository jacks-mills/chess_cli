#ifndef _VIEW_H
#define _VIEW_H

#include "piece_definitions.h"

#define ESC "\033"

#define SCREEN_CLEAR()              printf(ESC "[2J")
#define SCREEN_INSERT_BLANKS(num)   printf(ESC "[%i@", (num))

#define CURSOR_MOVE_UP(steps)       printf(ESC "[%iA", (steps)) 
#define CURSOR_MOVE_DOWN(steps)     printf(ESC "[%iB", (steps)) 
#define CURSOR_MOVE_RIGHT(steps)    printf(ESC "[%iC", (steps)) 
#define CURSOR_MOVE_LEFT(steps)     printf(ESC "[%iD", (steps)) 
#define CURSOR_SET(row, col)        printf(ESC "[%i;%i;H", (row), (col))

#define GRAPHICS_RESET()            printf(ESC "[0m");
#define GRAPHICS_BG_COLOUR_SET(rgb) \
            printf(ESC "[48:2:%i:%i:%im", \
                ((rgb) >> (8 * 2) & 0xFF), \
                ((rgb) >> (8 * 1) & 0xFF), \
                ((rgb) >> (8 * 0) & 0xFF));
#define GRAPHICS_FG_COLOUR_SET(rgb) \
            printf(ESC "[38:2:%i:%i:%im", \
                ((rgb) >> (8 * 2) & 0xFF), \
                ((rgb) >> (8 * 1) & 0xFF), \
                ((rgb) >> (8 * 0) & 0xFF));


#define BOARD_COLOUR_DARK           0xB16E41
#define BOARD_COLOUR_LIGHT          0xFBD497

#define BOARD_COLOUR_WHITE_PIECE    0xFFFFFF
#define BOARD_COLOUR_BLACK_PIECE    0x000000


void view_init_screen();

void view_draw_piece(int rank, int file, int piece);


#endif //_VIEW_H
