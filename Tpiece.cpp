
#include "Tpiece.h"
#include <algorithm>
#include <iterator>

using namespace std;

/*
 . 2 .
 1 3 4
 . . .

 . 1 .
 . 3 2
 . 4 .

 . . .
 4 3 1
 . 2 .

 . 4 .
 2 3 .
 . 1 .

*/

Tpiece::Tpiece(int board_rows, int board_cols, char **board_state): Piece('T', board_rows, board_cols, board_state) {

  int tempX1[4] = {-1, 0, 0, 1};
  copy(begin(tempX1), end(tempX1), Xcoords[0]);
  int tempY1[4] = {0, 1, 0, 0};
  copy(begin(tempY1), end(tempY1), Ycoords[0]);

  int tempX2[4] = {0, 1, 0, 0};
  copy(begin(tempX2), end(tempX2), Xcoords[1]);
  int tempY2[4] = {1, 0, 0, -1};
  copy(begin(tempY2), end(tempY2), Ycoords[1]);

  int tempX3[4] = {1, 0, 0, -1};
  copy(begin(tempX3), end(tempX3), Xcoords[2]);
  int tempY3[4] = {0, -1, 0, 0};
  copy(begin(tempY3), end(tempY3), Ycoords[2]);

  int tempX4[4] = {0, -1, 0, 0};
  copy(begin(tempX4), end(tempX4), Xcoords[3]);
  int tempY4[4] = {-1, 0, 0, 1};
  copy(begin(tempY4), end(tempY4), Ycoords[3]);
}

void Tpiece::Rotate_L() {}

/*
    // Rotations
   virtual void Rotate_L();
   virtual void Rotate_R();

   // Translations
   virtual void step_L();
   virtual void step_R();
   virtual void step_D();
   virtual void hard_drop();

*/
