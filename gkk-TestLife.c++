#include <algorithm> // count
#include <iostream>  // ios_base
#include <vector>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define class struct
#define private public
#define protected public

#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

using namespace std;

struct TestLife : CppUnit::TestFixture {
    // -----------
    // test_conway
    // -----------

    void test_conway_turn_1()
    {
        ConwayCell cell(false);
        CPPUNIT_ASSERT(!cell.get_alive());
        cell.turn(0, 0);
        CPPUNIT_ASSERT(!cell.get_alive());
        cell.turn(1, 1);
        CPPUNIT_ASSERT(!cell.get_alive());
        cell.turn(2, 2);
        CPPUNIT_ASSERT(!cell.get_alive());
        cell.turn(3, 3);
        CPPUNIT_ASSERT(!cell.get_alive());
        cell.turn(4, 4);
        CPPUNIT_ASSERT(!cell.get_alive());
    }

    void test_conway_turn_2()
    {
        ConwayCell cell(true);
        CPPUNIT_ASSERT(cell.get_alive());
        cell.turn(1, 1);
        CPPUNIT_ASSERT(cell.get_alive());
        cell.turn(1, 2);
        CPPUNIT_ASSERT(cell.get_alive());
        cell.turn(2, 1);
        CPPUNIT_ASSERT(cell.get_alive());
        cell.turn(3, 0);
        CPPUNIT_ASSERT(cell.get_alive());
        cell.turn(0, 3);
        CPPUNIT_ASSERT(cell.get_alive());
    }

    void test_conway_turn_3()
    {
        ConwayCell cell(false);
        CPPUNIT_ASSERT(!cell.get_alive());
        cell.turn(3, 0);
        CPPUNIT_ASSERT(cell.get_alive());
        cell.turn(0, 1);
        CPPUNIT_ASSERT(!cell.get_alive());
        cell.turn(2, 1);
        CPPUNIT_ASSERT(cell.get_alive());
        cell.turn(3, 1);
        CPPUNIT_ASSERT(!cell.get_alive());
        cell.turn(0, 3);
        CPPUNIT_ASSERT(cell.get_alive());
    }

    void test_conway_clone_1()
    {
        ConwayCell cell(false);
        AbstractCell* cell2 = cell.clone();
        CPPUNIT_ASSERT(&cell != cell2);
        CPPUNIT_ASSERT(!cell.get_alive());
        CPPUNIT_ASSERT(!cell2->get_alive());
        delete cell2;
    }

    void test_conway_clone_2()
    {
        ConwayCell cell(true);
        AbstractCell* cell2 = cell.clone();
        CPPUNIT_ASSERT(&cell != cell2);
        CPPUNIT_ASSERT(cell.get_alive());
        CPPUNIT_ASSERT(cell2->get_alive());
        delete cell2;
    }

    void test_conway_clone_3()
    {
        ConwayCell cell(false);
        AbstractCell* cell2 = cell.clone();
        cell2->set_alive(true);
        CPPUNIT_ASSERT(&cell != cell2);
        CPPUNIT_ASSERT(!cell.get_alive());
        CPPUNIT_ASSERT(cell2->get_alive());
        delete cell2;
    }

    void test_conway_mutate_1()
    {
        ConwayCell cell(false);
        CPPUNIT_ASSERT(cell.mutate() == 0);
    }

    void test_conway_mutate_2()
    {
        ConwayCell cell(true);
        CPPUNIT_ASSERT(cell.mutate() == 0);
    }

    // ------------
    // test_fredkin
    // ------------

    void test_fredkin_turn_1()
    {
        FredkinCell cell(false);
        CPPUNIT_ASSERT(!cell.get_alive());
        for (int i = 0; i <= 4; ++i) {
            cell.turn(0, i);
            CPPUNIT_ASSERT(!cell.get_alive());
            cell.turn(2, i);
            CPPUNIT_ASSERT(!cell.get_alive());
            cell.turn(4, i);
            CPPUNIT_ASSERT(!cell.get_alive());
        }
    }

    void test_fredkin_turn_2()
    {
        FredkinCell cell(true);
        CPPUNIT_ASSERT(cell.get_alive());
        for (int i = 0; i <= 4; ++i) {
            cell.turn(1, i);
            CPPUNIT_ASSERT(cell.get_alive());
            cell.turn(3, i);
            CPPUNIT_ASSERT(cell.get_alive());
        }
    }

