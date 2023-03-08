#include <iostream>
#include "Menu.h"

#include "Grid.h"
#include <stdlib.h>
#include <iomanip>

void banner() {

	std::cout << "================================================================================================" << std::endl
			  << "|  888888ba   .d888888 d888888P d888888P dP        88888888b .d88888b  dP     dP dP 888888ba   |" << std::endl
			  << "|  88    `8b d8'    88    88       88    88        88        88.     ' 88     88 88 88    `8b  |" << std::endl
			  << "|  88aaaa8P' 88aaaaa88    88       88    88        88aaaa    `Y88888b. 88aaaaa88 88 88aaaa8P'  |" << std::endl
			  << "|  88   `8b. 88     88    88       88    88        88              `8b 88     88 88 88         |" << std::endl
			  << "|  88    .88 88     88    88       88    88        88        d8'   .8P 88     88 88 88         |" << std::endl
			  << "|  88888888P 88     88    dP       dP    88888888P 88888888P  Y88888P  dP     dP dP dP         |" << std::endl
			  << "================================================================================================" << std::endl;

}

void menu() {

		std::cout << "================================================================================================" << std::endl
			<< "|                      _____ _____ _____ _____    _____ _____ _____ _____                      |" << std::endl
			<< "|                     |     |  _  |     |   | |  |     |   __|   | |  |  |                     |" << std::endl
			<< "|                     | | | |     |-   -| | | |  | | | |   __| | | |  |  |                     |" << std::endl
			<< "|                     |_|_|_|__|__|_____|_|___|  |_|_|_|_____|_|___|_____|                     |" << std::endl
			<< "|                                                                                              |" << std::endl
			<< "|                                          [A] Play                                            |" << std::endl
			<< "|                                          [B] Instructions                                    |" << std::endl
			<< "|                                          [C] Debug                                           |" << std::endl
			<< "|                                          [D] Demo                                            |" << std::endl
			<< "|                                          [X] Exit                                            |" << std::endl
			<< "|                                                                                              |" << std::endl
			<< "================================================================================================" << std::endl
			<< "\n\tEnter Here: ";

}

char selection() {

	char choice{ 0 };
	bool repeat = true;

	do {

		banner();
		menu();
		std::cin >> std::setw(1) >> choice;
		choice = toupper(choice);

		switch (choice) {

		case 'A':
			std::cout << "\n\tYou have chosen to play\n" << std::endl << std::flush;
			repeat = false;
			system("PAUSE");
			system("CLS");
			break;
		case 'B':
			std::cout << "\n\tYou have chosen the instructions\n" << std::endl << std::flush;
			repeat = false;
			system("PAUSE");
			system("CLS");
			break;
		case 'C':
			std::cout << "\n\tYou have chosen debug mode\n" << std::endl << std::flush;
			repeat = false;
			system("PAUSE");
			system("CLS");
			break;
		case 'D':
			std::cout << "\n\tYou have chosen demo mode\n" << std::endl << std::flush;
			repeat = false;
			system("PAUSE");
			system("CLS");
			break;
		case 'X':
			std::cout << "\n\tYou have chosen to exit\n" << std::endl << std::flush;
			repeat = false;
			system("PAUSE");
			system("CLS");
			break;
		default:
			std::cout << "\n\tError: Incorrect Input. Try Again.\n" << std::endl << std::flush;
			system("PAUSE");
			system("CLS");
			break;

		}

		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

	} while (repeat == true);

	return choice;

}