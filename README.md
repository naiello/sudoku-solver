# sudoku-solver
Sudoku solver for CSE 20212 (Lab 5).

Sudoku is a popular puzzle where a player completes a grid based on some (but not all) cells provided.  The challenge is to find the values of the unknown cells.  Every column, row, and 3x3 sub-grid must contain the numbers 1-9 exactly once.

The goal of this lab is to design a templated class Puzzle<T> in order to allow the user to play Sudoku (Puzzle<int>) or a variant like Wordoku (Puzzle<char>), and then design a driver program to allow a user to actually play.
