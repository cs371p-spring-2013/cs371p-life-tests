// ------------
// Eric Carrillo
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
// TestLife
// ----------

struct TestLife : CppUnit::TestFixture {

  // ----------
  // ConwayCell
  // ----------

  void testConway1() {
    ConwayCell cell('*');
    CPPUNIT_ASSERT(cell.type == 'c');
    CPPUNIT_ASSERT(cell.n == 0);
    CPPUNIT_ASSERT(cell.state == '*');
  }

  void testConway2() {
    ConwayCell cell('.');
    CPPUNIT_ASSERT(cell.type == 'c');
    CPPUNIT_ASSERT(cell.n == 0);
    CPPUNIT_ASSERT(cell.state == '.');
  }

  void testConway3() {
    ConwayCell cell('*');
    ConwayCell cell2('.');
    CPPUNIT_ASSERT(cell.type == 'c');
    CPPUNIT_ASSERT(cell.n == 0);
    CPPUNIT_ASSERT(cell.state == '*');
    CPPUNIT_ASSERT(cell2.type == 'c');
    CPPUNIT_ASSERT(cell2.n == 0);
    CPPUNIT_ASSERT(cell2.state == '.');
  }


  // ---------------
  // ConwayCellType
  // ---------------

  void testConwayType1(){
    ConwayCell cell('*');
    CPPUNIT_ASSERT(cell.getType() == 'c');
  }

  void testConwayType2(){
    ConwayCell cell('.');
    CPPUNIT_ASSERT(cell.getType() == 'c');
  }

  void testConwayType3(){
    ConwayCell cell('.');
    ConwayCell cell2('*');
    CPPUNIT_ASSERT(cell.getType() == 'c');
    CPPUNIT_ASSERT(cell2.getType() == 'c');
  }

  // ---------------
  // ConwayCellState
  // ---------------

  void testConwayState1(){
    ConwayCell cell('*');
    CPPUNIT_ASSERT(cell.getState() == '*');
  }

  void testConwayState2(){
    ConwayCell cell('.');
    CPPUNIT_ASSERT(cell.getState() == '.');
  }

  void testConwayState3(){
    ConwayCell cell('.');
    ConwayCell cell2('*');
    CPPUNIT_ASSERT(cell.getState() == '.');
    CPPUNIT_ASSERT(cell2.getState() == '*');
  }

  // ---------------
  // ConwayCellAddN
  // ---------------

  void testConwayAdd1(){
    ConwayCell cell('.');
    cell.addNeighbor();
    CPPUNIT_ASSERT(cell.n == 1);
  }

  void testConwayAdd2(){
    ConwayCell cell('.');
    for(int i = 0; i < 100; i++)
      cell.addNeighbor();
    CPPUNIT_ASSERT(cell.n == 100);
  }

  void testConwayAdd3(){
    ConwayCell cell('*');
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    CPPUNIT_ASSERT(cell.n == 5);
  }

  // ------------
  // ConwayCellN
  // ------------

  void testConwayN1(){
    ConwayCell cell('.');
    CPPUNIT_ASSERT(cell.neighbors() == 0);
  }

  void testConwayN2(){
    ConwayCell cell('*');
    for(int i = 0; i < 100; i++)
      cell.addNeighbor();
    CPPUNIT_ASSERT(cell.neighbors() == 100);
  }

  void testConwayN3(){
    ConwayCell cell('*');
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    CPPUNIT_ASSERT(cell.neighbors() == 5);
  }

  // ---------------
  // ConwayCellZero
  // ---------------

  void testConwayZero1(){
    ConwayCell cell('*');
    cell.zeroNeighbors();
    CPPUNIT_ASSERT(cell.n == 0);
  }

  void testConwayZero2(){
    ConwayCell cell('*');
    for(int i = 0; i < 100; i++)
      cell.addNeighbor();
    cell.zeroNeighbors();
    CPPUNIT_ASSERT(cell.n == 0);
  }

  void testConwayZero3(){
    ConwayCell cell('*');
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.zeroNeighbors();
    CPPUNIT_ASSERT(cell.n == 0);
  }

