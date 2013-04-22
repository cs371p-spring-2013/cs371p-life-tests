// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#define private public
#define protected public
#include "Life.h"

using namespace std;

// -----------
// TestLife
// -----------

struct TestLife : CppUnit::TestFixture {

	// -----
	// chooseAction
	// -----
/*
	.*.
	..*
	.*.
*/
	void test_choose_action_1 () {
		Life<ConwayCell> l = Life<ConwayCell>();	// default 3x3 life board
		ConwayCell cA(true);
		ConwayCell cD(false);
		l.populateBoard(0, 0, cD);
		l.populateBoard(0, 1, cA);
		l.populateBoard(0, 2, cD);
		l.populateBoard(1, 0, cD);
		l.populateBoard(1, 1, cD);
		l.populateBoard(1, 2, cA);
		l.populateBoard(2, 0, cD);
		l.populateBoard(2, 1, cA);
		l.populateBoard(2, 2, cD);
		int numCols = 3;
		l.B(1, 1).chooseAction(3);
		CPPUNIT_ASSERT(l.B(1, 1).action == BECOMEALIVE);
	}

	void test_choose_action_2 () {
		Life<FredkinCell> l = Life<FredkinCell>();	// default 3x3 life board
		FredkinCell fA(true);
		FredkinCell fD(false);
		l.populateBoard(0, 0, fD);
		l.populateBoard(0, 1, fD);
		l.populateBoard(0, 2, fD);
		l.populateBoard(1, 0, fD);
		l.populateBoard(1, 1, fA);
		l.populateBoard(1, 2, fD);
		l.populateBoard(2, 0, fD);
		l.populateBoard(2, 1, fD);
		l.populateBoard(2, 2, fD);
		int numCols = 3;
		l.B(1, 1).chooseAction(2);
		CPPUNIT_ASSERT(l.B(1, 1).action == BECOMEDEAD);
	}

	void test_choose_action_3 () {
		Life<Cell> l = Life<Cell>();	// default 3x3 life board
		Cell fA = new FredkinCell(true);
		Cell fD = new FredkinCell(false);
		l.populateBoard(0, 0, fD);
		l.populateBoard(0, 1, fD);
		l.populateBoard(0, 2, fD);
		l.populateBoard(1, 0, fD);
		l.populateBoard(1, 1, fA);
		l.populateBoard(1, 2, fD);
		l.populateBoard(2, 0, fD);
		l.populateBoard(2, 1, fD);
		l.populateBoard(2, 2, fD);
		int numCols = 3;
		l.B(0, 1).chooseAction(1);
		CPPUNIT_ASSERT(l.B(0, 1).get()->action == BECOMEALIVE);
	}

	// -----
	// performAction
	// -----
	void test_perform_action_1 () {
		ConwayCell c = ConwayCell(true);
		c.action = BECOMEDEAD;
		c.performAction();
		CPPUNIT_ASSERT(!c.alive);
	}
	
	void test_perform_action_2 () {
		FredkinCell c = FredkinCell(true);
		c.action = DONOTHING;
		c.performAction();
		CPPUNIT_ASSERT(c.alive && c.age == 1);
	}

	void test_perform_action_3 () {
		Cell c = new FredkinCell(false);
		c.get()->action = BECOMEALIVE;
		c.performAction();
		CPPUNIT_ASSERT(c.get()->alive);
	}

	// -----
	// write / <<
	// -----
	void test_write_1 () {
		ostringstream w;
		ConwayCell c(true);
		c.write(w);
		CPPUNIT_ASSERT(w.str() == "*");
	}
	void test_write_2 () {
		ostringstream w;
		FredkinCell c(false);
		c.write(w);
		CPPUNIT_ASSERT(w.str() == "-");
	}
	void test_write_3 () {
		ostringstream w;
		FredkinCell c(true);
		c.age = 9;
		w << c;
		CPPUNIT_ASSERT(w.str() == "9");
		c.age = 1000;
		w << c;
		CPPUNIT_ASSERT(w.str() == "9+");
	}

