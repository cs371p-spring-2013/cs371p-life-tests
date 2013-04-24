#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
//--------------
//TestLife.c++
//--------------

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#define private public
#define protected public
#define class struct

#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Life.h"
#include "Handle.h"


 //--------------------------------------
// Test ConwayCell
//---------------------------------------
struct TestConwayCell : CppUnit::TestFixture {

   // test AbstractCell() constructor
   void test_ConwayCell_constructor1() {
       ConwayCell ff;
	     CPPUNIT_ASSERT(ff.type == "Conway");	 
   }

   void test_ConwayCell_constructor2() {
        ConwayCell ff;
	      CPPUNIT_ASSERT(ff._numNeighbor == 0);	 
   }

   void test_ConwayCell_constructor3() {
        ConwayCell ee;
	      CPPUNIT_ASSERT(ee.type == "Conway");	 
   }

   // test ConwayCell clone()  
   void test_ConwayCell_clone1(){
      	ConwayCell a;
        ConwayCell* x = a.clone();
      	CPPUNIT_ASSERT(x->type == "Conway");
        delete x;
   }

   void test_ConwayCell_clone2(){
      	ConwayCell a;
        ConwayCell* x = a.clone();
      	CPPUNIT_ASSERT(x->_numNeighbor == 0);
        delete x;
	 
   }

   void test_ConwayCell_clone3(){
         ConwayCell a;
        ConwayCell* x = a.clone();
        CPPUNIT_ASSERT(x->_numNeighbor == 0);
        delete x; 
   }

   // test ConwayCell getType()
   void test_ConwayCell_getType1(){
    	ConwayCell a;
    	CPPUNIT_ASSERT(a.getType() == "Conway");
   }

   void test_ConwayCell_getType2(){
    	ConwayCell a2;
    	CPPUNIT_ASSERT(a2.getType() == "Conway");
   }
   
   void test_ConwayCell_getType3(){
    	ConwayCell a3;
    	CPPUNIT_ASSERT(a3.getType() == "Conway");
   }

   CPPUNIT_TEST_SUITE(TestConwayCell);
   CPPUNIT_TEST(test_ConwayCell_constructor1);
   CPPUNIT_TEST(test_ConwayCell_constructor2);
   CPPUNIT_TEST(test_ConwayCell_constructor3);
   CPPUNIT_TEST(test_ConwayCell_clone1);
   CPPUNIT_TEST(test_ConwayCell_clone2);
   CPPUNIT_TEST(test_ConwayCell_clone3);
   CPPUNIT_TEST(test_ConwayCell_getType1);
   CPPUNIT_TEST(test_ConwayCell_getType2);
   CPPUNIT_TEST(test_ConwayCell_getType3);
   CPPUNIT_TEST_SUITE_END();

};

 //--------------------------------------
// Test FredkinCell
//---------------------------------------
struct TestFredkinCell : CppUnit::TestFixture {

   // test FredkinCell constructor
   void test_FredkinCell_constructor1() {
    	FredkinCell gg;
      CPPUNIT_ASSERT(gg._numNeighbor == 0);
   }

   void test_FredkinCell_constructor2() {
    	FredkinCell gg;
  	  CPPUNIT_ASSERT(gg._age == 0);
   }

   void test_FredkinCell_constructor3() {
	    FredkinCell gg;
  	  CPPUNIT_ASSERT(gg.type == "Fredkin");
   }

   // test FredkinCell clone()
   void test_FredkinCell_clone1() {
  	  FredkinCell gg;
	    FredkinCell* g = gg.clone();
  	  CPPUNIT_ASSERT(g->_numNeighbor == 0);
      delete g;
   }

   void test_FredkinCell_clone2() {
     	FredkinCell gg;
      FredkinCell* g = gg.clone();
  	  CPPUNIT_ASSERT(g->_age == 0);
      delete g;

   }

   void test_FredkinCell_clone3() {
     	FredkinCell gg;
      FredkinCell* g = gg.clone();
     	CPPUNIT_ASSERT(g->type == "Fredkin");
      delete g;

   }

   // test FredkinCell getType
   void test_FredkinCell_getType1() {
  	   FredkinCell g;
	     CPPUNIT_ASSERT(g.getType() == "Fredkin");  
   }

   void test_FredkinCell_getType2() {
  	   FredkinCell gg;
	     CPPUNIT_ASSERT(gg.getType() == "Fredkin");  
   }

   void test_FredkinCell_getType3() {
  	   FredkinCell ggg;
	     CPPUNIT_ASSERT(ggg.getType() == "Fredkin");  
   }
   
