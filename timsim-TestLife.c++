// -------------------------
// projects/life/TestLife.c++
// -------------------------

// --------
// includes
// --------

#include <iostream>  // ios_base
#include <cstdlib>
#include <cassert>   // assert
#include <vector>


#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define private public

#include "Life.h"
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"

#undef private

// -------------
// TestDarwin
// -------------
struct TestLife : CppUnit::TestFixture {

	void constructor1 () {
		Life<Cell> l;
        CPPUNIT_ASSERT(l.rows == 0);
        CPPUNIT_ASSERT(l.cols == 0);
    }

    void constructor2 () {
		Life<ConwayCell> l;
        CPPUNIT_ASSERT(l.rows == 0);
        CPPUNIT_ASSERT(l.cols == 0);
    }
	
	void constructor3 () {
		Life<FredkinCell> l;
        CPPUNIT_ASSERT(l.rows == 0);
        CPPUNIT_ASSERT(l.cols == 0);
    }

    void read1 () {
		Life<Cell> l;
		l.read("RunLifeCell.in");
        CPPUNIT_ASSERT(l.rows == 20);
        CPPUNIT_ASSERT(l.cols == 20);
        //l.print();
    }

    void read2 () {
		Life<FredkinCell> l;
		l.read("RunLifeFredkin.in");
        CPPUNIT_ASSERT(l.rows == 20);
        CPPUNIT_ASSERT(l.cols == 20);
        //l.print();
    }

    void read3 () {
		Life<FredkinCell> l;
		l.read("RunLifeConway.in");
        CPPUNIT_ASSERT(l.rows == 109);
        CPPUNIT_ASSERT(l.cols == 69);
        //l.print();
    }

    void cell_mutate1 () {
		Life<Cell> l;
		l.read("RunLifeCell.in");
        CPPUNIT_ASSERT(l.rows == 20);
        CPPUNIT_ASSERT(l.cols == 20);
        CPPUNIT_ASSERT(l.board[0][0].name() == "FredkinCell");
        CPPUNIT_ASSERT(l.board[8][10].name() == "FredkinCell");
        CPPUNIT_ASSERT(l.board[8][10].is_alive() == false);
        l.board[8][10].mutate(l.getneighborsFredkin(8,10));
        CPPUNIT_ASSERT(l.board[8][10].is_alive() == true);

    }

    void cell_mutate2 () {
		Life<Cell> l;
		l.read("RunLifeCell.in");
        CPPUNIT_ASSERT(l.rows == 20);
        CPPUNIT_ASSERT(l.cols == 20);
        CPPUNIT_ASSERT(l.board[0][0].name() == "FredkinCell");
        l.board[8][10].mutate(l.getneighborsFredkin(8,10));
        CPPUNIT_ASSERT(l.board[8][10].is_alive() == true);
    }

    void cell_mutate3 () {
		Life<Cell> l;
		l.read("RunLifeCell.in");
        CPPUNIT_ASSERT(l.rows == 20);
        CPPUNIT_ASSERT(l.cols == 20);
        CPPUNIT_ASSERT(l.board[0][0].name() == "FredkinCell");
        l.board[8][10].mutate(l.getneighborsFredkin(8,10));
        CPPUNIT_ASSERT(l.board[8][10].is_alive() == true);
        l.board[8][10].mutate(l.getneighborsFredkin(8,10));
        l.board[8][10].mutate(l.getneighborsFredkin(8,10));
        CPPUNIT_ASSERT(l.board[8][10].is_alive() == true);
        CPPUNIT_ASSERT(l.board[8][10].name() == "ConwayCell");
    }	

    void name1 () {
		Life<ConwayCell> l;
		l.read("RunLifeConway.in");
        CPPUNIT_ASSERT(l.rows == 109);
        CPPUNIT_ASSERT(l.cols == 69);
        CPPUNIT_ASSERT(l.board[0][0].name() == "ConwayCell");
        //l.print();
    }

    void name2 () {
		Life<ConwayCell> l;
		l.read("RunLifeConway.in");
        CPPUNIT_ASSERT(l.board[0][0].name() == "ConwayCell");
        //l.print();
    }

    void name3 () {
		Life<Cell> l;
		l.read("RunLifeCell.in");
        CPPUNIT_ASSERT(l.board[0][0].name() == "FredkinCell");
        //l.print();
    }
	

    void generation1() {
    	Life<FredkinCell> l;
		l.read("RunLifeFredkin.in");
		CPPUNIT_ASSERT(l.board[9][10].is_alive() == true);
		l.one_gen();
		CPPUNIT_ASSERT(l.board[9][10].is_alive() == false);
    }

    void generation2() {
    	Life<FredkinCell> l;
		l.read("RunLifeFredkin.in");
		CPPUNIT_ASSERT(l.board[9][10].is_alive() == true);
		l.one_gen();
		CPPUNIT_ASSERT(l.board[9][10].is_alive() == false);
		l.one_gen();
		CPPUNIT_ASSERT(l.board[9][10].is_alive() == false);
    }

    void generation3() {
    	Life<FredkinCell> l;
		l.read("RunLifeFredkin.in");
		CPPUNIT_ASSERT(l.board[9][10].is_alive() == true);
		l.one_gen();
		CPPUNIT_ASSERT(l.board[9][10].is_alive() == false);
		l.one_gen();
		CPPUNIT_ASSERT(l.board[9][10].is_alive() == false);
		l.one_gen();
		CPPUNIT_ASSERT(l.board[9][10].is_alive() == false);
    }

