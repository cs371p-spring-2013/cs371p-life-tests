/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -pedantic -std=c++0x -Wall Allocator.c++ TestAllocator.c++ -o TestAllocator -lcppunit -ldl
    % valgrind TestAllocator >& TestAllocator.out
*/

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include <fstream>
#include <vector>

#include <algorithm> // count
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define private public
#define protected public
#define class struct

#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

struct TestLife : CppUnit::TestFixture {
	
	// --------
	// Conway tests
	// --------
	
	void testCPrintSelf1(){
		ConwayCell c(0, 0, 0, true);
		CPPUNIT_ASSERT(c.printSelf() == '*');
	} 
	
	void testCPrintSelf2(){
		ConwayCell c(3, 5, 3, false);
		CPPUNIT_ASSERT(c.printSelf() == '.');
	}
	
	void testCPrintSelf3(){
		ConwayCell c(0, 0, 3, false);
		CPPUNIT_ASSERT(c.printSelf() == '.');
	}
	
	void testCClone1(){
		ConwayCell c(0, 0, 0, true);
		CPPUNIT_ASSERT(c.clone()->getRow() == 0);
		CPPUNIT_ASSERT(c.clone()->getCol() == 0);
		CPPUNIT_ASSERT(c.clone()->getAge() == -1);
		CPPUNIT_ASSERT(c.clone()->isAlive() == true);
	}
	
	void testCClone2(){
		ConwayCell c(0, 5, 12, false);
		CPPUNIT_ASSERT(c.clone()->getRow() == 0);
		CPPUNIT_ASSERT(c.clone()->getCol() == 5);
		CPPUNIT_ASSERT(c.clone()->getAge() == -1);
		CPPUNIT_ASSERT(c.clone()->isAlive() == false);
	}
	
	void testCClone3(){
		ConwayCell c(5, 5, 0, true);
		CPPUNIT_ASSERT(c.clone()->getRow() == 5);
		CPPUNIT_ASSERT(c.clone()->getCol() == 5);
		CPPUNIT_ASSERT(c.clone()->getAge() == -1);
		CPPUNIT_ASSERT(c.clone()->isAlive() == true);
	}
	
	void testCTakeTurn1(){
		ConwayCell c(0, 0, 3, false);
		c.takeTurn();
		CPPUNIT_ASSERT(c.clone()->getRow() == 0);
		CPPUNIT_ASSERT(c.clone()->getCol() == 0);
		CPPUNIT_ASSERT(c.clone()->getAge() == -1);
		CPPUNIT_ASSERT(c.clone()->isAlive() == true);
	}
	
	void testCTakeTurn2(){
		ConwayCell c(0, 0, 4, false);
		c.takeTurn();
		CPPUNIT_ASSERT(c.clone()->getRow() == 0);
		CPPUNIT_ASSERT(c.clone()->getCol() == 0);
		CPPUNIT_ASSERT(c.clone()->getAge() == -1);
		CPPUNIT_ASSERT(c.clone()->isAlive() == false);
	}
	
	void testCTakeTurn3(){
		ConwayCell c(0, 0, 1, true);
		c.takeTurn();
		CPPUNIT_ASSERT(c.clone()->getRow() == 0);
		CPPUNIT_ASSERT(c.clone()->getCol() == 0);
		CPPUNIT_ASSERT(c.clone()->getAge() == -1);
		CPPUNIT_ASSERT(c.clone()->isAlive() == false);
	}
	
	// --------
	// Fredkin tests
	// --------
	
	void testFPrintSelf1(){
		FredkinCell c(0, 0, 0, true, 0);
		CPPUNIT_ASSERT(c.printSelf() == '0');
	} 
	
	void testFPrintSelf2(){
		FredkinCell c(3, 5, 3, false, 3);
		CPPUNIT_ASSERT(c.printSelf() == '-');
	}
	
	void testFPrintSelf3(){
		FredkinCell c(0, 0, 3, true, 3);
		CPPUNIT_ASSERT(c.printSelf() == '3');
	}
	
	void testFClone1(){
		FredkinCell c(0, 0, 0, true, 4);
		CPPUNIT_ASSERT(c.clone()->getRow() == 0);
		CPPUNIT_ASSERT(c.clone()->getCol() == 0);
		CPPUNIT_ASSERT(c.clone()->getAge() == 4);
		CPPUNIT_ASSERT(c.clone()->isAlive() == true);
	}
	
	void testFClone2(){
		FredkinCell c(0, 5, 12, false, 1);
		CPPUNIT_ASSERT(c.clone()->getRow() == 0);
		CPPUNIT_ASSERT(c.clone()->getCol() == 5);
		CPPUNIT_ASSERT(c.clone()->getAge() == 1);
		CPPUNIT_ASSERT(c.clone()->isAlive() == false);
	}
	
