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
#include <fstream>
#include <string>

#include "Life.h"
#include "AbstractCell.h"
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
        
       /* read RunLifeConway.in // assume all Conway cells
        Simulate 283 moves.
        Print the first 10 grids (i.e. 0, 1, 2...9).
        Print the 283rd grid.
        Simulate 40 moves.
        Print the 323rd grid.
        Simulate 2177 moves.
        Print the 2500th grid.*/
        
			unsigned rows, cols;
			string line;
			fstream file;
			file.open("RunLifeConway.in");
			file >> rows;
			file >> cols;
			Life<ConwayCell> l((int)rows, (int)cols, ConwayCell(false));
			
			for(int i = 0; i < (int)rows; ++i) {
				file >> line;
				for(int j = 0; j < (int)cols; ++j) {
					if (line.at(j) == '*'){
						l.add_cell(i,j,ConwayCell(true), '*');
					}
				}
			}
			
			l.simulate(9,cout,1);
			l.simulate(274,cout,283);
			l.simulate(40,cout,323);
			l.simulate(2177,cout,2500);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);} 

    // ------------------
    // Conway Cell 20x20
    // ------------------
    try {
        cout << "*** Life<ConwayCell> 20x20 ***" << endl;
			int rows = 20;
			int cols = 20;
			Life<ConwayCell> l(rows, cols, ConwayCell(false));
			
			l.add_cell(0, 1, ConwayCell(true), '*');
			l.add_cell(1, 2, ConwayCell(true), '*');
			l.add_cell(2, 0, ConwayCell(true), '*');
			l.add_cell(2, 1, ConwayCell(true), '*');
			l.add_cell(2, 2, ConwayCell(true), '*');
			
			l.simulate(80,cout,5);
		
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Conway Cell 19x30
    // ------------------
    try {
        cout << "*** Life<ConwayCell> 19x30 ***" << endl;
			int rows = 19;
			int cols = 30;
			Life<ConwayCell> l(rows, cols, ConwayCell(false));
			
			for(int i = 0; i < 10; ++i) {
				l.add_cell(9, i+10, ConwayCell(true), '*');
			}
			
			l.simulate(30,cout,1);
		
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Conway Cell 50x50
    // ------------------
    try {
        cout << "*** Life<ConwayCell> 50x50 ***" << endl;
			int rows = 50;
			int cols = 50;
			Life<ConwayCell> l(rows, cols, ConwayCell(false));
			l.add_cell(25,13,ConwayCell(true), '*');

			l.add_cell(27,13,ConwayCell(true), '*');

			l.add_cell(24,14,ConwayCell(true), '*');
			l.add_cell(24,15,ConwayCell(true), '*');
			l.add_cell(24,16,ConwayCell(true), '*');
			l.add_cell(24,17,ConwayCell(true), '*');
			l.add_cell(25,17,ConwayCell(true), '*');
			l.add_cell(26,17,ConwayCell(true), '*');

			l.add_cell(27,16,ConwayCell(true), '*');

			l.simulate(170,cout,10);
		
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}	


    // ------------------
    // Conway Cell 8x11
    // ------------------
    try {
        cout << "*** Life<ConwayCell> 8x10 ***" << endl;
			int rows = 8;
			int cols = 11;
			Life<ConwayCell> l(rows, cols, ConwayCell(false));
			
			l.add_cell(1,3,ConwayCell(true), '*');
			l.add_cell(1,4,ConwayCell(true), '*');
			l.add_cell(2,3,ConwayCell(true), '*');
			l.add_cell(2,4,ConwayCell(true), '*');

			l.add_cell(1,6,ConwayCell(true), '*');
			l.add_cell(1,7,ConwayCell(true), '*');
			l.add_cell(2,6,ConwayCell(true), '*');
			l.add_cell(2,7,ConwayCell(true), '*');

			l.add_cell(3,4,ConwayCell(true), '*');
			l.add_cell(3,6,ConwayCell(true), '*');
			l.add_cell(4,4,ConwayCell(true), '*');
			l.add_cell(4,6,ConwayCell(true), '*');
			l.add_cell(5,4,ConwayCell(true), '*');
			l.add_cell(5,6,ConwayCell(true), '*');

			l.add_cell(4,2,ConwayCell(true), '*');
			l.add_cell(4,8,ConwayCell(true), '*');
			l.add_cell(5,2,ConwayCell(true), '*');
			l.add_cell(5,8,ConwayCell(true), '*');
			l.add_cell(6,2,ConwayCell(true), '*');
			l.add_cell(6,8,ConwayCell(true), '*');

			l.add_cell(6,3,ConwayCell(true), '*');
			l.add_cell(6,7,ConwayCell(true), '*');

			l.simulate(14,cout,1);
		
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
        
        //read RunLifeFredkin.in // assume all Fredkin cells
        //Simulate 5 moves.
        //Print every grid (i.e. 0, 1, 2...5)
        
			unsigned rows, cols;
			string line;
			fstream file;
			file.open("RunLifeFredkin.in");
			file >> rows;
			file >> cols;
			Life<FredkinCell> l(rows, cols, FredkinCell(false));

			for(unsigned i = 0; i < rows; ++i) {
				file >> line;
				for(unsigned j = 0; j < cols; ++j) {
					if (line.at(j) != '-'){
						l.add_cell(i,j,FredkinCell(true), '0');
					}
				}
			}

			l.simulate(5,cout,1);
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
			int rows = 20;
			int cols = 20;
			Life<FredkinCell> l(rows, cols, FredkinCell(false));
			
			l.add_cell(0, 1, FredkinCell(true), '0');
			l.add_cell(1, 2, FredkinCell(true), '0');
			l.add_cell(2, 0, FredkinCell(true), '0');
			l.add_cell(2, 1, FredkinCell(true), '0');
			l.add_cell(2, 2, FredkinCell(true), '0');
			
			l.simulate(80,cout,5);
		
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
			int rows = 4;
			int cols = 4;
			Life<FredkinCell> l(rows, cols, FredkinCell(false));
			
			l.add_cell(0, 1, FredkinCell(true), '0');
			l.add_cell(1, 2, FredkinCell(true), '0');
			
			l.simulate(5,cout,1);
			l.simulate(80,cout,85);
		
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 1x1
    // ------------------
    try {
        cout << "*** Life<FredkinCell> 1x1 ***" << endl;
			int rows = 1;
			int cols = 1;
			Life<FredkinCell> l(rows, cols, FredkinCell(false));
			
			l.add_cell(0, 0, FredkinCell(true), '0');
			
			l.simulate(1,cout,1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 100x100
    // ------------------
    try {
        cout << "*** Life<FredkinCell> 100x100 ***" << endl;
			int rows = 100;
			int cols = 100;
			Life<FredkinCell> l(rows, cols, FredkinCell(false));
			
			l.add_cell(50,50, FredkinCell(true), '0');
			l.add_cell(49,50, FredkinCell(true), '0');
			l.add_cell(48,50, FredkinCell(true), '0');
			l.add_cell(51,50, FredkinCell(true), '0');
			l.add_cell(52,50, FredkinCell(true), '0');
			
			l.simulate(85,cout,1);
			//l.simulate(80,cout,85);
		
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 3x3
    // ------------------
    try {
        cout << "*** Life<FredkinCell> 3x3 ***" << endl;
			int rows = 3;
			int cols = 3;
			Life<FredkinCell> l(rows, cols, FredkinCell(false));
			
			l.add_cell(0,0, FredkinCell(true), '0');
			l.add_cell(2,0, FredkinCell(true), '0');
			l.add_cell(0,2, FredkinCell(true), '0');
			
			l.simulate(5,cout,1);
		
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
        
        //read RunLifeCell.in // assume all Fredkin cells
        //Simulate 5 moves.
        //Print every grid (i.e. 0, 1, 2...5)
        

			unsigned rows, cols;
			string line;
			fstream file;
			file.open("RunLifeCell.in");
			file >> rows;
			file >> cols;
			Life<Cell> l(rows, cols, new FredkinCell(false));

			for(unsigned i = 0; i < rows; ++i) {
				file >> line;
				for(unsigned j = 0; j < cols; ++j) {
					if (line.at(j) == '0'){
						l.add_cell(i,j,new FredkinCell(true), '0');
					}
				}
			}

			l.simulate(5,cout,1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // Cell 1x1
    // ----------

    try {
        cout << "*** Life<Cell> 1x1 ***" << endl;
        /*
		// assume all Fredkin cells
        */

			int rows = 1;
			int cols = 1;
			Life<Cell> l(rows, cols, new FredkinCell(false));
		
			l.add_cell(0,0,new FredkinCell(true), '0');

			l.simulate(5,cout,1);
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
		// assume all Fredkin cells
        */

			int rows = 3;
			int cols = 3;
			Life<Cell> l(rows, cols, new FredkinCell(false));
		
			l.add_cell(1,1,new FredkinCell(true), '0');

			l.simulate(5,cout,1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // Cell 50x50
    // ----------

    try {
        cout << "*** Life<Cell> 50x50 ***" << endl;
        /*
		// assume all Fredkin cells
        */

			int rows = 50;
			int cols = 50;
			Life<Cell> l(rows, cols, new FredkinCell(false));
		
			l.add_cell(24,24,new FredkinCell(true), '0');

			l.simulate(10,cout,1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 50x50
    // ----------

    try {
        cout << "*** Life<Cell> 50x50 ***" << endl;
        /*
		// assume all Fredkin cells
        */

			int rows = 50;
			int cols = 50;
			Life<Cell> l(rows, cols, new FredkinCell(false));
		
			for (int i = 0; i < rows; ++i){
				for (int j = 0; j < cols; ++j){
					l.add_cell(i,j,new FredkinCell(true), '0');
				}
			}

			l.simulate(10,cout,1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 50x50
    // ----------

    try {
        cout << "*** Life<Cell> 50x50 ***" << endl;
        /*
		// assume all Fredkin cells
        */

			int rows = 50;
			int cols = 50;
			Life<Cell> l(rows, cols, new FredkinCell(false));
		
			for (int i = 0; i < cols; ++i){
				l.add_cell(24,i,new FredkinCell(true), '0');
			}

			l.simulate(100,cout,1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    return 0;}


