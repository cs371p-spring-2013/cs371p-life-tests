// -----------------------------
// Thomas Torres
// tmtorres
// Paul Carroll
// pvc95
// -----------------------------

/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -pedantic -std=c++0x -Wall Life.c++ ConwayCell.c++ FredkinCell.c++ Cell.c++ TestLife.c++ -o TestAllocator -lcppunit -ldl
    % valgrind TestLife >& TestLife.out
*/

// --------
// includes
// --------

#include <algorithm> // count
#include <iostream>  // ios_base
#include <memory>    // allocator
#include <vector>
#include <sstream>
#include <string>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define private public
#define protected public

#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "AbstractCell.h"

// --------
// TestLife
// --------

struct TestLife : CppUnit::TestFixture {
    // --------
    // typedefs
    // --------
	typedef bool state;
	
//-------------------
// AbstractCell tests
//-------------------
	  
    // ------------------------
    // test_AbstractCell_update
    // ------------------------

    void test_AbstractCell_update_1(){
	ConwayCell c = ConwayCell(true);
	c.AbstractCell::update(false);
	CPPUNIT_ASSERT(c._s == false);
    }

    void test_AbstractCell_update_2(){
	ConwayCell c = ConwayCell(false);
	c.AbstractCell::update(true);
	CPPUNIT_ASSERT(c._s == true);
    }

    void test_AbstractCell_update_3(){
	ConwayCell c = ConwayCell(true);
	c.AbstractCell::update(true);
	CPPUNIT_ASSERT(c._s == true);
    }

    // ------------------------
    // test_AbstractCell_status
    // ------------------------

    void test_AbstractCell_status_1(){
	ConwayCell c = ConwayCell(true);
	CPPUNIT_ASSERT(c.AbstractCell::status());
    }

    void test_AbstractCell_status_2(){
	ConwayCell c = ConwayCell(false);
	CPPUNIT_ASSERT(!c.AbstractCell::status());
    }

    void test_AbstractCell_status_3(){
	ConwayCell c = ConwayCell(true);
	c.AbstractCell::update(false);
	CPPUNIT_ASSERT(!c.AbstractCell::status());
    }

//-----------------
// ConwayCell tests
//-----------------

	void test_ConwayCell_count_1(){
		ConwayCell c = ConwayCell(true);
		std::vector<state> b;
		for(int i = 0; i < 8; ++i)
			b.push_back(true);
		CPPUNIT_ASSERT(b.size() == 8);
		int n = c.count(b);
		CPPUNIT_ASSERT(n == 8);
	}

	void test_ConwayCell_count_2(){
		ConwayCell c = ConwayCell(true);
		std::vector<state> b;
		for(int i = 0; i < 8; ++i)
			b.push_back(false);
		CPPUNIT_ASSERT(b.size() == 8);
		int n = c.count(b);
		CPPUNIT_ASSERT(n == 0);
	}

	void test_ConwayCell_count_3(){
		ConwayCell c = ConwayCell(true);
		std::vector<state> b;
		for(int i = 0; i < 8; ++i){
			if(i % 2 == 0)
				b.push_back(true);
			else
				b.push_back(false);
		}
		CPPUNIT_ASSERT(b.size() == 8);
		int n = c.count(b);
		CPPUNIT_ASSERT(n == 4);
	}

	void test_ConwayCell_evolve_1(){
		ConwayCell c = ConwayCell(true);
		c.evolve(3);
		CPPUNIT_ASSERT(c._s);
	}

	void test_ConwayCell_evolve_2(){
		ConwayCell c = ConwayCell(false);
		c.evolve(1);
		CPPUNIT_ASSERT(c._s == 0);
	}

	void test_ConwayCell_evolve_3(){
		ConwayCell c = ConwayCell(true);
		c.evolve(1);
		CPPUNIT_ASSERT(c._s == 0);
	}

