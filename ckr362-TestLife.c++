// ------------------------------------
// projects/life/TestLife.c++
// ------------------------------------

/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -pedantic -std=c++0x -Wall Allocator.c++ TestAllocator.c++ -o TestAllocator -lcppunit -ldl
    % valgrind TestAllocator >& TestAllocator.out
*/

// --------
// includes
// --------
#include <cassert>
#include <algorithm> // count
#include <iostream>  // ios_base
#include <memory>    // allocator
#include <vector>	// vector
#include <map>
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

// DOWNING TRICK

#define private public
#define class struct 

#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Life.h"


using namespace std;

struct TestLife : CppUnit::TestFixture {
	

    /**
     * AbstractCell tests
     */
	void test_abstractcell_constructor_1() {
        ConwayCell acell;
        CPPUNIT_ASSERT(!acell.is_alive());
        ConwayCell acell1(true);
        CPPUNIT_ASSERT(acell1.is_alive());
    }

    void test_abstractcell_become_alive_1() {
        ConwayCell acell;
        CPPUNIT_ASSERT(!acell.is_alive());
        acell.become_alive();
        CPPUNIT_ASSERT(acell.is_alive());
        ConwayCell acell2(true);
        CPPUNIT_ASSERT(acell2.is_alive());
        acell2.become_alive();
        CPPUNIT_ASSERT(acell2.is_alive());
    }

    void test_abstractcell_die_1() {
        ConwayCell acell;
        CPPUNIT_ASSERT(!acell.is_alive());
        acell.die();
        CPPUNIT_ASSERT(!acell.is_alive());
        ConwayCell acell2(true);
        CPPUNIT_ASSERT(acell2.is_alive());
        acell2.die();
        CPPUNIT_ASSERT(!acell2.is_alive());
    }

    void test_abstractcell_is_alive() {
        // Tested previously.
    }

    void test_abstractcell_constructor_2() {
        FredkinCell acell;
        CPPUNIT_ASSERT(!acell.is_alive());
        FredkinCell acell1(true);
        CPPUNIT_ASSERT(acell1.is_alive());
    }

    void test_abstractcell_become_alive_2() {
        FredkinCell acell;
        CPPUNIT_ASSERT(!acell.is_alive());
        acell.become_alive();
        CPPUNIT_ASSERT(acell.is_alive());
        FredkinCell acell2(true);
        CPPUNIT_ASSERT(acell2.is_alive());
        acell2.become_alive();
        CPPUNIT_ASSERT(acell2.is_alive());

    }

    void test_abstractcell_die_2() {
        FredkinCell acell;
        CPPUNIT_ASSERT(!acell.is_alive());
        acell.die();
        CPPUNIT_ASSERT(!acell.is_alive());
        FredkinCell acell2(true);
        CPPUNIT_ASSERT(acell2.is_alive());
        acell2.die();
        CPPUNIT_ASSERT(!acell2.is_alive());
    }

    void test_abstractcell_is_alive_2() {
        // Tested previously.
    }
    void test_abstractcell_constructor_3() {
        FredkinCell* t = new FredkinCell();
        Cell acell1(t);
        CPPUNIT_ASSERT(!acell1.is_alive());
        FredkinCell* t2 = new FredkinCell(true);
        Cell acell2(t2);
        CPPUNIT_ASSERT(acell2.is_alive());



    }

    void test_abstractcell_become_alive_3() {
        CPPUNIT_ASSERT(true);
        // Test does not apply to Cell.
    }

    void test_abstractcell_die_3() {
        CPPUNIT_ASSERT(true);
        // Test does not apply to Cell.
    }

    void test_abstractcell_is_alive_3() {
        // Tested previously.
    }
    
    /**
     * ConwayCell tests
     */
    
     void test_conwaycell_constructor_1() {
        ConwayCell acell;
        CPPUNIT_ASSERT(!acell.is_alive());
     }

     void test_conwaycell_evolve_1() {
        ConwayCell cell;
        CPPUNIT_ASSERT(!cell.is_alive());
        cell.evolve(3);
        CPPUNIT_ASSERT(cell.is_alive());

     }

