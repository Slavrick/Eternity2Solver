#include<iostream>
#include<string.h>
#include<string>
#include"Workspace.h"
#include"Display.h"
#include"Randomizer.h"
#include"BoardIO.h"

using namespace std;

#define SOLVEMODE 1;
#define ANALYSISMODE 2;
#define CREATEMODE 3;
#define MANUALMODE 4;

void printMan();
void printUsage(string s, string error = "");
void printMan();
void handleBoardCreation(string outputfile, int numcolors, int seed = -1);
void solveBoard(string inputfile, string outputfile, int method = 0);
void handleAnalysis(char* inputfile);
int* parseForMode(int argc, char** argv);
int getMethod(int argc, char** argv, int currArg, int currChar);

int main(int argc, char** argv) {
	if (argc < 2) {
		printUsage(argv[0]);
		exit(EXIT_FAILURE);
	}
	int* mode = parseForMode(argc, argv);
	if (mode[0] == -1) {
		printUsage(argv[0]);
	}
	int requiredFiles = 0;
	int fileCount = 0;
	char* file1 = argv[0];
	char* file2 = argv[0];
	if (mode[0] == 1)
		requiredFiles = 2;
	else
		requiredFiles = 1;
	for (int currArg = 1; currArg < argc; currArg++) {
		if (argv[currArg][0] == '-' || argv[currArg][0] < 65) {
			continue;
		}
		else if (fileCount > requiredFiles) {
			printUsage(argv[0], "too many files specified");
			cout << fileCount;
			exit(EXIT_FAILURE);
		}
		else if (fileCount == 0) {
			file1 = argv[currArg];
			fileCount++;
		}
		else {
			file2 = argv[currArg];
			fileCount++;
		}

	}
	switch(mode[0]){
		case 1:
			if (fileCount != 2){
				printUsage(argv[0], "solution error");
				exit(EXIT_FAILURE);
			}
			solveBoard(file1, file2, mode[1]);
			break;
		case 2:
			if (fileCount != 1) {
				printUsage(argv[0], "Analysis error");
				exit(EXIT_FAILURE);
			}
			handleAnalysis(file1);
			break;
		case 3:
			if (fileCount != 1) {
				printUsage(argv[0], "creation error");
				exit(EXIT_FAILURE);
			}
			handleBoardCreation(file1,5);
			break;
		
	}
	//Workspace *ws = new Workspace(16);
	//Display d(ws);
	//d.printBoard();
	//cout << endl << endl;
	//Randomizer r(ws);
	//r.randomizeBoard(5);
	//r.linearAssignment();
	//d.printBoard();
	//d.printPieces();
	cout << endl;
	return 0;
}

int* parseForMode(int argc, char** argv) {
	bool modeSet = false;
	int* mode = new int[2];
	mode[1] = -1;
	mode[0] = -1;
	for (int currArg = 1; currArg < argc; currArg++) {
		if (argv[currArg][0] == '-') {
			int length = strlen(argv[currArg]);
			for (int currChar = 1; currChar < length; currChar++) {
				switch (argv[currArg][currChar]) {
					case's': {
						if (modeSet) {
							printUsage(argv[0], "Too many modes set");
							exit(EXIT_FAILURE);
						}
						mode[0] = SOLVEMODE;
						mode[1] = getMethod(argc, argv, currArg, currChar);
						modeSet = true;
						break;
					}
					case'h':
						printMan();
						exit(0);
					case'c': {
						if (modeSet) {
							printUsage(argv[0], "Too many modes set");
							exit(EXIT_FAILURE);
						}
						mode[0] = CREATEMODE;
						mode[1] = getMethod(argc, argv, currArg, currChar);
						modeSet = true;
						break;
					}
					case'a': {
						if (modeSet) {
							printUsage(argv[0], "Too many modes set");
							exit(EXIT_FAILURE);
						}
						mode[0] = ANALYSISMODE;
						mode[1] = getMethod(argc,argv,currArg,currChar);
						modeSet = true;
						break;
					}
				}
			}
		}
	}
	return mode;
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
	cout << "Usage: " << s << " [Input File] [Output File] <Flags> \n";
	if (error != "")
		cout << "  Error: " << error << endl;
	cout << "    -h for help \n";
}

void printMan() {
	cout << "Put the manual here";
}

void handleBoardCreation(string outputfile, int numcolors, int seed) {
	cout << "Creation entered output file specified is: " << outputfile;
	char* null = NULL;
	BoardIO boardOut;
	boardOut.outputFile = outputfile.c_str();
	Workspace* ws = new Workspace(5);
	Randomizer r(ws);
	r.randomizeBoard(numcolors);
	boardOut.writeToFile(ws);
	delete ws;
}

void solveBoard(string inputfile, string outputfile, int method) {
	cout << "Solve Mode entered; input file specified is: " << inputfile << " and output file specified is: " << outputfile;
}

void handleAnalysis(char* inputfile) {
	cout << "Analysis entered; input file specified is: " << inputfile;
	BoardIO boardLoader(inputfile, NULL);
	Workspace* ws = boardLoader.buildFromFile();
	Display d(ws);
	d.printPieces();
	cout << endl;
}

