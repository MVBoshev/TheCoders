#include <iostream>
using namespace std;

const int WIDTH = 20;
const int HEIGHT = 20;
unsigned char player = { 1 };
// Function prototypes

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

	}
}