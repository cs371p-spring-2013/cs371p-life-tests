// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#define class struct
#define private public
#define protected public

#include "Life.h"
#include "Cell.h"
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Handle.h"


using namespace std;
// -----------
// TestLife
// -----------

struct TestLife : CppUnit::TestFixture
{
    // ----------
    // ConwayCell
    // ----------

    void test_conway_constructor1(){
        ConwayCell c(1);
        CPPUNIT_ASSERT(c._state == true);
    }
    void test_conway_constructor2(){
        ConwayCell c(0);
        CPPUNIT_ASSERT(c._state == false);
    }
    void test_conway_constructor3(){
        ConwayCell c;
        CPPUNIT_ASSERT(c._state == false);
    }
    void test_conway_print1(){
        ConwayCell c(1);
        ostringstream o;
        o << c;
        CPPUNIT_ASSERT(o.str() == "*");
    }
    void test_conway_print2(){
        ConwayCell c(0);
        ostringstream o;
        o << c;
        CPPUNIT_ASSERT(o.str() == ".");
    }
    void test_conway_print3(){
        ConwayCell c;
        ostringstream o;
        o << c;
        CPPUNIT_ASSERT(o.str() == ".");
    }
    void test_conway_write1(){
        ConwayCell c(1);
        ostringstream o;
        c.write(o);
        CPPUNIT_ASSERT(o.str() == "*");
    }
    void test_conway_write2(){
        ConwayCell c(0);
        ostringstream o;
        c.write(o);
        CPPUNIT_ASSERT(o.str() == ".");
    }
    void test_conway_write3(){
        ConwayCell c;
        ostringstream o;
        c.write(o);
        CPPUNIT_ASSERT(o.str() == ".");
    }
    void test_conway_flip_and_get_state1(){
        ConwayCell c(1);

        CPPUNIT_ASSERT(c.get_state() == true);
        c.flip_state();
        CPPUNIT_ASSERT(c.get_state() == false);
    }
    void test_conway_flip_and_get_state2(){
        ConwayCell c(0);

        CPPUNIT_ASSERT(c.get_state() == false);
        c.flip_state();
        CPPUNIT_ASSERT(c.get_state() == true);
    }
    void test_conway_flip_and_get_state3(){
        ConwayCell c;

        CPPUNIT_ASSERT(c.get_state() == false);
        c.flip_state();
        CPPUNIT_ASSERT(c.get_state() == true);
    }
    void test_conway_get_neighbor_array1(){
        ConwayCell c(1);
        const bool* b = c.get_neighbor_array();
        for(int i = 0; i < 8; ++i)
            CPPUNIT_ASSERT(b[i]);
    }
    void test_conway_get_neighbor_array2(){
        ConwayCell c(1);
        const bool* b = c.get_neighbor_array();
        for(int i = 0; i < 8; ++i)
            CPPUNIT_ASSERT(b[i]);
    }
    void test_conway_get_neighbor_array3(){
        ConwayCell c(1);
        const bool* b1 = c.get_neighbor_array();
        const bool* b2 = c.get_neighbor_array();
        CPPUNIT_ASSERT(b1 == b2);
    }
    void test_conway_should_change1(){
        ConwayCell c(1);
        CPPUNIT_ASSERT(c.should_change(3) == NO_CHANGE);
        CPPUNIT_ASSERT(c.should_change(1) == CHANGE);
        CPPUNIT_ASSERT(c.should_change(5) == CHANGE);
    }
    void test_conway_should_change2(){
        ConwayCell c(0);
        CPPUNIT_ASSERT(c.should_change(3) == CHANGE);
        CPPUNIT_ASSERT(c.should_change(1) == NO_CHANGE);
        CPPUNIT_ASSERT(c.should_change(5) == NO_CHANGE);
    }
    void test_conway_should_change3(){
        ConwayCell c;
        CPPUNIT_ASSERT(c.should_change(3) == CHANGE);
        CPPUNIT_ASSERT(c.should_change(1) == NO_CHANGE);
        CPPUNIT_ASSERT(c.should_change(5) == NO_CHANGE);
    }
    void test_conway_clone1(){
        ConwayCell c(1);
        ConwayCell* cp = c.clone();
        CPPUNIT_ASSERT(cp != &c);
        CPPUNIT_ASSERT(cp->_state == c._state);
        delete cp;
    }
    void test_conway_clone2(){
        ConwayCell c(0);
        ConwayCell* cp = c.clone();
        CPPUNIT_ASSERT(cp != &c);
        CPPUNIT_ASSERT(cp->_state == c._state);
        delete cp;
    }
    void test_conway_clone3(){
        ConwayCell c;
        ConwayCell* cp = c.clone();
        CPPUNIT_ASSERT(cp != &c);
        CPPUNIT_ASSERT(cp->_state == c._state);
        delete cp;
    }
    // ----
    // Cell
    // ----

