#pragma once
#include "Workspace.h"

class Analysis
{
private:
	Workspace *ws;
public:
	Analysis();
	~Analysis();
	int numColors();
	void colorHistogram(bool sorted);

};