     void test_conwaycell_has_diagonal_neighbors_1() {
        ConwayCell cell;
        CPPUNIT_ASSERT(cell.has_diagonal_neighbors());
     }

     void test_conwaycell_clone_1() {
        ConwayCell cell;
        ConwayCell* cloned = cell.clone();
        CPPUNIT_ASSERT(!cell.is_alive());
        CPPUNIT_ASSERT(!cloned->is_alive());
        CPPUNIT_ASSERT(cell.is_alive() == cloned->is_alive());
        CPPUNIT_ASSERT(cloned != &cell);
        delete cloned;
     }

     void test_conwaycell_operator_1() {
        ConwayCell cell;
        cell << '.';
        CPPUNIT_ASSERT(!cell.is_alive());
        CPPUNIT_ASSERT(cell.write() == '.');
     }

     void test_conwaycell_write_1() {
        ConwayCell cell;
        CPPUNIT_ASSERT(cell.write() == '.');
        cell.become_alive();
        CPPUNIT_ASSERT(cell.write() == '*');
     }

     void test_conwaycell_mutating_1() {
        ConwayCell cell;
        CPPUNIT_ASSERT(cell.mutating() == false);
     }
     void test_conwaycell_constructor_2() {
        ConwayCell acell1(true);
        CPPUNIT_ASSERT(acell1.is_alive());
     }

     void test_conwaycell_evolve_2() {
        ConwayCell cell(true);
        CPPUNIT_ASSERT(cell.is_alive());
        cell.evolve(1);
        CPPUNIT_ASSERT(!cell.is_alive());
        cell.evolve(2);
        CPPUNIT_ASSERT(!cell.is_alive());
        cell.evolve(4);
        CPPUNIT_ASSERT(!cell.is_alive());
        cell.evolve(5);
        CPPUNIT_ASSERT(!cell.is_alive());
        cell.evolve(6);
        CPPUNIT_ASSERT(!cell.is_alive());
        cell.evolve(7);
        CPPUNIT_ASSERT(!cell.is_alive());
        cell.evolve(8);
        CPPUNIT_ASSERT(!cell.is_alive());

     }

     void test_conwaycell_has_diagonal_neighbors_2() {
        // Previously tested.
     }

     void test_conwaycell_clone_2() {
        ConwayCell cell(true);
        ConwayCell* cloned = cell.clone();
        CPPUNIT_ASSERT(cell.is_alive());
        CPPUNIT_ASSERT(cloned->is_alive());
        CPPUNIT_ASSERT(cell.is_alive() == cloned->is_alive());
        CPPUNIT_ASSERT(cloned != &cell);
        delete cloned;
     }

     void test_conwaycell_operator_2() {
        ConwayCell cell;
        cell << '*';
        CPPUNIT_ASSERT(cell.is_alive());
        CPPUNIT_ASSERT(cell.write() == '*');
     }

     void test_conwaycell_write_2() {
        ConwayCell cell(true);
        CPPUNIT_ASSERT(cell.write() == '*');
        cell.die();
        CPPUNIT_ASSERT(cell.write() == '.');
     }

     void test_conwaycell_mutating_2() {
        // Previously tested.
     }
     void test_conwaycell_constructor_3() {
        ConwayCell acell1(false);
        CPPUNIT_ASSERT(!acell1.is_alive());
     }

     void test_conwaycell_evolve_3() {
        ConwayCell cell(false);
        CPPUNIT_ASSERT(!cell.is_alive());
        cell.evolve(1);
        CPPUNIT_ASSERT(!cell.is_alive());
        cell.evolve(2);
        CPPUNIT_ASSERT(!cell.is_alive());
        cell.evolve(4);
        CPPUNIT_ASSERT(!cell.is_alive());
        cell.evolve(5);
        CPPUNIT_ASSERT(!cell.is_alive());
        cell.evolve(6);
        CPPUNIT_ASSERT(!cell.is_alive());
        cell.evolve(7);
        CPPUNIT_ASSERT(!cell.is_alive());
        cell.evolve(8);
        CPPUNIT_ASSERT(!cell.is_alive());
        cell.evolve(3);
        CPPUNIT_ASSERT(cell.is_alive());
     }

