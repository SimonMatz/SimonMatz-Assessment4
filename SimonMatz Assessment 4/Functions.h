//Simon Matz A00018077 Assessment 4
//Github respository link: https://github.com/SimonMatz/SimonMatz-Assessment4

#pragma once
#include <iostream>
#include <string>

using namespace std;

//had to use static, othwerwise weird build errors
static char player = 'X';
static bool tryAgain = false;
static int winner = 0;

//displays the main menu with 4 choices
int displayMenuScreen();

//draws game board
void drawBoard(char numbers[]);

//changes players and symbol
char playerChange();

//player field selection
void selection(char numbers[]);

//checks for 3 of a kind 
int checkWinner(char numbers[]);

//displays player wins
void showScores();

//main function for tic tac toe game PvP
int playTTT(char numbers[]);

//blocks possible player 1 win
int blockWin(char numbers[]);

//makes the winning move when possible for computer
int winningMove(char numbers[]);

//computer player field selection - random, blcok win, play for win
void cpuSelection(char numbers[]);

//main function for tic tac toe game PvC
int playTTT2(char numbers[]);
