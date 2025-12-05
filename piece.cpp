
#include "piece.h"

// ctor
Piece::Piece(char type, int board_rows, int board_cols, char **board_state) {
  this->type = type;
  max_up = board_rows;
  max_right = board_cols;

  row = 0; // Spawn at top
  col = max_right / 2;

  rot = 0;

  board = board_state;
}

bool Piece::isValidPos(int r, int c, int rotation) {
  for (int i = 0; i < 4; i++) {
    int colPos = Xcoords[rotation][i] + c;
    int rowPos = Ycoords[rotation][i] + r;

    if (colPos < 0 || colPos >= max_right)
      return false;
    if (rowPos < 0)
      return false;
    if (rowPos >= max_up) // Check bottom bound
      return false;

    if (board[rowPos][colPos] != 0 && board[rowPos][colPos] != ' ')
      return false;
  }

  return true;
}

// rotate CCW
// implement in each piece class
bool Piece::Rotate_L() {
  if (isValidPos(row, col, (rot - 1) % 4)) {
    rot = (rot - 1) % 4;
    return true;
  }

  return false;
}
// rotate CW
bool Piece::Rotate_R() {
  if (isValidPos(row, col, (rot + 1) % 4)) {
    rot = (rot + 1) % 4;
    return true;
  }

  return false;
}

// Translations
// implement in each piece class
bool Piece::step_L() {
  if (isValidPos(row, col - 1, rot)) {
    col--;
    return true;
  }

  return false;
}
bool Piece::step_R() {
  if (isValidPos(row, col + 1, rot)) {
    col++;
    return true;
  }

  return false;
}
bool Piece::step_D() {
  if (isValidPos(row + 1, col, rot)) { // Move DOWN (row++)
    row++;
    return true;
  }

  return false;
}

// implement in each piece class
void Piece::hard_drop() {
  while (isValidPos(row + 1, col, rot)) { // Move DOWN
    row++;
  }
}

int Piece::getRow() { return row; }
int Piece::getCol() { return col; }
int Piece::getType() { return type; }
int Piece::getRotation() { return rot; }

int Piece::getRelRow(int index) { return Ycoords[rot][index]; }
int Piece::getRelCol(int index) { return Xcoords[rot][index]; }
