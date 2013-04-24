// --------
// TestLife.c++
// --------

#pragma GCC diagnostic ignored "-Wdeprecated-declarations" // Disable auto_ptr compiler warning

// --------
// access
// --------

#define private public
#define protected public

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Life.h"

// -----------
// TestLife
// -----------

struct TestLife : CppUnit::TestFixture {
    // ----
    // alive
    // ----
    
    void test_alive_1 () {
        ConwayCell cell(true);
        CPPUNIT_ASSERT(cell.alive());}
    
    void test_alive_2 () {
        FredkinCell cell(false);
        CPPUNIT_ASSERT(!(cell.alive()));}
    
    void test_alive_3 () {
        Cell cell(new FredkinCell(false));
        CPPUNIT_ASSERT(!(cell.alive()));}

    // ----
    // clone
    // ----
    
    void test_clone_1 () {
        Cell c1;
        Cell c2;
        c2 = c1; // calls clone through Handler
        CPPUNIT_ASSERT(c1._p != c2._p);
        CPPUNIT_ASSERT(c1._p->_alive == c2._p->_alive);}
    
    void test_clone_2 () {
        Cell c1;
        Cell c2(new ConwayCell(true));
        c2 = c1; // calls clone through Handler
        CPPUNIT_ASSERT(c1._p != c2._p);
        CPPUNIT_ASSERT(c1._p->_alive == c2._p->_alive);}
    
    void test_clone_3 () {
        Cell c1(new ConwayCell(false));
        Cell c2(new ConwayCell(true));
        c2 = c1; // calls clone through Handler
        CPPUNIT_ASSERT(c1._p != c2._p);
        CPPUNIT_ASSERT(c1._p->_alive == c2._p->_alive);}

    // ----
    // ConwayCell::read
    // ----
    
    void test_cc_read_1 () {
        ConwayCell c;
        std::istringstream iss("*");
        c.read(iss);
        CPPUNIT_ASSERT(c.alive());}
    
    void test_cc_read_2 () {
        ConwayCell c;
        std::istringstream iss(".");
        c.read(iss);
        CPPUNIT_ASSERT(!(c.alive()));}
    
    void test_cc_read_3 () {
        ConwayCell c;
        CPPUNIT_ASSERT(!(c.alive()));
        std::istringstream iss("-");
        c.read(iss);
        CPPUNIT_ASSERT(!(c.alive()));}
    
    // ----
    // ConwayCell::write
    // ----

    void test_cc_write_1 () {
        ConwayCell c(true);
        std::ostringstream oss;
        c.write(oss);
        CPPUNIT_ASSERT(oss.str() == "*");}
    
    void test_cc_write_2 () {
        ConwayCell c(false);
        std::ostringstream oss;
        c.write(oss);
        CPPUNIT_ASSERT(oss.str() == ".");}
    
    void test_cc_write_3 () {
        ConwayCell c;
        std::ostringstream oss;
        c.write(oss);
        c.write(oss);
        CPPUNIT_ASSERT(oss.str() == "..");}
    
    // ----
    // ConwayCell::evolve
    // ----
    
    void test_cc_evolve_1 () {
        ConwayCell c;
        bool b[] = {0, 0, 0, 1, 0, 1, 1, 0};
        c.evolve(b);
        CPPUNIT_ASSERT(c.alive());}
    
    void test_cc_evolve_2 () {
        ConwayCell c;
        bool b[] = {0, 0, 0, 0, 0, 1, 1, 0};
        c.evolve(b);
        CPPUNIT_ASSERT(!(c.alive()));}
    
    void test_cc_evolve_3 () {
        ConwayCell c(true);
        bool b[] = {0, 0, 0, 0, 0, 0, 0, 0};
        c.evolve(b);
        CPPUNIT_ASSERT(!(c.alive()));}

    // ----
    // FredkinCell::read
    // ----

    void test_fc_read_1 () {
        FredkinCell c;
        std::istringstream iss("5");
        c.read(iss);
        CPPUNIT_ASSERT(c.alive());
        CPPUNIT_ASSERT(c._age == 5);}
    
    void test_fc_read_2 () {
        FredkinCell c;
        std::istringstream iss("-");
        c.read(iss);
        CPPUNIT_ASSERT(!(c.alive()));
        CPPUNIT_ASSERT(c._age == 0);}
    
