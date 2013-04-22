// ------------
// Reece Davies
// ------------


// --------
// includes
// --------

#include <iostream> // cout, endl, ios_base
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#define private public
#define protected public
#define class struct

#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Life.h"

// ----------
// TestDarwin
// ----------

struct TestLife : CppUnit::TestFixture {

  // ----------
  // ConwayCell
  // ----------

  void test_ConwayCell_1() {
    ConwayCell cell(true);
    CPPUNIT_ASSERT(cell._isDead == true);
    CPPUNIT_ASSERT(cell._action == DIE);
  }

  void test_ConwayCell_2() {
    ConwayCell cell(false);
    CPPUNIT_ASSERT(cell._isDead == false);
    CPPUNIT_ASSERT(cell._action == LIVE);
  }

  void test_ConwayCell_3() {
    ConwayCell cell(true);
    CPPUNIT_ASSERT(cell._action == DIE);
    CPPUNIT_ASSERT(cell._isDead == true);
  }

  // --------------
  // ConwayCellCopy
  // --------------

  void test_ConwayCellCopy_1() {
    ConwayCell c1(true);
    ConwayCell c2(c1);
    CPPUNIT_ASSERT(c2._isDead == true);
    CPPUNIT_ASSERT(c2._action == DIE);
  }

  void test_ConwayCellCopy_2() {
    ConwayCell c1(false);
    ConwayCell c2(c1);
    CPPUNIT_ASSERT(c2._isDead == false);
    CPPUNIT_ASSERT(c2._action == LIVE);
  }

  void test_ConwayCellCopy_3() {
    ConwayCell c1(true);
    ConwayCell c2(c1);
    CPPUNIT_ASSERT(c2._action == DIE);
    CPPUNIT_ASSERT(c2._isDead == true);
  }

  // ---------------
  // ConwayCellWrite
  // ---------------

  void test_ConwayCellWrite_1() {
    ConwayCell c(true);
    ostringstream w;
    c.write(w);
    string result = ".";
    CPPUNIT_ASSERT(w.str() == result);
  }

  void test_ConwayCellWrite_2() {
    ConwayCell c(false);
    ostringstream w;
    c.write(w);
    string result = "*";
    CPPUNIT_ASSERT(w.str() == result);
  }

  void test_ConwayCellWrite_3() {
    ConwayCell c1(true);
    ConwayCell c2(c1);
    ostringstream w;
    c2.write(w);
    string result = ".";
    CPPUNIT_ASSERT(w.str() == result);
  }

  // ---------------
  // ConwayCellClone
  // ---------------

  void test_ConwayCellClone_1() {
    ConwayCell c1(true);
    ConwayCell* c2 = c1.clone();
    CPPUNIT_ASSERT(c2->_isDead == true);
    CPPUNIT_ASSERT(c2->_action == DIE);
    delete c2;
  }

  void test_ConwayCellClone_2() {
    ConwayCell c1(false);
    ConwayCell* c2 = c1.clone();
    CPPUNIT_ASSERT(c2->_isDead == false);
    CPPUNIT_ASSERT(c2->_action == LIVE);
    delete c2;
  }

  void test_ConwayCellClone_3() {
    ConwayCell c1(true);
    ConwayCell* c2 = c1.clone();
    CPPUNIT_ASSERT(c2->_action == DIE);
    CPPUNIT_ASSERT(c2->_isDead == true);
    delete c2;
  }

  // --------------
  // ConwayCellEval
  // --------------

  void test_ConwayCellEval_1() {
    ConwayCell c(true);
    c.evalTurn(3);
    CPPUNIT_ASSERT(c._action == LIVE);
  }

  void test_ConwayCellEval_2() {
    ConwayCell c(true);
    c.evalTurn(4);
    CPPUNIT_ASSERT(c._action == SAME);
  }

  void test_ConwayCellEval_3() {
    ConwayCell c(false);
    c.evalTurn(1);
    CPPUNIT_ASSERT(c._action == DIE);
  }

