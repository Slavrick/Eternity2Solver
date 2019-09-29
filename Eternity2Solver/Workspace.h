#pragma once
#include"Piece.h"

class Workspace
{
public:
	int boardLength;
	Piece** boardSpace;
	Piece** ptrContainer;
	Piece empty;
	Workspace(int BoardLength);
	~Workspace();
	Piece* getPieceFromBoard(int x, int y);
	void setPiece(int x, int y, Piece* p);
};


