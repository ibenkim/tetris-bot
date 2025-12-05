#include "game.h"
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
    system("clear"); // Simple clear for linux/mac
    cout << "Score: " << score << " Level: " << level << endl;

    char **grid = board.getGrid();
    int rows = board.getRows();
    int cols = board.getCols();

    // Create a temporary display grid to show current piece
    // In a real app we might draw directly, but here we want to overlay the
    // piece

    // Simple rendering
    for (int i = 0; i < rows; ++i) {
      cout << "|";
      for (int j = 0; j < cols; ++j) {
        bool isPiece = false;
        if (currentPiece) {
          if (i == currentPiece->getRow() && j == currentPiece->getCol()) {
            cout << (char)currentPiece->getType();
            isPiece = true;
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
  char types[] = {'I', 'J', 'L', 'O', 'S', 'T', 'Z'};
  char type = types[rand() % 7];

  currentPiece =
      new Piece(type, board.getRows(), board.getCols(), board.getGrid());
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
  board.PlacePiece(currentPiece->getType(), currentPiece->getRow(),
                   currentPiece->getCol());
  delete currentPiece;
  currentPiece = nullptr;
}

bool Game::Collision(Piece *p, int newRow, int newCol) {
  if (newRow < 0 || newRow >= board.getRows() || newCol < 0 ||
      newCol >= board.getCols()) {
    return true;
  }
  if (board.getGrid()[newRow][newCol] != ' ' &&
      board.getGrid()[newRow][newCol] != 0) {
    return true;
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
