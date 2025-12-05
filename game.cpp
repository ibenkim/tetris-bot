#include "game.h"
#include "Lpiece.h"
#include "Tpiece.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Game::Game() {
  score = 0;
  level = 1;
  gameOver = false;
  srand(time(0));

  // Initialize board
  nextPiece = nullptr;
  SpawnPiece();
}

Game::~Game() {
  if (currentPiece)
    delete currentPiece;
  if (nextPiece)
    delete nextPiece;
}

void Game::Start() {
  while (!gameOver) {
    // Draw board
    system("clear");
    cout << "Score: " << score << " Level: " << level << endl;

    char **grid = board.getGrid();
    int rows = board.getRows();
    int cols = board.getCols();

    // Simple rendering
    for (int i = 0; i < rows; ++i) {
      cout << "|";
      for (int j = 0; j < cols; ++j) {
        bool isPiece = false;
        if (currentPiece) {
          // Check if this cell is part of the current piece
          for (int k = 0; k < 4; ++k) {
            if (i == currentPiece->getRow() + currentPiece->getRelRow(k) &&
                j == currentPiece->getCol() + currentPiece->getRelCol(k)) {
              cout << (char)currentPiece->getType();
              isPiece = true;
              break;
            }
          }
        }
        if (!isPiece) {
          cout << (grid[i][j] ? grid[i][j] : ' ');
        }
      }
      cout << "|" << endl;
    }
    cout << "----------------------" << endl;

    // Input handling
    cout << "Command (a:left, d:right, s:down, w:rotate, q:quit): ";
    char cmd;
    cin >> cmd;

    HandleInput(cmd);
    Update();
  }
  cout << "Game Over!" << endl;
}

void Game::Update() {
  if (gameOver)
    return;

  // Gravity
  if (!MoveCurrentPiece(0, 1)) {
    LockPiece();
    ClearFullLines();
    SpawnPiece();
    if (Collision(currentPiece, currentPiece->getRow(),
                  currentPiece->getCol())) {
      gameOver = true;
    }
  }
}

void Game::HandleInput(char key) {
  switch (key) {
  case 'a':
    MoveCurrentPiece(-1, 0);
    break;
  case 'd':
    MoveCurrentPiece(1, 0);
    break;
  case 's':
    MoveCurrentPiece(0, 1);
    break;
  case 'w':
    RotateCurrentPiece(true);
    break;
  case 'q':
    gameOver = true;
    break;
  }
}

int Game::getScore() const { return score; }
int Game::getLevel() const { return level; }
bool Game::isGameOver() const { return gameOver; }

void Game::SpawnPiece() {
  int pieceType = rand() % 2;
  if (pieceType == 0) {
    currentPiece =
        new Tpiece(board.getRows(), board.getCols(), board.getGrid());
  } else {
    currentPiece =
        new Lpiece(board.getRows(), board.getCols(), board.getGrid());
  }
}

bool Game::MoveCurrentPiece(int dx, int dy) {
  // Check if new position is valid
  int newRow = currentPiece->getRow() + dy;
  int newCol = currentPiece->getCol() + dx;

  if (Collision(currentPiece, newRow, newCol)) {
    return false;
  }

  // Apply movement
  if (dx == -1)
    currentPiece->step_L();
  if (dx == 1)
    currentPiece->step_R();
  if (dy == 1)
    currentPiece->step_D();

  return true;
}

void Game::RotateCurrentPiece(bool clockwise) {
  if (clockwise)
    currentPiece->Rotate_R();
  else
    currentPiece->Rotate_L();
}

void Game::LockPiece() {
  for (int i = 0; i < 4; i++) {
    int r = currentPiece->getRow() + currentPiece->getRelRow(i);
    int c = currentPiece->getCol() + currentPiece->getRelCol(i);
    board.PlacePiece(currentPiece->getType(), r, c);
  }
  delete currentPiece;
  currentPiece = nullptr;
}

bool Game::Collision(Piece *p, int newRow, int newCol) {
  // Check collision for all 4 blocks
  for (int i = 0; i < 4; ++i) {
    int r = newRow + p->getRelRow(i);
    int c = newCol + p->getRelCol(i);

    if (r < 0 || r >= board.getRows() || c < 0 || c >= board.getCols()) {
      return true;
    }
    if (board.getGrid()[r][c] != ' ' && board.getGrid()[r][c] != 0) {
      return true;
    }
  }
  return false;
}

void Game::ClearFullLines() {
  // Check each row
  for (int i = 0; i < board.getRows(); ++i) {
    bool full = true;
    for (int j = 0; j < board.getCols(); ++j) {
      if (board.getGrid()[i][j] == ' ' || board.getGrid()[i][j] == 0) {
        full = false;
        break;
      }
    }
    if (full) {
      board.LineClear(i);
      score += 100;
    }
  }
}
