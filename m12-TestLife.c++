/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -lcppunit -ldl -pedantic -std=c++0x -Wall TestLife.c++ -o TestLife
    % valgrind ./TestLife >& TestLife.out
*/

#define private public
#define protected public

// --------
// includes
// --------

#include <vector>
#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <utility>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#include "Handle.h"
#include "Cell.h"
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Life.h"

// -----------
// TestLife
// -----------

template <typename T>
struct TestLife : CppUnit::TestFixture {

	// ------------------
	// test_constructor
	// ------------------
	void test_constructor_1() {
		T t(false);
		CPPUNIT_ASSERT(t._age == 0);
		CPPUNIT_ASSERT(t._alive == false);
	}

	void test_constructor_2() {
		T t(true);
		CPPUNIT_ASSERT(t._age == 0);
		CPPUNIT_ASSERT(t._alive == true);
	}

	void test_constructor_3() {
		T t1(true);
		CPPUNIT_ASSERT(t1._age == 0);
		CPPUNIT_ASSERT(t1._alive == true);
		T t2(true);
		CPPUNIT_ASSERT(t2._age == 0);
		CPPUNIT_ASSERT(t2._alive == true);
	}

	void test_constructor_4() {
		FredkinCell f(true);
		CPPUNIT_ASSERT(f._age == 0);
		CPPUNIT_ASSERT(f._alive == true);
		CPPUNIT_ASSERT(f._mutateRequested == false);
	}


	// ----------------------
	// test_Cell_constructor
	// ----------------------
	void test_Cell_constructor_1() {
		Cell c = Cell(new T(false));
		CPPUNIT_ASSERT(c.Handle<AbstractCell>::get()->_age == 0);
		CPPUNIT_ASSERT(c.Handle<AbstractCell>::get()->_alive == false);
		CPPUNIT_ASSERT(c.mutateRequested() == false);
	}

	void test_Cell_constructor_2() {
		Cell c = Cell(new T(true));
		CPPUNIT_ASSERT(c.Handle<AbstractCell>::get()->_age == 0);
		CPPUNIT_ASSERT(c.Handle<AbstractCell>::get()->_alive == true);
		CPPUNIT_ASSERT(c.mutateRequested() == false);
	}

	void test_Cell_constructor_3() {
		Cell c = Cell(new FredkinCell(true));
		CPPUNIT_ASSERT(c.Handle<AbstractCell>::get()->_age == 0);
		CPPUNIT_ASSERT(c.Handle<AbstractCell>::get()->_alive == true);
		CPPUNIT_ASSERT(c.mutateRequested() == false);
	}

	void test_Cell_constructor_4() {
		Cell c = Cell(new ConwayCell(true));
		CPPUNIT_ASSERT(c.Handle<AbstractCell>::get()->_age == 0);
		CPPUNIT_ASSERT(c.Handle<AbstractCell>::get()->_alive == true);
		CPPUNIT_ASSERT(c.mutateRequested() == false);
	}

	// ------------------
	// test_Cell_mutate
	// -----------------
	void test_Cell_mutate_1() {
		Cell c1(new FredkinCell(true));
		CPPUNIT_ASSERT(dynamic_cast<FredkinCell *>(c1.Handle<AbstractCell>::get()));
		CPPUNIT_ASSERT(!dynamic_cast<ConwayCell *>(c1.Handle<AbstractCell>::get()));
		CPPUNIT_ASSERT(c1.isAlive());
		c1.mutate();
		CPPUNIT_ASSERT(dynamic_cast<ConwayCell *>(c1.Handle<AbstractCell>::get()));
		CPPUNIT_ASSERT(!dynamic_cast<FredkinCell *>(c1.Handle<AbstractCell>::get()));
		CPPUNIT_ASSERT(c1.isAlive());
	}

