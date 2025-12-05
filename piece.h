#ifndef PIECE_H
#define PIECE_H


class Piece {
 public: 
   // Initialize piece; c represents piece (e.g. L piece, O piece)
   Piece(char c, int board_rows, int board_cols, char** board_state); 

   // Rotations
   virtual void Rotate_L(); 
   virtual void Rotate_R(); 

   // Translations
   virtual void step_L(); 
   virtual void step_R(); 
   virtual void step_D();
   virtual void hard_drop(); 
    
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
   // length to each side of center, depending on rotation
   int leftN[4]; 
   int rightN[4]; 
   int upN[4]; 
   int downN[4]; 
   // coords the piece takes up (1st indicie is rotation)
   int Xcoords[4][4]; 
   int Ycoords[4][4]; 

   // board dimensions
   int max_up; 
   int max_right; 

   // board state
   char** board; 

}; 

















#endif
