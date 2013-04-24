/*
  cs371p Life
  Authors
  -------
  Name:  Bulat Bazarbayev
  csid:  bb26332
  utEID: bb26332

  Name:  Chris Word
  csid:  word
  udEID: cword

 */
#include <iostream> 
#include <sstream>  
#include <string>   

#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/TestFixture.h"            
#include "cppunit/TextTestRunner.h"         

#define private public
#define protected public

#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Life.h"
#include "Surrounding.h"
#include "Board.h"
// -----------
// TestLife
// -----------

struct TestLife : CppUnit::TestFixture {

    // ----
    // read
    // ----

    void fredkin_construction_true () {
        FredkinCell tester(true);
        CPPUNIT_ASSERT(tester.toString(0)=="0");
        CPPUNIT_ASSERT(tester.toString(1)=="-");
    }

    void fredkin_construction_false () {
        FredkinCell tester(false);
        CPPUNIT_ASSERT(tester.toString(0)=="-");
        CPPUNIT_ASSERT(tester.toString(1)=="-");
    }

    void cell_construction_true () {
        Cell tester(true);
        CPPUNIT_ASSERT(tester.toString(0)=="0");
        CPPUNIT_ASSERT(tester.toString(1)=="-");
    }

    void cell_construction_false () {
        Cell tester(false);
        CPPUNIT_ASSERT(tester.toString(0)=="-");
        CPPUNIT_ASSERT(tester.toString(1)=="-");
    }


    void conway_construction_true () {
        ConwayCell tester(true);
        CPPUNIT_ASSERT(tester.toString(0)=="*");
        CPPUNIT_ASSERT(tester.toString(1)==".");
    }

    void conway_construction_false () {
        ConwayCell tester(false);
        CPPUNIT_ASSERT(tester.toString(0)==".");
        CPPUNIT_ASSERT(tester.toString(1)==".");
    }

    void construction_surroundings_all () {
        Surrounding allLive(-1,1,1);
        CPPUNIT_ASSERT(allLive.check_north());
        CPPUNIT_ASSERT(allLive.check_n_east());
        CPPUNIT_ASSERT(allLive.check_east());
        CPPUNIT_ASSERT(allLive.check_s_east());
        CPPUNIT_ASSERT(allLive.check_south());
        CPPUNIT_ASSERT(allLive.check_s_west());
        CPPUNIT_ASSERT(allLive.check_west());
        CPPUNIT_ASSERT(allLive.check_n_west());


    }

    void construction_surroundings_dead () {
        Surrounding noLive(0,0,0);
        CPPUNIT_ASSERT(!noLive.check_north());
        CPPUNIT_ASSERT(!noLive.check_n_east());
        CPPUNIT_ASSERT(!noLive.check_east());
        CPPUNIT_ASSERT(!noLive.check_s_east());
        CPPUNIT_ASSERT(!noLive.check_south());
        CPPUNIT_ASSERT(!noLive.check_s_west());
        CPPUNIT_ASSERT(!noLive.check_west());
        CPPUNIT_ASSERT(!noLive.check_n_west());
    }

    void construction_surroundings_n_e () {
        Surrounding someLive(EAST | NORTH,0,0);
        CPPUNIT_ASSERT(someLive.check_north());
        CPPUNIT_ASSERT(!someLive.check_n_east());
        CPPUNIT_ASSERT(someLive.check_east());
        CPPUNIT_ASSERT(!someLive.check_s_east());
        CPPUNIT_ASSERT(!someLive.check_south());
        CPPUNIT_ASSERT(!someLive.check_s_west());
        CPPUNIT_ASSERT(!someLive.check_west());
        CPPUNIT_ASSERT(!someLive.check_n_west());
    }

    void conway_maketurn_1 () {
        ConwayCell tester(true);
        Surrounding someLive(EAST | NORTH | SOUTH ,0,0);
        tester.make_turn(someLive,0);
        CPPUNIT_ASSERT(tester.toString(0)=="*");
        CPPUNIT_ASSERT(tester.toString(1)=="*");
        tester.make_turn(someLive,1);
        CPPUNIT_ASSERT(tester.toString(0)=="*");
        CPPUNIT_ASSERT(tester.toString(1)=="*");
        tester.make_turn(someLive,2);
        CPPUNIT_ASSERT(tester.toString(0)=="*");
        CPPUNIT_ASSERT(tester.toString(1)=="*");
    }
    void conway_maketurn_2 () {
        ConwayCell tester(true);
        Surrounding live(EAST | NORTH | SOUTH,0,0);
        Surrounding die(0,0,0);
        tester.make_turn(live,0);
        CPPUNIT_ASSERT(tester.toString(0)=="*");
        CPPUNIT_ASSERT(tester.toString(1)=="*");
        tester.make_turn(die,1);
        CPPUNIT_ASSERT(tester.toString(0)==".");
        CPPUNIT_ASSERT(tester.toString(1)=="*");
        tester.make_turn(die,2);
        CPPUNIT_ASSERT(tester.toString(0)==".");
        CPPUNIT_ASSERT(tester.toString(1)==".");
    }

