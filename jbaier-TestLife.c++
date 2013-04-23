/*
To test the program:
% ls /usr/include/cppunit/
...
TestFixture.h
...
% locate libcppunit.a
/usr/lib/libcppunit.a
% g++ -pedantic -std=c++0x -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz.c++.app -lcppunit -ldl
% valgrind TestCollatz.c++.app >& TestCollatz.c++.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream> // istringtstream, ostringstream
#include <string> // ==
#include <vector>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TextTestRunner

#define private public
//#include "AbstractCell.h"
//#include "Handle.h"
#include "Cell.h"
#include "FredkinCell.h"
#include "Life.h"

using namespace std;

// -----------
// TestLife
// -----------

struct TestLife : CppUnit::TestFixture {


// ------------
// AbstractCell
// ------------

void test_AC_finish_1 () {
    ConwayCell k(false);
    CPPUNIT_ASSERT(!k.isAlive());
    k.AbstractCell::finish();
    CPPUNIT_ASSERT(!k.isAlive());
}

void test_AC_finish_2 () {
    ConwayCell k(true);
    CPPUNIT_ASSERT(k.isAlive());
    k.AbstractCell::finish();
    CPPUNIT_ASSERT(k.isAlive());
}

void test_AC_finish_3 () {
    FredkinCell k;
    CPPUNIT_ASSERT(!k.isAlive());
    k.AbstractCell::finish();
    CPPUNIT_ASSERT(!k.isAlive());
}

void test_AC_isAlive_1 () {
    ConwayCell k;
    CPPUNIT_ASSERT(!k.AbstractCell::isAlive());
}

void test_AC_isAlive_2 () {
    ConwayCell k(true);
    CPPUNIT_ASSERT(k.AbstractCell::isAlive());
    
}

void test_AC_isAlive_3 () {
    FredkinCell k;
    CPPUNIT_ASSERT(!k.AbstractCell::isAlive());
}


// ----------
// ConwayCell
// ----------

void test_CC_action_1 () {
    ConwayCell k;
    k.ConwayCell::action(3,0);
    k.finish();
    CPPUNIT_ASSERT(k.isAlive() == true);
}

void test_CC_action_2 () {
    ConwayCell k(true);
    k.ConwayCell::action(4,0);
    k.finish();
    CPPUNIT_ASSERT(k.isAlive() == false);    
}

void test_CC_action_3 () {
    ConwayCell k;
    k.ConwayCell::action(1,0);
    k.finish();
    CPPUNIT_ASSERT(k.isAlive() == false);
}

void test_CC_printCell_1 () {
    std::ostringstream w;
    ConwayCell k;
    k.printCell(w);
    CPPUNIT_ASSERT(w.str() == ".");
}

void test_CC_printCell_2 () {
    std::ostringstream w;
    ConwayCell k(true);
    k.printCell(w);
    CPPUNIT_ASSERT(w.str() == "*");
}

void test_CC_printCell_3 () {
    std::ostringstream w;
    ConwayCell k(true);
    k.action(4, 0);
    k.finish();
    k.printCell(w);
    CPPUNIT_ASSERT(w.str() == ".");
}

void test_CC_evolve_1 () {
    ConwayCell k;
    CPPUNIT_ASSERT(!k.evolve());
}

void test_CC_evolve_2 () {
    ConwayCell k(true);
    CPPUNIT_ASSERT(!k.evolve());
}

void test_CC_evolve_3 () {
    ConwayCell k(false);
    k.action(3,0);
    CPPUNIT_ASSERT(!k.evolve());
}

void test_CC_clone_1 () {
    ConwayCell k;
    ConwayCell* j = k.ConwayCell::clone();
    CPPUNIT_ASSERT(j->isAlive() == k.isAlive());
    delete j;
}

void test_CC_clone_2 () {
    ConwayCell k(true);
    ConwayCell* j = k.ConwayCell::clone();
    CPPUNIT_ASSERT(j->isAlive() == k.isAlive());
    delete j;
}

void test_CC_clone_3 () {
    ConwayCell k(true);
    ConwayCell* j = k.ConwayCell::clone();
    CPPUNIT_ASSERT(k.isAlive());
    delete j;
}


// -----------
// FredkinCell
// -----------

void test_FC_action_1 () {
    FredkinCell k;
    CPPUNIT_ASSERT(!k.isAlive());
    k.action(0,1);
    k.finish();
    CPPUNIT_ASSERT(k.isAlive());
}

void test_FC_action_2 () {
    FredkinCell k(true);
    CPPUNIT_ASSERT(k.isAlive());
    k.action(0,4);
    k.finish();
    CPPUNIT_ASSERT(!k.isAlive());
}

void test_FC_action_3 () {
    FredkinCell k(true);
    CPPUNIT_ASSERT(k.isAlive());
    k.action(0, 3);
    k.finish();
    CPPUNIT_ASSERT(!k.evolve());
    k.action(0,3);
    k.finish();
    CPPUNIT_ASSERT(k.evolve());
}

void test_FC_printCell_1 () {
    std::ostringstream w;
    FredkinCell k;
    k.printCell(w);
    CPPUNIT_ASSERT(w.str() == "-");
}

void test_FC_printCell_2 () {
    std::ostringstream w;
    FredkinCell k(true);
    k.action(0, 1);
    k.finish();
    k.printCell(w);
    CPPUNIT_ASSERT(w.str() == "1");
}

void test_FC_printCell_3 () {
    std::ostringstream w;
    FredkinCell k(true);
    for(int i = 0; i < 10; ++i){
       k.action(0, 1);
       k.finish();}
    k.printCell(w);
    CPPUNIT_ASSERT(w.str() == "+");
}

void test_FC_evolve_1 () {
    FredkinCell k;
    CPPUNIT_ASSERT(!k.evolve());
}

void test_FC_evolve_2 () {
    FredkinCell k(true);
    CPPUNIT_ASSERT(!k.evolve());
}

void test_FC_evolve_3 () {
    FredkinCell k(true);
    k.action(0,3);
    k.finish();
    k.action(0,3);
    k.finish();
    CPPUNIT_ASSERT(k.evolve());
}

void test_FC_clone_1 () {
    FredkinCell k;
    FredkinCell* j = k.FredkinCell::clone();
    CPPUNIT_ASSERT(j->isAlive() == k.isAlive());
    delete j;
}

void test_FC_clone_2 () {
    std::ostringstream w;
    std::ostringstream q;
    FredkinCell k(true);
    FredkinCell* j = k.FredkinCell::clone();
    j->printCell(w);
    k.printCell(q);
    CPPUNIT_ASSERT(w.str() == q.str());
    delete j;
}

void test_FC_clone_3 () {
    std::ostringstream w;
    std::ostringstream q;
    FredkinCell k(true);
    FredkinCell* j = k.FredkinCell::clone();
    k.action(0,3);
    k.finish();
    j->printCell(w);
    k.printCell(q);
    CPPUNIT_ASSERT(w.str() != q.str());
    delete j;
}

// ----
// Cell
// ----
void test_C_printCell_1 () {
    std::ostringstream w;
    ConwayCell k;
    Cell b(k.clone());
    b.printCell(w);
    CPPUNIT_ASSERT(w.str() == ".");
}

void test_C_printCell_2 () {
    std::ostringstream w;
    FredkinCell k;
    Cell b(k.clone());
    b.printCell(w);
    CPPUNIT_ASSERT(w.str() == "-");
}

void test_C_printCell_3 () {
    std::ostringstream w;
    FredkinCell k(true);
    for(int i = 0; i < 10; ++i){
       k.action(0, 1);
       k.finish();}
    Cell b(k.clone());
    b.printCell(w);
    CPPUNIT_ASSERT(w.str() == "+");
}

void test_C_finish_1 () {
    ConwayCell k(false);
    CPPUNIT_ASSERT(!k.isAlive());
    Cell b(k.clone());
    b.finish();
    CPPUNIT_ASSERT(!b.isAlive());
}

void test_C_finish_2 () {
    FredkinCell k(true);
    CPPUNIT_ASSERT(k.isAlive());
    Cell b(k.clone());
    b.finish();
    CPPUNIT_ASSERT(b.isAlive());
}

void test_C_finish_3 () {
    FredkinCell k;
    CPPUNIT_ASSERT(!k.isAlive());
    Cell b(k.clone());
    b.finish();
    CPPUNIT_ASSERT(!b.isAlive());
}

void test_C_isAlive_1 () {
    ConwayCell k;
    Cell b(k.clone());
    CPPUNIT_ASSERT(!b.isAlive());
}

void test_C_isAlive_2 () {
    FredkinCell k(true);
    Cell b(k.clone());
    CPPUNIT_ASSERT(b.isAlive());
    k.action(0,4);
    k.finish();
    Cell j(k.clone());
    CPPUNIT_ASSERT(!j.isAlive());
}

void test_C_isAlive_3 () {
    FredkinCell k;
    Cell b(k.clone());
    CPPUNIT_ASSERT(!b.isAlive());
    k.action(0,3);
    k.finish();
    Cell j(k.clone());
    CPPUNIT_ASSERT(j.isAlive());
}

void test_C_action_1 () {
    ConwayCell k;
    Cell b(k.clone());
    b.action(3,0);
    b.finish();
    CPPUNIT_ASSERT(b.isAlive() == true);
}

void test_C_action_2 () {
    FredkinCell k(true);
    Cell b(k.clone());
    b.action(0,4);
    b.finish();
    CPPUNIT_ASSERT(b.isAlive() == false);    
}

void test_C_action_3 () {
    std::ostringstream w;
    std::ostringstream q;
    FredkinCell k(true);
    Cell b(k.clone());
    b.action(0,3);
    b.finish();
    b.printCell(q);
    CPPUNIT_ASSERT(q.str() == "1");
    b.action(0,3);
    b.finish();
    b.printCell(w);
    CPPUNIT_ASSERT(w.str() == "*");
}


// ----
// Life
// ----

void test_conwayAdj_1 () {
    Life<ConwayCell, 2, 2> g;
    CPPUNIT_ASSERT(g.conwayAdj(0,0) == 0);
}

void test_conwayAdj_2 () {
    Life<ConwayCell, 2, 2> g;
    ConwayCell a(true);
    g.addCell(0,0,a);
    g.addCell(0,1,a);
    g.addCell(1,0,a);
    CPPUNIT_ASSERT(g.conwayAdj(0,0) == 2);
    g.addCell(1,1,a);
    CPPUNIT_ASSERT(g.conwayAdj(0,0) == 3);
}

void test_conwayAdj_3 () {
    Life<ConwayCell, 3, 3> g;
    ConwayCell a(true);
    FredkinCell b(true);
    g.addCell(0,0,a);
    g.addCell(0,1,a);
    g.addCell(1,0,a);
    CPPUNIT_ASSERT(g.conwayAdj(0,0) == 2);
    g.addCell(1,1,a);
    CPPUNIT_ASSERT(g.conwayAdj(0,0) == 3);
    g.addCell(1,2,a);
    g.addCell(0,2,a);
    CPPUNIT_ASSERT(g.conwayAdj(1,1) == 5);
}

void test_fredkinAdj_1 () {
    Life<FredkinCell, 2, 2> g;
    CPPUNIT_ASSERT(g.fredkinAdj(0,0) == 0);
}

void test_fredkinAdj_2 () {
    Life<FredkinCell, 2, 2> g;
    FredkinCell a(true);
    g.addCell(0,0,a);
    g.addCell(0,1,a);
    g.addCell(1,0,a);
    CPPUNIT_ASSERT(g.fredkinAdj(0,0) == 2);
    g.addCell(1,1,a);
    CPPUNIT_ASSERT(g.fredkinAdj(0,0) == 2);
}

void test_fredkinAdj_3 () {
    Life<Cell, 3, 3> g;
    Cell a(new FredkinCell(true));
    Cell d(new FredkinCell(false));
    Cell b(new ConwayCell(true));
    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
          g.addCell(i,j,d);
        }
    }
    g.addCell(0,0,a);
    g.addCell(0,1,a);
    g.addCell(1,0,a);
    CPPUNIT_ASSERT(g.fredkinAdj(0,0) == 2);
    g.addCell(1,1,a);
    CPPUNIT_ASSERT(g.fredkinAdj(0,0) == 2);
    g.addCell(1,2,b);
    g.addCell(0,2,a);
    CPPUNIT_ASSERT(g.fredkinAdj(1,1) == 3);
}

void test_outOfBounds_1 () {
    Life<ConwayCell, 2, 2> g;
    CPPUNIT_ASSERT(!g.outOfBounds(0,0));
}

void test_outOfBounds_2 () {
    Life<ConwayCell, 2, 2> g;
    CPPUNIT_ASSERT(g.outOfBounds(3,3));
}

void test_outOfBounds_3 () {
    Life<ConwayCell, 2, 2> g;
    CPPUNIT_ASSERT(g.outOfBounds(-1,0));
}

void test_addCell_1 () {
    Life<ConwayCell, 2, 2> g;
    ConwayCell a(true);
    g.addCell(0,0,a);
    CPPUNIT_ASSERT(g._grid[0][0].isAlive());
    CPPUNIT_ASSERT(!(g._grid[1][1].isAlive()));
}

void test_addCell_2 () {
    Life<FredkinCell, 2, 2> g;
    FredkinCell a(true);
    g.addCell(0,0,a);
    CPPUNIT_ASSERT(g._grid[0][0].isAlive());
    CPPUNIT_ASSERT(!(g._grid[1][1].isAlive()));
}

void test_addCell_3 () {
    Life<Cell, 2, 2> g;
    Cell a(new ConwayCell(true));
    Cell d(new FredkinCell(false));
      for(int i=0; i<2; ++i) {
        for(int j=0; j<2; ++j) {
          g.addCell(i,j,d);
        }
      }
    g.addCell(0,0,a);
    CPPUNIT_ASSERT(g._grid[0][0].isAlive());
    CPPUNIT_ASSERT(!(g._grid[1][1].isAlive()));
}

void test_oneTurn_1 () {
    Life<ConwayCell, 2,2> g;
    CPPUNIT_ASSERT(g._generation == 0);
    g.oneTurn();
    CPPUNIT_ASSERT(g._generation == 1);
}

void test_oneTurn_2 () {
    Life<ConwayCell, 3,3> g;
    CPPUNIT_ASSERT(g._population == 0);
    ConwayCell a(true);
    g.addCell(0,1,a);
    g.addCell(1,1,a);
    g.addCell(2,1,a);
    g.addCell(2,2,a);
    CPPUNIT_ASSERT(!(g._grid[1][0].isAlive()));
    CPPUNIT_ASSERT(g._population == 4);
    g.oneTurn();
    CPPUNIT_ASSERT((g._grid[1][0].isAlive()));
    CPPUNIT_ASSERT(g._population == 4);
}

void test_oneTurn_3 () {
    Life<Cell, 5, 5> g;
      Cell a(new FredkinCell(true));
      Cell d(new FredkinCell(false));
      for(int i=0; i<5; ++i) {
        for(int j=0; j<5; ++j) {
          g.addCell(i,j,d);
        }
      }
      g.addCell(0,0,a);
      g.addCell(0,1,a);
      g.addCell(1,0,a);
      g.addCell(1,1,a);
      g.addCell(4,4,a);
      g.addCell(4,3,a);
      g.addCell(3,4,a);
      g.addCell(3,3,a);
      g.addCell(4,0,a);
      g.addCell(3,0,a);
      g.addCell(4,1,a);
      g.addCell(3,1,a);
      g.addCell(0,4,a);
      g.addCell(0,3,a);
      g.addCell(1,4,a);
      g.addCell(1,3,a);
      CPPUNIT_ASSERT(g._population == 16);
      g.oneTurn();
      CPPUNIT_ASSERT(g._population == 0);
}

void test_printGrid_1 () {
    std::ostringstream w;
    std::ostringstream q;
    Life<ConwayCell, 2,2> g;
    ConwayCell a(true);
    g.printGrid(w);
    CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 0.\n..\n..\n\n");
    g.addCell(0,0,a);
    g.printGrid(q);
    CPPUNIT_ASSERT(q.str() == "Generation = 0, Population = 1.\n*.\n..\n\n");
}

void test_printGrid_2 () {
    std::ostringstream w;
    std::ostringstream q;
    Life<FredkinCell, 2,2> g;
    FredkinCell a(true);
    g.printGrid(w);
    CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 0.\n--\n--\n\n");
    g.addCell(0,0,a);
   // g.printGrid(cout);
    g.printGrid(q);
    
    CPPUNIT_ASSERT(q.str() == "Generation = 0, Population = 1.\n0-\n--\n\n");
}

void test_printGrid_3 () {
    std::ostringstream w;
    Life<Cell, 2, 2> g;
    Cell k(new ConwayCell(true));
    Cell a(new FredkinCell(true));
    Cell d(new FredkinCell(false));
    for(int i= 0; i<2; ++i){
	for(int j=0; j<2; ++j){
	   g.addCell(i,j,d);}
    }
    g.addCell(0,0,a);
    g.addCell(0,1,k);
    g.addCell(1,0,k);
    g.printGrid(w);
    CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 3.\n0*\n*-\n\n");
}
    // -----
    // suite
    // -----


    CPPUNIT_TEST_SUITE(TestLife);

    CPPUNIT_TEST(test_AC_finish_1);
    CPPUNIT_TEST(test_AC_finish_2);    
    CPPUNIT_TEST(test_AC_finish_3);    
    CPPUNIT_TEST(test_AC_isAlive_1);    
    CPPUNIT_TEST(test_AC_isAlive_2);    
    CPPUNIT_TEST(test_AC_isAlive_3);    
    CPPUNIT_TEST(test_CC_action_1);
    CPPUNIT_TEST(test_CC_action_2);
    CPPUNIT_TEST(test_CC_action_3);
    CPPUNIT_TEST(test_CC_printCell_1);
    CPPUNIT_TEST(test_CC_printCell_2);
    CPPUNIT_TEST(test_CC_printCell_3);
    CPPUNIT_TEST(test_CC_evolve_1);
    CPPUNIT_TEST(test_CC_evolve_2);
    CPPUNIT_TEST(test_CC_evolve_3);
    CPPUNIT_TEST(test_CC_clone_1);
    CPPUNIT_TEST(test_CC_clone_2);
    CPPUNIT_TEST(test_CC_clone_3);
    CPPUNIT_TEST(test_FC_action_1);
    CPPUNIT_TEST(test_FC_action_2);
    CPPUNIT_TEST(test_FC_action_3);
    CPPUNIT_TEST(test_FC_printCell_1);
    CPPUNIT_TEST(test_FC_printCell_2);
    CPPUNIT_TEST(test_FC_printCell_3);
    CPPUNIT_TEST(test_FC_evolve_1);
    CPPUNIT_TEST(test_FC_evolve_2);
    CPPUNIT_TEST(test_FC_evolve_3);
    CPPUNIT_TEST(test_FC_clone_1);
    CPPUNIT_TEST(test_FC_clone_2);
    CPPUNIT_TEST(test_FC_clone_3);
    CPPUNIT_TEST(test_C_printCell_1);
    CPPUNIT_TEST(test_C_printCell_2);
    CPPUNIT_TEST(test_C_printCell_3);
    CPPUNIT_TEST(test_C_finish_1);
    CPPUNIT_TEST(test_C_finish_2);    
    CPPUNIT_TEST(test_C_finish_3);
    CPPUNIT_TEST(test_C_isAlive_1);    
    CPPUNIT_TEST(test_C_isAlive_2);    
    CPPUNIT_TEST(test_C_isAlive_3); 
    CPPUNIT_TEST(test_C_action_1);
    CPPUNIT_TEST(test_C_action_2);
    CPPUNIT_TEST(test_C_action_3);
    CPPUNIT_TEST(test_conwayAdj_1);
    CPPUNIT_TEST(test_conwayAdj_2);
    CPPUNIT_TEST(test_conwayAdj_3);
    CPPUNIT_TEST(test_fredkinAdj_1);
    CPPUNIT_TEST(test_fredkinAdj_2);
    CPPUNIT_TEST(test_fredkinAdj_3);
    CPPUNIT_TEST(test_outOfBounds_1);
    CPPUNIT_TEST(test_outOfBounds_2);
    CPPUNIT_TEST(test_outOfBounds_3);
    CPPUNIT_TEST(test_addCell_1);
    CPPUNIT_TEST(test_addCell_2);
    CPPUNIT_TEST(test_addCell_3);
    CPPUNIT_TEST(test_oneTurn_1);
    CPPUNIT_TEST(test_oneTurn_2);
    CPPUNIT_TEST(test_oneTurn_3);
    CPPUNIT_TEST(test_printGrid_1);
    CPPUNIT_TEST(test_printGrid_2);
    CPPUNIT_TEST(test_printGrid_3);
    CPPUNIT_TEST_SUITE_END();
};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestLife.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestLife::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}

