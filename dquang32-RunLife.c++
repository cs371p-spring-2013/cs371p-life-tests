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
#include "test.h"
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

        ifstream j ("RunLifeConway.in");
        Life<ConwayCell> z(j, 9);
        z.run();

        ifstream k ("RunLifeConway.in");
        Life<ConwayCell> x(k, 2500);
        x.run(283, 323, 2500);

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

        ifstream a ("RunLifeFredkin.in");
        Life<FredkinCell> y(a, 5);
        y.run();
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

        ifstream k ("RunLifeCell.in");
        Life<Cell> x(k, "Cell", 5);
        x.runCell();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

// ---------------------------------------------------------------------------------------------------

    // ------------------
    // Conway Cell 10x10
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 10x10 ***" << endl;

        Life<ConwayCell> z(10,10,9);
        for(int i = 0; i < 7; i++)
            for(int j = 0; j < 7; j++)
                z.put(i,j);
        z.run();

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Conway Cell 15x15
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 15x15 ***" << endl;

        Life<ConwayCell> z(15,15,10);
        for(int i = 5; i < 10; i++)
            for(int j = 5; j < 10; j++)
                z.put(i,j);
        z.run();

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Conway Cell 30x10
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 30x10 ***" << endl;

        Life<ConwayCell> z(100,10,10);
        for(int i = 10; i < 30; i++)
            for(int j = 0; j < 7; j++)
                z.put(i,j);
        z.run();

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Conway Cell 25x45
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 25x45 ***" << endl;

        Life<ConwayCell> z(25,45,20);
        for(int i = 7; i < 15; i++)
            for(int j = 5; j < 30; j++)
                z.put(i,j);
        z.run();

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 60x60
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 60x60 ***" << endl;

        Life<FredkinCell> y(60,60,10);
        for(int i = 7; i < 15; i++)
            for(int j = 5; j < 30; j++)
                y.put(i,j);
        y.run();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 40x40
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 40x40 ***" << endl;

        Life<FredkinCell> y(40,40,10);
        for(int i = 30; i < 40; i++)
            for(int j = 30; j < 40; j++)
                y.put(i,j);
        y.run();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 40x40
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 40x40 ***" << endl;

        Life<FredkinCell> y(40,40,30);
        for(int i = 20; i < 30; i++)
            for(int j = 10; j < 20; j++)
                y.put(i,j);
        y.run();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 27x69
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 27x69 ***" << endl;

        Life<FredkinCell> y(27,69,40);
        for(int i = 15; i < 20; i++)
            for(int j = 20; j < 40; j++)
                y.put(i,j);
        y.run();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 10x10
    // ----------

    try {
        cout << "*** Life<Cell> 10x10 ***" << endl;

        Life<Cell> x(10,10,10, "Cell");
        for(int i = 5; i < 8; i++)
            for(int j = 4; j < 6; j++)
                x.put(i,j);
        x.runCell();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 50x50
    // ----------

    try {
        cout << "*** Life<Cell> 50x50 ***" << endl;

        Life<Cell> x(50,50, 20, "Cell");
        for(int i = 30; i < 50; i++)
            for(int j = 20; j < 30; j++)
                x.put(i,j);
        x.runCell();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 30x30
    // ----------

    try {
        cout << "*** Life<Cell> 30x30 ***" << endl;

        Life<Cell> x(30,30, 20, "Cell");
        for(int i = 10; i < 20; i++)
            for(int j = 10; j < 20; j++)
                x.put(i,j);
        x.runCell();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 30x40
    // ----------

    try {
        cout << "*** Life<Cell> 30x40 ***" << endl;

        Life<Cell> x(30,40,20, "Cell");
        for(int i = 10; i < 20; i++)
            for(int j = 0; j < 30; j++)
                x.put(i,j);
        x.runCell();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}

