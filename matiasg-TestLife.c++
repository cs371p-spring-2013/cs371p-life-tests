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
    % g++ -pedantic -std=c++0x -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz -lcppunit -ldl
    % valgrind TestCollatz >& TestCollatz.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl, ios_base
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#define private public
#define protected public

#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Life.h"

// -----------
// TestLife
// -----------

struct TestLife : CppUnit::TestFixture {

    // only doing one test, since the default constructor only does one thing
    void test_conwaycell_default () {
      ConwayCell c;
      CPPUNIT_ASSERT(c.symbol == '.');
      CPPUNIT_ASSERT(c.isDead == true);
    }

    // again, only doing two tests, since constructor can only be called with 2 different arguments
    void test_conwaycell_bool () {
      ConwayCell c(true);
      CPPUNIT_ASSERT(c.symbol == '.');
      CPPUNIT_ASSERT(c.isDead == true);
    }
    
    void test_conwaycell_bool_2 () {
      ConwayCell c(false);
      CPPUNIT_ASSERT(c.symbol == '*');
      CPPUNIT_ASSERT(c.isDead == false);
    }
    
    void test_conwaycell_populate () {
      ConwayCell c(false);
      CPPUNIT_ASSERT(c.symbol == '*');
      CPPUNIT_ASSERT(c.isDead == false);
      c.populate('.');
      CPPUNIT_ASSERT(c.symbol == '.');
      CPPUNIT_ASSERT(c.isDead == true);
    }
    
    void test_conwaycell_populate_2 () {
      ConwayCell c(true);
      CPPUNIT_ASSERT(c.symbol == '.');
      CPPUNIT_ASSERT(c.isDead == true);
      c.populate('*');
      CPPUNIT_ASSERT(c.symbol == '*');
      CPPUNIT_ASSERT(c.isDead == false);
    }
    
    void test_conwaycell_populate_3 () {
      ConwayCell c(false);
      CPPUNIT_ASSERT(c.symbol == '*');
      CPPUNIT_ASSERT(c.isDead == false);
      c.populate('*');
      CPPUNIT_ASSERT(c.symbol == '*');
      CPPUNIT_ASSERT(c.isDead == false);
    }
    
    void test_conwaycell_populate_4 () {
      ConwayCell c(false);
      CPPUNIT_ASSERT(c.symbol == '*');
      CPPUNIT_ASSERT(c.isDead == false);
      c.populate('x');
      CPPUNIT_ASSERT(c.symbol == '*');
      CPPUNIT_ASSERT(c.isDead == false);
    }
    
    void test_conwaycell_populate_5 () {
      ConwayCell c(true);
      CPPUNIT_ASSERT(c.symbol == '.');
      CPPUNIT_ASSERT(c.isDead == true);
      c.populate('x');
      CPPUNIT_ASSERT(c.symbol == '.');
      CPPUNIT_ASSERT(c.isDead == true);
    }
    
    void test_conwaycell_clone () {
      ConwayCell c(true);
      CPPUNIT_ASSERT(c.symbol == '.');
      CPPUNIT_ASSERT(c.isDead == true);
      ConwayCell* d = c.clone();
      CPPUNIT_ASSERT(d->symbol == '.');
      CPPUNIT_ASSERT(d->isDead == true);
      delete d;  // assuming this is allowable
    }
    
    void test_conwaycell_clone_2 () {
      ConwayCell c(false);
      CPPUNIT_ASSERT(c.symbol == '*');
      CPPUNIT_ASSERT(c.isDead == false);
      ConwayCell* d = c.clone();
      CPPUNIT_ASSERT(d->symbol == '*');
      CPPUNIT_ASSERT(d->isDead == false);
      delete d;  // assuming this is allowable
    }
    
    void test_conwaycell_clone_3 () {
      ConwayCell c(true);
      CPPUNIT_ASSERT(c.symbol == '.');
      CPPUNIT_ASSERT(c.isDead == true);
      AbstractCell* d = c.clone();
      CPPUNIT_ASSERT(d->isDead == true);
      delete d;
    }
    
