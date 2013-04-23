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

void test_at1(){
  Grid<ConwayCell> g(5 , 5);
	ConwayCell c;
	pair<int, int> loc = make_pair(2, 3);
	c.wakeup();
	g.add(loc, c);
	CPPUNIT_ASSERT(g.at(loc)._isAlive);
}

void test_at2(){
	Grid<FredkinCell> g(5 , 5);
	FredkinCell c;
	pair<int, int> loc = make_pair(2, 3);
	c.wakeup();
	g.add(loc, c);
	CPPUNIT_ASSERT(g.at(loc)._isAlive);
}

void test_at3(){
	Grid<Cell> g(5 , 5);
	FredkinCell * f = new FredkinCell();
	Cell c(f);
	pair<int, int> loc = make_pair(2, 3);
	g.add(loc, c);
	CPPUNIT_ASSERT(g.isOccupied(loc));
}

void test_add1(){
	Grid<ConwayCell> g(5 , 5);
	ConwayCell c;
	pair<int, int> loc = make_pair(2, 3);
	c.wakeup();
	g.add(loc, c);
	CPPUNIT_ASSERT(g.at(loc)._isAlive);
	CPPUNIT_ASSERT(g.isValid(loc));
	CPPUNIT_ASSERT(g.isOccupied(loc));
}

void test_add2(){
	Grid<FredkinCell> g(5 , 5);
	FredkinCell c;
	pair<int, int> loc = make_pair(2, 3);
	c.wakeup();
	g.add(loc, c);
	CPPUNIT_ASSERT(g.at(loc)._isAlive);
	CPPUNIT_ASSERT(g.isValid(loc));
	CPPUNIT_ASSERT(g.isOccupied(loc));
}

void test_add3(){
	Grid<Cell> g(5 , 5);
	FredkinCell * f = new FredkinCell();
	Cell c(f);
	pair<int, int> loc = make_pair(2, 3);
	g.add(loc, c);
	CPPUNIT_ASSERT(g.isValid(loc));
	CPPUNIT_ASSERT(g.isOccupied(loc));
}

void test_isValid1(){
	Grid<ConwayCell> g(5, 5);

	CPPUNIT_ASSERT(g.isValid(make_pair(4, 4)));
}	

void test_isValid2(){
	Grid<ConwayCell> g(1, 1);

	CPPUNIT_ASSERT(g.isValid(make_pair(0, 0)));
}

void test_isValid3(){
	Grid<ConwayCell> g(13, 13);

	CPPUNIT_ASSERT(!g.isValid(make_pair(13, 13)));
}

void test_isOccupied1(){
	Grid<ConwayCell> g(5 , 5);
	ConwayCell c;
	pair<int, int> loc = make_pair(2, 3);
	g.add(loc, c);
	CPPUNIT_ASSERT(g.isValid(loc));
	CPPUNIT_ASSERT(g.isOccupied(loc));
}

void test_isOccupied2(){
	Grid<ConwayCell> g(5 , 5);
	ConwayCell c;
	pair<int, int> loc = make_pair(2, 3);
	CPPUNIT_ASSERT(g.isValid(loc));
	CPPUNIT_ASSERT(!g.isOccupied(loc));
}

void test_isOccupied3(){
	Grid<ConwayCell> g(5 , 5);
	ConwayCell c;
	pair<int, int> loc = make_pair(2, 3);
	g.occupy(loc);
	CPPUNIT_ASSERT(g.isValid(loc));
	CPPUNIT_ASSERT(g.isOccupied(loc));
}

void test_vacate1(){
	Grid<ConwayCell> g(5, 5);
	ConwayCell c;
	pair<int, int> loc = make_pair(2, 3);
	g.add(loc, c);

	CPPUNIT_ASSERT(g.isValid(loc));
	CPPUNIT_ASSERT(g.isOccupied(loc));

	g.vacate(loc);

	CPPUNIT_ASSERT(g.isValid(loc));
	CPPUNIT_ASSERT(!g.isOccupied(loc));
}

void test_vacate2(){
	Grid<ConwayCell> g(5, 5);
	pair<int, int> loc = make_pair(2, 3);
	g.occupy(loc);

	CPPUNIT_ASSERT(g.isValid(loc));
	CPPUNIT_ASSERT(g.isOccupied(loc));

	g.vacate(loc);

	CPPUNIT_ASSERT(g.isValid(loc));
	CPPUNIT_ASSERT(!g.isOccupied(loc));
}

