/* Faisal Ejaz (UTEID: fe2333 CSID: faisalej, 10AM section)
/  Zachary Sais (UTEID: zrs233 CSID: zrs233, 1PM section)
/  CS371P - Downing
/  Project Life
/  April 24 2013
*/

/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -pedantic -std=c++0x -Wall Darwin.c++ TestDarwin.c++ -o TestDarwin.c++.app -lcppunit -ldl
    % valgrind TestDarwin.c++.app >& TestDarwin.c++.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <vector>
#include <utility>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#define private   public
#define protected public
#define class     struct

#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Life.h"


// -----------
// TestDarwin
// -----------

struct TestLife: CppUnit::TestFixture {

    // Testing Constructors
    void test_ConwayCell_1(){
        ConwayCell cell('.');
        CPPUNIT_ASSERT(cell._type =='.');
    }

    void test_ConwayCell_2(){
        ConwayCell cell('*');
        CPPUNIT_ASSERT(cell._type =='*');
        CPPUNIT_ASSERT(cell._alive == true);
        CPPUNIT_ASSERT(cell._will_mutate == false);
    }

    void test_ConwayCell_3(){
        ConwayCell cell('*');
        CPPUNIT_ASSERT(cell._type =='*');
        CPPUNIT_ASSERT(cell._type == '*');
        CPPUNIT_ASSERT(cell._alive = true);
        CPPUNIT_ASSERT(cell._will_mutate == false);
    }

    
    // Testing willInvert
    void test_ConwayCell_4(){
        ConwayCell cell('.');

        CPPUNIT_ASSERT(cell._type =='.');
        CPPUNIT_ASSERT(cell._will_invert == false);

        cell.willInvert(3);

        CPPUNIT_ASSERT(cell._will_invert == true);
    }

    void test_ConwayCell_5(){
        ConwayCell cell('*');

        CPPUNIT_ASSERT(cell._type =='*');
        CPPUNIT_ASSERT(cell._will_invert == false);

        cell.willInvert(1);

        CPPUNIT_ASSERT(cell._will_invert == true);
    }

    void test_ConwayCell_6(){
        ConwayCell cell('*');

        CPPUNIT_ASSERT(cell._type =='*');
        CPPUNIT_ASSERT(cell._will_invert == false);

        cell.willInvert(3);
        CPPUNIT_ASSERT(cell._will_invert == false);
    }


    // Testing move
    void test_ConwayCell_7(){
        ConwayCell cell('.');
        CPPUNIT_ASSERT(cell.move() == 0);
    }    

    void test_ConwayCell_8(){
        ConwayCell cell('.');
        cell.willInvert(3);
        CPPUNIT_ASSERT(cell.move() == 1);
        CPPUNIT_ASSERT(cell._type == '*');
    }    

    void test_ConwayCell_9(){
        ConwayCell cell('*');
        cell.willInvert(1);
        CPPUNIT_ASSERT(cell.move() == -1);        
        CPPUNIT_ASSERT(cell._type == '.');
    } 


    // Testing FredkinCell Constructors
    void test_FredkinCell_1(){
        FredkinCell cell('0');
        CPPUNIT_ASSERT(cell._type =='0');
        CPPUNIT_ASSERT(cell._age == 0);       
        CPPUNIT_ASSERT(cell._alive == true);

    }

    void test_FredkinCell_2(){
        FredkinCell cell('-');
        CPPUNIT_ASSERT(cell._type =='-');
        CPPUNIT_ASSERT(cell._alive == false);
        CPPUNIT_ASSERT(cell._will_mutate == false);
    }

    void test_FredkinCell_3(){
        FredkinCell cell('0');
        CPPUNIT_ASSERT(cell._type =='0');
        CPPUNIT_ASSERT(cell._alive = true);
        CPPUNIT_ASSERT(cell._will_mutate == false);
    }

    
    // Testing willInvert
    void test_FredkinCell_4(){
        FredkinCell cell('-');

        CPPUNIT_ASSERT(cell._type =='-');
        CPPUNIT_ASSERT(cell._will_invert == false);
        cell.willInvert(1);
        CPPUNIT_ASSERT(cell._will_invert == true);
    }

