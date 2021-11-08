#include <iostream>
#include <conio.h>
using namespace std;

const int width = 20;
const int height = 20;
unsigned char player = { 1 };
// Function prototypes

void displayMenu();
void printMaze(char maze[][width], int curX, int curY);
bool validMove(char maze[][width], int newX, int newY);
bool move(char maze[][width], int& curX, int& curY, int newX, int newY);
// These functions will return true or false if moving to a specified coordinate is valid


void displayMenu()
{
	char startGameButton;
	cout << "=====================================================\n";
	cout << " \t\tMENU \t \n";
	cout << "=====================================================\n";
	cout << "Press any button to continue to the game";
	cout << endl;
	startGameButton = _getch();
}

bool validMove(char maze[][width], int newX, int newY)
{
	// Checks if we are going off the maze edges
	if (newX < 0 || newX >= width)
	{
		return false;
	}
	if (newY < 0 || newY >= height)
	{
		return false;

	}
	// Checks if we hit a wall
	if (maze[newY][newX] == char(219))
	{
		return false;
	}
	return true;
}

// Make the move on the maze to move to a new coordinate
// curX and curY are passed by reference so they are changed to
// the new coordinates. We assume the move coordinates are valid.
// This returns true if we move onto the exit, false otherwise.

bool move(char maze[][width], int& curX, int& curY, int newX, int newY)
{
	bool foundExit = false;
	if (maze[newY][newX] == 'E') // Check for exit
	{
		foundExit = true;
		cout << "Congratulations, you have won our maze game!" << endl;
	}
	cout << endl;

	curX = newX; // Update location
	curY = newY;
	return foundExit;

}
// Display the maze in ASCII
void printMaze(char maze[][width], int curX, int curY)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if ((j == curX) && (i == curY))
			{
				cout << player;
				cout << maze[i][j];
			}
			else if (maze[i][j] == 'E')
			{
				cout << maze[i][j];
			}

			else
			{
				cout << maze[i][j] << maze[i][j];
			}
		}
		cout << endl;
	}
}

int main()
{
	displayMenu();

	char Wallsymb = char(219);

	char(*maze)[width] = new char[height][width]
	{

  {Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb},
  {Wallsymb,' ',' ',' ',' ',' ',' ',' ',Wallsymb,Wallsymb,' ',' ',' ',' ',' ',' ',Wallsymb,Wallsymb,' ',Wallsymb},
  {Wallsymb,' ',Wallsymb,' ',Wallsymb,Wallsymb,Wallsymb,' ',' ',' ',' ',Wallsymb,Wallsymb,' ',Wallsymb,' ',' ',' ',' ',Wallsymb},
  {Wallsymb,' ',Wallsymb,' ',Wallsymb,' ',Wallsymb,' ',Wallsymb,' ',Wallsymb,Wallsymb,' ',' ',' ',Wallsymb,' ',Wallsymb,Wallsymb,Wallsymb},
  {Wallsymb,' ',' ',' ',' ',' ',' ',' ',Wallsymb,' ',Wallsymb,' ',' ',Wallsymb,' ',Wallsymb,' ',' ',' ',Wallsymb},
  {Wallsymb,Wallsymb,' ',Wallsymb,' ',Wallsymb,Wallsymb,Wallsymb,Wallsymb,' ',Wallsymb,' ',Wallsymb,Wallsymb,' ',' ',' ',Wallsymb,' ',Wallsymb},
  {Wallsymb,' ',' ',Wallsymb,' ',' ',' ',' ',Wallsymb,' ',Wallsymb,' ',' ',' ',Wallsymb,' ',Wallsymb,Wallsymb,' ',Wallsymb},
  {Wallsymb,' ',Wallsymb,Wallsymb,Wallsymb,' ',Wallsymb,' ',' ',' ',Wallsymb,Wallsymb,Wallsymb,' ',' ',' ',' ',Wallsymb,' ',Wallsymb},
  {Wallsymb,' ',' ',' ',' ',' ',Wallsymb,' ',Wallsymb,' ',' ',' ',' ',' ',Wallsymb,Wallsymb,' ',' ',' ','E'},
  {Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb,Wallsymb},
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
		c = _getch();

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