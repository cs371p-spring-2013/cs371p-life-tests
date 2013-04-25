// Cameron Bielstein, UTEID: ctb677, CSID: cameronb

// --------
// includes
// --------

#include <iostream>  // ios_base
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner


// Defined to reveal private parts
#define private public
#define protected public
#define class struct

#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

struct TestLife : CppUnit::TestFixture {
    // ---------
    // Test Life
    // ---------

    // ---------------------------
    // Test ConwayCell Constructor
    // ---------------------------
        // -------------------------
        // test_conway_constructor_1
        // -------------------------
        void test_conway_constructor_1 () {
            ConwayCell c = ConwayCell(true, false);
            CPPUNIT_ASSERT(c.isAlive == true);
        }
        // -------------------------
        // test_conway_constructor_2
        // -------------------------        
        void test_conway_constructor_2 () {
            ConwayCell c = ConwayCell(false, false);
            CPPUNIT_ASSERT(c.isAlive == false);
        }
        // -------------------------
        // test_conway_constructor_3
        // -------------------------        
        void test_conway_constructor_3 () {
            ConwayCell c = ConwayCell(true, false);
            CPPUNIT_ASSERT(c.isAlive != false);
        }

    // ---------------------------
    // Test FredkinCell Constructor
    // ---------------------------
        // -------------------------
        // test_fredkin_constructor_1
        // -------------------------
        void test_fredkin_constructor_1 () {
            FredkinCell c = FredkinCell(true, true);
            CPPUNIT_ASSERT(c.isAlive == true);
        }
        // -------------------------
        // test_fredkin_constructor_2
        // -------------------------        
        void test_fredkin_constructor_2 () {
            FredkinCell c = FredkinCell(false, true);
            CPPUNIT_ASSERT(c.isAlive == false);
        }
        // -------------------------
        // test_fredkin_constructor_3
        // -------------------------        
        void test_fredkin_constructor_3 () {
            FredkinCell c = FredkinCell(true, true);
            CPPUNIT_ASSERT(c.isAlive != false);
        }

    // -----------------
    // Test Conway Print
    // -----------------
     
        // -------------------
        // test_conway_print_1
        // -------------------
        void test_conway_print_1 () {
            ConwayCell c(true, false);
            CPPUNIT_ASSERT(c.print() == '*');
        }
        // -------------------
        // test_conway_print_2
        // -------------------
        void test_conway_print_2 () {
            ConwayCell c(false, false);
            CPPUNIT_ASSERT(c.print() == '.');
        }
        // -------------------
        // test_conway_print_3
        // -------------------
        void test_conway_print_3 () {
            ConwayCell c(false, false);
            CPPUNIT_ASSERT(c.print() != '*');
        }

    // -----------------
    // Test Fredkin Print
    // -----------------
     
        // -------------------
        // test_fredkin_print_1
        // -------------------
        void test_fredkin_print_1 () {
            FredkinCell c(true, true);
            CPPUNIT_ASSERT(c.print() == '0');
        }
        // -------------------
        // test_fredkin_print_2
        // -------------------
        void test_fredkin_print_2 () {
            FredkinCell c(false, true);
            CPPUNIT_ASSERT(c.print() == '-');
        }
        // -------------------
        // test_fredkin_print_3
        // -------------------
        void test_fredkin_print_3 () {
            FredkinCell c(false, true);
            CPPUNIT_ASSERT(c.print() != '0');
        }

    // ---------------------        
    // Test Cell Constructor
    // ---------------------
        // -----------------------
        // test_cell_constructor_1
        // -----------------------
        void test_cell_constructor_1 () {
            ConwayCell cc(true, false);
            Cell c(&cc);
            CPPUNIT_ASSERT(c.get()->isAlive == cc.isAlive);
        }
        // -----------------------
        // test_cell_constructor_2
        // -----------------------
        void test_cell_constructor_2 () {
            ConwayCell cc(true, false);
            ConwayCell cc2(false, true);
            Cell c(&cc2);
            CPPUNIT_ASSERT(c.get() != &cc2);
            CPPUNIT_ASSERT(c.get() != &cc);
            CPPUNIT_ASSERT(c.get()->isAlive == cc2.isAlive);
        }

	// -----------------------
	// test_cell_constructor_3
	// -----------------------
	void test_cell_constructor_3 () {
	    ConwayCell cc(false, false);
	    ConwayCell cc2 (false, false);
	    Cell c(&cc);
	    CPPUNIT_ASSERT(c.get() != &cc2);
	    CPPUNIT_ASSERT(c.get() != &cc);
	    CPPUNIT_ASSERT(c.get()->isAlive == cc.isAlive);
        }
        
