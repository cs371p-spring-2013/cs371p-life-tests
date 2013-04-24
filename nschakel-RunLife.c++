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
        Life<ConwayCell> l("RunLifeConway.in");
        cout << l.toString();
        for (int i = 1; i <= 9; i++)
        {
          l.move();
          cout << l.toString();
        }
        for (int i = 10; i <= 282; i++)
        {
          l.move();
        }
        cout << l.toString();

        for (int i = 283; i <= 322; i++)
        {
          l.move();
        }
        cout << l.toString();

        for (int i = 323; i < 2500; i++)
        {
          l.move();
        }
        cout << l.toString();

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
        Life<FredkinCell> l("RunLifeFredkin.in");
        cout << l.toString();
        for (int i = 1; i <=5; i++)
        {
          l.move();
          cout << l.toString();
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
        Life<Cell> l("RunLifeCell.in");
        cout << l.toString();
        for (int i = 1; i <= 5; i++)
        {
          l.move();
          cout << l.toString();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    //Conway 1x1//
    try {
        cout << "*** Life<ConwayCell> 1x1 ***" << endl;
        Life<ConwayCell> l(1,1,true);
        for (int i = 0; i < 5; i++)
        {
          cout << l.toString();
          l.move();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    //Conway 1x1//
    try {
        cout << "*** Life<ConwayCell> 1x1 ***" << endl;
        Life<ConwayCell> l(1,1,false);
        for (int i = 0; i < 5; i++)
        {
          cout << l.toString();
          l.move();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    //Conway 1x3//
    try {
        cout << "*** Life<ConwayCell> 1x3 ***" << endl;
        Life<ConwayCell> l(3,1,false);
        for (int i = 0; i < 5; i++)
        {
          cout << l.toString();
          l.move();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    //Conway 3x1//
    try {
        cout << "*** Life<ConwayCell> 3x1 ***" << endl;
        Life<ConwayCell> l(1,3,false);
        for (int i = 0; i < 5; i++)
        {
          cout << l.toString();
          l.move();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    //Fredkin 1x1//
    try {
        cout << "*** Life<FredkinCell> 1x1 ***" << endl;
        Life<FredkinCell> l(1,1,true);
        for (int i = 0; i < 5; i++)
        {
          cout << l.toString();
          l.move();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    //Fredkin 1x1//
    try {
        cout << "*** Life<FredkinCell> 1x1 ***" << endl;
        Life<FredkinCell> l(1,1,false);
        for (int i = 0; i < 5; i++)
        {
          cout << l.toString();
          l.move();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    //Fredkin 1x3//
    try {
        cout << "*** Life<FredkinCell> 1x3 ***" << endl;
        Life<FredkinCell> l(3,1,false);
        for (int i = 0; i < 5; i++)
        {
          cout << l.toString();
          l.move();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    //Fredkin 3x1//
    try {
        cout << "*** Life<FredkinCell> 3x1 ***" << endl;
        Life<FredkinCell> l(1,3,false);
        for (int i = 0; i < 5; i++)
        {
          cout << l.toString();
          l.move();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    //Cell 1x1//
    try {
        cout << "*** Life<Cell> 1x1 ***" << endl;
        Life<Cell> l(1,1,true);
        for (int i = 0; i < 5; i++)
        {
          cout << l.toString();
          l.move();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    //Cell 1x1//
    try {
        cout << "*** Life<Cell> 1x1 ***" << endl;
        Life<Cell> l(1,1,false);
        for (int i = 0; i < 5; i++)
        {
          cout << l.toString();
          l.move();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    //Cell 1x3//
    try {
        cout << "*** Life<Cell> 1x3 ***" << endl;
        Life<Cell> l(3,1,false);
        for (int i = 0; i < 5; i++)
        {
          cout << l.toString();
          l.move();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    //Cell 3x1//
    try {
        cout << "*** Life<Cell> 3x1 ***" << endl;
        Life<Cell> l(1,3,true);
        for (int i = 0; i < 5; i++)
        {
          cout << l.toString();
          l.move();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
