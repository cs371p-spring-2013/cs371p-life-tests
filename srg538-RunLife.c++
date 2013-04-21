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
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

#include "ConwayCell.h"
#include "FredkinCell.h"
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
        ifstream conwayFile("RunLifeConway.in");

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<ConwayCell> > input;

        // read input file
        if (conwayFile.is_open()) {
            conwayFile >> i;
            conwayFile >> j;
            conwayFile.get();

            string line;
            while (l < i) {
                getline(conwayFile, line);

                char z;
                vector<ConwayCell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '*')
                        ++p;
                    rows.push_back(z);}
                input.push_back(rows);
                ++l;}}

        conwayFile.close();

        Life<ConwayCell> cc(input, p);

        cc.printGrid();
        for (int x = 0; x < 9; ++x) {
            cc.updateNeighbors();
            cc.updateLife();
            cc.printGrid();}

        for (int x = 9; x < 283; ++x) {
            cc.updateNeighbors();
            cc.updateLife();}
        cc.printGrid();

        for (int x = 283; x < 323; ++x) {
            cc.updateNeighbors();
            cc.updateLife();}
        cc.printGrid();

        for (int x = 323; x < 2500; ++x) {
            cc.updateNeighbors();
            cc.updateLife();}
        cc.printGrid();
        cout << endl;}
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
        ifstream fredkinFile ("RunLifeFredkin.in");

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<FredkinCell> > input;

        // read input file
        if (fredkinFile.is_open()) {
            fredkinFile >> i;
            fredkinFile >> j;
            fredkinFile.get();

            string line;
            while (l < i) {
                getline(fredkinFile, line);

                char z;
                vector<FredkinCell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '0')
                        ++p;
                    rows.push_back(z);}
                input.push_back(rows);
                ++l;}}

        fredkinFile.close();

        Life<FredkinCell> cc(input, p);
        cc.printGrid();

        for (int x = 0; x < 5; ++x) {
            cc.updateNeighbors();
            cc.updateLife();
            cc.printGrid();}
        cout << endl;}
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
        ifstream cellFile ("RunLifeCell.in");

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<Cell> > input;

        // read input file
        if (cellFile.is_open()) {
            cellFile >> i;
            cellFile >> j;
            cellFile.get();

            string line;
            while (l < i) {
                getline(cellFile, line);

                char z;
                vector<Cell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '0')
                        ++p;
                    rows.push_back(new FredkinCell(z));}
                input.push_back(rows);
                ++l;}}

        cellFile.close();

        Life<Cell> cc(input, p);
        cc.printGrid();

        for (int x = 0; x < 5; ++x) {
            cc.updateNeighbors();
            cc.updateLife();
            cc.printGrid();}
        cout << endl;}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Conway Cell 3x4
    // ----------------

    try {
        cout << "*** Life<ConwayCell> 3x4 ***" << endl;
        string conwayInput = "3\n4\n";
        for(int x = 0; x < 3; ++x)
            conwayInput += "....\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<ConwayCell> > input;

        istringstream r (conwayInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<ConwayCell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '*')
                        ++p;
                    rows.push_back(z);}
                input.push_back(rows);
                ++l;}

        Life<ConwayCell> cc(input, p);

        cc.printGrid();
        for (int x = 0; x < 3; ++x) {
            cc.updateNeighbors();
            cc.updateLife();
            cc.printGrid();}
        cout << endl;}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Conway Cell 6x6
    // ----------------

    try {
        cout << "*** Life<ConwayCell> 6x6 ***" << endl;
        string conwayInput = "6\n6\n";
        conwayInput += "*.....\n";
        conwayInput += ".*....\n";
        conwayInput += "..*...\n";
        conwayInput += "...*..\n";
        conwayInput += "....*.\n";
        conwayInput += ".....*\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<ConwayCell> > input;

        istringstream r (conwayInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<ConwayCell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '*')
                        ++p;
                    rows.push_back(z);}
                input.push_back(rows);
                ++l;}

        Life<ConwayCell> cc(input, p);

        cc.printGrid();
        for (int x = 0; x < 5; ++x) {
            cc.updateNeighbors();
            cc.updateLife();
            cc.printGrid();}
        cout << endl;}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Conway Cell 10x8
    // ----------------

    try {
        cout << "*** Life<ConwayCell> 10x8 ***" << endl;
        string conwayInput = "10\n8\n";
        conwayInput += "........\n";
        conwayInput += "....*...\n";
        conwayInput += "....*...\n";
        conwayInput += "....*...\n";
        conwayInput += "....*...\n";
        conwayInput += "........\n";
        conwayInput += "....*...\n";
        conwayInput += "....*...\n";
        conwayInput += "....*...\n";
        conwayInput += "........\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<ConwayCell> > input;

        istringstream r (conwayInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<ConwayCell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '*')
                        ++p;
                    rows.push_back(z);}
                input.push_back(rows);
                ++l;}

        Life<ConwayCell> cc(input, p);

        cc.printGrid();
        for (int x = 0; x < 5; ++x) {
            cc.updateNeighbors();
            cc.updateLife();
            cc.printGrid();}
        cout << endl;}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Conway Cell 5x5
    // ----------------

    try {
        cout << "*** Life<ConwayCell> 5x5 ***" << endl;
        string conwayInput = "5\n5\n";
        conwayInput += "..*..\n";
        conwayInput += ".***.\n";
        conwayInput += "*****\n";
        conwayInput += ".***.\n";
        conwayInput += "..*..\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<ConwayCell> > input;

        istringstream r (conwayInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<ConwayCell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '*')
                        ++p;
                    rows.push_back(z);}
                input.push_back(rows);
                ++l;}

        Life<ConwayCell> cc(input, p);

        cc.printGrid();
        for (int x = 0; x < 5; ++x) {
            cc.updateNeighbors();
            cc.updateLife();
            cc.printGrid();}
        cout << endl;}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Conway Cell 20x14
    // ----------------

    try {
        cout << "*** Life<ConwayCell> 20x14 ***" << endl;
        string conwayInput = "20\n14\n";
        conwayInput += ".....****.....\n";
        conwayInput += "...********...\n";
        conwayInput += ".************.\n";
        conwayInput += ".************.\n";
        conwayInput += "...********...\n";
        conwayInput += ".....****.....\n";
        conwayInput += "..*....*......\n";
        conwayInput += ".***....*.....\n";
        conwayInput += "..*.....*..*..\n";
        conwayInput += ".......*..***.\n";
        conwayInput += ".......*...*..\n";
        conwayInput += "......*.......\n";
        conwayInput += "......*.......\n";
        conwayInput += "..*....*......\n";
        conwayInput += ".***...*......\n";
        conwayInput += "..*.....*.....\n";
        conwayInput += "........*..*..\n";
        conwayInput += ".......*..***.\n";
        conwayInput += ".......*...*..\n";
        conwayInput += "......*.......\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<ConwayCell> > input;

        istringstream r (conwayInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<ConwayCell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '*')
                        ++p;
                    rows.push_back(z);}
                input.push_back(rows);
                ++l;}

        Life<ConwayCell> cc(input, p);

        cc.printGrid();
        for (int x = 0; x < 25; ++x) {
            cc.updateNeighbors();
            cc.updateLife();
            cc.printGrid();}

        for (int x = 25; x < 50; ++x) {
            cc.updateNeighbors();
            cc.updateLife();}
        cc.printGrid();

        cout << endl;}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Fredkin Cell 3x4
    // ----------------

    try {
        cout << "*** Life<FredkinCell> 3x4 ***" << endl;
        string FredkinInput = "3\n4\n";
        for(int x = 0; x < 3; ++x)
            FredkinInput += "----\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<FredkinCell> > input;

        istringstream r (FredkinInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<FredkinCell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '0')
                        ++p;
                    rows.push_back(z);}
                input.push_back(rows);
                ++l;}

        Life<FredkinCell> cc(input, p);

        cc.printGrid();
        for (int x = 0; x < 3; ++x) {
            cc.updateNeighbors();
            cc.updateLife();
            cc.printGrid();}
        cout << endl;}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Fredkin Cell 6x6
    // ----------------

    try {
        cout << "*** Life<FredkinCell> 6x6 ***" << endl;
        string FredkinInput = "6\n6\n";
        FredkinInput += "0-----\n";
        FredkinInput += "-0----\n";
        FredkinInput += "--0---\n";
        FredkinInput += "---0--\n";
        FredkinInput += "----0-\n";
        FredkinInput += "-----0\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<FredkinCell> > input;

        istringstream r (FredkinInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<FredkinCell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '0')
                        ++p;
                    rows.push_back(z);}
                input.push_back(rows);
                ++l;}

        Life<FredkinCell> cc(input, p);

        cc.printGrid();
        for (int x = 0; x < 5; ++x) {
            cc.updateNeighbors();
            cc.updateLife();
            cc.printGrid();}
        cout << endl;}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Fredkin Cell 10x8
    // ----------------

    try {
        cout << "*** Life<FredkinCell> 10x8 ***" << endl;
        string FredkinInput = "10\n8\n";
        FredkinInput += "--------\n";
        FredkinInput += "----0---\n";
        FredkinInput += "----0---\n";
        FredkinInput += "----0---\n";
        FredkinInput += "----0---\n";
        FredkinInput += "--------\n";
        FredkinInput += "----0---\n";
        FredkinInput += "----0---\n";
        FredkinInput += "----0---\n";
        FredkinInput += "--------\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<FredkinCell> > input;

        istringstream r (FredkinInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<FredkinCell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '0')
                        ++p;
                    rows.push_back(z);}
                input.push_back(rows);
                ++l;}

        Life<FredkinCell> cc(input, p);

        cc.printGrid();
        for (int x = 0; x < 25; ++x) {
            cc.updateNeighbors();
            cc.updateLife();
            cc.printGrid();}

        for (int x = 25; x < 50; ++x) {
            cc.updateNeighbors();
            cc.updateLife();}
        cc.printGrid();
        
        cout << endl;}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Fredkin Cell 5x5
    // ----------------

    try {
        cout << "*** Life<FredkinCell> 5x5 ***" << endl;
        string FredkinInput = "5\n5\n";
        FredkinInput += "--0--\n";
        FredkinInput += "-000-\n";
        FredkinInput += "00000\n";
        FredkinInput += "-000-\n";
        FredkinInput += "--0--\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<FredkinCell> > input;

        istringstream r (FredkinInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<FredkinCell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '0')
                        ++p;
                    rows.push_back(z);}
                input.push_back(rows);
                ++l;}

        Life<FredkinCell> cc(input, p);

        cc.printGrid();
        for (int x = 0; x < 10; ++x) {
            cc.updateNeighbors();
            cc.updateLife();
            cc.printGrid();}
        cout << endl;}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Fredkin Cell 20x14
    // ----------------

    try {
        cout << "*** Life<FredkinCell> 20x14 ***" << endl;
        string FredkinInput = "20\n14\n";
        FredkinInput += "-----0000-----\n";
        FredkinInput += "---00000000---\n";
        FredkinInput += "-000000000000-\n";
        FredkinInput += "-000000000000-\n";
        FredkinInput += "---00000000---\n";
        FredkinInput += "-----0000-----\n";
        FredkinInput += "--0----0------\n";
        FredkinInput += "-000----0-----\n";
        FredkinInput += "--0-----0--0--\n";
        FredkinInput += "-------0--000-\n";
        FredkinInput += "-------0---0--\n";
        FredkinInput += "------0-------\n";
        FredkinInput += "------0-------\n";
        FredkinInput += "--0----0------\n";
        FredkinInput += "-000---0------\n";
        FredkinInput += "--0-----0-----\n";
        FredkinInput += "--------0--0--\n";
        FredkinInput += "-------0--000-\n";
        FredkinInput += "-------0---0--\n";
        FredkinInput += "------0-------\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<FredkinCell> > input;

        istringstream r (FredkinInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<FredkinCell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '0')
                        ++p;
                    rows.push_back(z);}
                input.push_back(rows);
                ++l;}

        Life<FredkinCell> cc(input, p);

        cc.printGrid();
        for (int x = 0; x < 25; ++x) {
            cc.updateNeighbors();
            cc.updateLife();
            cc.printGrid();}

        for (int x = 25; x < 50; ++x) {
            cc.updateNeighbors();
            cc.updateLife();}
        cc.printGrid();

        for (int x = 50; x < 100; ++x) {
            cc.updateNeighbors();
            cc.updateLife();}
        cc.printGrid();

        for (int x = 100; x < 200; ++x) {
            cc.updateNeighbors();
            cc.updateLife();}
        cc.printGrid();
        
        cout << endl;}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Cell 3x4
    // ----------------

    try {
        cout << "*** Life<Cell> 3x4 ***" << endl;
        string CellInput = "3\n4\n";
        for(int x = 0; x < 3; ++x)
            CellInput += "----\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<Cell> > input;

        istringstream r (CellInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<Cell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '0')
                        ++p;
                    rows.push_back(new FredkinCell(z));}
                input.push_back(rows);
                ++l;}

        Life<Cell> cc(input, p);

        cc.printGrid();
        for (int x = 0; x < 3; ++x) {
            cc.updateNeighbors();
            cc.updateLife();
            cc.printGrid();}
        cout << endl;}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Cell 6x6
    // ----------------

    try {
        cout << "*** Life<Cell> 6x6 ***" << endl;
        string CellInput = "6\n6\n";
        CellInput += "0-----\n";
        CellInput += "-0----\n";
        CellInput += "--0---\n";
        CellInput += "---0--\n";
        CellInput += "----0-\n";
        CellInput += "-----0\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<Cell> > input;

        istringstream r (CellInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<Cell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '0')
                        ++p;
                    rows.push_back(new FredkinCell(z));}
                input.push_back(rows);
                ++l;}

        Life<Cell> cc(input, p);

        cc.printGrid();
        for (int x = 0; x < 5; ++x) {
            cc.updateNeighbors();
            cc.updateLife();
            cc.printGrid();}
        cout << endl;}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Cell 10x8
    // ----------------

    try {
        cout << "*** Life<Cell> 10x8 ***" << endl;
        string CellInput = "10\n8\n";
        CellInput += "--------\n";
        CellInput += "----0---\n";
        CellInput += "----0---\n";
        CellInput += "----0---\n";
        CellInput += "----0---\n";
        CellInput += "--------\n";
        CellInput += "----0---\n";
        CellInput += "----0---\n";
        CellInput += "----0---\n";
        CellInput += "--------\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<Cell> > input;

        istringstream r (CellInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<Cell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '0')
                        ++p;
                    rows.push_back(new FredkinCell(z));}
                input.push_back(rows);
                ++l;}

        Life<Cell> cc(input, p);

        cc.printGrid();
        for (int x = 0; x < 35; ++x) {
            cc.updateNeighbors();
            cc.updateLife();
            cc.printGrid();}  
        cout << endl;}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Cell 5x5
    // ----------------

    try {
        cout << "*** Life<Cell> 5x5 ***" << endl;
        string CellInput = "5\n5\n";
        CellInput += "--0--\n";
        CellInput += "-000-\n";
        CellInput += "00000\n";
        CellInput += "-000-\n";
        CellInput += "--0--\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<Cell> > input;

        istringstream r (CellInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<Cell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '0')
                        ++p;
                    rows.push_back(new FredkinCell(z));}
                input.push_back(rows);
                ++l;}

        Life<Cell> cc(input, p);

        cc.printGrid();
        for (int x = 0; x < 10; ++x) {
            cc.updateNeighbors();
            cc.updateLife();
            cc.printGrid();}
        cout << endl;}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------------
    // Cell 20x14
    // ----------------

    try {
        cout << "*** Life<Cell> 20x14 ***" << endl;
        string CellInput = "20\n14\n";
        CellInput += "-----0000-----\n";
        CellInput += "---00000000---\n";
        CellInput += "-000000000000-\n";
        CellInput += "-000000000000-\n";
        CellInput += "---00000000---\n";
        CellInput += "-----0000-----\n";
        CellInput += "--0----0------\n";
        CellInput += "-000----0-----\n";
        CellInput += "--0-----0--0--\n";
        CellInput += "-------0--000-\n";
        CellInput += "-------0---0--\n";
        CellInput += "------0-------\n";
        CellInput += "------0-------\n";
        CellInput += "--0----0------\n";
        CellInput += "-000---0------\n";
        CellInput += "--0-----0-----\n";
        CellInput += "--------0--0--\n";
        CellInput += "-------0--000-\n";
        CellInput += "-------0---0--\n";
        CellInput += "------0-------\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<Cell> > input;

        istringstream r (CellInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<Cell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '0')
                        ++p;
                    rows.push_back(new FredkinCell(z));}
                input.push_back(rows);
                ++l;}

        Life<Cell> cc(input, p);

        cc.printGrid();
        for (int x = 0; x < 25; ++x) {
            cc.updateNeighbors();
            cc.updateLife();
            cc.printGrid();}

        for (int x = 25; x < 50; ++x) {
            cc.updateNeighbors();
            cc.updateLife();}
        cc.printGrid();

        for (int x = 50; x < 100; ++x) {
            cc.updateNeighbors();
            cc.updateLife();}
        cc.printGrid();

        for (int x = 100; x < 200; ++x) {
            cc.updateNeighbors();
            cc.updateLife();}
        cc.printGrid();
        
        cout << endl;}
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    return 0;}
