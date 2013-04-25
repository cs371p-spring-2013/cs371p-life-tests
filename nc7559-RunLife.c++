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
#include <sstream>   // ofstream
#include <string>    // string

#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Life.h"

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    ofstream outfile;
    outfile.open("RunLife.out");

    // ------------------
    // Conway Cell 109x69
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 109x69 ***" << endl;
		outfile << "*** Life<ConwayCell> 109x69 ***" << endl << endl;
        /*
        read ConwayCell.in // assume all Conway cells
        Simulate 283 moves.
        Print the first 10 grids (i.e. 0, 1, 2...9).
        Print the 283rd grid.
        Simulate 40 moves.
        Print the 323rd grid.
        Simulate 2177 moves.
        Print the 2500th grid.
        */
		int i;
		ifstream infile("RunLifeConway.in");
        
        Life<ConwayCell> LifeGame(infile);
        LifeGame.print(outfile);
		for(i = 0; i < 9; ++i) {
			LifeGame.run(1);
			LifeGame.print(outfile);
		}
        LifeGame.run(274);
        LifeGame.print(outfile);
        LifeGame.run(40);
        LifeGame.print(outfile);
        LifeGame.run(2177);
        LifeGame.print(outfile);
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
		outfile << "*** Life<FredkinCell> 20x20 ***" << endl << endl;
        /*
        read FredkinCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
		int i;
		ifstream infile("RunLifeFredkin.in");
        
        Life<FredkinCell> LifeGame(infile);
        LifeGame.print(outfile);
		for(i = 0; i < 5; ++i) {
			LifeGame.run(1);
			LifeGame.print(outfile);
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
		outfile << "*** Life<Cell> 20x20 ***" << endl << endl;
        /*
        read Cell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
		ifstream infile("RunLifeCell.in");
        
        Life<Cell> LifeGame(infile);
        LifeGame.print(outfile);
        for (int i=0; i<5; ++i) {
            LifeGame.run(1);
            LifeGame.print(outfile);
        }
	}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------
    // Cell 5x5
    // --------
    try {

        cout << "*** Life<Cell> 5x5 ***" << endl;
		outfile << "*** Life<Cell> 5x5 ***" << endl << endl;
        
        ifstream infile("Cell5x5.in");
        
        Life<Cell> LifeGame(infile);
        LifeGame.print(outfile);
        LifeGame.run(5);
        LifeGame.print(outfile);
        LifeGame.run(25);
        LifeGame.print(outfile);
        LifeGame.run(70);
        LifeGame.print(outfile);
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
		outfile << "*** Life<Cell> 10x10 ***" << endl << endl;

        ifstream infile("Cell10x10.in");
        
        Life<Cell> LifeGame(infile);
        LifeGame.print(outfile);
        LifeGame.run(5);
        LifeGame.print(outfile);
        LifeGame.run(25);
        LifeGame.print(outfile);
        LifeGame.run(70);
        LifeGame.print(outfile);
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
		outfile << "*** Life<Cell> 20x20 ***" << endl << endl;

        ifstream infile("Cell20x20.in");
        
        Life<Cell> LifeGame(infile);
        LifeGame.print(outfile);
        LifeGame.run(5);
        LifeGame.print(outfile);
        LifeGame.run(25);
        LifeGame.print(outfile);
        LifeGame.run(70);
        LifeGame.print(outfile);
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
		outfile << "*** Life<Cell> 50x50 ***" << endl << endl;

        ifstream infile("Cell50x50.in");
        
        Life<Cell> LifeGame(infile);
        LifeGame.print(outfile);
        LifeGame.run(5);
        LifeGame.print(outfile);
        LifeGame.run(25);
        LifeGame.print(outfile);
        LifeGame.run(70);
        LifeGame.print(outfile);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ---------------
    // Conway Cell 5x5
    // ---------------
    try {

        cout << "*** Life<ConwayCell> 5x5 ***" << endl;
		outfile << "*** Life<ConwayCell> 5x5 ***" << endl << endl;
        
        ifstream infile("ConwayCell5x5.in");
        
        Life<ConwayCell> LifeGame(infile);
        LifeGame.print(outfile);
        LifeGame.run(5);
        LifeGame.print(outfile);
        LifeGame.run(25);
        LifeGame.print(outfile);
        LifeGame.run(70);
        LifeGame.print(outfile);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -----------------
    // Conway Cell 10x10
    // -----------------
    try {

        cout << "*** Life<ConwayCell> 10x10 ***" << endl;
		outfile << "*** Life<ConwayCell> 10x10 ***" << endl << endl;
        
        ifstream infile("ConwayCell10x10.in");
        
        Life<ConwayCell> LifeGame(infile);
        LifeGame.print(outfile);
        LifeGame.run(5);
        LifeGame.print(outfile);
        LifeGame.run(25);
        LifeGame.print(outfile);
        LifeGame.run(70);
        LifeGame.print(outfile);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -----------------
    // Conway Cell 20x20
    // -----------------
    try {

        cout << "*** Life<ConwayCell> 20x20 ***" << endl;
		outfile << "*** Life<ConwayCell> 20x20 ***" << endl << endl;

        ifstream infile("ConwayCell20x20.in");
        
        Life<ConwayCell> LifeGame(infile);
        LifeGame.print(outfile);
        LifeGame.run(5);
        LifeGame.print(outfile);
        LifeGame.run(25);
        LifeGame.print(outfile);
        LifeGame.run(70);
        LifeGame.print(outfile);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -----------------
    // Conway Cell 50x50
    // -----------------
    try {

        cout << "*** Life<ConwayCell> 50x50 ***" << endl;
		outfile << "*** Life<ConwayCell> 50x50 ***" << endl << endl;

        ifstream infile("ConwayCell50x50.in");
        
        Life<ConwayCell> LifeGame(infile);
        LifeGame.print(outfile);
        LifeGame.run(5);
        LifeGame.print(outfile);
        LifeGame.run(25);
        LifeGame.print(outfile);
        LifeGame.run(70);
        LifeGame.print(outfile);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Fredkin Cell 5x5
    // ----------------
    try {

        cout << "*** Life<FredkinCell> 5x5 ***" << endl;
		outfile << "*** Life<FredkinCell> 5x5 ***" << endl << endl;
        
        ifstream infile("FredkinCell5x5.in");
        
        Life<FredkinCell> LifeGame(infile);
        LifeGame.print(outfile);
        LifeGame.run(5);
        LifeGame.print(outfile);
        LifeGame.run(25);
        LifeGame.print(outfile);
        LifeGame.run(70);
        LifeGame.print(outfile);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 10x10
    // ------------------
    try {

        cout << "*** Life<FredkinCell> 10x10 ***" << endl;
		outfile << "*** Life<FredkinCell> 10x10 ***" << endl << endl;
        
        ifstream infile("FredkinCell10x10.in");
        
        Life<FredkinCell> LifeGame(infile);
        LifeGame.print(outfile);
        LifeGame.run(5);
        LifeGame.print(outfile);
        LifeGame.run(25);
        LifeGame.print(outfile);
        LifeGame.run(70);
        LifeGame.print(outfile);
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
		outfile << "*** Life<FredkinCell> 20x20 ***" << endl << endl;

        ifstream infile("FredkinCell20x20.in");
        
        Life<FredkinCell> LifeGame(infile);
        LifeGame.print(outfile);
        LifeGame.run(5);
        LifeGame.print(outfile);
        LifeGame.run(25);
        LifeGame.print(outfile);
        LifeGame.run(70);
        LifeGame.print(outfile);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 50x50
    // ------------------
    try {

        cout << "*** Life<FredkinCell> 50x50 ***" << endl;
		outfile << "*** Life<FredkinCell> 50x50 ***" << endl << endl;

        ifstream infile("FredkinCell50x50.in");
        
        Life<FredkinCell> LifeGame(infile);
        LifeGame.print(outfile);
        LifeGame.run(5);
        LifeGame.print(outfile);
        LifeGame.run(25);
        LifeGame.print(outfile);
        LifeGame.run(70);
        LifeGame.print(outfile);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
