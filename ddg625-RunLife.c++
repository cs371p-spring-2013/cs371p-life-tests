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
EXTRACT_ALL = YES
EXTRACT_PRIVATE = YES
EXTRACT_STATIC = YES
GENERATE_LATEX = NO

To document the program:
doxygen Doxyfile
*/

// --------
// includes
// --------

#include <cassert> // assert
#include <iostream> // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include <sstream>
#include <fstream>
#include <string>
#include "Life.h"


// ----
// main
// ----

int main ()
{
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    
    // ---------------
    // FredkinCell 3x3
    // ---------------

    try
    {
        cout << "*** Life<FredkinCell> 3x3 ***" << endl;
        
        istringstream r ("3\n3\n0-0\n-0-\n0-0\n");
        Life <FredkinCell> l = Life <FredkinCell> (r, false);
        l.print (cout);
        
        for (int i = 0; i < 5; ++i)
        {
            l.evolve (1);
            l.print (cout);
        }
    }
    catch (const invalid_argument&)
    {
        assert(false);
    }
    catch (const out_of_range&)
    {
        assert(false);
    }
    
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    // --------------
    // ConwayCell 5x5
    // --------------

    try
    {
        cout << "*** Life<ConwayCell> 5x5 ***" << endl;

        istringstream r ("5\n5\n.....\n..*..\n..*..\n..*..\n.....\n");
        Life <ConwayCell> l = Life <ConwayCell> (r, false);
        l.print (cout);

        for (int i = 0; i < 5; ++i)
        {
            l.evolve (1);
            l.print (cout);
        }
    }
    catch (const invalid_argument&)
    {
        assert(false);
    }
    catch (const out_of_range&)
    {
        assert(false);
    }

    // ----------------
    // ConwayCell 10x10
    // ----------------

    try
    {
        cout << "*** Life<ConwayCell> 10x10 ***" << endl;

        istringstream r ("10\n10\n..........\n.*......*.\n.*......*.\n.*......*.\n.*......*.\n.*......*.\n.*......*.\n.*......*.\n.*......*.\n..........\n");
        Life <ConwayCell> l = Life <ConwayCell> (r, false);
        l.print (cout);

        for (int i = 0; i < 10; ++i)
        {
            l.evolve (1);
            l.print (cout);
        }
    }
    catch (const invalid_argument&)
    {
        assert(false);
    }
    catch (const out_of_range&)
    {
        assert(false);
    }

    // ---------
    // Cell 30x3
    // ---------

    try
    {
        cout << "*** Life<Cell> 30x3 ***" << endl;

        istringstream r ("30\n3\n...\n.0.\n.0.\n.0.\n.0.\n.0.\n.0.\n.0.\n.0.\n.0.\n.0.\n.0.\n.0.\n.0.\n.0.\n.0.\n.0.\n.0.\n.0.\n.0.\n.0.\n.0.\n.0.\n.0.\n.0.\n.0.\n.0.\n.0.\n.0.\n...\n");
        Life <Cell> l = Life <Cell> (r, true);
        l.print (cout);

        for (int i = 0; i < 15; ++i)
        {
            l.evolve (1);
            l.print (cout);
        }
    }
    catch (const invalid_argument&)
    {
        assert(false);
    }
    catch (const out_of_range&)
    {
        assert(false);
    }

    // --------
    // Cell 4x4
    // --------

    try
    {
        cout << "*** Life<Cell> 4x4 ***" << endl;

        istringstream r ("4\n4\n----\n-00-\n-00-\n----\n");
        Life <Cell> l = Life <Cell> (r, true);
        l.print (cout);

        for (int i = 0; i < 10; ++i)
        {
            l.evolve (1);
            l.print (cout);
        }
    }
    catch (const invalid_argument&)
    {
        assert(false);
    }
    catch (const out_of_range&)
    {
        assert(false);
    }
    
    // ---------------
    // FredkinCell 5x5
    // ---------------

    try
    {
        cout << "*** Life<FredkinCell> 5x5 ***" << endl;

        istringstream r ("5\n5\n-000-\n0---0\n0---0\n0---0\n-000-\n");
        Life <FredkinCell> l = Life <FredkinCell> (r, false);
        l.print (cout);

        for (int i = 0; i < 10; ++i)
        {
            l.evolve (1);
            l.print (cout);
        }
    }
    catch (const invalid_argument&)
    {
        assert(false);
    }
    catch (const out_of_range&)
    {
        assert(false);
    }
    
    // --------------
    // ConwayCell 5x5
    // --------------

    try
    {
        cout << "*** Life<ConwayCell> 5x5 ***" << endl;

        istringstream r ("5\n5\n.***.\n*...*\n*...*\n*...*\n.***.\n");
        Life <ConwayCell> l = Life <ConwayCell> (r, false);
        l.print (cout);

        for (int i = 0; i < 10; ++i)
        {
            l.evolve (1);
            l.print (cout);
        }
    }
    catch (const invalid_argument&)
    {
        assert(false);
    }
    catch (const out_of_range&)
    {
        assert(false);
    }
    
    // --------
    // Cell 3x3
    // --------

    try
    {
        cout << "*** Life<Cell> 3x3 ***" << endl;

        istringstream r ("3\n3\n-0-\n000\n-0-\n");
        Life <Cell> l = Life <Cell> (r, true);
        l.print (cout);

        for (int i = 0; i < 10; ++i)
        {
            l.evolve (1);
            l.print (cout);
        }
    }
    catch (const invalid_argument&)
    {
        assert(false);
    }
    catch (const out_of_range&)
    {
        assert(false);
    }
    
    // ---------
    // Cell 3x10
    // ---------

    try
    {
        cout << "*** Life<Cell> 3x10 ***" << endl;

        istringstream r ("3\n10\n-0-0-0-0-0\n-0-0-0-0-0\n-0-0-0-0-0\n");
        Life <Cell> l = Life <Cell> (r, true);
        l.print (cout);

        for (int i = 0; i < 5; ++i)
        {
            l.evolve (1);
            l.print (cout);
        }
    }
    catch (const invalid_argument&)
    {
        assert(false);
    }
    catch (const out_of_range&)
    {
        assert(false);
    }
    
    // ----------
    // Cell 10x10
    // ----------

    try
    {
        cout << "*** Life<Cell> 10x10 ***" << endl;

        istringstream r ("10\n10\n----------\n-00----00-\n-00----00-\n----------\n-00----00-\n-00----00-\n----------\n-00----00-\n-00----00-\n----------\n");
        Life <Cell> l = Life <Cell> (r, true);
        l.print (cout);

        for (int i = 0; i < 10; ++i)
        {
            l.evolve (1);
            l.print (cout);
        }
    }
    catch (const invalid_argument&)
    {
        assert(false);
    }
    catch (const out_of_range&)
    {
        assert(false);
    }
    
    // ---------------
    // FredkinCell 4x4
    // ---------------

    try
    {
        cout << "*** Life<FredkinCell> 4x4 ***" << endl;

        istringstream r ("4\n4\n0000\n0--0\n-00-\n----\n");
        Life <FredkinCell> l = Life <FredkinCell> (r, false);
        l.print (cout);

        for (int i = 0; i < 10; ++i)
        {
            l.evolve (1);
            l.print (cout);
        }
    }
    catch (const invalid_argument&)
    {
        assert(false);
    }
    catch (const out_of_range&)
    {
        assert(false);
    }
    
    // --------------
    // ConwayCell 4x4
    // --------------

    try
    {
        cout << "*** Life<ConwayCell> 4x4 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

        istringstream r ("4\n4\n****\n*..*\n*..*\n****\n");
        Life <ConwayCell> l = Life <ConwayCell> (r, false);
        l.print (cout);

        for (int i = 0; i < 10; ++i)
        {
            l.evolve (1);
            l.print (cout);
        }
    }
    catch (const invalid_argument&)
    {
        assert(false);
    }
    catch (const out_of_range&)
    {
        assert(false);
    }
    
    // ---------------
    // FredkinCell 1x1
    // ---------------

    try
    {
        cout << "*** Life<FredkinCell> 1x1 ***" << endl;

        istringstream r ("1\n1\n0\n");
        Life <FredkinCell> l = Life <FredkinCell> (r, false);
        l.print (cout);
    }
    catch (const invalid_argument&)
    {
        assert(false);
    }
    catch (const out_of_range&)
    {
        assert(false);
    }
    
    // --------------
    // ConwayCell 1x1
    // --------------

    try
    {
        cout << "*** Life<ConwayCell> 1x1 ***" << endl;

        istringstream r ("1\n1\n.\n");
        Life <ConwayCell> l = Life <ConwayCell> (r, false);
        l.print (cout);
    }
    catch (const invalid_argument&)
    {
        assert(false);
    }
    catch (const out_of_range&)
    {
        assert(false);
    }
    
    // --------
    // Cell 2x8
    // --------

    try
    {
        cout << "*** Life<Cell> 2x8 ***" << endl;

        istringstream r ("2\n8\n--------\n-00--00-\n");
        Life <Cell> l = Life <Cell> (r, true);
        l.print (cout);

        for (int i = 0; i < 10; ++i)
        {
            l.evolve (1);
            l.print (cout);
        }
    }
    catch (const invalid_argument&)
    {
        assert(false);
    }
    catch (const out_of_range&)
    {
        assert(false);
    }

    // -----------------
    // ConwayCell 109x69
    // -----------------

    try
    {
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
        
        ifstream f ("RunLifeConway.in", fstream::in);
        
        Life <ConwayCell> l = Life <ConwayCell> (f, false);
        l.print (cout);
        
        for (int i = 0; i < 9; ++i)
        {
            l.evolve (1);
            l.print (cout);
        }
        
        l.evolve (274);
        l.print (cout);
        
        l.evolve (40);
        l.print (cout);
        
        l.evolve (2177);
        l.print (cout);
    }
    catch (const invalid_argument&)
    {
        assert(false);
    }
    catch (const out_of_range&)
    {
        assert(false);
    }

    // -----------------
    // FredkinCell 20x20
    // -----------------

    try
    {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        
        ifstream f ("RunLifeFredkin.in", fstream::in);
        Life <FredkinCell> l = Life <FredkinCell> (f, false);
        l.print (cout);
        
        for (int i = 0; i < 5; ++i)
        {
            l.evolve (1);
            l.print (cout);
        }
    }
    catch (const invalid_argument&)
    {
        assert(false);
    }
    catch (const out_of_range&)
    {
        assert(false);
    }

    // ----------
    // Cell 20x20
    // ----------

    try
    {
        cout << "*** Life<Cell> 20x20 ***" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        ifstream f ("RunLifeCell.in", fstream::in);
        Life <Cell> l = Life <Cell> (f, true);
        l.print (cout);
        
        for (int i = 0; i < 5; ++i)
        {
            l.evolve (1);
            l.print (cout);
        }
    }
    catch (const invalid_argument&)
    {
        assert(false);
    }
    catch (const out_of_range&)
    {
        assert(false);
    }

    return 0;
}
