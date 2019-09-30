#include "Display.h"
#include<iostream>
using namespace std;

Display::Display(Workspace * ws)
{
	this->ws = ws;
}

Display::~Display()
{
}

void Display::printBoard()
{
	cout << "+";
	for (int j = 0; j < ws->boardLength; j++) {
		cout << "---+";
	}
	cout << endl;
	for (int i = 0; i < ws->boardLength; i++) {
		//print top
		for (int j = 0; j < ws->boardLength; j++) {
			cout <<"| "<<ws->getPieceFromBoard(i, j)->getRelativeColor(0) << " ";
		}
		cout << "| \n";
		//print middle
		for (int j = 0; j < ws->boardLength; j++) {
			cout << "|" << ws->getPieceFromBoard(i, j)->getRelativeColor(3) << " " << ws->getPieceFromBoard(i, j)->getRelativeColor(1);
		}
		cout << "| \n";
		//print bottom
		for (int j = 0; j < ws->boardLength; j++) {
			cout << "| " << ws->getPieceFromBoard(i, j)->getRelativeColor(2) << " ";
		}
		cout << "| \n";
		//print spacer
		cout << "+";
		for (int j = 0; j < ws->boardLength; j++) {
			cout << "---+";
		}
		cout << endl;
	}
}

void Display::printPieces()
{
	for (int i = 0; i < ws->boardLength * ws->boardLength; i++) {
		cout << i <<": { " << ws->ptrContainer[i]->colors[0] << "," << ws->ptrContainer[i]->colors[1] << "," << ws->ptrContainer[i]->colors[2] << "," << ws->ptrContainer[i]->colors[3] << " } ";
	}
}
