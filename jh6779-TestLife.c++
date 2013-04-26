// ------------------------------------
// Copyright (C) 2013
// Glenn P. Downing
// ------------------------------------

/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -pedantic -std=c++0x -Wall TestLife.c++ -o TestLife -lcppunit -ldl
    % valgrind TestAllocator >& TestAllocator.out
*/

// --------
// includes
// --------

#include <iostream>  // ios_base
#include <sstream>
#include <string>
#include <utility>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define private public
#define protected public
//#define class struct

#include <stdexcept> // invalid_argument, out_of_range
#include "Cell.h"
#include "Life.h"

// ----------
// TestLife
// ----------

struct TestLife : CppUnit::TestFixture {
    // ----------
    // test_CCell
    // ----------
    
    void test_CCell () {
      ConwayCell cc(true);
      CPPUNIT_ASSERT(cc._alive);
      CPPUNIT_ASSERT(!cc._nextAlive);
      
      ConwayCell cc2;
      CPPUNIT_ASSERT(!cc2._alive);
      CPPUNIT_ASSERT(!cc2._nextAlive);}
      
    // ----------
    // test_FCell
    // ----------
    
    void test_FCell () {
      FredkinCell fc(true);
      CPPUNIT_ASSERT(!fc._alive);
      CPPUNIT_ASSERT(!fc._nextAlive);
      CPPUNIT_ASSERT(fc._mutable);
      CPPUNIT_ASSERT(fc._age == 0);}
      
    // ---------
    // test_Cell
    // ---------
    
    void test_Cell () {
      Cell c(new ConwayCell());
      CPPUNIT_ASSERT(!c.get()->_alive);
      CPPUNIT_ASSERT(!c.get()->_nextAlive);}
      
    // ---------
    // test_Grid
    // ---------
    
    void test_Grid () {
      Grid<double> g(3,3,1.1);
      for(int r = 0; r < 2; ++r){
        for(int c = 0; c < 2; ++c){
          CPPUNIT_ASSERT(g._m[r][c] == 1.1);}}
      }
      
    // ---------
    // test_Life
    // ---------
    
    void test_Life () {
      Life<ConwayCell> life(2,2,ConwayCell());
      CPPUNIT_ASSERT(life._generation == 0);
      CPPUNIT_ASSERT(life._population == 0);
      for(int r = 0; r < 2; ++r){
        for(int c = 0; c < 2; ++c){
          CPPUNIT_ASSERT(!life._world(r,c)._alive);
          CPPUNIT_ASSERT(!life._world(r,c)._nextAlive);}}}

    // ---------------
    // test_ConwayCell
    // ---------------

    void test_ConwayCell () {/*
      ConwayCell c1();
      CPPUNIT_ASSERT(!c1._alive);}
      CPPUNIT_ASSERT(!c1._nextAlive);
      CPPUNIT_ASSERT(c1.age() == 0);
      CPPUNIT_ASSERT(!c1.canMutate());*/}
      
    // --------
    // test_age
    // --------
    
    void test_age () {
      ConwayCell cc;
      CPPUNIT_ASSERT(cc.age() == 0);
      FredkinCell fc(false);
      Cell c(new FredkinCell(false));
      CPPUNIT_ASSERT(fc.age() == 0);
      fc._age = 10;
      CPPUNIT_ASSERT(fc.age() == 10);
      CPPUNIT_ASSERT(c.age() == 0);
      static_cast<FredkinCell*>(c.get())->_age = 20;
      CPPUNIT_ASSERT(c.age() == 20);
      c = Cell(new ConwayCell());
      CPPUNIT_ASSERT(c.age() == 0);}
      
    // --------------
    // test_canMutate
    // --------------
    
