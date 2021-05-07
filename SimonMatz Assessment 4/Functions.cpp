//Simon Matz A00018077 Assessment 4
//Github respository link: https://github.com/SimonMatz/SimonMatz-Assessment4

#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>
#include <chrono>
#include <vector>
#include <fstream>
#include "termcolor.h"
#include "Functions.h"

using namespace std;
using namespace termcolor;

enum MenuChoice
{
	PLAY = 1,
	PLAY2,
	SCORES,
	EXIT,
	CHOICES_END     //will always be last valid choice +1
};

//was able to use the same menu screen setup I made for ISE102 Poker Machine game
int displayMenuScreen()
{
	bool validChoice = false;
	int choice = 0;
	string error = "";

	//main menu with 4 options, tells user if wrong input and ask to try again
	while (!validChoice)
	{
		cout << on_red << "xxxxxxxxxx  Welcome to Tic Tac Toe  xxxxxxxxxx\n\n" << reset;

		cout << "\t\t" << cyan << "1" << white << ": Player vs Player\n";
		cout << "\t\t" << cyan << "2" << white << ": Player vs CPU\n";
		cout << "\t\t" << cyan << "3" << white << ": Scores\n";
		cout << "\t\t" << cyan << "4" << white << ": Exit\n";

		if (!error.empty())     // If player entered wrong choice, error string won't be empty
		{
			cout << error << endl;
		}
		cout << "\n\t\tEnter 1, 2, 3 or 4  " << cyan << "> " << white;
		cin >> choice;

		if (choice > 0 && choice < MenuChoice::CHOICES_END)
		{
			validChoice = true;
		}
		else
		{
			error = "\n\tMate! " + to_string(choice) + " is not an option. TRY AGAIN.";
			system("cls");  //clear screen before showing menu again
		}
	}
	return choice;
}

void drawBoard(char numbers[])
{
	system("cls");

	cout << "|-------|-------|-------|" << endl;
	cout << "|       |       |       |" << endl;
	cout << "|   " << numbers[0] << "   |   " << numbers[1] << "   |   " << numbers[2] << "   |   " << endl;
	cout << "|       |       |       |" << endl;
	cout << "|-------|-------|-------|" << endl;
	cout << "|       |       |       |" << endl;
	cout << "|   " << numbers[3] << "   |   " << numbers[4] << "   |   " << numbers[5] << "   |   " << endl;
	cout << "|       |       |       |" << endl;
	cout << "|-------|-------|-------|" << endl;
	cout << "|       |       |       |" << endl;
	cout << "|   " << numbers[6] << "   |   " << numbers[7] << "   |   " << numbers[8] << "   |   " << endl;
	cout << "|       |       |       |" << endl;
	cout << "|-------|-------|-------|" << endl;
}

char playerChange()
{
	if (player == 'X')
		player = 'O';
	else
		player = 'X';

	return player;
}

