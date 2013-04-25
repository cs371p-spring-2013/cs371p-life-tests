#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TextTestRunner.h"


#define private public
#define protected public
#define class struct

#include "Cell.h"
#include "Life.h"

using namespace std;

// ----------
// TestDarwin
// ----------

struct TestLife : CppUnit::TestFixture
{
  // ---------
  // TestSuite
  // ---------

  void test1 ()
  {
    Handle <ConwayCell> aHandle (new ConwayCell ());
    CPPUNIT_ASSERT (!aHandle.myPointer -> isAlive);
    CPPUNIT_ASSERT (dynamic_cast <ConwayCell*> (aHandle.myPointer));
    CPPUNIT_ASSERT (!dynamic_cast <FredkinCell*> (aHandle.myPointer));
  }

  void test2 ()
  {
    Handle <ConwayCell> aHandle (0);
    Handle <ConwayCell> anotherHandle (aHandle);
    CPPUNIT_ASSERT (aHandle.myPointer == 0);
    CPPUNIT_ASSERT (anotherHandle.myPointer == 0);
  }

  void test3 ()
  {
    Handle <ConwayCell> aHandle (new ConwayCell ());
    Handle <ConwayCell> anotherHandle (aHandle);
    CPPUNIT_ASSERT (!aHandle.myPointer -> isAlive);
    CPPUNIT_ASSERT (!anotherHandle.myPointer -> isAlive);
    CPPUNIT_ASSERT (!(aHandle.myPointer == anotherHandle.myPointer));
  }

  void test4 ()
  {
    AbstractCell* aCell = new ConwayCell ();
    CPPUNIT_ASSERT (!aCell -> isAlive);
    CPPUNIT_ASSERT (!aCell -> getIsAlive ());
    aCell -> changeState ();
    CPPUNIT_ASSERT (aCell -> isAlive);
    CPPUNIT_ASSERT (aCell -> getIsAlive ());
    delete aCell;
  }

  void test5 ()
  {
    AbstractCell* aCell = new ConwayCell ();
    std::ostringstream outStream;
    outStream << *aCell;
    CPPUNIT_ASSERT (outStream.str () == ".");
    std::ostringstream anotherOutStream;
    aCell -> write (anotherOutStream);
    CPPUNIT_ASSERT (anotherOutStream.str () == ".");
    delete aCell;
  }

  void test6 ()
  {
    Cell aCell (new ConwayCell ());
    CPPUNIT_ASSERT (!aCell.myPointer -> isAlive);
    CPPUNIT_ASSERT (!aCell.getIsAlive ());
    aCell.animate (' ');
    CPPUNIT_ASSERT (aCell.getIsAlive ());
    aCell.changeState ();
    CPPUNIT_ASSERT (!aCell.getIsAlive ());
    CPPUNIT_ASSERT (dynamic_cast <ConwayCell*> (aCell.myPointer));
    CPPUNIT_ASSERT (!dynamic_cast <FredkinCell*> (aCell.myPointer));
  }

  void test7 ()
  {
    Cell aCell (0);
    Cell anotherCell (aCell);
    CPPUNIT_ASSERT (aCell.myPointer == 0);
    CPPUNIT_ASSERT (anotherCell.myPointer == 0);
  }

  void test8 ()
  {
    Cell aCell (new FredkinCell ());
    CPPUNIT_ASSERT (!dynamic_cast <ConwayCell*> (aCell.myPointer));
    CPPUNIT_ASSERT (dynamic_cast <FredkinCell*> (aCell.myPointer));
    std::ostringstream outStream;
    outStream << aCell;
    CPPUNIT_ASSERT (outStream.str () == "-");
    aCell.mutate ();
    CPPUNIT_ASSERT (dynamic_cast <ConwayCell*> (aCell.myPointer));
    CPPUNIT_ASSERT (!dynamic_cast <FredkinCell*> (aCell.myPointer));
    CPPUNIT_ASSERT (aCell.getIsAlive ());
    std::ostringstream anotherOutStream;
    anotherOutStream << aCell;
    CPPUNIT_ASSERT (anotherOutStream.str () == "*");
  }

