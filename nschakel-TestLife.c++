#include <algorithm> //count
#include <iostream> //ios_base
#include <memory> //allocator
#include <sstream> // string stream
#include <vector> //vector

#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TextTestRunner.h"

#define protected public
#define private public
#define class struct

#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Handle.h"
#include "Cell.h"
#include "Life.h"

struct TestLife : CppUnit::TestFixture
{
  //Conway
  

  //readyToEvolve()
  void testConwayReady()
  {
    ConwayCell c = false;
    c.getReadyToEvolve(3,0);
    CPPUNIT_ASSERT(c.nextState);
    c.getReadyToEvolve(2,0);
    CPPUNIT_ASSERT(!c.nextState);
  }

  void testConwayReady2()
  {
    ConwayCell c = true;
    c.getReadyToEvolve(1,0);
    CPPUNIT_ASSERT(c.nextState == false);
    c.getReadyToEvolve(1,3);
    CPPUNIT_ASSERT(c.nextState == false);
  }

  void testConwayReady3()
  {
    ConwayCell c = true;
    c.getReadyToEvolve(1,2);
    CPPUNIT_ASSERT(c.nextState == true);
    c.getReadyToEvolve(2,0);
    CPPUNIT_ASSERT(c.nextState == true);
  }

  void testConwayEvolve()
  {
    ConwayCell c = true;
    c.nextState = true;
    c.evolve();
    CPPUNIT_ASSERT(c.isAlive());
  }

  void testConwayEvolve2()
  {
    ConwayCell c = false;
    c.nextState = true;
    c.evolve();
    CPPUNIT_ASSERT(c.isAlive());
  }

  void testConwayEvolve3()
  {
    ConwayCell c = false;
    c.getReadyToEvolve(3,0);
    AbstractCell* p = c.evolve();
    CPPUNIT_ASSERT(c.isAlive());
    CPPUNIT_ASSERT(&c == p);
  }

  void testConwayToString()
  {
    ConwayCell c = false;
    CPPUNIT_ASSERT(c.toString().compare(".") == 0);
    c.alive = true;
    CPPUNIT_ASSERT(c.toString().compare("*") == 0);
  }

  void testFredkinReady()
  {
    FredkinCell c = false;
    c.getReadyToEvolve(1,2);
    CPPUNIT_ASSERT(c.nextState);
    c.alive = false;
    c.getReadyToEvolve(2,2);
    CPPUNIT_ASSERT(!c.nextState);
  }

  void testFredkinReady2()
  {
    FredkinCell c = true;
    c.getReadyToEvolve(0,4);
    CPPUNIT_ASSERT(!c.nextState);
  }

  void testFredkinReady3()
  {
    FredkinCell c = true;
    c.getReadyToEvolve(1,3);
    CPPUNIT_ASSERT(c.nextState);
  }

  void testFredkinEvolve()
  {
    FredkinCell c = false;
    c.getReadyToEvolve(1,2);
    AbstractCell* p = c.evolve();
    CPPUNIT_ASSERT(c.alive);
    CPPUNIT_ASSERT(c.age == 0);
    CPPUNIT_ASSERT(p == &c);
  }

  void testFredkinEvolve2()
  {
    FredkinCell c = true;
    c.getReadyToEvolve(1,3);
    AbstractCell* p = c.evolve();
    CPPUNIT_ASSERT(c.alive);
    CPPUNIT_ASSERT(c.age == 1);
    CPPUNIT_ASSERT(p == &c);
    c.getReadyToEvolve(1,3);
    p = c.evolve();
    CPPUNIT_ASSERT(c.alive);
    CPPUNIT_ASSERT(c.age == 2);
    CPPUNIT_ASSERT(p == &c);
    CPPUNIT_ASSERT(!(dynamic_cast<ConwayCell*> (p)));

  }

  void testFredkinEvolve3()
  {
    FredkinCell c = true;
    c.getReadyToEvolve(1,3);
    c.evolve();
    c.getReadyToEvolve(1,3);
    AbstractCell* p = c.evolve(true);
    CPPUNIT_ASSERT(c.alive);
    CPPUNIT_ASSERT(p != &c);
    CPPUNIT_ASSERT(dynamic_cast<ConwayCell*> (p));
  }

  void testHandle()
  {
    ConwayCell* a = new ConwayCell(false);
    Cell c = a;
    c.getReadyToEvolve(3,0);
    CPPUNIT_ASSERT(!c.isAlive());
    c.evolve();
    CPPUNIT_ASSERT(c.isAlive());
    
  }

  void testHandle2()
  {
    using namespace std;
    ConwayCell* a = new ConwayCell(true);
    vector<Cell> x(2,a);
    CPPUNIT_ASSERT(x[0]._p != x[1]._p);
  }

