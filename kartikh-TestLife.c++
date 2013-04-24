// ------------------------------------
// cs371p-life/TestLife.c++
// Copyright (C) 2013
// Kartik Hattangadi
// ------------------------------------

/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -pedantic -std=c++0x -Wall Allocator.c++ TestAllocator.c++ -o TestAllocator -lcppunit -ldl
    % valgrind TestAllocator >& TestAllocator.out
*/

// --------
// includes
// --------

#include <algorithm> // count
#include <iostream>  // ios_base
#include <memory>    // allocator

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define private public
#define protected public
#define class struct

#include "AbstractCell.h"
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Life.h"
#include "Handle.h"

// --------
// TestLife
// --------

struct TestLife : CppUnit::TestFixture {


    // --------------------
    // test_conwaycell_constr
    // --------------------

    void test_conwaycell_constr() {
      ConwayCell c(true);
      CPPUNIT_ASSERT(c._a == true);
      CPPUNIT_ASSERT(c._c == '*');
    }

    // --------------------
    // test_fredkincell_constr
    // --------------------

    void test_fredkincell_constr() {
      FredkinCell c(true);
      CPPUNIT_ASSERT(c._a == true);
      CPPUNIT_ASSERT(c._c == '0');
    }

    // ------------------
    // test_cell_constr_1
    // ------------------

    void test_cell_constr_1() {
      Cell c = new FredkinCell(true);
      CPPUNIT_ASSERT(c._p->_a == true);
      CPPUNIT_ASSERT(c._p->_c == '0');
    }
    
    // ------------------
    // test_cell_constr_2
    // ------------------

    void test_cell_constr_2() {
      Cell c = new ConwayCell(true);
      CPPUNIT_ASSERT(c._p->_a == true);
      CPPUNIT_ASSERT(c._p->_c == '*');
    }

    // -----------------
    // test_can_mutate_1
    // -----------------

    void test_can_mutate_1() {
      Cell c = new ConwayCell(true);
      CPPUNIT_ASSERT(c.can_mutate() == true);
    }

    // -----------------
    // test_can_mutate_2
    // -----------------

    void test_can_mutate_2() {
      ConwayCell c = new ConwayCell(true);
      CPPUNIT_ASSERT(c.can_mutate() == false);
    }
    
    // -----------------
    // test_can_mutate_3
    // -----------------

    void test_can_mutate_3() {
      FredkinCell c = new FredkinCell(true);
      CPPUNIT_ASSERT(c.can_mutate() == false);
    }

    // -----------------------
    // test_conway_next_move_1
    // -----------------------

    void test_conway_next_move_1() {
      ConwayCell c(true);
      CPPUNIT_ASSERT(c.next_move(1, 1) == AbstractCell::A_to_A);
    }

    // -----------------------
    // test_conway_next_move_2
    // -----------------------

    void test_conway_next_move_2() {
      ConwayCell c(true);
      CPPUNIT_ASSERT(c.next_move(2, 1) == AbstractCell::A_to_A);
    }

    // -----------------------
    // test_conway_next_move_3
    // -----------------------

    void test_conway_next_move_3() {
      ConwayCell c(false);
      CPPUNIT_ASSERT(c.next_move(2, 0) == AbstractCell::D_to_D);
    }

    // -----------------------
    // test_conway_next_move_4
    // -----------------------

    void test_conway_next_move_4() {
      ConwayCell c(false);
      CPPUNIT_ASSERT(c.next_move(3, 0) == AbstractCell::D_to_A);
    }

    // ------------------------
    // test_fredkin_next_move_1
    // ------------------------

    void test_fredkin_next_move_1() {
      FredkinCell c(true);
      CPPUNIT_ASSERT(c.next_move(1, 1) == AbstractCell::A_to_A);
    }

    // ------------------------
    // test_fredkin_next_move_2
    // ------------------------

    void test_fredkin_next_move_2() {
      FredkinCell c(true);
      CPPUNIT_ASSERT(c.next_move(2, 0) == AbstractCell::A_to_D);
    }

    // ------------------------
    // test_fredkin_next_move_3
    // ------------------------

    void test_fredkin_next_move_3() {
      FredkinCell c(false);
      CPPUNIT_ASSERT(c.next_move(1, 3) == AbstractCell::D_to_A);
    }

    // ------------------------
    // test_fredkin_next_move_4
    // ------------------------

    void test_fredkin_next_move_4() {
      FredkinCell c(false);
      CPPUNIT_ASSERT(c.next_move(2, 1) == AbstractCell::D_to_D);
    }
    
    // ------------------------
    // test_fredkin_next_move_5
    // ------------------------

