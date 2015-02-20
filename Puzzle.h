#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

template<typename T>
class Puzzle
{
public:
	Puzzle(int = 9, T = 0);

	int size();
	void set(int, int, T);
	T get(int, int);
	bool complete();

	template<typename U>
	friend istream& operator>>(istream&, Puzzle<U>&);
	template<typename U>
	friend ostream& operator<<(ostream&, Puzzle<U>&);

	typedef vector<vector<T> > Board;
private:
	Board board;
	T defVal;

	bool colContains(int, T);
	bool rowContains(int, T);
	bool boxContains(int, int, T);
};

template<typename T>
istream& operator>>(istream& in, Puzzle<T>& puzz)
{
	T val;
	for (int r = 0; r < puzz.size(); r++)
	{
		for (int c = 0; c < puzz.size(); c++)
		{
			in >> val;
			puzz.board[r][c] = val;
		}
	}
	return in;
}

template<typename T>
ostream& operator<<(ostream& out, Puzzle<T>& puzz)
{
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
	for (int r = 0; r < size(); r++)
	{
		if (board[r][col] == val)
			return true;
	}
}

template<typename T>
bool Puzzle<T>::rowContains(int row, T val)
{
	return !(find(board[row].begin(), board[row].end(), val) == board[row].end());
}

template<typename T>
bool Puzzle<T>::boxContains(int row, int col, T val)
{
	int nBoxes = sqrt(size());
	int br = row / nBoxes * nBoxes;		// These two lines compute the top left square in the box
	int bc = col / nBoxes * nBoxes;

	return ((board[br][bc] == val) || (board[br][bc + 1] == val) || (board[br][bc + 2] == val) ||
		(board[br + 1][bc] == val) || (board[br + 1][bc + 1] == val) || (board[br + 1][bc + 2] == val) ||
		(board[br + 2][bc] == val) || (board[br + 2][bc + 1] == val) || (board[br + 2][bc + 2] == val));
}