    void test_cell_constructor1(){
        Cell c = new ConwayCell(1);
        CPPUNIT_ASSERT(c._p != NULL);
        CPPUNIT_ASSERT(c._p->_state == true);
    }
    void test_cell_constructor2(){
        Cell c = new FredkinCell(1);
        CPPUNIT_ASSERT(c._p != NULL);
        CPPUNIT_ASSERT(c._p->_state == true);
    }
    void test_cell_constructor3(){
        Cell c;
        CPPUNIT_ASSERT(c._p == NULL);
    }
    void test_cell_should_change1(){
        Cell c = new ConwayCell(1);
        CPPUNIT_ASSERT(c.should_change(3) == NO_CHANGE);
        CPPUNIT_ASSERT(c.should_change(1) == CHANGE);
        CPPUNIT_ASSERT(c.should_change(5) == CHANGE);
    }
    void test_cell_should_change2(){
        Cell c = new FredkinCell(1);
        CPPUNIT_ASSERT(c.should_change(3) == NO_CHANGE);
        CPPUNIT_ASSERT(c.should_change(2) == CHANGE);
        CPPUNIT_ASSERT(c.should_change(0) == CHANGE);
    }
    void test_cell_should_change3(){
        Cell c = new FredkinCell(1);
        FredkinCell* fp = dynamic_cast<FredkinCell*>(c._p);
        fp->age = 1;
        CPPUNIT_ASSERT(c.should_change(3,true) == MUTATE);
    }
    void test_cell_mutate1(){
        Cell c = new FredkinCell(1);
        AbstractCell* p = c._p;
        c.mutate<ConwayCell>();
        CPPUNIT_ASSERT(p != c._p);
        CPPUNIT_ASSERT(dynamic_cast<ConwayCell*>(c._p));
    }
    void test_cell_mutate2(){
        Cell c = new ConwayCell(1);
        AbstractCell* p = c._p;
        c.mutate<FredkinCell>();
        CPPUNIT_ASSERT(p != c._p);
        CPPUNIT_ASSERT(dynamic_cast<FredkinCell*>(c._p));
    }
    void test_cell_mutate3(){
        Cell c = new ConwayCell(1);
        AbstractCell* p = c._p;
        c.mutate<ConwayCell>();
        CPPUNIT_ASSERT(p != c._p);
        CPPUNIT_ASSERT(dynamic_cast<ConwayCell*>(c._p));
    }
    void test_cell_get_neighbor_array1(){
        Cell c = new ConwayCell(1);
        const bool* b = c.get_neighbor_array();
        for(int i = 0; i < 8; ++i)
            CPPUNIT_ASSERT(b[i]);
    }
    void test_cell_get_neighbor_array2(){
        Cell c = new FredkinCell(1);
        const bool* b = c.get_neighbor_array();
        CPPUNIT_ASSERT(!b[0]);
        CPPUNIT_ASSERT(b[1]);
        CPPUNIT_ASSERT(!b[2]);
        CPPUNIT_ASSERT(b[3]);
        CPPUNIT_ASSERT(b[4]);
        CPPUNIT_ASSERT(!b[5]);
        CPPUNIT_ASSERT(b[6]);
        CPPUNIT_ASSERT(!b[7]);
    }
    void test_cell_get_neighbor_array3(){
        Cell c1 = new ConwayCell(1);
        const bool* b1 = c1.get_neighbor_array();
        Cell c2 = new FredkinCell(1);
        const bool* b2 = c2.get_neighbor_array();
        CPPUNIT_ASSERT(b1 == c1.get_neighbor_array());
        CPPUNIT_ASSERT(b2 == c2.get_neighbor_array());
    }
    void test_cell_print1(){
        Cell c = new ConwayCell(1);
        ostringstream o,o2;
        o << c;
        CPPUNIT_ASSERT(o.str() == "*");
        c.flip_state();
        o2 << c;
        CPPUNIT_ASSERT(o2.str() == ".");
    }
    void test_cell_print2(){
        Cell c = new FredkinCell(1);
        FredkinCell* fp = dynamic_cast<FredkinCell*>(c._p);
        fp->age = 20;
        ostringstream o,o2;
        o << c;
        CPPUNIT_ASSERT(o.str() == "+");
        c.flip_state();
        o2 << c;
        CPPUNIT_ASSERT(o2.str() == "-");
    }
    void test_cell_print3(){
        Cell c = new FredkinCell(1);
        ostringstream o,o2;
        o << c;
        CPPUNIT_ASSERT(o.str() == "0");
        c.flip_state();
        o2 << c;
        CPPUNIT_ASSERT(o2.str() == "-");
    }
    void test_cell_flip_and_get_state1(){
        Cell c = new ConwayCell(1);

        CPPUNIT_ASSERT(c.get_state() == true);
        c.flip_state();
        CPPUNIT_ASSERT(c.get_state() == false);
    }
    void test_cell_flip_and_get_state2(){
        Cell c = new FredkinCell(1);

        CPPUNIT_ASSERT(c.get_state() == true);
        c.flip_state();
        CPPUNIT_ASSERT(c.get_state() == false);
    }
    void test_cell_flip_and_get_state3(){
        Cell c = new FredkinCell(1);
        c.mutate<ConwayCell>();

        CPPUNIT_ASSERT(c.get_state() == true);
        c.flip_state();
        CPPUNIT_ASSERT(c.get_state() == false);
    }

