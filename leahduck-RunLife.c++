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
#include <vector>

#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

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
        filebuf fb;
        fb.open("RunLifeConway.in", ios::in);
        int rows, cols;
        istream reader(&fb);
        reader >> rows;
        reader >> cols;
   		reader.ignore();		// get to first line of input
        vector<ConwayCell> v;
        Life<ConwayCell> l(rows, cols, v);
        int row = 0, col = 0;
        while(row != rows && !reader.eof()){
        	char c;
        	reader >> c;
  			bool isAlive = (c == '*') ? true : false;
        	ConwayCell temp(row, col, 0, isAlive);
        	l.addCell(temp);
        	if(++col == cols){
        		col = 0;
        		++row;
        	}
        }
        l.update();				//update after adding cells
		l.printGrid();
		for(int i = 0; i < 10; ++i){
			l.processTurns();
			l.update();
			l.printGrid();
		}
		for(int i = 10; i < 283; ++i){
			l.processTurns();
			l.update();
		}
		l.printGrid();
		for(int i = 283; i < 323; ++i){
			l.processTurns();
			l.update();
		}
		l.printGrid();
		for(int i = 323; i < 2500; ++i){
			l.processTurns();
			l.update();
		}
		l.printGrid();
		
        cout << endl;
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
        filebuf fb;
        fb.open("RunLifeFredkin.in", ios::in);
        int rows, cols;
        istream reader(&fb);
        reader >> rows;
        reader >> cols;
        reader.ignore();		//get to first line of input
        vector<FredkinCell> v;
        Life<FredkinCell> l(rows, cols, v);
        int row = 0, col = 0;
        while(row != rows && !reader.eof()){
        	char c;
        	reader >> c;
  			bool isAlive = (c == '0') ? true : false;
        	FredkinCell temp(row, col, 0, isAlive, 0);
        	l.addCell(temp);
        	if(++col == cols){
        		col = 0;
        		++row;
        	}
        }
        l.update();				//update after adding cells
		l.printGrid();
		for(int i = 0; i < 5; ++i){
			l.processTurns();
			l.update();
			l.printGrid();
		}
		
		cout << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
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
        filebuf fb;
        fb.open("RunLifeCell.in", ios::in);
        int rows, cols;
        istream reader(&fb);
        reader >> rows;
        reader >> cols;
        reader.ignore();		// get to first line of input
        vector<Cell> v;
        Life<Cell> l(rows, cols, v);
        int row = 0, col = 0;
        while(row != rows && !reader.eof()){
        	char c;
        	reader >> c;
  			bool isAlive = (c == '0') ? true : false;
        	Cell temp(new FredkinCell(row, col, 0, isAlive, 0));
        	l.addCell(temp);
        	if(++col == cols){
        		col = 0;
        		++row;
        	}
        }
		l.update();				//update after adding cells
		l.printGrid();
		for(int i = 0; i < 5 ; ++i){
			l.processTurns();
			l.update();
			l.printGrid();
		}
		
		cout << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // ----------
    // Conway 25x25
    // ----------