    void test_FredkinCell_5(){
        FredkinCell cell('0');
        CPPUNIT_ASSERT(cell._will_invert == false);
        cell.willInvert(0);
        CPPUNIT_ASSERT(cell._will_invert == true);
    }

    void test_FredkinCell_6(){
        FredkinCell cell('0');
        CPPUNIT_ASSERT(cell._type =='0');
        CPPUNIT_ASSERT(cell._will_invert == false);
        cell.willInvert(3);
        CPPUNIT_ASSERT(cell._will_invert == false);
    }


    // Testing move
    void test_FredkinCell_7(){
        FredkinCell cell('.');
        CPPUNIT_ASSERT(cell.move() == 0);
    }    

    void test_FredkinCell_8(){
        FredkinCell cell('0');
        cell.willInvert(0);
        CPPUNIT_ASSERT(cell.move() == -1);
        CPPUNIT_ASSERT(cell._age == 0);
        CPPUNIT_ASSERT(cell._type == '-');
    }    

    void test_FredkinCell_9(){
        FredkinCell cell('-');
        cell.willInvert(1);
        CPPUNIT_ASSERT(cell.move() == 1);        
        CPPUNIT_ASSERT(cell._type == '0');
    }  


    // Testing Cell Constructors
    void test_Cell_1(){
        Cell cell = new ConwayCell('.');
        CPPUNIT_ASSERT(cell.get()->_type =='.');     
        CPPUNIT_ASSERT(cell.get()->_alive == false);

    }

    void test_Cell_2(){
        Cell cell = new ConwayCell('*');
        CPPUNIT_ASSERT(cell.get()->_type =='*');     
        CPPUNIT_ASSERT(cell.get()->_alive == true);
    }

    void test_Cell_3(){
        Cell cell = new FredkinCell('0');
        CPPUNIT_ASSERT(cell.get()->_type =='0');     
        CPPUNIT_ASSERT(cell.get()->_alive == true);
    }

    void test_Cell_4(){
        Cell cell = new FredkinCell('-');
        CPPUNIT_ASSERT(cell.get()->_type =='-');     
        CPPUNIT_ASSERT(cell.get()->_alive == false);
    }

    // Testing isAlive()
    void test_Cell_5(){
        Cell cell = new ConwayCell('.');
        CPPUNIT_ASSERT(cell.isAlive() == false);      
    }

    void test_Cell_6(){
        Cell cell = new FredkinCell('0');
        CPPUNIT_ASSERT(cell.isAlive() == true);      
    }

    void test_Cell_7(){
        Cell cell = new FredkinCell('-');
        CPPUNIT_ASSERT(cell.isAlive() == false);      
    }

    // Testing printStatus()
    void test_Cell_8(){
        Cell cell = new ConwayCell('.');
        CPPUNIT_ASSERT(cell.printStatus() == '.');      
    }

    void test_Cell_9(){
        Cell cell = new FredkinCell('0');
        CPPUNIT_ASSERT(cell.printStatus() == '0');      
    }

    void test_Cell_10(){
        Cell cell = new FredkinCell('-');
        CPPUNIT_ASSERT(cell.printStatus() == '-');      
    }

    // Testing willInvert()
    void test_Cell_11(){
        Cell cell = new ConwayCell('*');
        cell.willInvert(1);
        CPPUNIT_ASSERT(cell.get()->_will_invert == true);   
    }

    void test_Cell_12(){
        Cell cell = new FredkinCell('0');
        cell.willInvert(2);
        CPPUNIT_ASSERT(cell.get()->_will_invert == true);     
    }

