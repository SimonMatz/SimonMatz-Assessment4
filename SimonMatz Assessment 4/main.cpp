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

				if (winner == 1 || winner == 2 || winner == 5)
				{
					cout << "\nEnter 1 to play again or any other number to return to menu > ";
					cin >> playAgain;
					system("cls");
					//player = 'X';
				}

				fstream  writeFile;
				//append mode FROM: https://stackoverflow.com/questions/4155537/writing-into-a-text-file-without-overwriting-it
				writeFile.open("P1-P2-Wins.txt", fstream::app);
				writeFile << winner << " ";
				writeFile.close();	

			} while (playAgain == 1);
		}

		else if (choice == PLAY2)
		{
			system("cls");

			do
			{
				char numbers[9]{ '1', '2', '3', '4', '5', '6', '7', '8', '9' };

				winner = playTTT2(numbers);

				if (winner == 3 || winner == 4 || winner == 5)
				{
					cout << "\nEnter 1 to play again or any other number to return to menu > ";
					cin >> playAgain;
					system("cls");
				}
				
				fstream  writeFile;
				//append mode FROM: https://stackoverflow.com/questions/4155537/writing-into-a-text-file-without-overwriting-it
				writeFile.open("P1-P2-Wins.txt", fstream::app);
				writeFile << winner << " ";
				writeFile.close();

			} while (playAgain == 1);
		}

		else if (choice == SCORES)
		{
			int goBack = 0;

			system("cls");

			do
			{
				showScores();
				cout << "\n\n\n\nEnter any number to return to menu > ";
				cin >> goBack;

			} while (goBack == 0);
		}

	} while (choice != EXIT);

	return;
}