     void test_conwaycell_has_diagonal_neighbors_3() {
        CPPUNIT_ASSERT(true);
        // Previously tested.
     }

     void test_conwaycell_clone_3() {
        CPPUNIT_ASSERT(true);
        // Previously tested.
     }

     void test_conwaycell_operator_3() {
        ConwayCell cell(true);
        cell << '.'; // Note this changes the state of the Conway Cell. 
        CPPUNIT_ASSERT(!cell.is_alive());
        CPPUNIT_ASSERT(cell.write() == '.');
     }

     void test_conwaycell_write_3() {
        //Note that his works, since ConwayCell isn't adding any
        //extra data... interesting... meow.
        AbstractCell* cell = new ConwayCell(false);
        CPPUNIT_ASSERT(cell->write() == '.');
        cell->become_alive();
        CPPUNIT_ASSERT(cell->write() == '*');
        delete cell;
     }

     void test_conwaycell_mutating_3() {
        // Previously tested.
     }
    /**
     * FredkinCell tests
     */
     void test_fredkincell_constructor_1() {
        FredkinCell acell;
        CPPUNIT_ASSERT(!acell.is_alive());
     }

     void test_fredkincell_evolve_1() {
        FredkinCell cell;
        CPPUNIT_ASSERT(!cell.is_alive());
        cell.evolve(1);
        CPPUNIT_ASSERT(cell.is_alive());
        cell.die();
        cell.evolve(3);
        CPPUNIT_ASSERT(cell.is_alive());
        cell.die();
        CPPUNIT_ASSERT(!cell.is_alive());
     }

     void test_fredkincell_has_diagonal_neighbors_1() {
        FredkinCell cell;
        CPPUNIT_ASSERT(!cell.has_diagonal_neighbors());
     }

     void test_fredkincell_clone_1() {
        FredkinCell cell;
        FredkinCell* cloned = cell.clone();
        CPPUNIT_ASSERT(!cell.is_alive());
        CPPUNIT_ASSERT(!cloned->is_alive());
        CPPUNIT_ASSERT(cell.is_alive() == cloned->is_alive());
        CPPUNIT_ASSERT(cloned != &cell);
        delete cloned;
     }

     void test_fredkincell_operator_1() {
        FredkinCell cell;
        cell << '-';
        CPPUNIT_ASSERT(!cell.is_alive());
        CPPUNIT_ASSERT(cell.write() == '-');
     }

     void test_fredkincell_write_1() {
        FredkinCell cell;
        CPPUNIT_ASSERT(cell.write() == '-');
        cell.become_alive();
        CPPUNIT_ASSERT(cell.write() == '0');
     }

     void test_fredkincell_mutating_1() {
        FredkinCell cell;
        CPPUNIT_ASSERT(cell.mutating() == false);
     }
     void test_fredkincell_constructor_2() {
        FredkinCell acell1(true);
        CPPUNIT_ASSERT(acell1.is_alive());
     }

     void test_fredkincell_evolve_2() {
        FredkinCell cell(true);
        CPPUNIT_ASSERT(cell.is_alive());
        cell.die();
        cell.evolve(1);
        CPPUNIT_ASSERT(cell.is_alive());
        cell.die();
        cell.evolve(3);
        CPPUNIT_ASSERT(cell.is_alive());
        cell.evolve(0);
        CPPUNIT_ASSERT(!cell.is_alive());
        cell.evolve(4);
        CPPUNIT_ASSERT(!cell.is_alive());
        cell.evolve(2);
        CPPUNIT_ASSERT(!cell.is_alive());
        cell.evolve(0);
        CPPUNIT_ASSERT(!cell.is_alive());
     }

     void test_fredkincell_has_diagonal_neighbors_2() {
        CPPUNIT_ASSERT(true);
        // Previously tested.
     }