    void test_Cell_13(){
        Cell cell = new FredkinCell('-');
        cell.willInvert(1);
        CPPUNIT_ASSERT(cell.get()->_will_invert == true);   
    }

    // Test move
    void test_Cell_14(){
        Cell cell = new ConwayCell('.');
        CPPUNIT_ASSERT(cell.move() == 0);       
    }

    void test_Cell_15(){
        Cell cell = new ConwayCell('*');
        cell.willInvert(1);
        CPPUNIT_ASSERT(cell.move() == -1);        
        CPPUNIT_ASSERT(cell.get()->_type == '.');        
    }

    void test_Cell_16(){
        Cell cell = new FredkinCell('-');
        cell.willInvert(1);
        CPPUNIT_ASSERT(cell.move() == 1);        
        CPPUNIT_ASSERT(cell.get()->_type == '0');
    }

    // Test mutate
    void test_Cell_17(){
        Cell cell = new FredkinCell('-');
        cell.mutate();
        CPPUNIT_ASSERT(cell.get()->_type == '*');
    }
 
    void test_Cell_18(){
        Cell cell = new FredkinCell('0');
        cell.willInvert(1);
        cell.move();
        CPPUNIT_ASSERT(cell.get()->_type == '1');
        cell.mutate();
        CPPUNIT_ASSERT(cell.get()->_type == '*');
    }

    void test_Cell_19(){
        Cell cell = new FredkinCell('0');
        cell.willInvert(2);
        cell.move();
        CPPUNIT_ASSERT(cell.get()->_type == '-');
        cell.mutate();
        CPPUNIT_ASSERT(cell.get()->_type == '*');
    }

    // Test Constructor
    void test_Life_1(){
        Life<ConwayCell> life;
        CPPUNIT_ASSERT(life._population == 0);
    }

    void test_Life_2(){
        Life<ConwayCell> life;
        CPPUNIT_ASSERT(life._generation == 0);
    }

    // Test read with filename
    void test_Life_3(){
        Life<ConwayCell> life;
        life.read("RunLifeConway.in");

        CPPUNIT_ASSERT(life._height == 109);
        CPPUNIT_ASSERT(life._width == 69);
    }

    void test_Life_4(){
        Life<FredkinCell> life;
        life.read("RunLifeFredkin.in");

        CPPUNIT_ASSERT(life._population == 4);
    }

    void test_Life_5(){
        Life<Cell> life;
        life.read("RunLifeCell.in");
        CPPUNIT_ASSERT(life._population == 6);
    }

     void test_Life_6(){
        Life<ConwayCell> life;
        life.read("RunLifeConway.in");
        CPPUNIT_ASSERT(life._height == 109);
        CPPUNIT_ASSERT(life._width == 69);
        CPPUNIT_ASSERT(life._population == 35);
    }

    // testing read with stringstream
    void test_Life_7(){
        Life <FredkinCell> life;
        string grid = "9\n9\n0-------0\n-0-----0-\n--0---0--\n---0-0---\n----0----\n---0-0---\n--0---0--\n-0-----0-\n0-------0\n";
        stringstream s_stream;
        s_stream << grid;
        life.read(s_stream);
        CPPUNIT_ASSERT(life._height == 9);
        CPPUNIT_ASSERT(life._width == 9);
        CPPUNIT_ASSERT(life._population == 17);
    }


    void test_Life_8(){
        Life <Cell> life;
        string grid = "2\n2\n00\n-0\n";
        stringstream s_stream;
        s_stream << grid;
        life.read(s_stream);
        CPPUNIT_ASSERT(life._height == 2);
        CPPUNIT_ASSERT(life._width == 2);
        CPPUNIT_ASSERT(life._population == 3);
    }

    void test_Life_9(){
        Life<FredkinCell> life;
        string grid = "20\n20\n--------------------\n-000000000000000000-\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n-000000000000000000-\n--------------------\n";
        stringstream s_stream;
        s_stream << grid;
        life.read(s_stream);
        CPPUNIT_ASSERT(life._height == 20);
        CPPUNIT_ASSERT(life._width == 20);
        CPPUNIT_ASSERT(life._population == 36);
    }