    void test_conwaycell_update () {
      ConwayCell c(true);
      std::string nbrs = "........";
      CPPUNIT_ASSERT(c.symbol == '.');
      CPPUNIT_ASSERT(c.isDead == true);
      c.update(const_cast<char*>(nbrs.c_str()));
      CPPUNIT_ASSERT(c.symbol == '.');
      CPPUNIT_ASSERT(c.isDead == true);
    }
    void test_conwaycell_update_2 () {
      ConwayCell c(true);
      std::string nbrs = "*.......";
      CPPUNIT_ASSERT(c.symbol == '.');
      CPPUNIT_ASSERT(c.isDead == true);
      c.update(const_cast<char*>(nbrs.c_str()));
      CPPUNIT_ASSERT(c.symbol == '.');
      CPPUNIT_ASSERT(c.isDead == true);
    }
    
    void test_conwaycell_update_3 () {
      ConwayCell c(false);
      std::string nbrs = "*.......";
      CPPUNIT_ASSERT(c.symbol == '*');
      CPPUNIT_ASSERT(c.isDead == false);
      c.update(const_cast<char*>(nbrs.c_str()));
      CPPUNIT_ASSERT(c.symbol == '.');
      CPPUNIT_ASSERT(c.isDead == true);
    }
    
    void test_conwaycell_update_4 () {
      ConwayCell c(true);
      std::string nbrs = "**......";
      CPPUNIT_ASSERT(c.symbol == '.');
      CPPUNIT_ASSERT(c.isDead == true);
      c.update(const_cast<char*>(nbrs.c_str()));
      CPPUNIT_ASSERT(c.symbol == '.');
      CPPUNIT_ASSERT(c.isDead == true);
    }
    
    void test_conwaycell_update_5 () {
      ConwayCell c(false);
      std::string nbrs = "*......*";
      CPPUNIT_ASSERT(c.symbol == '*');
      CPPUNIT_ASSERT(c.isDead == false);
      c.update(const_cast<char*>(nbrs.c_str()));
      CPPUNIT_ASSERT(c.symbol == '*');
      CPPUNIT_ASSERT(c.isDead == false);
    }
    
    void test_conwaycell_update_6 () {
      ConwayCell c(false);
      std::string nbrs = "*..*...*";
      CPPUNIT_ASSERT(c.symbol == '*');
      CPPUNIT_ASSERT(c.isDead == false);
      c.update(const_cast<char*>(nbrs.c_str()));
      CPPUNIT_ASSERT(c.symbol == '*');
      CPPUNIT_ASSERT(c.isDead == false);
    }
    
    void test_conwaycell_update_7 () {
      ConwayCell c(true);
      std::string nbrs = "*..*...*";
      CPPUNIT_ASSERT(c.symbol == '.');
      CPPUNIT_ASSERT(c.isDead == true);
      c.update(const_cast<char*>(nbrs.c_str()));
      CPPUNIT_ASSERT(c.symbol == '*');
      CPPUNIT_ASSERT(c.isDead == false);
    }
    
    void test_conwaycell_update_8 () {
      ConwayCell c(true);
      std::string nbrs = "*..*.*.*";
      CPPUNIT_ASSERT(c.symbol == '.');
      CPPUNIT_ASSERT(c.isDead == true);
      c.update(const_cast<char*>(nbrs.c_str()));
      CPPUNIT_ASSERT(c.symbol == '.');
      CPPUNIT_ASSERT(c.isDead == true);
    }
    
    void test_conwaycell_update_9 () {
      ConwayCell c(false);
      std::string nbrs = "*..*.*.*";
      CPPUNIT_ASSERT(c.symbol == '*');
      CPPUNIT_ASSERT(c.isDead == false);
      c.update(const_cast<char*>(nbrs.c_str()));
      CPPUNIT_ASSERT(c.symbol == '.');
      CPPUNIT_ASSERT(c.isDead == true);
    }
    
    void test_conwaycell_update_10 () {
      ConwayCell c(false);
      std::string nbrs = "*******";
      CPPUNIT_ASSERT(c.symbol == '*');
      CPPUNIT_ASSERT(c.isDead == false);
      c.update(const_cast<char*>(nbrs.c_str()));
      CPPUNIT_ASSERT(c.symbol == '.');
      CPPUNIT_ASSERT(c.isDead == true);
    }
    
