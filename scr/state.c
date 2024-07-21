#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "state.h"
#include "piece_definitions.h"

#define BOARD_DEFAULT_WIDTH     8
#define BOARD_DEFAULT_HEIGHT    8
#define BOARD_DEFAULT_WHITE_BACK_RANK \
    {P_WHITE_ROOK, P_WHITE_KNIGHT, P_WHITE_BISHOP, P_WHITE_QUEEN, \
     P_WHITE_KING, P_WHITE_BISHOP, P_WHITE_KNIGHT, P_WHITE_ROOK}
#define BOARD_DEFAULT_BLACK_BACK_RANK \
    {P_BLACK_ROOK, P_BLACK_KNIGHT, P_BLACK_BISHOP, P_BLACK_QUEEN, \
     P_BLACK_KING, P_BLACK_BISHOP, P_BLACK_KNIGHT, P_BLACK_ROOK}

struct Board {
    // Board dimensions
    unsigned int width;
    unsigned int height;

    int *pieces;
};

static int pos_to_index(struct Board *b, int rank, int file);
static int index_to_rank(struct Board *b, int index);
static int index_to_file(struct Board *b, int index);

struct Board *board_create() {
    struct Board *b = malloc(sizeof(*b));
    if (b == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    memset(b, 0, sizeof(*b));
    return b;
}

void board_init(struct Board *b) {
    b->width = BOARD_DEFAULT_WIDTH;
    b->height = BOARD_DEFAULT_HEIGHT;

    b->pieces = malloc(sizeof(*(b->pieces)) * b->width * b->height);

    int pieceToFill = P_NONE;
    for (int i = 0; i < (b->width * b->height); i++) {
        b->pieces[i] = pieceToFill;
    }

    int blackBackRank[BOARD_DEFAULT_WIDTH] = BOARD_DEFAULT_BLACK_BACK_RANK;
    int whiteBackRank[BOARD_DEFAULT_WIDTH] = BOARD_DEFAULT_WHITE_BACK_RANK;

    for (int file = 0; file < BOARD_DEFAULT_WIDTH; file++) {
        int pos;

        pos = pos_to_index(b, 0, file);
        b->pieces[pos] = whiteBackRank[file];

        pos = pos_to_index(b, 1, file);
        b->pieces[pos] = P_WHITE_PAWN;

        pos = pos_to_index(b, BOARD_DEFAULT_HEIGHT - 1, file);
        b->pieces[pos] = blackBackRank[file];

        pos = pos_to_index(b, BOARD_DEFAULT_HEIGHT - 2, file);
        b->pieces[pos] = P_BLACK_PAWN;
    }
}

void board_destroy(struct Board *b) {
    free(b->pieces);
    free(b);
}

int board_get_piece(struct Board *b, int rank, int file) {
    bool rankOutOfRange = (rank >= b->height || rank < 0);
    bool fileOutOfRange = (file >= b->width  || file < 0);
    if (rankOutOfRange || fileOutOfRange) {
        return -1;
    }

    return b->pieces[pos_to_index(b, rank, file)];
}



static int pos_to_index(struct Board *b, int rank, int file) {
    return rank * b->width + file;
}

static int index_to_rank(struct Board *b, int index) {
    return index / b->width;
}

static int index_to_file(struct Board *b, int index) {
    return index % b->width;
}