    // testing do_turn()
    void test_Life_10(){
        Life<Cell> life;
        string grid = "2\n2\n00\n-0\n";
        stringstream s_stream;
        s_stream << grid;
        life.read(s_stream);  
        life.doTurn();
        CPPUNIT_ASSERT(life._population == 2); 
    }    

    void test_Life_11(){
        Life<Cell> life;
        string grid = "8\n10\n----------\n-00000000-\n-00-00-00-\n-00-00-00-\n-00000000-\n-0--0-0-0-\n-0--0-0-0-\n----------\n";
        stringstream s_stream;
        s_stream << grid;
        life.read(s_stream);
        CPPUNIT_ASSERT(life._population == 36);        
        CPPUNIT_ASSERT(life._generation == 0);

        life.doTurn();
        life.doTurn();

        CPPUNIT_ASSERT(life._population == 38); 
    }   

    void test_Life_12(){
        Life<Cell> life;
        string grid = "20\n20\n--------------------\n-000000000000000000-\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n--------------------\n-000000000000000000-\n--------------------\n";
        stringstream s_stream;
        s_stream << grid;
        life.read(s_stream);
        CPPUNIT_ASSERT(life._population == 36);        
        CPPUNIT_ASSERT(life._generation == 0);

        life.doTurn();
        life.doTurn();
        life.doTurn();
        life.doTurn();
        life.doTurn();

        CPPUNIT_ASSERT(life._generation == 5);
        CPPUNIT_ASSERT(life._population == 152); 
    }   

    // Testing findNeighbors()
    void test_Life_13(){
        Life<Cell> life;
        string grid = "8\n10\n----------\n-00000000-\n-00-00-00-\n-00-00-00-\n-00000000-\n-0--0-0-0-\n-0--0-0-0-\n----------\n";
        stringstream s_stream;
        s_stream << grid;
        life.read(s_stream);

        CPPUNIT_ASSERT(life.findNeighbors(0,0) == 0);        
    }   

    void test_Life_14(){
        Life<Cell> life;
        string grid = "2\n2\n00\n-0\n";
        stringstream s_stream;
        s_stream << grid;
        life.read(s_stream);

        life.doTurn();
        CPPUNIT_ASSERT(life.findNeighbors(1,1) == 0);        
    }

    void test_Life_15(){
        Life<ConwayCell> life;
        string grid = "6\n4\n....\n....\n***.\n.***\n....\n....\n";
        stringstream s_stream;
        s_stream << grid;
        life.read(s_stream);

        life.doTurn();
        life.doTurn();
        life.doTurn();
        life.doTurn();

        CPPUNIT_ASSERT(life._generation == 4); 
        CPPUNIT_ASSERT(life.findNeighbors(1,2) == 4);        
    }

    // testing addCell()
    void test_Life_16(){
        Life<ConwayCell> life;
        string grid = "2\n2\n..\n..\n";
        stringstream s_stream;
        s_stream << grid;
        life.read(s_stream);
        CPPUNIT_ASSERT(life.addCell(0,0, ConwayCell('*')) == true);
        CPPUNIT_ASSERT(life._grid[0][0]._type == '*');        
    }

    void test_Life_17(){
        Life<FredkinCell> life;
        string grid = "2\n2\n--\n--\n";
        stringstream s_stream;
        s_stream << grid;
        life.read(s_stream);
        CPPUNIT_ASSERT(life.addCell(0,0, FredkinCell('0')) == true);
        CPPUNIT_ASSERT(life.addCell(1,1, FredkinCell('-')) == false);
        CPPUNIT_ASSERT(life._grid[0][0]._type == '0');
        CPPUNIT_ASSERT(life._grid[1][1]._type == '-');        
        CPPUNIT_ASSERT(life._grid[1][0]._type == '-');                        
    }


