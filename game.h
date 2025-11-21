#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "piece.h"

class Game{
public:
    Game();
    ~Game();

    void Start();
    void Update();
    void HandleInput(char key);

    int getScore() const;
    int getLevel() const;
    bool isGameOver() const;

private:
    Board board;
    Piece* currentPiece;
    Piece* nextPiece; 

    int score;
    int level;
    bool gameOver;

    //Piece Management 
    void SpawnPiece();
    bool MoveCurrentPiece(int dx, int dy);
    void RotateCurrentPiece(bool clockwise);

     // Locking + collision
    void LockPiece();
    bool Collision(Piece* p, int newRow, int newCol);

    // Line clearing
    void ClearFullLines();
};

#endif