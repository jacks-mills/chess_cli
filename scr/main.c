#include <stdio.h>
#include "piece_definitions.h"
#include "state.h"
#include "view.h"

int main(int argc, char **argv) {
    struct Board *board = board_create();
    board_init(board);

    view_init_screen();

    printf("\r");
    board_destroy(board);
    
    return 0;
}
