// --------
// includes
// --------

#include <algorithm> // count
#include <iostream>  // ios_base
#include <memory>    // allocator

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

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
	
	// -------------
	// test_DefaultConstruct
	// -------------
	
	void Life_DLife1() 
	{
		Life<ConwayCell> x;
		CPPUNIT_ASSERT(x._gridH == 0);
		CPPUNIT_ASSERT(x._gridW == 0);
		CPPUNIT_ASSERT(x._gen == 0);
		CPPUNIT_ASSERT(x._popu == 0);
	}
	
	void Life_DLife2() 
	{
		Life<FredkinCell> x; 
		CPPUNIT_ASSERT(x._gridH == 0);
		CPPUNIT_ASSERT(x._gridW == 0);
		CPPUNIT_ASSERT(x._gen == 0);
		CPPUNIT_ASSERT(x._popu == 0);
	}
	
	void Life_DLife3() 
	{
		Life<Cell> x; 
		CPPUNIT_ASSERT(x._gridH == 0);
		CPPUNIT_ASSERT(x._gridW == 0);
		CPPUNIT_ASSERT(x._gen == 0);
		CPPUNIT_ASSERT(x._popu == 0);
	}

	// -------------
	// test_ParameterConstruct
	// -------------
	
	void Life_PLife1() 
	{
		Life<ConwayCell> x(1, 1, '.'); 
		CPPUNIT_ASSERT(x._gridH == 1);
		CPPUNIT_ASSERT(x._gridW == 1);
		CPPUNIT_ASSERT(x._gen == 0);
		CPPUNIT_ASSERT(x._popu == 0);
	}
	
	void Life_PLife2() 
	{
		Life<FredkinCell> x(1, 1, '-'); 
		CPPUNIT_ASSERT(x._gridH == 1);
		CPPUNIT_ASSERT(x._gridW == 1);
		CPPUNIT_ASSERT(x._gen == 0);
		CPPUNIT_ASSERT(x._popu == 0);
	}
	
	void Life_PLife3() 
	{
		Life<Cell> x(1, 1, '-');  
		CPPUNIT_ASSERT(x._gridH == 1);
		CPPUNIT_ASSERT(x._gridW == 1);
		CPPUNIT_ASSERT(x._gen == 0);
		CPPUNIT_ASSERT(x._popu == 0);
	}

	void Life_PLife4() 
	{
		Life<ConwayCell> x(1, 1, '.');
		x.insertCell(0, 0, '*');
		CPPUNIT_ASSERT(x._gridH == 1);
		CPPUNIT_ASSERT(x._gridW == 1);
		CPPUNIT_ASSERT(x._gen == 0);
		CPPUNIT_ASSERT(x._popu == 1);
	}
	
	void Life_PLife5() 
	{
		Life<FredkinCell> x(1, 1, '-');
		x.insertCell(0, 0, '0');
		CPPUNIT_ASSERT(x._gridH == 1);
		CPPUNIT_ASSERT(x._gridW == 1);
		CPPUNIT_ASSERT(x._gen == 0);
		CPPUNIT_ASSERT(x._popu == 1);
	}
	
	void Life_PLife6() 
	{
		Life<Cell> x(1, 1, '-');  
		x.insertCell(0, 0, '0');
		CPPUNIT_ASSERT(x._gridH == 1);
		CPPUNIT_ASSERT(x._gridW == 1);
		CPPUNIT_ASSERT(x._gen == 0);
		CPPUNIT_ASSERT(x._popu == 1);
	}

	// -------------
	// test_InsertCell
	// -------------
	
	void Life_InsertCell1() 
	{
		Life<ConwayCell> x(1, 1, '.');
		x.insertCell(0, 0, '*');
		CPPUNIT_ASSERT(x._gridH == 1);
		CPPUNIT_ASSERT(x._gridW == 1);
		CPPUNIT_ASSERT(x._gen == 0);
		CPPUNIT_ASSERT(x._popu == 1);
	}
	
	void Life_InsertCell2() 
	{
		Life<FredkinCell> x(1, 1, '-');
		x.insertCell(0, 0, '0');
		CPPUNIT_ASSERT(x._gridH == 1);
		CPPUNIT_ASSERT(x._gridW == 1);
		CPPUNIT_ASSERT(x._gen == 0);
		CPPUNIT_ASSERT(x._popu == 1);
	}
	
	void Life_InsertCell3() 
	{
		Life<Cell> x(1, 1, '-');  
		x.insertCell(0, 0, '0');
		CPPUNIT_ASSERT(x._gridH == 1);
		CPPUNIT_ASSERT(x._gridW == 1);
		CPPUNIT_ASSERT(x._gen == 0);
		CPPUNIT_ASSERT(x._popu == 1);
	}
	
	// -------------
	// test_read
	// -------------
	
	void Life_Read1() 
	{
		Life<ConwayCell> x; 
		x.read("RunLifeConway.in");
		CPPUNIT_ASSERT(x._gridH == 109);
		CPPUNIT_ASSERT(x._gridW == 69);
		CPPUNIT_ASSERT(x._gen == 0);
		CPPUNIT_ASSERT(x._popu == 35);
	}
	
	void Life_Read2() 
	{
		Life<FredkinCell> x; 
		x.read("RunLifeFredkin.in");
		CPPUNIT_ASSERT(x._gridH == 20);
		CPPUNIT_ASSERT(x._gridW == 20);
		CPPUNIT_ASSERT(x._gen == 0);
		CPPUNIT_ASSERT(x._popu == 4);
	}
	
	void Life_Read3() 
	{
		Life<Cell> x; 
		x.read("RunLifeCell.in");
		CPPUNIT_ASSERT(x._gridH == 20);
		CPPUNIT_ASSERT(x._gridW == 20);
		CPPUNIT_ASSERT(x._gen == 0);
		CPPUNIT_ASSERT(x._popu == 6);
	}
	
	// -------------
	// test_simulate
	// -------------
	
	void Life_Simulate1() 
	{
		Life<ConwayCell> x; 
		x.read("RunLifeConway.in");
		x.simulate();
		CPPUNIT_ASSERT(x._gen == 1);
	}
	
	void Life_Simulate2() 
	{
		Life<FredkinCell> x; 
		x.read("RunLifeFredkin.in");
		x.simulate();
		CPPUNIT_ASSERT(x._gen == 1);
	}
	
	void Life_Simulate3() 
	{
		Life<Cell> x; 
		x.read("RunLifeCell.in");
		x.simulate();
		CPPUNIT_ASSERT(x._gen == 1);
	}
	
	
	// -------------
	// test_run
	// -------------
	
	void Life_Run1() 
	{
		Life<ConwayCell> x; 
		x.read("RunLifeConway.in");
		x.simulate();
		x.run();
		CPPUNIT_ASSERT(x._popu == 63);
	}
	
	void Life_Run2() 
	{
		Life<FredkinCell> x; 
		x.read("RunLifeFredkin.in");
		x.simulate();
		x.run();
		CPPUNIT_ASSERT(x._popu == 8);
	}
	
	void Life_Run3() 
	{
		Life<Cell> x; 
		x.read("RunLifeCell.in");
		x.simulate();
		x.run();
		CPPUNIT_ASSERT(x._popu == 12);
	}
	
	// -------------
	// test_print
	// -------------
	
	void Life_Print1()
	{
	Life<ConwayCell> x;
	x.read("RunLifeConway.in");
	ostringstream o;
	x.print(o);
	CPPUNIT_ASSERT(o.str() == "Generation = 0, Population = 35.\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n..................................*..................................\n..................................*..................................\n..................................*..................................\n..................................*..................................\n..................................*..................................\n.....................................................................\n..................................*..................................\n..................................*..................................\n..................................*..................................\n..................................*..................................\n..................................*..................................\n.....................................................................\n..................................*..................................\n..................................*..................................\n..................................*..................................\n..................................*..................................\n..................................*..................................\n.....................................................................\n..................................*..................................\n..................................*..................................\n..................................*..................................\n..................................*..................................\n..................................*..................................\n.....................................................................\n..................................*..................................\n..................................*..................................\n..................................*..................................\n..................................*..................................\n..................................*..................................\n.....................................................................\n..................................*..................................\n..................................*..................................\n..................................*..................................\n..................................*..................................\n..................................*..................................\n.....................................................................\n..................................*..................................\n..................................*..................................\n..................................*..................................\n..................................*..................................\n..................................*..................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n.....................................................................\n\n");
}

	void Life_Print2()
	{
	Life<FredkinCell> x;
	x.read("RunLifeFredkin.in");
	ostringstream o;
	x.print(o);
	CPPUNIT_ASSERT(o.str() == "Generation = 0, Population = 4.\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n---------00---------\n---------00---------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n\n");
	}

	void Life_Print3()
	{
	Life<Cell> x;
	x.read("RunLifeCell.in");
	ostringstream o;
	x.print(o);
	CPPUNIT_ASSERT(o.str() == "Generation = 0, Population = 6.\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n---------00---------\n--------0000--------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n\n");
	}

	// -------------
	// test_AIsAlive
	// -------------
	
	void A_IsAlive1() 
	{
		FredkinCell x('0');
		CPPUNIT_ASSERT(x.isAlive());
	}

	void A_IsAlive2() 
	{
		FredkinCell x('-');
		CPPUNIT_ASSERT(!x.isAlive());
	}
	
	void A_IsAlive3() 
	{
		ConwayCell x('*');
		CPPUNIT_ASSERT(x.isAlive());
	}

	void A_IsAlive4() 
	{
		ConwayCell x('.');
		CPPUNIT_ASSERT(!x.isAlive());
	}
	
	// -------------
	// test_ARun
	// -------------
	
	void A_Run1() 
	{
		FredkinCell x('0');
		x._status = false;
		x.run();
		CPPUNIT_ASSERT(!x.isAlive());
	}

	void A_Run2() 
	{
		FredkinCell x('-');
		x._status = true;
		x.run();
		CPPUNIT_ASSERT(x.isAlive());
	}
	
	void A_Run3() 
	{
		ConwayCell x('*');
		x._status = false;
		x.run();
		CPPUNIT_ASSERT(!x.isAlive());
	}

	void A_Run4() 
	{
		ConwayCell x('.');
		x._status = true;
		x.run();
		CPPUNIT_ASSERT(x.isAlive());
	}

	// -------------
	// test_FCConstruct
	// -------------
	
	void FC_Construct1() 
	{
		FredkinCell x('0');
		CPPUNIT_ASSERT(x._alive == true);
		CPPUNIT_ASSERT(x._status == true);
		CPPUNIT_ASSERT(x._age == 0);
	}

	void FC_Construct2() 
	{
		FredkinCell x('-');
		CPPUNIT_ASSERT(x._alive == false);
		CPPUNIT_ASSERT(x._status == false);
		CPPUNIT_ASSERT(x._age == 0);
	}

	void FC_Construct3() 
	{
		FredkinCell x('-');
		CPPUNIT_ASSERT(x._alive == false);
		CPPUNIT_ASSERT(x._status == false);
		CPPUNIT_ASSERT(x._age == 0);
		ostringstream o;
		x.print(o);
		CPPUNIT_ASSERT(o.str() == "-");
	}

	// -------------
	// test_FCPrint
	// -------------

	void FC_Print1() 
	{
		FredkinCell x('-');
		ostringstream o;
		x.print(o);
		CPPUNIT_ASSERT(o.str() == "-");
	}

	void FC_Print2() 
	{
		FredkinCell x('0');
		ostringstream o;
		x.print(o);
		CPPUNIT_ASSERT(o.str() == "0");
	}

	void FC_Print3() 
	{
		FredkinCell x('0');
		x._age = 10;
		ostringstream o;
		x.print(o);
		CPPUNIT_ASSERT(o.str() == "+");
	}

	void FC_Print4() 
	{
		FredkinCell x('0');
		x._age = 4;
		ostringstream o;
		x.print(o);
		CPPUNIT_ASSERT(o.str() == "4");
	}

	// -------------
	// test_FCneighbors
	// -------------

	void FC_Neighbors1() 
	{
		FredkinCell x('-');
		vector<pair<int, int> > neighbors = x.neighbors(make_pair(0, 0));
		CPPUNIT_ASSERT(neighbors[0] == make_pair(0, -1));
		CPPUNIT_ASSERT(neighbors[1] == make_pair(-1, 0));
		CPPUNIT_ASSERT(neighbors[2] == make_pair(1, 0));
		CPPUNIT_ASSERT(neighbors[3] == make_pair(0, 1));
	}

	void FC_Neighbors2() 
	{
		FredkinCell x('-');
		vector<pair<int, int> > neighbors = x.neighbors(make_pair(10, 10));
		CPPUNIT_ASSERT(neighbors[0] == make_pair(10, 9));
		CPPUNIT_ASSERT(neighbors[1] == make_pair(9, 10));
		CPPUNIT_ASSERT(neighbors[2] == make_pair(11, 10));
		CPPUNIT_ASSERT(neighbors[3] == make_pair(10, 11));
	}

	void FC_Neighbors3() 
	{
		FredkinCell x('-');
		vector<pair<int, int> > neighbors = x.neighbors(make_pair(-10, -10));
		CPPUNIT_ASSERT(neighbors[0] == make_pair(-10, -11));
		CPPUNIT_ASSERT(neighbors[1] == make_pair(-11, -10));
		CPPUNIT_ASSERT(neighbors[2] == make_pair(-9, -10));
		CPPUNIT_ASSERT(neighbors[3] == make_pair(-10, -9));
	}

	// -------------
	// test_FCStatus
	// -------------

	void FC_Status1() 
	{
		FredkinCell x('-');
		x.updateStatus(0);
		CPPUNIT_ASSERT(!x._status);
	}

	void FC_Status2() 
	{
		FredkinCell x('-');
		x.updateStatus(3);
		CPPUNIT_ASSERT(x._status);
	}

	void FC_Status3() 
	{
		FredkinCell x('0');
		x.updateStatus(0);
		CPPUNIT_ASSERT(!x._status);
	}

	void FC_Status4() 
	{
		FredkinCell x('0');
		x.updateStatus(3);
		CPPUNIT_ASSERT(x._status);
	}

	// -------------
	// test_FCClone
	// -------------

	void FC_Clone1() 
	{
		FredkinCell x('-');
		FredkinCell* y = x.clone();
		CPPUNIT_ASSERT(x._alive == (*y)._alive);
	}

	void FC_Clone2() 
	{
		FredkinCell x('0');
		FredkinCell* y = x.clone();
		CPPUNIT_ASSERT(x._alive == (*y)._alive);
	}

	void FC_Clone3() 
	{
		FredkinCell x('-');
		x._age = 48;
		FredkinCell* y = x.clone();
		CPPUNIT_ASSERT(x._alive == (*y)._alive);
	}

	void FC_Clone4() 
	{
		FredkinCell x('0');
		x._age = 48;
		FredkinCell* y = x.clone();
		CPPUNIT_ASSERT(x._status == (*y)._status);
	}

	void FC_Clone5() 
	{
		FredkinCell x('-');
		x._age = 48;
		FredkinCell* y = x.clone();
		CPPUNIT_ASSERT(x._age == (*y)._age);
	}

	// -------------
	// test_CCConstruct
	// -------------

	void CC_Construct1()
	{
		ConwayCell x('*');
		CPPUNIT_ASSERT(x._alive == true);
		CPPUNIT_ASSERT(x._status == true);
	}

	void CC_Construct2()
	{
		ConwayCell x('.');
		CPPUNIT_ASSERT(x._alive == false);
		CPPUNIT_ASSERT(x._status == false);
	}

	void CC_Construct3()
	{
		ConwayCell x('.');
		CPPUNIT_ASSERT(x._alive == false);
		CPPUNIT_ASSERT(x._status == false);
		ostringstream o;
		x.print(o);
		CPPUNIT_ASSERT(o.str() == ".");
	}

	// -------------
	// test_CCPrint
	// -------------

	void CC_Print1()
	{
		ConwayCell x('.');
		ostringstream o;
		x.print(o);
		CPPUNIT_ASSERT(o.str() == ".");
	}

	void CC_Print2()
	{
		ConwayCell x('*');
		ostringstream o;
		x.print(o);
		CPPUNIT_ASSERT(o.str() == "*");
	}

	void CC_Print3()
	{
		ConwayCell x('.');
		x._alive = true;
		ostringstream o;
		x.print(o);
		CPPUNIT_ASSERT(o.str() == "*");
	}

	// -------------
	// test_CCneighbors
	// -------------

	void CC_Neighbors1()
	{
		ConwayCell x('.');
		vector<pair<int, int> > neighbors = x.neighbors(make_pair(0, 0));
		CPPUNIT_ASSERT(neighbors[0] == make_pair(0, -1));
		CPPUNIT_ASSERT(neighbors[1] == make_pair(0, 1));
		CPPUNIT_ASSERT(neighbors[2] == make_pair(-1, 0));
		CPPUNIT_ASSERT(neighbors[3] == make_pair(1, 0));
		CPPUNIT_ASSERT(neighbors[4] == make_pair(-1, -1));
		CPPUNIT_ASSERT(neighbors[5] == make_pair(-1, 1));
		CPPUNIT_ASSERT(neighbors[6] == make_pair(1, -1));
		CPPUNIT_ASSERT(neighbors[7] == make_pair(1, 1));
	}

	void CC_Neighbors2()
	{
		ConwayCell x('.');
		vector<pair<int, int> > neighbors = x.neighbors(make_pair(10, 10));
		CPPUNIT_ASSERT(neighbors[0] == make_pair(10, 9));
		CPPUNIT_ASSERT(neighbors[1] == make_pair(10, 11));
		CPPUNIT_ASSERT(neighbors[2] == make_pair(9, 10));
		CPPUNIT_ASSERT(neighbors[3] == make_pair(11, 10));
		CPPUNIT_ASSERT(neighbors[4] == make_pair(9, 9));
		CPPUNIT_ASSERT(neighbors[5] == make_pair(9, 11));
		CPPUNIT_ASSERT(neighbors[6] == make_pair(11, 9));
		CPPUNIT_ASSERT(neighbors[7] == make_pair(11, 11));
	}

	void CC_Neighbors3()
	{
		ConwayCell x('.');
		vector<pair<int, int> > neighbors = x.neighbors(make_pair(-10, -10));
		CPPUNIT_ASSERT(neighbors[0] == make_pair(-10, -11));
		CPPUNIT_ASSERT(neighbors[1] == make_pair(-10, -9));
		CPPUNIT_ASSERT(neighbors[2] == make_pair(-11, -10));
		CPPUNIT_ASSERT(neighbors[3] == make_pair(-9, -10));
		CPPUNIT_ASSERT(neighbors[4] == make_pair(-11, -11));
		CPPUNIT_ASSERT(neighbors[5] == make_pair(-11, -9));
		CPPUNIT_ASSERT(neighbors[6] == make_pair(-9, -11));
		CPPUNIT_ASSERT(neighbors[7] == make_pair(-9, -9));
	}

	// -------------
	// test_CCStatus
	// -------------

	void CC_Status1()
	{
		ConwayCell x('.');
		x.updateStatus(0);
		CPPUNIT_ASSERT(!x._status);
	}

	void CC_Status2()
	{
		ConwayCell x('.');
		x.updateStatus(3);
		CPPUNIT_ASSERT(x._status);
	}

	void CC_Status3()
	{
		ConwayCell x('*');
		x.updateStatus(0);
		CPPUNIT_ASSERT(!x._status);
	}

	void CC_Status4()
	{
		ConwayCell x('*');
		x.updateStatus(3);
		CPPUNIT_ASSERT(x._status);
	}

	// -------------
	// test_CCClone
	// -------------

	void CC_Clone1()
	{
		FredkinCell x('*');
		FredkinCell* y = x.clone();
		CPPUNIT_ASSERT(x._alive == (*y)._alive);
	}

	void CC_Clone2()
	{
		FredkinCell x('*');	
		FredkinCell* y = x.clone();
		CPPUNIT_ASSERT(x._status == (*y)._status);
	}

	void CC_Clone3()
	{
		FredkinCell x('.');
		FredkinCell* y = x.clone();
		CPPUNIT_ASSERT(x._alive == (*y)._alive);
	}

	// -------------
	// test_CConstruct
	// -------------
	
	void C_Construct1() 
	{
		Cell x('0');
		CPPUNIT_ASSERT(x.isAlive());
	}

	void C_Construct2() 
	{
		Cell x('-');
		CPPUNIT_ASSERT(!x.isAlive());
	}

	void C_Construct3() 
	{
		Cell x('4');
		CPPUNIT_ASSERT(!x.isAlive());
	}

	// -------------
	// test_CIsAlive
	// -------------
	
	void C_IsAlive1() 
	{
		Cell x('-');
		CPPUNIT_ASSERT(!x.isAlive());
	}

	void C_IsAlive2() 
	{
		Cell x('0');
		CPPUNIT_ASSERT(x.isAlive());
	}

	void C_IsAlive3() 
	{
		Cell x('-');
		x.get()->_alive = true;
		CPPUNIT_ASSERT(x.isAlive());
	}

	// -------------
	// test_CRun
	// -------------
	
	void C_Run1() 
	{
		Cell x('-');
		x.run();
		CPPUNIT_ASSERT(!x.isAlive());
	}

	void C_Run2() 
	{
		Cell x('0');
		x.run();
		CPPUNIT_ASSERT(x.isAlive());
	}

	void C_Run3() 
	{
		Cell x('4');
		x.run();
		CPPUNIT_ASSERT(!x.isAlive());
	}

	// -------------
	// test_CPrint
	// -------------
	
	void C_Print1() 
	{
		Cell x('-');
		ostringstream o;
		x.print(o);
		CPPUNIT_ASSERT(o.str() == "-");
	}

	void C_Print2() 
	{
		Cell x('0');
		ostringstream o;
		x.print(o);
		CPPUNIT_ASSERT(o.str() == "0");
	}

	void C_Print3() 
	{
		Cell x('-');
		x.get()->_alive = true;
		ostringstream o;
		x.print(o);
		CPPUNIT_ASSERT(o.str() == "0");
	}

	// -------------
	// test_CNeighbors
	// -------------
	
	void C_Neighbors1() 
	{
		Cell x('-');
		vector<pair<int, int> > neighbors = x.neighbors(make_pair(0, 0));
		CPPUNIT_ASSERT(neighbors[0] == make_pair(0, -1));
		CPPUNIT_ASSERT(neighbors[1] == make_pair(-1, 0));
		CPPUNIT_ASSERT(neighbors[2] == make_pair(1, 0));
		CPPUNIT_ASSERT(neighbors[3] == make_pair(0, 1));
	}

	void C_Neighbors2() 
	{
		Cell x('-');
		vector<pair<int, int> > neighbors = x.neighbors(make_pair(10, 10));
		CPPUNIT_ASSERT(neighbors[0] == make_pair(10, 9));
		CPPUNIT_ASSERT(neighbors[1] == make_pair(9, 10));
		CPPUNIT_ASSERT(neighbors[2] == make_pair(11, 10));
		CPPUNIT_ASSERT(neighbors[3] == make_pair(10, 11));
	}

	void C_Neighbors3() 
	{
		Cell x('-');
		vector<pair<int, int> > neighbors = x.neighbors(make_pair(-10, -10));
		CPPUNIT_ASSERT(neighbors[0] == make_pair(-10, -11));
		CPPUNIT_ASSERT(neighbors[1] == make_pair(-11, -10));
		CPPUNIT_ASSERT(neighbors[2] == make_pair(-9, -10));
		CPPUNIT_ASSERT(neighbors[3] == make_pair(-10, -9));
	}

	void C_Neighbors4() 
	{
		Cell x('0');
		x.updateStatus(1);
		x.run();
		x.updateStatus(1);
		x.run();
		vector<pair<int, int> > neighbors = x.neighbors(make_pair(0, 0));
		CPPUNIT_ASSERT(neighbors[0] == make_pair(0, -1));
		CPPUNIT_ASSERT(neighbors[1] == make_pair(0, 1));
		CPPUNIT_ASSERT(neighbors[2] == make_pair(-1, 0));
		CPPUNIT_ASSERT(neighbors[3] == make_pair(1, 0));		
		CPPUNIT_ASSERT(neighbors[4] == make_pair(-1, -1));
		CPPUNIT_ASSERT(neighbors[5] == make_pair(-1, 1));
		CPPUNIT_ASSERT(neighbors[6] == make_pair(1, -1));
		CPPUNIT_ASSERT(neighbors[7] == make_pair(1, 1));
	}

	// -------------
	// test_CUpdateStatus
	// -------------

	void C_UpdateStatus1() 
	{
		Cell x('0');
		x.updateStatus(1);
		x.run();
		x.updateStatus(1);
		x.run();
		ostringstream o;
		x.print(o);
		CPPUNIT_ASSERT(o.str() == "*");
	}

	void C_UpdateStatus2() 
	{
		Cell x('0');
		x.updateStatus(1);
		x.run();
		ostringstream o;
		x.print(o);
		CPPUNIT_ASSERT(o.str() == "1");
	}

	void C_UpdateStatus3() 
	{
		Cell x('-');
		x.updateStatus(3);
		x.run();
		ostringstream o;
		x.print(o);
		CPPUNIT_ASSERT(o.str() == "0");
	}


	CPPUNIT_TEST_SUITE(TestLife);
	CPPUNIT_TEST(Life_DLife1);
	CPPUNIT_TEST(Life_DLife2);
	CPPUNIT_TEST(Life_DLife3);
	CPPUNIT_TEST(Life_PLife1);
	CPPUNIT_TEST(Life_PLife2);
	CPPUNIT_TEST(Life_PLife3);
	CPPUNIT_TEST(Life_PLife4);
	CPPUNIT_TEST(Life_PLife5);
	CPPUNIT_TEST(Life_PLife6);
	CPPUNIT_TEST(Life_InsertCell1);
	CPPUNIT_TEST(Life_InsertCell2);
	CPPUNIT_TEST(Life_InsertCell3);
	CPPUNIT_TEST(Life_Read1);
	CPPUNIT_TEST(Life_Read2);
	CPPUNIT_TEST(Life_Read3);
	CPPUNIT_TEST(Life_Simulate1);
	CPPUNIT_TEST(Life_Simulate2);
	CPPUNIT_TEST(Life_Simulate3);
	CPPUNIT_TEST(Life_Run1);
	CPPUNIT_TEST(Life_Run2);
	CPPUNIT_TEST(Life_Run3);
	CPPUNIT_TEST(Life_Print1);
	CPPUNIT_TEST(Life_Print2);
	CPPUNIT_TEST(Life_Print3);

	CPPUNIT_TEST(A_IsAlive1);
	CPPUNIT_TEST(A_IsAlive2);
	CPPUNIT_TEST(A_IsAlive3);
	CPPUNIT_TEST(A_IsAlive4);
	CPPUNIT_TEST(A_Run1);
	CPPUNIT_TEST(A_Run2);
	CPPUNIT_TEST(A_Run3);
	CPPUNIT_TEST(A_Run4);

	CPPUNIT_TEST(FC_Construct1);
	CPPUNIT_TEST(FC_Construct2);
	CPPUNIT_TEST(FC_Construct3);
	CPPUNIT_TEST(FC_Print1);
	CPPUNIT_TEST(FC_Print2);
	CPPUNIT_TEST(FC_Print3);
	CPPUNIT_TEST(FC_Print4);
	CPPUNIT_TEST(FC_Neighbors1);
	CPPUNIT_TEST(FC_Neighbors2);
	CPPUNIT_TEST(FC_Neighbors3);
	CPPUNIT_TEST(FC_Status1);
	CPPUNIT_TEST(FC_Status2);
	CPPUNIT_TEST(FC_Status3);
	CPPUNIT_TEST(FC_Status4);
	CPPUNIT_TEST(FC_Clone1);
	CPPUNIT_TEST(FC_Clone2);
	CPPUNIT_TEST(FC_Clone3);
	CPPUNIT_TEST(FC_Clone4);
	CPPUNIT_TEST(FC_Clone5);

	CPPUNIT_TEST(CC_Construct1);
	CPPUNIT_TEST(CC_Construct2);
	CPPUNIT_TEST(CC_Construct3);
	CPPUNIT_TEST(CC_Print1);
	CPPUNIT_TEST(CC_Print2);
	CPPUNIT_TEST(CC_Print3);
	CPPUNIT_TEST(CC_Neighbors1);
	CPPUNIT_TEST(CC_Neighbors2);
	CPPUNIT_TEST(CC_Neighbors3);
	CPPUNIT_TEST(CC_Status1);
	CPPUNIT_TEST(CC_Status2);
	CPPUNIT_TEST(CC_Status3);
	CPPUNIT_TEST(CC_Status4);
	CPPUNIT_TEST(CC_Clone1);
	CPPUNIT_TEST(CC_Clone2);
	CPPUNIT_TEST(CC_Clone3);
	
	CPPUNIT_TEST(C_Construct1);
	CPPUNIT_TEST(C_Construct2);
	CPPUNIT_TEST(C_Construct3);
	CPPUNIT_TEST(C_IsAlive1);
	CPPUNIT_TEST(C_IsAlive2);
	CPPUNIT_TEST(C_IsAlive3);
	CPPUNIT_TEST(C_Run1);
	CPPUNIT_TEST(C_Run2);
	CPPUNIT_TEST(C_Run3);
	CPPUNIT_TEST(C_Print1);
	CPPUNIT_TEST(C_Print2);
	CPPUNIT_TEST(C_Print3);
	CPPUNIT_TEST(C_Neighbors1);
	CPPUNIT_TEST(C_Neighbors2);
	CPPUNIT_TEST(C_Neighbors3);
	CPPUNIT_TEST(C_Neighbors4);
	CPPUNIT_TEST(C_UpdateStatus1);
	CPPUNIT_TEST(C_UpdateStatus2);
	CPPUNIT_TEST(C_UpdateStatus3);

	
	CPPUNIT_TEST_SUITE_END();};

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