    void test_fredkin_turn_3()
    {
        FredkinCell cell(false);
        CPPUNIT_ASSERT(!cell.get_alive());
        for (int i = 0; i <= 4; ++i) {
            cell.turn(0, i);
            CPPUNIT_ASSERT(!cell.get_alive());
            cell.turn(1, i);
            CPPUNIT_ASSERT(cell.get_alive());
            cell.turn(2, i);
            CPPUNIT_ASSERT(!cell.get_alive());
            cell.turn(3, i);
            CPPUNIT_ASSERT(cell.get_alive());
            cell.turn(4, i);
            CPPUNIT_ASSERT(!cell.get_alive());
        }
    }

    void test_fredkin_clone_1()
    {
        FredkinCell cell(false);
        AbstractCell* cell2 = cell.clone();
        CPPUNIT_ASSERT(&cell != cell2);
        CPPUNIT_ASSERT(!cell.get_alive());
        CPPUNIT_ASSERT(!cell2->get_alive());
        delete cell2;
    }

    void test_fredkin_clone_2()
    {
        FredkinCell cell(true);
        AbstractCell* cell2 = cell.clone();
        CPPUNIT_ASSERT(&cell != cell2);
        CPPUNIT_ASSERT(cell.get_alive());
        CPPUNIT_ASSERT(cell2->get_alive());
        delete cell2;
    }

    void test_fredkin_clone_3()
    {
        FredkinCell cell(false);
        AbstractCell* cell2 = cell.clone();
        cell2->set_alive(true);
        CPPUNIT_ASSERT(&cell != cell2);
        CPPUNIT_ASSERT(!cell.get_alive());
        CPPUNIT_ASSERT(cell2->get_alive());
        delete cell2;
    }

    void test_fredkin_mutate_1()
    {
        FredkinCell cell(false);
        CPPUNIT_ASSERT(cell.mutate() == 0);
    }

    void test_fredkin_mutate_2()
    {
        FredkinCell cell(true);
        CPPUNIT_ASSERT(cell.mutate() == 0);
    }

    void test_fredkin_mutate_3()
    {
        FredkinCell cell(true);
        cell.turn(1, 0);

        AbstractCell* cell2 = cell.mutate();
        CPPUNIT_ASSERT(cell2 == 0);
        delete cell2;
    }

    void test_fredkin_mutate_4()
    {
        FredkinCell cell(true);
        cell.turn(1, 0);
        cell.turn(1, 0);

        AbstractCell* cell2 = cell.mutate();
        CPPUNIT_ASSERT(cell2 != 0);
        delete cell2;
    }

    // ---------
    // test_cell
    // ---------

    void test_cell_turn_1() {
        Cell cell = new ConwayCell();
        cell.turn(3, 0);
        CPPUNIT_ASSERT(cell.get_alive());
        cell.turn(0, 0);
        CPPUNIT_ASSERT(!cell.get_alive());
    }

    void test_cell_turn_2() {
        Cell cell = new FredkinCell();
        cell.turn(3, 0);
        CPPUNIT_ASSERT(cell.get_alive());
        cell.turn(0, 3);
        CPPUNIT_ASSERT(!cell.get_alive());
    }

    void test_cell_turn_3() {
        Cell cell = new FredkinCell(true);
        cell.turn(3, 0);
        CPPUNIT_ASSERT(cell.get_alive());
        cell.turn(3, 0);
        CPPUNIT_ASSERT(cell.get_alive());
        cell.turn(0, 3);
        CPPUNIT_ASSERT(cell.get_alive());
    }

    // ---------
    // test_life
    // ---------

    void test_life_set_cell_1() {
        Life<ConwayCell> life(2, 2);
        life.set_cell(0, 0, true);
        life.set_cell(0, 1, false);
        life.set_cell(1, 0, false);
        life.set_cell(1, 1, true);
        CPPUNIT_ASSERT(life.cell(0, 0).get_alive());
        CPPUNIT_ASSERT(!life.cell(0, 1).get_alive());
        CPPUNIT_ASSERT(!life.cell(1, 0).get_alive());
        CPPUNIT_ASSERT(life.cell(1, 1).get_alive());
    }

    void test_life_set_cell_2() {
        Life<FredkinCell> life(2, 2);
        life.set_cell(0, 0, true);
        life.set_cell(0, 1, false);
        life.set_cell(1, 0, false);
        life.set_cell(1, 1, true);
        CPPUNIT_ASSERT(life.cell(0, 0).get_alive());
        CPPUNIT_ASSERT(!life.cell(0, 1).get_alive());
        CPPUNIT_ASSERT(!life.cell(1, 0).get_alive());
        CPPUNIT_ASSERT(life.cell(1, 1).get_alive());
    }

