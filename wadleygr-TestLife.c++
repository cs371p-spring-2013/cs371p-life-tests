// ------------------------------------
// projects/allocator/TestAllocator.c++
// Copyright (C) 2013
// Glenn P. Downing
// ------------------------------------

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

#include <algorithm> // count
#include <iostream>  // ios_base
#include <memory>    // allocator
#include <string.h>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define private public
#define protected public
#define class struct

#include "Life.h"

// -------------
// TestAllocator
// -------------

struct TestLife : CppUnit::TestFixture {

	//Test Constructors
	//life constructor
    void test_Life1 () {
        Life<ConwayCell> x  = Life<ConwayCell>(5,5);
		assert(x._rows == 5);
		assert(x._cols == 5);
		assert(x._population == 0);       
    }

    void test_Life2() {
        Life<FredkinCell> x  = Life<FredkinCell>(6,6);
		assert(x._rows == 6);
		assert(x._cols == 6);
		assert(x._turn == 0);       
    }

    void test_Life3 () {
        Life<Cell> x  = Life<Cell>(5,5);
		assert(x._rows == 5);
		assert(x._cols == 5);
		assert(x._population == 0);       
    }

	//Conway Constructor
	void test_Conway1(){
		ConwayCell v = ConwayCell(0,0,false);
		assert(v._row == 0);
		assert(v._col == 0);
	}

	void test_Conway2(){
		ConwayCell v = ConwayCell(2,2,true);
		assert(v._row == 2);
		assert(v._col == 2);
		assert(v._alive);
	}

	void test_Conway3(){
		ConwayCell v = ConwayCell(3,3,false);
		assert(v._row == 3);
		assert(v._col == 3);
		assert(!(v._alive));
	}

	//Fredkin Constuctor
	void test_Fredkin1(){
		FredkinCell v = FredkinCell(0,0,false);
		assert(v._row == 0);
		assert(v._col == 0);
		assert(!(v._alive));
	}

	void test_Fredkin2(){
		FredkinCell v = FredkinCell(0,0,false);
		assert(v._row == 0);
		assert(v._col == 0);
		assert(v._age == 0);
	}

	//Cell Constructor
	void test_Cell1(){
		Cell v = Cell(0,0,false);
	}

	void test_Cell2(){
		Cell v = Cell(0,0,true);
	}

	//---
	//test methods
	//
	
	//life::AddRow
	void test_Add_Row1(){
		using namespace std;
        Life<ConwayCell> x  = Life<ConwayCell>(5,5);
		string s = ".....";
		x.AddRow(s,0);
		assert(!(x._board[0][0].IsAlive()));
	}	

	void test_Add_Row2(){
		using namespace std;
        Life<ConwayCell> x  = Life<ConwayCell>(5,5);
		string s = "*.*..";
		x.AddRow(s,0);
		assert(x._board[0][0].IsAlive());
	}

	void test_Add_Row3(){
		using namespace std;
        Life<ConwayCell> x  = Life<ConwayCell>(5,5);
		string s = ".....";
		x.AddRow(s,0);
		x.AddRow(s,1);
		x.AddRow(s,2);
		assert(!(x._board[1][1].IsAlive()));
	}

	//Life::Check_Population
	void test_Population1(){
		using namespace std;
        Life<ConwayCell> x  = Life<ConwayCell>(5,5);
		string s = ".....";
		x.AddRow(s,0);
		x.AddRow(s,1);
		x.AddRow(s,2);
		x.AddRow(s,3);
		x.AddRow(s,4);
		int n = x.CheckPopulation();
		assert(n == 0);
	}

	void test_Population2(){
		using namespace std;
        Life<ConwayCell> x  = Life<ConwayCell>(5,5);
		string s = ".*...";
		x.AddRow(s,0);
		x.AddRow(s,1);
		x.AddRow(s,2);
		x.AddRow(s,3);
		x.AddRow(s,4);
		int n = x.CheckPopulation();
		assert(n == 5);
	}

	void test_Population3(){
		using namespace std;
        Life<ConwayCell> x  = Life<ConwayCell>(5,5);
		string s = "*****";
		x.AddRow(s,0);
		x.AddRow(s,1);
		x.AddRow(s,2);
		x.AddRow(s,3);
		x.AddRow(s,4);
		int n = x.CheckPopulation();
		assert(n == 25);
	}

	//Life::CheckL
	void test_CheckL1(){
		using namespace std;
        Life<ConwayCell> x  = Life<ConwayCell>(5,5);
		string s = ".....";
		x.AddRow(s,0);
		x.AddRow(s,1);
		x.AddRow(s,2);
		x.AddRow(s,3);
		x.AddRow(s,4);
		bool t = x.CheckL(0,0);
		assert(!t);
		t = x.CheckL(1,-290);
		assert(!t);
	}

	void test_CheckL2(){
		using namespace std;
        Life<ConwayCell> x  = Life<ConwayCell>(5,5);
		string s = "*****";
		x.AddRow(s,0);
		x.AddRow(s,1);
		x.AddRow(s,2);
		x.AddRow(s,3);
		x.AddRow(s,4);
		bool t = x.CheckL(0,0);
		assert(t);
		t = x.CheckL(1,-290);
		assert(!t);
	}

	void test_CheckL3(){
		using namespace std;
        Life<ConwayCell> x  = Life<ConwayCell>(5,5);
		string s = "..*..";
		x.AddRow(s,0);
		x.AddRow(s,1);
		x.AddRow(s,2);
		x.AddRow(s,3);
		x.AddRow(s,4);
		bool t = x.CheckL(0,2);
		assert(t);
		t = x.CheckL(3,2);
		assert(t);
	}

