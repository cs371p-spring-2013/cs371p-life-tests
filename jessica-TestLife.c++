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

// --------
// TestLife
// --------

struct TestLife : CppUnit::TestFixture {

	// Life::Conway::create
	
	void testConcreate1(){
		stringstream input;
		input << 2 << endl << 2 << endl;
		input << "*." << endl << "..";
		Life<ConwayCell> test;
		test.create(input);
		assert(test.grid.size() == 2);
		assert(test.grid[0].size() == 2);
		assert(test.grid[0][0].print() == '*');
	}

	// Life::Fredkin::create

	void testFredcreate1(){
		stringstream input;
		input << 3 << endl << 3 << endl;
		input << "-0-" << endl << "---" << endl << "-0-";
		Life<FredkinCell> test;
		test.create(input);
		assert(test.grid.size() == 3);
		assert(test.grid[0].size() == 3);
		assert(test.grid[0][0].print() == '-');
		assert(test.grid[0][1].print() == '0');
		assert(test.grid[1][1].print() == '-');
		assert(test.grid[2][1].print() == '0');
		assert(test.grid[2][2].print() == '-');
	}

	// Life::Cell::create

	void testCellcreate1(){
		stringstream input;
		input << 2 << endl << 2 << endl;
		input << "--" << endl << "--" << endl;;
		Life<Cell> test;
		test.create(input);
		assert(test.grid.size() == 2);
		assert(test.grid[0].size() == 2);
		assert(test.grid[0][0].get()->print() == '-');
		assert(test.grid[1][1].get()->print() == '-');
	}

	// Life::ConwayCell::printGrid

	void testConprintGrid1(){
		stringstream input;
		input << 2 << endl << 2 << endl;
		input << "*." << endl << "..";
		Life<ConwayCell> test;
		ostringstream out;
		test.create(input);
		test.printGrid(out);
		assert(out.str() == "\nGeneration = 0, Population = 1.\n*.\n..\n");

	}

	// Life::FredkinCell::printGrid

	void testFredprintGrid1(){
		stringstream input;
		input << 2 << endl << 2 << endl;
		input << "--" << endl << "-0";
		Life<FredkinCell> test;
		ostringstream out;
		test.create(input);
		test.printGrid(out);
		assert(out.str() == "\nGeneration = 0, Population = 1.\n--\n-0\n");

	}

	// // Life::Cell::printGrid

	void testCellprintGrid1(){
		stringstream input;
		input << 2 << endl << 2 << endl;
		input << "--" << endl << "-0";
		Life<Cell> test;
		ostringstream out;
		test.create(input);
		test.printGrid(out);
		assert(out.str() == "\nGeneration = 0, Population = 1.\n--\n-0\n");
	}

	// Life::Conway::getNeighbors

	void testCongetNeighbors1(){
		stringstream input;
		input << 2 << endl << 2 << endl;
		input << "*." << endl << ".*";
		Life<ConwayCell> test;
		test.create(input);
		test.getNeighbors();
		assert(test.grid[0][0].aliveNeighbors == 1);
		assert(test.grid[0][1].aliveNeighbors == 2);
		assert(test.grid[1][0].aliveNeighbors == 2);
		assert(test.grid[1][1].aliveNeighbors == 1);

	}

	// Life::Fredkin::getNeighbors

	void testFredgetNeighbors1(){
		stringstream input;
		input << 2 << endl << 2 << endl;
		input << "0-" << endl << "-0";
		Life<FredkinCell> test;
		test.create(input);
		test.getNeighbors();
		assert(test.grid[0][0].aliveNeighbors == 0);
		assert(test.grid[0][1].aliveNeighbors == 2);
		assert(test.grid[1][0].aliveNeighbors == 2);
		assert(test.grid[1][1].aliveNeighbors == 0);	}

	// Life::Cell::getNeighbors

	void testCellgetNeighbors1(){
		stringstream input;
		input << 2 << endl << 2 << endl;
		input << "0-" << endl << "-0";
		Life<Cell> test_c;
		test_c.create(input);
		test_c.getNeighbors();
		assert(test_c.grid[0][0].get()->getAliveNeighbors() == 0);
		assert(test_c.grid[0][1].get()->getAliveNeighbors() == 2);
		assert(test_c.grid[1][0].get()->getAliveNeighbors() == 2);
		assert(test_c.grid[1][1].get()->getAliveNeighbors() == 0);
	}

