#ifndef BOARD_H
#define BOARD_H

#include "piece.h"

class Board {
public:
  // Default size: 20 x 10
  Board();
  // Custom size
  Board(int rows, int cols);

  // Destructor
  ~Board();

  // Reset board;
  void BoardReset();

  // Shift board state after clearing lines
  void LineClear(int row);

  // Place piece
  void PlacePiece(char c, int row, int col);

  // Getters
  int getRows() const;
  int getCols() const;
  char **getGrid() const;

private:
  char **grid;
  int nRows;
  int nCols;
};

#endif
