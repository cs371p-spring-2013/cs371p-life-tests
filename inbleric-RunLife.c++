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
#include <fstream>
#include <stdexcept> // invalid_argument, out_of_range
#include "AbstractCell.h" 
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Handle.h"
#include "Life.h"


// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    

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
	vector<vector<FredkinCell> >cells = vector<vector<FredkinCell> >(0);
        cells.resize(20/*y*/);
        for(int i = 0; i < 20/*y*/; ++i)
        	cells[i].resize(20/*x*/);
        string line;
        int lnum = 0;
        ifstream fileIn ("RunLifeFredkin.in");
        while (fileIn.good()) {
          ++lnum;
          getline (fileIn,line);
          for(int i = 0; i < (int)line.size(); ++i) {
            if(lnum > 2) {
              cells[lnum-3][i] = FredkinCell(i,lnum-3,line[i]);           		
            }
          }
        }
        fileIn.close();

        Life<FredkinCell> L = Life<FredkinCell>(20/*y*/,20/*x*/,cells);
        for(int i = 0; i < 5; ++i) {
        	L.printGrid();
        	L.doMoves(1);        	
        }
        L.printGrid();
        
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
        vector<vector<Cell> >cells = vector<vector<Cell> >(0);
        cells.resize(20/*y*/);
        for(int i = 0; i < 20/*y*/; ++i)
        	cells[i].resize(20/*x*/);
        string line;
        int lnum = 0;        
        ifstream fileIn ("RunLifeCell.in");
        
        while (fileIn.good()) {
          ++lnum;
          getline (fileIn,line);
          for(int i = 0; i < (int)line.size(); ++i) {
            if(lnum > 2) {
   	      if(line[i] == '.' || line[i] == '*')
	        cells[lnum-3][i] = Cell(new ConwayCell(i,lnum-3,line[i]));         		         		
	      else
	        cells[lnum-3][i] = Cell(new FredkinCell(i,lnum-3,line[i]));         		         		
            }
          }
        }
        fileIn.close();
        
        Life<Cell> L = Life<Cell>(20/*y*/,20/*x*/,cells);        
        for(int i = 0; i < 5; ++i) {
        	L.printGrid();
        	L.doMoves(1);        	
        }
        L.printGrid();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}        
        
        
        
        
        /*
        1x5
        5x1
        2x2
        3x3
        7x7
        
        
        */
        
        
        
        ///////////
        //CONWAY//
        //////////
        
        try {
        cout << "*** Life<ConwayCell> 1x5 ***" << endl;
       
        vector<vector<ConwayCell> >cells = vector<vector<ConwayCell> >(0);
        cells.resize(1/*y*/);
        for(int i = 0; i < 1/*y*/; ++i)
          cells[i].resize(5/*x*/);
        string line;
        int lnum = 0;
        ifstream fileIn ("RunLifeConway1.in");
        
        while (fileIn.good()) {                  	    
          getline (fileIn,line);
          ++lnum;
          for(int i = 0; i < (int)line.size(); ++i) {
	    if(lnum > 2) {
              cells[lnum-3][i] = ConwayCell(i,lnum-3,line[i]);
            }		
          }
        }
        fileIn.close();
        
        Life<ConwayCell> L = Life<ConwayCell>(1/*y*/,5/*x*/,cells);
        for(int i = 0; i < 5; ++i) {
        	L.printGrid();
        	L.doMoves(1);        	
        }
        L.printGrid();
       
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        try {
        cout << "*** Life<ConwayCell> 5x1 ***" << endl;
       
        vector<vector<ConwayCell> >cells = vector<vector<ConwayCell> >(0);
        cells.resize(5/*y*/);
        for(int i = 0; i < 5/*y*/; ++i)
          cells[i].resize(1/*x*/);
        string line;
        int lnum = 0;
        ifstream fileIn ("RunLifeConway2.in");
        
        while (fileIn.good()) {                  	    
          getline (fileIn,line);
          ++lnum;
          for(int i = 0; i < (int)line.size(); ++i) {
	    if(lnum > 2) {
              cells[lnum-3][i] = ConwayCell(i,lnum-3,line[i]);
            }		
          }
        }
        fileIn.close();
        
        Life<ConwayCell> L = Life<ConwayCell>(5/*y*/,1/*x*/,cells);
       for(int i = 0; i < 5; ++i) {
        	L.printGrid();
        	L.doMoves(1);        	
        }
        L.printGrid();
       
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        try {
        cout << "*** Life<ConwayCell> 2x2 ***" << endl;
       
        vector<vector<ConwayCell> >cells = vector<vector<ConwayCell> >(0);
        cells.resize(2/*y*/);
        for(int i = 0; i < 2/*y*/; ++i)
          cells[i].resize(2/*x*/);
        string line;
        int lnum = 0;
        ifstream fileIn ("RunLifeConway3.in");
        
        while (fileIn.good()) {                  	    
          getline (fileIn,line);
          ++lnum;
          for(int i = 0; i < (int)line.size(); ++i) {
	    if(lnum > 2) {
              cells[lnum-3][i] = ConwayCell(i,lnum-3,line[i]);
            }		
          }
        }
        fileIn.close();
        
        Life<ConwayCell> L = Life<ConwayCell>(2/*y*/,2/*x*/,cells);
       for(int i = 0; i < 5; ++i) {
        	L.printGrid();
        	L.doMoves(1);        	
        }
        L.printGrid();
       
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        try {
        cout << "*** Life<ConwayCell> 3x3 ***" << endl;
       
        vector<vector<ConwayCell> >cells = vector<vector<ConwayCell> >(0);
        cells.resize(3/*y*/);
        for(int i = 0; i < 3/*y*/; ++i)
          cells[i].resize(3/*x*/);
        string line;
        int lnum = 0;
        ifstream fileIn ("RunLifeConway4.in");
        
        while (fileIn.good()) {                  	    
          getline (fileIn,line);
          ++lnum;
          for(int i = 0; i < (int)line.size(); ++i) {
	    if(lnum > 2) {
              cells[lnum-3][i] = ConwayCell(i,lnum-3,line[i]);
            }		
          }
        }
        fileIn.close();
        
        Life<ConwayCell> L = Life<ConwayCell>(3/*y*/,3/*x*/,cells);
       for(int i = 0; i < 5; ++i) {
        	L.printGrid();
        	L.doMoves(1);        	
        }
        L.printGrid();
       
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        try {
        cout << "*** Life<ConwayCell> 7x7 ***" << endl;
       
        vector<vector<ConwayCell> >cells = vector<vector<ConwayCell> >(0);
        cells.resize(7/*y*/);
        for(int i = 0; i < 7/*y*/; ++i)
          cells[i].resize(7/*x*/);
        string line;
        int lnum = 0;
        ifstream fileIn ("RunLifeConway5.in");
        
        while (fileIn.good()) {                  	    
          getline (fileIn,line);
          ++lnum;
          for(int i = 0; i < (int)line.size(); ++i) {
	    if(lnum > 2) {
              cells[lnum-3][i] = ConwayCell(i,lnum-3,line[i]);
            }		
          }
        }
        fileIn.close();
        
        Life<ConwayCell> L = Life<ConwayCell>(7/*y*/,7/*x*/,cells);
       for(int i = 0; i < 5; ++i) {
        	L.printGrid();
        	L.doMoves(1);        	
        }
        L.printGrid();
       
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ///////////
        //FREDKIN//
        //////////
        
        try {
        cout << "*** Life<FredkinCell> 1x5 ***" << endl;
       
        vector<vector<FredkinCell> >cells = vector<vector<FredkinCell> >(0);
        cells.resize(1/*y*/);
        for(int i = 0; i < 1/*y*/; ++i)
          cells[i].resize(5/*x*/);
        string line;
        int lnum = 0;
        ifstream fileIn ("RunLifeFredkin1.in");
        
        while (fileIn.good()) {                  	    
          getline (fileIn,line);
          ++lnum;
          for(int i = 0; i < (int)line.size(); ++i) {
	    if(lnum > 2) {
              cells[lnum-3][i] = FredkinCell(i,lnum-3,line[i]);
            }		
          }
        }
        fileIn.close();
        
        Life<FredkinCell> L = Life<FredkinCell>(1/*y*/,5/*x*/,cells);
        for(int i = 0; i < 5; ++i) {
        	L.printGrid();
        	L.doMoves(1);        	
        }
        L.printGrid();
       
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        try {
        cout << "*** Life<FredkinCell> 5x1 ***" << endl;
       
        vector<vector<FredkinCell> >cells = vector<vector<FredkinCell> >(0);
        cells.resize(5/*y*/);
        for(int i = 0; i < 5/*y*/; ++i)
          cells[i].resize(1/*x*/);
        string line;
        int lnum = 0;
        ifstream fileIn ("RunLifeFredkin2.in");
        
        while (fileIn.good()) {                  	    
          getline (fileIn,line);
          ++lnum;
          for(int i = 0; i < (int)line.size(); ++i) {
	    if(lnum > 2) {
              cells[lnum-3][i] = FredkinCell(i,lnum-3,line[i]);
            }		
          }
        }
        fileIn.close();
        
        Life<FredkinCell> L = Life<FredkinCell>(5/*y*/,1/*x*/,cells);
       for(int i = 0; i < 5; ++i) {
        	L.printGrid();
        	L.doMoves(1);        	
        }
        L.printGrid();
       
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        try {
        cout << "*** Life<FredkinCell> 2x2 ***" << endl;
       
        vector<vector<FredkinCell> >cells = vector<vector<FredkinCell> >(0);
        cells.resize(2/*y*/);
        for(int i = 0; i < 2/*y*/; ++i)
          cells[i].resize(2/*x*/);
        string line;
        int lnum = 0;
        ifstream fileIn ("RunLifeFredkin3.in");
        
        while (fileIn.good()) {                  	    
          getline (fileIn,line);
          ++lnum;
          for(int i = 0; i < (int)line.size(); ++i) {
	    if(lnum > 2) {
              cells[lnum-3][i] = FredkinCell(i,lnum-3,line[i]);
            }		
          }
        }
        fileIn.close();
        
        Life<FredkinCell> L = Life<FredkinCell>(2/*y*/,2/*x*/,cells);
       for(int i = 0; i < 5; ++i) {
        	L.printGrid();
        	L.doMoves(1);        	
        }
        L.printGrid();
       
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        try {
        cout << "*** Life<FredkinCell> 3x3 ***" << endl;
       
        vector<vector<FredkinCell> >cells = vector<vector<FredkinCell> >(0);
        cells.resize(3/*y*/);
        for(int i = 0; i < 3/*y*/; ++i)
          cells[i].resize(3/*x*/);
        string line;
        int lnum = 0;
        ifstream fileIn ("RunLifeFredkin4.in");
        
        while (fileIn.good()) {                  	    
          getline (fileIn,line);
          ++lnum;
          for(int i = 0; i < (int)line.size(); ++i) {
	    if(lnum > 2) {
              cells[lnum-3][i] = FredkinCell(i,lnum-3,line[i]);
            }		
          }
        }
        fileIn.close();
        
        Life<FredkinCell> L = Life<FredkinCell>(3/*y*/,3/*x*/,cells);
       for(int i = 0; i < 5; ++i) {
        	L.printGrid();
        	L.doMoves(1);        	
        }
        L.printGrid();
       
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        try {
        cout << "*** Life<FredkinCell> 7x7 ***" << endl;
       
        vector<vector<FredkinCell> >cells = vector<vector<FredkinCell> >(0);
        cells.resize(7/*y*/);
        for(int i = 0; i < 7/*y*/; ++i)
          cells[i].resize(7/*x*/);
        string line;
        int lnum = 0;
        ifstream fileIn ("RunLifeFredkin5.in");
        
        while (fileIn.good()) {                  	    
          getline (fileIn,line);
          ++lnum;
          for(int i = 0; i < (int)line.size(); ++i) {
	    if(lnum > 2) {
              cells[lnum-3][i] = FredkinCell(i,lnum-3,line[i]);
            }		
          }
        }
        fileIn.close();
        
        Life<FredkinCell> L = Life<FredkinCell>(7/*y*/,7/*x*/,cells);
       for(int i = 0; i < 5; ++i) {
        	L.printGrid();
        	L.doMoves(1);        	
        }
        L.printGrid();
       
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ///////////
        //Cell//
        //////////
        
        try {
        cout << "*** Life<Cell> 1x5 ***" << endl;
       
        vector<vector<Cell> >cells = vector<vector<Cell> >(0);
        cells.resize(1/*y*/);
        for(int i = 0; i < 1/*y*/; ++i)
          cells[i].resize(5/*x*/);
        string line;
        int lnum = 0;
        ifstream fileIn ("RunLifeConway1.in");
        
        while (fileIn.good()) {
          ++lnum;
          getline (fileIn,line);
          for(int i = 0; i < (int)line.size(); ++i) {
            if(lnum > 2) {
   	      if(line[i] == '.' || line[i] == '*')
	        cells[lnum-3][i] = Cell(new ConwayCell(i,lnum-3,line[i]));         		         		
	      else
	        cells[lnum-3][i] = Cell(new FredkinCell(i,lnum-3,line[i]));         		         		
            }
          }
        }
        fileIn.close();
        
        Life<Cell> L = Life<Cell>(1/*y*/,5/*x*/,cells);
        for(int i = 0; i < 5; ++i) {
        	L.printGrid();
        	L.doMoves(1);        	
        }
        L.printGrid();
       
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        try {
        cout << "*** Life<Cell> 5x1 ***" << endl;
       
        vector<vector<Cell> >cells = vector<vector<Cell> >(0);
        cells.resize(5/*y*/);
        for(int i = 0; i < 5/*y*/; ++i)
          cells[i].resize(1/*x*/);
        string line;
        int lnum = 0;
        ifstream fileIn ("RunLifeConway2.in");
        
        while (fileIn.good()) {
          ++lnum;
          getline (fileIn,line);
          for(int i = 0; i < (int)line.size(); ++i) {
            if(lnum > 2) {
   	      if(line[i] == '.' || line[i] == '*')
	        cells[lnum-3][i] = Cell(new ConwayCell(i,lnum-3,line[i]));         		         		
	      else
	        cells[lnum-3][i] = Cell(new FredkinCell(i,lnum-3,line[i]));         		         		
            }
          }
        }
        fileIn.close();
        
        Life<Cell> L = Life<Cell>(5/*y*/,1/*x*/,cells);
       for(int i = 0; i < 5; ++i) {
        	L.printGrid();
        	L.doMoves(1);        	
        }
        L.printGrid();
       
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        try {
        cout << "*** Life<Cell> 2x2 ***" << endl;
       
        vector<vector<Cell> >cells = vector<vector<Cell> >(0);
        cells.resize(2/*y*/);
        for(int i = 0; i < 2/*y*/; ++i)
          cells[i].resize(2/*x*/);
        string line;
        int lnum = 0;
        ifstream fileIn ("RunLifeConway3.in");
        
        while (fileIn.good()) {
          ++lnum;
          getline (fileIn,line);
          for(int i = 0; i < (int)line.size(); ++i) {
            if(lnum > 2) {
   	      if(line[i] == '.' || line[i] == '*')
	        cells[lnum-3][i] = Cell(new ConwayCell(i,lnum-3,line[i]));         		         		
	      else
	        cells[lnum-3][i] = Cell(new FredkinCell(i,lnum-3,line[i]));         		         		
            }
          }
        }
        fileIn.close();
        
        Life<Cell> L = Life<Cell>(2/*y*/,2/*x*/,cells);
       for(int i = 0; i < 5; ++i) {
        	L.printGrid();
        	L.doMoves(1);        	
        }
        L.printGrid();
       
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        try {
        cout << "*** Life<Cell> 3x3 ***" << endl;
       
        vector<vector<Cell> >cells = vector<vector<Cell> >(0);
        cells.resize(3/*y*/);
        for(int i = 0; i < 3/*y*/; ++i)
          cells[i].resize(3/*x*/);
        string line;
        int lnum = 0;
        ifstream fileIn ("RunLifeConway4.in");
        
        while (fileIn.good()) {
          ++lnum;
          getline (fileIn,line);
          for(int i = 0; i < (int)line.size(); ++i) {
            if(lnum > 2) {
   	      if(line[i] == '.' || line[i] == '*')
	        cells[lnum-3][i] = Cell(new ConwayCell(i,lnum-3,line[i]));         		         		
	      else
	        cells[lnum-3][i] = Cell(new FredkinCell(i,lnum-3,line[i]));         		         		
            }
          }
        }
        fileIn.close();
        
        Life<Cell> L = Life<Cell>(3/*y*/,3/*x*/,cells);
       for(int i = 0; i < 5; ++i) {
        	L.printGrid();
        	L.doMoves(1);        	
        }
        L.printGrid();
       
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        try {
        cout << "*** Life<Cell> 7x7 ***" << endl;
       
        vector<vector<Cell> >cells = vector<vector<Cell> >(0);
        cells.resize(7/*y*/);
        for(int i = 0; i < 7/*y*/; ++i)
          cells[i].resize(7/*x*/);
        string line;
        int lnum = 0;
        ifstream fileIn ("RunLifeConway5.in");
        
        while (fileIn.good()) {
          ++lnum;
          getline (fileIn,line);
          for(int i = 0; i < (int)line.size(); ++i) {
            if(lnum > 2) {
   	      if(line[i] == '.' || line[i] == '*')
	        cells[lnum-3][i] = Cell(new ConwayCell(i,lnum-3,line[i]));         		         		
	      else
	        cells[lnum-3][i] = Cell(new FredkinCell(i,lnum-3,line[i]));         		         		
            }
          }
        }
        fileIn.close();
        
        Life<Cell> L = Life<Cell>(7/*y*/,7/*x*/,cells);
       for(int i = 0; i < 5; ++i) {
        	L.printGrid();
        	L.doMoves(1);        	
        }
        L.printGrid();
       
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
        vector<vector<ConwayCell> >cells = vector<vector<ConwayCell> >(0);
        cells.resize(109/*y*/);
        for(int i = 0; i < 109/*y*/; ++i)
          cells[i].resize(69/*x*/);
        string line;
        int lnum = 0;
        ifstream fileIn ("RunLifeConway.in");
        
        while (fileIn.good()) {                  	    
          getline (fileIn,line);
          ++lnum;
          for(int i = 0; i < (int)line.size(); ++i) {
	    if(lnum > 2) {
              cells[lnum-3][i] = ConwayCell(i,lnum-3,line[i]);
            }		
          }
        }
        fileIn.close();
        
        Life<ConwayCell> L = Life<ConwayCell>(109/*y*/,69/*x*/,cells);
        //for(int i = 0; i < 10; ++i) {
        	//do move
        	//print
        //}
        for(int i = 0; i < 10; ++i) {
	        L.printGrid();
                L.doMoves(1);
        }
        //do 273 moves
        //print
        L.doMoves(273);
        L.printGrid();
        //do 40
        //print
        L.doMoves(40);
        L.printGrid();
        //do 2177
        //print
        L.doMoves(2177);
        L.printGrid();
        
       
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        
        
    
        
        
        
        
        
        
        
        
        
        
        
        
        

    return 0;}

