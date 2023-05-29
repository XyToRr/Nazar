#include <iostream>

using namespace std;

void print(char** board, int size)
{
	cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i << " ";
		for (int j = 0; j < size; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}



void getInput(int* x, int* y) {
	while (true) {
		cout << "Enter x coordinate (0-9): ";
		cin >> *x;
		if (*x >= 0 && *x < 10) {
			break;
		}
		else {
			cout << "Invalid input. Please try again." << endl;
		}
	}



	while (true) {
		cout << "Enter y coordinate (0-9): ";
		cin >> *y;
		if (*y >= 0 && *y < 10) {
			break;
		}
		else {
			cout << "Invalid input. Please try again." << endl;
		}
	}
}