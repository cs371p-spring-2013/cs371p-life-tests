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
      Life<ConwayCell, 109, 69> g;
      ConwayCell a(true);
      for(int i=0; i<7; ++i) {
        g.addCell(34+(i*6),34,a);
        g.addCell(35+(i*6),34,a);
        g.addCell(36+(i*6),34,a);
        g.addCell(37+(i*6),34,a);
        g.addCell(38+(i*6),34,a);
      }

      g.printGrid();
      for(int i=0; i<9; ++i) {
        g.oneTurn();
        g.printGrid();
      }
      for(int i=9; i<283; ++i) {
        g.oneTurn();
      }
      g.printGrid();
      for(int i=283; i<323; ++i) {
        g.oneTurn();
      }
      g.printGrid();
      for(int i=323; i<2500; ++i) {
        g.oneTurn();
      }
      g.printGrid();
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
      Life<FredkinCell, 20, 20> g;
      FredkinCell a(true);
      g.addCell(9,9,a);
      g.addCell(9,10,a);
      g.addCell(10,9,a);
      g.addCell(10,10,a);

      g.printGrid();
      for (int i=0; i<5; ++i) {
        g.oneTurn();
        g.printGrid();
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
      Life<Cell, 20, 20> g;
      Cell a(new FredkinCell(true));
      Cell d(new FredkinCell(false));
      for(int i=0; i<20; ++i) {
        for(int j=0; j<20; ++j) {
          g.addCell(i,j,d);
        }
      }
      g.addCell(9,9,a);
      g.addCell(9,10,a);
      g.addCell(10,8,a);
      g.addCell(10,9,a);
      g.addCell(10,10,a);
      g.addCell(10,11,a);

      g.printGrid();
      for (int i=0; i<5; ++i) {
        g.oneTurn();
        g.printGrid();
      }
    }

    catch (const invalid_argument&) {
      assert(false);}
    catch (const out_of_range&) {
      assert(false);}

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

    // ------------------
    // Test Conway 1
    // ------------------

    try {
      cout << "*** Test Conway 1 ***" << endl;

      Life<ConwayCell, 6, 5> g;
      ConwayCell a(true);
      g.addCell(0,2,a);
      g.addCell(0,3,a);
      g.addCell(1,1,a);
      g.addCell(1,4,a);
      g.addCell(2,1,a);
      g.addCell(2,3,a);
      g.addCell(2,4,a);
      g.addCell(3,0,a);
      g.addCell(3,1,a);
      g.addCell(3,3,a);
      g.addCell(4,0,a);
      g.addCell(4,3,a);
      g.addCell(5,1,a);
      g.addCell(5,2,a);

      g.printGrid();
      g.oneTurn();
      g.printGrid();
      g.oneTurn();
      g.printGrid();
    }

    catch (const invalid_argument&) {
      assert(false);}
    catch (const out_of_range&) {
      assert(false);}

    // ------------------
    // Test Conway 2
    // ------------------

    try {
      cout << "*** Test Conway 2 ***" << endl;

      Life<ConwayCell, 10, 10> g;
      ConwayCell a(true);
      g.addCell(0,1,a);
      g.addCell(1,2,a);
      g.addCell(2,0,a);
      g.addCell(2,1,a);
      g.addCell(2,2,a);

      for (int i=0; i<10; ++i) {
        g.printGrid();
        g.oneTurn();
        g.oneTurn();
        g.oneTurn();
      }
      g.printGrid();
    }

    catch (const invalid_argument&) {
      assert(false);}
    catch (const out_of_range&) {
      assert(false);}

    // ------------------
    // Test Conway 3
    // ------------------

    try {
      cout << "*** Test Conway 3 ***" << endl;

      Life<ConwayCell, 3, 3> g;
      ConwayCell a(true);
      g.addCell(1,1,a);

      g.printGrid();
      g.oneTurn();
      g.printGrid();
      g.oneTurn();
      g.printGrid();
    }

    catch (const invalid_argument&) {
      assert(false);}
    catch (const out_of_range&) {
      assert(false);}

    // ------------------
    // Test Conway 4
    // ------------------

    try {
      cout << "*** Test Conway 4 ***" << endl;

      Life<ConwayCell, 3, 3> g;
      ConwayCell a(true);
      g.addCell(0,0,a);
      g.addCell(0,1,a);
      g.addCell(0,2,a);
      g.addCell(1,0,a);
      g.addCell(1,1,a);
      g.addCell(1,2,a);
      g.addCell(2,0,a);
      g.addCell(2,1,a);
      g.addCell(2,2,a);

      g.printGrid();
      g.oneTurn();
      g.printGrid();
      g.oneTurn();
      g.printGrid();
      g.oneTurn();
      g.printGrid();
    }

    catch (const invalid_argument&) {
      assert(false);}
    catch (const out_of_range&) {
      assert(false);}

    // ------------------
    // Test Conway 5
    // ------------------

    try {
      cout << "*** Test Conway 5 ***" << endl;

      Life<ConwayCell, 5, 5> g;
      ConwayCell a(true);
      g.addCell(0,0,a);
      g.addCell(0,1,a);
      g.addCell(1,0,a);
      g.addCell(1,1,a);
      g.addCell(4,4,a);
      g.addCell(4,3,a);
      g.addCell(3,4,a);
      g.addCell(3,3,a);
      g.addCell(4,0,a);
      g.addCell(3,0,a);
      g.addCell(4,1,a);
      g.addCell(3,1,a);
      g.addCell(0,4,a);
      g.addCell(0,3,a);
      g.addCell(1,4,a);
      g.addCell(1,3,a);

      g.printGrid();
      g.oneTurn();
      g.printGrid();
      g.oneTurn();
      g.printGrid();
    }

    catch (const invalid_argument&) {
      assert(false);}
    catch (const out_of_range&) {
      assert(false);}

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

    // ------------------
    // Test Fredkin 1
    // ------------------

    try {
      cout << "*** Test Fredkin 1 ***" << endl;

      Life<FredkinCell, 6, 5> g;
      FredkinCell a(true);
      g.addCell(0,2,a);
      g.addCell(0,3,a);
      g.addCell(1,1,a);
      g.addCell(1,4,a);
      g.addCell(2,1,a);
      g.addCell(2,3,a);
      g.addCell(2,4,a);
      g.addCell(3,0,a);
      g.addCell(3,1,a);
      g.addCell(3,3,a);
      g.addCell(4,0,a);
      g.addCell(4,3,a);
      g.addCell(5,1,a);
      g.addCell(5,2,a);

      g.printGrid();
      for (int i=0; i<30; ++i) {
        g.oneTurn();
      }
      g.printGrid();
    }

    catch (const invalid_argument&) {
      assert(false);}
    catch (const out_of_range&) {
      assert(false);}

    // ------------------
    // Test Fredkin 2
    // ------------------

    try {
      cout << "*** Test Fredkin 2 ***" << endl;

      Life<FredkinCell, 10, 10> g;
      FredkinCell a(true);
      g.addCell(0,1,a);
      g.addCell(1,2,a);
      g.addCell(2,0,a);
      g.addCell(2,1,a);
      g.addCell(2,2,a);

      g.printGrid();
      for (int i=0; i<30; ++i) {
        g.oneTurn();
      }
      g.printGrid();
    }

    catch (const invalid_argument&) {
      assert(false);}
    catch (const out_of_range&) {
      assert(false);}

    // ------------------
    // Test Fredkin 3
    // ------------------

    try {
      cout << "*** Test Fredkin 3 ***" << endl;

      Life<FredkinCell, 3, 3> g;
      FredkinCell a(true);
      g.addCell(1,1,a);

      g.printGrid();
      g.oneTurn();
      g.printGrid();
      g.oneTurn();
      g.printGrid();
      g.oneTurn();
      g.printGrid();
    }

    catch (const invalid_argument&) {
      assert(false);}
    catch (const out_of_range&) {
      assert(false);}

    // ------------------
    // Test Fredkin 4
    // ------------------

    try {
      cout << "*** Test Fredkin 4 ***" << endl;

      Life<FredkinCell, 3, 3> g;
      FredkinCell a(true);
      g.addCell(0,0,a);
      g.addCell(0,1,a);
      g.addCell(0,2,a);
      g.addCell(1,0,a);
      g.addCell(1,1,a);
      g.addCell(1,2,a);
      g.addCell(2,0,a);
      g.addCell(2,1,a);
      g.addCell(2,2,a);

      g.printGrid();
      g.oneTurn();
      g.printGrid();
      g.oneTurn();
      g.printGrid();
      g.oneTurn();
      g.printGrid();
    }

    catch (const invalid_argument&) {
      assert(false);}
    catch (const out_of_range&) {
      assert(false);}

    // ------------------
    // Test Fredkin 5
    // ------------------

    try {
      cout << "*** Test Fredkin 5 ***" << endl;

      Life<FredkinCell, 5, 5> g;
      FredkinCell a(true);
      g.addCell(0,0,a);
      g.addCell(0,1,a);
      g.addCell(1,0,a);
      g.addCell(1,1,a);
      g.addCell(4,4,a);
      g.addCell(4,3,a);
      g.addCell(3,4,a);
      g.addCell(3,3,a);
      g.addCell(4,0,a);
      g.addCell(3,0,a);
      g.addCell(4,1,a);
      g.addCell(3,1,a);
      g.addCell(0,4,a);
      g.addCell(0,3,a);
      g.addCell(1,4,a);
      g.addCell(1,3,a);

      g.printGrid();
      g.oneTurn();
      g.printGrid();
      g.oneTurn();
      g.printGrid();
    }

    catch (const invalid_argument&) {
      assert(false);}
    catch (const out_of_range&) {
      assert(false);}

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

    // ------------------
    // Test Cell 1
    // ------------------

    try {
      cout << "*** Test Cell 1 ***" << endl;

      Life<Cell, 6, 5> g;
      Cell a(new FredkinCell(true));
      Cell d(new FredkinCell(false));
      for(int i=0; i<6; ++i) {
        for(int j=0; j<5; ++j) {
          g.addCell(i,j,d);
        }
      }
      g.addCell(0,2,a);
      g.addCell(0,3,a);
      g.addCell(1,1,a);
      g.addCell(1,4,a);
      g.addCell(2,1,a);
      g.addCell(2,3,a);
      g.addCell(2,4,a);
      g.addCell(3,0,a);
      g.addCell(3,1,a);
      g.addCell(3,3,a);
      g.addCell(4,0,a);
      g.addCell(4,3,a);
      g.addCell(5,1,a);
      g.addCell(5,2,a);

      g.printGrid();
      for (int i=0; i<30; ++i) {
        g.oneTurn();
      }
      g.printGrid();
    }

    catch (const invalid_argument&) {
      assert(false);}
    catch (const out_of_range&) {
      assert(false);}

    // ------------------
    // Test Cell 2
    // ------------------

    try {
      cout << "*** Test Cell 2 ***" << endl;

      Life<Cell, 10, 10> g;
      Cell a(new FredkinCell(true));
      Cell d(new FredkinCell(false));
      for(int i=0; i<10; ++i) {
        for(int j=0; j<10; ++j) {
          g.addCell(i,j,d);
        }
      }
      g.addCell(0,1,a);
      g.addCell(1,2,a);
      g.addCell(2,0,a);
      g.addCell(2,1,a);
      g.addCell(2,2,a);

      g.printGrid();
      for (int i=0; i<30; ++i) {
        g.oneTurn();
      }
      g.printGrid();
    }

    catch (const invalid_argument&) {
      assert(false);}
    catch (const out_of_range&) {
      assert(false);}

    // ------------------
    // Test Cell 3
    // ------------------

    try {
      cout << "*** Test Cell 3 ***" << endl;

      Life<Cell, 3, 3> g;
      Cell a(new FredkinCell(true));
      Cell d(new FredkinCell(false));
      for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
          g.addCell(i,j,d);
        }
      }
      g.addCell(1,1,a);

      g.printGrid();
      g.oneTurn();
      g.printGrid();
      g.oneTurn();
      g.printGrid();
      g.oneTurn();
      g.printGrid();
    }

    catch (const invalid_argument&) {
      assert(false);}
    catch (const out_of_range&) {
      assert(false);}

    // ------------------
    // Test Cell 4
    // ------------------

    try {
      cout << "*** Test Cell 4 ***" << endl;

      Life<Cell, 3, 3> g;
      Cell a(new FredkinCell(true));
      Cell d(new FredkinCell(false));
      for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
          g.addCell(i,j,d);
        }
      }
      g.addCell(0,0,a);
      g.addCell(0,1,a);
      g.addCell(0,2,a);
      g.addCell(1,0,a);
      g.addCell(1,1,a);
      g.addCell(1,2,a);
      g.addCell(2,0,a);
      g.addCell(2,1,a);
      g.addCell(2,2,a);

      g.printGrid();
      g.oneTurn();
      g.printGrid();
      g.oneTurn();
      g.printGrid();
      g.oneTurn();
      g.printGrid();
    }

    catch (const invalid_argument&) {
      assert(false);}
    catch (const out_of_range&) {
      assert(false);}

    // ------------------
    // Test Cell 5
    // ------------------

    try {
      cout << "*** Test Cell 5 ***" << endl;

      Life<Cell, 5, 5> g;
      Cell a(new FredkinCell(true));
      Cell d(new FredkinCell(false));
      for(int i=0; i<5; ++i) {
        for(int j=0; j<5; ++j) {
          g.addCell(i,j,d);
        }
      }
      g.addCell(0,0,a);
      g.addCell(0,1,a);
      g.addCell(1,0,a);
      g.addCell(1,1,a);
      g.addCell(4,4,a);
      g.addCell(4,3,a);
      g.addCell(3,4,a);
      g.addCell(3,3,a);
      g.addCell(4,0,a);
      g.addCell(3,0,a);
      g.addCell(4,1,a);
      g.addCell(3,1,a);
      g.addCell(0,4,a);
      g.addCell(0,3,a);
      g.addCell(1,4,a);
      g.addCell(1,3,a);

      g.printGrid();
      g.oneTurn();
      g.printGrid();
      g.oneTurn();
      g.printGrid();
    }

    catch (const invalid_argument&) {
      assert(false);}
    catch (const out_of_range&) {
      assert(false);}

    return 0;}
