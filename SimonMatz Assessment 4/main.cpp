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

string a = "1";
string b = "2";
string c = "3";
string d = "4";
string e = "5";
string f = "6";
string g = "7";
string h = "8";
string i = "9";

char player = 'x';
bool tryAgain = false;

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

void drawBoard()
{
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
	while (true)
	{
			if (keyIsDown('1'))
			{
				system("cls");

				if (a == "x" || a == "o")
				{
					cout << "\n\n\nERROR\n\n";
					tryAgain = true;
				}
				else
				{
					a = player;
					tryAgain = false;
				}

				drawBoard();
				system("pause");
				system("cls");
				return;
			}

			if (keyIsDown('2'))
			{
				system("cls");

				if (b == "x" || b == "o")
				{
					cout << "\n\n\nERROR\n\n";
					tryAgain = true;
				}
				else
				{
					b = player;
				tryAgain = false;
				}

				drawBoard();
				system("pause");
				system("cls");
				return;
			}
			if (keyIsDown('3'))
			{
				system("cls");

				if (c == "x" || c == "o")
				{
					cout << "\n\n\nERROR\n\n";
					tryAgain = true;
				}
				else
				{
					c = player;
					tryAgain = false;
				}
				drawBoard();
				system("pause");
				system("cls");
				return;
			}

			if (keyIsDown('4'))
			{
				system("cls");
				if (d == "x" || d == "o")
				{
					cout << "\n\n\nERROR\n\n";
					tryAgain = true;
				}
				else
				{
					d = player;
					tryAgain = false;
				}

				drawBoard();
				system("pause");
				system("cls");
				return;
			}
			if (keyIsDown('5'))
			{
				system("cls");
				if (e == "x" || e == "o")
				{
					cout << "\n\n\nERROR\n\n";
					tryAgain = true;
				}
				else
				{
					e = player;
					tryAgain = false;
				}

				drawBoard();
				system("pause");
				system("cls");
				return;

			}

			if (keyIsDown('6'))
			{
				system("cls");
				if (f == "x" || f == "o")
				{
					cout << "\n\n\nERROR\n\n";
					tryAgain = true;
				}
				else
				{
					f = player;
					tryAgain = false;
				}

				drawBoard();
				system("pause");
				system("cls");
				return;
			}
			if (keyIsDown('7'))
			{
				system("cls");
				if (g == "x" || g == "o")
				{
					cout << "\n\n\nERROR\n\n";
					tryAgain = true;
				}
				else
				{
					g = player;
					tryAgain = false;
				}

				drawBoard();
				system("pause");
				system("cls");
				return;
			}

			if (keyIsDown('8'))
			{
				system("cls");
				if (h == "x" || h == "o")
				{
					cout << "\n\n\nERROR\n\n";
					tryAgain = true;
				}
				else
				{	h = player;
					tryAgain = false;
				}

				drawBoard();
				system("pause");
				system("cls");
				return;
			}
			if (keyIsDown('9'))
			{
				system("cls");
				if (i == "x" || i == "o")
				{
					cout << "\n\n\nERROR\n\n";
					tryAgain = true;
				}
				else
				{
					i = player;
					tryAgain = false;
				}

				drawBoard();
				system("pause");
				system("cls");
				return;
			}
	}
}

void selection2()
{
	while (true)
	{
		
		if (keyIsDown('1'))
		{
			system("cls");

			if (a == "x" || a == "o")
			{
				cout << "\n\n\nERROR\n\n";
				tryAgain = true;
			}

			else
			a = "o";

			drawBoard();
			system("pause");
			system("cls");
			return;

		}

		if (keyIsDown('2'))
		{
			system("cls");

			if (b == "x" || b == "o")
			{
				cout << "\n\n\nERROR\n\n";
				tryAgain = true;
			}

			else

			b = "o";
			
			drawBoard();
			system("pause");
			system("cls");
			return;
		}
		if (keyIsDown('3'))
		{
			system("cls");
			
			if (c == "x" || c == "o")
			{
				cout << "\n\n\nERROR\n\n";
				tryAgain = true;
			}

			else
			c = "o";
			
			drawBoard();
			system("pause");
			system("cls");
			return;
		}

		if (keyIsDown('4'))
		{
			system("cls");
			if (d == "x" || d == "o")
			{
				cout << "\n\n\nERROR\n\n";
				tryAgain = true;
			}
			else
			d = "o";
		
			drawBoard();
			system("pause");
			system("cls");
			return;
		}
		if (keyIsDown('5'))
		{
			system("cls");
			if (e == "x" || e == "o")
			{
				cout << "\n\n\nERROR\n\n";
				tryAgain = true;
			}
			else
			e = "o";
			
			drawBoard();
			system("pause");
			system("cls");
			return;

		}

		if (keyIsDown('6'))
		{
			system("cls");
			if (f == "x" || f == "o")
			{
				cout << "\n\n\nERROR\n\n";
				tryAgain = true;
			}
			else
			f = "o";
			
			drawBoard();
			system("pause");
			system("cls");
			return;
		}
		if (keyIsDown('7'))
		{
			system("cls");
			if (g == "x" || g == "o")
			{
				cout << "\n\n\nERROR\n\n";
				tryAgain = true;
			}
			else
			g = "o";
			
			drawBoard();
			system("pause");
			system("cls");
			return;
		}

		if (keyIsDown('8'))
		{
			system("cls");
			if (h == "x" || h == "o")
			{
				cout << "\n\n\nERROR\n\n";
				tryAgain = true;
			}
			else
			h = "o";
			
			drawBoard();
			system("pause");
			system("cls");
			return;
		}
		if (keyIsDown('9'))
		{
			system("cls");
			if (i == "x" || i == "o")
			{
				cout << "\n\n\nERROR\n\n";
				tryAgain = true;
			}
			else
			i = "o";
			
			drawBoard();
			system("pause");
			system("cls");
			return;
		}
	}
}

void playTTT()
{
	while (true)
	{
		drawBoard();
		do
		{
			selection();

		} while (tryAgain == true);

		playerChange();
	}

	system("pause");
}

void main()
{
	int choice = 0;

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

			} while (true);
		}
	} while (choice != EXIT);

	system("pause");
}