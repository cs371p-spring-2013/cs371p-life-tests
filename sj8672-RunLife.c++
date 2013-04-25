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
	std::ifstream in;
	in.open("RunLifeConway.in");
	Life<ConwayCell> l(in, 's');
	for(int i = 0; i < 10; ++i) {
		l.print_board();
		l.evolution(1);
		cout << '\n';
	}
	l.evolution(273);
	l.print_board();
	cout << '\n';
	l.evolution(40);
	l.print_board();
	cout << '\n';	
	l.evolution(2177);
	l.print_board();
	cout << '\n';	
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
	std::ifstream in;
	in.open("RunLifeFredkin.in");
	Life<FredkinCell> l(in, 'f');
	for(int i = 0; i < 6; ++i) {
		l.print_board();
		l.evolution(1);
		cout << '\n';
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
	std::ifstream in;
	in.open("RunLifeCell.in");
	Life<Cell> l(in, 'c');
	for(int i = 0; i < 6; ++i) {
		l.print_board();
		l.evolution(1, 'c');
		cout << '\n';
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}



    // ----------------
    // Conway Cell 5X5
    // ----------------

    try {
        cout << "*** Life<ConwayCell> 5x5 ***" << endl;

        std::istringstream in("5\n5\n*...*\n.....\n..*..\n.....\n*...*\n");
        Life<ConwayCell> l(in, 's');
        for(int i = 0; i < 5; ++i){
            l.print_board();
            l.evolution(1);
	    cout << '\n';
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -----------------
    // Conway Cell 10X8
    // -----------------

    try {
        cout << "*** Life<ConwayCell> 10x8 ***" << endl;

        std::istringstream in("10\n8\n........\n....*...\n....*...\n....*...\n....*...\n"
                            "........\n....*...\n....*...\n....*...\n........\n");
	Life<ConwayCell> l(in, 's');
        for(int i = 0; i < 9; ++i){
            l.print_board();
            l.evolution(1);
	    cout << '\n';
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ---------------
    // Conway Cell 6X6
    // ---------------

    try {
        cout << "*** Life<ConwayCell> 6x6 ***" << endl;

        std::istringstream in("6\n6\n*.....\n.*....\n..*...\n...*..\n....*.\n.....*\n");
        Life<ConwayCell> l(in, 's');
        for(int i = 0; i < 5; ++i){
            l.print_board();
            l.evolution(1);
	    cout << '\n';
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ---------------
    // Conway Cell 6X6
    // ---------------

    try {
        cout << "*** Life<ConwayCell> 6x6 ***" << endl;

        std::istringstream in("6\n6\n******\n*....*\n*....*\n*....*\n*....*\n******\n");
        Life<ConwayCell> l(in, 's');
        for(int i = 0; i < 5; ++i){
            l.print_board();
            l.evolution(1);
	    cout << '\n';
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ---------------
    // Conway Cell 2X1
    // ---------------

    try {
        cout << "*** Life<ConwayCell> 2x1 ***" << endl;

        std::istringstream in("2\n1\n.\n*\n");
        Life<ConwayCell> l(in, 's');
        for(int i = 0; i < 3; ++i){
            l.print_board();
            l.evolution(1);
	    cout << '\n';
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Fredkin Cell 5X5
    // ----------------

    try {
        cout << "*** Life<FredkinCell> 5x5 ***" << endl;
        
        std::istringstream in("5\n5\n0---0\n-----\n--0--\n-----\n0---0\n");
        Life<FredkinCell> l(in, 'f');
        for(int i = 0; i < 9; ++i){
            l.print_board();
            l.evolution(1);
	    	cout << '\n';
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------------
    // Fredkin Cell 2X1
    // ----------------

    try {
        cout << "*** Life<FredkinCell> 2x1 ***" << endl;

        std::istringstream in("2\n1\n-\n0\n");
        Life<FredkinCell> l(in, 'f');
        for(int i = 0; i < 9; ++i){
            l.print_board();
            l.evolution(1);
	    	cout << '\n';
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------------
    // Fredkin Cell 6X6
    // ----------------

    try {
        cout << "*** Life<FredkinCell> 6x6 ***" << endl;

        std::istringstream in("6\n6\n0-----\n-0----\n--0---\n---0--\n----0-\n-----0\n");
        Life<FredkinCell> l(in, 'f');
        for(int i = 0; i < 3; ++i){
            l.print_board();
            l.evolution(1);
	    	cout << '\n';
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // -----------------
    // Fredkin Cell 10X8
    // -----------------

    try {
        cout << "*** Life<FredkinCell> 10x8 ***" << endl;

        std::istringstream in("10\n8\n--------\n----0---\n----0---\n----0---\n----0---\n"
                            "--------\n----0---\n----0---\n----0---\n--------\n");

        Life<FredkinCell> l(in, 'f');
        for(int i = 0; i < 9; ++i){
            l.print_board();
            l.evolution(1);
	    	cout << '\n';
        }
     }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------------
    // Fredkin Cell 6X6
    // ----------------

    try {
        cout << "*** Life<FredkinCell> 6x6 ***" << endl;

        std::istringstream in("6\n6\n000000\n0----0\n0----0\n0----0\n0----0\n000000\n");
        Life<FredkinCell> l(in, 'f'); 
        for(int i = 0; i < 9; ++i){
            l.print_board();
            l.evolution(1);
	    	cout << '\n';
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // --------
    // Cell 6X6
    // --------

    try {
        cout << "*** Life<Cell> 6x6 ***" << endl;
        std::istringstream in("6\n6\n000000\n0----0\n0----0\n0----0\n0----0\n000000\n");
        Life<Cell> l(in, 'c');
        for(int i = 0; i < 9; ++i){
            l.print_board();
            l.evolution(1, 'c');
	    	cout << '\n';
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);} 
        

    // --------
    // Cell 6X6
    // --------

    try {
        cout << "*** Life<Cell> 6x6 ***" << endl;

        std::istringstream in("6\n6\n0-----\n-0----\n--0---\n---0--\n----0-\n-----0\n");
        Life<Cell> l(in, 'c');
        for(int i = 0; i < 3; ++i){
            l.print_board();
            l.evolution(1, 'c');
	    	cout << '\n';
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	// --------
    // Cell 2X1
    // --------

    try {
        cout << "*** Life<Cell> 2x1 ***" << endl;

        std::istringstream in("2\n1\n-\n0\n");
        Life<Cell> l(in, 'c');
        for(int i = 0; i < 9; ++i){
            l.print_board();
            l.evolution(1, 'c');
	    	cout << '\n';
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------
    // Cell 5X5
    // --------

    try {
        cout << "*** Life<Cell> 5x5 ***" << endl;
        
        std::istringstream in("5\n5\n0---0\n-----\n--0--\n-----\n0---0\n");
        Life<Cell> l(in, 'c');
        for(int i = 0; i < 9; ++i){
            l.print_board();
            l.evolution(1, 'c');
	    	cout << '\n';
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ---------
    // Cell 10X8
    // ---------

    try {
        cout << "*** Cell> 10x8 ***" << endl;

        std::istringstream in("10\n8\n--------\n----0---\n----0---\n----0---\n----0---\n"
                            "--------\n----0---\n----0---\n----0---\n--------\n");

        Life<Cell> l(in, 'c');
        for(int i = 0; i < 9; ++i){
            l.print_board();
            l.evolution(1, 'c');
	    	cout << '\n';
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

      return 0;
}