try {
        cout << "*** Life<ConwayCell> 25x25 ***" << endl;
        cout << endl;
        vector<ConwayCell> v;
        Life<ConwayCell> game(25,25, v);
	for(int i = 0; i < 25; ++i){
		for(int j = 0; j < 25; ++j){
			if(i == 0 && j == 2){
				ConwayCell c1(0,2,0,true);
        			game.addCell(c1);
			}
			else if(i == 1 && j == 3){
				ConwayCell c2(1,3,0,true);
        			game.addCell(c2);
			}
			else if(i == 2 && j == 3){
				ConwayCell c3(2,3,0,true);
        			game.addCell(c3);
			}
			else if(i == 2 && j == 2){
				ConwayCell c4(2,2,0,true);
      				  game.addCell(c4);
			}
		        else if(i == 2 && j == 1){
				ConwayCell c5(2,1,0,true);
      				  game.addCell(c5);
			}
			else{
				ConwayCell c(i,j,0,false);
				game.addCell(c);
			}

		}
	}
	game.update();				//update after adding cells
	game.printGrid();
        for(int i = 0; i < 10; ++i){
		game.processTurns();
		game.update();
		game.printGrid();
        }
        for(int i = 10; i < 20; ++i){
		game.processTurns();
		game.update();
        }
	game.printGrid();
        for(int i = 20; i < 50; ++i){
		game.processTurns();
		game.update();
        }
	game.printGrid();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // Conway 5x5
    // ----------

try {
        cout << "*** Life<ConwayCell> 5x5 ***" << endl;
        cout << endl;
        vector<ConwayCell> v;
        Life<ConwayCell> game(5,5, v);
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			if(i == 0){
				ConwayCell c1(0,j,0,true);
        			game.addCell(c1);
			}
			else if(i == 1){
				ConwayCell c2(1,j,0,false);
        			game.addCell(c2);
			}
			else if(i == 2){
				ConwayCell c3(2,j,0,true);
        			game.addCell(c3);
			}
			else if(i == 3){
				ConwayCell c4(3,j,0,false);
      				  game.addCell(c4);
			}
		        else{
				ConwayCell c5(4,j,0,true);
      				  game.addCell(c5);
			}
		}
	}
	game.update();				//update after adding cells
	game.printGrid();
        for(int i = 0; i < 10; ++i){
		game.processTurns();
		game.update();
		game.printGrid();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // Conway 10x10
    // ----------

try {
        cout << "*** Life<ConwayCell> 10x10 ***" << endl;
        cout << endl;
        vector<ConwayCell> v;
        Life<ConwayCell> game(10,10, v);
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < 10; ++j){
			if(i == 0){
				ConwayCell c1(0,j,0,true);
        			game.addCell(c1);
			}
			else if(i == 9){
				ConwayCell c2(9,j,0,true);
        			game.addCell(c2);
			}
			else if(j == 0){
				ConwayCell c3(i,0,0,true);
        			game.addCell(c3);
			}
			else if(j == 9){
				ConwayCell c4(i,9,0,true);
      				  game.addCell(c4);
			}
		        else{
				ConwayCell c5(i,j,0,false);
      				  game.addCell(c5);
			}
		}
	}
	game.update();				//update after adding cells
	game.printGrid();
        for(int i = 0; i < 10; ++i){
		game.processTurns();
		game.update();
		game.printGrid();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // Conway 10x10
    // ----------

try {
        cout << "*** Life<ConwayCell> 10x10 ***" << endl;
        cout << endl;
        vector<ConwayCell> v;
        Life<ConwayCell> game(10,10, v);
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < 10; ++j){
			if(i == 0){
				ConwayCell c1(0,j,0,false);
        			game.addCell(c1);
			}
			else if(i == 9){
				ConwayCell c2(9,j,0,false);
        			game.addCell(c2);
			}
			else if(j == 0){
				ConwayCell c3(i,0,0,false);
        			game.addCell(c3);
			}
			else if(j == 9){
				ConwayCell c4(i,9,0,false);
      				  game.addCell(c4);
			}
		        else{
				ConwayCell c5(i,j,0,true);
      				  game.addCell(c5);
			}
		}
	}
	game.update();				//update after adding cells
	game.printGrid();
        for(int i = 0; i < 10; ++i){
		game.processTurns();
		game.update();
		game.printGrid();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
 

    // ----------
    // Fredkin 5x5
    // ----------

try {
        cout << "*** Life<FredkinCell> 5x5 ***" << endl;
        cout << endl;
        vector<FredkinCell> v;
        Life<FredkinCell> game(5,5, v);
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			if(i == 1 && j == 1){
				FredkinCell c1(1,1,0,true,0);
        			game.addCell(c1);
			}
			else if(i == 1 && j == 2){
				FredkinCell c2(1,2,0,true,0);
        			game.addCell(c2);
			}
			else if(i == 2 && j == 1){
				FredkinCell c3(2,1,0,true,0);
        			game.addCell(c3);
			}
			else if(i == 2 && j == 3){
				FredkinCell c4(2,3,0,true,0);
      				game.addCell(c4);
			}
		        else if(i == 3 && j == 2){
				FredkinCell c5(3,2,0,true,0);
      				game.addCell(c5);
			}
			else{
				FredkinCell c(i,j,0,false,0);
				game.addCell(c);
			}

		}
	}
	game.update();				//update after adding cells
	game.printGrid();
        for(int i = 0; i < 10; ++i){
		game.processTurns();
		game.update();
		game.printGrid();
        }
	game.printGrid();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}    

    // ----------
    // Fredkin 25x25
    // ----------

