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
#include "Board.h"
#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
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

    try {
        cout << "*** Life<ConwayCell> 109x69 ***" << endl;

//        read RunLifeConway.in // assume all Conway cells
        ifstream file_in("RunLifeConway.in");
        int y_dim;
        int x_dim;
        file_in >> y_dim;
        file_in >> x_dim;
        string line;

        Board<ConwayCell> brd(x_dim,y_dim);

        for(int _y = 0; _y < y_dim ; ++_y){
            file_in >> line;
            for(int _x = 0; _x < x_dim ; ++_x){
                if(line[_x]=='*'){
                    ConwayCell cc(true);
                    brd.add_creature( cc , _x, _y);
                }
            }
        }
        file_in.close();
        Life<ConwayCell> l(brd);
//        Print the first 10 grids (i.e. 0, 1, 2...9).
        l.print_life();
        for(int i = 0; i < 10; ++i){
            l.simulate_round();
            l.print_life();
        }

        for(int i = 0; i < 273; ++i){
            l.simulate_round();
        }
//        Print the 283rd grid.
        l.print_life();

//        Simulate 40 moves.
        for(int i = 0; i < 40; ++i){
            l.simulate_round();
        }
//        Print the 323rd grid.
        l.print_life();

//        Simulate 2177 moves.
        for(int i = 0; i < 2177; ++i){
            l.simulate_round();
        }
//        Print the 2500th grid.
        l.print_life();
        cout << std::endl;
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
        ifstream file_in("RunLifeFredkin.in");
        int y_dim;
        int x_dim;
        file_in >> y_dim;
        file_in >> x_dim;
        string line;

        Board<FredkinCell> brd(x_dim,y_dim);

        for(int _y = 0; _y < y_dim ; ++_y){
            file_in >> line;
            for(int _x = 0; _x < x_dim ; ++_x){
                if(line[_x]=='0'){
                    FredkinCell cc(true);
                    brd.add_creature( cc , _x, _y);
                }
            }
        }
        file_in.close();
        Life<FredkinCell> l(brd);
        l.print_life();
        for(int i = 0; i < 10; ++i){
            l.simulate_round();
            l.print_life();
        }
        cout << std::endl;
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
        ifstream file_in("RunLifeCell.in");
        int y_dim;
        int x_dim;
        file_in >> y_dim;
        file_in >> x_dim;
        string line;

        Board<Cell> brd(x_dim,y_dim);

        for(int _y = 0; _y < y_dim ; ++_y){
            file_in >> line;
            for(int _x = 0; _x < x_dim ; ++_x){
                if(line[_x]=='0'){
                    Cell cc(true);
                    brd.add_creature( cc , _x, _y);
                }
            }
        }
        file_in.close();
        Life<Cell> l(brd);
        l.print_life();
        for(int i = 0; i < 5; ++i){
            l.simulate_round();
            l.print_life();
        }
        cout << std::endl;

    }
    catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
            assert(false);}


    // ----------
    //  Conway 10x10 flyer
    // ----------

            try {
                cout << "*** Life<ConwayCell> 10x10 ***" << endl;
        int y_dim = 10;
        int x_dim = 10;

        Board<ConwayCell> brd(x_dim,y_dim);
        ConwayCell c1(true);
        ConwayCell c2(true);
        ConwayCell c3(true);
        ConwayCell c4(true);
        ConwayCell c5(true);

        brd.add_creature( c1 , 2, 0);
        brd.add_creature( c2 , 2, 1);
        brd.add_creature( c3 , 2, 2);
        brd.add_creature( c4 , 0, 1);
        brd.add_creature( c5 , 1, 2);

        Life<ConwayCell> l(brd);
        l.print_life();
        for(int i = 0; i < 20; ++i){
            l.simulate_round();
            l.print_life();
        }
        cout << std::endl;

    }
    catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
            assert(false);}

    // ----------
    //  Conway 100x100 flyer
    // ----------

            try {
                cout << "*** Life<ConwayCell> 10x10 ***" << endl;

        int x[] = {2,2,2,0,1,97,97,97,99,98,25,25,25,23,24};
        int y[] = {0,1,2,1,2,99,98,97,98,97,23,24,25,24,25};

        int y_dim = 100;
        int x_dim = 100;
        Board<ConwayCell> brd(x_dim,y_dim);
        int cells_needed = 15;
        for (int i = 0; i < cells_needed ; ++i){
            ConwayCell cc(true);
            brd.add_creature( cc , x[i], y[i]);
        }

        Life<ConwayCell> l(brd);
        l.print_life();
        for(int i = 0; i < 30; ++i){
            l.simulate_round();
            l.print_life();
        }
        cout << std::endl;

    }
    catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
            assert(false);}

    // ----------
    //  Conway 40x40 flyer
    // ----------

            try {
                cout << "*** Life<ConwayCell> 40x40 ***" << endl;

        int x[] = {2,2,2,0,1,25,25,25,23,24};
        int y[] = {0,1,2,1,2,23,24,25,24,25};

        int y_dim = 40;
        int x_dim = 40;
        Board<ConwayCell> brd(x_dim,y_dim);
        int cells_needed = 10;
        for (int i = 0; i < cells_needed ; ++i){
            ConwayCell cc(true);
            brd.add_creature( cc , x[i], y[i]);
        }

        Life<ConwayCell> l(brd);
        l.print_life();
        for(int i = 0; i < 10; ++i){
            l.simulate_round();
            l.print_life();
        }
        cout << std::endl;

    }
    catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
            assert(false);}

    // ----------
    //  Conway 6x6 flyer
    // ----------

            try {
                cout << "*** Life<ConwayCell> 6x6 ***" << endl;

        int x[] = {2,3,4,1,2,3};
        int y[] = {2,2,2,3,3,3};
        int cells_needed = 6;

        int y_dim = 6;
        int x_dim = 6;
        Board<ConwayCell> brd(x_dim,y_dim);
        for (int i = 0; i < cells_needed ; ++i){
            ConwayCell cc(true);
            brd.add_creature( cc , x[i], y[i]);
        }

        Life<ConwayCell> l(brd);
        l.print_life();
        for(int i = 0; i < 10; ++i){
            l.simulate_round();
            l.print_life();
        }
        cout << std::endl;

    }
    catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
            assert(false);}

    // ----------
    //  Conway 6x6 pulsar
    // ----------

            try {
                cout << "*** Life<ConwayCell> 6x6 ***" << endl;

        int x[] = {1,2,1,4,3,4};
        int y[] = {1,1,2,3,4,4};
        int cells_needed = 6;

        int y_dim = 6;
        int x_dim = 6;
        Board<ConwayCell> brd(x_dim,y_dim);
        for (int i = 0; i < cells_needed ; ++i){
            ConwayCell cc(true);
            brd.add_creature( cc , x[i], y[i]);
        }

        Life<ConwayCell> l(brd);
        l.print_life();
        for(int i = 0; i < 10; ++i){
            l.simulate_round();
            l.print_life();
        }
        cout << std::endl;

    }
    catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
            assert(false);}

    // ----------
    //  Fredkin 10x10 flyer
    // ----------

            try {
                cout << "*** Life<FredkinCell> 10x10 ***" << endl;
        int y_dim = 10;
        int x_dim = 10;

        Board<FredkinCell> brd(x_dim,y_dim);
        FredkinCell c1(true);
        FredkinCell c2(true);
        FredkinCell c3(true);
        FredkinCell c4(true);
        FredkinCell c5(true);

        brd.add_creature( c1 , 2, 0);
        brd.add_creature( c2 , 2, 1);
        brd.add_creature( c3 , 2, 2);
        brd.add_creature( c4 , 0, 1);
        brd.add_creature( c5 , 1, 2);

        Life<FredkinCell> l(brd);
        l.print_life();
        for(int i = 0; i < 20; ++i){
            l.simulate_round();
            l.print_life();
        }
        cout << std::endl;

    }
    catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
            assert(false);}

    // ----------
    //  Fredkin 100x100 flyer
    // ----------

            try {
                cout << "*** Life<FredkinCell> 10x10 ***" << endl;

        int x[] = {2,2,2,0,1,97,97,97,99,98,25,25,25,23,24};
        int y[] = {0,1,2,1,2,99,98,97,98,97,23,24,25,24,25};

        int y_dim = 100;
        int x_dim = 100;
        Board<FredkinCell> brd(x_dim,y_dim);
        int cells_needed = 15;
        for (int i = 0; i < cells_needed ; ++i){
            FredkinCell cc(true);
            brd.add_creature( cc , x[i], y[i]);
        }

        Life<FredkinCell> l(brd);
        l.print_life();
        for(int i = 0; i < 30; ++i){
            l.simulate_round();
            l.print_life();
        }
        cout << std::endl;

    }
    catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
            assert(false);}

    // ----------
    //  Fredkin 40x40 flyer
    // ----------

            try {
                cout << "*** Life<FredkinCell> 40x40 ***" << endl;

        int x[] = {2,2,2,0,1,25,25,25,23,24};
        int y[] = {0,1,2,1,2,23,24,25,24,25};

        int y_dim = 40;
        int x_dim = 40;
        Board<FredkinCell> brd(x_dim,y_dim);
        int cells_needed = 10;
        for (int i = 0; i < cells_needed ; ++i){
            FredkinCell cc(true);
            brd.add_creature( cc , x[i], y[i]);
        }

        Life<FredkinCell> l(brd);
        l.print_life();
        for(int i = 0; i < 10; ++i){
            l.simulate_round();
            l.print_life();
        }
        cout << std::endl;

    }
    catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
            assert(false);}

    // ----------
    //  Fredkin 6x6 flyer
    // ----------

            try {
                cout << "*** Life<FredkinCell> 6x6 ***" << endl;

        int x[] = {2,3,4,1,2,3};
        int y[] = {2,2,2,3,3,3};
        int cells_needed = 6;

        int y_dim = 6;
        int x_dim = 6;
        Board<FredkinCell> brd(x_dim,y_dim);
        for (int i = 0; i < cells_needed ; ++i){
            FredkinCell cc(true);
            brd.add_creature( cc , x[i], y[i]);
        }

        Life<FredkinCell> l(brd);
        l.print_life();
        for(int i = 0; i < 10; ++i){
            l.simulate_round();
            l.print_life();
        }
        cout << std::endl;

    }
    catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
            assert(false);}

    // ----------
    //  Fredkin 6x6 pulsar
    // ----------

            try {
                cout << "*** Life<FredkinCell> 6x6 ***" << endl;

        int x[] = {1,2,1,4,3,4};
        int y[] = {1,1,2,3,4,4};
        int cells_needed = 6;

        int y_dim = 6;
        int x_dim = 6;
        Board<FredkinCell> brd(x_dim,y_dim);
        for (int i = 0; i < cells_needed ; ++i){
            FredkinCell cc(true);
            brd.add_creature( cc , x[i], y[i]);
        }

        Life<FredkinCell> l(brd);
        l.print_life();
        for(int i = 0; i < 10; ++i){
            l.simulate_round();
            l.print_life();
        }
        cout << std::endl;

    }
    catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
            assert(false);}
    // ----------
    //   10x10 flyer
    // ----------

            try {
                cout << "*** Life<Cell> 10x10 ***" << endl;
        int y_dim = 10;
        int x_dim = 10;

        Board<Cell> brd(x_dim,y_dim);
        Cell c1(true);
        Cell c2(true);
        Cell c3(true);
        Cell c4(true);
        Cell c5(true);

        brd.add_creature( c1 , 2, 0);
        brd.add_creature( c2 , 2, 1);
        brd.add_creature( c3 , 2, 2);
        brd.add_creature( c4 , 0, 1);
        brd.add_creature( c5 , 1, 2);

        Life<Cell> l(brd);
        l.print_life();
        for(int i = 0; i < 20; ++i){
            l.simulate_round();
            l.print_life();
        }
        cout << std::endl;

    }
    catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
            assert(false);}

    // ----------
    //  Cell 100x100 flyer
    // ----------

            try {
                cout << "*** Life<Cell> 10x10 ***" << endl;

        int x[] = {2,2,2,0,1,97,97,97,99,98,25,25,25,23,24};
        int y[] = {0,1,2,1,2,99,98,97,98,97,23,24,25,24,25};

        int y_dim = 100;
        int x_dim = 100;
        Board<Cell> brd(x_dim,y_dim);
        int cells_needed = 15;
        for (int i = 0; i < cells_needed ; ++i){
            Cell cc(true);
            brd.add_creature( cc , x[i], y[i]);
        }

        Life<Cell> l(brd);
        l.print_life();
        for(int i = 0; i < 30; ++i){
            l.simulate_round();
            l.print_life();
        }
        cout << std::endl;

    }
    catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
            assert(false);}

    // ----------
    //  Cell 40x40 flyer
    // ----------

            try {
                cout << "*** Life<Cell> 40x40 ***" << endl;

        int x[] = {2,2,2,0,1,25,25,25,23,24};
        int y[] = {0,1,2,1,2,23,24,25,24,25};

        int y_dim = 40;
        int x_dim = 40;
        Board<Cell> brd(x_dim,y_dim);
        int cells_needed = 10;
        for (int i = 0; i < cells_needed ; ++i){
            Cell cc(true);
            brd.add_creature( cc , x[i], y[i]);
        }

        Life<Cell> l(brd);
        l.print_life();
        for(int i = 0; i < 10; ++i){
            l.simulate_round();
            l.print_life();
        }
        cout << std::endl;

    }
    catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
            assert(false);}

    // ----------
    //  Cell 6x6 flyer
    // ----------

            try {
                cout << "*** Life<Cell> 6x6 ***" << endl;

        int x[] = {2,3,4,1,2,3};
        int y[] = {2,2,2,3,3,3};
        int cells_needed = 6;

        int y_dim = 6;
        int x_dim = 6;
        Board<Cell> brd(x_dim,y_dim);
        for (int i = 0; i < cells_needed ; ++i){
            Cell cc(true);
            brd.add_creature( cc , x[i], y[i]);
        }

        Life<Cell> l(brd);
        l.print_life();
        for(int i = 0; i < 10; ++i){
            l.simulate_round();
            l.print_life();
        }
        cout << std::endl;

    }
    catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
            assert(false);}

    // ----------
    //  Cell 6x6 pulsar
    // ----------

            try {
                cout << "*** Life<Cell> 6x6 ***" << endl;

        int x[] = {1,2,1,4,3,4};
        int y[] = {1,1,2,3,4,4};
        int cells_needed = 6;

        int y_dim = 6;
        int x_dim = 6;
        Board<Cell> brd(x_dim,y_dim);
        for (int i = 0; i < cells_needed ; ++i){
            Cell cc(true);
            brd.add_creature( cc , x[i], y[i]);
        }

        Life<Cell> l(brd);
        l.print_life();
        for(int i = 0; i < 10; ++i){
            l.simulate_round();
            l.print_life();
        }
        cout << std::endl;

    }
    catch (const invalid_argument&) {
        assert(false);}
        catch (const out_of_range&) {
            assert(false);}



































            return 0;}