    void test_canMutate () {
      ConwayCell cc;
      FredkinCell fc1(false);
      FredkinCell fc2(true);
      Cell c1(new FredkinCell(false));
      Cell c2(new FredkinCell(true));
      CPPUNIT_ASSERT(!cc.canMutate());
      CPPUNIT_ASSERT(!fc1.canMutate());
      CPPUNIT_ASSERT(fc2.canMutate());
      CPPUNIT_ASSERT(!c1.canMutate());
      CPPUNIT_ASSERT(c2.canMutate());
      fc1._mutable = true;
      CPPUNIT_ASSERT(fc1.canMutate());
      static_cast<FredkinCell*>(c2.get())->_mutable = false;
      CPPUNIT_ASSERT(!c2.canMutate());}
      
    // ------------
    // test_isAlive
    // ------------
   
     void test_isAlive () {
      ConwayCell cc(true);
      FredkinCell fc(false,true);
      Cell c(new ConwayCell());
      CPPUNIT_ASSERT(cc.isAlive());
      CPPUNIT_ASSERT(fc.isAlive());
      CPPUNIT_ASSERT(!c.isAlive());
      static_cast<FredkinCell*>(c.get())->_alive = true;
      CPPUNIT_ASSERT(c.isAlive());}
      
    // ------------
    // test_mutate1
    // ------------
    
    void test_mutate1 () {
      Cell c(new ConwayCell(true));
      ConwayCell* t = static_cast<ConwayCell*>(c.get());
      c.mutate();
      CPPUNIT_ASSERT(t == c.get());}
      
    // ------------
    // test_mutate2
    // ------------
    
    void test_mutate2 () {
      Cell c(new FredkinCell(false,true));
      FredkinCell* t = static_cast<FredkinCell*>(c.get());
      t->_age = 3;
      c.mutate();
      CPPUNIT_ASSERT(t == c.get());}
      
    // ------------
    // test_mutate3
    // ------------
    
    void test_mutate3 () {
      Cell c(new FredkinCell(true,true));
      FredkinCell* t = static_cast<FredkinCell*>(c.get());
      t->_age = 3;
      c.mutate();
      CPPUNIT_ASSERT(t != c.get());}
	  
	// ---------------
	// test_nextState1
	// ---------------
	
	void test_nextState1 () {
	  ConwayCell cc(true);
	  cc.nextState(2);
	  CPPUNIT_ASSERT(cc._nextAlive);
	  cc.nextState(3);
	  CPPUNIT_ASSERT(cc._nextAlive);
	  cc.nextState(8);
	  CPPUNIT_ASSERT(!cc._nextAlive);
	  cc._alive = false;
	  cc.nextState(8);
	  CPPUNIT_ASSERT(!cc._nextAlive);
	  cc.nextState(3);
	  CPPUNIT_ASSERT(cc._nextAlive);}
	  
	// ---------------
	// test_nextState2
	// ---------------
	
	void test_nextState2 () {
	  FredkinCell fc(false,true);
	  fc.nextState(1);
	  CPPUNIT_ASSERT(fc._nextAlive);
	  fc.nextState(3);
	  CPPUNIT_ASSERT(fc._nextAlive);
	  fc.nextState(2);
	  CPPUNIT_ASSERT(!fc._nextAlive);
	  fc._alive = false;
	  fc.nextState(2);
	  CPPUNIT_ASSERT(!fc._nextAlive);
	  fc.nextState(3);
	  CPPUNIT_ASSERT(fc._nextAlive);}
	  
	// ---------------
	// test_nextState3
	// ---------------
	
	void test_nextState3 () {
	  Cell c(new ConwayCell(true));
	  ConwayCell* t = static_cast<ConwayCell*>(c.get());
	  c.nextState(3);
	  CPPUNIT_ASSERT(t->_nextAlive);
	  c.nextState(1);
	  CPPUNIT_ASSERT(!t->_nextAlive);
    t->_alive = false;
	  c.nextState(2);
	  CPPUNIT_ASSERT(!t->_nextAlive);
	  c.nextState(3);
	  CPPUNIT_ASSERT(t->_nextAlive);}
    
  // ------------------
  // test_updateState1
  // ------------------
  
  void test_updateState1 () {
    ConwayCell cc(false);
    cc._nextAlive = true;
	  CPPUNIT_ASSERT(!cc.isAlive());
    cc.updateState();
	  CPPUNIT_ASSERT(cc.isAlive());}
    