	// neighborHelpConway

	void testneighborHelpConway1(){
		stringstream input;
		input << 1 << endl << 1 << endl;
		input << "*";
		Life<ConwayCell> test;
		test.create(input);
		assert(test.neighborHelpConway(1, 1) == 0);
	}

	void testneighborHelpConway2(){
		stringstream input;
		input << 2 << endl << 2 << endl;
		input << "*." << endl << "..";
		Life<ConwayCell> test;
		test.create(input);
		assert(test.neighborHelpConway(0, 0) == 1);

	}


	void testneighborHelpConway3(){
		stringstream input;
		input << 3 << endl << 3 << endl;
		input << "***" << endl << "***" << endl << "...";
		Life<ConwayCell> test;
		test.create(input);
		assert(test.neighborHelpConway(0, 0) == 1);
		assert(test.neighborHelpConway(0, 1) == 1);
		assert(test.neighborHelpConway(0, 2) == 1);
		assert(test.neighborHelpConway(1, 0) == 1);
		assert(test.neighborHelpConway(1, 1) == 1);
		assert(test.neighborHelpConway(1, 2) == 1);
		assert(test.neighborHelpConway(2, 0) == 0);
		assert(test.neighborHelpConway(2, 1) == 0);
		assert(test.neighborHelpConway(2, 2) == 0);
	}
	
	// Life::neighborHelpFredkin

	void testneighborHelpFredkin1(){
		stringstream input;
		input << 1 << endl << 1 << endl;
		input << "0";
		Life<FredkinCell> test;
		test.create(input);
		assert(test.neighborHelpFredkin(1, 1) == 0);
	}
	
	void testneighborHelpFredkin2(){
		stringstream input;
		input << 2 << endl << 2 << endl;
		input << "0-" << endl << "--";
		Life<FredkinCell> test;
		test.create(input);
		assert(test.neighborHelpFredkin(0, 0) == 1);
	}
	
	void testneighborHelpFredkin3(){
		stringstream input;
		input << 3 << endl << 3 << endl;
		input << "000" << endl << "000" << endl << "---";
		Life<FredkinCell> test;
		test.create(input);
		assert(test.neighborHelpFredkin(0, 0) == 1);
		assert(test.neighborHelpFredkin(0, 1) == 1);
		assert(test.neighborHelpFredkin(0, 2) == 1);
		assert(test.neighborHelpFredkin(1, 0) == 1);
		assert(test.neighborHelpFredkin(1, 1) == 1);
		assert(test.neighborHelpFredkin(1, 2) == 1);
		assert(test.neighborHelpFredkin(2, 0) == 0);
		assert(test.neighborHelpFredkin(2, 1) == 0);
		assert(test.neighborHelpFredkin(2, 2) == 0);
	}
	
	// Life::Conway::updateGrid

	void testConupdateGrid1(){
		stringstream input;
		input << 3 << endl << 3 << endl;
		input << ".*." << endl << "**." << endl << "..*";
		Life<ConwayCell> test;
		test.create(input);
		test.getNeighbors();
		test.updateGrid();
		assert(test.grid[0][0].print() == '*');
		assert(test.grid[1][1].print() == '*');
		assert(test.grid[2][2].print() == '.');
	}

	// Life::Fredkin::updateGrid

	void testFredupdateGrid1(){
		stringstream input;
		input << 3 << endl << 3 << endl;
		input << "0-0" << endl << "-00" << endl << "-0-";
		Life<FredkinCell> test;
		test.create(input);
		test.getNeighbors();
		test.updateGrid();
		assert(test.grid[0][0].print() == '-');
		assert(test.grid[0][1].print() == '0');
		assert(test.grid[0][2].print() == '1');
		assert(test.grid[1][0].print() == '-');
		assert(test.grid[1][1].print() == '-');
		assert(test.grid[1][2].print() == '-');
		assert(test.grid[2][0].print() == '0');
		assert(test.grid[2][1].print() == '1');
		assert(test.grid[2][2].print() == '-');

	}

