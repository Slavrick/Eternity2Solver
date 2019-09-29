#pragma once
#include "Algorithm.h"

class BruteForce: public Algorithm
{
public:
	BruteForce();
	~BruteForce();
	void run();
	void preempt();
	void stop();
};

