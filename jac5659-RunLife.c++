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
#include <sstream>   // istringstream
#include <fstream>
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Life.h"
#include "Cell.h"
// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    // ------------------
    // Conway Cell 109x69
    // ------------------
    ConwayCell c_alive(1);
    ConwayCell c_dead(0);
    FredkinCell f_alive(1);
    FredkinCell f_dead(0);
    Cell c_cell_alive = new ConwayCell(1);
    Cell c_cell_dead = new ConwayCell(0);
    Cell f_cell_alive = new FredkinCell(1);
    Cell f_cell_dead = new FredkinCell(0);
    try {
        cout << "*** Life<ConwayCell> 109x69 ***\n" << endl;
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
        int row, col;
        ifstream my_file;
        my_file.open("RunLifeConway.in");
        my_file >> row >> col;
        Life<ConwayCell> game(row,col);
        char character;
        my_file >> skipws;
        for(int r = 0; r < row; ++r){
            for(int c = 0; c < col; ++c){
                my_file >> character;
                if(character == '.')
                    game.add_cell(r,c,c_dead);
                else if(character == '*')
                    game.add_cell(r,c,c_alive);
            }
        }
        game.print_grid();
        for(int i = 1; i <= 2500; ++i){
            game.evolve();
            if(i < 10 || i == 283 || i == 323 || i == 2500)
                game.print_grid();
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
        cout << "*** Life<FredkinCell> 20x20 ***\n" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        int row, col;
        ifstream my_file;
        my_file.open("RunLifeFredkin.in");
        my_file >> row >> col;
        Life<FredkinCell> game(row,col);
        char character;
        my_file >> skipws;
        for(int r = 0; r < row; ++r){
            for(int c = 0; c < col; ++c){
                my_file >> character;
                if(character == '-')
                    game.add_cell(r,c,f_dead);
                else if(character == '0')
                    game.add_cell(r,c,f_alive);
            }
        }
        game.print_grid();
        for(int i = 1; i <= 5; ++i){
            game.evolve();
            game.print_grid();
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
        cout << "*** Life<Cell> 20x20 ***\n" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        int row, col;
        ifstream my_file;
        my_file.open("RunLifeCell.in");
        my_file >> row >> col;
        Life<Cell> game(row,col);
        char character;
        my_file >> skipws;
        for(int r = 0; r < row; ++r){
            for(int c = 0; c < col; ++c){
                my_file >> character;
                if(character == '-')
                    game.add_cell(r,c,f_cell_dead);
                else if(character == '0')
                    game.add_cell(r,c,f_cell_alive);
            }
        }
        game.print_grid();
        for(int i = 1; i <= 5; ++i){
            game.evolve();
            game.print_grid();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    //Test 1-Conway
    //Conway Cell, 1 live cell
    try 
    {
        cout << "*** Life<ConwayCell> 1x1 ***\n" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        int row, col;
        string input = "1\n1\n*\n";
        istringstream my_file(input);
        my_file >> row >> col;
        Life<ConwayCell> game(row,col);
        char character;
        my_file >> skipws;
        for(int r = 0; r < row; ++r)
        {
            for(int c = 0; c < col; ++c)
            {
                my_file >> character;
                if(character == '*')
                    game.add_cell(r,c,c_alive);
                else if(character == '.')
                    game.add_cell(r,c,c_dead);
            }
        }
        game.print_grid();
        for(int i = 1; i <= 2; ++i)
        {
            game.evolve();
            game.print_grid();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    //Test 2-Conway
    //Conway Cell, 1 flipper
    try 
    {
        cout << "*** Life<ConwayCell> 3x3 ***\n" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        int row, col;
        string input =  "3\n" 
                        "3\n"
                        ".*.\n"
                        ".*.\n"
                        ".*.\n";
        istringstream my_file(input);
        my_file >> row >> col;
        Life<ConwayCell> game(row,col);
        char character;
        my_file >> skipws;
        for(int r = 0; r < row; ++r)
        {
            for(int c = 0; c < col; ++c)
            {
                my_file >> character;
                if(character == '*')
                    game.add_cell(r,c,c_alive);
                else if(character == '.')
                    game.add_cell(r,c,c_dead);
            }
        }
        game.print_grid();
        for(int i = 1; i <= 5; ++i)
        {
            game.evolve();
            game.print_grid();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    //Test 3-Conway
    //Conway Cell, neighbors
    try 
    {
        cout << "*** Life<ConwayCell> 3x4 ***\n" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        int row, col;
        string input =  "3\n" 
                        "4\n"
                        "....\n"
                        ".**.\n"
                        "....\n";
        istringstream my_file(input);
        my_file >> row >> col;
        Life<ConwayCell> game(row,col);
        char character;
        my_file >> skipws;
        for(int r = 0; r < row; ++r)
        {
            for(int c = 0; c < col; ++c)
            {
                my_file >> character;
                if(character == '*')
                    game.add_cell(r,c,c_alive);
                else if(character == '.')
                    game.add_cell(r,c,c_dead);
            }
        }
        game.print_grid();
        for(int i = 1; i <= 2; ++i)
        {
            game.evolve();
            game.print_grid();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    //Test 4-Conway
    //Conway Cell, an x
    try 
    {
        cout << "*** Life<ConwayCell> 4x4 ***\n" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        int row, col;
        string input =  "4\n" 
                        "4\n"
                        "*..*\n"
                        ".**.\n"
                        ".**.\n"
                        "*..*\n";
        istringstream my_file(input);
        my_file >> row >> col;
        Life<ConwayCell> game(row,col);
        char character;
        my_file >> skipws;
        for(int r = 0; r < row; ++r)
        {
            for(int c = 0; c < col; ++c)
            {
                my_file >> character;
                if(character == '*')
                    game.add_cell(r,c,c_alive);
                else if(character == '.')
                    game.add_cell(r,c,c_dead);
            }
        }
        game.print_grid();
        for(int i = 1; i <= 2; ++i)
        {
            game.evolve();
            game.print_grid();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    //Test 1-Fredkin
    //Fredkin Cell, 1 live cell
    try 
    {
        cout << "*** Life<FredkinCell> 1x1 ***\n" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        int row, col;
        string input = "1\n1\n0\n";
        istringstream my_file(input);
        my_file >> row >> col;
        Life<FredkinCell> game(row,col);
        char character;
        my_file >> skipws;
        for(int r = 0; r < row; ++r)
        {
            for(int c = 0; c < col; ++c)
            {
                my_file >> character;
                if(character == '0')
                    game.add_cell(r,c,f_alive);
                else if(character == '-')
                    game.add_cell(r,c,f_dead);
            }
        }
        game.print_grid();
        for(int i = 1; i <= 3; ++i)
        {
            game.evolve();
            game.print_grid();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    //Test 2-Fredkin
    //Fredkin Cell, Generic grid
    try 
    {
        cout << "*** Life<FredkinCell> 5x5 ***\n" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        int row, col;
        string input =  "5\n"
                        "5\n"
                        "-0-0-\n"
                        "0-0-0\n"
                        "-0-0-\n"
                        "0-0-0\n"
                        "-0-0-\n";
        istringstream my_file(input);
        my_file >> row >> col;
        Life<FredkinCell> game(row,col);
        char character;
        my_file >> skipws;
        for(int r = 0; r < row; ++r)
        {
            for(int c = 0; c < col; ++c)
            {
                my_file >> character;
                if(character == '0')
                    game.add_cell(r,c,f_alive);
                else if(character == '-')
                    game.add_cell(r,c,f_dead);
            }
        }
        game.print_grid();
        for(int i = 1; i <= 3; ++i)
        {
            game.evolve();
            game.print_grid();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    //Test 3-Fredkin
    //Fredkin Cell, Neighbors
    try 
    {
        cout << "*** Life<FredkinCell> 3x4 ***\n" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        int row, col;
        string input =  "3\n"
                        "4\n"
                        "----\n"
                        "-00-\n"
                        "----\n";
        istringstream my_file(input);
        my_file >> row >> col;
        Life<FredkinCell> game(row,col);
        char character;
        my_file >> skipws;
        for(int r = 0; r < row; ++r)
        {
            for(int c = 0; c < col; ++c)
            {
                my_file >> character;
                if(character == '0')
                    game.add_cell(r,c,f_alive);
                else if(character == '-')
                    game.add_cell(r,c,f_dead);
            }
        }
        game.print_grid();
        for(int i = 1; i <= 100; ++i)
        {
            game.evolve();
            if (i % 10 == 0)
                game.print_grid();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    //Test 4-Fredkin
    //Fredkin Cell, Neighbors
    try 
    {
        cout << "*** Life<FredkinCell> 10x10 ***\n" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        int row, col;
        string input =  "10\n"
                        "10\n"
                        "-00-0---00\n"
                        "-00-0---00\n"
                        "-00-0---00\n"
                        "-00-0---00\n"
                        "-00-0---00\n"
                        "-00-0---00\n"
                        "-00-0---00\n"
                        "-00-0---00\n"
                        "-00-0---00\n"
                        "-00-0---00\n";
        istringstream my_file(input);
        my_file >> row >> col;
        Life<FredkinCell> game(row,col);
        char character;
        my_file >> skipws;
        for(int r = 0; r < row; ++r)
        {
            for(int c = 0; c < col; ++c)
            {
                my_file >> character;
                if(character == '0')
                    game.add_cell(r,c,f_alive);
                else if(character == '-')
                    game.add_cell(r,c,f_dead);
            }
        }
        game.print_grid();
        for(int i = 1; i <= 10; ++i)
        {
            game.evolve();
            if (i % 1 == 0)
                game.print_grid();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    //Test 1-Cell
    //Cell, Fredkin Change
    try 
    {
        cout << "*** Life<Cell> 10x10 ***\n" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        int row, col;
        string input =  "10\n"
                        "10\n"
                        "-00-0---00\n"
                        "-00-0---00\n"
                        "-00-0---00\n"
                        "-00-0---00\n"
                        "-00-0---00\n"
                        "-00-0---00\n"
                        "-00-0---00\n"
                        "-00-0---00\n"
                        "-00-0---00\n"
                        "-00-0---00\n";
        istringstream my_file(input);
        my_file >> row >> col;
        Life<Cell> game(row,col);
        char character;
        my_file >> skipws;
        for(int r = 0; r < row; ++r)
        {
            for(int c = 0; c < col; ++c)
            {
                my_file >> character;
                if(character == '0')
                    game.add_cell(r,c,f_cell_alive);
                else if(character == '-')
                    game.add_cell(r,c,f_cell_dead);
            }
        }
        game.print_grid();
        for(int i = 1; i <= 5; ++i)
        {
            game.evolve();
            game.print_grid();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    //Test 2-Cell
    //Cell, 1 Cell
    try 
    {
        cout << "*** Life<Cell> 1x1 ***\n" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        int row, col;
        string input =  "1\n"
                        "1\n"
                        "0\n";
        istringstream my_file(input);
        my_file >> row >> col;
        Life<Cell> game(row,col);
        char character;
        my_file >> skipws;
        for(int r = 0; r < row; ++r)
        {
            for(int c = 0; c < col; ++c)
            {
                my_file >> character;
                if(character == '0')
                    game.add_cell(r,c,f_cell_alive);
                else if(character == '-')
                    game.add_cell(r,c,f_cell_dead);
            }
        }
        game.print_grid();
        for(int i = 1; i <= 3; ++i)
        {
            game.evolve();
            game.print_grid();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    //Test 3-Cell
    //Cell, Input includes both
    try 
    {
        cout << "*** Life<Cell> 9x9 ***\n" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        int row, col;
        string input =  "9\n"
                        "9\n"
                        "-00-*-.-0\n"
                        "-00-*-*-0\n"
                        "-00-*-.-0\n"
                        "-00-.-*-0\n"
                        "-00-*-.-0\n"
                        "-00-*-*-0\n"
                        "-00-*-.-0\n"
                        "-00-.-*-0\n"
                        "-00-*-.-0\n";
        istringstream my_file(input);
        my_file >> row >> col;
        Life<Cell> game(row,col);
        char character;
        my_file >> skipws;
        for(int r = 0; r < row; ++r)
        {
            for(int c = 0; c < col; ++c)
            {
                my_file >> character;
                if(character == '0')
                    game.add_cell(r,c,f_cell_alive);
                else if(character == '-')
                    game.add_cell(r,c,f_cell_dead);
                else if(character == '*')
                    game.add_cell(r,c,c_cell_alive);
                else if(character == '.')
                    game.add_cell(r,c,c_cell_dead);
            }
        }
        game.print_grid();
        for(int i = 1; i <= 5; ++i)
        {
            game.evolve();
            game.print_grid();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    //Test 4-Cell
    //Cell, Glider Gun
    try
    {
        cout << "*** Life<Cell> 9x36 ***\n" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        int row, col;
        string input =  "24\n"
                        "38\n"
                        "......................................\n"
                        ".........................*............\n"
                        ".......................*.*............\n"
                        ".............**......**............**.\n"
                        "............*...*....**............**.\n"
                        ".**........*.....*...**...............\n"
                        ".**........*...*.**....*.*............\n"
                        "...........*.....*.......*............\n"
                        "............*...*.....................\n"
                        ".............**.......................\n"
                        "......................................\n"
                        "......................................\n"
                        "......................................\n"
                        "......................................\n"
                        "......................................\n"
                        "......................................\n"
                        "......................................\n"
                        "......................................\n"
                        "......................................\n"
                        "......................................\n"
                        "......................................\n"
                        "......................................\n"
                        "......................................\n"
                        "......................................\n";
        istringstream my_file(input);
        my_file >> row >> col;
        Life<Cell> game(row,col);
        char character;
        my_file >> skipws;
        for(int r = 0; r < row; ++r)
        {
            for(int c = 0; c < col; ++c)
            {
                my_file >> character;
                if(character == '0')
                    game.add_cell(r,c,f_cell_alive);
                else if(character == '-')
                    game.add_cell(r,c,f_cell_dead);
                else if(character == '*')
                    game.add_cell(r,c,c_cell_alive);
                else if(character == '.')
                    game.add_cell(r,c,c_cell_dead);
            }
        }
        game.print_grid();
        for(int i = 1; i <= 30; ++i)
        {
            game.evolve();
            game.print_grid();
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
