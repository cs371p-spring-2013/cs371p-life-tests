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
        int r, c;
        ifstream myfile;
        myfile.open("RunLifeConway.in");
        myfile >> r;
        myfile >> c;
        Life<ConwayCell> life(r,c,ConwayCell());
        for(int i = 0; i < r; ++i){
          for(int j = 0; j < c; ++j){
            char t;
            myfile >> t;
            if(t == '*'){
              life.add(i,j,ConwayCell(true));}}}
        myfile.close();
        std::cout << life;
        for(int i = 0; i < 2500; ++i){
          life.run();
          if((i < 9) || (i == 282) || (i == 322) || (i == 2499)){
            std::cout << life;}}
        std::cout << std::endl;
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
        ifstream myfile;
        myfile.open("RunLifeFredkin.in");
        myfile >> r;
        myfile >> c;
        Life<FredkinCell> life(r,c,FredkinCell(false));
        for(int i = 0; i < r; ++i){
          for(int j = 0; j < c; ++j){
            char t;
            myfile >> t;
            if(t == '0'){
              life.add(i,j,FredkinCell(false,true));}}}
        myfile.close();
        std::cout << life;
        for(int i = 0; i < 5; ++i){
          life.run();
            std::cout << life;}
        std::cout << std::endl;
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
        ifstream myfile;
        myfile.open("RunLifeCell.in");
        myfile >> r;
        myfile >> c;
        Life<Cell> life(r,c,new FredkinCell(true));
        for(int i = 0; i < r; ++i){
          for(int j = 0; j < c; ++j){
            char t;
            myfile >> t;
            if(t == '0'){
              life.add(i,j,new FredkinCell(true,true));}}}
        myfile.close();
        std::cout << life;
        for(int i = 0; i < 5; ++i){
          life.run();
            std::cout << life;}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> 3x3 ***" << endl;
        Life<ConwayCell> life(3,3,ConwayCell());
        life.add(0,0,ConwayCell(true));
        life.add(0,1,ConwayCell(true));
        life.add(0,2,ConwayCell(true));
        std::cout << life;
        for(int i = 0; i < 5; ++i){
          life.run();
            std::cout << life;}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> 2x2 ***" << endl;
        Life<ConwayCell> life(3,3,ConwayCell(true));
        std::cout << life;
        for(int i = 0; i < 5; ++i){
          life.run();
            std::cout << life;}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> 10x10 ***" << endl;
        Life<ConwayCell> life(10,10,ConwayCell());
        for(int i = 0; i < 10; ++i){
          for(int j = 0; j < 10; ++j){
            if((i*10+j) % 3 == 0){
              life.add(i,j,ConwayCell(true));}}}
        std::cout << life;
        for(int i = 0; i < 5; ++i){
          life.run();
            std::cout << life;}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> 10x10 ***" << endl;
        Life<ConwayCell> life(10,10,ConwayCell());
        for(int i = 0; i < 10; ++i){
          for(int j = 0; j < 10; ++j){
            if(((i*10+j) & 1) == 0){
              life.add(i,j,ConwayCell(true));}}}
        std::cout << life;
        for(int i = 0; i < 5; ++i){
          life.run();
            std::cout << life;}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> 1x1 ***" << endl;
        Life<ConwayCell> life(1,1,ConwayCell(true));
        std::cout << life;
        for(int i = 0; i < 5; ++i){
          life.run();
          std::cout << life;}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
        
        

    try {
        cout << "*** Life<FredkinCell> 3x3 ***" << endl;
        Life<FredkinCell> life(3,3,FredkinCell(false));
        life.add(0,0,FredkinCell(false,true));
        life.add(0,1,FredkinCell(false,true));
        life.add(0,2,FredkinCell(false,true));
        std::cout << life;
        for(int i = 0; i < 5; ++i){
          life.run();
            std::cout << life;}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> 2x2 ***" << endl;
        Life<FredkinCell> life(3,3,FredkinCell(false,true));
        std::cout << life;
        for(int i = 0; i < 5; ++i){
          life.run();
            std::cout << life;}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> 10x10 ***" << endl;
        Life<FredkinCell> life(10,10,FredkinCell(false));
        for(int i = 0; i < 10; ++i){
          for(int j = 0; j < 10; ++j){
            if((i*10+j) % 3 == 0){
              life.add(i,j,FredkinCell(false,true));}}}
        std::cout << life;
        for(int i = 0; i < 5; ++i){
          life.run();
            std::cout << life;}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> 10x10 ***" << endl;
        Life<FredkinCell> life(10,10,FredkinCell(false));
        for(int i = 0; i < 10; ++i){
          for(int j = 0; j < 10; ++j){
            if(((i*10+j) & 1) == 0){
              life.add(i,j,FredkinCell(false,true));}}}
        std::cout << life;
        for(int i = 0; i < 5; ++i){
          life.run();
            std::cout << life;}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> 1x1 ***" << endl;
        Life<FredkinCell> life(1,1,FredkinCell(false,true));
        std::cout << life;
        for(int i = 0; i < 5; ++i){
          life.run();
          std::cout << life;}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}




        
        
        

    try {
        cout << "*** Life<Cell> 3x3 ***" << endl;
        Life<Cell> life(3,3,new FredkinCell(true));
        life.add(0,0,new FredkinCell(true,true));
        life.add(0,1,new FredkinCell(true,true));
        life.add(0,2,new FredkinCell(true,true));
        std::cout << life;
        for(int i = 0; i < 8; ++i){
          life.run();
            std::cout << life;}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<Cell> 2x2 ***" << endl;
        Life<Cell> life(3,3,new FredkinCell(true,true));
        std::cout << life;
        for(int i = 0; i < 8; ++i){
          life.run();
            std::cout << life;}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<Cell> 10x10 ***" << endl;
        Life<Cell> life(10,10,new FredkinCell(true));
        for(int i = 0; i < 10; ++i){
          for(int j = 0; j < 10; ++j){
            if((i*10+j) % 3 == 0){
              life.add(i,j,new FredkinCell(true,true));}}}
        std::cout << life;
        for(int i = 0; i < 8; ++i){
          life.run();
            std::cout << life;}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<Cell> 10x10 ***" << endl;
        Life<Cell> life(10,10,new FredkinCell(true));
        for(int i = 0; i < 10; ++i){
          for(int j = 0; j < 10; ++j){
            if(((i*10+j) & 1) == 0){
              life.add(i,j,new FredkinCell(true,true));}}}
        std::cout << life;
        for(int i = 0; i < 8; ++i){
          life.run();
            std::cout << life;}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<Cell> 1x1 ***" << endl;
        Life<Cell> life(1,1,new FredkinCell(true,true));
        std::cout << life;
        for(int i = 0; i < 8; ++i){
          life.run();
          std::cout << life;}
        std::cout << std::endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}        
        
        
        
    return 0;}