  // --------------
  // ConwayCellTurn
  // --------------

  void test_ConwayCellTurn_1() {
    ConwayCell c(true);
    c._action = LIVE;
    c.takeTurn();
    CPPUNIT_ASSERT(c._isDead == false);
  }

  void test_ConwayCellTurn_2() {
    ConwayCell c(true);
    c.takeTurn();
    CPPUNIT_ASSERT(c._isDead == true);
  }

  void test_ConwayCellTurn_3() {
    ConwayCell c(false);
    c._action = DIE;
    c.takeTurn();
    CPPUNIT_ASSERT(c._isDead == true);
  }

  // -----------
  // FredkinCell
  // -----------

  void test_FredkinCell_1() {
    FredkinCell c(true);
    CPPUNIT_ASSERT(c._isDead == true);
    CPPUNIT_ASSERT(c._action == DIE);
    CPPUNIT_ASSERT(c._age == 0);
  }

  void test_FredkinCell_2() {
    FredkinCell c(false);
    CPPUNIT_ASSERT(c._isDead == false);
    CPPUNIT_ASSERT(c._action == LIVE);
    CPPUNIT_ASSERT(c._age == 0);
  }

  void test_FredkinCell_3() {
    FredkinCell c(true);
    CPPUNIT_ASSERT(c._action == DIE);
    CPPUNIT_ASSERT(c._isDead == true);
    CPPUNIT_ASSERT(c._age == 0);
  }

  // ---------------
  // FredkinCellCopy
  // ---------------

  void test_FredkinCellCopy_1() {
    FredkinCell c1(true);
    FredkinCell c2(c1);
    CPPUNIT_ASSERT(c2._isDead == true);
    CPPUNIT_ASSERT(c2._action == DIE);
    CPPUNIT_ASSERT(c2._age == c1._age);
  }

  void test_FredkinCellCopy_2() {
    FredkinCell c1(false);
    FredkinCell c2(c1);
    CPPUNIT_ASSERT(c2._isDead == false);
    CPPUNIT_ASSERT(c2._action == LIVE);
    CPPUNIT_ASSERT(c2._age == c1._age);
  }

  void test_FredkinCellCopy_3() {
    FredkinCell c1(true);
    FredkinCell c2(c1);
    CPPUNIT_ASSERT(c2._action == DIE);
    CPPUNIT_ASSERT(c2._isDead == true);
    CPPUNIT_ASSERT(c2._age == c1._age);
  }

  // ----------------
  // FredkinCellWrite
  // ----------------

  void test_FredkinCellWrite_1() {
    FredkinCell c(true);
    ostringstream w;
    c.write(w);
    string result = "-";
    CPPUNIT_ASSERT(w.str() == result);
  }

  void test_FredkinCellWrite_2() {
    FredkinCell c(false);
    ostringstream w;
    c.write(w);
    string result = "0";
    CPPUNIT_ASSERT(w.str() == result);
  }

  void test_FredkinCellWrite_3() {
    FredkinCell c(false);
    c._age = 9;
    ostringstream w;
    c.write(w);
    string result = "9";
    CPPUNIT_ASSERT(w.str() == result);
  }

  // ----------------
  // FredkinCellClone
  // ----------------

  void test_FredkinCellClone_1() {
    FredkinCell c1(true);
    FredkinCell* c2 = c1.clone();
    CPPUNIT_ASSERT(c2->_isDead == true);
    CPPUNIT_ASSERT(c2->_action == DIE);
    CPPUNIT_ASSERT(c2->_age == c1._age);
    delete c2;
  }

  void test_FredkinCellClone_2() {
    FredkinCell c1(false);
    FredkinCell* c2 = c1.clone();
    CPPUNIT_ASSERT(c2->_isDead == false);
    CPPUNIT_ASSERT(c2->_action == LIVE);
    CPPUNIT_ASSERT(c2->_age == c1._age);
    delete c2;
  }