    // -------------------------
    // Test ConwayCell Make Move
    // -------------------------
        // ----------------------
        // test_conway_makemove_1
        // ----------------------
        void test_conway_makemove_1 () {
            ConwayCell dead(false, false);
            bool neighbors[8] = {false, false, false, false, false, true, true, true};
            dead.makeMove(neighbors);
            CPPUNIT_ASSERT(dead.isAlive == true);
        }
        // ----------------------
        // test_conway_makemove_2
        // ----------------------        
        void test_conway_makemove_2 () {
            ConwayCell alive(true, false);
            bool neighbors[8] = {false, false, false, false, true, true, true, true};
            alive.makeMove(neighbors);
            CPPUNIT_ASSERT(alive.isAlive == false);
        }
        // ----------------------
        // test_conway_makemove_3
        // ----------------------        
        void test_conway_makemove_3 () {
            ConwayCell alive(true, false);
            bool neighbors[8] = {false, false, false, false, false, true, true, true};
            alive.makeMove(neighbors);
            CPPUNIT_ASSERT(alive.isAlive == true);
        }

    // -------------------------
    // Test FredkinCell Make Move
    // -------------------------
        // ----------------------
        // test_fredkin_makemove_1
        // ----------------------
        void test_fredkin_makemove_1 () {
            FredkinCell dead(false, false);
            bool neighbors[8] = {false, false, false, false, false, true, true, true};
            CPPUNIT_ASSERT(!dead.makeMove(neighbors));
            CPPUNIT_ASSERT(dead.isAlive == true);
        }
        // ----------------------
        // test_fredkin_makemove_2
        // ----------------------        
        void test_fredkin_makemove_2 () {
            FredkinCell alive(true, false);
            bool neighbors[8] = {true, true, true, true, false, false, false, false};
            CPPUNIT_ASSERT(!alive.makeMove(neighbors));
            CPPUNIT_ASSERT(alive.isAlive == false);
        }
        // ----------------------
        // test_fredkin_makemove_3
        // ----------------------        
        void test_fredkin_makemove_3 () {
            FredkinCell alive(true, false);
            bool neighbors[8] = {false, false, true, false, false, true, false, true};
            alive.age = 1;
            CPPUNIT_ASSERT(alive.makeMove(neighbors));
            CPPUNIT_ASSERT(alive.isAlive == true);
        }

    //----------------------------------
    // Test the used functions in handle
    //----------------------------------
    
    // -------------------------
    // test_handle_constructor_1
    // -------------------------
    void test_handle_constructor_1 (){
        ConwayCell* c = new ConwayCell(true, true);
        Handle<AbstractCell> h (c);
        AbstractCell* p = h.get();
        CPPUNIT_ASSERT(p == c);
    }

    // -------------------------
    // test_handle_constructor_2
    // -------------------------    
    void test_handle_constructor_2 (){
        FredkinCell* c = new FredkinCell(true, true);
        Handle<AbstractCell> h (c);
        AbstractCell* p = h.get();
        CPPUNIT_ASSERT(p == c);
    }
    // -------------------------
    // test_handle_constructor_3
    // -------------------------    
    void test_handle_constructor_3 (){
       FredkinCell* c = new FredkinCell(false, false);
       const Handle<AbstractCell> h (c);
       const AbstractCell* p = h.get();
       CPPUNIT_ASSERT(p == c);
    }
    
    // -----------------------------
    // test_handle_copyconstructor_1
    // -----------------------------
     void test_handle_copyconstructor_1 () {
        ConwayCell* c = new ConwayCell(true, true);
        Handle<AbstractCell> h (c);
        Handle<AbstractCell> h2 (h);
        CPPUNIT_ASSERT(h._p != h2._p);
        CPPUNIT_ASSERT(h._p->alive() == h2._p->alive());        
    }

    // -----------------------------
    // test_handle_copyconstructor_2
    // -----------------------------    
    void test_handle_copyconstructor_2 () {
        FredkinCell* c = new FredkinCell(true, true);
        Handle<AbstractCell> h (c);
        Handle<AbstractCell> h2 (h);
        CPPUNIT_ASSERT(h._p != h2._p);
        CPPUNIT_ASSERT (h._p->alive() == h2._p->alive());        
    }

    // -----------------------------
    // test_handle_copyconstructor_3
    // -----------------------------   
     void test_handle_copyconstructor_3 (){
        ConwayCell* c = new ConwayCell(true, false);
        Handle<AbstractCell> h (c);
        Handle<AbstractCell> h2 (h);
        CPPUNIT_ASSERT (h._p != h2._p);
        CPPUNIT_ASSERT (h._p->alive() == h2._p->alive());
    }
    