  void test9 ()
  {
    Cell aCell (new FredkinCell ());
    CPPUNIT_ASSERT (!aCell.getIsAlive ());
    CPPUNIT_ASSERT (!dynamic_cast <ConwayCell*> (aCell.myPointer));
    CPPUNIT_ASSERT (dynamic_cast <FredkinCell*> (aCell.myPointer));
    std::ostringstream outStream1;
    outStream1 << aCell;
    CPPUNIT_ASSERT (outStream1.str () == "-");
    aCell.animate ('0');
    std::ostringstream outStream2;
    outStream2 << aCell;
    CPPUNIT_ASSERT (aCell.getIsAlive ());
    CPPUNIT_ASSERT (outStream2.str () == "0");
    CPPUNIT_ASSERT (aCell.simulate (1, 0) == 0);
    std::ostringstream outStream3;
    outStream3 << aCell;
    CPPUNIT_ASSERT (outStream3.str () == "1");
    CPPUNIT_ASSERT (aCell.simulate (1, 0) == 2);
    std::ostringstream outStream4;
    outStream4 << aCell;
    CPPUNIT_ASSERT (outStream4.str () == "2");
  }

  void test10 ()
  {
    ConwayCell aCell;
    CPPUNIT_ASSERT (!aCell.isAlive);
    CPPUNIT_ASSERT (!aCell.getIsAlive ());
    aCell.changeState ();
    CPPUNIT_ASSERT (aCell.isAlive);
    CPPUNIT_ASSERT (aCell.getIsAlive ());
  }

  void test11 ()
  {
    ConwayCell aCell;
    CPPUNIT_ASSERT (!aCell.isAlive);
    CPPUNIT_ASSERT (!aCell.getIsAlive ());
    std::ostringstream outStream1;
    outStream1 << aCell;
    CPPUNIT_ASSERT (aCell.getChar () == '.');
    CPPUNIT_ASSERT (outStream1.str () == ".");
    aCell.animate ('0');
    std::ostringstream outStream2;
    outStream2 << aCell;
    CPPUNIT_ASSERT (aCell.getIsAlive ());
    CPPUNIT_ASSERT (aCell.getChar () == '*');
    CPPUNIT_ASSERT (outStream2.str () == "*");
  }

  void test12 ()
  {
    ConwayCell aCell1;
    CPPUNIT_ASSERT (!aCell1.isAlive);
    CPPUNIT_ASSERT (!aCell1.getIsAlive ());
    ConwayCell* anotherCell = aCell1.clone ();
    CPPUNIT_ASSERT (!anotherCell -> isAlive);
    CPPUNIT_ASSERT (!anotherCell -> getIsAlive ());
    aCell1.changeState ();
    CPPUNIT_ASSERT (aCell1.isAlive);
    CPPUNIT_ASSERT (aCell1.getIsAlive ());
    ConwayCell* aCell2 = aCell1.clone ();
    CPPUNIT_ASSERT (aCell2 -> isAlive);
    CPPUNIT_ASSERT (aCell2 -> getIsAlive ());
    delete anotherCell;
    delete aCell2;
  }

  void test13 ()
  {
    ConwayCell aCell1;
    CPPUNIT_ASSERT (!aCell1.isAlive);
    CPPUNIT_ASSERT (!aCell1.getIsAlive ());
    CPPUNIT_ASSERT (aCell1.simulate (1, 2) == 1);
    CPPUNIT_ASSERT (aCell1.simulate (2, 1) == 1);
    CPPUNIT_ASSERT (aCell1.simulate (2, 2) == 0);
    aCell1.changeState ();
    CPPUNIT_ASSERT (aCell1.isAlive);
    CPPUNIT_ASSERT (aCell1.getIsAlive ());
    CPPUNIT_ASSERT (aCell1.simulate (1, 0) == 1);
    CPPUNIT_ASSERT (aCell1.simulate (2, 2) == 1);
    CPPUNIT_ASSERT (aCell1.simulate (2, 0) == 0);
  }

