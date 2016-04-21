#include <string>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


/**
 * Exception signaling that the player hit a wall
 */
class wallhit_exception : public std::exception {
};


/**
 * Exception signaling that the player found an exit
 * from the game
 */
class exitreach_exception : public std::exception {
};


/**
 * Board class is responsible for managing the board
 * operations: initializing the board, setting/getting the characters
 * from the board and also displaying the board
 */
class Board {
public:
  typedef std::string::size_type pos;

  /**
   * Constructor
   * @param boardSize NxN board size filled with '.'
   */
  Board(int boardSize): _boardSize(boardSize), _board(boardSize*boardSize, '.') {}


  /**
   * Get the board dimension
   * @return NxN dimension of the board
   */
  int getBoardSize() { return _boardSize;}


  /**
   * Get a character at selected position
   * @param row
   * @param col
   * @return the character at the selected position
   * @throws out_of_range position is outside of the board
   */
  char get(pos row, pos col) const { return _board.at(row * _boardSize + col);}


  /**
   * Set the character at the selected position
   * @param c
   * @param row
   * @param col
   * @return Board&
   * @throws out_of_range position is outside of the board
   */
  Board & set(char c, pos row, pos col);


  /**
   * Display the board
   */
  void display();

private:

  //board size
  const int _boardSize;

  //board storage
  std::string _board;
};


/**
 * A board game enabling the player to move around walls
 * in the board and reach the exit point.
 */
class Game {
public:

  /**
   * Constructor
   * @param boardSize NxN game board size
   */
  Game(int boardSize): _currRow(0), _currCol(0), _board(boardSize) { setupBoard();}


  /**
   * Display the game board
   */
  void displayBoard() { _board.display();}


  /**
   * Move a player in the up direction.
   *
   * @throws out_of_range position is outside of the board
   * @throws wallhit_exception player has hit a wall
   * @throws exitreach_exception player has reached the exit of the game
   */
  void moveUp() { move(_currRow - 1, _currCol);}


  /**
   * Move a player in the down direction.
   *
   * @throws out_of_range position is outside of the board
   * @throws wallhit_exception player has hit a wall
   * @throws exitreach_exception player has reached the exit of the game
  */
  void moveDown() { move(_currRow + 1, _currCol);}


  /**
   * Move a player in the left direction
   *
   * @throws out_of_range position is outside of the board
   * @throws wallhit_exception player has hit a wall
   * @throws exitreach_exception player has reached the exit of the game
   */
  void moveLeft() { move(_currRow, _currCol -1);}


  /**
   * Move the player in the right direction
   *
   * @throws out_of_range position is outside of the board
   * @throws wallhit_exception player has hit a wall
   * @throws exitreach_exception player has reached the exit of the game
  */
  void moveRight(){ move(_currRow, _currCol + 1);}

private:

  static const char PLAYER_CHAR = 'P';
  static const char EXIT_CHAR = 'X';
  static const char WALL_CHAR = 'W';
  static const char EMPTY_CHAR = '.';

  /**
   * Setup the board with a player location
   * and random walls on the board.
   */
  void setupBoard();


  /**
   * Move a player to a new position
   * @param row new player row position
   * @param col new player column position
   */
  void move(int row, int col);


  //current row position of the player
  int _currRow;
  //current column position of the player
  int _currCol;
  //the game board
  Board _board;
};


Board & Board::set(char c, pos row, pos col) 
{ 
  _board.at(row * _boardSize + col) = c;
  return *this;
}


void Board::display() {
  for (int row = 0; row < _boardSize; row++) {
    cout << _board.substr(row * _boardSize, _boardSize) << endl;
  }
}


void Game::setupBoard() {

  int boardSize = _board.getBoardSize();
  
  _board.set(PLAYER_CHAR, 0,0);
  _board.set(EXIT_CHAR, boardSize - 1, boardSize -1);

  int numOfRndWalls = 6;
  while (numOfRndWalls) {

    int wallRow = rand() % boardSize;
    int wallCol = rand() % boardSize;

    if (_board.get(wallRow, wallCol) == '.') {
      _board.set(WALL_CHAR, wallRow, wallCol);
      numOfRndWalls--;
    }
  }
}


void Game::move(int row, int col) {

  char c = _board.get(row, col);

  if (c == WALL_CHAR) {
    throw wallhit_exception();
  }
  else if (c == EXIT_CHAR) {
    throw exitreach_exception();
  }

  _board.set(PLAYER_CHAR, row, col);
  _board.set(EMPTY_CHAR, _currRow, _currCol);

  _currRow = row;
  _currCol = col;
}


int main(int argc, char *argv[])
{
  srand( time(NULL) );

  Game game(10);

  game.displayBoard();

  char c;
  while(cin >> c) {

    try {

      switch(c) {

      case 'U':
      case 'u':
        game.moveUp();
        break;

      case 'D':
      case 'd':
        game.moveDown();
        break;

      case 'L':
      case 'l':
        game.moveLeft();
        break;

      case 'R':
      case 'r':
        game.moveRight();
        break;
      }

    } catch(std::out_of_range &) {
      cout << "Invalid move! Try again" << endl;
    
    } catch(wallhit_exception &) {
      cout << "You hit the wall. Better luck next time!" << endl;
      break;
    
    } catch(exitreach_exception &) {
      cout << "You win!!!" << endl;
      break;
    }

    game.displayBoard();

  }

  return 0;

}