	void test_ConwayCell_evolve_4(){
		ConwayCell c = ConwayCell(false);
		c.evolve(3);
		CPPUNIT_ASSERT(c._s);
	}

	void test_ConwayCell_print_1(){
		ConwayCell c = ConwayCell(true);
        std::stringstream s;
		c.print(s);
        CPPUNIT_ASSERT(s.str() == "*");
	}

	void test_ConwayCell_print_2(){
		ConwayCell c = ConwayCell(false);
        std::stringstream s;
		c.print(s);
        CPPUNIT_ASSERT(s.str() == ".");
	}

	void test_ConwayCell_print_3(){
		ConwayCell c = ConwayCell(true);
        ConwayCell c2 = ConwayCell(false);
        std::stringstream s;
		c.print(s);
        c2.print(s);
        CPPUNIT_ASSERT(s.str() == "*.");
	}

	void test_ConwayCell_clone_1(){
		ConwayCell c = ConwayCell(true);
		ConwayCell* c2 = c.clone();
		CPPUNIT_ASSERT(c._s == c2->_s);
        delete c2;
	}

	void test_ConwayCell_clone_2(){
		ConwayCell c = ConwayCell(false);
		ConwayCell* c2 = c.clone();
		CPPUNIT_ASSERT(c._s == c2->_s);
        delete c2;
	}

	void test_ConwayCell_clone_3(){
		ConwayCell c = ConwayCell(true);
		ConwayCell* c2 = c.clone();
		CPPUNIT_ASSERT(c._s);
		c.evolve(0);
		CPPUNIT_ASSERT(!c._s);
		CPPUNIT_ASSERT(c2->_s);
		CPPUNIT_ASSERT(c._s != c2->_s);
        delete c2;
	}

//------------------
// FredkinCell tests
//------------------

	void test_FredkinCell_count_1(){
		FredkinCell c = FredkinCell(true);
        std::vector<state> b;
		for(int i = 0; i < 8; ++i)
			b.push_back(true);
		CPPUNIT_ASSERT(b.size() == 8);
		int n = c.count(b);
		CPPUNIT_ASSERT(n == 4);
	}

    void test_FredkinCell_count_2(){
		FredkinCell c = FredkinCell(true);
        std::vector<state> b;
		for(int i = 0; i < 8; ++i)
			b.push_back(false);
		CPPUNIT_ASSERT(b.size() == 8);
		int n = c.count(b);
		CPPUNIT_ASSERT(n == 0);
    }

    void test_FredkinCell_count_3(){
		FredkinCell c = FredkinCell(true);
        std::vector<state> b;
		for(int i = 0; i < 8; ++i){
			if(i % 2)
                b.push_back(true);
            else
                b.push_back(false);
        }
		CPPUNIT_ASSERT(b.size() == 8);
		int n = c.count(b);
		CPPUNIT_ASSERT(n == 2);
    }

	void test_FredkinCell_evolve_1(){
		FredkinCell c = FredkinCell(true);
		c.evolve(1);
		CPPUNIT_ASSERT(c._s);
	}

	void test_FredkinCell_evolve_2(){
		FredkinCell c = FredkinCell(true);
		c.evolve(0);
		CPPUNIT_ASSERT(c._s == 0);
    }

	void test_FredkinCell_evolve_3(){
		FredkinCell c = FredkinCell(false);
		c.evolve(1);
		CPPUNIT_ASSERT(c._s);
    }

	void test_FredkinCell_print_1(){
		FredkinCell c = FredkinCell(true);
        std::stringstream s;
		c.print(s);
        CPPUNIT_ASSERT(s.str() == "0");
	}

	void test_FredkinCell_print_2(){
		FredkinCell c = FredkinCell(false);
        std::stringstream s;
		c.print(s);
        CPPUNIT_ASSERT(s.str() == "-");
    }

