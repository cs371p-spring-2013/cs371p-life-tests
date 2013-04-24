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
    CPPUNIT_ASSERT(life._rows == 1);
    CPPUNIT_ASSERT(life._cols == 1);
    CPPUNIT_ASSERT(life._latentBoard[0][0].isAlive() == false);
  }

  void test_life_constructor_2() {
    Life<FredkinCell> life(1, 1, FredkinCell());
    CPPUNIT_ASSERT(life._rows == 1);
    CPPUNIT_ASSERT(life._cols == 1);
    CPPUNIT_ASSERT(life._latentBoard[0][0].isAlive() == false);
  }

  void test_life_constructor_3() {
    Life<Cell> life(1, 1, new FredkinCell());
    CPPUNIT_ASSERT(life._rows == 1);
    CPPUNIT_ASSERT(life._cols == 1);
    CPPUNIT_ASSERT(life._latentBoard[0][0].isAlive() == false);
  }

  // -------------
  // life add_cell
  // -------------
  void test_life_add_cell_1() {
    Life<ConwayCell> life(1, 1, ConwayCell());
    life.add_cell(0, 0, ConwayCell(true));
    CPPUNIT_ASSERT(life._latentBoard[0][0].isAlive() == true);
  }

  void test_life_add_cell_2() {
    Life<FredkinCell> life(1, 1, FredkinCell());
    life.add_cell(0, 0, FredkinCell(true));
    CPPUNIT_ASSERT(life._latentBoard[0][0].isAlive() == true);
  }

  void test_life_add_cell_3() {
    Life<Cell> life(1, 1, new FredkinCell());
    life.add_cell(0, 0, new FredkinCell(true));
    CPPUNIT_ASSERT(life._latentBoard[0][0].isAlive() == true);
  }

  // --------
  // life run
  // --------
  void test_life_run_1() {
    Life<ConwayCell> life(1, 1, ConwayCell());
    life.add_cell(0, 0, ConwayCell(true));
    CPPUNIT_ASSERT(life._latentBoard[0][0].isAlive() == true);
    life.run(1);
    CPPUNIT_ASSERT(life._latentBoard[0][0].isAlive() == false);
  }

  void test_life_run_2() {
    Life<FredkinCell> life(1, 2, FredkinCell());
    life.add_cell(0, 0, FredkinCell(true));
    life.add_cell(0, 1, FredkinCell(true));
    CPPUNIT_ASSERT(life._latentBoard[0][0].isAlive() == true);
    CPPUNIT_ASSERT(life._latentBoard[0][1].isAlive() == true);
    life.run(1);
    CPPUNIT_ASSERT(life._latentBoard[0][0].isAlive() == true);
    CPPUNIT_ASSERT(life._latentBoard[0][1].isAlive() == true);
  }

  void test_life_run_3() {
    Life<Cell> life(1, 2, new FredkinCell());
    life.add_cell(0, 0, new FredkinCell(true));
    life.add_cell(0, 1, new FredkinCell(true));
    CPPUNIT_ASSERT(life._latentBoard[0][0].get()->age() == 0);
    CPPUNIT_ASSERT(life._latentBoard[0][1].get()->age() == 0);
    life.run(1);
    CPPUNIT_ASSERT(life._latentBoard[0][0].get()->age() == 1);
    CPPUNIT_ASSERT(life._latentBoard[0][1].get()->age() == 1);
    life.run(1);
    CPPUNIT_ASSERT(life._latentBoard[0][0].get()->age() == 0);
    CPPUNIT_ASSERT(life._latentBoard[0][1].get()->age() == 0);
  }

  // --------
  // life run
  // --------
  void test_life_fill_neighbors_1() {
    Life<ConwayCell> life(1, 1, ConwayCell());
    life.add_cell(0, 0, ConwayCell(true));
    vector< vector< bool > > neighbors(3, vector< bool >(3, false));
    life.fill_neighbors(neighbors, 0, 0);
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        CPPUNIT_ASSERT(neighbors[i][j] == false);
      }
    }
  }

  void test_life_fill_neighbors_2() {
    Life<FredkinCell> life(1, 2, FredkinCell());
    life.add_cell(0, 0, FredkinCell(true));
    life.add_cell(0, 1, FredkinCell(true));
    vector< vector< bool > > neighbors(3, vector< bool >(3, false));
    life.fill_neighbors(neighbors, 0, 0);
    CPPUNIT_ASSERT(neighbors[1][1] == false);
    CPPUNIT_ASSERT(neighbors[1][2] == true);
  }

  void test_life_fill_neighbors_3() {
    Life<Cell> life(2, 1, new FredkinCell());
    life.add_cell(0, 0, new FredkinCell(true));
    life.add_cell(1, 0, new FredkinCell(true));
    vector< vector< bool > > neighbors(3, vector< bool >(3, false));
    life.fill_neighbors(neighbors, 0, 0);
    CPPUNIT_ASSERT(neighbors[1][1] == false);
    CPPUNIT_ASSERT(neighbors[2][1] == true);
  }

  // ----------
  // life write
  // ----------
  void test_life_write_1() {
    Life<ConwayCell> life(1, 1, ConwayCell());
    string s = "Generation = 0, Population = 0.\n";
    s += ".\n\n";
    ostringstream oss;
    life.write(oss);
    CPPUNIT_ASSERT(s == oss.str());
  }

  void test_life_write_2() {
    Life<FredkinCell> life(1, 1, FredkinCell());
    life.add_cell(0, 0, FredkinCell(true));
    string s = "Generation = 0, Population = 1.\n";
    s += "0\n\n";
    ostringstream oss;
    life.write(oss);
    CPPUNIT_ASSERT(s == oss.str());
  }

  void test_life_write_3() {
    Life<Cell> life(2, 2, new FredkinCell());
    life.add_cell(0, 0, new FredkinCell(true));
    life.add_cell(1, 1, new FredkinCell(true));
    string s = "Generation = 0, Population = 2.\n";
    s += "0-\n";
    s += "-0\n\n";
    ostringstream oss;
    life.write(oss);
    CPPUNIT_ASSERT(s == oss.str());
  }

  // -----------------
  // AbstractCell live
  // -----------------
  void test_abstract_cell_live_1() {
    ConwayCell c(false);
    CPPUNIT_ASSERT(c.isAlive() == false);
    c.live();
    CPPUNIT_ASSERT(c.isAlive() == true);
  }

  void test_abstract_cell_live_2() {
    FredkinCell c(false);
    CPPUNIT_ASSERT(c.isAlive() == false);
    c.live();
    CPPUNIT_ASSERT(c.isAlive() == true);
  }

  void test_abstract_cell_live_3() {
    ConwayCell c(true);
    CPPUNIT_ASSERT(c.isAlive() == true);
    c.live();
    CPPUNIT_ASSERT(c.isAlive() == true);
  }

  // ----------------
  // AbstractCell die
  // ----------------
  void test_abstract_cell_die_1() {
    ConwayCell c(true);
    CPPUNIT_ASSERT(c.isAlive() == true);
    c.die();
    CPPUNIT_ASSERT(c.isAlive() == false);
  }

  void test_abstract_cell_die_2() {
    FredkinCell c(true);
    CPPUNIT_ASSERT(c.isAlive() == true);
    c.die();
    CPPUNIT_ASSERT(c.isAlive() == false);
  }

  void test_abstract_cell_die_3() {
    ConwayCell c(false);
    CPPUNIT_ASSERT(c.isAlive() == false);
    c.die();
    CPPUNIT_ASSERT(c.isAlive() == false);
  }

  // --------------------
  // AbstractCell isAlive
  // --------------------
  void test_abstract_cell_isAlive_1() {
    ConwayCell c(true);
    CPPUNIT_ASSERT(c.isAlive() == true);
    CPPUNIT_ASSERT(c.isAlive() == c._alive);
  }

  void test_abstract_cell_isAlive_2() {
    FredkinCell c(true);
    CPPUNIT_ASSERT(c.isAlive() == true);
    CPPUNIT_ASSERT(c.isAlive() == c._alive);
  }

  void test_abstract_cell_isAlive_3() {
    ConwayCell c(false);
    CPPUNIT_ASSERT(c.isAlive() == false);
    CPPUNIT_ASSERT(c.isAlive() == c._alive);
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
    ConwayCell c1('*');
    CPPUNIT_ASSERT(c1.isAlive() == true);
    ConwayCell c2('.');
    CPPUNIT_ASSERT(c2.isAlive() == false);
  }

  // -----------------------
  // ConwayCell get_neighbors
  // -----------------------
  void test_conway_cell_get_neighbors_1() {
    ConwayCell c;
    vector< vector< bool > > neighbors(3, vector< bool >(3, false));
    int n = c.get_neighbors(neighbors);
    CPPUNIT_ASSERT(n == 0);
  }

  void test_conway_cell_get_neighbors_2() {
    ConwayCell c;
    vector< vector< bool > > neighbors(3, vector< bool >(3, true));
    neighbors[1][1] = false;
    int n = c.get_neighbors(neighbors);
    CPPUNIT_ASSERT(n == 8);
  }

  void test_conway_cell_get_neighbors_3() {
    ConwayCell c;
    vector< vector< bool > > neighbors(3, vector< bool >(3, false));
    neighbors[0][0] = true;
    neighbors[0][2] = true;
    neighbors[2][0] = true;
    neighbors[2][2] = true;
    int n = c.get_neighbors(neighbors);
    CPPUNIT_ASSERT(n == 4);
  }

  // ----------------
  // ConwayCell age
  // ----------------
  void test_conway_cell_age_1() {
    ConwayCell c;
    CPPUNIT_ASSERT(c.age() == 0);
  }

  void test_conway_cell_age_2() {
    ConwayCell c;
    CPPUNIT_ASSERT(c.age() == 0);
  }

  void test_conway_cell_age_3() {
    ConwayCell c;
    CPPUNIT_ASSERT(c.age() == 0);
  }

  // ----------------
  // ConwayCell act
  // ----------------
  void test_conway_cell_act_1() {
    ConwayCell c;
    vector< vector< bool > > neighbors(3, vector< bool >(3, false));
    CPPUNIT_ASSERT(c.act(neighbors) == false);
  }

  void test_conway_cell_act_2() {
    ConwayCell c;
    vector< vector< bool > > neighbors(3, vector< bool >(3, false));
    neighbors[0][0] = true;
    neighbors[0][1] = true;
    neighbors[0][2] = true;
    CPPUNIT_ASSERT(c.act(neighbors) == true);
  }

  void test_conway_cell_act_3() {
    ConwayCell c(true);
    vector< vector< bool > > neighbors(3, vector< bool >(3, false));
    CPPUNIT_ASSERT(c.act(neighbors) == false);
    neighbors[0][0] = true;
    neighbors[0][1] = true;
    CPPUNIT_ASSERT(c.act(neighbors) == true);
    neighbors[0][2] = true;
    CPPUNIT_ASSERT(c.act(neighbors) == true);
    neighbors[1][0] = true;
    CPPUNIT_ASSERT(c.act(neighbors) == false);
  }

  // -----------------
  // ConwayCell mutate
  // -----------------
  void test_conway_cell_mutate_1() {
    ConwayCell c1(false);
    ConwayCell c2(false);
    c2 = c1.mutate();
    CPPUNIT_ASSERT(c2.isAlive() == false);
  }

  void test_conway_cell_mutate_2() {
    ConwayCell c1(true);
    ConwayCell c2(false);
    c2 = c1.mutate();
    CPPUNIT_ASSERT(c2.isAlive() == true);
  }

  void test_conway_cell_mutate_3() {
    ConwayCell c1(false);
    ConwayCell c2(true);
    c2 = c1.mutate();
    CPPUNIT_ASSERT(c2.isAlive() == false);
  }

  // -----------------
  // ConwayCell clone
  // -----------------
  void test_conway_cell_clone_1() {
    ConwayCell c1(false);
    ConwayCell* c1p = c1.clone();
    CPPUNIT_ASSERT(c1p->isAlive() == false);
  }

  void test_conway_cell_clone_2() {
    ConwayCell c1(true);
    ConwayCell* c1p = c1.clone();
    CPPUNIT_ASSERT(c1p->isAlive() == true);
  }

  void test_conway_cell_clone_3() {
    ConwayCell c1(false);
    ConwayCell* c1p1 = c1.clone();
    ConwayCell* c1p2 = c1.clone();
    CPPUNIT_ASSERT(c1p1 != c1p2);
  }

  // -----------------
  // ConwayCell write
  // -----------------
  void test_conway_cell_write_1() {
    ConwayCell c;
    ostringstream oss;
    c.write(oss);
    string s = ".";
    CPPUNIT_ASSERT(s == oss.str());
  }

  void test_conway_cell_write_2() {
    ConwayCell c(true);
    ostringstream oss;
    c.write(oss);
    string s = "*";
    CPPUNIT_ASSERT(s == oss.str());

  }

  void test_conway_cell_write_3() {
    ConwayCell c1('.');
    ostringstream oss1;
    c1.write(oss1);
    string s = ".";
    CPPUNIT_ASSERT(s == oss1.str());
    ConwayCell c2('*');
    ostringstream oss2;
    c2.write(oss2);
    s = "*";
    CPPUNIT_ASSERT(s == oss2.str());
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
    FredkinCell c1('0');
    CPPUNIT_ASSERT(c1.isAlive() == true);
    FredkinCell c2('-');
    CPPUNIT_ASSERT(c2.isAlive() == false);
  }

  // -----------------------
  // FredkinCell get_neighbors
  // -----------------------
  void test_fredkin_cell_get_neighbors_1() {
    FredkinCell c;
    vector< vector< bool > > neighbors(3, vector< bool >(3, false));
    int n = c.get_neighbors(neighbors);
    CPPUNIT_ASSERT(n == 0);
  }

  void test_fredkin_cell_get_neighbors_2() {
    FredkinCell c;
    vector< vector< bool > > neighbors(3, vector< bool >(3, true));
    neighbors[1][1] = false;
    int n = c.get_neighbors(neighbors);
    CPPUNIT_ASSERT(n == 4);
  }

  void test_fredkin_cell_get_neighbors_3() {
    FredkinCell c;
    vector< vector< bool > > neighbors(3, vector< bool >(3, false));
    neighbors[0][0] = true;
    neighbors[0][2] = true;
    neighbors[2][0] = true;
    neighbors[2][2] = true;
    int n = c.get_neighbors(neighbors);
    CPPUNIT_ASSERT(n == 0);
  }

  // ----------------
  // FredkinCell age
  // ----------------
  void test_fredkin_cell_age_1() {
    FredkinCell c;
    CPPUNIT_ASSERT(c.age() == 0);
  }

  void test_fredkin_cell_age_2() {
    FredkinCell c('0');
    CPPUNIT_ASSERT(c.age() == 0);
  }

  void test_fredkin_cell_age_3() {
    FredkinCell c('9');
    CPPUNIT_ASSERT(c.age() == 9);
  }

  // ----------------
  // FredkinCell act
  // ----------------
  void test_fredkin_cell_act_1() {
    FredkinCell c;
    vector< vector< bool > > neighbors(3, vector< bool >(3, false));
    CPPUNIT_ASSERT(c.act(neighbors) == false);
  }

  void test_fredkin_cell_act_2() {
    FredkinCell c;
    vector< vector< bool > > neighbors(3, vector< bool >(3, false));
    neighbors[0][1] = true;
    CPPUNIT_ASSERT(c.act(neighbors) == true);
    neighbors[1][0] = true;
    neighbors[1][2] = true;
    CPPUNIT_ASSERT(c.act(neighbors) == true);
  }

  void test_fredkin_cell_act_3() {
    FredkinCell c(true);
    vector< vector< bool > > neighbors(3, vector< bool >(3, false));
    CPPUNIT_ASSERT(c.act(neighbors) == false);
    neighbors[0][1] = true;
    neighbors[1][0] = true;
    CPPUNIT_ASSERT(c.act(neighbors) == false);
    neighbors[1][2] = true;
    neighbors[2][1] = true;
    CPPUNIT_ASSERT(c.act(neighbors) == false);
  }

  // -----------------
  // FredkinCell mutate
  // -----------------
  void test_fredkin_cell_mutate_1() {
    FredkinCell c1(false);
    FredkinCell c2(false);
    c2 = c1.mutate();
    CPPUNIT_ASSERT(c2.isAlive() == false);
  }

  void test_fredkin_cell_mutate_2() {
    FredkinCell c1(true);
    FredkinCell c2(false);
    c2 = c1.mutate();
    CPPUNIT_ASSERT(c2.isAlive() == true);
  }

  void test_fredkin_cell_mutate_3() {
    FredkinCell c1(false);
    FredkinCell c2(true);
    c2 = c1.mutate();
    CPPUNIT_ASSERT(c2.isAlive() == false);
  }

  // -----------------
  // FredkinCell mutate
  // -----------------
  void test_fredkin_cell_clone_1() {
    FredkinCell c1(false);
    FredkinCell* c1p = c1.clone();
    CPPUNIT_ASSERT(c1p->isAlive() == false);
    CPPUNIT_ASSERT(c1p->age() == 0);
  }

  void test_fredkin_cell_clone_2() {
    FredkinCell c1('0');
    FredkinCell* c1p = c1.clone();
    CPPUNIT_ASSERT(c1p->isAlive() == true);
    CPPUNIT_ASSERT(c1p->age() == 0);
  }

  void test_fredkin_cell_clone_3() {
    FredkinCell c1('9');
    FredkinCell* c1p1 = c1.clone();
    FredkinCell* c1p2 = c1.clone();
    CPPUNIT_ASSERT(c1p1 != c1p2);
    CPPUNIT_ASSERT(c1p1->isAlive() == true);
    CPPUNIT_ASSERT(c1p2->isAlive() == true);
    CPPUNIT_ASSERT(c1p1->age() == 9);
    CPPUNIT_ASSERT(c1p2->age() == 9);
  }

  // -----------------
  // FredkinCell write
  // -----------------
  void test_fredkin_cell_write_1() {
    FredkinCell c;
    ostringstream oss;
    c.write(oss);
    string s = "-";
    CPPUNIT_ASSERT(s == oss.str());
  }

  void test_fredkin_cell_write_2() {
    FredkinCell c(true);
    ostringstream oss;
    c.write(oss);
    string s = "0";
    CPPUNIT_ASSERT(s == oss.str());

  }

  void test_fredkin_cell_write_3() {
    FredkinCell c1('9');
    ostringstream oss1;
    c1.write(oss1);
    string s = "9";
    CPPUNIT_ASSERT(s == oss1.str());
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
    c.live();
    CPPUNIT_ASSERT(c.isAlive() == true);
  }

  void test_cell_live_2() {
    Cell c = new FredkinCell(false);
    c.live();
    CPPUNIT_ASSERT(c.isAlive() == true);
  }

  void test_cell_live_3() {
    Cell c1 = new ConwayCell(true);
    Cell c2 = new FredkinCell(true);
    c1.live();
    c2.live();
    CPPUNIT_ASSERT(c1.isAlive() == true);
    CPPUNIT_ASSERT(c2.isAlive() == true);
  }

  // ----------------
  // Cell die
  // ----------------
  void test_cell_die_1() {
    Cell c = new ConwayCell(true);
    c.die();
    CPPUNIT_ASSERT(c.isAlive() == false);
  }

  void test_cell_die_2() {
    Cell c = new FredkinCell(true);
    c.die();
    CPPUNIT_ASSERT(c.isAlive() == false);
  }

  void test_cell_die_3() {
    Cell c1 = new ConwayCell(true);
    Cell c2 = new FredkinCell(true);
    c1.die();
    c2.die();
    CPPUNIT_ASSERT(c1.isAlive() == false);
    CPPUNIT_ASSERT(c2.isAlive() == false);
  }

  // ----------------
  // Cell isAlive
  // ----------------
  void test_cell_isAlive_1() {
    Cell c = new ConwayCell(false);
    CPPUNIT_ASSERT(c.isAlive() == false);
    CPPUNIT_ASSERT(c.isAlive() == c.get()->_alive);
  }

  void test_cell_isAlive_2() {
    Cell c = new FredkinCell(false);
    CPPUNIT_ASSERT(c.isAlive() == false);
    CPPUNIT_ASSERT(c.isAlive() == c.get()->_alive);
  }

  void test_cell_isAlive_3() {
    Cell c = new ConwayCell(true);
    CPPUNIT_ASSERT(c.isAlive() == true);
    CPPUNIT_ASSERT(c.isAlive() == c.get()->_alive);
  }

  // ----------------
  // Cell act
  // ----------------
  void test_cell_act_1() {
    {
    Cell c = new ConwayCell;
    vector< vector< bool > > neighbors(3, vector< bool >(3, false));
    CPPUNIT_ASSERT(c.act(neighbors) == false);
    }

    {
    Cell c = new FredkinCell(false);
    vector< vector< bool > > neighbors(3, vector< bool >(3, false));
    CPPUNIT_ASSERT(c.act(neighbors) == false);
    }
  }

  void test_cell_act_2() {
    {
    Cell c = new ConwayCell;
    vector< vector< bool > > neighbors(3, vector< bool >(3, false));
    neighbors[0][0] = true;
    neighbors[0][1] = true;
    neighbors[0][2] = true;
    CPPUNIT_ASSERT(c.act(neighbors) == true);
    }

    {
    Cell c = new FredkinCell(false);
    vector< vector< bool > > neighbors(3, vector< bool >(3, false));
    neighbors[0][1] = true;
    CPPUNIT_ASSERT(c.act(neighbors) == true);
    neighbors[1][0] = true;
    neighbors[1][2] = true;
    CPPUNIT_ASSERT(c.act(neighbors) == true);
    }
  }

  void test_cell_act_3() {
    {
    Cell c = new ConwayCell(true);
    vector< vector< bool > > neighbors(3, vector< bool >(3, false));
    CPPUNIT_ASSERT(c.act(neighbors) == false);
    neighbors[0][0] = true;
    neighbors[0][1] = true;
    CPPUNIT_ASSERT(c.act(neighbors) == true);
    neighbors[0][2] = true;
    CPPUNIT_ASSERT(c.act(neighbors) == true);
    neighbors[1][0] = true;
    CPPUNIT_ASSERT(c.act(neighbors) == false);
    }

    {
    Cell c = new FredkinCell(true);
    vector< vector< bool > > neighbors(3, vector< bool >(3, false));
    CPPUNIT_ASSERT(c.act(neighbors) == false);
    neighbors[0][1] = true;
    neighbors[1][0] = true;
    CPPUNIT_ASSERT(c.act(neighbors) == false);
    neighbors[1][2] = true;
    neighbors[2][1] = true;
    CPPUNIT_ASSERT(c.act(neighbors) == false);
    }
  }
  // ----------------
  // Cell mutate
  // ----------------
  void test_cell_mutate_1() {
    Cell c1 = new FredkinCell('2');
    Cell c2 = c1.mutate();
    CPPUNIT_ASSERT(c1.get() != c2.get());
  }

  void test_cell_mutate_2() {
    Cell c1 = new FredkinCell(false);
    Cell c2 = c1.mutate();
    CPPUNIT_ASSERT(c1.get()->age() == c2.get()->age());
  }

  void test_cell_mutate_3() {
    Cell c1 = new ConwayCell(true);
    Cell c2 = c1.mutate();
    CPPUNIT_ASSERT(c1.isAlive() == c2.isAlive());
  }

  // ----------------
  // Cell write
  // ----------------
  void test_cell_write_1() {
    Cell c = new FredkinCell(false);
    ostringstream oss;
    c.write(oss);
    string s = "-";
    CPPUNIT_ASSERT(s == oss.str());
  }

  void test_cell_write_2() {
    Cell c = new FredkinCell(true);
    ostringstream oss;
    c.write(oss);
    string s = "0";
    CPPUNIT_ASSERT(s == oss.str());
  }

  void test_cell_write_3() {
    Cell c = new FredkinCell('9');
    ostringstream oss1;
    c.write(oss1);
    string s = "9";
    CPPUNIT_ASSERT(s == oss1.str());
  }







  // ---------
  // TestSuite
  // ---------
  CPPUNIT_TEST_SUITE(TestLife);

  CPPUNIT_TEST(test_life_constructor_1);
  CPPUNIT_TEST(test_life_constructor_2);
  CPPUNIT_TEST(test_life_constructor_3);

  CPPUNIT_TEST(test_life_add_cell_1);
  CPPUNIT_TEST(test_life_add_cell_2);
  CPPUNIT_TEST(test_life_add_cell_3);

  CPPUNIT_TEST(test_life_run_1);
  CPPUNIT_TEST(test_life_run_2);
  CPPUNIT_TEST(test_life_run_3);

  CPPUNIT_TEST(test_life_fill_neighbors_1);
  CPPUNIT_TEST(test_life_fill_neighbors_2);
  CPPUNIT_TEST(test_life_fill_neighbors_3);

  CPPUNIT_TEST(test_life_write_1);
  CPPUNIT_TEST(test_life_write_2);
  CPPUNIT_TEST(test_life_write_3);

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

  CPPUNIT_TEST(test_conway_cell_get_neighbors_1);
  CPPUNIT_TEST(test_conway_cell_get_neighbors_2);
  CPPUNIT_TEST(test_conway_cell_get_neighbors_3);

  CPPUNIT_TEST(test_conway_cell_age_1);
  CPPUNIT_TEST(test_conway_cell_age_2);
  CPPUNIT_TEST(test_conway_cell_age_3);

  CPPUNIT_TEST(test_conway_cell_act_1);
  CPPUNIT_TEST(test_conway_cell_act_2);
  CPPUNIT_TEST(test_conway_cell_act_3);

  CPPUNIT_TEST(test_conway_cell_mutate_1);
  CPPUNIT_TEST(test_conway_cell_mutate_2);
  CPPUNIT_TEST(test_conway_cell_mutate_3);

  CPPUNIT_TEST(test_conway_cell_clone_1);
  CPPUNIT_TEST(test_conway_cell_clone_2);
  CPPUNIT_TEST(test_conway_cell_clone_3);

  CPPUNIT_TEST(test_conway_cell_write_1);
  CPPUNIT_TEST(test_conway_cell_write_2);
  CPPUNIT_TEST(test_conway_cell_write_3);

  CPPUNIT_TEST(test_fredkin_cell_constructor_1);
  CPPUNIT_TEST(test_fredkin_cell_constructor_2);
  CPPUNIT_TEST(test_fredkin_cell_constructor_3);

  CPPUNIT_TEST(test_fredkin_cell_get_neighbors_1);
  CPPUNIT_TEST(test_fredkin_cell_get_neighbors_2);
  CPPUNIT_TEST(test_fredkin_cell_get_neighbors_3);

  CPPUNIT_TEST(test_fredkin_cell_age_1);
  CPPUNIT_TEST(test_fredkin_cell_age_2);
  CPPUNIT_TEST(test_fredkin_cell_age_3);

  CPPUNIT_TEST(test_fredkin_cell_act_1);
  CPPUNIT_TEST(test_fredkin_cell_act_2);
  CPPUNIT_TEST(test_fredkin_cell_act_3);

  CPPUNIT_TEST(test_fredkin_cell_mutate_1);
  CPPUNIT_TEST(test_fredkin_cell_mutate_2);
  CPPUNIT_TEST(test_fredkin_cell_mutate_3);

  CPPUNIT_TEST(test_fredkin_cell_clone_1);
  CPPUNIT_TEST(test_fredkin_cell_clone_2);
  CPPUNIT_TEST(test_fredkin_cell_clone_3);

  CPPUNIT_TEST(test_fredkin_cell_write_1);
  CPPUNIT_TEST(test_fredkin_cell_write_2);
  CPPUNIT_TEST(test_fredkin_cell_write_3);

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

  CPPUNIT_TEST(test_cell_act_1);
  CPPUNIT_TEST(test_cell_act_2);
  CPPUNIT_TEST(test_cell_act_3);

  CPPUNIT_TEST(test_cell_mutate_1);
  CPPUNIT_TEST(test_cell_mutate_2);
  CPPUNIT_TEST(test_cell_mutate_3);

  CPPUNIT_TEST(test_cell_write_1);
  CPPUNIT_TEST(test_cell_write_2);
  CPPUNIT_TEST(test_cell_write_3);


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