    void test_conwaycell_update_11 () {
      ConwayCell c(false);
      std::string nbrs = ".04.3.15";
      CPPUNIT_ASSERT(c.symbol == '*');
      CPPUNIT_ASSERT(c.isDead == false);
      c.update(const_cast<char*>(nbrs.c_str()));
      CPPUNIT_ASSERT(c.symbol == '.');
      CPPUNIT_ASSERT(c.isDead == true);
    }
    
    // this is proper behavior. ConwayCell has no idea about the symbols
    // for other cells, so it assumes anything that isn't '.' is alive. after all
    // there could be another class of cell that uses '-' to denote a live cell. so
    // it's life's responsibility to make sure this isn't an issue 
    void test_conwaycell_update_12 () {
      ConwayCell c(true);
      std::string nbrs = ".--.-...";
      CPPUNIT_ASSERT(c.symbol == '.');
      CPPUNIT_ASSERT(c.isDead == true);
      c.update(const_cast<char*>(nbrs.c_str()));
      CPPUNIT_ASSERT(c.symbol == '*');
      CPPUNIT_ASSERT(c.isDead == false);
    }
    
    // this is just a getter, and it returns a constant, so i'm only doing one test.
    void test_conwaycell_getDeadSymbol () {
      ConwayCell c(true);
      char ch = c.getDeadSymbol();
      CPPUNIT_ASSERT(ch == '.');
    }
    
    // conwaycell's wantstomutate always returns false, so i'm only doing one
    void test_conwaycell_wants_to_mutate () {
      ConwayCell c(true);
      bool b = c.wantsToMutate();
      CPPUNIT_ASSERT(b == false);
    }
    
    // conwaycell's mutate always returns 0 , so i'm only doing one
    void test_conwaycell_mutate () {
      ConwayCell c(true);
      char ch = c.mutate();
      CPPUNIT_ASSERT(ch == 0);
    }
    
    // only doing one test, since the default constructor only does one thing
    void test_fredkincell_default () {
      FredkinCell c;
      CPPUNIT_ASSERT(c.symbol == '-');
      CPPUNIT_ASSERT(c.isDead == true);
    }
    
     // again, only doing two tests, since constructor can only be called with 2 different arguments
    void test_fredkincell_bool () {
      FredkinCell c(true);
      CPPUNIT_ASSERT(c.symbol == '-');
      CPPUNIT_ASSERT(c.isDead == true);
      CPPUNIT_ASSERT(c.age == 0);
    }
    
    void test_fredkincell_bool_2 () {
      FredkinCell c(false);
      CPPUNIT_ASSERT(c.symbol == '0');
      CPPUNIT_ASSERT(c.isDead == false);
      CPPUNIT_ASSERT(c.age == 0);

    }
    
    void test_fredkincell_populate () {
      FredkinCell c(false);
      CPPUNIT_ASSERT(c.symbol == '0');
      CPPUNIT_ASSERT(c.isDead == false);
      CPPUNIT_ASSERT(c.age == 0);
      c.populate('-');
      CPPUNIT_ASSERT(c.symbol == '-');
      CPPUNIT_ASSERT(c.isDead == true);
      CPPUNIT_ASSERT(c.age == 0);
    }
    
    void test_fredkincell_populate_2 () {
      FredkinCell c(false);
      CPPUNIT_ASSERT(c.symbol == '0');
      CPPUNIT_ASSERT(c.isDead == false);
      CPPUNIT_ASSERT(c.age == 0);
      c.populate('0');
      CPPUNIT_ASSERT(c.symbol == '0');
      CPPUNIT_ASSERT(c.isDead == false);
      CPPUNIT_ASSERT(c.age == 0);
    }
    
    void test_fredkincell_populate_3 () {
      FredkinCell c(false);
      CPPUNIT_ASSERT(c.symbol == '0');
      CPPUNIT_ASSERT(c.isDead == false);
      CPPUNIT_ASSERT(c.age == 0);
      c.populate('5');
      CPPUNIT_ASSERT(c.symbol == '5');
      CPPUNIT_ASSERT(c.isDead == false);
      CPPUNIT_ASSERT(c.age == 5);
    }
    