  void testHandle3()
  {
    FredkinCell* f = new FredkinCell(true,1);
    Cell c = f;
    c.getReadyToEvolve(3,0);
    c.evolve();
    CPPUNIT_ASSERT(c.isAlive());
    CPPUNIT_ASSERT(c.get() != dynamic_cast<AbstractCell*>(f));
    CPPUNIT_ASSERT(dynamic_cast<ConwayCell*> (c.get()));
    CPPUNIT_ASSERT(!(dynamic_cast<FredkinCell*>(c.get())));
    CPPUNIT_ASSERT(c.isAlive());
  }

  void testLifeConstructor()
  {
    ConwayCell c(true);
    Life<ConwayCell> l(2,2,c);
    l.board[0][0].alive = false;
    l.board[1][1].alive = false;
    CPPUNIT_ASSERT(!l.board[0][0].alive);
    CPPUNIT_ASSERT(l.board[0][1].alive);
    CPPUNIT_ASSERT(l.board[1][0].alive);
    CPPUNIT_ASSERT(!l.board[1][1].alive);
  }

  void testPopulation()
  {
    ConwayCell c(true);
    Life<ConwayCell> l(2,2,c);
    CPPUNIT_ASSERT(l.board[0][0].alive);
    CPPUNIT_ASSERT(l.board[0][1].alive);
    CPPUNIT_ASSERT(l.board[1][0].alive);
    CPPUNIT_ASSERT(l.board[1][1].alive);
    CPPUNIT_ASSERT(l.getPopulation() == 4);
  }

  void testPopulation2()
  {
    FredkinCell c(false);
    Life<FredkinCell> l(2,2,c);
    l.board[0][0].alive = true;
    CPPUNIT_ASSERT(l.getPopulation() == 1);
  }

  void testPopulation3()
  {
    Cell c = new FredkinCell(true);
    Life<Cell> l(4,3,c);
    CPPUNIT_ASSERT(l.getPopulation() == 12);
  }

  void testNeighbors()
  {
    Cell c = new FredkinCell(true);
    Life<Cell> l(3,3,c);
    CPPUNIT_ASSERT(l.getStraightLiveNeighbors(1,1) == 4);
    CPPUNIT_ASSERT(l.getDiagonalLiveNeighbors(1,1) == 4);
  }

  void testNeighbors2()
  {
    ConwayCell c(true);
    Life<ConwayCell> l(3,3,c);
    l.board[0][0].alive = false;
    l.board[0][1].alive = false;
    CPPUNIT_ASSERT(l.getStraightLiveNeighbors(1,1) == 3);
    CPPUNIT_ASSERT(l.getDiagonalLiveNeighbors(1,1) == 3);
  }

  void testNeighbors3()
  {
    FredkinCell c(true);
    Life<FredkinCell> l(2,2,c);
    CPPUNIT_ASSERT(l.getStraightLiveNeighbors(1,1) == 2);
    CPPUNIT_ASSERT(l.getDiagonalLiveNeighbors(1,1) == 1);
    CPPUNIT_ASSERT(l.getStraightLiveNeighbors(0,0) + l.getDiagonalLiveNeighbors(0,0) == 3);
   
  }

  void testMove()
  {
    ConwayCell c(true);
    Life<ConwayCell> l(2,2,c);
    l.move();

    CPPUNIT_ASSERT(l.board[0][0].alive);
    CPPUNIT_ASSERT(l.board[0][1].alive);
    CPPUNIT_ASSERT(l.board[1][0].alive);
    CPPUNIT_ASSERT(l.board[1][1].alive);

    CPPUNIT_ASSERT(l.getPopulation() == 4);
  }

  void testMove2()
  {
    FredkinCell c(false);
    Life<FredkinCell> l(2,2,c);
    l.board[0][0] = FredkinCell(true, 1);
    l.move();
    CPPUNIT_ASSERT(!l.board[0][0].alive);
    CPPUNIT_ASSERT(l.board[1][0].alive);
    CPPUNIT_ASSERT(l.board[0][1].alive);
    CPPUNIT_ASSERT(!l.board[1][1].alive);
    CPPUNIT_ASSERT(l.getPopulation() == 2);

    l.move();

    CPPUNIT_ASSERT(l.getPopulation() == 0);
    CPPUNIT_ASSERT(l.generation == 2);
  }

  void testMove3()
  {
    Cell c = new FredkinCell(true, 1);
    Life<Cell> l(20,20,c);
    l.move();
    CPPUNIT_ASSERT(l.board[1][0].isAlive());
    CPPUNIT_ASSERT(!l.board[0][0].isAlive());
    CPPUNIT_ASSERT(dynamic_cast<ConwayCell*> (l.board[1][0].get()));
    CPPUNIT_ASSERT(dynamic_cast<FredkinCell*> (l.board[0][0].get()));
  }

  void testToString()
  {
    using namespace std;
    ios_base::sync_with_stdio(false);
    stringstream s;
    s << endl;
    s << "Generation = 0, Population = 1." << endl;
    s << "*." << endl;
    s << endl;

    ConwayCell c(true);
    Life<ConwayCell> l(2,1,c);
    l.board[1][0] = ConwayCell(false);
    CPPUNIT_ASSERT(l.width == 2);
    CPPUNIT_ASSERT(l.height == 1);

    CPPUNIT_ASSERT(s.str().compare(l.toString()) == 0);
  }