	// Life::Cell::updateGrid

	void testCellupdateGrid1(){
		stringstream input;
		input << 3 << endl << 3 << endl;
		input << "0-0" << endl << "-00" << endl << "-0-";
		Life<Cell> test;
		test.create(input);
		test.getNeighbors();
		test.updateGrid();
		assert(test.grid[0][0].print() == '-');
		assert(test.grid[0][1].print() == '0');
		assert(test.grid[0][2].print() == '1');
		assert(test.grid[1][0].print() == '-');
		assert(test.grid[1][1].print() == '-');
		assert(test.grid[1][2].print() == '-');
		assert(test.grid[2][0].print() == '0');
		assert(test.grid[2][1].print() == '1');
		assert(test.grid[2][2].print() == '-');

	}

	// Life::Conway::processTurn

	void testConprocessTurn1(){
		stringstream input;
		input << 3 << endl << 3 << endl;
		input << "***" << endl << "***" << endl << "...";
		Life<ConwayCell> test;
		test.create(input);
		test.getNeighbors();
		test.updateGrid();
		assert(test.grid[0][0].print() == '*');
		assert(test.grid[0][1].print() == '.');
		assert(test.grid[0][2].print() == '*');
		assert(test.grid[1][0].print() == '*');
		assert(test.grid[1][1].print() == '.');
		assert(test.grid[1][2].print() == '*');
		assert(test.grid[2][0].print() == '.');
		assert(test.grid[2][1].print() == '*');
		assert(test.grid[2][2].print() == '.');
	}

	// Life::Fredkin::processTurn

	void testFredprocessTurn1(){
		stringstream input;
		input << 3 << endl << 3 << endl;
		input << "000" << endl << "000" << endl << "---";
		Life<FredkinCell> test;
		test.create(input);
		test.getNeighbors();
		test.updateGrid();
		assert(test.grid[0][0].print() == '-');
		assert(test.grid[0][1].print() == '1');
		assert(test.grid[0][2].print() == '-');
		assert(test.grid[1][0].print() == '-');
		assert(test.grid[1][1].print() == '1');
		assert(test.grid[1][2].print() == '-');
		assert(test.grid[2][0].print() == '0');
		assert(test.grid[2][1].print() == '0');
		assert(test.grid[2][2].print() == '0');
	}

	// Life::Cell::processTurn

	void testCellprocessTurn1(){
		stringstream input;
		input << 3 << endl << 3 << endl;
		input << "0-0" << endl << "-00" << endl << "-0-";
		Life<FredkinCell> test;
		test.create(input);
		test.getNeighbors();
		test.updateGrid();
		assert(test.grid[0][0].print() == '-');
		assert(test.grid[0][1].print() == '0');
		assert(test.grid[0][2].print() == '1');
		assert(test.grid[1][0].print() == '-');
		assert(test.grid[1][1].print() == '-');
		assert(test.grid[1][2].print() == '-');
		assert(test.grid[2][0].print() == '0');
		assert(test.grid[2][1].print() == '1');
		assert(test.grid[2][2].print() == '-');
	}
	// Conway::constructor

	void testConway(){
		ConwayCell cell1;
		assert(cell1.symbol == '.');
		assert(cell1.isAlive == false);
		assert(cell1.maxNeighbors == 8);
		assert(cell1.aliveNeighbors == 0);
	}

	// Conway::evolve

	void testConevolve1(){
		ConwayCell cell2;
		cell2.aliveNeighbors = 3;
		cell2.evolve();
		assert(cell2.isAlive == true);
		assert(cell2.symbol == '*');
	}

	void testConevolve2(){
		ConwayCell cell3;
		cell3.aliveNeighbors = 1;
		cell3.isAlive = true;
		cell3.evolve();
		assert(cell3.symbol == '.');
		assert(cell3.isAlive == false);
		
	}

	void testConevolve3(){
		ConwayCell cell4;
		cell4.aliveNeighbors = 0;
		cell4.isAlive = false;
		cell4.evolve();
		assert(cell4.symbol == '.');
		assert(cell4.isAlive == false);
	}