	void testFClone3(){
		FredkinCell c(5, 5, 0, true, 0);
		CPPUNIT_ASSERT(c.clone()->getRow() == 5);
		CPPUNIT_ASSERT(c.clone()->getCol() == 5);
		CPPUNIT_ASSERT(c.clone()->getAge() == 0);
		CPPUNIT_ASSERT(c.clone()->isAlive() == true);
	}
	
	void testFTakeTurn1(){
		FredkinCell c(0, 0, 3, false, 0);
		c.takeTurn();
		CPPUNIT_ASSERT(c.clone()->getRow() == 0);
		CPPUNIT_ASSERT(c.clone()->getCol() == 0);
		CPPUNIT_ASSERT(c.clone()->getAge() == 0);
		CPPUNIT_ASSERT(c.clone()->isAlive() == true);
	}
	
	void testFTakeTurn2(){
		FredkinCell c(0, 0, 4, false, 0);
		c.takeTurn();
		CPPUNIT_ASSERT(c.clone()->getRow() == 0);
		CPPUNIT_ASSERT(c.clone()->getCol() == 0);
		CPPUNIT_ASSERT(c.clone()->getAge() == 0);
		CPPUNIT_ASSERT(c.clone()->isAlive() == false);
	}
	
	void testFTakeTurn3(){
		FredkinCell c(0, 0, 2, true, 0);
		c.takeTurn();
		CPPUNIT_ASSERT(c.clone()->getRow() == 0);
		CPPUNIT_ASSERT(c.clone()->getCol() == 0);
		CPPUNIT_ASSERT(c.clone()->getAge() == 0);
		CPPUNIT_ASSERT(c.clone()->isAlive() == false);
	}
	
	// --------
	// Cell tests
	// --------
	
	void testCellisAlive1(){
		Cell c(new FredkinCell(0, 0, 0, false, 0));
		CPPUNIT_ASSERT(c.getAge() == 0);
	}
	
	void testCellisAlive2(){
		Cell c(new ConwayCell(0, 9, 3, true));
		CPPUNIT_ASSERT(c.getAge() == -1);
	}
	
	void testCellisAlive3(){
		Cell c(new FredkinCell(0, 0, 2, true, 0));
		CPPUNIT_ASSERT(c.getAge() == 0);
	}
	
	void testCellPrintSelf1(){
		Cell c(new ConwayCell(0, 0, 0, true));
		CPPUNIT_ASSERT(c.printSelf() == '*');
	}
	
	void testCellPrintSelf2(){
		Cell c(new FredkinCell(2, 3, 0, false, 0));
		CPPUNIT_ASSERT(c.printSelf() == '-');
	}
	
	void testCellPrintSelf3(){
		Cell c(new ConwayCell(0, 0, 0, false));
		CPPUNIT_ASSERT(c.printSelf() == '.');
	}
	
	void testCellgetRow1(){
		Cell c(new ConwayCell(4, 0, 0, false));
		CPPUNIT_ASSERT(c.getRow() == 4);
	}
	
	void testCellgetRow2(){
		Cell c(new FredkinCell(3, 2, 0, false, 0));
		CPPUNIT_ASSERT(c.getRow() == 3);
	}
	
	void testCellgetRow3(){
		Cell c(new ConwayCell(7, 10, 0, false));
		CPPUNIT_ASSERT(c.getRow() == 7);
	}
	
	void testCellgetCol1(){
		Cell c(new ConwayCell(0, 4, 4, true));
		CPPUNIT_ASSERT(c.getCol() == 4);
	}
	
	void testCellgetCol2(){
		Cell c(new FredkinCell(0, 6, 4, true, 7));
		CPPUNIT_ASSERT(c.getCol() == 6);
	}
	
	void testCellgetCol3(){
		Cell c(new ConwayCell(0, 0, 4, true));
		CPPUNIT_ASSERT(c.getCol() == 0);
	}
	
	void testCellgetAge1(){
		Cell c(new ConwayCell(0, 4, 4, true));
		CPPUNIT_ASSERT(c.getAge() == -1);
	}
	
	void testCellgetAge2(){
		Cell c(new FredkinCell(0, 6, 4, true, 7));
		CPPUNIT_ASSERT(c.getAge() == 7);
	}
	
	void testCellgetAge3(){
		Cell c(new FredkinCell(0, 0, 4, true, 0));
		CPPUNIT_ASSERT(c.getAge() == 0);
	}
	
	void testCellTakeTurn1(){
		Cell c(new ConwayCell(3, 3, 1, true));
		c.takeTurn();
		CPPUNIT_ASSERT(c.isAlive() == false);
		CPPUNIT_ASSERT(c.getAge() == -1);
	}
	