	void test_FredkinCell_print_3(){
		FredkinCell c = FredkinCell(true);
		FredkinCell c2 = FredkinCell(false);
		FredkinCell c3 = FredkinCell(true);
        c3._a = 100;
        std::stringstream s;
		c.print(s);
		c2.print(s);
        c3.print(s);
        CPPUNIT_ASSERT(s.str() == "0-+");
    }

	void test_FredkinCell_clone_1(){
		FredkinCell c = FredkinCell(true);
		FredkinCell* c2 = c.clone();
		CPPUNIT_ASSERT(c._s == c2->_s);
        delete c2;
    }
	void test_FredkinCell_clone_2(){
		FredkinCell c = FredkinCell(false);
		FredkinCell* c2 = c.clone();
		CPPUNIT_ASSERT(c._s == 0);
		CPPUNIT_ASSERT(c2->_s == 0);
        delete c2;
    }
	void test_FredkinCell_clone_3(){
		FredkinCell c = FredkinCell(true);
		FredkinCell* c2 = c.clone();
    	CPPUNIT_ASSERT(c._s == c2->_s);
        c.evolve(0);
    	CPPUNIT_ASSERT(c._s == 0);
    	CPPUNIT_ASSERT(c2->_s);
        CPPUNIT_ASSERT(c._s != c2->_s);
        delete c2;
    }

	void test_FredkinCell_mutate_1(){
        FredkinCell c = FredkinCell(true);
        AbstractCell* c2 = c.mutate();
        CPPUNIT_ASSERT(dynamic_cast<ConwayCell*>(c2));
        delete c2;
    }
	void test_FredkinCell_mutate_2(){
        FredkinCell c = FredkinCell(false);
        AbstractCell* c2 = c.mutate();
        CPPUNIT_ASSERT(dynamic_cast<ConwayCell*>(c2));
        delete c2;
    }

	void test_FredkinCell_mutate_3(){
        FredkinCell c = FredkinCell(false);
        AbstractCell* c2 = c.mutate();
        CPPUNIT_ASSERT(!dynamic_cast<FredkinCell*>(c2));
        delete c2;
    }

//-----------
// Cell tests
//-----------

	void test_Cell_status_1(){
	    Cell c = new ConwayCell(true);
	    CPPUNIT_ASSERT(c.status());
	}

    void test_Cell_status_2(){
	    Cell c = new ConwayCell(false);
	    CPPUNIT_ASSERT(!c.status());
    }
    void test_Cell_status_3(){
	    Cell c = new FredkinCell(true);
	    CPPUNIT_ASSERT(c.status());
    }

	void test_Cell_count_1(){
		Cell c = new ConwayCell(true);
		std::vector<state> b;
		for(int i = 0; i < 8; ++i)
			b.push_back(true);
		CPPUNIT_ASSERT(b.size() == 8);
		int n = c.count(b);
		CPPUNIT_ASSERT(n == 8);
	}

    void test_Cell_count_2(){
		Cell c = new ConwayCell(true);
		std::vector<state> b;
		for(int i = 0; i < 8; ++i)
			b.push_back(false);
		CPPUNIT_ASSERT(b.size() == 8);
		int n = c.count(b);
		CPPUNIT_ASSERT(n == 0);
    }

    void test_Cell_count_3(){
		Cell c = new FredkinCell(true);
        std::vector<state> b;
		for(int i = 0; i < 8; ++i)
			b.push_back(true);
		CPPUNIT_ASSERT(b.size() == 8);
		int n = c.count(b);
		CPPUNIT_ASSERT(n == 4);
    }

	void test_Cell_evolve_1(){
		Cell c = new ConwayCell(true);
		c.evolve(3);
		CPPUNIT_ASSERT(c.status());
    }
	void test_Cell_evolve_2(){
		Cell c = new FredkinCell(true);
		c.evolve(1);
		CPPUNIT_ASSERT(c.status());
    }
	void test_Cell_evolve_3(){
		Cell c = new FredkinCell(true);
		c.evolve(0);
		CPPUNIT_ASSERT(c.status() == 0);
    }

