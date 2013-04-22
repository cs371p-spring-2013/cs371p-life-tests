// -------------------------
// projects/life/RunLife.c++
// Copyright (C) 2013
// Glenn P. Downing
// -------------------------

/*
To run the program:
    % make RunLife
    % make run

To configure Doxygen:
    doxygen -g
That creates the file Doxyfile.
Make the following edits:
    EXTRACT_ALL            = YES
    EXTRACT_PRIVATE        = YES
    EXTRACT_STATIC         = YES
    GENERATE_LATEX         = NO

To document the program:
    doxygen Doxyfile
*/

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>

#define private public
#define protected public
#include "Life.h"

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    // ------------------
    // Conway Cell 109x69
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 109x69 ***" << endl;

		// read RunLifeConway.in // assume all Conway cells
		ifstream ifs;
		ifs.open("RunLifeConway.in", ifstream::in);

		char inp[256];
		ifs.getline(inp, 256);
		int numRows = atoi (inp);	// 109
		ifs.getline(inp, 256);	
		int numCols = atoi (inp);	// 69

        Life<ConwayCell> l(numRows, numCols);

		char c = ifs.get();
		int i = 0;
		int j = 0;
		while(ifs.good() && (i < numRows) && (j < numCols))
		{
			switch (c) {
				case '.' :
					l.populateBoard(i, j, ConwayCell(false));
					break;
				case '*' :
					l.populateBoard(i, j, ConwayCell(true));
					break;
				default :
					cout << "ConwayCell not dead or alive? - char: " << c << "(i, j) = " << i << " " << j << endl;			
			}
			++j;	// increment column
			
			c = ifs.get();	// to move to next character

			if (c == '\n') {	// when reach end of column,
				c = ifs.get();	// get next character
				j = 0;			// set column back to zero
				++i;			// and increment row
			}
		}
		l.printBoard(cout);
		
        // Simulate 283 moves.
        // Print the first 10 grids (i.e. 0, 1, 2...9).
        // Print the 283rd grid.
		int max = 283;
		for (i = 0; i < max; ++i) {
			l.doGeneration();
			if (i < 10)
				l.printBoard(cout);
		}
		l.printBoard(cout);

        // Simulate 40 moves.
        // Print the 323rd grid.
		max = 40;
		for (i = 0; i < max; ++i)
			l.doGeneration();
		l.printBoard(cout);

        // Simulate 2177 moves.
        // Print the 2500th grid.
		max = 2177;
		for (i = 0; i < max; ++i)
			l.doGeneration();
		l.printBoard(cout);
        
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
        
        // read RunLifeFredkin.in // assume all Fredkin cells
		ifstream ifs;
		ifs.open("RunLifeFredkin.in", ifstream::in);

		char inp[256];
		ifs.getline(inp, 256);
		int numRows = atoi (inp);	// 20
		ifs.getline(inp, 256);	
		int numCols = atoi (inp);	// 20

        Life<FredkinCell> l(numRows, numCols);

		char c = ifs.get();
		int i = 0;
		int j = 0;
		while(ifs.good() && (i < numRows) && (j < numCols))
		{
			switch (c) {
				case '-' :
					l.populateBoard(i, j, FredkinCell(false));
					break;
				case '0' :
					l.populateBoard(i, j, FredkinCell(true));
					break;
				default :
					cout << "FredkinCell not dead or alive? - char: " << c << "(i, j) = " << i << " " << j << endl;			
			}
			++j;	// increment column
			
			c = ifs.get();	// to move to next character

			if (c == '\n') {	// when reach end of column,
				c = ifs.get();	// get next character
				j = 0;			// set column back to zero
				++i;			// and increment row
			}
		}
		l.printBoard(cout);

        // Simulate 5 moves.
        // Print every grid (i.e. 0, 1, 2...5)
		int max = 5;
		for (i = 0; i < max; ++i) {
			l.doGeneration();
			l.printBoard(cout);
		}
        
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 20x20
    // ----------

    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;
        
        // read RunLifeCell.in // assume all Fredkin cells
		ifstream ifs;
		ifs.open("RunLifeCell.in", ifstream::in);

		char inp[256];
		ifs.getline(inp, 256);
		int numRows = atoi (inp);	// 20
		ifs.getline(inp, 256);	
		int numCols = atoi (inp);	// 20

        Life<Cell> l(numRows, numCols);

		char c = ifs.get();
		int i = 0;
		int j = 0;
		while(ifs.good() && (i < numRows) && (j < numCols))
		{
			switch (c) {
				case '-' :
					l.populateBoard(i, j, new FredkinCell(false));
					break;
				case '0' :
					l.populateBoard(i, j, new FredkinCell(true));
					break;
				default :
					cout << "Cell not dead or alive? - char: " << c << "(i, j) = " << i << " " << j << endl;			
			}
			++j;	// increment column
			
			c = ifs.get();	// to move to next character

			if (c == '\n') {	// when reach end of column,
				c = ifs.get();	// get next character
				j = 0;			// set column back to zero
				++i;			// and increment row
			}
		}
		l.printBoard(cout);

        // Simulate 5 moves.
        // Print every grid (i.e. 0, 1, 2...5)
		int max = 5;
		for (i = 0; i < max; ++i) {
			l.doGeneration(true);	// need to call the mutatable doGeneration
			l.printBoard(cout);
		}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


