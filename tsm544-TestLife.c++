/**
 * A unit testing program for the Life project
 *
 * @author Taylor McKinney, tsm544
 */

#include <iostream>  // ios_base
#include <sstream>
#include <string>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define private public
#define protected public
#define class struct

#include "./AbstractCell.h"
#include "./Handle.h"
#include "./Cell.h"
#include "./FredkinCell.h"
#include "./ConwayCell.h"
#include "./Life.h"

struct TestAbstractCell : CppUnit::TestFixture {

  void testConstructor01 () {
    AbstractCell* c = new ConwayCell();

    CPPUNIT_ASSERT(!c->_isAlive);
    CPPUNIT_ASSERT(!c->_isGoingToLive);

    delete c;
  }

  void testConstructor02 () {
    AbstractCell* c = new ConwayCell(false);

    CPPUNIT_ASSERT(!c->_isAlive);
    CPPUNIT_ASSERT(!c->_isGoingToLive);

    delete c;
  }

  void testConstructor03 () {
    AbstractCell* c = new ConwayCell(true);

    CPPUNIT_ASSERT(c->_isAlive);
    CPPUNIT_ASSERT(c->_isGoingToLive);

    delete c;
  }

  void testBehave01 () {
    AbstractCell* c = new ConwayCell(false);
    c->_isGoingToLive = true;
    c->behave();

    CPPUNIT_ASSERT(c->_isAlive);

    delete c;
  }

  void testBehave02 () {
    AbstractCell* c = new ConwayCell(true);
    c->_isGoingToLive = false;
    c->behave();

    CPPUNIT_ASSERT(!c->_isAlive);

    delete c;
  }

  void testBehave03 () {
    AbstractCell* c = new ConwayCell(false);
    c->_isGoingToLive = false;
    c->behave();

    CPPUNIT_ASSERT(!c->_isAlive);

    delete c;
  }

  void testBehave04 () {
    AbstractCell* c = new ConwayCell(true);
    c->_isGoingToLive = true;
    c->behave();

    CPPUNIT_ASSERT(c->_isAlive);

    delete c;
  }

  void testMutate01 () {
    AbstractCell* c = new ConwayCell(true);

    CPPUNIT_ASSERT(c->_isAlive);
    CPPUNIT_ASSERT(c->_isGoingToLive);
    c->mutate();
    CPPUNIT_ASSERT(c->_isAlive);
    CPPUNIT_ASSERT(c->_isGoingToLive);

    delete c;
  }

  void testMutate02 () {
    AbstractCell* c = new ConwayCell(false);

    CPPUNIT_ASSERT(!c->_isAlive);
    CPPUNIT_ASSERT(!c->_isGoingToLive);
    c->mutate();
    CPPUNIT_ASSERT(!c->_isAlive);
    CPPUNIT_ASSERT(!c->_isGoingToLive);

    delete c;
  }

  void testShouldMutate01 () {
    AbstractCell* c = new ConwayCell(false);

    CPPUNIT_ASSERT(!c->shouldMutate());

    delete c;
  }

  void testShouldMutate02 () {
    AbstractCell* c = new ConwayCell(true);

    CPPUNIT_ASSERT(!c->shouldMutate());

    delete c;
  }

  CPPUNIT_TEST_SUITE(TestAbstractCell);

  CPPUNIT_TEST(testConstructor01);
  CPPUNIT_TEST(testConstructor02);
  CPPUNIT_TEST(testConstructor03);

  CPPUNIT_TEST(testBehave01);
  CPPUNIT_TEST(testBehave02);
  CPPUNIT_TEST(testBehave03);
  CPPUNIT_TEST(testBehave04);

  CPPUNIT_TEST(testMutate01);
  CPPUNIT_TEST(testMutate02);

  CPPUNIT_TEST(testShouldMutate01);
  CPPUNIT_TEST(testShouldMutate02);

  CPPUNIT_TEST_SUITE_END();
};

struct TestHandle : CppUnit::TestFixture {
  struct test {
      int filler;

      test* clone() {
        return new test(*this);
      }
  };

  void testConstructor01 () {
    test* t = new test();
    Handle<test> h = t;

    CPPUNIT_ASSERT(h._p == t);
  }

  void testConstructor02 () {
    test* t = new test();
    Handle<test> h1 = t;
    Handle<test> h2(h1);

    CPPUNIT_ASSERT(h1._p == t);
    CPPUNIT_ASSERT(h2._p != t);
  }

