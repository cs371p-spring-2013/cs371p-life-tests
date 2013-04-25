#include <iostream>
#include <sstream>
#include <string>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#define protected public
#define private public
#define class struct

#include "Life.h"



struct TestLife : CppUnit::TestFixture {
    
	void test_constructor_conway() {
	Life<ConwayCell> a(10, 10, ConwayCell(false));
	CPPUNIT_ASSERT(a._rows == 10);
	CPPUNIT_ASSERT(a._cols == 10);
	CPPUNIT_ASSERT(a._generation == 0);
	CPPUNIT_ASSERT(a._population == 0);
	CPPUNIT_ASSERT(a._cells.size() == 10);
	CPPUNIT_ASSERT(a._cells[0].size() == 10);
	CPPUNIT_ASSERT(a._cells[0][0]._state == false); }

	void test_constructor_fredkin() {
	Life<FredkinCell> a(10, 10, FredkinCell(false));
	CPPUNIT_ASSERT(a._rows == 10);
	CPPUNIT_ASSERT(a._cols == 10);
	CPPUNIT_ASSERT(a._generation == 0);
	CPPUNIT_ASSERT(a._population == 0);
	CPPUNIT_ASSERT(a._cells.size() == 10);
	CPPUNIT_ASSERT(a._cells[0].size() == 10);
	CPPUNIT_ASSERT(a._cells[0][0]._state == false); }

	void test_constructor_cell() {
	Life<Cell> a(10, 10, new FredkinCell(false));
	CPPUNIT_ASSERT(a._rows == 10);
	CPPUNIT_ASSERT(a._cols == 10);
	CPPUNIT_ASSERT(a._generation == 0);
	CPPUNIT_ASSERT(a._population == 0);
	CPPUNIT_ASSERT(a._cells.size() == 10);
	CPPUNIT_ASSERT(a._cells[0].size() == 10);
	CPPUNIT_ASSERT(!a._cells[0][0].getState()); }

	void test_setState_conway() {
	Life<ConwayCell> a(1, 1, ConwayCell(false));
	a.setState(false, 0, 0);
	CPPUNIT_ASSERT(a._cells[0][0]._state == false);
	CPPUNIT_ASSERT(a._population == 0);
	a.setState(true, 0, 0);
	CPPUNIT_ASSERT(a._cells[0][0]._state == true);
	CPPUNIT_ASSERT(a._population == 1);
	a.setState(true, 0, 0);
	CPPUNIT_ASSERT(a._cells[0][0]._state == true);
	CPPUNIT_ASSERT(a._population == 1);
	a.setState(false, 0, 0);
	CPPUNIT_ASSERT(a._cells[0][0]._state == false);
	CPPUNIT_ASSERT(a._population == 0); }

	void test_setState_fredkin() {
	Life<FredkinCell> a(1, 1, FredkinCell(false));
	a.setState(false, 0, 0);
	CPPUNIT_ASSERT(a._cells[0][0]._state == false);
	CPPUNIT_ASSERT(a._population == 0);
	a.setState(true, 0, 0);
	CPPUNIT_ASSERT(a._cells[0][0]._state == true);
	CPPUNIT_ASSERT(a._population == 1);
	a.setState(true, 0, 0);
	CPPUNIT_ASSERT(a._cells[0][0]._state == true);
	CPPUNIT_ASSERT(a._population == 1);
	a.setState(false, 0, 0);
	CPPUNIT_ASSERT(a._cells[0][0]._state == false);
	CPPUNIT_ASSERT(a._population == 0); }

	void test_setState_cell() {
	Life<Cell> a(1, 1, new FredkinCell(false));
	a.setState(false, 0, 0);
	CPPUNIT_ASSERT(a._cells[0][0].getState() == false);
	CPPUNIT_ASSERT(a._population == 0);
	a.setState(true, 0, 0);
	CPPUNIT_ASSERT(a._cells[0][0].getState() == true);
	CPPUNIT_ASSERT(a._population == 1);
	a.setState(true, 0, 0);
	CPPUNIT_ASSERT(a._cells[0][0].getState() == true);
	CPPUNIT_ASSERT(a._population == 1);
	a.setState(false, 0, 0);
	CPPUNIT_ASSERT(a._cells[0][0].getState() == false);
	CPPUNIT_ASSERT(a._population == 0); }

