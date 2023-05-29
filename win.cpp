#include <iostream>
using namespace std;

bool CheckShips(int count)
{
	if (count == 20)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Victory(bool move)
{
	if (move == false)
	{
		cout << "player 1 has won";
	}
	if (move == true)
	{
		cout << "player 2 has won";
	}
}