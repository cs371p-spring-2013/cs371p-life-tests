// --------
// includes
// --------

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <ostream>
#include <vector>

#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TextTestRunner.h"


#define private public
#define protected public
#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

using namespace std;

// ----------
// TestDarwin
// ----------

struct TestLife : CppUnit::TestFixture {

  // ----------------
  // life constructor
  // ----------------
  void test_life_constructor_1() {
    Life<ConwayCell> life(1, 1, ConwayCell());
    CPPUNIT_ASSERT(life.row == 3);
    CPPUNIT_ASSERT(life.col == 3);
    CPPUNIT_ASSERT(life._generation == 0);
  }

  void test_life_constructor_2() {
    Life<FredkinCell> life(1, 1, FredkinCell());
    CPPUNIT_ASSERT(life.row == 3);
    CPPUNIT_ASSERT(life.col == 3);
    CPPUNIT_ASSERT(life._generation == 0);

  }

  void test_life_constructor_3() {
    Life<Cell> life(1, 1, new FredkinCell());
    CPPUNIT_ASSERT(life.row == 3);
    CPPUNIT_ASSERT(life.col == 3);
    CPPUNIT_ASSERT(life._generation == 0);

  }

  // -------------
  // life add_cell
  // -------------
  void test_life_respawn_1() {
    Life<ConwayCell> life(1, 1, ConwayCell());
    life.respawn(0, 0);
    CPPUNIT_ASSERT(life._grid[1][1].isAlive() == true);
  }

  void test_life_respawn_2() {
    Life<FredkinCell> life(1, 1, FredkinCell());
    life.respawn(0, 0);
    CPPUNIT_ASSERT(life._grid[1][1].isAlive() == true);
  }

  void test_life_respawn_3() {
    Life<Cell> life(1, 1, new FredkinCell());
    life.respawn(0, 0);
    CPPUNIT_ASSERT(life._grid[1][1].isAlive() == true);
  }


  // --------
  // life run
  // --------
  void test_life_run_1() {
    Life<ConwayCell> life(1, 1, ConwayCell());
    life.respawn(0, 0);
    CPPUNIT_ASSERT(life._grid[1][1].isAlive() == true);
    life.run(1);
    CPPUNIT_ASSERT(life._grid[1][1].isAlive() == false);
  }

  void test_life_run_2() {
    Life<FredkinCell> life(1, 2, FredkinCell());
    life.respawn(0,0);
    life.respawn(0,1);
    CPPUNIT_ASSERT(life._grid[1][1].isAlive() == true);
    CPPUNIT_ASSERT(life._grid[1][2].isAlive() == true);
    life.run(1);
    CPPUNIT_ASSERT(life._grid[1][1].isAlive() == true);
    CPPUNIT_ASSERT(life._grid[1][2].isAlive() == true);
  }

  void test_life_run_3() {
    Life<Cell> life(1, 2, new FredkinCell());
    life.respawn(0, 0);
    life.respawn(0, 1);
    CPPUNIT_ASSERT(life._grid[1][1].get()->age() == 0);
    CPPUNIT_ASSERT(life._grid[1][2].get()->age() == 0);
    life.run(1);
    CPPUNIT_ASSERT(life._grid[1][1].get()->age() == 1);
    CPPUNIT_ASSERT(life._grid[1][2].get()->age() == 1);
    life.run(1);
  }


  void test_life_neighbors_1() {
    Life<ConwayCell> life(1, 1, ConwayCell());
    life.respawn(0,0);
    CPPUNIT_ASSERT( life.getConwayNeighborCount(1, 1) == 0);
  }

  void test_life_neighbors_2() {
    Life<FredkinCell> life(1, 2, FredkinCell());
    life.respawn(0,0);
    CPPUNIT_ASSERT(life.getFredkinNeighborCount(1, 1) == 0);
  }

  void test_life_neighbors_3() {
    Life<FredkinCell> life(3, 3, FredkinCell());
    life.respawn(2,1);
    life.respawn(2, 3);
    CPPUNIT_ASSERT(life.getFredkinNeighborCount(3, 3) == 2);
  }

  // -----------------
  // AbstractCell live
  // -----------------
  void test_abstract_cell_live_1() {
    ConwayCell c(false);
    CPPUNIT_ASSERT(c.isAlive() == false);
    c.respawn();
    CPPUNIT_ASSERT(c.isAlive() == true);
  }

  void test_abstract_cell_live_2() {
    FredkinCell c(false);
    CPPUNIT_ASSERT(c.isAlive() == false);
    c.respawn();
    CPPUNIT_ASSERT(c.isAlive() == true);
  }

  void test_abstract_cell_live_3() {
    ConwayCell c(true);
    CPPUNIT_ASSERT(c.isAlive() == true);
    c.respawn();
    CPPUNIT_ASSERT(c.isAlive() == true);
  }