    //******************Fredkin Tests**************************/
    //Fredkin Constructor
    void test_fredkin_constructor1()
    {
        FredkinCell c(1);
        CPPUNIT_ASSERT(c._state == true);
        CPPUNIT_ASSERT(c.age == 0);
    }
    void test_fredkin_constructor2()
    {
        FredkinCell c(0);
        CPPUNIT_ASSERT(c._state == false);
        CPPUNIT_ASSERT(c.age == 0);
    }
    void test_fredkin_constructor3()
    {
        FredkinCell c;
        CPPUNIT_ASSERT(c._state == false);
        CPPUNIT_ASSERT(c.age == 0);
    }

    //Fredkin Print
    void test_fredkin_print1()
    {
        FredkinCell c(1);
        c.age = 5;
        ostringstream o;
        o << c;
        CPPUNIT_ASSERT(o.str() == "5");
    }
    void test_fredkin_print2()
    {
        FredkinCell c(0);
        ostringstream o;
        o << c;
        CPPUNIT_ASSERT(o.str() == "-");
    }
    void test_fredkin_print3()
    {
        FredkinCell c(true);
        c.age = 10;
        ostringstream o;
        o << c;
        CPPUNIT_ASSERT(o.str() == "+");
    }

    //Fredkin Write
    void test_fredkin_write1()
    {
        FredkinCell c(1);
        c.age = 5;
        ostringstream o;
        c.write(o);
        CPPUNIT_ASSERT(o.str() == "5");
    }
    void test_fredkin_write2()
    {
        FredkinCell c(0);
        ostringstream o;
        c.write(o);
        CPPUNIT_ASSERT(o.str() == "-");
    }
    void test_fredkin_write3()
    {
        FredkinCell c(true);
        c.age = 10;
        ostringstream o;
        c.write(o);
        CPPUNIT_ASSERT(o.str() == "+");
    }

    //Fredkin Get State
    void test_fredkin_get_state1(){
        FredkinCell c(1);
        CPPUNIT_ASSERT(c.get_state() == true);
    }
    void test_fredkin_get_state2(){
        FredkinCell c(0);
        CPPUNIT_ASSERT(c.get_state() == false);
    }
    void test_fredkin_get_state3(){
        FredkinCell c;
        CPPUNIT_ASSERT(c.get_state() == false);
    }