    void test_life_set_cell_3() {
        Life<Cell> life(2, 2);
        life.set_cell(0, 0, new ConwayCell(true));
        life.set_cell(0, 1, new ConwayCell(false));
        life.set_cell(1, 0, new FredkinCell(false));
        life.set_cell(1, 1, new FredkinCell(true));
        CPPUNIT_ASSERT(life.cell(0, 0).get_alive());
        CPPUNIT_ASSERT(!life.cell(0, 1).get_alive());
        CPPUNIT_ASSERT(!life.cell(1, 0).get_alive());
        CPPUNIT_ASSERT(life.cell(1, 1).get_alive());
    }

    void test_life_simulate_1() {
        Life<ConwayCell> life(2, 2);
        life.set_cell(0, 0, true);
        life.set_cell(0, 1, true);
        life.set_cell(1, 0, true);
        life.set_cell(1, 1, true);
        for (int i = 0; i < 100; ++i) {
            life.simulate(1);
            CPPUNIT_ASSERT(life.cell(0, 0).get_alive());
            CPPUNIT_ASSERT(life.cell(0, 1).get_alive());
            CPPUNIT_ASSERT(life.cell(1, 0).get_alive());
            CPPUNIT_ASSERT(life.cell(1, 1).get_alive());
        }
    }

    void test_life_simulate_2() {
        Life<FredkinCell> life(3, 3);
        life.set_cell(1, 1, true);
        life.simulate(1);
        CPPUNIT_ASSERT(!life.cell(0, 0).get_alive());
        CPPUNIT_ASSERT(life.cell(1, 0).get_alive());
        CPPUNIT_ASSERT(!life.cell(2, 0).get_alive());
        CPPUNIT_ASSERT(life.cell(0, 1).get_alive());
        CPPUNIT_ASSERT(!life.cell(1, 1).get_alive());
        CPPUNIT_ASSERT(life.cell(2, 1).get_alive());
        CPPUNIT_ASSERT(!life.cell(0, 2).get_alive());
        CPPUNIT_ASSERT(life.cell(1, 2).get_alive());
        CPPUNIT_ASSERT(!life.cell(2, 2).get_alive());
    }

    void test_life_simulate_3() {
        srand(0);
        Life<Cell> life(10, 10);
        Life<Cell> life2(10, 10);
        for (int y = 0; y < 10; ++y) {
            for (int x = 0; x < 10; ++x) {
                bool alive = rand() % 2;
                life.set_cell(x, y, new FredkinCell(alive));
                life2.set_cell(x, y, new FredkinCell(alive));
            }
        }

        life.simulate(100);
        for (int i = 0; i < 100; ++i) {
            life2.simulate();
        }

        for (int y = 0; y < 10; ++y) {
            for (int x = 0; x < 10; ++x) {
                CPPUNIT_ASSERT(life.cell(x, y).get_alive() == life2.cell(x, y).get_alive());
            }
        }
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST(test_conway_turn_1);
    CPPUNIT_TEST(test_conway_turn_2);
    CPPUNIT_TEST(test_conway_turn_3);
    CPPUNIT_TEST(test_conway_clone_1);
    CPPUNIT_TEST(test_conway_clone_2);
    CPPUNIT_TEST(test_conway_clone_3);
    CPPUNIT_TEST(test_conway_mutate_1);
    CPPUNIT_TEST(test_conway_mutate_2);
    CPPUNIT_TEST(test_fredkin_turn_1);
    CPPUNIT_TEST(test_fredkin_turn_2);
    CPPUNIT_TEST(test_fredkin_turn_3);
    CPPUNIT_TEST(test_fredkin_clone_1);
    CPPUNIT_TEST(test_fredkin_clone_2);
    CPPUNIT_TEST(test_fredkin_clone_3);
    CPPUNIT_TEST(test_fredkin_mutate_1);
    CPPUNIT_TEST(test_fredkin_mutate_2);
    CPPUNIT_TEST(test_fredkin_mutate_3);
    CPPUNIT_TEST(test_fredkin_mutate_4);
    CPPUNIT_TEST(test_cell_turn_1);
    CPPUNIT_TEST(test_cell_turn_2);
    CPPUNIT_TEST(test_cell_turn_3);
    CPPUNIT_TEST(test_life_set_cell_1);
    CPPUNIT_TEST(test_life_set_cell_2);
    CPPUNIT_TEST(test_life_set_cell_3);
    CPPUNIT_TEST(test_life_simulate_1);
    CPPUNIT_TEST(test_life_simulate_2);
    CPPUNIT_TEST(test_life_simulate_3);
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
