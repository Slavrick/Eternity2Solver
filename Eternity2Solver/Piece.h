#pragma once
class Piece
{
public:
	char* colors;
	int pieceNum;
	int pieceFlag;
	int rotation;
	int pieceType;
	Piece(char* colors, int pieceNum = 0, int rotation = 0, int pieceFlag = 0);
	Piece(int pieceNum = 0, int rotation = 0, int pieceFlag = 0);
	~Piece();
	char getRelativeColor(int pos);
	char getAbsoluteColor(int pos);
	void rotate();
	void setRotation(int rotation);
};

