puzzletest: main.o Puzzle.h.gch
	g++ main.o -o puzzletest

main.o: main.cpp
	g++ -c main.cpp

Puzzle.h.gch: Puzzle.h
	g++ -c Puzzle.h

clean:
	rm *.gch *.o puzzletest
