#pragma once
#include<string>

class Args {
public:
	Args();
	~Args();
	int numArgs;
	int numOpts;
	std::string* options;
	int ufc;
	char* unaryFlags;
	int bfc;
	char* biFlag;
	std::string* biFlagOpts;
};
