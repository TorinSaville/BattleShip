#ifndef _PLAY_H_
#define _PLAY_H_
#include "Grid.h"

void debugMode(int _ammo, bool _debug, cell _grid[10][10]);
char shotInputY();
int shotInputX();
bool shotCheck(cell _grid[10][10], char _y, int _x);
void game(int _ammo, bool _debug, cell _grid[10][10]);

#endif
