/// -------------------------
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
#include <stdlib.h>   // atoi
#include <fstream> // ifstream
#include <typeinfo>

#include "Life.h"
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"

vector<vector<AbstractCell*> > board;

template <typename T>
Life<T> read_default (int sig) {
    int r, c;
    int cur_row = 0;
    int cur_col = 0;
    string str;
    char _char;
    char dead;
    
    bool is_conway = false;
    bool is_fredkin = false;

    if (sig == 1)
    {
         Life <T> test(20,20, false);
         test.make_board(20,20);
         return test;
    }
      
    T cell(false, false);
    dead = cell.cell_name();

    if (dead == '.')
    {
        str = "RunLifeConway.in";
        is_conway = true;
    }
    else
    {    
        str = "RunLifeFredkin.in";
        is_fredkin = true;
    }
    
    ifstream myfile (str);

    if (myfile.is_open())
    {
        getline (myfile, str);
        r = atoi(str.c_str()); 

        getline (myfile, str);
        c = atoi(str.c_str()); 

        Life<T> life(r,c, false);
        life.make_board(r,c);

        while ( myfile.good() )
        {
            _char = myfile.get();

            if (is_conway) // if conway
            {   
                // switch A
                switch ( _char )
                {
                     case '*':
                        life.add(1, cur_row, cur_col);
                         break;
                     case '.':
                         break;
                     default:
                         cur_col = -1;
                         ++cur_row;
                }
            } 
            else // if not
            {
                // swtich B
                switch ( _char )
                {
                    case '\n':
                        cur_col = -1;
                        ++cur_row;
                        break;
                    case '-':
                        break;
                    case '0':
                        life.add(1, cur_row, cur_col);
                        break;                                        
                    default:
                        break;
                }
            }
            ++cur_col;
        }            
        myfile.close();
        cout << endl;
        return life;
    }
    else 
    {
        cout << "Unable to open file"; 
        Life<T> nothing(4,4, false);
        return nothing;
    }
}


// template <typename T>
// Life<T> read (int sig) {
//     int r, c;
//     int cur_row = 0;
//     int cur_col = 0;
//     string str;
//     char _char;
    
//     cout << "HIHIHIHIHIH" << endl;

//     if (sig == 1)
//     {
//          Life <FredkinCell> test(20,20, false);
//          test.make_board(20,20);
//          return test;
//     }
      
//     str = "RunLifeCell.in";

    
//     ifstream myfile (str);

//     if (myfile.is_open())
//     {
//         getline (myfile, str);
//         r = atoi(str.c_str()); 

//         getline (myfile, str);
//         c = atoi(str.c_str()); 

//         Life<FredkinCell> life(r,c, true);
//         life.make_board(r,c);

//         while ( myfile.good() )
//         {
//             _char = myfile.get();

//             // swtich B
//             switch ( _char )
//             {
//                 case '\n':
//                     cur_col = -1;
//                     ++cur_row;
//                     break;
//                 case '-':
//                     break;
//                 case '0':
//                     life.add(1, cur_row, cur_col);
//                     break;                                        
//                 default:
//                     break;
//             }
            
//             ++cur_col;
//         }            
//         myfile.close();
//         cout << endl;

//         // AbstractCell* ptr = &life;
//         Cell cell = life;
//         return cell;
//     }
//     else 
//     {
//         cout << "Unable to open file"; 
//         Life<T> nothing(4,4, false);
//         return nothing;
//     }
// }


// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O


    // ------------------
    // Conway Cell 20x20
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 20x20 ***" << endl;
        /*
        read RunLifeConway.in // assume all Conway cells
        Simulate 10 moves.
        Print the first 10 grids (i.e. 0, 1, 2...9).
        */
        
        // code
        // 0 = read default default 
        // 1 = do NOT read. reaturn 20x20 grid
        Life<ConwayCell> have_life = read_default<ConwayCell>(1);
        have_life.add(1, 0, 0);
        have_life.add(1, 0, 1);
        have_life.add(1, 0, 2);
        have_life.add(1, 1, 0);
        have_life.add(1, 1, 1);

        // To turn off the flag
        //set print_till = 0
        //set print_on = -1
        have_life.start(5, 5, -1);
        cout << ""<< endl;

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

        // code
        // 0 = read default default 
        // 1 = do NOT read. reaturn 20x20 grid
        Life<ConwayCell> have_life = read_default<ConwayCell>(0);
        have_life.start(283, 10, 283);
        have_life.start(40, 0, 40);
        have_life.start(2177, 0, 2500);
        cout << ""<< endl;
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
        
        // code
        // 0 = read default default 
        // 1 = do NOT read. reaturn 20x20 grid
        Life<FredkinCell> have_life = read_default<FredkinCell>(0);
        have_life.start(5, 5, -1);
        cout << ""<< endl;
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
        // Life<Cell> have_life = read<FredkinCell>(0);
        // cout << ""<< endl;
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
