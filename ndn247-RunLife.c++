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
#include <fstream>   // ifstream
#include <sstream>   // istringstream
#include <string>    
#include <stdexcept> // invalid_argument, out_of_range
#include <utility>   // std::pair, std::make_pair
#include <map>   

#include "Life.h"
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"


using namespace std;

int read_int(ifstream& filereader) {
    string line;
    int i;
    getline(filereader, line);
    istringstream stringreader(line);
    stringreader >> i;
    return i;
}


ConwayCell create_conwaycell(char c) {
    switch(c) {
        case '.':
            return ConwayCell(false);
        case '*':
            return ConwayCell(true);                  
    }
    return ConwayCell();
}

FredkinCell create_fredkincell(char c) {
    switch(c) {
        case '-':
            return FredkinCell(false);
        case '0':
            return FredkinCell(true);                  
    }
    return FredkinCell();
}

Cell create_cell(char c) {
    switch(c) {
        case '.':
            return Cell(new ConwayCell(false));
        case '*':
            return Cell(new ConwayCell(true));
        case '-':
            return Cell(new FredkinCell(false));
        case '0':
            return Cell(new FredkinCell(true));
    }
    return Cell(new ConwayCell());
}

template<typename T>
void display_round(map< pair<int,int>, T> grid, int generation, int m, int n) {
    int population = 0;
    for (typename map<pair<int,int>, T>::iterator iter = grid.begin(); iter != grid.end(); iter++) {
        if(iter->second.is_alive()) { ++population; }
    }
    cout << "Generation = " << generation << ", " << "Population = " << population << "." << endl;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout << grid[make_pair(i,j)].toString();
        }
        cout << endl;
    } 
    cout << endl;
}

// ----
// main
// ----