    //Fredkin Flip State
    void test_fredkin_flip_state1(){
        FredkinCell c(1);
        c.flip_state();
        CPPUNIT_ASSERT(c._state != true);
    }
    void test_fredkin_flip_state2(){
        FredkinCell c(0);
        c.flip_state();
        CPPUNIT_ASSERT(c._state != false);
    }
    void test_fredkin_flip_state3(){
        FredkinCell c;
        c.flip_state();
        CPPUNIT_ASSERT(c._state != false);
    }

    //Fredkin Neighbor Array
    void test_fredkin_get_neighbor_array1(){
        FredkinCell c(1);
        const bool* b = c.get_neighbor_array();
        CPPUNIT_ASSERT(!b[0] && b[1] && !b[2] &&
                        b[3] &&          b[4] &&
                       !b[5] && b[6] && !b[7]);
    }
    void test_fredkin_get_neighbor_array2(){
        FredkinCell c(1);
        const bool* b = c.get_neighbor_array();
        CPPUNIT_ASSERT(!b[0] && b[1] && !b[2] &&
                        b[3] &&          b[4] &&
                       !b[5] && b[6] && !b[7]);
    }
    void test_fredkin_get_neighbor_array3(){
        FredkinCell c(1);
        const bool* b1 = c.get_neighbor_array();
        const bool* b2 = c.get_neighbor_array();
        CPPUNIT_ASSERT(b1 == b2);
    }

    //Should Change
    void test_fredkin_should_change1(){
        FredkinCell c(1);
        CPPUNIT_ASSERT(c.should_change(0) == CHANGE);
        CPPUNIT_ASSERT(c.should_change(2) == CHANGE);
        CPPUNIT_ASSERT(c.should_change(3) == NO_CHANGE);
    }
    void test_fredkin_should_change2(){
        FredkinCell c(0);
        CPPUNIT_ASSERT(c.should_change(1) == CHANGE);
        CPPUNIT_ASSERT(c.should_change(3) == CHANGE);
        CPPUNIT_ASSERT(c.should_change(2) == NO_CHANGE);
    }
    void test_fredkin_should_change3(){
        FredkinCell c(true);
        c.age = 1;
        CPPUNIT_ASSERT(c.should_change(0, true) == CHANGE);
        CPPUNIT_ASSERT(c.should_change(2, true) == CHANGE);
        CPPUNIT_ASSERT(c.should_change(3, true) == MUTATE);
    }

    //Clone
    void test_fredkin_clone1(){
        FredkinCell c(1);
        FredkinCell* cp = c.clone();
        CPPUNIT_ASSERT(cp != &c);
        CPPUNIT_ASSERT(cp->_state == c._state);
        CPPUNIT_ASSERT(cp->age == 0);
        delete cp;
    }
    void test_fredkin_clone2(){
        FredkinCell c(0);
        FredkinCell* cp = c.clone();
        CPPUNIT_ASSERT(cp != &c);
        CPPUNIT_ASSERT(cp->_state == c._state);
        CPPUNIT_ASSERT(cp->age == 0);
        delete cp;
    }
    void test_fredkin_clone3(){
        FredkinCell c;
        FredkinCell* cp = c.clone();
        CPPUNIT_ASSERT(cp != &c);
        CPPUNIT_ASSERT(cp->_state == c._state);
        CPPUNIT_ASSERT(cp->age == 0);
        delete cp;
    }