	// -----
	// countNeighbors and countNeighborsHelper
	// -----
/*
	.*.
	..*
	.*.
*/
	void test_count_neighbors_1 () {
		Life<ConwayCell> l = Life<ConwayCell>();	// default 3x3 life board
		ConwayCell cA(true);
		ConwayCell cD(false);
		l.populateBoard(0, 0, cD);
		l.populateBoard(0, 1, cA);
		l.populateBoard(0, 2, cD);
		l.populateBoard(1, 0, cD);
		l.populateBoard(1, 1, cD);
		l.populateBoard(1, 2, cA);
		l.populateBoard(2, 0, cD);
		l.populateBoard(2, 1, cA);
		l.populateBoard(2, 2, cD);
		int numNeighbs = l.countNeighbors(1, 1, 'c');
		CPPUNIT_ASSERT(numNeighbs == 3);
	}
	void test_count_neighbors_2 () {
		Life<FredkinCell> l = Life<FredkinCell>();	// default 3x3 life board
		FredkinCell fA(true);
		FredkinCell fD(false);
		l.populateBoard(0, 0, fD);
		l.populateBoard(0, 1, fA);
		l.populateBoard(0, 2, fD);
		l.populateBoard(1, 0, fD);
		l.populateBoard(1, 1, fA);
		l.populateBoard(1, 2, fD);
		l.populateBoard(2, 0, fD);
		l.populateBoard(2, 1, fD);
		l.populateBoard(2, 2, fD);
		int numNeighbs = l.countNeighbors(0, 0, 'f');
		CPPUNIT_ASSERT(numNeighbs == 1);
	}

	void test_count_neighbors_3 () {
		Life<Cell> l = Life<Cell>();	// default 3x3 life board
		Cell fA = new FredkinCell(true);
		Cell fD = new FredkinCell(false);
		l.populateBoard(0, 0, fD);
		l.populateBoard(0, 1, fD);
		l.populateBoard(0, 2, fD);
		l.populateBoard(1, 0, fA);
		l.populateBoard(1, 1, fA);
		l.populateBoard(1, 2, fD);
		l.populateBoard(2, 0, fD);
		l.populateBoard(2, 1, fA);
		l.populateBoard(2, 2, fD);
		int numNeighbs = l.countNeighbors(2, 2, 'f');
		CPPUNIT_ASSERT(numNeighbs == 1);
	}
	
	// -----
	// populateBoard & printBoard
	// -----
/*
	.  .  .
	.  *  .
	.  .  .
*/
	void test_populate_print_board_1 () {
		ostringstream w;
		Life<ConwayCell> l = Life<ConwayCell>();	// default 3x3 life board
		ConwayCell cA(true);
		ConwayCell cD(false);
		l.populateBoard(0, 0, cD);
		l.populateBoard(0, 1, cD);
		l.populateBoard(0, 2, cD);
		l.populateBoard(1, 0, cD);
		l.populateBoard(1, 1, cA);
		l.populateBoard(1, 2, cD);
		l.populateBoard(2, 0, cD);
		l.populateBoard(2, 1, cD);
		l.populateBoard(2, 2, cD);
		l.printBoard(w);
		CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 1.\n...\n.*.\n...\n\n");
	}

	void test_populate_print_board_2 () {
		ostringstream w;
		Life<FredkinCell> l = Life<FredkinCell>();	// default 3x3 life board
		FredkinCell fA(true);
		FredkinCell fD(false);
		l.populateBoard(0, 0, fD);
		l.populateBoard(0, 1, fD);
		l.populateBoard(0, 2, fD);
		l.populateBoard(1, 0, fD);
		l.populateBoard(1, 1, fA);
		l.populateBoard(1, 2, fD);
		l.populateBoard(2, 0, fD);
		l.populateBoard(2, 1, fD);
		l.populateBoard(2, 2, fD);
		l.printBoard(w);
		CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 1.\n---\n-0-\n---\n\n");
	}
	
