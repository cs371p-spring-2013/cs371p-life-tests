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
#include <fstream>
#include <stdexcept> // invalid_argument, out_of_range
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
		int rows, columns;
		ifstream stream;
		char letter;
		stream.open("RunLifeConway.in");
		stream  >> rows >> columns;
		Life<ConwayCell> a (rows, columns);
		for(int i = 1; i < rows + 1; ++i) {
			for(int j = 1; j < columns + 1; ++j){
				stream >> letter;
				switch(letter){
				case '.':
					a.pushcell(ConwayCell(letter), i ,j);
				case '*':
					a.pushcell(ConwayCell(letter), i, j);
				}

			}
		}
		for(int z = 0; z < 283; ++z){
			if(z < 10){
				a.printboard();
			}
			a.simulate();
		}
		a.printboard();

		for(int z = 0; z < 40; ++z){
			a.simulate();
		}
		a.printboard();
		for(int z = 0; z < 2177; ++z){
			a.simulate();
		}
		a.printboard();

		cout << endl;
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

		int rows, columns;
		ifstream stream;
		char letter;
		stream.open("RunLifeFredkin.in");
		stream  >> rows >> columns;
		Life<FredkinCell> a (rows, columns);
		for(int i = 1; i < rows + 1; ++i) {
			for(int j = 1; j < columns + 1; ++j){
				stream >> letter;
				switch(letter){
				case '-':
					a.pushcell(FredkinCell(letter), i ,j);
				case '0':
					a.pushcell(FredkinCell(letter), i, j);
				}

			}
		}
		a.printboard();
		for(int b = 0; b < 5; ++b){
			a.simulate();
			a.printboard();
		}
		cout << endl;
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
		int rows, columns;
		ifstream stream;
		char letter;
		stream.open("RunLifeCell.in");
		stream  >> rows >> columns;
		Life<Cell> a (rows, columns);
		for(int i = 1; i < rows + 1; ++i) {
			for(int j = 1; j < columns + 1; ++j){
				stream >> letter;
				switch(letter){
				case '-':
					a.pushcell(Cell(new FredkinCell(letter)), i ,j);
				case '0':
					a.pushcell(Cell( new FredkinCell(letter)), i, j);
				}

			}
		}

		a.printboard();
		for(int b = 0; b < 5; ++b){
			a.simulate();
			a.printboard();
		}


		cout << endl;
	}
	catch (const invalid_argument&) {
		assert(false);}
	catch (const out_of_range&) {
		assert(false);}



	try {
		cout << "*** Life<ConwayCell> 1x1 ***" << endl;
		/*
		 */
		Life<ConwayCell> a (1, 1);
		a.pushcell(ConwayCell('*'), 1 ,1);
		a.printboard();
		a.simulate();
		a.printboard();


		cout << endl;
	}
	catch (const invalid_argument&) {
		assert(false);}
	catch (const out_of_range&) {
		assert(false);}


	try {
		cout << "*** Life<ConwayCell> 10x10 ***" << endl; // all alive cells
		/*
		 */
		Life<ConwayCell> a (10, 10);
		for(int i = 1; i < 10 + 1; ++i) {
			for(int j = 1; j < 10 + 1; ++j){
				a.pushcell(ConwayCell('*'), i, j);

			}
		}
		for(int i = 0; i < 2; ++i){
			a.printboard();
			a.simulate();
		}
		a.printboard();

		cout << endl;
	}
	catch (const invalid_argument&) {
		assert(false);}
	catch (const out_of_range&) {
		assert(false);}


	try {
		cout << "*** Life<ConwayCell> 0x0 ***" << endl; // nothing
		/*
		 */
		Life<ConwayCell> a (0, 0);
		a.pushcell(ConwayCell('*'), 0, 0); //wont do anything will place a cell in an extra spot wont print


		a.printboard();
		a.simulate();
		a.printboard();

		cout << endl;
	}
	catch (const invalid_argument&) {
		assert(false);}
	catch (const out_of_range&) {
		assert(false);}



	try {
		cout << "*** Life<ConwayCell> 10x10 ***" << endl; // all dead cells except for 1
		/*
		 */
		Life<ConwayCell> a (10, 10);
		for(int i = 1; i < 10 + 1; ++i) {
			for(int j = 1; j < 10 + 1; ++j){
				a.pushcell(ConwayCell('.'), i, j);

			}
		}
		a.pushcell(ConwayCell('*'), 3, 3);
		for(int i = 0; i < 1; ++i){
			a.printboard();
			a.simulate();
		}
		a.printboard();

		cout << endl;
	}
	catch (const invalid_argument&) {
		assert(false);}
	catch (const out_of_range&) {
		assert(false);}



	try {
		cout << "*** Life<ConwayCell> 10x10 ***" << endl; // 3 live cells that just alternate
		/*
		 */
		Life<ConwayCell> a (10, 10);
		for(int i = 1; i < 10 + 1; ++i) {
			for(int j = 1; j < 10 + 1; ++j){
				a.pushcell(ConwayCell('.'), i, j);

			}
		}
		a.pushcell(ConwayCell('*'), 3, 4);
		a.pushcell(ConwayCell('*'), 3, 2);
		a.pushcell(ConwayCell('*'), 3, 3);
		for(int i = 0; i < 3; ++i){
			a.printboard();
			a.simulate();
		}
		a.printboard();

		cout << endl;
	}
	catch (const invalid_argument&) {
		assert(false);}
	catch (const out_of_range&) {
		assert(false);}


	try {
		cout << "*** Life<FredkinCell> 10x10 ***" << endl; // all alive Fredkin cells


		Life<FredkinCell> a (10, 10);
		for(int i = 1; i < 10 + 1; ++i) {
			for(int j = 1; j < 10 + 1; ++j){
				a.pushcell(FredkinCell('0'), i ,j);
			}

		}
		a.printboard();
		for(int b = 0; b < 30; ++b){
			a.simulate();
			a.printboard();
		}
		cout << endl;
	}
	catch (const invalid_argument&) {
		assert(false);}
	catch (const out_of_range&) {
		assert(false);}


	try {
		cout << "*** Life<FredkinCell> 1x1 ***" << endl; // 1x1 grid


		Life<FredkinCell> a (1, 1);
		for(int i = 1; i < 1 + 1; ++i) {
			for(int j = 1; j < 1 + 1; ++j){
				a.pushcell(FredkinCell('0'), i ,j);
			}

		}
		a.printboard();
		for(int b = 0; b < 1; ++b){
			a.simulate();
			a.printboard();
		}
		cout << endl;
	}
	catch (const invalid_argument&) {
		assert(false);}
	catch (const out_of_range&) {
		assert(false);}

	try {
		cout << "*** Life<FredkinCell> 0x0 ***" << endl; // 1x1 grid


		Life<FredkinCell> a (0, 0);

		a.pushcell(FredkinCell('0'), 0 ,0); //like before does nothing really

		a.printboard();
		for(int b = 0; b < 1; ++b){
			a.simulate();
			a.printboard();
		}
		cout << endl;
	}
	catch (const invalid_argument&) {
		assert(false);}
	catch (const out_of_range&) {
		assert(false);}


	try {
		cout << "*** Life<FredkinCell> 10x10 ***" << endl; // all dead


		Life<FredkinCell> a (10, 10);
		for(int i = 1; i < 10 + 1; ++i) {
			for(int j = 1; j < 10 + 1; ++j){
				a.pushcell(FredkinCell('-'), i ,j);
			}

		}
		a.printboard();
		for(int b = 0; b < 1; ++b){
			a.simulate();
			a.printboard();
		}
		cout << endl;
	}
	catch (const invalid_argument&) {
		assert(false);}
	catch (const out_of_range&) {
		assert(false);}


	try {
		cout << "*** Life<FredkinCell> 10x10 ***" << endl; // one alive in corner


		Life<FredkinCell> a (10, 10);
		for(int i = 1; i < 10 + 1; ++i) {
			for(int j = 1; j < 10 + 1; ++j){
				a.pushcell(FredkinCell('-'), i ,j);
			}

		}
		a.pushcell(FredkinCell('0'), 1 ,1);
		a.printboard();
		for(int b = 0; b < 20; ++b){
			a.simulate();
			a.printboard();
		}
		cout << endl;
	}
	catch (const invalid_argument&) {
		assert(false);}
	catch (const out_of_range&) {
		assert(false);}


	try {
		cout << "*** Life<Cell> 10x10 ***" << endl;// all alive cells

		Life<Cell> a (10, 10);
		for(int i = 1; i < 10 + 1; ++i) {
			for(int j = 1; j < 10 + 1; ++j){
				a.pushcell(Cell(new FredkinCell('0')), i ,j);
			}
		}

		a.printboard();
		for(int b = 0; b < 5; ++b){
			a.simulate();
			a.printboard();
		}


		cout << endl;
	}
	catch (const invalid_argument&) {
		assert(false);}
	catch (const out_of_range&) {
		assert(false);}


	try {
		cout << "*** Life<Cell> 1x1 ***" << endl;// 1x1

		Life<Cell> a (1, 1);
		for(int i = 1; i < 1 + 1; ++i) {
			for(int j = 1; j < 1 + 1; ++j){
				a.pushcell(Cell(new FredkinCell('0')), i ,j);
			}
		}

		a.printboard();
		for(int b = 0; b < 2; ++b){
			a.simulate();
			a.printboard();
		}


		cout << endl;
	}
	catch (const invalid_argument&) {
		assert(false);}
	catch (const out_of_range&) {
		assert(false);}


	try {
		cout << "*** Life<Cell> 0x0 ***" << endl; //empty gird

		Life<Cell> a (0, 0);
		a.pushcell(Cell(new FredkinCell('0')), 0 ,0); //does nothing


		a.printboard();
		for(int b = 0; b < 1; ++b){
			a.simulate();
			a.printboard();
		}


		cout << endl;
	}
	catch (const invalid_argument&) {
		assert(false);}
	catch (const out_of_range&) {
		assert(false);}

	try {
		cout << "*** Life<Cell> 10x10 ***" << endl;// all dead cells

		Life<Cell> a (10, 10);
		for(int i = 1; i < 10 + 1; ++i) {
			for(int j = 1; j < 10 + 1; ++j){
				a.pushcell(Cell(new FredkinCell('-')), i ,j);
			}
		}

		a.printboard();
		for(int b = 0; b < 1; ++b){
			a.simulate();
			a.printboard();
		}


		cout << endl;
	}
	catch (const invalid_argument&) {
		assert(false);}
	catch (const out_of_range&) {
		assert(false);}

	try {
		cout << "*** Life<Cell> 10x10 ***" << endl;// mix of conway and fred

		Life<Cell> a (10, 10);
		for(int i = 1; i < 10 + 1; ++i) {
			for(int j = 1; j < 10 + 1; ++j){
				a.pushcell(Cell(new FredkinCell('0')), i ,j);
			}
		}
		a.pushcell(Cell(new ConwayCell('*')), 1 ,1);
		a.pushcell(Cell(new ConwayCell('*')), 10 ,10);
		a.printboard();
		for(int b = 0; b < 10; ++b){
			a.simulate();
			a.printboard();
		}


		cout << endl;
	}
	catch (const invalid_argument&) {
		assert(false);}
	catch (const out_of_range&) {
		assert(false);}

	return 0;}