  // ------------------
  // test_updateState2
  // ------------------
  
  void test_updateState2 () {
    FredkinCell fc(false,false);
    fc._nextAlive = true;
    CPPUNIT_ASSERT(!fc.isAlive());
    fc.updateState();
    CPPUNIT_ASSERT(fc.isAlive());}
    
  // ------------------
  // test_updateState3
  // ------------------
  
  void test_updateState3 () {
    Cell c(new FredkinCell(true,false));
    FredkinCell* t = static_cast<FredkinCell*>(c.get());
    t->_nextAlive = true;
    CPPUNIT_ASSERT(!c.isAlive());
    c.updateState();
    CPPUNIT_ASSERT(c.isAlive());
    t->_nextAlive = true;
    c.updateState();
    CPPUNIT_ASSERT(c.isAlive());
    CPPUNIT_ASSERT(c.age() == 1);
    t->_age = 3;
    t->_nextAlive = true;
    c.updateState();
    CPPUNIT_ASSERT(c.isAlive());
    CPPUNIT_ASSERT(c.age() == 0);
    ConwayCell* u = dynamic_cast<ConwayCell*>(c.get());
    CPPUNIT_ASSERT(u != NULL);}
   
  // ------------------
  // test_getNeighbors1
  // ------------------
  
  void test_getNeighbors1 () {
    std::vector<Coor> a = {{0,1},{0,2},{1,2},{2,2},{2,1},{2,0},{1,0},{0,0}};
    ConwayCell cc(false);
    std::vector<Coor> r = cc.getNeighbors({1,1});
    CPPUNIT_ASSERT(a[0] == r[0]);
    CPPUNIT_ASSERT(a[1] == r[1]);
    CPPUNIT_ASSERT(a[2] == r[2]);
    CPPUNIT_ASSERT(a[3] == r[3]);
    CPPUNIT_ASSERT(a[4] == r[4]);
    CPPUNIT_ASSERT(a[5] == r[5]);
    CPPUNIT_ASSERT(a[6] == r[6]);
    CPPUNIT_ASSERT(a[7] == r[7]);}
   
  // ------------------
  // test_getNeighbors2
  // ------------------
  
  void test_getNeighbors2 () {
    std::vector<Coor> a = {{3,5},{4,6},{5,5},{4,4}};
    FredkinCell fc(false);
    std::vector<Coor> r = fc.getNeighbors({4,5});
    CPPUNIT_ASSERT(a[0] == r[0]);
    CPPUNIT_ASSERT(a[1] == r[1]);
    CPPUNIT_ASSERT(a[2] == r[2]);
    CPPUNIT_ASSERT(a[3] == r[3]);}
   
  // ------------------
  // test_getNeighbors3
  // ------------------
  
  void test_getNeighbors3 () {
    std::vector<Coor> a = {{6,7},{7,8},{8,7},{7,6}};
    Cell c(new FredkinCell(false));
    std::vector<Coor> r = c.getNeighbors({7,7});
    CPPUNIT_ASSERT(a[0] == r[0]);
    CPPUNIT_ASSERT(a[1] == r[1]);
    CPPUNIT_ASSERT(a[2] == r[2]);
    CPPUNIT_ASSERT(a[3] == r[3]);}
    
  // -----------
  // test_write1
  // -----------
    
  void test_write1 () {
    std::stringstream ss;
    ConwayCell cc(false);
    ss << cc;
    CPPUNIT_ASSERT(ss.str() == ".");
    cc._alive = true;
    ss.str("");
    ss << cc;
    CPPUNIT_ASSERT(ss.str() == "*");}
    
  // -----------
  // test_write2
  // -----------
    