	void test_populate_print_board_3 () {
		ostringstream w;
		Life<Cell> l = Life<Cell>();	// default 3x3 life board
		Cell fA = new FredkinCell(true);
		Cell fD = new FredkinCell(false);
		l.populateBoard(0, 0, fD);
		l.populateBoard(0, 1, fD);
		l.populateBoard(0, 2, fD);
		l.populateBoard(1, 0, fD);
		l.populateBoard(1, 1, fA);
		l.populateBoard(1, 2, fD);
		l.populateBoard(2, 0, fD);
		l.populateBoard(2, 1, fD);
		l.populateBoard(2, 2, fD);
		l.printBoard(w);
		CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 1.\n---\n-0-\n---\n\n");
	}

	// -----
	// doGeneration
	// -----
	void test_do_generation_1 () {
		ostringstream w;
		Life<ConwayCell> l = Life<ConwayCell>(2, 2);
		ConwayCell cA(true);
		ConwayCell cD(false);
		l.populateBoard(0, 0, cD);
		l.populateBoard(0, 1, cD);
		l.populateBoard(1, 0, cD);
		l.populateBoard(1, 1, cA);
		l.printBoard(w);
		l.doGeneration();
		l.printBoard(w);
		CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 1.\n..\n.*\n\nGeneration = 1, Population = 0.\n..\n..\n\n");
	}

	void test_do_generation_2 () {
		ostringstream w;
		Life<FredkinCell> l = Life<FredkinCell>(2, 2);
		FredkinCell fA(true);
		FredkinCell fD(false);
		l.populateBoard(0, 0, fD);
		l.populateBoard(0, 1, fD);
		l.populateBoard(1, 0, fA);
		l.populateBoard(1, 1, fA);
		l.printBoard(w);
		l.doGeneration();
		l.printBoard(w);
		CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 2.\n--\n00\n\nGeneration = 1, Population = 4.\n00\n11\n\n");
	}
	
	void test_do_generation_3 () {
		ostringstream w;
		Life<Cell> l = Life<Cell>(2, 2);
		Cell fA0 = new FredkinCell(true);
		Cell fA1 = new FredkinCell(true);
		reinterpret_cast<FredkinCell*>(fA1.get())->age = 1;
		Cell fD = new FredkinCell(false);
		l.populateBoard(0, 0, fD);
		l.populateBoard(0, 1, fD);
		l.populateBoard(1, 0, fA1);
		l.populateBoard(1, 1, fA0);
		l.printBoard(w);
		l.doGeneration(true);
		l.printBoard(w);
		l.doGeneration(true);
		l.printBoard(w);
		CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 2.\n--\n10\n\nGeneration = 1, Population = 4.\n00\n*1\n\nGeneration = 2, Population = 1.\n--\n*-\n\n");
	}



    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);
	CPPUNIT_TEST(test_choose_action_1);
	CPPUNIT_TEST(test_choose_action_2);
	CPPUNIT_TEST(test_choose_action_3);
	CPPUNIT_TEST(test_perform_action_1);
	CPPUNIT_TEST(test_perform_action_2);
	CPPUNIT_TEST(test_perform_action_3);
	CPPUNIT_TEST(test_write_1);
	CPPUNIT_TEST(test_write_2);
	CPPUNIT_TEST(test_write_3);
	CPPUNIT_TEST(test_count_neighbors_1);
	CPPUNIT_TEST(test_count_neighbors_2);
	CPPUNIT_TEST(test_count_neighbors_3);
	CPPUNIT_TEST(test_populate_print_board_1);
	CPPUNIT_TEST(test_populate_print_board_2);
	CPPUNIT_TEST(test_populate_print_board_3);
	CPPUNIT_TEST(test_do_generation_1);
	CPPUNIT_TEST(test_do_generation_2);
	CPPUNIT_TEST(test_do_generation_3);
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
