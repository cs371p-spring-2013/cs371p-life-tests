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
#include "math.h" // invalid_argument, out_of_range
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
	Life<ConwayCell>  l(ConwayCell(true));
	l.read("RunLifeConway.in");
	for(int i = 0; i <= 2500; ++i) {
	  if((i<10) || (i == 283) || (i == 323)  || (i == 2500)) {
	    l.printGrid();
	  }
	  l.step();
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
	Life<FredkinCell>l (FredkinCell(true));
	l.read("RunLifeFredkin.in");
	
	l.printGrid();
	for(int i = 0; i < 5; ++i) {
	  l.step();
	  l.printGrid();
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
	Life<Cell> l (new FredkinCell(true));
	l.read("RunLifeCell.in");
	
	l.printGrid();
	for(int i = 0; i < 5; ++i) {
	  l.step();
	  l.printGrid();
	}

	
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        try {
        cout<< "conway acceptance 2"<<endl;
	Life<ConwayCell> l(ConwayCell(true));
	std::istringstream r("5\n40\n.**........**...**...**...**...**...**.."\
				   "\n...**.**.....**...**...**...**...**...**"\
				   "\n...**...**...**...**...**...**...**...**"\
				   "\n.**.....**.**...**...**...**...**...**.."\
				   "\n......**................................");
	l.read(r);
	
	l.printGrid();
	for(int i = 0; i < 50; ++i) {
	  l.step();
	  if(i % 10 == 0)
	    l.printGrid();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        try {
        cout<< "conway acceptance 3"<<endl;
	Life<ConwayCell> l(ConwayCell(true));
	std::istringstream r("10\n15\n...............\n..............."\
				    "\n..*............\n*.*............"\
				    "\n.**............\n....**........."\
				    "\n....*.*........\n......*........"\
				    "\n......**.......\n...............");
	l.read(r);
	
	l.printGrid();
	for(int i = 0; i < 4; ++i) {
	  l.step();
	  l.printGrid();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
         try {
        cout<< "conway acceptance 4 (gosper glider gun)" <<endl;
	Life<ConwayCell> l(ConwayCell(true));
	std::istringstream r("30\n50\n.................................................."\
				    "\n.................................................."\
				    "\n.................................................."\
				    "\n.................................................."\
				    "\n.................................................."\
				    "\n.................................................."\
				    "\n.................................................."\
				    "\n...........................**.........**.........."\
				    "\n..........................*.*.........**.........."\
				    "\n....**.......**...........**......................"\
				    "\n....**......*.*..................................."\
				    "\n............**......**............................"\
				    "\n....................*.*..........................."\
				    "\n....................*............................."\
				    "\n.......................................**........."\
				    "\n.......................................*.*........"\
				    "\n.......................................*.........."\
				    "\n.................................................."\
				    "\n.................................................."\
				    "\n............................***..................."\
				    "\n............................*....................."\
				    "\n.............................*...................."\
				    "\n.................................................."\
				    "\n.................................................."\
				    "\n.................................................."\
				    "\n.................................................."\
				    "\n.................................................."\
				    "\n.................................................."\
				    "\n.................................................."\
				    "\n..................................................");
	
	l.read(r);
	
	l.printGrid();
	for(int i = 0; i < 80; ++i) {
	  l.step();
	  if(i> 60 || i< 10)
	    l.printGrid();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        try {
        cout<< "conway acceptance 5 "<<endl;
	Life<ConwayCell> l(ConwayCell(true));
	std::istringstream r("10\n40\n........................................"\
				"\n........................................"\
				"\n........................................"\
				"\n........................................"\
				"\n.........*......*......................."\
				"\n........***....***......................"\
				"\n.......*...*..*..*......................"\
				"\n......*.....***..*......................"\
				"\n.....*.......*....*....................."\
				"\n........................................");
	l.read(r);
	
	l.printGrid();
	for(int i = 0; i < 10; ++i) {
	  l.step();
	  l.printGrid();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        try {
        cout<< "fredkin acceptance 2"<<endl;
	Life<FredkinCell> l(FredkinCell(true));
	std::istringstream r("10\n40\n----------------------------------------"\
				"\n----------------------------------------"\
				"\n----------------------------------------"\
				"\n----------------------------------------"\
				"\n---------0------0----------00000--------"\
				"\n--------000----000--------0-------------"\
				"\n-------0---0--0--0-------0--000---------"\
				"\n-------0---000---0--------0----0--------"\
				"\n------0-----0-----0--------00000--------"\
				"\n----------------------------------------");
	l.read(r);
	
	l.printGrid();
	for(int i = 0; i < 10; ++i) {
	  l.step();
	  l.printGrid();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
         try {
        cout<<"fredkin acceptance 3"<<endl;
	Life<FredkinCell> l(FredkinCell(true));
	std::istringstream r("5\n5\n--0--\n-0000\n00--0\n-----\n0000-");
	l.read(r);
	
	l.printGrid();
	for(int i = 0; i < 10; ++i) {
	  l.step();
	  l.printGrid();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
         try {
        cout<<"fredkin acceptance 4"<<endl;
	Life<FredkinCell> l(FredkinCell(true));
	std::istringstream r("5\n5\n--0--\n--0--\n--0--\n--0--\n--0--");
	l.read(r);
	
	l.printGrid();
	for(int i = 0; i < 10; ++i) {
	  l.step();
	  l.printGrid();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
	
	
	try {
        cout<<"fredkin acceptance 5"<<endl;
	Life<FredkinCell> l(FredkinCell(true));
	std::istringstream r("10\n10\n--0----0--\n--0----0--\n--0----0--\n--0----0--\n--0----0--");
	l.read(r);
	
	l.printGrid();
	for(int i = 0; i < 10; ++i) {
	  l.step();
	  l.printGrid();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        try {
        cout<<"fredkin acceptance 6"<<endl;
	Life<FredkinCell> l(FredkinCell(true));
	std::istringstream r("10\n10\n--0-0--0--\n--0-0--0--\n--0--0-0--\n0000---0--\n--000000--");
	l.read(r);
	
	l.printGrid();
	for(int i = 0; i < 10; ++i) {
	  l.step();
	  l.printGrid();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
         try {
        cout<<"cell acceptance 2"<<endl;
	Life<Cell> l(new FredkinCell(true));
	std::istringstream r("10\n10\n--0-0--0--\n--0-0--0--\n--0--0-0--\n0000---0--\n--000000--");
	l.read(r);
	
	l.printGrid();
	for(int i = 0; i < 10; ++i) {
	  l.step();
	  l.printGrid();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        try {
        cout<<"cell acceptance 3"<<endl;
	Life<Cell> l(new FredkinCell(true));
	std::istringstream r("5\n5\n--0-0\n--0-0\n--0--\n0000-\n--00-");
	l.read(r);
	
	l.printGrid();
	for(int i = 0; i < 10; ++i) {
	  l.step();
	  l.printGrid();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        try {
        cout<<"cell acceptance 4"<<endl;
	Life<Cell> l(new FredkinCell(true));
	std::istringstream r("5\n5\n00000\n00000\n00000\n00000\n00000");
	l.read(r);
	
	l.printGrid();
	for(int i = 0; i < 10; ++i) {
	  l.step();
	  l.printGrid();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        try {
        cout<<"cell acceptance 5"<<endl;
	Life<Cell> l(new FredkinCell(true));
	std::istringstream r("5\n5\n00-00\n00-00\n00-00\n00-00\n00-00");
	l.read(r);
	
	l.printGrid();
	for(int i = 0; i < 10; ++i) {
	  l.step();
	  l.printGrid();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}