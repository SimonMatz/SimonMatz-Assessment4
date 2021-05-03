#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <chrono>
#include <fstream>
#include "termcolor.h"
#include "Functions.h"
//#include "textpixels.h"

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

void playerChange()
{
	if (player == 'X')
		player = 'O';
	else
		player = 'X';

}

void selection(char numbers[])
{
	string pause;
	int a = 0;

	while (true)
	{	
		cout << "\nEnter number to play accordingly > ";
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
				cout << "\nERROR. Press y to continue\n\n";
				cin >> pause;
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
				cout << "\nERROR 2\n\n";
				cin >> pause;
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
				cout << "\nERROR. Press y to continue\n\n";
				cin >> pause;
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
				cout << "\nERROR. Press y to continue\n\n";
				cin >> pause;
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
				cout << "\nERROR. Press y to continue\n\n";
				cin >> pause;
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
				cout << "\nERROR. Press y to continue\n\n";
				cin >> pause;
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
				cout << "\nERROR. Press y to continue\n\n";
				cin >> pause;
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
				cout << "\nERROR. Press y to continue\n\n";
				cin >> pause;
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
				cout << "\nERROR. Press y to continue\n\n";
				cin >> pause;
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
				cout << "Player 1 wins!!\n" << endl;
				//cin >> next;
				return winner;
			}
			else if (winner == 2)
			{
				system("cls");
				cout << "Player 2 wins!!\n" << endl;
				//cin >> next;
				return winner;
			}
			else if (drawCount == 9)
			{
				system("cls");
				cout << "It's a draw!!\n" << endl;
				//cin >> next;
				return winner;
			}
			drawBoard(numbers);

		} while (tryAgain == true);

		playerChange();
		
	}
	system("cls");

	return winner;
}

int playTTT2(char numbers[])
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
				cout << "Player 1 wins!!\n" << endl;
				cin >> next;
				return winner;
			}
			else if (winner == 2)
			{
				system("cls");
				cout << "Player 2 wins!!\n" << endl;
				cin >> next;
				return winner;
			}
			else if (drawCount == 9)
			{
				system("cls");
				cout << "It's a draw!!\n" << endl;
				cin >> next;
				return winner;
			}
			drawBoard(numbers);

		} while (tryAgain == true);

		playerChange();

	}
	system("cls");

	return winner;
}