	void test_setAge_fredkin() {
	Life<FredkinCell> a(1, 1, FredkinCell(true));
	CPPUNIT_ASSERT(a._cells[0][0]._age == 0);
	a.setAge(5,0,0);
	CPPUNIT_ASSERT(a._cells[0][0]._age == 5); }

	void test_next_conway_1() {
	Life<ConwayCell> a(1, 1, ConwayCell(true));
	a.next();
	CPPUNIT_ASSERT(a._population == 0);
	CPPUNIT_ASSERT(a._generation == 1);
	CPPUNIT_ASSERT(a._cells[0][0]._state == false);	}

	void test_next_conway_2() {
	Life<ConwayCell> a(3, 3, ConwayCell(false));
	a.setState(true,0,1);
	a.setState(true,1,1);
	a.setState(true,2,1);
	a.next();
	CPPUNIT_ASSERT(a._population == 3);
	CPPUNIT_ASSERT(a._generation == 1);
	CPPUNIT_ASSERT(a._cells[0][1]._state == false);
	CPPUNIT_ASSERT(a._cells[2][1]._state == false);
	CPPUNIT_ASSERT(a._cells[1][0]._state == true);
	CPPUNIT_ASSERT(a._cells[1][2]._state == true);
	a.next();
	CPPUNIT_ASSERT(a._population == 3);
	CPPUNIT_ASSERT(a._generation == 2);
	CPPUNIT_ASSERT(a._cells[0][1]._state == true);
	CPPUNIT_ASSERT(a._cells[2][1]._state == true);
	CPPUNIT_ASSERT(a._cells[1][0]._state == false);
	CPPUNIT_ASSERT(a._cells[1][2]._state == false);	}

	void test_next_conway_3() {
	Life<ConwayCell> a(3, 3, ConwayCell(true));
	a.next();
	CPPUNIT_ASSERT(a._population == 4);
	CPPUNIT_ASSERT(a._generation == 1);
	CPPUNIT_ASSERT(a._cells[0][0]._state == true);
	CPPUNIT_ASSERT(a._cells[2][2]._state == true);
	CPPUNIT_ASSERT(a._cells[2][0]._state == true);
	CPPUNIT_ASSERT(a._cells[0][2]._state == true);
	a.next();
	CPPUNIT_ASSERT(a._population == 0);
	CPPUNIT_ASSERT(a._generation == 2);	}

	void test_next_fredkin_1() {
	Life<FredkinCell> a(4, 4, FredkinCell(false));
	a.setState(true,1,1);
	a.setState(true,1,2);
	a.setState(true,2,1);
	a.setState(true,2,2);
	a.next();
	CPPUNIT_ASSERT(a._population == 8);
	CPPUNIT_ASSERT(a._generation == 1);
	CPPUNIT_ASSERT(a._cells[0][1]._state == true);
	CPPUNIT_ASSERT(a._cells[0][2]._state == true);
	CPPUNIT_ASSERT(a._cells[1][0]._state == true);
	CPPUNIT_ASSERT(a._cells[2][0]._state == true);
	CPPUNIT_ASSERT(a._cells[1][3]._state == true);
	CPPUNIT_ASSERT(a._cells[2][3]._state == true);
	CPPUNIT_ASSERT(a._cells[3][1]._state == true);
	CPPUNIT_ASSERT(a._cells[3][2]._state == true); }

	void test_next_fredkin_2() {
	Life<FredkinCell> a(4, 3, FredkinCell(false));
	a.setState(true,1,1);
	a.setState(true,2,1);
	a.next();
	CPPUNIT_ASSERT(a._population == 8);
	CPPUNIT_ASSERT(a._generation == 1);
	CPPUNIT_ASSERT(a._cells[1][1]._state == true);
	CPPUNIT_ASSERT(a._cells[2][1]._state == true);
	CPPUNIT_ASSERT(a._cells[0][1]._state == true);
	CPPUNIT_ASSERT(a._cells[3][1]._state == true);
	CPPUNIT_ASSERT(a._cells[1][0]._state == true);
	CPPUNIT_ASSERT(a._cells[2][0]._state == true);
	CPPUNIT_ASSERT(a._cells[1][2]._state == true);
	CPPUNIT_ASSERT(a._cells[2][2]._state == true); }

