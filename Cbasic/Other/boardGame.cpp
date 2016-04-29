/*
 * BoardGame.cpp
 *
 *  Created on: 2016年4月28日
 *      Author: Beven
 */

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <string>



using namespace std;

class wallhit_expectiom: public std::exception{};

class exitreach_exception: public std::exception{};

class outrange_exception: public std::exception{};

class Board
{
private:
  int _boardSize;
  char _board[15][15];

public:
  Board()
  {
	_boardSize = 0;

  }

  Board(int boardSize)
   {
 	  _boardSize = boardSize;
 	  _board[0][0] = '2';
 	  for(int i = 0; i < _boardSize; i++)
 	  {
 		  for(int j = 0; i < _boardSize; j++)
 		  {
 			  _board[i][j] = EMPTY;
 		  }
 	  }
   }

/**
 *enum state present the type of the board point.
 */
  enum state
  {
	  PLAYER = 'P',//!< Location of the Player
	  EXIT = 'X',  //!< Location of the Exit
	  WALL = 'W',  //!< Location of the Wall
	  EMPTY = '.'  //!< Present the path that player can walk through
  };


  void setState(int row, int col, char state)
  {
	 _board[row][col] = state;
  }

  void displayBoard()
  {
	  for(int i = 0; i < _boardSize; i++)
	  {
		  for(int j = 0; j < _boardSize; j++)
		  {
			  std::cout << _board[i][j];
		  }
		  std::cout << std::endl;
	  }
  }

  int getSize()
  {
	  return _boardSize;
  }

  char getState(int row, int col)
  {
	  return _board[row][col];
  }

};

class Game
{

public:
	int _row;
	int _col;
	Board _board;
	std::string _gameName;

	Game();
	Game(int boardSize,int id)
    {
		_row = 0;
		_col = 0;
		_gameName = "game" + id;
		_board = Board(boardSize);
		initBoard();
	}

	void initBoard()
	{
		int boardSize = this->_board.getSize();
		_board.setState(0,0,_board.PLAYER);
		_board.setState(boardSize-1,boardSize-1,_board.EXIT);
		int wallNum = 6;
		while(wallNum)
		{
			srand( time(NULL) );
			int rowRand = rand() % boardSize;
			int colRand = rand() % boardSize;
			if(_board.getState(rowRand, colRand) == _board.EMPTY)
			{
				_board.setState(rowRand, colRand, _board.WALL);
				wallNum--;
			}
		}
	}

	void displayBoard()
	{
		_board.displayBoard();
	}

	void move(int row, int col)
	{
		if(_board.getState(row, col) == _board.EXIT)
		{
			throw exitreach_exception();
		}
		else if(_board.getState(row, col) == _board.WALL)
		{
			throw wallhit_expectiom();
		}
		else if(_board.getState(row, col) == _board.EMPTY)
		{
			_board.setState(row, col, _board.PLAYER);
			_board.setState(_row, _col, _board.EMPTY);
			_row = row;
			_col = col;
		}
		else
		{

			throw outrange_exception();
		}
	}

	std::string getName()
	{
		return this->_gameName;
	}

	std::string setName(std::string name)
	{
		return this->_gameName = name;
	}

	void moveUp()
	{
        move(_row-1, _col);
	}

	void moveDown()
	{
		move(_row+1, _col);
	}

	void moveRight()
	{
		move(_row, _col+1);
	}

	void moveLeft()
	{
		move(_row, _col-1);
	}
};


class GameManager
{

	int gameSum;
	int gameId;
	Game* gameUsing;
	Game* games[];
public:
	GameManager()
	{
		createGame();
	}

    Game* createGame()
    {
    	int boardSize;
    	std::cout << "Please input the size of the board" << std::endl;
    	std::cin >> boardSize;
    	Game* game = new Game(boardSize, gameSum);
    	gameSum ++;
    	games[gameSum] = game;
    	return this->gameUsing =  game;
    }

    std::string rename()
    {
    	Game* game = chooseGame();
    	std::cout << "Please enter the new name!" << std::endl;
    	std::string name = NULL;
    	std::cin >> name;
    	game->setName(name);
    	return game->getName();
    }

    Game* switchGame()
    {
    	std::cout << "Plese enter the game you want to play" << std::endl;
        return this->gameUsing = chooseGame();
    }

    Game* resetGame()
    {
    	Game* _game = gameUsing;
    	_game->initBoard();
    	return _game;
    }
    Game* chooseGame()
    {
    	Game * game = NULL;
    	std::cout << "Please enter the game name" << std::endl;
    	std::string name;
    	while(game != NULL)
    	{
        	std::cin >> name;
        	int gameId = gameSum;
        	while(gameId)
        	{
        		if(name == games[--gameId]->getName())
        		{
        			return game = games[gameId];
        		}
        	}
    	}
    	return NULL;
    }

    void playGame(std::string direction)
    {
    	Game* game = this->gameUsing;
    	char c = direction.at(0);
    	try
    	{
    		switch(c)
			{
			case 'u':
				game->moveUp();
				break;
			case 'd':
				game->moveDown();
				break;
			case 'r':
				game->moveRight();
				break;
			case 'l':
				game->moveLeft();
				break;
			}
    	}
    	catch(outrange_exception &)
    	{
    		std::cout << "Invalid move, try again!" << std::endl;
    	}
    	catch(wallhit_expectiom &)
    	{
    		std::cout << "Hit the wall, game over!" << std::endl;
    	}
    	catch(exitreach_exception &)
    	{
    		std::cout << "Arrived the Exit, WIN!" << std::endl;
    	}

    }

};

int main()
{
	std::cout << "Game start! type help for instructions";
    GameManager gameManager;
    std::string operate;
    while(1)
    {
    	std::cin >> operate;

    	if(operate == "help")
    	{
    		std::cout << " help: display instrucions\n ";
    	}
    	else if(operate == "rename")
    	{
    		gameManager.rename();
    	}
    	else if(operate == "new")
    	{
    		gameManager.createGame();
    	}
    	else if(operate == "reset")
    	{
    		gameManager.resetGame();
    	}
    	else if(operate == "switch")
    	{
    		gameManager.switchGame();
    	}
    	else
    	{
    		gameManager.playGame(operate);
    	}
    }

    return 0;
}






























