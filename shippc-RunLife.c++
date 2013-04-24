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

#include "AbstractCell.h"
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Handle.h"
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
        cout << endl;
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

        // read in the file.
        std::ifstream input("RunLifeConway.in");
        int r;
        int c;
        input >> r;
        input >> c;
        input.get();    // get rid of the blank line.

        Life<ConwayCell> life(r, c, ConwayCell(false));
        char cells[70];
        for (int i = 0; i < r; ++i) {
            input.getline(cells, 70);

            for (int j = 0; j < c; ++j) {
                if (cells[j] == '*') {
                    life.place_cell(i, j, ConwayCell(true));
                }
            }
        }


        // print board.
        life.print(cout, 0);
        for (int iteration = 1; iteration <= 2500; ++iteration) {

            life.step();

            if ((iteration < 10) || (iteration == 283) || (iteration == 323) || (iteration == 2500)) {
                life.print(cout, iteration);
            }
        }

        
    }
    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }

    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
        cout << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

        // read in the file.
        std::ifstream input("RunLifeFredkin.in");
        int r;
        int c;
        input >> r;
        input >> c;
        input.get();    // get rid of the blank line.

        Life<FredkinCell> life(r, c, FredkinCell(false));
        char cells[21];
        for (int i = 0; i < r; ++i) {
            input.getline(cells, 21);

            for (int j = 0; j < c; ++j) {
                if (cells[j] == '0') {
                    life.place_cell(i, j, FredkinCell(true));
                }
            }
        }


        life.print(cout, 0);
        for (int iteration = 1; iteration <= 5; ++iteration) {
            life.step();
            life.print(cout, iteration);
        }


    }
    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }

    // ----------
    // Cell 20x20
    // ----------

    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;
        cout << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

        // read in the file.
        std::ifstream input("RunLifeCell.in");
        int r;
        int c;
        input >> r;
        input >> c;
        input.get();    // get rid of the blank line.

        Life<Cell> life(r, c, new FredkinCell(false));
        char cells[21];
        for (int i = 0; i < r; ++i) {
            input.getline(cells, 21);

            for (int j = 0; j < c; ++j) {
                if (cells[j] == '0') {
                    life.place_cell(i, j, new FredkinCell(true));
                }
            }
        }


        life.print(cout, 0);
        for (int iteration = 1; iteration <= 5; ++iteration) {
            life.step();
            life.print(cout, iteration);
        }

    }
    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }

    // ------------------
    // Conway Cell 3x3
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 3x3 ***" << endl;
        cout << endl;
        /*
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

        Life<ConwayCell> life(3, 3, ConwayCell(false));
        
        life.place_cell(0, 1, ConwayCell(true));
        life.place_cell(1, 0, ConwayCell(true));
        life.place_cell(1, 1, ConwayCell(true));
        life.place_cell(1, 2, ConwayCell(true));
        life.place_cell(2, 1, ConwayCell(true));

        life.print(cout, 0);
        for (int iteration = 1; iteration <= 5; ++iteration) {
            life.step();
            life.print(cout, iteration);
        }


    }
    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }

    // ------------------
    // Conway Cell 5x5a
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 5x5a ***" << endl;
        cout << endl;
        /*
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

        Life<ConwayCell> life(5, 5, ConwayCell(false));
        
        life.place_cell(0, 0, ConwayCell(true));
        life.place_cell(0, 1, ConwayCell(true));
        life.place_cell(0, 3, ConwayCell(true));
        life.place_cell(0, 4, ConwayCell(true));

        life.place_cell(1, 0, ConwayCell(true));
        life.place_cell(1, 1, ConwayCell(true));
        life.place_cell(1, 3, ConwayCell(true));
        life.place_cell(1, 4, ConwayCell(true));

        life.place_cell(3, 0, ConwayCell(true));
        life.place_cell(3, 1, ConwayCell(true));
        life.place_cell(3, 3, ConwayCell(true));
        life.place_cell(3, 4, ConwayCell(true));

        life.place_cell(4, 0, ConwayCell(true));
        life.place_cell(4, 1, ConwayCell(true));
        life.place_cell(4, 3, ConwayCell(true));
        life.place_cell(4, 4, ConwayCell(true));

        life.print(cout, 0);
        for (int iteration = 1; iteration <= 5; ++iteration) {
            life.step();
            life.print(cout, iteration);
        }


    }
    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }

    // ------------------
    // Conway Cell 5x5b
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 5x5b ***" << endl;
        cout << endl;
        /*
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

        Life<ConwayCell> life(5, 5, ConwayCell(false));
        
        life.place_cell(0, 0, ConwayCell(true));
        life.place_cell(0, 4, ConwayCell(true));

        life.place_cell(1, 1, ConwayCell(true));
        life.place_cell(1, 2, ConwayCell(true));
        life.place_cell(1, 3, ConwayCell(true));

        life.place_cell(2, 1, ConwayCell(true));
        life.place_cell(2, 3, ConwayCell(true));

        life.place_cell(3, 1, ConwayCell(true));
        life.place_cell(3, 2, ConwayCell(true));
        life.place_cell(3, 3, ConwayCell(true));

        life.place_cell(4, 0, ConwayCell(true));
        life.place_cell(4, 4, ConwayCell(true));

        life.print(cout, 0);
        for (int iteration = 1; iteration <= 5; ++iteration) {
            life.step();
            life.print(cout, iteration);
        }


    }
    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }

    // ------------------
    // Conway Cell 5x5c
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 5x5c ***" << endl;
        cout << endl;
        /*
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

        Life<ConwayCell> life(5, 5, ConwayCell(false));
        
        life.place_cell(0, 0, ConwayCell(true));
        life.place_cell(0, 2, ConwayCell(true));
        life.place_cell(0, 4, ConwayCell(true));

        life.place_cell(1, 1, ConwayCell(true));
        life.place_cell(1, 3, ConwayCell(true));

        life.place_cell(2, 0, ConwayCell(true));
        life.place_cell(2, 2, ConwayCell(true));
        life.place_cell(2, 4, ConwayCell(true));

        life.place_cell(3, 1, ConwayCell(true));
        life.place_cell(3, 3, ConwayCell(true));

        life.place_cell(4, 0, ConwayCell(true));
        life.place_cell(4, 2, ConwayCell(true));
        life.place_cell(4, 4, ConwayCell(true));

        life.print(cout, 0);
        for (int iteration = 1; iteration <= 5; ++iteration) {
            life.step();
            life.print(cout, iteration);
        }


    }
    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }

    // ------------------
    // Conway Cell 4x4
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 4x4 ***" << endl;
        cout << endl;
        /*
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

        Life<ConwayCell> life(4, 4, ConwayCell(false));
        
        life.place_cell(0, 1, ConwayCell(true));
        life.place_cell(0, 2, ConwayCell(true));

        life.place_cell(1, 0, ConwayCell(true));
        life.place_cell(1, 2, ConwayCell(true));
        life.place_cell(1, 3, ConwayCell(true));

        life.place_cell(2, 0, ConwayCell(true));
        life.place_cell(2, 3, ConwayCell(true));

        life.place_cell(3, 1, ConwayCell(true));
        life.place_cell(3, 2, ConwayCell(true));

        life.print(cout, 0);
        for (int iteration = 1; iteration <= 5; ++iteration) {
            life.step();
            life.print(cout, iteration);
        }


    }
    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }

    // ------------------
    // Fredkin Cell 3x3
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 3x3 ***" << endl;
        cout << endl;
        /*
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

        Life<FredkinCell> life(3, 3, FredkinCell(false));
        
        life.place_cell(0, 1, FredkinCell(true));
        life.place_cell(1, 0, FredkinCell(true));
        life.place_cell(1, 1, FredkinCell(true));
        life.place_cell(1, 2, FredkinCell(true));
        life.place_cell(2, 1, FredkinCell(true));

        life.print(cout, 0);
        for (int iteration = 1; iteration <= 5; ++iteration) {
            life.step();
            life.print(cout, iteration);
        }


    }
    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }

    // ------------------
    // Fredkin Cell 5x5a
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 5x5a ***" << endl;
        cout << endl;
        /*
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

        Life<FredkinCell> life(5, 5, FredkinCell(false));
        
        life.place_cell(0, 0, FredkinCell(true));
        life.place_cell(0, 1, FredkinCell(true));
        life.place_cell(0, 3, FredkinCell(true));
        life.place_cell(0, 4, FredkinCell(true));

        life.place_cell(1, 0, FredkinCell(true));
        life.place_cell(1, 1, FredkinCell(true));
        life.place_cell(1, 3, FredkinCell(true));
        life.place_cell(1, 4, FredkinCell(true));

        life.place_cell(3, 0, FredkinCell(true));
        life.place_cell(3, 1, FredkinCell(true));
        life.place_cell(3, 3, FredkinCell(true));
        life.place_cell(3, 4, FredkinCell(true));

        life.place_cell(4, 0, FredkinCell(true));
        life.place_cell(4, 1, FredkinCell(true));
        life.place_cell(4, 3, FredkinCell(true));
        life.place_cell(4, 4, FredkinCell(true));

        life.print(cout, 0);
        for (int iteration = 1; iteration <= 5; ++iteration) {
            life.step();
            life.print(cout, iteration);
        }


    }
    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }

    // ------------------
    // Fredkin Cell 5x5b
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 5x5b ***" << endl;
        cout << endl;
        /*
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

        Life<FredkinCell> life(5, 5, FredkinCell(false));
        
        life.place_cell(0, 0, FredkinCell(true));
        life.place_cell(0, 4, FredkinCell(true));

        life.place_cell(1, 1, FredkinCell(true));
        life.place_cell(1, 2, FredkinCell(true));
        life.place_cell(1, 3, FredkinCell(true));

        life.place_cell(2, 1, FredkinCell(true));
        life.place_cell(2, 3, FredkinCell(true));

        life.place_cell(3, 1, FredkinCell(true));
        life.place_cell(3, 2, FredkinCell(true));
        life.place_cell(3, 3, FredkinCell(true));

        life.place_cell(4, 0, FredkinCell(true));
        life.place_cell(4, 4, FredkinCell(true));

        life.print(cout, 0);
        for (int iteration = 1; iteration <= 5; ++iteration) {
            life.step();
            life.print(cout, iteration);
        }


    }
    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }

    // ------------------
    // Fredkin Cell 5x5c
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 5x5c ***" << endl;
        cout << endl;
        /*
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

        Life<FredkinCell> life(5, 5, FredkinCell(false));
        
        life.place_cell(0, 0, FredkinCell(true));
        life.place_cell(0, 2, FredkinCell(true));
        life.place_cell(0, 4, FredkinCell(true));

        life.place_cell(1, 1, FredkinCell(true));
        life.place_cell(1, 3, FredkinCell(true));

        life.place_cell(2, 0, FredkinCell(true));
        life.place_cell(2, 2, FredkinCell(true));
        life.place_cell(2, 4, FredkinCell(true));

        life.place_cell(3, 1, FredkinCell(true));
        life.place_cell(3, 3, FredkinCell(true));

        life.place_cell(4, 0, FredkinCell(true));
        life.place_cell(4, 2, FredkinCell(true));
        life.place_cell(4, 4, FredkinCell(true));

        life.print(cout, 0);
        for (int iteration = 1; iteration <= 5; ++iteration) {
            life.step();
            life.print(cout, iteration);
        }


    }
    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }

    // ------------------
    // Fredkin Cell 4x4
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 4x4 ***" << endl;
        cout << endl;
        /*
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

        Life<FredkinCell> life(4, 4, FredkinCell(false));
        
        life.place_cell(0, 1, FredkinCell(true));
        life.place_cell(0, 2, FredkinCell(true));

        life.place_cell(1, 0, FredkinCell(true));
        life.place_cell(1, 2, FredkinCell(true));
        life.place_cell(1, 3, FredkinCell(true));

        life.place_cell(2, 0, FredkinCell(true));
        life.place_cell(2, 3, FredkinCell(true));

        life.place_cell(3, 1, FredkinCell(true));
        life.place_cell(3, 2, FredkinCell(true));

        life.print(cout, 0);
        for (int iteration = 1; iteration <= 5; ++iteration) {
            life.step();
            life.print(cout, iteration);
        }


    }
    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }

    // ------------------
    // Cell 3x3
    // ------------------

    try {
        cout << "*** Life<Cell> 3x3 ***" << endl;
        cout << endl;
        /*
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

        Life<Cell> life(3, 3, new FredkinCell(false));
        
        life.place_cell(0, 1, new FredkinCell(true));
        life.place_cell(1, 0, new FredkinCell(true));
        life.place_cell(1, 1, new FredkinCell(true));
        life.place_cell(1, 2, new FredkinCell(true));
        life.place_cell(2, 1, new FredkinCell(true));

        life.print(cout, 0);
        for (int iteration = 1; iteration <= 5; ++iteration) {
            life.step();
            life.print(cout, iteration);
        }


    }
    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }

    // ------------------
    // Cell 5x5a
    // ------------------

    try {
        cout << "*** Life<Cell> 5x5a ***" << endl;
        cout << endl;
        /*
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

        Life<Cell> life(5, 5, new FredkinCell(false));
        
        life.place_cell(0, 0, new FredkinCell(true));
        life.place_cell(0, 1, new FredkinCell(true));
        life.place_cell(0, 3, new FredkinCell(true));
        life.place_cell(0, 4, new FredkinCell(true));

        life.place_cell(1, 0, new FredkinCell(true));
        life.place_cell(1, 1, new FredkinCell(true));
        life.place_cell(1, 3, new FredkinCell(true));
        life.place_cell(1, 4, new FredkinCell(true));

        life.place_cell(3, 0, new FredkinCell(true));
        life.place_cell(3, 1, new FredkinCell(true));
        life.place_cell(3, 3, new FredkinCell(true));
        life.place_cell(3, 4, new FredkinCell(true));

        life.place_cell(4, 0, new FredkinCell(true));
        life.place_cell(4, 1, new FredkinCell(true));
        life.place_cell(4, 3, new FredkinCell(true));
        life.place_cell(4, 4, new FredkinCell(true));

        life.print(cout, 0);
        for (int iteration = 1; iteration <= 5; ++iteration) {
            life.step();
            life.print(cout, iteration);
        }


    }
    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }

    // ------------------
    // Cell 5x5b
    // ------------------

    try {
        cout << "*** Life<Cell> 5x5b ***" << endl;
        cout << endl;
        /*
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

        Life<Cell> life(5, 5, new FredkinCell(false));
        
        life.place_cell(0, 0, new FredkinCell(true));
        life.place_cell(0, 4, new FredkinCell(true));

        life.place_cell(1, 1, new FredkinCell(true));
        life.place_cell(1, 2, new FredkinCell(true));
        life.place_cell(1, 3, new FredkinCell(true));

        life.place_cell(2, 1, new FredkinCell(true));
        life.place_cell(2, 3, new FredkinCell(true));

        life.place_cell(3, 1, new FredkinCell(true));
        life.place_cell(3, 2, new FredkinCell(true));
        life.place_cell(3, 3, new FredkinCell(true));

        life.place_cell(4, 0, new FredkinCell(true));
        life.place_cell(4, 4, new FredkinCell(true));

        life.print(cout, 0);
        for (int iteration = 1; iteration <= 5; ++iteration) {
            life.step();
            life.print(cout, iteration);
        }


    }
    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }

    // ------------------
    // Cell 5x5c
    // ------------------

    try {
        cout << "*** Life<Cell> 5x5c ***" << endl;
        cout << endl;
        /*
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

        Life<Cell> life(5, 5, new FredkinCell(false));
        
        life.place_cell(0, 0, new FredkinCell(true));
        life.place_cell(0, 2, new FredkinCell(true));
        life.place_cell(0, 4, new FredkinCell(true));

        life.place_cell(1, 1, new FredkinCell(true));
        life.place_cell(1, 3, new FredkinCell(true));

        life.place_cell(2, 0, new FredkinCell(true));
        life.place_cell(2, 2, new FredkinCell(true));
        life.place_cell(2, 4, new FredkinCell(true));

        life.place_cell(3, 1, new FredkinCell(true));
        life.place_cell(3, 3, new FredkinCell(true));

        life.place_cell(4, 0, new FredkinCell(true));
        life.place_cell(4, 2, new FredkinCell(true));
        life.place_cell(4, 4, new FredkinCell(true));

        life.print(cout, 0);
        for (int iteration = 1; iteration <= 5; ++iteration) {
            life.step();
            life.print(cout, iteration);
        }


    }
    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }

    // ------------------
    // Cell 4x4
    // ------------------

    try {
        cout << "*** Life<Cell> 4x4 ***" << endl;
        cout << endl;
        /*
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

        Life<Cell> life(4, 4, new FredkinCell(false));
        
        life.place_cell(0, 1, new ConwayCell(true));
        life.place_cell(0, 2, new ConwayCell(true));

        life.place_cell(1, 0, new ConwayCell(true));
        life.place_cell(1, 2, new ConwayCell(true));
        life.place_cell(1, 3, new ConwayCell(true));

        life.place_cell(2, 0, new FredkinCell(true));
        life.place_cell(2, 3, new FredkinCell(true));

        life.place_cell(3, 1, new FredkinCell(true));
        life.place_cell(3, 2, new FredkinCell(true));

        life.print(cout, 0);
        for (int iteration = 1; iteration <= 5; ++iteration) {
            life.step();
            life.print(cout, iteration);
        }


    }
    catch (const invalid_argument&) {
        assert(false);
    }
    catch (const out_of_range&) {
        assert(false);
    }



    return 0;
}
