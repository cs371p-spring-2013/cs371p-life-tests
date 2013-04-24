// --------
// includes
// --------
#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TextTestRunner.h"

#include "Life.h"

#include <iostream>
#include <sstream>
#include <string> 

using namespace std;


// --------------
// TestConwayCell
// --------------
struct TestConwayCell : CppUnit::TestFixture
{
    // ------------
    // test_isAlive
    // ------------
    void test_isAlive_1 ()
    {
        ConwayCell c = ConwayCell (true);
        CPPUNIT_ASSERT(c.isAlive());
    }
    
    void test_isAlive_2 ()
    {
        ConwayCell c = ConwayCell (false);
        CPPUNIT_ASSERT(!c.isAlive());
    }
    
    void test_isAlive_3 ()
    {
        ConwayCell c = ConwayCell (true);
        CPPUNIT_ASSERT(c.isAlive());
        
        c = ConwayCell (false);
        CPPUNIT_ASSERT(!c.isAlive());
    }
    
    
    // -------------
    // test_isConway
    // -------------
    void test_isConway ()
    {
        ConwayCell c = ConwayCell (true);
        CPPUNIT_ASSERT(c.isConway());
    }
    
    
    // -----------
    // test_evolve
    // -----------
    void test_evolve_1 ()
    {
        ConwayCell c = ConwayCell (true);
        CPPUNIT_ASSERT(c.isAlive());
        
        CPPUNIT_ASSERT(!c.evolve (2));
        CPPUNIT_ASSERT(c.isAlive());
        
        CPPUNIT_ASSERT(!c.evolve (3));
        CPPUNIT_ASSERT(c.isAlive());
    }
    
    void test_evolve_2 ()
    {
        ConwayCell c = ConwayCell (true);
        CPPUNIT_ASSERT(c.isAlive());
        
        CPPUNIT_ASSERT(!c.evolve (4));
        CPPUNIT_ASSERT(!c.isAlive());
        
        c = ConwayCell (true);
        CPPUNIT_ASSERT(c.isAlive());
        
        CPPUNIT_ASSERT(!c.evolve (1));
        CPPUNIT_ASSERT(!c.isAlive());
    }
    
    void test_evolve_3 ()
    {
        ConwayCell c = ConwayCell (false);
        CPPUNIT_ASSERT(!c.isAlive());
        
        CPPUNIT_ASSERT(!c.evolve (2));
        CPPUNIT_ASSERT(!c.isAlive());
        
        CPPUNIT_ASSERT(!c.evolve (4));
        CPPUNIT_ASSERT(!c.isAlive());
    }
    
    void test_evolve_4 ()
    {
        ConwayCell c = ConwayCell (false);
        CPPUNIT_ASSERT(!c.isAlive());
        
        CPPUNIT_ASSERT(!c.evolve (3));
        CPPUNIT_ASSERT(c.isAlive());
    }
    
    
    // ----------
    // test_print
    // ----------
    void test_print_1 ()
    {
        ostringstream w;
        ConwayCell c = ConwayCell (true);
        c.print (w);
        CPPUNIT_ASSERT(w.str() == "*");
    }
    
    void test_print_2 ()
    {
        ostringstream w;
        ConwayCell c = ConwayCell (false);
        c.print (w);
        CPPUNIT_ASSERT(w.str() == ".");
    }
    
    void test_print_3 ()
    {
        ostringstream w;
        ConwayCell c = ConwayCell (true);
        c.evolve (4);
        c.print (w);
        CPPUNIT_ASSERT(w.str() == ".");
    }
    
    
    CPPUNIT_TEST_SUITE(TestConwayCell);
    CPPUNIT_TEST(test_isAlive_1);
    CPPUNIT_TEST(test_isAlive_2);
    CPPUNIT_TEST(test_isAlive_3);
    CPPUNIT_TEST(test_isConway);
    CPPUNIT_TEST(test_evolve_1);
    CPPUNIT_TEST(test_evolve_2);
    CPPUNIT_TEST(test_evolve_3);
    CPPUNIT_TEST(test_evolve_4);
    CPPUNIT_TEST(test_print_1);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_print_3);
    CPPUNIT_TEST_SUITE_END();
};


// ---------------
// TestFredkinCell
// ---------------
struct TestFredkinCell : CppUnit::TestFixture
{
    // ------------
    // test_isAlive
    // ------------
    void test_isAlive_1 ()
    {
        FredkinCell f = FredkinCell (true);
        CPPUNIT_ASSERT(f.isAlive());
    }
    
    void test_isAlive_2 ()
    {
        FredkinCell f = FredkinCell (false);
        CPPUNIT_ASSERT(!f.isAlive());
    }
    
