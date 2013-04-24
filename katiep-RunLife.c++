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
	EXTRACT_ALL = YES
	EXTRACT_PRIVATE = YES
	EXTRACT_STATIC = YES
	GENERATE_LATEX = NO

To document the program:
	doxygen Doxyfile
*/

// --------
// includes
// --------

#include <cassert> // assert
#include <iostream> // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include <string>
#include <fstream>
#include <sstream>

//#define private public

#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Handle.h"
#include "Cell.h"
#include "Life.h"

// ----
// main
// ----

int main () {
	using namespace std;
	ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

// -----------
// -----------
// GIVEN TESTS
// -----------
// -----------
	
	// ------------------
	// Conway Cell 109x69
	// ------------------
	
	try {
		cout << "*** Life<ConwayCell> 109x69 ***" << endl << endl;
		/*
		read RunLifeConway.in // assume all Conway cells
		Simulate 283 moves.
		Print the first 10 grids (i.e. 0, 1, 2...9).
		Print the 283rd grid.
		Simulate 40 moves.
		Print the 323rd grid.
		Simulate 2177 moves.
		Print the 2500th grid.
		*/
		
		ifstream in("RunLifeConway.in");
		
		// get height and width
		int height, width;
		in >> height >> width;
		
		// create life
		Life<ConwayCell> life(height, width);
		
		// read in rest of file and set board
		char cell;
		for (int r = 0; r < height; r++) {
			for (int c = 0; c < width; c++) {
				in >> cell;
				if (cell == '*') {
					life.add_cell(r, c, CONWAY, true);
				}
			}
		}

		// simulate 283 moves
		// print the first 10 grids and the 283rd grid
		int move = 0;
		for (; move < 10; move++) {
			life.print(cout);
			life.turn();
		}
		for (; move < 283; move++) {
			life.turn();
		}
		life.print(cout);
		
		// simulate 40 moves
		// print the 323rd grid
		for (; move < 323; move++) {
			life.turn();
		}
		life.print(cout);
		
		// simulate 2177 moves
		// print 2500th grid
		for (; move < 2500; move++) {
			life.turn();
		}
		life.print(cout);
		
	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// ------------------
	// Fredkin Cell 20x20
	// ------------------
	
	try {
		cout << "*** Life<FredkinCell> 20x20 ***" << endl << endl;
		/*
		read RunLifeFredkin.in // assume all Fredkin cells
		Simulate 5 moves.
		Print every grid (i.e. 0, 1, 2...5)
		*/
		
		ifstream in("RunLifeFredkin.in");
		
		// get height and width
		int height, width;
		in >> height >> width;
		
		// create life
		Life<FredkinCell> life(height, width);
		
		// read in rest of file and set board
		char cell;
		for (int r = 0; r < height; r++) {
			for (int c = 0; c < width; c++) {
				in >> cell;
				if (cell != '-') {
					life.add_cell(r, c, FREDKIN, true);
				}
			}
		}

		// simulate 5 moves
		// print every grid
		int move = 0;
		for (; move < 5; move++) {
			life.print(cout);
			life.turn();
		}
		life.print(cout);
		
	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// ----------
	// Cell 20x20
	// ----------
	
	try {
		cout << "*** Life<Cell> 20x20 ***" << endl << endl;
		/*
		read RunLifeCell.in // assume all Fredkin cells
		Simulate 5 moves.
		Print every grid (i.e. 0, 1, 2...5)
		*/
		
		ifstream in("RunLifeCell.in");
		
		// get height and width
		int height, width;
		in >> height >> width;
		
		// create life
		Life<Cell> life(height, width);
		
		// read in rest of file and set board
		char cell;
		for (int r = 0; r < height; r++) {
			for (int c = 0; c < width; c++) {
				in >> cell;
				if (cell == '.') {
					life.add_cell(r, c, CONWAY, false);
				} else if (cell == '*') {
					life.add_cell(r, c, CONWAY, true);
				} else if (cell == '-') {
					life.add_cell(r, c, FREDKIN, false);
				} else {
					life.add_cell(r, c, FREDKIN, true);
				}
			}
		}

		// simulate 5 moves
		// print every grid
		int move = 0;
		for (; move < 5; move++) {
			life.print(cout);
			life.turn();
		}
		life.print(cout);
		
	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}


// ----------------	
// ----------------
// ADDITIONAL TESTS
// ----------------
// ----------------
	
	// -------------------
	// 1 - Conway Cell 3x3
	// -------------------
	
	try {
		cout << "*** Life<ConwayCell> 3x3 ***" << endl << endl;
		
		// get height and width
		int height = 3;
		int width = 3;
		
		// create life
		Life<ConwayCell> life(height, width);
		
		// read in rest of file and set board
		life.add_cell(0, 0, CONWAY, true);
		life.add_cell(1, 1, CONWAY, true);
		life.add_cell(2, 2, CONWAY, true);
		
		// simulate moves
		int move = 0;
		for (; move < 5; move++) {
			life.print(cout);
			life.turn();
		}
		life.print(cout);
		
	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// -------------------
	// 2 - Conway Cell 8x8
	// -------------------
	
	try {
		cout << "*** Life<ConwayCell> 8x8 ***" << endl << endl;

		// dimensions
		int height = 8;
		int width = 8;

		// create life
		Life<ConwayCell> life(height, width);
		
		// set cells
		for(int i = 0; i < 7; ++i){
			life.add_cell(i, 3, CONWAY, true);
			life.add_cell(i + 1, 4, CONWAY, true);
		}

		// simulate moves
		int move = 0;
		for (; move < 5; move++) {
			life.print(cout);
			life.turn();
		}
		life.print(cout);
		
	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// ---------------------
	// 3 - Conway Cell 20x20
	// ---------------------
	
	try {
		cout << "*** Life<ConwayCell> 20x20 ***" << endl << endl;

		// dimensions
		int height = 20;
		int width = 20;

		// create life
		Life<ConwayCell> life(height, width);

		// set cells
		for(int r = 0; r < 20; r++) {
			for (int c = 0 ; c < 10; c++) {
				if (c % 2 == 0) {
					life.add_cell(r, c, CONWAY, true);
				}
			}
			if (r % 2 == 0){
				life.add_cell(r, 0, CONWAY, true);
			}
		}

		// simulate moves
		int move = 0;
		for (; move < 8; move++) {
			life.print(cout);
			life.turn();
		}
		life.print(cout);

	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// ---------------------
	// 4 - Conway Cell 50x50
	// ---------------------
	
	try {
		cout << "*** Life<ConwayCell> 50x50 ***" << endl << endl;

		// dimensions
		int height = 50;
		int width = 50;

		// create life
		Life<ConwayCell> life(height, width);

		// set cells
		for (int x = 5; x < 50; x+=5) {
			life.add_cell(x, x, CONWAY, true);
			life.add_cell(x-1, x, CONWAY, true);
			life.add_cell(x, x-1, CONWAY, true);
			life.add_cell(x+1, x, CONWAY, true);
			life.add_cell(x, x+1, CONWAY, true);
			
			life.add_cell(x, width-x, CONWAY, true);
			life.add_cell(x-1, width-x, CONWAY, true);
			life.add_cell(x, width-x-1, CONWAY, true);
			life.add_cell(x+1, width-x, CONWAY, true);
			life.add_cell(x, width-x+1, CONWAY, true);
		}

		// simulate moves
		int move = 0;
		for (; move < 10; move++) {
			life.print(cout);
			life.turn();
		}
		life.print(cout);

	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// -----------------------
	// 5 - Conway Cell 100x100
	// -----------------------
	
	try {
		cout << "*** Life<ConwayCell> 100x100 ***" << endl << endl;

		// dimensions
		int height = 100;
		int width = 100;

		// create life
		Life<ConwayCell> life(height, width);

		// set cells
		for (int c = 10; c < width; c+=10) {
			for (int i = 1; i < 10; i++) {
				for (int r = i*10; r < 9+i*10; r++) {
					life.add_cell(r, c, CONWAY, true);
				}
			}
		}

		// simulate 283 moves
		// print the first 10 grids and the 283rd grid
		int move = 0;
		for (; move < 10; move++) {
			life.print(cout);
			life.turn();
		}
		for (; move < 283; move++) {
			life.turn();
		}
		life.print(cout);
		
		// simulate 40 moves
		// print the 323rd grid
		for (; move < 323; move++) {
			life.turn();
		}
		life.print(cout);
		
		// simulate 2177 moves
		// print 2500th grid
		for (; move < 2500; move++) {
			life.turn();
		}
		life.print(cout);

	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// --------------------
	// 1 - Fredkin Cell 3x3
	// --------------------
	
	try {
		cout << "*** Life<FredkinCell> 3x3 ***" << endl << endl;

		// dimensions
		int height = 3;
		int width = 3;

		// create life
		Life<FredkinCell> life(height, width);
		
		// set cells
		life.add_cell(0, 0, FREDKIN, true);
		life.add_cell(0, 2, FREDKIN, true);
		life.add_cell(1, 1, FREDKIN, true);
		life.add_cell(2, 0, FREDKIN, true);
		life.add_cell(2, 2, FREDKIN, true);

		// simulate moves
		int move = 0;
		for (; move < 3; move++) {
			life.print(cout);
			life.turn();
		}
		life.print(cout);
		
	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// --------------------
	// 2 - Fredkin Cell 8x8
	// --------------------
	
	try {
		cout << "*** Life<FredkinCell> 8x8 ***" << endl << endl;

		// dimensions
		int height = 8;
		int width = 8;

		// create life
		Life<FredkinCell> life(height, width);
		
		// set cells
		for(int i = 0; i < 7; ++i){
			life.add_cell(i, 3, FREDKIN, true);
			life.add_cell(i + 1, 4, FREDKIN, true);
		}

		// simulate moves
		int move = 0;
		for (; move < 5; move++) {
			life.print(cout);
			life.turn();
		}
		life.print(cout);
		
	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// ---------------------
	// 3 - Fredkin Cell 20x20
	// ---------------------
	
	try {
		cout << "*** Life<FredkinCell> 20x20 ***" << endl << endl;

		// dimensions
		int height = 20;
		int width = 20;

		// create life
		Life<FredkinCell> life(height, width);

		// set cells
		for(int r = 0; r < 20; r++) {
			for (int c = 0 ; c < 10; c++) {
				if (c % 2 == 0) {
					life.add_cell(r, c, FREDKIN, true);
				}
			}
			if (r % 2 == 0){
				life.add_cell(r, 0, FREDKIN, true);
			}
		}

		// simulate moves
		int move = 0;
		for (; move < 8; move++) {
			life.print(cout);
			life.turn();
		}
		life.print(cout);

	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// ---------------------
	// 4 - Fredkin Cell 50x50
	// ---------------------
	
	try {
		cout << "*** Life<FredkinCell> 50x50 ***" << endl << endl;

		// dimensions
		int height = 50;
		int width = 50;

		// create life
		Life<FredkinCell> life(height, width);

		// set cells
		for (int x = 5; x < 50; x+=5) {
			life.add_cell(x, x, FREDKIN, true);
			life.add_cell(x-1, x, FREDKIN, true);
			life.add_cell(x, x-1, FREDKIN, true);
			life.add_cell(x+1, x, FREDKIN, true);
			life.add_cell(x, x+1, FREDKIN, true);
			
			life.add_cell(x, width-x, FREDKIN, true);
			life.add_cell(x-1, width-x, FREDKIN, true);
			life.add_cell(x, width-x-1, FREDKIN, true);
			life.add_cell(x+1, width-x, FREDKIN, true);
			life.add_cell(x, width-x+1, FREDKIN, true);
		}

		// simulate moves
		int move = 0;
		for (; move < 10; move++) {
			life.print(cout);
			life.turn();
		}
		life.print(cout);

	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// -----------------------
	// 5 - Fredkin Cell 100x100
	// -----------------------
	
	try {
		cout << "*** Life<FredkinCell> 100x100 ***" << endl << endl;

		// dimensions
		int height = 100;
		int width = 100;

		// create life
		Life<FredkinCell> life(height, width);

		// set cells
		for (int c = 10; c < width; c+=10) {
			for (int i = 1; i < 10; i++) {
				for (int r = i*10; r < 9+i*10; r++) {
					life.add_cell(r, c, FREDKIN, true);
				}
			}
		}

		// simulate 283 moves
		// print the first 10 grids and the 283rd grid
		int move = 0;
		for (; move < 10; move++) {
			life.print(cout);
			life.turn();
		}
		for (; move < 283; move++) {
			life.turn();
		}
		life.print(cout);
		
		// simulate 40 moves
		// print the 323rd grid
		for (; move < 323; move++) {
			life.turn();
		}
		life.print(cout);
		
		// simulate 2177 moves
		// print 2500th grid
		for (; move < 2500; move++) {
			life.turn();
		}
		life.print(cout);

	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// --------------------
	// 1 - Fredkin Cell 3x3
	// --------------------
	
	try {
		cout << "*** Life<Cell> 3x3 ***" << endl << endl;

		// dimensions
		int height = 3;
		int width = 3;

		// create life
		Life<Cell> life(height, width);
		
		// set cells
		for (int r = 0; r < height; r++) {
			for (int c = 0; c < width; c++) {
				life.add_cell(r, c, FREDKIN, false);
			}
		}
		life.add_cell(0, 0, FREDKIN, true);
		life.add_cell(0, 2, FREDKIN, true);
		life.add_cell(1, 1, FREDKIN, true);
		life.add_cell(2, 0, FREDKIN, true);
		life.add_cell(2, 2, FREDKIN, true);

		// simulate moves
		int move = 0;
		for (; move < 3; move++) {
			life.print(cout);
			life.turn();
		}
		life.print(cout);
		
	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// ------------
	// 2 - Cell 8x8
	// ------------
	
	try {
		cout << "*** Life<Cell> 8x8 ***" << endl << endl;

		// dimensions
		int height = 8;
		int width = 8;

		// create life
		Life<Cell> life(height, width);
		
		// set cells
		for (int r = 0; r < height; r++) {
			for (int c = 0; c < width; c++) {
				life.add_cell(r, c, FREDKIN, false);
			}
		}
		for(int i = 0; i < 7; i++){
			life.add_cell(i, 3, FREDKIN, true);
			life.add_cell(i + 1, 4, FREDKIN, true);
		}

		// simulate moves
		int move = 0;
		for (; move < 10; move++) {
			life.print(cout);
			life.turn();
		}
		life.print(cout);
		
	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// --------------
	// 3 - Cell 20x20
	// --------------
	
	try {
		cout << "*** Life<Cell> 20x20 ***" << endl << endl;

		// dimensions
		int height = 20;
		int width = 20;

		// create life
		Life<Cell> life(height, width);

		// set cells
		for (int r = 0; r < height; r++) {
			for (int c = 0; c < width; c++) {
				life.add_cell(r, c, FREDKIN, false);
			}
		}
		for(int r = 0; r < 20; r++) {
			for (int c = 0 ; c < 10; c++) {
				if (c % 2 == 0) {
					life.add_cell(r, c, FREDKIN, true);
				}
			}
			if (r % 2 == 0){
				life.add_cell(r, 0, FREDKIN, true);
			}
		}

		// simulate moves
		int move = 0;
		for (; move < 8; move++) {
			life.print(cout);
			life.turn();
		}
		life.print(cout);

	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// --------------
	// 4 - Cell 50x50
	// --------------
	
	try {
		cout << "*** Life<Cell> 50x50 ***" << endl << endl;

		// dimensions
		int height = 50;
		int width = 50;

		// create life
		Life<Cell> life(height, width);

		// set cells
		for (int r = 0; r < height; r++) {
			for (int c = 0; c < width; c++) {
				life.add_cell(r, c, FREDKIN, false);
			}
		}
		for (int x = 5; x < 50; x+=5) {
			life.add_cell(x, x, FREDKIN, true);
			life.add_cell(x-1, x, FREDKIN, true);
			life.add_cell(x, x-1, FREDKIN, true);
			life.add_cell(x+1, x, FREDKIN, true);
			life.add_cell(x, x+1, FREDKIN, true);
			
			life.add_cell(x, width-x, FREDKIN, true);
			life.add_cell(x-1, width-x, FREDKIN, true);
			life.add_cell(x, width-x-1, FREDKIN, true);
			life.add_cell(x+1, width-x, FREDKIN, true);
			life.add_cell(x, width-x+1, FREDKIN, true);
		}

		// simulate moves
		int move = 0;
		for (; move < 10; move++) {
			life.print(cout);
			life.turn();
		}
		life.print(cout);

	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	// ----------------
	// 5 - Cell 100x100
	// ----------------
	
	try {
		cout << "*** Life<Cell> 100x100 ***" << endl << endl;

		// dimensions
		int height = 100;
		int width = 100;

		// create life
		Life<Cell> life(height, width);

		// set cells
		for (int r = 0; r < height; r++) {
			for (int c = 0; c < width; c++) {
				life.add_cell(r, c, FREDKIN, false);
			}
		}
		for (int c = 10; c < width; c+=10) {
			for (int i = 1; i < 10; i++) {
				for (int r = i*10; r < 9+i*10; r++) {
					life.add_cell(r, c, FREDKIN, true);
				}
			}
		}

		// simulate 283 moves
		// print the first 10 grids and the 283rd grid
		int move = 0;
		for (; move < 10; move++) {
			life.print(cout);
			life.turn();
		}
		for (; move < 283; move++) {
			life.turn();
		}
		life.print(cout);
		
		// simulate 40 moves
		// print the 323rd grid
		for (; move < 323; move++) {
			life.turn();
		}
		life.print(cout);
		
		// simulate 2177 moves
		// print 2500th grid
		for (; move < 2500; move++) {
			life.turn();
		}
		life.print(cout);

	} catch (const invalid_argument&) {
		assert(false);
	} catch (const out_of_range&) {
		assert(false);
	}
	
	return 0;
}