    void test_fredkin_next_move_5() {
      FredkinCell c(true);
      c.age = 1;
      CPPUNIT_ASSERT(c.next_move(1, 2) == AbstractCell::MUTATE);
    }
    
    // ------------------
    // test_conway_grow_1
    // ------------------

    void test_conway_grow_1() {
      ConwayCell c(true);
      c.grow(AbstractCell::A_to_A);
      CPPUNIT_ASSERT(c._c == '*');
    }
    
    // ------------------
    // test_conway_grow_2
    // ------------------

    void test_conway_grow_2() {
      ConwayCell c(true);
      c.grow(AbstractCell::A_to_D);
      CPPUNIT_ASSERT(c._c == '.');
    }
    
    // ------------------
    // test_conway_grow_3
    // ------------------

    void test_conway_grow_3() {
      ConwayCell c(false);
      c.grow(AbstractCell::D_to_A);
      CPPUNIT_ASSERT(c._c == '*');
    }
    
    // ------------------
    // test_conway_grow_4
    // ------------------

    void test_conway_grow_4() {
      ConwayCell c(false);
      c.grow(AbstractCell::D_to_D);
      CPPUNIT_ASSERT(c._c == '.');
    }
    
    // -------------------
    // test_fredkin_grow_1
    // -------------------

    void test_fredkin_grow_1() {
      FredkinCell c(true);
      c.grow(AbstractCell::A_to_A);
      CPPUNIT_ASSERT(c._c == '1');
    }
    
    // -------------------
    // test_fredkin_grow_2
    // -------------------

    void test_fredkin_grow_2() {
      FredkinCell c(true);
      c.grow(AbstractCell::A_to_D);
      CPPUNIT_ASSERT(c._c == '-');
    }
    
    // -------------------
    // test_fredkin_grow_3
    // -------------------

    void test_fredkin_grow_3() {
      FredkinCell c(false);
      c.grow(AbstractCell::D_to_A);
      CPPUNIT_ASSERT(c._c == '0');
    }
    
    // -------------------
    // test_fredkin_grow_4
    // -------------------

    void test_fredkin_grow_4() {
      FredkinCell c(false);
      c.grow(AbstractCell::D_to_D);
      CPPUNIT_ASSERT(c._c == '-');
    }

    // ------------------
    // test_life_constr_1
    // ------------------

    void test_life_constr_1() {
      Life<ConwayCell> l(10, 10, ConwayCell(false));
      CPPUNIT_ASSERT(l.gen == 0);
      CPPUNIT_ASSERT(l.pop == 0);
      CPPUNIT_ASSERT(l._x == 10);
      CPPUNIT_ASSERT(l._y == 10);
    }

    // ------------------
    // test_life_constr_2
    // ------------------

    void test_life_constr_2() {
      Life<FredkinCell> l(10, 10, FredkinCell(false));
      CPPUNIT_ASSERT(l.gen == 0);
      CPPUNIT_ASSERT(l.pop == 0);
      CPPUNIT_ASSERT(l._x == 10);
      CPPUNIT_ASSERT(l._y == 10);
    }
    
    // ------------------
    // test_life_constr_3
    // ------------------

    void test_life_constr_3() {
      Life<Cell> l(10, 10, new FredkinCell(false));
      CPPUNIT_ASSERT(l.gen == 0);
      CPPUNIT_ASSERT(l.pop == 0);
      CPPUNIT_ASSERT(l._x == 10);
      CPPUNIT_ASSERT(l._y == 10);
    }

    // -----------------------
    // test_life_constr_file_1
    // -----------------------

    void test_life_constr_file_1() {
      Life<ConwayCell> l("RunLifeConway.in");
      CPPUNIT_ASSERT(l._x == 109);
      CPPUNIT_ASSERT(l._y == 69);
      CPPUNIT_ASSERT(l.grid[10][10]._a == false);
      CPPUNIT_ASSERT(l.grid[10][10]._c == '.');
      CPPUNIT_ASSERT(l.grid[10][11]._a == false);
      CPPUNIT_ASSERT(l.grid[10][11]._c == '.');
      CPPUNIT_ASSERT(l.grid[72][34]._a == true);
      CPPUNIT_ASSERT(l.grid[72][34]._c == '*');
    }

    // -------------------
    // test_life_addcell_1
    // -------------------

    void test_life_addcell_1() {
      Life<FredkinCell> l(10, 10, FredkinCell(false));
      l.add_cell(0, 0, FredkinCell(true));
      CPPUNIT_ASSERT(l.pop == 1);
      CPPUNIT_ASSERT(l.grid[0][0]._c == '0');
      CPPUNIT_ASSERT(l.grid[0][0]._a == true);
    }

    // -------------------
    // test_life_addcell_2
    // -------------------