	void test_Cell_mutate_2() {
		Cell c1(new ConwayCell(true));
		CPPUNIT_ASSERT(dynamic_cast<ConwayCell *>(c1.Handle<AbstractCell>::get()));
		CPPUNIT_ASSERT(!dynamic_cast<FredkinCell *>(c1.Handle<AbstractCell>::get()));
		c1.mutate();
		CPPUNIT_ASSERT(dynamic_cast<ConwayCell *>(c1.Handle<AbstractCell>::get()));
		CPPUNIT_ASSERT(!dynamic_cast<FredkinCell *>(c1.Handle<AbstractCell>::get()));
		CPPUNIT_ASSERT(c1.isAlive());
		CPPUNIT_ASSERT(c1.mutateRequested() == false);
	}

	void test_Cell_mutate_3() {
		Cell c1(new FredkinCell(false));
		CPPUNIT_ASSERT(!dynamic_cast<ConwayCell *>(c1.Handle<AbstractCell>::get()));
		CPPUNIT_ASSERT(dynamic_cast<FredkinCell *>(c1.Handle<AbstractCell>::get()));
		c1.mutate();
		CPPUNIT_ASSERT(dynamic_cast<ConwayCell *>(c1.Handle<AbstractCell>::get()));
		CPPUNIT_ASSERT(!dynamic_cast<FredkinCell *>(c1.Handle<AbstractCell>::get()));
		CPPUNIT_ASSERT(c1.isAlive());
		CPPUNIT_ASSERT(c1.mutateRequested() == false);
	}

	// --------------------------
	// test_Cell_mutateRequested
	// --------------------------

	void test_Cell_mutateRequested_1(){
		FredkinCell f(true);
		CPPUNIT_ASSERT(f._mutateRequested == false);
		CPPUNIT_ASSERT(!f.mutateRequested());
		f._mutateRequested = true;
		CPPUNIT_ASSERT(f.mutateRequested());
		CPPUNIT_ASSERT(f._mutateRequested == false);
	}

	void test_Cell_mutateRequested_2(){
		ConwayCell f(true);
		CPPUNIT_ASSERT(!f.mutateRequested());
	}
		
	void test_Cell_mutateRequested_3(){
		Cell c(new FredkinCell (true));
		CPPUNIT_ASSERT(!c.mutateRequested());
		CPPUNIT_ASSERT(!c.mutateRequested());
		CPPUNIT_ASSERT(c.Handle<AbstractCell>::get()->_alive == true);
	}

	// ----------------
	// test_Cell_clone
	// ----------------

	void test_Cell_clone_1(){
		T t1(true);
		T* t2 = t1.clone();
		CPPUNIT_ASSERT(t2->_alive);
		delete t2;
	}

	void test_Cell_clone_2(){
		T t1(false);
		T* t2 = t1.clone();
		CPPUNIT_ASSERT(!t2->_alive);
		delete t2;
	}

	void test_Cell_clone_3(){
		Cell c1(new T(true));
		Cell c2(c1.Handle<AbstractCell>::get()->clone());
		c2.Handle<AbstractCell>::get()->_alive = false;
		CPPUNIT_ASSERT(!c2.Handle<AbstractCell>::get()->_alive);
	}

	// --------------------------
	// test_Cell_liveNeighbors
	// --------------------------

	void test_Cell_liveNeighbors_1(){
		ConwayCell c1(false);
		vector<bool> v(8, false);
		v[0] = true;
		v[1] = true;
		v[2] = true;
		char ch = c1.liveNeighbors(v);
		CPPUNIT_ASSERT(c1._alive);
		CPPUNIT_ASSERT(ch == '*');
		v[3] = true;
		ch = c1.liveNeighbors(v);
		CPPUNIT_ASSERT(!c1._alive);
		CPPUNIT_ASSERT(ch == '.');
	}

