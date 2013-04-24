// ------------
// TestLife.c++
// ------------

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringstream, ostringstream
#include <string>   // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUIT_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define private public
#define protected public
#define class struct

#include "Life.h"
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

// --------
// TestLife
// --------

struct TestLife : CppUnit::TestFixture {
    // ----------
    // Life::Life
    // ----------

    void test_Life_1 () {
        Life<ConwayCell> x (10, 5);
        CPPUNIT_ASSERT (x._length == 10);
        CPPUNIT_ASSERT (x._width == 5);
        CPPUNIT_ASSERT (x._generation == 0);
        CPPUNIT_ASSERT (x._population == 0);
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 5; ++j) {
                CPPUNIT_ASSERT (x._grid[i][j]._state == DEAD);
            }
        }
    }

    void test_Life_2 () {
        Life<FredkinCell> x (10, 5);
        CPPUNIT_ASSERT (x._length == 10);
        CPPUNIT_ASSERT (x._width == 5);
        CPPUNIT_ASSERT (x._generation == 0);
        CPPUNIT_ASSERT (x._population == 0);
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 5; ++j) {
                CPPUNIT_ASSERT (x._grid[i][j]._state == DEAD);
                CPPUNIT_ASSERT (x._grid[i][j]._age == 0);
            }
        }
    }

    void test_Life_3 () {
        Life<Cell> x (10, 5);
        CPPUNIT_ASSERT (x._length == 10);
        CPPUNIT_ASSERT (x._width == 5);
        CPPUNIT_ASSERT (x._generation == 0);
        CPPUNIT_ASSERT (x._population == 0);
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 5; ++j) {
                CPPUNIT_ASSERT (x._grid[i][j]._p->_state == DEAD);
            }
        }
    }

    // -----------
    // Life::place
    // -----------

    void test_Life_place_1 () {
        Life<ConwayCell> x (10, 5);
        x.place (0, 1);
        x.place (0, 2);
        x.place (0, 3);
        x.place (5, 1);
        x.place (5, 2);
        x.place (5, 3);
        CPPUNIT_ASSERT (x._grid[0][1]._state = ALIVE);
        CPPUNIT_ASSERT (x._grid[0][2]._state = ALIVE);
        CPPUNIT_ASSERT (x._grid[0][3]._state = ALIVE);
        CPPUNIT_ASSERT (x._grid[5][1]._state = ALIVE);
        CPPUNIT_ASSERT (x._grid[5][2]._state = ALIVE);
        CPPUNIT_ASSERT (x._grid[5][3]._state = ALIVE);
    }

    void test_Life_place_2 () {
        Life<FredkinCell> x (10, 5);
        x.place (0, 1);
        x.place (0, 2);
        x.place (0, 3);
        x.place (5, 1);
        x.place (5, 2);
        x.place (5, 3);
        CPPUNIT_ASSERT (x._grid[0][1]._state = ALIVE);
        CPPUNIT_ASSERT (x._grid[0][2]._state = ALIVE);
        CPPUNIT_ASSERT (x._grid[0][3]._state = ALIVE);
        CPPUNIT_ASSERT (x._grid[5][1]._state = ALIVE);
        CPPUNIT_ASSERT (x._grid[5][2]._state = ALIVE);
        CPPUNIT_ASSERT (x._grid[5][3]._state = ALIVE);
    }

    void test_Life_place_3 () {
        Life<Cell> x (10, 5);
        x.place (0, 1);
        x.place (0, 2);
        x.place (0, 3);
        x.place (5, 1);
        x.place (5, 2);
        x.place (5, 3);
        CPPUNIT_ASSERT (x._grid[0][1]._p->_state = ALIVE);
        CPPUNIT_ASSERT (x._grid[0][2]._p->_state = ALIVE);
        CPPUNIT_ASSERT (x._grid[0][3]._p->_state = ALIVE);
        CPPUNIT_ASSERT (x._grid[5][1]._p->_state = ALIVE);
        CPPUNIT_ASSERT (x._grid[5][2]._p->_state = ALIVE);
        CPPUNIT_ASSERT (x._grid[5][3]._p->_state = ALIVE);
    }

    // --------------
    // Life::simulate
    // --------------

    void test_Life_simulate_1 () {
        Life<ConwayCell> x (10, 5);
        x.simulate ();
        CPPUNIT_ASSERT (x._generation == 1);
        CPPUNIT_ASSERT (x._population == 0);
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 5; ++j) {
                CPPUNIT_ASSERT (x._grid[i][j]._state == DEAD);
            }
        }
    }

    void test_Life_simulate_2 () {
        Life<FredkinCell> x (10, 5);
        for (int n = 1; n <= 10; ++n) {
            x.simulate ();
            CPPUNIT_ASSERT (x._generation == n);
            CPPUNIT_ASSERT (x._population == 0);
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 5; ++j) {
                    CPPUNIT_ASSERT (x._grid[i][j]._state == DEAD);
                    CPPUNIT_ASSERT (x._grid[i][j]._age == 0);
                }
            }
        }
    }

    void test_Life_simulate_3 () {
        Life<Cell> x (10, 5);
        x._grid [0][0];
        x._grid [0][2];
        x._grid [0][4];
        x._grid [2][0];
        x._grid [2][2];
        x._grid [2][4];
        x._population = 6;
        for (int n = 1; n <= 10; ++n) {
            x.simulate ();
            CPPUNIT_ASSERT (x._generation == n);
            CPPUNIT_ASSERT (x._population == 0);
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 5; ++j) {
                    CPPUNIT_ASSERT (x._grid[i][j]._p->_state == DEAD);
                }
            }
        }
    }

    // -----------
    // Life::print
    // -----------

    void test_Life_print_1 () {
        Life<ConwayCell> x (3, 3);
        x._population = 3;
        x._generation = 3;
        x._grid[0][0]._state = ALIVE;
        x._grid[1][1]._state = ALIVE;
        x._grid[2][2]._state = ALIVE;
        std::ostringstream w;
        x.print (w);
        CPPUNIT_ASSERT (w.str () == "Generation = 3, Population = 3.\n*..\n.*.\n..*\n\n");
    }

    void test_Life_print_2 () {
        Life<FredkinCell> x (3, 3);
        x._population = 10;
        x._generation = 100;
        x._grid[0][0]._state = ALIVE;
        x._grid[0][0]._age = 10;
        x._grid[1][1]._state = ALIVE;
        x._grid[1][1]._age = 5;
        x._grid[2][2]._state = ALIVE;
        x._grid[2][2]._age = 7;
        std::ostringstream w;
        x.print (w);
        CPPUNIT_ASSERT (w.str () == "Generation = 100, Population = 10.\n+--\n-5-\n--7\n\n");
    }

    void test_Life_print_3 () {
        Life<Cell> x (3, 3);
        x._population = 25;
        x._generation = 25;
        x._grid[0][0]._p = new ConwayCell ();
        x._grid[0][1]._p = new ConwayCell ();
        x._grid[0][2]._p = new ConwayCell ();
        x._grid[0][0]._p->_state = ALIVE;
        x._grid[1][1]._p->_state = ALIVE;
        x._grid[2][2]._p->_state = ALIVE;
        std::ostringstream w;
        x.print (w);
        CPPUNIT_ASSERT (w.str () == "Generation = 25, Population = 25.\n*..\n-0-\n--0\n\n");
    }

    // --------------------
    // Life::check_neighbor
    // --------------------

    void test_Life_check_neighbor_1 () {
        Life<ConwayCell> x (3, 3);
        x.place (0, 0);
        x.place (0, 1);
        x.place (0, 2);
        CPPUNIT_ASSERT (x.check_neighbor (N, 1, 1));
        CPPUNIT_ASSERT (x.check_neighbor (NW, 1, 1));
        CPPUNIT_ASSERT (x.check_neighbor (NE, 1, 1));
        CPPUNIT_ASSERT (!x.check_neighbor (W, 1, 1));
        CPPUNIT_ASSERT (!x.check_neighbor (S, 1, 1));
        CPPUNIT_ASSERT (!x.check_neighbor (E, 1, 1));
        CPPUNIT_ASSERT (!x.check_neighbor (SW, 1, 1));
        CPPUNIT_ASSERT (!x.check_neighbor (SE, 1, 1));
    }

    void test_Life_check_neighbor_2 () {
        Life<FredkinCell> x (3, 3);
        CPPUNIT_ASSERT (!x.check_neighbor (N, 0, 0));
        CPPUNIT_ASSERT (!x.check_neighbor (W, 0, 0));
        CPPUNIT_ASSERT (!x.check_neighbor (S, 0, 0));
        CPPUNIT_ASSERT (!x.check_neighbor (E, 0, 0));
        CPPUNIT_ASSERT (!x.check_neighbor (NW, 0, 0));
        CPPUNIT_ASSERT (!x.check_neighbor (NE, 0, 0));
        CPPUNIT_ASSERT (!x.check_neighbor (SW, 0, 0));
        CPPUNIT_ASSERT (!x.check_neighbor (SE, 0, 0));
    }

    void test_Life_check_neighbor_3 () {
        Life<Cell> x (3, 3);
        x.place (0, 0);
        x.place (0, 1);
        x.place (0, 2);
        x.place (2, 0);
        x.place (2, 1);
        x.place (2, 2);
        CPPUNIT_ASSERT (x.check_neighbor (N, 1, 1));
        CPPUNIT_ASSERT (x.check_neighbor (S, 1, 1));
        CPPUNIT_ASSERT (x.check_neighbor (NW, 1, 1));
        CPPUNIT_ASSERT (x.check_neighbor (NE, 1, 1));
        CPPUNIT_ASSERT (x.check_neighbor (SW, 1, 1));
        CPPUNIT_ASSERT (x.check_neighbor (SE, 1, 1));
        CPPUNIT_ASSERT (!x.check_neighbor (W, 1, 1));
        CPPUNIT_ASSERT (!x.check_neighbor (E, 1, 1));
        delete x._grid[1][1]._p;
        x._grid[1][1]._p = new ConwayCell ();
        CPPUNIT_ASSERT (x.check_neighbor (N, 1, 1));
        CPPUNIT_ASSERT (x.check_neighbor (S, 1, 1));
        CPPUNIT_ASSERT (x.check_neighbor (NW, 1, 1));
        CPPUNIT_ASSERT (x.check_neighbor (NE, 1, 1));
        CPPUNIT_ASSERT (x.check_neighbor (SW, 1, 1));
        CPPUNIT_ASSERT (x.check_neighbor (SE, 1, 1));
        CPPUNIT_ASSERT (!x.check_neighbor (W, 1, 1));
        CPPUNIT_ASSERT (!x.check_neighbor (E, 1, 1));
    }

    // ----------------------
    // AbstractCell::is_alive
    // ----------------------

    void test_AbstractCell_is_alive_1 () {
        ConwayCell x;
        CPPUNIT_ASSERT (!x.is_alive ());
    }

    void test_AbstractCell_is_alive_2 () {
        ConwayCell x;
        CPPUNIT_ASSERT (!x.is_alive ());
        x._state = ALIVE;
        CPPUNIT_ASSERT (x.is_alive ());
    }

    void test_AbstractCell_is_alive_3 () {
        FredkinCell x;
        CPPUNIT_ASSERT (!x.is_alive ());
        x._state = ALIVE;
        CPPUNIT_ASSERT (x.is_alive ());
    }

    // --------------------------
    // AbstractCell::update_state
    // --------------------------

    void test_AbstractCell_update_state_1 () {
        ConwayCell x;
        CPPUNIT_ASSERT (x._state == DEAD);
        x.update_state (DEAD);
        CPPUNIT_ASSERT (x._state == DEAD);
    }

    void test_AbstractCell_update_state_2 () {
        ConwayCell x;
        CPPUNIT_ASSERT (x._state == DEAD);
        x.update_state (ALIVE);
        CPPUNIT_ASSERT (x._state == ALIVE);
    }

    void test_AbstractCell_update_state_3 () {
        FredkinCell x;
        CPPUNIT_ASSERT (x._state == DEAD);
        x.update_state (ALIVE);
        CPPUNIT_ASSERT (x._state == ALIVE);
    }

    // ----------------------
    // ConwayCell::ConwayCell
    // ----------------------

    void test_ConwayCell () {
        FredkinCell x;
        CPPUNIT_ASSERT (x._state == DEAD);
        CPPUNIT_ASSERT (x._age == 0);
    }

    // -----------------
    // ConwayCell::print
    // -----------------
    
    void test_ConwayCell_print_1 () {
        ConwayCell x;
        std::ostringstream w;
        x.print (w);
        CPPUNIT_ASSERT (w.str () == ".");
    }

    void test_ConwayCell_print_2 () {
        ConwayCell x;
        x._state = ALIVE;
        std::ostringstream w;
        x.print (w);
        CPPUNIT_ASSERT (w.str () == "*");
    }

    void test_ConwayCell_print_3 () {
        ConwayCell x;
        x._state = DEAD;
        std::ostringstream w;
        x.print (w);
        CPPUNIT_ASSERT (w.str () == ".");
        x._state = ALIVE;
        x.print (w);
        CPPUNIT_ASSERT (w.str () == ".*");
    }

    // --------------------------
    // ConwayCell::valid_neighbor
    // --------------------------

    void test_ConwayCell_valid_neighbor_1 () {
        ConwayCell x;
        CPPUNIT_ASSERT (x.valid_neighbor (N));
        CPPUNIT_ASSERT (x.valid_neighbor (S));
        CPPUNIT_ASSERT (x.valid_neighbor (W));
        CPPUNIT_ASSERT (x.valid_neighbor (E));
        CPPUNIT_ASSERT (x.valid_neighbor (NW));
        CPPUNIT_ASSERT (x.valid_neighbor (NE));
        CPPUNIT_ASSERT (x.valid_neighbor (SW));
        CPPUNIT_ASSERT (x.valid_neighbor (SE));
    }

    void test_ConwayCell_valid_neighbor_2 () {
        ConwayCell x;
        CPPUNIT_ASSERT (x.valid_neighbor (NW));
        CPPUNIT_ASSERT (x.valid_neighbor (NE));
        CPPUNIT_ASSERT (x.valid_neighbor (SW));
        CPPUNIT_ASSERT (x.valid_neighbor (SE));
    }

    void test_ConwayCell_valid_neighbor_3 () {
        ConwayCell x;
        ConwayCell y;
        x = y;
        CPPUNIT_ASSERT (x.valid_neighbor (N));
        CPPUNIT_ASSERT (x.valid_neighbor (S));
        CPPUNIT_ASSERT (x.valid_neighbor (W));
        CPPUNIT_ASSERT (x.valid_neighbor (E));
        CPPUNIT_ASSERT (x.valid_neighbor (NW));
        CPPUNIT_ASSERT (x.valid_neighbor (NE));
        CPPUNIT_ASSERT (x.valid_neighbor (SW));
        CPPUNIT_ASSERT (x.valid_neighbor (SE));
    }

    // ------------------
    // ConwayCell::evolve
    // ------------------

    void test_ConwayCell_evolve_1 () {
        ConwayCell x;
        CPPUNIT_ASSERT (x._state == DEAD);
        x.evolve (0);
        CPPUNIT_ASSERT (x._state == DEAD);
    }

    void test_ConwayCell_evolve_2 () {
        ConwayCell x;
        CPPUNIT_ASSERT (x._state == DEAD);
        x.evolve (3);
        CPPUNIT_ASSERT (x._state == ALIVE);
        x.evolve (2);
        CPPUNIT_ASSERT (x._state == ALIVE);
    }

    void test_ConwayCell_evolve_3 () {
        ConwayCell x;
        CPPUNIT_ASSERT (x._state == DEAD);
        x.evolve (3);
        CPPUNIT_ASSERT (x._state == ALIVE);
        x.evolve (8);
        CPPUNIT_ASSERT (x._state == DEAD);
    }

    // -------------------
    // ConwayCell::is_cell
    // -------------------

    void test_ConwayCell_is_cell_1 () {
        ConwayCell x;
        CPPUNIT_ASSERT (!x.is_cell ());
    }

    void test_ConwayCell_is_cell_2 () {
        ConwayCell x;
        ConwayCell y;
        x = y;
        CPPUNIT_ASSERT (!x.is_cell ());
        CPPUNIT_ASSERT (!y.is_cell ());
    }

    void test_ConwayCell_is_cell_3 () {
        ConwayCell x;
        x._state = ALIVE;
        CPPUNIT_ASSERT (!x.is_cell ());
    }

    // -----------------
    // ConwayCell::clone
    // -----------------

    void test_ConwayCell_clone_1 () {
        ConwayCell x;
        ConwayCell* y = x.clone ();
        CPPUNIT_ASSERT (&x != y);
    }

    void test_ConwayCell_clone_2 () {
        ConwayCell x;
        ConwayCell* y = x.clone ();
        CPPUNIT_ASSERT (x._state == y->_state);
        x._state = ALIVE;
        CPPUNIT_ASSERT (x._state != y->_state);
    }

    void test_ConwayCell_clone_3 () {
        ConwayCell x;
        x._state = ALIVE;
        ConwayCell* y = x.clone ();
        CPPUNIT_ASSERT (x._state == y->_state);
        x._state = DEAD;
        ConwayCell* z = x.clone ();
        CPPUNIT_ASSERT (x._state == z->_state);
        CPPUNIT_ASSERT (y->_state != z->_state);
        CPPUNIT_ASSERT (&x != y);
        CPPUNIT_ASSERT (&x != z);
        CPPUNIT_ASSERT (y != z);
    }

    // ------------------------
    // FredkinCell::FredkinCell
    // ------------------------

    void test_FredkinCell () {
        FredkinCell x;
        CPPUNIT_ASSERT (x._state == DEAD);
        CPPUNIT_ASSERT (x._age == 0);
    }

    // ------------------
    // FredkinCell::print
    // ------------------

    void test_FredkinCell_print_1 () {
        FredkinCell x;
        std::ostringstream w;
        x.print (w);
        CPPUNIT_ASSERT (w.str () == "-");
    }

    void test_FredkinCell_print_2 () {
        FredkinCell x;
        x._state = ALIVE;
        std::ostringstream w;
        x.print (w);
        CPPUNIT_ASSERT (w.str () == "0");
        x._age = 5;
        x.print (w);
        CPPUNIT_ASSERT (w.str () == "05");
    }

    void test_FredkinCell_print_3 () {
        FredkinCell x;
        x._state = ALIVE;
        x._age = 100;
        std::ostringstream w;
        x.print (w);
        CPPUNIT_ASSERT (w.str () == "+");
        x._state = DEAD;
        x.print (w);
        CPPUNIT_ASSERT (w.str () == "+-");
        x._state = ALIVE;
        x._age = 7;
        x.print (w);
        CPPUNIT_ASSERT (w.str () == "+-7");
    }

    // ---------------------------
    // FredkinCell::valid_neighbor
    // ---------------------------

    void test_FredkinCell_valid_neighbor_1 () {
        FredkinCell x;
        CPPUNIT_ASSERT (x.valid_neighbor (N));
        CPPUNIT_ASSERT (x.valid_neighbor (S));
        CPPUNIT_ASSERT (x.valid_neighbor (W));
        CPPUNIT_ASSERT (x.valid_neighbor (E));
    }

    void test_FredkinCell_valid_neighbor_2 () {
        FredkinCell x;
        CPPUNIT_ASSERT (!x.valid_neighbor (NW));
        CPPUNIT_ASSERT (!x.valid_neighbor (NE));
        CPPUNIT_ASSERT (!x.valid_neighbor (SW));
        CPPUNIT_ASSERT (!x.valid_neighbor (SE));
    }

    void test_FredkinCell_valid_neighbor_3 () {
        FredkinCell x;
        FredkinCell y;
        x = y;
        CPPUNIT_ASSERT (x.valid_neighbor (N));
        CPPUNIT_ASSERT (x.valid_neighbor (S));
        CPPUNIT_ASSERT (x.valid_neighbor (W));
        CPPUNIT_ASSERT (x.valid_neighbor (E));
        CPPUNIT_ASSERT (!x.valid_neighbor (NW));
        CPPUNIT_ASSERT (!x.valid_neighbor (NE));
        CPPUNIT_ASSERT (!x.valid_neighbor (SW));
        CPPUNIT_ASSERT (!x.valid_neighbor (SE));
    }

    // -------------------
    // FredkinCell::evolve
    // -------------------

    void test_FredkinCell_evolve_1 () {
        FredkinCell x;
        CPPUNIT_ASSERT (x._state == DEAD);
        CPPUNIT_ASSERT (x._age == 0);
        x.evolve (2);
        CPPUNIT_ASSERT (x._state == DEAD);
        CPPUNIT_ASSERT (x._age == 0);
    }

    void test_FredkinCell_evolve_2 () {
        FredkinCell x;
        CPPUNIT_ASSERT (x._state == DEAD);
        CPPUNIT_ASSERT (x._age == 0);
        x.evolve (1);
        CPPUNIT_ASSERT (x._state == ALIVE);
        CPPUNIT_ASSERT (x._age == 0);
        x.evolve (1);
        CPPUNIT_ASSERT (x._state == ALIVE);
        CPPUNIT_ASSERT (x._age == 1);
    }

    void test_FredkinCell_evolve_3 () {
        FredkinCell x;
        CPPUNIT_ASSERT (x._state == DEAD);
        CPPUNIT_ASSERT (x._age == 0);
        x.evolve (1);
        CPPUNIT_ASSERT (x._state == ALIVE);
        CPPUNIT_ASSERT (x._age == 0);
        x.evolve (0);
        CPPUNIT_ASSERT (x._state == DEAD);
        CPPUNIT_ASSERT (x._age == 0);
    }

    // --------------------
    // FredkinCell::is_cell
    // --------------------

    void test_FredkinCell_is_cell_1 () {
        FredkinCell x;
        CPPUNIT_ASSERT (!x.is_cell ());
    }

    void test_FredkinCell_is_cell_2 () {
        FredkinCell x;
        FredkinCell y;
        x = y;
        CPPUNIT_ASSERT (!x.is_cell ());
        CPPUNIT_ASSERT (!y.is_cell ());
    }

    void test_FredkinCell_is_cell_3 () {
        FredkinCell x;
        x._state = ALIVE;
        x._age = 10;
        CPPUNIT_ASSERT (!x.is_cell ());
    }

    // ------------------
    // FredkinCell::clone
    // ------------------

    void test_FredkinCell_clone_1 () {
        FredkinCell x;
        FredkinCell* y = x.clone ();
        CPPUNIT_ASSERT (&x != y);
    }

    void test_FredkinCell_clone_2 () {
        FredkinCell x;
        FredkinCell* y = x.clone ();
        CPPUNIT_ASSERT (x._state == y->_state);
        CPPUNIT_ASSERT (x._age == y->_age);
        x._state = ALIVE;
        x._age = 10;
        CPPUNIT_ASSERT (x._state != y->_state);
        CPPUNIT_ASSERT (x._age != y->_age);
    }

    void test_FredkinCell_clone_3 () {
        FredkinCell x;
        x._state = ALIVE;
        x._age = 5;
        FredkinCell* y = x.clone ();
        CPPUNIT_ASSERT (x._state == y->_state);
        CPPUNIT_ASSERT (x._age == y->_age);
        x._state = DEAD;
        x._age = 10;
        FredkinCell* z = x.clone ();
        CPPUNIT_ASSERT (x._state == z->_state);
        CPPUNIT_ASSERT (x._age == z->_age);
        CPPUNIT_ASSERT (y->_state != z->_state);
        CPPUNIT_ASSERT (y->_age != z->_age);
        CPPUNIT_ASSERT (&x != y);
        CPPUNIT_ASSERT (&x != z);
        CPPUNIT_ASSERT (y != z);
    }

    // --------------------
    // Cell::Cell (DEFAULT)
    // --------------------

    void test_Cell_default () {
        Cell x;
        CPPUNIT_ASSERT (x._p != NULL);
        CPPUNIT_ASSERT (x._p->_state == DEAD);
    }

    // -----------------
    // Cell::Cell (COPY)
    // -----------------

    void test_Cell_copy_1 () {
        ConwayCell* c = new ConwayCell ();
        Cell x = c;
        CPPUNIT_ASSERT (x._p == c);
        CPPUNIT_ASSERT (x._p->_state == DEAD);
    }

    void test_Cell_copy_2 () {
        FredkinCell* f = new FredkinCell ();
        Cell x = f;
        CPPUNIT_ASSERT (x._p == f);
        CPPUNIT_ASSERT (x._p->_state == DEAD);
    }

    // -----------
    // Cell::print
    // -----------

    void test_Cell_print_1 () {
        Cell x = new ConwayCell ();
        x._p->_state = ALIVE;
        std::ostringstream w;
        x.print (w);
        CPPUNIT_ASSERT (w.str () == "*");
        x._p->_state = DEAD;
        x.print (w);
        CPPUNIT_ASSERT (w.str () == "*.");
    }

    void test_Cell_print_2 () {
        Cell x = new FredkinCell ();
        x._p->_state = ALIVE;
        std::ostringstream w;
        x.print (w);
        CPPUNIT_ASSERT (w.str () == "0");
        x._p->_state = DEAD;
        x.print (w);
        CPPUNIT_ASSERT (w.str () == "0-");
    }

    void test_Cell_print_3 () {
        ConwayCell* c = new ConwayCell ();
        FredkinCell* f = new FredkinCell ();
        Cell x = f;
        x._p->_state = ALIVE;
        std::ostringstream w;
        x.print (w);
        CPPUNIT_ASSERT (w.str () == "0");
        x._p->_state = DEAD;
        x.print (w);
        CPPUNIT_ASSERT (w.str () == "0-");
        x = c;
        x._p->_state = ALIVE;
        x.print (w);
        CPPUNIT_ASSERT (w.str () == "0-*");
        x._p->_state = DEAD;
        x.print (w);
        CPPUNIT_ASSERT (w.str () == "0-*.");
    }

    // --------------------
    // Cell::valid_neighbor
    // --------------------

    void test_Cell_valid_neighbor_1 () {
        Cell x;
        CPPUNIT_ASSERT (x.valid_neighbor (N));
        CPPUNIT_ASSERT (x.valid_neighbor (S));
        CPPUNIT_ASSERT (x.valid_neighbor (W));
        CPPUNIT_ASSERT (x.valid_neighbor (E));
        CPPUNIT_ASSERT (!x.valid_neighbor (NW));
        CPPUNIT_ASSERT (!x.valid_neighbor (NE));
        CPPUNIT_ASSERT (!x.valid_neighbor (SW));
        CPPUNIT_ASSERT (!x.valid_neighbor (SE));
    }

    void test_Cell_valid_neighbor_2 () {
        Cell x = new ConwayCell ();
        CPPUNIT_ASSERT (x.valid_neighbor (N));
        CPPUNIT_ASSERT (x.valid_neighbor (S));
        CPPUNIT_ASSERT (x.valid_neighbor (W));
        CPPUNIT_ASSERT (x.valid_neighbor (E));
        CPPUNIT_ASSERT (x.valid_neighbor (NW));
        CPPUNIT_ASSERT (x.valid_neighbor (NE));
        CPPUNIT_ASSERT (x.valid_neighbor (SW));
        CPPUNIT_ASSERT (x.valid_neighbor (SE));
    }

    void test_Cell_valid_neighbor_3 () {
        Cell x = new FredkinCell ();
        CPPUNIT_ASSERT (x.valid_neighbor (N));
        CPPUNIT_ASSERT (x.valid_neighbor (S));
        CPPUNIT_ASSERT (x.valid_neighbor (W));
        CPPUNIT_ASSERT (x.valid_neighbor (E));
        CPPUNIT_ASSERT (!x.valid_neighbor (NW));
        CPPUNIT_ASSERT (!x.valid_neighbor (NE));
        CPPUNIT_ASSERT (!x.valid_neighbor (SW));
        CPPUNIT_ASSERT (!x.valid_neighbor (SE));
    }

    // ------------
    // Cell::evolve
    // ------------

    void test_Cell_evolve_1 () {
        Cell x;
        CPPUNIT_ASSERT (x._p->_state == DEAD);
        x.evolve (2);
        CPPUNIT_ASSERT (x._p->_state == DEAD);
    }

    void test_Cell_evolve_2 () {
        Cell x = new ConwayCell ();
        CPPUNIT_ASSERT (x._p->_state == DEAD);
        x.evolve (3);
        CPPUNIT_ASSERT (x._p->_state == ALIVE);
        x.evolve (2);
        CPPUNIT_ASSERT (x._p->_state == ALIVE);
    }

    void test_Cell_evolve_3 () {
        Cell x = new FredkinCell ();
        CPPUNIT_ASSERT (x._p->_state == DEAD);
        x.evolve (1);
        CPPUNIT_ASSERT (x._p->_state == ALIVE);
        x.evolve (0);
        CPPUNIT_ASSERT (x._p->_state == DEAD);
    }

    // --------------
    // Cell::is_alive
    // --------------

    void test_Cell_is_alive_1 () {
        Cell x;
        CPPUNIT_ASSERT (!x.is_alive ());
    }

    void test_Cell_is_alive_2 () {
        Cell x = new ConwayCell ();
        CPPUNIT_ASSERT (!x.is_alive ());
        x._p->_state = ALIVE;
        CPPUNIT_ASSERT (x.is_alive ());
    }

    void test_Cell_is_alive_3 () {
        Cell x = new FredkinCell ();
        CPPUNIT_ASSERT (!x.is_alive ());
        x._p->_state = ALIVE;
        CPPUNIT_ASSERT (x.is_alive ());
    }

    // ------------------
    // Cell::update_state
    // ------------------

    void test_Cell_update_state_1 () {
        Cell x;
        CPPUNIT_ASSERT (x._p->_state == DEAD);
        x.update_state (DEAD);
        CPPUNIT_ASSERT (x._p->_state == DEAD);
    }

    void test_Cell_update_state_2 () {
        Cell x = new ConwayCell ();
        CPPUNIT_ASSERT (x._p->_state == DEAD);
        x.update_state (ALIVE);
        CPPUNIT_ASSERT (x._p->_state == ALIVE);
    }

    void test_Cell_update_state_3 () {
        Cell x = new FredkinCell ();
        CPPUNIT_ASSERT (x._p->_state == DEAD);
        x.update_state (ALIVE);
        CPPUNIT_ASSERT (x._p->_state == ALIVE);
    }

    // ------------
    // Cell::mutate
    // ------------

    void test_Cell_mutate_1 () {
        Cell x;
        x._p->_state = ALIVE;
        x.mutate ();
        CPPUNIT_ASSERT (x._p->_state == DEAD);
    }

    void test_Cell_mutate_2 () {
        ConwayCell* c = new ConwayCell ();
        Cell x = c;
        x._p->_state = ALIVE;
        x.mutate ();
        CPPUNIT_ASSERT (x._p->_state == DEAD);
        CPPUNIT_ASSERT (x._p != c);
    }

    void test_Cell_mutate_3 () {
        FredkinCell* f = new FredkinCell ();
        Cell x = f;
        x._p->_state = ALIVE;
        x.mutate ();
        CPPUNIT_ASSERT (x._p->_state == DEAD);
        CPPUNIT_ASSERT (x._p != f);
    }    

    // -------------
    // Cell::is_cell
    // -------------

    void test_Cell_is_cell_1 () {
        Cell x;
        CPPUNIT_ASSERT (x.is_cell ());
    }

    void test_Cell_is_cell_2 () {
        Cell x = new ConwayCell ();
        CPPUNIT_ASSERT (x.is_cell ());
    }

    void test_Cell_is_cell_3 () {
        Cell x = new FredkinCell ();
        CPPUNIT_ASSERT (x.is_cell ());
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE (TestLife);
    // Life Tests
    CPPUNIT_TEST (test_Life_1);
    CPPUNIT_TEST (test_Life_2);
    CPPUNIT_TEST (test_Life_3);
    CPPUNIT_TEST (test_Life_place_1);
    CPPUNIT_TEST (test_Life_place_2);
    CPPUNIT_TEST (test_Life_place_3);
    CPPUNIT_TEST (test_Life_simulate_1);
    CPPUNIT_TEST (test_Life_simulate_2);
    CPPUNIT_TEST (test_Life_simulate_3);
    CPPUNIT_TEST (test_Life_print_1);
    CPPUNIT_TEST (test_Life_print_2);
    CPPUNIT_TEST (test_Life_print_3);
    CPPUNIT_TEST (test_Life_check_neighbor_1);
    CPPUNIT_TEST (test_Life_check_neighbor_2);
    CPPUNIT_TEST (test_Life_check_neighbor_3);
    // AbstractCell Tests
    CPPUNIT_TEST (test_AbstractCell_is_alive_1);
    CPPUNIT_TEST (test_AbstractCell_is_alive_2);
    CPPUNIT_TEST (test_AbstractCell_is_alive_3);
    CPPUNIT_TEST (test_AbstractCell_update_state_1);
    CPPUNIT_TEST (test_AbstractCell_update_state_2);
    CPPUNIT_TEST (test_AbstractCell_update_state_3);
    // ConwayCell Tests
    CPPUNIT_TEST (test_ConwayCell);
    CPPUNIT_TEST (test_ConwayCell_print_1);
    CPPUNIT_TEST (test_ConwayCell_print_2);
    CPPUNIT_TEST (test_ConwayCell_print_3);
    CPPUNIT_TEST (test_ConwayCell_valid_neighbor_1);
    CPPUNIT_TEST (test_ConwayCell_valid_neighbor_2);
    CPPUNIT_TEST (test_ConwayCell_valid_neighbor_3);
    CPPUNIT_TEST (test_ConwayCell_evolve_1);
    CPPUNIT_TEST (test_ConwayCell_evolve_2);
    CPPUNIT_TEST (test_ConwayCell_evolve_3);
    CPPUNIT_TEST (test_ConwayCell_is_cell_1);
    CPPUNIT_TEST (test_ConwayCell_is_cell_2);
    CPPUNIT_TEST (test_ConwayCell_is_cell_3);
    CPPUNIT_TEST (test_ConwayCell_clone_1);
    CPPUNIT_TEST (test_ConwayCell_clone_2);
    CPPUNIT_TEST (test_ConwayCell_clone_3);
    // FredkinCell Tests
    CPPUNIT_TEST (test_FredkinCell);
    CPPUNIT_TEST (test_FredkinCell_print_1);
    CPPUNIT_TEST (test_FredkinCell_print_2);
    CPPUNIT_TEST (test_FredkinCell_print_3);
    CPPUNIT_TEST (test_FredkinCell_valid_neighbor_1);
    CPPUNIT_TEST (test_FredkinCell_valid_neighbor_1);
    CPPUNIT_TEST (test_FredkinCell_valid_neighbor_1);
    CPPUNIT_TEST (test_FredkinCell_evolve_1);
    CPPUNIT_TEST (test_FredkinCell_evolve_2);
    CPPUNIT_TEST (test_FredkinCell_evolve_3);
    CPPUNIT_TEST (test_FredkinCell_is_cell_1);
    CPPUNIT_TEST (test_FredkinCell_is_cell_2);
    CPPUNIT_TEST (test_FredkinCell_is_cell_3);
    CPPUNIT_TEST (test_FredkinCell_clone_1);
    CPPUNIT_TEST (test_FredkinCell_clone_2);
    CPPUNIT_TEST (test_FredkinCell_clone_3);
    // Cell Tests
    CPPUNIT_TEST (test_Cell_default);
    CPPUNIT_TEST (test_Cell_copy_1);
    CPPUNIT_TEST (test_Cell_copy_2);
    CPPUNIT_TEST (test_Cell_print_1);
    CPPUNIT_TEST (test_Cell_print_2);
    CPPUNIT_TEST (test_Cell_print_3);
    CPPUNIT_TEST (test_Cell_valid_neighbor_1);
    CPPUNIT_TEST (test_Cell_valid_neighbor_2);
    CPPUNIT_TEST (test_Cell_valid_neighbor_3);
    CPPUNIT_TEST (test_Cell_evolve_1);
    CPPUNIT_TEST (test_Cell_evolve_2);
    CPPUNIT_TEST (test_Cell_evolve_3);
    CPPUNIT_TEST (test_Cell_is_alive_1);
    CPPUNIT_TEST (test_Cell_is_alive_2);
    CPPUNIT_TEST (test_Cell_is_alive_3);
    CPPUNIT_TEST (test_Cell_update_state_1);
    CPPUNIT_TEST (test_Cell_update_state_2);
    CPPUNIT_TEST (test_Cell_update_state_3);
    CPPUNIT_TEST (test_Cell_mutate_1);
    CPPUNIT_TEST (test_Cell_mutate_2);
    CPPUNIT_TEST (test_Cell_mutate_3);
    CPPUNIT_TEST (test_Cell_is_cell_1);
    CPPUNIT_TEST (test_Cell_is_cell_2);
    CPPUNIT_TEST (test_Cell_is_cell_3);
    CPPUNIT_TEST_SUITE_END ();
};

int main () {
    using namespace std;
    ios_base::sync_with_stdio (false); // turn off synchronization with C I/O
    cout << "TestLife.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest (TestLife::suite ());
    tr.run ();

    cout << "Done." << endl;
    return 0;
}