    void test_life_addcell_2() {
      Life<ConwayCell> l(10, 10, ConwayCell(false));
      l.add_cell(0, 0, ConwayCell(true));
      CPPUNIT_ASSERT(l.pop == 1);
      CPPUNIT_ASSERT(l.grid[0][0]._c == '*');
      CPPUNIT_ASSERT(l.grid[0][0]._a == true);
    }
    
    // -------------------
    // test_life_addcell_3
    // -------------------

    void test_life_addcell_3() {
      Life<Cell> l(10, 10, new FredkinCell(false));
      l.add_cell(0, 0, new FredkinCell(true));
      CPPUNIT_ASSERT(l.pop == 1);
      CPPUNIT_ASSERT(l.grid[0][0]._p->_c == '0');
      CPPUNIT_ASSERT(l.grid[0][0]._p->_a == true);
    }

    // ------------------
    // test_life_mutate_1
    // ------------------

    void test_life_mutate_1() {
      Life<Cell> l(10, 10, new FredkinCell(true));
      l.moves[0][0] = AbstractCell::MUTATE;
      l.mutate(0, 0);
      CPPUNIT_ASSERT(l.grid[0][0]._p->_a == true);
      CPPUNIT_ASSERT(l.grid[0][0]._p->_c == '*');
    }
    
    // ------------------
    // test_life_mutate_2
    // ------------------

    void test_life_mutate_2() {
      Life<Cell> l(10, 10, new FredkinCell(true));
      l.moves[0][0] = AbstractCell::A_to_A;
      l.mutate(0, 0);
      CPPUNIT_ASSERT(l.grid[0][0]._p->_a == true);
      CPPUNIT_ASSERT(l.grid[0][0]._p->_c == '0');
    }

    // ------------------
    // test_life_next_gen
    // ------------------

    void test_life_next_gen() {
      Life<Cell> l(2, 2, new FredkinCell(true));
      l.add_cell(0, 0, new FredkinCell(false));
      l.add_cell(1, 0, new FredkinCell(false));
      l.next_gen();
      l.next_gen();
    }

    // --------------------------
    // test_life_find_neigh_1
    // --------------------------

    void test_life_find_neigh_1() {
      Life<Cell> l("RunLifeConway.in");
      CPPUNIT_ASSERT(l.find_ord_neigh(36, 33) == 2);
      CPPUNIT_ASSERT(l.find_card_neigh(36, 33) == 1);
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST(test_conwaycell_constr);
    CPPUNIT_TEST(test_fredkincell_constr);
    CPPUNIT_TEST(test_cell_constr_1);
    CPPUNIT_TEST(test_cell_constr_2);
    CPPUNIT_TEST(test_can_mutate_1);
    CPPUNIT_TEST(test_can_mutate_2);
    CPPUNIT_TEST(test_can_mutate_3);
    CPPUNIT_TEST(test_conway_next_move_1);
    CPPUNIT_TEST(test_conway_next_move_2);
    CPPUNIT_TEST(test_conway_next_move_3);
    CPPUNIT_TEST(test_conway_next_move_4);
    CPPUNIT_TEST(test_fredkin_next_move_1);
    CPPUNIT_TEST(test_fredkin_next_move_2);
    CPPUNIT_TEST(test_fredkin_next_move_3);
    CPPUNIT_TEST(test_fredkin_next_move_4);
    CPPUNIT_TEST(test_fredkin_next_move_5);
    CPPUNIT_TEST(test_conway_grow_1);
    CPPUNIT_TEST(test_conway_grow_2);
    CPPUNIT_TEST(test_conway_grow_3);
    CPPUNIT_TEST(test_conway_grow_4);
    CPPUNIT_TEST(test_fredkin_grow_1);
    CPPUNIT_TEST(test_fredkin_grow_2);
    CPPUNIT_TEST(test_fredkin_grow_3);
    CPPUNIT_TEST(test_fredkin_grow_4);
    CPPUNIT_TEST(test_life_constr_1);
    CPPUNIT_TEST(test_life_constr_2);
    CPPUNIT_TEST(test_life_constr_3);
    CPPUNIT_TEST(test_life_constr_file_1);
    CPPUNIT_TEST(test_life_addcell_1);
    CPPUNIT_TEST(test_life_addcell_2);
    CPPUNIT_TEST(test_life_addcell_3);
    CPPUNIT_TEST(test_life_mutate_1);
    CPPUNIT_TEST(test_life_mutate_2);
    CPPUNIT_TEST(test_life_find_neigh_1);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);    // turn off synchronization with C I/O
    cout << "TestLife.c++" << endl;

    CppUnit::TextTestRunner tr;

    tr.addTest(TestLife::suite());

    tr.run();

    cout << "Done." << endl;
    return 0;}
