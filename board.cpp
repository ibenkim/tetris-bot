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

void Board::LineClear(int row) {
    for(int i = nRows-row-1; i >= 0; i++) {
        delete [] grid[i];
    }

    for(int i = nRows-row-1; i < nRows-1; i++) {
        for(int j = 0; j < nCols; j++) {
            grid[i-row][j] = grid[i][j];
        }
    } 
}