  void test_write2 () {
    std::stringstream ss;
    FredkinCell fc(false);
    ss << fc;
    CPPUNIT_ASSERT(ss.str() == "-");
    fc._alive = true;
    ss.str("");
    ss << fc;
    CPPUNIT_ASSERT(ss.str() == "0");
    fc._age = 9;
    ss.str("");
    ss << fc;
    CPPUNIT_ASSERT(ss.str() == "9");
    fc._age = 10;
    ss.str("");
    ss << fc;
    CPPUNIT_ASSERT(ss.str() == "+");}
    
  // -----------
  // test_write3
  // -----------
    
  void test_write3 () {
    std::stringstream ss;
    Cell c(new ConwayCell());
    ss << c;
    CPPUNIT_ASSERT(ss.str() == ".");
    c.get()->_alive = true;
    ss.str("");
    ss << c;
    CPPUNIT_ASSERT(ss.str() == "*");}
    
  // -----------
  // test_clone1
  // -----------
  
  void test_clone1 () {
    ConwayCell cc(true);
    cc._nextAlive = true;
    ConwayCell* ccp = cc.clone();
    CPPUNIT_ASSERT(ccp != &cc);
    CPPUNIT_ASSERT(ccp->isAlive() == cc.isAlive());
    CPPUNIT_ASSERT(ccp->_nextAlive == cc._nextAlive);
    delete ccp;}
    
  // -----------
  // test_clone2
  // -----------
  
  void test_clone2 () {
    FredkinCell fc(true,true);
    fc._nextAlive = true;
    fc._age = 100;
    FredkinCell* fcp = fc.clone();
    CPPUNIT_ASSERT(fcp != &fc);
    CPPUNIT_ASSERT(fcp->isAlive() == fc.isAlive());
    CPPUNIT_ASSERT(fcp->_nextAlive == fc._nextAlive);
    CPPUNIT_ASSERT(fcp->_age == fc._age);
    CPPUNIT_ASSERT(fcp->_mutable == fc._mutable);
    delete fcp;}
    
  // ----------
  // test_Grid1
  // ----------
  
  void test_Grid1 () {
    Grid<int> g(12,19,7);
    CPPUNIT_ASSERT(g.rows() == 12);
    CPPUNIT_ASSERT(g.cols() == 19);
    
    CPPUNIT_ASSERT(g._m[5][6] == 7);
    CPPUNIT_ASSERT(g._m[3][17] == 7);
    CPPUNIT_ASSERT(g._m[9][12] == 7);
    
    CPPUNIT_ASSERT(g(5,6) == 7);
    CPPUNIT_ASSERT(g(3,17) == 7);
    CPPUNIT_ASSERT(g(9,12) == 7);
    
    CPPUNIT_ASSERT(g({5,6}) == 7);
    CPPUNIT_ASSERT(g({3,17}) == 7);
    CPPUNIT_ASSERT(g({9,12}) == 7);
    
    g(11,11) = -1;
    g({10,10}) = -8;
    CPPUNIT_ASSERT(g._m[11][11] == -1);
    CPPUNIT_ASSERT(g._m[10][10] == -8);
    
    try{
      g(-1,10);
      CPPUNIT_ASSERT(false);
    }
    catch (std::out_of_range& e) {
      CPPUNIT_ASSERT(true);}
    CPPUNIT_ASSERT(!g.inBounds(1,30));}
    
  // ----------
  // test_Grid2
  // ----------
  
  void test_Grid2 () {
    Grid<int> g(10,10,8);
    CPPUNIT_ASSERT(g.rows() == 10);
    CPPUNIT_ASSERT(g.cols() == 10);
    
    CPPUNIT_ASSERT(g(5,6) == 8);
    CPPUNIT_ASSERT(g(3,5) == 8);
    CPPUNIT_ASSERT(g(9,9) == 8);
    
    CPPUNIT_ASSERT(g({5,6}) == 8);
    CPPUNIT_ASSERT(g({3,5}) == 8);
    CPPUNIT_ASSERT(g({9,9}) == 8);
    
    g(1,1) = -1;
    g({7,6}) = -8;
    CPPUNIT_ASSERT(g._m[1][1] == -1);
    CPPUNIT_ASSERT(g._m[7][6] == -8);
    
    try{
      g(0,10);
      CPPUNIT_ASSERT(false);
    }
    catch (std::out_of_range& e) {
      CPPUNIT_ASSERT(true);}
    CPPUNIT_ASSERT(!g.inBounds(-12,30));}
    
