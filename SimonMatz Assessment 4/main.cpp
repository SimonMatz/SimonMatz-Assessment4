#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <chrono>
#include <fstream>
#include "Functions.h"

using namespace std;

enum MenuChoice
{
	PLAY = 1,
	EXIT,
	CREDITS,
	CHOICES_END     //will alsways be last valid choice +1
};

void main()
{
	
	int choice = 0;
	int playAgain = 0;
	int winner = 0;

	do
	{
		system("cls");
		choice = displayMenuScreen();

		if (choice == PLAY)
		{
			system("cls");

			do
			{
				winner = playTTT(winner);

				if (winner == 1 || winner == 2)
				{
					
					winner = 0;
					cout << "Enter 1 to play again or any other number to return to menu > ";
					cin >> playAgain;
					system("cls");
				}

			} while (playAgain == 1);
		}

	} while (choice != EXIT);

	system("cls");
	displayMenuScreen();

}