    void test_fredkincell_clone () {
      FredkinCell c(true);
      CPPUNIT_ASSERT(c.symbol == '-');
      CPPUNIT_ASSERT(c.isDead == true);
      FredkinCell* d = c.clone();
      CPPUNIT_ASSERT(d->symbol == '-');
      CPPUNIT_ASSERT(d->isDead == true);
      delete d;  // assuming this is allowable
    }
    
    void test_fredkincell_clone_2 () {
      FredkinCell c(false);
      CPPUNIT_ASSERT(c.symbol == '0');
      CPPUNIT_ASSERT(c.isDead == false);
      FredkinCell* d = c.clone();
      CPPUNIT_ASSERT(d->symbol == '0');
      CPPUNIT_ASSERT(d->isDead == false);
      delete d;  // assuming this is allowable
    }
    
    void test_fredkincell_clone_3 () {
      FredkinCell c(true);
      CPPUNIT_ASSERT(c.symbol == '-');
      CPPUNIT_ASSERT(c.isDead == true);
      FredkinCell* d = c.clone();
      CPPUNIT_ASSERT(d->isDead == true);
      delete d;
    }
    
    void test_fredkincell_update () {
      FredkinCell c(true);
      std::string nbrs = "--------";
      CPPUNIT_ASSERT(c.symbol == '-');
      CPPUNIT_ASSERT(c.isDead == true);
      CPPUNIT_ASSERT(c.age == 0);
      c.update(const_cast<char*>(nbrs.c_str()));
      CPPUNIT_ASSERT(c.symbol == '-');
      CPPUNIT_ASSERT(c.isDead == true);
      CPPUNIT_ASSERT(c.age == 0);
    }
    
    void test_fredkincell_update_2 () {
      FredkinCell c(true);
      std::string nbrs = "0-------";
      CPPUNIT_ASSERT(c.symbol == '-');
      CPPUNIT_ASSERT(c.isDead == true);
      CPPUNIT_ASSERT(c.age == 0);
      c.update(const_cast<char*>(nbrs.c_str()));
      CPPUNIT_ASSERT(c.symbol == '0');
      CPPUNIT_ASSERT(c.isDead == false);
      CPPUNIT_ASSERT(c.age == 0);
    }
    
    void test_fredkincell_update_3 () {
      FredkinCell c(false);
      std::string nbrs = "0-------";
      CPPUNIT_ASSERT(c.symbol == '0');
      CPPUNIT_ASSERT(c.isDead == false);
      CPPUNIT_ASSERT(c.age == 0);
      c.update(const_cast<char*>(nbrs.c_str()));
      CPPUNIT_ASSERT(c.symbol == '1');
      CPPUNIT_ASSERT(c.isDead == false);
      CPPUNIT_ASSERT(c.age == 1);
    }
    
    void test_fredkincell_update_4 () {
      FredkinCell c(false);
      std::string nbrs = "01------";
      CPPUNIT_ASSERT(c.symbol == '0');
      CPPUNIT_ASSERT(c.isDead == false);
      CPPUNIT_ASSERT(c.age == 0);
      c.update(const_cast<char*>(nbrs.c_str()));
      CPPUNIT_ASSERT(c.symbol == '-');
      CPPUNIT_ASSERT(c.isDead == true);
      CPPUNIT_ASSERT(c.age == 0);
    }
    void test_fredkincell_update_5 () {
      FredkinCell c(false);
      std::string nbrs = "01-----2";  // note the 2 will not be considered a neighbor
      CPPUNIT_ASSERT(c.symbol == '0');
      CPPUNIT_ASSERT(c.isDead == false);
      CPPUNIT_ASSERT(c.age == 0);
      c.update(const_cast<char*>(nbrs.c_str()));
      CPPUNIT_ASSERT(c.symbol == '-');
      CPPUNIT_ASSERT(c.isDead == true);
      CPPUNIT_ASSERT(c.age == 0);
    }
    void test_fredkincell_update_6 () {
      FredkinCell c(false);
      c.populate('9');
      std::string nbrs = "0------1";
      CPPUNIT_ASSERT(c.symbol == '9');
      CPPUNIT_ASSERT(c.isDead == false);
      CPPUNIT_ASSERT(c.age == 9);
      c.update(const_cast<char*>(nbrs.c_str()));
      CPPUNIT_ASSERT(c.symbol == '+');
      CPPUNIT_ASSERT(c.isDead == false);
      CPPUNIT_ASSERT(c.age == 10);
    }
    
