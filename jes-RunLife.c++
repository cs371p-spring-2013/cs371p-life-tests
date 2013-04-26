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
#include <stdlib.h>
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
		Life("RunLifeConway.in");
        read RunLifeConway.in // assume all Conway cells
        Simulate 283 moves.
        Print the first 10 grids (i.e. 0, 1, 2...9).
        Print the 283rd grid.
        Simulate 40 moves.
        Print the 323rd grid.
        Simulate 2177 moves.
        Print the 2500th grid.
        */
        cout << "*** Life<ConwayCell> 109x69 ***" << endl <<endl;
		ifstream ifs;
		ifs.open("RunLifeConway.in");
		int row = 0; 
		int h; 
		int w;
		ifs >> h;
		ifs >> w;
		Life<ConwayCell> board(h, w);
		string line;
		while (ifs >> line){
			for (int col = 0; col < w; ++col) {
				if (line[col] == '*') {
				    ConwayCell con(true);
                    board.add(con, row, col); //cout << "rowcol " << row << ", " << col << endl;
				}
			}
			++row;
		}
        assert(board.population == 35);
		ifs.close();
        for (int i = 0; i < 283; ++i){ //Simulate 283 moves.
            if (i < 10) board.print(); //Print the first 10 grids (i.e. 0, 1, 2...9).
            board.simulate(); 
        } board.print(); //Print the 283rd grid
        for (int i = 283; i < 323; ++i){ //Simulate 40 moves
            board.simulate(); 
        } board.print(); //Print the 323rd grid

        for (int i = 323; i < 2500; ++i){ //Simulate 2177 moves
            board.simulate(); 
        } board.print(); //Print the 323rd grid
        cout << endl << endl;
    } 
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
	
	
    // ---------------
    // Conway Cell 10X8
    // ---------------

    try {
        /*
		* simulate 5 moves
		* print every move
		* has one dead cell
		*/
        cout << "*** Life<ConwayCell> 10x8 ***" << endl << endl;
        int r = 10; int c = 8;
        Life<ConwayCell> board(r,c);
        for (int i = 0; i < 4; ++i) {
            ConwayCell con(true);
            board.add(con, i + 1, 4);
            if (i < 3)  board.add(con, i + 6, 4);
        }
        
		 board.print();
		 for(unsigned int i = 0; i < 5; ++i){
			 board.simulate();
			 board.print();
         } cout << endl;
		
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
	
	
    // ---------------
    // Conway Cell 10X8
    // ---------------

    try {
        /*
		* simulate 15 moves
		* print every move
		* has one dead cell
		*/
        cout << "*** Life<ConwayCell> 10x8 ***" << endl << endl;
        int r = 10; int c = 8;
        Life<ConwayCell> board(r,c);
        for (int i = 0; i < 4; ++i) {
            ConwayCell con(true);
            board.add(con, i + 1, 4);
            if (i < 3)  board.add(con, i + 6, 4);
        }
        
		 board.print();
		 for(unsigned int i = 0; i < 15; ++i){
			 board.simulate();
			 board.print();
         } cout << endl;
		
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	
	
    // ---------------
    // Conway Cell 3X3
    // ---------------

    try {
        /*
		* simulate 2 moves
		* print every move
		* has one dead cell
		*/
        cout << "*** Life<ConwayCell> 3x3 ***" << endl << endl;
        int r = 3; int c = 3;
        Life<ConwayCell> board(r,c);
        for (int i = 0; i < 3; ++i) {
            ConwayCell con(true);
            board.add(con, i, 2);
        }
        
		 board.print();
		 for(unsigned int i = 0; i < 2; ++i){
			 board.simulate();
			 board.print();
         } cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	
    // ---------------
    // Conway Cell 30X30
    // ---------------

    try {
        /*
		* simulate 10 moves
		* print every move
		* has one dead cell
		*/
        int r = 30; int c = 30; int moves = 10;
        cout << "*** Life<ConwayCell> "<< r << "x" << c << " ***" << endl << endl;
        Life<ConwayCell> board(r,c);
        for (int i = 0; i < 20; ++i) {
            ConwayCell con(true);
            board.add(con, i+2, 15);
        }
        
		 board.print();
		 for(int i = 0; i < moves; ++i){
			 board.simulate();
			 board.print();
         } cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

	
    // ---------------
    // Conway Cell 50X50
    // ---------------

    try {
        /*
		* simulate 10 moves
		* print every move
		* has one dead cell
		*/
        int r = 50; int c = 50; int moves = 10;
        cout << "*** Life<ConwayCell> "<< r << "x" << c << " ***" << endl << endl;
        Life<ConwayCell> board(r,c);
        for (int i = 0; i < 20; ++i) {
            ConwayCell con(true);
            board.add(con, i+11, 28);
            board.add(con, i+11, 29);
            board.add(con, i+11, 30);
            board.add(con, i, 0);
            board.add(con, i, 49);
        }
        
		 board.print();
		 for(int i = 0; i < moves; ++i){
			 board.simulate();
			 board.print();
         } cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}



    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    try {
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        cout << "*** Life<FredkinCell> 20x20 ***" << endl << endl;
		ifstream ifs;
		ifs.open("RunLifeFredkin.in");
		int row = 0; 
		int h; 
		int w;
		ifs >> h;
		ifs >> w;
		Life<FredkinCell> board(h, w);
		string line;
		while (ifs >> line){
			for (int col = 0; col < w; ++col) {
				if (line[col] == '+' || isdigit(line[col])) {
                    FredkinCell con(true);
                    board.add(con, row, col); //cout << "rowcol " << row << ", " << col << endl;
				}
			}
			++row;
		}
        assert(board.population == 4);
		ifs.close();
        board.print(); 
        for (int i = 0; i < 5; ++i){ 
            board.simulate(); 
            board.print(); 
        } 
        cout << endl << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ---------------
    // Fredkin Cell 50X50
    // ---------------

    try {
        /*
		* simulate 10 moves
		* print every move
		* has one dead cell
		*/
        int r = 50; int c = 50; int moves = 10;
        cout << "*** Life<FredkinCell> "<< r << "x" << c << " ***" << endl << endl;
        Life<FredkinCell> board(r,c);
        for (int i = 0; i < 20; ++i) {
            FredkinCell con(true);
            board.add(con, i+11, 28);
            board.add(con, i+11, 29);
            board.add(con, i+11, 30);
            board.add(con, i, 0);
            board.add(con, i, 49);
        }
        
		 board.print();
		 for(int i = 0; i < moves; ++i){
			 board.simulate();
			 board.print();
         } cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ---------------
    // Fredkin Cell 3X3
    // ---------------

    try {
        /*
		* simulate 5 moves
		* print every move
		* has one dead cell
		*/
        int r = 3; int c = 3; int moves = 5;
        cout << "*** Life<FredkinCell> "<< r << "x" << c << " ***" << endl << endl;
        Life<FredkinCell> board(r,c);
        for (int i = 0; i < 2; ++i) {
            FredkinCell con(true);
            board.add(con, i, 0);
        }
        
		 board.print();
		 for(int i = 0; i < moves; ++i){
			 board.simulate();
			 board.print();
         } cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ---------------
    // Fredkin Cell 10X10
    // ---------------

    try {
        /*
		* simulate 5 moves
		* print every move
		* has one dead cell
		*/
        int r = 10; int c = 10; int moves = 10;
        cout << "*** Life<FredkinCell> "<< r << "x" << c << " ***" << endl << endl;
        Life<FredkinCell> board(r,c);
        for (int i = 0; i < 10; ++i) {
            FredkinCell con(true);
            board.add(con, i, 0);
            board.add(con, i, c - 1);
            board.add(con, 0, i);
            board.add(con, r - 1, i);
        }
        
		 board.print();
		 for(int i = 0; i < moves; ++i){
			 board.simulate();
			 board.print();
         } cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ---------------
    // Fredkin Cell 30X30
    // ---------------

    try {
        /*
		* simulate 30 moves
		* print every move
		* has one dead cell
		*/
        int r = 30; int c = 30; int moves = 30;
        cout << "*** Life<FredkinCell> "<< r << "x" << c << " ***" << endl << endl;
        Life<FredkinCell> board(r,c);
        for (int i = 0; i < r; ++i) {
            FredkinCell con(true);
            board.add(con, i, 0);
            board.add(con, i, c - 1);
            board.add(con, 0, i);
            board.add(con, r - 1, i);
        }
        
		 board.print();
		 for(int i = 0; i < moves; ++i){
			 board.simulate();
			 board.print();
         } cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ---------------
    // Fredkin Cell Castle 50X50
    // ---------------

    try {
        /*
		* simulate 10 moves
		* print every move
		* has one dead cell
		*/
        int r = 50; int c = r; int moves = 10;
        cout << "*** Life<FredkinCell> Castle "<< r << "x" << c << " ***" << endl << endl;
        Life<FredkinCell> board(r,c);
        for (int i = 0; i < 30; ++i) {
            FredkinCell con(true);
            board.add(con, r - i - 1, r/2);
            if (i < 15){
                board.add(con, r - i - 1, 12);
                board.add(con, r - i - 1, 38);
            }
        }
        
		 board.print();
		 for(int i = 0; i < moves; ++i){
			 board.simulate();
			 board.print();
         } cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}



    // ----------
    // Cell 20x20
    // ----------

    try {
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
         cout << "*** Life<Cell> 20x20 ***" << endl << endl;
		 ifstream ifs;
		 ifs.open("RunLifeCell.in");
		 int row = 0; 
		 int h; 
		 int w;
		 ifs >> h;
		 ifs >> w;
		// cout << "Board not initialized" << endl;
		 Life<Cell> board(h, w);
		//// cout << "Board initialized" << endl;
		 string line;
		 while (ifs >> line){
		     for (int col = 0; col < w; ++col) {
		        if (line[col] == '+' || isdigit(line[col])) {
                    //FredkinCell con(true);
                    //// cout << "rowcol " << row << ", " << col << endl;
                    board.add(new FredkinCell(true), row, col); 
				}
			}
			++row;
		 }
        assert(board.population == 6);
		ifs.close();
        board.print(); 
        for (int i = 0; i < 5; ++i){ 
            board.simulate(); 
            board.print(); 
        } 
        cout << endl << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
    // --------
    // Cell 2X1
    // --------

    try {
        /*
		* simulate 5 moves
		* print every move
		* has one dead cell
		*/
        int r = 1; int c = 2; int moves = 5;
        cout << "*** Life<Cell> "<< r << "x" << c << " ***" << endl << endl;
        Life<Cell> board(r,c);
        
        board.add(new FredkinCell(true), 0, 0);
        
		board.print();
		for(int i = 0; i < moves; ++i){
		    board.simulate();
		    board.print();
        } cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        
    // --------
    // Cell 5X5
    // --------

    try {
        /*
		* simulate 5 moves
		* print every move
		* has one dead cell
		*/
        int r = 5; int c = r; int moves = 5;
        cout << "*** Life<Cell> "<< r << "x" << c << " ***" << endl << endl;
        Life<Cell> board(r,c);
        for (int i = 0; i < 3; ++i) {
            board.add(new FredkinCell(true), i, 2);
        }
        
		 board.print();
		 for(int i = 0; i < moves; ++i){
			 board.simulate();
			 board.print();
         } cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // --------
    // Cell 5X5
    // --------

    try {
        /*
		* simulate 8 moves
		* print every move
		* has one dead cell
		*/
        int r = 5; int c = r; int moves = 8;
        cout << "*** Life<Cell> 5x5 part 2 "<< r << "x" << c << " ***" << endl << endl;
        Life<Cell> board(r,c);
        
        board.add(new FredkinCell(true), 0, 0);
        board.add(new FredkinCell(true), 0, 4);
        board.add(new FredkinCell(true), 4, 0);
        board.add(new FredkinCell(true), 4, 4);
        board.add(new FredkinCell(true), 2, 2);
        
		 board.print();
		 for(int i = 0; i < moves; ++i){
			 board.simulate();
			 board.print();
         } cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ---------------
    // Cell Castle 50X50
    // ---------------

    try {
        /*
		* simulate 10 moves
		* print every move
		* has one dead cell
		*/
        int r = 50; int c = r; int moves = 10;
        cout << "*** Life<Cell> Castle "<< r << "x" << c << " ***" << endl << endl;
        Life<Cell> board(r,c);
        for (int i = 0; i < 30; ++i) {
            board.add(new FredkinCell(true), r - i - 1, r/2);
            if (i < 15){
                board.add(new FredkinCell(true), r - i - 1, 12);
                board.add(new FredkinCell(true), r - i - 1, 38);
            }
        }
        
		 board.print();
		 for(int i = 0; i < moves; ++i){
			 board.simulate();
			 board.print();
         } cout << endl;
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}