  void testCopy01 () {
    test* t = new test();
    Handle<test> h1 = t;
    Handle<test> h2 = h1;

    CPPUNIT_ASSERT(h1._p == t);
    CPPUNIT_ASSERT(h2._p != t);
  }

  CPPUNIT_TEST_SUITE(TestHandle);

  CPPUNIT_TEST(testConstructor01);
  CPPUNIT_TEST(testConstructor02);
  CPPUNIT_TEST(testCopy01);

  CPPUNIT_TEST_SUITE_END();
};

struct TestCell : CppUnit::TestFixture {
  void testConstructor01 () {
    Cell c = new ConwayCell();

    CPPUNIT_ASSERT(!c._p->_isAlive);
    CPPUNIT_ASSERT(!c._p->_isGoingToLive);
  }

  void testConstructor02 () {
    Cell c = new ConwayCell(false);

    CPPUNIT_ASSERT(!c._p->_isAlive);
    CPPUNIT_ASSERT(!c._p->_isGoingToLive);
  }

  void testConstructor03 () {
    Cell c = new ConwayCell(true);

    CPPUNIT_ASSERT(c._p->_isAlive);
    CPPUNIT_ASSERT(c._p->_isGoingToLive);
  }

  void testBehave01 () {
    Cell c = new ConwayCell(false);
    c._p->_isGoingToLive = true;
    c.behave();

    CPPUNIT_ASSERT(c._p->_isAlive);
  }

  void testBehave02 () {
    Cell c = new ConwayCell(true);
    c._p->_isGoingToLive = false;
    c.behave();

    CPPUNIT_ASSERT(!c._p->_isAlive);
  }

  void testBehave03 () {
    Cell c = new ConwayCell(false);
    c._p->_isGoingToLive = false;
    c.behave();

    CPPUNIT_ASSERT(!c._p->_isAlive);
  }

  void testBehave04 () {
    Cell c = new ConwayCell(true);
    c._p->_isGoingToLive = true;
    c.behave();

    CPPUNIT_ASSERT(c._p->_isAlive);
  }

  void testMutate01 () {
    Cell c = new ConwayCell(true);

    CPPUNIT_ASSERT(c._p->_isAlive);
    CPPUNIT_ASSERT(c._p->_isGoingToLive);
    c.mutate();
    CPPUNIT_ASSERT(c._p->_isAlive);
    CPPUNIT_ASSERT(c._p->_isGoingToLive);
  }

  void testMutate02 () {
    Cell c = new ConwayCell(false);

    CPPUNIT_ASSERT(!c._p->_isAlive);
    CPPUNIT_ASSERT(!c._p->_isGoingToLive);
    c.mutate();
    CPPUNIT_ASSERT(!c._p->_isAlive);
    CPPUNIT_ASSERT(!c._p->_isGoingToLive);
  }

  void testShouldMutate01 () {
    Cell c = new ConwayCell(false);

    CPPUNIT_ASSERT(!c.shouldMutate());
  }

  void testShouldMutate02 () {
    Cell c = new ConwayCell(true);

    CPPUNIT_ASSERT(!c.shouldMutate());
  }

  CPPUNIT_TEST_SUITE(TestCell);

  CPPUNIT_TEST(testConstructor01);
  CPPUNIT_TEST(testConstructor02);
  CPPUNIT_TEST(testConstructor03);

  CPPUNIT_TEST(testBehave01);
  CPPUNIT_TEST(testBehave02);
  CPPUNIT_TEST(testBehave03);
  CPPUNIT_TEST(testBehave04);

  CPPUNIT_TEST(testMutate01);
  CPPUNIT_TEST(testMutate02);

  CPPUNIT_TEST(testShouldMutate01);
  CPPUNIT_TEST(testShouldMutate02);

  CPPUNIT_TEST_SUITE_END();
};

struct TestConwayCell : CppUnit::TestFixture {
  void testConstructor02 () {
    ConwayCell c (false);

    CPPUNIT_ASSERT(!c._isAlive);
    CPPUNIT_ASSERT(!c._isGoingToLive);
  }

  void testConstructor03 () {
    ConwayCell c (true);

    CPPUNIT_ASSERT(c._isAlive);
    CPPUNIT_ASSERT(c._isGoingToLive);
  }

  void testBehave01 () {
    ConwayCell c (false);
    c._isGoingToLive = true;
    c.behave();

    CPPUNIT_ASSERT(c._isAlive);
  }

  void testBehave02 () {
    ConwayCell c (true);
    c._isGoingToLive = false;
    c.behave();

    CPPUNIT_ASSERT(!c._isAlive);
  }