   // -----------------------------------------------------------
   // test FredkinCell getAge() and incrementAge() and resetAge()
   // -----------------------------------------------------------
   void test_FredkinCell_age1() {
     	FredkinCell ggg;
    	CPPUNIT_ASSERT(ggg.getAge() == 0);
    	ggg.incrementAge();  
    	CPPUNIT_ASSERT(ggg.getAge() == 1);
    	ggg.resetAge();
      CPPUNIT_ASSERT(ggg.getAge() == 0);  

   }

   void test_FredkinCell_age2() {
     	FredkinCell ggg;
    	CPPUNIT_ASSERT(ggg.getAge() == 0);
    	ggg.incrementAge();
    	ggg.resetAge();
      CPPUNIT_ASSERT(ggg.getAge() == 0);  
   }
    
   void test_FredkinCell_age3() {
     	FredkinCell ggg;
    	ggg.incrementAge();
    	ggg.incrementAge();
    	CPPUNIT_ASSERT(ggg.getAge() == 2);  
    	ggg.resetAge();
    	CPPUNIT_ASSERT(ggg.getAge() == 0);  
   }



   CPPUNIT_TEST_SUITE(TestFredkinCell);
   CPPUNIT_TEST(test_FredkinCell_constructor1);
   CPPUNIT_TEST(test_FredkinCell_constructor2);
   CPPUNIT_TEST(test_FredkinCell_constructor3);
   CPPUNIT_TEST(test_FredkinCell_clone1);
   CPPUNIT_TEST(test_FredkinCell_clone2);
   CPPUNIT_TEST(test_FredkinCell_clone3);
   CPPUNIT_TEST(test_FredkinCell_getType1);
   CPPUNIT_TEST(test_FredkinCell_getType2);
   CPPUNIT_TEST(test_FredkinCell_getType3);
   CPPUNIT_TEST(test_FredkinCell_age1);
   CPPUNIT_TEST(test_FredkinCell_age2);
   CPPUNIT_TEST(test_FredkinCell_age3);
   CPPUNIT_TEST_SUITE_END();

};

 //--------------------------------------
// Test Cell
//---------------------------------------
struct TestCell : CppUnit::TestFixture {

  // test_Cell_getType
  void test_Cell_getType1(){
    	ConwayCell g;
    	ConwayCell* gg = g.clone();
    	Cell x(gg);
    	CPPUNIT_ASSERT(x.getType() == "Conway");
  }

  void test_Cell_getType2(){
      ConwayCell h;
      ConwayCell* gg = h.clone();
      Cell x(gg);
      CPPUNIT_ASSERT(x.getType() == "Conway");
  }

  void test_Cell_getType3(){
      FredkinCell g;
      FredkinCell* gg = g.clone();
      Cell x(gg);
      CPPUNIT_ASSERT(x.getType() == "Fredkin");
  }
   
   //------------------------------------
  // test Cell_getAlive and Cell_setAlive
  //-------------------------------------
  void test_Cell_Alive1(){
      ConwayCell g;
      ConwayCell* gg = g.clone();
      Cell h(gg);      
       CPPUNIT_ASSERT(h.getAlive() == false);
  }

  void test_Cell_Alive2(){
      ConwayCell g;
      ConwayCell* gg = g.clone();
      Cell h(gg);
      CPPUNIT_ASSERT(h.getAlive() == false);
      h.setAlive(true);
      CPPUNIT_ASSERT(h.getAlive() == true);
  }

 void test_Cell_Alive3(){
      ConwayCell g;
      ConwayCell* gg = g.clone();
      Cell h(gg);      
       CPPUNIT_ASSERT(h.getAlive() == false);
       h.setAlive(false);
       CPPUNIT_ASSERT(h.getAlive() == false);
  }
  
  //-------------------------------------------------------------
  // test Cell_getAge(), Cell_incrementAge(), and Cell resetAge()
  //--------------------------------------------------------------
  void test_Cell_Age1(){
        FredkinCell e;
        FredkinCell* kk = e.clone();
        Cell k(kk);
        CPPUNIT_ASSERT(k.getAge() == 0);
        k.incrementAge();
        k.resetAge();
        CPPUNIT_ASSERT(k.getAge() == 0);

  }

  void test_Cell_Age2(){
        FredkinCell e;
        FredkinCell* kk = e.clone();
        Cell k(kk);      
        CPPUNIT_ASSERT(k.getAge() == 0);
        k.incrementAge();
        CPPUNIT_ASSERT(k.getAge() == 1);
        k.resetAge();
        CPPUNIT_ASSERT(k.getAge() == 0);
  }
 
  void test_Cell_Age3(){
        FredkinCell e;
        FredkinCell* kk = e.clone();
        Cell k(kk);   
        CPPUNIT_ASSERT(k.getAge() == 0);
        k.incrementAge();
        k.incrementAge();
        CPPUNIT_ASSERT(k.getAge() == 2);
        k.resetAge();
        CPPUNIT_ASSERT(k.getAge() == 0);
  }