void test_vacate3(){
	Grid<ConwayCell> g(5, 5);
	pair<int, int> loc = make_pair(2, 3);

	g.vacate(loc);

	CPPUNIT_ASSERT(g.isValid(loc));
	CPPUNIT_ASSERT(!g.isOccupied(loc));
}

void test_occupy1(){
	Grid<ConwayCell> g(5, 5);
	pair<int, int> loc = make_pair(2, 3);

	CPPUNIT_ASSERT(g.isValid(loc));
	CPPUNIT_ASSERT(!g.isOccupied(loc));

	g.occupy(loc);

	CPPUNIT_ASSERT(g.isValid(loc));
	CPPUNIT_ASSERT(g.isOccupied(loc));
}

void test_occupy2(){
	Grid<ConwayCell> g(5, 5);
	ConwayCell c;
	pair<int, int> loc = make_pair(2, 3);
	g.add(loc, c);

	CPPUNIT_ASSERT(g.isValid(loc));
	CPPUNIT_ASSERT(g.isOccupied(loc));
	
	g.vacate(loc);

	CPPUNIT_ASSERT(g.isValid(loc));
	CPPUNIT_ASSERT(!g.isOccupied(loc));

	g.occupy(loc);

	CPPUNIT_ASSERT(g.isValid(loc));
	CPPUNIT_ASSERT(g.isOccupied(loc));
}

void test_occupy3(){
	Grid<ConwayCell> g(5, 5);
	pair<int, int> loc = make_pair(2, 3);

	g.occupy(loc);

	CPPUNIT_ASSERT(g.isValid(loc));
	CPPUNIT_ASSERT(g.isOccupied(loc));

	pair<int, int> loc2 = make_pair(3, 4);

	CPPUNIT_ASSERT(g.isValid(loc2));
	CPPUNIT_ASSERT(!g.isOccupied(loc2));
}

void test_wakeup1(){
	ConwayCell c;

	CPPUNIT_ASSERT(c._name == '.');	

	c.wakeup();

	CPPUNIT_ASSERT(c._isAlive == true);
	CPPUNIT_ASSERT(c._name == '*');	
}

void test_wakeup2(){
	FredkinCell c;

	CPPUNIT_ASSERT(c._name == '-');	

	c.wakeup();

	CPPUNIT_ASSERT(c._isAlive == true);
	CPPUNIT_ASSERT(c._name == '0');	
}

void test_wakeup3(){
	FredkinCell * f = new FredkinCell();
	Cell c(f);

	CPPUNIT_ASSERT(c.printName() == '-');	

	c.wakeup();

	CPPUNIT_ASSERT(c.printName() == '0');
}

void test_mutate1(){
	ConwayCell c;
	c.wakeup();

	CPPUNIT_ASSERT(c.mutate() == false);
}

void test_mutate2(){
	FredkinCell * f = new FredkinCell();	
	Cell c(f);
	c.wakeup();

	CPPUNIT_ASSERT(c.mutate() == false);

	vector<bool> neighbors(8, false);
	neighbors[0] = true;
	c.prepareMove(neighbors);
	c.executeMove();
	c.prepareMove(neighbors);

	CPPUNIT_ASSERT(c.mutate() == true);
}

void test_mutate3(){
	FredkinCell * f = new FredkinCell();	
	Cell c(f);
	c.wakeup();

	CPPUNIT_ASSERT(c.mutate() == false);

	vector<bool> neighbors(8, false);
	neighbors[0] = true;
	neighbors[2] = true;
	c.prepareMove(neighbors);
	c.executeMove();
	c.prepareMove(neighbors);

	CPPUNIT_ASSERT(c.mutate() == false);
}

void test_clone1(){
	ConwayCell * c1;
	ConwayCell c2;
	c2.wakeup();
	c1 = c2.clone();
	CPPUNIT_ASSERT(c1->_name == '*');
	CPPUNIT_ASSERT(c1->_isAlive == true);
}

void test_clone2(){
	FredkinCell * c1;
	FredkinCell c2;
	c2.wakeup();
	c1 = c2.clone();
	CPPUNIT_ASSERT(c1->_name == '0');
	CPPUNIT_ASSERT(c1->_isAlive == true);
}

void test_clone3(){
	FredkinCell * c1;
	FredkinCell c2;
	c2.wakeup();
	c1 = c2.clone();
	CPPUNIT_ASSERT(c1->printName() == '0');
	CPPUNIT_ASSERT(c1->_isAlive == true);
}

