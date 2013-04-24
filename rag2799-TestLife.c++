// --------------------------------
// TestDarwin
// --------------------------------

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
#include <sstream> // istringtstream, ostringstream
#include <string> // ==
#include <vector>
#include <sstream>
#include <stdexcept>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TextTestRunner

#define private public
#define protected public

#include "Life.h"
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

using namespace std;

struct TestLife : CppUnit::TestFixture {

    // ------------------------------------    
    // AbstractCell tests
    // ------------------------------------

    void test_isAlive () {
			ConwayCell a(true);
			CPPUNIT_ASSERT(a.isAlive());
    }

    void test_isAlive2 () {
			FredkinCell a(false);
			CPPUNIT_ASSERT(!a.isAlive());
    }

    void test_isAlive3 () {
			ConwayCell a(true);
			a.update();
			CPPUNIT_ASSERT(!a.isAlive());
    }
    
    // ------------------------------------
    // Conway Tests
    // ------------------------------------

    void test_ConwayUpdate () {
			ConwayCell a(true);
			CPPUNIT_ASSERT(!a.update());
			CPPUNIT_ASSERT(!a.isAlive());
    }

    void test_ConwayUpdate2 () {
			ConwayCell a(true);
			a.nextState = true;
			CPPUNIT_ASSERT(!a.update());
			CPPUNIT_ASSERT(a.isAlive());
    }

    void test_ConwayUpdate3 () {
			ConwayCell a(false);
			a.nextState = true;
			CPPUNIT_ASSERT(!a.update());
			CPPUNIT_ASSERT(a.isAlive());
    }

    void test_ConwayEvolve () {
			ConwayCell a(false);
			CPPUNIT_ASSERT(a.evolve(3));
    }

    void test_ConwayEvolve2 () {
			ConwayCell a(false);
			CPPUNIT_ASSERT(!a.evolve(2));
    }

		void test_ConwayEvolve3 () {
			ConwayCell a(true);
			CPPUNIT_ASSERT(a.evolve(3));
    }

    void test_ConwayEvolve4 () {
			ConwayCell a(true);
			CPPUNIT_ASSERT(!a.evolve(1));
    }

    void test_ConwayEvolve5 () {
			ConwayCell a(true);
			CPPUNIT_ASSERT(!a.evolve(5));
    }

    void test_ConwayPrint () {
			ConwayCell a(true);
			CPPUNIT_ASSERT(a.print() == '*');
    }

    void test_ConwayPrint2 () {
			ConwayCell a(false);
			CPPUNIT_ASSERT(a.print() == '.');
    }

    void test_ConwayClone () {
			ConwayCell a(true);
			ConwayCell* copy = a.clone();
			CPPUNIT_ASSERT(copy->isAlive() == a.isAlive());
			CPPUNIT_ASSERT(copy->nextState == a.nextState);
			delete copy;
    }

    // ------------------------------------
    // Fredkin Tests
    // ------------------------------------

    void test_FredkinUpdate () {
			FredkinCell a(true);
			CPPUNIT_ASSERT(!a.update());
			CPPUNIT_ASSERT(!a.isAlive());
    }

    void test_FredkinUpdate2 () {
			FredkinCell a(true, 2);
			a.nextState = true;
			CPPUNIT_ASSERT(a.update());
			CPPUNIT_ASSERT(a.isAlive());
    }

    void test_FredkinUpdate3 () {
			FredkinCell a(false);
			a.nextState = true;
			CPPUNIT_ASSERT(!a.update());
			CPPUNIT_ASSERT(a.isAlive());
    }

    void test_FredkinEvolve () {
			FredkinCell a(false);
			CPPUNIT_ASSERT(a.evolve(3));
    }

    void test_FredkinEvolve2 () {
			FredkinCell a(false);
			CPPUNIT_ASSERT(!a.evolve(2));
    }

    void test_FredkinEvolve3 () {
			FredkinCell a(true);
			CPPUNIT_ASSERT(a.evolve(3));
    }

    void test_FredkinEvolve4 () {
			FredkinCell a(true);
			CPPUNIT_ASSERT(a.evolve(1));
    }

    void test_FredkinEvolve5 () {
			FredkinCell a(true);
			CPPUNIT_ASSERT(!a.evolve(4));
    }

    void test_FredkinPrint () {
			FredkinCell a(true);
			CPPUNIT_ASSERT(a.print() == '0');
    }

    void test_FredkinPrint2 () {
			FredkinCell a(false);
			CPPUNIT_ASSERT(a.print() == '-');
    }

    void test_FredkinPrint3 () {
			FredkinCell a(true, 12);
			CPPUNIT_ASSERT(a.print() == '2');
    }

    void test_FredkinClone () {
			FredkinCell a(true);
			FredkinCell* copy = a.clone();
			CPPUNIT_ASSERT(copy->isAlive() == a.isAlive());
			CPPUNIT_ASSERT(copy->nextState == a.nextState);
			CPPUNIT_ASSERT(copy->age == a.age);
			delete copy;
    }

