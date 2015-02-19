#include <iostream>
#include <fstream>
#include <string>
#include "Puzzle.h"

using namespace std;

int main(int argc, char** argv)
{
	string filename;
	Puzzle<int> puzz(9);
	if (argc == 2)
		filename = argv[1];
	else
	{
		cout << "Enter the input file name: ";
		cin >> filename;
	}

	ifstream file(filename.c_str());
	file >> puzz;
	file.close();

	cout << puzz;

	return 0;
}
