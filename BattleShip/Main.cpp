#include "Menu.h"
#include "Grid.h"
#include "Play.h"
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <ctime>

int main(void) {

	bool repeat = true;

	do {

		cell grid[10][10];  //Initialize new grid
		randomiseShips(grid);

		char choice = selection(); //Player choice

		switch (choice) { 

			case 'A':

				game(40, false, grid); //Standard Game
				break;

			case 'B':

				banner();
				std::cout << "================================================================================================" << std::endl    //Instructions
					<< "|                                                                                              |" << std::endl
					<< "|                                          INSTRUCTIONS                                        |" << std::endl
					<< "|                                                                                              |" << std::endl
					<< "|      The objective of Battleship is to sink 5 randomly placed ships of different lengths     |" << std::endl
					<< "|      on a 10 x 10 grid. Shoot at positions on this grid by entering coordinates (ie. C3)     |" << std::endl
					<< "|     The ships will be vertical or horozontal but never diagonal and will be hidden to the    |" << std::endl
					<< "|                                            player.                                           |" << std::endl
					<< "|                                                                                              |" << std::endl
					<< "|         You will have 40 shots to destroy all 5 ships; An Aircraft Carrier (5 Cells),        |" << std::endl
					<< "|       a Battleship (4 Cells), a Destroyer (3 Cells), a Submarine (2 Cells) and a Patrol      |" << std::endl 
					<< "|         Boat (1 Cell). If you fail to destroy all these boats in the shots provided,         |" << std::endl
					<< "|                 you will lose. If you destroy all the ships however, you win!                |" << std::endl
					<< "|                                                                                              |" << std::endl
					<< "|         In debug mode, you will see two grids. One grid will display the standard game       |" << std::endl
					<< "|         grid whilst the other grid will show the positions of the battleships. In demo       |" << std::endl
					<< "|                mode, you will have an unlimited amount shots to destroy all the              |" << std::endl
					<< "|                                          battleship.                                         |" << std::endl
					<< "|                                                                                              |" << std::endl
					<< "================================================================================================\n" << std::endl;
				system("PAUSE");
				system("CLS");
				break;

			case 'C':

				game(40, true, grid); // Debug Game
				break;

			case 'D':

				game(200, false, grid);  //Demo Game
				break;

			case 'X':

				do {

					char check{ 0 };

					std::cout << "\nAre You Sure You Would Like To Exit? (Y/N): ";
					std::cin >> check;
					check = toupper(check);

					if (check == 'Y') {

						std::cout << "\nExiting...\n" << std::endl;
						repeat = false;  //Exit
						choice = 0;
						system("PAUSE");


					}
					else if (check == 'N') {

						std::cout << "\nCanceling...\n" << std::endl;
						choice = 0;
						system("PAUSE");
						system("CLS");

					}
					else {

						std::cout << "\nInvalid Input. Try Again\n" << std::endl;
						system("PAUSE");
						system("CLS");

					}

				} while (choice == 'X');

			default:

				break;

		}

	} while (repeat == true);

	return 0;

}
