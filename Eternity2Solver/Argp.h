#pragma once
#include<iostream>
#include<string>
#include "Args.h"

namespace Argp {
	Args* parseArgs(int argc, char** argv, const char* unf, int unfl, const char* bif, int bifl);
}
