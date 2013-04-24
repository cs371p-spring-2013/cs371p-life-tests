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
#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include <sstream>      // std::istringstream


#define dead false
#define alive true
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
        ifstream file("RunLifeConway.in");

        int rows, cols;
        file >> rows;
        file >> cols;
        file.get();

        Life<ConwayCell> board(rows, cols);
        int rowCount = 0;
        int colCount = 0;
        while(file.good()){
        char c = file.get();

        if(c == '.'){
        ConwayCell cell(dead);
        board.addCell(cell ,rowCount, colCount, c);
        }
        else if(c == '*'){
        ConwayCell cell(alive);
        board.addCell(cell, rowCount, colCount, c);
        board.increasePopulation();
        }

        ++colCount;
        if(c == '\n'){
        colCount = 0;
        ++rowCount;
        }

        }
        file.close();

        board.print();
        board.simulate(10,1);
        board.simulate(273);
        board.print();
        board.simulate(40);
        board.print();
        board.simulate(2177);
        board.print();
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
    // Conway Cell 5x5
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 5x5 ***" << endl;

        string s = "*...*\n*...*\n*...*\n*...*\n*...*\n";
        istringstream file (s);
		

        Life<ConwayCell> board(5, 5);
        int rowCount = 0;
        int colCount = 0;
        char c;
        while(file>>c){


            if(c == '.'){
                ConwayCell cell(dead);
                board.addCell(cell ,rowCount, colCount, c);
            }
            else if(c == '*'){
                ConwayCell cell(alive);
                board.addCell(cell, rowCount, colCount, c);
                board.increasePopulation();
            }

            ++colCount;
            if(colCount == 5){
                colCount = 0;
                ++rowCount;
            }

        }


        board.print();
        board.simulate(3,1);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Conway Cell 10x10
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 10x10 ***" << endl;

        string s = "**........\n*.........\n..........\n..........\n..........\n..........\n..........\n..........\n.........*\n........**\n";
        istringstream file (s);
		

        Life<ConwayCell> board(10, 10);
        int rowCount = 0;
        int colCount = 0;
        char c;
        while(file>>c){


            if(c == '.'){
                ConwayCell cell(dead);
                board.addCell(cell ,rowCount, colCount, c);
            }
            else if(c == '*'){
                ConwayCell cell(alive);
                board.addCell(cell, rowCount, colCount, c);
                board.increasePopulation();
            }

            ++colCount;
            if(colCount == 10){
                colCount = 0;
                ++rowCount;
            }

        }


        board.print();
        board.simulate(3,1);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Conway Cell 2x2
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 2x2 ***" << endl;

        string s = "**\n..\n";
        istringstream file (s);
		

        Life<ConwayCell> board(2, 2);
        int rowCount = 0;
        int colCount = 0;
        char c;
        while(file>>c){


            if(c == '.'){
                ConwayCell cell(dead);
                board.addCell(cell ,rowCount, colCount, c);
            }
            else if(c == '*'){
                ConwayCell cell(alive);
                board.addCell(cell, rowCount, colCount, c);
                board.increasePopulation();
            }

            ++colCount;
            if(colCount == 2){
                colCount = 0;
                ++rowCount;
            }

        }


        board.print();
        board.simulate(3,1);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}



    // ------------------
    // Conway Cell 2x2
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 2x2 ***" << endl;

        string s = "*.\n.*\n";
        istringstream file (s);
		

        Life<ConwayCell> board(2, 2);
        int rowCount = 0;
        int colCount = 0;
        char c;
        while(file>>c){


            if(c == '.'){
                ConwayCell cell(dead);
                board.addCell(cell ,rowCount, colCount, c);
            }
            else if(c == '*'){
                ConwayCell cell(alive);
                board.addCell(cell, rowCount, colCount, c);
                board.increasePopulation();
            }

            ++colCount;
            if(colCount == 2){
                colCount = 0;
                ++rowCount;
            }

        }


        board.print();
        board.simulate(3,1);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // Conway Cell 2x1
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 2x1 ***" << endl;

        string s = "*\n.\n";
        istringstream file (s);
		

        Life<ConwayCell> board(2, 1);
        int rowCount = 0;
        int colCount = 0;
        char c;
        while(file>>c){


            if(c == '.'){
                ConwayCell cell(dead);
                board.addCell(cell ,rowCount, colCount, c);
            }
            else if(c == '*'){
                ConwayCell cell(alive);
                board.addCell(cell, rowCount, colCount, c);
                board.increasePopulation();
            }

            ++colCount;
            if(colCount == 1){
                colCount = 0;
                ++rowCount;
            }

        }


        board.print();
        board.simulate(2,1);

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
        ifstream file("RunLifeFredkin.in");

        int rows, cols;
        file >> rows;
        file >> cols;
        file.get();

        Life<FredkinCell> board(rows, cols);
        int rowCount = 0;
        int colCount = 0;
        while(file.good()){
        char c = file.get();

        if(c == '-'){
        FredkinCell cell(dead);
        board.addCell(cell ,rowCount, colCount, c);
        }
        else if(c == '0'){
        FredkinCell cell(alive);
        board.addCell(cell, rowCount, colCount, c);
        board.increasePopulation();
        }

        ++colCount;
        if(c == '\n'){
        colCount = 0;
        ++rowCount;
        }

        }
        file.close();

        board.print();
        board.simulate(5, 1);
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


    // ------------------
    // Fredkin Cell 5x5
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 5x5 ***" << endl;
        string s = "0...0\n0...0\n0...0\n0...0\n0...0\n";
        istringstream file (s);


        Life<FredkinCell> board(5, 5);
        int rowCount = 0;
        int colCount = 0;
        char c;
        while(file>>c){


            if(c == '-'){
                FredkinCell cell(dead);
                board.addCell(cell ,rowCount, colCount, c);
            }
            else if(c == '0'){
                FredkinCell cell(alive);
                board.addCell(cell, rowCount, colCount, c);
                board.increasePopulation();
            }

            ++colCount;
            if(colCount == 5){
                colCount = 0;
                ++rowCount;
            }

        }


        board.print();
        board.simulate(5, 1);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // Fredkin Cell 10x10
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 10x10 ***" << endl;
        string s = "00........\n0.........\n..........\n..........\n..........\n..........\n..........\n..........\n.........0\n........00\n";
        istringstream file (s);


        Life<FredkinCell> board(10, 10);
        int rowCount = 0;
        int colCount = 0;
        char c;
        while(file>>c){


            if(c == '-'){
                FredkinCell cell(dead);
                board.addCell(cell ,rowCount, colCount, c);
            }
            else if(c == '0'){
                FredkinCell cell(alive);
                board.addCell(cell, rowCount, colCount, c);
                board.increasePopulation();
            }

            ++colCount;
            if(colCount == 10){
                colCount = 0;
                ++rowCount;
            }

        }


        board.print();
        board.simulate(5, 1);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}



    // ------------------
    // Fredkin Cell 2x2
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 2x2 ***" << endl;
        string s = "00\n..\n";
        istringstream file (s);

        Life<FredkinCell> board(2, 2);
        int rowCount = 0;
        int colCount = 0;
        char c;
        while(file>>c){


            if(c == '-'){
                FredkinCell cell(dead);
                board.addCell(cell ,rowCount, colCount, c);
            }
            else if(c == '0'){
                FredkinCell cell(alive);
                board.addCell(cell, rowCount, colCount, c);
                board.increasePopulation();
            }

            ++colCount;
            if(colCount == 2){
                colCount = 0;
                ++rowCount;
            }

        }


        board.print();
        board.simulate(3, 1);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}



    // ------------------
    // Fredkin Cell 2x1
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 2x1 ***" << endl;

        string s = "0\n.\n";
        istringstream file (s);
		

        Life<FredkinCell> board(2, 1);
        int rowCount = 0;
        int colCount = 0;
        char c;
        while(file>>c){


            if(c == '-'){
                FredkinCell cell(dead);
                board.addCell(cell ,rowCount, colCount, c);
            }
            else if(c == '0'){
                FredkinCell cell(alive);
                board.addCell(cell, rowCount, colCount, c);
                board.increasePopulation();
            }

            ++colCount;
            if(colCount == 1){
                colCount = 0;
                ++rowCount;
            }

        }


        board.print();
        board.simulate(3, 1);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // Fredkin Cell 2x2
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 2x2 ***" << endl;

        string s = "0.\n.0\n";
        istringstream file (s);
		

        Life<FredkinCell> board(2, 2);
        int rowCount = 0;
        int colCount = 0;
        char c;
        while(file>>c){


            if(c == '-'){
                FredkinCell cell(dead);
                board.addCell(cell ,rowCount, colCount, c);
            }
            else if(c == '0'){
                FredkinCell cell(alive);
                board.addCell(cell, rowCount, colCount, c);
                board.increasePopulation();
            }

            ++colCount;
            if(colCount == 2){
                colCount = 0;
                ++rowCount;
            }

        }


        board.print();
        board.simulate(3, 1);

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
        ifstream file("RunLifeCell.in");

        int rows, cols;
        file >> rows;
        file >> cols;
        file.get();

        Life<Cell> board(rows, cols);
        int rowCount = 0;
        int colCount = 0;
        while(file.good()){
        char c = file.get();

        if(c == '-'){
        Cell cell = new FredkinCell(dead);
        board.addCell(cell ,rowCount, colCount, c);
        }
        else if(c == '0'){
        Cell cell = new FredkinCell(alive);
        board.addCell(cell, rowCount, colCount, c);
        board.increasePopulation();
        }

        ++colCount;
        if(c == '\n'){
        colCount = 0;
        ++rowCount;
        }

        }
        file.close();

        board.print();
        board.simulate(5, 1);
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
    // Cell 10x10
    // ----------

    try {
        cout << "*** Life<Cell> 10x10 ***" << endl;
        string s = "----------\n----------\n----------\n----00----\n---0--0---\n----00----\n----------\n----------\n----------\n----------\n";
        istringstream file (s);
		

		
		Life<Cell> board(10, 10);
		int rowCount = 0;
		int colCount = 0;
        char c;
		while(file >> c){
			if(c == '-'){
				Cell cell = new FredkinCell(dead);
				board.addCell(cell ,rowCount, colCount, c);
			}
			else if(c == '0'){
				Cell cell = new FredkinCell(alive);
				board.addCell(cell, rowCount, colCount, c);
				board.increasePopulation();
			}
			
			++colCount;
			if(colCount == 10){
				colCount = 0;
				++rowCount;
			}
			
		}

		board.print();
		board.simulate(5, 1);
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
    // Cell 30x50
    // ----------

    try {
        cout << "*** Life<Cell> 30x50 ***" << endl;
        string s = "0-------------------------------------------------\n--------------------------------------------------\n--------------------------------------------------\n--------------------------------------------------\n--------------------------------------------------\n--------------------------------------------------\n--------------------------------------------------\n--------------------------------------------------\n--------------------------------------------------\n--------------------------------------------------\n--------------------------------------------------\n------------------0000000000----------------------\n------------------0---00---0----------------------\n--------------------000000------------------------\n------------------0---00---0----------------------\n------------------0--------0----------------------\n------------------0--------0----------------------\n------------------0--------0----------------------\n--------------------------------------------------\n--------------------------------------------------\n--------------------------------------------------\n--------------------------------------------------\n--------------------------------------------------\n--------------------------------------------------\n--------------------------------------------------\n--------------------------------------------------\n--------------------------------------------------\n--------------------------------------------------\n--------------------------------------------------\n-------------------------------------------------0\n";
        istringstream file (s);
		

		
		Life<Cell> board(30, 50);
		int rowCount = 0;
		int colCount = 0;
        char c;
		while(file >> c){
			if(c == '-'){
				Cell cell = new FredkinCell(dead);
				board.addCell(cell ,rowCount, colCount, c);
			}
			else if(c == '0'){
				Cell cell = new FredkinCell(alive);
				board.addCell(cell, rowCount, colCount, c);
				board.increasePopulation();
			}
			
			++colCount;
			if(colCount == 50){
				colCount = 0;
				++rowCount;
			}
			
		}

		board.print();
		board.simulate(5, 1);
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
    // Cell 3x3
    // ----------

    try {
        cout << "*** Life<Cell> 3x3 ***" << endl;
        string s = "0--\n--0\n0--\n";
        istringstream file (s);
		

		
		Life<Cell> board(3, 3);
		int rowCount = 0;
		int colCount = 0;
        char c;
		while(file >> c){
			if(c == '-'){
				Cell cell = new FredkinCell(dead);
				board.addCell(cell ,rowCount, colCount, c);
			}
			else if(c == '0'){
				Cell cell = new FredkinCell(alive);
				board.addCell(cell, rowCount, colCount, c);
				board.increasePopulation();
			}
			
			++colCount;
			if(colCount == 3){
				colCount = 0;
				++rowCount;
			}
			
		}

		board.print();
		board.simulate(5, 1);
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
    // Cell 5x5
    // ----------

    try {
        cout << "*** Life<Cell> 5x5 ***" << endl;
        string s = "0---0\n0---0\n0---0\n0---0\n0---0\n";
        istringstream file (s);
		

		
		Life<Cell> board(5, 5);
		int rowCount = 0;
		int colCount = 0;
        char c;
		while(file >> c){
			if(c == '-'){
				Cell cell = new FredkinCell(dead);
				board.addCell(cell ,rowCount, colCount, c);
			}
			else if(c == '0'){
				Cell cell = new FredkinCell(alive);
				board.addCell(cell, rowCount, colCount, c);
				board.increasePopulation();
			}
			
			++colCount;
			if(colCount == 5){
				colCount = 0;
				++rowCount;
			}
			
		}

		board.print();
		board.simulate(5, 1);
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
    // Cell 2x2
    // ----------

    try {
        cout << "*** Life<Cell> 2x2 ***" << endl;
        string s = "0-\n0-\n";
        istringstream file (s);
		

		
		Life<Cell> board(2, 2);
		int rowCount = 0;
		int colCount = 0;
        char c;
		while(file >> c){
			if(c == '-'){
				Cell cell = new FredkinCell(dead);
				board.addCell(cell ,rowCount, colCount, c);
			}
			else if(c == '0'){
				Cell cell = new FredkinCell(alive);
				board.addCell(cell, rowCount, colCount, c);
				board.increasePopulation();
			}
			
			++colCount;
			if(colCount == 2){
				colCount = 0;
				++rowCount;
			}
			
		}

		board.print();
		board.simulate(5, 1);
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


    return 0;}