    // this is just a getter, and it returns a constant, so i'm only doing one test.
    void test_fredkincell_getDeadSymbol () {
      FredkinCell c(true);
      char ch = c.getDeadSymbol();
      CPPUNIT_ASSERT(ch == '-');
    }
    
    void test_fredkincell_wants_to_mutate () {
      FredkinCell c(true);
      bool b = c.wantsToMutate();
      CPPUNIT_ASSERT(b == false);
    }
    
    void test_fredkincell_wants_to_mutate_2 () {
      FredkinCell c(true);
      bool b = c.wantsToMutate();
      CPPUNIT_ASSERT(b == false);
      c.populate('2');
      b = c.wantsToMutate();
      CPPUNIT_ASSERT(b == true);
    }
    
    // conwaycell's mutate always returns '*' so i'm only doing one
    void test_fredkincell_mutate () {
      FredkinCell c(true);
      char ch = c.mutate();
      CPPUNIT_ASSERT(ch == '*');
    }
    
    // I'm only testing cell's one-liners twice--once for Fredkin, once for Conway, since
    // they just call stuff I've already tested
    
    void test_cell() {
      Cell c(new FredkinCell());
      char ch = c.getDeadSymbol();
      CPPUNIT_ASSERT(ch == '-');
    }
    
    void test_cell_2() {
      Cell c(new ConwayCell());
      char ch = c.getDeadSymbol();
      CPPUNIT_ASSERT(ch == '.');
    }
    
    void test_cell_update() {
      FredkinCell* f = new FredkinCell(false);
      Cell c(f);
      std::string nbrs = "01------";
      CPPUNIT_ASSERT(f->symbol == '0');
      CPPUNIT_ASSERT(f->isDead == false);
      CPPUNIT_ASSERT(f->age == 0);
      c.update(const_cast<char*>(nbrs.c_str()));
      CPPUNIT_ASSERT(f->symbol == '-');
      CPPUNIT_ASSERT(f->isDead == true);
      CPPUNIT_ASSERT(f->age == 0);
    }
    
    void test_cell_update_2() {
      ConwayCell* cc = new ConwayCell(false);
      Cell c(cc);
      std::string nbrs = "*.......";
      CPPUNIT_ASSERT(cc->symbol == '*');
      CPPUNIT_ASSERT(cc->isDead == false);
      c.update(const_cast<char*>(nbrs.c_str()));
      CPPUNIT_ASSERT(cc->symbol == '.');
      CPPUNIT_ASSERT(cc->isDead == true);
    }
    
    void test_cell_populate() {
      FredkinCell* f = new FredkinCell(false);
      Cell c(f);
      CPPUNIT_ASSERT(f->symbol == '0');
      CPPUNIT_ASSERT(f->isDead == false);
      CPPUNIT_ASSERT(f->age == 0);
      c.populate('9');
      CPPUNIT_ASSERT(f->symbol == '9');
      CPPUNIT_ASSERT(f->isDead == false);
      CPPUNIT_ASSERT(f->age == 9);
    }
    
    void test_cell_populate_2() {
      ConwayCell* cc = new ConwayCell(false);
      Cell c(cc);
      CPPUNIT_ASSERT(cc->symbol == '*');
      CPPUNIT_ASSERT(cc->isDead == false);
      c.populate('.');
      CPPUNIT_ASSERT(cc->symbol == '.');
      CPPUNIT_ASSERT(cc->isDead == true);
    }
    
    void test_cell_getDeadSymbol() {
      Cell c(new FredkinCell());
      char ch = c.getDeadSymbol();
      CPPUNIT_ASSERT(ch == '-');
    }
    
    void test_cell_getDeadSymbol_2() {
      Cell c(new ConwayCell());
      char ch = c.getDeadSymbol();
      CPPUNIT_ASSERT(ch == '.');
    }
    