  void test_FredkinCellClone_3() {
    FredkinCell c1(true);
    c1._age = 5;
    FredkinCell* c2 = c1.clone();
    CPPUNIT_ASSERT(c2->_isDead == true);
    CPPUNIT_ASSERT(c2->_action == DIE);
    CPPUNIT_ASSERT(c2->_age == c1._age);
    delete c2;
  }

  // ---------------
  // FredkinCellEval
  // ---------------

  void test_FredkinCellEval_1() {
    FredkinCell c(true);
    c.evalTurn(3);
    CPPUNIT_ASSERT(c._action == LIVE);
  }

  void test_FredkinCellEval_2() {
    FredkinCell c(true);
    c.evalTurn(5);
    CPPUNIT_ASSERT(c._action == SAME);
  }

  void test_FredkinCellEval_3() {
    FredkinCell c(false);
    c.evalTurn(0);
    CPPUNIT_ASSERT(c._action == DIE);
  }

  // ---------------
  // FredkinCellTurn
  // ---------------

  void test_FredkinCellTurn_1() {
    FredkinCell c(true);
    c._action = LIVE;
    c.takeTurn();
    CPPUNIT_ASSERT(c._isDead == false);
  }

  void test_FredkinCellTurn_2() {
    FredkinCell c(true);
    c.takeTurn();
    CPPUNIT_ASSERT(c._isDead == true);
  }

  void test_FredkinCellTurn_3() {
    FredkinCell c(false);
    c._action = DIE;
    c.takeTurn();
    CPPUNIT_ASSERT(c._isDead == true);
  }

  // ----------
  // CellIsDead
  // ----------

  void test_CellIsDead_1() {
    Cell c = new ConwayCell(false);
    CPPUNIT_ASSERT(!c.isDead());
  }

  void test_CellIsDead_2() {
    Cell c = new ConwayCell(true);
    CPPUNIT_ASSERT(c.isDead());
  }

  void test_CellIsDead_3() {
    Cell c = new FredkinCell(false);
    CPPUNIT_ASSERT(!c.isDead());
  }

  // ---------
  // CellClone
  // ---------

  void test_CellClone_1() {
    Cell c1 = new ConwayCell(false);
    Cell c2 = c1.clone();
    CPPUNIT_ASSERT(!c1.isDead());
  }

  void test_CellClone_2() {
    Cell c1 = new ConwayCell(true);
    Cell c2 = c1.clone();
    CPPUNIT_ASSERT(c1.isDead());
  }

  void test_CellClone_3() {
    Cell c1 = new FredkinCell(false);
    Cell c2 = c1.clone();
    CPPUNIT_ASSERT(!c1.isDead());
  }

  // --------------
  // test_cellWrite
  // --------------

  void test_CellWrite_1() {
    Cell c = new ConwayCell(true);
    ostringstream w;
    c.write(w);
    CPPUNIT_ASSERT(w.str() == ".");
  }

  void test_CellWrite_2() {
    Cell c = new ConwayCell(false);
    ostringstream w;
    c.write(w);
    CPPUNIT_ASSERT(w.str() == "*");
  }

  void test_CellWrite_3() {
    Cell c = new FredkinCell(true);
    ostringstream w;
    c.write(w);
    CPPUNIT_ASSERT(w.str() == "-");
  }

  void test_CellWrite_4() {
    Cell c = new FredkinCell(false);
    ostringstream w;
    c.write(w);
    CPPUNIT_ASSERT(w.str() == "0");
  }

  // -------------
  // test_CellEval
  // -------------

  void test_CellEval_1() {
    Cell c = new ConwayCell(true);
    c.evalTurn(3);
    CPPUNIT_ASSERT(c.get()->_action == LIVE);
  }

  void test_CellEval_2() {
    Cell c = new ConwayCell(true);
    c.evalTurn(4);
    CPPUNIT_ASSERT(c.get()->_action == SAME);
  }

  void test_CellEval_3() {
    Cell c = new ConwayCell(false);
    c.evalTurn(0);
    CPPUNIT_ASSERT(c.get()->_action == DIE);
  }

  // --------
  // CellTurn
  // --------

