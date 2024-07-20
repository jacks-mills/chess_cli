#ifndef _STATE_H
#define _STATE_H

struct Board;

struct Board *board_create();

void board_destroy(struct Board *b);

#endif //_STATE_H
