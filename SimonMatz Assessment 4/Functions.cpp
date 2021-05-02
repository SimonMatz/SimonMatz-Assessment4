#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <chrono>
#include <fstream>
#include "termcolor.h"
#include "Functions.h"
#include "textpixels.h"

using namespace std;
using namespace termcolor;
using namespace textpixels;

string a = "1";
char b = '2';
char c = '3';
char d = '4';
char e = '5';
char f = '6';
char g = '7';
char h = '8';
char i = '9';



enum MenuChoice
{
	PLAY = 1,
	EXIT,
	CREDITS,
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
	string a = "1";
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

void playerChange()
{
	if (player == 'x')
		player = 'o';
	else
		player = 'x';

}

void selection()
{
	string pause;

	while (true)
	{
		if (keyIsDown('1'))
		{

			if (a == "x" || a == "o")
			{
			cout << "\n\n\nERROR\n\n";
			cin >> pause;
			tryAgain = true;
			}

			else
			{
				a = player;
				tryAgain = false;	
			}
			
			return;
		}

		else if (keyIsDown('2'))
		{
			
			if (b == 'x' || b == 'o')
			{
				cout << "\n\n\nERROR\n\n";
				cin >> pause;
				tryAgain = true;
			}

			else
			{
				b = player;
				tryAgain = false;
			}
			return;
		}
		else if (keyIsDown('3'))
		{
			

			if (c == 'x' || c == 'o')
			{
				
				tryAgain = true;
			}
			else
			{
				c = player;
				tryAgain = false;
			}
			return;
		}

		else if (keyIsDown('4'))
		{
			
			if (d == 'x' || d == 'o')
			{
				
				tryAgain = true;
			}
			else
			{
				d = player;
				tryAgain = false;
			}
			return;
		}
		else if (keyIsDown('5'))
		{
			
			if (e == 'x' || e == 'o')
			{
				
				tryAgain = true;
			}
			else
			{
				e = player;
				tryAgain = false;
			}
			return;

		}

		else if (keyIsDown('6'))
		{
			
			if (f == 'x' || f == 'o')
			{
				
				tryAgain = true;
			}
			else
			{
				f = player;
				tryAgain = false;
			}
			return;
		}
		else if (keyIsDown('7'))
		{
			
			if (g == 'x' || g == 'o')
			{
				
				tryAgain = true;
			}
			else
			{
				g = player;
				tryAgain = false;
			}

			return;
		}

		else if (keyIsDown('8'))
		{
			
			if (h == 'x' || h == 'o')
			{
				
				tryAgain = true;
			}
			else
			{
				h = player;
				tryAgain = false;
			}

			return;
		}
		else if (keyIsDown('9'))
		{
			
			if (i == 'x' || i == 'o')
			{
				
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

int checkWinner()
{
	int winner = 0;
	
	//player 1 win check
	if (a == "x" && b == 'x' && c == 'x')
	{
		winner = 1;
		return winner;
	}
	if (d == 'x' && e == 'x' && f == 'x')
	{
		winner = 1;
		return winner;
	}
	if (g == 'x' && h == 'x' && i == 'x')
	{
		winner = 1;
		return winner;
	}
	if (a == "x" && d == 'x' && g == 'x')
	{
		winner = 1;
		return winner;
	}
	if (b == 'x' && e == 'x' && h == 'x')
	{
		winner = 1;
		return winner;
	}
	if (c == 'x' && f == 'x' && i == 'x')
	{
		winner = 1;
		return winner;
	}
	if (a == "x" && e == 'x' && i == 'x')
	{
		winner = 1;
		return winner;
	}
	if (c == 'x' && e == 'x' && g == 'x')
	{
		winner = 1;
		return winner;
	}

	//player 2 win check
	if (a == "o" && b == 'o' && c == 'o')
	{
		winner = 2;
		return winner;
	}
	if (d == 'o' && e == 'o' && f == 'o')
	{
		winner = 2;
		return winner;
	}
	if (g == 'o' && h == 'o' && i == 'o')
	{
		winner = 2;
		return winner;
	}
	if (a == "o" && d == 'o' && g == 'o')
	{
		winner = 2;
		return winner;
	}
	if (b == 'o' && e == 'o' && h == 'o')
	{
		winner = 2;
		return winner;
	}
	if (c == 'o' && f == 'o' && i == 'o')
	{
		winner = 2;
		return winner;
	}
	if (a == "o" && e == 'o' && i == 'o')
	{
		winner = 2;
		return winner;
	}
	if (c == 'o' && e == 'o' && g == 'o')
	{
		winner = 2;
		return winner;
	}

	return 0;
}

int playTTT(int winner)
{
	int drawCount = 0;
	while (winner != 1 || winner != 2)
	{
		drawCount++;
		string next;

		drawBoard();
		do
		{
			chrono::steady_clock::time_point begin = chrono::steady_clock::now();
			selection();
			chrono::steady_clock::time_point end = chrono::steady_clock::now();
			int time = chrono::duration_cast<chrono::seconds>(end - begin).count();

			if (time > 9999)
			{
				system("cls");
				cout << "Time violation! You automatically lost. Press y to continue" << endl;
				cin >> next;

				return 0;
			}

			winner = checkWinner();

			if (winner == 1)
			{
				system("cls");
				cout << "Player 1 wins!!\n" << endl;
				clearSelections();
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
				return 0;
			}
			drawBoard();

		} while (tryAgain == true);

		playerChange();
		
	}
	system("cls");
	return 0;
}

