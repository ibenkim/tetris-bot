#include "board.h"

Board::Board() {
  nRows = 20;
  nCols = 10;
  grid = new char *[nRows];
  for (int i = 0; i < nRows; i++) {
    grid[i] = new char[nCols];
    for (int j = 0; j < nCols; j++)
      grid[i][j] = ' ';
  }
}

Board::Board(int rows, int cols) {
  nRows = rows;
  nCols = cols;
  grid = new char *[nRows];
  for (int i = 0; i < nRows; i++) {
    grid[i] = new char[nCols];
    for (int j = 0; j < nCols; j++)
      grid[i][j] = ' ';
  }
}

Board::~Board() {
  for (int i = 0; i < nRows; i++) {
    delete[] grid[i];
  }
  delete[] grid;
}

void Board::BoardReset() {
  for (int i = 0; i < nRows; i++) {
    delete[] grid[i];
  }
  delete[] grid;

  nRows = 20;
  nCols = 10;
  grid = new char *[nRows];
  for (int i = 0; i < nRows; i++) {
    grid[i] = new char[nCols];
  }
}

void Board::LineClear(int row) {
  // Shift rows down
  for (int i = row; i > 0; i--) {
    for (int j = 0; j < nCols; j++) {
      grid[i][j] = grid[i - 1][j];
    }
  }
  // Clear top row
  for (int j = 0; j < nCols; j++) {
    grid[0][j] = ' ';
  }
}

void Board::PlacePiece(char c, int row, int col) {
  if (row >= 0 && row < nRows && col >= 0 && col < nCols) {
    grid[row][col] = c;
  }
}

int Board::getRows() const { return nRows; }

int Board::getCols() const { return nCols; }

char **Board::getGrid() const { return grid; }