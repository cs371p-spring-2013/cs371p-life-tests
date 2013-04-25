#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#define private public
#define protected public

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>


#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TextTestRunner.h"
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Life.h"

struct TestLife : CppUnit::TestFixture {

    void test_life1() {    
        Life<ConwayCell> conway (109, 69, ConwayCell(false));
    	for(int j = 34; j < 75; ++j) {
	      conway.gridCellType(j,34, ConwayCell(true));
          conway.gridCellType(j+1,34, ConwayCell(true));
          conway.gridCellType(j+2,34, ConwayCell(true));
          conway.gridCellType(j+3,34, ConwayCell(true));
          conway.gridCellType(j+4,34, ConwayCell(true));
          j+=5;
        }
        CPPUNIT_ASSERT_EQUAL(false,conway._grid[0][0].getAlive());
        CPPUNIT_ASSERT_EQUAL(true,conway._grid[34][34].getAlive());
    	conway.simulate(283);
        CPPUNIT_ASSERT_EQUAL(false,conway._grid[10][10].getAlive());
        CPPUNIT_ASSERT_EQUAL(true,conway._grid[24][8].getAlive());
		CPPUNIT_ASSERT_EQUAL(492,conway._population);
		CPPUNIT_ASSERT_EQUAL(3,conway.ctNDiag(24,8));
		CPPUNIT_ASSERT_EQUAL(0,conway.ctNSq(24,8));
    }


    void test_life2() {    
        Life<FredkinCell> fred (10, 10, FredkinCell(false));
        fred.gridCellType(1,4, FredkinCell(true));
        fred.gridCellType(4,4, FredkinCell(true));
        fred.gridCellType(3,4, FredkinCell(true));
        fred.gridCellType(2,4, FredkinCell(true));
        fred.gridCellType(0,4, FredkinCell(true));
        CPPUNIT_ASSERT_EQUAL(true,fred._grid[4][4].getAlive());
        CPPUNIT_ASSERT_EQUAL(false,fred._grid[0][0].getAlive());
		fred.simulate(1);
        CPPUNIT_ASSERT_EQUAL(true,fred._grid[0][4].getAlive());
        CPPUNIT_ASSERT_EQUAL(false,fred._grid[1][4].getAlive());
		CPPUNIT_ASSERT_EQUAL(13,fred._population);
		CPPUNIT_ASSERT_EQUAL(2,fred.ctNDiag(0,4));
		CPPUNIT_ASSERT_EQUAL(2,fred.ctNSq(0,4));
    }

    void test_life3() {    
        Life<Cell> fred (6, 5, new FredkinCell(false));
        fred.gridCellType(1,1, new FredkinCell(true));
        fred.gridCellType(1,3, new FredkinCell(true));
        fred.gridCellType(2,2, new FredkinCell(true));
        fred.gridCellType(3,2, new FredkinCell(true));
        fred.gridCellType(4,1, new FredkinCell(true));
        fred.gridCellType(4,3, new FredkinCell(true));
		CPPUNIT_ASSERT_EQUAL(true,fred._grid[1][1].getAlive());
        CPPUNIT_ASSERT_EQUAL(false,fred._grid[0][0].getAlive());
		fred.simulate(1);
        CPPUNIT_ASSERT_EQUAL(true,fred._grid[3][2].getAlive());
        CPPUNIT_ASSERT_EQUAL(true,fred._grid[1][4].getAlive());
		CPPUNIT_ASSERT_EQUAL(12,fred._population);
		CPPUNIT_ASSERT_EQUAL(0,fred.ctNDiag(3,2));
		CPPUNIT_ASSERT_EQUAL(2,fred.ctNSq(3,2));
      }

    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST(test_life1);
    CPPUNIT_TEST(test_life2);
    CPPUNIT_TEST(test_life3);

    CPPUNIT_TEST_SUITE_END();
};

struct TestAbs : CppUnit::TestFixture {
  
  void test_ctr1() {
    ConwayCell conway(true);
    AbstractCell& abs = conway;
    CPPUNIT_ASSERT_EQUAL(true,abs.getAlive());
  }
  
  void test_ctr2() {
    FredkinCell fred(true);
    AbstractCell& abs = fred;
    CPPUNIT_ASSERT_EQUAL(true,abs.getAlive());
  }

  void test_ctr3() {
    ConwayCell conway(false);
    AbstractCell& abs = conway;
    CPPUNIT_ASSERT_EQUAL(false,abs.getAlive());
  }