  void test14 ()
  {
    ConwayCell* aCell1 = new ConwayCell;
    CPPUNIT_ASSERT (dynamic_cast <ConwayCell*> (aCell1));
    CPPUNIT_ASSERT (!dynamic_cast <FredkinCell*> (aCell1));
    aCell1 -> mutate ();
    CPPUNIT_ASSERT (dynamic_cast <ConwayCell*> (aCell1));
    CPPUNIT_ASSERT (!dynamic_cast <FredkinCell*> (aCell1));
    delete aCell1;
  }

  void test15 ()
  {
    FredkinCell aCell;
    CPPUNIT_ASSERT (!aCell.isAlive);
    CPPUNIT_ASSERT (!aCell.getIsAlive ());
    CPPUNIT_ASSERT (aCell.myAge == 0);
    aCell.changeState ();
    CPPUNIT_ASSERT (aCell.isAlive);
    CPPUNIT_ASSERT (aCell.getIsAlive ());
    CPPUNIT_ASSERT (aCell.myAge == 0);
  }

  void test16 ()
  {
    FredkinCell aCell;
    CPPUNIT_ASSERT (!aCell.isAlive);
    CPPUNIT_ASSERT (!aCell.getIsAlive ());
    CPPUNIT_ASSERT (aCell.myAge == 0);
    std::ostringstream outStream1;
    outStream1 << aCell;
    CPPUNIT_ASSERT (aCell.getChar () == '-');
    CPPUNIT_ASSERT (outStream1.str () == "-");
    aCell.animate ('0');
    std::ostringstream outStream2;
    outStream2 << aCell;
    CPPUNIT_ASSERT (aCell.myAge == 0);
    CPPUNIT_ASSERT (aCell.getIsAlive ());
    CPPUNIT_ASSERT (aCell.getChar () == '0');
    CPPUNIT_ASSERT (outStream2.str () == "0");
  }

  void test17 ()
  {
    FredkinCell aCell1;
    CPPUNIT_ASSERT (!aCell1.isAlive);
    CPPUNIT_ASSERT (!aCell1.getIsAlive ());
    CPPUNIT_ASSERT (aCell1.myAge == 0);
    FredkinCell* anotherCell = aCell1.clone ();
    CPPUNIT_ASSERT (!anotherCell -> isAlive);
    CPPUNIT_ASSERT (!anotherCell -> getIsAlive ());
    CPPUNIT_ASSERT (anotherCell -> myAge == 0);
    aCell1.changeState ();
    CPPUNIT_ASSERT (aCell1.isAlive);
    CPPUNIT_ASSERT (aCell1.getIsAlive ());
    CPPUNIT_ASSERT (aCell1.myAge == 0);
    FredkinCell* aCell2 = aCell1.clone ();
    CPPUNIT_ASSERT (aCell2 -> isAlive);
    CPPUNIT_ASSERT (aCell2 -> getIsAlive ());
    CPPUNIT_ASSERT (aCell2 -> myAge == 0);
    delete anotherCell;
    delete aCell2;
  }

  void test18 ()
  {
    FredkinCell aCell1;
    CPPUNIT_ASSERT (!aCell1.isAlive);
    CPPUNIT_ASSERT (!aCell1.getIsAlive ());
    CPPUNIT_ASSERT (aCell1.simulate (1, 3) == 1);
    CPPUNIT_ASSERT (aCell1.simulate (3, 15) == 1);
    CPPUNIT_ASSERT (aCell1.simulate (0, 1) == 0);
    aCell1.changeState ();
    CPPUNIT_ASSERT (aCell1.isAlive);
    CPPUNIT_ASSERT (aCell1.getIsAlive ());
    CPPUNIT_ASSERT (aCell1.simulate (0, 1) == 1);
    CPPUNIT_ASSERT (aCell1.simulate (2, 0) == 1);
    CPPUNIT_ASSERT (aCell1.simulate (1, 0) == 0);
    CPPUNIT_ASSERT (aCell1.myAge == 1);
  }

