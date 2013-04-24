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
	void testAlive1() {
		Life<ConwayCell> l(ConwayCell(), 1, 1);
		CPPUNIT_ASSERT(l._grid[0][0].isAlive());
	}
	void testAlive2() {
		Life<ConwayCell> l(ConwayCell(false), 1, 1);
		CPPUNIT_ASSERT(!l._grid[0][0].isAlive());
	}
	void testAlive3() {
		Life<ConwayCell> l(ConwayCell(true), 2, 2);
		CPPUNIT_ASSERT(l._grid[1][1].isAlive());
	}
	
	void testPrint1() {
		Life<ConwayCell> l(ConwayCell(), 1, 1);
		CPPUNIT_ASSERT(l._grid[0][0].print() == '*');
	}
	
	void testPrint2() {
		Life<FredkinCell> l(FredkinCell(), 1, 1);
		CPPUNIT_ASSERT(l._grid[0][0].print() == '0');
	}
	
	void testPrint3() {
		Life<Cell> l(new FredkinCell(), 1, 1);
		CPPUNIT_ASSERT(l._grid[0][0].print() == '0');
	}
	
	void testMorph1() {
		Life<ConwayCell> l(ConwayCell(), 1, 1);
		CPPUNIT_ASSERT(!l._grid[0][0].morph());
	}
	
	void testMorph2() {
		Life<FredkinCell> l(FredkinCell(), 1, 1);
		CPPUNIT_ASSERT(!l._grid[0][0].morph());
	}
	
	void testMorph3() {
		Life<FredkinCell> l(FredkinCell(true, 3), 1, 1);
		CPPUNIT_ASSERT(l._grid[0][0].morph());
	}
	
	void testConwayCell1() {
		Cell c(new ConwayCell());
		CPPUNIT_ASSERT(c.isAlive());
	}
	
	void testConwayCell2() {
		Cell c(new ConwayCell(true));
		CPPUNIT_ASSERT(c.isAlive());
	}
	
	void testConwayCell3() {
		Cell c(new ConwayCell(false));
		CPPUNIT_ASSERT(!c.isAlive());
	}
	
	void testFredkinCell1() {
		Cell c(new FredkinCell());
		CPPUNIT_ASSERT(c.isAlive());
	}
	
	void testFredkinCell2() {
		Cell c(new FredkinCell(true));
		CPPUNIT_ASSERT(c.isAlive());
	}
	
	void testFredkinCell3() {
		Cell c(new FredkinCell(false));
		CPPUNIT_ASSERT(!c.isAlive());
	}
	
	
	CPPUNIT_TEST_SUITE(TestLife);
	CPPUNIT_TEST(testAlive1);
	CPPUNIT_TEST(testAlive2);
	CPPUNIT_TEST(testAlive3);
	CPPUNIT_TEST(testPrint1);
	CPPUNIT_TEST(testPrint2);
	CPPUNIT_TEST(testPrint3);
	CPPUNIT_TEST(testMorph1);
	CPPUNIT_TEST(testMorph2);
	CPPUNIT_TEST(testMorph3);
	CPPUNIT_TEST(testConwayCell1);
	CPPUNIT_TEST(testConwayCell2);
	CPPUNIT_TEST(testConwayCell3);
	CPPUNIT_TEST(testFredkinCell1);
	CPPUNIT_TEST(testFredkinCell2);
	CPPUNIT_TEST(testFredkinCell3);
// 	CPPUNIT_TEST();
// 	CPPUNIT_TEST();
// 	CPPUNIT_TEST();
// 	CPPUNIT_TEST();
// 	CPPUNIT_TEST();
// 	CPPUNIT_TEST();
// 	CPPUNIT_TEST();
// 	CPPUNIT_TEST();
// 	CPPUNIT_TEST();
// 	CPPUNIT_TEST();
// 	CPPUNIT_TEST();
// 	CPPUNIT_TEST();
	CPPUNIT_TEST_SUITE_END();
};


int main() {
    using namespace std;
    ios_base::sync_with_stdio(false);
    //freopen("TestLife.out", "w", stdout);
    cout << "TestLife.c++" << endl;
    CppUnit::TextTestRunner tr;
    tr.addTest(TestLife::suite());
    tr.run();
    cout << "Done." << endl;

    return 0;
}