  // ----------
  // test_Grid3
  // ----------
  
  void test_Grid3 () {
    Grid<int> g(1,1,7);
    CPPUNIT_ASSERT(g.rows() == 1);
    CPPUNIT_ASSERT(g.cols() == 1);
    
    CPPUNIT_ASSERT(g._m[0][0] == 7);
    
    CPPUNIT_ASSERT(g(0,0) == 7);
    
    CPPUNIT_ASSERT(g({0,0}) == 7);
    
    g(0,0) = -1;
    CPPUNIT_ASSERT(g._m[0][0] == -1);
    
    try{
      g(0,1) = 2;
      CPPUNIT_ASSERT(false);
    }
    catch (std::out_of_range&) {
      CPPUNIT_ASSERT(true);}
    CPPUNIT_ASSERT(!g.inBounds(1,30));}
    
  // ---------
  // test_run1
  // ---------
   
  void test_run1 () {
    Life<ConwayCell> life(3,3,ConwayCell());
    life.add(0,1,ConwayCell(true));
    life.add(1,1,ConwayCell(true));
    life.add(2,1,ConwayCell(true));
    CPPUNIT_ASSERT(life._population == 3);
    CPPUNIT_ASSERT(life._generation == 0);
    life.run();
    CPPUNIT_ASSERT(life._population == 3);
    CPPUNIT_ASSERT(life._generation == 1);
    CPPUNIT_ASSERT(!life._world(0,1).isAlive());
    CPPUNIT_ASSERT(!life._world(2,1).isAlive());
    CPPUNIT_ASSERT(life._world(1,0).isAlive());
    CPPUNIT_ASSERT(life._world(1,2).isAlive());
    life.run();
    CPPUNIT_ASSERT(life._population == 3);
    CPPUNIT_ASSERT(life._generation == 2);
    CPPUNIT_ASSERT(life._world(0,1).isAlive());
    CPPUNIT_ASSERT(life._world(2,1).isAlive());
    CPPUNIT_ASSERT(!life._world(1,0).isAlive());
    CPPUNIT_ASSERT(!life._world(1,2).isAlive());}
    
  // ---------
  // test_run2
  // ---------
  
  void test_run2 () {
    Life<FredkinCell> life(2,1,FredkinCell(false));
    life.add(0,0,FredkinCell(false,true));
    life.add(1,0,FredkinCell(false,true));
    CPPUNIT_ASSERT(life._population == 2);
    CPPUNIT_ASSERT(life._generation == 0);
    life.run();
    CPPUNIT_ASSERT(life._population == 2);
    CPPUNIT_ASSERT(life._generation == 1);
    CPPUNIT_ASSERT(life._world(0,0).isAlive());
    CPPUNIT_ASSERT(life._world(1,0).isAlive());
    CPPUNIT_ASSERT(life._world(0,0).age() == 1);
    CPPUNIT_ASSERT(life._world(1,0).age() == 1);
    }
  
  // ---------
  // test_run3
  // ---------
    
  void test_run3 () {
    Life<Cell> life(2,1,new FredkinCell(true));
    life.add(0,0,new FredkinCell(true,true));
    life.add(1,0,new FredkinCell(true,true));
    CPPUNIT_ASSERT(life._population == 2);
    CPPUNIT_ASSERT(life._generation == 0);
    life.run();
    CPPUNIT_ASSERT(life._population == 2);
    CPPUNIT_ASSERT(life._generation == 1);
    CPPUNIT_ASSERT(life._world(0,0).isAlive());
    CPPUNIT_ASSERT(life._world(1,0).isAlive());
    CPPUNIT_ASSERT(life._world(0,0).age() == 1);
    CPPUNIT_ASSERT(life._world(1,0).age() == 1);
    life.run();
    CPPUNIT_ASSERT(life._population == 2);
    CPPUNIT_ASSERT(life._generation == 2);
    CPPUNIT_ASSERT(life._world(0,0).isAlive());
    CPPUNIT_ASSERT(life._world(1,0).isAlive());
    CPPUNIT_ASSERT(life._world(0,0).age() == 0);
    CPPUNIT_ASSERT(life._world(1,0).age() == 0);
    }
    
