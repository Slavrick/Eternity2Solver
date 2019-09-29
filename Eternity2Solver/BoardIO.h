#pragma once
#include"Workspace.h"

class BoardIO
{
public:
	BoardIO();
	~BoardIO();
	Workspace buildFromFile();
};

