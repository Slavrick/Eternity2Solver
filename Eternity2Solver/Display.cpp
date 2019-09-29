#include "Display.h"
#include<iostream>
using namespace std;


Display::Display()
{
}


Display::~Display()
{
}

void Display::printBoard()
{
	for (int i = 0; i < ws->boardLength; i++) {
		for (int j = 0; j < ws->boardLength; j++) {
			cout <<" "<<ws->getPieceFromBoard(i, j)->getRelativeColor(0);
		}
	}
}