	// Conway::print

	void testConprint1(){
		ConwayCell cell5;
		cell5.symbol = '*';
		assert(cell5.print() == '*');
	}

	void testConprint2(){
		ConwayCell cell5;
		cell5.symbol = '-';
		assert(cell5.print() == '-');
	}

	void testConprint3(){
		ConwayCell cell5;
		cell5.symbol = '*';
		cell5.isAlive = false;
		assert(cell5.print() == '*');
	}

	// Conway::setNeighbors

	void testConsetNeighbors1(){
		ConwayCell cell6;
		cell6.setNeighbors(10);
		assert(cell6.aliveNeighbors == 10);
	}

	void testConsetNeighbors2(){
		ConwayCell cell6;
		cell6.setNeighbors(-510);
		assert(cell6.aliveNeighbors == -510);
	}

	void testConsetNeighbors3(){
		ConwayCell cell6;
		cell6.setNeighbors(1);
		assert(cell6.aliveNeighbors == 1);
	}

	// Conway::clone

	void testConclone(){
		ConwayCell cell7;
		cell7.setNeighbors(5);
		ConwayCell cell8;
		cell8 = *cell7.clone();
		assert (cell7.aliveNeighbors == cell8.aliveNeighbors);
	}

	// Conway::changeStatus

	void testConchangeStatus1(){
		ConwayCell cell9;
		cell9.changeStatus(true);
		assert(cell9.isAlive == true);
		assert(cell9.symbol == '*');
	}

	void testConchangeStatus2(){
		ConwayCell cell10;
		cell10.isAlive = true;
		cell10.changeStatus(false);
		assert(cell10.isAlive == false);
		assert(cell10.symbol == '.');
	}

	void testConchangeStatus3(){
		ConwayCell cell11;
		cell11.changeStatus(true);
		assert(cell11.isAlive == true);
		assert(cell11.symbol == '*');
		cell11.changeStatus(false);
		assert(cell11.isAlive == false);
		assert(cell11.symbol == '.');
	}

	// Fredkin::constructor

	void testFredkin(){
		FredkinCell fcell1;
		assert(fcell1.symbol == '-');
		assert(fcell1.isAlive == false);
		assert(fcell1.maxNeighbors == 4);
		assert(fcell1.aliveNeighbors == 0);
	}

	// Fredkin::evolve

	void testFredevolve1(){
		FredkinCell fcell2;
		fcell2.isAlive = true;
		fcell2.aliveNeighbors = 2;
		fcell2.evolve();
		assert(fcell2.isAlive == false);
		assert(fcell2.symbol == '-');
	}

	void testFredevolve2(){
		FredkinCell fcell3;
		fcell3.aliveNeighbors = 1;
		fcell3.isAlive = false;
		fcell3.evolve();
		assert(fcell3.symbol == '0');
		assert(fcell3.isAlive == true);		
	}

	void testFredevolve3(){
		FredkinCell fcell4;
		fcell4.aliveNeighbors = 3;
		fcell4.isAlive = false;
		fcell4.evolve();
		assert(fcell4.symbol == '0');
		assert(fcell4.isAlive == true);	
	}

	// Fredkin::print

	void testFredprint1(){
		FredkinCell fcell5;
		fcell5.symbol = '-';
		assert(fcell5.print() == '-');
	}

	void testFredprint2(){
		FredkinCell cell6;
		cell6.symbol = '0';
		cell6.isAlive = true;
		assert(cell6.print() == '0');
	}

	void testFredprint3(){
		FredkinCell cell7;
		cell7.symbol = '-';
		cell7.isAlive = false;
		assert(cell7.print() == '-');
	}

	// Fredkin::setNeighbors

	void testFredsetNeighbors1(){
		FredkinCell cell8;
		cell8.setNeighbors(3);
		assert(cell8.aliveNeighbors == 3);
	}

	void testFredsetNeighbors2(){
		FredkinCell cell9;
		cell9.setNeighbors(21);
		assert(cell9.aliveNeighbors == 21);
	}