  void test_CellTurn_1() {
    Cell c = new ConwayCell(true);
    c.get()->_action = LIVE;
    c.takeTurn();
    CPPUNIT_ASSERT(c.get()->_isDead == false);
  }

  void test_CellTurn_2() {
    Cell c = new ConwayCell(false);
    c.get()->_action = DIE;
    c.takeTurn();
    CPPUNIT_ASSERT(c.get()->_isDead == true);
  }

  void test_CellTurn_3() {
    Cell c = new FredkinCell(true);
    c.get()->_action = DIE;
    c.takeTurn();
    CPPUNIT_ASSERT(c.get()->_isDead == true);
  }

  // ----
  // Life
  // ----

  void test_Life_1() {
    Life<ConwayCell> l(5, false);
    CPPUNIT_ASSERT(l._generation == 0);
    CPPUNIT_ASSERT(l._canMutate == false);
    CPPUNIT_ASSERT(l._board.size() == 5);
    CPPUNIT_ASSERT(l._pop == 0);
  }

  void test_Life_2() {
    Life<FredkinCell> l(72, false);
    CPPUNIT_ASSERT(l._generation == 0);
    CPPUNIT_ASSERT(l._canMutate == false);
    CPPUNIT_ASSERT(l._board.size() == 72);
    CPPUNIT_ASSERT(l._pop == 0);
  }

  void test_Life_3() {
    Life<FredkinCell> l(10, true);
    CPPUNIT_ASSERT(l._generation == 0);
    CPPUNIT_ASSERT(l._canMutate == true);
    CPPUNIT_ASSERT(l._board.size() == 10);
    CPPUNIT_ASSERT(l._pop == 0);
  }

  // -------
  // putCell
  // -------

  void test_putCell_1() {
    Life<ConwayCell> l(10, false);
    l.putCell(0, ConwayCell(false));
    CPPUNIT_ASSERT(l._pop == 1);
    CPPUNIT_ASSERT(l._board[0][0]._isDead == false);
  }

  void test_putCell_2() {
    Life<ConwayCell> l(15, false);
    l.putCell(0, ConwayCell(false));
    l.putCell(0, ConwayCell(false));
    CPPUNIT_ASSERT(l._pop == 2);
    CPPUNIT_ASSERT(l._board[0][0]._isDead == false);
    CPPUNIT_ASSERT(l._board[0][1]._isDead == false);
  }

  void test_putCell_3() {
    Life<FredkinCell> l(72, false);
    l.putCell(1, FredkinCell(false));
    l.putCell(2, FredkinCell(false));
    CPPUNIT_ASSERT(l._pop == 2);
    CPPUNIT_ASSERT(l._board[1][0]._isDead == false);
    CPPUNIT_ASSERT(l._board[2][0]._isDead == false);
  }

  // ----------
  // printBoard
  // ----------

  void test_printBoard_1() {
    Life<ConwayCell> l(2, false);
    l.putCell(0, ConwayCell(false));
    l.putCell(0, ConwayCell(true));
    l.putCell(1, ConwayCell(true));
    l.putCell(1, ConwayCell(true));
    ostringstream w;
    l.printBoard(w);
    string result = "Generation = 0, Population = 1.\n*.\n..\n";
    CPPUNIT_ASSERT(w.str() == result);
  }

  void test_printBoard_2() {
    Life<ConwayCell> l(1, false);
    l.putCell(0, ConwayCell(false));
    l.putCell(0, ConwayCell(true));
    l.putCell(0, ConwayCell(false));
    l.putCell(0, ConwayCell(true));
    ostringstream w;
    l.printBoard(w);
    string result = "Generation = 0, Population = 2.\n*.*.\n";
    CPPUNIT_ASSERT(w.str() == result);
  }

