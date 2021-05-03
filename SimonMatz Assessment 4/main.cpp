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

	int winner = 0;
	int choice = 0;
	int playAgain = 0;

	do
	{
		system("cls");
		choice = displayMenuScreen();

		if (choice == PLAY)
		{
			system("cls");

			do
			{
				char numbers[9]{ '1', '2', '3', '4', '5', '6', '7', '8', '9' };
				winner = playTTT(numbers);

				if (winner == 1 || winner == 2)
				{
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