	void test_next_fredkin_3() {
	Life<FredkinCell> a(1, 1, FredkinCell(true));
	a.next();
	CPPUNIT_ASSERT(a._population == 0);
	CPPUNIT_ASSERT(a._generation == 1); }

	void test_next_cell_1() {
	Life<Cell> a(4, 3, new FredkinCell(false));
	a.setState(true,1,1);
	a.setState(true,2,1);
	a.next();
	a.next();
	CPPUNIT_ASSERT(a._population == 2);
	CPPUNIT_ASSERT(a._generation == 2);
	CPPUNIT_ASSERT(a._cells[0][1].getState());
	CPPUNIT_ASSERT(a._cells[3][1].getState()); }

	void test_next_cell_2() {
	Life<Cell> a(4, 3, new FredkinCell(true));
	a.next();
	a.next();
	CPPUNIT_ASSERT(a._population == 6);
	CPPUNIT_ASSERT(a._generation == 2);
	CPPUNIT_ASSERT(a._cells[1][0].getType() == 'C');
	CPPUNIT_ASSERT(a._cells[2][0].getType() == 'C');
	CPPUNIT_ASSERT(a._cells[1][2].getType() == 'C');
	CPPUNIT_ASSERT(a._cells[2][2].getType() == 'C'); }

	void test_next_cell_3() {
	Life<Cell> a(5, 5, new FredkinCell(true));
	a.next();
	a.next();
	a.next();
	CPPUNIT_ASSERT(a._population == 12);
	CPPUNIT_ASSERT(a._generation == 3);
	CPPUNIT_ASSERT(a._cells[0][2].getType() == 'F');
	CPPUNIT_ASSERT(a._cells[4][2].getType() == 'F');
	CPPUNIT_ASSERT(a._cells[2][0].getType() == 'F');
	CPPUNIT_ASSERT(a._cells[2][4].getType() == 'F');
	CPPUNIT_ASSERT(a._cells[0][1].getType() == 'C');
	CPPUNIT_ASSERT(a._cells[0][3].getType() == 'C');
	CPPUNIT_ASSERT(a._cells[1][0].getType() == 'C');
	CPPUNIT_ASSERT(a._cells[1][4].getType() == 'C');
	CPPUNIT_ASSERT(a._cells[3][0].getType() == 'C');
	CPPUNIT_ASSERT(a._cells[3][4].getType() == 'C');
	CPPUNIT_ASSERT(a._cells[4][1].getType() == 'C');
	CPPUNIT_ASSERT(a._cells[4][3].getType() == 'C'); }

	void test_getNeighbors_conway_1() {
	Life<ConwayCell> a(3, 3, ConwayCell(true));
	CPPUNIT_ASSERT(a._population == 9);
	CPPUNIT_ASSERT(a._generation == 0);
	CPPUNIT_ASSERT(a.getNeighbors(0,0) == 3);
	CPPUNIT_ASSERT(a.getNeighbors(0,1) == 5);
	CPPUNIT_ASSERT(a.getNeighbors(0,2) == 3);
	CPPUNIT_ASSERT(a.getNeighbors(1,0) == 5);
	CPPUNIT_ASSERT(a.getNeighbors(1,1) == 8);
	CPPUNIT_ASSERT(a.getNeighbors(1,2) == 5);
	CPPUNIT_ASSERT(a.getNeighbors(2,0) == 3);
	CPPUNIT_ASSERT(a.getNeighbors(2,1) == 5);
	CPPUNIT_ASSERT(a.getNeighbors(2,2) == 3); }