		// --------------------------------------------
		// Cell tests
		// -------------------------------------------

		void test_CellisAlive() {
			Cell c = ConwayCell(true);
			CPPUNIT_ASSERT(c.isAlive());
    }

    void test_CellisAlive2 () {
			Cell c = FredkinCell(false);
			CPPUNIT_ASSERT(!c.isAlive());
    }

    void test_CellisAlive3 () {
			Cell a = ConwayCell(true);
			a.update();
			CPPUNIT_ASSERT(!a.isAlive());
    }

    void test_CellUpdate(){
      Cell a = ConwayCell(true);
      CPPUNIT_ASSERT(!a.update());
      CPPUNIT_ASSERT(!a.isAlive());
    }

    void test_CellUpdate2 () {
      Cell a = ConwayCell(true);
      (*a).nextState = true;
      CPPUNIT_ASSERT(!a.update());
      CPPUNIT_ASSERT(a.isAlive());
    }

    void test_CellUpdate3 () {
      Cell a = ConwayCell(false);
      (*a).nextState = true;
      CPPUNIT_ASSERT(!a.update());
      CPPUNIT_ASSERT(a.isAlive());
    }

    void test_CellUpdate4 () {
			Cell a = FredkinCell(true);
			CPPUNIT_ASSERT(!a.update());
			CPPUNIT_ASSERT(!a.isAlive());
		}

    void test_CellUpdate5 () {
			Cell a = FredkinCell(true, 2);
			(*a).nextState = true;
			CPPUNIT_ASSERT(a.update());
			CPPUNIT_ASSERT(a.isAlive());
    }

    void test_CellUpdate6 () {
			Cell a = FredkinCell(false);
			(*a).nextState = true;
			CPPUNIT_ASSERT(!a.update());
			CPPUNIT_ASSERT(a.isAlive());
    }

    void test_CellEvolve(){
      Cell a = ConwayCell(false);
      CPPUNIT_ASSERT(a.evolve(3));
    }

    void test_CellEvolve2 () {
			Cell a = ConwayCell(false);
			CPPUNIT_ASSERT(!a.evolve(2));
    }

    void test_CellEvolve3 () {
      Cell a = ConwayCell(true);
      CPPUNIT_ASSERT(a.evolve(3));
    }

    void test_CellEvolve4 () {
      Cell a = ConwayCell(true);
      CPPUNIT_ASSERT(!a.evolve(1));
    }

    void test_CellEvolve5 () {
      Cell a = ConwayCell(true);
      CPPUNIT_ASSERT(!a.evolve(5));
    }

    void test_CellEvolve6 () {
			Cell a = FredkinCell(false);
			CPPUNIT_ASSERT(a.evolve(3));
    }

    void test_CellEvolve7 () {
			Cell a = FredkinCell(false);
			CPPUNIT_ASSERT(!a.evolve(2));
    }

    void test_CellEvolve8 () {
			Cell a = FredkinCell(true);
			CPPUNIT_ASSERT(a.evolve(3));
    }

    void test_CellEvolve9 () {
			Cell a = FredkinCell(true);
			CPPUNIT_ASSERT(a.evolve(1));
    }

    void test_CellEvolve10 () {
			Cell a = FredkinCell(true);
			CPPUNIT_ASSERT(!a.evolve(4));
    }

    void test_CellPrint () {
      Cell a = ConwayCell(true);
      CPPUNIT_ASSERT(a.print() == '*');
    }

    void test_CellPrint2 () {
      Cell a = ConwayCell(false);
      CPPUNIT_ASSERT(a.print() == '.');
    }

    void test_CellPrint3 () {
			Cell a = FredkinCell(true);
			CPPUNIT_ASSERT(a.print() == '0');
    }

    void test_CellPrint4 () {
			Cell a = FredkinCell(false);
			CPPUNIT_ASSERT(a.print() == '-');
    }

    void test_CellPrint5 () {
			Cell a = FredkinCell(true, 12);
			CPPUNIT_ASSERT(a.print() == '2');
    }

		// ----------------------------------
		// Life tests
		// ----------------------------------

		void test_readConway(){
			Life<ConwayCell> test;
			test.read_grid("TestLifeConway.in");
			CPPUNIT_ASSERT(test.everybody.size() == test.rows*test.cols);
			CPPUNIT_ASSERT(test.population == 35);
			CPPUNIT_ASSERT(test.generation == 0);
		}

		void test_readFredkin(){
			Life<FredkinCell> test;
			test.read_grid("TestLifeFredkin.in");
			CPPUNIT_ASSERT(test.everybody.size() == test.rows*test.cols);
			CPPUNIT_ASSERT(test.population == 4);
			CPPUNIT_ASSERT(test.generation == 0);
		}

		void test_readCell(){
			Life<Cell> test;
			test.read_grid("TestLifeCell.in");
			CPPUNIT_ASSERT(test.everybody.size() == test.rows*test.cols);
			CPPUNIT_ASSERT(test.population == 9);
			CPPUNIT_ASSERT(test.generation == 0);
		}

