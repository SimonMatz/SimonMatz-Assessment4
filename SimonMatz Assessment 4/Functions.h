#pragma once
#include <iostream>
#include <string>


using namespace std;


static char player = 'x';
static bool tryAgain = false;
//static int winner = 0;


int displayMenuScreen();

void clearSelections();

void drawBoard();

void playerChange();

void selection();

int checkWinner();

int playTTT(int winner);