void selection(char numbers[])
{
	//variable to store user input
	int a = 0;

	//takes user input and stores player symbol in numbers array.
	while (true)
	{
		if (player == 'X')
		{
			cout << "\nPlayer 1 - it's your turn!\n\nEnter number 1-9 to place marker accordingly > ";
			cin >> a;
		}
		else if (player == 'O')
		{
			cout << "\nPlayer 2 - it's your turn!\n\nEnter number 1-9 to place marker accordingly > ";
			cin >> a;
		}

		if (a == 1)
		{

			if (numbers[0] == '1')
			{
				numbers[0] = player;
				tryAgain = false;
			}

			//checks if field is already taken and sets tryAgain to true so player can choose another field
			else
			{
				cout << "\nThis field is already taken. Try again!\n\n";
				Sleep(2500);
				tryAgain = true;
			}
			return;
		}

		else if (a == 2)
		{
			if (numbers[1] == '2')
			{
				numbers[1] = player;
				tryAgain = false;
			}

			else
			{
				cout << "\nThis field is already taken. Try again!\n\n";
				Sleep(2500);
				tryAgain = true;
			}
			return;
		}
		else if (a == 3)
		{
			if (numbers[2] == '3')
			{
				numbers[2] = player;
				tryAgain = false;
			}

			else
			{
				cout << "\nThis field is already taken. Try again!\n\n";
				Sleep(2500);
				tryAgain = true;
			}
			return;
		}

		else if (a == 4)
		{
			if (numbers[3] == '4')
			{
				numbers[3] = player;
				tryAgain = false;
			}

			else
			{
				cout << "\nThis field is already taken. Try again!\n\n";
				Sleep(2500);
				tryAgain = true;
			}
			return;
		}
		else if (a == 5)
		{
			if (numbers[4] == '5')
			{
				numbers[4] = player;
				tryAgain = false;
			}

			else
			{
				cout << "\nThis field is already taken. Try again!\n\n";
				Sleep(2500);
				tryAgain = true;
			}
			return;

		}

		else if (a == 6)
		{
			if (numbers[5] == '6')
			{
				numbers[5] = player;
				tryAgain = false;
			}

			else
			{
				cout << "\nThis field is already taken. Try again!\n\n";
				Sleep(2500);
				tryAgain = true;
			}
			return;
		}
		else if (a == 7)
		{
			if (numbers[6] == '7')
			{
				numbers[6] = player;
				tryAgain = false;
			}

			else
			{
				cout << "\nThis field is already taken. Try again!\n\n";
				Sleep(2500);
				tryAgain = true;
			}
			return;
		}

		else if (a == 8)
		{
			if (numbers[7] == '8')
			{
				numbers[7] = player;
				tryAgain = false;
			}

			else
			{
				cout << "\nThis field is already taken. Try again!\n\n";
				Sleep(2500);
				tryAgain = true;
			}

			return;
		}
		else if (a == 9)
		{
			if (numbers[8] == '9')
			{
				numbers[8] = player;
				tryAgain = false;
			}

			else
			{
				cout << "\nThis field is already taken. Try again!\n\n";
				Sleep(2500);
				tryAgain = true;
			}

			return;
		}
	}
}

//8 possible win combinations per player
int checkWinner(char numbers[])
{
	//player 1 win check
	//goes through all combinations of board placements and returns winner value 1
	if (numbers[0] == 'X' && numbers[1] == 'X' && numbers[2] == 'X')
	{
		winner = 1;
		return winner;
	}
	if (numbers[3] == 'X' && numbers[4] == 'X' && numbers[5] == 'X')
	{
		winner = 1;
		return winner;
	}
	if (numbers[6] == 'X' && numbers[7] == 'X' && numbers[8] == 'X')
	{
		winner = 1;
		return winner;
	}
	if (numbers[0] == 'X' && numbers[3] == 'X' && numbers[6] == 'X')
	{
		winner = 1;
		return winner;
	}
	if (numbers[1] == 'X' && numbers[4] == 'X' && numbers[7] == 'X')
	{
		winner = 1;
		return winner;
	}
	if (numbers[2] == 'X' && numbers[5] == 'X' && numbers[8] == 'X')
	{
		winner = 1;
		return winner;
	}
	if (numbers[0] == 'X' && numbers[4] == 'X' && numbers[8] == 'X')
	{
		winner = 1;
		return winner;
	}
	if (numbers[2] == 'X' && numbers[4] == 'X' && numbers[6] == 'X')
	{
		winner = 1;
		return winner;
	}

	//player 2 win check
	//goes through all combinations of board placements and returns winner value 2
	if (numbers[0] == 'O' && numbers[1] == 'O' && numbers[2] == 'O')
	{
		winner = 2;
		return winner;
	}
	if (numbers[3] == 'O' && numbers[4] == 'O' && numbers[5] == 'O')
	{
		winner = 2;
		return winner;
	}
	if (numbers[6] == 'O' && numbers[7] == 'O' && numbers[8] == 'O')
	{
		winner = 2;
		return winner;
	}
	if (numbers[0] == 'O' && numbers[3] == 'O' && numbers[6] == 'O')
	{
		winner = 2;
		return winner;
	}
	if (numbers[1] == 'O' && numbers[4] == 'O' && numbers[7] == 'O')
	{
		winner = 2;
		return winner;
	}
	if (numbers[2] == 'O' && numbers[5] == 'O' && numbers[8] == 'O')
	{
		winner = 2;
		return winner;
	}
	if (numbers[0] == 'O' && numbers[4] == 'O' && numbers[8] == 'O')
	{
		winner = 2;
		return winner;
	}
	if (numbers[2] == 'O' && numbers[4] == 'O' && numbers[6] == 'O')
	{
		winner = 2;
		return winner;
	}

	return winner;
}

