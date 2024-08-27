#ifndef _STATE_H
#define _STATE_H

#include "piece_definitions.h"

struct Board;

struct Board *board_create();
void board_init(struct Board *b);
void board_destroy(struct Board *b);

int board_get_piece(struct Board *b, int rank, int file);

#endif //_STATE_H
