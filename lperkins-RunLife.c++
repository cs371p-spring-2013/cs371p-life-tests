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
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
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
        int row = 0;
        int col = 0;
        char c;
        
        ifstream file("RunLifeConway.in");
        file >> row;
        file >> col;
        Life<ConwayCell> g(row,col, ConwayCell(false));
        for(int i = 0; i < row; ++i) {
         for(int j = 0; j < col; ++j) {
          file >> c;
          if(c == '*') {
           g.gridCellType(i,j, ConwayCell(true));
          }
         }
        }
        g.print();
        g.simulate(283);
        g.print();
        g.simulate(40);
        g.print();
        g.simulate(2177);
        g.print();

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
        int row = 0;
        int col = 0;
        char c;
        ifstream file("RunLifeFredkin.in");
        file >> row;
        file >> col;
        Life<FredkinCell> g(row,col, FredkinCell(false));
        for(int i = 0; i < row; ++i) {
         for(int j = 0; j < col; ++j) {
          file >> c;
          if(c == '0') {
           g.gridCellType(i,j, FredkinCell(true));
          }
         }
        }
        g.print();
        for(int k = 0; k < 5; ++k) {
          g.simulate(1);
          g.print();
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
        int row = 0;
        int col = 0;
        char c;
        ifstream file("RunLifeCell.in");
        file >> row;
        file >> col;
        Life<Cell> g(row,col, new FredkinCell(false));
        for(int i = 0; i < row; ++i) {
         for(int j = 0; j < col; ++j) {
          file >> c;
          if(c == '0') {
           g.gridCellType(i,j, new FredkinCell(true));
          }}}
        g.print();
        
        for(int k = 0; k < 5; ++k) {
          g.simulate(1);
          g.print();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    
// ------------------
// ConwayCell 5X5
// ------------------
   try {
	cout << "*** Life<ConwayCell> 5x5" << endl;
	Life<ConwayCell> conway(5,5, ConwayCell(false));
        conway.gridCellType(1,1, ConwayCell(true));
        conway.gridCellType(2,2, ConwayCell(true));
        conway.gridCellType(3,3, ConwayCell(true));
        conway.gridCellType(0,0, ConwayCell(true));
        conway.print();
	for(int i = 0; i < 3; i++) {
        conway.simulate(5);
        conway.print();}
    }
    catch (const invalid_argument&) {
        assert(false); }
    catch (const out_of_range&) {
        assert(false);}
    
    
    // ------------------
    // ConwayCell 10X10
    // ------------------
    try {
        cout << "*** Life<ConwayCell> 10x10" << endl;
        Life<ConwayCell> conway(10,10, ConwayCell(false));
        conway.gridCellType(3,5, ConwayCell(true));
        conway.gridCellType(4,4, ConwayCell(true));
        conway.gridCellType(4,3, ConwayCell(true));
        conway.gridCellType(5,5, ConwayCell(true));
        
        conway.print();
        for(int i = 0; i < 3; i++) {
            conway.simulate(10);
            conway.print();}
    }
    catch (const invalid_argument&) {
        assert(false); }
    catch (const out_of_range&) {
        assert(false);}
    
    
    // ------------------
    // ConwayCell 5X3
    // ------------------
    try {
        cout << "*** Life<ConwayCell> 5x3" << endl;
        Life<ConwayCell> conway(5,3, ConwayCell(false));
        conway.gridCellType(0,0, ConwayCell(true));
        conway.gridCellType(0,1, ConwayCell(true));
        conway.gridCellType(1,0, ConwayCell(true));
        
        conway.print();
        for(int i = 0; i < 4; i++) {
            conway.simulate(500);
            conway.print();}
    }
    catch (const invalid_argument&) {
        assert(false); }
    catch (const out_of_range&) {
        assert(false);}
    
    
    // ------------------
    // ConwayCell 2X2
    // ------------------
    try {
        cout << "*** Life<ConwayCell> 2x2" << endl;
        Life<ConwayCell> conway(2,2, ConwayCell(false));
        conway.gridCellType(0,0, ConwayCell(true));
        conway.gridCellType(0,1, ConwayCell(true));
        conway.gridCellType(1,1, ConwayCell(true));
        conway.gridCellType(1,0, ConwayCell(true));
        conway.print();
        for(int i = 0; i < 4; i++) {
            conway.simulate(500);
            conway.print();}
    }
    catch (const invalid_argument&) {
        assert(false); }
    catch (const out_of_range&) {
        assert(false);}    
    
    
    
    
    
    
    
    
    
  // ------------------
  // Fredkin Cell 50X50
  // ------------------
  try {
	cout << "*** Life<FredkinCell> 50x50" << endl;
	Life<FredkinCell> fred(50,50, FredkinCell(false));
	for (int col = 0; col < 50; col++) {
	  fred.gridCellType(24,col, FredkinCell(true));
	}
         fred.print();

	for(int i = 0; i < 4; i++) {
	  fred.simulate(500);
          fred.print();}
   } 
    catch (const invalid_argument&) {
	assert(false); } 
    catch (const out_of_range&) {
	assert(false);}
   
    
  // ------------------
  // Fredkin Cell 10X10
  // ------------------
  try {
        cout << "*** Life<FredkinCell> 10x10" << endl;
        Life<FredkinCell> fred(10,10, FredkinCell(false));
        fred.gridCellType(3,2, FredkinCell(true));
        fred.gridCellType(2,3, FredkinCell(true));
        fred.gridCellType(2,2, FredkinCell(true));
        fred.gridCellType(3,3, FredkinCell(true));
        fred.gridCellType(2,4, FredkinCell(true));
        fred.print();
        for(int i = 0; i < 10; i++) {
          fred.simulate(10);
          fred.print();
        }
   }
    catch (const invalid_argument&) {
        assert(false); }
    catch (const out_of_range&) {
        assert(false);}

    
    // ------------------
    // Fredkin Cell 5X3
    // ------------------
    try {
        cout << "*** Life<FredkinCell> 5x3" << endl;
        Life<FredkinCell> fred(5,3, FredkinCell(false));
        fred.gridCellType(0,0, FredkinCell(true));
        fred.gridCellType(2,2, FredkinCell(true));
        fred.gridCellType(3,2, FredkinCell(true));
        fred.gridCellType(2,1, FredkinCell(true));
        fred.print();
        for(int i = 0; i < 4; i++) {
            fred.simulate(5);
            fred.print();}
    }
    catch (const invalid_argument&) {
        assert(false); }
    catch (const out_of_range&) {
        assert(false);}
    
    
    // ------------------
    // Fredkin Cell 5X5
    // ------------------
    try {
        cout << "*** Life<FredkinCell> 5x5" << endl;
        Life<FredkinCell> fred(5,5, FredkinCell(false));
        fred.gridCellType(0,0, FredkinCell(true));
        fred.gridCellType(0,4, FredkinCell(true));
        fred.gridCellType(2,2, FredkinCell(true));
        fred.gridCellType(4,0, FredkinCell(true));
        fred.gridCellType(4,4, FredkinCell(true));
        fred.print();
        for(int i = 0; i < 5; i++) {
            fred.simulate(10);
            fred.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false); }
    catch (const out_of_range&) {
        assert(false);}
    
    
    
    
    
    // ------------------
    // Cell 6X5
    // ------------------
    try {
        cout << "*** Life<Cell> 6x5" << endl;
        Life<Cell> c (6, 5, new FredkinCell(false));
        c.gridCellType(1,1, new FredkinCell(true));
        c.gridCellType(1,3, new FredkinCell(true));
        c.gridCellType(2,2, new FredkinCell(true));
        c.gridCellType(3,2, new FredkinCell(true));
        c.gridCellType(4,1, new FredkinCell(true));
        c.gridCellType(4,3, new FredkinCell(true));
        c.print();
        for(int i = 0; i < 4; ++i) {
            c.simulate(5);
            c.print();}
    }
    catch (const invalid_argument&) {
        assert(false); }
    catch (const out_of_range&) {
        assert(false);}
    
    
    // ------------------
    // Cell 10X10
    // ------------------
    try {
        cout << "*** Life<Cell> 10x10" << endl;
        Life<FredkinCell> c(10,10, FredkinCell(false));
        c.gridCellType(3,2, FredkinCell(true));
        c.gridCellType(2,3, FredkinCell(true));
        c.gridCellType(2,2, FredkinCell(true));
        c.gridCellType(3,3, FredkinCell(true));
        c.gridCellType(2,4, FredkinCell(true));
        c.print();
        for(int i = 0; i < 10; i++) {
            c.simulate(10);
            c.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false); }
    catch (const out_of_range&) {
        assert(false);}
    
    
    // ------------------
    // Cell 2X2
    // ------------------
    try {
        cout << "*** Life<Cell> 2x2" << endl;
        Life<FredkinCell> c(2,2, FredkinCell(false));
        c.gridCellType(0,0, FredkinCell(true));
        c.gridCellType(1,1, FredkinCell(true));
        c.print();
        for(int i = 0; i < 3; i++) {
            c.simulate(5);
            c.print();}
    }
    catch (const invalid_argument&) {
        assert(false); }
    catch (const out_of_range&) {
        assert(false);}
    
    
    // ------------------
    // Cell 1X1
    // ------------------
    try {
        cout << "*** Life<Cell> 1x1" << endl;
        Life<FredkinCell> c(1,1, FredkinCell(false));
        c.gridCellType(0,0, FredkinCell(true));
        c.print();
        for(int i = 0; i < 2; i++) {
            c.simulate(10);
            c.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false); }
    catch (const out_of_range&) {
        assert(false);}
    

    return 0;}







