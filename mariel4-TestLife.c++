// -----------------------------
// projects/darwin/TestLife.c++
// Copyright (C) 2013
// Glenn P. Downing
// -----------------------------

// --------
// includes
// --------

#include <iostream>
#include <string>
#include <cassert>
#include <sstream> 
#include <vector>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner


#define private public
#define protected public
#define class struct

#include "Life.h"

struct TestLife : CppUnit::TestFixture {

// ---------
// Life tests
// ---------

	// AddCell
	void testAddCell1(){
		Life<ConwayCell> life = Life<ConwayCell>();
		life.AddCell(ConwayCell(true,0,'*'));
		assert(life.row.size() == 1);
	}

	void testAddCell2(){
		Life<FredkinCell> life = Life<FredkinCell>();
		life.AddCell(FredkinCell(true,0,'*'));
		assert(life.row.size() == 1);
	}
	void testAddCell3(){
		Life<Cell> life = Life<Cell>();
		life.AddCell(new FredkinCell(true,0,'*'));
		assert(life.row.size() == 1);
	}

	// AddRow
	void testAddRow1(){
		Life<ConwayCell> life = Life<ConwayCell>();
		life.AddCell(ConwayCell(true,0,'*'));
		life.AddRow();

		assert(life.map.size() == 1);
		assert(life.row.size() == 0);
	}
	void testAddRow2(){
		Life<FredkinCell> life = Life<FredkinCell>();
		life.AddCell(FredkinCell(true,0,'*'));
		life.AddRow();

		assert(life.map.size() == 1);
		assert(life.row.size() == 0);
	}
	void testAddRow3(){
		Life<Cell> life = Life<Cell>();
		life.AddCell(new FredkinCell(true,0,'*'));
		assert(life.row.size() == 1);
		life.AddRow();

		assert(life.map.size() == 1);
		assert(life.row.size() == 0);
	}

	// runBoard
	void testRunboard1(){
		Life<ConwayCell> life = Life<ConwayCell>();
		life.AddCell(ConwayCell(true,0,'*'));
		life.AddCell(ConwayCell(false,0,'.'));
		life.AddRow();
		life.AddCell(ConwayCell(false,0,'.'));
		life.AddCell(ConwayCell(false,0,'.'));
		life.AddRow();

		life.runBoard();
		assert(life.neighbors.size() == 2);
		assert(life.neighbors[0].size() == 2);
		assert(life.neighbors[0][0] == 0);
		assert(life.neighbors[0][1] == 1);
		assert(life.neighbors[1][0] == 1);
		assert(life.neighbors[1][1] == 1);
		
	}
	void testRunboard2(){
		Life<FredkinCell> life = Life<FredkinCell>();
		life.AddCell(FredkinCell(true,0,'0'));
		life.AddCell(FredkinCell(false,0,'-'));
		life.AddRow();
		life.AddCell(FredkinCell(false,0,'-'));
		life.AddCell(FredkinCell(false,0,'-'));
		life.AddRow();

		life.runBoard();
		assert(life.neighbors.size() == 2);
		assert(life.neighbors[0].size() == 2);
		assert(life.neighbors[0][0] == 0);
		assert(life.neighbors[0][1] == 1);
		assert(life.neighbors[1][0] == 1);
		assert(life.neighbors[1][1] == 0);
		
	}
	void testRunBoard3(){
		Life<Cell> life = Life<Cell>();
		life.AddCell(new FredkinCell(true,0,'0'));
		life.AddCell(new FredkinCell(false,0,'-'));
		life.AddRow();
		life.AddCell(new FredkinCell(false,0,'-'));
		life.AddCell(new FredkinCell(false,0,'-'));
		life.AddRow();

		life.runBoard();
		assert(life.neighbors.size() == 2);
		assert(life.neighbors[0].size() == 2);
		assert(life.neighbors[0][0] == 0);
		assert(life.neighbors[0][1] == 1);
		assert(life.neighbors[1][0] == 1);
		assert(life.neighbors[1][1] == 0);
	}

