#include <fstream>
#include <iostream>
#include <cstdlib>
#include "Puzzle.h"

#define PUZZLE_SIZE 9

using namespace std;

int main(int argc, char** argv)
{
	string filename;
	if (argc == 2)
		filename = argv[1];
	else
	{
		cout << "Enter the input file name: ";
		cin >> filename;
	}

	ifstream file(filename.c_str());
	if (!file.is_open())
	{
		cout << "Failed to open " << filename << endl;
		return 1;
	}
	
	Puzzle<int> puzz(PUZZLE_SIZE, 0);
	file >> puzz;
	file.close();

	int r, c, val;
	while (!puzz.complete())
	{
		system("clear");
		cout << "SUDOKU PUZZLE" << endl;
		cout << "Enter -1 to quit." << endl;
		cout << puzz;
		cout << "Enter row, column and value [1 - " << PUZZLE_SIZE << "] separated by spaces: ";
		cin >> r;

		if (r == -1) 
			break;

		cin >> c >> val;
		puzz.set(r - 1, c - 1, val);
	}
	return 0;
}
