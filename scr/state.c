#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "state.h"

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

    // Array of non-empty square positions and the corresponding array of
    // pieces in those positions
    unsigned int next;
    unsigned int len;
    int *positions;
    int *pieces;
};

void board_init(struct Board *b);

struct Board *board_create() {
    struct Board *b = malloc(sizeof(*b));
    if (b == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    memset(b, 0, sizeof(*b));
    board_init(b);

    return b;
}

void board_init(struct Board *b) {
   b->width = BOARD_DEFAULT_WIDTH;
   b->height = BOARD_DEFAULT_HEIGHT;

   b->next = 0;
   b->len = BOARD_DEFAULT_WIDTH * 4;
   b->positions = malloc(sizeof(*(b->positions)) * b->len);
   b->pieces = malloc(sizeof(*(b->pieces)) * b->len);

   int whiteBackRank[BOARD_DEFAULT_WIDTH] = BOARD_DEFAULT_WHITE_BACK_RANK;
   int blackBackRank[BOARD_DEFAULT_WIDTH] = BOARD_DEFAULT_BLACK_BACK_RANK;

   // Add white pieces to board
   int rank = 0;
   for (int file = 0; file < BOARD_DEFAULT_WIDTH; file++) {
       int pos = rank * b->width + file;
       b->positions[b->next] = pos;
       b->pieces[b->next] = whiteBackRank[file];
       (b->next)++;
   }

   rank = 1;
   for (int file = 0; file < BOARD_DEFAULT_WIDTH; file++) {
       int pos = rank * b->width + file;
       b->positions[b->next] = pos;
       b->pieces[b->next] = P_WHITE_PAWN;
       (b->next)++;
   }

   // Add black pieces to board
   rank = BOARD_DEFAULT_HEIGHT - 2;
   for (int file = 0; file < BOARD_DEFAULT_WIDTH; file++) {
       int pos = rank * b->width + file;
       b->positions[b->next] = pos;
       b->pieces[b->next] = P_BLACK_PAWN;
       (b->next)++;
   }

   for (int file = 0; file < BOARD_DEFAULT_WIDTH; file++) {
       int pos = rank * b->width + file;
       b->positions[b->next] = pos;
       b->pieces[b->next] = blackBackRank[file];
       (b->next)++;
   }

}

void board_destroy(struct Board *b) {
    free(b->positions);
    free(b->pieces);

    free(b);
}
