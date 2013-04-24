// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringstream, ostringstream
#include <string>   // ==
#include <vector> //vector

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#define private public
#define protected public

#include "Cell.h"
#include "Life.h"
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Handle.h"

using namespace std;
// -----------
// TestLife
// -----------

struct TestLife : CppUnit::TestFixture {

    // test Conway constructor
    void test_conway_constructor_1(){
        ConwayCell c (true, CONWAY);
        CPPUNIT_ASSERT (c._state == true);
        CPPUNIT_ASSERT (c._type == CONWAY);
        CPPUNIT_ASSERT (c._symbol == '*');
    }

    void test_conway_constructor_2(){
        ConwayCell c (false, CONWAY);
        CPPUNIT_ASSERT (c._state == false);
        CPPUNIT_ASSERT (c._type == CONWAY);
        CPPUNIT_ASSERT (c._symbol == '.');
    }

    void test_conway_constructor_3(){
        try{
            ConwayCell c (true, FREDKIN);
            CPPUNIT_ASSERT(false);
        }
        catch(...){
            CPPUNIT_ASSERT(true);
        }
    }

    // test fredkin constructor
    void test_fredkin_constructor_1(){
        FredkinCell f (true, FREDKIN);
        CPPUNIT_ASSERT (f._state == true);
        CPPUNIT_ASSERT (f._type == FREDKIN);
        CPPUNIT_ASSERT (f._symbol == '0');
    }

    void test_fredkin_constructor_2(){
        FredkinCell f (false, FREDKIN);
        CPPUNIT_ASSERT (f._state == false);
        CPPUNIT_ASSERT (f._type == FREDKIN);
        CPPUNIT_ASSERT (f._symbol == '-');
    }

    void test_fredkin_constructor_3(){
        try{
            FredkinCell f (true, CONWAY);
            CPPUNIT_ASSERT(false);
        }
        catch(...){
            CPPUNIT_ASSERT(true);
        }
    }

    void test_cell_constructor_1(){
        Cell c = new ConwayCell(true, CONWAY);
        CPPUNIT_ASSERT (c._p->_state == true);
        CPPUNIT_ASSERT (c._p->_type == CONWAY);
        CPPUNIT_ASSERT (c._p->_symbol == '*');
    }

    void test_cell_constructor_2(){
        Cell c = new ConwayCell(false, CONWAY);
        CPPUNIT_ASSERT (c._p->_state == false);
        CPPUNIT_ASSERT (c._p->_type == CONWAY);
        CPPUNIT_ASSERT (c._p->_symbol == '.');
    }

    void test_cell_constructor_3(){
        Cell c = new FredkinCell(true, FREDKIN);
        CPPUNIT_ASSERT (c._p->_state == true);
        CPPUNIT_ASSERT (c._p->_type == FREDKIN);
        CPPUNIT_ASSERT (c._p->_symbol == '0');
    }

    void test_cell_constructor_4(){
        Cell c = new FredkinCell(false, FREDKIN);
        CPPUNIT_ASSERT (c._p->_state == false);
        CPPUNIT_ASSERT (c._p->_type == FREDKIN);
        CPPUNIT_ASSERT (c._p->_symbol == '-');
    }



    // test life print out
    void test_life_constructor_1(){
        istringstream s ("1\n1\n.");
        Life<ConwayCell> l (s);
        const Cell& c = l.mainBoard[0][0];
        CPPUNIT_ASSERT(c._p->_state == false);
        CPPUNIT_ASSERT(c._p->_type == CONWAY);
        CPPUNIT_ASSERT(c._p->_symbol == '.');
    }

    void test_life_constructor_2(){
        istringstream s ("3\n1\n.\n*\n.");
        Life<ConwayCell> l (s);
        const Cell& c1 = l.mainBoard[0][0];
        const Cell& c2 = l.mainBoard[1][0];
        const Cell& c3 = l.mainBoard[2][0];
        CPPUNIT_ASSERT(c1._p->_state == false);
        CPPUNIT_ASSERT(c1._p->_type == CONWAY);
        CPPUNIT_ASSERT(c1._p->_symbol == '.');

        CPPUNIT_ASSERT(c2._p->_state == true);
        CPPUNIT_ASSERT(c2._p->_type == CONWAY);
        CPPUNIT_ASSERT(c2._p->_symbol == '*');

        CPPUNIT_ASSERT(c3._p->_state == false);
        CPPUNIT_ASSERT(c3._p->_type == CONWAY);
        CPPUNIT_ASSERT(c3._p->_symbol == '.');
    }

