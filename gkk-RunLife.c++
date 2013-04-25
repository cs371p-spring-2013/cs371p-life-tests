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
        cout << "*** Life<ConwayCell> 109x69 ***" << endl << endl;

        ifstream fin("RunLifeConway.in");

        int width, height;
        fin >> height >> width;
        fin.get();

        Life<ConwayCell> life(width, height);

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                char c = fin.get();
                assert(c == '.' || c == '*');
                if (c == '*') {
                    life.set_cell(x, y, true);
                }
            }
            fin.get();
        }

        for (int i = 0; i < 10; ++i) {
            life.print();
            life.simulate(1);
        }
        life.simulate(283 - 10);
        life.print();
        life.simulate(40);
        life.print();
        life.simulate(2177);
        life.print();
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

        ifstream fin("RunLifeFredkin.in");

        int width, height;
        fin >> height >> width;
        fin.get();

        Life<FredkinCell> life(width, height);

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                char c = fin.get();
                assert (c == '-' || c == '0');
                if (c == '0')
                    life.set_cell(x, y, true);
            }
            fin.get();
        }

        life.print();
        for (int i = 0; i < 5; ++i) {
            life.simulate(1);
            life.print();
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

        ifstream fin("RunLifeCell.in");

        int width, height;
        fin >> height >> width;
        fin.get();

        Life<Cell> life(width, height);

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                char c = fin.get();
                if (c == '-')
                    life.set_cell(x, y, new FredkinCell(false));
                else if (c == '0')
                    life.set_cell(x, y, new FredkinCell(true));
                else
                    assert(false);
            }
            fin.get();
        }

        life.print();
        for (int i = 0; i < 5; ++i) {
            life.simulate(1);
            life.print();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // ConwayCell tests
    // ----------------

    try {
        cout << "*** Life<ConwayCell> Glider ***" << endl << endl;

        Life<ConwayCell> life(5, 6);
        life.set_cell(1, 0, true);
        life.set_cell(2, 1, true);
        life.set_cell(2, 2, true);
        life.set_cell(1, 2, true);
        life.set_cell(0, 2, true);

        life.print();
        for (int i = 0; i < 10; ++i) {
            life.simulate();
            life.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> Still Life ***" << endl << endl;

        Life<ConwayCell> life(7, 7);

        life.set_cell(0, 0, true);
        life.set_cell(0, 1, true);
        life.set_cell(1, 1, true);
        life.set_cell(1, 0, true);

        life.set_cell(5, 0, true);
        life.set_cell(4, 1, true);
        life.set_cell(6, 1, true);
        life.set_cell(5, 2, true);

        life.set_cell(0, 5, true);
        life.set_cell(1, 4, true);
        life.set_cell(2, 4, true);
        life.set_cell(3, 5, true);
        life.set_cell(2, 6, true);
        life.set_cell(1, 6, true);

        life.print();
        for (int i = 0; i < 3; ++i) {
            life.simulate();
            life.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> Flipper ***" << endl << endl;

        Life<ConwayCell> life(3, 3);
        life.set_cell(0, 1, true);
        life.set_cell(1, 1, true);
        life.set_cell(2, 1, true);

        life.print();
        for (int i = 0; i < 5; ++i) {
            life.simulate();
            life.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> Random ***" << endl << endl;
        srand(0);

        Life<ConwayCell> life(20, 20);
        for (int y = 0; y < 20; ++y) {
            for (int x = 0; x < 20; ++x) {
                life.set_cell(x, y, rand() % 2);
            }
        }

        life.print();
        for (int i = 0; i < 5; ++i) {
            life.simulate();
            life.print();
        }
        life.simulate(95);
        life.print();
        life.simulate(100);
        life.print();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -----------------
    // FredkinCell tests
    // -----------------

    try {
        cout << "*** Life<FredkinCell> Single ***" << endl << endl;

        Life<FredkinCell> life(11, 11);
        life.set_cell(5, 5, true);

        life.print();
        for (int i = 0; i < 10; ++i) {
            life.simulate();
            life.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> Flipper? ***" << endl << endl;

        Life<FredkinCell> life(11, 11);
        life.set_cell(4, 5, true);
        life.set_cell(5, 5, true);
        life.set_cell(6, 5, true);

        life.print();
        for (int i = 0; i < 10; ++i) {
            life.simulate();
            life.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> Star? ***" << endl << endl;

        Life<FredkinCell> life(11, 11);
        life.set_cell(4, 5, true);
        life.set_cell(6, 5, true);
        life.set_cell(5, 4, true);
        life.set_cell(5, 6, true);
        life.set_cell(5, 5, true);

        life.print();
        for (int i = 0; i < 10; ++i) {
            life.simulate();
            life.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> Random ***" << endl << endl;
        srand(0);

        Life<FredkinCell> life(20, 20);
        for (int y = 0; y < 20; ++y) {
            for (int x = 0; x < 20; ++x) {
                life.set_cell(x, y, rand() % 2);
            }
        }

        life.print();
        for (int i = 0; i < 5; ++i) {
            life.simulate();
            life.print();
        }
        life.simulate(95);
        life.print();
        life.simulate(100);
        life.print();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -----------------
    // Cell tests
    // -----------------

    try {
        cout << "*** Life<Cell> Single ***" << endl << endl;

        Life<Cell> life(11, 11);
        for (int y = 0; y < 11; ++y) {
            for (int x = 0; x < 11; ++x) {
                life.set_cell(x, y, new FredkinCell(false));
            }
        }

        life.set_cell(5, 5, new FredkinCell(true));

        life.print();
        for (int i = 0; i < 10; ++i) {
            life.simulate();
            life.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<Cell> Flipper? ***" << endl << endl;

        Life<Cell> life(11, 11);
        for (int y = 0; y < 11; ++y) {
            for (int x = 0; x < 11; ++x) {
                life.set_cell(x, y, new FredkinCell(false));
            }
        }

        life.set_cell(4, 5, new FredkinCell(true));
        life.set_cell(5, 5, new FredkinCell(true));
        life.set_cell(6, 5, new FredkinCell(true));

        life.print();
        for (int i = 0; i < 10; ++i) {
            life.simulate();
            life.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<Cell> Star? ***" << endl << endl;

        Life<Cell> life(11, 11);
        for (int y = 0; y < 11; ++y) {
            for (int x = 0; x < 11; ++x) {
                life.set_cell(x, y, new FredkinCell(false));
            }
        }

        life.set_cell(4, 5, new FredkinCell(true));
        life.set_cell(6, 5, new FredkinCell(true));
        life.set_cell(5, 4, new FredkinCell(true));
        life.set_cell(5, 6, new FredkinCell(true));
        life.set_cell(5, 5, new FredkinCell(true));

        life.print();
        for (int i = 0; i < 10; ++i) {
            life.simulate();
            life.print();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<Cell> Random ***" << endl << endl;
        srand(0);

        Life<Cell> life(20, 20);
        for (int y = 0; y < 20; ++y) {
            for (int x = 0; x < 20; ++x) {
                if (rand() % 2)
                    life.set_cell(x, y, new FredkinCell(true));
                else
                    life.set_cell(x, y, new FredkinCell(false));
            }
        }

        life.print();
        for (int i = 0; i < 5; ++i) {
            life.simulate();
            life.print();
        }
        life.simulate(95);
        life.print();
        life.simulate(100);
        life.print();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}

