#pragma once
#include <iostream>
#include <string>

using namespace std;

static char player = 'X';
static bool tryAgain = false;
static int winner = 0;

int displayMenuScreen();

void drawBoard(char numbers[]);

void playerChange();

void selection(char numbers[]);

int checkWinner(char numbers[]);

int playTTT(char numbers []);

int playTTT2(char numbers[]);