    void test_life_read() {
      Life<Cell> l(new FredkinCell(true));
      std::istringstream r("5\n5\n00-00\n00-00\n00-00\n00-00\n00-00");
      l.read(r);
      CPPUNIT_ASSERT(l.x == 5);
      CPPUNIT_ASSERT(l.y == 5);
      CPPUNIT_ASSERT(l.pop == 20);
      CPPUNIT_ASSERT(l.generation == 0);
      CPPUNIT_ASSERT(l.deadsymbol == '-');
      CPPUNIT_ASSERT(l.grid.size() == l.graphics.size());
      CPPUNIT_ASSERT(l.grid.size() == 7);
      CPPUNIT_ASSERT(l.grid[0].size() == l.graphics[0].size());
      CPPUNIT_ASSERT(l.grid[0].size() == 7);

    }
    
    void test_life_read_2() {
      Life<Cell> l(new ConwayCell(true));
      std::istringstream r("5\n5\n*..**\n*..**\n**..*\n**.**\n*****");
      l.read(r);
      CPPUNIT_ASSERT(l.x == 5);
      CPPUNIT_ASSERT(l.y == 5);
      CPPUNIT_ASSERT(l.pop == 18);
      CPPUNIT_ASSERT(l.generation == 0);
      CPPUNIT_ASSERT(l.deadsymbol == '.');
      CPPUNIT_ASSERT(l.grid.size() == l.graphics.size());
      CPPUNIT_ASSERT(l.grid.size() == 7);
      CPPUNIT_ASSERT(l.grid[0].size() == l.graphics[0].size());
      CPPUNIT_ASSERT(l.grid[0].size() == 7);

    }
    
    void test_life_read_3() {
      Life<FredkinCell> l(FredkinCell(true));
      std::istringstream r("5\n5\n00-00\n00-00\n00-00\n00-00\n00-00");
      l.read(r);
      CPPUNIT_ASSERT(l.x == 5);
      CPPUNIT_ASSERT(l.y == 5);
      CPPUNIT_ASSERT(l.pop == 20);
      CPPUNIT_ASSERT(l.generation == 0);
      CPPUNIT_ASSERT(l.deadsymbol == '-');
      CPPUNIT_ASSERT(l.grid.size() == l.graphics.size());
      CPPUNIT_ASSERT(l.grid.size() == 7);
      CPPUNIT_ASSERT(l.grid[0].size() == l.graphics[0].size());
      CPPUNIT_ASSERT(l.grid[0].size() == 7);

    }
    
    void test_life_getNeighbors() {
      char neighbors[8];
      Life<ConwayCell> l(ConwayCell(true));
      std::istringstream r("5\n5\n*.***\n*....\n.....\n.....\n.....");
      l.read(r);
      l.getNeighbors(neighbors, 1, 1);
      int count = 0;
      for(int i =0; i< 8; ++i) {
	if(neighbors[i] == '*')
	  ++count;
      }
      
      CPPUNIT_ASSERT(l.x == 5);
      CPPUNIT_ASSERT(l.y == 5);
      CPPUNIT_ASSERT(l.pop == 5);
      CPPUNIT_ASSERT(l.generation == 0);
      CPPUNIT_ASSERT(l.deadsymbol == '.');
      CPPUNIT_ASSERT(l.grid.size() == l.graphics.size());
      CPPUNIT_ASSERT(l.grid.size() == 7);
      CPPUNIT_ASSERT(l.grid[0].size() == l.graphics[0].size());
      CPPUNIT_ASSERT(l.grid[0].size() == 7);
      CPPUNIT_ASSERT(count == 1);

    }
    
    void test_life_getNeighbors_2() {
      char neighbors[8];
      Life<ConwayCell> l(ConwayCell(true));
      std::istringstream r("5\n5\n*.***\n*....\n.....\n.....\n.....");
      l.read(r);
      l.getNeighbors(neighbors, 1, 1);
      int count = 0;
      for(int i =0; i< 8; ++i) {
	if(neighbors[i] == '*')
	  ++count;
      }
      
      CPPUNIT_ASSERT(l.x == 5);
      CPPUNIT_ASSERT(l.y == 5);
      CPPUNIT_ASSERT(l.pop == 5);
      CPPUNIT_ASSERT(l.generation == 0);
      CPPUNIT_ASSERT(l.deadsymbol == '.');
      CPPUNIT_ASSERT(l.grid.size() == l.graphics.size());
      CPPUNIT_ASSERT(l.grid.size() == 7);
      CPPUNIT_ASSERT(l.grid[0].size() == l.graphics[0].size());
      CPPUNIT_ASSERT(l.grid[0].size() == 7);
      CPPUNIT_ASSERT(count == 1);

    }
    
