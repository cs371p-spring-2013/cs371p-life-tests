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
#include <sstream>
#include <string>
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
        cout << "\n*** Life<ConwayCell> 109x69 ***" << endl;
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

        // Open file
        string filename("RunLifeConway.in");
        ifstream fileStream(filename.c_str(), fstream::in);

        /// Get grid dimensions from file
        unsigned int numRows;    
        unsigned int numColumns;
        
        string line;

        getline(fileStream, line);
        istringstream (line) >> numRows;

        getline(fileStream, line);
        istringstream (line) >> numColumns;

        /// Create Life
        Life<ConwayCell> life(numRows, numColumns);

        /// Initialize grid with data from file
        for(unsigned int r = 0; r < numRows; ++r) {
            getline(fileStream, line);  /// Read line of input into string
            for(unsigned int c = 0; c < numColumns; ++c) {
                const char symbol = line[c];
                life.addAbstractCell(symbol, r, c);
            }}
            
        fileStream.close();

        for(unsigned int turn = 0; turn < 283; ++turn) {
            if(turn < 10 || turn  == 282) {
                life.print(cout);
            }
            life.simulateTurn();
        }

        for(unsigned int i = 0; i < 40; ++i) {
            life.simulateTurn();
        }
        life.print(cout);

        for(unsigned int i = 0; i < 2177; ++i) {
            life.simulateTurn();
        }
        life.print(cout);
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

        // Open file
        string filename("RunLifeFredkin.in");
        ifstream fileStream(filename.c_str(), fstream::in);

        /// Get grid dimensions from file
        unsigned int numRows;    
        unsigned int numColumns;
        
        string line;

        getline(fileStream, line);
        istringstream (line) >> numRows;

        getline(fileStream, line);
        istringstream (line) >> numColumns;

        /// Create Life
        Life<FredkinCell> life(numRows, numColumns);

        /// Initialize grid with data from file
        for(unsigned int r = 0; r < numRows; ++r) {
            getline(fileStream, line);  /// Read line of input into string
            for(unsigned int c = 0; c < numColumns; ++c) {
                const char symbol = line[c];
                life.addAbstractCell(symbol, r, c);
            }}
            
        fileStream.close();

        life.print(cout);
        for(unsigned int turn = 0; turn < 5; ++turn) {
            life.simulateTurn();
            life.print(cout);
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

        // Open file
        string filename("RunLifeCell.in");
        ifstream fileStream(filename.c_str(), fstream::in);

        /// Get grid dimensions from file
        unsigned int numRows;    
        unsigned int numColumns;
        
        string line;

        getline(fileStream, line);
        istringstream (line) >> numRows;

        getline(fileStream, line);
        istringstream (line) >> numColumns;

        /// Create Life
        Life<Cell> life(numRows, numColumns);

        cout << "life" << endl;

        /// Initialize grid with data from file
        for(unsigned int r = 0; r < numRows; ++r) {
            getline(fileStream, line);  /// Read line of input into string
            for(unsigned int c = 0; c < numColumns; ++c) {
                const char symbol = line[c];
                life.addCell(symbol, r, c);
            }}
            
        fileStream.close();
        
        life.print(cout);
        for(unsigned int turn = 0; turn < 5; ++turn) {
            life.simulateTurn();
            life.print(cout);
        }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    try {
        cout << "\n*** Life<Cell> 25x25 One ***" << endl;
        Life<Cell> life(25, 25);
        for(unsigned int r = 0; r < 25; ++r) {
            for(unsigned int c = 0; c < 25; ++c) {
                if(r == 0 || r == 24 || c == 0 || c == 24) {
                    life.addCell('0', r, c);
                } else {
                    life.addCell('-', r, c);
                }
            }}

        for(unsigned int i = 0; i < 200; ++i) {
            if(i % 10 == 0) {
                life.print(cout);
            }
            life.simulateTurn();
        }
        life.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    try {
        cout << "\n*** Life<Cell> 100x25 Two ***" << endl;
        Life<Cell> life(25, 100);
        for(unsigned int r = 0; r < 25; ++r) {
            for(unsigned int c = 0; c < 100; ++c) {
                if(r == 0 || r == 24 || c == 0 || c == 99) {
                    life.addCell('0', r, c);
                } else {
                    life.addCell('-', r, c);
                }
            }}

        for(unsigned int i = 0; i < 200; ++i) {
            if(i % 10 == 0) {
                life.print(cout);
            }
            life.simulateTurn();
        }
        life.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    try {
        cout << "\n*** Life<Cell> 100x100 Three ***" << endl;
        Life<Cell> life(100, 100);
        for(unsigned int r = 0; r < 100; ++r) {
            for(unsigned int c = 0; c < 100; ++c) {
                if(r == 0 || r == 99 || c == 0 || c == 99) {
                    life.addCell('0', r, c);
                } else if(r == c) {
                    life.addCell('0', r, c);
                } else {
                    life.addCell('-', r, c);
                }
            }}

        for(unsigned int i = 0; i < 1000; ++i) {
            if(i % 50 == 0) {
                life.print(cout);
            }
            life.simulateTurn();
        }
        life.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    try {
        cout << "\n*** Life<Cell> 50x50 Four ***" << endl;
        Life<Cell> life(50, 50);
        for(unsigned int r = 0; r < 50; ++r) {
            for(unsigned int c = 0; c < 50; ++c) {
                if(r == 0 || r == 49 || c == 0 || c == 49) {
                    life.addCell('0', r, c);
                } else if(r == c) {
                    life.addCell('0', r, c);
                } else {
                    life.addCell('-', r, c);
                }
                    life.addCell('0', r, 49 - r);
            }}

        for(unsigned int i = 0; i < 100; ++i) {
            if(i % 10 == 0) {
                life.print(cout);
            }
            life.simulateTurn();
        }
        life.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "\n*** Life<ConwayCell> 25x200 One ***" << endl;
        Life<ConwayCell> life(25, 200);
        for(unsigned int r = 0; r < 25; ++r) {
            for(unsigned int c = 0; c < 200; ++c) {
                if(r % 7 == 0) {
                    life.addAbstractCell('*', r, c);
                } else if(c % 5 == 0) {
                    life.addAbstractCell('*', r, c);
                } else {
                    life.addAbstractCell('.', r, c);
                }
            }}

        for(unsigned int i = 0; i < 200; ++i) {
            if(i % 10 == 0) {
                life.print(cout);
            }
            life.simulateTurn();
        }
        life.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "\n*** Life<ConwayCell> 25x200 Two ***" << endl;
        Life<ConwayCell> life(25, 200);
        for(unsigned int r = 0; r < 25; ++r) {
            for(unsigned int c = 0; c < 200; ++c) {
                if(r % 3 == 0) {
                    life.addAbstractCell('*', r, c);
                } else if(c % 23 == 0) {
                    life.addAbstractCell('*', r, c);
                } else {
                    life.addAbstractCell('.', r, c);
                }
            }}

        for(unsigned int i = 0; i < 200; ++i) {
            if(i % 10 == 0) {
                life.print(cout);
            }
            life.simulateTurn();
        }
        life.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "\n*** Life<ConwayCell> 10x10 Three ***" << endl;
        Life<ConwayCell> life(10, 11);
        for(unsigned int r = 0; r < 10; ++r) {
            for(unsigned int c = 0; c < 11; ++c) {
                    life.addAbstractCell('.', r, c);
            }}
       
        life.addAbstractCell('*', 0, 0);
        life.addAbstractCell('*', 1, 0);
        life.addAbstractCell('*', 0, 1);
        life.addAbstractCell('*', 1, 1);
        life.addAbstractCell('*', 2, 2);
        life.addAbstractCell('*', 1, 2);
        life.addAbstractCell('*', 2, 3);
        life.addAbstractCell('*', 3, 3);
        life.addAbstractCell('*', 4, 5);

        for(unsigned int i = 0; i < 10; ++i) {
            if(i % 10 == 0) {
                life.print(cout);
            }
            life.simulateTurn();
        }
        life.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "\n*** Life<ConwayCell> 67x173 Four ***" << endl;
        Life<ConwayCell> life(67, 173);
        for(unsigned int r = 0; r < 67; ++r) {
            for(unsigned int c = 0; c < 173; ++c) {
                if(r % 11 == 0) {
                    life.addAbstractCell('*', r, c);
                } else if(c % 23 == 0) {
                    life.addAbstractCell('*', r, c);
                } else {
                    life.addAbstractCell('.', r, c);
                }
            }}
             life.addAbstractCell('*', 53, 97);
        for(unsigned int i = 0; i < 200; ++i) {
            if(i % 10 == 0) {
                life.print(cout);
            }
            life.simulateTurn();
        }
        life.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "\n*** Life<FredkinCell> 30x173 One ***" << endl;
        Life<FredkinCell> life(30, 173);
        for(unsigned int r = 0; r < 30; ++r) {
            for(unsigned int c = 0; c < 173; ++c) {
                if(r % 11 == 0) {
                    life.addAbstractCell('0', r, c);
                } else if(c % 23 == 0) {
                    life.addAbstractCell('0', r, c);
                } else {
                    life.addAbstractCell('-', r, c);
                }
            }}
             life.addAbstractCell('0', 22, 97);
        for(unsigned int i = 0; i < 200; ++i) {
            if(i % 10 == 0) {
                life.print(cout);
            }
            life.simulateTurn();
        }
        life.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "\n*** Life<FredkinCell> 30x91 Two ***" << endl;
        Life<FredkinCell> life(30, 91);
        for(unsigned int r = 0; r < 30; ++r) {
            for(unsigned int c = 0; c < 91; ++c) {
                if(r % 11 == 0) {
                    life.addAbstractCell('0', r, c);
                } else if(c % 23 == 0) {
                    life.addAbstractCell('0', r, c);
                } else {
                    life.addAbstractCell('-', r, c);
                }
            }}
             life.addAbstractCell('0', 22, 33);
        for(unsigned int i = 0; i < 200; ++i) {
            if(i % 10 == 0) {
                life.print(cout);
            }
            life.simulateTurn();
        }
        life.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "\n*** Life<FredkinCell> 30x51 Three ***" << endl;
        Life<FredkinCell> life(30, 51);
        for(unsigned int r = 0; r < 30; ++r) {
            for(unsigned int c = 0; c < 51; ++c) {
                if(r % 11 == 0) {
                    life.addAbstractCell('0', r, c);
                } else if(c % 23 == 0) {
                    life.addAbstractCell('0', r, c);
                } else {
                    life.addAbstractCell('-', r, c);
                }
            }}
             life.addAbstractCell('0', 22, 33);
        for(unsigned int i = 0; i < 200; ++i) {
            if(i % 10 == 0) {
                life.print(cout);
            }
            life.simulateTurn();
        }
        life.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "\n*** Life<FredkinCell> 20x20 Four ***" << endl;
        Life<FredkinCell> life(20, 20);
        for(unsigned int r = 0; r < 20; ++r) {
            for(unsigned int c = 0; c < 20; ++c) {
                if(r % 4 == 0) {
                    life.addAbstractCell('0', r, c);
                } else if(c % 5 == 0) {
                    life.addAbstractCell('0', r, c);
                } else {
                    life.addAbstractCell('-', r, c);
                }
            }}
             life.addAbstractCell('0',2, 3);
        for(unsigned int i = 0; i < 200; ++i) {
            if(i % 10 == 0) {
                life.print(cout);
            }
            life.simulateTurn();
        }
        life.print(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}




    return 0;}
