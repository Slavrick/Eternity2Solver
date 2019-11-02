#include "Argp.h"

namespace Argp {
	bool isInArray(const char* chararray, int arrayLen, char target) {
		for (int i = 0; i < arrayLen; i++) {
			if (chararray[i] == target)
				return true;
		}
		return false;
	}

	Args* parseArgs(int argc, char** argv, const char* unf, int unfl, const char* bif, int bifl) {
		if (argc < 2) {
			return nullptr;
		}
		int numUF = 0;
		int numbif = 0;
		int numOptions = 0;
		for (int currArg = 1; currArg < argc; currArg++) {
			if (argv[currArg][0] == '-') {
				//search for flags
				int argLen = strlen(argv[currArg]);
				for (int currChar = 1; currChar < argLen; currChar++) {
					//search for unary flags
					if (isInArray(unf, unfl, argv[currArg][currChar])) {
						numUF++;
					}
					//search for binary flags
					else if (isInArray(bif, bifl, argv[currArg][currChar])) {
						numbif++;
						if (currChar + 1 == argLen) {
							currArg++;
						}
						goto ENDLOOP;
					}
					//search for binary flags
				}
			}
			else {
				numOptions++;
			}
		ENDLOOP:;
		}
		std::cout << "NumUnf " << numUF << std::endl;
		std::cout << "Numbif " << numbif << std::endl;
		std::cout << "NumOpt " << numOptions << std::endl;
		Args* a;
		a = new Args;
		a->ufc = numUF;
		a->unaryFlags = new char[numUF];
		a->bfc = numbif;
		a->biFlag = new char[numbif];
		a->biFlagOpts = new std::string[numbif];
		a->numOpts = numOptions;
		a->options = new std::string[numOptions];
		int currOpt = 0;
		int curruf = 0;
		int currbif = 0;
		for (int currArg = 1; currArg < argc; currArg++) {
			if (argv[currArg][0] == '-') {
				//search for flags
				int argLen = strlen(argv[currArg]);
				for (int currChar = 1; currChar < argLen; currChar++) {
					//search for unary flags
					if (isInArray(unf, unfl, argv[currArg][currChar])) {
						a->unaryFlags[curruf] = argv[currArg][currChar];
						std::cout << argv[currArg][currChar];
						curruf++;
					}
					//search for binary flags
					else if (isInArray(bif, bifl, argv[currArg][currChar])) {
						a->biFlag[currbif] = argv[currArg][currChar];
						if (currChar + 1 == argLen) {
							currArg++;
							a->biFlagOpts[currbif] = argv[currArg];
						}
						else {
							int substrLen = argLen - currChar;
							char* substr = new char[substrLen];
							memcpy(substr, &argv[currArg][currChar + 1], substrLen - 1);
							substr[substrLen - 1] = '\0';
							a->biFlagOpts[currbif] = substr;
						}
						currbif++;
						goto ENDLOOPL;
					}
					//search for binary flags
				}
			}
			else {
				a->options[currOpt] = argv[currArg];
				currOpt++;
			}
		ENDLOOPL:;
		}
		return a;

	}

}