  void test_updateState1() {
    ConwayCell conway(false);
    AbstractCell& abs = conway;
    abs.updateState();
    CPPUNIT_ASSERT_EQUAL(true,abs.getAlive());
  }

   void test_updateState2() {
     ConwayCell conway(true);
     AbstractCell& abs = conway;
     abs.updateState();
     CPPUNIT_ASSERT_EQUAL(false,abs.getAlive());
   }

  void test_updateState3() {
    FredkinCell fred(false);
    AbstractCell& abs = fred;
    abs.updateState();
    CPPUNIT_ASSERT_EQUAL(true,abs.getAlive());
  }

  void test_alive1() {
    ConwayCell conway(false);
    AbstractCell& abs = conway;
    CPPUNIT_ASSERT_EQUAL(false,abs.getAlive());
  }

   void test_alive2() {
     ConwayCell conway(true);
     AbstractCell& abs = conway;
     CPPUNIT_ASSERT_EQUAL(true,abs.getAlive());
   }

  void test_alive3() {
    FredkinCell fred(false);
    AbstractCell& abs = fred;
    CPPUNIT_ASSERT_EQUAL(false,abs.getAlive());
  }



  CPPUNIT_TEST_SUITE(TestAbs); 
  CPPUNIT_TEST(test_ctr1);
  CPPUNIT_TEST(test_ctr2);
  CPPUNIT_TEST(test_ctr3);
  CPPUNIT_TEST(test_updateState1);
  CPPUNIT_TEST(test_updateState2);
  CPPUNIT_TEST(test_updateState3);
  CPPUNIT_TEST(test_alive1);
  CPPUNIT_TEST(test_alive2);
  CPPUNIT_TEST(test_alive3);
  CPPUNIT_TEST_SUITE_END();
};

struct TestConway : CppUnit::TestFixture {
    
    void test_ctr1() {
        ConwayCell conway(true);
        CPPUNIT_ASSERT_EQUAL(true,conway.getAlive());
    }
    
    void test_ctr2() {
        ConwayCell conway(false);
        CPPUNIT_ASSERT_EQUAL(false,conway.getAlive());
    }
    
    void test_ctr3() {
        ConwayCell conway(true);
        conway.updateState();
        CPPUNIT_ASSERT_EQUAL(false,conway.getAlive());
    }
    
    void test_updateState1() {
        ConwayCell conway(true);
        conway.updateState();
        CPPUNIT_ASSERT_EQUAL(false,conway.getAlive());
    }
    
    void test_updateState2() {
        ConwayCell conway(false);
        conway.updateState();
        CPPUNIT_ASSERT_EQUAL(true,conway.getAlive());
    }
    
    void test_updateState3() {
        ConwayCell conway(true);
        conway.updateState();
        conway.updateState();
        CPPUNIT_ASSERT_EQUAL(true,conway.getAlive());
    }
    
    void test_alive1() {
        ConwayCell conway(false);
        CPPUNIT_ASSERT_EQUAL(false,conway.getAlive());
    }
    
    void test_alive2() {
        ConwayCell conway(true);
        CPPUNIT_ASSERT_EQUAL(true,conway.getAlive());
    }
    
    void test_alive3() {
        ConwayCell conway(true);
        CPPUNIT_ASSERT_EQUAL(true,conway.getAlive());
    }
    
    void test_evolve1() {
        ConwayCell conway(true);
        CPPUNIT_ASSERT_EQUAL(false,conway.evolve());
    }
    
    void test_checkNeighbors1() {
        ConwayCell conway(true);
        CPPUNIT_ASSERT_EQUAL(true, conway.checkNeighbors (0,0));
    }
    
    void test_checkNeighbors2() {
        ConwayCell conway(true);
        CPPUNIT_ASSERT_EQUAL(false, conway.checkNeighbors (1,1));
    }
    
    void test_checkNeighbors3() {
        ConwayCell conway(true);
        CPPUNIT_ASSERT_EQUAL(false, conway.checkNeighbors (2,1));
    }
    
    void test_cell1() {
        ConwayCell conway(false);
        CPPUNIT_ASSERT_EQUAL('.', conway.cellChar());
    }
    
    void test_cell2() {
        ConwayCell conway(true);
        CPPUNIT_ASSERT_EQUAL('*', conway.cellChar());
    }
    
    void test_cell3() {
        ConwayCell conway(true);
        conway.updateState();
        CPPUNIT_ASSERT_EQUAL('.', conway.cellChar());
    }
    