	// processGeneration
	void testProcessGeneration1(){
		Life<ConwayCell> life = Life<ConwayCell>();
		life.AddCell(ConwayCell(true,0,'*'));
		life.AddCell(ConwayCell(false,0,'.'));
		life.AddRow();
		life.AddCell(ConwayCell(false,0,'.'));
		life.AddCell(ConwayCell(false,0,'.'));
		life.AddRow();

		life.runBoard();
		life.processGeneration();

		assert(life.map[0][0].GetState() == false);
		assert(life.map[0][1].GetState() == false);
		assert(life.map[1][0].GetState() == false);
		assert(life.map[1][1].GetState() == false);
	}
	void testProcessGeneration2(){
		Life<FredkinCell> life = Life<FredkinCell>();
		life.AddCell(FredkinCell(true,0,'0'));
		life.AddCell(FredkinCell(false,0,'-'));
		life.AddRow();
		life.AddCell(FredkinCell(false,0,'-'));
		life.AddCell(FredkinCell(false,0,'-'));
		life.AddRow();

		life.runBoard();
		life.processGeneration();

		assert(life.map[0][0].GetState() == false);
		assert(life.map[0][1].GetState() == true);
		assert(life.map[1][0].GetState() == true);
		assert(life.map[1][1].GetState() == false);
	}
	void testProcessGeneration3(){
		Life<Cell> life = Life<Cell>();
		life.AddCell(new FredkinCell(true,0,'0'));
		life.AddCell(new FredkinCell(false,0,'-'));
		life.AddRow();
		life.AddCell(new FredkinCell(false,0,'-'));
		life.AddCell(new FredkinCell(false,0,'-'));
		life.AddRow();

		life.runBoard();
		life.processGeneration();

		assert(life.map[0][0].GetState() == false);
		assert(life.map[0][1].GetState() == true);
		assert(life.map[1][0].GetState() == true);
		assert(life.map[1][1].GetState() == false);
	}

	// printBoard
	void testPrintBoard1(){
		Life<ConwayCell> life = Life<ConwayCell>();
		life.AddCell(ConwayCell(true,0,'*'));
		life.AddCell(ConwayCell(false,0,'.'));
		life.AddRow();
		life.AddCell(ConwayCell(false,0,'.'));
		life.AddCell(ConwayCell(false,0,'.'));
		life.AddRow();

		life.runBoard();
		assert(life.neighbors.size() == 2);
		assert(life.neighbors[0].size() == 2);
		assert(life.neighbors[0][0] == 0);
		assert(life.neighbors[0][1] == 1);
		assert(life.neighbors[1][0] == 1);
		assert(life.neighbors[1][1] == 1);


		std::ostringstream w;
		life.printBoard(w, 0);

		assert(w.str() == "Generation = 0, Population = 1\n*.\n..\n\n");

	}
	void testPrintBoard2(){
		Life<FredkinCell> life = Life<FredkinCell>();
		life.AddCell(FredkinCell(true,0,'0'));
		life.AddCell(FredkinCell(false,0,'-'));
		life.AddRow();
		life.AddCell(FredkinCell(false,0,'-'));
		life.AddCell(FredkinCell(false,0,'-'));
		life.AddRow();

		life.runBoard();
		assert(life.neighbors.size() == 2);
		assert(life.neighbors[0].size() == 2);
		assert(life.neighbors[0][0] == 0);
		assert(life.neighbors[0][1] == 1);
		assert(life.neighbors[1][0] == 1);
		assert(life.neighbors[1][1] == 0);

		std::ostringstream w;
		life.printBoard(w, 0);

		assert(w.str() == "Generation = 0, Population = 1\n0-\n--\n\n");

	}
	void testPrintBoard3(){
		Life<Cell> life = Life<Cell>();
		life.AddCell(new FredkinCell(true,0,'0'));
		life.AddCell(new FredkinCell(false,0,'-'));
		life.AddRow();
		life.AddCell(new FredkinCell(false,0,'-'));
		life.AddCell(new FredkinCell(false,0,'-'));
		life.AddRow();

		life.runBoard();
		assert(life.neighbors.size() == 2);
		assert(life.neighbors[0].size() == 2);
		assert(life.neighbors[0][0] == 0);
		assert(life.neighbors[0][1] == 1);
		assert(life.neighbors[1][0] == 1);
		assert(life.neighbors[1][1] == 0);
	
		std::ostringstream w;
		life.printBoard(w, 0);

		assert(w.str() == "Generation = 0, Population = 1\n0-\n--\n\n");
	}