	void testCellTakeTurn2(){
		Cell c(new FredkinCell(1, 1, 1, true, 2));
		c.takeTurn();
		CPPUNIT_ASSERT(c.isAlive() == true);
		CPPUNIT_ASSERT(c.getRow() == 1);
		CPPUNIT_ASSERT(c.getCol() == 1);
	}
	
	void testCellTakeTurn3(){
		Cell c(new ConwayCell(1, 1, 3, false));
		c.takeTurn();
		CPPUNIT_ASSERT(c.isAlive() == true);
		CPPUNIT_ASSERT(c.getRow() == 1);
		CPPUNIT_ASSERT(c.getCol() == 1);
	}
	
	void testCellUpdate1(){
		Cell c(new FredkinCell(2, 2, 0, true, 2));
		c.updateNeighbors(2);
		c.takeTurn();
		CPPUNIT_ASSERT(c.isAlive() == false);
	}
	
	void testCellUpdate2(){
		Cell c(new ConwayCell(1, 1, 0, true));
		c.updateNeighbors(1);
		c.takeTurn();
		CPPUNIT_ASSERT(c.isAlive() == false);
	}
	
	void testCellUpdate3(){
		Cell c(new ConwayCell(2, 2, 0, false));
		c.updateNeighbors(3);
		c.takeTurn();
		CPPUNIT_ASSERT(c.isAlive() == true);
	}
	
	void testCellMutate1(){
		Cell c(new FredkinCell(1, 1, 3, true, 2));
		c.mutate();
		CPPUNIT_ASSERT(c.isAlive() == true);
		CPPUNIT_ASSERT(c.getAge() == -1);
	}
	
	void testCellMutate2(){
		Cell c(new FredkinCell(3, 3, 2, false, 2));
		c.mutate();
		CPPUNIT_ASSERT(c.isAlive() == true);
		CPPUNIT_ASSERT(c.getAge() == -1);
	}
	
	void testCellMutate3(){
		Cell c(new FredkinCell(1, 4, 3, true, 2));
		c.mutate();
		CPPUNIT_ASSERT(c.isAlive() == true);
		CPPUNIT_ASSERT(c.getAge() == -1);
	}
	
	// -----
    // Life tests
    // -----
    
    void testLifeAddCell1(){
    	vector<ConwayCell> v;
    	Life<ConwayCell> l(4, 4, v);
    	for(int i = 0; i < 4; ++i)
    		for(int j = 0; j < 4; ++j){
    			ConwayCell temp(i, j, 0, true);
    			l.addCell(temp);
    		}
    	CPPUNIT_ASSERT(l._grid.size() == 16);
    }
    
    void testLifeAddCell2(){
    	vector<FredkinCell> v;
    	Life<FredkinCell> l(3, 3, v);
    	for(int i = 0; i < 3; ++i)
    		for(int j = 0; j < 3; ++j){
    			FredkinCell temp(i, j, 0 ,false, 0);
    			l.addCell(temp);
    		}
    	CPPUNIT_ASSERT(l._grid.size() == 9);
    }
    
    void testLifeAddCell3(){
    	vector<Cell> v;
    	Life<Cell> l(3, 3, v);
    	for(int i = 0; i < 3; ++i)
    		for(int j = 0; j < 3; ++j){
    			Cell temp(new ConwayCell(i, j, 0, true));
    			l.addCell(temp);
    		}
    	CPPUNIT_ASSERT(l._grid.size() == 9);
    }
    
    void testLifeProcessTurns1(){
    	vector<ConwayCell> v;
    	Life<ConwayCell> l(3, 3, v);
    	for(int i = 0; i < 3; ++i)
    		for(int j = 0; j < 3; ++j){
    			ConwayCell temp(i, j, 0, true);
    			l.addCell(temp);
    		}
    	l.update();
    	l.processTurns();
    	CPPUNIT_ASSERT(l._grid[0].isAlive() == true);
    	CPPUNIT_ASSERT(l._grid[1].isAlive() == false);
    }
    
    void testLifeProcessTurns2(){
    	vector<FredkinCell> v;
    	Life<FredkinCell> l(4, 4, v);
    	for(int i = 0; i < 4; ++i)
    		for(int j = 0; j < 4; ++j){
    			FredkinCell temp(i, j, 0, true, 0);
    			l.addCell(temp);
    		}
    	l.update();
    	l.processTurns();
    	CPPUNIT_ASSERT(l._grid[0].isAlive() == false);
    	CPPUNIT_ASSERT(l._grid[1].isAlive() == true);
    }
    
    void testLifeProcessTurns3(){
    	vector<Cell> v;
    	Life<Cell> l(4, 4, v);
    	for(int i = 0; i < 4; ++i)
    		for(int j = 0; j < 4; ++j){
    			Cell temp(new FredkinCell(i, j, 0, true, 0));
    			l.addCell(temp);
    		}
    	l.update();
    	l.processTurns();
    	CPPUNIT_ASSERT(l._grid[0].isAlive() == false);
    	CPPUNIT_ASSERT(l._grid[1].isAlive() == true);
    }
    