void test_prepareMove1(){
	ConwayCell c;
	c.wakeup();

	vector<bool> neighbors(8, false);
	neighbors[1] = true;
	neighbors[3] = true;
	c.prepareMove(neighbors);

	CPPUNIT_ASSERT(c._willSurvive == true);
}

void test_prepareMove2(){
	ConwayCell c;
	c.wakeup();

	vector<bool> neighbors(8, false);
	neighbors[1] = true;
	neighbors[2] = true;
	neighbors[3] = true;
	c.prepareMove(neighbors);

	CPPUNIT_ASSERT(c._willSurvive == true);
}

void test_prepareMove3(){
	ConwayCell c;
	c.wakeup();

	vector<bool> neighbors(8, false);
	neighbors[1] = true;
	neighbors[2] = true;
	neighbors[3] = true;
	neighbors[4] = true;
	c.prepareMove(neighbors);

	CPPUNIT_ASSERT(c._willSurvive == false);
}

void test_prepareMove4(){
	ConwayCell c;
	c.wakeup();

	vector<bool> neighbors(8, false);
	neighbors[1] = true;
	c.prepareMove(neighbors);

	CPPUNIT_ASSERT(c._willSurvive == false);
}

void test_prepareMove5(){
	ConwayCell c;

	vector<bool> neighbors(8, false);
	neighbors[1] = true;
	neighbors[2] = true;
	c.prepareMove(neighbors);

	CPPUNIT_ASSERT(c._willSurvive == false);
}

void test_prepareMove6(){
	ConwayCell c;

	vector<bool> neighbors(8, false);
	neighbors[1] = true;
	neighbors[2] = true;
	neighbors[3] = true;
	c.prepareMove(neighbors);

	CPPUNIT_ASSERT(c._willSurvive == true);
}

void test_prepareMove7(){
	FredkinCell c;

	vector<bool> neighbors(8, false);
	neighbors[1] = true;
	neighbors[3] = true;
	neighbors[5] = true;
	c.prepareMove(neighbors);

	CPPUNIT_ASSERT(c._willSurvive == false);
}

void test_prepareMove8(){
	FredkinCell c;

	vector<bool> neighbors(8, false);
	neighbors[0] = true;
	neighbors[2] = true;
	neighbors[4] = true;
	c.prepareMove(neighbors);

	CPPUNIT_ASSERT(c._willSurvive == true);
}

void test_prepareMove9(){
	FredkinCell c;
	c.wakeup();

	vector<bool> neighbors(8, false);
	neighbors[0] = true;
	neighbors[2] = true;
	neighbors[4] = true;
	c.prepareMove(neighbors);

	CPPUNIT_ASSERT(c._willSurvive == true);
}


void test_prepareMove10(){
	FredkinCell c;
	c.wakeup();

	vector<bool> neighbors(8, false);
	neighbors[0] = true;
	c.prepareMove(neighbors);

	CPPUNIT_ASSERT(c._willSurvive == true);
}

void test_executeMove1(){
	ConwayCell c;

	vector<bool> neighbors(8, false);
	neighbors[1] = true;
	neighbors[2] = true;
	neighbors[3] = true;
	c.prepareMove(neighbors);

	CPPUNIT_ASSERT(c.executeMove() == true);
	CPPUNIT_ASSERT(c.printName() == '*');
}

void test_executeMove2(){
	FredkinCell c;

	vector<bool> neighbors(8, false);
	neighbors[1] = true;
	neighbors[3] = true;
	neighbors[5] = true;
	c.prepareMove(neighbors);

	CPPUNIT_ASSERT(c.executeMove() == false);
	CPPUNIT_ASSERT(c.printName() == '-');
}

void test_executeMove3(){
	FredkinCell c;

	vector<bool> neighbors(8, false);
	neighbors[0] = true;
	neighbors[2] = true;
	neighbors[4] = true;
	c.prepareMove(neighbors);

	CPPUNIT_ASSERT(c.executeMove() == true);
	CPPUNIT_ASSERT(c.printName() == '0');
}

void test_printName1(){
	ConwayCell c;
	CPPUNIT_ASSERT(c.printName() == '.');
}

void test_printName2(){
	FredkinCell c;
	CPPUNIT_ASSERT(c.printName() == '-');
}

void test_printName3(){
	ConwayCell c;
	c.wakeup();
	CPPUNIT_ASSERT(c.printName() == '*');
}

