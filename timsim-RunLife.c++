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
        cout << "*** Life<ConwayCell> 109x69 ***" << endl << endl;
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
        Life<ConwayCell> l;
        l.read("RunLifeConway.in");
        l.simulate(283, 0);
        l.print();
        l.simulate(40, 0);
        l.print();
        l.simulate(2177, 0);
        l.print();
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
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        Life<FredkinCell> l;
        l.read("RunLifeFredkin.in");
        l.simulate(5, 5);
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
        Life<Cell> l;
        l.read("RunLifeCell.in");
        l.simulate(5, 5);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}












    // ----------
    // LifeTest 20x20
    // ----------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl << endl;
        /*
        read Lifetest.in // assume all Fredkin cells
        Simulate 5 moves. Print
        20
        20
        -0------0-0-------0-
        00----------------0-
        --------------------
        --------------------
        --------------------
        --------------------
        ---------000--------
        00-------0-0------0-
        -0-------000--------
        00------------------
        ----------0---------
        ---------0-0--------
        ----------0---------
        --------------------
        ---------0-0--------
        --------------------
        ---------0-0--------
        --------------------
        -0------0-0---------
        --------0-0---------
        */
        Life<Cell> l;
        l.read("LifeTest.in");
        l.simulate(5, 0);
        l.print();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


        // ----------
    // LifeTest 20x20
    // ----------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl << endl;
        /*
        read Lifetest.in // assume all Fredkin cells
        Simulate 10 moves. Print
        20
        20
        -0------0-0-------0-
        00----------------0-
        --------------------
        --------------------
        --------------------
        --------------------
        ---------000--------
        00-------0-0------0-
        -0-------000--------
        00------------------
        ----------0---------
        ---------0-0--------
        ----------0---------
        --------------------
        ---------0-0--------
        --------------------
        ---------0-0--------
        --------------------
        -0------0-0---------
        --------0-0---------
        */
        Life<Cell> l;
        l.read("LifeTest.in");
        l.simulate(10, 0);
        l.print();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


     // ----------
    // LifeTest 20x20
    // ----------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl << endl;
        /*
        read Lifetest.in // assume all Fredkin cells
        Simulate 100 moves. Print
        20
        20
        -0------0-0-------0-
        00----------------0-
        --------------------
        --------------------
        --------------------
        --------------------
        ---------000--------
        00-------0-0------0-
        -0-------000--------
        00------------------
        ----------0---------
        ---------0-0--------
        ----------0---------
        --------------------
        ---------0-0--------
        --------------------
        ---------0-0--------
        --------------------
        -0------0-0---------
        --------0-0---------
        */
        Life<Cell> l;
        l.read("LifeTest.in");
        l.simulate(100, 0);
        l.print();
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
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 20 moves.
        */
        Life<FredkinCell> l;
        l.read("RunLifeFredkin.in");
        l.simulate(20, 0);
        l.print();
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
        Simulate 20 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        Life<Cell> l;
        l.read("RunLifeCell.in");
        l.simulate(20, 0);
        l.print();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // Conway Cell 10x50
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 10x50 ***" << endl << endl;
        /*
        read Spaceship.in // assume all Conway cells
        10
        50
        ..................................................
        ..................................................
        ..................................................
        ..................................................
        ..................................................
        ............................................****..
        ............................................*...*.
        ............................................*.....
        .............................................*..*.
        ..................................................
        Simulate 5 moves.
        Print the all grids.
        */
        Life<ConwayCell> l;
        l.read("Spaceship.in");
        l.simulate(5,5);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Conway Cell 10x50
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 10x50 ***" << endl << endl;
        /*
        read Spaceship.in // assume all Conway cells
        10
        50
        ..................................................
        ..................................................
        ..................................................
        ..................................................
        ..................................................
        ............................................****..
        ............................................*...*.
        ............................................*.....
        .............................................*..*.
        ..................................................
        Simulate 50 moves.
        Print the all grids.
        */
        Life<ConwayCell> l;
        l.read("Spaceship.in");
        l.simulate(50,50);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}    




    return 0;}