  void testBehave03 () {
    ConwayCell c (false);
    c._isGoingToLive = false;
    c.behave();

    CPPUNIT_ASSERT(!c._isAlive);
  }

  void testBehave04 () {
    ConwayCell c (true);
    c._isGoingToLive = true;
    c.behave();

    CPPUNIT_ASSERT(c._isAlive);
  }

  void testMutate01 () {
    ConwayCell c (true);

    CPPUNIT_ASSERT(c._isAlive);
    CPPUNIT_ASSERT(c._isGoingToLive);
    c.mutate();
    CPPUNIT_ASSERT(c._isAlive);
    CPPUNIT_ASSERT(c._isGoingToLive);
  }

  void testMutate02 () {
    ConwayCell c (false);

    CPPUNIT_ASSERT(!c._isAlive);
    CPPUNIT_ASSERT(!c._isGoingToLive);
    c.mutate();
    CPPUNIT_ASSERT(!c._isAlive);
    CPPUNIT_ASSERT(!c._isGoingToLive);
  }

  void testShouldMutate01 () {
    ConwayCell c (false);

    CPPUNIT_ASSERT(!c.shouldMutate());
  }

  void testShouldMutate02 () {
    ConwayCell c (true);

    CPPUNIT_ASSERT(!c.shouldMutate());
  }

  CPPUNIT_TEST_SUITE(TestConwayCell);

  CPPUNIT_TEST(testConstructor02);
  CPPUNIT_TEST(testConstructor03);

  CPPUNIT_TEST(testBehave01);
  CPPUNIT_TEST(testBehave02);
  CPPUNIT_TEST(testBehave03);
  CPPUNIT_TEST(testBehave04);

  CPPUNIT_TEST(testMutate01);
  CPPUNIT_TEST(testMutate02);

  CPPUNIT_TEST(testShouldMutate01);
  CPPUNIT_TEST(testShouldMutate02);

  CPPUNIT_TEST_SUITE_END();
};

struct TestFredkinCell : CppUnit::TestFixture {
  void testConstructor02 () {
    FredkinCell c (false);

    CPPUNIT_ASSERT(!c._isAlive);
    CPPUNIT_ASSERT(!c._isGoingToLive);
  }

  void testConstructor03 () {
    FredkinCell c (true);

    CPPUNIT_ASSERT(c._isAlive);
    CPPUNIT_ASSERT(c._isGoingToLive);
  }

  void testBehave01 () {
    FredkinCell c (false);
    c._isGoingToLive = true;
    c.behave();

    CPPUNIT_ASSERT(c._isAlive);
  }

  void testBehave02 () {
    FredkinCell c (true);
    c._isGoingToLive = false;
    c.behave();

    CPPUNIT_ASSERT(!c._isAlive);
  }

  void testBehave03 () {
    FredkinCell c (false);
    c._isGoingToLive = false;
    c.behave();

    CPPUNIT_ASSERT(!c._isAlive);
  }

  void testBehave04 () {
    FredkinCell c (true);
    c._isGoingToLive = true;
    c.behave();

    CPPUNIT_ASSERT(c._isAlive);
  }

  void testMutate01 () {
    FredkinCell c (true);

    CPPUNIT_ASSERT(c._isAlive);
    CPPUNIT_ASSERT(c._isGoingToLive);
    c.mutate();
    CPPUNIT_ASSERT(c._isAlive);
    CPPUNIT_ASSERT(c._isGoingToLive);
  }

  void testMutate02 () {
    FredkinCell c (false);

    CPPUNIT_ASSERT(!c._isAlive);
    CPPUNIT_ASSERT(!c._isGoingToLive);
    c.mutate();
    CPPUNIT_ASSERT(!c._isAlive);
    CPPUNIT_ASSERT(!c._isGoingToLive);
  }

  void testShouldMutate01 () {
    FredkinCell c (false);

    CPPUNIT_ASSERT(!c.shouldMutate());
  }

  void testShouldMutate02 () {
    FredkinCell c (true);

    CPPUNIT_ASSERT(!c.shouldMutate());
  }

  void testShouldMutate03 () {
    FredkinCell c (false);

    c._age = 2;

    CPPUNIT_ASSERT(c.shouldMutate());
  }

  void testShouldMutate04 () {
    FredkinCell c (true);

    c._age = 2;

    CPPUNIT_ASSERT(c.shouldMutate());
  }

  CPPUNIT_TEST_SUITE(TestFredkinCell);

  CPPUNIT_TEST(testConstructor02);
  CPPUNIT_TEST(testConstructor03);