	// inbouds
	void testInBounds1(){
		Life<ConwayCell> life = Life<ConwayCell>();
		life.AddCell(ConwayCell(true,0,'*'));
		life.AddCell(ConwayCell(false,0,'.'));
		life.AddRow();
		life.AddCell(ConwayCell(false,0,'.'));
		life.AddCell(ConwayCell(false,0,'.'));
		life.AddRow();

		assert(life.inbounds(0,0) == true);
		assert(life.inbounds(0,1) == true);
		assert(life.inbounds(1,0) == true);
		assert(life.inbounds(1,1) == true);
		assert(life.inbounds(-1,-1) == false);
		assert(life.inbounds(2,2) == false);
	}
	void testInBounds2(){
	Life<FredkinCell> life = Life<FredkinCell>();
		life.AddCell(FredkinCell(true,0,'0'));
		life.AddCell(FredkinCell(false,0,'-'));
		life.AddRow();
		life.AddCell(FredkinCell(false,0,'-'));
		life.AddCell(FredkinCell(false,0,'-'));
		life.AddRow();
	
		assert(life.inbounds(0,0) == true);
		assert(life.inbounds(0,1) == true);
		assert(life.inbounds(1,0) == true);
		assert(life.inbounds(1,1) == true);
		assert(life.inbounds(-1,-1) == false);
		assert(life.inbounds(2,2) == false);
	}
	void testInBounds3(){
		Life<Cell> life = Life<Cell>();
		life.AddCell(new FredkinCell(true,0,'0'));
		life.AddCell(new FredkinCell(false,0,'-'));
		life.AddRow();
		life.AddCell(new FredkinCell(false,0,'-'));
		life.AddCell(new FredkinCell(false,0,'-'));
		life.AddRow();

		assert(life.inbounds(0,0) == true);
		assert(life.inbounds(0,1) == true);
		assert(life.inbounds(1,0) == true);
		assert(life.inbounds(1,1) == true);
		assert(life.inbounds(-1,-1) == false);
		assert(life.inbounds(2,2) == false);
	}

	// countNeighborsIfConway
	void testConwayNeighbors1(){
		Life<ConwayCell> life = Life<ConwayCell>();
		life.AddCell(ConwayCell(true,0,'*'));
		life.AddCell(ConwayCell(false,0,'.'));
		life.AddRow();
		life.AddCell(ConwayCell(false,0,'.'));
		life.AddCell(ConwayCell(false,0,'.'));
		life.AddRow();

		life.runBoard();
		assert(life.countNeighborsIfConway(0,0) == 0);
		assert(life.countNeighborsIfConway(0,1) == 1);
		assert(life.countNeighborsIfConway(1,0) == 1);
		assert(life.countNeighborsIfConway(1,1) == 1);
	}

	void testConwayNeighbors2(){
		Life<ConwayCell> life = Life<ConwayCell>();
		life.AddCell(ConwayCell(true,0,'*'));
		life.AddCell(ConwayCell(true,0,'*'));
		life.AddRow();
		life.AddCell(ConwayCell(false,0,'.'));
		life.AddCell(ConwayCell(false,0,'.'));
		life.AddRow();

		life.runBoard();
		assert(life.countNeighborsIfConway(0,0) == 1);
		assert(life.countNeighborsIfConway(0,1) == 1);
		assert(life.countNeighborsIfConway(1,0) == 2);
		assert(life.countNeighborsIfConway(1,1) == 2);
	}

	void testConwayNeighbors3(){
		Life<ConwayCell> life = Life<ConwayCell>();
		life.AddCell(ConwayCell(true,0,'*'));
		life.AddCell(ConwayCell(false,0,'.'));
		life.AddRow();
		life.AddCell(ConwayCell(false,0,'.'));
		life.AddCell(ConwayCell(true,0,'*'));
		life.AddRow();

		life.runBoard();
		assert(life.countNeighborsIfConway(0,0) == 1);
		assert(life.countNeighborsIfConway(0,1) == 2);
		assert(life.countNeighborsIfConway(1,0) == 2);
		assert(life.countNeighborsIfConway(1,1) == 1);

	}

