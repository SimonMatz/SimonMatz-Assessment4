#pragma once
#include <iostream>
#include <string>

using namespace std;

static char player = 'X';
static bool tryAgain = false;
static int winner = 0;

int displayMenuScreen();

void drawBoard(char numbers[]);

char playerChange();

void selection(char numbers[]);

int checkWinner(char numbers[]);

void showScores();

int playTTT(char numbers[]);

int blockWin(char numbers[]);

int winningMove(char numbers[]);

void cpuSelection(char numbers[]);

int playTTT2(char numbers[]);