  CPPUNIT_TEST(testBehave01);
  CPPUNIT_TEST(testBehave02);
  CPPUNIT_TEST(testBehave03);
  CPPUNIT_TEST(testBehave04);

  CPPUNIT_TEST(testMutate01);
  CPPUNIT_TEST(testMutate02);

  CPPUNIT_TEST(testShouldMutate01);
  CPPUNIT_TEST(testShouldMutate02);
  CPPUNIT_TEST(testShouldMutate03);
  CPPUNIT_TEST(testShouldMutate04);

  CPPUNIT_TEST_SUITE_END();
};

struct TestLife : CppUnit::TestFixture {
  // TODO Tests

  void testConstructor01 () {
    Life<ConwayCell> c (1, 1);
    CPPUNIT_ASSERT(c.MAX_X == 1);
    CPPUNIT_ASSERT(c.MAX_Y == 1);
  }

  void testConstructor02 () {
    Life<ConwayCell> c (6, 6);
    CPPUNIT_ASSERT(c.MAX_X == 6);
    CPPUNIT_ASSERT(c.MAX_Y == 6);
  }

  void testGet01() {
    Life<ConwayCell> c (1, 1);
    c.get(0, 0) = ConwayCell(true);

    CPPUNIT_ASSERT(c._map[point(0, 0)]._isAlive);
  }

  void testGet02() {
    Life<ConwayCell> c (1, 1);
    c.get(0, 0) = ConwayCell(false);

    CPPUNIT_ASSERT(!c._map[point(0, 0)]._isAlive);
  }

  void testGet03() {
    Life<ConwayCell> c (6, 6);
    c.get(5, 5) = ConwayCell(true);

    CPPUNIT_ASSERT(c._map[point(5, 5)]._isAlive);
  }

  void testGet04() {
    Life<ConwayCell> c (6, 6);
    c.get(2, 3) = ConwayCell(true);

    CPPUNIT_ASSERT(c._map[point(2, 3)]._isAlive);
  }

  void testRunStep01 () {
    Life<ConwayCell> c (1, 1);
    c.get(0, 0) = ConwayCell(true);

    c.runStep();

    CPPUNIT_ASSERT(!c.get(0, 0)._isAlive);
  }

  void testRunStep02 () {
    Life<ConwayCell> c (5, 5);
    c.get(2, 1) = ConwayCell(true);
    c.get(2, 2) = ConwayCell(true);
    c.get(2, 3) = ConwayCell(true);

    c.runStep();
  }

  void testRunStep03 () {
    Life<ConwayCell> c (1, 1);
    c.get(0, 0) = ConwayCell(true);

    c.runStep();

    CPPUNIT_ASSERT(!c.get(0, 0)._isAlive);
  }

  void testPopulation01 () {
    Life<ConwayCell> c (1, 1);

    CPPUNIT_ASSERT(c.population() == 0);
  }

  void testPopulation02 () {
    Life<ConwayCell> c (2, 2);
    c.get(0, 0) = ConwayCell(true);

    CPPUNIT_ASSERT(c.population() == 1);
  }

  void testPopulation03 () {
    Life<ConwayCell> c (2, 2);
    c.get(0, 0) = ConwayCell(true);
    c.get(1, 1) = ConwayCell(true);

    CPPUNIT_ASSERT(c.population() == 2);
  }

  CPPUNIT_TEST_SUITE(TestLife);

  CPPUNIT_TEST(testConstructor01);
  CPPUNIT_TEST(testConstructor02);

  CPPUNIT_TEST(testGet01);
  CPPUNIT_TEST(testGet02);
  CPPUNIT_TEST(testGet03);
  CPPUNIT_TEST(testGet04);

  CPPUNIT_TEST(testRunStep01);
  CPPUNIT_TEST(testRunStep02);
  CPPUNIT_TEST(testRunStep03);

  CPPUNIT_TEST(testPopulation01);
  CPPUNIT_TEST(testPopulation02);
  CPPUNIT_TEST(testPopulation03);

  CPPUNIT_TEST_SUITE_END();
};


int main() {
  using namespace std;
  ios_base::sync_with_stdio(false);    // turn off synchronization with C I/O
  CppUnit::TextTestRunner tr;

  tr.addTest(TestAbstractCell::suite());
  tr.addTest(TestConwayCell::suite());
  tr.addTest(TestFredkinCell::suite());
  tr.addTest(TestHandle::suite());
  tr.addTest(TestCell::suite());
  tr.addTest(TestLife::suite());

  cout << "Running TestLife.c++" << endl;
  tr.run();
  return 0;
}