    CPPUNIT_TEST_SUITE(TestConway);
    CPPUNIT_TEST(test_ctr1);
    CPPUNIT_TEST(test_ctr2);
    CPPUNIT_TEST(test_ctr3);
    CPPUNIT_TEST(test_updateState1);
    CPPUNIT_TEST(test_updateState2);
    CPPUNIT_TEST(test_updateState3);
    CPPUNIT_TEST(test_alive1);
    CPPUNIT_TEST(test_alive2);
    CPPUNIT_TEST(test_alive3);
    CPPUNIT_TEST(test_evolve1);
    CPPUNIT_TEST(test_checkNeighbors1);
    CPPUNIT_TEST(test_checkNeighbors2);
    CPPUNIT_TEST(test_checkNeighbors3);
    CPPUNIT_TEST(test_cell1);
    CPPUNIT_TEST(test_cell2);
    CPPUNIT_TEST(test_cell3);
    
    CPPUNIT_TEST_SUITE_END();
};


struct TestFredkin : CppUnit::TestFixture {
    
    void test_ctr1() {
        FredkinCell fred(true);
        CPPUNIT_ASSERT_EQUAL(true,fred.getAlive());
    }
    
    void test_ctr2() {
        FredkinCell fred(false);
        CPPUNIT_ASSERT_EQUAL(false,fred.getAlive());
    }
    
    void test_ctr3() {
        FredkinCell fred(true);
        fred.updateState();
        CPPUNIT_ASSERT_EQUAL(false,fred.getAlive());
    }
    
    void test_updateState1() {
        FredkinCell fred(true);
        fred.updateState();
        CPPUNIT_ASSERT_EQUAL(false,fred.getAlive());
    }
    
    void test_updateState2() {
        FredkinCell fred(false);
        fred.updateState();
        CPPUNIT_ASSERT_EQUAL(true,fred.getAlive());
    }
    
    void test_updateState3() {
        FredkinCell fred(true);
        fred.updateState();
        fred.updateState();
        CPPUNIT_ASSERT_EQUAL(true,fred.getAlive());
    }
    
    void test_alive1() {
        FredkinCell fred(false);
        CPPUNIT_ASSERT_EQUAL(false,fred.getAlive());
    }
    
    void test_alive2() {
        FredkinCell fred(true);
        CPPUNIT_ASSERT_EQUAL(true,fred.getAlive());
    }
    
    void test_alive3() {
        FredkinCell fred(true);
        CPPUNIT_ASSERT_EQUAL(true,fred.getAlive());
    }
    
    void test_evolve1() {
        FredkinCell fred(true);
        CPPUNIT_ASSERT_EQUAL(false,fred.evolve());
    }
    
    void test_checkNeighbors1() {
        FredkinCell fred(true);
        CPPUNIT_ASSERT_EQUAL(true, fred.checkNeighbors (0,0));
    }
    
    void test_checkNeighbors2() {
        FredkinCell fred(true);
        CPPUNIT_ASSERT_EQUAL(false, fred.checkNeighbors (1,0));
    }
    
    void test_checkNeighbors3() {
        FredkinCell fred(true);
        CPPUNIT_ASSERT_EQUAL(true, fred.checkNeighbors (2,0));
    }
    
    void test_cell1() {
        FredkinCell fred(true);
        CPPUNIT_ASSERT_EQUAL('0', fred.cellChar());
    }
    
    void test_cell2() {
        FredkinCell fred(true);
        fred.checkNeighbors (2,0);
        CPPUNIT_ASSERT_EQUAL('0', fred.cellChar());
    }
    
    void test_cell3() {
        FredkinCell fred(true);
        fred.updateState();
        CPPUNIT_ASSERT_EQUAL('-', fred.cellChar());
    }
    
    CPPUNIT_TEST_SUITE(TestFredkin);
    CPPUNIT_TEST(test_ctr1);
    CPPUNIT_TEST(test_ctr2);
    CPPUNIT_TEST(test_ctr3);
    CPPUNIT_TEST(test_updateState1);
    CPPUNIT_TEST(test_updateState2);
    CPPUNIT_TEST(test_updateState3);
    CPPUNIT_TEST(test_alive1);
    CPPUNIT_TEST(test_alive2);
    CPPUNIT_TEST(test_alive3);
    CPPUNIT_TEST(test_evolve1);
    CPPUNIT_TEST(test_checkNeighbors1);
    CPPUNIT_TEST(test_checkNeighbors1);
    CPPUNIT_TEST(test_checkNeighbors1);
    CPPUNIT_TEST(test_cell1);
    CPPUNIT_TEST(test_cell2);
    CPPUNIT_TEST(test_cell3);
    
