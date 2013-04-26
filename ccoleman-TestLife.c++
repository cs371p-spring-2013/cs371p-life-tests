// -------------
// TestLife.c++
// Clare Coleman
// -------------

/*
To test the program:
% ls /usr/include/cppunit/
...
TestFixture.h
...
% locate libcppunit.a
/usr/lib/libcppunit.a
% g++ -pedantic -std=c++0x -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz.c++.app -lcppunit -ldl
% valgrind TestCollatz.c++.app >& TestCollatz.c++.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <string> // ==
#include <vector>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TextTestRunner

#define class struct
#define private public
#define protected public

#include "Life.h"

using namespace std;

struct TestLife: CppUnit::TestFixture {
    // ------
    // Conway
    // ------

    void test_conway_construct_1 () {
       ConwayCell cc;
       CPPUNIT_ASSERT(!(cc.live));
       CPPUNIT_ASSERT(!(cc.nextLive));
       CPPUNIT_ASSERT(cc._c == '.');
       CPPUNIT_ASSERT(cc._nn == 8);
    }

    void test_conway_construct_2 () {
       ConwayCell cc('*');
       CPPUNIT_ASSERT(cc.live);
       CPPUNIT_ASSERT(!(cc.nextLive));
       CPPUNIT_ASSERT(cc._c == '*');
       CPPUNIT_ASSERT(cc._nn == 8);
    }
  
    void test_conway_construct_3 () {
       try {
         ConwayCell cc('x');
       } catch(const invalid_argument&) { 
         CPPUNIT_ASSERT(true);
         return;
       }

       CPPUNIT_ASSERT(false);
    }
  
    void test_conway_construct_4 () {
       try {
         ConwayCell cc('6');
       } catch(const invalid_argument&) { 
         CPPUNIT_ASSERT(true);
         return;
       }

       CPPUNIT_ASSERT(false);
    }

    void test_conway_equals_1 () {
       ConwayCell c1;
       ConwayCell c2;
       CPPUNIT_ASSERT(c1.equals(c2));
    }

    void test_conway_equals_2 () {
       ConwayCell c1;
       ConwayCell c2;
       CPPUNIT_ASSERT(c1 == c2);
    }

    void test_conway_equals_3 () {
       ConwayCell c1('*');
       ConwayCell c2('*');
       CPPUNIT_ASSERT(c1 == c2);
    }

    void test_conway_equals_4 () {
       ConwayCell c1('*');
       ConwayCell c2('*');
       CPPUNIT_ASSERT(c1.equals(c2));
    }

    void test_conway_clone_1 () {
       ConwayCell cc;
       ConwayCell* pcc = cc.clone();
       CPPUNIT_ASSERT(*pcc == cc);
    }
  
    void test_conway_clone_2 () {
       ConwayCell cc('*');
       ConwayCell* pcc = cc.clone();
       CPPUNIT_ASSERT(*pcc == cc);
    }
  
    void test_conway_clone_3 () {
       ConwayCell cc;
       ConwayCell* pcc = cc.clone();
       CPPUNIT_ASSERT(pcc != &cc);
    }
  
    void test_conway_setNextAlive_1 () {
       ConwayCell cc;
       int pop = 0;
       CPPUNIT_ASSERT(!(cc.live));
       cc.setNextAlive(2, pop);
       CPPUNIT_ASSERT(!(cc.nextLive));
       CPPUNIT_ASSERT(pop == 0);
    }
  
    void test_conway_setNextAlive_2 () {
       ConwayCell cc;
       int pop = 0;
       CPPUNIT_ASSERT(!(cc.live));
       cc.setNextAlive(3, pop); 
       CPPUNIT_ASSERT(cc.nextLive);
       CPPUNIT_ASSERT(pop == 1);
    }
  
    void test_conway_setNextAlive_3 () {
       ConwayCell cc;
       int pop = 135;
       CPPUNIT_ASSERT(!(cc.live));
       cc.setNextAlive(4, pop);
       CPPUNIT_ASSERT(!(cc.nextLive));
       CPPUNIT_ASSERT(pop == 135);
    }

    void test_conway_setNextAlive_4 () {
       ConwayCell cc('*');
       int pop = 24;
       CPPUNIT_ASSERT(cc.live);
       cc.setNextAlive(3, pop);
       CPPUNIT_ASSERT(cc.nextLive);
       CPPUNIT_ASSERT(pop == 24);
       cc.setNextAlive(2, pop);
       CPPUNIT_ASSERT(cc.nextLive);
       CPPUNIT_ASSERT(pop == 24);
       cc.setNextAlive(1, pop);
       CPPUNIT_ASSERT(!(cc.nextLive));
       CPPUNIT_ASSERT(pop == 23);
       cc.setNextAlive(4, pop);
       CPPUNIT_ASSERT(!(cc.nextLive));
       CPPUNIT_ASSERT(pop == 22);
    }
  
    void test_conway_updateState_1() {
       ConwayCell cc;
       CPPUNIT_ASSERT(!(cc.live));
       CPPUNIT_ASSERT(!(cc.nextLive));
       CPPUNIT_ASSERT(cc._c == '.');
       cc.updateState();
       CPPUNIT_ASSERT(!(cc.live));
       CPPUNIT_ASSERT(!(cc.nextLive));
       CPPUNIT_ASSERT(cc._c == '.');
    }

    void test_conway_updateState_2() {
       ConwayCell cc('*');
       CPPUNIT_ASSERT(cc.live);
       CPPUNIT_ASSERT(!(cc.nextLive));
       CPPUNIT_ASSERT(cc._c == '*');
       cc.updateState();
       CPPUNIT_ASSERT(!(cc.live));
       CPPUNIT_ASSERT(!(cc.nextLive));
       CPPUNIT_ASSERT(cc._c == '.');
    }

    void test_conway_updateState_3() {
       ConwayCell cc('*');
       int pop = 2;
       cc.setNextAlive(2, pop);
       CPPUNIT_ASSERT(cc.live);
       CPPUNIT_ASSERT(cc.nextLive);
       CPPUNIT_ASSERT(cc._c == '*');
       cc.updateState();
       CPPUNIT_ASSERT(cc.live);
       CPPUNIT_ASSERT(!(cc.nextLive));
       CPPUNIT_ASSERT(cc._c == '*');
    }

    void test_conway_updateState_4() {
       ConwayCell cc;
       int pop = 2;
       cc.setNextAlive(3, pop);
       CPPUNIT_ASSERT(!(cc.live));
       CPPUNIT_ASSERT(cc.nextLive);
       CPPUNIT_ASSERT(cc._c == '.');
       cc.updateState();
       CPPUNIT_ASSERT(cc.live);
       CPPUNIT_ASSERT(!(cc.nextLive));
       CPPUNIT_ASSERT(cc._c == '*');
    }

    // -------
    // Fredkin
    // -------
  
   void test_fredkin_construct_1 () {
       FredkinCell fc;
       CPPUNIT_ASSERT(!(fc.live));
       CPPUNIT_ASSERT(!(fc.nextLive));
       CPPUNIT_ASSERT(fc._c == '-');
       CPPUNIT_ASSERT(fc._nn == 4);
    }

    void test_fredkin_construct_2 () {
       FredkinCell fc('0');
       CPPUNIT_ASSERT(fc.live);
       CPPUNIT_ASSERT(!(fc.nextLive));
       CPPUNIT_ASSERT(fc._nn == 4);
       CPPUNIT_ASSERT(fc._c == '0');
    }
  
    void test_fredkin_construct_3 () {
       try {
         FredkinCell fc('*');
       } catch(const invalid_argument&) { 
         CPPUNIT_ASSERT(true);
         return;
       }

       CPPUNIT_ASSERT(false);
    }
  
    void test_fredkin_construct_4 () {
       try {
         FredkinCell fc('M');
       } catch(const invalid_argument&) { 
         CPPUNIT_ASSERT(true);
         return;
       }

       CPPUNIT_ASSERT(false);
    }

    void test_fredkin_equals_1 () {
       FredkinCell c1;
       FredkinCell c2;
       CPPUNIT_ASSERT(c1.equals(c2));
    }

    void test_fredkin_equals_2 () {
       FredkinCell c1;
       FredkinCell c2;
       CPPUNIT_ASSERT(c1 == c2);
    }

    void test_fredkin_equals_3 () {
       FredkinCell c1('5');
       FredkinCell c2('5');
       CPPUNIT_ASSERT(c1 == c2);
    }

    void test_fredkin_equals_4 () {
       FredkinCell c1('0');
       FredkinCell c2('2');
       CPPUNIT_ASSERT(!(c1.equals(c2)));
    }

    void test_fredkin_clone_1 () {
       FredkinCell cc;
       FredkinCell* pcc = cc.clone();
       CPPUNIT_ASSERT(*pcc == cc);
    }
  
    void test_fredkin_clone_2 () {
       FredkinCell cc('3');
       FredkinCell* pcc = cc.clone();
       CPPUNIT_ASSERT(*pcc == cc);
    }
  
    void test_fredkin_clone_3 () {
       FredkinCell cc;
       FredkinCell* pcc = cc.clone();
       CPPUNIT_ASSERT(pcc != &cc);
    }
  
    void test_fredkin_setNextAlive_1 () {
       FredkinCell cc;
       int pop = 0;
       CPPUNIT_ASSERT(!(cc.live));
       cc.setNextAlive(2, pop);
       CPPUNIT_ASSERT(!(cc.nextLive));
       CPPUNIT_ASSERT(pop == 0);
    }
  
    void test_fredkin_setNextAlive_2 () {
       FredkinCell cc;
       int pop = 0;
       CPPUNIT_ASSERT(!(cc.live));
       CPPUNIT_ASSERT(cc._a == 0);
       cc.setNextAlive(3, pop); 
       CPPUNIT_ASSERT(cc.nextLive);
       CPPUNIT_ASSERT(pop == 1);
       CPPUNIT_ASSERT(cc._a == 0);
    }
  
    void test_fredkin_setNextAlive_3 () {
       FredkinCell cc;
       int pop = 135;
       CPPUNIT_ASSERT(!(cc.live));
       cc.setNextAlive(4, pop);
       CPPUNIT_ASSERT(!(cc.nextLive));
       CPPUNIT_ASSERT(pop == 135);
    }

    void test_fredkin_setNextAlive_4 () {
       FredkinCell cc('4');
       int pop = 24;
       CPPUNIT_ASSERT(cc.live);
       CPPUNIT_ASSERT(cc._a == 4);
       cc.setNextAlive(3, pop);
       CPPUNIT_ASSERT(cc.nextLive);
       CPPUNIT_ASSERT(cc._a == 4);
       CPPUNIT_ASSERT(pop == 24);
       cc.setNextAlive(2, pop);
       CPPUNIT_ASSERT(!(cc.nextLive));
       CPPUNIT_ASSERT(pop == 23);
       cc.setNextAlive(1, pop);
       CPPUNIT_ASSERT(cc.nextLive);
       CPPUNIT_ASSERT(pop == 23);
       cc.setNextAlive(4, pop);
       CPPUNIT_ASSERT(!(cc.nextLive));
       CPPUNIT_ASSERT(pop == 22);
    }
  
    void test_fredkin_updateState_1() {
       FredkinCell cc;
       CPPUNIT_ASSERT(!(cc.live));
       CPPUNIT_ASSERT(!(cc.nextLive));
       CPPUNIT_ASSERT(cc._c == '-');
       cc.updateState();
       CPPUNIT_ASSERT(!(cc.live));
       CPPUNIT_ASSERT(!(cc.nextLive));
       CPPUNIT_ASSERT(cc._c == '-');
    }

    void test_fredkin_updateState_2() {
       FredkinCell cc('0');
       CPPUNIT_ASSERT(cc.live);
       CPPUNIT_ASSERT(!(cc.nextLive));
       CPPUNIT_ASSERT(cc._a == 0);
       CPPUNIT_ASSERT(cc._c == '0');
       cc.updateState();
       CPPUNIT_ASSERT(cc._a == 0);
       CPPUNIT_ASSERT(!(cc.live));
       CPPUNIT_ASSERT(!(cc.nextLive));
       CPPUNIT_ASSERT(cc._c == '-');
    }

    void test_fredkin_updateState_3() {
       FredkinCell cc('4');
       int pop = 2;
       cc.setNextAlive(1, pop);
       CPPUNIT_ASSERT(cc.live);
       CPPUNIT_ASSERT(cc.nextLive);
       CPPUNIT_ASSERT(cc._c == '4');
       CPPUNIT_ASSERT(cc._a == 4);
       cc.updateState();
       CPPUNIT_ASSERT(cc.live);
       CPPUNIT_ASSERT(!(cc.nextLive));
       CPPUNIT_ASSERT(cc._c == '5');
       CPPUNIT_ASSERT(cc._a == 5);
    }

    void test_fredkin_updateState_4() {
       FredkinCell cc;
       int pop = 2;
       cc.setNextAlive(3, pop);
       CPPUNIT_ASSERT(!(cc.live));
       CPPUNIT_ASSERT(cc.nextLive);
       CPPUNIT_ASSERT(cc._c == '-');
       CPPUNIT_ASSERT(cc._a == 0);
       cc.updateState();
       CPPUNIT_ASSERT(cc.live);
       CPPUNIT_ASSERT(!(cc.nextLive));
       CPPUNIT_ASSERT(cc._c == '0');
       CPPUNIT_ASSERT(cc._a == 0);
    }

    // ----
    // Cell
    // ----

   void test_cell_construct_1 () {
       Cell c;
       CPPUNIT_ASSERT(!(c.get()->live));
       CPPUNIT_ASSERT(!(c.get()->nextLive));
       CPPUNIT_ASSERT(c.get()->_c == '-');
       CPPUNIT_ASSERT(c.get()->_nn == 4);
    }

    void test_cell_construct_2 () {
       Cell c('0');
       CPPUNIT_ASSERT(c.get()->live);
       CPPUNIT_ASSERT(!(c.get()->nextLive));
       CPPUNIT_ASSERT(c.get()->_nn == 4);
       CPPUNIT_ASSERT(c.get()->_c == '0');
    }
  
    void test_cell_construct_3 () {
       try {
         Cell c('m');
       } catch(const invalid_argument&) { 
         CPPUNIT_ASSERT(true);
         return;
       }

       CPPUNIT_ASSERT(false);
    }
  
    void test_cell_setNextAlive_1 () {
       Cell cc;
       int pop = 0;
       CPPUNIT_ASSERT(!(cc.get()->live));
       cc.setNextAlive(2, pop);
       CPPUNIT_ASSERT(!(cc.get()->nextLive));
       CPPUNIT_ASSERT(pop == 0);
    }
  
    void test_cell_setNextAlive_2 () {
       Cell cc;
       int pop = 0;
       CPPUNIT_ASSERT(!(cc.get()->live));
       CPPUNIT_ASSERT(dynamic_cast<const FredkinCell*>(cc.get())->_a == 0);
       cc.setNextAlive(3, pop); 
       CPPUNIT_ASSERT(cc.get()->nextLive);
       CPPUNIT_ASSERT(pop == 1);
       CPPUNIT_ASSERT(dynamic_cast<const FredkinCell*>(cc.get())->_a == 0);
    }
  
    void test_cell_setNextAlive_3 () {
       Cell cc;
       int pop = 135;
       CPPUNIT_ASSERT(!(cc.get()->live));
       cc.setNextAlive(4, pop);
       CPPUNIT_ASSERT(!(cc.get()->nextLive));
       CPPUNIT_ASSERT(pop == 135);
    }

    void test_cell_setNextAlive_4 () {
       Cell cc('4');
       int pop = 24;
       CPPUNIT_ASSERT(cc.get()->live);
       CPPUNIT_ASSERT(dynamic_cast<const FredkinCell*>(cc.get())->_a == 4);
       cc.setNextAlive(3, pop);
       CPPUNIT_ASSERT(cc.get()->nextLive);
       CPPUNIT_ASSERT(dynamic_cast<const FredkinCell*>(cc.get())->_a == 4);
       CPPUNIT_ASSERT(pop == 24);
       cc.setNextAlive(2, pop);
       CPPUNIT_ASSERT(!(cc.get()->nextLive));
       CPPUNIT_ASSERT(pop == 23);
       cc.setNextAlive(1, pop);
       CPPUNIT_ASSERT(cc.get()->nextLive);
       CPPUNIT_ASSERT(pop == 23);
       cc.setNextAlive(4, pop);
       CPPUNIT_ASSERT(!(cc.get()->nextLive));
       CPPUNIT_ASSERT(pop == 22);
    }
  
    void test_cell_updateState_1() {
       Cell cc;
       CPPUNIT_ASSERT(!(cc.get()->live));
       CPPUNIT_ASSERT(!(cc.get()->nextLive));
       CPPUNIT_ASSERT(cc.get()->_c == '-');
       cc.updateState();
       CPPUNIT_ASSERT(!(cc.get()->live));
       CPPUNIT_ASSERT(!(cc.get()->nextLive));
       CPPUNIT_ASSERT(cc.get()->_c == '-');
    }

    // ----
    // Life
    // ----

    void test_life_construct_1() {
       Life<ConwayCell> y(2, 2);
       CPPUNIT_ASSERT(y._p == 0);
       CPPUNIT_ASSERT(y._g == 0);
       CPPUNIT_ASSERT(y._r == 4);
       CPPUNIT_ASSERT(y._c == 4);
       CPPUNIT_ASSERT(y.grid[6]._c == '.');
    }

    void test_life_construct_2() {
       Life<FredkinCell> y(2, 2);
       CPPUNIT_ASSERT(y._p == 0);
       CPPUNIT_ASSERT(y._g == 0);
       CPPUNIT_ASSERT(y._r == 4);
       CPPUNIT_ASSERT(y._c == 4);
       CPPUNIT_ASSERT(y.grid[6]._c == '-');
    }

    void test_life_construct_3() {
       Life<Cell> y(2, 2);
       CPPUNIT_ASSERT(y._p == 0);
       CPPUNIT_ASSERT(y._g == 0);
       CPPUNIT_ASSERT(y._r == 4);
       CPPUNIT_ASSERT(y._c == 4);
       CPPUNIT_ASSERT(y.grid[6].get()->_c == '-');
    }

    void test_life_countNeighbors_1() {
       Life<ConwayCell> y(2, 2);
       CPPUNIT_ASSERT(y.countNeighbors(6) == 0);
    }

    void test_life_countNeighbors_2() {
       Life<FredkinCell> y(2, 2);
       CPPUNIT_ASSERT(y.countNeighbors(6) == 0);
    }

    void test_life_countNeighbors_3() {
       Life<Cell> y(2, 2);
       CPPUNIT_ASSERT(y.countNeighbors(6) == 0);
    }

    void test_life_addCell_1() {
       Life<ConwayCell> y(2, 2);
       for(int i = 0; i < 4; ++i) {
          for(int j = 0; j < 4; ++j) 
             CPPUNIT_ASSERT(y.grid[i*y._c+j]._c == '.');
       }
       y.addCell(1, 2, '*');
       CPPUNIT_ASSERT(y._p == 1);
       CPPUNIT_ASSERT(y.grid[1*y._c+2]._c == '*');
       CPPUNIT_ASSERT(y.grid[1*y._c+2].live);
       CPPUNIT_ASSERT(!(y.grid[1*y._c+2].nextLive));
    }

    void test_life_addCell_2() {
       Life<ConwayCell> y(2, 2);
       for(int i = 0; i < 4; ++i) {
          for(int j = 0; j < 4; ++j) 
             CPPUNIT_ASSERT(y.grid[i*y._c+j]._c == '.');
       }
       y.addCell(1, 2, '.');
       CPPUNIT_ASSERT(y._p == 0);
       CPPUNIT_ASSERT(y.grid[1*y._c+2]._c == '.');
       CPPUNIT_ASSERT(!(y.grid[1*y._c+2].live));
       CPPUNIT_ASSERT(!(y.grid[1*y._c+2].nextLive));
    }

    void test_life_addCell_3() {
       Life<ConwayCell> y(2, 2);
       for(int i = 0; i < 4; ++i) {
          for(int j = 0; j < 4; ++j) 
             CPPUNIT_ASSERT(y.grid[i*y._c+j]._c == '.');
       }
       try {
          y.addCell(1, 2, '+');
          CPPUNIT_ASSERT(false);
       } catch(const invalid_argument&) {
          CPPUNIT_ASSERT(y._p == 0);
          CPPUNIT_ASSERT(y.grid[1*y._c+2]._c == '.');
          CPPUNIT_ASSERT(!(y.grid[1*y._c+2].live));
          CPPUNIT_ASSERT(!(y.grid[1*y._c+2].nextLive));
       }
    }

    void test_life_addCell_4() {
       Life<FredkinCell> y(2, 2);
       for(int i = 0; i < 4; ++i) {
          for(int j = 0; j < 4; ++j) 
             CPPUNIT_ASSERT(y.grid[i*y._c+j]._c == '-');
       }
       try {
          y.addCell(1, 2, '*');
          CPPUNIT_ASSERT(false);
       } catch(const invalid_argument&) {
          CPPUNIT_ASSERT(y._p == 0);
          CPPUNIT_ASSERT(y.grid[1*y._c+2]._c == '-');
          CPPUNIT_ASSERT(!(y.grid[1*y._c+2].live));
          CPPUNIT_ASSERT(!(y.grid[1*y._c+2].nextLive));
       }
    }

    void test_life_addCell_5() {
       Life<FredkinCell> y(2, 2);
       for(int i = 0; i < 4; ++i) {
          for(int j = 0; j < 4; ++j) 
             CPPUNIT_ASSERT(y.grid[i*y._c+j]._c == '-');
       }
       y.addCell(1, 2, '1');
       CPPUNIT_ASSERT(y._p == 1);
       CPPUNIT_ASSERT(y.grid[1*y._c+2]._c == '1');
       CPPUNIT_ASSERT(y.grid[1*y._c+2].live);
       CPPUNIT_ASSERT(!(y.grid[1*y._c+2].nextLive));
    }

    void test_life_addCell_6() {
       Life<Cell> y(2, 2);
       for(int i = 0; i < 4; ++i) {
          for(int j = 0; j < 4; ++j) 
             CPPUNIT_ASSERT(y.grid[i*y._c+j].get()->_c == '-');
       }
       y.addCell(1, 2, '1');
       CPPUNIT_ASSERT(y._p == 1);
       CPPUNIT_ASSERT(y.grid[1*y._c+2].get()->_c == '1');
       CPPUNIT_ASSERT(y.grid[1*y._c+2].get()->live);
       CPPUNIT_ASSERT(!(y.grid[1*y._c+2].get()->nextLive));
    }

    void test_life_addCell_7() {
       Life<Cell> y(2, 2);
       for(int i = 0; i < 4; ++i) {
          for(int j = 0; j < 4; ++j) 
             CPPUNIT_ASSERT(y.grid[i*y._c+j].get()->_c == '-');
       }
       try {
         y.addCell(1, 2, '*');
         CPPUNIT_ASSERT(false);
       } catch(const invalid_argument&) {
          CPPUNIT_ASSERT(y._p == 0);
          CPPUNIT_ASSERT(y.grid[1*y._c+2].get()->_c == '-');
          CPPUNIT_ASSERT(!(y.grid[1*y._c+2].get()->live));
          CPPUNIT_ASSERT(!(y.grid[1*y._c+2].get()->nextLive));
       }
    }

    void test_life_executeTurn_1() {
       Life<ConwayCell> y(1, 1);
       CPPUNIT_ASSERT(y._g == 0);
       CPPUNIT_ASSERT(y._p == 0);
       y.executeTurn();
       CPPUNIT_ASSERT(y._g == 1);
       CPPUNIT_ASSERT(y._p == 0);
    }

    void test_life_executeTurn_2() {
       Life<ConwayCell> y(1, 1);
       y.addCell(1, 1, '*');
       CPPUNIT_ASSERT(y._g == 0);
       CPPUNIT_ASSERT(y._p == 1);
       y.executeTurn();
       CPPUNIT_ASSERT(y._g == 1);
       CPPUNIT_ASSERT(y._p == 0);
    }

    void test_life_executeTurn_3() {
       Life<ConwayCell> y(2, 2);
       y.addCell(1, 1, '*');
       y.addCell(1, 2, '*');
       y.addCell(2, 1, '*');
       y.addCell(2, 2, '*');
       CPPUNIT_ASSERT(y._g == 0);
       CPPUNIT_ASSERT(y._p == 4);
       y.executeTurn();
       CPPUNIT_ASSERT(y._g == 1);
       CPPUNIT_ASSERT(y._p == 4);
    }

    void test_life_executeTurn_4() {
       Life<FredkinCell> y(1, 1);
       y.addCell(1, 1, '0');
       CPPUNIT_ASSERT(y._g == 0);
       CPPUNIT_ASSERT(y._p == 1);
       y.executeTurn();
       CPPUNIT_ASSERT(y._g == 1);
       CPPUNIT_ASSERT(y._p == 0);
       CPPUNIT_ASSERT(y.grid[4]._c == '-');
       CPPUNIT_ASSERT(y.grid[4]._a == 0);
    }

    void test_life_executeTurn_5() {
       Life<FredkinCell> y(1, 2);
       y.addCell(1, 1, '0');
       CPPUNIT_ASSERT(y._g == 0);
       CPPUNIT_ASSERT(y._p == 1);
       y.executeTurn();
       CPPUNIT_ASSERT(y._g == 1);
       CPPUNIT_ASSERT(y._p == 1);
       CPPUNIT_ASSERT(y.grid[5]._c == '-');
       CPPUNIT_ASSERT(y.grid[5]._a == 0);
       CPPUNIT_ASSERT(y.grid[6]._c == '0');
       CPPUNIT_ASSERT(y.grid[6]._a == 0);
    }

    void test_life_executeTurn_6() {
       Life<Cell> y(1, 1);
       y.addCell(1, 1, '0');
       CPPUNIT_ASSERT(y._g == 0);
       CPPUNIT_ASSERT(y._p == 1);
       y.executeTurn();
       CPPUNIT_ASSERT(y._g == 1);
       CPPUNIT_ASSERT(y._p == 0);
       CPPUNIT_ASSERT(y.grid[4].get()->_c == '-');
       CPPUNIT_ASSERT(dynamic_cast<const FredkinCell*>(y.grid[4].get())->_a == 0);
    }

    void test_life_executeTurn_7() {
       Life<Cell> y(1, 2);
       y.addCell(1, 1, '0');
       CPPUNIT_ASSERT(y._g == 0);
       CPPUNIT_ASSERT(y._p == 1);
       y.executeTurn();
       CPPUNIT_ASSERT(y._g == 1);
       CPPUNIT_ASSERT(y._p == 1);
       CPPUNIT_ASSERT(y.grid[5].get()->_c == '-');
       CPPUNIT_ASSERT(dynamic_cast<const FredkinCell*>(y.grid[5].get())->_a == 0);
       CPPUNIT_ASSERT(y.grid[6].get()->_c == '0');
       CPPUNIT_ASSERT(dynamic_cast<const FredkinCell*>(y.grid[6].get())->_a == 0);
    }


    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST(test_conway_construct_1);
    CPPUNIT_TEST(test_conway_construct_2);
    CPPUNIT_TEST(test_conway_construct_3);
    CPPUNIT_TEST(test_conway_construct_4);
    CPPUNIT_TEST(test_conway_equals_1);
    CPPUNIT_TEST(test_conway_equals_2);
    CPPUNIT_TEST(test_conway_equals_3);
    CPPUNIT_TEST(test_conway_equals_4);
    CPPUNIT_TEST(test_conway_clone_1);
    CPPUNIT_TEST(test_conway_clone_2);
    CPPUNIT_TEST(test_conway_clone_3);
    CPPUNIT_TEST(test_conway_setNextAlive_1);
    CPPUNIT_TEST(test_conway_setNextAlive_2);
    CPPUNIT_TEST(test_conway_setNextAlive_3);
    CPPUNIT_TEST(test_conway_setNextAlive_4);
    CPPUNIT_TEST(test_conway_updateState_1);
    CPPUNIT_TEST(test_conway_updateState_2);
    CPPUNIT_TEST(test_conway_updateState_3);
    CPPUNIT_TEST(test_conway_updateState_4);
    CPPUNIT_TEST(test_fredkin_construct_1);
    CPPUNIT_TEST(test_fredkin_construct_2);
    CPPUNIT_TEST(test_fredkin_construct_3);
    CPPUNIT_TEST(test_fredkin_construct_4);
    CPPUNIT_TEST(test_fredkin_equals_1);
    CPPUNIT_TEST(test_fredkin_equals_2);
    CPPUNIT_TEST(test_fredkin_equals_3);
    CPPUNIT_TEST(test_fredkin_equals_4);
    CPPUNIT_TEST(test_fredkin_clone_1);
    CPPUNIT_TEST(test_fredkin_clone_2);
    CPPUNIT_TEST(test_fredkin_clone_3);
    CPPUNIT_TEST(test_fredkin_setNextAlive_1);
    CPPUNIT_TEST(test_fredkin_setNextAlive_2);
    CPPUNIT_TEST(test_fredkin_setNextAlive_3);
    CPPUNIT_TEST(test_fredkin_setNextAlive_4);
    CPPUNIT_TEST(test_fredkin_updateState_1);
    CPPUNIT_TEST(test_fredkin_updateState_2);
    CPPUNIT_TEST(test_fredkin_updateState_3);
    CPPUNIT_TEST(test_fredkin_updateState_4);
    CPPUNIT_TEST(test_cell_construct_1);
    CPPUNIT_TEST(test_cell_construct_2);
    CPPUNIT_TEST(test_cell_construct_3);
    CPPUNIT_TEST(test_cell_setNextAlive_1);
    CPPUNIT_TEST(test_cell_setNextAlive_2);
    CPPUNIT_TEST(test_cell_setNextAlive_3);
    CPPUNIT_TEST(test_cell_setNextAlive_4);
    CPPUNIT_TEST(test_cell_updateState_1);
    CPPUNIT_TEST(test_life_construct_1);
    CPPUNIT_TEST(test_life_construct_2);
    CPPUNIT_TEST(test_life_construct_3);
    CPPUNIT_TEST(test_life_countNeighbors_1);
    CPPUNIT_TEST(test_life_countNeighbors_2);
    CPPUNIT_TEST(test_life_countNeighbors_3);
    CPPUNIT_TEST(test_life_addCell_1);
    CPPUNIT_TEST(test_life_addCell_2);
    CPPUNIT_TEST(test_life_addCell_3);
    CPPUNIT_TEST(test_life_addCell_4);
    CPPUNIT_TEST(test_life_addCell_5);
    CPPUNIT_TEST(test_life_addCell_6);
    CPPUNIT_TEST(test_life_addCell_7);
    CPPUNIT_TEST(test_life_executeTurn_1);
    CPPUNIT_TEST(test_life_executeTurn_2);
    CPPUNIT_TEST(test_life_executeTurn_3);
    CPPUNIT_TEST(test_life_executeTurn_4);
    CPPUNIT_TEST(test_life_executeTurn_5);
    CPPUNIT_TEST(test_life_executeTurn_6);
    CPPUNIT_TEST(test_life_executeTurn_7);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestLife.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestLife::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
