#ifndef _STATE_H
#define _STATE_H


#define P_NONE          0

#define P_BLACK         3
#define P_WHITE         1

#define P_KING          4
#define P_QUEEN         8
#define P_ROOK          12
#define P_BISHOP        16
#define P_KNIGHT        20
#define P_PAWN          24

#define P_BLACK_KING    (P_BLACK | P_KING)
#define P_BLACK_QUEEN   (P_BLACK | P_QUEEN)
#define P_BLACK_ROOK    (P_BLACK | P_ROOK)
#define P_BLACK_BISHOP  (P_BLACK | P_BISHOP)
#define P_BLACK_KNIGHT  (P_BLACK | P_KNIGHT)
#define P_BLACK_PAWN    (P_BLACK | P_PAWN)

#define P_WHITE_KING    (P_WHITE | P_KING)
#define P_WHITE_QUEEN   (P_WHITE | P_QUEEN)
#define P_WHITE_ROOK    (P_WHITE | P_ROOK)
#define P_WHITE_BISHOP  (P_WHITE | P_BISHOP)
#define P_WHITE_KNIGHT  (P_WHITE | P_KNIGHT)
#define P_WHITE_PAWN    (P_WHITE | P_PAWN)


struct Board;


struct Board *board_create();

void board_destroy(struct Board *b);

#endif //_STATE_H
