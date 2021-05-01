#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include "termcolor.h"
#include "Functions.h"
#include "textpixels.h"

using namespace std;
using namespace termcolor;
using namespace textpixels;

char a = '1';
char b = '2';
char c = '3';
char d = '4';
char e = '5';
char f = '6';
char g = '7';
char h = '8';
char i = '9';

char player = 'x';
bool tryAgain = false;
int winner = 0;

enum MenuChoice
{
	PLAY = 1,
	EXIT,
	CREDITS,
	CHOICES_END     //will alsways be last valid choice +1
};

int displayMenuScreen()
{
	bool validChoice = false;
	int choice = 0;
	string error = "";

	while (!validChoice)
	{
		cout << on_red << "xxxxxxxxxx  Welcome to Tic Tac Toe  xxxxxxxxxx\n\n" << reset;

		cout << "\t\t" << cyan << "1" << white << ": Play\n";
		cout << "\t\t" << cyan << "2" << white << ": Exit\n";
		cout << "\t\t" << cyan << "3" << white << ": Credits\n";

		if (!error.empty())     // If player entered wrong choice, error string won't be empty
		{
			cout << error << endl;
		}
		cout << "\n\t\tEnter 1, 2 or 3  " << cyan << "> " << white;
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

void clearSelections()
{
	char a = '1';
	char b = '2';
	char c = '3';
	char d = '4';
	char e = '5';
	char f = '6';
	char g = '7';
	char h = '8';
	char i = '9';

}

void drawBoard()
{
	system("cls");

	cout << "| " << a << " | " << b << " | " << c << " | " << endl;
	cout << "|---|---|---|" << endl;
	cout << "| " << d << " | " << e << " | " << f << " | " << endl;
	cout << "|---|---|---|" << endl;
	cout << "| " << g << " | " << h << " | " << i << " | " << endl;
}

void checkError()
{
	if (a == 'x' || a == 'o')
	{
		cout << "\n\n\nERROR\n\n";
		tryAgain = true;
		return;
	}
}

void playerChange()
{
	if (player == 'x')
		player = 'o';
	else
		player = 'x';

}

void selection()
{
	while (true)
	{

		if (keyIsDown('1'))
		{
			//system("cls");

			if (a == 'x' || a == 'o')
			{
				cout << "\n\n\nERROR\n\n";
				system("sleep");
				tryAgain = true;
			}
			else
			{
				a = player;
				tryAgain = false;
			}
			return;
		}

		if (keyIsDown('2'))
		{
			system("cls");

			if (b == 'x' || b == 'o')
			{
				cout << "\n\n\nERROR\n\n";
				tryAgain = true;
			}
			else
			{
				b = player;
				tryAgain = false;
			}
			return;
		}
		if (keyIsDown('3'))
		{
			system("cls");

			if (c == 'x' || c == 'o')
			{
				cout << "\n\n\nERROR\n\n";
				tryAgain = true;
			}
			else
			{
				c = player;
				tryAgain = false;
			}
			return;
		}

		if (keyIsDown('4'))
		{
			system("cls");
			if (d == 'x' || d == 'o')
			{
				cout << "\n\n\nERROR\n\n";
				tryAgain = true;
			}
			else
			{
				d = player;
				tryAgain = false;
			}
			return;
		}
		if (keyIsDown('5'))
		{
			system("cls");
			if (e == 'x' || e == 'o')
			{
				cout << "\n\n\nERROR\n\n";
				tryAgain = true;
			}
			else
			{
				e = player;
				tryAgain = false;
			}
			return;

		}

		if (keyIsDown('6'))
		{
			system("cls");
			if (f == 'x' || f == 'o')
			{
				cout << "\n\n\nERROR\n\n";
				tryAgain = true;
			}
			else
			{
				f = player;
				tryAgain = false;
			}
			return;
		}
		if (keyIsDown('7'))
		{
			system("cls");
			if (g == 'x' || g == 'o')
			{
				cout << "\n\n\nERROR\n\n";
				tryAgain = true;
			}
			else
			{
				g = player;
				tryAgain = false;
			}

			return;
		}

		if (keyIsDown('8'))
		{
			system("cls");
			if (h == 'x' || h == 'o')
			{
				cout << "\n\n\nERROR\n\n";
				tryAgain = true;
			}
			else
			{
				h = player;
				tryAgain = false;
			}

			return;
		}
		if (keyIsDown('9'))
		{
			system("cls");
			if (i == 'x' || i == 'o')
			{
				cout << "\n\n\nERROR\n\n";
				tryAgain = true;
			}
			else
			{
				i = player;
				tryAgain = false;
			}

			return;
		}
	}
}

void checkWinner()
{
	//player 1 win check
	if (a == 'x' && b == 'x' && c == 'x')
	{
		winner = 1;
		return;
	}
	if (d == 'x' && e == 'x' && f == 'x')
	{
		winner = 1;
		return;
	}
	if (g == 'x' && h == 'x' && i == 'x')
	{
		winner = 1;
		return;
	}
	if (a == 'x' && d == 'x' && g == 'x')
	{
		winner = 1;
		return;
	}
	if (b == 'x' && e == 'x' && h == 'x')
	{
		winner = 1;
		return;
	}
	if (c == 'x' && f == 'x' && i == 'x')
	{
		winner = 1;
		return;
	}
	if (a == 'x' && e == 'x' && i == 'x')
	{
		winner = 1;
		return;
	}
	if (c == 'x' && e == 'x' && g == 'x')
	{
		winner = 1;
		return;
	}

	//player 2 win check
	if (a == 'o' && b == 'o' && c == 'o')
	{
		winner = 2;
		return;
	}
	if (d == 'o' && e == 'o' && f == 'o')
	{
		winner = 2;
		return;
	}
	if (g == 'o' && h == 'o' && i == 'o')
	{
		winner = 2;
		return;
	}
	if (a == 'o' && d == 'o' && g == 'o')
	{
		winner = 2;
		return;
	}
	if (b == 'o' && e == 'o' && h == 'o')
	{
		winner = 2;
		return;
	}
	if (c == 'o' && f == 'o' && i == 'o')
	{
		winner = 2;
		return;
	}
	if (a == 'o' && e == 'o' && i == 'o')
	{
		winner = 2;
		return;
	}
	if (c == 'o' && e == 'o' && g == 'o')
	{
		winner = 2;
		return;
	}

	return;
}



void playTTT()
{
	while (winner != 1 || winner != 2)
	{

		drawBoard();
		do
		{

			selection();
			checkWinner();

			if (winner == 1)
			{
				system("cls");
				cout << "Player 1 wins!!\n" << endl;
				return;

			}
			else if (winner == 2)
			{
				system("cls");
				cout << "Player 2 wins!!\n" << endl;
				return;

			}
			drawBoard();


		} while (tryAgain == true);

		playerChange();
	}
	system("cls");

}

void main()
{
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
				playTTT();

				if (winner == 1 || winner == 2)
				{
					winner = 0;
					clearSelections();
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