    /********************Life******************/
    //The meaning of which is 42
    //Get Neighbors
    void test_life_get_neighbors1()
    {
        //Setup
        ConwayCell c_alive(true);
        ConwayCell c_dead(0);
        FredkinCell f_alive(1);
        FredkinCell f_dead(0);
        Cell c_cell_alive = new ConwayCell(1);
        Cell c_cell_dead = new ConwayCell(0);
        Cell f_cell_alive = new FredkinCell(1);
        Cell f_cell_dead = new FredkinCell(0);

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
        CPPUNIT_ASSERT(game.get_neighbors(0, 0) == 0);
    }
    void test_life_get_neighbors2()
    {
        //Setup
        ConwayCell c_alive(true);
        ConwayCell c_dead(0);
        FredkinCell f_alive(1);
        FredkinCell f_dead(0);
        Cell c_cell_alive = new ConwayCell(1);
        Cell c_cell_dead = new ConwayCell(0);
        Cell f_cell_alive = new FredkinCell(1);
        Cell f_cell_dead = new FredkinCell(0);

        int row, col;
        string input =  "3\n" 
                        "3\n"
                        "0--\n"
                        "0--\n"
                        "-0-\n";
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
        CPPUNIT_ASSERT(game.get_neighbors(1, 0) == 1);
    }
    void test_life_get_neighbors3()
    {
        //Setup
        ConwayCell c_alive(true);
        ConwayCell c_dead(0);
        FredkinCell f_alive(1);
        FredkinCell f_dead(0);
        Cell c_cell_alive = new ConwayCell(1);
        Cell c_cell_dead = new ConwayCell(0);
        Cell f_cell_alive = new FredkinCell(1);
        Cell f_cell_dead = new FredkinCell(0);

        int row, col;
        string input =  "3\n" 
                        "3\n"
                        "*..\n"
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
        CPPUNIT_ASSERT(game.get_neighbors(1, 1) == 2);
    }

    //Evolve Helper
    void test_life_evolve_helper1()
    {
        //Setup
        ConwayCell c_alive(true);
        ConwayCell c_dead(0);
        FredkinCell f_alive(1);
        FredkinCell f_dead(0);
        Cell c_cell_alive = new ConwayCell(1);
        Cell c_cell_dead = new ConwayCell(0);
        Cell f_cell_alive = new FredkinCell(1);
        Cell f_cell_dead = new FredkinCell(0);

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
        game.evolve_helper(0,0);
        CPPUNIT_ASSERT(game.to_change.size() == 1);
    }
    void test_life_evolve_helper2()
    {
        //Setup
        ConwayCell c_alive(true);
        ConwayCell c_dead(0);
        FredkinCell f_alive(1);
        FredkinCell f_dead(0);
        Cell c_cell_alive = new ConwayCell(1);
        Cell c_cell_dead = new ConwayCell(0);
        Cell f_cell_alive = new FredkinCell(1);
        Cell f_cell_dead = new FredkinCell(0);

        int row, col;
        string input =  "1\n"
                        "2\n"
                        "**\n";
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
        game.evolve_helper(0,0);
        game.evolve_helper(0,1);
        CPPUNIT_ASSERT(game.to_change.size() == 2);
    }
    void test_life_evolve_helper3()
    {
        //Setup
        ConwayCell c_alive(true);
        ConwayCell c_dead(0);
        FredkinCell f_alive(1);
        FredkinCell f_dead(0);
        Cell c_cell_alive = new ConwayCell(1);
        Cell c_cell_dead = new ConwayCell(0);
        Cell f_cell_alive = new FredkinCell(1);
        Cell f_cell_dead = new FredkinCell(0);

        int row, col;
        string input =  "3\n" 
                        "3\n"
                        ".*0\n"
                        "-*.\n"
                        ".*.\n";
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
        dynamic_cast<FredkinCell*>(game.grid[0][2]._p)->age = 1;
        game.evolve_helper(0,2);
        CPPUNIT_ASSERT(game.to_change.size() == 0);
        CPPUNIT_ASSERT(dynamic_cast<ConwayCell*>(game.grid[0][2]._p) != NULL);
    }
    //Life constructor
    void test_life_constructor1()
    {
        int rows = 5;
        int cols = 5;
        Life<Cell> game(rows, cols);
        CPPUNIT_ASSERT(game.rows == rows);
        CPPUNIT_ASSERT(game.cols == cols);
        CPPUNIT_ASSERT(game.live_cells == 0);
        CPPUNIT_ASSERT(game.turn == 0);
        CPPUNIT_ASSERT(game.grid.size() == (uint)rows);
        for (int i = 0; i < rows; ++i)
        {
            CPPUNIT_ASSERT(game.grid[i].size() == (uint)cols);
        }
    }
    void test_life_constructor2()
    {
        int rows = 1;
        int cols = 1;
        Life<FredkinCell> game(rows, cols);
        CPPUNIT_ASSERT(game.rows == rows);
        CPPUNIT_ASSERT(game.cols == cols);
        CPPUNIT_ASSERT(game.live_cells == 0);
        CPPUNIT_ASSERT(game.turn == 0);
        CPPUNIT_ASSERT(game.grid.size() == (uint)rows);
        for (int i = 0; i < rows; ++i)
        {
            CPPUNIT_ASSERT(game.grid[i].size() == (uint)cols);
        }
    }
    void test_life_constructor3()
    {
        int rows = -1;
        int cols = 5;
        try
        {
            Life<ConwayCell> game(rows, cols);
            CPPUNIT_ASSERT(false);
        }
        catch(...)
        {
            CPPUNIT_ASSERT(true);
        }
    }