	void testFredsetNeighbors3(){
		FredkinCell cell10;
		cell10.setNeighbors(-1);
		assert(cell10.aliveNeighbors == -1);
		}

	// Fredkin::clone

	void testFredclone(){
		FredkinCell cell11;
		cell11.setNeighbors(5);
		FredkinCell cell12;
		cell12 = *cell11.clone();
		assert (cell11.aliveNeighbors == cell12.aliveNeighbors);
	}

	// Fredkin::changeStatus

	void testFredchangeStatus1(){
		FredkinCell cell13;
		cell13.isAlive = true;
		cell13.changeStatus(false);
		assert(cell13.isAlive == false);
	}

	void testFredchangeStatus2(){
		FredkinCell cell14;
		cell14.isAlive = false;
		cell14.changeStatus(false);
		assert(cell14.isAlive == false);
	}

	void testFredchangeStatus3(){
		FredkinCell cell14;
		cell14.isAlive = false;
		cell14.changeStatus(true);
		assert(cell14.isAlive == true);
	}

	// Cell::constructor

	void testCell(){
		Cell cell1;
		assert(cell1.get()->getSymbol() == '-');
		assert(cell1.get()->getIsAlive() == false);
		assert(cell1.get()->getMaxNeighbors() == 4);
		assert(cell1.get()->getAliveNeighbors() == 0);
	}

	// Cell::evolve

	void testCellevolve1(){
		Cell cell2;
		cell2.get()->getIsAlive() = true;
		cell2.get()->getAliveNeighbors() = 2;
		cell2.evolve();
		assert(cell2.get()->getIsAlive() == false);
		assert(cell2.get()->getSymbol() == '-');
	}

	void testCellevolve2(){
		Cell cell3;
		cell3.get()->getAliveNeighbors() = 1;
		cell3.get()->getIsAlive() = false;
		cell3.evolve();
		assert(cell3.get()->getSymbol() == '0');
		assert(cell3.get()->getIsAlive() == true);		
	}

	void testCellevolve3(){
		Cell cell4;
		cell4.get()->getAliveNeighbors() = 0;
		cell4.get()->getIsAlive() = true;
		cell4.evolve();
		assert(cell4.get()->getSymbol() == '-');
		assert(cell4.get()->getIsAlive() == false);	
	}

	// Cell::print

	void testCellprint1(){
		Cell cell5;
		cell5.get()->getSymbol() = '-';
		assert(cell5.print() == '-');
	}

	void testCellprint2(){
		Cell cell6;
		cell6.get()->getSymbol() = '0';
		assert(cell6.print() == '0');
	}

	void testCellprint3(){
		Cell cell7;
		cell7.get()->getSymbol() = '*';
		assert(cell7.print() == '*');
	}

	// Cell::setNeighbors

	void testCellsetNeighbors1(){
		Cell cell8;
		cell8.setNeighbors(4);
		assert(cell8.get()->getAliveNeighbors() == 4);
	}

	void testCellsetNeighbors2(){
		Cell cell9;
		cell9.setNeighbors(8);
		assert(cell9.get()->getAliveNeighbors() == 8);
	}

	void testCellsetNeighbors3(){
		Cell cell10;
		cell10.setNeighbors(-1);
		assert(cell10.get()->getAliveNeighbors() == -1);
	}

	// Cell::clone

	void testCellclone(){
		Cell cell11;
		cell11.setNeighbors(3);
		Cell cell12;
		cell12 = cell11.get()->clone();
		assert(cell12.get()->getAliveNeighbors() == cell11.get()->getAliveNeighbors());
	}

	// Cell::changeStatus

	void testCellchangeStatus1(){
		Cell cell13;
		cell13.get()->getIsAlive() = true;
		cell13.get()->changeStatus(false);
		assert(cell13.get()->getIsAlive() == false);
	}

	void testCellchangeStatus2(){
		Cell cell14;
		cell14.get()->getIsAlive() = false;
		cell14.get()->changeStatus(true);
		assert(cell14.get()->getIsAlive() == true);
	}

	void testCellchangeStatus3(){
		Cell cell15;
		cell15.get()->getIsAlive() = false;
		cell15.get()->changeStatus(false);
		assert(cell15.get()->getIsAlive() == false);
	}