    void test_isAlive_3 ()
    {
        FredkinCell f = FredkinCell (true);
        CPPUNIT_ASSERT(f.isAlive());
        
        f = FredkinCell (false);
        CPPUNIT_ASSERT(!f.isAlive());
    }
    
    
    // -------------
    // test_isConway
    // -------------
    void test_isConway ()
    {
        FredkinCell c = FredkinCell (true);
        CPPUNIT_ASSERT(!c.isConway());
    }
    
    
    // -----------
    // test_evolve
    // -----------
    void test_evolve_1 ()
    {
        FredkinCell f = FredkinCell (true);
        CPPUNIT_ASSERT(f.isAlive());
        
        CPPUNIT_ASSERT(!f.evolve (1));
        CPPUNIT_ASSERT(f.isAlive());
        
        CPPUNIT_ASSERT(f.evolve (3));
        CPPUNIT_ASSERT(f.isAlive());
    }
    
    void test_evolve_2 ()
    {
        FredkinCell f = FredkinCell (true);
        CPPUNIT_ASSERT(f.isAlive());
        
        CPPUNIT_ASSERT(!f.evolve (0));
        CPPUNIT_ASSERT(!f.isAlive());
        
        f = FredkinCell (true);
        CPPUNIT_ASSERT(f.isAlive());
        
        CPPUNIT_ASSERT(!f.evolve (2));
        CPPUNIT_ASSERT(!f.isAlive());
        
        f = FredkinCell (true);
        CPPUNIT_ASSERT(f.isAlive());
        
        CPPUNIT_ASSERT(!f.evolve (4));
        CPPUNIT_ASSERT(!f.isAlive());
    }
    
    void test_evolve_3 ()
    {
        FredkinCell f = FredkinCell (false);
        CPPUNIT_ASSERT(!f.isAlive());
        
        CPPUNIT_ASSERT(!f.evolve (0));
        CPPUNIT_ASSERT(!f.isAlive());
        
        CPPUNIT_ASSERT(!f.evolve (2));
        CPPUNIT_ASSERT(!f.isAlive());
        
        CPPUNIT_ASSERT(!f.evolve (4));
        CPPUNIT_ASSERT(!f.isAlive());
    }
    
    void test_evolve_4 ()
    {
        FredkinCell f = FredkinCell (false);
        CPPUNIT_ASSERT(!f.isAlive());
        
        CPPUNIT_ASSERT(!f.evolve (1));
        CPPUNIT_ASSERT(f.isAlive());
        
        f = FredkinCell (false);
        CPPUNIT_ASSERT(!f.isAlive());
        
        CPPUNIT_ASSERT(!f.evolve (3));
        CPPUNIT_ASSERT(f.isAlive());
    }
    
    
    // ----------
    // test_print
    // ----------
    void test_print_1 ()
    {
        ostringstream w;
        FredkinCell f = FredkinCell (true);
        f.print (w);
        CPPUNIT_ASSERT(w.str() == "0");
    }
    
    void test_print_2 ()
    {
        ostringstream w;
        FredkinCell f = FredkinCell (true);
        int i;
        for (i = 0; i < 12; ++i)
        {
            f.evolve (1);
        }
        f.print (w);
        CPPUNIT_ASSERT(w.str() == "+");
    }
    
    void test_print_3 ()
    {
        ostringstream w;
        FredkinCell f = FredkinCell (false);
        f.print (w);
        CPPUNIT_ASSERT(w.str() == "-");
    }
    
    CPPUNIT_TEST_SUITE(TestFredkinCell);
    CPPUNIT_TEST(test_isAlive_1);
    CPPUNIT_TEST(test_isAlive_2);
    CPPUNIT_TEST(test_isAlive_3);
    CPPUNIT_TEST(test_isConway);
    CPPUNIT_TEST(test_evolve_1);
    CPPUNIT_TEST(test_evolve_2);
    CPPUNIT_TEST(test_evolve_3);
    CPPUNIT_TEST(test_evolve_4);
    CPPUNIT_TEST(test_print_1);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_print_3);
    CPPUNIT_TEST_SUITE_END();
};


// --------
// TestCell
// --------
struct TestCell : CppUnit::TestFixture
{
    // ------------
    // test_isAlive
    // ------------
    void test_isAlive_1 ()
    {
        Cell c = new ConwayCell (true);
        CPPUNIT_ASSERT(c.isAlive()); 
    }
    
    void test_isAlive_2 ()
    {
        Cell c = new FredkinCell (true);
        CPPUNIT_ASSERT(c.isAlive());
    }
    