	void test_Cell_liveNeighbors_2(){
		FredkinCell c1(false);
		vector<bool> v(8, false);
		v[0] = true;
		v[1] = true;
		char ch = c1.liveNeighbors(v);
		CPPUNIT_ASSERT(c1._alive);
		CPPUNIT_ASSERT(ch == '0');
		v[2] = true;
		ch = c1.liveNeighbors(v);
		CPPUNIT_ASSERT(!c1._alive);
		CPPUNIT_ASSERT(ch == '-');
	}

	void test_Cell_liveNeighbors_3(){
		Cell c(new FredkinCell (false));
		vector<bool> v(8, false);
		v[0] = true;
		v[1] = true;
		char ch = c.Handle<AbstractCell>::get()->liveNeighbors(v);
		CPPUNIT_ASSERT(c.Handle<AbstractCell>::get()->_alive);
		CPPUNIT_ASSERT(ch == '0');
		v[2] = true;
		ch = c.Handle<AbstractCell>::get()->liveNeighbors(v);
		CPPUNIT_ASSERT(!c.Handle<AbstractCell>::get()->_alive);
		CPPUNIT_ASSERT(ch == '-');
	}

	// --------------------------
	// test_Cell_toggle_alive
	// --------------------------

	void test_Cell_toggle_alive_1(){
		ConwayCell c(true);
		c.toggle_alive();
		CPPUNIT_ASSERT(!c._alive);
	}

	void test_Cell_toggle_alive_2(){
		FredkinCell f(false);
		f.toggle_alive();
		CPPUNIT_ASSERT(f._alive);
	}

	void test_Cell_toggle_alive_3(){
		Cell c(new FredkinCell(true));
		c.Handle<AbstractCell>::get()->toggle_alive();
		CPPUNIT_ASSERT(!c.Handle<AbstractCell>::get()->_alive);
	}

	// --------------------------
	// test_Cell_increment_age
	// --------------------------

	void test_Cell_increment_age_1(){
		T c(true);
		c.increment_age();
		c.increment_age();
		CPPUNIT_ASSERT(c._age == 2);
	}

	void test_Cell_increment_age_2(){
		T f(true);
		f.increment_age();
		f.increment_age();
		f.increment_age();
		CPPUNIT_ASSERT(f._age == 3);
	}

	void test_Cell_increment_age_3(){
		Cell c(new T(true));
		c.Handle<AbstractCell>::get()->increment_age();
		c.Handle<AbstractCell>::get()->increment_age();
		c.Handle<AbstractCell>::get()->increment_age();
		CPPUNIT_ASSERT(c.Handle<AbstractCell>::get()->_age == 3);
	}

	// --------------------------
	// test_Cell_get_age
	// --------------------------

	void test_Cell_get_age_1(){
		T c(true);
		c.increment_age();
		c.increment_age();
		CPPUNIT_ASSERT(c.get_age() == 2);
	}

	void test_Cell_get_age_2(){
		T f(true);
		f.increment_age();
		f.increment_age();
		f.increment_age();
		CPPUNIT_ASSERT(f.get_age() == 3);
	}

	void test_Cell_get_age_3(){
		Cell c(new T(true));
		c.Handle<AbstractCell>::get()->increment_age();
		c.Handle<AbstractCell>::get()->increment_age();
		c.Handle<AbstractCell>::get()->increment_age();
		CPPUNIT_ASSERT(c.Handle<AbstractCell>::get()->get_age() == 3);
	}


	// -----------------
	// test_Life_constructor
	// -----------------
	void test_Life_constructor_1() {
		Life<T> l(1,1, T(false));
		CPPUNIT_ASSERT(l._rows == 1);
		CPPUNIT_ASSERT(l._cols == 1);
		CPPUNIT_ASSERT(l._gen_num == 0);
		CPPUNIT_ASSERT(l._live_cells == 0);
		CPPUNIT_ASSERT(l._cells.size() == 1);
		CPPUNIT_ASSERT(l._cells[0].size() == 1);
		CPPUNIT_ASSERT(l._current_grid.size() == 1);
		CPPUNIT_ASSERT(l._current_grid[0].size() == 1);
	}

