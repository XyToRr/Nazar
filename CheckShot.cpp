#include<iostream>

using namespace std;

#define SIZE 10

bool CheckShot(char** arr, int k1, int k2)
{
	if (arr[k1][k2] != '^')
	{
		cout << "You have already shot there"<<endl;
		return true;
	}
	else
	{
		return false;
	}
}