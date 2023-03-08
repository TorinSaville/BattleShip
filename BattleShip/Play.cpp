#include <iostream>
#include "Play.h"

#include "Menu.h"
#include "Grid.h"
#include <stdlib.h>
#include <iomanip>
#include <Windows.h>

void _debugMode(int _ammo, bool _debug, cell _grid[10][10]){

	if (_debug == false) {

		displayGrid(_grid);

	}
	else {

		displayGridDebug(_grid);

	}

	if (_ammo < 41 && _ammo >= 0) {

		std::cout << "\n" << std::setw(30) << "Ammo Remaining: " << _ammo << std::endl
			<< "\n-------------------------------------------------------------------------------------------------" << std::endl;

	}
	else if (_ammo == -1) {

		std::cout << "\n" << std::setw(30) << "Ammo Remaining: 0" << std::endl
			<< "\n-------------------------------------------------------------------------------------------------" << std::endl;

	}
	else {

		std::cout << "\n" << std::setw(35) << "Ammo Remaining: Unlimited" << std::endl
			<< "\n-------------------------------------------------------------------------------------------------" << std::endl;

	}

}

char shotInputY() {

	char y{ 0 };

		std::cout << "\n\tWhere Would You Like To Shoot?          (Select 'X' as your Y coordinate to exit game)\n" << "\n\tY Coordinate (A-J): ";
		std::cin >> y;
		std::cin.ignore(INT_MAX, '\n');

		y = toupper(y);

		return y;

}

int shotInputX() {

	int x{ 0 };

	std::cout << "\tX Coordinate (1 - 10): ";
	std::cin >> x;

	return x;

}

bool shotCheck(cell _grid[10][10], char _y, int _x) {

	bool repeat = true;

	if ((_y >= 'A' && _y <= 'J') && (_x >= 1 && _x <= 10)) {

		if (_grid[(int)_y - 65][_x - 1].gShow == true) {

			std::cout << "\n\tError: Target Already Hit. Try Again\n\n";
			system("PAUSE");
			system("CLS");

		}
		else {

			std::cout << "\n\tAiming for " << _y << _x << "\n\n";
			repeat = false;
			system("PAUSE");
			system("CLS");

		}

	}
	else {

		std::cout << "\n\tError: Invalid Coordinates. Try Again\n\n";
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		system("PAUSE");
		system("CLS");

	}

	return repeat;

}

void game(int _ammo, bool _debug, cell _grid[10][10]) {

	int aCount = 0;
	int bCount = 0;
	int dCount = 0;
	int sCount = 0;
	int hits = 0;

	do {

		int x{ 0 };
		int y{ 0 };
		char charY{ 0 };
		
		bool repeat = true;

		do {
			
			_debugMode(_ammo, _debug, _grid);

			charY = shotInputY();  //Take Shot Input

			if (charY != 'X') {

				x = shotInputX();
				repeat = shotCheck(_grid, charY, x);  //Check Shot is Valid

			}
			else {

				repeat = false;

			}

		} while (repeat == true);

		if (charY != 'X') {

			x = x - 1;
			y = (int)charY - 65;

			_grid[y][x].gShow = true;  //Set target location to show
			_ammo--;

			if (_grid[y][x].gContent == 'X') {  //Check Location contents, if there is no ship it has missed

				_debugMode(_ammo, _debug, _grid);

				std::cout << "\n\tOH NO! You Missed!\n" << std::endl;
				Beep(500, 500);
				system("PAUSE");
				system("CLS");

			}
			else {  //If there is ship, find which ship

				_debugMode(_ammo, _debug, _grid);

				std::cout << "\n\tHIT!\n" << std::endl;

				if (_grid[y][x].gContent == 'A') {

					aCount++;  //Add one to ship counter

					if (aCount == 5) {

						std::cout << "\tYou Destroyed My Aircraft Carrier!\n" << std::endl;
						aCount = 0;
						hits++;
						Beep(1250, 750);

					}
					else {
						Beep(1000, 500);
					}

				}
				else if (_grid[y][x].gContent == 'B') {

					bCount++;

					if (bCount == 4) {

						std::cout << "\tYou Destroyed My BattleShip!\n" << std::endl;
						bCount = 0;
						hits++;
						Beep(1250, 750);

					}
					else {
						Beep(1000, 500);
					}

				}
				else if (_grid[y][x].gContent == 'D') {

					dCount++;

					if (dCount == 3) {

						std::cout << "\tYou Destroyed My Destroyer!\n" << std::endl;
						dCount = 0;
						hits++;
						Beep(1250, 750);

					}
					else {
						Beep(1000, 500);
					}

				}
				else if (_grid[y][x].gContent == 'S') {

					sCount++;

					if (sCount == 2) {

						std::cout << "\tYou Destroyed My Submarine!\n" << std::endl;
						sCount = 0;
						hits++;
						Beep(1250, 750);

					}
					else {
						Beep(1000, 500);
					}

				}
				else {

					std::cout << "\tYou Destroyed My Patrol Boat!\n" << std::endl;
					hits++;
					Beep(1250, 750);

				}

				system("PAUSE");
				system("CLS");

			}

		}
		else {

		_ammo = -1;
		system("CLS");

		}

	} while (_ammo > 0 && hits < 5);  //Repeat while there is ammo left and not all ships are sunk

	if (hits == 5) {

		_debugMode(_ammo, _debug, _grid);

		std::cout << "\n\tHooray! You've Sunk All The Battleships!\n" << std::endl;

		system("PAUSE");
		system("CLS");

	}
	else if (_ammo == 0) {

		for (int i = 0; i < 10; i++) {

			for (int j = 0; j < 10; j++) {

				if (_grid[i][j].gContent != 'X') {

					_grid[i][j].gShow = true;

				}

			}
		}

		_debugMode(_ammo, _debug, _grid);

		std::cout << "\n\tOH NO! We're Out Of Ammo! Better Luck Next Time!\n" << std::endl;

		system("PAUSE");
		system("CLS");

	}
	else {

		for (int i = 0; i < 10; i++) {

			for (int j = 0; j < 10; j++) {

				if (_grid[i][j].gContent != 'X') {

					_grid[i][j].gShow = true;

				}

			}
		}

		_debugMode(_ammo, _debug, _grid);

		std::cout << "\n\tExiting Game...\n" << std::endl;

		system("PAUSE");
		system("CLS");

	}

}