	// countNeighborsIfFredkin
	void testFredkinNeighbors1(){
		Life<FredkinCell> life = Life<FredkinCell>();
		life.AddCell(FredkinCell(true,0,'0'));
		life.AddCell(FredkinCell(false,0,'-'));
		life.AddRow();
		life.AddCell(FredkinCell(false,0,'-'));
		life.AddCell(FredkinCell(true,0,'0'));
		life.AddRow();

		life.runBoard();
		assert(life.countNeighborsIfFredkin(0,0) == 0);
		assert(life.countNeighborsIfFredkin(0,1) == 2);
		assert(life.countNeighborsIfFredkin(1,0) == 2);
		assert(life.countNeighborsIfFredkin(1,1) == 0);
	}
	void testFredkinNeighbors2(){
		Life<FredkinCell> life = Life<FredkinCell>();
		life.AddCell(FredkinCell(true,0,'0'));
		life.AddCell(FredkinCell(true,0,'0'));
		life.AddRow();
		life.AddCell(FredkinCell(false,0,'-'));
		life.AddCell(FredkinCell(false,0,'-'));
		life.AddRow();

		life.runBoard();
		assert(life.countNeighborsIfFredkin(0,0) == 1);
		assert(life.countNeighborsIfFredkin(0,1) == 1);
		assert(life.countNeighborsIfFredkin(1,0) == 1);
		assert(life.countNeighborsIfFredkin(1,1) == 1);
	}

	void testFredkinNeighbors3(){
		Life<FredkinCell> life = Life<FredkinCell>();
		life.AddCell(FredkinCell(true,0,'0'));
		life.AddCell(FredkinCell(false,0,'-'));
		life.AddRow();
		life.AddCell(FredkinCell(false,0,'-'));
		life.AddCell(FredkinCell(false,0,'-'));
		life.AddRow();

		life.runBoard();
		assert(life.countNeighborsIfFredkin(0,0) == 0);
		assert(life.countNeighborsIfFredkin(0,1) == 1);
		assert(life.countNeighborsIfFredkin(1,0) == 1);
		assert(life.countNeighborsIfFredkin(1,1) == 0);
	}

// ---------
// Conway Tests
// ---------

// changeState
void testConwayChangeState1(){
	ConwayCell c = ConwayCell(true, 0, '*');
	c.changeState(1);
	assert(c.GetState() == false);
}
void testConwayChangeState2(){
	ConwayCell c = ConwayCell(false, 0, '.');
	c.changeState(1);
	assert(c.GetState() == false);
}
void testConwayChangeState3(){
	ConwayCell c = ConwayCell(true, 0, '*');
	c.changeState(2);
	assert(c.GetState() == true);
}

// mutate will always return itself
void testConwayMutate1(){
	ConwayCell c = ConwayCell(true, 0, '*');
	ConwayCell* cp = c.mutate();

	assert(cp == &c);
}

// ShouldMutate will always return false
void testConwayShouldMutate1(){
	ConwayCell c = ConwayCell(true, 0, '*');
	assert(c.ShouldMutate() == false);
}

// clone
void testConwayClone1(){
	ConwayCell c = ConwayCell(true, 0, '*');
	ConwayCell* cp = c.clone();

	assert(cp != &c);
}


// ---------
// Fredkin Tests
// ---------

// changeState
void testFredkinChangeState1(){	
	FredkinCell f = FredkinCell(true, 0, '0');
	f.changeState(1);
	assert(f.GetState() == true);
}
void testFredkinChangeState2(){
	FredkinCell f = FredkinCell(false, 0, '0');
	f.changeState(2);
	assert(f.GetState() == false);
}
void testFredkinChangeState3(){
	FredkinCell f = FredkinCell(true, 0, '0');
	f.changeState(2);
	assert(f.GetState() == false);
}

// mutate always returns same thing
void testFredkinMutate1(){
	FredkinCell f = FredkinCell(true, 2, '0');
	ConwayCell* cp = f.mutate();

	assert(cp->GetState() == true);
}

// ShouldMutate
void testFredkinShouldMutate1(){
	//this test assumes this fredkin cell was made through Life<Cell>
	FredkinCell f = FredkinCell(true, 2, '0');
	assert(f.ShouldMutate() == true);
}
void testFredkinShouldMutate2(){
	FredkinCell f = FredkinCell(false, 2, '-');
	assert(f.ShouldMutate() == false);
}
void testFredkinShouldMutate3(){
	FredkinCell f = FredkinCell(true, 1, '0');
	assert(f.ShouldMutate() == false);
}

// clone
void testFredkinClone1(){
	FredkinCell f = FredkinCell(true, 0, '*');
	FredkinCell* fp = f.clone();

	assert(fp != &f);
}

// ---------
// Cell Tests
// ---------

// changeState
void testCellChangeState1(){	
	Cell f = Cell(new FredkinCell(true, 0, '0'));
	f.changeState(1);
	assert(f.GetState() == true);
}
void testCellChangeState2(){
	Cell f = Cell(new FredkinCell(false, 0, '0'));
	f.changeState(2);
	assert(f.GetState() == false);
}
void testCellChangeState3(){
	Cell f = Cell(new FredkinCell(true, 0, '0'));
	f.changeState(2);
	assert(f.GetState() == false);
}

// mutate always returns same thing
void testCellMutate1(){
	Cell f = Cell(new FredkinCell(true, 2, '0'));
	f.mutate();

	assert(f.GetValue() == '*');
}

// ShouldMutate
void testCellShouldMutate1(){
	//this test assumes this  cell was made through Life<Cell>
	Cell f = Cell(new FredkinCell(true, 2, '0'));
	assert(f.ShouldMutate() == true);
}
void testCellShouldMutate2(){
	Cell f = Cell(new FredkinCell(false, 2, '-'));
	assert(f.ShouldMutate() == false);
}
void testCellShouldMutate3(){
	Cell f = Cell(new FredkinCell(true, 1, '0'));
	assert(f.ShouldMutate() == false);
}



