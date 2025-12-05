#ifndef TPIECE_H
#define TPIECE_H

#include "piece.h"

/*
 . # . 
 # # #
 . . .

 . 2 . 
 1 3 4
 . . .
*/


struct Tpiece : public Piece {
    //ctor
    Tpiece(int board_rows, int board_cols, char** board_state); 
};



#endif