  // ---------------
  // ConwayCellAlive
  // ---------------

  void testConwayAlive1(){
    ConwayCell cell('*');
    CPPUNIT_ASSERT(cell.alive());
  }

  void testConwayAlive2(){
    ConwayCell cell('.');
    CPPUNIT_ASSERT(!cell.alive());
  }

  void testConwayAlive3(){
    ConwayCell cell('.');
    ConwayCell cell2('*');
    CPPUNIT_ASSERT(!cell.alive());
    CPPUNIT_ASSERT(cell2.alive());
  }

  // --------------
  // ConwayCellNext
  // --------------

  void testConwayNext1(){
    ConwayCell cell('*');
    cell.nextGen();
    CPPUNIT_ASSERT(cell.state == '.');
  }

  void testConwayNext2(){
    ConwayCell cell('*');
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.nextGen();
    CPPUNIT_ASSERT(cell.state == '.');
  }

  void testConwayNext3(){
    ConwayCell cell('.');
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.nextGen();
    CPPUNIT_ASSERT(cell.state == '*');
  }


  // ----------
  // FredkinCell
  // ----------

  void testFredkin1() {
    FredkinCell cell('0');
    CPPUNIT_ASSERT(cell.type == 'f');
    CPPUNIT_ASSERT(cell.n == 0);
    CPPUNIT_ASSERT(cell.state == '0');
  }

  void testFredkin2() {
    FredkinCell cell('-');
    CPPUNIT_ASSERT(cell.type == 'f');
    CPPUNIT_ASSERT(cell.n == 0);
    CPPUNIT_ASSERT(cell.state == '-');
  }

  void testFredkin3() {
    FredkinCell cell('0');
    FredkinCell cell2('-');
    CPPUNIT_ASSERT(cell.type == 'f');
    CPPUNIT_ASSERT(cell.n == 0);
    CPPUNIT_ASSERT(cell.state == '0');
    CPPUNIT_ASSERT(cell2.type == 'f');
    CPPUNIT_ASSERT(cell2.n == 0);
    CPPUNIT_ASSERT(cell2.state == '-');
  }

  // ---------------
  // FredkinCellType
  // ---------------

  void testFredkinType1(){
    FredkinCell cell('0');
    CPPUNIT_ASSERT(cell.getType() == 'f');
  }

  void testFredkinType2(){
    FredkinCell cell('-');
    CPPUNIT_ASSERT(cell.getType() == 'f');
  }

  void testFredkinType3(){
    FredkinCell cell('-');
    FredkinCell cell2('0');
    CPPUNIT_ASSERT(cell.getType() == 'f');
    CPPUNIT_ASSERT(cell2.getType() == 'f');
  }

  // ---------------
  // FredkinCellState
  // ---------------

  void testFredkinState1(){
    FredkinCell cell('0');
    CPPUNIT_ASSERT(cell.getState() == '0');
  }

  void testFredkinState2(){
    FredkinCell cell('-');
    CPPUNIT_ASSERT(cell.getState() == '-');
  }

  void testFredkinState3(){
    FredkinCell cell('0');
    FredkinCell cell2('-');
    CPPUNIT_ASSERT(cell.getState() == '0');
    CPPUNIT_ASSERT(cell2.getState() == '-');
  }

  // ---------------
  // FredkinCellAddN
  // ---------------

  void testFredkinAdd1(){
    FredkinCell cell('0');
    cell.addNeighbor();
    CPPUNIT_ASSERT(cell.n == 1);
  }

  void testFredkinAdd2(){
    FredkinCell cell('-');
    for(int i = 0; i < 100; i++)
      cell.addNeighbor();
    CPPUNIT_ASSERT(cell.n == 100);
  }

  void testFredkinAdd3(){
    FredkinCell cell('0');
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    CPPUNIT_ASSERT(cell.n == 5);
  }


  // ------------
  // FredkinCellN
  // ------------

  void testFredkinN1(){
    FredkinCell cell('-');
    CPPUNIT_ASSERT(cell.neighbors() == 0);
  }

