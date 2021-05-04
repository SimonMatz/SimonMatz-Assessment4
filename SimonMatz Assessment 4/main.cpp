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
	PLAY2,
	SCORES,
	EXIT,
	CHOICES_END //will alsways be last valid choice +1
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

				fstream  writeFile;
				//append mode FROM: https://stackoverflow.com/questions/4155537/writing-into-a-text-file-without-overwriting-it
				writeFile.open("PlayerVsPlayerScores.txt", fstream::app);
				writeFile << winner << endl;
				writeFile.close();

				if (winner == 1 || winner == 2)
				{
					cout << "Enter 1 to play again or any other number to return to menu > ";
					cin >> playAgain;
					system("cls");
				}

			} while (playAgain == 1);
		}

		else if (choice == PLAY2)
		{
			system("cls");

			do
			{
				char numbers[9]{ '1', '2', '3', '4', '5', '6', '7', '8', '9' };
				winner = playTTT2(numbers);

				fstream  writeFile;
				//append mode FROM: https://stackoverflow.com/questions/4155537/writing-into-a-text-file-without-overwriting-it
				writeFile.open("PlayerVsCpuScores.txt", fstream::app);
				writeFile << winner << endl;
				writeFile.close();

				if (winner == 1 || winner == 2)
				{
					cout << "Enter 1 to play again or any other number to return to menu > ";
					cin >> playAgain;
					system("cls");
				}

			} while (playAgain == 1);
		}

		else if (choice == SCORES)
		{
			system("cls");

			do
			{
				cout << "Scores coming soon...\n\n" << endl;

				
					cout << "Enter 2 to return to menu > ";
					cin >> playAgain;
					system("cls");
				

			} while (playAgain == 1);
		}

	} while (choice != EXIT);

	return;
}