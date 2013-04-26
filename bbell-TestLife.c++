#include <algorithm> // count
#include <iostream> // ios_base
#include <memory> // allocator

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TestRunner

#define private public
#define protected public
#define class struct

#include "Life.h"
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Handle.h"

using namespace std;

// -------------
// TestLife
// -------------

struct TestLife : CppUnit::TestFixture {

//tests
	void ConwayLiveness1() {
		ConwayCell c;
		CPPUNIT_ASSERT(!c.isAlive());
	}
	void ConwayLiveness2() {
		ConwayCell c(false);
		CPPUNIT_ASSERT(!c.isAlive());
	}
	void ConwayLiveness3() {
		ConwayCell c(true);
		CPPUNIT_ASSERT(c.isAlive());
	}

	void FredkinLiveness1() {
		FredkinCell f;
		CPPUNIT_ASSERT(!f.isAlive());
	}
	void FredkinLiveness2() {
		FredkinCell f(false);
		CPPUNIT_ASSERT(!f.isAlive());
	}
	void FredkinLiveness3() {
		FredkinCell f(true);
		CPPUNIT_ASSERT(f.isAlive());
	}
	
	void CellLiveness1() {
		Cell f;
		CPPUNIT_ASSERT(!f.isAlive());
	}
	void CellLiveness2() {
		Cell f(new FredkinCell(false));
		CPPUNIT_ASSERT(!f.isAlive());
	}
	void CellLiveness3() {
		Cell f(new FredkinCell(true));
		CPPUNIT_ASSERT(f.isAlive());
	}

	void NeighCount1() {
		ConwayCell c;
		c.updateCount();
		CPPUNIT_ASSERT(c.numNeighbors() == 1);
		c.updateCount();
		CPPUNIT_ASSERT(c.numNeighbors() == 2);
	}
	void NeighCount2() {
		FredkinCell c(true);
		c.updateCount();
		CPPUNIT_ASSERT(c.numNeighbors() == 1);
		c.updateCount();
		CPPUNIT_ASSERT(c.numNeighbors() == 2);
	}
	void NeighCount3() {
		Cell c(new ConwayCell(false));
		c.updateCount();
		CPPUNIT_ASSERT(c.numNeighbors() == 1);
		c.updateCount();
		CPPUNIT_ASSERT(c.numNeighbors() == 2);
	}
	
	void ageTest1() {
		FredkinCell f(true);
		f.age = 4;
		CPPUNIT_ASSERT(f.getAge() == 4);
	}
	void ageTest2() {
		Cell f(new ConwayCell(true));
		CPPUNIT_ASSERT(f.getAge() == -1);
	}
	void ageTest3() {
		Cell f(new FredkinCell(false));
		CPPUNIT_ASSERT(f.getAge() == 0);
	}
	void testClone1() {
		ConwayCell* c = new ConwayCell(true);	
		(*c).aliveNeighbors = 2;
		ConwayCell* d = c->clone();
		CPPUNIT_ASSERT((*c).age == (*d).age);
		CPPUNIT_ASSERT((*c).aliveNeighbors == (*d).aliveNeighbors);
		CPPUNIT_ASSERT((*c)._alive == (*d)._alive);
	}
	void testClone2() {
		FredkinCell* c = new FredkinCell(false);	
		(*c).aliveNeighbors = 4;
		(*c).age = 3;
		FredkinCell* d = c->clone();
		CPPUNIT_ASSERT((*c).age == (*d).age);
		CPPUNIT_ASSERT((*c).aliveNeighbors == (*d).aliveNeighbors);
		CPPUNIT_ASSERT((*c)._alive == (*d)._alive);
	}
	void testClone3() {
		Cell c = new ConwayCell(true);	
		c.updateCount();
		Cell d = c.clone();
		CPPUNIT_ASSERT(c.getAge()  == d.getAge());
		CPPUNIT_ASSERT(c.numNeighbors() == d.numNeighbors());
		CPPUNIT_ASSERT(c.isAlive() == d.isAlive());
	}
	
	void testWrite1() {
		ConwayCell c(true);
		ostringstream o;
		c.write(o);
		CPPUNIT_ASSERT(o.str() == "*");
	}
	void testWrite2() {
		FredkinCell c(true);
		c.age = 4;
		ostringstream o;
		c.write(o);
		CPPUNIT_ASSERT(o.str() == "4");
	}
	void testWrite3() {
		FredkinCell c(true);
		c.age = 11;
		ostringstream o;
		c.write(o);
		CPPUNIT_ASSERT(o.str() == "+");
	}

