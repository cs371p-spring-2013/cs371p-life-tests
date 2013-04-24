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
#include <fstream>   // ifstream
#include <sstream>   // istringstream
#include <stdexcept> // invalid_argument, out_of_range

#include "Life.h"
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    // ------------------
    // 1. Conway Cell 109x69
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
        ifstream input("RunLifeConway.in");
        Life<ConwayCell> l(input);
        input.close();
        l.print();
        for (unsigned int i = 0; i < 9; ++i) {
            l.turn();
            l.print();}
        l.run(274);
        l.print();
        l.run(40);
        l.print();
        l.run(2177);
        l.print();
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------
    // 2. ConwayCell 0x0
    // ----------

    try {
        cout << "*** Life<ConwayCell> 0x0 ***" << endl;
        /*
        0
        0
        ...
        ...
        ...
        */
        istringstream input("0\n0\n...\n...\n...");
        Life<ConwayCell> l(input);
        l.print();
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------
    // 3. ConwayCell 3x3
    // ----------
    
    try {
        cout << "*** Life<ConwayCell> 3x3 ***" << endl;
        /*
        3
        3
        ...
        .*.
        ...
        */
        istringstream input("3\n3\n...\n.*.\n...");
        Life<ConwayCell> l(input);
        l.print();
        for (unsigned int i = 0; i < 2; ++i) {
            l.turn();
            l.print();}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // 4. ConwayCell 10x10
    // ----------

    try {
        cout << "*** Life<ConwayCell> 10x10 ***" << endl;
        /*
        10
        10
        ..........
        ..........
        ..........
        ..........
        ..........
        ..........
        ..........
        .......***
        .......*..
        ........*.
        */
        istringstream input(
            "10\n"
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
        Life<ConwayCell> l(input);
        l.print();
        for (unsigned int i = 0; i < 5; ++i) {
            l.turn();
            l.print();}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // 5. ConwayCell 5x5
    // ----------

    try {
        cout << "*** Life<ConwayCell> 5x5 ***" << endl;
        /*
        5
        5
        .....
        .....
        .***.
        .....
        .....
        */
        istringstream input(
            "5\n"
            "5\n"
            ".....\n"
            ".....\n"
            ".***.\n"
            ".....\n"
            ".....");
        Life<ConwayCell> l(input);
        l.print();
        for (unsigned int i = 0; i < 5; ++i) {
            l.turn();
            l.print();}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // 6. Fredkin Cell 20x20
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        ifstream input("RunLifeFredkin.in");
        Life<FredkinCell> l(input);
        input.close();
        l.print();
        for (unsigned int i = 0; i < 5; ++i) {
            l.turn();
            l.print();}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // 7. FredkinCell 3x3
    // ----------

    try {
        cout << "*** Life<FredkinCell> 3x3 ***" << endl;
        /*
        3
        3
        ---
        -5-
        ---
        */
        istringstream input("3\n3\n---\n-5-\n---");
        Life<FredkinCell> l(input);
        l.print();
        for (unsigned int i = 0; i < 2; ++i) {
            l.turn();
            l.print();}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // 8. FredkinCell 6x5
    // ----------

    try {
        cout << "*** Life<FredkinCell> 6x5 ***" << endl;
        /*
        6
        5
        -----
        -0-0-
        --0--
        --0--
        -0-0-
        -----
        */
        istringstream input(
            "6\n"
            "5\n"
            "-----\n"
            "-0-0-\n"
            "--0--\n"
            "--0--\n"
            "-0-0-\n"
            "-----");
        Life<FredkinCell> l(input);
        l.print();
        for (unsigned int i = 0; i < 5; ++i) {
            l.run(5);
            l.print();}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // 9. FredkinCell 5x5
    // ----------

    try {
        cout << "*** Life<FredkinCell> 5x5 ***" << endl;
        /*
        5
        5
        -----
        -----
        -+++-
        -----
        -----
        */
        istringstream input(
        "5\n"
        "5\n"
        "-----\n"
        "-----\n"
        "-+++-\n"
        "-----\n"
        "-----");
        Life<FredkinCell> l(input);
        l.print();
        for (unsigned int i = 0; i < 5; ++i) {
            l.turn();
            l.print();}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // 10. FredkinCell 3x3
    // ----------

    try {
        cout << "*** Life<FredkinCell> 3x3 ***" << endl;
        /*
        3
        3
        +-+
        -+-
        +-+
        */
        istringstream input(
            "3\n"
            "3\n"
            "+-+\n"
            "-+-\n"
            "+-+");
        Life<FredkinCell> l(input);
        l.print();
        for (unsigned int i = 0; i < 3; ++i) {
            l.turn();
            l.print();}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // 11. Cell 20x20
    // ----------

    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        ifstream input("RunLifeCell.in");
        Life<Cell> l(input);
        input.close();
        l.print();
        for (unsigned int i = 0; i < 5; ++i) {
            l.turn();
            l.print();}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // 12. Cell 8x9
    // ----------

    try {
        cout << "*** Life<Cell> 8x9 ***" << endl;
        /*
        8
        9
        ---------
        ----0----
        ----+----
        ----0----
        ----+----
        ----0----
        ----+----
        ---------
        */
        istringstream input(
            "8\n"
            "9\n"
            "---------\n"
            "----0----\n"
            "----+----\n"
            "----0----\n"
            "----+----\n"
            "----0----\n"
            "----+----\n"
            "---------");
        Life<Cell> l(input);
        l.print();
        for (unsigned int i = 0; i < 5; ++i) {
            l.turn();
            l.print();}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // 13. Cell 2x1
    // ----------
    
    try {
        cout << "*** Life<Cell> 2x1 ***" << endl;
        /*
        2
        1
        0
        -
        */
        istringstream input(
            "2\n"
            "1\n"
            "0\n"
            "-");
        Life<Cell> l(input);
        l.print();
        for (unsigned int i = 0; i < 4; ++i) {
            l.turn();
            l.print();}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ----------
    // 14. Cell 6x5
    // ----------

    try {
        cout << "*** Life<Cell> 6x5 ***" << endl;
        /*
        6
        5
        0---0
        -0-0-
        --0--
        0-0-0
        -0-0-
        0---0
        */
        istringstream input(
            "6\n"
            "5\n"
            "0---0\n"
            "-0-0-\n"
            "--0--\n"
            "0-0-0\n"
            "-0-0-\n"
            "0---0");
        Life<Cell> l(input);
        l.print();
        for (unsigned int i = 0; i < 2; ++i) {
            l.turn();
            l.print();}
        for (unsigned int i = 0; i < 2; ++i) {
            l.run(5);
            l.print();}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // 15. Cell 2x2
    // ----------
    
    try {
        cout << "*** Life<Cell> 2x2 ***" << endl;
        /*
        2
        2
        00
        -0
        */
        istringstream input(
            "2\n"
            "2\n"
            "00\n"
            "-0");
        Life<Cell> l(input);
        l.print();
        for (unsigned int i = 0; i < 3; ++i) {
            l.turn();
            l.print();}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}