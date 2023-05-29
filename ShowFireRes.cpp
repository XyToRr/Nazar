#include <iostream>

#define MISS '*'
#define HIT 'X'
#define SHIP '#'
#define HORIZONTAL 0
#define VERTICAL 1
#define ONESIZEDSHIP -1

using namespace std;

void CheckZone(int* startIcorner, int* endIcorner, int* startJcorner, int* endJcorner, int size, int x, int y, int endX, int endY);

void KillShip(char** game, int startX, int startY, int size, int endX, int endY, int direction)
{
	int startIcorner, startJcorner;
	int endIcorner, endJcorner;
	CheckZone(&startIcorner, &endIcorner, &startJcorner, &endJcorner, size, startX, startY, endX, endY);

	if (direction == VERTICAL)
	{
		for (int i = startIcorner; i <= endIcorner; i++)
		{
			for (int j = startJcorner; j <= endJcorner; j++)
			{
			
				game[i][j] = MISS;
			}
		}
		for (int i = startY; i <= endY; i++)
		{
			game[i][startX] = SHIP;
		}
		
	}
	else if (direction == HORIZONTAL)
	{
		for (int i = startIcorner; i <= endIcorner; i++)
		{
			for (int j = startJcorner; j <= endJcorner; j++)
			{			
				game[i][j] = MISS;
			}
		}
		for (int i = startX; i <= endX; i++)
		{
			game[startY][i] = SHIP;
		}
		
	}
	else if (direction == ONESIZEDSHIP)
	{
		for (int i = startIcorner; i <= endIcorner; i++)
		{
			for (int j = startJcorner; j <= endJcorner; j++)
			{
				game[i][j] = MISS;
			}
		}
		game[startY][startX] = SHIP;
		
	}	
}

void CheckZone(int* startIcorner, int* endIcorner, int* startJcorner, int* endJcorner, int size, int x, int y, int endX, int endY)
{
	if (y == 0)
	{
		*startIcorner = y;
		*endIcorner = endY + 1;
	}
	else if (endY == size - 1)
	{
		*startIcorner = y - 1;
		*endIcorner = endY;
	}
	else
	{
		*startIcorner = y - 1;
		*endIcorner = endY + 1;
	}

	if (x == 0)
	{
		*startJcorner = x;
		*endJcorner = endX + 1;
	}
	else if (endX == size - 1)
	{
		*startJcorner = x - 1;
		*endJcorner = endX;
	}
	else
	{
		*startJcorner = x - 1;
		*endJcorner = endX + 1;
	}
}

int CheckDirection(char** shipInfo, int x, int y, int size)
{
	int startI, startJ;
	int endI, endJ;

	if (y == 0)
	{
		startI = y;
		endI = y + 1;
	}
	else if (y == size - 1)
	{
		startI = y-1;
		endI = y;
	}
	else
	{
		startI = y - 1;
		endI = y+1;
	}

	if (x == 0)
	{
		startJ = x;
		endJ = x + 1;
	}
	else if (x == size - 1)
	{
		startJ = x - 1;
		endJ = x;
	}
	else
	{
		startJ = x - 1;
		endJ = x + 1;
	}

	for (int i = startI; i <= endI; i++)
	{
		for (int j = startJ; j <= endJ; j++)
		{
			if ((j == x || i == y) && shipInfo[i][j] == SHIP)
			{
				if (j == x && i != y)
				{
					return VERTICAL;
				}
				else if (i == y && j != x)
				{
					return HORIZONTAL;
				}
			}
		}
	}

	return ONESIZEDSHIP;
}

void FindEndPoints(char** info,int* startX, int* startY ,int* endX, int* endY, int x, int y, int direction, int size)
{
	if (direction == ONESIZEDSHIP)
	{
		*startX = x;
		*endX = x;
		*startY = y;
		*endY = y;
	}
	else
	{
		if (direction == VERTICAL)
		{
			for (int i = y; i>=0 && info[i][x] == SHIP; i--)
			{
				*startY = i;
			}
			for (int i = y; i < size && info[i][x] == SHIP; i++)
			{
				*endY = i;
			}
			*startX = x;
			*endX = x;
		}
		else if (direction == HORIZONTAL)
		{
			for (int i = x; i >= 0 && info[y][i] == SHIP ; i--)
			{
				*startX = i;
			}
			for (int i = x;i < size && info[y][i] == SHIP; i++)
			{
				*endX = i;
			}
			*startY = y;
			*endY = y;
		}
	}

}

bool MustToKill(char** info, char** game, int startX, int startY, int endX, int endY, int direction)
{
	int countInfo = 0, countGame = 0;
	if (direction == ONESIZEDSHIP)
	{
		return true;
	}
	else if (direction == VERTICAL)
	{
		for (int i = startY; i <= endY; i++)
		{
			if (game[i][startX] == HIT)
			{
				countGame++;
			}
			if (info[i][startX] == SHIP)
			{
				countInfo++;
			}

			
		}
	}
	else if (direction == HORIZONTAL)
	{
		for (int i = startX; i <= endX; i++)
		{
			if (game[startY][i] == HIT)
			{
				countGame++;
			}
			if (info[startY][i] == SHIP)
			{
				countInfo++;
			}


		}
	}
	if (countGame == countInfo)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ChangeMap(char** game, char** shipInfo, int size, bool hit, int y, int x)
{
	int direction;
	int startY, endY;
	int startX, endX;
	if (!hit)
	{
		game[y][x] = MISS;
	}
	else
	{
		game[y][x] = HIT;
		direction = CheckDirection(shipInfo, x, y, 10);
		FindEndPoints(shipInfo, &startX, &startY, &endX, &endY, x, y, direction, size);
		//if (direction == ONESIZEDSHIP)
		//{
		if (MustToKill(shipInfo, game, startX, startY, endX, endY, direction))
		{
			KillShip(game, startX, startY, size, endX, endY, direction);
		}
			
		//}
	}
}