	void testUpdate1() {
		ConwayCell c;
		c.aliveNeighbors = 3;
		c.updateState();
		CPPUNIT_ASSERT(c._alive == true);
		CPPUNIT_ASSERT(c.aliveNeighbors == 0);
	}
	void testUpdate2() {
		FredkinCell c(true);
		c.aliveNeighbors = 2;
		c.updateState();
		CPPUNIT_ASSERT(c._alive == false);
		CPPUNIT_ASSERT(c.aliveNeighbors == 0);
		CPPUNIT_ASSERT(c.age == 0);
	}
	void testUpdate3() {
		FredkinCell c(true);
		c.aliveNeighbors = 3;
		c.updateState();
		CPPUNIT_ASSERT(c._alive == true);
		CPPUNIT_ASSERT(c.aliveNeighbors == 0);
		CPPUNIT_ASSERT(c.age == 1);
	}

	void testMutate1() {
		ConwayCell c;
		AbstractCell* d = c.mutate();
		CPPUNIT_ASSERT(d == NULL);
	}
	void testMutate2() {
		FredkinCell c;
		AbstractCell* d = c.mutate();
		CPPUNIT_ASSERT(d != NULL);
	}
	void testMutate3() {
		FredkinCell c;
		AbstractCell* d = c.mutate();
		CPPUNIT_ASSERT(d != NULL);
	}
	
	void testLife1() {
		Life<ConwayCell> l(3, 3, ConwayCell());
		CPPUNIT_ASSERT(l._row == 5);
		CPPUNIT_ASSERT(l._col == 5);
	}
	void testLife2() {
		Life<FredkinCell> l(4, 6, FredkinCell());
		CPPUNIT_ASSERT(l._row == 6);
		CPPUNIT_ASSERT(l._col == 8);
	}
	void testLife3() {
		Life<Cell> l(7, 8, new FredkinCell());
		CPPUNIT_ASSERT(l._row == 9);
		CPPUNIT_ASSERT(l._col == 10);
	}

	void testPlace1() {
		Life<ConwayCell> l(3,3, ConwayCell());
		ConwayCell c(true);
		ostringstream o;
		l.putConway(c, 2, 2);
		o << l.grid[2+1][2+1];
		CPPUNIT_ASSERT(o.str() == "*");
	}
	void testPlace2() {
		Life<FredkinCell> l(3,3, FredkinCell());
		FredkinCell c(true);
		ostringstream o;
		l.putFredkin(c, 2, 2);
		o << l.grid[2+1][2+1];
		CPPUNIT_ASSERT(o.str() == "0");
	}
	void testPlace3() {
		Life<Cell> l(3,3, Cell());
		ostringstream o;
		l.putCell(new FredkinCell(true), 2, 2);
		o << l.grid[2+1][2+1];
		CPPUNIT_ASSERT(o.str() == "0");
	}
	
	void testPop1() {
		Life<ConwayCell> l(3,3, ConwayCell());
		ConwayCell c(true);
		l.putConway(c, 2, 2);
		l.putConway(ConwayCell(true), 1, 1);
		CPPUNIT_ASSERT(l.population() == 2 );
	}
	void testPop2() {
		Life<FredkinCell> l(3,3, FredkinCell());
		FredkinCell c(true);
		l.putFredkin(c, 2, 2);
		l.putFredkin(FredkinCell(true), 1, 1);
		l.putFredkin(FredkinCell(true), 2, 1);
		CPPUNIT_ASSERT(l.population() == 3);
	}
	void testPop3() {
		Life<Cell> l(3,3, new FredkinCell());
		l.putCell(new FredkinCell(true), 1, 1);	
		l.putCell(new FredkinCell(true), 1, 2);	
		l.putCell(new FredkinCell(true), 2, 1);	
		l.putCell(new FredkinCell(true), 2, 2);	
		CPPUNIT_ASSERT(l.population() == 4);
	}

	void lifeWrite1() {
		Life<ConwayCell> l(3,3, ConwayCell());
		ConwayCell c(true);
		l.putConway(c, 2, 2);
		l.putConway(ConwayCell(true), 1, 1);
		ostringstream o;
		o << l;
		CPPUNIT_ASSERT(o.str() == "...\n.*.\n..*\n");
	}

	void lifeWrite2() {
		Life<FredkinCell> l(3,3, FredkinCell());
		FredkinCell c(true);
		l.putFredkin(c, 2, 2);
		l.putFredkin(FredkinCell(true), 1, 1);
		l.putFredkin(FredkinCell(true), 2, 1);
		ostringstream o;
		o << l;
		CPPUNIT_ASSERT(o.str() == "---\n-0-\n-00\n");
	}
	void lifeWrite3() {
		Life<Cell> l(3,3, new FredkinCell());
		l.putCell(new FredkinCell(true), 1, 1);	
		l.putCell(new FredkinCell(true), 1, 2);	
		l.putCell(new FredkinCell(true), 2, 1);	
		l.putCell(new FredkinCell(true), 2, 2);	
		ostringstream o;
		o << l;
		CPPUNIT_ASSERT(o.str() == "---\n-00\n-00\n");
	}

