



#include<iostream>

using namespace std;
bool Fire(char** arr, int y, int x, int* hitCount)
{
		if (arr[y][x] == '#')
		{		
			(*hitCount)++;
			return true;
			
		}
		else
		{
			return false;
		}
}