// Used https://www.youtube.com/watch?v=1Vdb1DcXtFk as guide for counting different numbers
void showScores()
{
	int wins = 0;
	const int pvp1 = 1;
	const int pvp2 = 2;
	const int pvc1 = 3;
	const int pvc2 = 4;

	int pvpP1wins = 0;
	int pvpP2wins = 0;
	int pvcP1wins = 0;
	int pvcP2wins = 0;

	vector <int> winsVector;

	ifstream readFile;

	readFile.open("P1-P2-Wins.txt");

	while (readFile >> wins)
	{
		winsVector.push_back(wins);
	}

	while (readFile.is_open())
	{

		for (int i = 0; i < winsVector.size(); i++)
		{
			if (pvp1 == winsVector[i])
				pvpP1wins++;

			if (pvp2 == winsVector[i])
				pvpP2wins++;

			if (pvc1 == winsVector[i])
				pvcP1wins++;

			if (pvc2 == winsVector[i])
				pvcP2wins++;
		}
		readFile.close();
	}
	cout << on_green << "xxxxx Player vs Player xxxxx" << reset << "\t\t" << on_cyan << "xxxxx Player vs Computer xxxxx\n\n" << reset << endl;
	cout << "      Player1 wins: " << pvpP1wins << "\t\t\t\tPlayer wins: " << pvcP1wins << endl << endl;
	cout << "      Player2 wins: " << pvpP2wins << "\t\t\t\tComputer wins: " << pvcP2wins << endl << endl;


}

int playTTT(char numbers[])
{
	int drawCount = 0;
	while (winner != 1 || winner != 2)
	{
		drawCount++;
		winner = 0;

		drawBoard(numbers);
		do
		{
			chrono::steady_clock::time_point begin = chrono::steady_clock::now();
			selection(numbers);
			chrono::steady_clock::time_point end = chrono::steady_clock::now();
			int time = chrono::duration_cast<chrono::seconds>(end - begin).count();

			if (time > 10 && player == 'X')
			{
				system("cls");
				cout << "Time violation! Player 1 lost."<< endl;
				Sleep(2000);
				
				winner = 2;
				return winner;
			}
			else if (time > 10 && player == 'O')
			{
				system("cls");
				cout << "Time violation! Player 2 lost." << endl;
				Sleep(2000);

				winner = 1;
				return winner;
			}

			winner = checkWinner(numbers);

			if (winner == 1)
			{
				system("cls");
				drawBoard(numbers);
				cout << "\n\nPlayer 1 wins!!\n" << endl;
				return winner;
			}
			else if (winner == 2)
			{
				system("cls");
				drawBoard(numbers);
				cout << "\n\nPlayer 2 wins!!\n" << endl;
				return winner;
			}
			else if (drawCount == 9)
			{
				system("cls");
				drawBoard(numbers);
				cout << "\n\nIt's a draw!!\n" << endl;
				winner = 5;
				return winner;
			}
			drawBoard(numbers);

		} while (tryAgain == true);

		playerChange();

	}
	system("cls");

	return winner;
}

