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
#include <fstream>

#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

// ---------
// loadBoard
// ---------

template<class T>
std::vector<std::vector< T > > loadBoard(const int r, const int c, std::istream& in) {
    std::vector<std::vector< T > > board;
    for(int i = 0; i < r; ++i){
        std::vector<T> row;
        for(int j = 0; j < c; ++j)
            row.push_back(in.get());
        in.get(); // get rid of newline
        board.push_back(row);
    }       
    return board;
}

// -------------
// loadCellBoard
// -------------

std::vector<std::vector< Cell > > loadCellBoard(const int r, const int c, std::istream& in) {
    std::vector<std::vector< Cell > > board;
    char ch;
    for(int i = 0; i < r; ++i){
        std::vector<Cell> row;
        for(int j = 0; j < c; ++j){
            ch = in.get();
            if(ch == '.' || ch == '*')
                row.push_back(new ConwayCell(ch));
            else
                row.push_back(new FredkinCell(ch));
        }
        in.get(); // get rid of newline
        board.push_back(row);
    }  
    return board;
}



// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    
    // ---------------
    // Conway Cell 2X1
    // ---------------

    try {
        cout << "*** Life<ConwayCell> 2x1 ***" << endl;
        /*
         * simulate 5 moves
         * print every move
         * has one dead cell
         */
        std::istringstream in(".\n*\n");
        Life<ConwayCell> l(2, 1, loadBoard<ConwayCell>(2, 1, in));
        for(int i = 0; i < 3; ++i){
            l.printBoard(cout);
            l.runRound();
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Conway Cell 5X5
    // ----------------

    try {
        cout << "*** Life<ConwayCell> 5x5 ***" << endl;
        /*
         * simulate 5 moves
         * print every move
         * has one dead cell
         */
        std::istringstream in("*...*\n.....\n..*..\n.....\n*...*\n");
        Life<ConwayCell> l(5, 5, loadBoard<ConwayCell>(5, 5, in));
        for(int i = 0; i < 3; ++i){
            l.printBoard(cout);
            l.runRound();
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // -----------------
    // Conway Cell 10X8
    // -----------------

    try {
        cout << "*** Life<ConwayCell> 10x8 ***" << endl;
        /*
         * simulate 5 moves
         * print every move
         * has one dead cell
         */
        std::istringstream in("........\n....*...\n....*...\n....*...\n....*...\n"
                            "........\n....*...\n....*...\n....*...\n........\n");

        Life<ConwayCell> l(10, 8, loadBoard<ConwayCell>(10, 8, in));
        for(int i = 0; i < 9; ++i){
            l.printBoard(cout);
            l.runRound();
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ---------------
    // Conway Cell 6X6
    // ---------------

    try {
        cout << "*** Life<ConwayCell> 6x6 ***" << endl;
        /*
         * simulate 5 moves
         * print every move
         * has one dead cell
         */
        std::istringstream in("*.....\n.*....\n..*...\n...*..\n....*.\n.....*\n");
        Life<ConwayCell> l(6, 6, loadBoard<ConwayCell>(6, 6, in));
        for(int i = 0; i < 5; ++i){
            l.printBoard(cout);
            l.runRound();
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ---------------
    // Conway Cell 6X6
    // ---------------

    try {
        cout << "*** Life<ConwayCell> 6x6 ***" << endl;
        /*
         * simulate 5 moves
         * print every move
         * has one dead cell
         */
        std::istringstream in("******\n*....*\n*....*\n*....*\n*....*\n******\n");
        Life<ConwayCell> l(6, 6, loadBoard<ConwayCell>(6, 6, in));
        for(int i = 0; i < 5; ++i){
            l.printBoard(cout);
            l.runRound();
        }
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
        int r, c;
        std::ifstream in;
        in.open("RunLifeConway.in");
        in >> r;
        in >> c;
        in.get();
        Life<ConwayCell> l(r, c, loadBoard<ConwayCell>(r, c, in));
        for(int i = 0; i < 283; ++i){
            if(i < 10)
                l.printBoard(cout);
            l.runRound();
        }
        l.printBoard(cout);
        for(int i = 0; i < 40; ++i)
            l.runRound();
        l.printBoard(cout);
        for(int i = 0; i < 2177; ++i)
            l.runRound();
        l.printBoard(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------------
    // Fredkin Cell 2X1
    // ----------------

    try {
        cout << "*** Life<FredkinCell> 2x1 ***" << endl;
        /*
         * simulate 5 moves
         * print every move
         * has one dead cell
         */
        std::istringstream in("-\n0\n");
        Life<FredkinCell> l(2, 1, loadBoard<FredkinCell>(2, 1, in));
        for(int i = 0; i < 9; ++i){
            l.printBoard(cout);
            l.runRound();
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Fredkin Cell 5X5
    // ----------------

    try {
        cout << "*** Life<FredkinCell> 5x5 ***" << endl;
        /*
         * simulate 5 moves
         * print every move
         * has one dead cell
         */
        std::istringstream in("0---0\n-----\n--0--\n-----\n0---0\n");
        Life<FredkinCell> l(5, 5, loadBoard<FredkinCell>(5, 5, in));
        for(int i = 0; i < 9; ++i){
            l.printBoard(cout);
            l.runRound();
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // -----------------
    // Fredkin Cell 10X8
    // -----------------

    try {
        cout << "*** Life<FredkinCell> 10x8 ***" << endl;
        /*
         * simulate 5 moves
         * print every move
         * has one dead cell
         */
        std::istringstream in("--------\n----0---\n----0---\n----0---\n----0---\n"
                            "--------\n----0---\n----0---\n----0---\n--------\n");

        Life<FredkinCell> l(10, 8, loadBoard<FredkinCell>(10, 8, in));
        for(int i = 0; i < 9; ++i){
            l.printBoard(cout);
            l.runRound();
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ----------------
    // Fredkin Cell 6X6
    // ----------------

    try {
        cout << "*** Life<FredkinCell> 6x6 ***" << endl;
        /*
         * simulate 5 moves
         * print every move
         * has one dead cell
         */
        std::istringstream in("0-----\n-0----\n--0---\n---0--\n----0-\n-----0\n");
        Life<FredkinCell> l(6, 6, loadBoard<FredkinCell>(6, 6, in));
        for(int i = 0; i < 3; ++i){
            l.printBoard(cout);
            l.runRound();
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Fredkin Cell 6X6
    // ----------------

    try {
        cout << "*** Life<FredkinCell> 6x6 ***" << endl;
        /*
         * simulate 5 moves
         * print every move
         * has one dead cell
         */
        std::istringstream in("000000\n0----0\n0----0\n0----0\n0----0\n000000\n");
        Life<FredkinCell> l(6, 6, loadBoard<FredkinCell>(6, 6, in));
        for(int i = 0; i < 9; ++i){
            l.printBoard(cout);
            l.runRound();
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
        int r, c;
        std::ifstream in;
        in.open("RunLifeFredkin.in");
        in >> r;
        in >> c;
        in.get();
        Life<FredkinCell> l(r, c, loadBoard<FredkinCell>(r, c, in));
        for(int i = 0; i < 5; ++i){
            l.printBoard(cout);
            l.runRound();
        }
        l.printBoard(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------
    // Cell 2X1
    // --------

    try {
        cout << "*** Life<Cell> 2x1 ***" << endl;
        /*
         * simulate 5 moves
         * print every move
         * has one dead cell
         */
        std::istringstream in("-\n0\n");
        Life<Cell> l(2, 1, loadCellBoard(2, 1, in));
        for(int i = 0; i < 9; ++i){
            l.printBoard(cout);
            l.runRound();
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------
    // Cell 5X5
    // --------

    try {
        cout << "*** Life<Cell> 5x5 ***" << endl;
        /*
         * simulate 5 moves
         * print every move
         * has one dead cell
         */
        std::istringstream in("0---0\n-----\n--0--\n-----\n0---0\n");
        Life<Cell> l(5, 5, loadCellBoard(5, 5, in));
        for(int i = 0; i < 9; ++i){
            l.printBoard(cout);
            l.runRound();
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ---------
    // Cell 10X8
    // ---------

    try {
        cout << "*** Cell> 10x8 ***" << endl;
        /*
         * simulate 5 moves
         * print every move
         * has one dead cell
         */
        std::istringstream in("--------\n----0---\n----0---\n----0---\n----0---\n"
                            "--------\n----0---\n----0---\n----0---\n--------\n");

        Life<Cell> l(10, 8, loadCellBoard(10, 8, in));
        for(int i = 0; i < 9; ++i){
            l.printBoard(cout);
            l.runRound();
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // --------
    // Cell 6X6
    // --------

    try {
        cout << "*** Life<Cell> 6x6 ***" << endl;
        /*
         * simulate 5 moves
         * print every move
         * has one dead cell
         */
        std::istringstream in("0-----\n-0----\n--0---\n---0--\n----0-\n-----0\n");
        Life<Cell> l(6, 6, loadCellBoard(6, 6, in));
        for(int i = 0; i < 3; ++i){
            l.printBoard(cout);
            l.runRound();
        }
    }
     catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------
    // Cell 6X6
    // --------

    try {
        cout << "*** Life<Cell> 6x6 ***" << endl;
        /*
         * simulate 5 moves
         * print every move
         * has one dead cell
         */
        std::istringstream in("000000\n0----0\n0----0\n0----0\n0----0\n000000\n");
        Life<Cell> l(6, 6, loadCellBoard(6, 6, in));
        for(int i = 0; i < 9; ++i){
            l.printBoard(cout);
            l.runRound();
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
        int r, c;
        std::ifstream in;
        in.open("RunLifeCell.in");
        in >> r;
        in >> c;
        in.get();
        Life<Cell> l(r, c, loadCellBoard(r, c, in));
        for(int i = 0; i < 5; ++i){
            l.printBoard(cout);
            l.runRound();
        }
        l.printBoard(cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