  void test_printBoard_3() {
    Life<FredkinCell> l(2, false);
    l.putCell(0, FredkinCell(false));
    l.putCell(0, FredkinCell(true));
    l.putCell(0, FredkinCell(true));
    l.putCell(1, FredkinCell(false));
    l.putCell(1, FredkinCell(true));
    l.putCell(1, FredkinCell(true));
    ostringstream w;
    l.printBoard(w);
    string result = "Generation = 0, Population = 2.\n0--\n0--\n";
    CPPUNIT_ASSERT(w.str() == result);
  }

  void test_printBoard_4() {
    Life<Cell> l(2, true);
    l.putCell(0, new ConwayCell(false));
    l.putCell(0, new ConwayCell(true));
    l.putCell(1, new FredkinCell(false));
    l.putCell(1, new FredkinCell(true));
    ostringstream w;
    l.printBoard(w);
    string result = "Generation = 0, Population = 2.\n*.\n0-\n";
    CPPUNIT_ASSERT(w.str() == result);
  }

  // ---------
  // neighbors
  // ---------

  void test_neighbors_1() {
    Life<ConwayCell> l(2, false);
    l.putCell(0, ConwayCell(false));
    l.putCell(0, ConwayCell(true));
    l.putCell(1, ConwayCell(true));
    l.putCell(1, ConwayCell(true));
    CPPUNIT_ASSERT(l.neighbors(0, 0, 8) == 0);
  }

  void test_neighbors_2() {
    Life<ConwayCell> l(2, false);
    l.putCell(0, ConwayCell(false));
    l.putCell(0, ConwayCell(false));
    l.putCell(1, ConwayCell(true));
    l.putCell(1, ConwayCell(false));
    CPPUNIT_ASSERT(l.neighbors(0, 1, 8) == 2);
  }

  void test_neighbors_3() {
    Life<FredkinCell> l(2, false);
    l.putCell(0, FredkinCell(false));
    l.putCell(0, FredkinCell(true));
    l.putCell(1, FredkinCell(false));
    l.putCell(1, FredkinCell(false));
    CPPUNIT_ASSERT(l.neighbors(0, 0, 4) == 1);
  }

  void test_neighbors_4() {
    Life<Cell> l(2, true);
    l.putCell(0, new ConwayCell(false));
    l.putCell(0, new ConwayCell(true));
    l.putCell(1, new FredkinCell(false));
    l.putCell(1, new FredkinCell(false));
    CPPUNIT_ASSERT(l.neighbors(0, 0, 8) == 2);
    CPPUNIT_ASSERT(l.neighbors(1, 0, 4) == 2);
    CPPUNIT_ASSERT(l.neighbors(1, 1, 4) == 1);
  }

  void test_neighbors_5() {
    Life<Cell> l(2, true);
    l.putCell(0, new ConwayCell(false));
    l.putCell(0, new ConwayCell(false));
    l.putCell(1, new FredkinCell(true));
    l.putCell(1, new FredkinCell(false));
    CPPUNIT_ASSERT(l.neighbors(0, 0, 8) == 2);
    CPPUNIT_ASSERT(l.neighbors(0, 1, 8) == 2);
    CPPUNIT_ASSERT(l.neighbors(1, 1, 4) == 1);
  }

  // ------
  // mutate
  // ------

  void test_mutate_1() {
    Life<Cell> l(2, true);
    l.putCell(0, new ConwayCell(false));
    l.putCell(0, new ConwayCell(false));
    l.putCell(1, new FredkinCell(true));
    l.putCell(1, new FredkinCell(false));
    l.mutate(1 ,1);
    if (!dynamic_cast<ConwayCell*>(l._board[1][1]._p))
      CPPUNIT_ASSERT(false);
  }

  void test_mutate_2() {
    Life<Cell> l(2, true);
    l.putCell(0, new FredkinCell(true));
    l.putCell(0, new FredkinCell(false));
    l.putCell(1, new ConwayCell(false));
    l.putCell(1, new ConwayCell(false));
    l.mutate(0 ,1);
    if (!dynamic_cast<ConwayCell*>(l._board[0][1]._p))
      CPPUNIT_ASSERT(false);
  }

