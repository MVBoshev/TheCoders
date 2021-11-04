#include <iostream>
using namespace std;

const int WIDTH = 20;
const int HEIGHT = 20;
unsigned char player = { 1 };
// Function prototypes

void displayMenu();
void printMaze(char maze[][WIDTH], int curX, int cury);
bool validMove(char maze[][WIDTH], int newX, int newY);
bool move(char maze[][WIDTH], int& curX, int& curY, int newX, int newY);
// These functions will return true or false if moving to a specified coordinate is valid

void displayMenu()
{
	char a;
	cout << "===================================================== \n";
	cout << " \t\tMENU \t \n ";
	cout << "===================================================== \n";
	cout << "Press any character to continue to the game";
	cout << endl;
	cin >> a;

}

bool validMove(char maze[][WIDTH], int newX, int newY)
{
	// Checks if we are going off the maze edges
	if (newX < 0 || newX >= WIDTH)
	{
		return false;
	}
	if (newY < 0 || newY >= HEIGHT)
	{
		return false;

	}
	// Checks if we hit a wall
	if (maze[newY][newX] == '#')
	{
		return false;
	}
	return true;
}
// Make the move on the maze to move to a new coordinate
// curX and curY are passed by reference so they are changed to
// the new coordinates. The move coordinates are valid.
// This returns true if we move on the exit and otherwise false.

bool move(char maze[][WIDTH], int& curX, int& curY, int newX, int newY)
{
	bool foundExit = false;
	if (maze[newY][newX] == 'E') // Check for exit
	{
		foundExit = true;
	}
	cout << endl;
	cout << "Congratulations, you have won our maze game!" << endl;
	curX = newX; // Update location
	curY = newY;
	return foundExit;

}
// Display the maze in ASCII
void printMaze(char maze[][WIDTH], int curx, int cury)
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if ((j == curx) && (i == cury))
			{
				cout << player;
			}
			else
			{
				cout << maze[i][j];
			}
		}
		cout << endl;
	}
}



int main()
{
	char maze[HEIGHT][WIDTH] = {
	 {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
	 {'#',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ','#','#',' ','#'},
	 {'#',' ','#',' ','#','#','#',' ',' ',' ',' ','#','#',' ','#',' ',' ',' ',' ','#'},
	 {'#',' ','#',' ','#',' ','#',' ','#',' ','#','#',' ',' ',' ','#',' ','#','#','#'},
	 {'#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ',' ','#'},
	 {'#','#',' ','#',' ','#','#','#','#',' ','#',' ','#','#',' ',' ',' ','#',' ','#'},
	 {'#',' ',' ','#',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#','#',' ','#'},
	 {'#',' ','#','#','#',' ','#',' ',' ',' ','#','#','#',' ',' ',' ',' ','#',' ','#'},
	 {'#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#','#',' ',' ',' ','E'},
	 {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
	};

	int x = 1, y = 1;
	bool foundExit = false;

	while (!foundExit)
	{
		system("cls");

		printMaze(maze, x, y);
		cout << endl;
		cout << "Use WASD to move." << endl;

		char c;
		cin >> c;
		c = tolower(c);

		switch (c)
		{
		  case 'w':
			if (validMove(maze, x, y - 1))
			{
				foundExit = move(maze, x, y, x, y - 1);
			}
			break;
		  case 'a':
			if (validMove(maze, x - 1, y))
			{
				foundExit = move(maze, x, y, x - 1, y);
			}
			break;
		  case 's':
			  if (validMove(maze, x, y + 1))
			  {
				  foundExit = move(maze, x, y, x, y + 1);
			  }
			  break;
		  case 'd':
			  if (validMove(maze, x + 1, y))
			  {
				  foundExit = move(maze, x, y, x + 1, y);

			  }
		}
	}
}