    void test_Life_18(){
        Life<Cell> life;
        string grid = "8\n10\n----------\n-00000000-\n-00-00-00-\n-00-00-00-\n-00000000-\n-0--0-0-0-\n-0--0-0-0-\n----------\n";
        stringstream s_stream;
        s_stream << grid;
        life.read(s_stream);    
        CPPUNIT_ASSERT(life.addCell(0,5, new FredkinCell('0')) == true);
        CPPUNIT_ASSERT(life._grid[0][5].printStatus() == '0');   
    }

    // -----
    // suite
    // -----
     
    CPPUNIT_TEST_SUITE(TestLife);

    CPPUNIT_TEST(test_ConwayCell_1);
    CPPUNIT_TEST(test_ConwayCell_2);
    CPPUNIT_TEST(test_ConwayCell_3);
    CPPUNIT_TEST(test_ConwayCell_4);
    CPPUNIT_TEST(test_ConwayCell_5);
    CPPUNIT_TEST(test_ConwayCell_6);
    CPPUNIT_TEST(test_ConwayCell_7);
    CPPUNIT_TEST(test_ConwayCell_8);
    CPPUNIT_TEST(test_ConwayCell_9);

    CPPUNIT_TEST(test_FredkinCell_1);
    CPPUNIT_TEST(test_FredkinCell_2);
    CPPUNIT_TEST(test_FredkinCell_3);
    CPPUNIT_TEST(test_FredkinCell_4);
    CPPUNIT_TEST(test_FredkinCell_5);
    CPPUNIT_TEST(test_FredkinCell_6);
    CPPUNIT_TEST(test_FredkinCell_7);
    CPPUNIT_TEST(test_FredkinCell_8);
    CPPUNIT_TEST(test_FredkinCell_9);


    CPPUNIT_TEST(test_Cell_1);
    CPPUNIT_TEST(test_Cell_2);
    CPPUNIT_TEST(test_Cell_3);
    CPPUNIT_TEST(test_Cell_4);
    CPPUNIT_TEST(test_Cell_5);
    CPPUNIT_TEST(test_Cell_6);
    CPPUNIT_TEST(test_Cell_7);
    CPPUNIT_TEST(test_Cell_8);
    CPPUNIT_TEST(test_Cell_9);
    CPPUNIT_TEST(test_Cell_10);
    CPPUNIT_TEST(test_Cell_11);
    CPPUNIT_TEST(test_Cell_12);
    CPPUNIT_TEST(test_Cell_13);
    CPPUNIT_TEST(test_Cell_14);
    CPPUNIT_TEST(test_Cell_15);
    CPPUNIT_TEST(test_Cell_16);
    CPPUNIT_TEST(test_Cell_17);
    CPPUNIT_TEST(test_Cell_18);
    CPPUNIT_TEST(test_Cell_19);

    CPPUNIT_TEST(test_Life_1);
    CPPUNIT_TEST(test_Life_2);
    CPPUNIT_TEST(test_Life_3);
    CPPUNIT_TEST(test_Life_4);
    CPPUNIT_TEST(test_Life_5);
    CPPUNIT_TEST(test_Life_6);
    CPPUNIT_TEST(test_Life_7);
    CPPUNIT_TEST(test_Life_8);
    CPPUNIT_TEST(test_Life_9);
    CPPUNIT_TEST(test_Life_10);
    CPPUNIT_TEST(test_Life_11);
    CPPUNIT_TEST(test_Life_12);
    CPPUNIT_TEST(test_Life_13);    
    CPPUNIT_TEST(test_Life_14);  
    CPPUNIT_TEST(test_Life_15);
    CPPUNIT_TEST(test_Life_16);
    CPPUNIT_TEST(test_Life_17);
    CPPUNIT_TEST(test_Life_18);

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

    cout << "Done." << endl;
    return 0;}