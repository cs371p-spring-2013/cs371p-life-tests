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
#include "Life.h"
#include "ConwayCell.h"
#include "Cell.h"
#include "FredkinCell.h"

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
        Life<ConwayCell> life;
        ifstream in("RunLifeConway.in");
        life = Life<ConwayCell>(in);
        life.printLife();
        for(int i = 0; i < 9; i++){
          life.simulate(1);
          life.printLife();
        }
        life.simulate(274);
        life.printLife();
        life.simulate(40);
        life.printLife();
        life.simulate(2177);
        life.printLife();
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
        ifstream in("RunLifeFredkin.in");
        Life<FredkinCell> life = Life<FredkinCell>(in);
        for(int i = 0; i < 6;i++){
          life.printLife();
          life.simulate(1);
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
        ifstream in("RunLifeCell.in");
        Life<Cell> life = Life<Cell>(in);
        for(int i = 0; i < 6; i++){
          life.printLife();
          life.simulate(1);
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // My ConwayCell1 1x1
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 1x1 ***" << endl;
        
        Life<ConwayCell> life = Life<ConwayCell>(1,1);
        ConwayCell* cell = new ConwayCell('*');
        life.addCell(0,0,*cell);
        life.printLife();
        life.simulate(100);
        life.printLife();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // --------------------
    // My ConwayCell2 10x10
    // --------------------

    try {
        cout << "*** Life<ConwayCell> 10x10 ***" << endl;
        
        Life<ConwayCell> life = Life<ConwayCell>(10,10);
        for(int i = 0; i < 10; i++){
          for(int j = 0; j < 10; j++){
            ConwayCell* cell = new ConwayCell('*');
            life.addCell(i,j,*cell);
          }
        }
        life.printLife();
        life.simulate(2);
        life.printLife();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------------------
    // My ConwayCell3 10x10
    // --------------------

    try {
        cout << "*** Life<ConwayCell> 10x10 ***" << endl;
        
        Life<ConwayCell> life = Life<ConwayCell>(10,10);
        for(int i = 1; i < 10; i+=2){
          for(int j = 0; j < 10; j++){
            ConwayCell* cell = new ConwayCell('*');
            life.addCell(i,j,*cell);
          }
        }
        life.printLife();
        life.simulate(5);
        life.printLife();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------------------
    // My ConwayCell4 1x10
    // --------------------

    try {
        cout << "*** Life<ConwayCell> 1x10 ***" << endl;
        
        Life<ConwayCell> life = Life<ConwayCell>(1,10);
        for(int i = 0; i < 10; i++){
          ConwayCell* cell = new ConwayCell('*');
          life.addCell(0,i,*cell);
        }
        for(int i = 0; i < 4; i++){
          life.printLife();
          life.simulate(1);
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // --------------------
    // My ConwayCell5 100x100
    // --------------------

    try {
        cout << "*** Life<ConwayCell> 100x100 ***" << endl;
        
        Life<ConwayCell> life = Life<ConwayCell>(100,100);
        life.simulate(100);
        life.printLife();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // My FredkinCell1 1x1
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 1x1 ***" << endl;
        
        Life<FredkinCell> life = Life<FredkinCell>(1,1);
        FredkinCell* cell = new FredkinCell('0');
        life.addCell(0,0,*cell);
        life.printLife();
        life.simulate(100);
        life.printLife();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------------------
    // My FredkinCell2 10x10
    // --------------------

    try {
        cout << "*** Life<FredkinCell> 10x10 ***" << endl;
        
        Life<FredkinCell> life = Life<FredkinCell>(10,10);
        for(int i = 0; i < 10; i++){
          for(int j = 0; j < 10; j++){
            FredkinCell* cell = new FredkinCell('0');
            life.addCell(i,j,*cell);
          }
        }
        life.printLife();
        life.simulate(3);
        life.printLife();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------------------
    // My FredkinCell3 10x10
    // --------------------

    try {
        cout << "*** Life<FredkinCell> 10x10 ***" << endl;
        
        Life<FredkinCell> life = Life<FredkinCell>(10,10);
        for(int i = 1; i < 10; i+=2){
          for(int j = 0; j < 10; j++){
            FredkinCell* cell = new FredkinCell('0');
            life.addCell(i,j,*cell);
          }
        }
        life.printLife();
        life.simulate(5);
        life.printLife();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------------------
    // My FredkinCell4 1x10
    // --------------------

    try {
        cout << "*** Life<FredkinCell> 1x10 ***" << endl;
        
        Life<FredkinCell> life = Life<FredkinCell>(1,10);
        for(int i = 0; i < 10; i++){
          FredkinCell* cell = new FredkinCell('0');
          life.addCell(0,i,*cell);
        }
        for(int i = 0; i < 4; i++){
          life.printLife();
          life.simulate(1);
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------------------
    // My FredkinCell5 100x100
    // --------------------

    try {
        cout << "*** Life<FredkinCell> 100x100 ***" << endl;
        
        Life<FredkinCell> life = Life<FredkinCell>(100,100);
        int i = 0;
        while(i < 100){
          FredkinCell* cell = new FredkinCell('0');
          life.addCell(i,50,*cell);
          i++;
        }
        i = 0;
        while(i < 100){
          FredkinCell* cell = new FredkinCell('0');
          life.addCell(50,i,*cell);
          i++;
        }
        life.simulate(100);
        life.printLife();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // My Cell1 1x1
    // ------------------

    try {
        cout << "*** Life<Cell> 1x1 ***" << endl;
        
        Life<Cell> life = Life<Cell>(1,1);
        Cell* cell = new Cell('0');
        life.addCell(0,0,*cell);
        life.printLife();
        life.simulate(100);
        life.printLife();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------------------
    // My Cell2 10x10
    // --------------------

    try {
        cout << "*** Life<Cell> 10x10 ***" << endl;
        
        Life<Cell> life = Life<Cell>(10,10);
        for(int i = 0; i < 10; i++){
          for(int j = 0; j < 10; j++){
            Cell* cell = new Cell('0');
            life.addCell(i,j,*cell);
          }
        }
        life.printLife();
        life.simulate(4);
        life.printLife();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------------------
    // My Cell3 10x10
    // --------------------

    try {
        cout << "*** Life<Cell> 10x10 ***" << endl;
        
        Life<Cell> life = Life<Cell>(10,10);
        for(int i = 1; i < 10; i+=2){
          for(int j = 0; j < 10; j++){
            char s = '*';
            if(j % 2 == 0)
              s = '0';
            Cell* cell = new Cell(s);
            life.addCell(i,j,*cell);
          }
        }
        life.printLife();
        life.simulate(5);
        life.printLife();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------------------
    // My Cell4 1x10
    // --------------------

    try {
        cout << "*** Life<Cell> 1x10 ***" << endl;
        
        Life<Cell> life = Life<Cell>(1,10);
        for(int i = 0; i < 10; i++){
          Cell* cell = new Cell('0');
          life.addCell(0,i,*cell);
        }
        for(int i = 0; i < 10; i++){
          life.printLife();
          life.simulate(1);
        }
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------------------
    // My Cell5 100x100
    // --------------------

    try {
        cout << "*** Life<Cell> 100x100 ***" << endl;
        
        Life<Cell> life = Life<Cell>(100,100);
        int i = 0;
        while(i < 100){
          Cell* cell = new Cell('*');
          life.addCell(i,50,*cell);
          i++;
        }
        i = 0;
        while(i < 100){
          Cell* cell = new Cell('0');
          life.addCell(50,i,*cell);
          i++;
        }
        life.simulate(100);
        life.printLife();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    return 0;}