//uses the same logic as check for win and goes through all possible constelations
int blockWin(char numbers[])
{
	//variable for where the actual marker will be placed when drawing the board
	int winningChance = -1;
	
	//checks if there are two X next to each other to block possible win
	//also checks that it hasn't been blocked before


	//top row
	if (numbers[0] == 'X' && numbers[1] == 'X' && numbers[2] != 'O')
	{
		//value for winningChance will be relevant array location 
		winningChance = 2;
		//returns the marker location for the cpuSelection function
		return winningChance;
	}
	if (numbers[1] == 'X' && numbers[2] == 'X' && numbers[0] != 'O')
	{
		winningChance = 0;
		return winningChance;
	}
	if (numbers[0] == 'X' && numbers[2] == 'X' && numbers[1] != 'O')
	{
		winningChance = 1;
		return winningChance;
	}

	//middle row
	if (numbers[3] == 'X' && numbers[4] == 'X' && numbers[5] != 'O')
	{
		winningChance = 5;
		return winningChance;
	}
	if (numbers[4] == 'X' && numbers[5] == 'X' && numbers[3] != 'O')
	{
		winningChance = 3;
		return winningChance;
	}
	if (numbers[3] == 'X' && numbers[5] == 'X' && numbers[4] != 'O')
	{
		winningChance = 4;
		return winningChance;
	}
	//bottom row
	if (numbers[6] == 'X' && numbers[7] == 'X' && numbers[8] != 'O')
	{
		winningChance = 8;
		return winningChance;
	}
	if (numbers[7] == 'X' && numbers[8] == 'X' && numbers[6] != 'O')
	{
		winningChance = 6;
		return winningChance;
	}
	if (numbers[6] == 'X' && numbers[8] == 'X' && numbers[7] != 'O')
	{
		winningChance = 7;
		return winningChance;
	}

	//left row
	if (numbers[0] == 'X' && numbers[3] == 'X' && numbers[6] != 'O')
	{
		winningChance = 6;
		return winningChance;
	}
	if (numbers[3] == 'X' && numbers[6] == 'X' && numbers[0] != 'O')
	{
		winningChance = 0;
		return winningChance;
	}
	if (numbers[0] == 'X' && numbers[6] == 'X' && numbers[3] != 'O')
	{
		winningChance = 3;
		return winningChance;
	}

	//middle down
	if (numbers[1] == 'X' && numbers[4] == 'X' && numbers[7] != 'O')
	{
		winningChance = 7;
		return winningChance;
	}
	if (numbers[4] == 'X' && numbers[7] == 'X' && numbers[1] != 'O')
	{
		winningChance = 1;
		return winningChance;
	}
	if (numbers[1] == 'X' && numbers[7] == 'X' && numbers[4] != 'O')
	{
		winningChance = 4;
		return winningChance;
	}

	//right row
	if (numbers[2] == 'X' && numbers[5] == 'X' && numbers[8] != 'O')
	{
		winningChance = 8;
		return winningChance;
	}
	if (numbers[5] == 'X' && numbers[8] == 'X' && numbers[2] != 'O')
	{
		winningChance = 2;
		return winningChance;
	}
	if (numbers[2] == 'X' && numbers[8] == 'X' && numbers[5] != 'O')
	{
		winningChance = 5;
		return winningChance;
	}

	//diagonal 1
	if (numbers[0] == 'X' && numbers[4] == 'X' && numbers[8] != 'O')
	{
		winningChance = 8;
		return winningChance;
	}
	if (numbers[4] == 'X' && numbers[8] == 'X' && numbers[0] != 'O')
	{
		winningChance = 0;
		return winningChance;
	}
	if (numbers[0] == 'X' && numbers[8] == 'X' && numbers[4] != 'O')
	{
		winningChance = 4;
		return winningChance;
	}

	//diagonal 2
	if (numbers[2] == 'X' && numbers[4] == 'X' && numbers[6] != 'O')
	{
		winningChance = 6;
		return winningChance;
	}
	if (numbers[4] == 'X' && numbers[6] == 'X' && numbers[2] != 'O')
	{
		winningChance = 2;
		return winningChance;
	}
	if (numbers[2] == 'X' && numbers[6] == 'X' && numbers[4] != 'O')
	{
		winningChance = 4;
		return winningChance;
	}

	//returns -1 if none of above conditions are true
	return winningChance;
}