	void neighborUpdate1() {
		Life<ConwayCell> l(3,3, ConwayCell());
		l.putConway(ConwayCell(true), 0, 0);
		l.updateNeighbors(1, 1);
		CPPUNIT_ASSERT(l.grid[2][2].aliveNeighbors == 1);
		CPPUNIT_ASSERT(l.grid[1][2].aliveNeighbors == 1);
		CPPUNIT_ASSERT(l.grid[2][1].aliveNeighbors == 1);
	}
	void neighborUpdate2() {
		Life<ConwayCell> l(3,3, ConwayCell());
		l.putConway(ConwayCell(true), 1, 1);
		l.updateNeighbors(2, 2);
		CPPUNIT_ASSERT(l.grid[1][1].aliveNeighbors == 1);
		CPPUNIT_ASSERT(l.grid[1][2].aliveNeighbors == 1);
		CPPUNIT_ASSERT(l.grid[1][3].aliveNeighbors == 1);
		CPPUNIT_ASSERT(l.grid[2][1].aliveNeighbors == 1);
		CPPUNIT_ASSERT(l.grid[2][3].aliveNeighbors == 1);
		CPPUNIT_ASSERT(l.grid[3][1].aliveNeighbors == 1);
		CPPUNIT_ASSERT(l.grid[3][2].aliveNeighbors == 1);
		CPPUNIT_ASSERT(l.grid[3][3].aliveNeighbors == 1);
	}

	void neighborUpdate3() {
		Life<FredkinCell> l(3,3, FredkinCell());
		l.putFredkin(FredkinCell(true), 1, 1);
		l.updateNeighbors(2, 2);
		CPPUNIT_ASSERT(l.grid[1][1].aliveNeighbors == 0);
		CPPUNIT_ASSERT(l.grid[1][2].aliveNeighbors == 1);
		CPPUNIT_ASSERT(l.grid[1][3].aliveNeighbors == 0);
		CPPUNIT_ASSERT(l.grid[2][1].aliveNeighbors == 1);
		CPPUNIT_ASSERT(l.grid[2][3].aliveNeighbors == 1);
		CPPUNIT_ASSERT(l.grid[3][1].aliveNeighbors == 0);
		CPPUNIT_ASSERT(l.grid[3][2].aliveNeighbors == 1);
		CPPUNIT_ASSERT(l.grid[3][3].aliveNeighbors == 0);
	}

		


//test suit harness
CPPUNIT_TEST_SUITE(TestLife);

CPPUNIT_TEST(ConwayLiveness1);	
CPPUNIT_TEST(ConwayLiveness2);	
CPPUNIT_TEST(ConwayLiveness3);	
CPPUNIT_TEST(FredkinLiveness1);	
CPPUNIT_TEST(FredkinLiveness2);	
CPPUNIT_TEST(FredkinLiveness3);
CPPUNIT_TEST(CellLiveness1);
CPPUNIT_TEST(CellLiveness2);
CPPUNIT_TEST(CellLiveness3);
CPPUNIT_TEST(NeighCount1);
CPPUNIT_TEST(NeighCount2);
CPPUNIT_TEST(NeighCount3);
CPPUNIT_TEST(ageTest1);
CPPUNIT_TEST(ageTest2);
CPPUNIT_TEST(ageTest3);
CPPUNIT_TEST(testClone1);
CPPUNIT_TEST(testClone2);
CPPUNIT_TEST(testClone3);
CPPUNIT_TEST(testWrite1);
CPPUNIT_TEST(testWrite2);
CPPUNIT_TEST(testWrite3);
CPPUNIT_TEST(testUpdate1);
CPPUNIT_TEST(testUpdate2);
CPPUNIT_TEST(testUpdate3);
CPPUNIT_TEST(testMutate1);
CPPUNIT_TEST(testMutate2);
CPPUNIT_TEST(testMutate3);
CPPUNIT_TEST(testLife1);
CPPUNIT_TEST(testLife2);
CPPUNIT_TEST(testLife3);
CPPUNIT_TEST(testPlace1);
CPPUNIT_TEST(testPlace2);
CPPUNIT_TEST(testPlace3);
CPPUNIT_TEST(testPop1);
CPPUNIT_TEST(testPop2);
CPPUNIT_TEST(testPop3);
CPPUNIT_TEST(lifeWrite1);
CPPUNIT_TEST(lifeWrite2);
CPPUNIT_TEST(lifeWrite3);
CPPUNIT_TEST(neighborUpdate1);
CPPUNIT_TEST(neighborUpdate2);
CPPUNIT_TEST(neighborUpdate3);



CPPUNIT_TEST_SUITE_END();

};

int main () {
using namespace std;
ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
cout << "TestLife.c++" << endl;

CppUnit::TextTestRunner tr;

tr.addTest(TestLife::suite());

tr.run();

cout << "Done." << endl;
return 0;}