    void test_life_constructor_3(){
        istringstream s ("1\n4\n.*-0");
        Life<Cell> l (s);
        const Cell& c1 = l.mainBoard[0][0];
        const Cell& c2 = l.mainBoard[0][1];
        const Cell& c3 = l.mainBoard[0][2];
        const Cell& c4 = l.mainBoard[0][3];
        CPPUNIT_ASSERT(c1._p->_state == false);
        CPPUNIT_ASSERT(c1._p->_type == CONWAY);
        CPPUNIT_ASSERT(c1._p->_symbol == '.');

        CPPUNIT_ASSERT(c2._p->_state == true);
        CPPUNIT_ASSERT(c2._p->_type == CONWAY);
        CPPUNIT_ASSERT(c2._p->_symbol == '*');

        CPPUNIT_ASSERT(c3._p->_state == false);
        CPPUNIT_ASSERT(c3._p->_type == FREDKIN);
        CPPUNIT_ASSERT(c3._p->_symbol == '-');

        CPPUNIT_ASSERT(c4._p->_state == true);
        CPPUNIT_ASSERT(c4._p->_type == FREDKIN);
        CPPUNIT_ASSERT(c4._p->_symbol == '0');
    }

    // test kill
    void test_kill_1(){
        ConwayCell c(true, CONWAY);
        CPPUNIT_ASSERT(c._state == true);
        c.kill();
        CPPUNIT_ASSERT(c._state == false);
    }

    void test_kill_2(){
        FredkinCell c(true, FREDKIN);
        CPPUNIT_ASSERT(c._state == true);
        c.kill();
        CPPUNIT_ASSERT(c._state == false);
    }

    void test_kill_3(){
        Cell c = new ConwayCell(true, CONWAY);
        CPPUNIT_ASSERT(c._p->_state == true);
        c.kill();
        CPPUNIT_ASSERT(c._p->_state == false);
    }

    // test reincarnate
    void test_reincarnate_1(){
        ConwayCell c(false, CONWAY);
        CPPUNIT_ASSERT(c._state == false);
        c.reincarnate();
        CPPUNIT_ASSERT(c._state == true);
    }

    void test_reincarnate_2(){
        FredkinCell c(false, FREDKIN);
        CPPUNIT_ASSERT(c._state == false);
        c.reincarnate();
        CPPUNIT_ASSERT(c._state == true);
    }

    void test_reincarnate_3(){
        Cell c = new ConwayCell(false, CONWAY);
        CPPUNIT_ASSERT(c._p->_state == false);
        c.reincarnate();
        CPPUNIT_ASSERT(c._p->_state == true);
    }

    // test isAlive
    void test_isalive_1(){
        ConwayCell c1 (false, CONWAY);
        CPPUNIT_ASSERT(!c1.isAlive());
        ConwayCell c2 (true, CONWAY);
        CPPUNIT_ASSERT(c2.isAlive());
    }

    void test_isalive_2(){
        FredkinCell f1 (false, FREDKIN);
        CPPUNIT_ASSERT(!f1.isAlive());
        FredkinCell f2 (true, FREDKIN);
        CPPUNIT_ASSERT(f2.isAlive());
    }

    void test_isalive_3(){
        Cell c1 = new ConwayCell(false, CONWAY);
        CPPUNIT_ASSERT(!c1.isAlive());
        Cell c2 = new ConwayCell(true, CONWAY);
        CPPUNIT_ASSERT(c2.isAlive());
    }

    void test_isalive_4(){
        Cell f1 = new FredkinCell(false, FREDKIN);
        CPPUNIT_ASSERT(!f1.isAlive());
        Cell f2 = new FredkinCell(true, FREDKIN);
        CPPUNIT_ASSERT(f2.isAlive());
    }

    void test_check_1(){
        istringstream s ("3\n3\n...\n...\n...");
        Life<ConwayCell> l (s);
        Cell& c = l.mainBoard[1][1];
        int numNeigh = l.check(c, 1, 1);
        CPPUNIT_ASSERT(numNeigh == 0);
    }

