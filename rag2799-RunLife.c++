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

// ----
// main
// ----

int main () {
    using namespace std;
//  leaks memory so commenting sync_with_stdio
//  ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

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
				Life<ConwayCell> l;
			  l.read_grid("RunLifeConway.in");
				l.print(std::cout);
				l.run_turns(1);
				l.print(std::cout);
				l.run_turns(2);
				l.print(std::cout);
				l.run_turns(3);
				l.print(std::cout);
				l.run_turns(4);
				l.print(std::cout);
				l.run_turns(5);
				l.print(std::cout);
				l.run_turns(6);
				l.print(std::cout);
				l.run_turns(7);
				l.print(std::cout);
				l.run_turns(8);
				l.print(std::cout);
				l.run_turns(9);
				l.print(std::cout);
				l.run_turns(10);
				l.print(std::cout);
				l.run_turns(283);
				l.print(std::cout);
				l.run_turns(323);
				l.print(std::cout);
				l.run_turns(2500);
				l.print(std::cout);
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
				Life<FredkinCell> l;
			  l.read_grid("RunLifeFredkin.in");
				l.print(std::cout);
				l.run_turns(1);
				l.print(std::cout);
				l.run_turns(2);
				l.print(std::cout);
				l.run_turns(3);
				l.print(std::cout);
				l.run_turns(4);
				l.print(std::cout);
				l.run_turns(5);
				l.print(std::cout);
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
				Life<Cell> l;
			  l.read_grid("RunLifeCell.in");
				l.print(std::cout);
				l.run_turns(1);
				l.print(std::cout);
				l.run_turns(2);
				l.print(std::cout);
				l.run_turns(3);
				l.print(std::cout);
				l.run_turns(4);
				l.print(std::cout);
				l.run_turns(5);
				l.print(std::cout);
    } 
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
      cout << "*** Life<ConwayCell> 11x10 ***" << endl;
      /*
      read RunLifeConway2.in
      Simulate 5 moves
      Print every grid.
      */
      Life<ConwayCell> l;
			l.read_grid("RunLifeConway2.in");
			l.print(std::cout);
			l.run_turns(1);
			l.print(std::cout);
			l.run_turns(2);
			l.print(std::cout);
			l.run_turns(3);
			l.print(std::cout);
			l.run_turns(4);
			l.print(std::cout);
			l.run_turns(5);
			l.print(std::cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
      cout << "*** Life<ConwayCell> 23x53 ***" << endl;
      /*
      read RunLifeConway3.in
      Simulate 5 moves
      Print every grid.
      */
      Life<ConwayCell> l;
			l.read_grid("RunLifeConway3.in");
			l.print(std::cout);
			l.run_turns(1);
			l.print(std::cout);
			l.run_turns(2);
			l.print(std::cout);
			l.run_turns(3);
			l.print(std::cout);
			l.run_turns(4);
			l.print(std::cout);
			l.run_turns(5);
			l.print(std::cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
				Life<FredkinCell> l;
			  l.read_grid("RunLifeFredkin2.in");
				l.print(std::cout);
				l.run_turns(1);
				l.print(std::cout);
				l.run_turns(2);
				l.print(std::cout);
				l.run_turns(3);
				l.print(std::cout);
				l.run_turns(4);
				l.print(std::cout);
				l.run_turns(5);
				l.print(std::cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
				Life<FredkinCell> l;
			  l.read_grid("RunLifeFredkin3.in");
				l.print(std::cout);
				l.run_turns(1);
				l.print(std::cout);
				l.run_turns(2);
				l.print(std::cout);
				l.run_turns(3);
				l.print(std::cout);
				l.run_turns(4);
				l.print(std::cout);
				l.run_turns(5);
				l.print(std::cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
				Life<FredkinCell> l;
			  l.read_grid("RunLifeFredkin4.in");
				l.print(std::cout);
				l.run_turns(1);
				l.print(std::cout);
				l.run_turns(2);
				l.print(std::cout);
				l.run_turns(3);
				l.print(std::cout);
				l.run_turns(4);
				l.print(std::cout);
				l.run_turns(5);
				l.print(std::cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
				Life<FredkinCell> l;
			  l.read_grid("RunLifeFredkin5.in");
				l.print(std::cout);
				l.run_turns(1);
				l.print(std::cout);
				l.run_turns(2);
				l.print(std::cout);
				l.run_turns(3);
				l.print(std::cout);
				l.run_turns(4);
				l.print(std::cout);
				l.run_turns(5);
				l.print(std::cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
      cout << "*** Life<Cell> 11x10 ***" << endl;
      /*
      read RunLifeConway2.in
      Simulate 5 moves
      Print every grid.
      */
      Life<Cell> l;
			l.read_grid("RunLifeConway2.in");
			l.print(std::cout);
			l.run_turns(1);
			l.print(std::cout);
			l.run_turns(2);
			l.print(std::cout);
			l.run_turns(3);
			l.print(std::cout);
			l.run_turns(4);
			l.print(std::cout);
			l.run_turns(5);
			l.print(std::cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
      cout << "*** Life<Cell> 23x53 ***" << endl;
      /*
      read RunLifeConway3.in
      Simulate 5 moves
      Print every grid.
      */
      Life<Cell> l;
			l.read_grid("RunLifeConway3.in");
			l.print(std::cout);
			l.run_turns(1);
			l.print(std::cout);
			l.run_turns(2);
			l.print(std::cout);
			l.run_turns(3);
			l.print(std::cout);
			l.run_turns(4);
			l.print(std::cout);
			l.run_turns(5);
			l.print(std::cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
      cout << "*** Life<Cell> 109x69 ***" << endl;
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
		  Life<Cell> l;
  	  l.read_grid("RunLifeConway.in");
		  l.print(std::cout);
			l.run_turns(1);
			l.print(std::cout);
			l.run_turns(2);
			l.print(std::cout);
			l.run_turns(3);
			l.print(std::cout);
			l.run_turns(4);
			l.print(std::cout);
			l.run_turns(5);
			l.print(std::cout);
			l.run_turns(6);
			l.print(std::cout);
			l.run_turns(7);
			l.print(std::cout);
			l.run_turns(8);
			l.print(std::cout);
			l.run_turns(9);
			l.print(std::cout);
			l.run_turns(10);
			l.print(std::cout);
			l.run_turns(283);
			l.print(std::cout);
			l.run_turns(323);
			l.print(std::cout);
    }
    catch (const invalid_argument&) {
      assert(false);}
    catch (const out_of_range&) {
      assert(false);}

    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
				Life<Cell> l;
			  l.read_grid("RunLifeFredkin.in");
				l.print(std::cout);
				l.run_turns(1);
				l.print(std::cout);
				l.run_turns(2);
				l.print(std::cout);
				l.run_turns(3);
				l.print(std::cout);
				l.run_turns(4);
				l.print(std::cout);
				l.run_turns(5);
				l.print(std::cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
