#include<iostream>
#include<string.h>
#include<string>
#include"Workspace.h"
#include"Display.h"
#include"Randomizer.h"
#include"BoardIO.h"
#include"Argp.h"
#include"Args.h"

using namespace std;

#define SOLVEMODE 1;
#define ANALYSISMODE 2;
#define CREATEMODE 3;
#define MANUALMODE 4;

void printUsage(string s, string error = "");
void printMan();
void solveBoard(Args* arguments);
void createBoard(Args* arguments);
void analyzeBoard(Args* arguments);
string* getIOFiles(Args* arguments, int numFiles = 1, const char* type = "r");

void solveBoard(string inputfile, string outputfile, int method = 0);
void handleBoardCreation(string outputfile, int numcolors, int seed = -1);
void handleAnalysis(char* inputfile);
int getMethod(int argc, char** argv, int currArg, int currChar);

int main(int argc, char** argv) {
	if (argc < 2) {
		printUsage(argv[0]);
		exit(EXIT_FAILURE);
	}
	Args* parsedArgs = Argp::parseArgs(argc, argv, "achs", 4, "LAMSoi", 4);
	if (parsedArgs->ufc == 0) {
		printUsage(argv[0], "No mode set");
	}
	switch (parsedArgs->unaryFlags[0]) {
		case 'a':
			analyzeBoard(parsedArgs);
			break;
		case 'c':
			createBoard(parsedArgs);
			break;
		case 'h':
			printMan();
			break;
		case 's':
			solveBoard(parsedArgs);
			break;
	}
	//Workspace *ws = new Workspace(16);
	//Display d(ws);
	//d.printBoard();
	//std::cout << endl << endl;
	//Randomizer r(ws);
	//r.randomizeBoard(5);
	//r.linearAssignment();
	//d.printBoard();
	//d.printPieces();
	std::cout << endl;
	return 0;
}

int getMethod(int argc, char** argv, int currArg, int currChar) {
	string next = string(argv[currArg]).substr(currChar + 1);
	int method = 0;
	if (next.length() == 0 && currArg + 1 != argc) {
		method = atoi(argv[currArg + 1]);
	}
	else {
		method = atoi(next.c_str());
	}
	if (method == 0) {
		printUsage(argv[0], "no option chosen");
		exit(EXIT_FAILURE);
	}
	return method;
}

void printUsage(string s, string error) {
	std::cout << "Usage: " << s << " [Input File] [Output File] <Flags> \n";
	if (error != "")
		std::cout << "  Error: " << error << endl;
	std::cout << "    -h for help \n";
}

void printMan() {
	std::cout << "Put the manual here";
}

void handleBoardCreation(string outputfile, int numcolors, int seed) {
	std::cout << "Creation entered output file specified is: " << outputfile;
	char* null = NULL;
	BoardIO boardOut;
	boardOut.outputFile = outputfile.c_str();
	Workspace* ws = new Workspace(5);
	Randomizer r(ws);
	r.randomizeBoard(numcolors);
	boardOut.writeToFile(ws);
	delete ws;
}

void createBoard(Args * arguments)
{
	std::cout << "Board Creation Entered";
}

void solveBoard(string inputfile, string outputfile, int method) {
	std::cout << "Solve Mode entered; input file specified is: " << inputfile << " and output file specified is: " << outputfile;
}

void solveBoard(Args * arguments) {
	std::cout << "Solve Mode entered;";

}

void analyzeBoard(Args * arguments){
	std::cout << "analysis entered";
}

void handleAnalysis(char* inputfile) {
	std::cout << "Analysis entered; input file specified is: " << inputfile;
	BoardIO boardLoader(inputfile, NULL);
	Workspace* ws = boardLoader.buildFromFile();
	Display d(ws);
	d.printPieces();
	std::cout << endl;
}

