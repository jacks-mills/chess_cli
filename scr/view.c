#include <stdio.h>
#include <stdbool.h>
#include "piece_definitions.h"
#include "view.h"

#define TILE_CHAR_WIDTH     2
#define TILE_CHAR_HEIGHT    1

#define BOARD_FILES 8
#define BOARD_RANKS 8

#define BOARD_ORIGIN_ROW    4
#define BOARD_ORIGIN_COL    8


static void draw_tile();
static void set_tile_colour(int rank, int file);
static void set_piece_colour(int piece);
static char *piece_to_string(int piece);

void view_init_screen() {
    CURSOR_SET(1, 1);
    SCREEN_CLEAR();
}

void view_draw_empty_board() {
    CURSOR_SET(BOARD_ORIGIN_ROW, BOARD_ORIGIN_COL);
    for (int rank = (BOARD_RANKS - 1); rank >= 0; rank--) {
        for (int file = 0; file < BOARD_FILES; file++) {
            set_tile_colour(rank, file);
            draw_tile();
        }

        CURSOR_MOVE_LEFT(TILE_CHAR_WIDTH * BOARD_FILES);
        CURSOR_MOVE_DOWN(TILE_CHAR_HEIGHT);
    }

    GRAPHICS_RESET();

    CURSOR_SET(
        BOARD_ORIGIN_ROW + (TILE_CHAR_HEIGHT * BOARD_RANKS),
        BOARD_ORIGIN_COL);

    fflush(stdout);
}

void view_draw_piece(int rank, int file, int piece) {
    int rowOffset = TILE_CHAR_HEIGHT * (BOARD_RANKS - 1 - rank);
    int colOffset = TILE_CHAR_WIDTH * file;
    
    CURSOR_SET(
        BOARD_ORIGIN_ROW + rowOffset,
        BOARD_ORIGIN_COL + colOffset);

    set_tile_colour(rank, file);
    set_piece_colour(piece);

    char *pieceSymbol = piece_to_string(piece);
    printf("%s", pieceSymbol);

    GRAPHICS_RESET();

    CURSOR_SET(
        BOARD_ORIGIN_ROW + (TILE_CHAR_HEIGHT * BOARD_RANKS),
        BOARD_ORIGIN_COL);

    fflush(stdout);
}



static void draw_tile() {
    for (int rows = 0; rows < TILE_CHAR_HEIGHT; rows++) {
        for (int cols = 0; cols < TILE_CHAR_WIDTH; cols++) {
            putchar(' ');
        }
        CURSOR_MOVE_LEFT(TILE_CHAR_WIDTH);
        CURSOR_MOVE_DOWN(1);
    }
    CURSOR_MOVE_RIGHT(TILE_CHAR_WIDTH);
    CURSOR_MOVE_UP(TILE_CHAR_HEIGHT);
}

static void set_tile_colour(int rank, int file) {
    bool isDarkSquare = ((rank + file) % 2 == 0);
    if (isDarkSquare) {
        GRAPHICS_BG_COLOUR_SET(BOARD_COLOUR_DARK);
    } else {
        GRAPHICS_BG_COLOUR_SET(BOARD_COLOUR_LIGHT);
    }
}

static void set_piece_colour(int piece) {
    bool isWhite = ((piece & P_WHITE) == P_WHITE);
    if (isWhite) {
        GRAPHICS_FG_COLOUR_SET(BOARD_COLOUR_WHITE_PIECE);
    } else {
        GRAPHICS_FG_COLOUR_SET(BOARD_COLOUR_BLACK_PIECE);
    }
}

static char *piece_to_string(int piece) {
    switch (piece) {
        // Unknown piece
        default:
            return "?";

        // None piece
        case P_NONE:
            return " ";

        // Black pieces
        case P_BLACK_KING:
            return "♔";
        case P_BLACK_QUEEN:
            return "♕";
        case P_BLACK_ROOK:
            return "♖";
        case P_BLACK_BISHOP:
            return "♗";
        case P_BLACK_KNIGHT:
            return "♘";
        case P_BLACK_PAWN:
            return "♙";

        // White pieces
        case P_WHITE_KING:
            return "♚";
        case P_WHITE_QUEEN:
            return "♛";
        case P_WHITE_ROOK:
            return "♜";
        case P_WHITE_BISHOP:
            return "♝";
        case P_WHITE_KNIGHT:
            return "♞";
        case P_WHITE_PAWN:
            return "♟︎";
    }
}
