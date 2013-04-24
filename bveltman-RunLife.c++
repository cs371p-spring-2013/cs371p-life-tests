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

#define private public
#define protected public
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Handle.h"
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
        cout << endl;
        ifstream inFile;
        char inputFileName[] = "RunLifeConway.in";
        inFile.open(inputFileName, ios::in);
        int row;
        inFile >> row;
        int col;
        inFile >> col;
        Life<ConwayCell> a(row, col);
        for(int i = 0; i < a.row; ++i){
            char x;
            for(int j = 0; j < a.col; ++j){
                inFile >> x;
                if(x == '*'){
                    a.current[i][j].changeState();
                    a.next[i][j].changeState();
                }
            }
        }
        inFile.close();
        a.playLifeGame(11, 1);
        for (int i = 0; i < 273; ++i){
            a.playLifeRound();
        }
        cout << a.printLife() << "\n";          //283
        for(int i = 0; i < 40; ++i){
            a.playLifeRound();
        } 
        cout << a.printLife() << "\n";          //323
        for(int i = 0; i < 2177; ++i){
            a.playLifeRound();
        }
        cout << a.printLife() << "\n";          //2500
        
        /*
//        read RunLifeConway.in // assume all Conway cells
//        Simulate 283 moves.
//        Print the first 10 grids (i.e. 0, 1, 2...9).
//        Print the 283rd grid.
//        Simulate 40 moves.
//        Print the 323rd grid.
//        Simulate 2177 moves.
//        Print the 2500th grid.
//        */
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
        cout << endl;
        ifstream inFile;
        char inputFileName[] = "RunLifeFredkin.in";
        inFile.open(inputFileName, ios::in);
        int row;
        inFile >> row;
        int col;
        inFile >> col;
        Life<FredkinCell> a(row, col);
        for(int i = 0; i < a.row; ++i){
            char x;
            for(int j = 0; j < a.col; ++j){
                inFile >> x;
                if(x == '0'){
                    a.current[i][j].changeState();
                    a.next[i][j].changeState();
                }
            }
        }
        inFile.close();
        a.playLifeGame(6, 1);

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
        cout << endl;
        ifstream inFile;
        char inputFileName[] = "RunLifeCell.in";
        inFile.open(inputFileName, ios::in);
        int row;
        inFile >> row;
        int col;
        inFile >> col;
        Life<Cell> a(row, col);
        for(int i = 0; i < a.row; ++i){
            char x;
            for(int j = 0; j < a.col; ++j){
                inFile >> x;
                if(x == '0'){
                    a.current[i][j].changeState();
                    a.next[i][j].changeState();
                }
            }
        }
        inFile.close();
        a.playLifeGame(6, 1);
        
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
    
    //Additional ConwayCell Tests
    try {
        cout << "*** Life<ConwayCell> 8x8 ***" << endl;
        cout << endl;
        Life<ConwayCell> a(8,8);
        for(int i = 0; i < 7; ++i){
                ConwayCell* c = new ConwayCell();
                a.placeCell(*c, i, 3);
                ConwayCell* d = new ConwayCell();
                a.placeCell(*d, i+1, 4);
        }
        
        a.playLifeGame(6, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> 10x6 ***" << endl;
        cout << endl;
        Life<ConwayCell> a(10,6);
        for(int i = 0; i < 3; ++i){
                ConwayCell* c = new ConwayCell();
                a.placeCell(*c, i, 3);
                ConwayCell* d = new ConwayCell();
                a.placeCell(*d, i+1, 4);
        }
        
        a.playLifeGame(6, 1);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> 4x4 ***" << endl;
        cout << endl;
        Life<ConwayCell> a(4,4);
        for(int i = 0; i < 4; ++i){
            for (int j = 0 ; j < 4; ++j){
                if (j % 2 == 0){
                        ConwayCell* c = new ConwayCell();
                        a.placeCell(*c, i, j);
                }
            }
        }
        
        a.playLifeGame(10, 1);
        
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> 8x8 ***" << endl;
        cout << endl;
        Life<ConwayCell> a(8,8);
        for(int i = 0; i < 8; ++i){
            for (int j = 0 ; j < 8; ++j){
                if (j % 2 == 0){
                        ConwayCell* c = new ConwayCell();
                        a.placeCell(*c, i, j);
                }
            }
            if (i % 2 == 0){
                        ConwayCell* c = new ConwayCell();
                        a.placeCell(*c, i, 0);
                }
        }
        
        a.playLifeGame(6, 1);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    try {
        cout << "*** Life<ConwayCell> 20x20 ***" << endl;
        cout << endl;
        Life<ConwayCell> a(20,20);
        for(int i = 0; i < 20; ++i){
            for (int j = 0 ; j < 10; ++j){
                if (j % 2 == 0){
                        ConwayCell* c = new ConwayCell();
                        a.placeCell(*c, i, j);
                }
            }
            if (i % 2 == 0){
                        ConwayCell* c = new ConwayCell();
                        a.placeCell(*c, i, 0);
                }
        }
        
        a.playLifeGame(9, 1);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    try {
        cout << "*** Life<FredkinCell> 8x8 ***" << endl;
        cout << endl;
        Life<FredkinCell> a(8,8);
        for(int i = 0; i < 7; ++i){
                FredkinCell* c = new FredkinCell();
                a.placeCell(*c, i, 3);
                FredkinCell* d = new FredkinCell();
                a.placeCell(*d, i+1, 4);
        }
        
        a.playLifeGame(6, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> 10x6 ***" << endl;
        cout << endl;
        Life<FredkinCell> a(10,6);
        for(int i = 0; i < 3; ++i){
                FredkinCell* c = new FredkinCell();
                a.placeCell(*c, i, 3);
                FredkinCell* d = new FredkinCell();
                a.placeCell(*d, i+1, 4);
        }
        
        a.playLifeGame(6, 1);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> 4x4 ***" << endl;
        cout << endl;
        Life<FredkinCell> a(4,4);
        for(int i = 0; i < 4; ++i){
            for (int j = 0 ; j < 4; ++j){
                if (j % 2 == 0){
                        FredkinCell* c = new FredkinCell();
                        a.placeCell(*c, i, j);
                }
            }
        }
        
        a.playLifeGame(10, 1);
        
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> 8x8 ***" << endl;
        cout << endl;
        Life<FredkinCell> a(8,8);
        for(int i = 0; i < 8; ++i){
            for (int j = 0 ; j < 8; ++j){
                if (j % 2 == 0){
                        FredkinCell* c = new FredkinCell();
                        a.placeCell(*c, i, j);
                }
            }
            if (i % 2 == 0){
                        FredkinCell* c = new FredkinCell();
                        a.placeCell(*c, i, 0);
                }
        }
        
        a.playLifeGame(6, 1);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    try {
        cout << "*** Life<ConwayCell> 20x20 ***" << endl;
        cout << endl;
        Life<FredkinCell> a(20,20);
        for(int i = 0; i < 20; ++i){
            for (int j = 0 ; j < 10; ++j){
                if (j % 2 == 0){
                        FredkinCell* c = new FredkinCell();
                        a.placeCell(*c, i, j);
                }
            }
            if (i % 2 == 0){
                        FredkinCell* c = new FredkinCell();
                        a.placeCell(*c, i, 0);
                }
        }
        
        a.playLifeGame(9, 1);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    try {
        cout << "*** Life<Cell> 8x8 ***" << endl;
        cout << endl;
        Life<Cell> a(8,8);
        for(int i = 0; i < 7; ++i){
                Cell* c = new Cell();
                a.placeCell(*c, i, 3);
                Cell* d = new Cell();
                a.placeCell(*d, i+1, 4);
        }
        
        a.playLifeGame(6, 1);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<Cell> 10x6 ***" << endl;
        cout << endl;
        Life<Cell> a(10,6);
        for(int i = 0; i < 3; ++i){
                Cell* c = new Cell();
                a.placeCell(*c, i, 3);
                Cell* d = new Cell();
                a.placeCell(*d, i+1, 4);
        }
        
        a.playLifeGame(6, 1);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<Cell> 4x4 ***" << endl;
        cout << endl;
        Life<Cell> a(4,4);
        for(int i = 0; i < 4; ++i){
            for (int j = 0 ; j < 4; ++j){
                if (j % 2 == 0){
                        Cell* c = new Cell();
                        a.placeCell(*c, i, j);
                }
            }
        }
        
        a.playLifeGame(10, 1);
        
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<Cell> 8x8 ***" << endl;
        cout << endl;
        Life<Cell> a(8,8);
        for(int i = 0; i < 8; ++i){
            for (int j = 0 ; j < 8; ++j){
                if (j % 2 == 0){
                        Cell* c = new Cell();
                        a.placeCell(*c, i, j);
                }
            }
            if (i % 2 == 0){
                        Cell* c = new Cell();
                        a.placeCell(*c, i, 0);
                }
        }
        
        a.playLifeGame(6, 1);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;
        cout << endl;
        Life<Cell> a(20,20);
        for(int i = 0; i < 20; ++i){
            for (int j = 0 ; j < 10; ++j){
                if (j % 2 == 0){
                        Cell* c = new Cell();
                        a.placeCell(*c, i, j);
                }
            }
            if (i % 2 == 0){
                        Cell* c = new Cell();
                        a.placeCell(*c, i, 0);
                }
        }
        
        a.playLifeGame(9, 1);
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    
    return 0;}