//same concept as blockWin just instead checks if there are two O next to each other to win
int winningMove(char numbers[])
{
	//variable for where the actual marker will be placed when drawing the board
	int playToWin = -1;

	//top row
	if (numbers[0] == 'O' && numbers[1] == 'O' && numbers[2] != 'X')
	{
		//value for playToWin will be relevant array location 
		playToWin = 2;
		//returns the marker location for the cpuSelection function
		return playToWin;
	}
	if (numbers[1] == 'O' && numbers[2] == 'O' && numbers[0] != 'X')
	{
		playToWin = 0;
		return playToWin;
	}
	if (numbers[0] == 'O' && numbers[2] == 'O' && numbers[1] != 'X')
	{
		playToWin = 1;
		return playToWin;
	}

	//middle row
	if (numbers[3] == 'O' && numbers[4] == 'O' && numbers[5] != 'X')
	{
		playToWin = 5;
		return playToWin;
	}
	if (numbers[4] == 'O' && numbers[5] == 'O' && numbers[3] != 'X')
	{
		playToWin = 3;
		return playToWin;
	}
	if (numbers[3] == 'O' && numbers[5] == 'O' && numbers[4] != 'X')
	{
		playToWin = 4;
		return playToWin;
	}
	//bottom row
	if (numbers[6] == 'O' && numbers[7] == 'O' && numbers[8] != 'X')
	{
		playToWin = 8;
		return playToWin;
	}
	if (numbers[7] == 'O' && numbers[8] == 'O' && numbers[6] != 'X')
	{
		playToWin = 6;
		return playToWin;
	}
	if (numbers[6] == 'O' && numbers[8] == 'O' && numbers[7] != 'X')
	{
		playToWin = 7;
		return playToWin;
	}

	//left row
	if (numbers[0] == 'O' && numbers[3] == 'O' && numbers[6] != 'X')
	{
		playToWin = 6;
		return playToWin;
	}
	if (numbers[3] == 'O' && numbers[6] == 'O' && numbers[0] != 'X')
	{
		playToWin = 0;
		return playToWin;
	}
	if (numbers[0] == 'O' && numbers[6] == 'O' && numbers[3] != 'X')
	{
		playToWin = 3;
		return playToWin;
	}

	//middle down
	if (numbers[1] == 'O' && numbers[4] == 'O' && numbers[7] != 'X')
	{
		playToWin = 7;
		return playToWin;
	}
	if (numbers[4] == 'O' && numbers[7] == 'O' && numbers[1] != 'X')
	{
		playToWin = 1;
		return playToWin;
	}
	if (numbers[1] == 'O' && numbers[7] == 'O' && numbers[4] != 'X')
	{
		playToWin = 4;
		return playToWin;
	}

	//right row
	if (numbers[2] == 'O' && numbers[5] == 'O' && numbers[8] != 'X')
	{
		playToWin = 8;
		return playToWin;
	}
	if (numbers[5] == 'O' && numbers[8] == 'O' && numbers[2] != 'X')
	{
		playToWin = 2;
		return playToWin;
	}
	if (numbers[2] == 'O' && numbers[8] == 'O' && numbers[5] != 'X')
	{
		playToWin = 5;
		return playToWin;
	}

	//diagonal 1
	if (numbers[0] == 'O' && numbers[4] == 'O' && numbers[8] != 'X')
	{
		playToWin = 8;
		return playToWin;
	}
	if (numbers[4] == 'O' && numbers[8] == 'O' && numbers[0] != 'X')
	{
		playToWin = 0;
		return playToWin;
	}
	if (numbers[0] == 'O' && numbers[8] == 'O' && numbers[4] != 'X')
	{
		playToWin = 4;
		return playToWin;
	}

	//diagonal 2
	if (numbers[2] == 'O' && numbers[4] == 'O' && numbers[6] != 'X')
	{
		playToWin = 6;
		return playToWin;
	}
	if (numbers[4] == 'O' && numbers[6] == 'O' && numbers[0] != 'X')
	{
		playToWin = 0;
		return playToWin;
	}
	if (numbers[2] == 'O' && numbers[6] == 'O' && numbers[4] != 'X')
	{
		playToWin = 4;
		return playToWin;
	}

	//returns -1 if none of above conditions are true
	return playToWin;
}

