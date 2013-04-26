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
#include <fstream>
#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

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

		fstream fs("RunLifeConway.in");
		int rows, cols;
		char cellChar;
		fs >> rows;
		fs >> cols;
		Life<ConwayCell> grid(rows, cols, ConwayCell());
		int i,j;
		for(i=0; i<rows; i++)
			for(j=0; j<cols; j++) {
				fs >> cellChar;
				if(cellChar == '*')
					grid.putConway(ConwayCell(true), i, j);
			}
		int gen = 0;			
		//evolve 10 times, print before each evolution.
		cout << "Generation = " << gen << ", Population = " 
			<< grid.population() << "." << endl;
		cout << grid << endl;
		grid.evolve();
		
		for( i=1; i<10; ++i) {
			cout << "Generation = " << ++gen << ", Population = " 
				<< grid.population() << "." << endl;
			cout << grid << endl;
			grid.evolve();
        }

		//evolve 273 more times, then print
		for(i=0; i<273; ++i) {	
			grid.evolve();
			++gen;
		}

		cout << "Generation = " << ++gen << ", Population = " 
			<< grid.population() << "." << endl;
		cout << grid << endl;
		
		for(i=0; i<40; ++i) { 
			grid.evolve();
			++gen;
		}

		cout << "Generation = " << gen << ", Population = " 
			<< grid.population() << "." << endl;
		cout << grid << endl;
		
		for(i=0; i<2177; ++i) {
			grid.evolve();
			++gen;
		}

		cout << "Generation = " << gen << ", Population = " 
			<< grid.population() << "." << endl;
		cout << grid << endl; 

	}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Conway Cell 10x10
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 10x10 ***" << endl;
/*
Simulate 5 moves.
Print every grid (i.e. 0, 1, 2...5)
*/

		fstream fs("Conway1.in");
		int rows, cols;
		char cellChar;
		fs >> rows;
		fs >> cols;
		Life<Cell> grid(rows, cols, new FredkinCell(false));
		int i,j;
		for(i=0; i<rows; i++)
			for(j=0; j<cols; j++) {
				fs >> cellChar;
				if(cellChar == '0')
					grid.putCell(new FredkinCell(true), i, j);
			}
		for(i=0; i<=5; i++) {
			cout << "Generation = " << i << ", Population = " 
				<< grid.population() << "." << endl;
			cout << grid << endl;
			grid.evolve();
		}

	}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Conway Cell 3x3
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 3x3 ***" << endl;
/*
Simulate 5 moves.
Print every grid (i.e. 0, 1, 2...5)
*/

		fstream fs("Conway2.in");
		int rows, cols;
		char cellChar;
		fs >> rows;
		fs >> cols;
		Life<Cell> grid(rows, cols, new FredkinCell(false));
		int i,j;
		for(i=0; i<rows; i++)
			for(j=0; j<cols; j++) {
				fs >> cellChar;
				if(cellChar == '0')
					grid.putCell(new FredkinCell(true), i, j);
			}
		for(i=0; i<=5; i++) {
			cout << "Generation = " << i << ", Population = " 
				<< grid.population() << "." << endl;
			cout << grid << endl;
			grid.evolve();
		}

	}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Conway Cell 6x6
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 6x6 ***" << endl;
/*
Simulate 5 moves.
Print every grid (i.e. 0, 1, 2...5)
*/

		fstream fs("Conway3.in");
		int rows, cols;
		char cellChar;
		fs >> rows;
		fs >> cols;
		Life<Cell> grid(rows, cols, new FredkinCell(false));
		int i,j;
		for(i=0; i<rows; i++)
			for(j=0; j<cols; j++) {
				fs >> cellChar;
				if(cellChar == '0')
					grid.putCell(new FredkinCell(true), i, j);
			}
		for(i=0; i<=5; i++) {
			cout << "Generation = " << i << ", Population = " 
				<< grid.population() << "." << endl;
			cout << grid << endl;
			grid.evolve();
		}

	}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Conway Cell 9x9
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 9x9 ***" << endl;
/*
Simulate 5 moves.
Print every grid (i.e. 0, 1, 2...5)
*/

		fstream fs("Conway4.in");
		int rows, cols;
		char cellChar;
		fs >> rows;
		fs >> cols;
		Life<Cell> grid(rows, cols, new FredkinCell(false));
		int i,j;
		for(i=0; i<rows; i++)
			for(j=0; j<cols; j++) {
				fs >> cellChar;
				if(cellChar == '0')
					grid.putCell(new FredkinCell(true), i, j);
			}
		for(i=0; i<=5; i++) {
			cout << "Generation = " << i << ", Population = " 
				<< grid.population() << "." << endl;
			cout << grid << endl;
			grid.evolve();
		}

	}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 4x4
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 4x4 ***" << endl;
/*
Simulate 5 moves.
Print every grid (i.e. 0, 1, 2...5)
*/

		fstream fs("Fredkin1.in");
		int rows, cols;
		char cellChar;
		fs >> rows;
		fs >> cols;
		Life<Cell> grid(rows, cols, new FredkinCell(false));
		int i,j;
		for(i=0; i<rows; i++)
			for(j=0; j<cols; j++) {
				fs >> cellChar;
				if(cellChar == '0')
					grid.putCell(new FredkinCell(true), i, j);
			}
		for(i=0; i<=5; i++) {
			cout << "Generation = " << i << ", Population = " 
				<< grid.population() << "." << endl;
			cout << grid << endl;
			grid.evolve();
		}

	}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 12x12
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 12x12 ***" << endl;
/*
Simulate 5 moves.
Print every grid (i.e. 0, 1, 2...5)
*/

		fstream fs("Fredkin2.in");
		int rows, cols;
		char cellChar;
		fs >> rows;
		fs >> cols;
		Life<Cell> grid(rows, cols, new FredkinCell(false));
		int i,j;
		for(i=0; i<rows; i++)
			for(j=0; j<cols; j++) {
				fs >> cellChar;
				if(cellChar == '0')
					grid.putCell(new FredkinCell(true), i, j);
			}
		for(i=0; i<=5; i++) {
			cout << "Generation = " << i << ", Population = " 
				<< grid.population() << "." << endl;
			cout << grid << endl;
			grid.evolve();
		}

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
        /*
read RunLifeFredkin.in // assume all Fredkin cells
Simulate 5 moves.
Print every grid (i.e. 0, 1, 2...5)
*/

		fstream fs("RunLifeFredkin.in");
		int rows, cols;
		char cellChar;
		fs >> rows;
		fs >> cols;
		Life<FredkinCell> grid(rows, cols, FredkinCell());
		int i,j;
		for(i=0; i<rows; i++)
			for(j=0; j<cols; j++) {
				fs >> cellChar;
				if(cellChar == '0')
					grid.putFredkin(FredkinCell(true), i, j);
			}
		cout << "Generation = 0, Population = " << grid.population()
			<< "." << endl;
		cout << grid << endl;
		for(i=0; i<5; i++) {
			grid.evolve();
			cout << "Generation = " << i+1 << ", Population = " 
				<< grid.population() << "." << endl;
			cout << grid << endl;	
		}


	}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 6x6
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 6x6 ***" << endl;
        /*
read RunLifeFredkin.in // assume all Fredkin cells
Simulate 5 moves.
Print every grid (i.e. 0, 1, 2...5)
*/

		fstream fs("Fredkin3.in");
		int rows, cols;
		char cellChar;
		fs >> rows;
		fs >> cols;
		Life<FredkinCell> grid(rows, cols, FredkinCell());
		int i,j;
		for(i=0; i<rows; i++)
			for(j=0; j<cols; j++) {
				fs >> cellChar;
				if(cellChar == '0')
					grid.putFredkin(FredkinCell(true), i, j);
			}
		cout << "Generation = 0, Population = " << grid.population()
			<< "." << endl;
		cout << grid << endl;
		for(i=0; i<5; i++) {
			grid.evolve();
			cout << "Generation = " << i+1 << ", Population = " 
				<< grid.population() << "." << endl;
			cout << grid << endl;	
		}


	}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 5x5
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 5x5 ***" << endl;
        /*
read RunLifeFredkin.in // assume all Fredkin cells
Simulate 5 moves.
Print every grid (i.e. 0, 1, 2...5)
*/

		fstream fs("Fredkin4.in");
		int rows, cols;
		char cellChar;
		fs >> rows;
		fs >> cols;
		Life<FredkinCell> grid(rows, cols, FredkinCell());
		int i,j;
		for(i=0; i<rows; i++)
			for(j=0; j<cols; j++) {
				fs >> cellChar;
				if(cellChar == '0')
					grid.putFredkin(FredkinCell(true), i, j);
			}
		cout << "Generation = 0, Population = " << grid.population()
			<< "." << endl;
		cout << grid << endl;
		for(i=0; i<5; i++) {
			grid.evolve();
			cout << "Generation = " << i+1 << ", Population = " 
				<< grid.population() << "." << endl;
			cout << grid << endl;	
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
        /*
read RunLifeCell.in // assume all Fredkin cells
Simulate 5 moves.
Print every grid (i.e. 0, 1, 2...5)
*/

		fstream fs("RunLifeCell.in");
		int rows, cols;
		char cellChar;
		fs >> rows;
		fs >> cols;
		Life<Cell> grid(rows, cols, new FredkinCell(false));
		int i,j;
		for(i=0; i<rows; i++)
			for(j=0; j<cols; j++) {
				fs >> cellChar;
				if(cellChar == '0')
					grid.putCell(new FredkinCell(true), i, j);
			}
		for(i=0; i<=5; i++) {
			cout << "Generation = " << i << ", Population = " 
				<< grid.population() << "." << endl;
			cout << grid << endl;
			grid.evolve();
		}

	}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 10x10
    // ----------

    try {
        cout << "*** Life<Cell> 10x10 ***" << endl;
        /*
read RunLifeCell.in // assume all Fredkin cells
Simulate 5 moves
Print every grid (i.e. 0, 1, 2...5)
*/

		fstream fs("CellTest1.in");
		int rows, cols;
		char cellChar;
		fs >> rows;
		fs >> cols;
		Life<Cell> grid(rows, cols, new FredkinCell(false));
		int i,j;
		for(i=0; i<rows; i++)
			for(j=0; j<cols; j++) {
				fs >> cellChar;
				if(cellChar == '0')
					grid.putCell(new FredkinCell(true), i, j);
			}
		for(i=0; i<=5; i++) {
			cout << "Generation = " << i << ", Population = " 
				<< grid.population() << "." << endl;
			cout << grid << endl;
			grid.evolve();
		}

	}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 5x5
    // ----------

    try {
        cout << "*** Life<Cell> 5x5***" << endl;
        /*
read RunLifeCell.in // assume all Fredkin cells
Simulate 5 moves.
Print every grid (i.e. 0, 1, 2...5)
*/

		fstream fs("CellTest2.in");
		int rows, cols;
		char cellChar;
		fs >> rows;
		fs >> cols;
		Life<Cell> grid(rows, cols, new FredkinCell(false));
		int i,j;
		for(i=0; i<rows; i++)
			for(j=0; j<cols; j++) {
				fs >> cellChar;
				if(cellChar == '0')
					grid.putCell(new FredkinCell(true), i, j);
			}
		for(i=0; i<=5; i++) {
			cout << "Generation = " << i << ", Population = " 
				<< grid.population() << "." << endl;
			cout << grid << endl;
			grid.evolve();
		}

	}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 3x3
    // ----------

    try {
        cout << "*** Life<Cell> 3x3 ***" << endl;
        /*
read RunLifeCell.in // assume all Fredkin cells
Simulate 5 moves.
Print every grid (i.e. 0, 1, 2...5)
*/

		fstream fs("CellTest3.in");
		int rows, cols;
		char cellChar;
		fs >> rows;
		fs >> cols;
		Life<Cell> grid(rows, cols, new FredkinCell(false));
		int i,j;
		for(i=0; i<rows; i++)
			for(j=0; j<cols; j++) {
				fs >> cellChar;
				if(cellChar == '0')
					grid.putCell(new FredkinCell(true), i, j);
			}
		for(i=0; i<=5; i++) {
			cout << "Generation = " << i << ", Population = " 
				<< grid.population() << "." << endl;
			cout << grid << endl;
			grid.evolve();
		}

	}

    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 5x5
    // ----------

    try {
        cout << "*** Life<Cell> 5x5***" << endl;
        /*
read RunLifeCell.in // assume all Fredkin cells
Simulate 5 moves.
Print every grid (i.e. 0, 1, 2...5)
*/

		fstream fs("CellTest4.in");
		int rows, cols;
		char cellChar;
		fs >> rows;
		fs >> cols;
		Life<Cell> grid(rows, cols, new FredkinCell(false));
		int i,j;
		for(i=0; i<rows; i++)
			for(j=0; j<cols; j++) {
				fs >> cellChar;
				if(cellChar == '0')
					grid.putCell(new FredkinCell(true), i, j);
			}
		for(i=0; i<=5; i++) {
			cout << "Generation = " << i << ", Population = " 
				<< grid.population() << "." << endl;
			cout << grid << endl;
			grid.evolve();
		}

	}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
