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
#include <fstream>   // fstream


#include "Life.h"

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    // we'll be reading from these three files, five tests apiece
    fstream conwayStream ("RunLifeConway.in", std::fstream::in);
    fstream fredkinStream ("RunLifeFredkin.in", std::fstream::in);
    fstream cellStream ("RunLifeCell.in", std::fstream::in);

    // ------------------
    // Conway Cell 109x69
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 109x69 ***" << endl << endl;
        int rows, cols;
        conwayStream >> rows >> cols;
        Life<ConwayCell> life(rows, cols, ConwayCell()); 
        conwayStream >> life;
        for(int i = 0; i < 283; ++i) {
            if( i < 10)
                cout << life << endl;
            life.simulateMove();}
        cout << life << endl;
        for(int i = 0; i < 40; ++i) 
            life.simulateMove();
        cout << life << endl;
        for(int i = 0; i < 2177; ++i) 
            life.simulateMove();
        cout << life << endl;}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Conway Cell other!
    // ------------------
    for(int test = 1 ; test < 5; ++test) {
        try {
            int rows, cols;
            conwayStream >> rows >> cols;
            cout << "*** Life<ConwayCell> " << rows << "x" << cols << " ***" << endl << endl;
            Life<ConwayCell> life(rows, cols, ConwayCell()); 
            conwayStream >> life;
            for(int i = 0; i < 10; ++i) {
                cout << life << endl;
                life.simulateMove();}}
        catch (const invalid_argument&) {
            assert(false);}
        catch (const out_of_range&) {
            assert(false);}}

    conwayStream.close();

    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl << endl;
        int rows, cols;
        fredkinStream >> rows >> cols;
        Life<FredkinCell> life(rows, cols);
        fredkinStream >> life;
        for(int i = 0; i < 5; ++i) {
            cout << life << endl;
            life.simulateMove();}
        cout << life << endl;}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell other!
    // ------------------
    for(int test = 1 ; test < 5; ++test) {
        try {
            int rows, cols;
            fredkinStream >> rows >> cols;
            cout << "*** Life<FredkinCell> " << rows << "x" << cols << " ***" << endl << endl;
            Life<FredkinCell> life(rows, cols, FredkinCell()); 
            fredkinStream >> life;
            for(int i = 0; i < 10; ++i) {
                cout << life << endl;
                life.simulateMove();}}
        catch (const invalid_argument&) {
            assert(false);}
        catch (const out_of_range&) {
            assert(false);}}

    fredkinStream.close();


    // ----------
    // Cell 20x20
    // ----------

    try {
        cout << "*** Life<Cell> 20x20 ***" << endl << endl;
        int rows, cols;
        cellStream >> rows >> cols;
        Life<Cell> life(rows, cols, new FredkinCell());
        cellStream >> life;
        for(int i = 0; i < 5; ++i) {
            cout << life << endl;
            life.simulateMove();}
        cout << life << endl;}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Cell other!
    // ------------------
    for(int test = 1 ; test < 5; ++test) {
        try {
            int rows, cols;
            cellStream >> rows >> cols;
            cout << "*** Life<Cell> " << rows << "x" << cols << " ***" << endl << endl;
            Life<Cell> life(rows, cols, new FredkinCell()); 
            cellStream >> life;
            for(int i = 0; i < 10; ++i) {
                cout << life << endl;
                life.simulateMove();}}
        catch (const invalid_argument&) {
            assert(false);}
        catch (const out_of_range&) {
            assert(false);}}

    cellStream.close();

    return 0;}