    // Add Cell
    void test_life_add_cell1()
    {
        ConwayCell c_alive(true);
        ConwayCell c_dead(0);
        FredkinCell f_alive(1);
        FredkinCell f_dead(0);
        Cell c_cell_alive = new ConwayCell(1);
        Cell c_cell_dead = new ConwayCell(0);
        Cell f_cell_alive = new FredkinCell(1);
        Cell f_cell_dead = new FredkinCell(0);
        Life<ConwayCell> game(1,1);
        CPPUNIT_ASSERT(game.grid[0][0].get_state() == false);
        game.add_cell(0,0,c_alive);
        CPPUNIT_ASSERT(game.grid[0][0].get_state() != false);
    }
    void test_life_add_cell2()
    {
        ConwayCell c_alive(true);
        ConwayCell c_dead(0);
        FredkinCell f_alive(1);
        FredkinCell f_dead(0);
        Cell c_cell_alive = new ConwayCell(1);
        Cell c_cell_dead = new ConwayCell(0);
        Cell f_cell_alive = new FredkinCell(1);
        Cell f_cell_dead = new FredkinCell(0);

        Life<Cell> game(3,3);
        game.add_cell(0,0,c_cell_alive);
        CPPUNIT_ASSERT(game.grid[0][0].get_state() != false);
    }
    void test_life_add_cell3()
    {
        ConwayCell c_alive(true);
        ConwayCell c_dead(0);
        FredkinCell f_alive(1);
        FredkinCell f_dead(0);
        Cell c_cell_alive = new ConwayCell(1);
        Cell c_cell_dead = new ConwayCell(0);
        Cell f_cell_alive = new FredkinCell(1);
        Cell f_cell_dead = new FredkinCell(0);

        Life<Cell> game(3,3);
        try
        {
            game.add_cell(0,4,c_cell_alive);
            CPPUNIT_ASSERT(false);
        }
        catch (...)
        {
            CPPUNIT_ASSERT(true);
        }
    }

