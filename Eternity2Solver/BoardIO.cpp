#include "BoardIO.h"

BoardIO::BoardIO(char * inputFile, char * outputFile)
{
	this->inputFile = inputFile;
	this->outputFile = outputFile;
}

BoardIO::BoardIO()
{
	inputFile = NULL;
	outputFile = NULL;
}

BoardIO::~BoardIO()
{
}

Workspace* BoardIO::buildFromFile()
{
	if (inputFile == NULL) {
		return NULL;
	}
	std::ifstream boardFileStream(inputFile);
	if (!boardFileStream.good()) {
		std::cout << "Could not open input file";
		exit(EXIT_FAILURE);
	}
	std::string boardWidth;
	boardFileStream >> boardWidth;
	int width = std::stoi(boardWidth);
	std::cout << width;
	Workspace* ws = new Workspace(width);
	for (int i = 0; i < width * width; i++) {
		std::string colors;
		boardFileStream >> colors;
		std::cout << colors << std::endl;
		if (!boardFileStream.good()) {
			std::cout << "Error Reading Pieces; Line number" << i;
			exit(EXIT_FAILURE);
		}
		Piece* pptr = new Piece(colors);
		ws->ptrContainer[i] = pptr;
	}
	return ws;
}

void BoardIO::writeToFile(Workspace * ws)
{
	if (outputFile == NULL) {
		std::cout << "Could Not Get Output File \n";
		exit(EXIT_FAILURE);
	}
	std::ofstream outputStream(outputFile);
	if (!outputStream.good()) {
		std::cout << "Could Not Open File For Writing \n";
		exit(EXIT_FAILURE);
	}
	outputStream << ws->boardLength << std::endl;
	for (int i = 0; i < ws->boardLength * ws->boardLength; i++) {
		Piece* temp = ws->ptrContainer[i];
		outputStream << temp->colors[0] << temp->colors[1] << temp->colors[2] << temp->colors[3] << std::endl;
	}
}

