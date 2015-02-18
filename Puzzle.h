#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Puzzle<T>
{
public:
	Puzzle(int = 9, istream&);

	int size();
	void set(int, int, T);
	T get(int, int);

	friend istream& operator>>(Puzzle<T>&, istream&);
	typedef vector<vector<T>> Board;
private:
	Board board;
};

template<typename T>
Puzzle<T>::Puzzle(int size, istream in&)
{
	T temp;
	for (int r = 0; r < size; r++)
	{
		vector<T> row(size, 0);
		for (int c = 0; c < size; c++)
		{
			in >> temp;
			row.push_back(temp);
		}
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