  // ----------------
  // AbstractCell die
  // ----------------
  void test_abstract_cell_die_1() {
    ConwayCell c(true);
    CPPUNIT_ASSERT(c.isAlive() == true);
    c.kill();
    CPPUNIT_ASSERT(c.isAlive() == false);
  }

  void test_abstract_cell_die_2() {
    FredkinCell c(true);
    CPPUNIT_ASSERT(c.isAlive() == true);
    c.kill();
    CPPUNIT_ASSERT(c.isAlive() == false);
  }

  void test_abstract_cell_die_3() {
    ConwayCell c(false);
    CPPUNIT_ASSERT(c.isAlive() == false);
    c.kill();
    CPPUNIT_ASSERT(c.isAlive() == false);
  }

  // --------------------
  // AbstractCell isAlive
  // --------------------
  void test_abstract_cell_isAlive_1() {
    ConwayCell c(true);
    CPPUNIT_ASSERT(c.isAlive() == true);
  }

  void test_abstract_cell_isAlive_2() {
    FredkinCell c(true);
    CPPUNIT_ASSERT(c.isAlive() == true);
  }

  void test_abstract_cell_isAlive_3() {
    ConwayCell c(false);
    CPPUNIT_ASSERT(c.isAlive() == false);
  }

  // -----------------------
  // ConwayCell constructors
  // -----------------------
  void test_conway_cell_constructor_1() {
    ConwayCell c;
    CPPUNIT_ASSERT(c.isAlive() == false);
  }

  void test_conway_cell_constructor_2() {
    ConwayCell c1(false);
    CPPUNIT_ASSERT(c1.isAlive() == false);
    ConwayCell c2(true);
    CPPUNIT_ASSERT(c2.isAlive() == true);
  }

  void test_conway_cell_constructor_3() {
    ConwayCell c1();
    //CPPUNIT_ASSERT(c1.isAlive() == false);
    ConwayCell c2();
    //CPPUNIT_ASSERT(c2.isAlive() == false);
  }

  // ----------------
  // ConwayCell age
  // ----------------
  void test_conway_cell_age_1() {
    ConwayCell c;
    CPPUNIT_ASSERT(c.age() == -1);
  }

  void test_conway_cell_age_2() {
    ConwayCell c;
    CPPUNIT_ASSERT(c.age() == -1);
  }

  void test_conway_cell_age_3() {
    ConwayCell c;
    CPPUNIT_ASSERT(c.age() == -1);
  }

  // ----------------
  // ConwayCell act
  // ----------------
  void test_conway_symbol_1() {
    ConwayCell c;
    CPPUNIT_ASSERT(c.symbol() == '.');
  }

  void test_conway_symbol_2() {
    ConwayCell c(true);
    CPPUNIT_ASSERT(c.symbol() == '*');
  }

  void test_conway_symbol_3() {
    ConwayCell c(false);
    CPPUNIT_ASSERT(c.symbol() == '.');
  }

  // -----------------------
  // FredkinCell constructors
  // -----------------------
  void test_fredkin_cell_constructor_1() {
    FredkinCell c;
    CPPUNIT_ASSERT(c.isAlive() == false);
  }

  void test_fredkin_cell_constructor_2() {
    FredkinCell c1(false);
    CPPUNIT_ASSERT(c1.isAlive() == false);
    FredkinCell c2(true);
    CPPUNIT_ASSERT(c2.isAlive() == true);
  }

  void test_fredkin_cell_constructor_3() {
    FredkinCell c1(true);
    CPPUNIT_ASSERT(c1.isAlive() == true);
    FredkinCell c2(false);
    CPPUNIT_ASSERT(c2.isAlive() == false);
  }


  // ----------------
  // FredkinCell age
  // ----------------
  void test_fredkin_cell_age_1() {
    FredkinCell c;
    CPPUNIT_ASSERT(c.age() == 0);
  }

  void test_fredkin_cell_age_2() {
    FredkinCell c(false);
    CPPUNIT_ASSERT(c.age() == 0);
  }

  void test_fredkin_cell_age_3() {
    FredkinCell c(true);
    CPPUNIT_ASSERT(c.age() == 0);
  }


  // ----------------
  // Cell constructor
  // ----------------
  void test_cell_constructor_1() {
    Cell c = new ConwayCell(false);
    CPPUNIT_ASSERT(c.isAlive() == false);
  }

  void test_cell_constructor_2() {
    Cell c = new FredkinCell(false);
    CPPUNIT_ASSERT(c.isAlive() == false);
  }

  void test_cell_constructor_3() {
    Cell c1 = new ConwayCell(true);
    Cell c2 = new FredkinCell(true);
    CPPUNIT_ASSERT(c1.isAlive() == true);
    CPPUNIT_ASSERT(c2.isAlive() == true);
  }

  // ----------------
  // Cell live
  // ----------------
  void test_cell_live_1() {
    Cell c = new ConwayCell(false);
    c.respawn();
    CPPUNIT_ASSERT(c.isAlive() == true);
  }

