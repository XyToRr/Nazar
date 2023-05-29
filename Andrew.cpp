#include <iostream>
#include <math.h>
#include <random>
#define SIZE 10



using namespace std;

void WaterInit(char**& p /*береться поле, яке заповнюємо водою*/)
{
	p = new char* [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		p[i] = new char[SIZE];
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			p[i][j] = '^';
		}
	}
}

bool CheckIfThereIsNoShips(char** p)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (p[i][j] == 'N')
			{
				for (int l = -1; l < 2; l++)
				{
					for (int k = -1; k < 2; k++)
					{
						if ((i + l >= 0) && (j + k >= 0) && (i + l <= 9) && (j + k <= 9))
						{
							if (p[i + l][j + k] == '#')
								return 0;
						}
					}
				}
			}
		}
	}
	return 1;
}

void ShipLocation(char** p /*береться поле, на якому ми будемо розставляти кораблі*/)
{

	int ship_1 = 4, ship_2 = 3, ship_3 = 2, ship_4 = 1, count_size,/*к-сть кожного корабля, та для майбутнього підрахунку кораблів*/ f_x, f_y, s_x, s_y /*Розстановка кораблів*/, f, s /*для розстановки*/;
	while (ship_1 != 0 || ship_2 != 0 || ship_3 != 0 || ship_4 != 0)
	{
		count_size = 0;
		cout << endl << "Enter the first position of the ship (x and y):";
		cin >> f_x >> f_y;
		cout << "Enter the second position of the ship (x and y):";
		cin >> s_x >> s_y;
		if ((f_x == s_x || f_y == s_y) && abs(f_x - s_x) <= 3 && abs(f_y - s_y) <= 3)
		{
			if (f_x - s_x == 0)
			{
				if (f_y <= s_y)
				{
					f = f_y;
					s = s_y;
				}
				if (f_y >= s_y)
				{
					f = s_y;
					s = f_y;
				}
				for (int i = f; i <= s; i++)
				{
					count_size++;
					if (p[i][f_x] != '#')
						p[i][f_x] = 'N';
				}
			}
			else if (f_y - s_y == 0)
			{
				if (f_x < s_x)
				{
					f = f_x;
					s = s_y;
				}
				if (f_x > s_x)
				{
					f = s_x;
					s = f_y;
				}
				for (int i = f; i <= s; i++)
				{
					p[f_y][i] = 'N';
					count_size++;
				}
			}
			if (CheckIfThereIsNoShips(p) && ((count_size == 1 && ship_1 != 0) || (count_size == 2 && ship_2 != 0) || (count_size == 3 && ship_3 != 0) || (count_size == 4 && ship_4 != 0)))
			{
				for (int l = 0; l < SIZE; l++)
				{
					for (int k = 0; k < SIZE; k++)
					{
						if (p[l][k] == 'N')
							p[l][k] = '#';
					}
				}
				switch (count_size)
				{
				case 1:
					ship_1--;
					break;
				case 2:
					ship_2--;
					break;
				case 3:
					ship_3--;
					break;
				case 4:
					ship_4--;
					break;
				}
			}
			else
				for (int l = 0; l < SIZE; l++)
				{
					for (int k = 0; k < SIZE; k++)
					{
						if (p[l][k] == 'N')
							p[l][k] = '^';
					}
				}
		}
	}
}