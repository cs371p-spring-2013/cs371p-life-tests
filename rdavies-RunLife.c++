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
#include <fstream>   // ifstream
#include <stdexcept> // invalid_argument, out_of_range

#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
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

        cout << endl;

        int row, col;
        ifstream file("RunLifeConway.in");
        file >> row;
        file >> col;
        Life<ConwayCell> gameBoard(row, false);

        char c;
        for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
            file >> c;
            switch (c) {
              case '.':
                gameBoard.putCell(i, ConwayCell(1));
                break;
              case '*':
                gameBoard.putCell(i, ConwayCell(0));
                break;
            }
          } 
        }

        for (int i = 0; i <= 2500; i++) {
          if (i < 10) {
            gameBoard.printBoard(cout);
            cout << endl;
          }
          if (i == 283) {
            gameBoard.printBoard(cout);
            cout << endl;
          }
          if (i == 323) {
            gameBoard.printBoard(cout);
            cout << endl;
          }
          if (i == 2500) {
            gameBoard.printBoard(cout);
            cout << endl;
          }

          gameBoard.doGeneration();
        }
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

        cout << endl;

        int row, col;
        ifstream file("RunLifeFredkin.in");
        file >> row;
        file >> col;
        Life<FredkinCell> gameBoard(row, false);

        char c;
        for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
            file >> c;
            switch (c) {
              case '-':
                gameBoard.putCell(i, FredkinCell(1));
                break;
              case '0':
                gameBoard.putCell(i, FredkinCell(0));
                break;
            }
          } 
        }

        for (int i = 0; i <= 5; i++) {
          gameBoard.printBoard(cout);
          gameBoard.doGeneration();
          cout << endl;
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

        cout << endl;

        int row, col;
        ifstream file("RunLifeCell.in");
        file >> row;
        file >> col;
        Life<Cell> gameBoard(row, true);

        char c;
        for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
            file >> c;
            switch (c) {
              case '-':
                gameBoard.putCell(i, new FredkinCell(1));
                break;
              case '0':
                gameBoard.putCell(i, new FredkinCell(0));
                break;
            }
          } 
        }

        for (int i = 0; i <= 5; i++) {
          gameBoard.printBoard(cout);
          gameBoard.doGeneration();
          cout << endl;
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ---------------------
    // My_ConwayCell_1 10x10
    // ---------------------

    try{
        cout << "*** My_Life<ConwayCell>_1 10x20 ***" << endl;

        cout << endl;

        int row = 10;
        int col = 10;
        Life<ConwayCell> gameBoard(row, false);

        for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
              gameBoard.putCell(i, ConwayCell(1));
              gameBoard.putCell(i, ConwayCell(0));
          }
        } 

        for (int i = 0; i <= 5; i++) {
          gameBoard.printBoard(cout);
          gameBoard.doGeneration();
          cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ---------------------
    // My_ConwayCell_2 10x10
    // ---------------------

    try{
        cout << "*** My_Life<ConwayCell>_2 10x10 ***" << endl;

        cout << endl;

        int row = 10;
        int col = 10;
        Life<ConwayCell> gameBoard(row, false);

        for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
            if (j < 5 || i < 5)
              gameBoard.putCell(i, ConwayCell(1));
            else
              gameBoard.putCell(i, ConwayCell(0));
          }
        } 

        for (int i = 0; i <= 5; i++) {
          gameBoard.printBoard(cout);
          gameBoard.doGeneration();
          cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // -------------------
    // My_ConwayCell_3 5x5
    // -------------------

    try{
        cout << "*** My_Life<ConwayCell>_3 5x5 ***" << endl;

        cout << endl;

        int row = 5;
        int col = 5;
        Life<ConwayCell> gameBoard(row, false);

        for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
            if (j > 2 || i > 2)
              gameBoard.putCell(i, ConwayCell(1));
            else
              gameBoard.putCell(i, ConwayCell(0));
          }
        } 

        for (int i = 0; i <= 5; i++) {
          gameBoard.printBoard(cout);
          gameBoard.doGeneration();
          cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // --------------------
    // My_ConwayCell_4 10x5
    // --------------------

    try{
        cout << "*** My_Life<ConwayCell>_4 10x5 ***" << endl;

        cout << endl;

        int row = 10;
        int col = 5;
        Life<ConwayCell> gameBoard(row, false);

        for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
            if (j % 2 == 0 || i % 2 == 0)
              gameBoard.putCell(i, ConwayCell(1));
            else
              gameBoard.putCell(i, ConwayCell(0));
          }
        } 

        for (int i = 0; i <= 5; i++) {
          gameBoard.printBoard(cout);
          gameBoard.doGeneration();
          cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ---------------------
    // My_ConwayCell_5 10x10
    // ---------------------

    try{
        cout << "*** My_Life<ConwayCell>_5 10x10 ***" << endl;

        cout << endl;

        int row = 10;
        int col = 10;
        Life<ConwayCell> gameBoard(row, false);

        for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
            if (i <= 5 || j == 9)
              gameBoard.putCell(i, ConwayCell(0));
            else
              gameBoard.putCell(i, ConwayCell(1));
          }
        } 

        for (int i = 0; i <= 5; i++) {
          gameBoard.printBoard(cout);
          gameBoard.doGeneration();
          cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------------------
    // My_FredkinCell_1 10x10
    // ----------------------

    try{
        cout << "*** My_Life<FredkinCell>_1 10x10 ***" << endl;

        cout << endl;

        int row = 10;
        int col = 10;
        Life<FredkinCell> gameBoard(row, false);

        for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
            if (i <= 5 || j == 9)
              gameBoard.putCell(i, FredkinCell(0));
            else
              gameBoard.putCell(i, FredkinCell(1));
          }
        } 

        for (int i = 0; i <= 5; i++) {
          gameBoard.printBoard(cout);
          gameBoard.doGeneration();
          cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // --------------------
    // My_FredkinCell_2 5x5
    // --------------------

    try{
        cout << "*** My_Life<FredkinCell>_2 5x5 ***" << endl;

        cout << endl;

        int row = 5;
        int col = 5;
        Life<FredkinCell> gameBoard(row, false);

        for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
            if (i % 2 == 0)
              gameBoard.putCell(i, FredkinCell(0));
            else
              gameBoard.putCell(i, FredkinCell(1));
          }
        } 

        for (int i = 0; i <= 5; i++) {
          gameBoard.printBoard(cout);
          gameBoard.doGeneration();
          cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ---------------------
    // My_FredkinCell_3 5x15
    // ---------------------

    try{
        cout << "*** My_Life<FredkinCell>_3 5x15 ***" << endl;

        cout << endl;

        int row = 5;
        int col = 15;
        Life<FredkinCell> gameBoard(row, false);

        for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
            if (i > 3 || j > 5)
              gameBoard.putCell(i, FredkinCell(0));
            else
              gameBoard.putCell(i, FredkinCell(1));
          }
        } 

        for (int i = 0; i <= 5; i++) {
          gameBoard.printBoard(cout);
          gameBoard.doGeneration();
          cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ---------------------
    // My_FredkinCell_4 15x5
    // ---------------------

    try{
        cout << "*** My_Life<FredkinCell>_4 15x5 ***" << endl;

        cout << endl;

        int row = 15;
        int col = 5;
        Life<FredkinCell> gameBoard(row, false);

        for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
            if (i > 5 && j < 3)
              gameBoard.putCell(i, FredkinCell(0));
            else
              gameBoard.putCell(i, FredkinCell(1));
          }
        } 

        for (int i = 0; i <= 5; i++) {
          gameBoard.printBoard(cout);
          gameBoard.doGeneration();
          cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------------
    // My_FredkinCell_5 10x10
    // ----------------------

    try{
        cout << "*** My_Life<FredkinCell>_5 10x10 ***" << endl;

        cout << endl;

        int row = 10;
        int col = 10;
        Life<FredkinCell> gameBoard(row, false);

        for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
            if ((i != 3 && i != 5 && i != 6) || j % 2 == 0)
              gameBoard.putCell(i, FredkinCell(0));
            else
              gameBoard.putCell(i, FredkinCell(1));
          }
        } 

        for (int i = 0; i <= 5; i++) {
          gameBoard.printBoard(cout);
          gameBoard.doGeneration();
          cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ---------------
    // My_Cell_1 10x10
    // ---------------

    try{
        cout << "*** My_Life<Cell>_1 10x10 ***" << endl;

        cout << endl;

        int row = 10;
        int col = 10;
        Life<Cell> gameBoard(row, true);

        for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
            if (i < 3 || j < 5)
              gameBoard.putCell(i, new FredkinCell(0));
            else
              gameBoard.putCell(i, new FredkinCell(1));
          }
        } 

        for (int i = 0; i <= 5; i++) {
          gameBoard.printBoard(cout);
          gameBoard.doGeneration();
          cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -------------
    // My_Cell_2 5x5
    // -------------

    try{
        cout << "*** My_Life<Cell>_2 5x5 ***" << endl;

        cout << endl;

        int row = 5;
        int col = 5;
        Life<Cell> gameBoard(row, true);

        for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
            if (i < 2 || j % 2 == 0)
              gameBoard.putCell(i, new FredkinCell(0));
            else
              gameBoard.putCell(i, new FredkinCell(1));
          }
        } 

        for (int i = 0; i <= 5; i++) {
          gameBoard.printBoard(cout);
          gameBoard.doGeneration();
          cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -------------
    // My_Cell_3 5x5
    // -------------

    try{
        cout << "*** My_Life<Cell>_3 5x5 ***" << endl;

        cout << endl;

        int row = 5;
        int col = 5;
        Life<Cell> gameBoard(row, true);

        for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
            if (i < 3)
              gameBoard.putCell(i, new FredkinCell(0));
            else
              gameBoard.putCell(i, new ConwayCell(1));
          }
        } 

        for (int i = 0; i <= 5; i++) {
          gameBoard.printBoard(cout);
          gameBoard.doGeneration();
          cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ---------------
    // My_Cell_4 10x10
    // ---------------

    try{
        cout << "*** My_Life<Cell>_4 10x10 ***" << endl;

        cout << endl;

        int row = 10;
        int col = 10;
        Life<Cell> gameBoard(row, true);

        for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
            if (i < 3)
              gameBoard.putCell(i, new FredkinCell(0));
            else
              gameBoard.putCell(i, new ConwayCell(0));
          }
        } 

        for (int i = 0; i <= 5; i++) {
          gameBoard.printBoard(cout);
          gameBoard.doGeneration();
          cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ---------------
    // My_Cell_5 10x10
    // ---------------

    try{
        cout << "*** My_Life<Cell>_5 10x10 ***" << endl;

        cout << endl;

        int row = 10;
        int col = 10;
        Life<Cell> gameBoard(row, true);

        for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
            if (i < 3)
              gameBoard.putCell(i, new ConwayCell(0));
            else
              gameBoard.putCell(i, new FredkinCell(1));
          }
        } 

        for (int i = 0; i <= 5; i++) {
          gameBoard.printBoard(cout);
          gameBoard.doGeneration();
          cout << endl;
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    return 0;}
