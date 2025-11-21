#include <iostream>
#include "board.h"
using namespace std;

Board::Board() {
   nRows = 20;
   nCols = 10;
   grid = new char*[nRows];
   for(int i = 0; i < nRows; i++) {
      grid[i] = new char[nCols];
   }
}

Board::Board(int rows, int cols) {
   nRows = rows;
   nCols = cols;
   grid = new char*[nRows];
   for(int i = 0; i < nRows; i++) {
      grid[i] = new char[nCols];
   }
}

Board::~Board() {
   for(int i = 0; i < nRows; i++) {
      delete [] grid[i];
   }
   delete [] grid;
}

void Board::BoardReset() {
    for(int i = 0; i < nRows; i++) {
      delete [] grid[i];
   }
   delete [] grid;

   nRows = 20;
   nCols = 10;
   grid = new char*[nRows];
   for(int i = 0; i < nRows; i++) {
      grid[i] = new char[nCols];
   }
}