  void test_mutate_3() {
    Life<Cell> l(3, true);
    l.putCell(0, new ConwayCell(false));
    l.putCell(0, new ConwayCell(false));
    l.putCell(1, new FredkinCell(false));
    l.putCell(1, new FredkinCell(true));
    l.putCell(2, new FredkinCell(false));
    l.putCell(2, new ConwayCell(false));

    l.mutate(1 ,0);
    if (!dynamic_cast<ConwayCell*>(l._board[1][0]._p))
      CPPUNIT_ASSERT(false);
  }

  // ------------
  // doGeneration
  // ------------

  void test_doGeneration_1() {
    Life<ConwayCell> l(2, false);
    l.putCell(0, ConwayCell(false));
    l.putCell(0, ConwayCell(true));
    l.putCell(1, ConwayCell(true));
    l.putCell(1, ConwayCell(true));
    CPPUNIT_ASSERT(l._pop == 1);
    l.doGeneration();
    CPPUNIT_ASSERT(l._pop == 0);
  }

  void test_doGeneration_2() {
    Life<ConwayCell> l(2, false);
    l.putCell(0, ConwayCell(false));
    l.putCell(0, ConwayCell(false));
    l.putCell(1, ConwayCell(false));
    l.putCell(1, ConwayCell(false));
    CPPUNIT_ASSERT(l._pop == 4);
    l.doGeneration();
    CPPUNIT_ASSERT(l._pop == 4);
  }

  void test_doGeneration_3() {
    Life<FredkinCell> l(2, false);
    l.putCell(0, FredkinCell(false));
    l.putCell(0, FredkinCell(true));
    l.putCell(1, FredkinCell(true));
    l.putCell(1, FredkinCell(true));
    CPPUNIT_ASSERT(l._pop == 1);
    l.doGeneration();
    CPPUNIT_ASSERT(l._pop == 2);
  }

  void test_doGeneration_4() {
    Life<Cell> l(2, false);
    l.putCell(0, new ConwayCell(false));
    l.putCell(0, new ConwayCell(false));
    l.putCell(1, new FredkinCell(false));
    l.putCell(1, new FredkinCell(false));
    CPPUNIT_ASSERT(l._pop == 4);
    l.doGeneration();
    CPPUNIT_ASSERT(l._pop == 2);
  }

  void test_doGeneration_5() {
    Life<Cell> l(2, true);
    l.putCell(0, new ConwayCell(false));
    l.putCell(0, new ConwayCell(false));
    l.putCell(1, new FredkinCell(true));
    l.putCell(1, new FredkinCell(false));
    FredkinCell* p = dynamic_cast<FredkinCell*>(l._board[1][1]._p);
    p->_age = 1;

    CPPUNIT_ASSERT(l._pop == 3);
    l.doGeneration();
    CPPUNIT_ASSERT(l._pop == 3);

    ostringstream w;
    l.printBoard(w);
    string result = "Generation = 1, Population = 3.\n**\n-*\n";
    CPPUNIT_ASSERT(w.str() == result); 
  }


  CPPUNIT_TEST_SUITE(TestLife);
  CPPUNIT_TEST(test_ConwayCell_1);
  CPPUNIT_TEST(test_ConwayCell_2);
  CPPUNIT_TEST(test_ConwayCell_3);
  CPPUNIT_TEST(test_ConwayCellCopy_1);
  CPPUNIT_TEST(test_ConwayCellCopy_2);
  CPPUNIT_TEST(test_ConwayCellCopy_3);
  CPPUNIT_TEST(test_ConwayCellWrite_1);
  CPPUNIT_TEST(test_ConwayCellWrite_2);
  CPPUNIT_TEST(test_ConwayCellWrite_3);
  CPPUNIT_TEST(test_ConwayCellClone_1);
  CPPUNIT_TEST(test_ConwayCellClone_2);
  CPPUNIT_TEST(test_ConwayCellClone_3);
  CPPUNIT_TEST(test_ConwayCellEval_1);
  CPPUNIT_TEST(test_ConwayCellEval_2);
  CPPUNIT_TEST(test_ConwayCellEval_3);
  CPPUNIT_TEST(test_ConwayCellTurn_1);
  CPPUNIT_TEST(test_ConwayCellTurn_2);
  CPPUNIT_TEST(test_ConwayCellTurn_3);