int main () {
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    ifstream filereader;
    
    // ------------------
    // Conway Cell 109x69
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 109x69 ***" << endl << endl;
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

        // read input grid
        int generation = 0;
        filereader.open("RunLifeConway.in");
        int m = read_int(filereader);
        int n = read_int(filereader);
        map<pair<int,int>, ConwayCell> grid;

        string line;
        for(int i=0; i<m; i++) {
            getline(filereader, line);
            istringstream stringreader(line);
            char c;
            for(int j=0; j<n; j++) {
                stringreader >> c;
                grid.insert(make_pair(make_pair(i,j), create_conwaycell(c)));            }
        }
        filereader.close();

        // play game
        Life<ConwayCell> game(grid);
        for(int i=0; i<10; i++) {
            display_round(game.get_grid(), generation, m, n);
            game.play_round();
            ++generation;
        }
        for(int i=10; i<283; i++) {
            game.play_round();
            ++generation;
        }
        display_round(game.get_grid(), generation, m, n);
        for(int i=283; i<323; i++) {
            game.play_round();
            ++generation;
        }
        display_round(game.get_grid(), generation, m, n);
        for(int i=323; i<2500; i++) {
            game.play_round();
            ++generation;
        }
        display_round(game.get_grid(), generation, m, n);

    } catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

        // read input grid
        int generation = 0;
        filereader.open("RunLifeFredkin.in");
        int m = read_int(filereader);
        int n = read_int(filereader);
        map<pair<int,int>, FredkinCell> grid;

        string line;
        for(int i=0; i<m; i++) {
            getline(filereader, line);
            istringstream stringreader(line);
            char c;
            for(int j=0; j<n; j++) {
                stringreader >> c;
               grid.insert(make_pair(make_pair(i,j), create_fredkincell(c)));
            }
        }
        filereader.close();

        // play game
        Life<FredkinCell> game(grid);
        for(int i=0; i<5; i++) {
            display_round(game.get_grid(), generation, m, n);
            game.play_round();
            ++generation;
        }
        display_round(game.get_grid(), generation, m, n);

    } catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 20x20
    // ----------

    try {
        cout << "*** Life<Cell> 20x20 ***" << endl << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

        // read input grid
        int generation = 0;
        filereader.open("RunLifeCell.in");
        int m = read_int(filereader);
        int n = read_int(filereader);
        map<pair<int,int>, Cell> grid;

        string line;
        for(int i=0; i<m; i++) {
            getline(filereader, line);
            istringstream stringreader(line);
            char c;
            for(int j=0; j<n; j++) {
                stringreader >> c;
                grid.insert(make_pair(make_pair(i,j), create_cell(c)));
            }
        }
        filereader.close();

        // play game
        Life<Cell> game(grid);
        for(int i=0; i<5; i++) {
            display_round(game.get_grid(), generation, m, n);
            game.play_round();
            ++generation;
        }
        display_round(game.get_grid(), generation, m, n);

    } catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> 10x10 (Glider) ***" << endl << endl;

        // read input grid
        int generation = 0;
        string str_grid = "..........\n..*.......\n...*......\n.***......\n..........\n..........\n..........\n..........\n..........\n..........\n";
        istringstream gridreader(str_grid);
        int m = 10;
        int n = 10;
        map<pair<int,int>, ConwayCell> grid;

        string line;
        for(int i=0; i<m; i++) {
            getline(gridreader, line);
            istringstream stringreader(line);
            char c;
            for(int j=0; j<n; j++) {
                stringreader >> c;
                grid.insert(make_pair(make_pair(i,j), create_conwaycell(c)));
            }
        }

        // play game
        Life<ConwayCell> game(grid);
        for(int i=0; i<10; i++) {
            display_round(game.get_grid(), generation, m, n);
            game.play_round();
            ++generation;
        }
        display_round(game.get_grid(), generation, m, n);

    } catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> 2x2 ***" << endl << endl;

        // read input grid
        int generation = 0;
        string str_grid = "*.\n..\n";
        istringstream gridreader(str_grid);
        int m = 2;
        int n = 2;
        map<pair<int,int>, ConwayCell> grid;

        string line;
        for(int i=0; i<m; i++) {
            getline(gridreader, line);
            istringstream stringreader(line);
            char c;
            for(int j=0; j<n; j++) {
                stringreader >> c;
                grid.insert(make_pair(make_pair(i,j), create_conwaycell(c)));
            }
        }

        // play game
        Life<ConwayCell> game(grid);
        for(int i=0; i<5; i++) {
            display_round(game.get_grid(), generation, m, n);
            game.play_round();
            ++generation;
        }
        display_round(game.get_grid(), generation, m, n);

    } catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> 30x30 ***" << endl << endl;

        // read input grid
        int generation = 0;
        string str_grid = "..............................\n..............................\n..............................\n..............................\n..............................\n..............................\n..............................\n..............................\n..............................\n..............................\n..............................\n..............................\n..............................\n..............................\n...............*..............\n..............***.............\n..............*.*.............\n...............*..............\n..............................\n..............................\n..............................\n..............................\n..............................\n..............................\n..............................\n..............................\n..............................\n..............................\n..............................\n..............................\n";
        istringstream gridreader(str_grid);
        int m = 30;
        int n = 30;
        map<pair<int,int>, ConwayCell> grid;

        string line;
        for(int i=0; i<m; i++) {
            getline(gridreader, line);
            istringstream stringreader(line);
            char c;
            for(int j=0; j<n; j++) {
                stringreader >> c;
                grid.insert(make_pair(make_pair(i,j), create_conwaycell(c)));
            }
        }

        // play game
        Life<ConwayCell> game(grid);
        for(int j=0; j<3; j++) {
            display_round(game.get_grid(), generation, m, n);
            for(int i=0; i<10; i++) {
                game.play_round();
                ++generation;
            }
        }
        display_round(game.get_grid(), generation, m, n);

    } catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> 22x53 (Gosper Glider Gun) ***" << endl << endl;

        // read input grid
        int generation = 0;
        string str_grid = ".....................................................\n........................*............................\n......................*.*............................\n............**......**............**.................\n...........*...*....**............**.................\n**........*.....*...**...............................\n**........*...*.**....*.*............................\n..........*.....*.......*............................\n...........*...*.....................................\n............**.......................................\n.....................................................\n.....................................................\n.....................................................\n.....................................................\n.....................................................\n.....................................................\n.....................................................\n.....................................................\n.....................................................\n.....................................................\n.....................................................\n.....................................................\n";
        istringstream gridreader(str_grid);
        int m = 22;
        int n = 53;
        map<pair<int,int>, ConwayCell> grid;

        string line;
        for(int i=0; i<m; i++) {
            getline(gridreader, line);
            istringstream stringreader(line);
            char c;
            for(int j=0; j<n; j++) {
                stringreader >> c;
                grid.insert(make_pair(make_pair(i,j), create_conwaycell(c)));
            }
        }

        // play game
        Life<ConwayCell> game(grid);
        for(int i=0; i<60; i++) {
            display_round(game.get_grid(), generation, m, n);
            game.play_round();
            ++generation;
        }
        display_round(game.get_grid(), generation, m, n);

    } catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<ConwayCell> 20x20 ***" << endl << endl;

        // read input grid
        int generation = 0;
        string str_grid = "*.*.*.*.*...........\n*.*.*.*.*...........\n*.*.*.*.*...........\n*.*.*.*.*...........\n*.*.*.*.*...........\n*.*.*.*.*...........\n*.*.*.*.*...........\n*.*.*.*.*...........\n*.*.*.*.*...........\n*.*.*.*.*...........\n*.*.*.*.*...........\n*.*.*.*.*...........\n*.*.*.*.*...........\n*.*.*.*.*...........\n*.*.*.*.*...........\n*.*.*.*.*...........\n*.*.*.*.*...........\n*.*.*.*.*...........\n*.*.*.*.*...........\n*.*.*.*.*...........\n";
        istringstream gridreader(str_grid);
        int m = 20;
        int n = 20;
        map<pair<int,int>, ConwayCell> grid;

        string line;
        for(int i=0; i<m; i++) {
            getline(gridreader, line);
            istringstream stringreader(line);
            char c;
            for(int j=0; j<n; j++) {
                stringreader >> c;
                grid.insert(make_pair(make_pair(i,j), create_conwaycell(c)));
            }
        }

        // play game
        Life<ConwayCell> game(grid);
        for(int i=0; i<8; i++) {
            display_round(game.get_grid(), generation, m, n);
            game.play_round();
            ++generation;
        }
        display_round(game.get_grid(), generation, m, n);

    } catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> 5x5 ***" << endl << endl;

        // read input grid
        int generation = 0;
        string str_grid = "00000\n00000\n00000\n00000\n00000\n";
        istringstream gridreader(str_grid);
        int m = 5;
        int n = 5;
        map<pair<int,int>, FredkinCell> grid;

        string line;
        for(int i=0; i<m; i++) {
            getline(gridreader, line);
            istringstream stringreader(line);
            char c;
            for(int j=0; j<n; j++) {
                stringreader >> c;
                grid.insert(make_pair(make_pair(i,j), create_fredkincell(c)));
            }
        }

        // play game
        Life<FredkinCell> game(grid);
        for(int i=0; i<5; i++) {
            display_round(game.get_grid(), generation, m, n);
            game.play_round();
            ++generation;
        }
        display_round(game.get_grid(), generation, m, n);

    } catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    try {
        cout << "*** Life<FredkinCell> 10x7 ***" << endl << endl;

        // read input grid
        int generation = 0;
        string str_grid = "000----\n--0-0-0\n-00-0-0\n0-0-0--\n--00-0-\n-0-0-0-\n0--00--\n00-0-0-\n0-0--0-\n-0--0--\n";
        istringstream gridreader(str_grid);
        int m = 10;
        int n = 7;
        map<pair<int,int>, FredkinCell> grid;

        string line;
        for(int i=0; i<m; i++) {
            getline(gridreader, line);
            istringstream stringreader(line);
            char c;
            for(int j=0; j<n; j++) {
                stringreader >> c;
                grid.insert(make_pair(make_pair(i,j), create_fredkincell(c)));
            }
        }

        // play game
        Life<FredkinCell> game(grid);
        for(int i=0; i<20; i++) {
            display_round(game.get_grid(), generation, m, n);
            game.play_round();
            ++generation;
        }
        display_round(game.get_grid(), generation, m, n);

    } catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    try {
        cout << "*** Life<FredkinCell> 3x3 ***" << endl << endl;

        // read input grid
        int generation = 0;
        string str_grid = "-0-\n000\n-0-\n";
        istringstream gridreader(str_grid);
        int m = 3;
        int n = 3;
        map<pair<int,int>, FredkinCell> grid;

        string line;
        for(int i=0; i<m; i++) {
            getline(gridreader, line);
            istringstream stringreader(line);
            char c;
            for(int j=0; j<n; j++) {
                stringreader >> c;
                grid.insert(make_pair(make_pair(i,j), create_fredkincell(c)));
            }
        }

        // play game
        Life<FredkinCell> game(grid);
        for(int i=0; i<5; i++) {
            display_round(game.get_grid(), generation, m, n);
            game.play_round();
            ++generation;
        }
        display_round(game.get_grid(), generation, m, n);

    } catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}       


    try {
        cout << "*** Life<FredkinCell> 25x25 ***" << endl << endl;

        // read input grid
        int generation = 0;
        string str_grid = "--0----------------------\n---0---------------------\n-000---------------------\n-------------------------\n-------------------------\n-------------------------\n-------------------------\n-------------------------\n-------------------------\n-------------------------\n-------------------------\n-------------------------\n-------------------------\n-------------------------\n-------------------------\n-------------------------\n-------------------------\n-------------------------\n-------------------------\n-------------------------\n-------------------------\n-------------------------\n-------------------------\n-------------------------\n-------------------------\n";
        istringstream gridreader(str_grid);
        int m = 25;
        int n = 25;
        map<pair<int,int>, FredkinCell> grid;

        string line;
        for(int i=0; i<m; i++) {
            getline(gridreader, line);
            istringstream stringreader(line);
            char c;
            for(int j=0; j<n; j++) {
                stringreader >> c;
                grid.insert(make_pair(make_pair(i,j), create_fredkincell(c)));
            }
        }

        // play game
        Life<FredkinCell> game(grid);
        for(int i=0; i<50; i++) {
            display_round(game.get_grid(), generation, m, n);
            game.play_round();
            ++generation;
        }
        display_round(game.get_grid(), generation, m, n);

    } catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);} 

   try {
        cout << "*** Life<FredkinCell> 9x9 ***" << endl << endl;
        /*
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */

        // read input grid
        int generation = 0;
        string str_grid = "---------\n---------\n---------\n---------\n----0----\n---------\n---------\n---------\n---------\n";
        istringstream gridreader(str_grid);
        int m = 9;
        int n = 9;
        map<pair<int,int>, FredkinCell> grid;

        string line;
        for(int i=0; i<m; i++) {
            getline(gridreader, line);
            istringstream stringreader(line);
            char c;
            for(int j=0; j<n; j++) {
                stringreader >> c;
                grid.insert(make_pair(make_pair(i,j), create_fredkincell(c)));
            }
        }

        // play game
        Life<FredkinCell> game(grid);
        for(int i=0; i<19; i++) {
            display_round(game.get_grid(), generation, m, n);
            game.play_round();
            ++generation;
        }
        display_round(game.get_grid(), generation, m, n);

    } catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);} 

   try {
        cout << "*** Life<FredkinCell> 1x1 ***" << endl << endl;

        // read input grid
        int generation = 0;
        string str_grid = "0";
        istringstream gridreader(str_grid);
        int m = 1;
        int n = 1;
        map<pair<int,int>, FredkinCell> grid;

        string line;
        for(int i=0; i<m; i++) {
            getline(gridreader, line);
            istringstream stringreader(line);
            char c;
            for(int j=0; j<n; j++) {
                stringreader >> c;
                grid.insert(make_pair(make_pair(i,j), create_fredkincell(c)));
            }
        }

        // play game
        Life<FredkinCell> game(grid);
        for(int i=0; i<4; i++) {
            display_round(game.get_grid(), generation, m, n);
            game.play_round();
            ++generation;
        }
        display_round(game.get_grid(), generation, m, n);

    } catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);} 

   try {
        cout << "*** Life<Cell> 2x5 ***" << endl << endl;

        // read input grid
        int generation = 0;
        string str_grid = "0--00\n0---0\n";
        istringstream gridreader(str_grid);
        int m = 2;
        int n = 5;
        map<pair<int,int>, Cell> grid;

        string line;
        for(int i=0; i<m; i++) {
            getline(gridreader, line);
            istringstream stringreader(line);
            char c;
            for(int j=0; j<n; j++) {
                stringreader >> c;
                grid.insert(make_pair(make_pair(i,j), create_cell(c)));
            }
        }

        // play game
        Life<Cell> game(grid);
        for(int i=0; i<5; i++) {
            display_round(game.get_grid(), generation, m, n);
            game.play_round();
            ++generation;
        }
        display_round(game.get_grid(), generation, m, n);

    } catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);} 


   try {
        cout << "*** Life<Cell> 10x30 ***" << endl << endl;

        // read input grid
        int generation = 0;
        string str_grid = "------------------------------\n------------------------------\n------------------------------\n------------------------------\n-0000-------------------------\n0---0-------------------------\n----0-------------------------\n0--0--------------------------\n------------------------------\n------------------------------\n";
        istringstream gridreader(str_grid);
        int m = 10;
        int n = 30;
        map<pair<int,int>, Cell> grid;

        string line;
        for(int i=0; i<m; i++) {
            getline(gridreader, line);
            istringstream stringreader(line);
            char c;
            for(int j=0; j<n; j++) {
                stringreader >> c;
                grid.insert(make_pair(make_pair(i,j), create_cell(c)));
            }
        }

        // play game
        Life<Cell> game(grid);
        for(int i=0; i<15; i++) {
            display_round(game.get_grid(), generation, m, n);
            game.play_round();
            ++generation;
        }
        display_round(game.get_grid(), generation, m, n);

    } catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


   try {
        cout << "*** Life<Cell> 5x2 ***" << endl << endl;

        // read input grid
        int generation = 0;
        string str_grid = "00\n00\n00\n00\n00\n";
        istringstream gridreader(str_grid);
        int m = 5;
        int n = 2;
        map<pair<int,int>, Cell> grid;

        string line;
        for(int i=0; i<m; i++) {
            getline(gridreader, line);
            istringstream stringreader(line);
            char c;
            for(int j=0; j<n; j++) {
                stringreader >> c;
                grid.insert(make_pair(make_pair(i,j), create_cell(c)));
            }
        }

        // play game
        Life<Cell> game(grid);
        for(int i=0; i<8; i++) {
            display_round(game.get_grid(), generation, m, n);
            game.play_round();
            ++generation;
        }
        display_round(game.get_grid(), generation, m, n);

    } catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

   try {
        cout << "*** Life<Cell> 1x5 ***" << endl << endl;

        // read input grid
        int generation = 0;
        string str_grid = "00000\n";
        istringstream gridreader(str_grid);
        int m = 1;
        int n = 5;
        map<pair<int,int>, Cell> grid;

        string line;
        for(int i=0; i<m; i++) {
            getline(gridreader, line);
            istringstream stringreader(line);
            char c;
            for(int j=0; j<n; j++) {
                stringreader >> c;
                grid.insert(make_pair(make_pair(i,j), create_cell(c)));
            }
        }

        // play game
        Life<Cell> game(grid);
        for(int i=0; i<4; i++) {
            display_round(game.get_grid(), generation, m, n);
            game.play_round();
            ++generation;
        }
        display_round(game.get_grid(), generation, m, n);

    } catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

  try {
        cout << "*** Life<Cell> 10x8 ***" << endl << endl;

        // read input grid
        int generation = 0;
        string str_grid = "--------\n----0---\n----0---\n----0---\n----0---\n--------\n----0---\n----0---\n----0---\n--------\n";
        istringstream gridreader(str_grid);
        int m = 10;
        int n = 8;
        map<pair<int,int>, Cell> grid;

        string line;
        for(int i=0; i<m; i++) {
            getline(gridreader, line);
            istringstream stringreader(line);
            char c;
            for(int j=0; j<n; j++) {
                stringreader >> c;
                grid.insert(make_pair(make_pair(i,j), create_cell(c)));
            }
        }

        // play game
        Life<Cell> game(grid);
        for(int i=0; i<8; i++) {
            display_round(game.get_grid(), generation, m, n);
            game.play_round();
            ++generation;
        }
        display_round(game.get_grid(), generation, m, n);

    } catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}

