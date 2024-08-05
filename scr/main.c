#include <stdio.h>
#include "piece_definitions.h"
#include "state.h"
#include "view.h"

int main(int argc, char **argv) {
    struct Board *board = board_create();
    board_init(board);

    view_init_screen();
    view_draw_empty_board();

    int rank;
    int colour;

    rank = 0;
    colour = P_WHITE;
    view_draw_piece(rank, 0, colour | P_ROOK);
    view_draw_piece(rank, 1, colour | P_KNIGHT);
    view_draw_piece(rank, 2, colour | P_BISHOP);
    view_draw_piece(rank, 3, colour | P_QUEEN);
    view_draw_piece(rank, 4, colour | P_KING);
    view_draw_piece(rank, 5, colour | P_BISHOP);
    view_draw_piece(rank, 6, colour | P_KNIGHT);
    view_draw_piece(rank, 7, colour | P_ROOK);

    rank = 1;
    for (int file = 0; file < 8; file++) {
        view_draw_piece(rank, file, colour | P_PAWN);
    }

    rank = 7;
    colour = P_BLACK;
    view_draw_piece(rank, 0, colour | P_ROOK);
    view_draw_piece(rank, 1, colour | P_KNIGHT);
    view_draw_piece(rank, 2, colour | P_BISHOP);
    view_draw_piece(rank, 3, colour | P_QUEEN);
    view_draw_piece(rank, 4, colour | P_KING);
    view_draw_piece(rank, 5, colour | P_BISHOP);
    view_draw_piece(rank, 6, colour | P_KNIGHT);
    view_draw_piece(rank, 7, colour | P_ROOK);

    rank = 6;
    for (int file = 0; file < 8; file++) {
        view_draw_piece(rank, file, colour | P_PAWN);
    }

    printf("\r");

    board_destroy(board);
    return 0;
}