    void conway_maketurn_3 () {
        ConwayCell tester(false);
        Surrounding live(EAST | NORTH | SOUTH,0,0);
        Surrounding die(0,0,0);
        tester.make_turn(live,0);
        CPPUNIT_ASSERT(tester.toString(0)==".");
        CPPUNIT_ASSERT(tester.toString(1)=="*");
        tester.make_turn(live,1);
        CPPUNIT_ASSERT(tester.toString(0)=="*");
        CPPUNIT_ASSERT(tester.toString(1)=="*");
        tester.make_turn(die,2);
        CPPUNIT_ASSERT(tester.toString(0)=="*");
        CPPUNIT_ASSERT(tester.toString(1)==".");
    }

    void board_create_1 () {
        Board<ConwayCell> brd(3,3);

        ConwayCell c1(true);
        ConwayCell c2(true);
        ConwayCell c3(true);

        brd.add_creature(c1, 2, 1);
        brd.add_creature(c2, 0, 1);
        brd.add_creature(c3, 1, 1);

        CPPUNIT_ASSERT(brd._data[0][0].toString(0)==".");
        CPPUNIT_ASSERT(brd._data[0][1].toString(0)==".");
        CPPUNIT_ASSERT(brd._data[0][2].toString(0)==".");
        CPPUNIT_ASSERT(brd._data[1][0].toString(0)=="*");
        CPPUNIT_ASSERT(brd._data[1][1].toString(0)=="*");
        CPPUNIT_ASSERT(brd._data[1][2].toString(0)=="*");
        CPPUNIT_ASSERT(brd._data[2][0].toString(0)==".");
        CPPUNIT_ASSERT(brd._data[2][1].toString(0)==".");
        CPPUNIT_ASSERT(brd._data[2][2].toString(0)==".");
    }


    void board_create_2 () {
        Board<ConwayCell> brd(3,3);

        ConwayCell c1(true);
        ConwayCell c2(true);
        ConwayCell c3(true);

        brd.add_creature(c1, 2, 1);
        brd.add_creature(c2, 0, 1);
        brd.add_creature(c3, 1, 1);

        CPPUNIT_ASSERT(brd._data[0][0].toString(0)==".");
        CPPUNIT_ASSERT(brd._data[0][1].toString(0)==".");
        CPPUNIT_ASSERT(brd._data[0][2].toString(0)==".");
        CPPUNIT_ASSERT(brd._data[1][0].toString(0)=="*");
        CPPUNIT_ASSERT(brd._data[1][1].toString(0)=="*");
        CPPUNIT_ASSERT(brd._data[1][2].toString(0)=="*");
        CPPUNIT_ASSERT(brd._data[2][0].toString(0)==".");
        CPPUNIT_ASSERT(brd._data[2][1].toString(0)==".");
        CPPUNIT_ASSERT(brd._data[2][2].toString(0)==".");

        Surrounding srd(0, 0);
        int x = brd.get_x();
        int y = brd.get_y();

        for(int i = 0; i< y; ++i){
            // cout << "x " << i << " y " << 0 << endl;
            srd = brd.get_new_surrounding(0, i, 0);
            // srd.print_state();
            for(int j = 0; j < x; ++j){
                brd.execute_cell(j, i, srd, 0);
                srd = brd.shift_right_srd(srd, 0);
                // srd.print_state();
                // do shift right
            }
        }
        
        CPPUNIT_ASSERT(brd._data[0][0].toString(1)==".");
        CPPUNIT_ASSERT(brd._data[0][1].toString(1)=="*");
        CPPUNIT_ASSERT(brd._data[0][2].toString(1)==".");
        CPPUNIT_ASSERT(brd._data[1][0].toString(1)==".");
        CPPUNIT_ASSERT(brd._data[1][1].toString(1)=="*");
        CPPUNIT_ASSERT(brd._data[1][2].toString(1)==".");
        CPPUNIT_ASSERT(brd._data[2][0].toString(1)==".");
        CPPUNIT_ASSERT(brd._data[2][1].toString(1)=="*");
        CPPUNIT_ASSERT(brd._data[2][2].toString(1)==".");
    }