	void test_Life_constructor_2() {
		Life<T> l(10,10, T(false));
		CPPUNIT_ASSERT(l._rows == 10);
		CPPUNIT_ASSERT(l._cols == 10);
		CPPUNIT_ASSERT(l._gen_num == 0);
		CPPUNIT_ASSERT(l._live_cells == 0);
		CPPUNIT_ASSERT(l._cells.size() == 10);
		CPPUNIT_ASSERT(l._cells[0].size() == 10);
		CPPUNIT_ASSERT(l._current_grid.size() == 10);
		CPPUNIT_ASSERT(l._current_grid[0].size() == 10);
	}

	void test_Life_constructor_3() {
		Life<Cell> l(100,100, new T(false));
		CPPUNIT_ASSERT(l._rows == 100);
		CPPUNIT_ASSERT(l._cols == 100);
		CPPUNIT_ASSERT(l._gen_num == 0);
		CPPUNIT_ASSERT(l._live_cells == 0);
		CPPUNIT_ASSERT(l._cells.size() == 100);
		CPPUNIT_ASSERT(l._cells[0].size() == 100);
		CPPUNIT_ASSERT(l._current_grid.size() == 100);
		CPPUNIT_ASSERT(l._current_grid[0].size() == 100);
	}
	
	// ------------------
	// test_Life_add_cell
	// ------------------
	void test_Life_add_cell_1() {
		Life<ConwayCell> l(100,100,ConwayCell(false));
		l.add_cell(10,10,ConwayCell(true), '*');
		l.add_cell(10,11,ConwayCell(true), '*');
		l.add_cell(10,12,ConwayCell(true), '*');
		l.add_cell(10,13,ConwayCell(true), '*');
		CPPUNIT_ASSERT(l._cells[10][10].isAlive());
		CPPUNIT_ASSERT(l._cells[10][11].isAlive());
		CPPUNIT_ASSERT(l._cells[10][12].isAlive());
		CPPUNIT_ASSERT(l._cells[10][13].isAlive());
		CPPUNIT_ASSERT(l._current_grid[10][10] == '*');
		CPPUNIT_ASSERT(l._current_grid[10][11] == '*');
		CPPUNIT_ASSERT(l._current_grid[10][12] == '*');
		CPPUNIT_ASSERT(l._current_grid[10][13] == '*');
	}

	void test_Life_add_cell_2() {
		Life<FredkinCell> l(100,100,FredkinCell(false));
		l.add_cell(30,10,FredkinCell(true), '0');
		l.add_cell(30,11,FredkinCell(true), '0');
		l.add_cell(30,12,FredkinCell(true), '0');
		l.add_cell(30,13,FredkinCell(true), '0');
		CPPUNIT_ASSERT(l._cells[30][10].isAlive());
		CPPUNIT_ASSERT(l._cells[30][11].isAlive());
		CPPUNIT_ASSERT(l._cells[30][12].isAlive());
		CPPUNIT_ASSERT(l._cells[30][13].isAlive());
		CPPUNIT_ASSERT(l._current_grid[30][10] == '0');
		CPPUNIT_ASSERT(l._current_grid[30][11] == '0');
		CPPUNIT_ASSERT(l._current_grid[30][12] == '0');
		CPPUNIT_ASSERT(l._current_grid[30][13] == '0');
	}