    void test_check_2(){
        istringstream s ("3\n3\n***\n*.*\n***");
        Life<ConwayCell> l (s);
        Cell& c = l.mainBoard[1][1];
        int numNeigh = l.check(c, 1, 1);
        CPPUNIT_ASSERT(numNeigh == 8);
    }

    void test_check_3(){
        istringstream s ("3\n3\n.*.\n*.*\n*.*");
        Life<ConwayCell> l (s);
        Cell& c = l.mainBoard[1][1];
        int numNeigh = l.check(c, 1, 1);
        CPPUNIT_ASSERT(numNeigh == 5);
    }

    void test_check_4(){
        istringstream s ("3\n3\n.*.\n**.\n...");
        Life<ConwayCell> l (s);
        Cell& c = l.mainBoard[0][0];
        int numNeigh = l.check(c, 0, 0);
        CPPUNIT_ASSERT(numNeigh == 3);
    }
    void test_check_5(){
        istringstream s ("3\n3\n.*.\n.*.\n...");
        Life<ConwayCell> l (s);
        Cell& c = l.mainBoard[0][2];
        int numNeigh = l.check(c, 0, 2);
        CPPUNIT_ASSERT(numNeigh == 2);
    }

    void test_check_6(){
        istringstream s ("3\n3\n**.\n.*.\n**.");
        Life<ConwayCell> l (s);
        Cell& c = l.mainBoard[1][0];
        int numNeigh = l.check(c, 1, 0);
        CPPUNIT_ASSERT(numNeigh == 5);
    }

    void test_check_7(){
        istringstream s ("3\n3\n.*.\n.*.\n.*.");
        Life<ConwayCell> l (s);
        Cell& c = l.mainBoard[1][2];
        int numNeigh = l.check(c, 1, 2);
        CPPUNIT_ASSERT(numNeigh == 3);
    }

    void test_check_8(){
        istringstream s ("3\n3\n.*.\n...\n...");
        Life<ConwayCell> l (s);
        Cell& c = l.mainBoard[0][1];
        int numNeigh = l.check(c, 0, 1);
        CPPUNIT_ASSERT(numNeigh == 0);
    }

    void test_getAge_1(){
        FredkinCell f (true, FREDKIN);
        CPPUNIT_ASSERT(f._age == 0);
    }    

    void test_getAge_2(){
        FredkinCell f (true, FREDKIN);
        f._age++;
        CPPUNIT_ASSERT(f._age == 1);
    }    

    void test_getAge_3(){
        FredkinCell f (true, FREDKIN);
        f._age++;
        f._age++;
        CPPUNIT_ASSERT(f._age == 2);
    }

    void test_ageUp_1(){
        FredkinCell f (true, FREDKIN);
        CPPUNIT_ASSERT(f._age == 0);
        f.ageUp();
        CPPUNIT_ASSERT(f._age == 1);
    }

    void test_ageUp_2(){
        FredkinCell f (true, FREDKIN);
        CPPUNIT_ASSERT(f._age == 0);
        f.ageUp();
        f.ageUp();
        CPPUNIT_ASSERT(f._age == 2);
    }

    void test_ageUp_3(){
        FredkinCell f (true, FREDKIN);
        CPPUNIT_ASSERT(f._age == 0);
        f.ageUp();
        f.ageUp();
        f.ageUp();
        f.ageUp();
        f.ageUp();
        CPPUNIT_ASSERT(f._age == 5);
    }

    void test_getType_1(){
        ConwayCell c (true, CONWAY);
        CPPUNIT_ASSERT(c.getType() == CONWAY);
    }

    void test_getType_2(){
        FredkinCell f (true, FREDKIN);
        CPPUNIT_ASSERT(f.getType() == FREDKIN);
    }

    void test_getType_3(){
        Cell c = new ConwayCell(true, CONWAY);
        CPPUNIT_ASSERT(c.getType() == CONWAY);
    }

    void test_getRep_1(){
        ConwayCell c (false, CONWAY);
        CPPUNIT_ASSERT(c.getRep() == '.');
    }

