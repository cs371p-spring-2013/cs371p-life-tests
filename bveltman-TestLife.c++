#include <iostream>
#include <sstream>
#include <string>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#define private public
#define protected public
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Handle.h"
#include "Cell.h"
#include "Life.h"

struct TestLife : CppUnit::TestFixture {

  //-------------------
    //test ConwayCell
    //-------------------
    
    //constructor tests
    void test_conway_constructor_1 (){
        ConwayCell c;
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
    }
    
     void test_conway_constructor_2 (){
        ConwayCell c(ALIVE);
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
    }
    
      void test_conway_constructor_3 (){
        ConwayCell c(DEAD);
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == DEAD);
    }
    
    //evolve tests
    void test_conway_evolve_1 (){
        ConwayCell c;
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        char around [] = {ALIVE, ALIVE, ALIVE, DEAD, DEAD, DEAD, DEAD, DEAD};
        char result = c.evolve(around);
        CPPUNIT_ASSERT (result == ALIVE);
    }
    
    void test_conway_evolve_2 (){
        ConwayCell c;
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        char around [] = {ALIVE, ALIVE, ALIVE, ALIVE, DEAD, DEAD, DEAD, DEAD};
        char result = c.evolve(around);
        CPPUNIT_ASSERT (result == DEAD);
    }
    
      void test_conway_evolve_3 (){
        ConwayCell c(DEAD);
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == DEAD);
        char around [] = {ALIVE, ALIVE, ALIVE, ALIVE, DEAD, DEAD, DEAD, DEAD};
        char result = c.evolve(around);
        CPPUNIT_ASSERT (result == DEAD);
    }
    
     void test_conway_evolve_4 (){
        ConwayCell c(DEAD);
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == DEAD);
        char around [] = {ALIVE, ALIVE, ALIVE, DEAD, DEAD, DEAD, DEAD, DEAD};
        char result = c.evolve(around);
        CPPUNIT_ASSERT (result == ALIVE);
    }
    
    //my type and myState tests
     void test_conway_typeAndState_1 (){
        ConwayCell c(DEAD);
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == DEAD);
    }
    
     void test_conway_typeAndState_2 (){
        ConwayCell c(ALIVE);
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
    }
    
     void test_conway_typeAndState_3 (){
        ConwayCell c;
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
    }
    
    //clone tests
    void test_conway_clone_1 (){
        ConwayCell c;
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        AbstractCell* d = c.clone();
        CPPUNIT_ASSERT (d->myState() == ALIVE);
        CPPUNIT_ASSERT (((ConwayCell*)d)->myType() == CONWAY);
    }
    
    void test_conway_clone_2 (){
        ConwayCell c (DEAD);
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == DEAD);
        AbstractCell* d = c.clone();
        CPPUNIT_ASSERT (d->myState() == DEAD);
        CPPUNIT_ASSERT (((ConwayCell*)d)->myType() == CONWAY);
    }
    
     void test_conway_clone_3 (){
        ConwayCell c (ALIVE);
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        AbstractCell* d = c.clone();
        CPPUNIT_ASSERT (d->myState() == ALIVE);
        CPPUNIT_ASSERT (((ConwayCell*)d)->myType() == CONWAY);
    }

    //change state tests
    void test_conway_changeState_1 (){
        ConwayCell c;
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        c.changeState();
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == DEAD);
    }
    
    void test_conway_changeState_2 (){
        ConwayCell c (ALIVE);
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        c.changeState();
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == DEAD);
    }
    
     void test_conway_changeState_3 (){
        ConwayCell c (DEAD);
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == DEAD);
        c.changeState();
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
    }
    
    //test myGen
    void test_conway_myGen_1 (){
        ConwayCell c;
        CPPUNIT_ASSERT (c.myGen() == 0);
    }
    
    void test_conway_myGen_2 (){
        ConwayCell c (DEAD);
        CPPUNIT_ASSERT (c.myGen() == 0);
    }
    
    void test_conway_myGen_3 (){
        ConwayCell c (DEAD);
        CPPUNIT_ASSERT (c.myGen() == 0);
    }
    
     //test isRegCell
    void test_conway_regCell_1 (){
        ConwayCell c (DEAD);
        CPPUNIT_ASSERT (!c.isRegCell());
    }
    
    void test_conway_regCell_2 (){
        ConwayCell c (ALIVE);
        CPPUNIT_ASSERT (!c.isRegCell());
    }
    
     void test_conway_regCell_3 (){
        ConwayCell c;
        CPPUNIT_ASSERT (!c.isRegCell());
    }
    
    //------------------
    //test FredkinCell
    //-----------------
    
    //constructor tests
    void test_fredkin_constructor_1 (){
        FredkinCell c;
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        CPPUNIT_ASSERT (c.myGen() == 0);
    }
    
    void test_fredkin_constructor_2 (){
        FredkinCell c(ALIVE);
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        CPPUNIT_ASSERT (c.myGen() == 0);
    }
    
    void test_fredkin_constructor_3 (){
        FredkinCell c(DEAD);
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == DEAD);
        CPPUNIT_ASSERT (c.myGen() == 0);
    }
    
    //evolve and incGen tests
    void test_fredkin_evolveAndIncGen_1 (){
        FredkinCell c;
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        CPPUNIT_ASSERT (c.myGen() == 0);
        char around [] = {ALIVE, ALIVE, ALIVE, DEAD, DEAD, DEAD, DEAD, DEAD};
        char result = c.evolve(around);
        CPPUNIT_ASSERT (result == ALIVE);
        CPPUNIT_ASSERT (c.myGen() == 1);
    }
    
    void test_fredkin_evolveAndIncGen_2 (){
        FredkinCell c;
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        CPPUNIT_ASSERT (c.myGen() == 0);
        char around [] = {ALIVE, ALIVE, ALIVE, ALIVE, DEAD, DEAD, DEAD, DEAD};
        char result = c.evolve(around);
        CPPUNIT_ASSERT (result == DEAD);
        CPPUNIT_ASSERT (c.myGen() == 0);
    }
    
      void test_fredkin_evolveAndIncGen_3 (){
        FredkinCell c(DEAD);
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == DEAD);
        CPPUNIT_ASSERT (c.myGen() == 0);
        char around [] = {ALIVE, ALIVE, ALIVE, ALIVE, DEAD, DEAD, DEAD, DEAD};
        char result = c.evolve(around);
        CPPUNIT_ASSERT (result == DEAD);
        CPPUNIT_ASSERT (c.myGen() == 0);
    }
    
     void test_fredkin_evolveAndIncGen_4(){
        FredkinCell c(DEAD);
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == DEAD);
        CPPUNIT_ASSERT (c.myGen() == 0);
        char around [] = {ALIVE, ALIVE, ALIVE, DEAD, DEAD, DEAD, DEAD, DEAD};
        char result = c.evolve(around);
        CPPUNIT_ASSERT (result == ALIVE);
        CPPUNIT_ASSERT (c.myGen() == 0);
    }
    
    //mytype, myState and myGen tests
     void test_fredkin_myTypeAndMyStateAndMyGen_1(){
        FredkinCell c(DEAD);
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == DEAD);
        CPPUNIT_ASSERT (c.myGen() == 0);
    }
    
     void test_fredkin_myTypeAndMyStateAndMyGen_2(){
        FredkinCell c(ALIVE);
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        CPPUNIT_ASSERT (c.myGen() == 0);
    }
    
     void test_fredkin_myTypeAndMyStateAndMyGen_3(){
        FredkinCell c;
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        CPPUNIT_ASSERT (c.myGen() == 0);
    }
    
    //clone tests
	void test_fredkin_clone_1() {
        FredkinCell c;
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        AbstractCell* d = c.clone();
        CPPUNIT_ASSERT (d->myState() == ALIVE);
        CPPUNIT_ASSERT (((FredkinCell*)d)->myType() == FREDKIN);
    }
    
    void test_fredkin_clone_2(){
        FredkinCell c (DEAD);
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == DEAD);
        AbstractCell* d = c.clone();
        CPPUNIT_ASSERT (d->myState() == DEAD);
        CPPUNIT_ASSERT (((FredkinCell*)d)->myType() == FREDKIN);
    }
    
     void test_fredkin_clone_3(){
        FredkinCell c (ALIVE);
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        AbstractCell* d = c.clone();
        CPPUNIT_ASSERT (d->myState() == ALIVE);
        CPPUNIT_ASSERT (((FredkinCell*)d)->myType() == FREDKIN);
    }

    //change state tests
    void test_fredkin_changeState_1(){
        FredkinCell c;
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        c.changeState();
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == DEAD);
    }
    
   void test_fredkin_changeState_2() {
        FredkinCell c (ALIVE);
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        c.changeState();
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == DEAD);
    }
    
     void test_fredkin_changeState_3(){
        FredkinCell c (DEAD);
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == DEAD);
        c.changeState();
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
    }
    
    //test isRegCell
    void test_fredkin_regCell_1(){
        FredkinCell c (DEAD);
        CPPUNIT_ASSERT (!c.isRegCell());
    }
    
    void test_fredkin_regCell_2(){
        FredkinCell c (ALIVE);
        CPPUNIT_ASSERT (!c.isRegCell());
    }
    
     void test_fredkin_regCell_3(){
        FredkinCell c;
        CPPUNIT_ASSERT (!c.isRegCell());
    }
    
    //------------
    //Handle tests
    //-----------
    
    //handle constructor and get
    void test_handle_constructor_1 (){
        Handle<AbstractCell> h (new ConwayCell());
        AbstractCell* p = h.get();
        if (ConwayCell* c = dynamic_cast<ConwayCell*>(p)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
         }
    }
    
    void test_handle_constructor_2 (){
        Handle<AbstractCell> h (new FredkinCell());
        AbstractCell* p = h.get();
        if (FredkinCell* c = dynamic_cast<FredkinCell*>(p)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
         }
    }
    
     void test_handle_constructor_3 (){
        const Handle<AbstractCell> h (new FredkinCell());
        const AbstractCell* p = h.get();
        if (const FredkinCell* c = dynamic_cast<const FredkinCell*>(p)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
         }
    }
    
      void test_handle_constructor_4 (){
        const Handle<AbstractCell> h (new ConwayCell());
        const AbstractCell* p = h.get();
        if (const ConwayCell* c = dynamic_cast<const ConwayCell*>(p)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
         }
    }
    
    //Handle copy constructor
     void test_handle_copyconstructor_1 (){
        Handle<AbstractCell> h (new ConwayCell());
        Handle<AbstractCell> h2 (h);
        AbstractCell* p = h2.get();
        if (ConwayCell* c = dynamic_cast<ConwayCell*>(p)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
         }  
    }
    
    void test_handle_copyconstructor_2 (){
        Handle<AbstractCell> h (new FredkinCell());
        Handle<AbstractCell> h2 (h);
        AbstractCell* p = h2.get();
        if (FredkinCell* c = dynamic_cast<FredkinCell*>(p)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
         }  
    }
    
     void test_handle_copyconstructor_3 (){
        Handle<AbstractCell> h (0);
        Handle<AbstractCell> h2 (h);
        CPPUNIT_ASSERT (h2._p == 0);
    }
    
    //test handle assignment operator 
    void test_handle_assgnconstructor_1 (){
        Handle<AbstractCell> h (new ConwayCell());
        CPPUNIT_ASSERT (h.get()->myState() == ALIVE);
        AbstractCell* p = h.get();
        if (ConwayCell* c = dynamic_cast<ConwayCell*>(p)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
        }
        Handle<AbstractCell> h2 (new FredkinCell());
        CPPUNIT_ASSERT (h2.get()->myState() == ALIVE);
        AbstractCell* p2 = h2.get();
        if (FredkinCell* c = dynamic_cast<FredkinCell*>(p2)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
        }
        h2 = h;
        p2 = h2.get();
        if (ConwayCell* c = dynamic_cast<ConwayCell*>(p)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
        }
    }
    
    void test_handle_assgnconstructor_2 (){
        Handle<AbstractCell> h (new ConwayCell(DEAD));
        CPPUNIT_ASSERT (h.get()->myState() == DEAD);
        AbstractCell* p = h.get();
        if (ConwayCell* c = dynamic_cast<ConwayCell*>(p)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
        }
        Handle<AbstractCell> h2 (new FredkinCell());
        CPPUNIT_ASSERT (h2.get()->myState() == ALIVE);
        AbstractCell* p2 = h2.get();
        if (FredkinCell* c = dynamic_cast<FredkinCell*>(p2)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
        }
        h2 = h;
        p2 = h2.get();
        if (ConwayCell* c = dynamic_cast<ConwayCell*>(p)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
        }
    }
    
    void test_handle_assgnconstructor_3 (){
        Handle<AbstractCell> h (new FredkinCell(DEAD));
        CPPUNIT_ASSERT (h.get()->myState() == DEAD);
        AbstractCell* p = h.get();
        if (FredkinCell* c = dynamic_cast<FredkinCell*>(p)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
        }
        Handle<AbstractCell> h2 (new ConwayCell());
        CPPUNIT_ASSERT (h2.get()->myState() == ALIVE);
        AbstractCell* p2 = h2.get();
        if (ConwayCell* c = dynamic_cast<ConwayCell*>(p2)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
        }
        h2 = h;
        p2 = h2.get();
        if (FredkinCell* c = dynamic_cast<FredkinCell*>(p)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
        }
    }
    
    //test swap method 
    void test_handle_swap_1 (){
         Handle<AbstractCell> h (new FredkinCell(DEAD));
        CPPUNIT_ASSERT (h.get()->myState() == DEAD);
        AbstractCell* p = h.get();
        if (FredkinCell* c = dynamic_cast<FredkinCell*>(p)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
        }
        Handle<AbstractCell> h2 (new ConwayCell());
        CPPUNIT_ASSERT (h2.get()->myState() == ALIVE);
        AbstractCell* p2 = h2.get();
        if (ConwayCell* c = dynamic_cast<ConwayCell*>(p2)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
        }
        h2.swap(h);
        p2 = h2.get();
        if (FredkinCell* c = dynamic_cast<FredkinCell*>(p)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
        }
        p = h.get();
        if (ConwayCell* c = dynamic_cast<ConwayCell*>(p)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
        }
    }
    
    void test_handle_swap_2 (){
         Handle<AbstractCell> h (new FredkinCell(ALIVE));
        CPPUNIT_ASSERT (h.get()->myState() == ALIVE);
        AbstractCell* p = h.get();
        if (FredkinCell* c = dynamic_cast<FredkinCell*>(p)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
        }
        Handle<AbstractCell> h2 (new ConwayCell());
        CPPUNIT_ASSERT (h2.get()->myState() == ALIVE);
        AbstractCell* p2 = h2.get();
        if (ConwayCell* c = dynamic_cast<ConwayCell*>(p2)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
        }
        h2.swap(h);
        p2 = h2.get();
        if (FredkinCell* c = dynamic_cast<FredkinCell*>(p)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
        }
        p = h.get();
        if (ConwayCell* c = dynamic_cast<ConwayCell*>(p)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
        }
    }
    
     void test_handle_swap_3 (){
         Handle<AbstractCell> h (new ConwayCell(ALIVE));
        CPPUNIT_ASSERT (h.get()->myState() == ALIVE);
        AbstractCell* p = h.get();
        if (ConwayCell* c = dynamic_cast<ConwayCell*>(p)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
        }
        Handle<AbstractCell> h2 (new FredkinCell());
        CPPUNIT_ASSERT (h2.get()->myState() == ALIVE);
        AbstractCell* p2 = h2.get();
        if (FredkinCell* c = dynamic_cast<FredkinCell*>(p2)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
        }
        h2.swap(h);
        p2 = h2.get();
        if (ConwayCell* c = dynamic_cast<ConwayCell*>(p)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
        }
        p = h.get();
        if (FredkinCell* c = dynamic_cast<FredkinCell*>(p)){
            CPPUNIT_ASSERT(true);
        } else{
            CPPUNIT_ASSERT(false);
        }
    }
    
    //------------------
    //tests for Cell.h
    //------------------
    
    //test cell constructor
     void test_cell_constructor_1 (){
        Cell c;
        CPPUNIT_ASSERT (true);
    }
    
    void test_cell_constructor_2 (){
        Cell c (new ConwayCell());
        CPPUNIT_ASSERT (true);
    }
    
     void test_cell_constructor_3 (){
        Cell c (new FredkinCell());
        CPPUNIT_ASSERT (true);
    }
    
    //test evolve
    void test_cell_evolve_1 (){
        Cell c (new FredkinCell());
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        CPPUNIT_ASSERT (c.myGen() == 0);
        char around [] = {ALIVE, ALIVE, ALIVE, DEAD, DEAD, DEAD, DEAD, DEAD};
        char result = c.evolve(around);
        CPPUNIT_ASSERT (result == ALIVE);
        CPPUNIT_ASSERT (c.myGen() == 1);   
    }
    
    void test_cell_evolve_2 (){
        Cell c (new ConwayCell());
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        CPPUNIT_ASSERT (c.myGen() == 0);
        char around [] = {ALIVE, ALIVE, ALIVE, ALIVE, DEAD, DEAD, DEAD, DEAD};
        char result = c.evolve(around);
        CPPUNIT_ASSERT (result == DEAD);
        CPPUNIT_ASSERT (c.myGen() == 0);   
    }
    
     void test_cell_evolve_3 (){
        Cell c (new ConwayCell());
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        CPPUNIT_ASSERT (c.myGen() == 0);
        char around [] = {ALIVE, ALIVE, ALIVE, DEAD, DEAD, DEAD, DEAD, DEAD};
        char result = c.evolve(around);
        CPPUNIT_ASSERT (result == ALIVE);
        CPPUNIT_ASSERT (c.myGen() == 0);   
    }
    
    //test changeState
    void test_cell_changeState_1 (){
        Cell c (new ConwayCell());
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        c.changeState();
        CPPUNIT_ASSERT (c.myState() == DEAD);
    }
    
    void test_cell_changeState_2 (){
        Cell c (new FredkinCell());
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        c.changeState();
        CPPUNIT_ASSERT (c.myState() == DEAD);
    }
    
    void test_cell_changeState_3 (){
        Cell c (new FredkinCell(DEAD));
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == DEAD);
        c.changeState();
        CPPUNIT_ASSERT (c.myState() == ALIVE);
    }
    
    //test myType
    void test_cell_myType_1 (){
        Cell c (new FredkinCell(DEAD));
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
    }
    
    void test_cell_myType_2 (){
        Cell c (new ConwayCell(DEAD));
        CPPUNIT_ASSERT(c.myType() == CONWAY);
    }

    void test_cell_myType_3 (){
        Cell c;
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
    }
    
    //myState
    void test_cell_myState_1 (){
        Cell c (new FredkinCell(DEAD));
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == DEAD);
    }
    
    void test_cell_myState_2 (){
        Cell c (new FredkinCell());
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
    }
    
     void test_cell_myState_3 (){
        Cell c (new ConwayCell());
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
    }
    
     //mutate tests 
    void test_cell_mutate_1 (){
        Cell c (new FredkinCell());
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        CPPUNIT_ASSERT (c.myGen() == 0);
        c.mutate();
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        CPPUNIT_ASSERT (c.myGen() == 0);
        
    }
    
    void test_cell_mutate_2 (){
        Cell c (new FredkinCell(DEAD));
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == DEAD);
        CPPUNIT_ASSERT (c.myGen() == 0);
        c.mutate();
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        CPPUNIT_ASSERT (c.myGen() == 0);
        
    }
    
    void test_cell_mutate_3 (){
        Cell c;
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        CPPUNIT_ASSERT (c.myGen() == 0);
        c.mutate();
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        CPPUNIT_ASSERT (c.myGen() == 0); 
    }
    
    //myGen tests
    void test_cell_myGen_1 (){
        Cell c (new FredkinCell());
        CPPUNIT_ASSERT(c.myType() == FREDKIN);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        CPPUNIT_ASSERT (c.myGen() == 0);
        char around [] = {ALIVE, ALIVE, ALIVE, DEAD, DEAD, DEAD, DEAD, DEAD};
        char result = c.evolve(around);
        CPPUNIT_ASSERT (result == ALIVE);
        CPPUNIT_ASSERT (c.myGen() == 1);   
    }
    
    void test_cell_myGen_2 (){
        Cell c (new ConwayCell());
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        CPPUNIT_ASSERT (c.myGen() == 0);
        char around [] = {ALIVE, ALIVE, ALIVE, ALIVE, DEAD, DEAD, DEAD, DEAD};
        char result = c.evolve(around);
        CPPUNIT_ASSERT (result == DEAD);
        CPPUNIT_ASSERT (c.myGen() == 0);   
    }
    
     void test_cell_myGen_3 (){
        Cell c (new ConwayCell());
        CPPUNIT_ASSERT(c.myType() == CONWAY);
        CPPUNIT_ASSERT (c.myState() == ALIVE);
        CPPUNIT_ASSERT (c.myGen() == 0);
        char around [] = {ALIVE, ALIVE, ALIVE, DEAD, DEAD, DEAD, DEAD, DEAD};
        char result = c.evolve(around);
        CPPUNIT_ASSERT (result == ALIVE);
        CPPUNIT_ASSERT (c.myGen() == 0);   
    }
    
