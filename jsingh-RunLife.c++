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
#include "AbstractCell.h"
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
        fstream fs("RunLifeConway.in", fstream::in);

        int height = 0;
        int width = 0;
        fs >> height;
        fs >> width;
        fs.get();
        char list[70];

        Life<ConwayCell> game(height, width);

        for(int i = 0; i < height; ++i){
            fs.getline(list, 70);

            for(int j = 0; j < width; ++j){
                if(list[j] == '.'){
                    ConwayCell test(State::DEAD);
                    game.addCell(i, j, test);
                }else{
                    ConwayCell test(State::ALIVE);
                    game.addCell(i, j, test);
                }
            }
        }

        cout << endl;
        for(int i = 0; i < 2500; ++i){
            if(i>=0 && i <10)
                game.printBoard(cout);
            if(i==283 || i==323)
                game.printBoard(cout);
            game.simulate();
        }
        game.printBoard(cout);        

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
        fstream fs("RunLifeFredkin.in", fstream::in);
        
        int height = 0;
        int width = 0;
        fs >> height;
        fs >> width;

        fs.get(); 
        
        char list[21];
        
        Life<FredkinCell> game(height, width);
        
        for(int i = 0; i < height; ++i){
            fs.getline(list, 21);
            
            for(int j = 0; j < width; ++j){
                if(list[j] == '-'){
                    FredkinCell test(State::DEAD);
                    game.addCell(i, j, test);
                }else{
                    FredkinCell test(State::ALIVE);
                    game.addCell(i, j, test);
                }
            }
        } 

        cout << endl;
        for(int i = 0; i < 5; ++i){
            game.printBoard(cout);
            game.simulate();
        }
        game.printBoard(cout);

        fs.close();
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
        
        fstream fs("RunLifeCell.in", fstream::in);

        int height = 0;
        int width = 0;
        fs >> height;
        fs >> width;
    
        fs.get();

        char list[21];

        Life<Cell> game(height, width);

        for(int i = 0; i < height; ++i){
            fs.getline(list, 21);

            for(int j = 0; j < width; ++j){
                if(list[j] == '-'){
                    game.addCell(i, j, new FredkinCell(State::DEAD));
                }else{
                    game.addCell(i, j, new FredkinCell(State::ALIVE));
                }
            }
        }

        cout << endl;

        for(int i = 0; i < 5; ++i){
            game.printBoard(cout);
            game.simulate();
        }
        game.printBoard(cout);

        fs.close();
        }
    catch(const invalid_argument&){
        assert(false);}
    catch(const out_of_range&){
        assert(false);}


    // --------------
    // ConwayCell 3x3
    // --------------

    try {
        cout << "*** Life<ConwayCell> 3x3 ***" << endl;
        cout << endl;
        Life<ConwayCell> game(3,3);
        ConwayCell test(State::ALIVE);
        ConwayCell test2(State::ALIVE);
        ConwayCell test3(State::ALIVE);
        game.addCell(1,0, test);
        game.addCell(1,1, test2);
        game.addCell(1,2, test3);
        
        game.printBoard(cout);
        game.simulate();
        game.printBoard(cout);
        game.simulate();
        game.printBoard(cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // --------------
    // FredkinCell 3x3
    // --------------

    try {
        cout << "*** Life<FredkinCell> 3x3 ***" << endl;
        cout << endl;
        Life<FredkinCell> game(3,3);
        game.addCell(1,0, FredkinCell(State::ALIVE));
        game.addCell(1,1, FredkinCell(State::ALIVE));
        game.addCell(1,2, FredkinCell(State::ALIVE));
        
        for(int i =0; i< 5; ++i){
            game.printBoard(cout);
            game.simulate();
        }
        game.printBoard(cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // -------------------
    // ConwayCell 5x5 Boat
    // -------------------

    try {
        cout << "*** Life<ConwayCell> 5x5 Boat ***" << endl;
        cout << endl;
        Life<ConwayCell> game(5,5);
        game.addCell(1,1, ConwayCell(State::ALIVE));
        game.addCell(1,2, ConwayCell(State::ALIVE));
        game.addCell(2,1, ConwayCell(State::ALIVE));
        game.addCell(2,3, ConwayCell(State::ALIVE));
        game.addCell(3,2, ConwayCell(State::ALIVE));
        
        game.printBoard(cout);
        game.simulate();
        game.printBoard(cout);
        game.simulate();
        game.printBoard(cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // -------------------
    // FredkinCell 5x5 Boat
    // -------------------

    try {
        cout << "*** Life<FredkinCell> 5x5 Boat ***" << endl;
        cout << endl;
        Life<FredkinCell> game(5,5);
        game.addCell(1,1, FredkinCell(State::ALIVE));
        game.addCell(1,2, FredkinCell(State::ALIVE));
        game.addCell(2,1, FredkinCell(State::ALIVE));
        game.addCell(2,3, FredkinCell(State::ALIVE));
        game.addCell(3,2, FredkinCell(State::ALIVE));
        
        for(int i =0; i< 10; ++i){
            game.printBoard(cout);
            game.simulate();
        }
        game.printBoard(cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // -----------------------
    // Cell 5x5 Boat w/ Conway
    // -----------------------

    try {
        cout << "*** Life<Cell> 5x5 Boat ***" << endl;
        cout << endl;
        Life<Cell> game(5,5);
        game.addCell(1,1, new ConwayCell(State::ALIVE));
        game.addCell(1,2, new ConwayCell(State::ALIVE));
        game.addCell(2,1, new ConwayCell(State::ALIVE));
        game.addCell(2,3, new ConwayCell(State::ALIVE));
        game.addCell(3,2, new ConwayCell(State::ALIVE));
        
        for(int i = 0; i < 10; ++i){
            game.printBoard(cout);
            game.simulate();
        }
        game.printBoard(cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------------
    // CownayCell 6x6 Beacon
    // --------------------

    try {
        cout << "*** Life<ConwayCell> 6x6 ***" << endl;
        cout << endl;
        Life<ConwayCell> game(6,6);
        game.addCell(1,1, ConwayCell(State::ALIVE));
        game.addCell(2,1, ConwayCell(State::ALIVE));
        game.addCell(1,2, ConwayCell(State::ALIVE));
        game.addCell(4,4, ConwayCell(State::ALIVE));
        game.addCell(4,3, ConwayCell(State::ALIVE));
        game.addCell(3,4, ConwayCell(State::ALIVE));
        
        game.printBoard(cout);
        game.simulate();
        game.printBoard(cout);
        game.simulate();
        game.printBoard(cout);
        game.simulate();
        game.printBoard(cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // --------------------------
    // ConwayCell 25x25 Spaceship
    // --------------------------

    try {
        cout << "*** Life<ConwayCell> 25x25 Spaceship ***" << endl;
        cout << endl;
        Life<ConwayCell> game(25,25);
        game.addCell(2,1, ConwayCell(State::ALIVE));
        game.addCell(2,2, ConwayCell(State::ALIVE));
        game.addCell(2,3, ConwayCell(State::ALIVE));
        game.addCell(1,3, ConwayCell(State::ALIVE));
        game.addCell(0,2, ConwayCell(State::ALIVE));

        for(int i = 0; i < 50; ++i){
            game.printBoard(cout);
            game.simulate();
        }
        game.printBoard(cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // -----------------
    // FrekinCell 25x25
    // -----------------

    try {
        cout << "*** Life<FredkinCell> 25x25 ***" << endl;
        cout << endl;
        Life<FredkinCell> game(25,25);
        game.addCell(2,1, FredkinCell(State::ALIVE));
        game.addCell(2,2, FredkinCell(State::ALIVE));
        game.addCell(2,3, FredkinCell(State::ALIVE));
        game.addCell(1,3, FredkinCell(State::ALIVE));
        game.addCell(0,2, FredkinCell(State::ALIVE));

        for(int i = 0; i < 50; ++i){
            game.printBoard(cout);
            game.simulate();
        }
        game.printBoard(cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ---------------
    // FredkinCell 6x6
    // ---------------     

    try {
        cout << "*** Life<FredkinCell> 6x6 ***" << endl;
        cout << endl;
        Life<FredkinCell> game(6,6);
        game.addCell(1,1, FredkinCell(State::ALIVE));
        game.addCell(2,1, FredkinCell(State::ALIVE));
        game.addCell(1,2, FredkinCell(State::ALIVE));
        game.addCell(4,4, FredkinCell(State::ALIVE));
        game.addCell(4,3, FredkinCell(State::ALIVE));
        game.addCell(3,4, FredkinCell(State::ALIVE));
       

        for(int i = 0; i < 10; ++i){ 
            game.printBoard(cout);
            game.simulate();
        }
        game.printBoard(cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ------------------------
    // Cell 3x3 with ConwayCell
    // ------------------------
        
    try {
        cout << "*** Life<Cell> 3x3 ***" << endl;
        cout << endl;
        Life<Cell> game(3,3);
        game.addCell(1,0, new ConwayCell(State::ALIVE));
        game.addCell(1,1, new ConwayCell(State::ALIVE));
        game.addCell(1,2, new ConwayCell(State::ALIVE));
        
        game.printBoard(cout);
        game.simulate();
        game.printBoard(cout);
        game.simulate();
        game.printBoard(cout);
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Cell 5x5 with mix
    // ------------------

    try {
        cout << "*** Life<Cell> 5x5 w/ mix ***" << endl;
        cout << endl;

        Life<Cell> game(5,5);
        game.addCell(1,0, new ConwayCell(State::ALIVE));
        game.addCell(2,1, new FredkinCell(State::ALIVE));
        game.addCell(2,2, new ConwayCell(State::DEAD));
        game.addCell(4,4, new ConwayCell(State::DEAD));
        game.addCell(3,3, new FredkinCell(State::ALIVE));
        game.addCell(4,1, new ConwayCell(State::ALIVE));

        for(int i = 0; i < 5; ++i){
            game.printBoard(cout);
            game.simulate();
        }
        game.printBoard(cout);
    }
    catch(const invalid_argument&){
        assert(false);}
    catch(const out_of_range&){
        assert(false);}
    

    // -------------------
    // Cell 5x5 w/ Fredkin
    // -------------------    
    
    try {
        cout << "*** Life<Cell> 5x5 w/ Fredkin ***" << endl;
        cout << endl;

        Life<Cell> game(5,5);
        game.addCell(1,0, new FredkinCell(State::ALIVE));
        game.addCell(2,1, new FredkinCell(State::ALIVE));
        game.addCell(2,2, new FredkinCell(State::ALIVE));
        game.addCell(4,4, new FredkinCell(State::ALIVE));
        game.addCell(3,3, new FredkinCell(State::ALIVE));
        game.addCell(4,1, new FredkinCell(State::ALIVE));

        for(int i = 0; i < 10; ++i){
            game.printBoard(cout);
            game.simulate();
        }
        game.printBoard(cout);
    }
    catch(const invalid_argument&){
        assert(false);}
    catch(const out_of_range&){
        assert(false);}

    return 0;}