    void test_life_getNeighbors_3() {
      char neighbors[8];
      Life<ConwayCell> l(ConwayCell(true));
      std::istringstream r("5\n5\n*.***\n*....\n.***.\n.....\n.....");
      l.read(r);
      l.getNeighbors(neighbors, 4, 4);
      int count = 0;
      for(int i =0; i< 8; ++i) {
	if(neighbors[i] == '*')
	  ++count;
      }
      
      CPPUNIT_ASSERT(l.x == 5);
      CPPUNIT_ASSERT(l.y == 5);
      CPPUNIT_ASSERT(l.pop == 8);
      CPPUNIT_ASSERT(l.generation == 0);
      CPPUNIT_ASSERT(l.deadsymbol == '.');
      CPPUNIT_ASSERT(l.grid.size() == l.graphics.size());
      CPPUNIT_ASSERT(l.grid.size() == 7);
      CPPUNIT_ASSERT(l.grid[0].size() == l.graphics[0].size());
      CPPUNIT_ASSERT(l.grid[0].size() == 7);
      CPPUNIT_ASSERT(count == 2);

    }
    
    //step tests also test updategraphics, as far as i'm concerned
    void test_life_step() {
      Life<ConwayCell> l(ConwayCell(true));
      std::istringstream r("5\n5\n*.***\n*....\n.***.\n.....\n.....");
      l.read(r);
      l.step();
      
      CPPUNIT_ASSERT(l.x == 5);
      CPPUNIT_ASSERT(l.y == 5);
      CPPUNIT_ASSERT(l.pop == 7);
      CPPUNIT_ASSERT(l.generation == 1);
      CPPUNIT_ASSERT(l.deadsymbol == '.');
      CPPUNIT_ASSERT(l.grid.size() == l.graphics.size());
      CPPUNIT_ASSERT(l.grid.size() == 7);
      CPPUNIT_ASSERT(l.grid[0].size() == l.graphics[0].size());
      CPPUNIT_ASSERT(l.grid[0].size() == 7);
      CPPUNIT_ASSERT(l.graphics[1][2] == '*');
      CPPUNIT_ASSERT(l.graphics[1][1] == '.');


    }
    
    void test_life_step_2() {
      Life<FredkinCell> l(FredkinCell(true));
      std::istringstream r("5\n5\n--0--\n--0--\n-----\n-----\n-----");
      l.read(r);
      l.step();
      
      CPPUNIT_ASSERT(l.x == 5);
      CPPUNIT_ASSERT(l.y == 5);
      CPPUNIT_ASSERT(l.pop == 7);
      CPPUNIT_ASSERT(l.generation == 1);
      CPPUNIT_ASSERT(l.deadsymbol == '-');
      CPPUNIT_ASSERT(l.grid.size() == l.graphics.size());
      CPPUNIT_ASSERT(l.grid.size() == 7);
      CPPUNIT_ASSERT(l.grid[0].size() == l.graphics[0].size());
      CPPUNIT_ASSERT(l.grid[0].size() == 7);
      CPPUNIT_ASSERT(l.graphics[1][3] == '1');
      CPPUNIT_ASSERT(l.graphics[1][2] == '0');
    }
    