void test_printName4(){
	FredkinCell c;
	c.wakeup();
	CPPUNIT_ASSERT(c.printName() == '0');
}

void test_do_mutate1(){
	FredkinCell * f = new FredkinCell();
	Cell cell(f);
	CPPUNIT_ASSERT(cell.printName() == '-');
	cell.wakeup();
	CPPUNIT_ASSERT(cell.printName() == '0');
	cell.do_mutate();
	CPPUNIT_ASSERT(cell.printName() == '*');
}

void test_do_mutate2(){
	FredkinCell * f = new FredkinCell();
	Cell cell(f);
	CPPUNIT_ASSERT(cell.printName() == '-');
	cell.do_mutate();
	CPPUNIT_ASSERT(cell.printName() == '*');
}

void test_do_mutate3(){
	FredkinCell * f = new FredkinCell();
	Cell cell(f);
	cell.do_mutate();
	CPPUNIT_ASSERT(cell.printName() == '*');
	cell.executeMove();
	CPPUNIT_ASSERT(cell.printName() == '.');
}

void test_addCell1(){
	Life<ConwayCell> life(2, 2);
	ConwayCell c1;
	life.addCell(0, 0, c1, false);
	
	CPPUNIT_ASSERT(life._grid.isOccupied(make_pair(0, 0)) == false);

	ConwayCell c2;
	life.addCell(0, 1, c2, true);

	CPPUNIT_ASSERT(life._grid.isOccupied(make_pair(0, 1)));
}

void test_addCell2(){
	Life<FredkinCell> life(2, 2);
	FredkinCell c1;
	life.addCell(0, 0, c1, false);
	
	CPPUNIT_ASSERT(life._grid.isOccupied(make_pair(0, 0)) == false);

	FredkinCell c2;
	life.addCell(0, 1, c2, true);

	CPPUNIT_ASSERT(life._grid.isOccupied(make_pair(0, 1)));
}

void test_addCell3(){
	Life<Cell> life(2, 2);
	FredkinCell * f1 = new FredkinCell();
	Cell c1(f1);
	life.addCell(0, 0, c1, false);
	
	CPPUNIT_ASSERT(life._grid.isOccupied(make_pair(0, 0)) == false);

	FredkinCell * f2 = new FredkinCell();
	Cell c2(f2);
	life.addCell(0, 1, c2, true);

	CPPUNIT_ASSERT(life._grid.isOccupied(make_pair(0, 1)));
}

void test_processGeneration1(){
	Life<ConwayCell> life(2, 2);
	life.addCell(0, 0);
	life.addCell(0, 1);
	life.addCell(1, 1);
	life.addCell(1, 0);
	life.processGeneration();
	
	CPPUNIT_ASSERT(life._grid.at(make_pair(0,0))._isAlive == true);
	CPPUNIT_ASSERT(life._grid.at(make_pair(0,1))._isAlive == true);
	CPPUNIT_ASSERT(life._grid.at(make_pair(1,1))._isAlive == true);
	CPPUNIT_ASSERT(life._grid.at(make_pair(1,0))._isAlive == true);
}

void test_processGeneration2(){
	Life<ConwayCell> life(2, 2);
	life.addCell(0, 0);

	ConwayCell c1;
	life.addCell(0, 1, c1, false);
	life.addCell(1, 1);
	life.addCell(1, 0);
	life.processGeneration();
	
	CPPUNIT_ASSERT(life._grid.at(make_pair(0,0))._isAlive == true);
	CPPUNIT_ASSERT(life._grid.at(make_pair(0,1))._isAlive == true);
	CPPUNIT_ASSERT(life._grid.at(make_pair(1,1))._isAlive == true);
	CPPUNIT_ASSERT(life._grid.at(make_pair(1,0))._isAlive == true);
}

void test_processGeneration3(){
	Life<FredkinCell> life(2, 2);
	life.addCell(0, 0);

	FredkinCell c1;
	life.addCell(0, 1, c1, false);
	life.addCell(1, 1);
	life.addCell(1, 0);
	life.processGeneration();
	
	CPPUNIT_ASSERT(life._grid.at(make_pair(0,0)).printName() == '1');
	CPPUNIT_ASSERT(life._grid.at(make_pair(0,1)).printName() == '-');
	CPPUNIT_ASSERT(life._grid.at(make_pair(1,1)).printName() == '1');
	CPPUNIT_ASSERT(life._grid.at(make_pair(1,0)).printName() == '-');
}

