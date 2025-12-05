#ifndef PIECE_H
#define PIECE_H


class Piece {
 public: 
   // Initialize piece; c represents piece (e.g. L piece, O piece)
   Piece(int board_rows, int board_cols, char** board_state); 

   // Rotations
   bool Rotate_L(); 
   bool Rotate_R(); 

   // Translations
   bool step_L(); 
   bool step_R(); 
   bool step_D();
   void hard_drop(); 

   // check for collisions
   bool isValidPos(int r, int c, int rotation); 
    
   // Access variables
   int getRow(); 
   int getCol(); 
   int getType(); 
   int getRotation(); 

 protected: 
   // piece
   int row; 
   int col; 
 
   // L piece, T piece, etc.
   char type; 

   // 0, 1, 2, 3 is clockwise
   int rot; 

   // displacement from center that the coords of the piece takes up (1st indicie is rotation)
   int Xcoords[4][4]; 
   int Ycoords[4][4]; 

   // board dimensions
   int max_up; 
   int max_right; 

   // board state
   char** board; 

}; 

















#endif