    // ------------------
    // test_handle_swap_1
    // ------------------
    void test_handle_swap_1 (){
        ConwayCell* c = new ConwayCell(true, true);
        ConwayCell* fc = new ConwayCell(true, true);
        Handle<AbstractCell> h(c);
        Handle<AbstractCell> fh(fc);
        h.swap(fh);
        CPPUNIT_ASSERT(h._p == fc && fh._p == c);
    }
    
    // ------------------
    // test_handle_swap_2
    // ------------------
    void test_handle_swap_2 (){
        FredkinCell* c = new FredkinCell(true, true);
        FredkinCell* fc = new FredkinCell(true, true);
        Handle<AbstractCell> h(c);
        Handle<AbstractCell> fh(fc);
        fh.swap(fh);
        CPPUNIT_ASSERT(h._p == c && fh._p == fc);
    }

    // ------------------
    // test_handle_swap_3
    // ------------------
     void test_handle_swap_3 (){
        FredkinCell* c = new FredkinCell(true, true);
        FredkinCell* fc = new FredkinCell(true, true);
        Handle<AbstractCell> h(c);
        Handle<AbstractCell> fh(fc);
        h.swap(fh);
        CPPUNIT_ASSERT(h._p == fc && fh._p == c);
    }

    // ---------------------
    // Test ConwayCell Clone
    // ---------------------
        // -------------------
        // test_conway_clone_1
        // -------------------
        void test_conway_clone_1 () {
            ConwayCell dead(false, false);
            ConwayCell* dead2 = dead.clone();
            CPPUNIT_ASSERT(dead.isAlive == dead2->isAlive);
            delete dead2;
        }

        // -------------------
        // test_conway_clone_2
        // -------------------
        void test_conway_clone_2 () {
            ConwayCell alive(true, false);
            ConwayCell* alive2 = alive.clone();
            CPPUNIT_ASSERT(alive.isAlive == alive2->isAlive);
            delete alive2;
        }

        // -------------------
        // test_conway_clone_3
        // -------------------
        void test_conway_clone_3 () {
            ConwayCell alive(true, false);
            ConwayCell* alive2 = alive.clone();
            ConwayCell dead(false, false); 
            CPPUNIT_ASSERT(dead.isAlive != alive2->isAlive);
            delete alive2;
        }

    // ---------------------
    // Test FredkinCell Clone
    // ---------------------
        // -------------------
        // test_fredkin_clone_1
        // -------------------
        void test_fredkin_clone_1 () {
            FredkinCell dead(false, true);
            FredkinCell* dead2 = dead.clone();
            CPPUNIT_ASSERT(dead.isAlive == dead2->isAlive);
            delete dead2;
        }
        // -------------------
        // test_fredkin_clone_2
        // -------------------
        void test_fredkin_clone_2 () {
            FredkinCell alive(true, true);
            FredkinCell* alive2 = alive.clone();
            CPPUNIT_ASSERT(alive.isAlive == alive2->isAlive);
            delete alive2;
        }

        // -------------------
        // test_fredkin_clone_3
        // -------------------
        void test_fredkin_clone_3 () {
            FredkinCell alive(true, true);
            FredkinCell* alive2 = alive.clone();
            FredkinCell dead(false, true); 
            CPPUNIT_ASSERT(dead.isAlive != alive2->isAlive); 
            delete alive2;
        }

    // ---------------------
    // Test Cell Clone
    // ---------------------
        // -------------------
        // test_cell_clone_1
        // -------------------
        void test_cell_clone_1 () {
            Cell dead(false, true);
            Cell dead2 = dead; 
            CPPUNIT_ASSERT(dead.alive() == dead2.alive());      
        }
        // -------------------
        // test_cell_clone_2
        // -------------------
        void test_cell_clone_2 () {
            Cell alive(true, false);
            Cell alive2 = alive; 
            CPPUNIT_ASSERT(alive.alive() == alive2.alive());         
        }

        // -------------------
        // test_cell_clone_3
        // -------------------
        void test_cell_clone_3 () {
            Cell alive(true, true);
            Cell alive2 = alive; 
            Cell dead(false, false); 
            CPPUNIT_ASSERT(dead.alive() != alive2.alive());           
        }