  void testFredkinN2(){
    FredkinCell cell('0');
    for(int i = 0; i < 100; i++)
      cell.addNeighbor();
    CPPUNIT_ASSERT(cell.neighbors() == 100);
  }

  void testFredkinN3(){
    FredkinCell cell('-');
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    CPPUNIT_ASSERT(cell.neighbors() == 5);
  }


  // ---------------
  // FredkinCellZero
  // ---------------

  void testFredkinZero1(){
    FredkinCell cell('-');
    cell.zeroNeighbors();
    CPPUNIT_ASSERT(cell.n == 0);
  }

  void testFredkinZero2(){
    FredkinCell cell('0');
    for(int i = 0; i < 100; i++)
      cell.addNeighbor();
    cell.zeroNeighbors();
    CPPUNIT_ASSERT(cell.n == 0);
  }

  void testFredkinZero3(){
    FredkinCell cell('*');
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.zeroNeighbors();
    CPPUNIT_ASSERT(cell.n == 0);
  }

  // ---------------
  // FredkinCellAlive
  // ---------------

  void testFredkinAlive1(){
    FredkinCell cell('+');
    CPPUNIT_ASSERT(cell.alive());
  }

  void testFredkinAlive2(){
    FredkinCell cell('-');
    CPPUNIT_ASSERT(!cell.alive());
  }

  void testFredkinAlive3(){
    FredkinCell cell('-');
    FredkinCell cell2('3');
    CPPUNIT_ASSERT(!cell.alive());
    CPPUNIT_ASSERT(cell2.alive());
  }

  // ---------------
  // FredkinCellNext
  // ---------------

  void testFredkinNext1(){
    FredkinCell cell('-');
    cell.nextGen();
    CPPUNIT_ASSERT(cell.state == '-');
  }

  void testFredkinNext2(){
    FredkinCell cell('5');
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.nextGen();
    CPPUNIT_ASSERT(cell.state == '-');
  }

  void testFredkinNext3(){
    FredkinCell cell('0');
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.nextGen();
    CPPUNIT_ASSERT(cell.state == '1');
  }



  // ----
  // Cell
  // ----

  void testCell1() {
    Cell cell('0');
    CPPUNIT_ASSERT(cell.getType() == 'f');
    CPPUNIT_ASSERT(cell.neighbors() == 0);
    CPPUNIT_ASSERT(cell.getState() == '0');
  }

  void testCell2() {
    Cell cell('*');
    CPPUNIT_ASSERT(cell.getType() == 'c');
    CPPUNIT_ASSERT(cell.neighbors() == 0);
    CPPUNIT_ASSERT(cell.getState() == '*');
  }

  void testCell3() {
    Cell cell('*');
    Cell cell2('0');
    CPPUNIT_ASSERT(cell.getType() == 'c');
    CPPUNIT_ASSERT(cell.neighbors() == 0);
    CPPUNIT_ASSERT(cell.getState() == '*');
    CPPUNIT_ASSERT(cell2.getType() == 'f');
    CPPUNIT_ASSERT(cell2.neighbors() == 0);
    CPPUNIT_ASSERT(cell2.getState() == '0');
  }

  // --------
  // CellType
  // --------

  void testCellType1(){
    Cell cell('0');
    CPPUNIT_ASSERT(cell.getType() == 'f');
  }

  void testCellType2(){
    Cell cell('*');
    CPPUNIT_ASSERT(cell.getType() == 'c');
  }

  void testCellType3(){
    Cell cell('-');
    Cell cell2('*');
    CPPUNIT_ASSERT(cell.getType() == 'f');
    CPPUNIT_ASSERT(cell2.getType() == 'c');
  }

  // ---------
  // CellState
  // ---------

  void testCellState1(){
    Cell cell('0');
    CPPUNIT_ASSERT(cell.getState() == '0');
  }

  void testCellState2(){
    Cell cell('*');
    CPPUNIT_ASSERT(cell.getState() == '*');
  }

  void testCellState3(){
    Cell cell('0');
    Cell cell2('*');
    CPPUNIT_ASSERT(cell.getState() == '0');
    CPPUNIT_ASSERT(cell2.getState() == '*');
  }

