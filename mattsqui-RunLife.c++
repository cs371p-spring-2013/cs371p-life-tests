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
#include <string>

#include "Life.h"

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O



    // ------------------
    // Conway Cell 3x3
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 3x3 ***" << endl;
        /*
        Simulate 4 moves.
        Print every grid.
        */

        string s[3] = {"*.*",
                       "**.",
                       "*.*"};
        Life<ConwayCell> l = Life<ConwayCell>(3, 3);
        
        for(unsigned x = 0; x < 3; ++x) {
          for(unsigned y = 0; y < s[0].size(); ++y) {
            l.createCell(x, y, s[x].at(y));
          }
        }

        l.displayGrid();
        for(int x = 0; x < 4; ++x) {
          l.play();
          l.displayGrid();
        }
        cout << endl;

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Conway Cell 6x6
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 6x6 ***" << endl;
        /*
        Simulate 5 moves.
        Print every grid.
        */

        string s[6] = {"*.*.*.",
                       ".*.*.*",
                       "......",
                       "..**..",
                       ".*.*.*",
                       "*.*.*."};
        Life<ConwayCell> l = Life<ConwayCell>(6, 6);

        for(unsigned x = 0; x < 6; ++x) {
          for(unsigned y = 0; y < s[0].size(); ++y) {
            l.createCell(x, y, s[x].at(y));
          }
        }

        l.displayGrid();
        for(int x = 0; x < 5; ++x) {
          l.play();
          l.displayGrid();
        }
        cout << endl;

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Conway Cell 2x7
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 2x7 ***" << endl;
        /*
        Simulate 3 moves.
        Print every grid.
        */

        string s[2] = {"*******",
                       "......."};
        Life<ConwayCell> l = Life<ConwayCell>(2, 7);

        for(unsigned x = 0; x < 2; ++x) {
          for(unsigned y = 0; y < s[0].size(); ++y) {
            l.createCell(x, y, s[x].at(y));
          }
        }

        l.displayGrid();
        for(int x = 0; x < 3; ++x) {
          l.play();
          l.displayGrid();
        }
        cout << endl;

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Conway Cell 8x8
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 8x8 ***" << endl;
        /*
        Simulate 5 moves.
        Print every grid.
        */

        string s[8] = {".*......",
                       "***.....",
                       ".*......",
                       "......*.",
                       "......*.",
                       "...****.",
                       "......*.",
                       "........"};
        Life<ConwayCell> l = Life<ConwayCell>(8, 8);

        for(unsigned x = 0; x < 8; ++x) {
          for(unsigned y = 0; y < s[0].size(); ++y) {
            l.createCell(x, y, s[x].at(y));
          }
        }

        l.displayGrid();
        for(int x = 0; x < 5; ++x) {
          l.play();
          l.displayGrid();
        }
        cout << endl;

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Conway Cell 10x12
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 10x12 ***" << endl;
        /*
        Simulate 5 moves.
        Print every grid.
        */

        string s[10] = {"**.......***",
                        "**.......*..",
                        "**..........",
                        "**..........",
                        "**.....*....",
                        "**.....*....",
                        "**...*****..",
                        "**.....*....",
                        "**.....*....",
                        "**.........."};
        Life<ConwayCell> l = Life<ConwayCell>(10, 12);

        for(unsigned x = 0; x < 10; ++x) {
          for(unsigned y = 0; y < s[0].size(); ++y) {
            l.createCell(x, y, s[x].at(y));
          }
        }

        l.displayGrid();
        for(int x = 0; x < 5; ++x) {
          l.play();
          l.displayGrid();
        }
        cout << endl;

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

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

        ifstream file;
        file.open("RunLifeConway.in");
        if(file.is_open()) {
          int rows, cols;
          char rep;
          file >> rows;
          file >> cols;
          Life<ConwayCell> l = Life<ConwayCell>(rows, cols);

          for(int x = 0; x < rows; ++x) {
            for(int y = 0; y < cols; ++y) {
              file >> rep;
              l.createCell(x, y, rep); 
            }
          }

          l.displayGrid();
          for(int x = 0; x < 2500; ++x) { 
            l.play();
            if((x < 9) | (x == 282) | (x == 322) | (x == 2499)) 
              l.displayGrid(); 
          }
          file.close();
        }
        cout << endl;

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 3x3
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 3x3 ***" << endl;
        /*
        Simulate 4 moves.
        Print every grid.
        */

        string s[3] = {"0-0",
                       "---",
                       "-0-"};
        Life<FredkinCell> l = Life<FredkinCell>(3, 3);

        for(unsigned x = 0; x < 3; ++x) {
          for(unsigned y = 0; y < s[0].size(); ++y) {
            l.createCell(x, y, s[x].at(y));
          }
        }

        l.displayGrid();
        for(int x = 0; x < 4; ++x) {
          l.play();
          l.displayGrid();
        }
        cout << endl;

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 3x2
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 3x2 ***" << endl;
        /*
        Simulate 10 moves.
        Print generations 0, 5, 8, 9, and 10.
        */

        string s[3] = {"0-",
                       "00",
                       "0-"};
        Life<FredkinCell> l = Life<FredkinCell>(3, 2);

        for(unsigned x = 0; x < 3; ++x) {
          for(unsigned y = 0; y < s[0].size(); ++y) {
            l.createCell(x, y, s[x].at(y));
          }
        }

        l.displayGrid();
        for(int x = 0; x < 10; ++x) {
          l.play();
          if ((x == 4) | (x >= 7))
            l.displayGrid();
        }
        cout << endl;

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 2x5
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 2x5 ***" << endl;
        /*
        Simulate 5 moves.
        Print every grid.
        */

        string s[2] = {"0----",
                       "-----"};
        Life<FredkinCell> l = Life<FredkinCell>(2, 5);

        for(unsigned x = 0; x < 2; ++x) {
          for(unsigned y = 0; y < s[0].size(); ++y) {
            l.createCell(x, y, s[x].at(y));
          }
        }

        l.displayGrid();
        for(int x = 0; x < 5; ++x) {
          l.play();
          l.displayGrid();
        }
        cout << endl;

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 6x6
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 6x6 ***" << endl;
        /*
        Simulate 5 moves.
        Print every grid.
        */

        string s[6] = {"0----0",
                       "------",
                       "------",
                       "------",
                       "------",
                       "0----0"};
        Life<FredkinCell> l = Life<FredkinCell>(6, 6);

        for(unsigned x = 0; x < 6; ++x) {
          for(unsigned y = 0; y < s[0].size(); ++y) {
            l.createCell(x, y, s[x].at(y));
          }
        }

        l.displayGrid();
        for(int x = 0; x < 5; ++x) {
          l.play();
          l.displayGrid();
        }
        cout << endl;

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 7x7
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 7x7 ***" << endl;
        /*
        Simulate 5 moves.
        Print every grid.
        */

        string s[7] = {"0------",
                       "-------",
                       "-------",
                       "---0---",
                       "-------",
                       "-------",
                       "0------"};
        Life<FredkinCell> l = Life<FredkinCell>(7, 7);

        for(unsigned x = 0; x < 7; ++x) {
          for(unsigned y = 0; y < s[0].size(); ++y) {
            l.createCell(x, y, s[x].at(y));
          }
        }

        l.displayGrid();
        for(int x = 0; x < 5; ++x) {
          l.play();
          l.displayGrid();
        }
        cout << endl;

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

        ifstream file;
        file.open("RunLifeFredkin.in");
        if(file.is_open()) {
          int rows, cols;
          char rep;
          file >> rows;
          file >> cols;
          Life<FredkinCell> l = Life<FredkinCell>(rows, cols);

          for(int x = 0; x < rows; ++x) {
            for(int y = 0; y < cols; ++y) {
              file >> rep;
              l.createCell(x, y, rep);
            }
          }

          l.displayGrid();
          for(int x = 0; x < 5; ++x) {
            l.play();
            l.displayGrid();
          }
          file.close();
        }
        cout << endl;

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Cell 3x3
    // ------------------

    try {
        cout << "*** Life<Cell> 3x3 ***" << endl;
        /*
        Simulate 4 moves.
        Print every grid.
        */

        string s[3] = {"0-0",
                       "---",
                       "-0-"};
        Life<Cell> l = Life<Cell>(3, 3);

        for(unsigned x = 0; x < 3; ++x) {
          for(unsigned y = 0; y < s[0].size(); ++y) {
            l.createCell(x, y, s[x].at(y));
          }
        }

        l.displayGrid();
        for(int x = 0; x < 4; ++x) {
          l.play();
          l.displayGrid();
        }
        cout << endl;

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // Cell 4x4
    // ------------------

    try {
        cout << "*** Life<Cell> 4x4 ***" << endl;
        /*
        Simulate 4 moves.
        Print every grid.
        */

        string s[4] = {"----",
                       "-00-",
                       "-00-",
                       "----"};
        Life<Cell> l = Life<Cell>(4, 4);

        for(unsigned x = 0; x < 4; ++x) {
          for(unsigned y = 0; y < s[0].size(); ++y) {
            l.createCell(x, y, s[x].at(y));
          }
        }

        l.displayGrid();
        for(int x = 0; x < 4; ++x) {
          l.play();
          l.displayGrid();
        }
        cout << endl;

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Cell 5x8
    // ------------------

    try {
        cout << "*** Life<Cell> 5x8 ***" << endl;
        /*
        Simulate 5 moves.
        Print every grid.
        */

        string s[5] = {"0-------",
                       "--------",
                       "-------0",
                       "------00",
                       "-------0"};
        Life<Cell> l = Life<Cell>(5, 8);

        for(unsigned x = 0; x < 5; ++x) {
          for(unsigned y = 0; y < s[0].size(); ++y) {
            l.createCell(x, y, s[x].at(y));
          }
        }

        l.displayGrid();
        for(int x = 0; x < 5; ++x) {
          l.play();
          l.displayGrid();
        }
        cout << endl;

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Cell 6x6
    // ------------------

    try {
        cout << "*** Life<Cell> 6x6 ***" << endl;
        /*
        Simulate 5 moves.
        Print every grid.
        */

        string s[6] = {"0----0",
                       "------",
                       "------",
                       "------",
                       "------",
                       "0----0"};
        Life<Cell> l = Life<Cell>(6, 6);

        for(unsigned x = 0; x < 6; ++x) {
          for(unsigned y = 0; y < s[0].size(); ++y) {
            l.createCell(x, y, s[x].at(y));
          }
        }

        l.displayGrid();
        for(int x = 0; x < 5; ++x) {
          l.play();
          l.displayGrid();
        }
        cout << endl;

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Cell 10x8
    // ------------------

    try {
        cout << "*** Life<Cell> 10x8 ***" << endl;
        /*
        Simulate 8 moves.
        Print every grid.
        */

        string s[10] = {"0-------",
                        "0-------",
                        "0-------",
                        "0-------",
                        "0-------",
                        "0-------",
                        "0-------",
                        "0-------",
                        "0-------",
                        "0-------"};
        Life<Cell> l = Life<Cell>(10, 8);

        for(unsigned x = 0; x < 10; ++x) {
          for(unsigned y = 0; y < s[0].size(); ++y) {
            l.createCell(x, y, s[x].at(y));
          }
        }

        l.displayGrid();
        for(int x = 0; x < 8; ++x) {
          l.play();
          l.displayGrid();
        }
        cout << endl;

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

        ifstream file;
        file.open("RunLifeCell.in");
        if(file.is_open()) {
          int rows, cols;
          char rep;
          file >> rows;
          file >> cols;
          Life<Cell> l = Life<Cell>(rows, cols);

          for(int x = 0; x < rows; ++x) {
            for(int y = 0; y < cols; ++y) {
              file >> rep;
              l.createCell(x, y, rep);
            }
          }

          l.displayGrid();
          for(int x = 0; x < 5; ++x) {
            l.play();
            l.displayGrid();
          }
          file.close();
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}