  CPPUNIT_TEST(test_FredkinCell_1);
  CPPUNIT_TEST(test_FredkinCell_2);
  CPPUNIT_TEST(test_FredkinCell_3);
  CPPUNIT_TEST(test_FredkinCellCopy_1);
  CPPUNIT_TEST(test_FredkinCellCopy_2);
  CPPUNIT_TEST(test_FredkinCellCopy_3);
  CPPUNIT_TEST(test_FredkinCellWrite_1);
  CPPUNIT_TEST(test_FredkinCellWrite_2);
  CPPUNIT_TEST(test_FredkinCellWrite_3);
  CPPUNIT_TEST(test_FredkinCellClone_1);
  CPPUNIT_TEST(test_FredkinCellClone_2);
  CPPUNIT_TEST(test_FredkinCellClone_3);
  CPPUNIT_TEST(test_FredkinCellEval_1);
  CPPUNIT_TEST(test_FredkinCellEval_2);
  CPPUNIT_TEST(test_FredkinCellEval_3);
  CPPUNIT_TEST(test_FredkinCellTurn_1);
  CPPUNIT_TEST(test_FredkinCellTurn_2);
  CPPUNIT_TEST(test_FredkinCellTurn_3);

  CPPUNIT_TEST(test_CellIsDead_1);
  CPPUNIT_TEST(test_CellIsDead_2);
  CPPUNIT_TEST(test_CellIsDead_3);
  CPPUNIT_TEST(test_CellClone_1);
  CPPUNIT_TEST(test_CellClone_2);
  CPPUNIT_TEST(test_CellClone_3);
  CPPUNIT_TEST(test_CellWrite_1);
  CPPUNIT_TEST(test_CellWrite_2);
  CPPUNIT_TEST(test_CellWrite_3);
  CPPUNIT_TEST(test_CellWrite_4);
  CPPUNIT_TEST(test_CellEval_1);
  CPPUNIT_TEST(test_CellEval_2);
  CPPUNIT_TEST(test_CellEval_3);
  CPPUNIT_TEST(test_CellTurn_1);
  CPPUNIT_TEST(test_CellTurn_2);
  CPPUNIT_TEST(test_CellTurn_3);

  CPPUNIT_TEST(test_Life_1);
  CPPUNIT_TEST(test_Life_2);
  CPPUNIT_TEST(test_Life_3);
  CPPUNIT_TEST(test_putCell_1);
  CPPUNIT_TEST(test_putCell_2);
  CPPUNIT_TEST(test_putCell_3);
  CPPUNIT_TEST(test_printBoard_1);
  CPPUNIT_TEST(test_printBoard_2);
  CPPUNIT_TEST(test_printBoard_3);
  CPPUNIT_TEST(test_printBoard_4);
  CPPUNIT_TEST(test_neighbors_1);
  CPPUNIT_TEST(test_neighbors_2);
  CPPUNIT_TEST(test_neighbors_3);
  CPPUNIT_TEST(test_neighbors_4);
  CPPUNIT_TEST(test_mutate_1);
  CPPUNIT_TEST(test_mutate_2);
  CPPUNIT_TEST(test_mutate_3);
  CPPUNIT_TEST(test_doGeneration_1);
  CPPUNIT_TEST(test_doGeneration_2);
  CPPUNIT_TEST(test_doGeneration_3);
  CPPUNIT_TEST(test_doGeneration_4);
  CPPUNIT_TEST(test_doGeneration_5);
  CPPUNIT_TEST_SUITE_END();
};

// ----
// main
// ----

int main () {
  using namespace std;
  ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
  cout << "TestLife.c++" << endl;

  CppUnit::TextTestRunner tr;
  tr.addTest(TestLife::suite());
  tr.run();
}