    void simulate1() {
    	Life<FredkinCell> l;
		l.read("RunLifeFredkin.in");
		CPPUNIT_ASSERT(l.board[9][10].is_alive() == true);
		l.simulate(1,0);
		CPPUNIT_ASSERT(l.board[9][10].is_alive() == false);
    }

    void simulate2() {
    	Life<FredkinCell> l;
		l.read("RunLifeFredkin.in");
		l.simulate(2,0);
		CPPUNIT_ASSERT(l.board[9][10].is_alive() == false);
    }

    void simulate3() {
    	Life<FredkinCell> l;
		l.read("RunLifeFredkin.in");
		l.simulate(3,0);
		CPPUNIT_ASSERT(l.board[9][10].is_alive() == false);
    }
   
    void neighbors1 () {
    	Life<FredkinCell> l;
		l.read("LifeTest.in");
		//l.print();
		/*
		-0------0-0-------0-
		00----------------0-
		--------------------
		--------------------
		--------------------
		--------------------
		---------000--------
		00-------0-0------0-
		-0-------000--------
		00------------------
		----------0---------
		---------0-0--------
		----------0---------
		--------------------
		---------0-0--------
		--------------------
		---------0-0--------
		--------------------
		-0------0-0---------
		--------0-0---------*/
		CPPUNIT_ASSERT(l.rows == 20);
        CPPUNIT_ASSERT(l.cols == 20);
        CPPUNIT_ASSERT(l.getneighborsConway(0,0) == 3);
		CPPUNIT_ASSERT(l.getneighborsFredkin(0,0) == 2);
		CPPUNIT_ASSERT(l.getneighborsConway(0,9) == 2);
		CPPUNIT_ASSERT(l.getneighborsFredkin(0,9) == 2);
		CPPUNIT_ASSERT(l.getneighborsConway(0,19) == 2);
		CPPUNIT_ASSERT(l.getneighborsFredkin(0,19) == 1);
    }

    void neighbors2 () {
    	Life<FredkinCell> l;
		l.read("LifeTest.in");
		//l.print();
		/*
		-0------0-0-------0-
		00----------------0-
		--------------------
		--------------------
		--------------------
		--------------------
		---------000--------
		00-------0-0------0-
		-0-------000--------
		00------------------
		----------0---------
		---------0-0--------
		----------0---------
		--------------------
		---------0-0--------
		--------------------
		---------0-0--------
		--------------------
		-0------0-0---------
		--------0-0---------*/
		CPPUNIT_ASSERT(l.rows == 20);
        CPPUNIT_ASSERT(l.cols == 20);
        
		CPPUNIT_ASSERT(l.getneighborsConway(8,0) == 5);
		CPPUNIT_ASSERT(l.getneighborsFredkin(8,0) == 3);
		CPPUNIT_ASSERT(l.getneighborsConway(7,10) == 8);
		CPPUNIT_ASSERT(l.getneighborsFredkin(7,10) == 4);
		CPPUNIT_ASSERT(l.getneighborsConway(7,19) == 1);
		CPPUNIT_ASSERT(l.getneighborsFredkin(7,19) == 1);
		CPPUNIT_ASSERT(l.getneighborsConway(0,19) == 2);
		CPPUNIT_ASSERT(l.getneighborsFredkin(0,19) == 1);	
    }

    void neighbors3 () {
    	Life<FredkinCell> l;
		l.read("LifeTest.in");
		//l.print();
		/*
		-0------0-0-------0-
		00----------------0-
		--------------------
		--------------------
		--------------------
		--------------------
		---------000--------
		00-------0-0------0-
		-0-------000--------
		00------------------
		----------0---------
		---------0-0--------
		----------0---------
		--------------------
		---------0-0--------
		--------------------
		---------0-0--------
		--------------------
		-0------0-0---------
		--------0-0---------*/
		CPPUNIT_ASSERT(l.rows == 20);
        CPPUNIT_ASSERT(l.cols == 20);
        CPPUNIT_ASSERT(l.getneighborsConway(11,10) == 4);
		CPPUNIT_ASSERT(l.getneighborsFredkin(11,10) == 4);
		CPPUNIT_ASSERT(l.getneighborsConway(15,10) == 4);
		CPPUNIT_ASSERT(l.getneighborsFredkin(15,10) == 0);
		CPPUNIT_ASSERT(l.getneighborsConway(19,0) == 1);
		CPPUNIT_ASSERT(l.getneighborsFredkin(19,0) == 0);
		CPPUNIT_ASSERT(l.getneighborsConway(19,9) == 4);
		CPPUNIT_ASSERT(l.getneighborsFredkin(19,9) == 2);
    }


	// -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST(constructor1);
    CPPUNIT_TEST(constructor2);
    CPPUNIT_TEST(constructor3);
    CPPUNIT_TEST(read1);
    CPPUNIT_TEST(read2);
    CPPUNIT_TEST(read3);
    CPPUNIT_TEST(cell_mutate1);
    CPPUNIT_TEST(cell_mutate2);
    CPPUNIT_TEST(cell_mutate3);
    CPPUNIT_TEST(name1);
    CPPUNIT_TEST(name2);
    CPPUNIT_TEST(name3);
    CPPUNIT_TEST(generation1);
    CPPUNIT_TEST(generation2);
    CPPUNIT_TEST(generation3);
    CPPUNIT_TEST(simulate1);
    CPPUNIT_TEST(simulate2);
    CPPUNIT_TEST(simulate3);
    CPPUNIT_TEST(neighbors1);
    CPPUNIT_TEST(neighbors2);
    CPPUNIT_TEST(neighbors3);


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