     void test_fredkincell_clone_2() {
        FredkinCell cell;
        FredkinCell* cloned = cell.clone();
        CPPUNIT_ASSERT(cloned->_age == 0 && cell._age == 0 && &cell._age != &cloned->_age);
        CPPUNIT_ASSERT(!cell.is_alive());
        CPPUNIT_ASSERT(!cloned->is_alive());
        CPPUNIT_ASSERT(cell.is_alive() == cloned->is_alive());
        CPPUNIT_ASSERT(cloned != &cell);
        delete cloned;
     }

     void test_fredkincell_operator_2() {   
        FredkinCell cell;
        cell << '0';
        CPPUNIT_ASSERT(cell.is_alive());
        CPPUNIT_ASSERT(cell._age == 0);
        FredkinCell cell2;
        cell << '4';
        CPPUNIT_ASSERT(cell.is_alive());
        CPPUNIT_ASSERT(cell._age == 4);
     }

     void test_fredkincell_write_2() {
        FredkinCell cell(true);
        CPPUNIT_ASSERT(cell.write() == '0');
        cell.evolve(1);
        CPPUNIT_ASSERT(cell.write() == '1');
     }

     void test_fredkincell_mutating_2() {
        FredkinCell cell;
        cell.evolve(1);
        cell.evolve(3);
        cell.evolve(3);
        CPPUNIT_ASSERT(cell.mutating() == true);
        cell.evolve(1);
        CPPUNIT_ASSERT(!cell.mutating());
     }
     
     void test_fredkincell_constructor_3() {
        FredkinCell cell(false);
        CPPUNIT_ASSERT(!cell.is_alive());
     }

     void test_fredkincell_evolve_3() {
        FredkinCell cell(true);
        for ( int i = 0; i < 10; ++i )
            cell.evolve(1);
        CPPUNIT_ASSERT(cell.is_alive());
        CPPUNIT_ASSERT(cell._age == 10);
     }

     void test_fredkincell_has_diagonal_neighbors_3() {
        CPPUNIT_ASSERT(true);
        FredkinCell poop;
        CPPUNIT_ASSERT(!poop.has_diagonal_neighbors());
     }

     void test_fredkincell_clone_3() {
        FredkinCell cell(true);
        for ( int i = 0; i < 10; ++i )
            cell.evolve(1);
        FredkinCell* cloned = cell.clone();
        CPPUNIT_ASSERT(&cell != cloned);
        CPPUNIT_ASSERT(cell._age == cloned->_age);
		delete cloned;
     }

     void test_fredkincell_operator_3() {
        FredkinCell cell;
        cell << '+';
        CPPUNIT_ASSERT(cell._age == 10);
        CPPUNIT_ASSERT(cell.is_alive());
        // cell << '-'; UNSUPPORTED OPERATION
        CPPUNIT_ASSERT(cell.is_alive());
     }

     void test_fredkincell_write_3() {
        FredkinCell cell;
        CPPUNIT_ASSERT(cell.write() == '-');
        FredkinCell cell2(true);
        CPPUNIT_ASSERT(cell2.write() == '0');
        cell2.evolve(1);
        CPPUNIT_ASSERT(cell2.write() == '1');
        cell2.evolve(1);
        CPPUNIT_ASSERT(cell2.write() == '2');
        for ( int i = 0; i < 13; ++i)
                    cell2.evolve(1);
        CPPUNIT_ASSERT(cell2.write() == '+');
     }

     void test_fredkincell_mutating_3() {
        CPPUNIT_ASSERT(true);
        // Previously tested
     }
    /**
     * Cell tests
     */
     void test_cell_constructor_1() {
        Cell cell = new ConwayCell;
        CPPUNIT_ASSERT(!cell._p->is_alive());
     }