    // -----------------------
    // Test AbstractCell alive
    // -----------------------
        // ---------------------
        // test_abstract_alive_1
        // ---------------------
        void test_abstract_alive_1 () {
            FredkinCell dead(false, true);      
            CPPUNIT_ASSERT(!dead.alive());
        }
        // ---------------------
        // test_abstract_alive_2
        // ---------------------
        void test_abstract_alive_2 () {
            ConwayCell alive(true, false);
            CPPUNIT_ASSERT(alive.alive());
        }
        // ---------------------
        // test_abstract_alive_3
        // ---------------------
        void test_abstract_alive_3 () {
            ConwayCell alive(true, false);
            CPPUNIT_ASSERT(!(!alive.alive()));
        }

    // ---------------
    // Test Cell alive
    // ---------------
        // ---------------------
        // test_cell_alive_1
        // ---------------------
        void test_cell_alive_1 () {
            Cell dead(false, true);      
            CPPUNIT_ASSERT(!dead.alive());
        }
        // ---------------------
        // test_cell_alive_2
        // ---------------------
        void test_cell_alive_2 () {
            Cell alive(true, false);
            CPPUNIT_ASSERT(alive.alive());
        }
        // ---------------------
        // test_cell_alive_3
        // ---------------------
        void test_cell_alive_3 () {
            Cell alive(true, false);
            CPPUNIT_ASSERT(alive.alive());
        }

    // ----------------
    // Test Cell Mutate
    // ----------------
        // ------------------
        // test_cell_mutate_1
        // ------------------
        void test_cell_mutate_1 () {
            FredkinCell fc(false, false);
            Cell c(&fc);
            c.mutate();
            CPPUNIT_ASSERT(c.alive());
        }
        // ------------------
        // test_cell_mutate_2
        // ------------------
        void test_cell_mutate_2 () {
            ConwayCell cc(true, false);
            Cell c(&cc);
            c.mutate();
            CPPUNIT_ASSERT(c.alive());
        }
        // ------------------
        // test_cell_mutate_3
        // ------------------
        void test_cell_mutate_3 () {
            FredkinCell fc(true, false);
            Cell c(&fc);
            c.mutate();
            CPPUNIT_ASSERT(c.alive());
        }

    // -------------------
    // Test Life makeBoard
    // -------------------
        // ---------------------
        // test_life_makeboard_1
        // ---------------------
        void test_life_makeboard_1 () {
            std::istringstream r("1\n10\n....*.....");
            Life<ConwayCell> x;
            CPPUNIT_ASSERT(x.makeBoard(r) == 1);
        }
        // ---------------------
        // test_life_makeboard_2
        // ---------------------
        void test_life_makeboard_2 () {
            std::istringstream r("1\n5\n00-00");
            Life<FredkinCell> x;
            CPPUNIT_ASSERT(x.makeBoard(r) == 4);
        }
        // ---------------------
        // test_life_makeboard_3
        // ---------------------
        void test_life_makeboard_3 () {
            std::istringstream r("2\n7\n0*0*..-\n**0.*..");
            Life<Cell> x;
            CPPUNIT_ASSERT(x.makeBoard(r) == 8);
        }
    // ------------------
    // Test Life takeTurn
    // ------------------
        // --------------------
        // test_life_taketurn_1
        // --------------------
        void test_life_taketurn_1 () {
            std::istringstream r("3\n3\n...\n.*.\n...");
            Life<ConwayCell> x;
            CPPUNIT_ASSERT(x.makeBoard(r) == 1);
            CPPUNIT_ASSERT(x.takeTurn() == 0);
        }
        // --------------------
        // test_life_taketurn_2
        // --------------------
        void test_life_taketurn_2 () {
            std::istringstream r("1\n5\n000-0");
            Life<FredkinCell> x;
            CPPUNIT_ASSERT(x.makeBoard(r) == 4);
            CPPUNIT_ASSERT(x.takeTurn() == 2);
        }
        // --------------------
        // test_life_taketurn_3
        // --------------------
        void test_life_taketurn_3 () {
            std::istringstream r("2\n7\n0*0*..-\n**0.*..");
            Life<Cell> x;
            CPPUNIT_ASSERT(x.makeBoard(r) == 8);
            CPPUNIT_ASSERT(x.takeTurn() == 3);     
        }