try {
        cout << "*** Life<FredkinCell> 25x25 ***" << endl;
        cout << endl;
        vector<FredkinCell> v;
        Life<FredkinCell> game(25,25, v);
	for(int i = 0; i < 25; ++i){
		for(int j = 0; j < 25; ++j){
			if(i == 0 && j == 2){
				FredkinCell c1(0,2,0,true,0);
        			game.addCell(c1);
			}
			else if(i == 1 && j == 3){
				FredkinCell c2(1,3,0,true,0);
        			game.addCell(c2);
			}
			else if(i == 2 && j == 3){
				FredkinCell c3(2,3,0,true,0);
        			game.addCell(c3);
			}
			else if(i == 2 && j == 2){
				FredkinCell c4(2,2,0,true,0);
      				  game.addCell(c4);
			}
		        else if(i == 2 && j == 1){
				FredkinCell c5(2,1,0,true,0);
      				  game.addCell(c5);
			}
			else{
				FredkinCell c(i,j,0,false,0);
				game.addCell(c);
			}

		}
	}
	game.update();				//update after adding cells
	game.printGrid();
        for(int i = 0; i < 10; ++i){
		game.processTurns();
		game.update();
		game.printGrid();
        }
        for(int i = 10; i < 20; ++i){
		game.processTurns();
		game.update();
        }
	game.printGrid();
        for(int i = 20; i < 50; ++i){
		game.processTurns();
		game.update();
        }
	game.printGrid();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}   


    // ----------
    // Fredkin 5x5
    // ----------

try {
        cout << "*** Life<FredkinCell> 5x5 ***" << endl;
        cout << endl;
        vector<FredkinCell> v;
        Life<FredkinCell> game(5,5, v);
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			if(i == 1 && j == 1){
				FredkinCell c1(1,1,0,true,0);
        			game.addCell(c1);
			}
			else if(i == 2 && j == 1){
				FredkinCell c2(2,1,0,true,0);
        			game.addCell(c2);
			}
			else if(i == 1 && j == 2){
				FredkinCell c3(1,2,0,true,0);
        			game.addCell(c3);
			}
			else if(i == 4 && j == 4){
				FredkinCell c4(4,4,0,true,0);
      				  game.addCell(c4);
			}
		        else if(i == 4 && j == 3){
				FredkinCell c5(4,3,0,true,0);
      				  game.addCell(c5);
			}
			else{
				FredkinCell c(i,j,0,false,0);
				game.addCell(c);
			}

		}
	}
	game.update();				//update after adding cells
	game.printGrid();
        for(int i = 0; i < 10; ++i){
		game.processTurns();
		game.update();
		game.printGrid();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);} 

    // ----------
    // Fredkin 10x10
    // ----------