	void test_Cell_print_1(){
		Cell c = new ConwayCell(true);
        std::stringstream s;
		c.print(s);
        CPPUNIT_ASSERT(s.str() == "*");
    }

	void test_Cell_print_2(){
		Cell c = new ConwayCell(false);
        std::stringstream s;
		c.print(s);
        CPPUNIT_ASSERT(s.str() == ".");
    }

	void test_Cell_print_3(){
		Cell c = new FredkinCell(true);
        std::stringstream s;
		c.print(s);
        CPPUNIT_ASSERT(s.str() == "0");
    }

//-----------
// Life tests
//-----------

	void test_Life_valid_1(){
        Life<ConwayCell> L(1, 1);
        CPPUNIT_ASSERT(L.valid(0, 0));
    }
	void test_Life_valid_2(){
        Life<ConwayCell> L(1, 1);
        CPPUNIT_ASSERT(!L.valid(0, 1));
    }
	void test_Life_valid_3(){
        Life<ConwayCell> L(10, 10);
        CPPUNIT_ASSERT(!L.valid(10, 1));
    }

	void test_Life_bitmap_1(){
        Life<ConwayCell> L(3, 3);
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                L.add(i, j, ConwayCell(true));
            }
        }
        int n = L._g[2][2].count(L.bitmap(2, 2));
        CPPUNIT_ASSERT(n == 8);
    }
	void test_Life_bitmap_2(){
        Life<ConwayCell> L(3, 3);
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                L.add(i, j, ConwayCell(true));
            }
        }
        int n = L._g[1][1].count(L.bitmap(1, 1));
        CPPUNIT_ASSERT(n == 3);
    }
	void test_Life_bitmap_3(){
        Life<FredkinCell> L(3, 3);
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                L.add(i, j, FredkinCell(true));
            }
        }
        int n = L._g[1][2].count(L.bitmap(1, 2));
        CPPUNIT_ASSERT(n == 3);
    }

	void test_Life_add_1(){
        ConwayCell c = ConwayCell(true);
        Life<ConwayCell> l(3, 3);
        l.add(1, 1, c);
        CPPUNIT_ASSERT(l._g[2][2] == c);
    }
	void test_Life_add_2(){
        ConwayCell c = ConwayCell(true);
        Life<ConwayCell> l(3, 3);
        l.add(1, 2, c);
        CPPUNIT_ASSERT(l._g[2][3] == c);
    }
	void test_Life_add_3(){
        ConwayCell c = ConwayCell(true);
        Life<ConwayCell> l(3, 3);
        l.add(1, 1, c);
        CPPUNIT_ASSERT(!(l._g[2][3] == c));
    }
	
	void test_Life_simulate_1(){
        std::stringstream ss;  
        std::string s = "Generation = 0, Population = 36.\n000000\n000000\n000000\n000000\n000000\n000000\n\nGeneration = 1, Population = 16.\n-1111-\n1----1\n1----1\n1----1\n1----1\n-1111-\n\n";      
        Life<FredkinCell> l(6, 6);
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                    l.add(i, j, FredkinCell(1));
            }
        }
        l.simulate(1, 1, ss);
        CPPUNIT_ASSERT(ss.str() == s);
    }
	void test_Life_simulate_2(){
        std::stringstream ss;
        Life<FredkinCell> l(6, 6);
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                    l.add(i, j, FredkinCell(1));
            }
        }
        l.simulate(10, 10, ss);
        CPPUNIT_ASSERT(l._l == 11);
    }
	void test_Life_simulate_3(){
        std::stringstream ss;
        Life<FredkinCell> l(6, 6);
        CPPUNIT_ASSERT(l._l == 0);
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                    l.add(i, j, FredkinCell(1));
            }
        }
        l.simulate(10, 10, ss);
        CPPUNIT_ASSERT(l._l == 11);
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);
    // AbstractCell Tests
    CPPUNIT_TEST(test_AbstractCell_update_1);
    CPPUNIT_TEST(test_AbstractCell_update_2);
    CPPUNIT_TEST(test_AbstractCell_update_3);
    CPPUNIT_TEST(test_AbstractCell_status_1);
    CPPUNIT_TEST(test_AbstractCell_status_2);
    CPPUNIT_TEST(test_AbstractCell_status_3);
    // ConwayCell Tests
    CPPUNIT_TEST(test_ConwayCell_count_1);
    CPPUNIT_TEST(test_ConwayCell_count_2);
    CPPUNIT_TEST(test_ConwayCell_count_3);
    CPPUNIT_TEST(test_ConwayCell_evolve_1);
    CPPUNIT_TEST(test_ConwayCell_evolve_2);
    CPPUNIT_TEST(test_ConwayCell_evolve_3);
    CPPUNIT_TEST(test_ConwayCell_evolve_4);
    CPPUNIT_TEST(test_ConwayCell_print_1);
    CPPUNIT_TEST(test_ConwayCell_print_2);
    CPPUNIT_TEST(test_ConwayCell_print_3);
    CPPUNIT_TEST(test_ConwayCell_clone_1);
    CPPUNIT_TEST(test_ConwayCell_clone_2);
    CPPUNIT_TEST(test_ConwayCell_clone_3);
    // FredkinCell Tests
	CPPUNIT_TEST(test_FredkinCell_count_1);
	CPPUNIT_TEST(test_FredkinCell_count_2);
	CPPUNIT_TEST(test_FredkinCell_count_3);
    CPPUNIT_TEST(test_FredkinCell_evolve_1);
    CPPUNIT_TEST(test_FredkinCell_evolve_2);
    CPPUNIT_TEST(test_FredkinCell_evolve_3);
    CPPUNIT_TEST(test_FredkinCell_print_1);
    CPPUNIT_TEST(test_FredkinCell_print_2);
    CPPUNIT_TEST(test_FredkinCell_print_3);
    CPPUNIT_TEST(test_FredkinCell_clone_1);
    CPPUNIT_TEST(test_FredkinCell_clone_2);
    CPPUNIT_TEST(test_FredkinCell_clone_3);
    CPPUNIT_TEST(test_FredkinCell_mutate_1);
    CPPUNIT_TEST(test_FredkinCell_mutate_2);
    CPPUNIT_TEST(test_FredkinCell_mutate_3);
	// Cell
    CPPUNIT_TEST(test_Cell_status_1);
    CPPUNIT_TEST(test_Cell_status_2);
    CPPUNIT_TEST(test_Cell_status_3);
    CPPUNIT_TEST(test_Cell_count_1);
    CPPUNIT_TEST(test_Cell_count_2);
    CPPUNIT_TEST(test_Cell_count_3);
    CPPUNIT_TEST(test_Cell_evolve_1);
    CPPUNIT_TEST(test_Cell_evolve_2);
    CPPUNIT_TEST(test_Cell_evolve_3);
    CPPUNIT_TEST(test_Cell_print_1);
    CPPUNIT_TEST(test_Cell_print_2);
    CPPUNIT_TEST(test_Cell_print_3);
	// Life
    CPPUNIT_TEST(test_Life_bitmap_1);
    CPPUNIT_TEST(test_Life_bitmap_2);
    CPPUNIT_TEST(test_Life_bitmap_3);
    CPPUNIT_TEST(test_Life_add_1);
    CPPUNIT_TEST(test_Life_add_2);
    CPPUNIT_TEST(test_Life_add_3);
    CPPUNIT_TEST(test_Life_simulate_1);
    CPPUNIT_TEST(test_Life_simulate_2);
    CPPUNIT_TEST(test_Life_simulate_3);

    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);    // turn off synchronization with C I/O
    cout << "TestLife.c++" << endl;

    CppUnit::TextTestRunner tr;

  	tr.addTest(TestLife::suite());

    tr.run();

    cout << "Done." << endl;
    return 0;}