    void test_getRep_2(){
        ConwayCell c (true, CONWAY);
        CPPUNIT_ASSERT(c.getRep() == '*');
    }

    void test_getRep_3(){
        FredkinCell c (false, FREDKIN);
        CPPUNIT_ASSERT(c.getRep() == '-');
    }


    // void test_run_life_1(){
    //     cout<<endl;
    //     cout<<endl;
    //     istringstream s ("5\n5\n*....\n.*...\n..*..\n...*.\n....*");
    //     Life<ConwayCell> l (s);
    //     l.runLife(5);

    // }

    // void test_run_life_2(){
    //     cout<<endl;
    //     cout<<endl;
    //     istringstream s ("5\n5\n.....\n...*.\n..**.\n.*...\n.....");
    //     Life<ConwayCell> l (s);
    //     l.runLife(5);
    // }

    // void test_run_life_3(){
    //     cout<<endl;
    //     cout<<endl;
    //     istringstream s ("6\n6\n000000\n------\n------\n------\n------\n000000");
    //     Life<FredkinCell> l (s);
    //     l.runLife(6);
    // }

    // void test_run_life_4(){
    //     cout<<endl;
    //     cout<<endl;
    //     istringstream s ("5\n5\n*....\n.*...\n..*..\n...*.\n....*");
    //     Life<Cell> l (s);
    //     l.runLife(6);
    // }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);
    
    // test conway constructor
    CPPUNIT_TEST(test_conway_constructor_1);
    CPPUNIT_TEST(test_conway_constructor_2);
    CPPUNIT_TEST(test_conway_constructor_3);

    // test fredkin constructor
    CPPUNIT_TEST(test_fredkin_constructor_1);
    CPPUNIT_TEST(test_fredkin_constructor_2);
    CPPUNIT_TEST(test_fredkin_constructor_3);

    // test cell constructor
    CPPUNIT_TEST(test_cell_constructor_1);
    CPPUNIT_TEST(test_cell_constructor_2);
    CPPUNIT_TEST(test_cell_constructor_3);
    CPPUNIT_TEST(test_cell_constructor_4);

    // test life consstructor
    CPPUNIT_TEST(test_life_constructor_1);
    CPPUNIT_TEST(test_life_constructor_2);
    CPPUNIT_TEST(test_life_constructor_3);

    // test kill
    CPPUNIT_TEST(test_kill_1);
    CPPUNIT_TEST(test_kill_2);
    CPPUNIT_TEST(test_kill_3);

    // test reincarnate
    CPPUNIT_TEST(test_reincarnate_1);
    CPPUNIT_TEST(test_reincarnate_2);
    CPPUNIT_TEST(test_reincarnate_3);

    // test isalive
    CPPUNIT_TEST(test_isalive_1);
    CPPUNIT_TEST(test_isalive_2);
    CPPUNIT_TEST(test_isalive_3);
    CPPUNIT_TEST(test_isalive_4);

    // test check
    CPPUNIT_TEST(test_check_1);
    CPPUNIT_TEST(test_check_2);
    CPPUNIT_TEST(test_check_3);
    CPPUNIT_TEST(test_check_4);
    CPPUNIT_TEST(test_check_5);
    CPPUNIT_TEST(test_check_6);
    CPPUNIT_TEST(test_check_7);
    CPPUNIT_TEST(test_check_8);

    // test get age
    CPPUNIT_TEST(test_getAge_1);
    CPPUNIT_TEST(test_getAge_2);
    CPPUNIT_TEST(test_getAge_3);

    // test age up
    CPPUNIT_TEST(test_ageUp_1);
    CPPUNIT_TEST(test_ageUp_2);
    CPPUNIT_TEST(test_ageUp_3);

    // test get type
    CPPUNIT_TEST(test_getType_1);
    CPPUNIT_TEST(test_getType_2);
    CPPUNIT_TEST(test_getType_3);

    CPPUNIT_TEST(test_getRep_1);
    CPPUNIT_TEST(test_getRep_2);
    CPPUNIT_TEST(test_getRep_3);

    //test runLife
    // CPPUNIT_TEST(test_run_life_1);
    // CPPUNIT_TEST(test_run_life_2);
    // CPPUNIT_TEST(test_run_life_3);
    // CPPUNIT_TEST(test_run_life_4);



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