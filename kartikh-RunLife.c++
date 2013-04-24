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
#include "AbstractCell.h"
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

        Life<ConwayCell> l ("RunLifeConway.in");
        for (int i = 0; i < 10; ++i) {
          std::cout << l;
          l.next_gen();
        }
        l.run(273);
        std::cout << l;
        l.run(40);
        std::cout << l;
        l.run(2177);
        std::cout << l;
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    try {
        cout << "\n*** Life<FredkinCell> 20x20 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

        Life<FredkinCell> l ("RunLifeFredkin.in");
        for (int i = 0; i < 6; ++i) {
          std::cout << l;
          l.next_gen();
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
        cout << "\n*** Life<Cell> 20x20 ***" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        Life<Cell> l ("RunLifeCell.in");
        for (int i = 0; i < 6; ++i) {
          std::cout << l;
          l.next_gen();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Conway 1x1
    // ----------

    try {
        cout << "\n*** Life<Conway>_1 1x1 ***" << endl;
        Life<ConwayCell> l (1, 1, ConwayCell(false));
        l.add_cell(0, 0, ConwayCell(true));
        for (int i = 0; i < 6; ++i) {
          std::cout << l;
          l.next_gen();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Conway 3x1
    // ----------

    try {
        cout << "\n*** Life<Conway>_2 3x1 ***" << endl;
        Life<ConwayCell> l (3, 1, ConwayCell(false));
        l.add_cell(0, 0, ConwayCell(true));
        l.add_cell(1, 0, ConwayCell(true));
        l.add_cell(2, 0, ConwayCell(true));
        for (int i = 0; i < 6; ++i) {
          std::cout << l;
          l.next_gen();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ----------
    // Conway 1x3
    // ----------

    try {
        cout << "\n*** Life<Conway>_3 1x3 ***" << endl;
        Life<ConwayCell> l (1, 3, ConwayCell(false));
        l.add_cell(0, 0, ConwayCell(true));
        l.add_cell(0, 1, ConwayCell(true));
        l.add_cell(0, 2, ConwayCell(true));
        for (int i = 0; i < 6; ++i) {
          std::cout << l;
          l.next_gen();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ----------
    // Conway 3x3
    // ----------

    try {
        cout << "\n*** Life<Conway>_4 3x3 ***" << endl;
        Life<ConwayCell> l (3, 3, ConwayCell(false));
        l.add_cell(1, 0, ConwayCell(true));
        l.add_cell(1, 1, ConwayCell(true));
        l.add_cell(1, 2, ConwayCell(true));
        for (int i = 0; i < 6; ++i) {
          std::cout << l;
          l.next_gen();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ----------
    // Conway 3x3
    // ----------

    try {
        cout << "\n*** Life<Conway>_5 3x3 ***" << endl;
        Life<ConwayCell> l (3, 3, ConwayCell(false));
        l.add_cell(0, 0, ConwayCell(true));
        l.add_cell(1, 0, ConwayCell(true));
        l.add_cell(2, 0, ConwayCell(true));
        l.add_cell(0, 1, ConwayCell(true));
        l.add_cell(0, 2, ConwayCell(true));
        l.add_cell(1, 2, ConwayCell(true));
        l.add_cell(2, 2, ConwayCell(true));
        for (int i = 0; i < 6; ++i) {
          std::cout << l;
          l.next_gen();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
 
    // -----------
    // Fredkin 1x1
    // -----------

    try {
        cout << "\n*** Life<Fredkin>_1 1x1 ***" << endl;
        Life<FredkinCell> l (1, 1, FredkinCell(false));
        l.add_cell(0, 0, FredkinCell(true));
        for (int i = 0; i < 6; ++i) {
          std::cout << l;
          l.next_gen();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Fredkin 3x1
    // ----------

    try {
        cout << "\n*** Life<Fredkin>_2 3x1 ***" << endl;
        Life<FredkinCell> l (3, 1, FredkinCell(false));
        l.add_cell(0, 0, FredkinCell(true));
        l.add_cell(1, 0, FredkinCell(true));
        l.add_cell(2, 0, FredkinCell(true));
        for (int i = 0; i < 6; ++i) {
          std::cout << l;
          l.next_gen();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ----------
    // Fredkin 1x3
    // ----------

    try {
        cout << "\n*** Life<Fredkin>_3 1x3 ***" << endl;
        Life<FredkinCell> l (1, 3, FredkinCell(false));
        l.add_cell(0, 0, FredkinCell(true));
        l.add_cell(0, 1, FredkinCell(true));
        l.add_cell(0, 2, FredkinCell(true));
        for (int i = 0; i < 6; ++i) {
          std::cout << l;
          l.next_gen();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ----------
    // Fredkin 3x3
    // ----------

    try {
        cout << "\n*** Life<Fredkin>_4 3x3 ***" << endl;
        Life<FredkinCell> l (3, 3, FredkinCell(false));
        l.add_cell(1, 0, FredkinCell(true));
        l.add_cell(1, 1, FredkinCell(true));
        l.add_cell(1, 2, FredkinCell(true));
        for (int i = 0; i < 6; ++i) {
          std::cout << l;
          l.next_gen();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ----------
    // Fredkin 3x3
    // ----------

    try {
        cout << "\n*** Life<Fredkin>_5 3x3 ***" << endl;
        Life<FredkinCell> l (3, 3, FredkinCell(false));
        l.add_cell(0, 0, FredkinCell(true));
        l.add_cell(1, 0, FredkinCell(true));
        l.add_cell(2, 0, FredkinCell(true));
        l.add_cell(0, 1, FredkinCell(true));
        l.add_cell(0, 2, FredkinCell(true));
        l.add_cell(1, 2, FredkinCell(true));
        l.add_cell(2, 2, FredkinCell(true));
        for (int i = 0; i < 6; ++i) {
          std::cout << l;
          l.next_gen();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // --------
    // Cell 1x1
    // --------

    try {
        cout << "\n*** Life<Cell>_1 1x1 ***" << endl;
        Life<Cell> l (1, 1, new FredkinCell(false));
        l.add_cell(0, 0, new FredkinCell(true));
        for (int i = 0; i < 6; ++i) {
          std::cout << l;
          l.next_gen();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------
    // Cell 3x1
    // --------

    try {
        cout << "\n*** Life<Cell>_2 3x1 ***" << endl;
        Life<Cell> l (3, 1, new FredkinCell(false));
        l.add_cell(0, 0, new FredkinCell(true));
        l.add_cell(1, 0, new FredkinCell(true));
        l.add_cell(2, 0, new FredkinCell(true));
        for (int i = 0; i < 6; ++i) {
          std::cout << l;
          l.next_gen();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // --------
    // Cell 1x3
    // --------

    try {
        cout << "\n*** Life<Cell>_3 1x3 ***" << endl;
        Life<Cell> l (1, 3, new FredkinCell(false));
        l.add_cell(0, 0, new FredkinCell(true));
        l.add_cell(0, 1, new FredkinCell(true));
        l.add_cell(0, 2, new FredkinCell(true));
        for (int i = 0; i < 6; ++i) {
          std::cout << l;
          l.next_gen();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ----------
    // Cell 3x3
    // ----------

    try {
        cout << "\n*** Life<Cell>_4 3x3 ***" << endl;
        Life<Cell> l (3, 3, new FredkinCell(false));
        l.add_cell(1, 0, new FredkinCell(true));
        l.add_cell(1, 1, new FredkinCell(true));
        l.add_cell(1, 2, new FredkinCell(true));
        for (int i = 0; i < 6; ++i) {
          std::cout << l;
          l.next_gen();
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // --------
    // Cell 3x3
    // --------

    try {
        cout << "\n*** Life<Cell>_5 3x3 ***" << endl;
        Life<Cell> l (3, 3, new FredkinCell(false));
        l.add_cell(0, 0, new FredkinCell(true));
        l.add_cell(1, 0, new FredkinCell(true));
        l.add_cell(2, 0, new FredkinCell(true));
        l.add_cell(0, 1, new FredkinCell(true));
        l.add_cell(0, 2, new FredkinCell(true));
        l.add_cell(1, 2, new FredkinCell(true));
        l.add_cell(2, 2, new FredkinCell(true));
        for (int i = 0; i < 6; ++i) {
          std::cout << l;
          l.next_gen();
        }
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    return 0;}