void cpuSelection(char numbers[])
{
	do
	{
		int playToWin = winningMove(numbers);
		int winningChance = blockWin(numbers);

		if (playToWin != -1)
		{
			numbers[playToWin] = player;
			tryAgain = false;
			playToWin = -1;
		}

		else if (winningChance != -1)
		{
			numbers[winningChance] = player;
			tryAgain = false;
			winningChance = -1;
		}

		else
		{
			srand(time(0));
			int a = (rand() % 9) + 1;

			if (a == 1)
			{
				if (numbers[0] == '1')
				{
					numbers[0] = player;
					tryAgain = false;
				}
				else
					tryAgain = true;
			}

			else if (a == 2)
			{
				if (numbers[1] == '2')
				{
					numbers[1] = player;
					tryAgain = false;
				}
				else
					tryAgain = true;
			}

			else if (a == 3)
			{
				if (numbers[2] == '3')
				{
					numbers[2] = player;
					tryAgain = false;
				}
				else
					tryAgain = true;
			}

			else if (a == 4)
			{
				if (numbers[3] == '4')
				{
					numbers[3] = player;
					tryAgain = false;
				}
				else
					tryAgain = true;
			}

			else if (a == 5)
			{
				if (numbers[4] == '5')
				{
					numbers[4] = player;
					tryAgain = false;
				}
				else
					tryAgain = true;
			}

			else if (a == 6)
			{
				if (numbers[5] == '6')
				{
					numbers[5] = player;
					tryAgain = false;
				}
				else
					tryAgain = true;
			}

			else if (a == 7)
			{
				if (numbers[6] == '7')
				{
					numbers[6] = player;
					tryAgain = false;
				}
				else
					tryAgain = true;
			}

			else if (a == 8)
			{
				if (numbers[7] == '8')
				{
					numbers[7] = player;
					tryAgain = false;
				}
				else
					tryAgain = true;
			}

			else if (a == 9)
			{
				if (numbers[8] == '9')
				{
					numbers[8] = player;
					tryAgain = false;
				}
				else
					tryAgain = true;
			}
		}
	} while (tryAgain == true);
}

int playTTT2(char numbers[])
{
	int drawCount = 0;
	char cpuPlayer;

	while (winner != 1 || winner != 2)
	{
		drawCount++;
		winner = 0;

		drawBoard(numbers);
		do
		{
			chrono::steady_clock::time_point begin = chrono::steady_clock::now();
			selection(numbers);
			chrono::steady_clock::time_point end = chrono::steady_clock::now();
			int time = chrono::duration_cast<chrono::seconds>(end - begin).count();

			winner = checkWinner(numbers);

			if (time > 10 && player == 'X')
			{
				system("cls");
				cout << "Time violation! Player 1 lost." << endl;
				Sleep(2000);

				winner = 4;
				return winner;
			}

			if (winner == 1)
			{
				system("cls");
				drawBoard(numbers);
				cout << "\n\nPlayer 1 wins!!\n" << endl;
				winner = 3;
				return winner;
			}
			else if (winner == 2)
			{
				system("cls");
				drawBoard(numbers);
				cout << "\n\nComputer wins!!\n" << endl;
				winner = 4;
				return winner;
			}
			else if (drawCount == 5)
			{
				system("cls");
				drawBoard(numbers);
				cout << "\n\nIt's a draw!!\n" << endl;
				winner = 5;
				return winner;
			}

			drawBoard(numbers);

		} while (tryAgain == true);

		cpuPlayer = playerChange();

		if (cpuPlayer == 'O')
		{
			cpuSelection(numbers);
			playerChange();
			winner = checkWinner(numbers);

			if (winner == 1)
			{
				system("cls");
				drawBoard(numbers);
				cout << "\n\nPlayer 1 wins!!\n" << endl;
				winner = 3;
				return winner;
			}
			else if (winner == 2)
			{
				system("cls");
				drawBoard(numbers);
				cout << "\n\nComputer wins!!\n" << endl;
				winner = 4;
				return winner;
			}
		}
	}
	system("cls");

	return winner;
}