    void test_isAlive_3 ()
    {
        Cell c = new ConwayCell (false);
        CPPUNIT_ASSERT(!c.isAlive());
    }
    
    
    // -------------
    // test_isConway
    // -------------
    void test_isConway_1 ()
    {
        Cell c = new FredkinCell (true);
        CPPUNIT_ASSERT(!c.isConway());
    }
    
    void test_isConway_2 ()
    {
        Cell c = new ConwayCell (true);
        CPPUNIT_ASSERT(c.isConway());
    }
    
    
    // -----------
    // test_evolve
    // -----------
    void test_evolve_1 ()
    {
        Cell c = new ConwayCell (true);
        CPPUNIT_ASSERT(c.isAlive());
        CPPUNIT_ASSERT(!c.evolve (2));
        CPPUNIT_ASSERT(c.isAlive());
    }
    
    void test_evolve_2 ()
    {
        Cell c = new FredkinCell (true);
        CPPUNIT_ASSERT(c.isAlive());
        CPPUNIT_ASSERT(!c.evolve (2));
        CPPUNIT_ASSERT(!c.isAlive());
    }
    
    void test_evolve_3 ()
    {
        Cell c = new ConwayCell (false);
        CPPUNIT_ASSERT(!c.isAlive());
        CPPUNIT_ASSERT(!c.evolve (3));
        CPPUNIT_ASSERT(c.isAlive());
    }

    void test_evolve_4 ()
    {
        Cell c = new FredkinCell (false);
        CPPUNIT_ASSERT(!c.isAlive());
        CPPUNIT_ASSERT(!c.evolve (3));
        CPPUNIT_ASSERT(c.isAlive());
    }
    
    
    // ----------
    // test_print
    // ----------
    void test_print_1 ()
    {
        ostringstream w;
        Cell c = new ConwayCell (true);
        c.print (w);
        CPPUNIT_ASSERT(w.str() == "*");
    }

    void test_print_2 ()
    {
        ostringstream w;
        Cell c = new FredkinCell (true);
        int i;
        for (i = 0; i < 12; ++i)
        {
            c.evolve (1);
        }
        c.print (w);
        CPPUNIT_ASSERT(w.str() == "+");
    }

    void test_print_3 ()
    {
        ostringstream w;
        Cell c = new FredkinCell (false);
        c.print (w);
        CPPUNIT_ASSERT(w.str() == "-");
    }
    
    
    CPPUNIT_TEST_SUITE(TestCell);
    CPPUNIT_TEST(test_isAlive_1);
    CPPUNIT_TEST(test_isAlive_2);
    CPPUNIT_TEST(test_isAlive_3);
    CPPUNIT_TEST(test_isConway_1);
    CPPUNIT_TEST(test_isConway_2);
    CPPUNIT_TEST(test_evolve_1);
    CPPUNIT_TEST(test_evolve_2);
    CPPUNIT_TEST(test_evolve_3);
    CPPUNIT_TEST(test_evolve_4);
    CPPUNIT_TEST(test_print_1);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_print_3);
    CPPUNIT_TEST_SUITE_END();
};   


// --------
// TestLife
// --------
struct TestLife : CppUnit::TestFixture
{
    // ---------------
    // count_neighbors
    // ---------------
    void test_count_neighbors_1 ()
    {
        istringstream r ("3\n3\n000\n0-0\n000\n");
        Life <Cell> l = Life <Cell> (r, true);
        CPPUNIT_ASSERT(l.count_neighbors (0, 0) == 2);
        CPPUNIT_ASSERT(l.count_neighbors (0, 1) == 2);
        CPPUNIT_ASSERT(l.count_neighbors (0, 2) == 2);
        CPPUNIT_ASSERT(l.count_neighbors (1, 0) == 2);
        CPPUNIT_ASSERT(l.count_neighbors (1, 1) == 4);
        CPPUNIT_ASSERT(l.count_neighbors (1, 2) == 2);
        CPPUNIT_ASSERT(l.count_neighbors (2, 0) == 2);
        CPPUNIT_ASSERT(l.count_neighbors (2, 1) == 2);
        CPPUNIT_ASSERT(l.count_neighbors (2, 2) == 2);
    }
    