    // Life evolve
    void test_life_evolve1()
    {
        ConwayCell c_alive(true);
        ConwayCell c_dead(0);
        FredkinCell f_alive(1);
        FredkinCell f_dead(0);
        Cell c_cell_alive = new ConwayCell(1);
        Cell c_cell_dead = new ConwayCell(0);
        Cell f_cell_alive = new FredkinCell(1);
        Cell f_cell_dead = new FredkinCell(0);

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

        game.evolve();
        ostringstream o;
        game.print_grid(o);
        CPPUNIT_ASSERT(o.str() ==   "Generation = 1, Population = 41.\n"
                                    "0---.0.01\n"
                                    "011-*-.--\n"
                                    "011-.0.0-\n"
                                    "0110.0.--\n"
                                    "011-.0.0-\n"
                                    "011-*-.--\n"
                                    "011-.0.0-\n"
                                    "0110.0.--\n"
                                    "0---.0.01\n\n");
    }
    void test_life_evolve2()
    {
        ConwayCell c_alive(true);
        ConwayCell c_dead(0);
        FredkinCell f_alive(1);
        FredkinCell f_dead(0);
        Cell c_cell_alive = new ConwayCell(1);
        Cell c_cell_dead = new ConwayCell(0);
        Cell f_cell_alive = new FredkinCell(1);
        Cell f_cell_dead = new FredkinCell(0);

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

        game.evolve();
        ostringstream o;
        game.print_grid(o);
        CPPUNIT_ASSERT(o.str() ==   "Generation = 1, Population = 3.\n"
                                    "...\n"
                                    "***\n"
                                    "...\n\n");
    }
    void test_life_evolve3()
    {
        ConwayCell c_alive(true);
        ConwayCell c_dead(0);
        FredkinCell f_alive(1);
        FredkinCell f_dead(0);
        Cell c_cell_alive = new ConwayCell(1);
        Cell c_cell_dead = new ConwayCell(0);
        Cell f_cell_alive = new FredkinCell(1);
        Cell f_cell_dead = new FredkinCell(0);

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

        game.evolve();
        ostringstream o;
        game.print_grid(o);
        CPPUNIT_ASSERT(o.str() ==   "Generation = 1, Population = 4.\n"
                                    "--0--\n"
                                    "-----\n"
                                    "0---0\n"
                                    "-----\n"
                                    "--0--\n\n");
    }
    void test_life_print1()
    {
        ConwayCell c_alive(true);
        ConwayCell c_dead(0);
        FredkinCell f_alive(1);
        FredkinCell f_dead(0);
        Cell c_cell_alive = new ConwayCell(1);
        Cell c_cell_dead = new ConwayCell(0);
        Cell f_cell_alive = new FredkinCell(1);
        Cell f_cell_dead = new FredkinCell(0);

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

        ostringstream o;
        game.print_grid(o);
        CPPUNIT_ASSERT(o.str() ==   "Generation = 0, Population = 38.\n"
                                    "-00-*-.-0\n"
                                    "-00-*-*-0\n"
                                    "-00-*-.-0\n"
                                    "-00-.-*-0\n"
                                    "-00-*-.-0\n"
                                    "-00-*-*-0\n"
                                    "-00-*-.-0\n"
                                    "-00-.-*-0\n"
                                    "-00-*-.-0\n\n");
    }
    void test_life_print2()
    {
        ConwayCell c_alive(true);
        ConwayCell c_dead(0);
        FredkinCell f_alive(1);
        FredkinCell f_dead(0);
        Cell c_cell_alive = new ConwayCell(1);
        Cell c_cell_dead = new ConwayCell(0);
        Cell f_cell_alive = new FredkinCell(1);
        Cell f_cell_dead = new FredkinCell(0);

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

        ostringstream o;
        game.print_grid(o);
        CPPUNIT_ASSERT(o.str() ==   "Generation = 0, Population = 3.\n"
                                    ".*.\n"
                                    ".*.\n"
                                    ".*.\n\n");
    }
    void test_life_print3()
    {
        ConwayCell c_alive(true);
        ConwayCell c_dead(0);
        FredkinCell f_alive(1);
        FredkinCell f_dead(0);
        Cell c_cell_alive = new ConwayCell(1);
        Cell c_cell_dead = new ConwayCell(0);
        Cell f_cell_alive = new FredkinCell(1);
        Cell f_cell_dead = new FredkinCell(0);

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

        ostringstream o;
        game.print_grid(o);
        CPPUNIT_ASSERT(o.str() ==   "Generation = 0, Population = 12.\n"
                                    "-0-0-\n"
                                    "0-0-0\n"
                                    "-0-0-\n"
                                    "0-0-0\n"
                                    "-0-0-\n\n");
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);
    // ConwayCell
    CPPUNIT_TEST(test_conway_constructor1);
    CPPUNIT_TEST(test_conway_constructor2);
    CPPUNIT_TEST(test_conway_constructor3);
    CPPUNIT_TEST(test_conway_print1);
    CPPUNIT_TEST(test_conway_print2);
    CPPUNIT_TEST(test_conway_print3);
    CPPUNIT_TEST(test_conway_write1);
    CPPUNIT_TEST(test_conway_write2);
    CPPUNIT_TEST(test_conway_write3);
    CPPUNIT_TEST(test_conway_flip_and_get_state1);
    CPPUNIT_TEST(test_conway_flip_and_get_state2);
    CPPUNIT_TEST(test_conway_flip_and_get_state3);
    CPPUNIT_TEST(test_conway_get_neighbor_array1);
    CPPUNIT_TEST(test_conway_get_neighbor_array2);
    CPPUNIT_TEST(test_conway_get_neighbor_array3);
    CPPUNIT_TEST(test_conway_should_change1);
    CPPUNIT_TEST(test_conway_should_change2);
    CPPUNIT_TEST(test_conway_should_change3);
    CPPUNIT_TEST(test_conway_clone1);
    CPPUNIT_TEST(test_conway_clone2);
    CPPUNIT_TEST(test_conway_clone3);
    // Cell
    CPPUNIT_TEST(test_cell_constructor1);
    CPPUNIT_TEST(test_cell_constructor2);
    CPPUNIT_TEST(test_cell_constructor3);
    CPPUNIT_TEST(test_cell_should_change1);
    CPPUNIT_TEST(test_cell_should_change2);
    CPPUNIT_TEST(test_cell_should_change3);
    CPPUNIT_TEST(test_cell_mutate1);
    CPPUNIT_TEST(test_cell_mutate2);
    CPPUNIT_TEST(test_cell_mutate3);
    CPPUNIT_TEST(test_cell_get_neighbor_array1);
    CPPUNIT_TEST(test_cell_get_neighbor_array2);
    CPPUNIT_TEST(test_cell_get_neighbor_array3);
    CPPUNIT_TEST(test_cell_print1);
    CPPUNIT_TEST(test_cell_print2);
    CPPUNIT_TEST(test_cell_print3);
    CPPUNIT_TEST(test_cell_flip_and_get_state1);
    CPPUNIT_TEST(test_cell_flip_and_get_state2);
    CPPUNIT_TEST(test_cell_flip_and_get_state3);
    // FredkinCell
    CPPUNIT_TEST(test_fredkin_constructor1);
    CPPUNIT_TEST(test_fredkin_constructor2);
    CPPUNIT_TEST(test_fredkin_constructor3);
    CPPUNIT_TEST(test_fredkin_print1);
    CPPUNIT_TEST(test_fredkin_print2);
    CPPUNIT_TEST(test_fredkin_print3);
    CPPUNIT_TEST(test_fredkin_write1);
    CPPUNIT_TEST(test_fredkin_write2);
    CPPUNIT_TEST(test_fredkin_write3);
    CPPUNIT_TEST(test_fredkin_flip_state1);
    CPPUNIT_TEST(test_fredkin_flip_state2);
    CPPUNIT_TEST(test_fredkin_flip_state3);
    CPPUNIT_TEST(test_fredkin_get_state1);
    CPPUNIT_TEST(test_fredkin_get_state2);
    CPPUNIT_TEST(test_fredkin_get_state3);
    CPPUNIT_TEST(test_fredkin_get_neighbor_array1);
    CPPUNIT_TEST(test_fredkin_get_neighbor_array2);
    CPPUNIT_TEST(test_fredkin_get_neighbor_array3);
    CPPUNIT_TEST(test_fredkin_should_change1);
    CPPUNIT_TEST(test_fredkin_should_change2);
    CPPUNIT_TEST(test_fredkin_should_change3);
    CPPUNIT_TEST(test_fredkin_clone1);
    CPPUNIT_TEST(test_fredkin_clone2);
    CPPUNIT_TEST(test_fredkin_clone3);

    // Life
    CPPUNIT_TEST(test_life_get_neighbors1);
    CPPUNIT_TEST(test_life_get_neighbors2);
    CPPUNIT_TEST(test_life_get_neighbors3);

    CPPUNIT_TEST(test_life_evolve_helper1);
    CPPUNIT_TEST(test_life_evolve_helper2);
    CPPUNIT_TEST(test_life_evolve_helper3);

    CPPUNIT_TEST(test_life_constructor1);
    CPPUNIT_TEST(test_life_constructor2);
    CPPUNIT_TEST(test_life_constructor3);

    CPPUNIT_TEST(test_life_add_cell1);
    CPPUNIT_TEST(test_life_add_cell2);
    CPPUNIT_TEST(test_life_add_cell3);

    CPPUNIT_TEST(test_life_evolve1);
    CPPUNIT_TEST(test_life_evolve2);
    CPPUNIT_TEST(test_life_evolve3);

    CPPUNIT_TEST(test_life_print1);
    CPPUNIT_TEST(test_life_print2);
    CPPUNIT_TEST(test_life_print3);
    
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestLife.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestLife::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
