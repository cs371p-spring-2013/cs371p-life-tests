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
#include <iostream>

#include "Life.h"
#include "AbstractCell.h"
#include "ConwayCell.h"



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
        cout << "*** Life<ConwayCell> 109x69 ***" << endl << endl;

        int x, y;

        ifstream infile;
        infile.open("RunLifeConway.in");
        infile >> y >> x;
        Life<ConwayCell> life1 (x, y, ConwayCell(false));

        life1.populate(infile);

        infile.close();

        life1.print();
        for(int i = 0; i < 283; ++i)        
            life1.simulate();
        life1.print();
        for(int i = 0; i < 40; ++i) 
            life1.simulate();
        life1.print();
        for(int i = 0; i < 2177; ++i)
            life1.simulate();
        life1.print();


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
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl << endl;

        int x, y;

        ifstream infile;
        infile.open("RunLifeFredkin.in");
        infile >> y >> x;
        Life<FredkinCell> life2 (x, y, FredkinCell(false));

        life2.populate(infile);

        infile.close();

        life2.print();
        for(int i = 0; i < 5; ++i) {
            life2.simulate();
            life2.print();
        }

        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


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
        int x, y;

        ifstream infile;
        infile.open("RunLifeCell.in");
        infile >> y >> x;
        Life<Cell> life3 (x, y, new FredkinCell(false));

        life3.populate(infile);
        infile.close();

        life3.print();
        for(int i = 0; i < 5; ++i) {
            life3.simulate();
            life3.print();
        }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // --------------------------
    // Conway Cell 20x20 (Glider)
    // --------------------------

    try {
        cout << "*** Life<ConwayCell> 20x20 : Glider ***" << endl << endl;

        Life<ConwayCell> life (20, 20, ConwayCell(false));

        life.setCell(1, 0);
        life.setCell(2, 1);
        life.setCell(0, 2);
        life.setCell(1, 2);
        life.setCell(2, 2);

        life.print();
        for(int i = 0; i < 5; ++i) {
            life.simulate();
            life.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------------------------------
    // Conway Cell 20x20 (Small Exploder)
    // ----------------------------------

    try {
        cout << "*** Life<ConwayCell> 20x20 : Small Exploder ***" << endl << endl;

        Life<ConwayCell> life (20, 20, ConwayCell(false));

        life.setCell(10, 8);
        life.setCell(9, 9);
        life.setCell(10, 9);
        life.setCell(11, 9);
        life.setCell(9, 10);
        life.setCell(11, 10);
        life.setCell(10, 11);

        life.print();
        for(int i = 0; i < 5; ++i) {
            life.simulate();
            life.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ---------------
    // Conway Cell 0x0
    // ---------------

    try {
        cout << "*** Life<ConwayCell> 0x0 ***" << endl << endl;

        Life<ConwayCell> life (0, 0, ConwayCell(false));

        life.print();
        for(int i = 0; i < 5; ++i) {
            life.simulate();
            life.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ---------------
    // Conway Cell 1x1
    // ---------------

    try {
        cout << "*** Life<ConwayCell> 1x1 ***" << endl << endl;

        Life<ConwayCell> life (1, 1, ConwayCell(false));

        life.print();

        for(int i = 0; i < 5; ++i) {
            life.simulate();
            life.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------------------
    // Conway Cell 6x6 (Toad)
    // ----------------------

    try {
        cout << "*** Life<ConwayCell> 6x6 : Toad ***" << endl << endl;

        Life<ConwayCell> life (6, 6, ConwayCell(false));

        life.setCell(2, 2);
        life.setCell(3, 2);
        life.setCell(4, 2);
        life.setCell(1, 3);
        life.setCell(2, 3);
        life.setCell(3, 3);

        life.print();
        for(int i = 0; i < 5; ++i) {
            life.simulate();
            life.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------------
    // Fredkin Cell 0x0
    // ----------------

    try {
        cout << "*** Life<FredkinCell> 0x0 ***" << endl << endl;

        Life<FredkinCell> life (0, 0, FredkinCell(false));

        life.print();
        for(int i = 0; i < 5; ++i) {
            life.simulate();
            life.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------------
    // Fredkin Cell 1x1
    // ----------------

    try {
        cout << "*** Life<FredkinCell> 1x1 ***" << endl << endl;

        Life<FredkinCell> life (1, 1, FredkinCell(false));

        life.print();
        for(int i = 0; i < 5; ++i) {
            life.simulate();
            life.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // --------------------------
    // Fredkin Cell 20x20 (Cross)
    // --------------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 : Cross ***" << endl << endl;

        Life<FredkinCell> life (20, 20, FredkinCell(false));

        life.setCell(10, 9);
        life.setCell(10, 10);
        life.setCell(10, 11);
        life.setCell(11, 10);
        life.setCell(9, 10);

        life.print();
        for(int i = 0; i < 5; ++i) {
            life.simulate();
            life.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ---------------------------------
    // Fredkin Cell 20x20 (Longer Cross)
    // ---------------------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 : Longer Cross ***" << endl << endl;

        Life<FredkinCell> life (20, 20, FredkinCell(false));

        life.setCell(10, 9);
        life.setCell(10, 10);
        life.setCell(10, 11);
        life.setCell(11, 10);
        life.setCell(9, 10);

        life.setCell(8, 10);
        life.setCell(12, 10);
        life.setCell(10, 8);
        life.setCell(10, 12);

        life.print();
        for(int i = 0; i < 5; ++i) {
            life.simulate();
            life.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // -------------------------
    // Fredkin Cell 20x20 (Ring)
    // -------------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 : Ring ***" << endl << endl;

        Life<FredkinCell> life (20, 20, FredkinCell(false));

        life.setCell(8, 8);
        life.setCell(9, 8);
        life.setCell(10, 8);
        life.setCell(11, 8);
        life.setCell(7, 9);
        life.setCell(8, 9);
        life.setCell(11, 9);
        life.setCell(12, 9);
        life.setCell(7, 10);
        life.setCell(12, 10);
        life.setCell(7, 11);
        life.setCell(12, 11);
        life.setCell(8, 13);
        life.setCell(9, 13);
        life.setCell(10, 13);
        life.setCell(11, 13);
        life.setCell(7, 12);
        life.setCell(8, 12);
        life.setCell(11, 12);
        life.setCell(12, 12);

        life.print();
        for(int i = 0; i < 5; ++i) {
            life.simulate();
            life.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // --------
    // Cell 0x0
    // --------

    try {
        cout << "*** Life<Cell> 0x0 ***" << endl << endl;

        Life<Cell> life (0, 0, new FredkinCell(false));

        life.print();
        for(int i = 0; i < 5; ++i) {
            life.simulate();
            life.print();
        }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------
    // Cell 1x1
    // --------

    try {
        cout << "*** Life<Cell> 1x1 ***" << endl << endl;

        Life<Cell> life (1, 1, new FredkinCell(false));

        life.print();
        for(int i = 0; i < 5; ++i) {
            life.simulate();
            life.print();
        }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -----------------
    // Cell 20x20 (Ring)
    // -----------------

    try {
        cout << "*** Life<Cell> 20x20 : Ring***" << endl << endl;

        Life<Cell> life (20, 20, new FredkinCell(false));

        life.setCell(8, 7);
        life.setCell(9, 7);
        life.setCell(10, 7);
        life.setCell(11, 7);
        life.setCell(7, 8);
        life.setCell(8, 8);
        life.setCell(11, 8);
        life.setCell(12, 8);
        life.setCell(7, 9);
        life.setCell(12, 9);
        life.setCell(7, 10);
        life.setCell(12, 10);
        life.setCell(8, 12);
        life.setCell(9, 12);
        life.setCell(10, 12);
        life.setCell(11, 12);
        life.setCell(7, 11);
        life.setCell(8, 11);
        life.setCell(11, 11);
        life.setCell(12, 11);

        life.print();
        for(int i = 0; i < 50; ++i) {
            life.simulate();
            if((i+1)%10 == 0) life.print();
        }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // -----------------
    // Cell 20x20 (Full)
    // -----------------

    try {
        cout << "*** Life<Cell> 20x20 : Full***" << endl << endl;

        Life<Cell> life (20, 20, new FredkinCell(true));

        life.print();
        for(int i = 0; i < 50; ++i) {
            life.simulate();
            if((i+1)%10 == 0) life.print();
        }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // -----------------
    // Cell 50x50 (Full)
    // -----------------

    try {
        cout << "*** Life<Cell> 50x50 : Full***" << endl << endl;

        Life<Cell> life (50, 50, new FredkinCell(true));

        life.print();
        for(int i = 0; i < 1000; ++i) {
            life.simulate();
            if((i+1)%200 == 0) life.print();
        }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;
}