	//Life::CountNeighbors
	void test_Count_Neighbors1(){
		using namespace std;
        Life<ConwayCell> x  = Life<ConwayCell>(5,5);
		string s = ".....";
		x.AddRow(s,0);
		x.AddRow(s,1);
		x.AddRow(s,2);
		x.AddRow(s,3);
		x.AddRow(s,4);
		int n = x.CountNeighbors(x._board[0][0],0,0);
		assert(n ==0);
		
	}

	void test_Count_Neighbors2(){
		using namespace std;
        Life<ConwayCell> x  = Life<ConwayCell>(5,5);
		string s = "*****";
		x.AddRow(s,0);
		x.AddRow(s,1);
		x.AddRow(s,2);
		x.AddRow(s,3);
		x.AddRow(s,4);
		int n = x.CountNeighbors(x._board[0][0],0,1);
		assert(n ==5);
		
	}

	void test_Count_Neighbors3(){
		using namespace std;
        Life<ConwayCell> x  = Life<ConwayCell>(5,5);
		string s = "*****";
		x.AddRow(s,0);
		x.AddRow(s,1);
		x.AddRow(s,2);
		x.AddRow(s,3);
		x.AddRow(s,4);
		int n = x.CountNeighbors(x._board[0][0],0,0);
		assert(n ==3);
		
	}

	//Life::Generation
	void test_Generation1(){
		using namespace std;
		Life<ConwayCell> x = Life<ConwayCell>(5,5);
		string s = ".....";
		x.AddRow(s,0);
		x.AddRow(s,1);
		s = "..**.";
		x.AddRow(s,2);
		s = "..*..";
		x.AddRow(s,3);
		s = ".....";
		x.AddRow(s,4);
		assert(!(x._board[3][3].IsAlive()));
		x.Generation();
		assert(x._board[3][3].IsAlive());
	}

	void test_Generation2(){
		using namespace std;
		Life<FredkinCell> x = Life<FredkinCell>(5,5);
		string s = "-----";
		x.AddRow(s,0);
		x.AddRow(s,1);
		s = "--00-";
		x.AddRow(s,2);
		s = "--0--";
		x.AddRow(s,3);
		s = "-----";
		x.AddRow(s,4);
		assert(x._board[2][2].IsAlive());
		x.Generation();
		assert(!(x._board[2][2].IsAlive()));
	}

	void test_Generation3(){
		using namespace std;
		Life<Cell> x = Life<Cell>(5,5);
		string s = "-----";
		x.AddRow(s,0);
		x.AddRow(s,1);
		s = "--00-";
		x.AddRow(s,2);
		s = "--0--";
		x.AddRow(s,3);
		s = "-----";
		x.AddRow(s,4);
		assert(x._board[2][2].IsAlive());
		x.Generation();
		assert(!(x._board[2][2].IsAlive()));
	}
	//----
	//Tests for cell methods
	//----
	//Symbol
	void test_Symbol1(){
		ConwayCell c = ConwayCell(0,0,true);
		assert((c.Symbol()).compare("*") == 0);
	}

	void test_Symbol2(){
		ConwayCell c = ConwayCell(0,0,false);
		assert((c.Symbol()).compare(".") == 0);
	}
	void test_Symbol3(){
		FredkinCell c = FredkinCell(0,0,true);
		assert((c.Symbol()).compare("0") == 0);
	}
	void test_Symbol4(){
		Cell c = Cell(0,0,true);
		assert((c.Symbol()).compare("0") == 0);
	}

	//Execute
	void test_Execute1(){
		ConwayCell c= ConwayCell(0,0,true);
		c._flip = true;
		c.Execute();
		assert(!(c.IsAlive()));
	}

	void test_Execute2(){
		FredkinCell c= FredkinCell(0,0,false);
		c._flip = true;
		c.Execute();
		assert(c.IsAlive());
	}

	void test_Execute3(){
		Cell c= Cell(0,0,true);
		c.Execute();
		assert(c.IsAlive());
	}

    CPPUNIT_TEST_SUITE(TestLife);
  
    CPPUNIT_TEST(test_Life1);
    CPPUNIT_TEST(test_Life2);
    CPPUNIT_TEST(test_Life3);
    CPPUNIT_TEST(test_Conway1);
    CPPUNIT_TEST(test_Conway2);
    CPPUNIT_TEST(test_Conway3);
    CPPUNIT_TEST(test_Fredkin1);
    CPPUNIT_TEST(test_Fredkin2);
    CPPUNIT_TEST(test_Cell1);
    CPPUNIT_TEST(test_Cell2);
    CPPUNIT_TEST(test_Add_Row1);
    CPPUNIT_TEST(test_Add_Row2);
    CPPUNIT_TEST(test_Add_Row3);
    CPPUNIT_TEST(test_Population1);
    CPPUNIT_TEST(test_Population2);
    CPPUNIT_TEST(test_Population3);
    CPPUNIT_TEST(test_CheckL1);
    CPPUNIT_TEST(test_CheckL2);
    CPPUNIT_TEST(test_CheckL3);
    CPPUNIT_TEST(test_Count_Neighbors1);
    CPPUNIT_TEST(test_Count_Neighbors2);
    CPPUNIT_TEST(test_Count_Neighbors3);
    CPPUNIT_TEST(test_Generation1);
    CPPUNIT_TEST(test_Generation2);
    CPPUNIT_TEST(test_Generation3);
    CPPUNIT_TEST(test_Symbol1);
    CPPUNIT_TEST(test_Symbol2);
    CPPUNIT_TEST(test_Symbol3);
    CPPUNIT_TEST(test_Symbol4);
    CPPUNIT_TEST(test_Execute1);
    CPPUNIT_TEST(test_Execute2);
    CPPUNIT_TEST(test_Execute3);





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