    // --------------------
    // Test Life printBoard
    // --------------------
        // ----------------------
        // test_life_printboard_1
        // ----------------------
        void test_life_printboard_1 () {
            std::istringstream r("1\n5\n*.*.*");
            Life<ConwayCell> x;
            x.makeBoard(r);
            std::ostringstream o;
            x.printBoard(o);
            CPPUNIT_ASSERT(o.str() == "*.*.*\n\n");
        }
        // ----------------------
        // test_life_printboard_2
        // ----------------------
        void test_life_printboard_2 () {
            std::istringstream r("2\n5\n-0-0-\n0-0-0");
            Life<FredkinCell> x;
            x.makeBoard(r);
            std::ostringstream o;
            x.printBoard(o);
            CPPUNIT_ASSERT(o.str() == "-0-0-\n0-0-0\n\n");
        }
        // ----------------------
        // test_life_printboard_3
        // ----------------------
        void test_life_printboard_3 () {
            std::istringstream r("3\n5\n-0-0-\n0.0.0\n**.**");
            Life<Cell> x;
            x.makeBoard(r);
            std::ostringstream o;
            x.printBoard(o);
            CPPUNIT_ASSERT(o.str() == "-0-0-\n0.0.0\n**.**\n\n");
        }


    // -----
    // suite
    // -----
        
    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST(test_conway_constructor_1);
    CPPUNIT_TEST(test_conway_constructor_2);
    CPPUNIT_TEST(test_conway_constructor_3);
    CPPUNIT_TEST(test_fredkin_constructor_1);
    CPPUNIT_TEST(test_fredkin_constructor_2);
    CPPUNIT_TEST(test_fredkin_constructor_3);
    CPPUNIT_TEST(test_conway_print_1);
    CPPUNIT_TEST(test_conway_print_2);
    CPPUNIT_TEST(test_conway_print_3);
    CPPUNIT_TEST(test_fredkin_print_1);
    CPPUNIT_TEST(test_fredkin_print_2);
    CPPUNIT_TEST(test_fredkin_print_3);
    CPPUNIT_TEST(test_cell_constructor_1);
    CPPUNIT_TEST(test_cell_constructor_2);
    CPPUNIT_TEST(test_cell_constructor_3);   
    CPPUNIT_TEST(test_conway_makemove_1);
    CPPUNIT_TEST(test_conway_makemove_2);
    CPPUNIT_TEST(test_conway_makemove_3);
    CPPUNIT_TEST(test_fredkin_makemove_1);
    CPPUNIT_TEST(test_fredkin_makemove_2);
    CPPUNIT_TEST(test_fredkin_makemove_3);
    CPPUNIT_TEST(test_handle_constructor_1);
    CPPUNIT_TEST(test_handle_constructor_2);    
    CPPUNIT_TEST(test_handle_constructor_3);
    CPPUNIT_TEST(test_handle_copyconstructor_1);
    CPPUNIT_TEST(test_handle_copyconstructor_2);
    CPPUNIT_TEST(test_handle_copyconstructor_3);
    CPPUNIT_TEST(test_handle_swap_1);
    CPPUNIT_TEST(test_handle_swap_2);
    CPPUNIT_TEST(test_handle_swap_3);
    CPPUNIT_TEST(test_conway_clone_1);
    CPPUNIT_TEST(test_conway_clone_2);
    CPPUNIT_TEST(test_conway_clone_3);
    CPPUNIT_TEST(test_fredkin_clone_1);
    CPPUNIT_TEST(test_fredkin_clone_2);
    CPPUNIT_TEST(test_fredkin_clone_3);
    CPPUNIT_TEST(test_cell_clone_1);
    CPPUNIT_TEST(test_cell_clone_2);
    CPPUNIT_TEST(test_cell_clone_3);
    CPPUNIT_TEST(test_abstract_alive_1);
    CPPUNIT_TEST(test_abstract_alive_2);
    CPPUNIT_TEST(test_abstract_alive_3);
    CPPUNIT_TEST(test_cell_alive_1);
    CPPUNIT_TEST(test_cell_alive_2);
    CPPUNIT_TEST(test_cell_alive_3);
    CPPUNIT_TEST(test_cell_mutate_1);
    CPPUNIT_TEST(test_cell_mutate_2);
    CPPUNIT_TEST(test_cell_mutate_3);
    CPPUNIT_TEST(test_life_makeboard_1);
    CPPUNIT_TEST(test_life_makeboard_2);
    CPPUNIT_TEST(test_life_makeboard_3);
    CPPUNIT_TEST(test_life_taketurn_1);
    CPPUNIT_TEST(test_life_taketurn_2);
    CPPUNIT_TEST(test_life_taketurn_3);
    CPPUNIT_TEST(test_life_printboard_1);
    CPPUNIT_TEST(test_life_printboard_2);
    CPPUNIT_TEST(test_life_printboard_3);
    CPPUNIT_TEST_SUITE_END();    
    };
    
int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);    // turn off synchronization with C I/O
    cout << "TestLife.c++" << endl;

    CppUnit::TextTestRunner tr;

    tr.addTest(TestLife::suite());

    tr.run();

    cout << "Done." << endl;
    return 0;}
