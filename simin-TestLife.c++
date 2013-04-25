// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// --------------------------------

/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -lcppunit -ldl -pedantic -std=c++0x -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz.c++.app
    % valgrind TestCollatz.c++.app >& TestCollatz.c++.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <map>
#include <fstream>
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#include "Life.h"
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"

// -----------
// TestCollatz
// -----------

struct TestLife : CppUnit::TestFixture {
    //--------------------
    // Tests for Cell
    //--------------------
    void test_cell_construct_cclive() {
        Cell c = new ConwayCell(0);
        CPPUNIT_ASSERT(c.is_alive());
    }

    void test_cell_construct_fclive() {
        Cell c = new FredkinCell(0, 0);
        CPPUNIT_ASSERT(c.is_alive());
    }
    
    void test_cell_construct_cfdead() {
        Cell f = new FredkinCell(1, 0);
        Cell c = new ConwayCell(1);
        CPPUNIT_ASSERT(!f.is_alive());
        CPPUNIT_ASSERT(!c.is_alive());
    }

    void test_set_neighbors_1() {
       Cell c = new ConwayCell(0);
       c.set_neighbors(2, 3);
       CPPUNIT_ASSERT(c.get_neighbors() == 2);
    }
    
    void test_set_neighbors_2() {
       Cell f = new FredkinCell(0, 0);
       f.set_neighbors(2, 3);
       CPPUNIT_ASSERT(f.get_neighbors() == 3);
    }

    void test_set_neighbors_3() {
       Cell f = new FredkinCell(0, 0);
       f.set_neighbors(2, 3);
       CPPUNIT_ASSERT(f.get_neighbors() == 3);
       Cell c = new ConwayCell(0);
       c.set_neighbors(6, 7);
       CPPUNIT_ASSERT(c.get_neighbors() == 6);
    }

    void test_need_kill_c() {
       Cell c = new ConwayCell(0);
       CPPUNIT_ASSERT(c.is_alive());
       c.set_neighbors(3, -1);
       CPPUNIT_ASSERT(!c.need_kill());
       c.set_neighbors(4, -1);
       CPPUNIT_ASSERT(c.need_kill());
    }

    void test_need_kill_f() {
       Cell c = new FredkinCell(0,0);
       CPPUNIT_ASSERT(c.is_alive());
       c.set_neighbors(-1, 1);
       CPPUNIT_ASSERT(!c.need_kill());
       c.set_neighbors(-1, 2);
       CPPUNIT_ASSERT(c.need_kill());
    }

    void test_need_revive_c() {
       Cell c = new ConwayCell(1);
       CPPUNIT_ASSERT(!c.is_alive());
       c.set_neighbors(4, -1);
       CPPUNIT_ASSERT(!c.need_revive());
       c.set_neighbors(3, -1);
       CPPUNIT_ASSERT(c.need_revive());
    }

    void test_need_revive_f() {
       Cell c = new FredkinCell(1, 0);
       CPPUNIT_ASSERT(!c.is_alive());
       c.set_neighbors(-1, 0);
       CPPUNIT_ASSERT(!c.need_revive());
       c.set_neighbors(-1, 1);
       CPPUNIT_ASSERT(c.need_revive());
    }
    
    void test_kill_c() {
        Cell c = new ConwayCell(0);
        CPPUNIT_ASSERT(c.is_alive());
        c.kill();
        CPPUNIT_ASSERT(!c.is_alive());
    }
    
    void test_revive_c() {
        Cell c = new ConwayCell(1);
        CPPUNIT_ASSERT(!c.is_alive());
        c.revive();
        CPPUNIT_ASSERT(c.is_alive());
    }

    void test_kill_f() {
        Cell c = new FredkinCell(0, 1);
        CPPUNIT_ASSERT(c.is_alive());
        c.kill();
        CPPUNIT_ASSERT(!c.is_alive());
    }
    
    void test_revive_f() {
        Cell c = new FredkinCell(1, 1);
        CPPUNIT_ASSERT(!c.is_alive());
        c.revive();
        CPPUNIT_ASSERT(c.is_alive());
    }