  void test_cell_live_2() {
    Cell c = new FredkinCell(false);
    c.respawn();
    CPPUNIT_ASSERT(c.isAlive() == true);
  }

  void test_cell_live_3() {
    Cell c1 = new ConwayCell(true);
    Cell c2 = new FredkinCell(true);
    c1.respawn();
    c2.respawn();
    CPPUNIT_ASSERT(c1.isAlive() == true);
    CPPUNIT_ASSERT(c2.isAlive() == true);
  }

  // ----------------
  // Cell die
  // ----------------
  void test_cell_die_1() {
    Cell c = new ConwayCell(true);
    c.kill();
    CPPUNIT_ASSERT(c.isAlive() == false);
  }

  void test_cell_die_2() {
    Cell c = new FredkinCell(true);
    c.kill();
    CPPUNIT_ASSERT(c.isAlive() == false);
  }

  void test_cell_die_3() {
    Cell c1 = new ConwayCell(true);
    Cell c2 = new FredkinCell(true);
    c1.kill();
    c2.kill();
    CPPUNIT_ASSERT(c1.isAlive() == false);
    CPPUNIT_ASSERT(c2.isAlive() == false);
  }

  // ----------------
  // Cell isAlive
  // ----------------
  void test_cell_isAlive_1() {
    Cell c = new ConwayCell(false);
    CPPUNIT_ASSERT(c.isAlive() == false);
  }

  void test_cell_isAlive_2() {
    Cell c = new FredkinCell(false);
    CPPUNIT_ASSERT(c.isAlive() == false);
  }

  void test_cell_isAlive_3() {
    Cell c = new ConwayCell(true);
    CPPUNIT_ASSERT(c.isAlive() == true);
  }


  // ---------
  // TestSuite
  // ---------
  CPPUNIT_TEST_SUITE(TestLife);

  CPPUNIT_TEST(test_life_constructor_1);
  CPPUNIT_TEST(test_life_constructor_2);
  CPPUNIT_TEST(test_life_constructor_3);

  CPPUNIT_TEST(test_life_respawn_1);
  CPPUNIT_TEST(test_life_respawn_2);
  CPPUNIT_TEST(test_life_respawn_3);

  CPPUNIT_TEST(test_life_run_1);
  CPPUNIT_TEST(test_life_run_2);
  CPPUNIT_TEST(test_life_run_3);

  CPPUNIT_TEST(test_life_neighbors_1);
  CPPUNIT_TEST(test_life_neighbors_2);
  CPPUNIT_TEST(test_life_neighbors_3);


  CPPUNIT_TEST(test_abstract_cell_live_1);
  CPPUNIT_TEST(test_abstract_cell_live_2);
  CPPUNIT_TEST(test_abstract_cell_live_3);

  CPPUNIT_TEST(test_abstract_cell_die_1);
  CPPUNIT_TEST(test_abstract_cell_die_2);
  CPPUNIT_TEST(test_abstract_cell_die_3);

  CPPUNIT_TEST(test_abstract_cell_isAlive_1);
  CPPUNIT_TEST(test_abstract_cell_isAlive_2);
  CPPUNIT_TEST(test_abstract_cell_isAlive_3);

  CPPUNIT_TEST(test_conway_cell_constructor_1);
  CPPUNIT_TEST(test_conway_cell_constructor_2);
  CPPUNIT_TEST(test_conway_cell_constructor_3);

  CPPUNIT_TEST(test_conway_cell_age_1);
  CPPUNIT_TEST(test_conway_cell_age_2);
  CPPUNIT_TEST(test_conway_cell_age_3);


  CPPUNIT_TEST(test_conway_symbol_1);
  CPPUNIT_TEST(test_conway_symbol_2);
  CPPUNIT_TEST(test_conway_symbol_3);



  CPPUNIT_TEST(test_fredkin_cell_constructor_1);
  CPPUNIT_TEST(test_fredkin_cell_constructor_2);
  CPPUNIT_TEST(test_fredkin_cell_constructor_3);

  CPPUNIT_TEST(test_fredkin_cell_age_1);
  CPPUNIT_TEST(test_fredkin_cell_age_2);
  CPPUNIT_TEST(test_fredkin_cell_age_3);

  CPPUNIT_TEST(test_cell_constructor_1);
  CPPUNIT_TEST(test_cell_constructor_2);
  CPPUNIT_TEST(test_cell_constructor_3);

  CPPUNIT_TEST(test_cell_live_1);
  CPPUNIT_TEST(test_cell_live_2);
  CPPUNIT_TEST(test_cell_live_3);

  CPPUNIT_TEST(test_cell_die_1);
  CPPUNIT_TEST(test_cell_die_2);
  CPPUNIT_TEST(test_cell_die_3);

  CPPUNIT_TEST(test_cell_isAlive_1);
  CPPUNIT_TEST(test_cell_isAlive_2);
  CPPUNIT_TEST(test_cell_isAlive_3);



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