    void fredkin_maketurn_1 () {
        FredkinCell tester(true);
        Surrounding someLive(EAST ,0,0);
        tester.make_turn(someLive,0);
        CPPUNIT_ASSERT(tester.toString(0)=="1");
        CPPUNIT_ASSERT(tester.toString(1)=="1");
        tester.make_turn(someLive,1);
        CPPUNIT_ASSERT(tester.toString(0)=="2");
        CPPUNIT_ASSERT(tester.toString(1)=="2");
        tester.make_turn(someLive,2);
        CPPUNIT_ASSERT(tester.toString(0)=="3");
        CPPUNIT_ASSERT(tester.toString(1)=="3");
    }
    void fredkin_maketurn_2 () {
        FredkinCell tester(true);
        Surrounding live(EAST,0,0);
        Surrounding die(0,0,0);
        tester.make_turn(live,0);
        CPPUNIT_ASSERT(tester.toString(0)=="1");
        CPPUNIT_ASSERT(tester.toString(1)=="1");
        tester.make_turn(die,1);
        CPPUNIT_ASSERT(tester.toString(0)=="-");
        CPPUNIT_ASSERT(tester.toString(1)=="1");
        tester.make_turn(live,2);
        CPPUNIT_ASSERT(tester.toString(0)=="-");
        CPPUNIT_ASSERT(tester.toString(1)=="1");
    }

    void fredkin_maketurn_3 () {
        FredkinCell tester(false);
        Surrounding live(EAST,0,0);
        Surrounding die(0,0,0);
        tester.make_turn(live,0);
        CPPUNIT_ASSERT(tester.toString(0)=="-");
        CPPUNIT_ASSERT(tester.toString(1)=="0");
        tester.make_turn(live,1);
        CPPUNIT_ASSERT(tester.toString(0)=="1");
        CPPUNIT_ASSERT(tester.toString(1)=="1");
        tester.make_turn(die,2);
        CPPUNIT_ASSERT(tester.toString(0)=="1");
        CPPUNIT_ASSERT(tester.toString(1)=="-");
    }

    void cell_maketurn_1 () {
        Cell tester(true);
        Surrounding someLive(EAST ,0,0);
        tester.make_turn(someLive,0);
        CPPUNIT_ASSERT(tester.toString(0)=="1");
        CPPUNIT_ASSERT(tester.toString(1)=="1");
        tester.make_turn(someLive,1);
        CPPUNIT_ASSERT(tester.toString(0)=="*");
        tester.make_turn(someLive,2);
        CPPUNIT_ASSERT(tester.toString(0)=="*");
    }
    void cell_maketurn_2 () {
        Cell tester(true);
        Surrounding live(EAST,0,0);
        Surrounding die(0,0,0);
        tester.make_turn(live,0);
        CPPUNIT_ASSERT(tester.toString(0)=="1");
        CPPUNIT_ASSERT(tester.toString(1)=="1");
        tester.make_turn(die,1);
        CPPUNIT_ASSERT(tester.toString(0)=="-");
        CPPUNIT_ASSERT(tester.toString(1)=="1");
        tester.make_turn(live,2);
        CPPUNIT_ASSERT(tester.toString(0)=="-");
        CPPUNIT_ASSERT(tester.toString(1)=="1");
    }

    void cell_maketurn_3 () {
        Cell tester(false);
        Surrounding live(EAST,0,0);
        Surrounding die(0,0,0);
        tester.make_turn(live,0);
        CPPUNIT_ASSERT(tester.toString(0)=="-");
        CPPUNIT_ASSERT(tester.toString(1)=="0");
        tester.make_turn(live,1);
        CPPUNIT_ASSERT(tester.toString(0)=="1");
        CPPUNIT_ASSERT(tester.toString(1)=="1");
        tester.make_turn(die,2);
        CPPUNIT_ASSERT(tester.toString(0)=="1");
        CPPUNIT_ASSERT(tester.toString(1)=="-");
    }

    void cell_maketurn_4 () {
        Cell tester(false);
        Surrounding live(EAST,0,0);
        Surrounding die(0,0,0);
        tester.make_turn(live,0);
        CPPUNIT_ASSERT(tester.toString(0)=="-");
        CPPUNIT_ASSERT(tester.toString(1)=="0");
        tester.make_turn(live,1);
        CPPUNIT_ASSERT(tester.toString(0)=="1");
        CPPUNIT_ASSERT(tester.toString(1)=="1");
        tester.make_turn(live,2);
        CPPUNIT_ASSERT(tester.toString(0)=="*");
        CPPUNIT_ASSERT(tester.toString(1)==".");
    }