    void test_die_c() {
        Cell c = new ConwayCell(0);
        CPPUNIT_ASSERT(c.is_alive());
        c.set_neighbors(4, -1);
        CPPUNIT_ASSERT(c.need_kill());
        c.to_live_or_die();
        CPPUNIT_ASSERT(!c.is_alive());
    }

    void test_live_c() {
       Cell c = new ConwayCell(1);
       CPPUNIT_ASSERT(!c.is_alive());
       c.set_neighbors(3, -1);
       CPPUNIT_ASSERT(c.need_revive());
       c.to_live_or_die();
       CPPUNIT_ASSERT(c.is_alive());
    }

    void test_die_f() {
       Cell c = new FredkinCell(0, 1);
       CPPUNIT_ASSERT(c.is_alive());
       c.set_neighbors(-1, 2);
       CPPUNIT_ASSERT(c.need_kill());
       c.to_live_or_die();
       CPPUNIT_ASSERT(!c.is_alive());
    }
 
    void test_live_f() {
       Cell c = new FredkinCell(1, 1);
       CPPUNIT_ASSERT(!c.is_alive());
       c.set_neighbors(-1, 1);
       CPPUNIT_ASSERT(c.need_revive());
       c.to_live_or_die();
       CPPUNIT_ASSERT(c.is_alive());
    }

    void char_live_c() {
       Cell c = new ConwayCell(0);
       std::cout << std::endl;
       CPPUNIT_ASSERT((char)c == '*');
    }
    void char_dead_c() {
       Cell c = new ConwayCell(1);
       CPPUNIT_ASSERT((char)c == '.');
    }
    void char_live_f() {
       Cell c = new FredkinCell(0, 1);
       CPPUNIT_ASSERT((char)c == '1');
       c = new FredkinCell(0, 10);
       CPPUNIT_ASSERT((char)c == '+');
    }
    void char_dead_f() {
       Cell c = new FredkinCell(1, 2);
       CPPUNIT_ASSERT((char)c == '-');
    }

    // ----
    // Life
    // ----

    void make_life_1() {
        
        Life<ConwayCell, 1, 1> l;
        l.board[0][0] = ConwayCell(0);
        //l.print_grid(0);
        l.count_neighbors(0, 0);
        CPPUNIT_ASSERT(l.board[0][0].get_neighbors() == 0);
        CPPUNIT_ASSERT(l.board[0][0].is_alive());

        l.simulate_moves(1);
        CPPUNIT_ASSERT(!l.board[0][0].is_alive()); 
        //l.print_grid(1);
    }

    void make_life_2() {
        
        Life<ConwayCell, 3, 3> l;
        l.board[0][0] = ConwayCell(1);
        l.board[1][0] = ConwayCell(0);
        l.board[1][1] = ConwayCell(0);
        l.board[0][1] = ConwayCell(0);

        //l.print_grid(0);
        l.count_neighbors(0, 0);
        CPPUNIT_ASSERT(l.board[0][0].get_neighbors() == 3);
        CPPUNIT_ASSERT(!l.board[0][0].is_alive());

        l.simulate_moves(1);
        CPPUNIT_ASSERT(l.board[0][0].is_alive()); 
        //l.print_grid(1);
    }

     void make_life_3() {
        
        Life<FredkinCell, 1, 1> l;
        l.board[0][0] = FredkinCell(0, 0);
        
        //l.print_grid(0);
        l.count_neighbors(0, 0);
        CPPUNIT_ASSERT(l.board[0][0].get_neighbors() == 0);
        CPPUNIT_ASSERT(l.board[0][0].is_alive());

        l.simulate_moves(1);
        CPPUNIT_ASSERT(!l.board[0][0].is_alive()); 
        //l.print_grid(1);
    }

    void make_life_4() {
        
        Life<FredkinCell, 1, 2> l;
        l.board[0][0] = FredkinCell(1, 0);
        l.board[0][1] = FredkinCell(0, 0);
       // l.print_grid(0);
        l.count_neighbors(0, 0);
        CPPUNIT_ASSERT(l.board[0][0].get_neighbors() == 1);
        CPPUNIT_ASSERT(!l.board[0][0].is_alive());
        l.count_neighbors(1, 0);
        CPPUNIT_ASSERT(l.board[0][1].get_neighbors() == 0);
        CPPUNIT_ASSERT(l.board[0][1].is_alive());

        l.simulate_moves(1);
        CPPUNIT_ASSERT(l.board[0][0].is_alive()); 
        CPPUNIT_ASSERT(!l.board[0][1].is_alive()); 

       // l.print_grid(1);
    }

