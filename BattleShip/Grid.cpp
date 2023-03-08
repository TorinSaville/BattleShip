#include <iostream>
#include "Grid.h"

#include "Menu.h"
#include <ctime>
#include <iomanip>

void randomiseShips(cell _grid[10][10]) {

	int x, y, axis{ 0 };
	bool tryAgain{ true };
	bool free{ true };
	srand(time(NULL));

	for (int i = 0; i < 5; i++) { //5 Ships

		do {

			x = rand() % 10; //Random Coordinates + Axis
			y = rand() % 10;
			axis = rand() % 2;

			for (int j = 0; j < i + 1; j++) { //How Many Cells Need To Check


				if (axis == 1) {	//Vertical Placement Check

					if (y <= 5) {

						if (_grid[y + j][x].gContent != 'X') {  //Check Down

							free = false;

						}

					}
					else {

						if (_grid[y - j][x].gContent != 'X') {  //Check Up

							free = false;

						}

					}

				}
				else {	//Horizontal Placement Check

					if (x <= 5) {

						if (_grid[y][x + j].gContent != 'X') {  //Check Right

							free = false;

						}

					}
					else {

						if (_grid[y][x - j].gContent != 'X') {  //Check Left

							free = false;

						}

					}

				}

			}

			if (free == true) {  //Placement of Ship
				for (int k = 0; k < i+1; k++) {
					if (axis == 1) {	//Vertical Placement
						if (y <= 5) {  //Down
							switch (i) {
							case 4:
								_grid[y + k][x].gContent = 'A';
								tryAgain = false;
								break;
							case 3:
								_grid[y + k][x].gContent = 'B';
								tryAgain = false;
								break;
							case 2:
								_grid[y + k][x].gContent = 'D';
								tryAgain = false;
								break;
							case 1:
								_grid[y + k][x].gContent = 'S';
								tryAgain = false;
								break;
							case 0:
								_grid[y + k][x].gContent = 'P';
								tryAgain = false;
								break;
							default:
								break;
							}
						}
						else {  //Up
							switch (i) {
							case 4:
								_grid[y - k][x].gContent = 'A';
								tryAgain = false;
								break;
							case 3:
								_grid[y - k][x].gContent = 'B';
								tryAgain = false;
								break;
							case 2:
								_grid[y - k][x].gContent = 'D';
								tryAgain = false;
								break;
							case 1:
								_grid[y - k][x].gContent = 'S';
								tryAgain = false;
								break;
							case 0:
								_grid[y - k][x].gContent = 'P';
								tryAgain = false;
								break;
							default:
								break;
							}
						}
					}
					else {	//Horizontal Placement
						if (x <= 5) {  //Right
							switch (i) {
							case 4:
								_grid[y][x + k].gContent = 'A';
								tryAgain = false;
								break;
							case 3:
								_grid[y][x + k].gContent = 'B';
								tryAgain = false;
								break;
							case 2:
								_grid[y][x + k].gContent = 'D';
								tryAgain = false;
								break;
							case 1:
								_grid[y][x + k].gContent = 'S';
								tryAgain = false;
								break;
							case 0:
								_grid[y][x + k].gContent = 'P';
								tryAgain = false;
								break;
							default:
								break;
							}
						}
						else {  //Left
							switch (i) {
							case 4:
								_grid[y][x - k].gContent = 'A';
								tryAgain = false;
								break;
							case 3:
								_grid[y][x - k].gContent = 'B';
								tryAgain = false;
								break;
							case 2:
								_grid[y][x - k].gContent = 'D';
								tryAgain = false;
								break;
							case 1:
								_grid[y][x - k].gContent = 'S';
								tryAgain = false;
								break;
							case 0:
								_grid[y][x - k].gContent = 'P';
								tryAgain = false;
								break;
							default:
								break;
							}
						}
					}
				}

			}
			else {  //Retry Placement

				tryAgain = true;
				free = true;

			}

		} while (tryAgain == true);

	}

}

void displayGrid(cell _grid[10][10]) {

	char rowString[46]{ " ---+---+---+---+---+---+---+---+---+---+---+"};

	banner();
	std::cout << std::endl << "    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |1 0|" << std::endl << rowString << std::endl;

	for (int i = 0; i < 10; i++) {

		std::cout << "  " << char(i + 65) << " |";

		for (int j = 0; j < 10; j++) {

			if (_grid[i][j].gShow == false) {  //Before Hit

				std::cout << "   |";

			}
			else {  //After Hit

				std::cout << " " << _grid[i][j].gContent << " |";

			}

		}

		switch (i) {

		case 2:
			std::cout << "\t\tAircraft Carrier (A): 5 Cells";
			break;
		case 3:
			std::cout << "\t\tBattleship (B): 4 Cells";
			break;
		case 4:
			std::cout << "\t\tDestroyer (D): 3 Cells";
			break;
		case 5:
			std::cout << "\t\tSubmarine (S): 2 Cells";
			break;
		case 6:
			std::cout << "\t\tPatrol Boat (P): 1 Cells";
			break;
		default:
			break;

		}

		std::cout << std::endl << rowString << std::endl;

	}

}

void displayGridDebug(cell _grid[10][10]) {

	char rowString[46]{ " ---+---+---+---+---+---+---+---+---+---+---+" };

	banner();
	std::cout << std::endl << "    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |1 0|         | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |1 0|" << std::endl 
		<< rowString << "     " << rowString << std::endl;

	for (int i = 0; i < 10; i++) {

		std::cout << "  " << char(i + 65) << " |";  //Standard Grid

		for (int j = 0; j < 10; j++) {

			if (_grid[i][j].gShow == false) {

				std::cout << "   |";

			}
			else {

				std::cout << " " << _grid[i][j].gContent << " |";

			}

		}

		std::cout << "       " << char(i + 65) << " |";  //Debug Grid

		for (int k = 0; k < 10; k++) {

			if (_grid[i][k].gContent == 'X') {

				std::cout << "   |";

			}
			else {

				std::cout << " " << _grid[i][k].gContent << " |";

			}

		}

		std::cout << std::endl << rowString << "     " << rowString << std::endl;

	}

}