	void test_Life_add_cell_3() {
		Life<Cell> l(100,100, new FredkinCell(false));
		l.add_cell(50,10,new FredkinCell(true), '0');
		l.add_cell(50,11,new FredkinCell(true), '0');
		l.add_cell(50,12,new FredkinCell(true), '0');
		l.add_cell(50,13,new FredkinCell(true), '0');
		l.add_cell(50,14,new FredkinCell(true), '0');
		CPPUNIT_ASSERT(l._cells[50][10].isAlive());
		CPPUNIT_ASSERT(l._cells[50][11].isAlive());
		CPPUNIT_ASSERT(l._cells[50][12].isAlive());
		CPPUNIT_ASSERT(l._cells[50][13].isAlive());
		CPPUNIT_ASSERT(l._cells[50][14].isAlive());
		CPPUNIT_ASSERT(l._current_grid[50][10] == '0');
		CPPUNIT_ASSERT(l._current_grid[50][11] == '0');
		CPPUNIT_ASSERT(l._current_grid[50][12] == '0');
		CPPUNIT_ASSERT(l._current_grid[50][13] == '0');
		CPPUNIT_ASSERT(l._current_grid[50][14] == '0');
		CPPUNIT_ASSERT(l._cells[50].size() == 100);
	}

	// ----------------
	// test_Life_print
	// ----------------
	void test_Life_print1(){
		Life<ConwayCell> one(1,1,ConwayCell(false));
		Life<ConwayCell> two(1,1,ConwayCell(false));
		one.add_cell(0,0, ConwayCell(true), '*');
		two._current_grid[0][0] = '*';
		++two._live_cells;
		std::stringstream s1;
		std::stringstream s2;
		one.print(s1);
		two.print(s2);
		CPPUNIT_ASSERT(s1.str() == s2.str());
	}

	void test_Life_print2(){
		Life<FredkinCell> one(1,1,FredkinCell(false));
		Life<FredkinCell> two(1,1,FredkinCell(false));
		one.add_cell(0,0, FredkinCell(true), '0');
		two._current_grid[0][0] = '0';
		++two._live_cells;
		std::stringstream s1;
		std::stringstream s2;
		one.print(s1);
		two.print(s2);
		CPPUNIT_ASSERT(s1.str() == s2.str());
	}

	void test_Life_print3(){
		Life<Cell> one(1,1,new FredkinCell(false));
		Life<Cell> two(1,1,new FredkinCell(false));
		one.add_cell(0,0, new FredkinCell(true), '*');
		two._current_grid[0][0] = '*';
		++two._live_cells;
		std::stringstream s1;
		std::stringstream s2;
		one.print(s1);
		two.print(s2);
		CPPUNIT_ASSERT(s1.str() == s2.str());
	}

	// -----------------
	// test_Life_isAlive
	// -----------------
	void test_Life_isAlive1(){
		Life<T> l(1,1,T(false));
		char c1 = '.';
		char c2 = '*';
		CPPUNIT_ASSERT(!l.isAlive(c1) && l.isAlive(c2));
	}

	void test_Life_isAlive2(){
		Life<T> l(1,1,T(false));
		char c1 = '0';
		char c2 = '-';
		CPPUNIT_ASSERT(l.isAlive(c1) && !l.isAlive(c2));
	}

	void test_Life_isAlive3(){
		Life<Cell> l(1,1,new T(false));
		char c1 = '*';
		char c2 = '0';
		CPPUNIT_ASSERT(l.isAlive(c1) && l.isAlive(c2));
	}

	// ----------------------
	// test_Live_getNeighbors
	// ----------------------
	void test_Life_getNeighbors1(){
		Life<T> l(1,1,T(false));
		l.add_cell(0,0,T(true),'*');
		vector<bool> neighbors = l.getNeighbors(0,0);
		CPPUNIT_ASSERT(neighbors.size() == 8);
		CPPUNIT_ASSERT(!neighbors[0]);
		CPPUNIT_ASSERT(!neighbors[1]);
		CPPUNIT_ASSERT(!neighbors[2]);
		CPPUNIT_ASSERT(!neighbors[3]);
		CPPUNIT_ASSERT(!neighbors[4]);
		CPPUNIT_ASSERT(!neighbors[5]);
		CPPUNIT_ASSERT(!neighbors[6]);
		CPPUNIT_ASSERT(!neighbors[7]);
	}