  void test19 ()
  {
    FredkinCell* aCell1 = new FredkinCell;
    CPPUNIT_ASSERT (!dynamic_cast <ConwayCell*> (aCell1));
    CPPUNIT_ASSERT (dynamic_cast <FredkinCell*> (aCell1));
    aCell1 -> mutate ();
    CPPUNIT_ASSERT (!dynamic_cast <ConwayCell*> (aCell1));
    CPPUNIT_ASSERT (dynamic_cast <FredkinCell*> (aCell1));
    delete aCell1;
  }

  void test20 ()
  {
    Life <ConwayCell> aLife (1, 1);
    CPPUNIT_ASSERT (aLife.myRows == 1);
    CPPUNIT_ASSERT (aLife.myCols == 1);
    CPPUNIT_ASSERT (aLife.population == 0);
    CPPUNIT_ASSERT (aLife.generation == 0);
    CPPUNIT_ASSERT (!aLife.myBoard [0] [0].isAlive);
    std::ostringstream outStream1;
    outStream1 << aLife;
    CPPUNIT_ASSERT (outStream1.str () == "Generation = 0, Population = 0.\n.\n");
  }

  void test21 ()
  {
    ConwayCell aCell;
    Life <ConwayCell> aLife (1, 1, aCell);
    CPPUNIT_ASSERT (aLife.myRows == 1);
    CPPUNIT_ASSERT (aLife.myCols == 1);
    CPPUNIT_ASSERT (aLife.population == 0);
    CPPUNIT_ASSERT (aLife.generation == 0);
    CPPUNIT_ASSERT (!aLife.myBoard [0] [0].isAlive);
    std::ostringstream outStream1;
    outStream1 << aLife;
    CPPUNIT_ASSERT (outStream1.str () == "Generation = 0, Population = 0.\n.\n");
  }

  void test22 ()
  {
    Life <FredkinCell> aLife (1, 1);
    CPPUNIT_ASSERT (aLife.myRows == 1);
    CPPUNIT_ASSERT (aLife.myCols == 1);
    CPPUNIT_ASSERT (aLife.population == 0);
    CPPUNIT_ASSERT (aLife.generation == 0);
    CPPUNIT_ASSERT (!aLife.myBoard [0] [0].isAlive);
    CPPUNIT_ASSERT (aLife.myBoard [0] [0].myAge == 0);
    std::ostringstream outStream1;
    outStream1 << aLife;
    CPPUNIT_ASSERT (outStream1.str () == "Generation = 0, Population = 0.\n-\n");
  }

  void test23 ()
  {
    FredkinCell aCell;
    aCell.animate ('0');
    Life <FredkinCell> aLife (1, 1, aCell);
    CPPUNIT_ASSERT (aLife.myRows == 1);
    CPPUNIT_ASSERT (aLife.myCols == 1);
    CPPUNIT_ASSERT (aLife.population == 0);
    CPPUNIT_ASSERT (aLife.generation == 0);
    CPPUNIT_ASSERT (aLife.myBoard [0] [0].isAlive);
    CPPUNIT_ASSERT (aLife.myBoard [0] [0].myAge == 0);
    std::ostringstream outStream1;
    outStream1 << aLife;
    CPPUNIT_ASSERT (outStream1.str () == "Generation = 0, Population = 0.\n0\n");
    ++aLife.myBoard [0] [0].myAge;
    std::ostringstream outStream2;
    outStream2 << aLife;
    CPPUNIT_ASSERT (outStream2.str () == "Generation = 0, Population = 0.\n1\n");
    aLife.myBoard [0] [0].myAge = 10;
    std::ostringstream outStream3;
    outStream3 << aLife;
    CPPUNIT_ASSERT (outStream3.str () == "Generation = 0, Population = 0.\n+\n");
  }

