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
#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
	
	// input files.
	std::ifstream conway("RunLifeConway.in");
	std::ifstream fredkin("RunLifeFredkin.in");
	std::ifstream cell("RunLifeCell.in");


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

            int row, col = 0;
            conway >> row;
            conway >> col;
            Life<ConwayCell> life(row, col);
            conway >> life;
            cout << life;

            for(int i = 1; i <= 2500; ++i) {
                life.evolve();
                if (i < 10 || i == 283 || i == 323 || i == 2500)
                    cout << life;    
               
            }
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
		cout << "***      Basic Glider      ***" << endl;

            int row, col = 0;
            conway >> row;
            conway >> col;
            Life<ConwayCell> life(row, col);
            conway >> life;
            cout << life;

            for(int i = 1; i <= 70; ++i) {
                life.evolve();
				if ( i % 5 == 0)
                	cout << life;

            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Conway Cell 1x1
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 1x1 ***" << endl;

            int row, col = 0;
            conway >> row;
            conway >> col;
            Life<ConwayCell> life(row, col);
            conway >> life;
            cout << life;

            for(int i = 1; i <= 2; ++i) {
                life.evolve();
                cout << life;

            }
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
        cout << "***     Figure Eight       ***" << endl;

            int row, col = 0;
            conway >> row;
            conway >> col;
            Life<ConwayCell> life(row, col);
            conway >> life;
            cout << life;

            for(int i = 1; i <= 8; ++i) {
                life.evolve();
                cout << life;

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
        cout << "***     Small Clock        ***" << endl;

            int row, col = 0;
            conway >> row;
            conway >> col;
            Life<ConwayCell> life(row, col);
            conway >> life;
            cout << life;

            for(int i = 1; i <= 4; ++i) {
                life.evolve();
                cout << life;

            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Conway Cell 12x12
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 12x12 ***" << endl;
        cout << "***     Large Clock        ***" << endl;

            int row, col = 0;
            conway >> row;
            conway >> col;
            Life<ConwayCell> life(row, col);
            conway >> life;
            cout << life;

            for(int i = 1; i <= 4; ++i) {
                life.evolve();
                cout << life;

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
            int row, col = 0;
            fredkin >> row;
            fredkin >> col;
            Life<FredkinCell> life(row, col);
            fredkin >> life;
            cout << life;

            for(int i = 1; i <= 5; ++i) {
                life.evolve();
                cout << life;   
            }
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
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
            int row, col = 0;
            fredkin >> row;
            fredkin >> col;
            Life<FredkinCell> life(row, col);
            fredkin >> life;
            cout << life;

            for(int i = 1; i <= 1; ++i) {
                life.evolve();
                cout << life;   
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // Fredkin Cell 10x10
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 4x4 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
            int row, col = 0;
            fredkin >> row;
            fredkin >> col;
            Life<FredkinCell> life(row, col);
            fredkin >> life;
            cout << life;

            for(int i = 1; i <= 5; ++i) {
                life.evolve();
                cout << life;   
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // Fredkin Cell 10x10
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 9x9 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
            int row, col = 0;
            fredkin >> row;
            fredkin >> col;
            Life<FredkinCell> life(row, col);
            fredkin >> life;
            cout << life;

            for(int i = 1; i <= 10; ++i) {
                life.evolve();
                if ( i % 2 == 0)
                    cout << life;   
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // Fredkin Cell 21x20
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 21x20 ***" << endl;
        cout << "***  Mixed Dead and Alive   ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
            int row, col = 0;
            fredkin >> row;
            fredkin >> col;
            Life<FredkinCell> life(row, col);
            fredkin >> life;
            cout << life;

            for(int i = 1; i <= 10; ++i) {
                life.evolve();
                cout << life;   
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
        cout << "***  Full Board           ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
            int row, col = 0;
            fredkin >> row;
            fredkin >> col;
            Life<FredkinCell> life(row, col);
            fredkin >> life;
            cout << life;

            for(int i = 1; i <= 10; ++i) {
                life.evolve();
                cout << life;   
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
            int row, col = 0;
            cell >> row;
            cell >> col;
            Life<Cell> life(row, col, FredkinCell());
            cell >> life;
            cout << life;

            for(int i = 1; i <= 20; ++i) {
                life.evolve();
                if(i % 4 == 0)
                    cout << life;   
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    //  Cell 1x1
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 1x1 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
            int row, col = 0;
            cell >> row;
            cell >> col;
            Life<Cell> life(row, col, FredkinCell());
            cell >> life;
            cout << life;

            for(int i = 1; i <= 1; ++i) {
                life.evolve();
                cout << life;   
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    //  Cell 10x10
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 4x4 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
            int row, col = 0;
            cell >> row;
            cell >> col;
            Life<Cell> life(row, col, FredkinCell());
            cell >> life;
            cout << life;

            for(int i = 1; i <= 5; ++i) {
                life.evolve();
                cout << life;   
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    //  Cell 10x10
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 9x9 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
            int row, col = 0;
            cell >> row;
            cell >> col;
            Life<Cell> life(row, col, FredkinCell());
            cell >> life;
            cout << life;

            for(int i = 1; i <= 10; ++i) {
                life.evolve();
                if ( i % 2 == 0)
                    cout << life;   
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    //  Cell 21x20
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 21x20 ***" << endl;
        cout << "***  Mixed Dead and Alive   ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
            int row, col = 0;
            cell >> row;
            cell >> col;
            Life<Cell> life(row, col, FredkinCell());
            cell >> life;
            cout << life;

            for(int i = 1; i <= 10; ++i) {
                life.evolve();
                cout << life;   
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}        

    // ------------------
    //  Cell 5x5
    // ------------------

    try {
        cout << "*** Life<Cell> 5x5 ***" << endl;
        cout << "***  Full Board           ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
            int row, col = 0;
            cell >> row;
            cell >> col;
            Life<Cell> life(row, col, FredkinCell());
            cell >> life;
            cout << life;

            for(int i = 1; i <= 10; ++i) {
                life.evolve();
                cout << life;   
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);} 

    return 0;}