	CPPUNIT_TEST_SUITE(TestLife);
	CPPUNIT_TEST(testAddCell1);
	CPPUNIT_TEST(testAddCell2);
	CPPUNIT_TEST(testAddCell3);
	CPPUNIT_TEST(testAddRow1);
	CPPUNIT_TEST(testAddRow2);
	CPPUNIT_TEST(testAddRow3);
	CPPUNIT_TEST(testRunboard1);
	CPPUNIT_TEST(testRunboard2);
	CPPUNIT_TEST(testRunBoard3);
	CPPUNIT_TEST(testProcessGeneration1);
	CPPUNIT_TEST(testProcessGeneration2);
	CPPUNIT_TEST(testProcessGeneration3);
	CPPUNIT_TEST(testPrintBoard1);
	CPPUNIT_TEST(testPrintBoard2);
	CPPUNIT_TEST(testPrintBoard3);
	CPPUNIT_TEST(testInBounds1);
	CPPUNIT_TEST(testInBounds2);
	CPPUNIT_TEST(testInBounds3);
	CPPUNIT_TEST(testConwayNeighbors1);
	CPPUNIT_TEST(testConwayNeighbors2);
	CPPUNIT_TEST(testConwayNeighbors3);
	CPPUNIT_TEST(testFredkinNeighbors1);
	CPPUNIT_TEST(testFredkinNeighbors2);
	CPPUNIT_TEST(testFredkinNeighbors3);

	CPPUNIT_TEST(testConwayChangeState1);
	CPPUNIT_TEST(testConwayChangeState2);
	CPPUNIT_TEST(testConwayChangeState3);
	CPPUNIT_TEST(testConwayMutate1);
	CPPUNIT_TEST(testConwayShouldMutate1);
	CPPUNIT_TEST(testConwayClone1);

	
	CPPUNIT_TEST(testFredkinChangeState1);
	CPPUNIT_TEST(testFredkinChangeState2);
	CPPUNIT_TEST(testFredkinChangeState3);
	CPPUNIT_TEST(testFredkinClone1);
	CPPUNIT_TEST(testFredkinMutate1);
	CPPUNIT_TEST(testFredkinShouldMutate1);
	CPPUNIT_TEST(testFredkinShouldMutate2);
	CPPUNIT_TEST(testFredkinShouldMutate3);

	CPPUNIT_TEST(testCellChangeState1);
	CPPUNIT_TEST(testCellChangeState2);
	CPPUNIT_TEST(testCellChangeState3);
	CPPUNIT_TEST(testCellMutate1);
	CPPUNIT_TEST(testCellShouldMutate1);
	CPPUNIT_TEST(testCellShouldMutate2);
	CPPUNIT_TEST(testCellShouldMutate3);

	CPPUNIT_TEST_SUITE_END();
};

int main() {
	using namespace std;

	cout << "TestLife.c++" << endl;
	CppUnit::TextTestRunner tr;
	tr.addTest(TestLife::suite());
	tr.run();

	cout << "Done." << endl;
	return 0; }