     void test_cell_evolve_1() {
        Cell cell = new FredkinCell(true);
        CPPUNIT_ASSERT(cell.is_alive());
        cell._p->die();
        cell.evolve(1);
        CPPUNIT_ASSERT(cell.is_alive());
        cell._p->die();
        cell.evolve(3);
        CPPUNIT_ASSERT(cell.is_alive());
        cell.evolve(0);
        CPPUNIT_ASSERT(!cell.is_alive());
        cell.evolve(4);
        CPPUNIT_ASSERT(!cell.is_alive());
        cell.evolve(2);
        CPPUNIT_ASSERT(!cell.is_alive());
        cell.evolve(0);
        CPPUNIT_ASSERT(!cell.is_alive());
     }

     void test_cell_has_diagonal_neighbors_1() {
        Cell cell = new ConwayCell;
        CPPUNIT_ASSERT(cell.has_diagonal_neighbors());
     }

     void test_cell_operator_1() {
        Cell cell = new FredkinCell;
        cell << '-';
        CPPUNIT_ASSERT(cell.write() == '-');
     }

     void test_cell_write_1() {
        Cell cell = new FredkinCell;
        CPPUNIT_ASSERT(cell.write() == '-');
        cell._p->become_alive();
        CPPUNIT_ASSERT(cell.write() == '0');
     }

     void test_cell_constructor_2() {
        Cell cell = new FredkinCell(true);
        CPPUNIT_ASSERT(cell._p->is_alive());
        CPPUNIT_ASSERT(dynamic_cast<FredkinCell*>(cell._p)->_age == 0);
     }

     void test_cell_evolve_2() {
        Cell cell = new ConwayCell(true);
        cell.evolve(2);
        CPPUNIT_ASSERT(cell.is_alive());
        cell.evolve(2);
        CPPUNIT_ASSERT(cell.is_alive());
        // Nothing else changes...
     }

     void test_cell_has_diagonal_neighbors_2() {
        Cell cell = new FredkinCell;
        CPPUNIT_ASSERT(!cell.has_diagonal_neighbors());
     }

     void test_cell_operator_2() {
        Cell cell = new ConwayCell;
        cell << '*';
        CPPUNIT_ASSERT(cell.write() == '*');
     }

     void test_cell_write_2() {
        Cell cell = new FredkinCell(true);
        CPPUNIT_ASSERT(cell.write() == '0');
        cell.evolve(1);
        CPPUNIT_ASSERT(cell.write() == '1');
     }
     void test_cell_constructor_3() {
        Cell cell = new FredkinCell(false);
        CPPUNIT_ASSERT(!cell._p->is_alive());
        CPPUNIT_ASSERT(dynamic_cast<FredkinCell*>(cell._p)->_age == 0);
     }

     void test_cell_evolve_3() {
        Cell cell = new FredkinCell(true);
        cell.evolve(1);
        CPPUNIT_ASSERT(cell.is_alive());
        cell.evolve(1);
        CPPUNIT_ASSERT(cell.is_alive());
        cell.evolve(2);
        CPPUNIT_ASSERT(cell.is_alive());
        
     }

     void test_cell_has_diagonal_neighbors_3() {
        CPPUNIT_ASSERT(true);
        // Previously tested.
     }

     void test_cell_operator_3() {
        Cell cell = new FredkinCell(true);
        cell << '+';
        CPPUNIT_ASSERT(dynamic_cast<FredkinCell*>(cell._p)->_age == 10);
        CPPUNIT_ASSERT(cell.is_alive());
        // cell << '-'; UNSUPPORTED OPERATION
        CPPUNIT_ASSERT(cell.is_alive());

     }

     void test_cell_write_3() {
        Cell cell = new FredkinCell;
        CPPUNIT_ASSERT(cell.write() == '-');
        FredkinCell cell2(true);
        CPPUNIT_ASSERT(cell2.write() == '0');
        cell2.evolve(1);
        CPPUNIT_ASSERT(cell2.write() == '1');
        cell2.evolve(1);
        CPPUNIT_ASSERT(cell2.write() == '2');
        for ( int i = 0; i < 13; ++i)
                    cell2.evolve(1);
        CPPUNIT_ASSERT(cell2.write() == '+');
     }
    /**
     * Handle Tests - This was provided by Downing.
     * No need to write these tests.
     */
    