    void make_life_5() {
        
        Life<FredkinCell, 1, 3> l;
        l.board[0][0] = FredkinCell(1, 0);
        l.board[0][1] = FredkinCell(0, 0);
        l.board[0][2] = FredkinCell(0, 0);

       // l.print_grid(0);

        l.count_neighbors(0, 0);
        CPPUNIT_ASSERT(l.board[0][0].get_neighbors() == 1);
        CPPUNIT_ASSERT(!l.board[0][0].is_alive());
        
        l.count_neighbors(1, 0);
        CPPUNIT_ASSERT(l.board[0][1].get_neighbors() == 1);
        CPPUNIT_ASSERT(l.board[0][1].is_alive());

        l.count_neighbors(2, 0);
        CPPUNIT_ASSERT(l.board[0][2].get_neighbors() == 1);
        CPPUNIT_ASSERT(l.board[0][2].is_alive());

        l.simulate_moves(1);
        CPPUNIT_ASSERT(l.board[0][0].is_alive()); 
        CPPUNIT_ASSERT(l.board[0][1].is_alive()); 
        CPPUNIT_ASSERT(l.board[0][2].is_alive());

        //l.print_grid(1);
    }

    void make_life_6() {
        
        Life<FredkinCell, 2, 2> l;
        l.board[0][0] = FredkinCell(0, 0);
        l.board[1][1] = FredkinCell(0, 0);

       // l.print_grid(0);

        l.count_neighbors(0, 0);
        CPPUNIT_ASSERT(l.board[0][0].get_neighbors() == 0);
        CPPUNIT_ASSERT(l.board[0][0].is_alive());
        
        l.count_neighbors(1, 1);
        CPPUNIT_ASSERT(l.board[1][1].get_neighbors() == 0);
        CPPUNIT_ASSERT(l.board[1][1].is_alive());

        l.simulate_moves(1);
        CPPUNIT_ASSERT(!l.board[0][0].is_alive()); 
        CPPUNIT_ASSERT(!l.board[1][1].is_alive()); 

       // l.print_grid(1);
    }

    void make_life_7() {
        
        Life<Cell, 1, 3> l;
        l.board[0][0] = new FredkinCell(0, 0);
        l.board[0][1] = new FredkinCell(0, 0);
        l.board[0][2] = new FredkinCell(1, 0);
       // l.print_grid(0);

        l.count_neighbors(0, 0);
        CPPUNIT_ASSERT(l.board[0][0].get_neighbors() == 1);
        CPPUNIT_ASSERT(l.board[0][0].is_alive());
        
        l.count_neighbors(1, 0);
        CPPUNIT_ASSERT(l.board[0][1].get_neighbors() == 1);
        CPPUNIT_ASSERT(l.board[0][1].is_alive());

        l.count_neighbors(2, 0);
        CPPUNIT_ASSERT(l.board[0][2].get_neighbors() == 1);
        CPPUNIT_ASSERT(!l.board[0][2].is_alive());

        l.simulate_moves(1);
        CPPUNIT_ASSERT(l.board[0][0].is_alive()); 
        CPPUNIT_ASSERT(l.board[0][1].is_alive()); 
        CPPUNIT_ASSERT(l.board[0][2].is_alive());

       // l.print_grid(1);


        l.count_neighbors(0, 0);
        CPPUNIT_ASSERT(l.board[0][0].get_neighbors() == 1);
        CPPUNIT_ASSERT(l.board[0][0].is_alive());
        
        l.count_neighbors(1, 0);
        CPPUNIT_ASSERT(l.board[0][1].get_neighbors() == 2);
        CPPUNIT_ASSERT(l.board[0][1].is_alive());

        l.count_neighbors(2, 0);
        CPPUNIT_ASSERT(l.board[0][2].get_neighbors() == 1);
        CPPUNIT_ASSERT(l.board[0][2].is_alive());

        l.simulate_moves(1);
        CPPUNIT_ASSERT(l.board[0][0].is_alive()); 
        CPPUNIT_ASSERT(!l.board[0][1].is_alive()); 
        CPPUNIT_ASSERT(l.board[0][2].is_alive());

       // l.print_grid(2);

    }


