#include "Workspace.h"



Workspace::Workspace(int boardLength)
{
	this->boardLength = boardLength;
	ptrContainer = new Piece*[boardLength * boardLength];
	for (int i = 0; i < boardLength * boardLength; i++) {
		ptrContainer[i] = new Piece();
	}
	boardSpace = new Piece*[boardLength * boardLength];
	for (int i = 0; i < boardLength * boardLength; i++) {
		boardSpace[i] = &empty;
	}
}

Workspace::~Workspace()
{
	for (int i = 0; i < boardLength * boardLength; i++) {
		delete ptrContainer[i];
	}
	delete[] boardSpace;
	delete[] ptrContainer;
}

Piece* Workspace::getPieceFromBoard(int x, int y)
{
	return boardSpace[x * boardLength + y];
}

void Workspace::setPiece(int x, int y, Piece * p)
{
	boardSpace[x * boardLength + y] = p;
}
