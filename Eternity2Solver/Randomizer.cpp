#include "Randomizer.h"
#include <stdlib.h>


Randomizer::Randomizer(Workspace* ws)
{
	this->ws = ws;
}


Randomizer::~Randomizer()
{
}

void Randomizer::randomizeBoard(int numColors)
{
	if (numColors < 2) {
		numColors = 2;
	}
	else if (numColors > 26) {
		numColors = 26;
	}
	for (int i = 0; i < ws->boardLength * ws->boardLength; i++) {
		for (int colIndex = 0; colIndex < 4; colIndex++) {
			ws->ptrContainer[i]->colors[colIndex] = (char)((rand() % numColors) + 65);
		}
	}
}

void Randomizer::linearAssignment()
{
	for (int i = 0; i < ws->boardLength; i++) {
		for (int j = 0; j < ws->boardLength; j++) {
			ws->setPiece(i,j,ws->ptrContainer[i*ws->boardLength + j]);
		}
	}
}
