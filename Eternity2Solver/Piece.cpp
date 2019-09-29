#include "Piece.h"

Piece::Piece(char * colors, int pieceNum, int rotation, int pieceFlag)
{
	this->pieceFlag = pieceFlag;
	this->pieceNum = pieceNum;
	this->rotation = rotation;
	this->colors = new char[4];
	for (int i = 0; i < 4; i++) {
		this->colors[i] = colors[i];
		if (colors[i] == '0')
			this->pieceType++;
	}
	
}

Piece::Piece(int pieceNum, int rotation, int pieceFlag)
{
	this->pieceFlag = pieceFlag;
	this->pieceNum = pieceNum;
	this->rotation = rotation;
	this->colors = new char[4];
	for (int i = 0; i < 4; i++) {
		this->colors[i] = ' ';
		if (colors[i] == '0')
			this->pieceType++;
	}
}

Piece::~Piece()
{
	delete[] colors;
}

char Piece::getRelativeColor(int pos)
{
	if (pos < 0)
		pos = 0;
	int relativeIndex = (rotation + pos) % 4;
	return this->colors[relativeIndex];
}

char Piece::getAbsoluteColor(int pos)
{
	if (pos < 0)
		pos = 0;
	pos = pos % 4;
	return this->colors[pos];
}

void Piece::rotate()
{
	this->rotation++;
	rotation = rotation % 4;
}

void Piece::setRotation(int rotation)
{
	if (rotation < 0 || rotation > 3)
		return;
	this->rotation = rotation;
}