    void test_fc_read_3 () {
        FredkinCell c;
        CPPUNIT_ASSERT(!(c.alive()));
        std::istringstream iss("+++");
        c.read(iss);
        CPPUNIT_ASSERT(c.alive());
        CPPUNIT_ASSERT(c._age == 10);}
    
    // ----
    // FredkinCell::write
    // ----

    void test_fc_write_1 () {
        FredkinCell c(true);
        std::ostringstream oss;
        c.write(oss);
        CPPUNIT_ASSERT(oss.str() == "0");}
    
    void test_fc_write_2 () {
        FredkinCell c(false);
        std::ostringstream oss;
        c.write(oss);
        CPPUNIT_ASSERT(oss.str() == "-");}
    
    void test_fc_write_3 () {
        FredkinCell c(true);
        c._age = 11;
        std::ostringstream oss;
        c.write(oss);
        CPPUNIT_ASSERT(oss.str() == "+");}

    // ----
    // FredkinCell::evolve
    // ----
    
    void test_fc_evolve_1 () {
        FredkinCell c;
        bool b[] = {0, 0, 0, 1, 0, 0, 0, 0};
        c.evolve(b);
        CPPUNIT_ASSERT(c.alive());}
    
    void test_fc_evolve_2 () {
        FredkinCell c(true);
        bool b[] = {0, 1, 0, 1, 0, 0, 1, 0};
        c.evolve(b);
        CPPUNIT_ASSERT(c.alive());
        CPPUNIT_ASSERT(c._age == 1);}
    
    void test_fc_evolve_3 () {
        FredkinCell c(true);
        bool b[] = {0, 1, 0, 1, 1, 0, 1, 0};
        c.evolve(b);
        CPPUNIT_ASSERT(!(c.alive()));}

    // ----
    // Cell::read (only one test since it's merely a pass-through method)
    // ----
    
    void test_c_read () {
        Cell c;
        std::istringstream iss("5");
        c.read(iss);
        CPPUNIT_ASSERT(c.alive());}
    
    // ----
    // Cell::write (only one test since it's merely a pass-through method)
    // ----
    
    void test_c_write () {
        Cell c;
        std::ostringstream oss;
        c.write(oss);
        CPPUNIT_ASSERT(oss.str() == "-");}

    // ----
    // Cell::evolve (only one test since it's merely a pass-through method)
    // ----
    
    void test_c_evolve () {
        Cell c;
        bool b[] = {0, 0, 0, 1, 0, 0, 0, 0};
        c.evolve(b);
        CPPUNIT_ASSERT(c.alive());}

    // ----
    // Cell::mutate (only one test since there is no complexity - if the
    //       method runs, only one thing can hapen)
    // ----
    
    void test_c_mutate () {
        Cell c = new FredkinCell(true);
        AbstractCell* p = c._p;
        std::ostringstream oss;
        c.mutate();
        c.write(oss);
        CPPUNIT_ASSERT(c._p->_alive);
        CPPUNIT_ASSERT(oss.str() == "*");
        CPPUNIT_ASSERT(c._p != p);}
        
    // ----
    // Life::print
    // ----
    
    void test_l_print_1 () {
        std::ostringstream oss;
        std::istringstream iss("3\n3\n.*.\n.*.\n.*.");
        Life<ConwayCell> l(iss);
        l.print(oss);
        CPPUNIT_ASSERT(oss.str() == "\nGeneration = 0, Population = 3.\n.*.\n.*.\n.*.\n");}

    void test_l_print_2 () {
        std::ostringstream oss;
        std::istringstream iss("3\n3\n---\n-5-\n-+-");
        Life<FredkinCell> l(iss);
        l.print(oss);
        CPPUNIT_ASSERT(oss.str() == "\nGeneration = 0, Population = 2.\n---\n-5-\n-+-\n");}

    void test_l_print_3 () {
        std::ostringstream oss;
        std::istringstream iss("3\n3\n---\n---\n---");
        Life<Cell> l(iss);
        l._gen = 2;
        l.print(oss);
        CPPUNIT_ASSERT(oss.str() == "\nGeneration = 2, Population = 0.\n---\n---\n---\n");}

    // ----
    // Life::turn
    // ----
    
    void test_l_turn_1 () {
        std::istringstream iss("3\n3\n...\n***\n..."); 
        Life<ConwayCell> l(iss);
        l.turn();
        CPPUNIT_ASSERT(l._board[0][1].alive());
        CPPUNIT_ASSERT(l._board[1][1].alive());
        CPPUNIT_ASSERT(l._board[2][1].alive());
        CPPUNIT_ASSERT(!(l._board[1][0].alive()));
        CPPUNIT_ASSERT(!(l._board[1][2].alive()));}

