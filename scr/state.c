#include "state.h"

struct Board {
    // Board dimensions
    unsigned int width;
    unsigned int height;

    // Array of non-empty square positions and the corresponding array of
    // peices in those positions
    unsigned int len;
    int *positions;
    int *peices;
};

struct Board *board_create();

void board_destroy(struct Board *b);
