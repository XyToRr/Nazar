#include <iostream>
#include <time.h>

#define SHIP '#'
#define VERTICAL 0
#define HORIZONTAL 1
#define SIZE 10

using namespace std;


bool ShipAround(char** field, int x1, int y1, int x2, int y2, int size)
{
	int startI, startJ;
	int endI, endJ;
	if (y1 == 0)
	{
		startI = y1;
		endI = y2 + 1;
	}
	else if (y2 == size - 1)
	{
		startI = y1 - 1;
		endI = y2;
	}
	else
	{
		startI = y1 - 1;
		endI = y2 + 1;
	}

	if (x1 == 0)
	{
		startJ = x1;
		endJ = x2 + 1;
	}
	else if (x2 == size - 1)
	{
		startJ = x1 - 1;
		endJ = x2;
	}
	else
	{
		startJ = x1 - 1;
		endJ = x2 + 1;
	}
	//cout << startI << " " << endI << endl;
	//cout << startJ << " " << endJ << endl;

	for (int i = startI; i <= endI; i++)
	{
		for (int j = startJ; j <= endJ; j++)
		{
			//cout << field[i][j];
			if (field[i][j] == SHIP)
			{
				//cout << endl;
				return false;
			}
		}
		//cout << endl;
	}
	return true;
}

void Place(char** field, int size, int shipSize)
{
	int x, y;
	int x2, y2;
	int direction;

	direction = rand() % 2;

	//spawn 4paklubnyy ship
	if (direction == HORIZONTAL)
	{
		while (true)
		{
			x = rand() % (size - shipSize + 1);
			y = rand() % 10;
			//cout << x << " " << y << endl;
			x2 = x + shipSize - 1;
			if (ShipAround(field, x, y, x2, y, SIZE))
			{
				break;
			}
		}
		for (int j = x; j <= x2; j++)
		{
			field[y][j] = SHIP;
		}
	}
	else if (direction == VERTICAL)
	{
		while (true)
		{
			x = rand() % 10;
			y = rand() % (SIZE - shipSize + 1);
			y2 = y + shipSize - 1;

			if (ShipAround(field, x, y, x, y2, SIZE))
			{
				break;
			}
		}
		for (int i = y; i <= y2; i++)
		{
			field[i][x] = SHIP;
		}
	}
}

void RandomPlacement(char** field, int size)
{
	Place(field, SIZE, 4);
	//PrintArr(field);
	for (int i = 0; i < 2; i++)
	{
		Place(field, SIZE, 3);
		//PrintArr(field);
	}
	for (int i = 0; i < 3; i++)
	{
		Place(field, SIZE, 2);
		//PrintArr(field);
	}
	for (int i = 0; i < 4; i++)
	{
		Place(field, SIZE, 1);
		//PrintArr(field);
	}
}