    void test_count_neighbors_2 ()
    {
        istringstream r ("3\n3\n***\n*.*\n***\n");
        Life <ConwayCell> l = Life <ConwayCell> (r, false);
        CPPUNIT_ASSERT(l.count_neighbors (0, 0) == 2);
        CPPUNIT_ASSERT(l.count_neighbors (0, 1) == 4);
        CPPUNIT_ASSERT(l.count_neighbors (0, 2) == 2);
        CPPUNIT_ASSERT(l.count_neighbors (1, 0) == 4);
        CPPUNIT_ASSERT(l.count_neighbors (1, 1) == 8);
        CPPUNIT_ASSERT(l.count_neighbors (1, 2) == 4);
        CPPUNIT_ASSERT(l.count_neighbors (2, 0) == 2);
        CPPUNIT_ASSERT(l.count_neighbors (2, 1) == 4);
        CPPUNIT_ASSERT(l.count_neighbors (2, 2) == 2);
    }
    
    void test_count_neighbors_3 ()
    {
        istringstream r ("3\n3\n-0-\n0-0\n-0-\n");
        Life <FredkinCell> l = Life <FredkinCell> (r, false);
        CPPUNIT_ASSERT(l.count_neighbors (0, 0) == 2);
        CPPUNIT_ASSERT(l.count_neighbors (0, 1) == 0);
        CPPUNIT_ASSERT(l.count_neighbors (0, 2) == 2);
        CPPUNIT_ASSERT(l.count_neighbors (1, 0) == 0);
        CPPUNIT_ASSERT(l.count_neighbors (1, 1) == 4);
        CPPUNIT_ASSERT(l.count_neighbors (1, 2) == 0);
        CPPUNIT_ASSERT(l.count_neighbors (2, 0) == 2);
        CPPUNIT_ASSERT(l.count_neighbors (2, 1) == 0);
        CPPUNIT_ASSERT(l.count_neighbors (2, 2) == 2);
    }
    
    
    // -----------
    // test_evolve
    // -----------
    void test_evolve_1 ()
    {
        istringstream r ("3\n3\n...\n***\n...\n");
        ostringstream w;
        
        Life <ConwayCell> l = Life <ConwayCell> (r, false);
        l.evolve (1);
        l.print(w);
        
        CPPUNIT_ASSERT(w.str () == "Generation = 1, Population = 3.\n.*.\n.*.\n.*.\n\n");
    }
    
    void test_evolve_2 ()
    {
        istringstream r ("5\n5\n-----\n-000-\n-0-0-\n-000-\n-----\n");
        ostringstream w;
        
        Life <FredkinCell> l = Life <FredkinCell> (r, false);
        l.evolve (5);
        l.print(w);
        
        CPPUNIT_ASSERT(w.str () == "Generation = 5, Population = 4.\n--0--\n-----\n0---0\n-----\n--0--\n\n");
    }
    
    void test_evolve_3 ()
    {
        istringstream r ("4\n4\n----\n-00-\n-00-\n----\n");
        ostringstream w;
        
        Life <Cell> l = Life <Cell> (r, true);
        l.evolve (5);
        l.print(w);
        
        CPPUNIT_ASSERT(w.str () == "Generation = 5, Population = 8.\n-**-\n*--*\n*--*\n-**-\n\n");
    }
    
    
    // ----------
    // test_print
    // ----------
    void test_print_1 ()
    {
        istringstream r ("3\n3\n000\n---\n-0-\n");
        ostringstream w;
        
        Life <Cell> l = Life <Cell> (r, true);
        l.print(w);
        
        CPPUNIT_ASSERT(w.str () == "Generation = 0, Population = 4.\n000\n---\n-0-\n\n");
    }
    
    void test_print_2 ()
    {
        istringstream r ("3\n5\n.....\n*****\n.....\n");
        ostringstream w;
        
        Life <ConwayCell> l = Life <ConwayCell> (r, false);
        l.print(w);
        
        CPPUNIT_ASSERT(w.str () == "Generation = 0, Population = 5.\n.....\n*****\n.....\n\n");
    }
    
    void test_print_3 ()
    {
        istringstream r ("4\n4\n0000\n0--0\n0--0\n0000\n");
        ostringstream w;
        
        Life <FredkinCell> l = Life <FredkinCell> (r, false);
        l.print(w);
        
        CPPUNIT_ASSERT(w.str () == "Generation = 0, Population = 12.\n0000\n0--0\n0--0\n0000\n\n");
    }
    
    
    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST(test_count_neighbors_1);
    CPPUNIT_TEST(test_count_neighbors_2);
    CPPUNIT_TEST(test_count_neighbors_3);
    CPPUNIT_TEST(test_evolve_1);
    CPPUNIT_TEST(test_evolve_2);
    CPPUNIT_TEST(test_evolve_3);
    CPPUNIT_TEST(test_print_1);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_print_3);
    CPPUNIT_TEST_SUITE_END();
};


int main ()
{
    ios_base::sync_with_stdio(false);
    
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
