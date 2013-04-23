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
#include <fstream>  // cout, endl
#include <vector>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range

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
        ifstream f;
        f.open("RunLifeConway.in");
        int h;
        int w;
        f >> h;
        f >> w;

        vector<vector<ConwayCell> > v(h, vector<ConwayCell>(w, false));

        int h_index;
        int w_index;
        int count = 0;
        char c;
        while(f){
          f >> c;
          w_index = count % w;
          h_index = count / w;
            
          if (c == '*'){
            v[h_index][w_index] = true;
          }
          ++count;
        }
        f.close();

        Life<ConwayCell> life(v);
        for(int i=0; i<10; i++){
          life.print(cout);
          life.evolve();
        }
        //We're on generation ten
        for(int i=10; i<283; i++){
          life.evolve();
        }
        life.print(cout);

        for(int i=283; i<323; i++){
          life.evolve();
        }
        life.print(cout);
        for(int i=323; i<2500; i++){
          life.evolve();
        }
        life.print(cout);

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
        ifstream f;
        f.open("RunLifeFredkin.in");
        int h;
        int w;
        f >> h;
        f >> w;

        vector<vector<FredkinCell> > v(h, vector<FredkinCell>(w, false));

        int h_index;
        int w_index;
        int count = 0;
        char c;
        while(f){
          f >> c;
          w_index = count % w;
          h_index = count / w;
            
          if (c == '0'){
            v[h_index][w_index] = true;
          }
          ++count;
        }
        f.close();

        Life<FredkinCell> life(v);

        for(int i=0; i<5; i++){
          life.print(cout);
          life.evolve();
        }
        life.print(cout);
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
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        ifstream f;
        f.open("RunLifeCell.in");
        int h;
        int w;
        f >> h;
        f >> w;

        vector<vector<Cell> > v(h, vector<Cell>(w, new FredkinCell(false)));

        int h_index;
        int w_index;
        int count = 0;
        char c;
        while(f){
          f >> c;
          w_index = count % w;
          h_index = count / w;
            
          if (c == '0'){
            v[h_index][w_index] = new FredkinCell(true);
          }
          ++count;
        }
        f.close();

        Life<Cell> life(v);

        for(int i=0; i<5; i++){
          life.print(cout);
          life.evolve();
        }
        life.print(cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    //Need 4 more Conway
      //glider
      //flipper (---) - oscilates 
      //square -static
    try {
        cout << "*** Life<ConwayCell> 9x14 ***" << endl;
        int h=9;
        int w=14;

        vector<vector<ConwayCell> > v(h, vector<ConwayCell>(w, false));

        Life<ConwayCell> life(v);

        for(int i=0; i<10; i++){
          life.print(cout);
          life.evolve();
        }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> 10x20 ***" << endl;
        int h=10;
        int w=20;

        vector<vector<ConwayCell> > v(h, vector<ConwayCell>(w, false));

        v[0][1] = true;
        v[1][1] = true;
        v[2][1] = true;

        v[7][18] = true;
        v[8][18] = true;
        v[9][18] = true;

        Life<ConwayCell> life(v);

        for(int i=0; i<10; i++){
          life.print(cout);
          life.evolve();
        }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> 4x4 ***" << endl;
        int h=4;
        int w=4;

        vector<vector<ConwayCell> > v(h, vector<ConwayCell>(w, false));

        v[1][1] = true;
        v[1][2] = true;
        v[2][1] = true;
        v[2][2] = true;

        Life<ConwayCell> life(v);

        for(int i=0; i<10; i++){
          life.print(cout);
          life.evolve();
        }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> 20x20 ***" << endl;
        int h=20;
        int w=20;

        vector<vector<ConwayCell> > v(h, vector<ConwayCell>(w, false));

        v[0][1] = true;

        v[1][2] = true;

        v[2][0] = true;
        v[2][1] = true;
        v[2][2] = true;


        Life<ConwayCell> life(v);

        for(int i=0; i<30; i++){
          life.print(cout);
          life.evolve();
        }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    //Need 4 more Fredkin
    try {
        cout << "*** Life<FredkinCell> 10x10 ***" << endl;
        int h=10;
        int w=10;

        vector<vector<FredkinCell> > v(h, vector<FredkinCell>(w, false));

        v[0][0] = true;

        v[9][0] = true;
        v[0][9] = true;
        v[9][9] = true;


        Life<FredkinCell> life(v);

        for(int i=0; i<30; i++){
          life.print(cout);
          life.evolve();
        }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> 9x9 ***" << endl;
        int h=9;
        int w=9;

        vector<vector<FredkinCell> > v(h, vector<FredkinCell>(w, false));

        v[4][4] = true;

        Life<FredkinCell> life(v);

        for(int i=0; i<20; i++){
          life.print(cout);
          life.evolve();
        }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> 1x1 ***" << endl;
        int h=1;
        int w=1;

        vector<vector<FredkinCell> > v(h, vector<FredkinCell>(w, true));

        Life<FredkinCell> life(v);

        for(int i=0; i<5; i++){
          life.print(cout);
          life.evolve();
        }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> 1x2 ***" << endl;
        int h=1;
        int w=2;

        vector<vector<FredkinCell> > v(h, vector<FredkinCell>(w, true));

        Life<FredkinCell> life(v);

        for(int i=0; i<5; i++){
          life.print(cout);
          life.evolve();
        }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    //Need 4 more Cell
    try {
        cout << "*** Life<Cell> 10x10 ***" << endl;
        int h=10;
        int w=10;

        vector<vector<Cell> > v(h, vector<Cell>(w, new FredkinCell(false)));

        v[0][0] = new FredkinCell(true);

        v[9][0] = new FredkinCell(true);
        v[0][9] = new FredkinCell(true);
        v[9][9] = new FredkinCell(true);


        Life<Cell> life(v);

        for(int i=0; i<30; i++){
          life.print(cout);
          life.evolve();
        }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<Cell> 9x9 ***" << endl;
        int h=9;
        int w=9;

        vector<vector<Cell> > v(h, vector<Cell>(w, new FredkinCell(false)));

        v[4][4] = new FredkinCell(true);

        Life<Cell> life(v);

        for(int i=0; i<20; i++){
          life.print(cout);
          life.evolve();
        }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<Cell> 1x1 ***" << endl;
        int h=1;
        int w=1;

        vector<vector<Cell> > v(h, vector<Cell>(w, new FredkinCell(true)));

        Life<Cell> life(v);

        for(int i=0; i<5; i++){
          life.print(cout);
          life.evolve();
        }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<Cell> 1x2 ***" << endl;
        int h=1;
        int w=2;

        vector<vector<Cell> > v(h, vector<Cell>(w, new FredkinCell(true)));

        Life<Cell> life(v);

        for(int i=0; i<5; i++){
          life.print(cout);
          life.evolve();
        }

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