try {
        cout << "*** Life<FredkinCell> 10x10 ***" << endl;
        cout << endl;
        vector<FredkinCell> v;
        Life<FredkinCell> game(10,10, v);
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < 10; ++j){
			if(i == 0){
				FredkinCell c1(0,j,0,false,0);
        			game.addCell(c1);
			}
			else if(i == 9){
				FredkinCell c2(9,j,0,false,0);
        			game.addCell(c2);
			}
			else if(j == 0){
				FredkinCell c3(i,0,0,false,0);
        			game.addCell(c3);
			}
			else if(j == 9){
				FredkinCell c4(i,9,0,false,0);
      				  game.addCell(c4);
			}
		        else{
				FredkinCell c5(i,j,0,true,0);
      				  game.addCell(c5);
			}
		}
	}
	game.update();				//update after adding cells
	game.printGrid();
        for(int i = 0; i < 10; ++i){
		game.processTurns();
		game.update();
		game.printGrid();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // Fredkin 5x5
    // ----------

try {
        cout << "*** Life<FredkinCell> 5x5 ***" << endl;
        cout << endl;
        vector<FredkinCell> v;
        Life<FredkinCell> game(5,5, v);
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			if(i == 0){
				FredkinCell c1(0,j,0,false,0);
        			game.addCell(c1);
			}
			else if(i == 4){
				FredkinCell c2(9,j,0,false,0);
        			game.addCell(c2);
			}
			else if(j == 0){
				FredkinCell c3(i,0,0,false,0);
        			game.addCell(c3);
			}
			else if(j == 4){
				FredkinCell c4(i,9,0,false,0);
      				  game.addCell(c4);
			}
			else if(i == 1){
				FredkinCell c5(1,j,0,false,0);
        			game.addCell(c5);
			}
			else if(i == 3){
				FredkinCell c6(3,j,0,false,0);
        			game.addCell(c6);
			}
			else if(j == 1){
				FredkinCell c7(i,1,0,false,0);
        			game.addCell(c7);
			}
			else if(j == 3){
				FredkinCell c4(i,3,0,false,0);
      				  game.addCell(c4);
			}
		        else{
				FredkinCell c5(i,j,0,true,0);
      				  game.addCell(c5);
			}
		}
	}
	game.update();				//update after adding cells
	game.printGrid();
        for(int i = 0; i < 10; ++i){
		game.processTurns();
		game.update();
		game.printGrid();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 5x5
    // ----------

try {
        cout << "*** Life<Cell> 5x5***" << endl;
        cout << endl;
        vector<Cell> v;
        Life<Cell> game(5,5, v);
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			if(i == 0 && j == 0){
				Cell c1(new ConwayCell(0,0,0,true));
        			game.addCell(c1);
			}
			else if(i == 0 && j == 4){
				Cell c2(new ConwayCell(0,4,0,true));
        			game.addCell(c2);
			}
			else if(i == 4 && j == 0){
				Cell c3(new ConwayCell(4,0,0,true));
        			game.addCell(c3);
			}
			else if(i == 4 && j == 4){
				Cell c4(new ConwayCell(4,4,0,true));
      				game.addCell(c4);
			}
		        else if(i == 1 && j == 2){
				Cell c5(new FredkinCell(1,2,0,true,0));
      				game.addCell(c5);
			}
		        else if(i == 2 && j == 2){
				Cell c6(new FredkinCell(2,2,0,true,0));
      				game.addCell(c6);
			}
		        else if(i == 3 && j == 2){
				Cell c7(new FredkinCell(3,2,0,true,0));
      				game.addCell(c7);
			}
			else{
				Cell c(new ConwayCell(i,j,0,false));
				game.addCell(c);
			}

		}
	}
	game.update();				//update after adding cells
	game.printGrid();
        for(int i = 0; i < 10; ++i){
		game.processTurns();
		game.update();
		game.printGrid();
        }
        for(int i = 10; i < 20; ++i){
		game.processTurns();
		game.update();
        }
	game.printGrid();
        for(int i = 20; i < 50; ++i){
		game.processTurns();
		game.update();
        }
	game.printGrid();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // Cell 10x10
    // ----------

