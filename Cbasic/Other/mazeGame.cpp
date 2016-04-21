//============================================================================
// Name        : MazeGame.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdlib>
#include <iostream>
#include <exception>


using namespace std;
static int row = 0;
static int col = 0;
static int size = 0;


/**
 * list the states of maze,
 * PATH: the way that you can walk through
 * EMPTY: The place out the limit of the maze,can't be arrived
 * WALL: Game will be over when player get here
 * PLAYER: Location where the player is
 * EXIT: Location of the exit
 */
enum State {

	PATH = -1,
	EMPTY = 0,
	WALL = 1,
	PLAYER = 2,
	EXIT = 3
    };

int maze[15][15] = {PATH};

//init the maze, set the wall and exit
void initMaze(){
	for(int i = 0; i < size; i++ ){
		for(int j = 0; j < size; j++){
			maze[i][j] = PATH;
		}
	}
	maze[size-1][size-1] = EXIT;

    int wallNum = 0;
    while(wallNum < 6){
		int i = rand()%size;
		int j = rand()%size;
		if(maze[i][j] != WALL ){
			wallNum++;
			maze[i][j] = WALL;
		}
	}
	maze[0][0] = PLAYER;
}

//move operator
void move(int i, int j){
	switch(maze[i][j]){
	case EXIT:
		throw 1;
		break;
	case WALL:
		throw 2;
		break;
	case PATH:
		maze[row][col] = PATH;
		maze[i][j] = PLAYER;
		row = i;
		col = j;
		break;
	default:
		cout << "Invalid move! Try again\n";
		break;
	}
}

//output the state of maze
void print_state(){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			switch(maze[i][j]){
			case PATH:
				cout << ". ";
				break;
			case WALL:
				cout << "W ";
				break;
			case PLAYER:
				cout << "P ";
				break;
			case EXIT:
				cout << "X ";
				break;
			default:
				throw "print the state error!";
			}
		}
		cout << endl;
	}
}

int main() {
	cout << "Please input the size of maze: no larger than 15" << endl;
	cin >> size;
	initMaze();
	print_state();

	//input the direction for move:u: up, d:down, l:left, r:right.
	char operation;
	while(true){
		cin >> operation;
		try
		{
			switch(operation){
			case 'u':
				move(row-1,col);
				break;
			case 'd':
				move(row+1,col);
				break;
			case 'l':
				move(row,col-1);
				break;
			case 'r':
				move(row,col+1);
				break;
			default:
				throw "move error!";
			}
		}
		catch(int i){
		    if(i == 1){
			    cout << "Arived EXIT!" <<endl;
			    return 0;
		    }
		    if(i == 2){
		    	cout << "Hit the wall, Game Over!" << endl;
		    	return 0;
		    }
		}
		print_state();
	}
	return 0;
}