		void test_runConway(){
			Life<ConwayCell> test;
			test.read_grid("TestLifeConway.in");
			test.run_turns(1);
			CPPUNIT_ASSERT(test.everybody.size() == test.rows*test.cols);
			CPPUNIT_ASSERT(test.population == 63);
			CPPUNIT_ASSERT(test.generation == 1);
			test.run_turns(2);
			CPPUNIT_ASSERT(test.population == 56);
			CPPUNIT_ASSERT(test.generation == 2);
		}

		void test_runFredkin(){
			Life<FredkinCell> test;
			test.read_grid("TestLifeFredkin.in");
			test.run_turns(1);
			CPPUNIT_ASSERT(test.everybody.size() == test.rows*test.cols);
			CPPUNIT_ASSERT(test.population == 8);
			CPPUNIT_ASSERT(test.generation == 1);
			test.run_turns(2);
			CPPUNIT_ASSERT(test.population == 16);
			CPPUNIT_ASSERT(test.generation == 2);
			CPPUNIT_ASSERT(test.grid[8][9].age == 1);
		}

		void test_runCell(){
			Life<Cell> test;
			test.read_grid("TestLifeCell.in");
			test.run_turns(1);
			CPPUNIT_ASSERT(test.everybody.size() == test.rows*test.cols);
			CPPUNIT_ASSERT(test.population == 21);
			CPPUNIT_ASSERT(test.generation == 1);
			test.run_turns(2);
			CPPUNIT_ASSERT(test.population == 34);
			CPPUNIT_ASSERT(test.generation == 2);
			test.run_turns(3);
			CPPUNIT_ASSERT(test.grid[16][18].print() == '*');
		}
  
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST(test_isAlive);
    CPPUNIT_TEST(test_isAlive2);
    CPPUNIT_TEST(test_isAlive3);
    CPPUNIT_TEST(test_ConwayUpdate);
    CPPUNIT_TEST(test_ConwayUpdate2);
    CPPUNIT_TEST(test_ConwayUpdate3);
    CPPUNIT_TEST(test_ConwayEvolve);
    CPPUNIT_TEST(test_ConwayEvolve2);
    CPPUNIT_TEST(test_ConwayEvolve3);
    CPPUNIT_TEST(test_ConwayEvolve4);
    CPPUNIT_TEST(test_ConwayEvolve5);
    CPPUNIT_TEST(test_ConwayPrint);
    CPPUNIT_TEST(test_ConwayPrint2);
    CPPUNIT_TEST(test_ConwayClone);

    CPPUNIT_TEST(test_FredkinUpdate);
    CPPUNIT_TEST(test_FredkinUpdate2);
    CPPUNIT_TEST(test_FredkinUpdate3);
    CPPUNIT_TEST(test_FredkinEvolve);
    CPPUNIT_TEST(test_FredkinEvolve2);
    CPPUNIT_TEST(test_FredkinEvolve3);
    CPPUNIT_TEST(test_FredkinEvolve4);
    CPPUNIT_TEST(test_FredkinEvolve5);
    CPPUNIT_TEST(test_FredkinPrint);
    CPPUNIT_TEST(test_FredkinPrint2);
    CPPUNIT_TEST(test_FredkinPrint3);
    CPPUNIT_TEST(test_FredkinClone);

    CPPUNIT_TEST(test_CellisAlive);
    CPPUNIT_TEST(test_CellisAlive2);
    CPPUNIT_TEST(test_CellisAlive3);
    CPPUNIT_TEST(test_CellUpdate);
    CPPUNIT_TEST(test_CellUpdate2);
    CPPUNIT_TEST(test_CellUpdate3);
    CPPUNIT_TEST(test_CellUpdate4);
    CPPUNIT_TEST(test_CellUpdate5);  
    CPPUNIT_TEST(test_CellUpdate6);
    CPPUNIT_TEST(test_CellEvolve);
    CPPUNIT_TEST(test_CellEvolve2);
    CPPUNIT_TEST(test_CellEvolve3);
    CPPUNIT_TEST(test_CellEvolve4);
    CPPUNIT_TEST(test_CellEvolve5);
    CPPUNIT_TEST(test_CellEvolve6);
    CPPUNIT_TEST(test_CellEvolve7);
    CPPUNIT_TEST(test_CellEvolve8);
    CPPUNIT_TEST(test_CellEvolve9);
    CPPUNIT_TEST(test_CellEvolve10);
    CPPUNIT_TEST(test_CellPrint);
    CPPUNIT_TEST(test_CellPrint2);
    CPPUNIT_TEST(test_CellPrint3);
    CPPUNIT_TEST(test_CellPrint4);
    CPPUNIT_TEST(test_CellPrint5);

		CPPUNIT_TEST(test_readConway);
		CPPUNIT_TEST(test_readFredkin);
		CPPUNIT_TEST(test_readCell);
		CPPUNIT_TEST(test_runConway);
		CPPUNIT_TEST(test_runFredkin);
		CPPUNIT_TEST(test_runCell);


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