  // ---------
  // CellAddN
  // ---------

  void testCellAdd1(){
    Cell cell('0');
    cell.addNeighbor();
    CPPUNIT_ASSERT(cell.neighbors() == 1);
  }

  void testCellAdd2(){
    Cell cell('*');
    for(int i = 0; i < 100; i++)
      cell.addNeighbor();
    CPPUNIT_ASSERT(cell.neighbors() == 100);
  }

  void testCellAdd3(){
    Cell cell('0');
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    CPPUNIT_ASSERT(cell.neighbors() == 5);
  }


  // -----
  // CellN
  // -----

  void testCellN1(){
    Cell cell('-');
    CPPUNIT_ASSERT(cell.neighbors() == 0);
  }

  void testCellN2(){
    Cell cell('*');
    for(int i = 0; i < 100; i++)
      cell.addNeighbor();
    CPPUNIT_ASSERT(cell.neighbors() == 100);
  }

  void testCellN3(){
    Cell cell('*');
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    CPPUNIT_ASSERT(cell.neighbors() == 5);
  }


  // --------
  // CellZero
  // --------

  void testCellZero1(){
    Cell cell('-');
    cell.zeroNeighbors();
    CPPUNIT_ASSERT(cell.neighbors() == 0);
  }

  void testCellZero2(){
    Cell cell('*');
    for(int i = 0; i < 100; i++)
      cell.addNeighbor();
    cell.zeroNeighbors();
    CPPUNIT_ASSERT(cell.neighbors() == 0);
  }

  void testCellZero3(){
    Cell cell('*');
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.zeroNeighbors();
    CPPUNIT_ASSERT(cell.neighbors() == 0);
  }

  // ---------
  // CellAlive
  // ---------

  void testCellAlive1(){
    Cell cell('0');
    CPPUNIT_ASSERT(cell.alive());
  }

  void testCellAlive2(){
    Cell cell('.');
    CPPUNIT_ASSERT(!cell.alive());
  }

  void testCellAlive3(){
    Cell cell('-');
    Cell cell2('*');
    CPPUNIT_ASSERT(!cell.alive());
    CPPUNIT_ASSERT(cell2.alive());
  }

  // --------
  // CellNext
  // --------

  void testCellNext1(){
    Cell cell('-');
    cell.nextGen();
    CPPUNIT_ASSERT(cell.getState() == '-');
  }

  void testCellNext2(){
    Cell cell('5');
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.nextGen();
    CPPUNIT_ASSERT(cell.getState() == '-');
  }

  void testCellNext3(){
    Cell cell('0');
    cell.addNeighbor();
    cell.addNeighbor();
    cell.addNeighbor();
    cell.nextGen();
    CPPUNIT_ASSERT(cell.getState() == '1');
  }


  // ----
  // Life
  // ----

  void testLife1(){
    Life<ConwayCell> life(10,10);
    CPPUNIT_ASSERT(life.rows == 10);
    CPPUNIT_ASSERT(life.cols == 10);
    CPPUNIT_ASSERT(!life.board[0][0].alive());
    CPPUNIT_ASSERT(life.board[0][0].getType() == 'c');
    CPPUNIT_ASSERT(life.board[0][0].state == '.');
  }

  void testLife2(){
    Life<FredkinCell> life(10,10);
    CPPUNIT_ASSERT(life.rows == 10);
    CPPUNIT_ASSERT(life.cols == 10);
    CPPUNIT_ASSERT(!life.board[0][0].alive());
    CPPUNIT_ASSERT(life.board[0][0].getType() == 'f');
    CPPUNIT_ASSERT(life.board[0][0].state == '-');
  }

  void testLife3(){
    Life<Cell> life(10,10);
    CPPUNIT_ASSERT(life.rows == 10);
    CPPUNIT_ASSERT(life.cols == 10);
    CPPUNIT_ASSERT(!life.board[0][0].alive());
    CPPUNIT_ASSERT(life.board[0][0].getType() == 'f');
    CPPUNIT_ASSERT(life.board[0][0].getState() == '-');
  }


