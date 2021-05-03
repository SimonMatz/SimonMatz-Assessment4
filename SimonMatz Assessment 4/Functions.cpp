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

void drawBoard(char numbers[])
{
	system("cls");

	cout << "| " << numbers[0] << " | " << numbers[1] << " | " << numbers[2] << " | " << endl;
	cout << "|---|---|---|" << endl;
	cout << "| " << numbers[3] << " | " << numbers[4] << " | " << numbers[5] << " | " << endl;
	cout << "|---|---|---|" << endl;
	cout << "| " << numbers[6] << " | " << numbers[7] << " | " << numbers[8] << " | " << endl;
}

void playerChange()
{
	if (player == 'x')
		player = 'o';
	else
		player = 'x';

}

//void checkError(char numbers[])
//{
//	string pause;
//
//	if (numbers[1] == 'x' || numbers[1] == 'o')
//	{
//		cout << "\n\n\nERROR 2\n\n";
//		cin >> pause;
//		tryAgain = true;
//	}
//}

void selection(char numbers[])
{
	string pause;

	while (true)
	{	
		if (keyIsDown('1'))
		{

			if (numbers[0] == '1')
			{
				numbers[0] = player;
				tryAgain = false;
			}

			else
			{
				cout << "\n\n\nERROR 1\n\n";
				cin >> pause;
				tryAgain = true;
			}
			return;
		}

		else if (keyIsDown('2'))
		{
			if (numbers[1] == '2')
			{
				numbers[1] = player;
				tryAgain = false;
			}

			else
			{
				cout << "\n\n\nERROR 2\n\n";
				cin >> pause;
				tryAgain = true;
			}
			return;
		}
		else if (keyIsDown('3'))
		{
			

			if (numbers[2] == 'x' || numbers[2] == 'o')
			{
				
				tryAgain = true;
			}
			else
			{
				numbers[2] = player;
				tryAgain = false;
			}
			return;
		}

		else if (keyIsDown('4'))
		{
			
			if (numbers[3] == 'x' || numbers[3] == 'o')
			{
				
				tryAgain = true;
			}
			else
			{
				numbers[3] = player;
				tryAgain = false;
			}
			return;
		}
		else if (keyIsDown('5'))
		{
			
			if (numbers[4] == 'x' || numbers[4] == 'o')
			{
				
				tryAgain = true;
			}
			else
			{
				numbers[4] = player;
				tryAgain = false;
			}
			return;

		}

		else if (keyIsDown('6'))
		{
			
			if (numbers[5] == 'x' || numbers[5] == 'o')
			{
				
				tryAgain = true;
			}
			else
			{
				numbers[5] = player;
				tryAgain = false;
			}
			return;
		}
		else if (keyIsDown('7'))
		{
			
			if (numbers[6] == 'x' || numbers[6] == 'o')
			{
				
				tryAgain = true;
			}
			else
			{
				numbers[6] = player;
				tryAgain = false;
			}

			return;
		}

		else if (keyIsDown('8'))
		{
			
			if (numbers[7] == 'x' || numbers[7] == 'o')
			{
				
				tryAgain = true;
			}
			else
			{
				numbers[7] = player;
				tryAgain = false;
			}

			return;
		}
		else if (keyIsDown('9'))
		{
			
			if (numbers[8] == 'x' || numbers[8] == 'o')
			{
				
				tryAgain = true;
			}
			else
			{
				numbers[8] = player;
				tryAgain = false;
			}

			return;
		}
	}
}

int checkWinner(char numbers[])
{
	//player 1 win check
	if (numbers[0] == 'x' && numbers[1] == 'x' && numbers[2] == 'x')
	{
		winner = 1;
		return winner;
	}
	if (numbers[3] == 'x' && numbers[4] == 'x' && numbers[5] == 'x')
	{
		winner = 1;
		return winner;
	}
	if (numbers[6] == 'x' && numbers[7] == 'x' && numbers[8] == 'x')
	{
		winner = 1;
		return winner;
	}
	if (numbers[0] == 'x' && numbers[3] == 'x' && numbers[6] == 'x')
	{
		winner = 1;
		return winner;
	}
	if (numbers[1] == 'x' && numbers[4] == 'x' && numbers[7] == 'x')
	{
		winner = 1;
		return winner;
	}
	if (numbers[2] == 'x' && numbers[5] == 'x' && numbers[8] == 'x')
	{
		winner = 1;
		return winner;
	}
	if (numbers[0] == 'x' && numbers[4] == 'x' && numbers[8] == 'x')
	{
		winner = 1;
		return winner;
	}
	if (numbers[2] == 'x' && numbers[4] == 'x' && numbers[6] == 'x')
	{
		winner = 1;
		return winner;
	}

	//player 2 win check
	if (numbers[0] == 'o' && numbers[1] == 'o' && numbers[2] == 'o')
	{
		winner = 2;
		return winner;
	}
	if (numbers[3] == 'o' && numbers[4] == 'o' && numbers[5] == 'o')
	{
		winner = 2;
		return winner;
	}
	if (numbers[6] == 'o' && numbers[7] == 'o' && numbers[8] == 'o')
	{
		winner = 2;
		return winner;
	}
	if (numbers[0] == 'o' && numbers[3] == 'o' && numbers[6] == 'o')
	{
		winner = 2;
		return winner;
	}
	if (numbers[1] == 'o' && numbers[4] == 'o' && numbers[7] == 'o')
	{
		winner = 2;
		return winner;
	}
	if (numbers[2] == 'o' && numbers[5] == 'o' && numbers[8] == 'o')
	{
		winner = 2;
		return winner;
	}
	if (numbers[0] == 'o' && numbers[4] == 'o' && numbers[8] == 'o')
	{
		winner = 2;
		return winner;
	}
	if (numbers[2] == 'o' && numbers[4] == 'o' && numbers[6] == 'o')
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
			drawBoard(numbers);

		} while (tryAgain == true);

		playerChange();
		
	}
	system("cls");

	return winner;
}