  void testToString2()
  {
    using namespace std;
    ios_base::sync_with_stdio(false);

    stringstream s;
    s << endl;
    s << "Generation = 0, Population = 2." << endl;
    s << "1+-" << endl;
    s << endl;

    FredkinCell c(true, 1);
    FredkinCell c1(true, 10);
    FredkinCell c2(false);
    Life<FredkinCell> l(3,1,c);
    l.board[1][0] = c1;
    l.board[2][0] = c2;

    CPPUNIT_ASSERT(l.board[0][0].age == 1);
    CPPUNIT_ASSERT(s.str().compare(l.toString()) == 0);
  }

  void testToString3()
  {
    using namespace std;
    ios_base::sync_with_stdio(false);

    stringstream s;
    s << endl;
    s << "Generation = 0, Population = 2." << endl;
    s << "*3" << endl;
    s << endl;

    Cell c0 = new ConwayCell(true);
    Cell c1 = new FredkinCell(true,3);
    Life<Cell> l(2,1,c0);
    l.board[1][0] = c1;

    CPPUNIT_ASSERT(s.str().compare(l.toString()) == 0);
  }

  void testFile()
  {
    Life<ConwayCell> l("RunLifeConway.in");
    CPPUNIT_ASSERT(l.getPopulation() == 35);
    CPPUNIT_ASSERT(l.board[34][34].isAlive());
    CPPUNIT_ASSERT(l.board[34][35].isAlive());
    CPPUNIT_ASSERT(l.board[34][36].isAlive());
    CPPUNIT_ASSERT(l.board[34][37].isAlive());
    CPPUNIT_ASSERT(l.height == 109);
    CPPUNIT_ASSERT(l.width == 69);
  }

  void testFile2()
  {
    Life<FredkinCell> l("RunLifeFredkin.in");
    CPPUNIT_ASSERT(l.getPopulation() == 4);
    CPPUNIT_ASSERT(l.board[9][9].isAlive());
    CPPUNIT_ASSERT(l.board[9][10].isAlive());
    CPPUNIT_ASSERT(l.board[10][9].isAlive());
    CPPUNIT_ASSERT(l.board[10][10].isAlive());
    CPPUNIT_ASSERT(l.width == 20);
    CPPUNIT_ASSERT(l.height == 20);
  }

  void testFile3()
  {
    Life<FredkinCell> l("RunLifeCell.in");
    CPPUNIT_ASSERT(l.getPopulation() == 6);
    CPPUNIT_ASSERT(l.board[9][9].isAlive());
    CPPUNIT_ASSERT(l.board[10][9].isAlive());
    CPPUNIT_ASSERT(l.board[8][10].isAlive());
    CPPUNIT_ASSERT(l.board[9][10].isAlive());
    CPPUNIT_ASSERT(l.board[10][10].isAlive());
    CPPUNIT_ASSERT(l.board[11][10].isAlive());
    CPPUNIT_ASSERT(l.width == 20);
    CPPUNIT_ASSERT(l.height == 20);
  }

  //suite
  CPPUNIT_TEST_SUITE(TestLife);
  CPPUNIT_TEST(testConwayReady);
  CPPUNIT_TEST(testConwayReady2);
  CPPUNIT_TEST(testConwayReady3);
  CPPUNIT_TEST(testConwayEvolve);
  CPPUNIT_TEST(testConwayEvolve2);
  CPPUNIT_TEST(testConwayEvolve3);
  CPPUNIT_TEST(testConwayToString);
  CPPUNIT_TEST(testFredkinReady);
  CPPUNIT_TEST(testFredkinReady2);
  CPPUNIT_TEST(testFredkinReady3);
  CPPUNIT_TEST(testFredkinEvolve);
  CPPUNIT_TEST(testFredkinEvolve2);
  CPPUNIT_TEST(testFredkinEvolve3);
  CPPUNIT_TEST(testHandle);
  CPPUNIT_TEST(testHandle2);
  CPPUNIT_TEST(testHandle3);
  CPPUNIT_TEST(testLifeConstructor);
  CPPUNIT_TEST(testPopulation);
  CPPUNIT_TEST(testPopulation2);
  CPPUNIT_TEST(testPopulation3);
  CPPUNIT_TEST(testNeighbors);
  CPPUNIT_TEST(testNeighbors2);
  CPPUNIT_TEST(testNeighbors3);
  CPPUNIT_TEST(testMove);
  CPPUNIT_TEST(testMove2);
  CPPUNIT_TEST(testMove3);
  CPPUNIT_TEST(testToString);
  CPPUNIT_TEST(testToString2);
  CPPUNIT_TEST(testToString3);
  CPPUNIT_TEST(testFile);
  CPPUNIT_TEST(testFile2);
  CPPUNIT_TEST(testFile3);
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
  return 0;}
