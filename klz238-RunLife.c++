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

#include <fstream>   // ifstream
#include <sstream>   // stringstream

#include "Life.h"
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
        int width = 0, height = 0;
        char w = 0;
        ifstream fin("RunLifeConway.in", ifstream::in);
        fin >> height >> width;
        Life<ConwayCell> l(width, height);
        for(int r = 0; r < height; ++r)
        {
            for(int c = 0; c < width; ++c)
            {
                fin >> w;
                switch (w) {
                    case '.':
                        l.pushCell(ConwayCell(STATE_DEAD));
                        break;
                    case '*':
                        l.pushCell(ConwayCell(STATE_ALIVE));
                }
            }
        }
        fin.close();
        for(int i = 0; i < 10; ++i) {
            cout << endl;
            l.board(cout);
            l.simulate(1);
        }
        cout << endl;
        l.simulate(273);
        l.board(cout);
        cout << endl;
        l.simulate(40);
        l.board(cout);
        cout << endl;
        l.simulate(2500-40-273-10);
        l.board(cout);
        cout << endl; // LAST THING TO DO IN BLOCK
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
        int width = 0, height = 0;
        char w = 0;
        ifstream fin("RunLifeFredkin.in", ifstream::in);
        fin >> height >> width;
        Life<FredkinCell> l(width, height);
        for(int r = 0; r < height; ++r)
        {
            for(int c = 0; c < width; ++c)
            {
                fin >> w;
                switch (w) {
                    case '-':
                        l.pushCell(FredkinCell(STATE_DEAD));
                        break;
                    case '0':
                        l.pushCell(FredkinCell(STATE_ALIVE));
                }
            }
        }
        fin.close();
        for(int i = 0; i < 5; ++i)
        {
            cout << endl;
            l.board(cout);
            l.simulate(1);
        }
        cout << endl << l;
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
        int width = 0, height = 0;
        char w = 0;
        ifstream fin("RunLifeCell.in", ifstream::in);
        fin >> height >> width;
        Life<Cell> l(width, height);
        for(int r = 0; r < height; ++r)
        {
            for(int c = 0; c < width; ++c)
            {
                fin >> w;
                switch(w) {
                    case '-':
                        l.pushCell(new FredkinCell(STATE_DEAD));
                        break;
                    case '0':
                        l.pushCell(new FredkinCell(STATE_ALIVE));
                }
            }
        }
        fin.close();
        for(int i = 0; i < 5; ++i)
        {
            cout << endl;
            l.board(cout);
            l.simulate(1);
        }
        cout << endl << l;
        cout << endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------------
    // ConwayCell 6x5
    // --------------

    try {
        cout << "*** Life<ConwayCell> 6x5 ***" << endl;
        istringstream iss;
        int width = 0, height = 0;
        char a = 0;
        iss.str("6\n"
                "5\n"
                "*.*.*\n"
                ".*.*.\n"
                "*.*.*\n"
                ".*.*.\n"
                "*.*.*\n"
                ".*.*.");
        iss >> height >> width;
        Life<ConwayCell> l(width,height);
        for(int r = 0; r < height; ++r)
        {
            for(int c = 0; c < width; ++c)
            {
                iss >> a;
                switch (a) {
                    case '.':
                        l.pushCell(ConwayCell(STATE_DEAD));
                        break;
                    case '*':
                        l.pushCell(ConwayCell(STATE_ALIVE));
                        break;
                }
            }
        }
        for(int i = 0; i <= 5; ++i)
        {
            cout << endl;
            l.board(cout);
            l.simulate(1);
        }
        cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // ConwayCell 10x10
    // ----------------

    try {
        cout << "*** Life<ConwayCell> 10x10 ***" << endl;
        istringstream iss;
        int width = 0, height = 0;
        char a = 0;
        iss.str("10\n"
                "10\n"
                "..........\n"
                "..........\n"
                "..........\n"
                "..........\n"
                "..........\n"
                "..........\n"
                "..........\n"
                ".......***\n"
                ".......*..\n"
                "........*.");
        iss >> height >> width;
        Life<ConwayCell> l(width,height);
        for(int r = 0; r < height; ++r)
        {
            for(int c = 0; c < width; ++c)
            {
                iss >> a;
                switch (a) {
                    case '.':
                        l.pushCell(ConwayCell(STATE_DEAD));
                        break;
                    case '*':
                        l.pushCell(ConwayCell(STATE_ALIVE));
                        break;
                }
            }
        }
        for(int i = 0; i <= 10; ++i)
        {
            cout << endl;
            l.board(cout);
            l.simulate(4);
        }
        cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // ConwayCell 15x15
    // ----------------

    try {
        cout << "*** Life<ConwayCell> 15x15 ***" << endl;
        istringstream iss;
        int width = 0, height = 0;
        char a = 0;
        iss.str("15\n"
                "15\n"
                "...............\n"
                "...............\n"
                "...............\n"
                "...............\n"
                "...............\n"
                "...............\n"
                ".......*.......\n"
                "......***......\n"
                "......*.*......\n"
                ".......*.......\n"
                "...............\n"
                "...............\n"
                "...............\n"
                "...............\n"
                "...............");
        iss >> height >> width;
        Life<ConwayCell> l(width,height);
        for(int r = 0; r < height; ++r)
        {
            for(int c = 0; c < width; ++c)
            {
                iss >> a;
                switch (a) {
                    case '.':
                        l.pushCell(ConwayCell(STATE_DEAD));
                        break;
                    case '*':
                        l.pushCell(ConwayCell(STATE_ALIVE));
                        break;
                }
            }
        }
        for(int i = 0; i <= 20; ++i)
        {
            cout << endl;
            l.board(cout);
            l.simulate(1);
        }
        cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // ConwayCell 15x15
    // ----------------

    try {
        cout << "*** Life<ConwayCell> 15x15 ***" << endl;
        istringstream iss;
        int width = 0, height = 0;
        char a = 0;
        iss.str("15\n"
                "15\n"
                "...............\n"
                "...............\n"
                "...............\n"
                "...............\n"
                "...............\n"
                ".....*.*.*.....\n"
                ".....*...*.....\n"
                ".....*...*.....\n"
                ".....*...*.....\n"
                ".....*.*.*.....\n"
                "...............\n"
                "...............\n"
                "...............\n"
                "...............\n"
                "...............");
        iss >> height >> width;
        Life<ConwayCell> l(width,height);
        for(int r = 0; r < height; ++r)
        {
            for(int c = 0; c < width; ++c)
            {
                iss >> a;
                switch (a) {
                    case '.':
                        l.pushCell(ConwayCell(STATE_DEAD));
                        break;
                    case '*':
                        l.pushCell(ConwayCell(STATE_ALIVE));
                        break;
                }
            }
        }
        for(int i = 0; i < 5; ++i)
        {
            cout << endl;
            l.board(cout);
            l.simulate(1);
        }
        for(int i = 0; i <= 10; ++i)
        {
            cout << endl;
            l.board(cout);
            l.simulate(5);
        }
        cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ---------------
    // ConwayCell 9x16
    // ---------------

    try {
        cout << "*** Life<ConwayCell> 9x16 ***" << endl;
        istringstream iss;
        int width = 0, height = 0;
        char a = 0;
        iss.str("9\n"
                "16\n"
                "................\n"
                "................\n"
                "................\n"
                "................\n"
                "...**********...\n"
                "................\n"
                "................\n"
                "................\n"
                "................");
        iss >> height >> width;
        Life<ConwayCell> l(width,height);
        for(int r = 0; r < height; ++r)
        {
            for(int c = 0; c < width; ++c)
            {
                iss >> a;
                switch (a) {
                    case '.':
                        l.pushCell(ConwayCell(STATE_DEAD));
                        break;
                    case '*':
                        l.pushCell(ConwayCell(STATE_ALIVE));
                        break;
                }
            }
        }
        for(int i = 0; i <= 17; ++i)
        {
            cout << endl;
            l.board(cout);
            l.simulate(1);
        }
        cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ---------------
    // FredkinCell 6x5
    // ---------------

    try {
        cout << "*** Life<FredkinCell> 6x5 ***" << endl;
        istringstream iss;
        int width = 0, height = 0;
        char a = 0;
        iss.str("6\n"
                "5\n"
                "-----\n"
                "-0-0-\n"
                "--0--\n"
                "--0--\n"
                "-0-0-\n"
                "-----");
        iss >> height >> width;
        Life<FredkinCell> l(width,height);
        for(int r = 0; r < height; ++r)
        {
            for(int c = 0; c < width; ++c)
            {
                iss >> a;
                switch (a) {
                    case '-':
                        l.pushCell(FredkinCell(STATE_DEAD));
                        break;
                    case '0':
                        l.pushCell(FredkinCell(STATE_ALIVE));
                        break;
                }
            }
        }
        for(int i = 0; i < 5; ++i)
        {
            cout << endl;
            l.board(cout);
            l.simulate(1);
        }
        for(int i = 1; i <= 19; ++i)
        {
            cout << endl;
            l.board(cout);
            l.simulate(5);
        }
        cout << l;
        cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ---------------
    // FredkinCell 5x5
    // ---------------

    try {
        cout << "*** Life<FredkinCell> 5x5 ***" << endl;
        istringstream iss;
        int width = 0, height = 0;
        char a = 0;
        iss.str("5\n"
                "5\n"
                "0---0\n"
                "-----\n"
                "-----\n"
                "-----\n"
                "0---0");
        iss >> height >> width;
        Life<FredkinCell> l(width,height);
        for(int r = 0; r < height; ++r)
        {
            for(int c = 0; c < width; ++c)
            {
                iss >> a;
                switch (a) {
                    case '-':
                        l.pushCell(FredkinCell(STATE_DEAD));
                        break;
                    case '0':
                        l.pushCell(FredkinCell(STATE_ALIVE));
                        break;
                }
            }
        }
        for(int i = 0; i < 3; ++i)
        {
            cout << endl;
            l.board(cout);
            l.simulate(1);
        }
        l.simulate(17);
        cout << endl << l;
        cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ---------------
    // FredkinCell 5x5
    // ---------------

    try {
        cout << "*** Life<FredkinCell> 5x5 ***" << endl;
        istringstream iss;
        int width = 0, height = 0;
        char a = 0;
        iss.str("5\n"
                "5\n"
                "0---0\n"
                "-----\n"
                "--0--\n"
                "-----\n"
                "0---0");
        iss >> height >> width;
        Life<FredkinCell> l(width,height);
        for(int r = 0; r < height; ++r)
        {
            for(int c = 0; c < width; ++c)
            {
                iss >> a;
                switch (a) {
                    case '-':
                        l.pushCell(FredkinCell(STATE_DEAD));
                        break;
                    case '0':
                        l.pushCell(FredkinCell(STATE_ALIVE));
                        break;
                }
            }
        }
        for(int i = 0; i < 10; ++i)
        {
            cout << endl;
            l.board(cout);
            l.simulate(1);
        }
        cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -----------------
    // FredkinCell 10x10
    // -----------------

    try {
        cout << "*** Life<FredkinCell> 10x10 ***" << endl;
        istringstream iss;
        int width = 0, height = 0;
        char a = 0;
        iss.str("10\n"
                "10\n"
                "0---00---0\n"
                "----------\n"
                "--0----0--\n"
                "----------\n"
                "0---00---0\n"
                "0---00---0\n"
                "----------\n"
                "--0----0--\n"
                "----------\n"
                "0---00---0\n");
        iss >> height >> width;
        Life<FredkinCell> l(width,height);
        for(int r = 0; r < height; ++r)
        {
            for(int c = 0; c < width; ++c)
            {
                iss >> a;
                switch (a) {
                    case '-':
                        l.pushCell(FredkinCell(STATE_DEAD));
                        break;
                    case '0':
                        l.pushCell(FredkinCell(STATE_ALIVE));
                        break;
                }
            }
        }
        for(int i = 0; i < 10; ++i)
        {
            cout << endl;
            l.board(cout);
            l.simulate(1);
        }
        cout << endl << l;
        cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -----------------
    // FredkinCell 11x11
    // -----------------

    try {
        cout << "*** Life<FredkinCell> 11x11 ***" << endl;
        istringstream iss;
        int width = 0, height = 0;
        char a = 0;
        iss.str("11\n"
                "11\n"
                "0----0----0\n"
                "-----------\n"
                "--0--0--0--\n"
                "-----------\n"
                "----0-0----\n"
                "0-0-----0-0\n"
                "----0-0----\n"
                "-----------\n"
                "--0--0--0--\n"
                "-----------\n"
                "0----0----0\n");
        iss >> height >> width;
        Life<FredkinCell> l(width,height);
        for(int r = 0; r < height; ++r)
        {
            for(int c = 0; c < width; ++c)
            {
                iss >> a;
                switch (a) {
                    case '-':
                        l.pushCell(FredkinCell(STATE_DEAD));
                        break;
                    case '0':
                        l.pushCell(FredkinCell(STATE_ALIVE));
                        break;
                }
            }
        }
        for(int i = 0; i < 10; ++i)
        {
            cout << endl;
            l.board(cout);
            l.simulate(1);
        }
        cout << endl << l;
        cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------
    // Cell 6x5
    // --------

    try {
        cout << "*** Life<Cell> 6x5 ***" << endl;
        istringstream iss;
        int width = 0, height = 0;
        char a = 0;
        iss.str("6\n"
                "5\n"
                "-----\n"
                "-0-0-\n"
                "--0--\n"
                "--0--\n"
                "-0-0-\n"
                "-----");
        iss >> height >> width;
        Life<Cell> l(width,height);
        for(int r = 0; r < height; ++r)
        {
            for(int c = 0; c < width; ++c)
            {
                iss >> a;
                switch (a) {
                    case '-':
                        l.pushCell(new FredkinCell(STATE_DEAD));
                        break;
                    case '0':
                        l.pushCell(new FredkinCell(STATE_ALIVE));
                        break;
                }
            }
        }
        for(int i = 0; i < 5; ++i)
        {
            cout << endl;
            l.board(cout);
            l.simulate(1);
        }
        for(int i = 1; i <= 3; ++i)
        {
            cout << endl;
            l.board(cout);
            l.simulate(5);
        }
        cout << endl << l;
        cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------
    // Cell 6x5
    // --------

    try {
        cout << "*** Life<Cell> 6x5 ***" << endl;
        istringstream iss;
        int width = 0, height = 0;
        char a = 0;
        iss.str("6\n"
                "5\n"
                "0---0\n"
                "-0-0-\n"
                "--0--\n"
                "0-0-0\n"
                "-0-0-\n"
                "0---0");
        iss >> height >> width;
        Life<Cell> l(width,height);
        for(int r = 0; r < height; ++r)
        {
            for(int c = 0; c < width; ++c)
            {
                iss >> a;
                switch (a) {
                    case '-':
                        l.pushCell(new FredkinCell(STATE_DEAD));
                        break;
                    case '0':
                        l.pushCell(new FredkinCell(STATE_ALIVE));
                        break;
                }
            }
        }
        for(int i = 0; i < 5; ++i)
        {
            cout << endl;
            l.board(cout);
            l.simulate(1);
        }
        for(int i = 1; i <= 3; ++i)
        {
            cout << endl;
            l.board(cout);
            l.simulate(5);
        }
        cout << endl << l;
        cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------
    // Cell 2x1
    // --------

    try {
        cout << "*** Life<Cell> 2x1 ***" << endl;
        istringstream iss;
        ostringstream oss;
        iss.str("2\n"
                "1\n"
                "0\n"
                "-\n");
        int width = 0, height = 0;
        char a = 0;
        iss >> height >> width;
        Life<Cell> l(width,height);
        for(int r = 0; r < height; ++r)
        {
            for(int c = 0; c < width; ++c)
            {
                iss >> a;
                switch (a) {
                    case '-':
                        l.pushCell(new FredkinCell(STATE_DEAD));
                        break;
                    case '0':
                        l.pushCell(new FredkinCell(STATE_ALIVE));
                        break;
                }
            }
        }
        for(int i = 0; i < 5; ++i)
        {
            cout << endl;
            l.board(cout);
            l.simulate(1);
        }
        cout << endl << l;
        cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------
    // Cell 2x2
    // --------

    try {
        cout << "*** Life<Cell> 2x2 ***" << endl;
        istringstream iss;
        ostringstream oss;
        iss.str("2\n"
                "2\n"
                "00\n"
                "-0\n");
        int width = 0, height = 0;
        char a = 0;
        iss >> height >> width;
        Life<Cell> l(width,height);
        for(int r = 0; r < height; ++r)
        {
            for(int c = 0; c < width; ++c)
            {
                iss >> a;
                switch (a) {
                    case '-':
                        l.pushCell(new FredkinCell(STATE_DEAD));
                        break;
                    case '0':
                        l.pushCell(new FredkinCell(STATE_ALIVE));
                        break;
                }
            }
        }
        for(int i = 0; i < 5; ++i)
        {
            cout << endl;
            l.board(cout);
            l.simulate(1);
        }
        cout << endl << l;
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
        istringstream iss;
        ostringstream oss;
        iss.str("20\n"
                "20\n"
                "--------------------\n"
                "-000000000000000000-\n"
                "--------------------\n"
                "--------------------\n"
                "--------------------\n"
                "--------------------\n"
                "--------------------\n"
                "--------------------\n"
                "--------------------\n"
                "--------------------\n"
                "--------------------\n"
                "--------------------\n"
                "--------------------\n"
                "--------------------\n"
                "--------------------\n"
                "--------------------\n"
                "--------------------\n"
                "--------------------\n"
                "-000000000000000000-\n"
                "--------------------\n");
        int width = 0, height = 0;
        char a = 0;
        iss >> height >> width;
        Life<Cell> l(width,height);
        for(int r = 0; r < height; ++r)
        {
            for(int c = 0; c < width; ++c)
            {
                iss >> a;
                switch (a) {
                    case '-':
                        l.pushCell(new FredkinCell(STATE_DEAD));
                        break;
                    case '0':
                        l.pushCell(new FredkinCell(STATE_ALIVE));
                        break;
                }
            }
        }
        for(int i = 0; i < 5; ++i)
        {
            cout << endl;
            l.board(cout);
            l.simulate(1);
        }
        cout << endl << l;
        cout << endl;    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