  // test Cell_mutate
  void test_Cell_Mutate1(){
      FredkinCell g;
      FredkinCell* gg = g.clone();
      Cell x(gg);      
      x.mutate();
      CPPUNIT_ASSERT(x.getType() == "Conway");
  }

 void test_Cell_Mutate2(){
      FredkinCell g;
      FredkinCell* gg = g.clone();
      Cell x(gg);      
      x.mutate();
      CPPUNIT_ASSERT(x.getAlive() == true);
  }

   void test_Cell_Mutate3(){
      FredkinCell g;
      FredkinCell* gg = g.clone();
      Cell x(gg);      
      x.mutate();
      CPPUNIT_ASSERT(x.getAlive() == true);
      CPPUNIT_ASSERT(x.getType() == "Conway");
  }
  CPPUNIT_TEST_SUITE(TestCell);
  CPPUNIT_TEST(test_Cell_getType1);
  CPPUNIT_TEST(test_Cell_getType2);
  CPPUNIT_TEST(test_Cell_getType3);
  CPPUNIT_TEST(test_Cell_Alive1);
  CPPUNIT_TEST(test_Cell_Alive2);
  CPPUNIT_TEST(test_Cell_Alive3);
  CPPUNIT_TEST(test_Cell_Age1);
  CPPUNIT_TEST(test_Cell_Age2);
  CPPUNIT_TEST(test_Cell_Age3);
  CPPUNIT_TEST(test_Cell_Mutate1);
  CPPUNIT_TEST(test_Cell_Mutate2);
  CPPUNIT_TEST(test_Cell_Mutate3);
  CPPUNIT_TEST_SUITE_END();

};

//--------------------------------------
// Test Life
//---------------------------------------
struct TestLife : CppUnit::TestFixture {

  // test Life constructor type 1
  void test_Life_ConstructorA1(){

     Life<ConwayCell> k = Life<ConwayCell>(4, 5, 10);
     CPPUNIT_ASSERT(k._row == 4);
  }

   void test_Life_ConstructorA2(){

     Life<ConwayCell> k = Life<ConwayCell>(4, 5, 10);
     CPPUNIT_ASSERT(k._col== 5);
  }

   void test_Life_ConstructorA3(){

     Life<ConwayCell> k = Life<ConwayCell>(4, 5, 10);
     CPPUNIT_ASSERT(k.Generation == 10);
  }

   // test Life constructor type 2
  void test_Life_ConstructorB1(){

     Life<Cell> k = Life<Cell>(4, 5, 10, "Cell");
     CPPUNIT_ASSERT(k._row == 4);
  }

   void test_Life_ConstructorB2(){

     Life<Cell> k = Life<Cell>(4, 5, 10, "Cell");
     CPPUNIT_ASSERT(k._col== 5);
  }

   void test_Life_ConstructorB3(){

     Life<Cell> k = Life<Cell>(4, 5, 10, "Cell");
     CPPUNIT_ASSERT(k.Generation == 10);
  }

  // test Life put
  void test_Life_Put1(){

       Life<ConwayCell> k = Life<ConwayCell>(4, 5, 10);
       k.put(1,1);
       CPPUNIT_ASSERT(k.population == 1);
  }

   void test_Life_Put2(){

       Life<ConwayCell> k = Life<ConwayCell>(4, 5, 10);
       k.put(1,1);
       k.put(1,3);
       CPPUNIT_ASSERT(k.population == 2);
  }

    void test_Life_Put3(){

       Life<ConwayCell> k = Life<ConwayCell>(4, 5, 10);
       k.put(1,1);
       k.put(1,2);
       k.put(1,3);
       CPPUNIT_ASSERT(k.population == 3);
    }

  // test Life printCell
  void test_Life_printCell1(){
     Life<Cell> k = Life<Cell>(4, 4, 0, "Cell");
      ostringstream w;
      k.printCell(w);
      CPPUNIT_ASSERT(w.str() == "----\n----\n----\n----\n\n");

  }

    void test_Life_printCell2(){
     Life<Cell> k = Life<Cell>(2, 2, 0, "Cell");
      ostringstream w;
      k.printCell(w);
      CPPUNIT_ASSERT(w.str() == "--\n--\n\n");

  }

    void test_Life_printCell3(){
      Life<Cell> k = Life<Cell>(3, 3, 0, "Cell");
      ostringstream w;
      k.printCell(w);
      CPPUNIT_ASSERT(w.str() == "---\n---\n---\n\n");

  }

