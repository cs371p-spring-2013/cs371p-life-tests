
// --------
// includes
// --------

#include <algorithm> //count
#include <iostream> // ios_base
#include <memory> //allocator
#include <sstream> //string stream
#include <stdexcept> //exceptions
#include <vector>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner



#define protected public
#define private public

#include "Cell.h"
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Life.h"

// -------------
// TestLife
// -------------

struct TestLife : CppUnit::TestFixture {
    // -------
    // isAlive
    // -------
    void testIsAlive1 () {
        ConwayCell c(true);
        CPPUNIT_ASSERT(c.isAlive());}
    
    void testIsAlive2 () {
        FredkinCell c(false, 0);
        CPPUNIT_ASSERT(!(c.isAlive()));}
    
    void testIsAlive3 () {
        Cell c(new FredkinCell(true, 0));
        CPPUNIT_ASSERT(c.isAlive());}
    
    // ----------
    // wantUpdate
    // ----------
    void testWantUpdate1 () {
        ConwayCell c(true);
        CPPUNIT_ASSERT(!(c.wantUpdate()));}
    
    void testWantUpdate2 () {
        FredkinCell c(false, 0);
        c.setUpdate(true);
        CPPUNIT_ASSERT(c.wantUpdate());}
    
    void testWantUpdate3 () {
        Cell c(new FredkinCell(true, 0));
        CPPUNIT_ASSERT(!(c.wantUpdate()));}
    
    // ---------
    // setUpdate
    // ---------
    void testSetUpdate1 () {
        ConwayCell c(true);
        c.setUpdate(true);
        CPPUNIT_ASSERT(c.wantUpdate());}
    
    void testSetUpdate2 () {
        FredkinCell c(false, 0);
        c.setUpdate(true);
        CPPUNIT_ASSERT(c.wantUpdate());}
    
    void testSetUpdate3 () {
        Cell c(new FredkinCell(true, 0));
        c.setUpdate(false);
        CPPUNIT_ASSERT(!(c.wantUpdate()));}
    
    // ---------
    // age
    // ---------
    void testAge1 () {
        ConwayCell c(true);
        c.age();
        CPPUNIT_ASSERT(c.getAge() == 0);}
    
    void testAge2 () {
        FredkinCell c(false, 0);
        c.age();
        CPPUNIT_ASSERT(c.getAge() == 0);}
    
    void testAge3 () {
        Cell c(new FredkinCell(true, 0));
        c.age();
        CPPUNIT_ASSERT(c.getAge() == 1);}
    
    // ---------
    // getAge
    // ---------
    void testGetAge1 () {
        ConwayCell c(true);
        CPPUNIT_ASSERT(c.getAge() == 0);}
    
    void testGetAge2 () {
        FredkinCell c(false, 2);
        CPPUNIT_ASSERT(c.getAge() == 2);}
    
    void testGetAge3 () {
        Cell c(new FredkinCell(true, 0));
        c.age();
        c.age();
        CPPUNIT_ASSERT(c.getAge() == 2);}
    
    // ---------
    // change
    // ---------
    void testChange1 () {
        ConwayCell c(false);
        c.change();
        CPPUNIT_ASSERT(c.isAlive());}
    
    void testChange2 () {
        FredkinCell c(false, 0);
        c.change();
        CPPUNIT_ASSERT(c.isAlive());}
    
    void testChange3 () {
        Cell c(new FredkinCell(true, 0));
        c.change();
        CPPUNIT_ASSERT(!(c.isAlive()));}
    
    // ---------
    // needsChange
    // ---------
    void testNeedsChange1 () {
        std::vector<bool> n;
        n.push_back(false);
        n.push_back(true);
        n.push_back(false);
        n.push_back(false);
        n.push_back(false);
        n.push_back(false);
        n.push_back(false);
        n.push_back(false);
        ConwayCell c(true);
        CPPUNIT_ASSERT(c.needsChange(n));}
    
    void testNeedsChange2 () {
        std::vector<bool> n;
        n.push_back(false);
        n.push_back(true);
        n.push_back(false);
        n.push_back(false);
        n.push_back(false);
        n.push_back(false);
        n.push_back(false);
        n.push_back(false);
        FredkinCell c(false, 0);
        CPPUNIT_ASSERT(c.needsChange(n));}
    
    void testNeedsChange3 () {
        std::vector<bool> n;
        n.push_back(false);
        n.push_back(true);
        n.push_back(false);
        n.push_back(false);
        n.push_back(false);
        n.push_back(false);
        n.push_back(false);
        n.push_back(false);
        Cell c(new FredkinCell(true, 0));
        CPPUNIT_ASSERT(!(c.needsChange(n)));}
    
    // All other Life methods are inductively correct if needsChange is correct
    
    // ---------
    // Life::read
    // ---------
    void testRead1() {
        std::istringstream r ("1\n1\n*");
        Life<ConwayCell> life;
        life.read(r);
        CPPUNIT_ASSERT(life.world[1][1].isAlive());
    }
    
    void testRead2() {
        std::istringstream r ("1\n1\n0");
        Life<FredkinCell> life;
        life.read(r);
        CPPUNIT_ASSERT(life.world[1][1].isAlive());
    }
    
    void testRead3() {
        std::istringstream r ("1\n1\n-");
        Life<Cell> life;
        life.read(r);
        CPPUNIT_ASSERT(!(life.world[1][1].isAlive()));
    }


    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST(testIsAlive1);
    CPPUNIT_TEST(testIsAlive2);
    CPPUNIT_TEST(testIsAlive3);
    CPPUNIT_TEST(testWantUpdate1);
    CPPUNIT_TEST(testWantUpdate2);
    CPPUNIT_TEST(testWantUpdate3);
    CPPUNIT_TEST(testSetUpdate1);
    CPPUNIT_TEST(testSetUpdate2);
    CPPUNIT_TEST(testSetUpdate3);
    CPPUNIT_TEST(testAge1);
    CPPUNIT_TEST(testAge2);
    CPPUNIT_TEST(testAge3);
    CPPUNIT_TEST(testGetAge1);
    CPPUNIT_TEST(testGetAge2);
    CPPUNIT_TEST(testGetAge3);
    CPPUNIT_TEST(testChange1);
    CPPUNIT_TEST(testChange2);
    CPPUNIT_TEST(testChange3);
    CPPUNIT_TEST(testNeedsChange1);
    CPPUNIT_TEST(testNeedsChange2);
    CPPUNIT_TEST(testNeedsChange3);
    CPPUNIT_TEST(testRead1);
    CPPUNIT_TEST(testRead2);
    CPPUNIT_TEST(testRead3);
    CPPUNIT_TEST_SUITE_END();
};


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
