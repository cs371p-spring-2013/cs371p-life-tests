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
#include <sstream>

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
        Life<ConwayCell> newLife;
        std::ifstream ifs ("RunLifeConway.in", std::ifstream::in);
        newLife.read(ifs);
        for (int i = 0; i < 10; ++i) {
            newLife.print(i);
            newLife.nextGen();
        }
        for (int i = 0; i < 283; ++i) {
            newLife.nextGen();
        }
        newLife.print(283);
        for (int i = 0; i < 40; ++i) {
            newLife.nextGen();
        }
        newLife.print(323);
        for (int i = 0; i < 2177; ++i) {
            newLife.nextGen();
        }
        newLife.print(2500);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ConwayCell 1
    try {
        cout << "*** Life<ConwayCell> 1x1 ***" << endl;
        Life<ConwayCell> newLife;
        std::istringstream r ("1\n1\n*");
        newLife.read(r);
        for (int i = 0; i < 2; ++i) {
            newLife.print(i);
            newLife.nextGen();
        }
        newLife.print(2);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ConwayCell 2
    try {
        cout << "*** Life<ConwayCell> 2x2 ***" << endl;
        Life<ConwayCell> newLife;
        std::istringstream r ("2\n2\n*.\n.*");
        newLife.read(r);
        for (int i = 0; i < 2; ++i) {
            newLife.print(i);
            newLife.nextGen();
        }
        newLife.print(2);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ConwayCell 3
    try {
        cout << "*** Life<ConwayCell> 2x2 ***" << endl;
        Life<ConwayCell> newLife;
        std::istringstream r ("2\n2\n**\n**");
        newLife.read(r);
        for (int i = 0; i < 2; ++i) {
            newLife.print(i);
            newLife.nextGen();
        }
        newLife.print(2);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ConwayCell 4
    try {
        cout << "*** Life<ConwayCell> 2x4 ***" << endl;
        Life<ConwayCell> newLife;
        std::istringstream r ("2\n4\n*..*\n.**.");
        newLife.read(r);
        for (int i = 0; i < 3; ++i) {
            newLife.print(i);
            newLife.nextGen();
        }
        newLife.print(3);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ConwayCell 5
    try {
        cout << "*** Life<ConwayCell> 4x2 ***" << endl;
        Life<ConwayCell> newLife;
        std::istringstream r ("4\n2\n*.\n.*\n*.\n.*");
        newLife.read(r);
        for (int i = 0; i < 3; ++i) {
            newLife.print(i);
            newLife.nextGen();
        }
        newLife.print(3);
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
        Life<FredkinCell> newLife;
        std::ifstream ifs ("RunLifeFredkin.in", std::ifstream::in);
        newLife.read(ifs);
        for (int i = 0; i < 5; ++i) {
            newLife.print(i);
            newLife.nextGen();
        }
        newLife.print(5);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // FredkinCell 1
    try {
        cout << "*** Life<FredkinCell> 1x1 ***" << endl;
        Life<FredkinCell> newLife;
        std::istringstream r ("1\n1\n0");
        newLife.read(r);
        for (int i = 0; i < 2; ++i) {
            newLife.print(i);
            newLife.nextGen();
        }
        newLife.print(2);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // FredkinCell 2
    try {
        cout << "*** Life<FredkinCell> 2x2 ***" << endl;
        Life<FredkinCell> newLife;
        std::istringstream r ("2\n2\n-0\n0-");
        newLife.read(r);
        for (int i = 0; i < 2; ++i) {
            newLife.print(i);
            newLife.nextGen();
        }
        newLife.print(2);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // FredkinCell 3
    try {
        cout << "*** Life<FredkinCell> 2x2 ***" << endl;
        Life<FredkinCell> newLife;
        std::istringstream r ("2\n2\n00\n00");
        newLife.read(r);
        for (int i = 0; i < 2; ++i) {
            newLife.print(i);
            newLife.nextGen();
        }
        newLife.print(2);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // FredkinCell 4
    try {
        cout << "*** Life<FredkinCell> 2x4 ***" << endl;
        Life<FredkinCell> newLife;
        std::istringstream r ("2\n4\n0--0\n-00-");
        newLife.read(r);
        for (int i = 0; i < 3; ++i) {
            newLife.print(i);
            newLife.nextGen();
        }
        newLife.print(3);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // FredkinCell 5
    try {
        cout << "*** Life<FredkinCell> 4x2 ***" << endl;
        Life<FredkinCell> newLife;
        std::istringstream r ("4\n2\n0-\n-0\n0-\n-0");
        newLife.read(r);
        for (int i = 0; i < 3; ++i) {
            newLife.print(i);
            newLife.nextGen();
        }
        newLife.print(3);
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
        Life<Cell> newLife;
        std::ifstream ifs ("RunLifeCell.in", std::ifstream::in);
        newLife.read(ifs);
        for (int i = 0; i < 5; ++i) {
            newLife.print(i);
            newLife.nextGen();
        }
        newLife.print(5);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // Cell 1
    try {
        cout << "*** Life<Cell> 1x1 ***" << endl;
        Life<Cell> newLife;
        std::istringstream r ("1\n1\n0");
        newLife.read(r);
        for (int i = 0; i < 2; ++i) {
            newLife.print(i);
            newLife.nextGen();
        }
        newLife.print(2);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // Cell 2
    try {
        cout << "*** Life<Cell> 2x2 ***" << endl;
        Life<Cell> newLife;
        std::istringstream r ("2\n2\n-0\n0-");
        newLife.read(r);
        for (int i = 0; i < 2; ++i) {
            newLife.print(i);
            newLife.nextGen();
        }
        newLife.print(2);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // Cell 3
    try {
        cout << "*** Life<Cell> 2x2 ***" << endl;
        Life<Cell> newLife;
        std::istringstream r ("2\n2\n11\n11");
        newLife.read(r);
        for (int i = 0; i < 2; ++i) {
            newLife.print(i);
            newLife.nextGen();
        }
        newLife.print(2);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // Cell 4
    try {
        cout << "*** Life<Cell> 2x4 ***" << endl;
        Life<Cell> newLife;
        std::istringstream r ("2\n4\n1--1\n-11-");
        newLife.read(r);
        for (int i = 0; i < 3; ++i) {
            newLife.print(i);
            newLife.nextGen();
        }
        newLife.print(3);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // Cell 5
    try {
        cout << "*** Life<Cell> 4x2 ***" << endl;
        Life<Cell> newLife;
        std::istringstream r ("4\n2\n1-\n-1\n1-\n-1");
        newLife.read(r);
        for (int i = 0; i < 3; ++i) {
            newLife.print(i);
            newLife.nextGen();
        }
        newLife.print(3);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
