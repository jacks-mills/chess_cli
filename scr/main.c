#include <stdio.h>
#include "state.h"

int main(int argc, char **argv) {
    struct Board *board = board_create();
    board_init(board);

    printf("BP: %2i, BK %2i, BB: %2i, BR: %2i, BQ: %2i, BK: %2i\n",
        P_BLACK_PAWN,
        P_BLACK_KNIGHT,
        P_BLACK_BISHOP,
        P_BLACK_ROOK,
        P_BLACK_QUEEN,
        P_BLACK_KING);

    printf("WP: %2i, WK %2i, WB: %2i, WR: %2i, WQ: %2i, WK: %2i\n",
        P_WHITE_PAWN,
        P_WHITE_KNIGHT,
        P_WHITE_BISHOP,
        P_WHITE_ROOK,
        P_WHITE_QUEEN,
        P_WHITE_KING);

    for (int rank = 7; rank >= 0; rank--) {
        for (int file = 0; file < 8; file++) {
            printf("%2i ", board_get_piece(board, rank, file));
        }
        printf("\n");
    }

    board_destroy(board);
    return 0;
}
