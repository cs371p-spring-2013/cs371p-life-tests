/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -pedantic -std=c++0x -Wall Life.c++ TestLife.c++ -o TestLife.c++.app -lcppunit -ldl
    % valgrind TestLife.c++.app >& TestVoti.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include <algorithm> // swap

#include <fstream> //reading files

#include <vector> // vector

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#define private public
#define protected public
#define class struct

#include "AbstractCell.h" //no tests for this

#include "Cell.h"
#include "ConwayCell.c++"
#include "FredkinCell.c++"
#include "Life.h"



// ----------
// TestLife
// ----------

struct TestLife : CppUnit::TestFixture {


// ----------------
// ConwayCell Tests
// ----------------

//5 Conway Constructor Tests
void test_ConwayDefault(){
	ConwayCell c = ConwayCell();
	CPPUNIT_ASSERT(!c.is_alive);
	CPPUNIT_ASSERT(c.type == '.');
	CPPUNIT_ASSERT(c.neighbors.size() == 8);
}

void test_ConwayBool_true(){
	ConwayCell c = ConwayCell(true);
	CPPUNIT_ASSERT(c.is_alive);
	CPPUNIT_ASSERT(c.type == '*');
	CPPUNIT_ASSERT(c.neighbors.size() == 8);
}

void test_ConwayBool_false(){
	ConwayCell c = ConwayCell(false);
	CPPUNIT_ASSERT(!c.is_alive);
	CPPUNIT_ASSERT(c.type == '.');
	CPPUNIT_ASSERT(c.neighbors.size() == 8);
}

void test_ConwayChar_alive(){
	ConwayCell c = ConwayCell('*');
	CPPUNIT_ASSERT(c.is_alive);
	CPPUNIT_ASSERT(c.type == '*');
	CPPUNIT_ASSERT(c.neighbors.size() == 8);
}

void test_ConwayChar_dead(){
	ConwayCell c = ConwayCell('.');
	CPPUNIT_ASSERT(!c.is_alive);
	CPPUNIT_ASSERT(c.type == '.');
	CPPUNIT_ASSERT(c.neighbors.size() == 8);
}

void test_ConwayLive_Or_Die_1(){
	ConwayCell c = ConwayCell('.');
	CPPUNIT_ASSERT(c.type == '.');
	CPPUNIT_ASSERT(!c.is_alive);
	c.live_or_die(3);
	CPPUNIT_ASSERT(c.is_alive);
	CPPUNIT_ASSERT(c.type == '*');
}

void test_ConwayLive_Or_Die_2(){
	ConwayCell c = ConwayCell('*');
	CPPUNIT_ASSERT(c.type == '*');
	CPPUNIT_ASSERT(c.is_alive);
	c.live_or_die(4);
	CPPUNIT_ASSERT(!c.is_alive);
	CPPUNIT_ASSERT(c.type == '.');
}

void test_ConwayLive_Or_Die_3(){
	ConwayCell c = ConwayCell('.');
	CPPUNIT_ASSERT(c.type == '.');
	CPPUNIT_ASSERT(!c.is_alive);
	c.live_or_die(5);
	CPPUNIT_ASSERT(!c.is_alive);
	CPPUNIT_ASSERT(c.type == '.');
}

//other Conway methods
void test_Conway_num_neighbors_to_check_1(){
	ConwayCell c = ConwayCell('.');
	ConwayCell d = ConwayCell('*');
	int n = c.num_neighbors_to_check();
	int m = d.num_neighbors_to_check();
	CPPUNIT_ASSERT(n == 8);
	CPPUNIT_ASSERT(m == 8);
}

void test_Conway_num_neighbors_to_check_2(){
	ConwayCell c = ConwayCell(true);
	ConwayCell d = ConwayCell(false);
	int n = c.num_neighbors_to_check();
	int m = d.num_neighbors_to_check();
	CPPUNIT_ASSERT(n == 8);
	CPPUNIT_ASSERT(m == 8);
}

void test_Conway_num_neighbors_to_check_3(){
	ConwayCell c = ConwayCell();
	int n = c.num_neighbors_to_check();
	CPPUNIT_ASSERT(n == 8);
}

void test_Conway_printType_1(){
	ConwayCell c = ConwayCell('.');
	ConwayCell d = ConwayCell('*');
	char x = c.printType();
	char y = d.printType();
	CPPUNIT_ASSERT(x == '.');
	CPPUNIT_ASSERT(y == '*');
}

void test_Conway_printType_2(){
	ConwayCell c = ConwayCell(false);
	ConwayCell d = ConwayCell(true);
	char x = c.printType();
	char y = d.printType();
	CPPUNIT_ASSERT(x == '.');
	CPPUNIT_ASSERT(y == '*');
}

void test_Conway_printType_3(){
	ConwayCell c = ConwayCell();
	char x = c.printType();
	CPPUNIT_ASSERT(x == '.');
}

void test_Conway_isAlive_1(){
	ConwayCell c = ConwayCell('.');
	ConwayCell d = ConwayCell('*');
	bool x = c.isAlive();
	bool y = d.isAlive();
	CPPUNIT_ASSERT(!x);
	CPPUNIT_ASSERT(y);
}

void test_Conway_isAlive_2(){
	ConwayCell c = ConwayCell(false);
	ConwayCell d = ConwayCell(true);
	bool x = c.isAlive();
	bool y = d.isAlive();
	CPPUNIT_ASSERT(!x);
	CPPUNIT_ASSERT(y);
}

void test_Conway_isAlive_3(){
	ConwayCell c = ConwayCell();
	bool x = c.isAlive();
	CPPUNIT_ASSERT(!x);
}

void test_Conway_get_neighbors_locations_1(){
	ConwayCell c = ConwayCell('.');
	ConwayCell d = ConwayCell('*');

	vector<vector<int> > x = c.get_neighbors_locations();
	vector<vector<int> > y = d.get_neighbors_locations();

	CPPUNIT_ASSERT(x.size() == 8);
	CPPUNIT_ASSERT(y.size() == 8);
}

void test_Conway_get_neighbors_locations_2(){
	ConwayCell c = ConwayCell(false);
	ConwayCell d = ConwayCell(true);

	vector<vector<int> > x = c.get_neighbors_locations();
	vector<vector<int> > y = d.get_neighbors_locations();

	CPPUNIT_ASSERT(x.size() == 8);
	CPPUNIT_ASSERT(y.size() == 8);
}

void test_Conway_get_neighbors_locations_3(){
	ConwayCell c = ConwayCell();
	vector<vector<int> > x = c.get_neighbors_locations();
	CPPUNIT_ASSERT(x.size() == 8);
}

void test_Conway_clone_1(){
	ConwayCell c = ConwayCell();
	ConwayCell* x = c.clone();
	CPPUNIT_ASSERT(!(x->is_alive));
	CPPUNIT_ASSERT(x->type == '.');
	CPPUNIT_ASSERT(x->neighbors.size() == 8);
	delete x;
}

void test_Conway_clone_2(){
	ConwayCell c = ConwayCell(false);
	ConwayCell d = ConwayCell(true);

	ConwayCell* x = c.clone();
	ConwayCell* y = d.clone();

	CPPUNIT_ASSERT(!(x->is_alive));
	CPPUNIT_ASSERT(x->type == '.');
	CPPUNIT_ASSERT(x->neighbors.size() == 8);

	CPPUNIT_ASSERT(y->is_alive);
	CPPUNIT_ASSERT(y->type == '*');
	CPPUNIT_ASSERT(y->neighbors.size() == 8);
	delete x;
	delete y;
}

void test_Conway_clone_3(){
	ConwayCell c = ConwayCell('.');
	ConwayCell d = ConwayCell('*');

	ConwayCell* x = c.clone();
	ConwayCell* y = d.clone();

	CPPUNIT_ASSERT(!(x->is_alive));
	CPPUNIT_ASSERT(x->type == '.');
	CPPUNIT_ASSERT(x->neighbors.size() == 8);

	CPPUNIT_ASSERT(y->is_alive);
	CPPUNIT_ASSERT(y->type == '*');
	CPPUNIT_ASSERT(y->neighbors.size() == 8);
	delete x;
	delete y;
}

// -----------------
// FredkinCell Tests
// -----------------
void test_FredkinDefault(){
	FredkinCell c = FredkinCell();
	CPPUNIT_ASSERT(!c.is_alive);
	CPPUNIT_ASSERT(c.type == '-');
	CPPUNIT_ASSERT(c.neighbors.size() == 4);
	CPPUNIT_ASSERT(c.age == 0);
}

void test_FredkinChar_alive(){
	FredkinCell c = FredkinCell('1');
	CPPUNIT_ASSERT(c.is_alive);
	CPPUNIT_ASSERT(c.type == '1');
	CPPUNIT_ASSERT(c.neighbors.size() == 4);
	CPPUNIT_ASSERT(c.age == 1);
}

void test_FredkinChar_dead(){
	FredkinCell c = FredkinCell('-');
	CPPUNIT_ASSERT(!c.is_alive);
	CPPUNIT_ASSERT(c.type == '-');
	CPPUNIT_ASSERT(c.neighbors.size() == 4);
	CPPUNIT_ASSERT(c.age == 0);
}

void test_FredkinLive_Or_Die_1(){
	FredkinCell c = FredkinCell('-');
	CPPUNIT_ASSERT(c.type == '-');
	CPPUNIT_ASSERT(!c.is_alive);
	c.live_or_die(3);
	CPPUNIT_ASSERT(c.is_alive);
	CPPUNIT_ASSERT(c.type == '0');
}

void test_FredkinLive_Or_Die_2(){
	FredkinCell c = FredkinCell('0');
	CPPUNIT_ASSERT(c.type == '0');
	CPPUNIT_ASSERT(c.is_alive);
	c.live_or_die(4);
	CPPUNIT_ASSERT(!c.is_alive);
	CPPUNIT_ASSERT(c.type == '-');
}

void test_FredkinLive_Or_Die_3(){
	FredkinCell c = FredkinCell('-');
	CPPUNIT_ASSERT(c.type == '-');
	CPPUNIT_ASSERT(!c.is_alive);
	c.live_or_die(5);
	CPPUNIT_ASSERT(!c.is_alive);
	CPPUNIT_ASSERT(c.type == '-');
}

//other Fredkin methods
void test_Fredkin_num_neighbors_to_check_1(){
	FredkinCell c = FredkinCell('-');
	int n = c.num_neighbors_to_check();
	CPPUNIT_ASSERT(n == 4);
}

void test_Fredkin_num_neighbors_to_check_2(){
	FredkinCell d = FredkinCell('0');
	int m = d.num_neighbors_to_check();
	CPPUNIT_ASSERT(m == 4);
}

void test_Fredkin_num_neighbors_to_check_3(){
	FredkinCell c = FredkinCell();
	int n = c.num_neighbors_to_check();
	CPPUNIT_ASSERT(n == 4);
}

void test_Fredkin_printType_1(){
	FredkinCell c = FredkinCell('-');
	FredkinCell d = FredkinCell('0');
	char x = c.printType();
	char y = d.printType();
	CPPUNIT_ASSERT(x == '-');
	CPPUNIT_ASSERT(y == '0');
}

void test_Fredkin_printType_2(){
	FredkinCell c = FredkinCell('3');
	FredkinCell d = FredkinCell('+');
	char x = c.printType();
	char y = d.printType();
	CPPUNIT_ASSERT(x == '3');
	CPPUNIT_ASSERT(y == '+');
}

void test_Fredkin_printType_3(){
	FredkinCell c = FredkinCell();
	char x = c.printType();
	CPPUNIT_ASSERT(x == '-');
}

void test_Fredkin_isAlive_1(){
	FredkinCell c = FredkinCell('-');
	bool x = c.isAlive();
	CPPUNIT_ASSERT(!x);
}

void test_Fredkin_isAlive_2(){
	FredkinCell c = FredkinCell('+');
	bool x = c.isAlive();
	CPPUNIT_ASSERT(x);
}

void test_Fredkin_isAlive_3(){
	FredkinCell c = FredkinCell();
	bool x = c.isAlive();
	CPPUNIT_ASSERT(!x);
}

void test_Fredkin_get_neighbors_locations_1(){
	FredkinCell c = FredkinCell('0');
	vector<vector<int> > x = c.get_neighbors_locations();
	CPPUNIT_ASSERT(x.size() == 4);
}

void test_Fredkin_get_neighbors_locations_2(){
	FredkinCell c = FredkinCell('-');
	vector<vector<int> > x = c.get_neighbors_locations();
	CPPUNIT_ASSERT(x.size() == 4);
}

void test_Fredkin_get_neighbors_locations_3(){
	FredkinCell c = FredkinCell();
	vector<vector<int> > x = c.get_neighbors_locations();
	CPPUNIT_ASSERT(x.size() == 4);
}

void test_Fredkin_clone_1(){
	FredkinCell c = FredkinCell();
	FredkinCell* x = c.clone();
	CPPUNIT_ASSERT(!(x->is_alive));
	CPPUNIT_ASSERT(x->type == '-');
	CPPUNIT_ASSERT(x->neighbors.size() == 4);
	delete x;
}

void test_Fredkin_clone_2(){
	FredkinCell c = FredkinCell('0');
	FredkinCell* x = c.clone();

	CPPUNIT_ASSERT(x->is_alive);
	CPPUNIT_ASSERT(x->type == '0');
	CPPUNIT_ASSERT(x->neighbors.size() == 4);
	delete x;
}

void test_Fredkin_clone_3(){
	FredkinCell c = FredkinCell('+');
	FredkinCell* x = c.clone();

	CPPUNIT_ASSERT(x->is_alive);
	CPPUNIT_ASSERT(x->type == '+');
	CPPUNIT_ASSERT(x->neighbors.size() == 4);
	delete x;
}

void test_Fredkin_getAge_1(){
	FredkinCell c = FredkinCell();
	CPPUNIT_ASSERT(c.get_age() == 0);
}

void test_Fredkin_getAge_2(){
	FredkinCell c = FredkinCell('+');
	CPPUNIT_ASSERT(c.get_age() >= 10);
}

void test_Fredkin_getAge_3(){
	FredkinCell c = FredkinCell('4');
	CPPUNIT_ASSERT(c.get_age() == 4);
}

// ----------
// Cell tests
// ----------
//5 Cell Constructor Tests
void test_CellDefault(){
	Cell c = Cell();
	CPPUNIT_ASSERT(c.get() == NULL);
}

void test_CellChar_alive(){
	Cell c = Cell('*');
	CPPUNIT_ASSERT(c.get()->is_alive);
	CPPUNIT_ASSERT(c.get()->type == '*');
	CPPUNIT_ASSERT(c.get()->neighbors.size() == 8);
}

void test_CellChar_dead(){
	Cell c = Cell('.');
	CPPUNIT_ASSERT(c.get()->is_alive == false);
	CPPUNIT_ASSERT(c.get()->type == '.');
	CPPUNIT_ASSERT(c.get()->neighbors.size() == 8);
}

void test_Cell_AbstractCell(){
	// ConwayCell x = ConwayCell('.');
	// ConwayCell* p = &x;
	// Cell c = Cell('.');
	// CPPUNIT_ASSERT(c.get()->is_alive == false);
	// CPPUNIT_ASSERT(c.get()->type == '.');
	// CPPUNIT_ASSERT(c.get()->neighbors.size() == 8);
}

void test_Cell_Copy(){
	// ConwayCell x = ConwayCell('.');
	// Cell c = Cell(&x);
	// CPPUNIT_ASSERT(c.get()->is_alive == false);
	// CPPUNIT_ASSERT(c.get()->type == '.');
	// CPPUNIT_ASSERT(c.get()->neighbors.size() == 8);
}



void test_CellLive_Or_Die_1(){
	Cell c = Cell('.');
	CPPUNIT_ASSERT(c.get()->type == '.');
	CPPUNIT_ASSERT(c.get()->is_alive == false);
	c.live_or_die(3);
	CPPUNIT_ASSERT(c.get()->is_alive);
	CPPUNIT_ASSERT(c.get()->type == '*');
}

void test_CellLive_Or_Die_2(){
	Cell c = Cell('*');
	CPPUNIT_ASSERT(c.get()->type == '*');
	CPPUNIT_ASSERT(c.get()->is_alive);
	c.live_or_die(4);
	CPPUNIT_ASSERT(c.get()->is_alive == false);
	CPPUNIT_ASSERT(c.get()->type == '.');
}

void test_CellLive_Or_Die_3(){
	Cell c = Cell('.');
	CPPUNIT_ASSERT(c.get()->type == '.');
	CPPUNIT_ASSERT(c.get()->is_alive == false);
	c.live_or_die(465);
	CPPUNIT_ASSERT(c.get()->is_alive == false);
	CPPUNIT_ASSERT(c.get()->type == '.');

}

//other Cell methods
void test_Cell_num_neighbors_to_check_1(){
	Cell c = Cell('.');
	Cell d = Cell('*');
	int n = c.get()->num_neighbors_to_check();
	int m = d.get()->num_neighbors_to_check();
	CPPUNIT_ASSERT(n == 8);
	CPPUNIT_ASSERT(m == 8);
}

void test_Cell_num_neighbors_to_check_2(){

	Cell c = Cell('-');
	Cell d = Cell('3');
	int n = c.get()->num_neighbors_to_check();
	int m = d.get()->num_neighbors_to_check();
	CPPUNIT_ASSERT(n == 4);
	CPPUNIT_ASSERT(m == 4);
}

void test_Cell_num_neighbors_to_check_3(){
	Cell c = Cell('.');
	int n = c.get()->num_neighbors_to_check();
	CPPUNIT_ASSERT(n == 8);
}

void test_Cell_printType_1(){
	Cell c = Cell('.');
	Cell d = Cell('*');
	char x = c.printType();
	char y = d.printType();
	CPPUNIT_ASSERT(x == '.');
	CPPUNIT_ASSERT(y == '*');
}

void test_Cell_printType_2(){
	Cell c = Cell('-');
	Cell d = Cell('1');
	char x = c.printType();
	char y = d.printType();
	CPPUNIT_ASSERT(x == '-');
	CPPUNIT_ASSERT(y == '1');
}

void test_Cell_printType_3(){
	Cell c = Cell('+');
	char x = c.printType();
	CPPUNIT_ASSERT(x == '+');
}

void test_Cell_isAlive_1(){
	Cell c = Cell('.');
	Cell d = Cell('*');
	bool x = c.isAlive();
	bool y = d.isAlive();
	CPPUNIT_ASSERT(!x);
	CPPUNIT_ASSERT(y);
}

void test_Cell_isAlive_2(){
	Cell c = Cell('-');
	Cell d = Cell('3');
	bool x = c.isAlive();
	bool y = d.isAlive();
	CPPUNIT_ASSERT(!x);
	CPPUNIT_ASSERT(y);
}

void test_Cell_isAlive_3(){
	Cell c = Cell('+');
	bool x = c.isAlive();
	CPPUNIT_ASSERT(x);
}

void test_Cell_get_neighbors_locations_1(){
	Cell c = Cell('.');
	Cell d = Cell('*');

	vector<vector<int> > x = c.get()->get_neighbors_locations();
	vector<vector<int> > y = d.get()->get_neighbors_locations();

	CPPUNIT_ASSERT(x.size() == 8);
	CPPUNIT_ASSERT(y.size() == 8);
}

void test_Cell_get_neighbors_locations_2(){
	Cell c = Cell('-');
	Cell d = Cell('3');

	vector<vector<int> > x = c.get()->get_neighbors_locations();
	vector<vector<int> > y = d.get()->get_neighbors_locations();

	CPPUNIT_ASSERT(x.size() == 4);
	CPPUNIT_ASSERT(y.size() == 4);
}

void test_Cell_get_neighbors_locations_3(){
	Cell c = Cell('+');
	vector<vector<int> > x = c.get_neighbors_locations();
	CPPUNIT_ASSERT(x.size() == 4);
}

//----------
//Life
//----------

void test_Life(){
	ifstream read("TestLife.in");
	Life<ConwayCell> l = Life<ConwayCell>(read);
	CPPUNIT_ASSERT(l.generation == 0);
	CPPUNIT_ASSERT(l.population == 0);
	CPPUNIT_ASSERT(l.rows == 1);
	CPPUNIT_ASSERT(l.columns == 1);
	CPPUNIT_ASSERT(l.current.size() == 1);
	CPPUNIT_ASSERT(l.neighbors_count.size() == 1);
}

void test_Life_Populate1(){
	ifstream read("TestLife.in");
	Life<ConwayCell> l = Life<ConwayCell>(read);
	CPPUNIT_ASSERT(l.generation == 0);
	CPPUNIT_ASSERT(l.population == 0);
	CPPUNIT_ASSERT(l.rows == 1);
	CPPUNIT_ASSERT(l.columns == 1);
	char x = l.current[0][0].printType();
	CPPUNIT_ASSERT(x == '.');
	ifstream read2("TestLifePopulate.in");
	l.populate(read2);
	x = l.current[0][0].printType();
	CPPUNIT_ASSERT(x == '*');
}

void test_Life_Populate2(){
	ifstream read("TestLife.in");
	Life<ConwayCell> l = Life<ConwayCell>(read);
	CPPUNIT_ASSERT(l.generation == 0);
	CPPUNIT_ASSERT(l.population == 0);
	CPPUNIT_ASSERT(l.rows == 1);
	CPPUNIT_ASSERT(l.columns == 1);
	char x = l.current[0][0].printType();
	CPPUNIT_ASSERT(x == '.');
	ifstream read2("TestLifePopulate.in");
	l.populate(read2);
	x = l.current[0][0].printType();
	CPPUNIT_ASSERT(x == '*');
}

void test_Life_Populate3(){
	ifstream read("TestLife.in");
	Life<ConwayCell> l = Life<ConwayCell>(read);
	CPPUNIT_ASSERT(l.generation == 0);
	CPPUNIT_ASSERT(l.population == 0);
	CPPUNIT_ASSERT(l.rows == 1);
	CPPUNIT_ASSERT(l.columns == 1);
	char x = l.current[0][0].printType();
	CPPUNIT_ASSERT(x == '.');
	ifstream read2("TestLifePopulate.in");
	l.populate(read2);
	x = l.current[0][0].printType();
	CPPUNIT_ASSERT(x == '*');
}

void test_Life_countPopulation1(){
	ifstream read("TestLife.in");
	Life<ConwayCell> l = Life<ConwayCell>(read);
	l.countPopulation(false);
	CPPUNIT_ASSERT(l.population == 0);	
}

void test_Life_countPopulation2(){
	ifstream read("TestLife.in");
	Life<ConwayCell> l = Life<ConwayCell>(read);
	l.countPopulation(false);
	CPPUNIT_ASSERT(l.population == 0);	
}

void test_Life_countPopulation3(){
	ifstream read("TestLife.in");
	Life<ConwayCell> l = Life<ConwayCell>(read);
	l.countPopulation(true);
	CPPUNIT_ASSERT(l.population == 1);	
}
//we test the print function in life by, well, printing and seeing it
void test_Life_countNeighbors1(){
	ifstream read("TestLife.in");
	Life<ConwayCell> l = Life<ConwayCell>(read);
	int n = l.neighbors_alive(l.current[0][0],0,0);
	CPPUNIT_ASSERT(n == 0);
}
void test_Life_countNeighbors2(){
	ifstream read("TestLife.in");
	Life<Cell> l = Life<Cell>(read);
	int n = l.neighbors_alive(l.current[0][0],0,0);
	CPPUNIT_ASSERT(n == 0);
}
void test_Life_countNeighbors3(){
	ifstream read("TestLife.in");
	Life<FredkinCell> l = Life<FredkinCell>(read);
	int n = l.neighbors_alive(l.current[0][0],0,0);
	CPPUNIT_ASSERT(n == 0);
}

void test_Life_Execute1(){
	ifstream read("TestLife.in");
	Life<ConwayCell> l = Life<ConwayCell>(read);
	CPPUNIT_ASSERT(l.generation == 0);
	CPPUNIT_ASSERT(l.population == 0);
	CPPUNIT_ASSERT(l.rows == 1);
	CPPUNIT_ASSERT(l.columns == 1);
	char x = l.current[0][0].printType();
	CPPUNIT_ASSERT(x == '.');
	l.execute(1);
	CPPUNIT_ASSERT(l.generation == 1);
	CPPUNIT_ASSERT(l.population == 0);
	x = l.current[0][0].printType();
	CPPUNIT_ASSERT(x == '.');
}

void test_Life_Execute2(){
	ifstream read("TestLife.in");
	Life<ConwayCell> l = Life<ConwayCell>(read);
	CPPUNIT_ASSERT(l.generation == 0);
	CPPUNIT_ASSERT(l.population == 0);
	CPPUNIT_ASSERT(l.rows == 1);
	CPPUNIT_ASSERT(l.columns == 1);
	char x = l.current[0][0].printType();
	CPPUNIT_ASSERT(x == '.');
	l.execute(2);
	CPPUNIT_ASSERT(l.generation == 2);
	CPPUNIT_ASSERT(l.population == 0);
	x = l.current[0][0].printType();
	CPPUNIT_ASSERT(x == '.');
}

void test_Life_Execute3(){
	ifstream read("TestLife.in");
	Life<ConwayCell> l = Life<ConwayCell>(read);
	CPPUNIT_ASSERT(l.generation == 0);
	CPPUNIT_ASSERT(l.population == 0);
	CPPUNIT_ASSERT(l.rows == 1);
	CPPUNIT_ASSERT(l.columns == 1);
	char x = l.current[0][0].printType();
	CPPUNIT_ASSERT(x == '.');
	l.execute(3);
	CPPUNIT_ASSERT(l.generation == 3);
	CPPUNIT_ASSERT(l.population == 0);
	x = l.current[0][0].printType();
	CPPUNIT_ASSERT(x == '.');
}








    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);

    //ConwayCell tests
    CPPUNIT_TEST(test_ConwayDefault);
    CPPUNIT_TEST(test_ConwayBool_true);
    CPPUNIT_TEST(test_ConwayBool_false);    
    CPPUNIT_TEST(test_ConwayChar_alive);
    CPPUNIT_TEST(test_ConwayChar_dead);
    CPPUNIT_TEST(test_ConwayLive_Or_Die_1);
    CPPUNIT_TEST(test_ConwayLive_Or_Die_2);
    CPPUNIT_TEST(test_ConwayLive_Or_Die_3);
    CPPUNIT_TEST(test_Conway_num_neighbors_to_check_1);
    CPPUNIT_TEST(test_Conway_num_neighbors_to_check_2);
    CPPUNIT_TEST(test_Conway_num_neighbors_to_check_3);
    CPPUNIT_TEST(test_Conway_printType_1);
    CPPUNIT_TEST(test_Conway_printType_2);
    CPPUNIT_TEST(test_Conway_printType_3);
    CPPUNIT_TEST(test_Conway_isAlive_1);
    CPPUNIT_TEST(test_Conway_isAlive_2);
    CPPUNIT_TEST(test_Conway_isAlive_3);
    CPPUNIT_TEST(test_Conway_get_neighbors_locations_1);
    CPPUNIT_TEST(test_Conway_get_neighbors_locations_2);
    CPPUNIT_TEST(test_Conway_get_neighbors_locations_3);
    CPPUNIT_TEST(test_Conway_clone_1);
    CPPUNIT_TEST(test_Conway_clone_2);
    CPPUNIT_TEST(test_Conway_clone_3);

    //FredkinCell tests
    CPPUNIT_TEST(test_FredkinDefault);
    CPPUNIT_TEST(test_FredkinChar_alive);
    CPPUNIT_TEST(test_FredkinChar_dead);
    CPPUNIT_TEST(test_FredkinLive_Or_Die_1);
    CPPUNIT_TEST(test_FredkinLive_Or_Die_2);
    CPPUNIT_TEST(test_FredkinLive_Or_Die_3);
    CPPUNIT_TEST(test_Fredkin_num_neighbors_to_check_1);
    CPPUNIT_TEST(test_Fredkin_num_neighbors_to_check_2);
    CPPUNIT_TEST(test_Fredkin_num_neighbors_to_check_3);
    CPPUNIT_TEST(test_Fredkin_printType_1);
    CPPUNIT_TEST(test_Fredkin_printType_2);
    CPPUNIT_TEST(test_Fredkin_printType_3);
    CPPUNIT_TEST(test_Fredkin_isAlive_1);
    CPPUNIT_TEST(test_Fredkin_isAlive_2);
    CPPUNIT_TEST(test_Fredkin_isAlive_3);
    CPPUNIT_TEST(test_Fredkin_get_neighbors_locations_1);
    CPPUNIT_TEST(test_Fredkin_get_neighbors_locations_2);
    CPPUNIT_TEST(test_Fredkin_get_neighbors_locations_3);
    CPPUNIT_TEST(test_Fredkin_clone_1);
    CPPUNIT_TEST(test_Fredkin_clone_2);
    CPPUNIT_TEST(test_Fredkin_clone_3);
    CPPUNIT_TEST(test_Fredkin_getAge_1);
    CPPUNIT_TEST(test_Fredkin_getAge_2);
    CPPUNIT_TEST(test_Fredkin_getAge_3);

    //Cell tests
    CPPUNIT_TEST(test_CellDefault);
	CPPUNIT_TEST(test_CellChar_alive);
    CPPUNIT_TEST(test_CellChar_dead);
    CPPUNIT_TEST(test_Cell_AbstractCell);
    CPPUNIT_TEST(test_Cell_Copy);
    CPPUNIT_TEST(test_CellLive_Or_Die_1);
    CPPUNIT_TEST(test_CellLive_Or_Die_2);
    CPPUNIT_TEST(test_CellLive_Or_Die_3);
    CPPUNIT_TEST(test_Cell_num_neighbors_to_check_1);
    CPPUNIT_TEST(test_Cell_num_neighbors_to_check_2);
    CPPUNIT_TEST(test_Cell_num_neighbors_to_check_3);
    CPPUNIT_TEST(test_Cell_printType_1);
    CPPUNIT_TEST(test_Cell_printType_2);
    CPPUNIT_TEST(test_Cell_printType_3);
    CPPUNIT_TEST(test_Cell_isAlive_1);
    CPPUNIT_TEST(test_Cell_isAlive_2);
    CPPUNIT_TEST(test_Cell_isAlive_3);
    CPPUNIT_TEST(test_Cell_get_neighbors_locations_1);
    CPPUNIT_TEST(test_Cell_get_neighbors_locations_2);
    CPPUNIT_TEST(test_Cell_get_neighbors_locations_3);

    //Life tests
    CPPUNIT_TEST(test_Life);
    CPPUNIT_TEST(test_Life_Populate1);
    CPPUNIT_TEST(test_Life_Populate2);
    CPPUNIT_TEST(test_Life_Populate3);
    CPPUNIT_TEST(test_Life_countPopulation1);
    CPPUNIT_TEST(test_Life_countPopulation2);
    CPPUNIT_TEST(test_Life_countPopulation3);
    CPPUNIT_TEST(test_Life_countNeighbors1);
    CPPUNIT_TEST(test_Life_countNeighbors2);
    CPPUNIT_TEST(test_Life_countNeighbors3);
    CPPUNIT_TEST(test_Life_Execute1);
    CPPUNIT_TEST(test_Life_Execute2);
    CPPUNIT_TEST(test_Life_Execute3);

    CPPUNIT_TEST_SUITE_END();
};

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
    return 0;
}
