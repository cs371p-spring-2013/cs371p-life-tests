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
#include <fstream> //reading from files
#include <stdexcept> // invalid_argument, out_of_range
#include "Life.h"
#include "Cell.h"
#include "AbstractCell.h"
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
    std::ifstream inCC ("RunLifeConway.in");
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
        
        Life<ConwayCell> x;

        int numAlive = 0;

        numAlive = x.makeBoard(inCC);

        // 283 moves, printing first 10 and 283rd
        for (int i = 0; i <= 283; i++) {
            if (i < 10 || i == 283) {
                cout << "Generation = " << i << ", Population = " << numAlive << "." << endl;
                x.printBoard(std::cout);
            }
            numAlive = x.takeTurn();
        }


        // 40 more moves
        for (int i = 0; i < 39; i++)
            numAlive = x.takeTurn();

        // printing 323rd grid
        cout << "Generation = 323, Population = " << numAlive << "." << endl;
        x.printBoard(std::cout);

        // 2177 moves
        for (int i = 0; i < 2177; i++)
            numAlive = x.takeTurn();

        // printing grid # 2500
        cout << "Generation = 2500, Population = " << numAlive << "." << endl;
        x.printBoard(std::cout);



        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -----------------
    // Conway Cell 10x10
    // -----------------
    try {
        cout << "*** Life<ConwayCell> 10x10 ***" << endl << endl;
            Life<ConwayCell> x;

            int numAlive = 0;

            numAlive = x.makeBoard(inCC);

            // 5 moves, printing before each
            for (int i = 0; i <= 5; i++) {
                cout << "Generation = " << i << ", Population = " << numAlive << "." << endl;
                x.printBoard(std::cout);
                numAlive = x.takeTurn();
            }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -----------------
    // Conway Cell 15x15
    // -----------------
    try {
        cout << "*** Life<ConwayCell> 15x15 ***" << endl << endl;
            Life<ConwayCell> x;

            int numAlive = 0;

            numAlive = x.makeBoard(inCC);

            // 5 moves, printing before each
            for (int i = 0; i <= 5; i++) {
                cout << "Generation = " << i << ", Population = " << numAlive << "." << endl;
                x.printBoard(std::cout);
                numAlive = x.takeTurn();
            }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ---------------
    // Conway Cell 5x5
    // ---------------
    try {
            cout << "*** Life<ConwayCell> 5x5 ***" << endl << endl;
            Life<ConwayCell> x;

            int numAlive = 0;

            numAlive = x.makeBoard(inCC);

            // 5 moves, printing before each
            for (int i = 0; i <= 5; i++) {
                cout << "Generation = " << i << ", Population = " << numAlive << "." << endl;
                x.printBoard(std::cout);
                numAlive = x.takeTurn();
            }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ---------------
    // Conway Cell 5x7
    // ---------------
    try {
        cout << "*** Life<ConwayCell> 5x7 ***" << endl << endl;
            Life<ConwayCell> x;

            int numAlive = 0;

            numAlive = x.makeBoard(inCC);

            // 5 moves, printing before each
            for (int i = 0; i <= 5; i++) {
                cout << "Generation = " << i << ", Population = " << numAlive << "." << endl;
                x.printBoard(std::cout);
                numAlive = x.takeTurn();
            }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    // -----------------
    // Conway Cell 10x10
    // -----------------
    try {
        cout << "*** Life<ConwayCell> 10x10 ***" << endl << endl;
            Life<ConwayCell> x;

            int numAlive = 0;

            numAlive = x.makeBoard(inCC);

            // 5 moves, printing before each
            for (int i = 0; i <= 5; i++) {
                cout << "Generation = " << i << ", Population = " << numAlive << "." << endl;
                x.printBoard(std::cout);
                numAlive = x.takeTurn();
            }


    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // Fredkin Cell 20x20
    // ------------------
    std::ifstream inF ("RunLifeFredkin.in");
    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

            
            Life<FredkinCell> x;

            int numAlive = 0;

            numAlive = x.makeBoard(inF);

            // 5 moves, printing before each
            for (int i = 0; i <= 5; i++) {
                cout << "Generation = " << i << ", Population = " << numAlive << "." << endl;
                x.printBoard(std::cout);
                numAlive = x.takeTurn();
            }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 11x10
    // ------------------
    try {
        cout << "*** Life<FredkinCell> 11x10 ***" << endl << endl;
            Life<FredkinCell> x;
            int numAlive = 0;

            numAlive = x.makeBoard(inF);

            // 5 moves, printing before each
            for (int i = 0; i <= 5; i++) {
                cout << "Generation = " << i << ", Population = " << numAlive << "." << endl;
                x.printBoard(std::cout);
                numAlive = x.takeTurn();
            }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Fredkin Cell 5x7
    // ----------------
    try {
        cout << "*** Life<FredkinCell> 5x7 ***" << endl << endl;
            Life<FredkinCell> x;
            int numAlive = 0;

            numAlive = x.makeBoard(inF);

            // 5 moves, printing before each
            for (int i = 0; i <= 5; i++) {
                cout << "Generation = " << i << ", Population = " << numAlive << "." << endl;
                x.printBoard(std::cout);
                numAlive = x.takeTurn();
            }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Fredkin Cell 5x5
    // ----------------
    try {
        cout << "*** Life<FredkinCell> 5x5***" << endl << endl;
            Life<FredkinCell> x;
            int numAlive = 0;

            numAlive = x.makeBoard(inF);

            // 5 moves, printing before each
            for (int i = 0; i <= 5; i++) {
                cout << "Generation = " << i << ", Population = " << numAlive << "." << endl;
                x.printBoard(std::cout);
                numAlive = x.takeTurn();
            }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Fredkin Cell 8x8
    // ----------------
    try {
        cout << "*** Life<FredkinCell> 8x8 ***" << endl << endl;
            Life<FredkinCell> x;
            int numAlive = 0;

            numAlive = x.makeBoard(inF);

            // 5 moves, printing before each
            for (int i = 0; i <= 5; i++) {
                cout << "Generation = " << i << ", Population = " << numAlive << "." << endl;
                x.printBoard(std::cout);
                numAlive = x.takeTurn();
            }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------------
    // Fredkin Cell 5x6
    // ----------------
    try {
        cout << "*** Life<FredkinCell> 5x6 ***" << endl << endl;
            Life<FredkinCell> x;
            int numAlive = 0;

            numAlive = x.makeBoard(inF);

            // 5 moves, printing before each
            for (int i = 0; i <= 5; i++) {
                cout << "Generation = " << i << ", Population = " << numAlive << "." << endl;
                x.printBoard(std::cout);
                numAlive = x.takeTurn();
            }


    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 20x20
    // ----------
    std::ifstream in ("RunLifeCell.in");
    try {
        cout << "*** Life<Cell> 20x20 ***" << endl << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

            Life<Cell> x;

            int numAlive = 0;

            numAlive = x.makeBoard(in);

            // 5 moves, printing before each
            for (int i = 0; i <= 5; i++) {
                cout << "Generation = " << i << ", Population = " << numAlive << "." << endl;
                x.printBoard(std::cout);
                numAlive = x.takeTurn();
            }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ---------
    // Cell 9x10
    // ---------
    try {
        cout << "*** Life<Cell> 9x10 ***" << endl << endl;
            Life<Cell> x;

            int numAlive = 0;

            numAlive = x.makeBoard(in);

            // 5 moves, printing before each
            for (int i = 0; i <= 5; i++) {
                cout << "Generation = " << i << ", Population = " << numAlive << "." << endl;
                x.printBoard(std::cout);
                numAlive = x.takeTurn();
            }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------
    // Cell 8x9
    // --------
    try {
        cout << "*** Life<Cell> 8x9 ***" << endl << endl;
            Life<Cell> x;

            int numAlive = 0;

            numAlive = x.makeBoard(in);

            // 5 moves, printing before each
            for (int i = 0; i <= 5; i++) {
                cout << "Generation = " << i << ", Population = " << numAlive << "." << endl;
                x.printBoard(std::cout);
                numAlive = x.takeTurn();
            }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------
    // Cell 6x6
    // --------
    try {
        cout << "*** Life<Cell> 6x6 ***" << endl << endl;
            Life<Cell> x;

            int numAlive = 0;

            numAlive = x.makeBoard(in);

            // 5 moves, printing before each
            for (int i = 0; i <= 5; i++) {
                cout << "Generation = " << i << ", Population = " << numAlive << "." << endl;
                x.printBoard(std::cout);
                numAlive = x.takeTurn();
            }


    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------
    // Cell 7x8
    // --------
    try {
        cout << "*** Life<Cell> 7x8 ***" << endl << endl;
            Life<Cell> x;

            int numAlive = 0;

            numAlive = x.makeBoard(in);

            // 5 moves, printing before each
            for (int i = 0; i <= 5; i++) {
                cout << "Generation = " << i << ", Population = " << numAlive << "." << endl;
                x.printBoard(std::cout);
                numAlive = x.takeTurn();
            }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------
    // Cell 11x11
    // ----------
    try {
        cout << "*** Life<Cell> 11x11 ***" << endl << endl;
            Life<Cell> x;

            int numAlive = 0;

            numAlive = x.makeBoard(in);

            // 5 moves, printing before each
            for (int i = 0; i <= 5; i++) {
                cout << "Generation = " << i << ", Population = " << numAlive << "." << endl;
                x.printBoard(std::cout);
                numAlive = x.takeTurn();
            }


    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
