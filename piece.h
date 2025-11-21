#ifndef PIECE_H
#define PIECE_H


class Piece {
 public: 
    // Initialize piece; c represents piece (e.g. L piece, O piece)
    Piece(char c); 

    // Destructor
    ~Piece(); 

    // Rotations
    void Rotate_L(); 
    void Rotate_R(); 

    // Translations
    void step_L(); 
    void step_R(); 
    void step_D();
    
    // Access variables
    int getRow(); 
    int getCol(); 
    int getType(); 
    int getRotation(); 

 private: 
    int row; 
    int col; 

    char type; 
    int rotation; 
}; 

















#endif