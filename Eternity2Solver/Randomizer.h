#pragma once
#include"Workspace.h"
class Randomizer
{
private:
	Workspace* ws;
public:
	Randomizer(Workspace* ws);
	~Randomizer();
	void randomizeBoard(int numColors);
	void linearAssignment();
};