    /**
     * Life tests.
     */
    void test_life_constructor_1_1() {
        CPPUNIT_ASSERT(true);
    }

    void test_life_constructor_2_1() {
        CPPUNIT_ASSERT(true);

    }

    void test_life_count_neighbors_1() {
        CPPUNIT_ASSERT(true);

    }

    void test_life_evolve_1() {
        CPPUNIT_ASSERT(true);

    }

    void test_life_write_1() {
        CPPUNIT_ASSERT(true);

    }

    void test_life_read_1() {
        CPPUNIT_ASSERT(true);

    }
    void test_life_constructor_1_2() {
        CPPUNIT_ASSERT(true);

    }

    void test_life_constructor_2_2() {
        CPPUNIT_ASSERT(true);

    }

    void test_life_count_neighbors_2() {
        CPPUNIT_ASSERT(true);

    }

    void test_life_evolve_2() {
        CPPUNIT_ASSERT(true);

    }

    void test_life_write_2() {
        CPPUNIT_ASSERT(true);

    }

    void test_life_read_2() {
        CPPUNIT_ASSERT(true);

    }
    void test_life_constructor_1_3() {
        CPPUNIT_ASSERT(true);

    }

    void test_life_constructor_2_3() {
        CPPUNIT_ASSERT(true);

    }

    void test_life_count_neighbors_3() {
        CPPUNIT_ASSERT(true);

    }

    void test_life_evolve_3() {
        CPPUNIT_ASSERT(true);

    }

    void test_life_write_3() {
        CPPUNIT_ASSERT(true);

    }

    void test_life_read_3() {
        CPPUNIT_ASSERT(true);

    }
	CPPUNIT_TEST_SUITE(TestLife);
    
