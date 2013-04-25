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
#include <cstdlib>   // rand, srand
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include <fstream>

#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

// ----
// main
// ----

int main () {
    //Adding comments so I can commit changes that github is being difficult about. 
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    // ------------------
    // Conway Cell 109x69
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 109x69 ***" << endl;
        std::ifstream infile("RunLifeConway.in");
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
        int height, width;
        infile >> height;
        infile >> width;
        Life<ConwayCell> life(width, height);
        string str;
        int index = 0;
        while(infile >> str){
            //str is a single line of input
            //cout << str << endl;
            for(int i = 0; i < (int)str.length(); i++){
                char c = str[i];
                if(c == '*'){
                    ConwayCell& c = life.getCell(index / width, index % width);
                    c.toggle_life_death(true);
                }
            index++;
            }
        }

        //life.displayGrid(cout);
        life.runLife(9,1, cout,0);
        life.runLife(274,274,cout,10);
        life.runLife(40,40,cout,284);
        life.runLife(2177,2177,cout,324);
        //life.runLife(283,283, cout);
        cout << endl;
        //life.runLife(273,273);
        //life.runLife(40,40);
        //life.runLife(2117,40);


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

        std::ifstream infile("RunLifeFredkin.in");

        int height, width;
        infile >> height;
        infile >> width;
        Life<FredkinCell> life(width, height);
        string str;
        int row = 0, col = 0;
        while(infile >> str){
            //str is a single line of input
            //cout << str << endl;
            col = 0;
            for(int i = 0; i < (int)str.length(); i++){
                char c = str[i];
                if(c != '-'){
                    FredkinCell& c = life.getCell(row, col);
                    c.toggle_life_death(true);
                }
                col++;
            }
            row++;
        }
        //life.displayGrid(cout);
        life.runLife( 5,1, cout,0);
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

        std::ifstream infile("RunLifeCell.in");

        int height, width;
        infile >> height;
        infile >> width;
        Life<Cell> life(width, height);
        string str;
        int index = 0;
        while(infile >> str){
            //str is a single line of input
            //cout << str << endl;
            for(int i = 0; i < (int)str.length(); i++){
                char c = str[i];
                if(c != '-'){
                    Cell& c = life.getCell(index / width, index % width);
                    c.toggle_life_death(true);
                }
            index++;
            }
        }
        //life.displayGrid(cout);
        life.runLife(5,1, cout,0);

        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


        //Begin Acceptance Tests ---------------------------------------------------------------------------------------------------------
        //Test ConwayCell
            //Test 1:
                cout << "Running ConwayCell AcceptanceTest 1" << endl;
                try{
                    Life<ConwayCell> life(0,0);
                    life.getCell(0,0);
                    assert(false);
                }
                catch(const invalid_argument&){assert(false);}
                catch(const out_of_range&){assert(true);}
            //Test 2:
                try{    //Predictable triangle
                    cout << "Running ConwayCell AcceptanceTest 2" << endl;
                    Life<ConwayCell> life(100, 1);
                    for(int i=0; i<100;i++){
                        ConwayCell& c = life.getCell(0,i);
                        c.toggle_life_death(true);
                    }
                    life.runLife(50,5, cout,0);
                    
                }
                catch(const invalid_argument&){assert(false);}
                catch(const out_of_range&){assert(false);}
            //Test 3:
                try{ //Infinite behavior
                    cout << "Running ConwayCell AcceptanceTest 3" << endl;
                    Life<ConwayCell> life(3,3);
                    life.getCell(0,1).toggle_life_death(true);
                    life.getCell(1,1).toggle_life_death(true);
                    life.getCell(2,1).toggle_life_death(true);

                    life.runLife(5,1,cout,0);
                }
                catch(const invalid_argument&){assert(false);}
                catch(const out_of_range&){assert(false);}
            //Test 4:
                try{    //Starvation aka instant kill 
                    cout << "Running ConwayCell AcceptanceTest 4" << endl;
                    Life<ConwayCell> life(10,10);
                    for(int i=0; i<100; i++)
                        life.getCell(i/10, i%10).toggle_life_death(true);
                    life.runLife(2,1,cout,0);

                }
                catch(const invalid_argument&){assert(false);}
                catch(const out_of_range&){assert(false);}
            //Test 5:
                try{ // civilizations live and die but the legend survives
                    cout << "Running ConwayCell AcceptanceTest 5" << endl;
                    Life<ConwayCell> life(10,10);
                    for(int i=0; i<100; i++)
                        life.getCell((i/2/10), (i%10)).toggle_life_death(true);
                    life.runLife(9,1,cout,0);
                }
                catch(const invalid_argument&){assert(false);}
                catch(const out_of_range&){assert(false);}


        //Test FredkinCell
            //Test 1:
                try{    //Starvation aka instant kill version 2
                    cout << "Running FredkinCell AcceptanceTest 1" << endl;
                    Life<FredkinCell> life(3,3);
                    for(int i=0; i<9;i++)
                        life.getCell((i/3), (i%3)).toggle_life_death(true);
                    life.runLife(3,1, cout,0);
                    
                }
                catch(const invalid_argument&){assert(false);}
                catch(const out_of_range&){assert(false);}
            //Test 2:
                try{    //Infinite sliding doors
                    cout << "Running FredkinCell AcceptanceTest 2" << endl;
                    Life<FredkinCell> life(9,3);
                    life.getCell(0,1).toggle_life_death(true);
                    life.getCell(1,1).toggle_life_death(true);
                    life.getCell(2,1).toggle_life_death(true);

                    life.runLife(40,1, cout,0);
                    
                }
                catch(const invalid_argument&){assert(false);}
                catch(const out_of_range&){assert(false);}
            //Test 3:
                try{    //Age to +
                    cout << "Running FredkinCell AcceptanceTest 3" << endl;
                    Life<FredkinCell> life(2,1);
                    life.getCell(0,0).toggle_life_death(true);
                    life.getCell(0,1).toggle_life_death(true);
                    life.runLife(11,1, cout,0);
                }
                catch(const invalid_argument&){assert(false);}
                catch(const out_of_range&){assert(false);}
            //Test 4:
                try{
                    cout << "Running FredkinCell AcceptanceTest 4" << endl;
                    Life<FredkinCell> life(100,10);
                    for(int i=0; i<100; i++)
                        life.getCell(0, i).toggle_life_death(true);
                    life.runLife(30,1, cout,0);
                }
                catch(const invalid_argument&){assert(false);}
                catch(const out_of_range&){assert(false);}
            //Test 5:
                try{        //Stress test
                    cout << "Running FredkinCell AcceptanceTest 5" << endl;
                    Life<FredkinCell> life(200,200);
                    srand(0);
                    for(int i=0; i<50; i++){
                        int myr = rand()%40000;
                        life.getCell(myr/200, myr%200).toggle_life_death(true);
                    }
                    life.runLife(30,5, cout,0);
                }
                catch(const invalid_argument&){assert(false);}
                catch(const out_of_range&){assert(false);}


        //Test Cell
            //Test 1:
                try{    //Transform cells and die
                    cout << "Running Cell AcceptanceTest 1" << endl;
                    Life<Cell> life(2,1);
                    life.getCell(0,0).toggle_life_death(true);
                    life.getCell(0,1).toggle_life_death(true);
                    life.runLife(4,1,cout,0);
                }
                catch(const invalid_argument&){assert(false);}
                catch(const out_of_range&){assert(false);}
            //Test 2:
                try{    //Instakill resurection
                    cout << "Running Cell AcceptanceTest 2" << endl;
                    Life<Cell> life(10,10);
                    for(int i=0; i<100; i++)
                        life.getCell(i/10, i%10).toggle_life_death(true);
                    life.runLife(5,1,cout,0);
                }
                catch(const invalid_argument&){assert(false);}
                catch(const out_of_range&){assert(false);}
            //Test 3:
                try{    //Total death!
                    cout << "Running Cell AcceptanceTest 3" << endl;
                    Life<Cell> life(10,1);
                    life.getCell(0,0).toggle_life_death(true);
                    life.getCell(0,1).toggle_life_death(true);
                    life.runLife(13,2,cout,0);
                }
                catch(const invalid_argument&){assert(false);}
                catch(const out_of_range&){assert(false);}
            //Test 4:
                try{    //Stress Test
                    cout << "Running Cell AcceptanceTest 4" << endl;
                    Life<Cell> life(50, 80);
                    for(int i=0; i<50; i++){
                        int myr = rand()%4000;
                        life.getCell(myr/80, myr%50).toggle_life_death(true);
                    }
                    life.runLife(60,10, cout,0);
                }
                catch(const invalid_argument&){assert(false);}
                catch(const out_of_range&){assert(false);}
            //Test 5:
                try{    //lonliness
                    cout << "Running Cell AcceptanceTest 5" << endl;
                    Life<Cell> life(1,1);
                    life.getCell(0,0).toggle_life_death(true);
                    life.runLife(2,1,cout,0);
                }
                catch(const invalid_argument&){assert(false);}
                catch(const out_of_range&){assert(false);}


        //End Acceptance Tests ---------------------------------------------------------------------------------------------------------
    return 0;}
