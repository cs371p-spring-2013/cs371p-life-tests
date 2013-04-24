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
#include <string>
#include <fstream>

#include "Life.h"
#include "AbstractCell.h"
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"


// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

	//freopen("RunLife.out", "w", stdout);

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
        fstream in("RunLifeConway.in");
        int rows;
        int cols;
        
        in >> rows;
        in >> cols;
        
        Life<ConwayCell> l(ConwayCell(), rows, cols);
        
        char c;
        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
        		in >> c;
        		if (c != '*') 
        			l.set(i, j, ConwayCell(false));
        	} 
        }
        
        in.close();
        
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(273);
        l.print();
        l.simulate(40);
        l.print();
        l.simulate(2177);
        l.print();
        
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
        fstream in("RunLifeFredkin.in");
        int rows;
        int cols;
        
        in >> rows;
        in >> cols;
        
        Life<FredkinCell> l(FredkinCell(), rows, cols);
        
        char c;
        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
        		in >> c;
        		if (c != '0') 
        			l.set(i, j, FredkinCell(false));
        	} 
        }
        
        in.close();
        
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        
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
        
        fstream in("RunLifeCell.in");
        int rows;
        int cols;
        
        in >> rows;
        in >> cols;
        
        Life<Cell> l(new FredkinCell(), rows, cols);
        
        char c;
        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
        		in >> c;
        		if (c != '0') 
        			l.set(i, j, new FredkinCell(false));
        	} 
        }
        
        in.close();
        
        l.print();
		l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
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
        
        fstream in("RunLifeCell.in");
        int rows;
        int cols;
        
        in >> rows;
        in >> cols;
        
        Life<Cell> l(new FredkinCell(), rows, cols);
        
        char c;
        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
        		in >> c;
        		if (c != '0') 
        			l.set(i, j, new FredkinCell(false));
        	} 
        }
        
        in.close();
        
        l.print();
		l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
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
        
        fstream in("RunLifeCell.in");
        int rows;
        int cols;
        
        in >> rows;
        in >> cols;
        
        Life<Cell> l(new FredkinCell(), rows, cols);
        
        char c;
        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
        		in >> c;
        		if (c != '0') 
        			l.set(i, j, new FredkinCell(false));
        	} 
        }
        
        in.close();
        
        l.print();
		l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
    }   
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    
    // my tests
    
    // ----------
    // ConwayCell1 109x69
    // ----------

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
        fstream in("RunLifeConway.in");
        int rows;
        int cols;
        
        in >> rows;
        in >> cols;
        
        Life<ConwayCell> l(ConwayCell(), rows, cols);
        
        char c;
        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
        		in >> c;
        		if (c != '*') 
        			l.set(i, j, ConwayCell(false));
        	} 
        }
        
        in.close();
        

        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.simulate(40);
        l.print();
        l.simulate(2500);
        l.print();
        
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
   // ------------------
    // Conway Cell2 109x69
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
        fstream in("RunLifeConway.in");
        int rows;
        int cols;
        
        in >> rows;
        in >> cols;
        
        Life<ConwayCell> l(ConwayCell(), rows, cols);
        
        char c;
        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
        		in >> c;
        		if (c != '*') 
        			l.set(i, j, ConwayCell(false));
        	} 
        }
        
        in.close();
        
        l.print();
        l.simulate(250);
        l.print();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ------------------
    // Conway Cell3 109x69
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 20x20 ***" << endl;
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
        fstream in("RunLifeConway.in");
        int rows;
        int cols;
        
        in >> rows;
        in >> cols;
        
        Life<ConwayCell> l(ConwayCell(), rows, cols);
        
        char c;
        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
        		in >> c;
        		if (c != '*') 
        			l.set(i, j, ConwayCell());
        	} 
        }
        
        in.close();
        
        l.print();
        l.simulate(1000);
        l.print();
        l.simulate(1000);
        l.print();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ------------------
    // Conway Cell4 109x69
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 20x20 ***" << endl;
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
        fstream in("RunLifeConway.in");
        int rows;
        int cols;
        
        in >> rows;
        in >> cols;
        
        Life<ConwayCell> l(ConwayCell(), rows, cols);
        
        char c;
        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
        		in >> c;
        		if (c != '*') 
        			l.set(i, j, ConwayCell(false));
        	} 
        }
        
        in.close();
        
        l.print();
        l.simulate(5000);
        l.print();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ------------------
    // Conway Cell5 109x69
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 20x20 ***" << endl;
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
        fstream in("RunLifeConway.in");
        int rows;
        int cols;
        
        in >> rows;
        in >> cols;
        
        Life<ConwayCell> l(ConwayCell(), rows, cols);
        
        char c;
        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
        		in >> c;
        		if (c != '*') 
        			l.set(i, j, ConwayCell(false));
        	} 
        }
        
        in.close();
        
        l.print();
        l.simulate(1000);
        l.print();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ------------------
    // Fredkin Cell1 20x20
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        fstream in("RunLifeFredkin.in");
        int rows;
        int cols;
        
        in >> rows;
        in >> cols;
        
        Life<FredkinCell> l(FredkinCell(), rows, cols);
        
        char c;
        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
        		in >> c;
        		if (c != '0') 
        			l.set(i, j, FredkinCell(false));
        	} 
        }
        
        in.close();
        
        l.print();
        l.simulate(1000);
        l.print();
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ------------------
    // Fredkin Cell2 20x20
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        fstream in("RunLifeFredkin.in");
        int rows;
        int cols;
        
        in >> rows;
        in >> cols;
        
        Life<FredkinCell> l(FredkinCell(), rows, cols);
        
        char c;
        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
        		in >> c;
        		if (c != '0') 
        			l.set(i, j, FredkinCell(false));
        	} 
        }
        
        in.close();
        
        l.print();
        l.simulate(10);
        l.print();
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ------------------
    // Fredkin Cell3 20x20
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        fstream in("RunLifeFredkin.in");
        int rows;
        int cols;
        
        in >> rows;
        in >> cols;
        
        Life<FredkinCell> l(FredkinCell(), rows, cols);
        
        char c;
        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
        		in >> c;
        		if (c != '0') 
        			l.set(i, j, FredkinCell(false));
        	} 
        }
        
        in.close();
        
        l.print();
        l.simulate(50);
        l.print();
        l.simulate(50);
        l.print();
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ------------------
    // Fredkin Cell4 20x20
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        fstream in("RunLifeFredkin.in");
        int rows;
        int cols;
        
        in >> rows;
        in >> cols;
        
        Life<FredkinCell> l(FredkinCell(), rows, cols);
        
        char c;
        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
        		in >> c;
        		if (c != '0') 
        			l.set(i, j, FredkinCell(false));
        	} 
        }
        
        in.close();
        
        l.print();
        l.simulate(2);
        l.print();
        l.simulate(2);
        l.print();
        l.simulate(2);
        l.print();
        l.simulate(2);
        l.print();
        l.simulate(2);
        l.print();
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        
    // ------------------
    // Fredkin Cell5 20x20
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        fstream in("RunLifeFredkin.in");
        int rows;
        int cols;
        
        in >> rows;
        in >> cols;
        
        Life<FredkinCell> l(FredkinCell(), rows, cols);
        
        char c;
        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
        		in >> c;
        		if (c != '0') 
        			l.set(i, j, FredkinCell(false));
        	} 
        }
        
        in.close();
        
        l.print();
        l.simulate(30);
        l.print();
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------
    // Cell1 20x20
    // ----------

    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        
        fstream in("RunLifeCell.in");
        int rows;
        int cols;
        
        in >> rows;
        in >> cols;
        
        Life<Cell> l(new FredkinCell(), rows, cols);
        
        char c;
        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
        		in >> c;
        		if (c != '0') 
        			l.set(i, j, new FredkinCell(false));
        	} 
        }
        
        in.close();
        
        l.print();
		l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
        l.simulate(1);
        l.print();
    }   
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------
    // Cell2 20x20
    // ----------

    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        
        fstream in("RunLifeCell.in");
        int rows;
        int cols;
        
        in >> rows;
        in >> cols;
        
        Life<Cell> l(new ConwayCell(), rows, cols);
        
        char c;
        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
        		in >> c;
        		if (c != '0') 
        			l.set(i, j, new ConwayCell(false));
        	} 
        }
        
        in.close();
        
        l.print();
		l.simulate(12);
        l.print();
    }   
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------
    // Cell3 20x20
    // ----------

    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        
        fstream in("RunLifeCell.in");
        int rows;
        int cols;
        
        in >> rows;
        in >> cols;
        
        Life<Cell> l(new FredkinCell(), rows, cols);
        
        char c;
        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
        		in >> c;
        		if (c != '0') 
        			l.set(i, j, new FredkinCell(false));
        	} 
        }
        
        in.close();
        
        l.print();
		l.simulate(10);
        l.print();
        l.simulate(10);
        l.print();
    }   
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------
    // Cell4 20x20
    // ----------

    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        
        fstream in("RunLifeCell.in");
        int rows;
        int cols;
        
        in >> rows;
        in >> cols;
        
        Life<Cell> l(new FredkinCell(), rows, cols);
        
        char c;
        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
        		in >> c;
        		if (c != '0') 
        			l.set(i, j, new FredkinCell(false));
        	} 
        }
        
        in.close();
        
        l.print();
		l.simulate(20);
        l.print();
    }   
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------
    // Cell5 20x20
    // ----------

    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        
        fstream in("RunLifeCell.in");
        int rows;
        int cols;
        
        in >> rows;
        in >> cols;
        
        Life<Cell> l(new ConwayCell(), rows, cols);
        
        char c;
        for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < cols; ++j) {
        		in >> c;
        		if (c != '0') 
        			l.set(i, j, new ConwayCell(false));
        	} 
        }
        
        in.close();
        
        l.print();
		l.simulate(100);
        l.print();
    }   
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        

    return 0;}
