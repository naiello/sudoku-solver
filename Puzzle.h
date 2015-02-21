#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

template<typename T>
class Puzzle
{
public:
	Puzzle(int = 9, T = 0);			// Takes an int that sets size of board and a T to use as the default value (usually 0 for ints)

	int size();				// Returns the size of the puzzle (puzzle assumed square)
	void set(int, int, T);			// Sets a certain square of the puzzle. Does nothing if changing would result in a duplicate value in a row, col or box
	T get(int, int);			// Gets the value of a square of the puzzle
	bool complete();			// Checks to see if the puzzle has been completed

	template<typename U>
	friend istream& operator>>(istream&, Puzzle<U>&);	// Load the puzzle from an input stream
	template<typename U>
	friend ostream& operator<<(ostream&, Puzzle<U>&);	// Write the puzzle to a stream

	typedef vector<vector<T> > Board;
private:
	Board board;
	T defVal;

	bool colContains(int, T);		// Checks if a given row contains a certain value
	bool rowContains(int, T);		// Checks if a given column contains a certain value
	bool boxContains(int, int, T);		// Checks if a 3x3 box contains a certain value
};

template<typename T>
istream& operator>>(istream& in, Puzzle<T>& puzz)
{
	T val;
	for (int r = 0; r < puzz.size(); r++)
	{
		for (int c = 0; c < puzz.size(); c++)
		{
			// Read the puzzle in space by space
			in >> val;
			puzz.board[r][c] = val;
		}
	}
	return in;
}

template<typename T>
ostream& operator<<(ostream& out, Puzzle<T>& puzz)
{
	// Print the puzzle space by space
	for (int r = 0; r < puzz.size(); r++)
	{
		for (int c = 0; c < puzz.size(); c++)
		{
			out << puzz.board[r][c] << " ";
		}
		out << endl;
	}

	return out;
}

template<typename T>
Puzzle<T>::Puzzle(int size, T val)
{
	T temp;
	for (int r = 0; r < size; r++)
	{
		vector<T> row(size, 0);
		board.push_back(row);
	}
	defVal = val;
}

template<typename T>
int Puzzle<T>::size()
{
	return board.size();
}

template<typename T>
void Puzzle<T>::set(int r, int c, T val)
{
	if ((r < size()) && (c < size()) && (c >= 0) && (r >= 0) && ((val == defVal) ||  (!colContains(c, val) && !rowContains(r, val) && !boxContains(r, c, val))))
		board[r][c] = val;
}

template<typename T>
T Puzzle<T>::get(int r, int c)
{
	if ((r < size()) && (c < size()) && (c >= 0) && (r >= 0))
		return board[r][c];

	return 0;
}

template<typename T>
bool Puzzle<T>::complete()
{
	// Does each space have a non-default value?
	for (int r = 0; r < size(); r++)
	{
		for (int c = 0; c < size(); c++)
		{
			if (board[r][c] == defVal)
				return false;
		}
	}

	return true;
}

template<typename T>
bool Puzzle<T>::colContains(int col, T val)
{
	// Does this column contain val?
	for (int r = 0; r < size(); r++)
	{
		if (board[r][col] == val)
			return true;
	}
}

template<typename T>
bool Puzzle<T>::rowContains(int row, T val)
{
	// Uses STL find() algorithm to attempt to find val in the given row
	return !(find(board[row].begin(), board[row].end(), val) == board[row].end());
}

template<typename T>
bool Puzzle<T>::boxContains(int row, int col, T val)
{
	int nBoxes = sqrt(size());
	int br = row / nBoxes * nBoxes;		// These two lines compute the top left square in the box
	int bc = col / nBoxes * nBoxes;

	// Check each square in the box, return result
	return ((board[br][bc] == val) || (board[br][bc + 1] == val) || (board[br][bc + 2] == val) ||
		(board[br + 1][bc] == val) || (board[br + 1][bc + 1] == val) || (board[br + 1][bc + 2] == val) ||
		(board[br + 2][bc] == val) || (board[br + 2][bc + 1] == val) || (board[br + 2][bc + 2] == val));
}