  CPPUNIT_TEST_SUITE(TestLife);
  CPPUNIT_TEST(testConway1);
  CPPUNIT_TEST(testConway2);
  CPPUNIT_TEST(testConway3);
  CPPUNIT_TEST(testConwayState1);
  CPPUNIT_TEST(testConwayState2);
  CPPUNIT_TEST(testConwayState3);
  CPPUNIT_TEST(testConwayType1);
  CPPUNIT_TEST(testConwayType2);
  CPPUNIT_TEST(testConwayType3);
  CPPUNIT_TEST(testConwayAdd1);
  CPPUNIT_TEST(testConwayAdd2);
  CPPUNIT_TEST(testConwayAdd3);
  CPPUNIT_TEST(testConwayN1);
  CPPUNIT_TEST(testConwayN2);
  CPPUNIT_TEST(testConwayN3);
  CPPUNIT_TEST(testConwayZero1);
  CPPUNIT_TEST(testConwayZero2);
  CPPUNIT_TEST(testConwayZero3);
  CPPUNIT_TEST(testConwayAlive1);
  CPPUNIT_TEST(testConwayAlive2);
  CPPUNIT_TEST(testConwayAlive3);
  CPPUNIT_TEST(testConwayNext1);
  CPPUNIT_TEST(testConwayNext2);
  CPPUNIT_TEST(testConwayNext3);

  CPPUNIT_TEST(testFredkin1);
  CPPUNIT_TEST(testFredkin2);
  CPPUNIT_TEST(testFredkin3);
  CPPUNIT_TEST(testFredkinType1);
  CPPUNIT_TEST(testFredkinType2);
  CPPUNIT_TEST(testFredkinType3);
  CPPUNIT_TEST(testFredkinState1);
  CPPUNIT_TEST(testFredkinState2);
  CPPUNIT_TEST(testFredkinState3);
  CPPUNIT_TEST(testFredkinAdd1);
  CPPUNIT_TEST(testFredkinAdd2);
  CPPUNIT_TEST(testFredkinAdd3);
  CPPUNIT_TEST(testFredkinN1);
  CPPUNIT_TEST(testFredkinN2);
  CPPUNIT_TEST(testFredkinN3);
  CPPUNIT_TEST(testFredkinZero1);
  CPPUNIT_TEST(testFredkinZero2);
  CPPUNIT_TEST(testFredkinZero3);
  CPPUNIT_TEST(testFredkinAlive1);
  CPPUNIT_TEST(testFredkinAlive2);
  CPPUNIT_TEST(testFredkinAlive3);
  CPPUNIT_TEST(testFredkinNext1);
  CPPUNIT_TEST(testFredkinNext2);
  CPPUNIT_TEST(testFredkinNext3);

  CPPUNIT_TEST(testCell1);
  CPPUNIT_TEST(testCell2);
  CPPUNIT_TEST(testCell3);
  CPPUNIT_TEST(testCellType1);
  CPPUNIT_TEST(testCellType2);
  CPPUNIT_TEST(testCellType3);
  CPPUNIT_TEST(testCellState1);
  CPPUNIT_TEST(testCellState2);
  CPPUNIT_TEST(testCellState3);
  CPPUNIT_TEST(testCellAdd1);
  CPPUNIT_TEST(testCellAdd2);
  CPPUNIT_TEST(testCellAdd3);
  CPPUNIT_TEST(testCellN1);
  CPPUNIT_TEST(testCellN2);
  CPPUNIT_TEST(testCellN3);
  CPPUNIT_TEST(testCellZero1);
  CPPUNIT_TEST(testCellZero2);
  CPPUNIT_TEST(testCellZero3);
  CPPUNIT_TEST(testCellAlive1);
  CPPUNIT_TEST(testCellAlive2);
  CPPUNIT_TEST(testCellAlive3);
  CPPUNIT_TEST(testCellNext1);
  CPPUNIT_TEST(testCellNext2);
  CPPUNIT_TEST(testCellNext3);

  CPPUNIT_TEST(testLife1);
  CPPUNIT_TEST(testLife2);
  CPPUNIT_TEST(testLife3);

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