	//suite
	CPPUNIT_TEST_SUITE(TestLife);
	CPPUNIT_TEST(testConcreate1);
	CPPUNIT_TEST(testFredcreate1);
	CPPUNIT_TEST(testCellcreate1);
	CPPUNIT_TEST(testConprintGrid1);
	CPPUNIT_TEST(testFredprintGrid1);
	CPPUNIT_TEST(testCellprintGrid1);
	CPPUNIT_TEST(testCongetNeighbors1);
	CPPUNIT_TEST(testFredgetNeighbors1);
	CPPUNIT_TEST(testCellgetNeighbors1);
	CPPUNIT_TEST(testneighborHelpConway1);
	CPPUNIT_TEST(testneighborHelpConway2);
	CPPUNIT_TEST(testneighborHelpConway3);
	CPPUNIT_TEST(testneighborHelpFredkin1);
	CPPUNIT_TEST(testneighborHelpFredkin2);
	CPPUNIT_TEST(testneighborHelpFredkin3);
	CPPUNIT_TEST(testConupdateGrid1);
	CPPUNIT_TEST(testFredupdateGrid1);
	CPPUNIT_TEST(testCellupdateGrid1);
	CPPUNIT_TEST(testConprocessTurn1);
	CPPUNIT_TEST(testFredprocessTurn1);
	CPPUNIT_TEST(testCellprocessTurn1);
	CPPUNIT_TEST(testConway);
	CPPUNIT_TEST(testConevolve1);
	CPPUNIT_TEST(testConevolve2);
	CPPUNIT_TEST(testConevolve3);
	CPPUNIT_TEST(testConprint1);
	CPPUNIT_TEST(testConprint2);
	CPPUNIT_TEST(testConprint3);
	CPPUNIT_TEST(testConsetNeighbors1);
	CPPUNIT_TEST(testConsetNeighbors2);
	CPPUNIT_TEST(testConsetNeighbors3);
	CPPUNIT_TEST(testConclone);
	CPPUNIT_TEST(testConchangeStatus1);
	CPPUNIT_TEST(testConchangeStatus2);
	CPPUNIT_TEST(testConchangeStatus3);
	CPPUNIT_TEST(testFredkin);
	CPPUNIT_TEST(testFredevolve1);
	CPPUNIT_TEST(testFredevolve2);
	CPPUNIT_TEST(testFredevolve3);
	CPPUNIT_TEST(testFredprint1);
	CPPUNIT_TEST(testFredprint2);
	CPPUNIT_TEST(testFredprint3);
	CPPUNIT_TEST(testFredsetNeighbors1);
	CPPUNIT_TEST(testFredsetNeighbors2);
	CPPUNIT_TEST(testFredsetNeighbors3);
	CPPUNIT_TEST(testFredclone);
	CPPUNIT_TEST(testFredchangeStatus1);
	CPPUNIT_TEST(testFredchangeStatus2);
	CPPUNIT_TEST(testFredchangeStatus3);
	CPPUNIT_TEST(testCell);
	CPPUNIT_TEST(testCellevolve1);
	CPPUNIT_TEST(testCellevolve2);
	CPPUNIT_TEST(testCellevolve3);
	CPPUNIT_TEST(testCellprint1);
	CPPUNIT_TEST(testCellprint2);
	CPPUNIT_TEST(testCellprint3);
	CPPUNIT_TEST(testCellsetNeighbors1);
	CPPUNIT_TEST(testCellsetNeighbors2);
	CPPUNIT_TEST(testCellsetNeighbors3);
	CPPUNIT_TEST(testCellclone);
	CPPUNIT_TEST(testCellchangeStatus1);
	CPPUNIT_TEST(testCellchangeStatus2);
	CPPUNIT_TEST(testCellchangeStatus3);
	CPPUNIT_TEST_SUITE_END();};

int main() {
	using namespace std;

	cout << "TestLife.c++" << endl;
	CppUnit::TextTestRunner tr;
	tr.addTest(TestLife::suite());
	tr.run();

	cout << "Done." << endl;
	return 0; }