  // test Life print()
  void test_Life_print1(){
      Life<ConwayCell> k = Life<ConwayCell>(3, 3, 0);
      ostringstream w;
      k.print(w);
      CPPUNIT_ASSERT(w.str() == "...\n...\n...\n\n");
  }

    void test_Life_print2(){
      Life<ConwayCell> k = Life<ConwayCell>(2, 2, 0);
      ostringstream w;
      k.print(w);
      CPPUNIT_ASSERT(w.str() == "..\n..\n\n");
  }

    void test_Life_print3(){
      Life<FredkinCell> k = Life<FredkinCell>(3, 3, 0);
      ostringstream w;
      k.print(w);
      CPPUNIT_ASSERT(w.str() == "---\n---\n---\n\n");
  }

  // test Life checkNeighbor()
  void test_Life_CheckNeighbor1(){
      Life<FredkinCell> k = Life<FredkinCell>(3, 3, 0);
      k.put(1,1);
      CPPUNIT_ASSERT(k.checkNeighbor(1,1) == 0);
  }

   void test_Life_CheckNeighbor2(){
      Life<ConwayCell> k = Life<ConwayCell>(3, 3, 0);
      k.put(1,1);
      CPPUNIT_ASSERT(k.checkNeighbor(1,1) == 0);
  }

   void test_Life_CheckNeighbor3(){
      Life<ConwayCell> k = Life<ConwayCell>(3, 3, 0);
      k.put(1,1);
      k.put(0,1);
      CPPUNIT_ASSERT(k.checkNeighbor(1,1) == 1);
  }

   // test Life run
   void test_Life_run1(){
      Life<ConwayCell> k = Life<ConwayCell>(3, 3, 0);
      k.put(1,1);
      ostringstream w;
      k.run(w);
      CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 1\n...\n.*.\n...\n\n");
   }

  void test_Life_run2(){
      Life<FredkinCell> k = Life<FredkinCell>(3, 3, 0);
      k.put(1,1);
      ostringstream w;
      k.run(w);
      CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 1\n---\n-0-\n---\n\n");
   }

    void test_Life_run3(){
      Life<ConwayCell> k = Life<ConwayCell>(3, 3, 0);
      k.put(0,0);
      ostringstream w;
      k.put(2,2);
      k.run(w);
      CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 2\n*..\n...\n..*\n\n");
   }

   // test Life runCell 
   void test_Life_runCell1(){
      Life<Cell> k = Life<Cell>(3, 3, 0, "Cell");
      ostringstream w;
      k.runCell(w);
      CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 0\n---\n---\n---\n\n");
   }

   void test_Life_runCell2(){
      Life<Cell> k = Life<Cell>(2, 3, 0, "Cell");
      ostringstream w;
      k.runCell(w);
      CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 0\n---\n---\n\n");
   }

   void test_Life_runCell3(){
     Life<Cell> k = Life<Cell>(3, 2, 0, "Cell");
      ostringstream w;
      k.runCell(w);
      CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 0\n--\n--\n--\n\n");
  }

  CPPUNIT_TEST_SUITE(TestLife);
  CPPUNIT_TEST(test_Life_ConstructorA1);
  CPPUNIT_TEST(test_Life_ConstructorA2);
  CPPUNIT_TEST(test_Life_ConstructorA3);
  CPPUNIT_TEST(test_Life_ConstructorB1);
  CPPUNIT_TEST(test_Life_ConstructorB2);
  CPPUNIT_TEST(test_Life_ConstructorB3);
  CPPUNIT_TEST(test_Life_Put1);
  CPPUNIT_TEST(test_Life_Put2);
  CPPUNIT_TEST(test_Life_Put3);
  CPPUNIT_TEST(test_Life_printCell1);
  CPPUNIT_TEST(test_Life_printCell2);
  CPPUNIT_TEST(test_Life_printCell3);
  CPPUNIT_TEST(test_Life_print1);
  CPPUNIT_TEST(test_Life_print2);
  CPPUNIT_TEST(test_Life_print3);
  CPPUNIT_TEST(test_Life_CheckNeighbor1);
  CPPUNIT_TEST(test_Life_CheckNeighbor2);
  CPPUNIT_TEST(test_Life_CheckNeighbor3);
  CPPUNIT_TEST(test_Life_run1);  
  CPPUNIT_TEST(test_Life_run2);
  CPPUNIT_TEST(test_Life_run3);
  CPPUNIT_TEST(test_Life_runCell1);
  CPPUNIT_TEST(test_Life_runCell2);
  CPPUNIT_TEST(test_Life_runCell3);
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
    tr.addTest(TestConwayCell::suite());
    tr.addTest(TestFredkinCell::suite());
    tr.addTest(TestCell::suite());
    tr.addTest(TestLife::suite());

    tr.run();
    
    cout << "Done." << endl;
    return 0;
}