    void life_create_1 () {
        Board<ConwayCell> brd(3,3);

        ConwayCell c1(true);
        ConwayCell c2(true);
        ConwayCell c3(true);

        brd.add_creature(c1, 2, 1);
        brd.add_creature(c2, 0, 1);
        brd.add_creature(c3, 1, 1);

        CPPUNIT_ASSERT(brd._data[0][0].toString(0)==".");
        CPPUNIT_ASSERT(brd._data[0][1].toString(0)==".");
        CPPUNIT_ASSERT(brd._data[0][2].toString(0)==".");
        CPPUNIT_ASSERT(brd._data[1][0].toString(0)=="*");
        CPPUNIT_ASSERT(brd._data[1][1].toString(0)=="*");
        CPPUNIT_ASSERT(brd._data[1][2].toString(0)=="*");
        CPPUNIT_ASSERT(brd._data[2][0].toString(0)==".");
        CPPUNIT_ASSERT(brd._data[2][1].toString(0)==".");
        CPPUNIT_ASSERT(brd._data[2][2].toString(0)==".");
        Life<ConwayCell> l(brd);
        CPPUNIT_ASSERT(l._turn==0);

    }


    void life_create_2 () {
        Board<ConwayCell> brd(3,3);

        ConwayCell c1(true);
        ConwayCell c2(true);
        ConwayCell c3(true);

        brd.add_creature(c1, 2, 1);
        brd.add_creature(c2, 0, 1);
        brd.add_creature(c3, 1, 1);

        Life<ConwayCell> l(brd);
        CPPUNIT_ASSERT(l._turn==0);
        CPPUNIT_ASSERT(l._board._data[0][0].toString(0)==".");
        CPPUNIT_ASSERT(l._board._data[0][1].toString(0)==".");
        CPPUNIT_ASSERT(l._board._data[0][2].toString(0)==".");
        CPPUNIT_ASSERT(l._board._data[1][0].toString(0)=="*");
        CPPUNIT_ASSERT(l._board._data[1][1].toString(0)=="*");
        CPPUNIT_ASSERT(l._board._data[1][2].toString(0)=="*");
        CPPUNIT_ASSERT(l._board._data[2][0].toString(0)==".");
        CPPUNIT_ASSERT(l._board._data[2][1].toString(0)==".");
        CPPUNIT_ASSERT(l._board._data[2][2].toString(0)==".");
        l.simulate_round();
        CPPUNIT_ASSERT(l._turn==1);

        CPPUNIT_ASSERT(l._board._data[0][0].toString(1)==".");
        CPPUNIT_ASSERT(l._board._data[0][1].toString(1)=="*");
        CPPUNIT_ASSERT(l._board._data[0][2].toString(1)==".");
        CPPUNIT_ASSERT(l._board._data[1][0].toString(1)==".");
        CPPUNIT_ASSERT(l._board._data[1][1].toString(1)=="*");
        CPPUNIT_ASSERT(l._board._data[1][2].toString(1)==".");
        CPPUNIT_ASSERT(l._board._data[2][0].toString(1)==".");
        CPPUNIT_ASSERT(l._board._data[2][1].toString(1)=="*");
        CPPUNIT_ASSERT(l._board._data[2][2].toString(1)==".");
    }
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);

    CPPUNIT_TEST(conway_construction_true);
    CPPUNIT_TEST(conway_construction_false);

    CPPUNIT_TEST(fredkin_construction_true);
    CPPUNIT_TEST(fredkin_construction_false);

    CPPUNIT_TEST(cell_construction_true);
    CPPUNIT_TEST(cell_construction_false);

    CPPUNIT_TEST(construction_surroundings_all);
    CPPUNIT_TEST(construction_surroundings_dead);
    CPPUNIT_TEST(construction_surroundings_n_e);

    CPPUNIT_TEST(conway_maketurn_1);
    CPPUNIT_TEST(conway_maketurn_2);
    CPPUNIT_TEST(conway_maketurn_3);

    CPPUNIT_TEST(fredkin_maketurn_1);
    CPPUNIT_TEST(fredkin_maketurn_2);
    CPPUNIT_TEST(fredkin_maketurn_3);

    CPPUNIT_TEST(cell_maketurn_1);
    CPPUNIT_TEST(cell_maketurn_2);
    CPPUNIT_TEST(cell_maketurn_3);
    CPPUNIT_TEST(cell_maketurn_4);


    CPPUNIT_TEST(board_create_1);
    CPPUNIT_TEST(board_create_2);

    CPPUNIT_TEST(life_create_1);
    CPPUNIT_TEST(life_create_2);


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
