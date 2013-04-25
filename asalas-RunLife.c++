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
	Life<ConwayCell> l;
	l.read("RunLifeConway.in");
	for(int i = 0; i < 283; ++i)
	{
		if(i < 10)
			l.print(cout);
		l.simulate();
		l.run();
	}
	l.print(cout);
	
	for(int i = 0; i < 40; ++i)
	{
		l.simulate();
		l.run();
	}
	l.print(cout);
	
	for(int i = 0; i < 2177; ++i)
	{
		l.simulate();
		l.run();
	}
	l.print(cout);
	
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
	l.read("RunLifeFredkin.in");
	l.print(cout);
	for(int i = 0; i < 5; ++i)
	{
		l.print(cout);
		l.simulate();
		l.run();
	}
	l.print(cout);
	
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
	l.read("RunLifeCell.in");
	l.print(cout);
	for(int i = 0; i < 5; ++i)
	{
		l.print(cout);
		l.simulate();
		l.run();
	}
	l.print(cout);
	
	
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ------------------
    // Conway Cell 20x20
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 20x20 ***" << endl;
        /*
        Creates a Life who's grid is 20x20.
        Live cells are inserted in the whole first column.
        Simulates 15 moves.
        Prints every 5th grid
        */
	int h = 20;
	int w = 20;
	Life<ConwayCell> l(h, w, '.');
	for(int x = 0; x < h; ++x)
	{
		for(int y = 0; y < w; ++y)
		{
			if(y == 0)
				l.insertCell(x, y, '*');
		}
	}
	
	for (int i = 0; i < 15; ++i)
	{
		if(i % 5 == 0)
			l.print(cout);
		l.simulate();
		l.run();
	}
	l.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Conway Cell 30x60
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 30x60 ***" << endl;
        /*
        Creates a Life who's grid is 30x60.
        Live cells are inserted into every third whole row.
        Simulates 15 moves.
        Prints every 5th grid
        */
	int h = 30;
	int w = 60;
	Life<ConwayCell> l(h, w, '.');
	for(int x = 0; x < h; ++x)
	{
		for(int y = 0; y < w; ++y)
		{
			if(x % 3 == 0)
				l.insertCell(x, y, '*');
		}
	}
	
	for (int i = 0; i < 15; ++i)
	{	
		if(i % 5 == 0)
			l.print(cout);
		l.simulate();
		l.run();
	}
	l.print(cout);
	
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ------------------
    // Conway Cell 90x90
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 90x90 ***" << endl;
        /*
        Creates a Life who's grid is 90x90.
        Live cells are inserted into every other position.
        Simulates 1 move.
        Prints initial and simulated grid.
        */
	int h = 90;
	int w = 90;
	Life<ConwayCell> l(h, w, '.');
	for(int x = 0; x < h; ++x)
	{
		for(int y = 0; y < w; ++y)
		{
			if(x % 2 == 0 && y % 2 == 0)
				l.insertCell(x, y, '*');
		}
	}
	
	l.print(cout);
	
	for (int i = 0; i < 1; ++i)
	{
		l.simulate();
		l.run();
		l.print(cout);
	}
	
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ------------------
    // Conway Cell 60x60
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 60x60 ***" << endl;
        /*
        Creates a Life who's grid is 60x60.
        Live cells are inserted into the whole top left corner of the grid.
        Simulates 100 moves.
        Prints every 20th grid
        */
	int h = 60;
	int w = 60;
	Life<ConwayCell> l(h, w, '.');
	for(int x = 0; x < h; ++x)
	{
		for(int y = 0; y < w; ++y)
		{
			if(y < w/2 && x < h/2)
				l.insertCell(x, y, '*');
		}
	}
	
	for (int i = 0; i < 100; ++i)
	{
		if(i % 20 == 0)
			l.print(cout);
		l.simulate();
		l.run();
	}
	l.print(cout);
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
        Creates a Life who's grid is 20x20.
        Live cells are inserted in the whole first row.
        Simulates 15 moves.
        Prints every 5th grid
        */
	int h = 20;
	int w = 20;
	Life<FredkinCell> l(h, w, '-');
	for(int x = 0; x < h; ++x)
	{
		for(int y = 0; y < w; ++y)
		{
			if(x == 0)
				l.insertCell(x, y, '0');
		}
	}
	
	for (int i = 0; i < 15; ++i)
	{
		if(i % 5 == 0)
			l.print(cout);
		l.simulate();
		l.run();
	}
	l.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ------------------
    // Fredkin Cell 30x60
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 30x60 ***" << endl;
        /*
        Creates a Life who's grid is 30x60.
        Live cells are inserted into every row when x % 10 == 0.
        Simulates 15 moves.
        Prints every 5th grid
        */
	int h = 30;
	int w = 60;
	Life<FredkinCell> l(h, w, '-');
	for(int x = 0; x < h; ++x)
	{
		for(int y = 0; y < w; ++y)
		{
			if(x % 10 == 0)
				l.insertCell(x, y, '0');
		}
	}
	
	for (int i = 0; i < 15; ++i)
	{	
		if(i % 5 == 0)
			l.print(cout);
		l.simulate();
		l.run();
	}
	l.print(cout);
	
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ------------------
    // Fredkin Cell 90x90
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 90x90 ***" << endl;
        /*
        Creates a Life who's grid is 90x90.
        Live cells are inserted into every other position.
        Simulates 50 move.
        Prints every 10th grid.
        */
	int h = 90;
	int w = 90;
	Life<FredkinCell> l(h, w, '-');
	for(int x = 0; x < h; ++x)
	{
		for(int y = 0; y < w; ++y)
		{
			if(x % 2 == 0 && y % 2 == 0)
				l.insertCell(x, y, '0');
		}
	}
	
	l.print(cout);
	
	for (int i = 0; i < 50; ++i)
	{	
		if(i % 10 == 0)
			l.print(cout);
		l.simulate();
		l.run();
	}
	l.print(cout);
	
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
        /*
        Creates a Life who's grid is 60x60.
        Live cells are inserted into the whole top left corner of the grid.
        Simulates 100 moves.
        Prints every 20th grid
        */
	int h = 60;
	int w = 60;
	Life<FredkinCell> l(h, w, '-');
	for(int x = 0; x < h; ++x)
	{
		for(int y = 0; y < w; ++y)
		{
			if(y < w/2 && x < h/2)
				l.insertCell(x, y, '0');
		}
	}
	
	for (int i = 0; i < 100; ++i)
	{
		if(i % 20 == 0)
			l.print(cout);
		l.simulate();
		l.run();
	}
	l.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ------------------
    // Cell 20x20
    // ------------------

    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;
        /*
        Creates a Life who's grid is 20x20.
        Live cells are inserted in the whole first row.
        Simulates 15 moves.
        Prints every 5th grid
        */
	int h = 20;
	int w = 20;
	Life<Cell> l(h, w, '-');
	for(int x = 0; x < h; ++x)
	{
		for(int y = 0; y < w; ++y)
		{
			if(x == 0)
				l.insertCell(x, y, '0');
		}
	}
	
	for (int i = 0; i < 15; ++i)
	{
		if(i % 5 == 0)
			l.print(cout);
		l.simulate();
		l.run();
	}
	l.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ------------------
    // Cell 30x60
    // ------------------

    try {
        cout << "*** Life<Cell> 30x60 ***" << endl;
        /*
        Creates a Life who's grid is 30x60.
        Live cells are inserted into every row when x % 10 == 0.
        Simulates 15 moves.
        Prints every 5th grid
        */
	int h = 30;
	int w = 60;
	Life<Cell> l(h, w, '-');
	for(int x = 0; x < h; ++x)
	{
		for(int y = 0; y < w; ++y)
		{
			if(x % 10 == 0)
				l.insertCell(x, y, '0');
		}
	}
	
	for (int i = 0; i < 15; ++i)
	{	
		if(i % 5 == 0)
			l.print(cout);
		l.simulate();
		l.run();
	}
	l.print(cout);
	
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ------------------
    // Cell 90x90
    // ------------------

    try {
        cout << "*** Life<Cell> 90x90 ***" << endl;
        /*
        Creates a Life who's grid is 90x90.
        Live cells are inserted into every other position.
        Simulates 50 move.
        Prints every 10th grid.
        */
	int h = 90;
	int w = 90;
	Life<Cell> l(h, w, '-');
	for(int x = 0; x < h; ++x)
	{
		for(int y = 0; y < w; ++y)
		{
			if(x % 2 == 0 && y % 2 == 0)
				l.insertCell(x, y, '0');
		}
	}
	
	l.print(cout);
	
	for (int i = 0; i < 50; ++i)
	{	
		if(i % 10 == 0)
			l.print(cout);
		l.simulate();
		l.run();
	}
	l.print(cout);
	
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ------------------
    // Cell 60x60
    // ------------------

    try {
        cout << "*** Life<Cell> 60x60 ***" << endl;
        /*
        Creates a Life who's grid is 60x60.
        Live cells are inserted into the whole top left corner of the grid.
        Simulates 100 moves.
        Prints every 20th grid
        */
	int h = 60;
	int w = 60;
	Life<Cell> l(h, w, '-');
	for(int x = 0; x < h; ++x)
	{
		for(int y = 0; y < w; ++y)
		{
			if(y < w/2 && x < h/2)
				l.insertCell(x, y, '0');
		}
	}
	
	for (int i = 0; i < 100; ++i)
	{
		if(i % 20 == 0)
			l.print(cout);
		l.simulate();
		l.run();
	}
	l.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    return 0;}