//----Student added tests----
    // ------------------
    // ConwayCell 1 3x3
    // ------------------
	try {
        cout << "*** Life<ConwayCell> 3x3 ***" << endl;

		string conwayInput = "3\n3\n";
		conwayInput += "...\n";
		conwayInput += ".*.\n";
		conwayInput += "...\n\n";
		istringstream in (conwayInput);

		// read our string // assume all Conway cells
		int numRows;	
		int numCols;
		in >> numRows;
		in >> numCols;

        Life<ConwayCell> l(numRows, numCols);

		char c;
		in >> c;
		int i = 0;
		int j = 0;
		while((i < numRows) && (j < numCols))
		{
			switch (c) {
				case '.' :
					l.populateBoard(i, j, ConwayCell(false));
					break;
				case '*' :
					l.populateBoard(i, j, ConwayCell(true));
					break;
				default :
					cout << "ConwayCell not dead or alive? - char: " << c << "(i, j) = " << i << " " << j << endl;			
			}
			++j;	// increment column
			
			in >> c; // move to next character

			if (j >= numCols) {	// when reach end of column,
				j = 0;			// set column back to zero
				++i;			// and increment row
			}
		}
		l.printBoard(cout);
		
        // Simulate 3 moves, Print every grid.
		int max = 3;
		for (i = 0; i < max; ++i) {
			l.doGeneration();
			l.printBoard(cout);
		}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // ConwayCell 2 3x3
    // ------------------
	try {
        cout << "*** Life<ConwayCell> 3x3 ***" << endl;

		string conwayInput = "3\n3\n";
		conwayInput += "***\n";
		conwayInput += "***\n";
		conwayInput += "***\n\n";
		istringstream in (conwayInput);

		// read our string // assume all Conway cells
		int numRows;	
		int numCols;
		in >> numRows;
		in >> numCols;

        Life<ConwayCell> l(numRows, numCols);

		char c;
		in >> c;
		int i = 0;
		int j = 0;
		while((i < numRows) && (j < numCols))
		{
			switch (c) {
				case '.' :
					l.populateBoard(i, j, ConwayCell(false));
					break;
				case '*' :
					l.populateBoard(i, j, ConwayCell(true));
					break;
				default :
					cout << "ConwayCell not dead or alive? - char: " << c << "(i, j) = " << i << " " << j << endl;			
			}
			++j;	// increment column
			
			in >> c; // move to next character

			if (j >= numCols) {	// when reach end of column,
				j = 0;			// set column back to zero
				++i;			// and increment row
			}
		}
		l.printBoard(cout);
		
        // Simulate 3 moves, Print every grid.
		int max = 3;
		for (i = 0; i < max; ++i) {
			l.doGeneration();
			l.printBoard(cout);
		}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    

    // ------------------
    // ConwayCell 3 5x5
    // ------------------
	try {
        cout << "*** Life<ConwayCell> 5x5 ***" << endl;

		string conwayInput = "5\n5\n";
		conwayInput += "*****\n";
		conwayInput += "*****\n";
		conwayInput += "*****\n";
		conwayInput += "*****\n";
		conwayInput += "*****\n\n";
		istringstream in (conwayInput);

		// read our string // assume all Conway cells
		int numRows;	
		int numCols;
		in >> numRows;
		in >> numCols;

        Life<ConwayCell> l(numRows, numCols);

		char c;
		in >> c;
		int i = 0;
		int j = 0;
		while((i < numRows) && (j < numCols))
		{
			switch (c) {
				case '.' :
					l.populateBoard(i, j, ConwayCell(false));
					break;
				case '*' :
					l.populateBoard(i, j, ConwayCell(true));
					break;
				default :
					cout << "ConwayCell not dead or alive? - char: " << c << "(i, j) = " << i << " " << j << endl;			
			}
			++j;	// increment column
			
			in >> c; // move to next character

			if (j >= numCols) {	// when reach end of column,
				j = 0;			// set column back to zero
				++i;			// and increment row
			}
		}
		l.printBoard(cout);
		
        // Simulate 5 moves, Print every grid.
		int max = 5;
		for (i = 0; i < max; ++i) {
			l.doGeneration();
			l.printBoard(cout);
		}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // ConwayCell 4 5x5
    // ------------------
	try {
        cout << "*** Life<ConwayCell> 5x5 ***" << endl;

		string conwayInput = "5\n5\n";
		conwayInput += "*...*\n";
		conwayInput += ".*.*.\n";
		conwayInput += "..*..\n";
		conwayInput += ".*.*.\n";
		conwayInput += "*...*\n\n";
		istringstream in (conwayInput);

		// read our string // assume all Conway cells
		int numRows;	
		int numCols;
		in >> numRows;
		in >> numCols;

        Life<ConwayCell> l(numRows, numCols);

		char c;
		in >> c;
		int i = 0;
		int j = 0;
		while((i < numRows) && (j < numCols))
		{
			switch (c) {
				case '.' :
					l.populateBoard(i, j, ConwayCell(false));
					break;
				case '*' :
					l.populateBoard(i, j, ConwayCell(true));
					break;
				default :
					cout << "ConwayCell not dead or alive? - char: " << c << "(i, j) = " << i << " " << j << endl;			
			}
			++j;	// increment column
			
			in >> c; // move to next character

			if (j >= numCols) {	// when reach end of column,
				j = 0;			// set column back to zero
				++i;			// and increment row
			}
		}
		l.printBoard(cout);
		
        // Simulate 10 moves, Print every grid.
		int max = 10;
		for (i = 0; i < max; ++i) {
			l.doGeneration();
			l.printBoard(cout);
		}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // ConwayCell 5 8x10
    // ------------------
	try {
        cout << "*** Life<ConwayCell> 8x10 ***" << endl;

		string conwayInput = "8\n10\n";
		conwayInput += ".*.*.*.*\n";
		conwayInput += ".*.*...*\n";
		conwayInput += ".*.*..*.\n";
		conwayInput += ".*.*.*.*\n";
		conwayInput += "..*.**..\n";
		conwayInput += "**.*.*.*\n";
		conwayInput += ".*.*.*.*\n";
		conwayInput += ".*.**..*\n";
		conwayInput += ".*.*.*.*\n";
		conwayInput += "**..*..*\n\n";
		istringstream in (conwayInput);

		// read our string // assume all Conway cells
		int numRows;	
		int numCols;
		in >> numRows;
		in >> numCols;

        Life<ConwayCell> l(numRows, numCols);

		char c;
		in >> c;
		int i = 0;
		int j = 0;
		while((i < numRows) && (j < numCols))
		{
			switch (c) {
				case '.' :
					l.populateBoard(i, j, ConwayCell(false));
					break;
				case '*' :
					l.populateBoard(i, j, ConwayCell(true));
					break;
				default :
					cout << "ConwayCell not dead or alive? - char: " << c << "(i, j) = " << i << " " << j << endl;			
			}
			++j;	// increment column
			
			in >> c; // move to next character

			if (j >= numCols) {	// when reach end of column,
				j = 0;			// set column back to zero
				++i;			// and increment row
			}
		}
		l.printBoard(cout);
		
        // Simulate 10 moves, Print every grid.
		int max = 10;
		for (i = 0; i < max; ++i) {
			l.doGeneration();
			l.printBoard(cout);
		}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // Fredkin Cell 1 5x5
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 5x5 ***" << endl;
        string input = "5\n5\n";
		input += "0---0\n";
		input += "-0-0-\n";
		input += "--0--\n";
		input += "-0-0-\n";
		input += "0---0\n\n";
		istringstream in (input);

        // read our string, assume all Fredkin cells
		int numRows;	
		int numCols;
		in >> numRows;
		in >> numCols;

        Life<FredkinCell> l(numRows, numCols);

		char c;
		in >> c;
		int i = 0;
		int j = 0;
		while((i < numRows) && (j < numCols))
		{
			switch (c) {
				case '-' :
					l.populateBoard(i, j, FredkinCell(false));
					break;
				case '0' :
					l.populateBoard(i, j, FredkinCell(true));
					break;
				default :
					cout << "FredkinCell not dead or alive? - char: " << c << "(i, j) = " << i << " " << j << endl;			
			}
			++j;	// increment column
			
			in >> c; // move to next character

			if (j >= numCols) {	// when reach end of column,
				j = 0;			// set column back to zero
				++i;			// and increment row
			}
		}
		l.printBoard(cout);
		
        // Simulate 10 moves, Print every grid.
		int max = 10;
		for (i = 0; i < max; ++i) {
			l.doGeneration();
			l.printBoard(cout);
		}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // Fredkin Cell 2 4x4
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 4x4 ***" << endl;
        string input = "4\n4\n";
		input += "-0-0\n";
		input += "0-0-\n";
		input += "-0-0\n";
		input += "0-0-\n\n";
		istringstream in (input);

        // read our string, assume all Fredkin cells
		int numRows;	
		int numCols;
		in >> numRows;
		in >> numCols;

        Life<FredkinCell> l(numRows, numCols);

		char c;
		in >> c;
		int i = 0;
		int j = 0;
		while((i < numRows) && (j < numCols))
		{
			switch (c) {
				case '-' :
					l.populateBoard(i, j, FredkinCell(false));
					break;
				case '0' :
					l.populateBoard(i, j, FredkinCell(true));
					break;
				default :
					cout << "FredkinCell not dead or alive? - char: " << c << "(i, j) = " << i << " " << j << endl;			
			}
			++j;	// increment column
			
			in >> c; // move to next character

			if (j >= numCols) {	// when reach end of column,
				j = 0;			// set column back to zero
				++i;			// and increment row
			}
		}
		l.printBoard(cout);
		
        // Simulate 10 moves, Print every grid.
		int max = 10;
		for (i = 0; i < max; ++i) {
			l.doGeneration();
			l.printBoard(cout);
		}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // Fredkin Cell 3 3x3
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 3x3 ***" << endl;
        string input = "3\n3\n";
		input += "---\n";
		input += "-00\n";
		input += "---\n\n";
		istringstream in (input);

        // read our string, assume all Fredkin cells
		int numRows;	
		int numCols;
		in >> numRows;
		in >> numCols;

        Life<FredkinCell> l(numRows, numCols);

		char c;
		in >> c;
		int i = 0;
		int j = 0;
		while((i < numRows) && (j < numCols))
		{
			switch (c) {
				case '-' :
					l.populateBoard(i, j, FredkinCell(false));
					break;
				case '0' :
					l.populateBoard(i, j, FredkinCell(true));
					break;
				default :
					cout << "FredkinCell not dead or alive? - char: " << c << "(i, j) = " << i << " " << j << endl;			
			}
			++j;	// increment column
			
			in >> c; // move to next character

			if (j >= numCols) {	// when reach end of column,
				j = 0;			// set column back to zero
				++i;			// and increment row
			}
		}
		l.printBoard(cout);
		
        // Simulate 3 moves, Print every grid.
		int max = 3;
		for (i = 0; i < max; ++i) {
			l.doGeneration();
			l.printBoard(cout);
		}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // Fredkin Cell 4 3x3
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 3x3 ***" << endl;
        string input = "3\n3\n";
		input += "--0\n";
		input += "000\n";
		input += "-0-\n\n";
		istringstream in (input);

        // read our string, assume all Fredkin cells
		int numRows;	
		int numCols;
		in >> numRows;
		in >> numCols;

        Life<FredkinCell> l(numRows, numCols);

		char c;
		in >> c;
		int i = 0;
		int j = 0;
		while((i < numRows) && (j < numCols))
		{
			switch (c) {
				case '-' :
					l.populateBoard(i, j, FredkinCell(false));
					break;
				case '0' :
					l.populateBoard(i, j, FredkinCell(true));
					break;
				default :
					cout << "FredkinCell not dead or alive? - char: " << c << "(i, j) = " << i << " " << j << endl;			
			}
			++j;	// increment column
			
			in >> c; // move to next character

			if (j >= numCols) {	// when reach end of column,
				j = 0;			// set column back to zero
				++i;			// and increment row
			}
		}
		l.printBoard(cout);
		
        // Simulate 3 moves, Print every grid.
		int max = 3;
		for (i = 0; i < max; ++i) {
			l.doGeneration();
			l.printBoard(cout);
		}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // Fredkin Cell 5 10x7
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 10x7 ***" << endl;
        string input = "10\n7\n";
		input += "000----\n";
		input += "--0-0-0\n";
		input += "-00-0-0\n";
		input += "0-0-0--\n";
		input += "--00-0-\n";
		input += "-0-0-0-\n";
		input += "0--00--\n";
		input += "00-0-0-\n";
		input += "0-0--0-\n";
		input += "-0--0--\n\n";
		istringstream in (input);

        // read our string, assume all Fredkin cells
		int numRows;	
		int numCols;
		in >> numRows;
		in >> numCols;

        Life<FredkinCell> l(numRows, numCols);

		char c;
		in >> c;
		int i = 0;
		int j = 0;
		while((i < numRows) && (j < numCols))
		{
			switch (c) {
				case '-' :
					l.populateBoard(i, j, FredkinCell(false));
					break;
				case '0' :
					l.populateBoard(i, j, FredkinCell(true));
					break;
				default :
					cout << "FredkinCell not dead or alive? - char: " << c << "(i, j) = " << i << " " << j << endl;			
			}
			++j;	// increment column
			
			in >> c; // move to next character

			if (j >= numCols) {	// when reach end of column,
				j = 0;			// set column back to zero
				++i;			// and increment row
			}
		}
		l.printBoard(cout);
		
        // Simulate 20 moves, Print every grid.
		int max = 20;
		for (i = 0; i < max; ++i) {
			l.doGeneration();
			l.printBoard(cout);
		}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // Cell 1 10x7
    // ------------------

    try {
        cout << "*** Life<Cell> 10x7 ***" << endl;
        string input = "10\n7\n";
		input += "000----\n";
		input += "--0-0-0\n";
		input += "-00-0-0\n";
		input += "0-0-0--\n";
		input += "--00-0-\n";
		input += "-0-0-0-\n";
		input += "0--00--\n";
		input += "00-0-0-\n";
		input += "0-0--0-\n";
		input += "-0--0--\n\n";
		istringstream in (input);

        // read our string, assume all Fredkin cells
		int numRows;	
		int numCols;
		in >> numRows;
		in >> numCols;

        Life<Cell> l(numRows, numCols);

		char c;
		in >> c;
		int i = 0;
		int j = 0;
		while((i < numRows) && (j < numCols))
		{
			switch (c) {
				case '-' :
					l.populateBoard(i, j, new FredkinCell(false));
					break;
				case '0' :
					l.populateBoard(i, j, new FredkinCell(true));
					break;
				default :
					cout << "FredkinCell not dead or alive? - char: " << c << "(i, j) = " << i << " " << j << endl;			
			}
			++j;	// increment column
			
			in >> c; // move to next character

			if (j >= numCols) {	// when reach end of column,
				j = 0;			// set column back to zero
				++i;			// and increment row
			}
		}
		l.printBoard(cout);
		
        // Simulate 20 moves, Print every grid.
		int max = 20;
		for (i = 0; i < max; ++i) {
			l.doGeneration(true);	// so Fredkin can mutate
			l.printBoard(cout);
		}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // Cell 2 7x7
    // ------------------

    try {
        cout << "*** Life<Cell> 7x7 ***" << endl;
        string input = "7\n7\n";
		input += "---00--\n";
		input += "-00-0--\n";
		input += "00-000-\n";
		input += "0-0-0-0\n";
		input += "-000-00\n";
		input += "--0-0--\n";
		input += "-0000--\n\n";
		istringstream in (input);

        // read our string, assume all Fredkin cells
		int numRows;	
		int numCols;
		in >> numRows;
		in >> numCols;

        Life<Cell> l(numRows, numCols);

		char c;
		in >> c;
		int i = 0;
		int j = 0;
		while((i < numRows) && (j < numCols))
		{
			switch (c) {
				case '-' :
					l.populateBoard(i, j, new FredkinCell(false));
					break;
				case '0' :
					l.populateBoard(i, j, new FredkinCell(true));
					break;
				default :
					cout << "FredkinCell not dead or alive? - char: " << c << "(i, j) = " << i << " " << j << endl;			
			}
			++j;	// increment column
			
			in >> c; // move to next character

			if (j >= numCols) {	// when reach end of column,
				j = 0;			// set column back to zero
				++i;			// and increment row
			}
		}
		l.printBoard(cout);
		
        // Simulate 20 moves, Print every grid.
		int max = 20;
		for (i = 0; i < max; ++i) {
			l.doGeneration(true);	// so Fredkin can mutate
			l.printBoard(cout);
		}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // Cell 3 30x30
    // ------------------

    try {
        cout << "*** Life<Cell> 30x30 ***" << endl;
        string input = "30\n30\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n";
		input += "---0----0----0----0----0----0-\n\n";
		istringstream in (input);

        // read our string, assume all Fredkin cells
		int numRows;	
		int numCols;
		in >> numRows;
		in >> numCols;

        Life<Cell> l(numRows, numCols);

		char c;
		in >> c;
		int i = 0;
		int j = 0;
		while((i < numRows) && (j < numCols))
		{
			switch (c) {
				case '-' :
					l.populateBoard(i, j, new FredkinCell(false));
					break;
				case '0' :
					l.populateBoard(i, j, new FredkinCell(true));
					break;
				default :
					cout << "FredkinCell not dead or alive? - char: " << c << "(i, j) = " << i << " " << j << endl;			
			}
			++j;	// increment column
			
			in >> c; // move to next character

			if (j >= numCols) {	// when reach end of column,
				j = 0;			// set column back to zero
				++i;			// and increment row
			}
		}
		l.printBoard(cout);
		
        // Simulate 20 moves, Print every grid.
		int max = 20;
		for (i = 0; i < max; ++i) {
			l.doGeneration(true);	// so Fredkin can mutate
			l.printBoard(cout);
		}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // Cell 4 30x30
    // ------------------

    try {
        cout << "*** Life<Cell> 30x30 ***" << endl;
        string input = "30\n30\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------0000--------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n\n";
		istringstream in (input);

        // read our string, assume all Fredkin cells
		int numRows;	
		int numCols;
		in >> numRows;
		in >> numCols;

        Life<Cell> l(numRows, numCols);

		char c;
		in >> c;
		int i = 0;
		int j = 0;
		while((i < numRows) && (j < numCols))
		{
			switch (c) {
				case '-' :
					l.populateBoard(i, j, new FredkinCell(false));
					break;
				case '0' :
					l.populateBoard(i, j, new FredkinCell(true));
					break;
				default :
					cout << "FredkinCell not dead or alive? - char: " << c << "(i, j) = " << i << " " << j << endl;			
			}
			++j;	// increment column
			
			in >> c; // move to next character

			if (j >= numCols) {	// when reach end of column,
				j = 0;			// set column back to zero
				++i;			// and increment row
			}
		}
		l.printBoard(cout);
		
        // Simulate 20 moves, Print every grid.
		int max = 20;
		for (i = 0; i < max; ++i) {
			l.doGeneration(true);	// so Fredkin can mutate
			l.printBoard(cout);
		}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // Cell 5 30x30
    // ------------------

    try {
        cout << "*** Life<Cell> 30x30 ***" << endl;
        string input = "20\n30\n";
		input += "00----------------------------\n";
		input += "00----------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n";
		input += "------------------------------\n\n";
		istringstream in (input);

        // read our string, assume all Fredkin cells
		int numRows;	
		int numCols;
		in >> numRows;
		in >> numCols;

        Life<Cell> l(numRows, numCols);

		char c;
		in >> c;
		int i = 0;
		int j = 0;
		while((i < numRows) && (j < numCols))
		{
			switch (c) {
				case '-' :
					l.populateBoard(i, j, new FredkinCell(false));
					break;
				case '0' :
					l.populateBoard(i, j, new FredkinCell(true));
					break;
				default :
					cout << "FredkinCell not dead or alive? - char: " << c << "(i, j) = " << i << " " << j << endl;			
			}
			++j;	// increment column
			
			in >> c; // move to next character

			if (j >= numCols) {	// when reach end of column,
				j = 0;			// set column back to zero
				++i;			// and increment row
			}
		}
		l.printBoard(cout);
		
        // Simulate 100 moves, Print every grid.
		int max = 100;
		for (i = 0; i < max; ++i) {
			l.doGeneration(true);	// so Fredkin can mutate
			l.printBoard(cout);
		}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}