	void test_getNeighbors_conway_2() {
	Life<ConwayCell> a(3, 3, ConwayCell(false));
	a.setState(true,1,1);
	CPPUNIT_ASSERT(a._population == 1);
	CPPUNIT_ASSERT(a._generation == 0);
	CPPUNIT_ASSERT(a.getNeighbors(0,0) == 1);
	CPPUNIT_ASSERT(a.getNeighbors(0,1) == 1);
	CPPUNIT_ASSERT(a.getNeighbors(0,2) == 1);
	CPPUNIT_ASSERT(a.getNeighbors(1,0) == 1);
	CPPUNIT_ASSERT(a.getNeighbors(1,1) == 0);
	CPPUNIT_ASSERT(a.getNeighbors(1,2) == 1);
	CPPUNIT_ASSERT(a.getNeighbors(2,0) == 1);
	CPPUNIT_ASSERT(a.getNeighbors(2,1) == 1);
	CPPUNIT_ASSERT(a.getNeighbors(2,2) == 1); }

	void test_getNeighbors_fredkin_1() {
	Life<FredkinCell> a(3, 3, FredkinCell(true));
	CPPUNIT_ASSERT(a._population == 9);
	CPPUNIT_ASSERT(a._generation == 0);
	CPPUNIT_ASSERT(a.getNeighbors(0,0) == 2);
	CPPUNIT_ASSERT(a.getNeighbors(0,1) == 3);
	CPPUNIT_ASSERT(a.getNeighbors(0,2) == 2);
	CPPUNIT_ASSERT(a.getNeighbors(1,0) == 3);
	CPPUNIT_ASSERT(a.getNeighbors(1,1) == 4);
	CPPUNIT_ASSERT(a.getNeighbors(1,2) == 3);
	CPPUNIT_ASSERT(a.getNeighbors(2,0) == 2);
	CPPUNIT_ASSERT(a.getNeighbors(2,1) == 3);
	CPPUNIT_ASSERT(a.getNeighbors(2,2) == 2); }

	void test_getNeighbors_fredkin_2() {
	Life<FredkinCell> a(3, 3, FredkinCell(false));
	a.setState(true,1,1);
	CPPUNIT_ASSERT(a._population == 1);
	CPPUNIT_ASSERT(a._generation == 0);
	CPPUNIT_ASSERT(a.getNeighbors(0,0) == 0);
	CPPUNIT_ASSERT(a.getNeighbors(0,1) == 1);
	CPPUNIT_ASSERT(a.getNeighbors(0,2) == 0);
	CPPUNIT_ASSERT(a.getNeighbors(1,0) == 1);
	CPPUNIT_ASSERT(a.getNeighbors(1,1) == 0);
	CPPUNIT_ASSERT(a.getNeighbors(1,2) == 1);
	CPPUNIT_ASSERT(a.getNeighbors(2,0) == 0);
	CPPUNIT_ASSERT(a.getNeighbors(2,1) == 1);
	CPPUNIT_ASSERT(a.getNeighbors(2,2) == 0); }


    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST(test_constructor_conway);
    CPPUNIT_TEST(test_constructor_fredkin);
    CPPUNIT_TEST(test_constructor_cell);
	CPPUNIT_TEST(test_setState_conway);
	CPPUNIT_TEST(test_setState_fredkin);
	CPPUNIT_TEST(test_setState_cell);
	CPPUNIT_TEST(test_setAge_fredkin);
	CPPUNIT_TEST(test_next_conway_1);
	CPPUNIT_TEST(test_next_conway_2);
	CPPUNIT_TEST(test_next_conway_3);
	CPPUNIT_TEST(test_next_fredkin_1);
	CPPUNIT_TEST(test_next_fredkin_2);
	CPPUNIT_TEST(test_next_fredkin_3);
	CPPUNIT_TEST(test_next_cell_1);
	CPPUNIT_TEST(test_next_cell_2);
	CPPUNIT_TEST(test_next_cell_3);
	CPPUNIT_TEST(test_getNeighbors_conway_1);
	CPPUNIT_TEST(test_getNeighbors_conway_2);
	CPPUNIT_TEST(test_getNeighbors_fredkin_1);
	CPPUNIT_TEST(test_getNeighbors_fredkin_2);
    CPPUNIT_TEST_SUITE_END();};

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestLife.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestLife::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}