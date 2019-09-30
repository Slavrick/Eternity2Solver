#pragma once
#include"Workspace.h"

class Display
{
private:
	Workspace *ws;
public:
	Display(Workspace* ws);
	~Display();
	void printBoard();
	void printPieces();
};

