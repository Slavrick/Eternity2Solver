#include<iostream>
#include"Workspace.h"
#include"Display.h"
#include"Randomizer.h"

using namespace std;

int main(int argc, char** argv) {

	//if (argc < 2) {
	//	cout << "Usage: " << argv[0] << " Flags";
	//}
	Workspace *ws = new Workspace(5);
	Display d(ws);
	d.printBoard();
	cout << endl << endl;
	Randomizer r(ws);
	r.randomizeBoard(5);
	r.linearAssignment();
	d.printBoard();
	d.printPieces();
	int a;
	cin >> a;
	return 0;
}