#pragma once
#include"Workspace.h"

class Display
{
private:
	Workspace *ws;
public:
	Display();
	~Display();
	void printBoard();
	void printPieces();
};

