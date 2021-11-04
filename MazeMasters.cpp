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