#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Puzzle
{
public:
	Puzzle(int = 9);

	int size();
	void set(int, int, T);
	T get(int, int);

	template<typename U>
	friend istream& operator>>(istream&, Puzzle<U>&);
	template<typename U>
	friend ostream& operator<<(ostream&, Puzzle<U>&);

	typedef vector<vector<T> > Board;
private:
	Board board;
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
Puzzle<T>::Puzzle(int size)
{
	T temp;
	for (int r = 0; r < size; r++)
	{
		vector<T> row(size, 0);
		board.push_back(row);
	}
}

template<typename T>
int Puzzle<T>::size()
{
	return board.size();
}

template<typename T>
void Puzzle<T>::set(int r, int c, T val)
{
	if ((r < size) && (c < size) && (c >= 0) && (r >= 0))
		board[r][c] = val;
}

template<typename T>
T Puzzle<T>::get(int r, int c)
{
	if ((r < size) && (c < size) && (c >= 0) && (r >= 0))
		return board[r][c];

	return 0;
}
