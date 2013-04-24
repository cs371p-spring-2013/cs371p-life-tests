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
#include "Life.h"
#include <vector>
#include <fstream>
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include <sstream>  // istringstream, ostringstream

#define DEBUG 0
// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    //------------------
    // Our 10 Tests
    //------------------

    try {
        cout << "*** Life<ConwayCell> 5x5 ***" << endl;

        istringstream s ("5\n5\n*....\n.*...\n..*..\n...*.\n....*");
        Life<ConwayCell> l (s);
        vector<int> v= {0,1,2,3,4,5};
        if(DEBUG)
            l.runLife(6,v);
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


    try {
        cout << "*** Life<ConwayCell> 5x1 ***" << endl;

        istringstream s ("5\n1\n*\n*\n*\n.\n.");
        Life<ConwayCell> l (s);
        vector<int> v= {0,1,2,3,4,5};
        if(DEBUG)
            l.runLife(6,v);
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

    try {
        cout << "*** Life<ConwayCell> 1x5 ***" << endl;

        istringstream s ("1\n5\n*...*");
        Life<ConwayCell> l (s);
        vector<int> v= {0,1,2,3,4,5};
        if(DEBUG)
            l.runLife(6,v);
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


    try {
        cout << "*** Life<ConwayCell> 2x2 ***" << endl;

        istringstream s ("2\n2\n*.\n.*");
        Life<ConwayCell> l (s);
        vector<int> v= {0,1};
        if(DEBUG)
            l.runLife(3,v);
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



    try {
        cout << "*** Life<ConwayCell> 5x2 ***" << endl;

        istringstream s ("5\n2\n**\n.*\n*.\n..\n.*");
        Life<ConwayCell> l (s);
        vector<int> v= {0,1,2,3,4,5};
        if(DEBUG)
            l.runLife(6,v);
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


    try {
        cout << "*** Life<FrankenCell> 6x6 ***" << endl;

        istringstream s ("6\n6\n000000\n------\n------\n------\n------\n000000");
        Life<ConwayCell> l (s);
        vector<int> v= {0,1,2,3,4,5};
        if(DEBUG)
            l.runLife(6,v);
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



    try {
        cout << "*** Life<FrankenCell> 4x4 ***" << endl;

        istringstream s ("4\n4\n0000\n--00\n--0-\n0--0");
        Life<ConwayCell> l (s);
        vector<int> v= {0,1,2,3,4,5,10,15};
        if(DEBUG)
            l.runLife(20,v);
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

    try {
        cout << "*** Life<FrankenCell> 4x8 ***" << endl;

        istringstream s ("4\n8\n0000--00\n------00\n0000--0-\n-0-00--0");
        Life<ConwayCell> l (s);
        vector<int> v= {0,1,2,3,4,5};
        if(DEBUG)
            l.runLife(6,v);
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


    try {
        cout << "*** Life<Cell> 5x5 ***" << endl;

        istringstream s ("5\n5\n0000--00\n------00\n0000--0-\n-0-00--0");
        Life<ConwayCell> l (s);
        vector<int> v= {0,1,2,3,4,5};
        if(DEBUG)
            l.runLife(6,v,true);
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


    try {
        cout << "*** Life<Cell> 2x5 ***" << endl;

        istringstream s ("2\n5\n0--00\n0---0");
        Life<ConwayCell> l (s);
        vector<int> v= {0,1,2,3,4,5};
        if(DEBUG)
            l.runLife(6,v,true);
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
    //-------------------
    // End of our Tests
    //-------------------


    // ------------------
    // Conway Cell 109x69
    // ------------------
    try {
        cout << "*** Life<ConwayCell> 109x69 ***" << endl;

        ifstream f;
        f.open("RunLifeConway.in");
        assert(f.good());

        istream& s = f;

        Life<ConwayCell> l (s);
        vector<int> v= {0,1,2,3,4,5,6,7,8,9,283,323,2500};
        if(DEBUG)
            l.runLife(2501,v);
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
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

        ifstream f;
        f.open("RunLifeFredkin.in");
        assert(f.good());

        istream& s = f;
        vector<int> v= {0,1,2,3,4,5};
        Life<FredkinCell> l (s);
        if(DEBUG)
            l.runLife(6,v,false);

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

        ifstream f;
        f.open("RunLifeCell.in");
        assert(f.good());

        istream& s = f;
        vector<int> v= {0,1,2,3,4,5};
        Life<Cell> l (s);
        if(DEBUG)
            l.runLife(6,v, true);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}