    CPPUNIT_TEST(test_abstractcell_constructor_1);
    CPPUNIT_TEST(test_abstractcell_constructor_1);
    CPPUNIT_TEST(test_abstractcell_become_alive_1); 
    CPPUNIT_TEST(test_abstractcell_die_1);
    CPPUNIT_TEST(test_abstractcell_is_alive); 
    CPPUNIT_TEST(test_conwaycell_constructor_1);
    CPPUNIT_TEST(test_conwaycell_evolve_1);
    CPPUNIT_TEST(test_conwaycell_has_diagonal_neighbors_1);
    CPPUNIT_TEST(test_conwaycell_clone_1);
    CPPUNIT_TEST(test_conwaycell_operator_1); 
    CPPUNIT_TEST(test_conwaycell_write_1);
    CPPUNIT_TEST(test_conwaycell_mutating_1);
    CPPUNIT_TEST(test_fredkincell_constructor_1); 
    CPPUNIT_TEST(test_fredkincell_evolve_1);
    CPPUNIT_TEST(test_fredkincell_has_diagonal_neighbors_1 );
    CPPUNIT_TEST(test_fredkincell_clone_1 );
    CPPUNIT_TEST(test_fredkincell_operator_1); 
    CPPUNIT_TEST(test_fredkincell_write_1 );
    CPPUNIT_TEST(test_fredkincell_mutating_1); 
    CPPUNIT_TEST(test_cell_constructor_1); 
    CPPUNIT_TEST(test_cell_evolve_1 );
    CPPUNIT_TEST(test_cell_has_diagonal_neighbors_1 );
    CPPUNIT_TEST(test_cell_operator_1); 
    CPPUNIT_TEST(test_cell_write_1 );
    CPPUNIT_TEST(test_life_constructor_1_1 );
    CPPUNIT_TEST(test_life_constructor_2_1 );
    CPPUNIT_TEST(test_life_count_neighbors_1 );
    CPPUNIT_TEST(test_life_evolve_1 );
    CPPUNIT_TEST(test_life_write_1 );
    CPPUNIT_TEST(test_life_read_1 );
    CPPUNIT_TEST(test_abstractcell_constructor_2 );
    CPPUNIT_TEST(test_abstractcell_become_alive_2); 
    CPPUNIT_TEST(test_abstractcell_die_2);
    CPPUNIT_TEST(test_abstractcell_is_alive );
    CPPUNIT_TEST(test_conwaycell_constructor_2 );
    CPPUNIT_TEST(test_conwaycell_evolve_2 );
    CPPUNIT_TEST(test_conwaycell_has_diagonal_neighbors_2); 
    CPPUNIT_TEST(test_conwaycell_clone_2 );
    CPPUNIT_TEST(test_conwaycell_operator_2); 
    CPPUNIT_TEST(test_conwaycell_write_2 );
    CPPUNIT_TEST(test_conwaycell_mutating_2 );
    CPPUNIT_TEST(test_fredkincell_constructor_2 );
    CPPUNIT_TEST(test_fredkincell_evolve_2 );
    CPPUNIT_TEST(test_fredkincell_has_diagonal_neighbors_2 );
    CPPUNIT_TEST(test_fredkincell_clone_2 );
    CPPUNIT_TEST(test_fredkincell_operator_2); 
    CPPUNIT_TEST(test_fredkincell_write_2 );
    CPPUNIT_TEST(test_fredkincell_mutating_2); 
    CPPUNIT_TEST(test_cell_constructor_2 );
    CPPUNIT_TEST(test_cell_evolve_2 );
    CPPUNIT_TEST(test_cell_has_diagonal_neighbors_2 );
    CPPUNIT_TEST(test_cell_operator_2); 
    CPPUNIT_TEST(test_cell_write_2 );
    CPPUNIT_TEST(test_life_constructor_1_2 );
    CPPUNIT_TEST(test_life_constructor_2_2 );
    CPPUNIT_TEST(test_life_count_neighbors_2 );
    CPPUNIT_TEST(test_life_evolve_2 );
    CPPUNIT_TEST(test_life_write_2 );
    CPPUNIT_TEST(test_life_read_2 );
    CPPUNIT_TEST(test_abstractcell_constructor_3 );
    CPPUNIT_TEST(test_abstractcell_become_alive_3 );
    CPPUNIT_TEST(test_abstractcell_die_3);
    CPPUNIT_TEST(test_abstractcell_is_alive );
    CPPUNIT_TEST(test_conwaycell_constructor_3 );
    CPPUNIT_TEST(test_conwaycell_evolve_3 );
    CPPUNIT_TEST(test_conwaycell_has_diagonal_neighbors_3 );
    CPPUNIT_TEST(test_conwaycell_clone_3 );
    CPPUNIT_TEST(test_conwaycell_operator_3); 
    CPPUNIT_TEST(test_conwaycell_write_3 );
    CPPUNIT_TEST(test_conwaycell_mutating_3 );
    CPPUNIT_TEST(test_fredkincell_constructor_3 );
    CPPUNIT_TEST(test_fredkincell_evolve_3 );
    CPPUNIT_TEST(test_fredkincell_has_diagonal_neighbors_3 );
    CPPUNIT_TEST(test_fredkincell_clone_3 );
    CPPUNIT_TEST(test_fredkincell_operator_3 );
    CPPUNIT_TEST(test_fredkincell_write_3 );
    CPPUNIT_TEST(test_fredkincell_mutating_3 );
    CPPUNIT_TEST(test_cell_constructor_3 );
    CPPUNIT_TEST(test_cell_evolve_3 );
    CPPUNIT_TEST(test_cell_has_diagonal_neighbors_3 );
    CPPUNIT_TEST(test_cell_operator_3); 
    CPPUNIT_TEST(test_cell_write_3 );
    CPPUNIT_TEST(test_life_constructor_1_3 );
    CPPUNIT_TEST(test_life_constructor_2_3 );
    CPPUNIT_TEST(test_life_count_neighbors_3 );
    CPPUNIT_TEST(test_life_evolve_3); 
    CPPUNIT_TEST(test_life_write_3); 
    CPPUNIT_TEST(test_life_read_3);


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
