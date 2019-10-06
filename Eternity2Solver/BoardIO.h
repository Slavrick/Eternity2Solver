#pragma once
#include"Workspace.h"
#include"Piece.h"
#include<fstream>
#include<string>
#include<iostream>

class BoardIO
{
public:
	const char* inputFile;
	const char* outputFile;
	BoardIO(char* inputFile, char* outputFile);
	BoardIO();
	~BoardIO();
	Workspace* buildFromFile();
	void writeToFile(Workspace* ws);
};

