
#include "piece.h"

// ctor
Piece::Piece(char c, int board_rows, int board_cols, char **board_state) {
  max_up = board_rows;
  max_right = board_cols;

  row = max_up;
  col = max_right / 2;

  type = c;
  rot = 0;

  board = board_state;
}

// rotate CCW
// implement in each piece class
void Piece::Rotate_L() { rot = (rot - 1) % 4; }
// rotate CW
void Piece::Rotate_R() { rot = (rot + 1) % 4; }

// Translations

// implement in each piece class
void Piece::step_L() {
  if (col > leftN[rot]) {
    col -= 1;
  }
}
void Piece::step_R() {
  if (col < max_right - rightN[rot] - 1) {
    col += 1;
  }
}
void Piece::step_D() {
  if (row > 0) {
    row -= 1;
  }
}

// implement in each piece class
void Piece::hard_drop() {}

int Piece::getRow() { return row; }
int Piece::getCol() { return col; }
int Piece::getType() { return type; }
int Piece::getRotation() { return rot; }