    CPPUNIT_TEST_SUITE_END();
};

struct TestCell : CppUnit::TestFixture {

    void test_ctr1() {    
        Cell fred = new FredkinCell(true);
        CPPUNIT_ASSERT_EQUAL(true,fred.getAlive());
    }

    void test_ctr2() {
        Cell fred = new FredkinCell(false);
        CPPUNIT_ASSERT_EQUAL(false,fred.getAlive());
    }

    void test_ctr3() {
        Cell fred = new FredkinCell(true);
        fred.updateState();
        CPPUNIT_ASSERT_EQUAL(false,fred.getAlive());
    }
    
    void test_updateState1() {
        Cell fred = new FredkinCell(true);
        fred.updateState();
        CPPUNIT_ASSERT_EQUAL(false,fred.getAlive());
    }
    
    void test_updateState2() {
        Cell fred = new FredkinCell(false);
        fred.updateState();
        CPPUNIT_ASSERT_EQUAL(true,fred.getAlive());
    }
    
    void test_updateState3() {
		Cell fred = new FredkinCell(true);
        fred.updateState();
        fred.updateState();
        CPPUNIT_ASSERT_EQUAL(true,fred.getAlive());
    }
    
    void test_alive1() {
        Cell fred = new FredkinCell(false);
        CPPUNIT_ASSERT_EQUAL(false,fred.getAlive());
    }
    
    void test_alive2() {
        Cell fred = new FredkinCell(true);
        CPPUNIT_ASSERT_EQUAL(true,fred.getAlive());
    }
    
    void test_alive3() {
        Cell fred = new FredkinCell(true);
        CPPUNIT_ASSERT_EQUAL(true,fred.getAlive());
    }
    
    void test_evolve1() {
		Cell fred = new FredkinCell(true);
        CPPUNIT_ASSERT_EQUAL(false,fred.evolve());
    }
    
    void test_checkNeighbors1() {
		Cell fred = new FredkinCell(true);
        CPPUNIT_ASSERT_EQUAL(true, fred.checkNeighbors (0,0));
    }
    
    void test_checkNeighbors2() {
        Cell fred = new FredkinCell(true);
        CPPUNIT_ASSERT_EQUAL(false, fred.checkNeighbors (1,0));
    }
    
    void test_checkNeighbors3() {
		Cell fred = new FredkinCell(true);
        CPPUNIT_ASSERT_EQUAL(true, fred.checkNeighbors (2,0));
    }
    
    void test_cell1() {
		Cell fred = new FredkinCell(true);
        CPPUNIT_ASSERT_EQUAL('0', fred.cellChar());
    }
    
    void test_cell2() {
        Cell fred = new FredkinCell(true);
        fred.checkNeighbors (2,0);
        CPPUNIT_ASSERT_EQUAL('0', fred.cellChar());
    }
    
    void test_cell3() {
		Cell fred = new FredkinCell(true);
        fred.updateState();
        CPPUNIT_ASSERT_EQUAL('-', fred.cellChar());
    }
    
    CPPUNIT_TEST_SUITE(TestCell);
    CPPUNIT_TEST(test_ctr1);
    CPPUNIT_TEST(test_ctr2);
    CPPUNIT_TEST(test_ctr3);
    CPPUNIT_TEST(test_updateState1);
    CPPUNIT_TEST(test_updateState2);
    CPPUNIT_TEST(test_updateState3);
    CPPUNIT_TEST(test_alive1);
    CPPUNIT_TEST(test_alive2);
    CPPUNIT_TEST(test_alive3);
    CPPUNIT_TEST(test_evolve1);
    CPPUNIT_TEST(test_checkNeighbors1);
    CPPUNIT_TEST(test_checkNeighbors1);
    CPPUNIT_TEST(test_checkNeighbors1);
    CPPUNIT_TEST(test_cell1);
    CPPUNIT_TEST(test_cell2);
    CPPUNIT_TEST(test_cell3);

    CPPUNIT_TEST_SUITE_END(); 
};





int main()
{
  using namespace std;
  ios_base::sync_with_stdio(false);
  cout << "TestLife.c++\n";
  CppUnit::TextTestRunner tr;
  tr.addTest(TestLife::suite());
  tr.addTest(TestAbs::suite());
  tr.addTest(TestConway::suite());
  tr.addTest(TestFredkin::suite());
  tr.addTest(TestCell::suite());
  tr.run();
  cout << "Done. \n";

  return 0;
}
