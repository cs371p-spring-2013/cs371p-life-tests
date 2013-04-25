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
#include <string>

#include "Life.h"
//#include "AbstractCell.h"
//#include "FredkinCell.h"
//#include "ConwayCell.h"

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    try {
        cout << "*** Life<ConwayCell> 1x1: Doomed to Die ***" << endl;
        Life<ConwayCell, 1, 1> l;
        l.board[0][0] = ConwayCell(0);

        l.print_grid(0);
        for(int i = 0; i < 3; i++) {
            l.simulate_moves(1);
            l.print_grid(i+1);
        }
        
       }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> 5x5: Diag Doom ***" << endl;
        Life<ConwayCell, 5, 5> l;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(i==j) l.board[i][j] = ConwayCell(0);
                else l.board[i][j] = ConwayCell(1);
            }
        }

        l.print_grid(0);
        for(int i = 0; i < 5; i++) {
            l.simulate_moves(1);
            l.print_grid(i+1);
        }
        
       }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    try {
        cout << "*** Life<ConwayCell> 6x7: Forever ***" << endl;
        Life<ConwayCell, 6, 7> l;
        for(int i = 0; i < 7; i++) {
            for(int j = 0; j < 6; j++) {
                l.board[i][j] = ConwayCell(1);
            }
        }
        l.board[2][3].revive();
        l.board[2][4].revive();
        l.board[3][3].revive();
        l.board[3][4].revive();
        

        l.print_grid(0);
        for(int i = 0; i < 50; i++) {
            l.simulate_moves(1);
            if(i%10 == 0) l.print_grid(i+1);
        }
        
       }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    try {
        cout << "*** Life<ConwayCell> 6x6: Baby boom ***" << endl;
        Life<ConwayCell, 6, 6> l;
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 6; j++) {
                if(i == 0 || i == 5 || j == 0 || j == 5)
                      l.board[i][j] = ConwayCell(0);
                else l.board[i][j] = ConwayCell(1);
            }
        }

        l.print_grid(0);
        for(int i = 0; i < 5; i++) {
            l.simulate_moves(1);
            l.print_grid(i+1);
        }
        
       }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


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
        std::string line;        
        Life<ConwayCell, 69, 109> l;
        std::ifstream file("RunLifeConway.in");
        std::getline(file, line);
        std::getline(file, line);
        for(int i = 0; i < 109; i++) {
            std::getline(file, line);
            for(int j = 0; j < 69; j++) {
              if(line[j] == '*') l.board[i][j] = ConwayCell(0);
              else l.board[i][j] = ConwayCell(1);   
            }
        }
        l.print_grid(0);
        
        for(int i = 0; i < 283; i++) {
            l.simulate_moves(1);
            if(i < 10) l.print_grid(i);
        }
        l.print_grid(283);
        for(int i = 0; i < 40; i++) {
            l.simulate_moves(1);
        }
        l.print_grid(323);
        for(int i = 0; i < 2177; i++) {
            l.simulate_moves(1);
        }
        l.print_grid(2500);
       }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 20x20
    // ------------------
    try {
        cout << "*** Life<FredkinCell> 3x1 ***" << endl;
        Life<FredkinCell, 3, 1> l;
        l.board[0][0] = FredkinCell(0, 0);
        l.board[0][1] = FredkinCell(0, 0);
        l.board[0][2] = FredkinCell(1, 0);        

        l.print_grid(0);
        for(int i = 1; i <= 5; i++) {
            l.simulate_moves(1);
            l.print_grid(i);
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> 5x5 forever young***" << endl;
        Life<FredkinCell, 5, 5> l;
       
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                l.board[i][j] = FredkinCell(1, 0);
            }
        }
    
        l.board[0][2].revive();
        l.board[2][0].revive();
        l.board[2][4].revive();
        l.board[4][2].revive();

        l.print_grid(0);
        for(int i = 1; i <= 8; i++) {
            l.simulate_moves(1);
            l.print_grid(i);
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
  
     try {
        cout << "*** Life<FredkinCell> 10x8 ***" << endl;
        Life<FredkinCell, 8, 10> l;
       
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 8; j++) {
                if(j == 4 && (i != 0 && i != 5 && i != 9)) l.board[i][j] = FredkinCell(0, 0);
                else l.board[i][j] = FredkinCell(1, 0);
            }
        }
    
        l.print_grid(0);
        for(int i = 1; i <= 8; i++) {
            l.simulate_moves(1);
            l.print_grid(i);
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
 
     try {
        cout << "*** Life<FredkinCell> 6x6 border ***" << endl;
        Life<FredkinCell, 6, 6> l;
       
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 6; j++) {
                if(j==0 || j==5 || i==0 || i==5) l.board[i][j] = FredkinCell(0, 0);
                else l.board[i][j] = FredkinCell(1, 0);
            }
        }
    
        l.print_grid(0);
        for(int i = 1; i <= 8; i++) {
            l.simulate_moves(1);
            l.print_grid(i);
        }
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}





    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        std::string line;        
        Life<FredkinCell, 20, 20> l;
        std::ifstream file("RunLifeFredkin.in");
        std::getline(file, line);
        std::getline(file, line);
        for(int i = 0; i < 20; i++) {
            std::getline(file, line);
            for(int j = 0; j < 20; j++) {
              if(line[j] == '0') l.board[i][j] = FredkinCell(0, 0);
              else l.board[i][j] = FredkinCell(1, 0);   
            }
        }
        l.print_grid(0);
        for(int i = 1; i <= 5; i++) {
            l.simulate_moves(1);
            l.print_grid(i);
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
        cout << "*** Life<Cell> 10x10 twins ***" << endl;
        Life<Cell, 10, 10> l;
        for(int i = 0; i < 10; i++ ) {
          for(int j = 0; j < 10; j++) {
             l.board[i][j] = new FredkinCell(1, 0);
          }
        }
        l.board[3][2].revive();
        l.board[4][2].revive();
        l.board[5][2].revive();
        l.board[6][2].revive();

 
        l.board[3][7].revive();
        l.board[4][7].revive();
        l.board[5][7].revive();
        l.board[6][7].revive();

        l.print_grid(0);
        for(int i = 0; i < 5; i++) {
            l.simulate_moves(1);
            l.print_grid(i+1);
        }
 
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
   


    try {
        cout << "*** Life<Cell> 10x10 spread ***" << endl;
        Life<Cell, 10, 10> l;
        for(int i = 0; i < 10; i++ ) {
          for(int j = 0; j < 10; j++) {
             l.board[i][j] = new FredkinCell(1, 0);
          }
        }
        l.board[3][2].revive();
        l.board[4][2].revive();

        l.print_grid(0);
        for(int i = 0; i < 5; i++) {
            l.simulate_moves(1);
            l.print_grid(i+1);
        }
 
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
   


    try {
        cout << "*** Life<Cell> 10x8 line down ***" << endl;
        Life<Cell, 8, 10> l;
        for(int i = 0; i < 10; i++ ) {
          for(int j = 0; j < 8; j++) {
             if(j == 4 && i != 0 && i!= 5 && i != 9) l.board[i][j] = new FredkinCell(0, 0);
             else l.board[i][j] = new FredkinCell(1, 0);
          }
        }
        l.print_grid(0);
        for(int i = 0; i < 8; i++) {
            l.simulate_moves(1);
            l.print_grid(i+1);
        }
 
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
   


    try {
        cout << "*** Life<Cell> 6x6 cell border ***" << endl;
        Life<Cell, 6, 6> l;
        for(int i = 0; i < 6; i++ ) {
          for(int j = 0; j < 6; j++) {
             if(i == 0 || j == 0 || i == 5 || j == 5) l.board[i][j] = new FredkinCell(0, 0);
             else l.board[i][j] = new FredkinCell(1, 0);
          }
        }
        l.print_grid(0);
        for(int i = 0; i < 8; i++) {
            l.simulate_moves(1);
            l.print_grid(i+1);
        }
 
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
   




    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        std::string line;        
        Life<Cell, 20, 20> l;
        std::ifstream file("RunLifeCell.in");
        std::getline(file, line);
        std::getline(file, line);
        for(int i = 0; i < 20; i++) {
            std::getline(file, line);
            for(int j = 0; j < 20; j++) {
              if(line[j] == '0') l.board[i][j] = new FredkinCell(0, 0);
              else if (line[j] == '*') l.board[i][j] = new ConwayCell(0);
              else if (line[j] == '.') l.board[i][j] = new ConwayCell(1);
              else l.board[i][j] = new FredkinCell(1, 0);   
            }
        }
        l.print_grid(0);
        for(int i = 1; i <= 5; i++) {
            l.simulate_moves(1);
            l.print_grid(i);
        }
 
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
   

   return 0;
}
