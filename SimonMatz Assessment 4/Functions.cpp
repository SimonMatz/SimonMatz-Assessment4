#include <iostream>
#include <Windows.h>
#include <conio.h>
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

int displayMenuScreen()
{
	bool validChoice = false;
	int choice = 0;
	string error = "";

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
	string pause;
	int a = 0;

	while (true)
	{
		cout << "\nEnter number 1-9 to place marker accordingly > ";
		cin >> a;

		if (a == 1)
		{

			if (numbers[0] == '1')
			{
				numbers[0] = player;
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

int checkWinner(char numbers[])
{
	//player 1 win check
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
	cout << "xxxxx Player vs Player xxxxx \t\t xxxxx Player vs Computer xxxxx\n\n" << endl;
	cout << "      Player1 wins: " << pvpP1wins << "\t\t\t\tPlayer wins: " << pvcP1wins << endl << endl;
	cout << "      Player2 wins: " << pvpP2wins << "\t\t\t\tComputer wins: " << pvcP2wins << endl << endl;


}

int playTTT(char numbers[])
{
	int drawCount = 0;
	while (winner != 1 || winner != 2)
	{
		drawCount++;
		string next;
		winner = 0;

		drawBoard(numbers);
		do
		{
			chrono::steady_clock::time_point begin = chrono::steady_clock::now();
			selection(numbers);
			chrono::steady_clock::time_point end = chrono::steady_clock::now();
			int time = chrono::duration_cast<chrono::seconds>(end - begin).count();

			if (time > 9999)
			{
				system("cls");
				cout << "Time violation! You automatically lost. Press y to continue" << endl;
				cin >> next;

				return 0;
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

int blockWin(char numbers[])
{
	int winningChance = -1;

	//top row
	if (numbers[0] == 'X' && numbers[1] == 'X' && numbers[2] != 'O')
	{
		winningChance = 2;
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

	return winningChance;
}

int winningMove(char numbers[])
{
	int playToWin = -1;

	//top row
	if (numbers[0] == 'O' && numbers[1] == 'O' && numbers[2] != 'X')
	{
		playToWin = 2;
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
		string next;
		winner = 0;

		drawBoard(numbers);
		do
		{
			chrono::steady_clock::time_point begin = chrono::steady_clock::now();
			selection(numbers);
			chrono::steady_clock::time_point end = chrono::steady_clock::now();
			int time = chrono::duration_cast<chrono::seconds>(end - begin).count();

			winner = checkWinner(numbers);

			if (time > 999)
			{
				system("cls");
				cout << "Time violation! You automatically lost. Press y to continue" << endl;
				cin >> next;

				return 0;
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
				cout << "\n\nPlayer 2 wins!!\n" << endl;
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
				cout << "\n\nPlayer 2 wins!!\n" << endl;
				winner = 4;
				return winner;
			}
		}
	}
	system("cls");

	return winner;
}

