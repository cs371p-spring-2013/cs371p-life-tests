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
#include <fstream>   // ifstream
#include <string>    // string
#include <cstdlib>

#include "Cell.h"
#include "ConwayCell.h"
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
        cout << "*** Life<ConwayCell> 109x69 ***\n" << endl;
        string line;
        int length = 0;
        int width = 0;
        ifstream file ("RunLifeConway.in");
        if (file.is_open ()) {
            if (file.good ()) {
                getline (file, line);
                length = atoi (line.c_str ());
            }
            if (file.good ()) {
                getline (file, line);
                width = atoi (line.c_str ());
            }
        }
        else {
            cout << "Unable to open file" << endl;
        }
        Life<ConwayCell> life (length, width);
        int r = 0;
        int c = 0;
        while (file.good ()) {
            getline (file, line);
            for (c = 0; c < width; ++c) {
                if (line.at(c) == '*') {
                    life.place (r, c);
                }
            }
            ++r;
        }
        file.close ();
        life.print (cout);
        for (int x = 0; x < 9; ++x) {
            life.simulate ();
            life.print (cout);
        }
        for (int x = 9; x < 283; ++x) {
            life.simulate ();
        }
        life.print (cout);
        for (int x = 283; x < 323; ++x) {
            life.simulate ();
        }
        life.print (cout);
        for (int x = 323; x < 2500; ++x) {
            life.simulate ();
        }
        life.print (cout);

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
        cout << "*** Life<FredkinCell> 20x20 ***\n" << endl;
        string line;
        int length = 0;
        int width = 0;
        ifstream file ("RunLifeFredkin.in");
        if (file.is_open ()) {
            if (file.good ()) {
                getline (file, line);
                length = atoi (line.c_str ());
            }
            if (file.good ()) {
                getline (file, line);
                width = atoi (line.c_str ());
            }
        }
        else {
            cout << "Unable to open file" << endl;
        }
        Life<FredkinCell> life (length, width);
        int r = 0;
        int c = 0;
        while (file.good ()) {
            getline (file, line);
            for (c = 0; c < width; ++c) {
                if (line.at(c) == '0') {
                    life.place (r, c);
                }
            }
            ++r;
        }
        file.close ();
        life.print (cout);
        for (int x = 0; x < 5; ++x) {
            life.simulate ();
            life.print (cout);
        }

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
        cout << "*** Life<Cell> 20x20 ***\n" << endl;
        string line;
        int length = 0;
        int width = 0;
        ifstream file ("RunLifeCell.in");
        if (file.is_open ()) {
            if (file.good ()) {
                getline (file, line);
                length = atoi (line.c_str ());
            }
            if (file.good ()) {
                getline (file, line);
                width = atoi (line.c_str ());
            }
        }
        else {
            cout << "Unable to open file" << endl;
        }
        Life<Cell> life (length, width);
        int r = 0;
        int c = 0;
        while (file.good ()) {
            getline (file, line);
            for (c = 0; c < width; ++c) {
                if (line.at(c) == '0') {
                    life.place (r, c);
                }
            }
            ++r;
        }
        file.close ();
        life.print (cout);
        for (int x = 0; x < 5; ++x) {
            life.simulate ();
            life.print (cout);
        }
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

    try {
        cout << "*** Life<ConwayCell> 100x50 ***\n" << endl;
        Life<ConwayCell> life (100, 50);
        for (int i = 0; i< 100; ++i){
            for(int j = 0; j< 50; ++j){
                if((j % 25))
                    life.place(i,j);
            }
        }

        life.print (cout);
        for (int x = 0; x < 500; ++x) {
            life.simulate();
            if(! (x%100))
                life.print(cout);
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> 75x75 ***\n" << endl;
        Life<FredkinCell> life (75, 75);
        for (int i = 0; i< 75; ++i){
            for(int j = 0; j< 75; ++j){
                if(!(j % 25) || !(i % 25))
                    life.place(i,j);
            }
        }

        life.print (cout);
        for (int x = 0; x < 10; ++x) {
            life.simulate();
            life.print(cout);
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<Cell> 45x45 ***\n" << endl;
        Life<Cell> life (45, 45);
        for (int i = 0; i< 45; ++i){
            for(int j = 0; j< 45; ++j){
                if(!(j % 15) || !(i % 15))
                    life.place(i, j);
            }
        }

        life.print (cout);
        for (int x = 0; x < 1000; ++x) {
            life.simulate();
            if ( !(x % 250))
                life.print(cout);
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> 75x75 ***\n" << endl;
        int length = 75;
        int width = 75;
        Life<ConwayCell> life (length, width);
        for (int i = 0; i< 75; ++i){
            for(int j = 0; j< 75; ++j){
                if(!(j % 25) || !(i % 25) || !(( (j+i) % 10)))
                    life.place(i,j);
            }
        }

        life.print (cout);
        for (int x = 0; x < 100; ++x) {
            life.simulate();
            if( !(x % 20))
                life.print(cout);
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

        try {
        cout << "*** Life<ConwayCell> 66x66 ***\n" << endl;
        Life<ConwayCell> life (66, 66);
        for (int i = 1; i< 66; ++i){
            for(int j = 1; j< 66; ++j){
                if(!((j*i) % 66))
                    life.place(i, j);
            }
        }

        life.print (cout);
        for (int x = 0; x < 100; ++x) {
            life.simulate();
             if( !(x % 20))
                life.print(cout);
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> 66x66 ***\n" << endl;
        Life<FredkinCell> life (66, 66);
        for (int i = 1; i< 66; ++i){
            for(int j = 1; j< 66; ++j){
                if(!((j*i) % 66))
                    life.place(i, j);
            }
        }

        life.print (cout);
        for (int x = 0; x < 100; ++x) {
            life.simulate();
             if( !(x % 20))
                life.print(cout);
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<Cell> 66x66 ***\n" << endl;
        Life<Cell> life (66, 66);
        for (int i = 1; i< 66; ++i){
            for(int j = 1; j< 66; ++j){
                if(!((j*i) % 66))
                    life.place(i, j);
            }
        }

        life.print (cout);
        for (int x = 0; x < 100; ++x) {
            life.simulate();
             if( !(x % 20))
                life.print(cout);
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}  


        try {
        cout << "*** Life<ConwayCell> 50x50 ***\n" << endl;
        Life<ConwayCell> life (50, 50);
        for (int i = 1; i< 50; ++i){
            for(int j = 1; j< 50; ++j){
                if(!((j+i) % 25) || !((j-i) % 25))
                    life.place(i, j);
            }
        }

        life.print (cout);
        for (int x = 0; x < 1000; ++x) {
            life.simulate();
             if( !(x % 200))
                life.print(cout);
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

        try {
        cout << "*** Life<FredkinCell> 50x50 ***\n" << endl;
        Life<FredkinCell> life (50, 50);
        for (int i = 1; i< 50; ++i){
            for(int j = 1; j< 50; ++j){
                if(!((j+i) % 25) || !((j-i) % 25))
                    life.place(i, j);
            }
        }

        life.print (cout);
        for (int x = 0; x < 1000; ++x) {
            life.simulate();
             if( !(x % 200))
                life.print(cout);
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

        try {
        cout << "*** Life<Cell> 50x50 ***\n" << endl;
        Life<Cell> life (50, 50);
        for (int i = 1; i< 50; ++i){
            for(int j = 1; j< 50; ++j){
                if(!((j+i) % 25) || !((j-i) % 25))
                    life.place(i, j);
            }
        }

        life.print (cout);
        for (int x = 0; x < 1000; ++x) {
            life.simulate();
             if( !(x % 200))
                life.print(cout);
        }

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}    
    return 0;}