void test_processGeneration4(){
	Life<Cell> life(2, 2);
	FredkinCell * f1 = new FredkinCell();
	Cell c1(f1);
	FredkinCell * f2 = new FredkinCell();
	Cell c2(f2);
	FredkinCell * f3 = new FredkinCell();
	Cell c3(f3);
	FredkinCell * f4 = new FredkinCell();
	Cell c4(f4);


	life.addCell(0, 0, c1, true);
	life.addCell(0, 1, c2, false);
	life.addCell(1, 1, c3, true);
	life.addCell(1, 0, c4, true);
	life.processGeneration();
	
	CPPUNIT_ASSERT(life._grid.at(make_pair(0,0)).printName() == '1');
	CPPUNIT_ASSERT(life._grid.at(make_pair(0,1)).printName() == '-');
	CPPUNIT_ASSERT(life._grid.at(make_pair(1,1)).printName() == '1');
	CPPUNIT_ASSERT(life._grid.at(make_pair(1,0)).printName() == '-');
}


// ---------
// TestSuite
// ---------

CPPUNIT_TEST_SUITE(TestLife);
CPPUNIT_TEST(test_at1);
CPPUNIT_TEST(test_at2);
CPPUNIT_TEST(test_at3);
CPPUNIT_TEST(test_at1);
CPPUNIT_TEST(test_isValid1);
CPPUNIT_TEST(test_isValid2);
CPPUNIT_TEST(test_isValid3);
CPPUNIT_TEST(test_isOccupied1);
CPPUNIT_TEST(test_isOccupied2);
CPPUNIT_TEST(test_isOccupied3);
CPPUNIT_TEST(test_vacate1);
CPPUNIT_TEST(test_vacate2);
CPPUNIT_TEST(test_vacate3);
CPPUNIT_TEST(test_occupy1);
CPPUNIT_TEST(test_occupy2);
CPPUNIT_TEST(test_occupy3);
CPPUNIT_TEST(test_wakeup1);
CPPUNIT_TEST(test_wakeup2);
CPPUNIT_TEST(test_wakeup3);
CPPUNIT_TEST(test_mutate1);
CPPUNIT_TEST(test_mutate2);
CPPUNIT_TEST(test_mutate3);
CPPUNIT_TEST(test_clone1);
CPPUNIT_TEST(test_clone2);
CPPUNIT_TEST(test_clone3);
CPPUNIT_TEST(test_prepareMove1);
CPPUNIT_TEST(test_prepareMove2);
CPPUNIT_TEST(test_prepareMove3);
CPPUNIT_TEST(test_prepareMove4);
CPPUNIT_TEST(test_prepareMove5);
CPPUNIT_TEST(test_prepareMove6);
CPPUNIT_TEST(test_prepareMove7);
CPPUNIT_TEST(test_prepareMove8);
CPPUNIT_TEST(test_prepareMove9);
CPPUNIT_TEST(test_prepareMove10);
CPPUNIT_TEST(test_executeMove1);
CPPUNIT_TEST(test_executeMove2);
CPPUNIT_TEST(test_executeMove3);
CPPUNIT_TEST(test_printName1);
CPPUNIT_TEST(test_printName2);
CPPUNIT_TEST(test_printName3);
CPPUNIT_TEST(test_printName4);
CPPUNIT_TEST(test_do_mutate1);
CPPUNIT_TEST(test_do_mutate2);
CPPUNIT_TEST(test_do_mutate3);
CPPUNIT_TEST(test_addCell1);
CPPUNIT_TEST(test_addCell2);
CPPUNIT_TEST(test_addCell3);
CPPUNIT_TEST(test_processGeneration1);
CPPUNIT_TEST(test_processGeneration2);
CPPUNIT_TEST(test_processGeneration3);
CPPUNIT_TEST(test_processGeneration4);
/*CPPUNIT_TEST();
CPPUNIT_TEST();
CPPUNIT_TEST();
CPPUNIT_TEST();
CPPUNIT_TEST();
CPPUNIT_TEST();
CPPUNIT_TEST();
CPPUNIT_TEST();
CPPUNIT_TEST();
CPPUNIT_TEST();
CPPUNIT_TEST();
CPPUNIT_TEST();
CPPUNIT_TEST();
CPPUNIT_TEST();
CPPUNIT_TEST();
CPPUNIT_TEST();
CPPUNIT_TEST();
CPPUNIT_TEST();
CPPUNIT_TEST();
CPPUNIT_TEST();
CPPUNIT_TEST();*/
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