  void test24 ()
  {
    Life <ConwayCell> aLife (1, 1);
    CPPUNIT_ASSERT (aLife.myRows == 1);
    CPPUNIT_ASSERT (aLife.myCols == 1);
    CPPUNIT_ASSERT (aLife.population == 0);
    CPPUNIT_ASSERT (aLife.generation == 0);
    CPPUNIT_ASSERT (!aLife.myBoard [0] [0].isAlive);
    std::ostringstream outStream1;
    outStream1 << aLife;
    CPPUNIT_ASSERT (outStream1.str () == "Generation = 0, Population = 0.\n.\n");
    aLife.animate (0, 0, '.');
    CPPUNIT_ASSERT (aLife.myRows == 1);
    CPPUNIT_ASSERT (aLife.myCols == 1);
    CPPUNIT_ASSERT (aLife.population == 1);
    CPPUNIT_ASSERT (aLife.generation == 0);
    CPPUNIT_ASSERT (aLife.myBoard [0] [0].isAlive);
    std::ostringstream outStream2;
    outStream2 << aLife;
    CPPUNIT_ASSERT (outStream2.str () == "Generation = 0, Population = 1.\n*\n");
  }

  void test25 ()
  {
    Life <FredkinCell> aLife (1, 1);
    CPPUNIT_ASSERT (aLife.myRows == 1);
    CPPUNIT_ASSERT (aLife.myCols == 1);
    CPPUNIT_ASSERT (aLife.population == 0);
    CPPUNIT_ASSERT (aLife.generation == 0);
    CPPUNIT_ASSERT (!aLife.myBoard [0] [0].isAlive);
    std::ostringstream outStream1;
    outStream1 << aLife;
    CPPUNIT_ASSERT (outStream1.str () == "Generation = 0, Population = 0.\n-\n");
    aLife.animate (0, 0, '0');
    CPPUNIT_ASSERT (aLife.myRows == 1);
    CPPUNIT_ASSERT (aLife.myCols == 1);
    CPPUNIT_ASSERT (aLife.population == 1);
    CPPUNIT_ASSERT (aLife.generation == 0);
    CPPUNIT_ASSERT (aLife.myBoard [0] [0].isAlive);
    std::ostringstream outStream2;
    outStream2 << aLife;
    CPPUNIT_ASSERT (outStream2.str () == "Generation = 0, Population = 1.\n0\n");
  }

  void test26 ()
  {
    Life <FredkinCell> aLife (1, 1);
    CPPUNIT_ASSERT (aLife.myRows == 1);
    CPPUNIT_ASSERT (aLife.myCols == 1);
    CPPUNIT_ASSERT (aLife.population == 0);
    CPPUNIT_ASSERT (aLife.generation == 0);
    CPPUNIT_ASSERT (!aLife.myBoard [0] [0].isAlive);
    std::ostringstream outStream1;
    outStream1 << aLife;
    CPPUNIT_ASSERT (outStream1.str () == "Generation = 0, Population = 0.\n-\n");
    aLife.animate (0, 0, '0');
    CPPUNIT_ASSERT (aLife.myRows == 1);
    CPPUNIT_ASSERT (aLife.myCols == 1);
    CPPUNIT_ASSERT (aLife.population == 1);
    CPPUNIT_ASSERT (aLife.generation == 0);
    CPPUNIT_ASSERT (aLife.myBoard [0] [0].isAlive);
    std::ostringstream outStream2;
    outStream2 << aLife;
    CPPUNIT_ASSERT (outStream2.str () == "Generation = 0, Population = 1.\n0\n");
    ++aLife.myBoard [0] [0].myAge;
    std::ostringstream outStream3;
    outStream3 << aLife;
    CPPUNIT_ASSERT (outStream3.str () == "Generation = 0, Population = 1.\n1\n");
  }

