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
#include <fstream>   // input/output
#include <stdexcept> // invalid_argument, out_of_range
#include "Life.h"

// ----
// main
// ----

int main () {
    using namespace std;
//    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    int numTests = 0;
    char c = '\0';
    int row = 0;
    int col = 0;
 
    // ------------------
    // Conway Cell 109x69
    // ------------------

    try {
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
        ifstream file ("RunLifeConway.in");
        if(file.is_open()) {
           file >> numTests;
           while(numTests > 0) {
              file >> row >> col;
              cout << "\n*** Life<ConwayCell> " << row << "x" << col <<" ***" << endl;
              Life<ConwayCell> y(row, col);
              for(size_t i = 1; i < (size_t)row+1; ++i) {
                 for(size_t j = 1; j < (size_t)col+1; ++j) {
                    file >> c;
                    if(c == '*')
                       y.addCell(i, j, c);
                 }
              }
              cout << y;
              for(int i = 0; i < 5; ++i) {
                 y.executeTurn();
                 cout << y;
              }
              --numTests;
           }
        } else {
           throw ios_base::failure("Bad file read.");
        }
    } catch (const invalid_argument&) {
        assert(false);
    } catch (const out_of_range&) {
        assert(false);
    } catch (const ios_base::failure&) {
        assert(false);
    }

    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    try {
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        ifstream file ("RunLifeFredkin.in");
        if(file.is_open()) {
           file >> numTests;
           while(numTests > 0) {
              file >> row >> col;
              cout << "\n*** Life<FredkinCell> " << row << "x" << col <<" ***" << endl;
              Life<FredkinCell> y(row, col);
              for(size_t i = 1; i < (size_t)row+1; ++i) {
                 for(size_t j = 1; j < (size_t)col+1; ++j) {
                    file >> c;
                    if(c == '+' || ((int)c > 47 && (int)c < 58))
                       y.addCell(i, j, c);
                 }
              }
              cout << y;
              for(int i = 0; i < 5; ++i) {
                 y.executeTurn();
                 cout << y;
              }
              --numTests;
           }
        } else {
           throw ios_base::failure("Bad file read.");
        }
    } catch (const invalid_argument& e) {
        assert(false);
    } catch (const out_of_range&) {
        assert(false);
    } catch (const ios_base::failure&) {
        assert(false);
    }

    // ----------
    // Cell 20x20
    // ----------

    try {
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        ifstream file ("RunLifeCell.in");
        if(file.is_open()) {
           file >> numTests;
           while(numTests > 0) {
              file >> row >> col;
              cout << "\n*** Life<Cell> " << row << "x" << col <<" ***" << endl;
              Life<Cell> y(row, col);
              for(size_t i = 1; i < (size_t)row+1; ++i) {
                 for(size_t j = 1; j < (size_t)col+1; ++j) {
                    file >> c;
                    if(c == '+' || ((int)c > 47 && (int)c < 58))
                       y.addCell(i, j, c);
                 }
              }
              cout << y;
              for(int i = 0; i < 5; ++i) {
                 y.executeTurn();
                 cout << y;
              }
              --numTests;
           }
        } else {
           throw ios_base::failure("Bad file read.");
        }
    } catch (const invalid_argument& e) {
        assert(false);
    } catch (const out_of_range&) {
        assert(false);
    } catch (const ios_base::failure&) {
        assert(false);
    }
}
