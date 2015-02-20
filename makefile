puzzletest: main.o Puzzle.h.gch sudoku
	g++ main.o -o puzzletest

sudoku: sudoku.o Puzzle.h.gch
	g++ sudoku.o -o sudoku

sudoko.o: sudoku.cpp
	g++ -c sudoku.cpp

main.o: main.cpp
	g++ -c main.cpp

Puzzle.h.gch: Puzzle.h
	g++ -c Puzzle.h

clean:
	rm *.gch *.o puzzletest sudoku
