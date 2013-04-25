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
#include <fstream> // fstream
#include "AbstractCell.h"
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
        fstream fs;
        fs.open("RunLifeConway.in", std::fstream::in);
        int num_gens = 2500;
        int x, y;
        fs >> x;
        fs >> y;
        Life<ConwayCell> l(x,y);
        fs >> l;
        fs.close();
        cout << l << endl;
		while(num_gens-- > 0)
		{
			int currentGen = 2500-num_gens;
			l.run_n_generations(1);
			if(currentGen < 10 || currentGen == 283 || currentGen == 323)
			{
				cout << l << endl;
			}
		}
		cout << l << endl;
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
        fstream fs;
        fs.open("RunLifeFredkin.in", std::fstream::in);
        int num_gens = 5;
        int x, y;
        fs >> x;
        fs >> y;
        Life<FredkinCell> l(x,y);
        fs >> l;
        fs.close();
        cout << l << endl;
		while(num_gens-- > 0)
		{
			l.run_n_generations(1);
			cout << l << endl;
		}
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
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
        fstream fs;
        fs.open("RunLifeCell.in", std::fstream::in);
        int num_gens = 5;
        int x, y;
        fs >> x;
        fs >> y;
        Life<Cell> l(x,y,new FredkinCell(0));
        fs >> l;
        fs.close();
        cout << l << endl;
		while(num_gens-- > 0)
		{
			l.run_n_generations(1);
			cout << l << endl;
		}
		cout << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    //ConwayCell Stuff Tests
    
     try {
        cout << "*** Life<ConwayCell> 3x3 ***" << endl;
        fstream fs;
        fs.open("AcceptanceTest1.in", std::fstream::in);
        int num_gens = 5;
        int x, y;
        fs >> x;
        fs >> y;
        Life<ConwayCell> l(x,y);
        fs >> l;
        fs.close();
        cout << l << endl;
		while(num_gens-- > 0)
		{
			l.run_n_generations(1);
			cout << l << endl;
		}
		cout << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    try {
        cout << "*** Life<ConwayCell> 4x6 ***" << endl;
        fstream fs;
        fs.open("AcceptanceTest2.in", std::fstream::in);
        int num_gens = 5;
        int x, y;
        fs >> x;
        fs >> y;
        Life<ConwayCell> l(x,y);
        fs >> l;
        fs.close();
        cout << l << endl;
		while(num_gens-- > 0)
		{
			l.run_n_generations(1);
			cout << l << endl;
		}
		cout << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
        cout << "*** Life<ConwayCell> 1x1 ***" << endl;
        fstream fs;
        fs.open("AcceptanceTest3.in", std::fstream::in);
        int num_gens = 5;
        int x, y;
        fs >> x;
        fs >> y;
        Life<ConwayCell> l(x,y);
        fs >> l;
        fs.close();
        cout << l << endl;
		while(num_gens-- > 0)
		{
			l.run_n_generations(1);
			cout << l << endl;
		}
		cout << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    try {
        cout << "*** Life<ConwayCell> 9x9 ***" << endl;
        fstream fs;
        fs.open("AcceptanceTest3.in", std::fstream::in);
        int num_gens = 10;
        int x, y;
        fs >> x;
        fs >> y;
        Life<ConwayCell> l(x,y);
        fs >> l;
        fs.close();
        cout << l << endl;
		while(num_gens-- > 0)
		{
			l.run_n_generations(1);
			cout << l << endl;
		}
		cout << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    try {
        cout << "*** Life<ConwayCell> 3x3 ***" << endl;
        fstream fs;
        fs.open("AcceptanceTest5.in", std::fstream::in);
        int num_gens = 5;
        int x, y;
        fs >> x;
        fs >> y;
        Life<ConwayCell> l(x,y);
        fs >> l;
        fs.close();
        cout << l << endl;
		while(num_gens-- > 0)
		{
			l.run_n_generations(1);
			cout << l << endl;
		}
		cout << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    try {
        cout << "*** Life<FredkinCell> 1x1 ***" << endl;
        fstream fs;
        fs.open("AcceptanceTest6.in", std::fstream::in);
        int num_gens = 5;
        int x, y;
        fs >> x;
        fs >> y;
        Life<FredkinCell> l(x,y);
        fs >> l;
        fs.close();
        cout << l << endl;
		while(num_gens-- > 0)
		{
			l.run_n_generations(1);
			cout << l << endl;
		}
		cout << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    try {
        cout << "*** Life<FredkinCell> 2x2 ***" << endl;
        fstream fs;
        fs.open("AcceptanceTest7.in", std::fstream::in);
        int num_gens = 5;
        int x, y;
        fs >> x;
        fs >> y;
        Life<FredkinCell> l(x,y);
        fs >> l;
        fs.close();
        cout << l << endl;
		while(num_gens-- > 0)
		{
			l.run_n_generations(1);
			cout << l << endl;
		}
		cout << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    try {
        cout << "*** Life<FredkinCell> 3x3 ***" << endl;
        fstream fs;
        fs.open("AcceptanceTest8.in", std::fstream::in);
        int num_gens = 5;
        int x, y;
        fs >> x;
        fs >> y;
        Life<FredkinCell> l(x,y);
        fs >> l;
        fs.close();
        cout << l << endl;
		while(num_gens-- > 0)
		{
			l.run_n_generations(1);
			cout << l << endl;
		}
		cout << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    try {
        cout << "*** Life<FredkinCell> 4x5 ***" << endl;
        fstream fs;
        fs.open("AcceptanceTest9.in", std::fstream::in);
        int num_gens = 10;
        int x, y;
        fs >> x;
        fs >> y;
        Life<FredkinCell> l(x,y);
        fs >> l;
        fs.close();
        cout << l << endl;
		while(num_gens-- > 0)
		{
			l.run_n_generations(1);
			cout << l << endl;
		}
		cout << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    try {
        cout << "*** Life<FredkinCell> 5x5 ***" << endl;
        fstream fs;
        fs.open("AcceptanceTest10.in", std::fstream::in);
        int num_gens = 10;
        int x, y;
        fs >> x;
        fs >> y;
        Life<FredkinCell> l(x,y);
        fs >> l;
        fs.close();
        cout << l << endl;
		while(num_gens-- > 0)
		{
			l.run_n_generations(1);
			cout << l << endl;
		}
		cout << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
   	try {
        cout << "*** Life<Cell> 1x1 ***" << endl;
        fstream fs;
        fs.open("AcceptanceTest11.in", std::fstream::in);
        int num_gens = 10;
        int x, y;
        fs >> x;
        fs >> y;
        Life<Cell> l(x,y,new FredkinCell(0));
        fs >> l;
        fs.close();
        cout << l << endl;
		while(num_gens-- > 0)
		{
			l.run_n_generations(1);
			cout << l << endl;
		}
		cout << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
        cout << "*** Life<Cell> 7x9 ***" << endl;
        fstream fs;
        fs.open("AcceptanceTest12.in", std::fstream::in);
        int num_gens = 10;
        int x, y;
        fs >> x;
        fs >> y;
        Life<Cell> l(x,y,new FredkinCell(0));
        fs >> l;
        fs.close();
        cout << l << endl;
		while(num_gens-- > 0)
		{
			l.run_n_generations(1);
			cout << l << endl;
		}
		cout << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
        cout << "*** Life<Cell> 5x5 ***" << endl;
        fstream fs;
        fs.open("AcceptanceTest13.in", std::fstream::in);
        int num_gens = 10;
        int x, y;
        fs >> x;
        fs >> y;
        Life<Cell> l(x,y,new FredkinCell(0));
        fs >> l;
        fs.close();
        cout << l << endl;
		while(num_gens-- > 0)
		{
			l.run_n_generations(1);
			cout << l << endl;
		}
		cout << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
        cout << "*** Life<Cell> 5x5 ***" << endl;
        fstream fs;
        fs.open("AcceptanceTest14.in", std::fstream::in);
        int num_gens = 10;
        int x, y;
        fs >> x;
        fs >> y;
        Life<Cell> l(x,y,new FredkinCell(0));
        fs >> l;
        fs.close();
        cout << l << endl;
		while(num_gens-- > 0)
		{
			l.run_n_generations(1);
			cout << l << endl;
		}
		cout << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
        cout << "*** Life<Cell> 5x5 ***" << endl;
        fstream fs;
        fs.open("AcceptanceTest15.in", std::fstream::in);
        int num_gens = 10;
        int x, y;
        fs >> x;
        fs >> y;
        Life<Cell> l(x,y,new FredkinCell(0));
        fs >> l;
        fs.close();
        cout << l << endl;
		while(num_gens-- > 0)
		{
			l.run_n_generations(1);
			cout << l << endl;
		}
		cout << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}