  void test27 ()
  {
    Life <FredkinCell> aLife (1, 1);
    CPPUNIT_ASSERT (aLife.myRows == 1);
    CPPUNIT_ASSERT (aLife.myCols == 1);
    CPPUNIT_ASSERT (aLife.population == 0);
    CPPUNIT_ASSERT (aLife.generation == 0);
    CPPUNIT_ASSERT (!aLife.myBoard [0] [0].isAlive);
    std::ostringstream outStream1;
    outStream1 << aLife;
    CPPUNIT_ASSERT (outStream1.str () == "Generation = 0, Population = 0.\n-\n");
  }

  void test28 ()
  {
    Life <ConwayCell> aLife (2, 2);
    aLife.animate (0, 1, '*');
    aLife.animate (1, 0, '*');
    aLife.animate (1, 1, '*');
    CPPUNIT_ASSERT (aLife.myRows == 2);
    CPPUNIT_ASSERT (aLife.myCols == 2);
    CPPUNIT_ASSERT (aLife.population == 3);
    CPPUNIT_ASSERT (aLife.generation == 0);
    CPPUNIT_ASSERT (!aLife.myBoard [0] [0].isAlive);
    CPPUNIT_ASSERT (aLife.myBoard [0] [1].isAlive);
    CPPUNIT_ASSERT (aLife.myBoard [1] [0].isAlive);
    CPPUNIT_ASSERT (aLife.myBoard [1] [1].isAlive);
    std::ostringstream outStream1;
    outStream1 << aLife;
    CPPUNIT_ASSERT (outStream1.str () == "Generation = 0, Population = 3.\n.*\n**\n");
    aLife.simulate ();
    std::ostringstream outStream2;
    outStream2 << aLife;
    CPPUNIT_ASSERT (aLife.myRows == 2);
    CPPUNIT_ASSERT (aLife.myCols == 2);
    CPPUNIT_ASSERT (aLife.population == 4);
    CPPUNIT_ASSERT (aLife.generation == 1);
    CPPUNIT_ASSERT (outStream2.str () == "Generation = 1, Population = 4.\n**\n**\n");
    aLife.simulate ();
    std::ostringstream outStream3;
    outStream3 << aLife;
    CPPUNIT_ASSERT (aLife.myRows == 2);
    CPPUNIT_ASSERT (aLife.myCols == 2);
    CPPUNIT_ASSERT (aLife.population == 4);
    CPPUNIT_ASSERT (aLife.generation == 2);
    CPPUNIT_ASSERT (outStream3.str () == "Generation = 2, Population = 4.\n**\n**\n");
  }

  void test29 ()
  {
    Life <FredkinCell> aLife (2, 2);
    aLife.animate (0, 1, '0');
    aLife.animate (1, 0, '0');
    aLife.animate (1, 1, '0');
    CPPUNIT_ASSERT (aLife.myRows == 2);
    CPPUNIT_ASSERT (aLife.myCols == 2);
    CPPUNIT_ASSERT (aLife.population == 3);
    CPPUNIT_ASSERT (aLife.generation == 0);
    CPPUNIT_ASSERT (!aLife.myBoard [0] [0].isAlive);
    CPPUNIT_ASSERT (aLife.myBoard [0] [1].isAlive);
    CPPUNIT_ASSERT (aLife.myBoard [1] [0].isAlive);
    CPPUNIT_ASSERT (aLife.myBoard [1] [1].isAlive);
    std::ostringstream outStream1;
    outStream1 << aLife;
    CPPUNIT_ASSERT (outStream1.str () == "Generation = 0, Population = 3.\n-0\n00\n");
    aLife.simulate ();
    std::ostringstream outStream2;
    outStream2 << aLife;
    CPPUNIT_ASSERT (aLife.myRows == 2);
    CPPUNIT_ASSERT (aLife.myCols == 2);
    CPPUNIT_ASSERT (aLife.population == 2);
    CPPUNIT_ASSERT (aLife.generation == 1);
    CPPUNIT_ASSERT (outStream2.str () == "Generation = 1, Population = 2.\n-1\n1-\n");
    aLife.simulate ();
    std::ostringstream outStream3;
    outStream3 << aLife;
    CPPUNIT_ASSERT (aLife.myRows == 2);
    CPPUNIT_ASSERT (aLife.myCols == 2);
    CPPUNIT_ASSERT (aLife.population == 0);
    CPPUNIT_ASSERT (aLife.generation == 2);
    CPPUNIT_ASSERT (outStream3.str () == "Generation = 2, Population = 0.\n--\n--\n");
  }

