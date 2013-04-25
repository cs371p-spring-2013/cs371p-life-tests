// -----------------------------
// Thomas Torres
// tmtorres
// Paul Carroll
// pvc95
// -----------------------------

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
#include <fstream>	 // read world from file
#include <stdexcept> // invalid_argument, out_of_range
#include <vector>

#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
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
		cout << "*** Life<ConwayCell> 109x69 ***" << endl;
		ifstream r;
		r.open ("RunLifeConway.in");
		int x;
		int y;
		char c;
		r >> x >> y;

        Life<ConwayCell> l(x, y);
		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j) {
				r >> c;
				if(c == '*')
					l.add(i, j, ConwayCell(1));
				else
					l.add(i, j, ConwayCell(0));
			}
		}
		r.close();
        l.simulate(10, 1);
        l.simulate(283);
        l.simulate(323);
        l.simulate(2500);

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
		ifstream r;
		r.open ("RunLifeFredkin.in");
		int x;
		int y;
		char c;
		r >> x >> y;

        Life<FredkinCell> l(x, y);
		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j) {
				r >> c;
				if(c == '0')
					l.add(i, j, FredkinCell(1));
				else
					l.add(i, j, FredkinCell(0));
			}
		}
		r.close();
		l.simulate(5, 1);
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
		ifstream r;
		r.open ("RunLifeCell.in");
		int x;
		int y;
		char c;
		r >> x >> y;

        Life<Cell> l(x, y);
		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j) {
				r >> c;
				if (c == '0')
					l.add(i, j, Cell(new FredkinCell(1)));
				else
					l.add(i, j, Cell(new FredkinCell(0)));
			}
		}
		r.close();
		l.simulate(5, 1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ---------------
    // Conway Cell 1x1
    // ---------------

    try {
		cout << "*** Life<ConwayCell> 1x1 ***" << endl;
        Life<ConwayCell> l(1, 1);
		l.add(0, 0, ConwayCell(1));
        l.simulate(5, 1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -----------------
    // Conway Cell 21x21
    // -----------------

    try {
		cout << "*** Life<ConwayCell> 21x21 ***" << endl;
        Life<ConwayCell> l(21, 21);
        for (int i = 1; i < 20; ++i) {
            for (int j = 1; j < 20; ++j) {
                if (!(21 % i)) {
                    l.add(i, j, ConwayCell(1));
                }
            }
        }
        l.simulate(10, 1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -----------------
    // Conway Cell 15x15
    // -----------------

    try {
		cout << "*** Life<ConwayCell> 15x15 ***" << endl;
        Life<ConwayCell> l(15, 15);
        for (int i = 1; i < 14; ++i) {
            for (int j = 1; j < 14; ++j) {
                if (15 % i && !(i % 2)) {
                    l.add(i, j, ConwayCell(1));
                }
            }
        }
        l.simulate(10, 1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -----------------
    // Conway Cell 10x10
    // -----------------

    try {
		cout << "*** Life<ConwayCell> 10x10 ***" << endl;
        Life<ConwayCell> l(10, 10);
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (i % 2) {
                    l.add(i, j, ConwayCell(1));
                }
            }
        }
        l.simulate(10, 1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // -----------------
    // Conway Cell 9x9
    // -----------------

    try {
		cout << "*** Life<ConwayCell> 9x9 ***" << endl;
        Life<ConwayCell> l(9, 9);
        for (int i = 1; i < 8; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (i == 4) {
                    l.add(i, j, ConwayCell(1));
                }
            }
        }
        l.simulate(10, 1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Fredkin Cell 1x1
    // ----------------

    try {
        cout << "*** Life<FredkinCell> 1x1 ***" << endl;
        Life<FredkinCell> l(1, 1);
		l.add (0, 0, FredkinCell(1));
        l.simulate(5, 1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 21x21
    // ------------------

    try {
		cout << "*** Life<FredkinCell> 21x21 ***" << endl;
        Life<FredkinCell> l(21, 21);
        for (int i = 1; i < 20; ++i) {
            for (int j = 1; j < 20; ++j) {
                if (21 % i) {
                    l.add(i, j, FredkinCell(1));
                }
            }
        }
        l.simulate(10, 1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 9x9
    // ------------------

    try {
		cout << "*** Life<FredkinCell> 21x21 ***" << endl;
        Life<FredkinCell> l(9, 9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (i == 4) {
                    l.add(i, j, FredkinCell(1));
                }
            }
        }
        l.simulate(10, 1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 12x12
    // ------------------

    try {
		cout << "*** Life<FredkinCell> 12x12 ***" << endl;
        Life<FredkinCell> l(12, 12);
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 12; ++j) {
                if (j > 3 && j < 8) {
                    l.add(i, j, FredkinCell(1));
                }
            }
        }
        l.simulate(10, 1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Fredkin Cell 6x6
    // ----------------

    try {
		cout << "*** Life<FredkinCell> 6x6 ***" << endl;
        Life<FredkinCell> l(6, 6);
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                    l.add(i, j, FredkinCell(1));
            }
        }
        l.simulate(10, 1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------
    // Cell 1x1
    // --------

    try {
        cout << "*** Life<Cell> 1x1 ***" << endl;
        Life<Cell> l(1, 1);
		l.add(0, 0, Cell(new ConwayCell(1)));
		l.simulate(5);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 21x21
    // ----------

    try {
        cout << "*** Life<Cell> 21x21 ***" << endl;
        Life<Cell> l(21, 21);
        for (int i = 0; i < 21; ++i) {
            for (int j = 0; j < 21; ++j) {
                l.add(i, j, Cell(new FredkinCell(1)));
            }
        }
		l.simulate(10, 1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 1x9
    // ----------

    try {
        cout << "*** Life<Cell> 1x9 ***" << endl;
        Life<Cell> l(1, 9);
        for (int i = 0; i < 9; ++i) {
            l.add(0, i, Cell(new FredkinCell(1)));
        }
		l.simulate(10, 1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------
    // Cell 7x7
    // --------

    try {
        cout << "*** Life<Cell> 7x7 ***" << endl;
        Life<Cell> l(7, 7);
        for (int i = 0; i < 7; ++i) {
            for (int j = 0; j < 7; ++j) {
                if (i % 2)
                    l.add(i, j, Cell(new ConwayCell(1)));
                else
                    l.add(i, j, Cell(new ConwayCell(0)));
            }
        }
		l.simulate(10, 1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 13x13
    // ----------

    try {
        cout << "*** Life<Cell> 13x13 ***" << endl;
        Life<Cell> l(13, 13);
        for (int i = 0; i < 13; ++i) {
            for (int j = 0; j < 13; ++j) {
                if (i % 2)
                    l.add(i, j, Cell(new ConwayCell(1)));
                else
                    l.add(i, j, Cell(new FredkinCell(1)));
            }
        }
		l.simulate(10, 1);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    return 0;
}
