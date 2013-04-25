/* Faisal Ejaz (UTEID: fe2333 CSID: faisalej, 10AM section)
/  Zachary Sais (UTEID: zrs233 CSID: zrs233, 1PM section)
/  CS371P - Downing
/  Project Life
/  April 24 2013
*/

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
#include <stdio.h>
#include <stdexcept> // invalid_argument, out_of_range

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
    
    /////////////
    // ConwayCell
    /////////////

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
        Life <ConwayCell> l;
        l.read("RunLifeConway.in");
        l.simulate(283, 0, 10);
        l.print();
        l.simulate(40, 0, 0);
        l.print();
        l.simulate(2177, 0, 0);
        l.print();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> 3x3 ***" << endl;
        
        Life <ConwayCell> l;
        string grid = "3\n3\n.*.\n.*.\n.*.\n";
        stringstream s_stream;
        s_stream << grid;
        l.read(s_stream);
        l.simulate(5, 0, 5);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> 6x4 ***" << endl;
       
        Life <ConwayCell> l;
        string grid = "6\n4\n....\n....\n***.\n.***\n....\n....\n";
        stringstream s_stream;
        s_stream << grid;
        l.read(s_stream);
        l.simulate(5, 0, 5);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> 9x9 ***" << endl;
        
       Life <ConwayCell> l;
        string grid = "9\n9\n.........\n.........\n.........\n....*....\n...***...\n....*....\n.........\n.........\n.........\n";
        stringstream s_stream;
        s_stream << grid;
        l.read(s_stream);
        l.simulate(5, 0, 5);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> 9x9 ***" << endl;
        Life <ConwayCell> l;
        string grid = "7\n7\n...*..*\n..*....\n..*...*\n..****.\n.......\n.......\n.......\n";
        stringstream s_stream;
        s_stream << grid;
        l.read(s_stream);
        l.simulate(5, 0, 5);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    //////////////
    // FredkinCell
    //////////////

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
        Life <FredkinCell> l;
        l.read("RunLifeFredkin.in");
        l.simulate(5, 0, 5);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    
    try {
        cout << "*** Life<FredkinCell> 9x9 ***" << endl;
        Life <FredkinCell> l;
        string grid = "9\n9\n0-------0\n-0-----0-\n--0---0--\n---0-0---\n----0----\n---0-0---\n--0---0--\n-0-----0-\n0-------0\n";
        stringstream s_stream;
        s_stream << grid;
        l.read(s_stream);
        l.simulate(5, 0, 5);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> 5x5 ***" << endl;
        Life <FredkinCell> l;
        string grid = "5\n5\n00000\n-----\n00000\n-----\n00000\n";
        stringstream s_stream;
        s_stream << grid;
        l.read(s_stream);
        l.simulate(5, 0, 5);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> 8x10 ***" << endl;
        Life <FredkinCell> l;
        string grid = "8\n10\n----------\n-00000000-\n-00-00-00-\n-00-00-00-\n-00000000-\n-0--0-0-0-\n-0--2-0-0-\n----------\n";
        stringstream s_stream;
        s_stream << grid;
        l.read(s_stream);
        l.simulate(5, 0, 5);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> 11x11 ***" << endl;
        Life <FredkinCell> l;
        string grid = "11\n11\n0----0----0\n-----------\n--0--0--0--\n-----------\n----0-0----\n0-0-----0-0\n----0-0----\n-----------\n--0--0--0--\n-----------\n0----0----0\n";
        stringstream s_stream;
        s_stream << grid;
        l.read(s_stream);
        l.simulate(10, 0, 10);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);} 


    //////////
    // Cell //
    /////////

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

        Life <Cell> l;
        l.read("RunLifeCell.in");   
        l.simulate(5, 0, 5);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<Cell> 6x5 ***" << endl;
        
        Life <Cell> l;
        string grid = "6\n5\n0---0\n-0-0-\n--0--\n0-0-0\n-0-0-\n0---0\n";
        stringstream s_stream;
        s_stream << grid;
        l.read(s_stream);
        l.simulate(10, 0, 5);
        l.print();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    try {
        cout << "*** Life<Cell> 2x2 ***" << endl;

        Life <Cell> l;
        string grid = "2\n2\n00\n-0\n";
        stringstream s_stream;
        s_stream << grid;
        l.read(s_stream);
        l.simulate(3, 0, 3);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;
        
        Life <Cell> l;
        string grid = "20\n20\n--------------------\n-000000000000000000-\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n-000000000000000000-\n--------------------\n";
        stringstream s_stream;
        s_stream << grid;
        l.read(s_stream);
        l.simulate(5, 0, 5);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<Cell> 8x10 ***" << endl;

        Life <Cell> l;
        string grid = "8\n10\n----------\n-00000000-\n-00-00-00-\n-00-00-00-\n-00000000-\n-0--0-0-0-\n-0--0-0-0-\n----------\n";
        stringstream s_stream;
        s_stream << grid;
        l.read(s_stream);
        l.simulate(50, 0, 5);
        l.print();
        l.simulate(50, 0, 0);
        l.print();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

return 0;}