  void test30 ()
  {
    Life <FredkinCell> aLife (2, 2);
    aLife.animate (0, 1, '0');
    aLife.animate (1, 1, '0');
    CPPUNIT_ASSERT (aLife.myRows == 2);
    CPPUNIT_ASSERT (aLife.myCols == 2);
    CPPUNIT_ASSERT (aLife.population == 2);
    CPPUNIT_ASSERT (aLife.generation == 0);
    CPPUNIT_ASSERT (!aLife.myBoard [0] [0].isAlive);
    CPPUNIT_ASSERT (aLife.myBoard [0] [1].isAlive);
    CPPUNIT_ASSERT (!aLife.myBoard [1] [0].isAlive);
    CPPUNIT_ASSERT (aLife.myBoard [1] [1].isAlive);
    std::ostringstream outStream1;
    outStream1 << aLife;
    CPPUNIT_ASSERT (outStream1.str () == "Generation = 0, Population = 2.\n-0\n-0\n");
    aLife.simulate ();
    std::ostringstream outStream2;
    outStream2 << aLife;
    CPPUNIT_ASSERT (aLife.myRows == 2);
    CPPUNIT_ASSERT (aLife.myCols == 2);
    CPPUNIT_ASSERT (aLife.population == 4);
    CPPUNIT_ASSERT (aLife.generation == 1);
    CPPUNIT_ASSERT (outStream2.str () == "Generation = 1, Population = 4.\n01\n01\n");
    aLife.simulate ();
    std::ostringstream outStream3;
    outStream3 << aLife;
    CPPUNIT_ASSERT (aLife.myRows == 2);
    CPPUNIT_ASSERT (aLife.myCols == 2);
    CPPUNIT_ASSERT (aLife.population == 0);
    CPPUNIT_ASSERT (aLife.generation == 2);
    CPPUNIT_ASSERT (outStream3.str () == "Generation = 2, Population = 0.\n--\n--\n");
  }

  CPPUNIT_TEST_SUITE (TestLife);
  CPPUNIT_TEST (test1);
  CPPUNIT_TEST (test2);
  CPPUNIT_TEST (test3);
  CPPUNIT_TEST (test4);
  CPPUNIT_TEST (test5);
  CPPUNIT_TEST (test6);
  CPPUNIT_TEST (test7);
  CPPUNIT_TEST (test8);
  CPPUNIT_TEST (test9);
  CPPUNIT_TEST (test10);
  CPPUNIT_TEST (test11);
  CPPUNIT_TEST (test12);
  CPPUNIT_TEST (test13);
  CPPUNIT_TEST (test14);
  CPPUNIT_TEST (test15);
  CPPUNIT_TEST (test16);
  CPPUNIT_TEST (test17);
  CPPUNIT_TEST (test18);
  CPPUNIT_TEST (test19);
  CPPUNIT_TEST (test20);
  CPPUNIT_TEST (test21);
  CPPUNIT_TEST (test22);
  CPPUNIT_TEST (test23);
  CPPUNIT_TEST (test24);
  CPPUNIT_TEST (test25);
  CPPUNIT_TEST (test26);
  CPPUNIT_TEST (test27);
  CPPUNIT_TEST (test28);
  CPPUNIT_TEST (test29);
  CPPUNIT_TEST (test30);
  CPPUNIT_TEST_SUITE_END ();
};

int main ()
{
  using namespace std;
  ios_base::sync_with_stdio (false);
  cout << "TestLife.c++" << endl;

  CppUnit::TextTestRunner testLife;
  testLife.addTest (TestLife::suite ());
  testLife.run ();

  cout << "Done." << endl;
  return 0;
}