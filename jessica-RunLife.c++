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
#include <string>
#include <fstream>
#include <sstream> 
#include <vector>
#include <stdexcept> // invalid_argument, out_of_range


#include "Life.h"

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    string temp1;
    ifstream file1 ("RunLifeConway1.in");
    stringstream input1;
    int j = 0;
    while(j<13){
        getline(file1, temp1);
        input1 << temp1 << endl;
        j++;
    }

    // -----------------
    // Conway Cell 10x10
    // -----------------

    try {
        cout << "*** Life<ConwayCell> 10x10 ***" << endl;
        Life<ConwayCell> life1;
        life1.create(input1);
        life1.printGrid(cout);

        for (int i = 0; i < 5; i++){
            life1.processTurn();
            life1.printGrid(cout);
        }
        cout << "\n";
    }

    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    input1.flush();
    temp1.clear();
    j = 0;
    while(j<13){
        getline(file1, temp1);
        input1 << temp1 << endl;
        j++;
    }

    // -----------------
    // Conway Cell 10x10
    // -----------------

    try {
        cout << "*** Life<ConwayCell> 10x10 ***" << endl;
        Life<ConwayCell> life1;
        life1.create(input1);
        life1.printGrid(cout);

        for (int i = 0; i < 5; i++){
            life1.processTurn();
            life1.printGrid(cout);
        }
        cout << "\n";
    }

    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    input1.flush();
    temp1.clear();
    j = 0;
    while(j<13){
        getline(file1, temp1);
        input1 << temp1 << endl;
        j++;
    }

    // -----------------
    // Conway Cell 10x10
    // -----------------

    try {
        cout << "*** Life<ConwayCell> 10x10 ***" << endl;
        Life<ConwayCell> life1;
        life1.create(input1);
        life1.printGrid(cout);

        for (int i = 0; i < 5; i++){
            life1.processTurn();
            life1.printGrid(cout);
        }
        cout << "\n";
    }

    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    input1.flush();
    temp1.clear();
    j = 0;
    while(j<8){
        getline(file1, temp1);
        input1 << temp1 << endl;
        j++;
    }

    // -----------------
    // Conway Cell 6x6
    // -----------------

    try {
        cout << "*** Life<ConwayCell> 6x6 ***" << endl;
        Life<ConwayCell> life1;
        life1.create(input1);
        life1.printGrid(cout);

        for (int i = 0; i < 5; i++){
            life1.processTurn();
            life1.printGrid(cout);
        }
        cout << "\n";
    }

    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    input1.flush();
    temp1.clear();
    j = 0;
    while(j<13){
        getline(file1, temp1);
        input1 << temp1 << endl;
        j++;
    }

    // -----------------
    // Conway Cell 10x10
    // -----------------

    try {
        cout << "*** Life<ConwayCell> 10x10 ***" << endl;
        Life<ConwayCell> life1;
        life1.create(input1);
        life1.printGrid(cout);

        for (int i = 0; i < 5; i++){
            life1.processTurn();
            life1.printGrid(cout);
        }
        cout << "\n";
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
        Life<ConwayCell> conway;
        string temp;
        ifstream file ("RunLifeConway.in");
        stringstream input;
        while(!file.eof()){
            getline(file, temp);
            input << temp << endl;
        }

        conway.create(input);
        conway.printGrid(cout);

        for (int i = 0; i < 9; i++){
            conway.processTurn();
            conway.printGrid(cout);
        }

        for (int i = 0; i < 274; i++)
            conway.processTurn();
        conway.printGrid(cout);
        for (int i = 0; i < 40; i++)
            conway.processTurn();
        conway.printGrid(cout);
        for (int i = 0; i < 2177; i++)
            conway.processTurn();
        conway.printGrid(cout);
        cout << "\n";
    }

    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    string temp2;
    ifstream file2 ("RunLifeFredkin1.in");
    stringstream input2;
    j = 0;
    while(j<13){
        getline(file2, temp2);
        input2 << temp2 << endl;
        j++;
    }

    // -----------------
    // Fredkin Cell 10x10
    // -----------------

    try {
        cout << "*** Life<FredkinCell> 10x10 ***" << endl;
        Life<FredkinCell> life1;
        life1.create(input2);
        life1.printGrid(cout);

        for (int i = 0; i < 5; i++){
            life1.processTurn();
            life1.printGrid(cout);
        }
        cout << "\n";
    }

    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    input2.flush();
    temp2.clear();
    j = 0;
    while(j<13){
        getline(file2, temp2);
        input2 << temp2 << endl;
        j++;
    }

    // -----------------
    // Fredkin Cell 10x10
    // -----------------

    try {
        cout << "*** Life<FredkinCell> 10x10 ***" << endl;
        Life<FredkinCell> life1;
        life1.create(input2);
        life1.printGrid(cout);

        for (int i = 0; i < 5; i++){
            life1.processTurn();
            life1.printGrid(cout);
        }
        cout << "\n";
    }

    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    input2.flush();
    temp2.clear();
    j = 0;
    while(j<13){
        getline(file2, temp2);
        input2 << temp2 << endl;
        j++;
    }

    // -----------------
    // Fredkin Cell 10x10
    // -----------------

    try {
        cout << "*** Life<FredkinCell> 10x10 ***" << endl;
        Life<FredkinCell> life1;
        life1.create(input2);
        life1.printGrid(cout);

        for (int i = 0; i < 5; i++){
            life1.processTurn();
            life1.printGrid(cout);
        }
        cout << "\n";
    }

    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    input2.flush();
    temp2.clear();
    j = 0;
    while(j<8){
        getline(file2, temp2);
        input2 << temp2 << endl;
        j++;
    }

    // -----------------
    // Fredkin Cell 6x6
    // -----------------

    try {
        cout << "*** Life<FredkinCell> 6x6 ***" << endl;
        Life<FredkinCell> life1;
        life1.create(input2);
        life1.printGrid(cout);

        for (int i = 0; i < 5; i++){
            life1.processTurn();
            life1.printGrid(cout);
        }
        cout << "\n";
    }

    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    input2.flush();
    temp2.clear();
    j = 0;
    while(j<13){
        getline(file2, temp2);
        input2 << temp2 << endl;
        j++;
    }

    // -----------------
    // Fredkin Cell 10x10
    // -----------------

    try {
        cout << "*** Life<FredkinCell> 10x10 ***" << endl;
        Life<FredkinCell> life1;
        life1.create(input2);
        life1.printGrid(cout);

        for (int i = 0; i < 5; i++){
            life1.processTurn();
            life1.printGrid(cout);
        }
        cout << "\n";
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
        Life<FredkinCell> fredkin;
        string temp1;
        ifstream file1 ("RunLifeFredkin.in");
        stringstream input1;
        while(!file1.eof()){
            getline(file1, temp1);
            input1 << temp1 << endl;
        }

        fredkin.create(input1);
        fredkin.printGrid(cout);

        for (int i = 0; i < 5; i++){
            fredkin.processTurn();
            fredkin.printGrid(cout);
        }


        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    string temp3;
    ifstream file3 ("RunLifeCell1.in");
    stringstream input3;
    j = 0;
    while(j<13){
        getline(file3, temp3);
        input3 << temp3 << endl;
        j++;
    }

    // ----------
    // Cell 10x10
    // ----------

    try {
        cout << "*** Life<Cell> 10x10 ***" << endl;
        Life<Cell> life1;
        life1.create(input3);
        life1.printGrid(cout);

        for (int i = 0; i < 5; i++){
            life1.processTurn();
            life1.printGrid(cout);
        }
        cout << "\n";
    }

    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    input3.flush();
    temp3.clear();
    j = 0;
    while(j<13){
        getline(file3, temp3);
        input3 << temp3 << endl;
        j++;
    }

    // ----------
    // Cell 10x10
    // ----------

    try {
        cout << "*** Life<Cell> 10x10 ***" << endl;
        Life<Cell> life1;
        life1.create(input3);
        life1.printGrid(cout);

        for (int i = 0; i < 5; i++){
            life1.processTurn();
            life1.printGrid(cout);
        }
        cout << "\n";
    }

    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    input3.flush();
    temp3.clear();
    j = 0;
    while(j<13){
        getline(file3, temp3);
        input3 << temp3 << endl;
        j++;
    }

    // ----------
    // Cell 10x10
    // ----------

    try {
        cout << "*** Life<Cell> 10x10 ***" << endl;
        Life<Cell> life1;
        life1.create(input3);
        life1.printGrid(cout);

        for (int i = 0; i < 5; i++){
            life1.processTurn();
            life1.printGrid(cout);
        }
        cout << "\n";
    }

    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    input3.flush();
    temp3.clear();
    j = 0;
    while(j<8){
        getline(file3, temp3);
        input3 << temp3 << endl;
        j++;
    }

    // --------
    // Cell 6x6
    // --------

    try {
        cout << "*** Life<Cell> 6x6 ***" << endl;
        Life<Cell> life1;
        life1.create(input3);
        life1.printGrid(cout);

        for (int i = 0; i < 5; i++){
            life1.processTurn();
            life1.printGrid(cout);
        }
        cout << "\n";
    }

    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    input3.flush();
    temp3.clear();
    j = 0;
    while(j<13){
        getline(file3, temp3);
        input3 << temp3 << endl;
        j++;
    }

    // ----------
    // Cell 10x10
    // ----------

    try {
        cout << "*** Life<Cell> 10x10 ***" << endl;
        Life<Cell> life1;
        life1.create(input3);
        life1.printGrid(cout);

        for (int i = 0; i < 5; i++){
            life1.processTurn();
            life1.printGrid(cout);
        }
        cout << "\n";
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

        Life<Cell> cells;
        string temp2;
        ifstream file2 ("RunLifeCell.in");
        stringstream input2;
        while(!file2.eof()){
            getline(file2, temp2);
            input2 << temp2 << endl;
        }

        cells.create(input2);
        cells.printGrid(cout);

        for (int i = 0; i < 5; i++){
            cells.processTurn();
            cells.printGrid(cout);
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