	void test_Life_getNeighbors2(){
		Life<FredkinCell> l(100,100,FredkinCell(false));
		l.add_cell(50,50,FredkinCell(true),'0');
		l.add_cell(49,50,FredkinCell(true),'0');
		l.add_cell(51,51,FredkinCell(true),'0');
		l.add_cell(50,49,FredkinCell(true),'0');
		l.add_cell(49,49,FredkinCell(true),'0');
		vector<bool> neighbors = l.getNeighbors(50,50);
		CPPUNIT_ASSERT(neighbors.size() == 8);
		CPPUNIT_ASSERT(neighbors[0]);
		CPPUNIT_ASSERT(!neighbors[1]);
		CPPUNIT_ASSERT(!neighbors[2]);
		CPPUNIT_ASSERT(neighbors[3]);
		CPPUNIT_ASSERT(!neighbors[4]);
		CPPUNIT_ASSERT(!neighbors[5]);
		CPPUNIT_ASSERT(neighbors[6]);
		CPPUNIT_ASSERT(neighbors[7]);
	}

	void test_Life_getNeighbors3(){
		Life<FredkinCell> l(100,100,FredkinCell(false));
		l.add_cell(99,99,FredkinCell(true),'0');
		l.add_cell(99,98,FredkinCell(true),'0');
		l.add_cell(98,98,FredkinCell(true),'0');
		l.add_cell(98,99,FredkinCell(true),'0');
		vector<bool> neighbors = l.getNeighbors(99,99);
		CPPUNIT_ASSERT(neighbors.size() == 8);
		CPPUNIT_ASSERT(neighbors[0]);
		CPPUNIT_ASSERT(!neighbors[1]);
		CPPUNIT_ASSERT(!neighbors[2]);
		CPPUNIT_ASSERT(!neighbors[3]);
		CPPUNIT_ASSERT(!neighbors[4]);
		CPPUNIT_ASSERT(!neighbors[5]);
		CPPUNIT_ASSERT(neighbors[6]);
		CPPUNIT_ASSERT(neighbors[7]);
	}

	// -------------------
	// test_Life_simulate
	// -------------------

	void test_Life_simulate_1(){
		Life<ConwayCell> l(2,2,ConwayCell(false));
		l.add_cell(0,0,ConwayCell(true), '*');
		l.add_cell(0,1,ConwayCell(true), '*');
		l.add_cell(1,0,ConwayCell(true), '*');
		stringstream ss;
		l.simulate(1,ss,1);
		CPPUNIT_ASSERT(l._cells[0][0]._alive);
		CPPUNIT_ASSERT(l._cells[1][0]._alive);
		CPPUNIT_ASSERT(l._cells[0][1]._alive);
		CPPUNIT_ASSERT(l._cells[1][1]._alive);
	}

	void test_Life_simulate_2(){
		Life<FredkinCell> l(2,2,FredkinCell(false));
		l.add_cell(0,1,FredkinCell(true), '0');
		stringstream ss;
		l.simulate(1,ss,1);
		CPPUNIT_ASSERT(l._cells[0][0]._alive);
		CPPUNIT_ASSERT(!l._cells[1][0]._alive);
		CPPUNIT_ASSERT(!l._cells[0][1]._alive);
		CPPUNIT_ASSERT(l._cells[1][1]._alive);
	}

	void test_Life_simulate_3(){
		Life<Cell> l(2,2,new FredkinCell(false));
		l.add_cell(0,0,new ConwayCell(true), '*');
		l.add_cell(0,1,new FredkinCell(true), '1');
		l._cells[0][1].Handle<AbstractCell>::get()->_age = 1;
		stringstream ss;
		l.simulate(1,ss,1);
		CPPUNIT_ASSERT(!l._cells[0][0].Handle<AbstractCell>::get()->_alive);
		CPPUNIT_ASSERT(l._cells[0][1].Handle<AbstractCell>::get()->_alive);
		CPPUNIT_ASSERT(l._cells[1][0].Handle<AbstractCell>::get()->_alive);
		CPPUNIT_ASSERT(l._cells[1][1].Handle<AbstractCell>::get()->_alive);
		CPPUNIT_ASSERT(dynamic_cast<ConwayCell *>(l._cells[0][1].Handle<AbstractCell>::get()));
		CPPUNIT_ASSERT(dynamic_cast<ConwayCell *>(l._cells[0][0].Handle<AbstractCell>::get()));
		CPPUNIT_ASSERT(dynamic_cast<FredkinCell *>(l._cells[1][0].Handle<AbstractCell>::get()));
		CPPUNIT_ASSERT(dynamic_cast<FredkinCell *>(l._cells[1][1].Handle<AbstractCell>::get()));
	}

