#include <algorithm> // count
#include <iostream> // ios_base
#include <fstream>
#include <vector>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TestRunner

#define class struct
#define private public
#define protected public

#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Handle.h"

// ----------
// TestLife
// ----------

struct TestLife : CppUnit::TestFixture {

void test_get_name_1 () {
	ConwayCell c;
	char name =	c.cell_name();
	CPPUNIT_ASSERT(name == '.');
}

void test_get_name_2 () {
	ConwayCell c;
	char name =	c.cell_name();
	CPPUNIT_ASSERT(name == '.');
	FredkinCell f;
	name =	f.cell_name();
	CPPUNIT_ASSERT(name == '-');
}

void test_get_name_3 () {
	ConwayCell c;
	char name =	c.cell_name();
	CPPUNIT_ASSERT(name == '.');
	FredkinCell f;
	name =	f.cell_name();
	CPPUNIT_ASSERT(name == '-');
	AbstractCell* ptr = &f;
	name = ptr->cell_name();
	CPPUNIT_ASSERT(name == '-');
}

void test_life_1 () {
	ConwayCell c;
	AbstractCell* ptr = &c;
	ptr->give_life();
	char name =	c.cell_name();
	CPPUNIT_ASSERT(name == '*');
	ptr->give_life();
	name = c.cell_name();
	CPPUNIT_ASSERT(name == '*');
}

void test_life_2 () {
	ConwayCell c;
	AbstractCell* ptr = &c;
	ptr->take_life();
	char name = c.cell_name();
	CPPUNIT_ASSERT(name == '.');
}

void test_life_3 () {
	ConwayCell c;
	AbstractCell* ptr = &c;
	ptr->take_life();
	char name = c.cell_name();
	CPPUNIT_ASSERT(name == '.');
	ptr->give_life();
	name = c.cell_name();
	CPPUNIT_ASSERT(name == '*');
}

void test_life_4 () {
	FredkinCell c;
	AbstractCell* ptr = &c;
	ptr->take_life();
	char name = c.cell_name();
	CPPUNIT_ASSERT(name == '-');
	ptr->give_life();
}

void test_life_5 () {
	FredkinCell c;
	AbstractCell* ptr = &c;
	ptr->take_life();
	char name = c.cell_name();
	CPPUNIT_ASSERT(name == '-');
	ptr->give_life();
	name = c.cell_name();
	CPPUNIT_ASSERT(name == '0');
}

void test_code_1 () {
	ConwayCell(0,false);
	ConwayCell c;
	int code = c.run_cell(3);
	CPPUNIT_ASSERT(code == 1);
}

void test_code_2 () {
	FredkinCell c;
	int code = c.run_cell(3);
	CPPUNIT_ASSERT(code == 1);
	code = c.run_cell(1);
	CPPUNIT_ASSERT(code == 1);

}

void test_code_3 () {
	ConwayCell(0,false);
	ConwayCell c;

	int code = c.run_cell(3);
	CPPUNIT_ASSERT(code == 1);
	code = c.run_cell(0);
	CPPUNIT_ASSERT(code == 0);
	code = c.run_cell(1);
	CPPUNIT_ASSERT(code == 0);

	FredkinCell f;
	int f_code = f.run_cell(3);
	CPPUNIT_ASSERT(f_code == 1);
	f_code = f.run_cell(1);
	CPPUNIT_ASSERT(f_code == 1);
	f_code = f.run_cell(1);
	CPPUNIT_ASSERT(f_code == 1);
}

void test_life_constructor_1 () {
	Life<ConwayCell> life(4,4, false);
	life.make_board(4,4);
	CPPUNIT_ASSERT(life.board_1[0][0]->cell_name() == '.');
	CPPUNIT_ASSERT(life.board_1[0][3]->cell_name() == '.');
	CPPUNIT_ASSERT(life.board_1[3][2]->cell_name() == '.');
}

void test_life_constructor_2 () {
	Life<ConwayCell> life(10,10, false);
	life.make_board(10,10);
	CPPUNIT_ASSERT(life.board_1[0][0]->cell_name() == '.');
	CPPUNIT_ASSERT(life.board_1[4][8]->cell_name() == '.');
	CPPUNIT_ASSERT(life.board_1[9][9]->cell_name() == '.');
}

void test_life_constructor_3 () {
	Life<ConwayCell> life(7,3, false);
	life.make_board(7,3);
	CPPUNIT_ASSERT(life.board_1[0][0]->cell_name() == '.');
	CPPUNIT_ASSERT(life.board_1[1][1]->cell_name() == '.');
}

void test_life_add_1 () {
	Life<ConwayCell> life(4,4, false);
	life.make_board(4,4);

	life.add(1,0,0);
	CPPUNIT_ASSERT(life.board_1[0][0]->cell_name() == '*');
}

void test_life_add_2 () {
	Life<ConwayCell> life(4,4, false);
	life.make_board(4,4);

	life.add(1,0,0);
	life.add(1,1,1);

	CPPUNIT_ASSERT(life.board_1[0][0]->cell_name() == '*');
	CPPUNIT_ASSERT(life.board_1[1][1]->cell_name() == '*');

}

void test_life_add_3 () {
	Life<ConwayCell> life(4,4, false);
	life.make_board(4,4);

	life.add(1,0,0);
	life.add(1,1,1);
	life.add(1,3,2);

	CPPUNIT_ASSERT(life.board_1[0][0]->cell_name() == '*');
	CPPUNIT_ASSERT(life.board_1[1][1]->cell_name() == '*');
	CPPUNIT_ASSERT(life.board_1[2][3]->cell_name() == '*');
}

void test_life_add_4 () {
	Life<ConwayCell> life(4,4, false);
	life.make_board(4,4);

	life.add(1,0,0);
	life.add(1,1,1);
	life.add(1,3,2);

	CPPUNIT_ASSERT(life.board_1[0][0]->cell_name() == '*');
	CPPUNIT_ASSERT(life.board_1[1][1]->cell_name() == '*');
	CPPUNIT_ASSERT(life.board_1[2][3]->cell_name() == '*');

	life.add(0,3,2);

	CPPUNIT_ASSERT(life.board_1[2][3]->cell_name() == '.');
}

void test_life_update_1 () {
	Life<ConwayCell> life(4,4, false);
	life.make_board(4,4);

	life.update();

	CPPUNIT_ASSERT(life.num_board[0][0] == 0);
}

void test_life_update_2 () {
	Life<ConwayCell> life(4,4, false);
	life.make_board(4,4);

	life.add(1,0,0);
	life.update();

	CPPUNIT_ASSERT(life.num_board[1][1] == 1);
}

void test_life_update_3 () {
	Life<ConwayCell> life(4,4, false);
	life.make_board(4,4);

	life.add(1,0,0);
	life.add(1,1,1);

	life.update();

	CPPUNIT_ASSERT(life.num_board[0][0] == 1);
	CPPUNIT_ASSERT(life.num_board[1][1] == 1);
	CPPUNIT_ASSERT(life.num_board[2][2] == 1);
}


void test_life_check_1 () {
	Life<ConwayCell> life(4,4, false);
	life.make_board(4,4);

	life.update();

	int check_num = life.check_update(0,0);
	CPPUNIT_ASSERT(life.num_board[0][0] == 0);
	CPPUNIT_ASSERT(check_num == 0);
}

void test_life_check_2() {
	Life<ConwayCell> life(4,4, false);
	life.make_board(4,4);

	life.add(1,1,1);
	life.update();

	int check_num = life.check_update(0,0);
	CPPUNIT_ASSERT(life.num_board[0][0] == 1);
	CPPUNIT_ASSERT(check_num == 1);
}

void test_life_check_3() {
	Life<ConwayCell> life(4,4, false);
	life.make_board(4,4);

	life.add(1,1,1);
	life.add(1,1,0);

	life.update();

	int check_num = life.check_update(0,0);
	CPPUNIT_ASSERT(life.num_board[0][0] == 2);
	CPPUNIT_ASSERT(check_num == 2);
}

// ---------
// TestSuite
// ---------

CPPUNIT_TEST_SUITE(TestLife);
CPPUNIT_TEST(test_get_name_1);
CPPUNIT_TEST(test_get_name_2);
CPPUNIT_TEST(test_get_name_3);


CPPUNIT_TEST(test_life_1);
CPPUNIT_TEST(test_life_2);
CPPUNIT_TEST(test_life_3);
CPPUNIT_TEST(test_life_4);


CPPUNIT_TEST(test_code_1);
CPPUNIT_TEST(test_code_2);
CPPUNIT_TEST(test_code_3);

CPPUNIT_TEST(test_life_constructor_1);
CPPUNIT_TEST(test_life_constructor_2);
CPPUNIT_TEST(test_life_constructor_3);


CPPUNIT_TEST(test_life_add_1);
CPPUNIT_TEST(test_life_add_2);
CPPUNIT_TEST(test_life_add_3);
CPPUNIT_TEST(test_life_add_4);

CPPUNIT_TEST(test_life_update_1);
CPPUNIT_TEST(test_life_update_2);
CPPUNIT_TEST(test_life_update_3);

CPPUNIT_TEST(test_life_check_1);
CPPUNIT_TEST(test_life_check_2);
CPPUNIT_TEST(test_life_check_3);


CPPUNIT_TEST_SUITE_END();
};


int main() {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout << "TestLife.c++" << endl;
    CppUnit::TextTestRunner tr;
    tr.addTest(TestLife::suite());
    tr.run();
    cout << "Done." << endl;

    return 0;
}