    void test_life_step_3() {
      Life<Cell> l(new FredkinCell(true));
      std::istringstream r("5\n5\n--0--\n--0--\n-----\n-----\n-----");
      l.read(r);
      l.step();
      l.step();
      
      CPPUNIT_ASSERT(l.x == 5);
      CPPUNIT_ASSERT(l.y == 5);
      CPPUNIT_ASSERT(l.pop == 7);
      CPPUNIT_ASSERT(l.generation == 2);
      CPPUNIT_ASSERT(l.deadsymbol == '-');
      CPPUNIT_ASSERT(l.grid.size() == l.graphics.size());
      CPPUNIT_ASSERT(l.grid.size() == 7);
      CPPUNIT_ASSERT(l.grid[0].size() == l.graphics[0].size());
      CPPUNIT_ASSERT(l.grid[0].size() == 7);
      CPPUNIT_ASSERT(l.graphics[1][3] == '*');
      CPPUNIT_ASSERT(l.graphics[1][1] == '0');
      CPPUNIT_ASSERT(l.graphics[3][3] == '1');
    }
    
    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST(test_conwaycell_default);
    CPPUNIT_TEST(test_conwaycell_bool);
    CPPUNIT_TEST(test_conwaycell_bool_2);
    CPPUNIT_TEST(test_conwaycell_populate);
    CPPUNIT_TEST(test_conwaycell_populate_2);
    CPPUNIT_TEST(test_conwaycell_populate_3);
    CPPUNIT_TEST(test_conwaycell_populate_4);
    CPPUNIT_TEST(test_conwaycell_populate_5);
    CPPUNIT_TEST(test_conwaycell_clone);
    CPPUNIT_TEST(test_conwaycell_clone_2);
    CPPUNIT_TEST(test_conwaycell_clone_3);
    CPPUNIT_TEST(test_conwaycell_update);
    CPPUNIT_TEST(test_conwaycell_update_2);
    CPPUNIT_TEST(test_conwaycell_update_3);
    CPPUNIT_TEST(test_conwaycell_update_4);
    CPPUNIT_TEST(test_conwaycell_update_5);
    CPPUNIT_TEST(test_conwaycell_update_6);
    CPPUNIT_TEST(test_conwaycell_update_7);
    CPPUNIT_TEST(test_conwaycell_update_8);
    CPPUNIT_TEST(test_conwaycell_update_9);
    CPPUNIT_TEST(test_conwaycell_update_10);
    CPPUNIT_TEST(test_conwaycell_update_11);
    CPPUNIT_TEST(test_conwaycell_update_12);
    CPPUNIT_TEST(test_conwaycell_getDeadSymbol);
    CPPUNIT_TEST(test_conwaycell_wants_to_mutate);
    CPPUNIT_TEST(test_conwaycell_mutate);
    CPPUNIT_TEST(test_fredkincell_default);
    CPPUNIT_TEST(test_fredkincell_populate);
    CPPUNIT_TEST(test_fredkincell_populate_2);
    CPPUNIT_TEST(test_fredkincell_populate_3);
    CPPUNIT_TEST(test_fredkincell_clone);
    CPPUNIT_TEST(test_fredkincell_clone_2);
    CPPUNIT_TEST(test_fredkincell_clone_3);
    CPPUNIT_TEST(test_fredkincell_update);
    CPPUNIT_TEST(test_fredkincell_update_2);
    CPPUNIT_TEST(test_fredkincell_update_3);
    CPPUNIT_TEST(test_fredkincell_update_4);
    CPPUNIT_TEST(test_fredkincell_update_5);
    CPPUNIT_TEST(test_fredkincell_update_6);
    CPPUNIT_TEST(test_fredkincell_getDeadSymbol);
    CPPUNIT_TEST(test_fredkincell_wants_to_mutate);
    CPPUNIT_TEST(test_fredkincell_wants_to_mutate_2);
    CPPUNIT_TEST(test_fredkincell_mutate);
    CPPUNIT_TEST(test_cell);
    CPPUNIT_TEST(test_cell_2);
    CPPUNIT_TEST(test_cell_update);
    CPPUNIT_TEST(test_cell_update_2);
    CPPUNIT_TEST(test_cell_populate);
    CPPUNIT_TEST(test_cell_populate_2);
    CPPUNIT_TEST(test_cell_getDeadSymbol);
    CPPUNIT_TEST(test_cell_getDeadSymbol_2);
    CPPUNIT_TEST(test_life_read);
    CPPUNIT_TEST(test_life_read_2);
    CPPUNIT_TEST(test_life_read_3);
    CPPUNIT_TEST(test_life_getNeighbors);
    CPPUNIT_TEST(test_life_getNeighbors_2);
    CPPUNIT_TEST(test_life_getNeighbors_3);
    CPPUNIT_TEST(test_life_step);
    CPPUNIT_TEST(test_life_step_2);
    CPPUNIT_TEST(test_life_step_3);

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