    // -----
    // suite
    // -----
    CPPUNIT_TEST_SUITE(TestLife);
	CPPUNIT_TEST(test_constructor_1);
	CPPUNIT_TEST(test_constructor_2);
	CPPUNIT_TEST(test_constructor_3);
	CPPUNIT_TEST(test_constructor_4);
	CPPUNIT_TEST(test_Cell_constructor_1);
	CPPUNIT_TEST(test_Cell_constructor_2);
	CPPUNIT_TEST(test_Cell_constructor_3);
	CPPUNIT_TEST(test_Cell_constructor_4);
	CPPUNIT_TEST(test_Cell_mutate_1);
	CPPUNIT_TEST(test_Cell_mutate_2);
	CPPUNIT_TEST(test_Cell_mutate_3);
	CPPUNIT_TEST(test_Cell_mutateRequested_1);
	CPPUNIT_TEST(test_Cell_mutateRequested_2);
	CPPUNIT_TEST(test_Cell_mutateRequested_3);
	CPPUNIT_TEST(test_Cell_clone_1);
	CPPUNIT_TEST(test_Cell_clone_2);
	CPPUNIT_TEST(test_Cell_clone_3);
	CPPUNIT_TEST(test_Cell_liveNeighbors_1);
	CPPUNIT_TEST(test_Cell_liveNeighbors_2);
	CPPUNIT_TEST(test_Cell_liveNeighbors_3);
	CPPUNIT_TEST(test_Cell_toggle_alive_1);
	CPPUNIT_TEST(test_Cell_toggle_alive_2);
	CPPUNIT_TEST(test_Cell_toggle_alive_3);
	CPPUNIT_TEST(test_Cell_increment_age_1);
	CPPUNIT_TEST(test_Cell_increment_age_2);
	CPPUNIT_TEST(test_Cell_increment_age_3);
	CPPUNIT_TEST(test_Cell_get_age_1);
	CPPUNIT_TEST(test_Cell_get_age_2);
	CPPUNIT_TEST(test_Cell_get_age_3);
	CPPUNIT_TEST(test_Life_constructor_1);
	CPPUNIT_TEST(test_Life_constructor_2);
	CPPUNIT_TEST(test_Life_constructor_3);
	CPPUNIT_TEST(test_Life_add_cell_1);
	CPPUNIT_TEST(test_Life_add_cell_2);
	CPPUNIT_TEST(test_Life_add_cell_3);
	CPPUNIT_TEST(test_Life_print1);
	CPPUNIT_TEST(test_Life_print2);
	CPPUNIT_TEST(test_Life_print3);
	CPPUNIT_TEST(test_Life_isAlive1);
	CPPUNIT_TEST(test_Life_isAlive2);
	CPPUNIT_TEST(test_Life_isAlive3);
	CPPUNIT_TEST(test_Life_getNeighbors1);
	CPPUNIT_TEST(test_Life_getNeighbors2);
	CPPUNIT_TEST(test_Life_getNeighbors3);
	CPPUNIT_TEST(test_Life_simulate_1);
	CPPUNIT_TEST(test_Life_simulate_2);
	CPPUNIT_TEST(test_Life_simulate_3);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestLife.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestLife<FredkinCell>::suite());
    tr.addTest(TestLife<ConwayCell>::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
