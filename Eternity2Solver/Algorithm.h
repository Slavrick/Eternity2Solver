#pragma once
#include "Workspace.h"
class Algorithm
{
private:
	Workspace ws;
public:
	virtual void preempt() = 0;
	virtual void stop() = 0;
	virtual void run() = 0;
};