    void test_l_turn_2 () {
        std::istringstream iss("3\n3\n-0-\n---\n---");
        Life<FredkinCell> l(iss);
        l.turn();
        CPPUNIT_ASSERT(l._board[0][0].alive());
        CPPUNIT_ASSERT(l._board[0][2].alive());
        CPPUNIT_ASSERT(l._board[1][1].alive());
        CPPUNIT_ASSERT(!(l._board[0][1].alive()));
        CPPUNIT_ASSERT(l._board[0][0]._age == 0);}

    void test_l_turn_3 () {
        std::istringstream iss("3\n3\n000\n-0-\n---");
        Life<Cell> l(iss);
        l.turn();
        l.turn();
        CPPUNIT_ASSERT(l._board[0][0].alive());
        CPPUNIT_ASSERT(l._board[0][1].alive());
        CPPUNIT_ASSERT(l._board[0][2].alive());
        CPPUNIT_ASSERT(!(l._board[1][0].alive()));
        CPPUNIT_ASSERT(!(l._board[1][1].alive()));
        CPPUNIT_ASSERT(!(l._board[1][2].alive()));
        CPPUNIT_ASSERT(l._board[2][0].alive());
        CPPUNIT_ASSERT(l._board[2][1].alive());
        CPPUNIT_ASSERT(l._board[2][2].alive());}

    // ----
    // Life::run (only one test since there is no complexity - if the
    //       method runs, only one thing can hapen)
    // ----

    void test_l_run () {
        std::istringstream iss("3\n3\n...\n***\n..."); 
        Life<ConwayCell> l(iss);
        l.run(5);
        CPPUNIT_ASSERT(!(l._board[0][0].alive()));
        CPPUNIT_ASSERT(l._board[0][1].alive());
        CPPUNIT_ASSERT(!(l._board[0][2].alive()));
        CPPUNIT_ASSERT(!(l._board[1][0].alive()));
        CPPUNIT_ASSERT(l._board[1][1].alive());
        CPPUNIT_ASSERT(!(l._board[1][2].alive()));
        CPPUNIT_ASSERT(!(l._board[2][0].alive()));
        CPPUNIT_ASSERT(l._board[2][1].alive());
        CPPUNIT_ASSERT(!(l._board[2][2].alive()));}
    
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST(test_alive_1);
    CPPUNIT_TEST(test_alive_2);
    CPPUNIT_TEST(test_alive_3);
    CPPUNIT_TEST(test_clone_1);
    CPPUNIT_TEST(test_clone_2);
    CPPUNIT_TEST(test_clone_3);
    CPPUNIT_TEST(test_cc_read_1);
    CPPUNIT_TEST(test_cc_read_2);
    CPPUNIT_TEST(test_cc_read_3);
    CPPUNIT_TEST(test_cc_write_1);
    CPPUNIT_TEST(test_cc_write_2);
    CPPUNIT_TEST(test_cc_write_3);
    CPPUNIT_TEST(test_cc_evolve_1);
    CPPUNIT_TEST(test_cc_evolve_2);
    CPPUNIT_TEST(test_cc_evolve_3);
    CPPUNIT_TEST(test_fc_read_1);
    CPPUNIT_TEST(test_fc_read_2);
    CPPUNIT_TEST(test_fc_read_3);
    CPPUNIT_TEST(test_fc_write_1);
    CPPUNIT_TEST(test_fc_write_2);
    CPPUNIT_TEST(test_fc_write_3);
    CPPUNIT_TEST(test_fc_evolve_1);
    CPPUNIT_TEST(test_fc_evolve_2);
    CPPUNIT_TEST(test_fc_evolve_3);
    CPPUNIT_TEST(test_c_read);
    CPPUNIT_TEST(test_c_write);
    CPPUNIT_TEST(test_c_evolve);
    CPPUNIT_TEST(test_c_mutate);
    CPPUNIT_TEST(test_l_print_1);
    CPPUNIT_TEST(test_l_print_2);
    CPPUNIT_TEST(test_l_print_3);
    CPPUNIT_TEST(test_l_turn_1);
    CPPUNIT_TEST(test_l_turn_2);
    CPPUNIT_TEST(test_l_turn_3);
    CPPUNIT_TEST(test_l_run);
    CPPUNIT_TEST_SUITE_END();};

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

    cout << "Done." << endl;
    return 0;}