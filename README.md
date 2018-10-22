# Tesla Question Implementation

## Original Question

Question:

Let’s say we have a chessboard, which has the typical 8 x 8 square tiles.  The rook is a chess piece that can move horizontally and vertically across the entire board.  We want a program that will take a board with N number of rooks already placed, and for the program to place more rooks with the following rules.
 

Rules:

Rooks must be placed in such a way that they don’t collide with each other. 
The program should take input for a starting board configuration with N rooks placed.  (The starting set always conforms to the previous rule.)
We would expect 8 total rooks (including the starting set) can always be placed without violating the rule.
View the attached picture for 2 valid final rook configurations.
  
Solution should include:

- Pick any programming language.
- Unit tests
- Source Code
- README file
- Explains how to install/run.
- Sample input/output.

## Installation Instructions

1. Clone this repository onto local device
2. Get the catch c++ testing framework: 
```
curl https://raw.githubusercontent.com/catchorg/Catch2/master/single_include/catch2/catch.hpp --ouput catch.hpp
```
3. Compile the two programs: 
```
g++ -std=c++11 -o nextRook main.cpp sol.cpp
```
```
g++ -std=c++11 -o testCases test.cpp sol.cpp
```

## Usage Instructions
### Input
The program takes in a parameter as an input text file. The text file is structured such that the first line contains a single integer _n_ - the number of rook placement scenarios. Each of the following lines represent a single scenario to be calculated, where the placements of the rooks are represented in the line with standard [Chess Algebraic Notation](https://en.wikipedia.org/wiki/Algebraic_notation_(chess)), each placement optionally separated with a space. 
### Output
The program outputs the results into a file called `output.txt`, with the position of the rook to be placed represented in the same notation. Each rook placement for each scenario given is represented in a new line. If the program encounters a syntax error for the input file, it will notify the user and shutdown. If the program cannot calculate a certain scenario, xx will be printed for the output. 

### Example 
Input:
```
3

a1 b7 c2 d3 e4 g6 f5

c1d2e6

a3 b4
```
Output:
```
h8
a3
c1
```

### Testing
General testing can be run after compiling the testCases program. All the unit tests are included in the `test.cpp` file.