try {
        cout << "*** Life<Cell> 10x10***" << endl;
        cout << endl;
        vector<Cell> v;
        Life<Cell> game(10,10, v);
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < 10; ++j){
			if(i == 0){
				Cell c1(new ConwayCell(0,j,0,true));
        			game.addCell(c1);
			}
			else if(i == 9){
				Cell c2(new ConwayCell(9,j,0,true));
        			game.addCell(c2);
			}
			else if(j == 0){
				Cell c3(new ConwayCell(i,0,0,true));
        			game.addCell(c3);
			}
			else if(j == 9){
				Cell c4(new ConwayCell(i,9,0,true));
      				game.addCell(c4);
			}
			else{
				Cell c(new FredkinCell(i,j,0,false,0));
				game.addCell(c);
			}

		}
	}
	game.update();				//update after adding cells
	game.printGrid();
        for(int i = 0; i < 10; ++i){
		game.processTurns();
		game.update();
		game.printGrid();
        }
        for(int i = 10; i < 20; ++i){
		game.processTurns();
		game.update();
        }
	game.printGrid();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------
    // Cell 13x13
    // ----------

try {
        cout << "*** Life<Cell> 13x13***" << endl;
        cout << endl;
        vector<Cell> v;
        Life<Cell> game(13,13, v);
	for(int i = 0; i < 13; ++i){
		for(int j = 0; j < 13; ++j){
			if(i == 0){
				Cell c1(new ConwayCell(0,j,0,true));
        			game.addCell(c1);
			}
			else if(i == 12){
				Cell c2(new ConwayCell(12,j,0,true));
        			game.addCell(c2);
			}
			else if(j == 0){
				Cell c3(new ConwayCell(i,0,0,true));
        			game.addCell(c3);
			}
			else if(j == 12){
				Cell c4(new ConwayCell(i,12,0,true));
      				game.addCell(c4);
			}
			else if(i == 1){
				Cell c5(new ConwayCell(1,j,0,false));
        			game.addCell(c5);
			}
			else if(i == 11){
				Cell c6(new ConwayCell(11,j,0,false));
        			game.addCell(c6);
			}
			else if(j == 1){
				Cell c7(new ConwayCell(i,1,0,false));
        			game.addCell(c7);
			}
			else if(j == 11){
				Cell c8(new ConwayCell(i,11,0,false));
      				game.addCell(c8);
			}
			else{
				Cell c(new ConwayCell(i,j,0,true));
				game.addCell(c);
			}

		}
	}
	game.update();				//update after adding cells
	game.printGrid();
        for(int i = 0; i < 10; ++i){
		game.processTurns();
		game.update();
		game.printGrid();
        }
        for(int i = 10; i < 20; ++i){
		game.processTurns();
		game.update();
        }
	game.printGrid();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 6x6
    // ----------

try {
        cout << "*** Life<Cell> 6x6***" << endl;
        cout << endl;
        vector<Cell> v;
        Life<Cell> game(6,6, v);
	for(int i = 0; i < 6; ++i){
		for(int j = 0; j < 6; ++j){
			if(i == 0){
				Cell c1(new FredkinCell(0,j,0,true,0));
        			game.addCell(c1);
			}
			else if(i == 5){
				Cell c2(new FredkinCell(5,j,0,true,0));
        			game.addCell(c2);
			}
			else if(j == 0){
				Cell c3(new FredkinCell(i,0,0,true,0));
        			game.addCell(c3);
			}
			else if(j == 5){
				Cell c4(new FredkinCell(i,5,0,true,0));
      				game.addCell(c4);
			}
			else if(i == 1){
				Cell c5(new FredkinCell(1,j,0,false,0));
        			game.addCell(c5);
			}
			else if(i == 4){
				Cell c6(new FredkinCell(4,j,0,false,0));
        			game.addCell(c6);
			}
			else if(j == 1){
				Cell c7(new FredkinCell(i,1,0,false,0));
        			game.addCell(c7);
			}
			else if(j == 4){
				Cell c8(new FredkinCell(i,4,0,false,0));
      				game.addCell(c8);
			}
			else{
				Cell c(new ConwayCell(i,j,0,true));
				game.addCell(c);
			}

		}
	}
	game.update();				//update after adding cells
	game.printGrid();
        for(int i = 0; i < 10; ++i){
		game.processTurns();
		game.update();
		game.printGrid();
        }
        for(int i = 10; i < 20; ++i){
		game.processTurns();
		game.update();
        }
	game.printGrid();
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    return 0;}
