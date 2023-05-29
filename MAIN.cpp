#include <iostream>
#include <time.h>
#include <Windows.h>
#include "Andrew.h"
#include "AutoPlace.h"
#include "CheckShot.h"
#include "deletearr.h"
#include "Fire.h"
#include "Perevirca.h"
#include "printhit.h"
#include "ShowFireRes.h"
#include "win.h"

using namespace std;

#define SIZE 10
#define PLAYER1TURN false
#define PLAYER2TURN true
#define AUTO 0
#define HANDLE 1

void PlacementChoice(int* method)
{
	while (true)
	{
		cout << "Choose placement method\n 0 - auto\n 1 - handle\n ->";
		cin >> *method;
		if (*method >= 0 && *method <= 1)
		{
			break;
		}
		else
		{
			cout << "NE" << endl;
		}
	}
}

int main()
{
	srand(time(NULL));
	char*** ShipPlacements = new char**[2];
	char*** ShowingInfo = new char**[2];
	char** P1ShipPlacement;
	char** P2ShipPlacement;
	char** P1ShowInfo;
	char** P2ShowInfo;

	int x, y;
	bool turn = false;
	bool hit, win = false;
	
	
	int* HitCounts = new int [2];
	HitCounts[0] = 0;
	HitCounts[1] = 0;
	int PlacementMethod;

	WaterInit(P1ShipPlacement);
	WaterInit(P2ShipPlacement);
	WaterInit(P1ShowInfo);
	WaterInit(P2ShowInfo);
	
	ShipPlacements[0] = P1ShipPlacement;
	ShipPlacements[1] = P2ShipPlacement;
	ShowingInfo[0] = P1ShowInfo;
	ShowingInfo[1] = P2ShowInfo;

	PlacementChoice(&PlacementMethod);
	

	//Розстановка кораблів
	for (int i = 0; i < 2; i++)			
	{
		if (PlacementMethod == AUTO)
		{
			//srand(time(0));
			RandomPlacement(ShipPlacements[i], SIZE);
			cout << "Player" << i + 1 << " ship placement"<<endl;
			print(ShipPlacements[i], SIZE);
		}
		else if (PlacementMethod == HANDLE)
		{
			ShipLocation(ShipPlacements[i]);
			cout << "Player" << i + 1 << " ship placement" << endl;
			print(ShipPlacements[i], SIZE);
		}
	} 
	
	while (!win)
	{
		cout << "Player" << (int)turn + 1 << " turn" << endl;
		print(ShowingInfo[(int)(!turn)], SIZE);
		while (true)
		{
			getInput(&x, &y);
			if(!(CheckShot(ShowingInfo[(int)(!turn)], y, x)))
			{
				break;
			}
		}
		hit = Fire(ShipPlacements[(int)(!turn)], y, x, &(HitCounts[(int)turn]));
		
		ChangeMap(ShowingInfo[(int)(!turn)], ShipPlacements[(int)(!turn)], SIZE, hit, y, x);
		print(ShowingInfo[(int)(!turn)], SIZE);
		isPopadania(&turn, hit);
		if (hit)
		{
			win = CheckShips(HitCounts[(int)turn]);
		}
	}

	Victory(turn);
	deletearr(P1ShipPlacement, SIZE);
	deletearr(P2ShipPlacement, SIZE);
	deletearr(P1ShowInfo, SIZE);
	deletearr(P2ShowInfo, SIZE);

}