    void make_life_8() {
        
        Life<FredkinCell, 1, 3> l;
        l.board[0][0] = FredkinCell(0, 0);
        l.board[0][1] = FredkinCell(0, 0);
        l.board[0][2] = FredkinCell(1, 0);
       // l.print_grid(0);

        l.count_neighbors(0, 0);
        CPPUNIT_ASSERT(l.board[0][0].get_neighbors() == 1);
        CPPUNIT_ASSERT(l.board[0][0].is_alive());
        
        l.count_neighbors(1, 0);
        CPPUNIT_ASSERT(l.board[0][1].get_neighbors() == 1);
        CPPUNIT_ASSERT(l.board[0][1].is_alive());

        l.count_neighbors(2, 0);
        CPPUNIT_ASSERT(l.board[0][2].get_neighbors() == 1);
        CPPUNIT_ASSERT(!l.board[0][2].is_alive());

        l.simulate_moves(1);
        CPPUNIT_ASSERT(l.board[0][0].is_alive()); 
        CPPUNIT_ASSERT(l.board[0][1].is_alive()); 
        CPPUNIT_ASSERT(l.board[0][2].is_alive());

       // l.print_grid(1);


        l.count_neighbors(0, 0);
        CPPUNIT_ASSERT(l.board[0][0].get_neighbors() == 1);
        CPPUNIT_ASSERT(l.board[0][0].is_alive());
        
        l.count_neighbors(1, 0);
        CPPUNIT_ASSERT(l.board[0][1].get_neighbors() == 2);
        CPPUNIT_ASSERT(l.board[0][1].is_alive());

        l.count_neighbors(2, 0);
        CPPUNIT_ASSERT(l.board[0][2].get_neighbors() == 1);
        CPPUNIT_ASSERT(l.board[0][2].is_alive());

        l.simulate_moves(1);
        CPPUNIT_ASSERT(l.board[0][0].is_alive()); 
        CPPUNIT_ASSERT(!l.board[0][1].is_alive()); 
        CPPUNIT_ASSERT(l.board[0][2].is_alive());

       // l.print_grid(2);

    }


    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST(test_cell_construct_cclive);
    CPPUNIT_TEST(test_cell_construct_fclive);
    CPPUNIT_TEST(test_cell_construct_cfdead);
    CPPUNIT_TEST(test_set_neighbors_1);
    CPPUNIT_TEST(test_set_neighbors_2);
    CPPUNIT_TEST(test_set_neighbors_3);
    CPPUNIT_TEST(test_need_kill_c);
    CPPUNIT_TEST(test_need_kill_f);
    CPPUNIT_TEST(test_need_revive_c);
    CPPUNIT_TEST(test_need_revive_f);
    CPPUNIT_TEST(test_kill_c);
    CPPUNIT_TEST(test_revive_c);
    CPPUNIT_TEST(test_kill_f);
    CPPUNIT_TEST(test_revive_f);
    CPPUNIT_TEST(test_die_c);
    CPPUNIT_TEST(test_live_c);
    CPPUNIT_TEST(test_die_f);
    CPPUNIT_TEST(test_live_f);
    CPPUNIT_TEST(char_live_c);
    CPPUNIT_TEST(char_dead_c);
    CPPUNIT_TEST(char_live_f);
    CPPUNIT_TEST(char_dead_f);
    CPPUNIT_TEST(make_life_1);
    CPPUNIT_TEST(make_life_2);
    CPPUNIT_TEST(make_life_3);
    CPPUNIT_TEST(make_life_4);
    CPPUNIT_TEST(make_life_5);
    CPPUNIT_TEST(make_life_6);
    CPPUNIT_TEST(make_life_7);
    CPPUNIT_TEST(make_life_8);
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
