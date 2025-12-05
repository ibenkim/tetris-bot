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


struct Zpiece : public Piece {
    //ctor
    Zpiece(int board_rows, int board_cols, char** board_state); 
};



#endif
