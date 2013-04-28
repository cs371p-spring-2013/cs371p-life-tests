// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#include "Life.h"

// --------
// TestLife
// --------

struct TestLife : CppUnit::TestFixture {
	
	// ------------
	// test_isAlive
	// ------------

	void test_isAlive_1() {
		ConwayCell c1(false);
		CPPUNIT_ASSERT(!c1.isAlive());
		ConwayCell c2(true);
		CPPUNIT_ASSERT(c2.isAlive());
	}
	void test_isAlive_2() {
		FredkinCell c1(false);
		CPPUNIT_ASSERT(!c1.isAlive());
		FredkinCell c2(true);
		CPPUNIT_ASSERT(c2.isAlive());
	}
	void test_isAlive_3() {
		ConwayCell c1(false);
		FredkinCell c2(false);
		CPPUNIT_ASSERT(!c1.isAlive());
		CPPUNIT_ASSERT(!c2.isAlive());
		c1.change();
		c2.change();
		CPPUNIT_ASSERT(c1.isAlive());
		CPPUNIT_ASSERT(c2.isAlive());
	}


	// -----------
	// test_change
	// -----------

	void test_change_1() {
		ConwayCell c1(false);
		CPPUNIT_ASSERT(!c1.isAlive());
		c1.change();
		CPPUNIT_ASSERT(c1.isAlive());
	}
	void test_change_2() {
		FredkinCell c1(false);
		CPPUNIT_ASSERT(!c1.isAlive());
		c1.change();
		CPPUNIT_ASSERT(c1.isAlive());
	}
	void test_change_3() {
		ConwayCell c1(false);
		FredkinCell c2(false);
		CPPUNIT_ASSERT(!c1.isAlive());
		CPPUNIT_ASSERT(!c2.isAlive());
		c1.change();
		c2.change();
		CPPUNIT_ASSERT(c1.isAlive());
		CPPUNIT_ASSERT(c2.isAlive());
	}


	// -----------
	// test_update
	// -----------
	
	void test_update_1() {
		ConwayCell c1(false);
		ConwayCell c2(false);
		ConwayCell c3(true);
		ConwayCell c4(true);
		c1.update(3);
		c2.update(0);
		c3.update(3);
		c4.update(0);
		bool a = c1.flagged();
		bool b = c2.flagged();
		bool c = c3.flagged();
		bool d = c4.flagged();
		CPPUNIT_ASSERT(a);
		CPPUNIT_ASSERT(!b);
		CPPUNIT_ASSERT(!c);
		CPPUNIT_ASSERT(d);
	}
	void test_update_2() {
		FredkinCell c1(false);
		FredkinCell c2(false);
		c1.update(0);
		c2.update(1);
		bool a = c1.flagged();
		bool b = c2.flagged();
		CPPUNIT_ASSERT(!a);
		CPPUNIT_ASSERT(b);
	}
	void test_update_3() {
		FredkinCell c1(true);
		FredkinCell c2(true);
		c1.update(0);
		c2.update(1);
		bool a = c1.flagged();
		bool b = c2.flagged();
		CPPUNIT_ASSERT(a);
		CPPUNIT_ASSERT(!b);
	}


	     
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST(test_isAlive_1);
    CPPUNIT_TEST(test_isAlive_2);
    CPPUNIT_TEST(test_isAlive_3);
    CPPUNIT_TEST(test_change_1);
    CPPUNIT_TEST(test_change_2);
    CPPUNIT_TEST(test_change_3);
    CPPUNIT_TEST(test_update_1);
    CPPUNIT_TEST(test_update_2);
    CPPUNIT_TEST(test_update_3);
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