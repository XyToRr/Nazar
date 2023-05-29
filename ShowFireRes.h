#pragma once

void CheckZone(int* startIcorner, int* endIcorner, int* startJcorner, int* endJcorner, int size, int x, int y, int endX, int endY);
void KillShip(char** game, int startX, int startY, int size, int endX, int endY, int direction);
void CheckZone(int* startIcorner, int* endIcorner, int* startJcorner, int* endJcorner, int size, int x, int y, int endX, int endY);
int CheckDirection(char** shipInfo, int x, int y, int size);
void FindEndPoints(char** info, int* startX, int* startY, int* endX, int* endY, int x, int y, int direction, int size);
bool MustToKill(char** info, char** game, int startX, int startY, int endX, int endY, int direction);
void ChangeMap(char** game, char** shipInfo, int size, bool hit, int y, int x);