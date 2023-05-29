#include <iostream>

using namespace std;

void deletearr(char** arr, int size)
{
	for(int i=0;i<size;i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