  // -----------
  // test_lwrite1
  // -----------
  
  void test_lwrite1 () {
    std::stringstream ss;
    std::string s = "\nGeneration = 0, Population = 3.\n*..\n.*.\n..*\n";
    Life<ConwayCell> life(3,3,ConwayCell());
    life.add(0,0,ConwayCell(true));
    life.add(1,1,ConwayCell(true));
    life.add(2,2,ConwayCell(true));
    ss << life;
    CPPUNIT_ASSERT(ss.str() == s);}
    
  // -----------
  // test_lwrite2
  // -----------
  
  void test_lwrite2 () {
    std::stringstream ss;
    std::string s = "\nGeneration = 4, Population = 3.\n+1-\n---\n--0\n";
    Life<FredkinCell> life(3,3,FredkinCell(false));
    life._generation = 4;
    life.add(0,0,FredkinCell(false,true));
    life.add(0,1,FredkinCell(false,true));
    life._world(0,0)._age = 10;
    life._world(0,1)._age = 1;
    life.add(2,2,FredkinCell(false,true));
    ss << life;
    CPPUNIT_ASSERT(ss.str() == s);}
    
  // -----------
  // test_lwrite3
  // -----------
  
  void test_lwrite3 () {
    std::stringstream ss;
    std::string s = "\nGeneration = 1, Population = 3.\n+1-\n---\n--*\n";
    Life<Cell> life(3,3,new FredkinCell(false));
    life._generation = 1;
    life.add(0,0,new FredkinCell(false,true));
    life.add(0,1,new FredkinCell(false,true));
    static_cast<FredkinCell*>(life._world(0,0).get())->_age = 10;
    static_cast<FredkinCell*>(life._world(0,1).get())->_age = 1;
    life.add(2,2,new ConwayCell(true));
    ss << life;
    CPPUNIT_ASSERT(ss.str() == s);}
  
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST(test_CCell);
    CPPUNIT_TEST(test_FCell);
    CPPUNIT_TEST(test_Cell);
    CPPUNIT_TEST(test_Grid);
    CPPUNIT_TEST(test_Life);
    CPPUNIT_TEST(test_ConwayCell);
    CPPUNIT_TEST(test_age);
    CPPUNIT_TEST(test_canMutate);
    CPPUNIT_TEST(test_mutate1);
    CPPUNIT_TEST(test_mutate2);
    CPPUNIT_TEST(test_mutate3);
    CPPUNIT_TEST(test_nextState1);
    CPPUNIT_TEST(test_nextState2);
    CPPUNIT_TEST(test_nextState3);
    CPPUNIT_TEST(test_updateState1);
    CPPUNIT_TEST(test_updateState2);
    CPPUNIT_TEST(test_updateState3);
    CPPUNIT_TEST(test_getNeighbors1);
    CPPUNIT_TEST(test_getNeighbors2);
    CPPUNIT_TEST(test_getNeighbors3);
    CPPUNIT_TEST(test_write1);
    CPPUNIT_TEST(test_write2);
    CPPUNIT_TEST(test_write3);
    CPPUNIT_TEST(test_clone1);
    CPPUNIT_TEST(test_clone2);
    CPPUNIT_TEST(test_Grid1);
    CPPUNIT_TEST(test_Grid2);
    CPPUNIT_TEST(test_Grid3);
    CPPUNIT_TEST(test_run1);
    CPPUNIT_TEST(test_run2);
    CPPUNIT_TEST(test_run3);
    CPPUNIT_TEST(test_lwrite1);
    CPPUNIT_TEST(test_lwrite2);
    CPPUNIT_TEST(test_lwrite3);
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
