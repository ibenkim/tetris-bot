#ifndef LPIECE_H
#define LPIECE_H

#include "piece.h"

/*
 . . # 
 # # #
 . . .

 . . 3 
 1 2 4
 . . .
*/


struct Lpiece : public Piece {
    //ctor
    Lpiece(int board_rows, int board_cols, char** board_state); 
};



#endif
