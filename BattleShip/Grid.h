#ifndef _GRID_H_
#define _GRID_H_

struct cell {

	bool gShow{ false };
	char gContent{'X'};

};

void displayGrid(cell _grid[10][10]);
void displayGridDebug(cell _grid[10][10]);
void randomiseShips(cell _grid[10][10]);

#endif
