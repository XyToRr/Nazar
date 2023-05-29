#pragma once

void RandomPlacement(char** field, int size);
void Place(char** field, int size, int shipSize);
bool ShipAround(char** field, int x1, int y1, int x2, int y2, int size);