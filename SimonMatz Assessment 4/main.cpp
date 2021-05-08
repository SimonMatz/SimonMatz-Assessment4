//Simon Matz A00018077 Assessment 4
//Github respository link: https://github.com/SimonMatz/SimonMatz-Assessment4

#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include "Functions.h"

using namespace std;

//creating variables for menu option
enum MenuChoice
{
	PLAY = 1,
	PLAY2,
	SCORES,
	EXIT,
	CHOICES_END //will always be last valid choice +1
};

void main()
{
	int winner = 0;
	int choice = 0;
	int playAgain = 0;

	//main game loop while player hasn't quit
	do
	{
		system("cls");
		choice = displayMenuScreen();

		//player selects menu option 1 - goes into PvP game mode
		if (choice == PLAY)
		{
			system("cls");

			//loops if player decides to play again
			do
			{
				char numbers[9]{ '1', '2', '3', '4', '5', '6', '7', '8', '9' };

				//returns the winner for score keeping
				winner = playTTT(numbers);

				//option to play again after P1 win, P2 win or draw
				if (winner == 1 || winner == 2 || winner == 5)
				{
					cout << "\nEnter 1 to play again or any other number to return to menu > ";
					cin >> playAgain;
					system("cls");
				}

				//writes winner into file to keep scores
				fstream  writeFile;
				//append mode FROM: https://stackoverflow.com/questions/4155537/writing-into-a-text-file-without-overwriting-it
				writeFile.open("P1-P2-Wins.txt", fstream::app);
				writeFile << winner << " ";
				writeFile.close();	
				
			} while (playAgain == 1);
		}

		//player selects menu option 2 - goes into PvC game mode
		else if (choice == PLAY2)
		{
			system("cls");

			//loops if player decides to play again
			do
			{
				char numbers[9]{ '1', '2', '3', '4', '5', '6', '7', '8', '9' };

				//returns the winner for score keeping
				winner = playTTT2(numbers);

				//option to play again after P1 win(3), P2 win(4) or draw(5)
				if (winner == 3 || winner == 4 || winner == 5)
				{
					cout << "\nEnter 1 to play again or any other number to return to menu > ";
					cin >> playAgain;
					system("cls");
				}
				
				//writes winner into file to keep scores
				fstream  writeFile;
				//append mode FROM: https://stackoverflow.com/questions/4155537/writing-into-a-text-file-without-overwriting-it
				writeFile.open("P1-P2-Wins.txt", fstream::app);
				writeFile << winner << " ";
				writeFile.close();

			} while (playAgain == 1);
		}

		//enters score screen until player enters number to go back to home screen
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

	} while (choice != EXIT); //application quits when user decides to exit

	return;
}