    void testLifeUpdate1(){
    	vector<ConwayCell> v;
    	Life<ConwayCell> l(1, 1, v);
    	ConwayCell temp(1, 1, 0, true);
    	l.addCell(temp);
    	l.update();
    	CPPUNIT_ASSERT(l._liveCells == 1);
    	CPPUNIT_ASSERT(l._grid[0].isAlive() == true);
    }
    
    void testLifeUpdate2(){
    	vector<FredkinCell> v;
    	Life<FredkinCell> l(2, 2, v);
    	for(int i = 0; i < 2; ++i)
    		for(int j = 0; j < 2; ++j){
    			FredkinCell temp(i, j, 0, false, 0);
    			l.addCell(temp);
    		}
    	l.update();
    	CPPUNIT_ASSERT(l._liveCells == 0);
    	CPPUNIT_ASSERT(l._grid[0]._liveNeighbors == 0);		
    }
    
    void testLifeUpdate3(){
    	vector<ConwayCell> v;
    	Life<ConwayCell> l(4, 4, v);
    	for(int i = 0; i < 4; ++i)
    		for(int j = 0; j < 4; ++j){
    			ConwayCell temp(i, j, 0, false);
    			l.addCell(temp);
    		}
    	l.update();
    	CPPUNIT_ASSERT(l._grid[0]._liveNeighbors == 0);
    	CPPUNIT_ASSERT(l._grid[1]._liveNeighbors == 0);
    }

	// -----
    // suite
    // -----

	CPPUNIT_TEST_SUITE(TestLife);
	//Conway
	CPPUNIT_TEST(testCPrintSelf1);
	CPPUNIT_TEST(testCPrintSelf2);
	CPPUNIT_TEST(testCPrintSelf3);
	CPPUNIT_TEST(testCClone1);
	CPPUNIT_TEST(testCClone2);
	CPPUNIT_TEST(testCClone3);
	CPPUNIT_TEST(testCTakeTurn3);
	CPPUNIT_TEST(testCTakeTurn1);
	CPPUNIT_TEST(testCTakeTurn2);
	//Fredkin
	CPPUNIT_TEST(testFPrintSelf1);
	CPPUNIT_TEST(testFPrintSelf2);
	CPPUNIT_TEST(testFPrintSelf3);
	CPPUNIT_TEST(testFClone1);
	CPPUNIT_TEST(testFClone2);
	CPPUNIT_TEST(testFClone3);
	CPPUNIT_TEST(testFTakeTurn3);
	CPPUNIT_TEST(testFTakeTurn1);
	CPPUNIT_TEST(testFTakeTurn2);
	//Cell
	CPPUNIT_TEST(testCellisAlive1);
	CPPUNIT_TEST(testCellisAlive2);
	CPPUNIT_TEST(testCellisAlive3);
	CPPUNIT_TEST(testCellPrintSelf1);
	CPPUNIT_TEST(testCellPrintSelf2);
	CPPUNIT_TEST(testCellPrintSelf3);
	CPPUNIT_TEST(testCellgetRow1);
	CPPUNIT_TEST(testCellgetRow2);
	CPPUNIT_TEST(testCellgetRow3);
	CPPUNIT_TEST(testCellgetCol1);
	CPPUNIT_TEST(testCellgetCol2);
	CPPUNIT_TEST(testCellgetCol3);
	CPPUNIT_TEST(testCellgetAge1);
	CPPUNIT_TEST(testCellgetAge2);
	CPPUNIT_TEST(testCellgetAge3);
	CPPUNIT_TEST(testCellTakeTurn1);
	CPPUNIT_TEST(testCellTakeTurn2);
	CPPUNIT_TEST(testCellTakeTurn3);
	CPPUNIT_TEST(testCellUpdate1);
	CPPUNIT_TEST(testCellUpdate2);
	CPPUNIT_TEST(testCellUpdate3);
	CPPUNIT_TEST(testCellMutate1);
	CPPUNIT_TEST(testCellMutate2);
	CPPUNIT_TEST(testCellMutate3);
	//Life
	CPPUNIT_TEST(testLifeAddCell1);
	CPPUNIT_TEST(testLifeAddCell2);
	CPPUNIT_TEST(testLifeAddCell3);
	CPPUNIT_TEST(testLifeProcessTurns1);
	CPPUNIT_TEST(testLifeProcessTurns2);
	CPPUNIT_TEST(testLifeProcessTurns3);
	CPPUNIT_TEST(testLifeUpdate1);
	CPPUNIT_TEST(testLifeUpdate2);
	CPPUNIT_TEST(testLifeUpdate3);
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
    return 0;
}


