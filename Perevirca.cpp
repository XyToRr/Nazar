#include<iostream>

using namespace std;

void isPopadania(bool* turn, bool hit)
{
	if (!hit)
	{
		*turn = !(*turn);
	}
}