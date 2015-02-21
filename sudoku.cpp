#include <fstream>
#include <iostream>
#include <cstdlib>
#include "Puzzle.h"

#define PUZZLE_SIZE 9

using namespace std;

int main(int argc, char** argv)
{
	// Try to read the file from the argument list, if we can't, ask the user
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

	// Read in the file
	Puzzle<int> puzz(PUZZLE_SIZE, 0);
	file >> puzz;
	file.close();

	int r, c, val;
	while (!puzz.complete())
	{
		// Print the puzzle & header
		system("clear");
		cout << "SUDOKU PUZZLE" << endl;
		cout << "Enter -1 to quit." << endl;
		cout << puzz;

		// Prompt the user for the next space to fill in
		cout << "Enter row, column and value [1 - " << PUZZLE_SIZE << "] separated by spaces: ";
		cin >> r;

		// Check to see if the user wants to quit
		if (r == -1) 
			break;

		// Try to set the given square (error checking handled by puzzle class)
		cin >> c >> val;
		puzz.set(r - 1, c - 1, val);
	}
	return 0;
}