//     //myType tests
//     void test_cell_myType_1 (){
//         Cell c;
//         CPPUNIT_ASSERT (c.myType() == FREDKIN);
//     }
//     
//     void test_cell_myType_2 (){
//         Cell c (new FredkinCell());
//         CPPUNIT_ASSERT (c.myType() == FREDKIN);
//     }
//     
//     void test_cell_myType_3 (){
//         Cell c (new ConwayCell());
//         CPPUNIT_ASSERT (c.myType() == CONWAY);
//     }
    
    //test isRegCell
    void test_cell_regCell_1 (){
        Cell c;
        CPPUNIT_ASSERT (c.isRegCell());
    }
    
    void test_cell_regCell_2(){
        Cell c (new FredkinCell());
        CPPUNIT_ASSERT (c.isRegCell());
    }
    
     void test_cell_regCell_3 (){
        Cell c (new ConwayCell());
        CPPUNIT_ASSERT (c.isRegCell());
    }
    
    //-----------------
    //Tests for Life.h
    //-----------------
    
    //constructor tests
    void test_life_defConstructor_1(){
        Life<FredkinCell> a;
        CPPUNIT_ASSERT(a.col == 2);
        CPPUNIT_ASSERT (a.row == 2);
        CPPUNIT_ASSERT(a.gen == 0);
        for(int i = 0; i < a.row; ++i){
            for (int j = 0; j < a.col; ++j){
                CPPUNIT_ASSERT(a.current[i][j].myState() == DEAD);
            }
        }
    }
    
    void test_life_defConstructor_2(){
        Life<ConwayCell> a;
        CPPUNIT_ASSERT(a.col == 2);
        CPPUNIT_ASSERT (a.row == 2);
        CPPUNIT_ASSERT(a.gen == 0);
        for(int i = 0; i < a.row; ++i){
            for (int j = 0; j < a.col; ++j){
                CPPUNIT_ASSERT(a.current[i][j].myState() == DEAD);
            }
        }
    }
    
    void test_life_defConstructor_3(){
        Life<Cell> a;
        CPPUNIT_ASSERT(a.col == 2);
        CPPUNIT_ASSERT (a.row == 2);
        CPPUNIT_ASSERT(a.gen == 0);
        for(int i = 0; i < a.row; ++i){
            for (int j = 0; j < a.col; ++j){
                CPPUNIT_ASSERT(a.current[i][j].myState() == DEAD);
            }
        }
    }

    //non-default constructor
    void test_life_constructor_1(){
        Life<ConwayCell> a(20, 20);
        CPPUNIT_ASSERT(a.col == 20);
        CPPUNIT_ASSERT (a.row == 20);
        CPPUNIT_ASSERT(a.gen == 0);
        for(int i = 0; i < a.row; ++i){
            for (int j = 0; j < a.col; ++j){
                CPPUNIT_ASSERT(a.current[i][j].myState() == DEAD);
                CPPUNIT_ASSERT(a.current[i][j].myType() == CONWAY);
            }
        }
    }
    
    void test_life_constructor_2(){
        Life<ConwayCell> a(109, 69);
        CPPUNIT_ASSERT(a.col == 69);
        CPPUNIT_ASSERT (a.row == 109);
        CPPUNIT_ASSERT(a.gen == 0);
        for(int i = 0; i < a.row; ++i){
            for (int j = 0; j < a.col; ++j){
                CPPUNIT_ASSERT(a.current[i][j].myState() == DEAD);
                CPPUNIT_ASSERT(a.current[i][j].myType() == CONWAY);
            }
        }
    }
    
    void test_life_constructor_3(){
        Life<FredkinCell> a(25, 50);
        CPPUNIT_ASSERT(a.col == 50);
        CPPUNIT_ASSERT (a.row == 25);
        CPPUNIT_ASSERT(a.gen == 0);
        for(int i = 0; i < a.row; ++i){
            for (int j = 0; j < a.col; ++j){
                CPPUNIT_ASSERT(a.current[i][j].myState() == DEAD);
                CPPUNIT_ASSERT(a.current[i][j].myType() == FREDKIN);
            }
        }
    }
    
    void test_life_constructor_4(){
        Life<Cell> a(109, 69);
        CPPUNIT_ASSERT(a.col == 69);
        CPPUNIT_ASSERT (a.row == 109);
        CPPUNIT_ASSERT(a.gen == 0);
        for(int i = 0; i < a.row; ++i){
            for (int j = 0; j < a.col; ++j){
                CPPUNIT_ASSERT(a.current[i][j].myState() == DEAD);
                CPPUNIT_ASSERT(a.current[i][j].myType() == FREDKIN);
            }
        }
    }
    
    //placeCell
    void test_life_placeCell_1(){
        Life<ConwayCell> a(2, 2);
        CPPUNIT_ASSERT(a.col == 2);
        CPPUNIT_ASSERT (a.row == 2);
        CPPUNIT_ASSERT(a.gen == 0);
        ConwayCell* c = new ConwayCell();
        a.placeCell(*c, 0, 0);
        CPPUNIT_ASSERT (a.current[0][0].myState() == ALIVE);
        //////cout << a.printLife();
    }
    
     void test_life_placeCell_2(){
        Life<FredkinCell> a(2, 2);
        CPPUNIT_ASSERT(a.col == 2);
        CPPUNIT_ASSERT (a.row == 2);
        CPPUNIT_ASSERT(a.gen == 0);
        FredkinCell* c = new FredkinCell();
        a.placeCell(*c, 1, 1);
        CPPUNIT_ASSERT (a.current[1][1].myState() == ALIVE);
        //////cout << a.printLife();
    }
    
    void test_life_placeCell_3(){
        Life<Cell> a(2, 2);
        CPPUNIT_ASSERT(a.col == 2);
        CPPUNIT_ASSERT (a.row == 2);
        CPPUNIT_ASSERT(a.gen == 0);
        Cell* c = new Cell(new FredkinCell());
        a.placeCell(*c, 0, 1);
        CPPUNIT_ASSERT (a.current[0][1].myState() == ALIVE);
        //////cout << a.printLife();
    }
    
    //test printLife
   void test_life_printLife_1() {
        Life<ConwayCell> a(2, 2);
        CPPUNIT_ASSERT(a.col == 2);
        CPPUNIT_ASSERT (a.row == 2);
        CPPUNIT_ASSERT(a.gen == 0);
        ConwayCell* c = new ConwayCell();
        a.placeCell(*c, 0, 0);
        CPPUNIT_ASSERT (a.current[0][0].myState() == ALIVE);
        std::string w = a.printLife();
        //////cout << a.printLife();
        CPPUNIT_ASSERT (w.compare("Generation = 0, Population = 1\n*.\n..\n") == 0);
    }
    
    void test_life_printLife_2(){
        Life<FredkinCell> a(2, 2);
        CPPUNIT_ASSERT(a.col == 2);
        CPPUNIT_ASSERT (a.row == 2);
        CPPUNIT_ASSERT(a.gen == 0);
        FredkinCell* c = new FredkinCell();
        a.placeCell(*c, 0, 0);
        CPPUNIT_ASSERT (a.current[0][0].myState() == ALIVE);
        std::string w = a.printLife();
        //////cout << a.printLife();
        CPPUNIT_ASSERT (w.compare("Generation = 0, Population = 1\n0-\n--\n") == 0);
    }
    
     void test_life_printLife_3(){
        Life<Cell> a(2, 2);
        CPPUNIT_ASSERT(a.col == 2);
        CPPUNIT_ASSERT (a.row == 2);
        CPPUNIT_ASSERT(a.gen == 0);
        Cell* c = new Cell(new FredkinCell());
        a.placeCell(*c, 0, 0);
        CPPUNIT_ASSERT (a.current[0][0].myState() == ALIVE);
        std::string w = a.printLife();
        //////cout << a.printLife();
        CPPUNIT_ASSERT (w.compare("Generation = 0, Population = 1\n0-\n--\n") == 0);
    }
    
    //test playLifeRound
    void test_life_playLifeRound_1() {
        Life<FredkinCell> a(2, 2);
        CPPUNIT_ASSERT(a.col == 2);
        CPPUNIT_ASSERT (a.row == 2);
        CPPUNIT_ASSERT(a.gen == 0);
        FredkinCell* c = new FredkinCell();
        a.placeCell(*c, 0, 0);
        FredkinCell* cc = new FredkinCell();
        a.placeCell(*cc, 0, 1);
        std::string w = a.printLife();
        //////cout << a.printLife();
        CPPUNIT_ASSERT (w.compare("Generation = 0, Population = 2\n00\n--\n") == 0);
        a.playLifeRound();
        w = a.printLife();
        //////cout << a.printLife();
        CPPUNIT_ASSERT (w.compare("Generation = 1, Population = 4\n11\n00\n") == 0);
        a.playLifeRound();
        w = a.printLife();
        //////cout << a.printLife();
        CPPUNIT_ASSERT (w.compare("Generation = 2, Population = 0\n--\n--\n") == 0);
    }
        
    void test_life_playLifeRound_2(){
        Life<ConwayCell> a(2, 2);
        CPPUNIT_ASSERT(a.col == 2);
        CPPUNIT_ASSERT (a.row == 2);
        CPPUNIT_ASSERT(a.gen == 0);
        ConwayCell* c = new ConwayCell();
        a.placeCell(*c, 0, 0);
        ConwayCell* cc = new ConwayCell();
        a.placeCell(*cc, 0, 1);
        std::string w = a.printLife();
        //////cout << a.printLife();
        CPPUNIT_ASSERT (w.compare("Generation = 0, Population = 2\n**\n..\n") == 0);
        a.playLifeRound();
        w = a.printLife();
        //////cout << a.printLife();
        CPPUNIT_ASSERT (w.compare("Generation = 1, Population = 0\n..\n..\n") == 0);
        a.playLifeRound();
        w = a.printLife();
        //////cout << a.printLife();
        CPPUNIT_ASSERT (w.compare("Generation = 2, Population = 0\n..\n..\n") == 0);
    }
    
    void test_life_playLifeRound_3(){
        Life<Cell> a(2, 2);
        CPPUNIT_ASSERT(a.col == 2);
        CPPUNIT_ASSERT (a.row == 2);
        CPPUNIT_ASSERT(a.gen == 0);
        Cell* c = new Cell(new ConwayCell());
        a.placeCell(*c, 0, 0);
        Cell* cc = new Cell(new FredkinCell());
        a.placeCell(*cc, 0, 1);
        std::string w = a.printLife();
        //////cout << a.printLife();
        CPPUNIT_ASSERT (w.compare("Generation = 0, Population = 2\n*0\n--\n") == 0);
        a.playLifeRound();
        w = a.printLife();
        //////cout << a.printLife();
        CPPUNIT_ASSERT (w.compare("Generation = 1, Population = 3\n.1\n00\n") == 0);
        a.playLifeRound();
        w = a.printLife();
        //////cout << a.printLife();
        CPPUNIT_ASSERT (w.compare("Generation = 2, Population = 3\n**\n1-\n") == 0);
    }
    
    //test playLifeGame
    void test_life_playLifeGame_1(){
         Life<Cell> a(2, 2);
        CPPUNIT_ASSERT(a.col == 2);
        CPPUNIT_ASSERT (a.row == 2);
        CPPUNIT_ASSERT(a.gen == 0);
        Cell* c = new Cell(new ConwayCell());
        a.placeCell(*c, 0, 0);
        Cell* cc = new Cell(new FredkinCell());
        a.placeCell(*cc, 0, 1);
        a.playLifeGame(2, 3);
        std::string w = a.printLife();
        //////cout << a.printLife();
        CPPUNIT_ASSERT (w.compare("Generation = 2, Population = 3\n**\n1-\n") == 0);
    }
    
    void test_life_playLifeGame_2(){
         Life<Cell> a(2, 2);
        CPPUNIT_ASSERT(a.col == 2);
        CPPUNIT_ASSERT (a.row == 2);
        CPPUNIT_ASSERT(a.gen == 0);
        Cell* c = new Cell(new ConwayCell());
        a.placeCell(*c, 0, 0);
        Cell* cc = new Cell(new FredkinCell());
        a.placeCell(*cc, 0, 1);
        a.playLifeGame(2, 3);
        std::string w = a.printLife();
        //////cout << a.printLife();
        CPPUNIT_ASSERT (w.compare("Generation = 2, Population = 3\n**\n1-\n") == 0);
    }
    
     void test_life_playLifeGame_3(){
        Life<ConwayCell> a(2, 2);
        CPPUNIT_ASSERT(a.col == 2);
        CPPUNIT_ASSERT (a.row == 2);
        CPPUNIT_ASSERT(a.gen == 0);
        ConwayCell* c = new ConwayCell();
        a.placeCell(*c, 0, 0);
        ConwayCell* cc = new ConwayCell();
        a.placeCell(*cc, 0, 1);
        a.playLifeGame(2, 3);
        std::string w = a.printLife();
        // << a.printLife();
        CPPUNIT_ASSERT (w.compare("Generation = 2, Population = 0\n..\n..\n") == 0);
    }
    
    void test_life_playLifeGame_4(){
        Life<FredkinCell> a(2, 2);
        CPPUNIT_ASSERT(a.col == 2);
        CPPUNIT_ASSERT (a.row == 2);
        CPPUNIT_ASSERT(a.gen == 0);
        FredkinCell* c = new FredkinCell();
        a.placeCell(*c, 0, 0);
        FredkinCell* cc = new FredkinCell();
        a.placeCell(*cc, 0, 1);
        a.playLifeGame(2, 3);
        std::string w = a.printLife();
        //////cout << a.printLife();
        CPPUNIT_ASSERT (w.compare("Generation = 2, Population = 0\n--\n--\n") == 0);
    }
    
    //testCountPop
    void test_life_countPop_1(){
        Life<FredkinCell> a(2, 2);
        CPPUNIT_ASSERT(a.col == 2);
        CPPUNIT_ASSERT (a.row == 2);
        CPPUNIT_ASSERT(a.gen == 0);
        FredkinCell* c = new FredkinCell();
        a.placeCell(*c, 0, 0);
        FredkinCell* cc = new FredkinCell();
        a.placeCell(*cc, 0, 1);
        std::string w = a.printLife();
        //////cout << a.printLife();
        CPPUNIT_ASSERT (a.countPop() == 2);
        a.playLifeRound();
        w = a.printLife();
        //////cout << a.printLife();
        CPPUNIT_ASSERT (a.countPop() == 4);
        a.playLifeRound();
        w = a.printLife();
        //////cout << a.printLife();
        CPPUNIT_ASSERT (a.countPop() == 0);
    }
        
     void test_life_countPop_2(){
        Life<ConwayCell> a(2, 2);
        CPPUNIT_ASSERT(a.col == 2);
        CPPUNIT_ASSERT (a.row == 2);
        CPPUNIT_ASSERT(a.gen == 0);
        ConwayCell* c = new ConwayCell();
        a.placeCell(*c, 0, 0);
        ConwayCell* cc = new ConwayCell();
        a.placeCell(*cc, 0, 1);
        std::string w = a.printLife();
        ////cout << a.printLife();
        CPPUNIT_ASSERT (a.countPop() == 2);
        a.playLifeRound();
        w = a.printLife();
        ////cout << a.printLife();
        CPPUNIT_ASSERT (a.countPop() == 0);
    }
    
     void test_life_countPop_3(){
        Life<Cell> a(2, 2);
        CPPUNIT_ASSERT(a.col == 2);
        CPPUNIT_ASSERT (a.row == 2);
        CPPUNIT_ASSERT(a.gen == 0);
        Cell* c = new Cell(new ConwayCell());
        a.placeCell(*c, 0, 0);
        Cell* cc = new Cell(new FredkinCell());
        a.placeCell(*cc, 0, 1);
        std::string w = a.printLife();
        ////cout << a.printLife();
        CPPUNIT_ASSERT (a.countPop() == 2);
        a.playLifeRound();
        w = a.printLife();
        ////cout << a.printLife();
        CPPUNIT_ASSERT (a.countPop() == 3);
        a.playLifeRound();
        w = a.printLife();
        ////cout << a.printLife();
        CPPUNIT_ASSERT (a.countPop() == 3);
    }
    
    //test lookAround
    void test_life_lookAround_1(){
        Life<Cell> a(2, 2);
        CPPUNIT_ASSERT(a.col == 2);
        CPPUNIT_ASSERT (a.row == 2);
        CPPUNIT_ASSERT(a.gen == 0);
        Cell* c = new Cell(new ConwayCell());
        a.placeCell(*c, 0, 0);
        char around [8] = {DEAD, DEAD,  DEAD,  DEAD,  DEAD,  DEAD,  DEAD,  DEAD}; 
        a.lookAround(around, 0, 0);
        CPPUNIT_ASSERT (around[0] == DEAD);
        CPPUNIT_ASSERT (around[1] == DEAD);
        CPPUNIT_ASSERT (around[2] == DEAD);
        CPPUNIT_ASSERT (around[3] == DEAD);
        CPPUNIT_ASSERT (around[4] == DEAD);
        CPPUNIT_ASSERT (around[5] == DEAD);
        CPPUNIT_ASSERT (around[6] == DEAD);
        CPPUNIT_ASSERT (around[7] == DEAD);
    }
    
    void test_life_lookAround_2(){
        Life<Cell> a(2, 2);
        CPPUNIT_ASSERT(a.col == 2);
        CPPUNIT_ASSERT (a.row == 2);
        CPPUNIT_ASSERT(a.gen == 0);
        Cell* c = new Cell(new ConwayCell());
        a.placeCell(*c, 0, 0);
        Cell* cc = new Cell(new FredkinCell());
        a.placeCell(*cc, 0, 1);
        char around [8] = {DEAD, DEAD,  DEAD,  DEAD,  DEAD,  DEAD,  DEAD,  DEAD}; 
        a.lookAround(around, 0, 0);
        CPPUNIT_ASSERT (around[0] == DEAD);
        CPPUNIT_ASSERT (around[1] == DEAD);
        CPPUNIT_ASSERT (around[2] == ALIVE);
        CPPUNIT_ASSERT (around[3] == DEAD);
        CPPUNIT_ASSERT (around[4] == DEAD);
        CPPUNIT_ASSERT (around[5] == DEAD);
        CPPUNIT_ASSERT (around[6] == DEAD);
        CPPUNIT_ASSERT (around[7] == DEAD);
    }
    
    void test_life_lookAround_3(){
        Life<FredkinCell> a(2, 2);
        CPPUNIT_ASSERT(a.col == 2);
        CPPUNIT_ASSERT (a.row == 2);
        CPPUNIT_ASSERT(a.gen == 0);
        FredkinCell* c = new FredkinCell();
        a.placeCell(*c, 0, 0);
        FredkinCell* cc = new FredkinCell();
        a.placeCell(*cc, 0, 1);
        FredkinCell* ccc = new FredkinCell();
        a.placeCell(*ccc, 1, 0);
        char around [8] = {DEAD, DEAD,  DEAD,  DEAD,  DEAD,  DEAD,  DEAD,  DEAD}; 
        a.lookAround(around, 0, 0);
        CPPUNIT_ASSERT (around[0] == DEAD);
        CPPUNIT_ASSERT (around[1] == DEAD);
        CPPUNIT_ASSERT (around[2] == ALIVE);
        CPPUNIT_ASSERT (around[3] == ALIVE);
        CPPUNIT_ASSERT (around[4] == DEAD);
        CPPUNIT_ASSERT (around[5] == DEAD);
        CPPUNIT_ASSERT (around[6] == DEAD);
        CPPUNIT_ASSERT (around[7] == DEAD);
    }
    
    CPPUNIT_TEST_SUITE(TestLife);
    	//conway
    	CPPUNIT_TEST(test_conway_constructor_1);
    	CPPUNIT_TEST(test_conway_constructor_2);
    	CPPUNIT_TEST(test_conway_constructor_3);
    	CPPUNIT_TEST(test_conway_evolve_1);
    	CPPUNIT_TEST(test_conway_evolve_2);
    	CPPUNIT_TEST(test_conway_evolve_3);
    	CPPUNIT_TEST(test_conway_evolve_4);
    	CPPUNIT_TEST(test_conway_typeAndState_1);
    	CPPUNIT_TEST(test_conway_typeAndState_2);
    	CPPUNIT_TEST(test_conway_typeAndState_3);
    	CPPUNIT_TEST(test_conway_changeState_1);
    	CPPUNIT_TEST(test_conway_changeState_2);
    	CPPUNIT_TEST(test_conway_changeState_3);
    	CPPUNIT_TEST(test_conway_myGen_1);
    	CPPUNIT_TEST(test_conway_myGen_2);
    	CPPUNIT_TEST(test_conway_myGen_3);
    	CPPUNIT_TEST(test_conway_regCell_1);
    	CPPUNIT_TEST(test_conway_regCell_2);
    	CPPUNIT_TEST(test_conway_regCell_3);
    	//fredkin
    	CPPUNIT_TEST(test_fredkin_constructor_1);
    	CPPUNIT_TEST(test_fredkin_constructor_2);
    	CPPUNIT_TEST(test_fredkin_constructor_3);
    	CPPUNIT_TEST(test_fredkin_evolveAndIncGen_1);
    	CPPUNIT_TEST(test_fredkin_evolveAndIncGen_2);
    	CPPUNIT_TEST(test_fredkin_evolveAndIncGen_3);
    	CPPUNIT_TEST(test_fredkin_evolveAndIncGen_4);
    	CPPUNIT_TEST(test_fredkin_myTypeAndMyStateAndMyGen_1);
    	CPPUNIT_TEST(test_fredkin_myTypeAndMyStateAndMyGen_2);
    	CPPUNIT_TEST(test_fredkin_myTypeAndMyStateAndMyGen_3);
    	CPPUNIT_TEST(test_fredkin_changeState_1);
    	CPPUNIT_TEST(test_fredkin_changeState_2);
    	CPPUNIT_TEST(test_fredkin_changeState_3);
    	CPPUNIT_TEST(test_fredkin_regCell_1);
    	CPPUNIT_TEST(test_fredkin_regCell_2);
    	CPPUNIT_TEST(test_fredkin_regCell_3);
    	//handle 
    	CPPUNIT_TEST(test_handle_constructor_1);
    	CPPUNIT_TEST(test_handle_constructor_2);
    	CPPUNIT_TEST(test_handle_constructor_3);
    	CPPUNIT_TEST(test_handle_constructor_4);
    	CPPUNIT_TEST(test_handle_copyconstructor_1);
    	CPPUNIT_TEST(test_handle_copyconstructor_2);
    	CPPUNIT_TEST(test_handle_copyconstructor_3);
    	CPPUNIT_TEST(test_handle_assgnconstructor_1);
    	CPPUNIT_TEST(test_handle_assgnconstructor_2);
    	CPPUNIT_TEST(test_handle_assgnconstructor_3);
    	CPPUNIT_TEST(test_handle_swap_1);
    	CPPUNIT_TEST(test_handle_swap_2);
    	CPPUNIT_TEST(test_handle_swap_3);
    	//cell
    	CPPUNIT_TEST(test_cell_constructor_1);
    	CPPUNIT_TEST(test_cell_constructor_2);
    	CPPUNIT_TEST(test_cell_constructor_3);
    	CPPUNIT_TEST(test_cell_evolve_1);
    	CPPUNIT_TEST(test_cell_evolve_2);
    	CPPUNIT_TEST(test_cell_evolve_3);
    	CPPUNIT_TEST(test_cell_changeState_1);
    	CPPUNIT_TEST(test_cell_changeState_2);
    	CPPUNIT_TEST(test_cell_changeState_3);
    	CPPUNIT_TEST(test_cell_myType_1);
    	CPPUNIT_TEST(test_cell_myType_2);
    	CPPUNIT_TEST(test_cell_myType_3);
    	CPPUNIT_TEST(test_cell_myState_1);
    	CPPUNIT_TEST(test_cell_myState_2);
    	CPPUNIT_TEST(test_cell_myState_3);
    	CPPUNIT_TEST(test_cell_mutate_1);
    	CPPUNIT_TEST(test_cell_mutate_2);
    	CPPUNIT_TEST(test_cell_mutate_3);
    	CPPUNIT_TEST(test_cell_myGen_1);
    	CPPUNIT_TEST(test_cell_myGen_2);
    	CPPUNIT_TEST(test_cell_myGen_3);
    	CPPUNIT_TEST(test_cell_regCell_1);
    	CPPUNIT_TEST(test_cell_regCell_2);
    	CPPUNIT_TEST(test_cell_regCell_3);
    	//life
    	CPPUNIT_TEST(test_life_defConstructor_1);
    	CPPUNIT_TEST(test_life_defConstructor_2);
    	CPPUNIT_TEST(test_life_defConstructor_3);
    	CPPUNIT_TEST(test_life_constructor_1);
    	CPPUNIT_TEST(test_life_constructor_2);
    	CPPUNIT_TEST(test_life_constructor_3);
    	CPPUNIT_TEST(test_life_constructor_4);
    	CPPUNIT_TEST(test_life_placeCell_1);
    	CPPUNIT_TEST(test_life_placeCell_2);
    	CPPUNIT_TEST(test_life_placeCell_3);
    	CPPUNIT_TEST(test_life_printLife_1);
    	CPPUNIT_TEST(test_life_printLife_2);
    	CPPUNIT_TEST(test_life_printLife_3);
    	CPPUNIT_TEST(test_life_playLifeRound_1);
    	CPPUNIT_TEST(test_life_playLifeRound_2);
    	CPPUNIT_TEST(test_life_playLifeRound_3);
    	CPPUNIT_TEST(test_life_playLifeGame_1);
    	CPPUNIT_TEST(test_life_playLifeGame_2);
    	CPPUNIT_TEST(test_life_playLifeGame_3);
    	CPPUNIT_TEST(test_life_playLifeGame_4);
    	CPPUNIT_TEST(test_life_countPop_1);
    	CPPUNIT_TEST(test_life_countPop_2);
    	CPPUNIT_TEST(test_life_countPop_3);
    	CPPUNIT_TEST(test_life_lookAround_1);
    	CPPUNIT_TEST(test_life_lookAround_2);
    	CPPUNIT_TEST(test_life_lookAround_3);
    CPPUNIT_TEST_SUITE_END();

};

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    ////cout << "TestLife.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestLife::suite());
    tr.run();

    ////cout << "Done." << endl;
    return 0;
}