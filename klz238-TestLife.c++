#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TextTestRunner.h"

// All main files
#include "Life.h"
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"

struct TestConway : CppUnit::TestFixture {
    void test_cstr_alive() {
        std::ostringstream ss;
        ConwayCell c(STATE_ALIVE);
        ss << c;
        CPPUNIT_ASSERT(ss.str() == "*");
        CPPUNIT_ASSERT(c.state() == STATE_ALIVE);
    }

    void test_cstr_dead() {
        std::ostringstream ss;
        ConwayCell c(STATE_DEAD);
        ss << c;
        CPPUNIT_ASSERT(ss.str() == ".");
        CPPUNIT_ASSERT(c.state() == STATE_DEAD);
    }

    void test_die() {
        std::ostringstream ss;
        ConwayCell c(STATE_ALIVE);
        ss << c;
        c.die();
        ss << c;
        CPPUNIT_ASSERT(ss.str() == "*.");
        CPPUNIT_ASSERT(c.state() == STATE_DEAD);
    }

    void test_live() {
        std::ostringstream ss;
        ConwayCell c(STATE_DEAD);
        ss << c;
        c.live();
        ss << c;
        CPPUNIT_ASSERT(ss.str() == ".*");
        CPPUNIT_ASSERT(c.state() == STATE_ALIVE);
    }

    void test_next_top_left() {
        ECellState die1[8] = {
            STATE_NONE, STATE_NONE, STATE_NONE,
            STATE_NONE,             STATE_DEAD,
            STATE_NONE, STATE_DEAD, STATE_DEAD};
        ECellState die2[8] = {
            STATE_NONE, STATE_NONE,  STATE_NONE,
            STATE_NONE,              STATE_DEAD,
            STATE_NONE, STATE_ALIVE, STATE_DEAD};
        ECellState die3[8] = {
            STATE_NONE, STATE_NONE, STATE_NONE,
            STATE_NONE,             STATE_DEAD,
            STATE_NONE, STATE_DEAD, STATE_ALIVE};
        ECellState die4[8] = {
            STATE_NONE, STATE_NONE, STATE_NONE,
            STATE_NONE,             STATE_ALIVE,
            STATE_NONE, STATE_DEAD, STATE_DEAD};
        ECellState livedie1[8] = {
            STATE_NONE, STATE_NONE, STATE_NONE,
            STATE_NONE,             STATE_ALIVE,
            STATE_NONE, STATE_DEAD, STATE_ALIVE};
        ECellState livedie2[8] = {
            STATE_NONE, STATE_NONE,  STATE_NONE,
            STATE_NONE,              STATE_ALIVE,
            STATE_NONE, STATE_ALIVE, STATE_DEAD};
        ECellState livedie3[8] = {
            STATE_NONE, STATE_NONE,  STATE_NONE,
            STATE_NONE,              STATE_DEAD,
            STATE_NONE, STATE_ALIVE, STATE_ALIVE};
        ECellState live1[8] = {
            STATE_NONE, STATE_NONE,  STATE_NONE,
            STATE_NONE,              STATE_ALIVE,
            STATE_NONE, STATE_ALIVE, STATE_ALIVE};

        ConwayCell a(STATE_DEAD);
        ConwayCell b(STATE_ALIVE);

        CPPUNIT_ASSERT(a.next(die1)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(die2)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(die3)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(die4)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie1) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie2) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie3) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(live1)    == STATE_ALIVE);

        CPPUNIT_ASSERT(b.next(die1)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(die2)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(die3)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(die4)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(livedie1) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie2) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie3) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(live1)    == STATE_ALIVE);
    }

    void test_next_top_right() {
        ECellState die1[8] = {
            STATE_NONE, STATE_NONE, STATE_NONE,
            STATE_DEAD,             STATE_NONE,
            STATE_DEAD, STATE_DEAD, STATE_NONE};
        ECellState die2[8] = {
            STATE_NONE, STATE_NONE,  STATE_NONE,
            STATE_DEAD,              STATE_NONE,
            STATE_DEAD, STATE_ALIVE, STATE_NONE};
        ECellState die3[8] = {
            STATE_NONE, STATE_NONE, STATE_NONE,
            STATE_DEAD,             STATE_NONE,
            STATE_ALIVE, STATE_DEAD, STATE_NONE};
        ECellState die4[8] = {
            STATE_NONE, STATE_NONE, STATE_NONE,
            STATE_ALIVE,             STATE_NONE,
            STATE_DEAD, STATE_DEAD, STATE_NONE};
        ECellState livedie1[8] = {
            STATE_NONE, STATE_NONE, STATE_NONE,
            STATE_ALIVE,             STATE_NONE,
            STATE_ALIVE, STATE_DEAD, STATE_NONE};
        ECellState livedie2[8] = {
            STATE_NONE, STATE_NONE,  STATE_NONE,
            STATE_ALIVE,              STATE_NONE,
            STATE_DEAD, STATE_ALIVE, STATE_NONE};
        ECellState livedie3[8] = {
            STATE_NONE, STATE_NONE,  STATE_NONE,
            STATE_DEAD,              STATE_NONE,
            STATE_ALIVE, STATE_ALIVE, STATE_NONE};
        ECellState live1[8] = {
            STATE_NONE, STATE_NONE,  STATE_NONE,
            STATE_ALIVE,              STATE_NONE,
            STATE_ALIVE, STATE_ALIVE, STATE_NONE};

        ConwayCell a(STATE_DEAD);
        ConwayCell b(STATE_ALIVE);

        CPPUNIT_ASSERT(a.next(die1)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(die2)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(die3)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(die4)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie1) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie2) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie3) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(live1)    == STATE_ALIVE);

        CPPUNIT_ASSERT(b.next(die1)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(die2)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(die3)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(die4)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(livedie1) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie2) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie3) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(live1)    == STATE_ALIVE);
    }

    void test_next_bottom_left() {
        ECellState die1[8] = {
            STATE_NONE, STATE_DEAD, STATE_DEAD,
            STATE_NONE,             STATE_DEAD,
            STATE_NONE, STATE_NONE, STATE_NONE};
        ECellState die2[8] = {
            STATE_NONE, STATE_ALIVE,  STATE_DEAD,
            STATE_NONE,              STATE_DEAD,
            STATE_NONE, STATE_NONE, STATE_NONE};
        ECellState die3[8] = {
            STATE_NONE, STATE_DEAD, STATE_ALIVE,
            STATE_NONE,             STATE_DEAD,
            STATE_NONE, STATE_NONE, STATE_NONE};
        ECellState die4[8] = {
            STATE_NONE, STATE_DEAD, STATE_DEAD,
            STATE_NONE,             STATE_ALIVE,
            STATE_NONE, STATE_NONE, STATE_NONE};
        ECellState livedie1[8] = {
            STATE_NONE, STATE_DEAD, STATE_ALIVE,
            STATE_NONE,             STATE_ALIVE,
            STATE_NONE, STATE_NONE, STATE_NONE};
        ECellState livedie2[8] = {
            STATE_NONE, STATE_ALIVE, STATE_DEAD,
            STATE_NONE,              STATE_ALIVE,
            STATE_NONE, STATE_NONE, STATE_NONE};
        ECellState livedie3[8] = {
            STATE_NONE, STATE_ALIVE,  STATE_ALIVE,
            STATE_NONE,              STATE_DEAD,
            STATE_NONE, STATE_NONE, STATE_NONE};
        ECellState live1[8] = {
            STATE_NONE, STATE_ALIVE,  STATE_ALIVE,
            STATE_NONE,              STATE_ALIVE,
            STATE_NONE, STATE_NONE, STATE_NONE};

        ConwayCell a(STATE_DEAD);
        ConwayCell b(STATE_ALIVE);

        CPPUNIT_ASSERT(a.next(die1)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(die2)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(die3)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(die4)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie1) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie2) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie3) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(live1)    == STATE_ALIVE);

        CPPUNIT_ASSERT(b.next(die1)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(die2)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(die3)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(die4)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(livedie1) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie2) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie3) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(live1)    == STATE_ALIVE);
    }

    void test_next_bottom_right() {
        ECellState die1[8] = {
            STATE_DEAD, STATE_DEAD, STATE_NONE,
            STATE_DEAD,             STATE_NONE,
            STATE_NONE, STATE_NONE, STATE_NONE};
        ECellState die2[8] = {
            STATE_DEAD, STATE_ALIVE,  STATE_NONE,
            STATE_DEAD,              STATE_NONE,
            STATE_NONE, STATE_NONE, STATE_NONE};
        ECellState die3[8] = {
            STATE_ALIVE, STATE_DEAD, STATE_NONE,
            STATE_DEAD,             STATE_NONE,
            STATE_NONE, STATE_NONE, STATE_NONE};
        ECellState die4[8] = {
            STATE_DEAD, STATE_DEAD, STATE_NONE,
            STATE_ALIVE,             STATE_NONE,
            STATE_NONE, STATE_NONE, STATE_NONE};
        ECellState livedie1[8] = {
            STATE_ALIVE, STATE_DEAD, STATE_NONE,
            STATE_ALIVE,             STATE_NONE,
            STATE_NONE, STATE_NONE, STATE_NONE};
        ECellState livedie2[8] = {
            STATE_DEAD, STATE_ALIVE,  STATE_NONE,
            STATE_ALIVE,              STATE_NONE,
            STATE_NONE, STATE_NONE, STATE_NONE};
        ECellState livedie3[8] = {
            STATE_ALIVE, STATE_ALIVE,  STATE_NONE,
            STATE_DEAD,              STATE_NONE,
            STATE_NONE, STATE_NONE, STATE_NONE};
        ECellState live1[8] = {
            STATE_ALIVE, STATE_ALIVE,  STATE_NONE,
            STATE_ALIVE,              STATE_NONE,
            STATE_NONE, STATE_NONE, STATE_NONE};

        ConwayCell a(STATE_DEAD);
        ConwayCell b(STATE_ALIVE);

        CPPUNIT_ASSERT(a.next(die1)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(die2)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(die3)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(die4)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie1) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie2) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie3) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(live1)    == STATE_ALIVE);

        CPPUNIT_ASSERT(b.next(die1)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(die2)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(die3)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(die4)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(livedie1) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie2) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie3) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(live1)    == STATE_ALIVE);
    }

    void test_next_mid_left() {
        ECellState die1[8] = {
            STATE_NONE, STATE_DEAD, STATE_DEAD,
            STATE_NONE,             STATE_DEAD,
            STATE_NONE, STATE_DEAD, STATE_DEAD};
        ECellState die2[8] = {
            STATE_NONE, STATE_ALIVE,  STATE_DEAD,
            STATE_NONE,              STATE_DEAD,
            STATE_NONE, STATE_DEAD, STATE_DEAD};
        ECellState die3[8] = {
            STATE_NONE, STATE_DEAD, STATE_ALIVE,
            STATE_NONE,             STATE_DEAD,
            STATE_NONE, STATE_DEAD, STATE_DEAD};
        ECellState die4[8] = {
            STATE_NONE, STATE_DEAD, STATE_DEAD,
            STATE_NONE,             STATE_ALIVE,
            STATE_NONE, STATE_DEAD, STATE_DEAD};
        ECellState die5[8] = {
            STATE_NONE, STATE_DEAD, STATE_DEAD,
            STATE_NONE,             STATE_DEAD,
            STATE_NONE, STATE_DEAD, STATE_ALIVE};
        ECellState die6[8] = {
            STATE_NONE, STATE_DEAD, STATE_DEAD,
            STATE_NONE,             STATE_DEAD,
            STATE_NONE, STATE_ALIVE, STATE_DEAD};
        ECellState livedie1[8] = {
            STATE_NONE, STATE_ALIVE, STATE_ALIVE,
            STATE_NONE,             STATE_DEAD,
            STATE_NONE, STATE_DEAD, STATE_DEAD};
        ECellState livedie2[8] = {
            STATE_NONE, STATE_ALIVE, STATE_DEAD,
            STATE_NONE,              STATE_ALIVE,
            STATE_NONE, STATE_DEAD, STATE_DEAD};
        ECellState livedie3[8] = {
            STATE_NONE, STATE_ALIVE,  STATE_DEAD,
            STATE_NONE,              STATE_DEAD,
            STATE_NONE, STATE_DEAD, STATE_ALIVE};
        ECellState livedie4[8] = {
            STATE_NONE, STATE_ALIVE,  STATE_DEAD,
            STATE_NONE,              STATE_DEAD,
            STATE_NONE, STATE_ALIVE, STATE_DEAD};
        ECellState livedie5[8] = {
            STATE_NONE, STATE_DEAD,  STATE_ALIVE,
            STATE_NONE,              STATE_ALIVE,
            STATE_NONE, STATE_DEAD, STATE_DEAD};
        ECellState livedie6[8] = {
            STATE_NONE, STATE_DEAD,  STATE_ALIVE,
            STATE_NONE,              STATE_DEAD,
            STATE_NONE, STATE_DEAD, STATE_ALIVE};
        ECellState livedie7[8] = {
            STATE_NONE, STATE_DEAD,  STATE_ALIVE,
            STATE_NONE,              STATE_DEAD,
            STATE_NONE, STATE_ALIVE, STATE_DEAD};
        ECellState livedie8[8] = {
            STATE_NONE, STATE_DEAD,  STATE_DEAD,
            STATE_NONE,              STATE_ALIVE,
            STATE_NONE, STATE_DEAD, STATE_ALIVE};
        ECellState livedie9[8] = {
            STATE_NONE, STATE_DEAD,  STATE_DEAD,
            STATE_NONE,              STATE_ALIVE,
            STATE_NONE, STATE_ALIVE, STATE_DEAD};
        ECellState livedie10[8] = {
            STATE_NONE, STATE_DEAD,  STATE_DEAD,
            STATE_NONE,              STATE_DEAD,
            STATE_NONE, STATE_ALIVE, STATE_ALIVE};
        ECellState livedie11[8] = {
            STATE_NONE, STATE_ALIVE,  STATE_DEAD,
            STATE_NONE,              STATE_DEAD,
            STATE_NONE, STATE_DEAD, STATE_ALIVE};
        ECellState live1[8] = {
            STATE_NONE, STATE_ALIVE,  STATE_ALIVE,
            STATE_NONE,              STATE_ALIVE,
            STATE_NONE, STATE_DEAD, STATE_DEAD};
        ECellState live2[8] = {
            STATE_NONE, STATE_ALIVE,  STATE_ALIVE,
            STATE_NONE,              STATE_DEAD,
            STATE_NONE, STATE_DEAD, STATE_ALIVE};
        ECellState live3[8] = {
            STATE_NONE, STATE_ALIVE,  STATE_ALIVE,
            STATE_NONE,              STATE_DEAD,
            STATE_NONE, STATE_ALIVE, STATE_DEAD};
        ECellState live4[8] = {
            STATE_NONE, STATE_DEAD,  STATE_ALIVE,
            STATE_NONE,              STATE_ALIVE,
            STATE_NONE, STATE_DEAD, STATE_ALIVE};
        ECellState live5[8] = {
            STATE_NONE, STATE_DEAD,  STATE_ALIVE,
            STATE_NONE,              STATE_ALIVE,
            STATE_NONE, STATE_ALIVE, STATE_DEAD};
        ECellState live6[8] = {
            STATE_NONE, STATE_DEAD,  STATE_DEAD,
            STATE_NONE,              STATE_ALIVE,
            STATE_NONE, STATE_ALIVE, STATE_ALIVE};
        ECellState dielive1[8] = {
            STATE_NONE, STATE_ALIVE,  STATE_ALIVE,
            STATE_NONE,              STATE_ALIVE,
            STATE_NONE, STATE_DEAD, STATE_ALIVE};
        ECellState dielive2[8] = {
            STATE_NONE, STATE_ALIVE,  STATE_ALIVE,
            STATE_NONE,              STATE_ALIVE,
            STATE_NONE, STATE_ALIVE, STATE_DEAD};
        ECellState dielive3[8] = {
            STATE_NONE, STATE_DEAD,  STATE_ALIVE,
            STATE_NONE,              STATE_ALIVE,
            STATE_NONE, STATE_ALIVE, STATE_ALIVE};
        ECellState dielive4[8] = {
            STATE_NONE, STATE_ALIVE,  STATE_ALIVE,
            STATE_NONE,              STATE_ALIVE,
            STATE_NONE, STATE_ALIVE, STATE_ALIVE};

        ConwayCell a(STATE_DEAD);
        ConwayCell b(STATE_ALIVE);

        CPPUNIT_ASSERT(a.next(die1)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(die2)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(die3)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(die4)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(die5)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(die6)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie1) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie2) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie3) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie4) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie5) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie6) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie7) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie8) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie9) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie10) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie11) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(live1)    == STATE_ALIVE);
        CPPUNIT_ASSERT(a.next(live2)    == STATE_ALIVE);
        CPPUNIT_ASSERT(a.next(live3)    == STATE_ALIVE);
        CPPUNIT_ASSERT(a.next(live4)    == STATE_ALIVE);
        CPPUNIT_ASSERT(a.next(live5)    == STATE_ALIVE);
        CPPUNIT_ASSERT(a.next(live6)    == STATE_ALIVE);
        CPPUNIT_ASSERT(a.next(dielive1) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(dielive2) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(dielive3) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(dielive4) == STATE_DEAD);

        CPPUNIT_ASSERT(b.next(die1)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(die2)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(die3)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(die4)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(die5)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(die6)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(livedie1) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie2) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie3) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie4) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie5) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie6) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie7) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie8) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie9) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie10) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie11) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(live1)    == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(live2)    == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(live3)    == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(live4)    == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(live5)    == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(live6)    == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(dielive1) == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(dielive2) == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(dielive3) == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(dielive4) == STATE_DEAD);
    }

    void test_next_mid_right() {
        ECellState die1[8] = {
            STATE_DEAD, STATE_DEAD, STATE_NONE,
            STATE_DEAD,             STATE_NONE,
            STATE_DEAD, STATE_DEAD, STATE_NONE};
        ECellState die2[8] = {
            STATE_DEAD, STATE_ALIVE,  STATE_NONE,
            STATE_DEAD,              STATE_NONE,
            STATE_DEAD, STATE_DEAD, STATE_NONE};
        ECellState die3[8] = {
            STATE_ALIVE, STATE_DEAD, STATE_NONE,
            STATE_DEAD,             STATE_NONE,
            STATE_DEAD, STATE_DEAD, STATE_NONE};
        ECellState die4[8] = {
            STATE_DEAD, STATE_DEAD, STATE_NONE,
            STATE_ALIVE,             STATE_NONE,
            STATE_DEAD, STATE_DEAD, STATE_NONE};
        ECellState die5[8] = {
            STATE_DEAD, STATE_DEAD, STATE_NONE,
            STATE_DEAD,             STATE_NONE,
            STATE_ALIVE, STATE_DEAD, STATE_NONE};
        ECellState die6[8] = {
            STATE_DEAD, STATE_DEAD, STATE_NONE,
            STATE_DEAD,             STATE_NONE,
            STATE_DEAD, STATE_ALIVE, STATE_NONE};
        ECellState livedie1[8] = {
            STATE_ALIVE, STATE_ALIVE, STATE_NONE,
            STATE_DEAD,             STATE_NONE,
            STATE_DEAD, STATE_DEAD, STATE_NONE};
        ECellState livedie2[8] = {
            STATE_DEAD, STATE_ALIVE, STATE_NONE,
            STATE_ALIVE,              STATE_NONE,
            STATE_DEAD, STATE_DEAD, STATE_NONE};
        ECellState livedie3[8] = {
            STATE_DEAD, STATE_ALIVE,  STATE_NONE,
            STATE_DEAD,              STATE_NONE,
            STATE_ALIVE, STATE_DEAD, STATE_NONE};
        ECellState livedie4[8] = {
            STATE_DEAD, STATE_ALIVE,  STATE_NONE,
            STATE_DEAD,              STATE_NONE,
            STATE_DEAD, STATE_ALIVE, STATE_NONE};
        ECellState livedie5[8] = {
            STATE_ALIVE, STATE_DEAD,  STATE_NONE,
            STATE_ALIVE,              STATE_NONE,
            STATE_DEAD, STATE_DEAD, STATE_NONE};
        ECellState livedie6[8] = {
            STATE_ALIVE, STATE_DEAD,  STATE_NONE,
            STATE_DEAD,              STATE_NONE,
            STATE_ALIVE, STATE_DEAD, STATE_NONE};
        ECellState livedie7[8] = {
            STATE_ALIVE, STATE_DEAD,  STATE_NONE,
            STATE_DEAD,              STATE_NONE,
            STATE_DEAD, STATE_ALIVE, STATE_NONE};
        ECellState livedie8[8] = {
            STATE_DEAD, STATE_DEAD,  STATE_NONE,
            STATE_ALIVE,              STATE_NONE,
            STATE_ALIVE, STATE_DEAD, STATE_NONE};
        ECellState livedie9[8] = {
            STATE_DEAD, STATE_DEAD,  STATE_NONE,
            STATE_ALIVE,              STATE_NONE,
            STATE_DEAD, STATE_ALIVE, STATE_NONE};
        ECellState livedie10[8] = {
            STATE_DEAD, STATE_DEAD,  STATE_NONE,
            STATE_DEAD,              STATE_NONE,
            STATE_ALIVE, STATE_ALIVE, STATE_NONE};
        ECellState livedie11[8] = {
            STATE_DEAD, STATE_ALIVE,  STATE_NONE,
            STATE_DEAD,              STATE_NONE,
            STATE_ALIVE, STATE_DEAD, STATE_NONE};
        ECellState live1[8] = {
            STATE_ALIVE, STATE_ALIVE,  STATE_NONE,
            STATE_ALIVE,              STATE_NONE,
            STATE_DEAD, STATE_DEAD, STATE_NONE};
        ECellState live2[8] = {
            STATE_ALIVE, STATE_ALIVE,  STATE_NONE,
            STATE_DEAD,              STATE_NONE,
            STATE_ALIVE, STATE_DEAD, STATE_NONE};
        ECellState live3[8] = {
            STATE_ALIVE, STATE_ALIVE,  STATE_NONE,
            STATE_DEAD,              STATE_NONE,
            STATE_DEAD, STATE_ALIVE, STATE_NONE};
        ECellState live4[8] = {
            STATE_ALIVE, STATE_DEAD,  STATE_NONE,
            STATE_ALIVE,              STATE_NONE,
            STATE_ALIVE, STATE_DEAD, STATE_NONE};
        ECellState live5[8] = {
            STATE_ALIVE, STATE_DEAD,  STATE_NONE,
            STATE_ALIVE,              STATE_NONE,
            STATE_DEAD, STATE_ALIVE, STATE_NONE};
        ECellState live6[8] = {
            STATE_DEAD, STATE_DEAD,  STATE_NONE,
            STATE_ALIVE,              STATE_NONE,
            STATE_ALIVE, STATE_ALIVE, STATE_NONE};
        ECellState dielive1[8] = {
            STATE_ALIVE, STATE_ALIVE,  STATE_NONE,
            STATE_ALIVE,              STATE_NONE,
            STATE_ALIVE, STATE_DEAD, STATE_NONE};
        ECellState dielive2[8] = {
            STATE_ALIVE, STATE_ALIVE,  STATE_NONE,
            STATE_ALIVE,              STATE_NONE,
            STATE_DEAD, STATE_ALIVE, STATE_NONE};
        ECellState dielive3[8] = {
            STATE_ALIVE, STATE_DEAD,  STATE_NONE,
            STATE_ALIVE,              STATE_NONE,
            STATE_ALIVE, STATE_ALIVE, STATE_NONE};
        ECellState dielive4[8] = {
            STATE_ALIVE, STATE_ALIVE,  STATE_NONE,
            STATE_ALIVE,              STATE_NONE,
            STATE_ALIVE, STATE_ALIVE, STATE_NONE};

        ConwayCell a(STATE_DEAD);
        ConwayCell b(STATE_ALIVE);

        CPPUNIT_ASSERT(a.next(die1)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(die2)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(die3)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(die4)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(die5)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(die6)     == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie1) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie2) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie3) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie4) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie5) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie6) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie7) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie8) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie9) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie10) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(livedie11) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(live1)    == STATE_ALIVE);
        CPPUNIT_ASSERT(a.next(live2)    == STATE_ALIVE);
        CPPUNIT_ASSERT(a.next(live3)    == STATE_ALIVE);
        CPPUNIT_ASSERT(a.next(live4)    == STATE_ALIVE);
        CPPUNIT_ASSERT(a.next(live5)    == STATE_ALIVE);
        CPPUNIT_ASSERT(a.next(live6)    == STATE_ALIVE);
        CPPUNIT_ASSERT(a.next(dielive1) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(dielive2) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(dielive3) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(dielive4) == STATE_DEAD);

        CPPUNIT_ASSERT(b.next(die1)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(die2)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(die3)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(die4)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(die5)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(die6)     == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(livedie1) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie2) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie3) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie4) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie5) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie6) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie7) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie8) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie9) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie10) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(livedie11) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(live1)    == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(live2)    == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(live3)    == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(live4)    == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(live5)    == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(live6)    == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(dielive1) == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(dielive2) == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(dielive3) == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(dielive4) == STATE_DEAD);
    }

    CPPUNIT_TEST_SUITE(TestConway);
    CPPUNIT_TEST(test_cstr_alive);
    CPPUNIT_TEST(test_cstr_dead);
    CPPUNIT_TEST(test_die);
    CPPUNIT_TEST(test_live);
    CPPUNIT_TEST(test_next_top_left);
    CPPUNIT_TEST(test_next_top_right);
    CPPUNIT_TEST(test_next_bottom_left);
    CPPUNIT_TEST(test_next_bottom_right);
    CPPUNIT_TEST(test_next_mid_left);
    CPPUNIT_TEST(test_next_mid_right);
    CPPUNIT_TEST_SUITE_END();
};

struct TestFredkin : CppUnit::TestFixture {
    void test_cstr_alive() {
        std::ostringstream ss;
        FredkinCell c(STATE_ALIVE);
        ss << c;
        CPPUNIT_ASSERT(ss.str() == "0");
        CPPUNIT_ASSERT(c.state() == STATE_ALIVE);
    }

    void test_cstr_dead() {
        std::ostringstream ss;
        FredkinCell c(STATE_DEAD);
        ss << c;
        CPPUNIT_ASSERT(ss.str() == "-");
        CPPUNIT_ASSERT(c.state() == STATE_DEAD);
    }

    void test_die() {
        std::ostringstream ss;
        FredkinCell c(STATE_ALIVE);
        ss << c;
        c.die();
        ss << c;
        CPPUNIT_ASSERT(ss.str() == "0-");
        CPPUNIT_ASSERT(c.state() == STATE_DEAD);
    }

    void test_live() {
        std::ostringstream ss;
        FredkinCell c(STATE_DEAD);
        ss << c;
        c.live();
        ss << c;
        CPPUNIT_ASSERT(ss.str() == "-0");
        CPPUNIT_ASSERT(c.state() == STATE_ALIVE);
    }

    void test_age() {
        std::ostringstream ss;
        FredkinCell c(STATE_ALIVE);
        ss << c;
        c.age();
        ss << c;
        CPPUNIT_ASSERT(ss.str() == "01");
        CPPUNIT_ASSERT(c.state() == STATE_ALIVE);
    }

    void test_next() {
        ECellState top_left[8] = {
            STATE_NONE, STATE_NONE, STATE_NONE,
            STATE_NONE,             STATE_ALIVE,
            STATE_NONE, STATE_DEAD, STATE_ALIVE};
        ECellState top_right[8] = {
            STATE_NONE, STATE_NONE, STATE_NONE,
            STATE_ALIVE,             STATE_NONE,
            STATE_DEAD, STATE_ALIVE, STATE_NONE};
        ECellState mid_left[8] = {
            STATE_NONE, STATE_ALIVE, STATE_ALIVE,
            STATE_NONE,             STATE_DEAD,
            STATE_NONE, STATE_DEAD, STATE_ALIVE};
        ECellState mid_right[8] = {
            STATE_DEAD, STATE_ALIVE, STATE_NONE,
            STATE_ALIVE,             STATE_NONE,
            STATE_ALIVE, STATE_DEAD, STATE_NONE};
        ECellState bot_left[8] = {
            STATE_NONE, STATE_ALIVE, STATE_ALIVE,
            STATE_NONE,             STATE_ALIVE,
            STATE_NONE, STATE_NONE, STATE_NONE};
        ECellState bot_right[8] = {
            STATE_DEAD, STATE_DEAD, STATE_NONE,
            STATE_DEAD,             STATE_NONE,
            STATE_NONE, STATE_NONE, STATE_NONE};

        FredkinCell a(STATE_DEAD);
        FredkinCell b(STATE_ALIVE);

        CPPUNIT_ASSERT(a.next(top_left) == STATE_ALIVE);
        CPPUNIT_ASSERT(a.next(top_right) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(mid_left) == STATE_ALIVE);
        CPPUNIT_ASSERT(a.next(mid_right) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(bot_left) == STATE_DEAD);
        CPPUNIT_ASSERT(a.next(bot_right) == STATE_DEAD);

        CPPUNIT_ASSERT(b.next(top_left) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(top_right) == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(mid_left) == STATE_ALIVE);
        CPPUNIT_ASSERT(b.next(mid_right) == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(bot_left) == STATE_DEAD);
        CPPUNIT_ASSERT(b.next(bot_right) == STATE_DEAD);
    }

    CPPUNIT_TEST_SUITE(TestFredkin);
    CPPUNIT_TEST(test_cstr_alive);
    CPPUNIT_TEST(test_cstr_dead);
    CPPUNIT_TEST(test_die);
    CPPUNIT_TEST(test_live);
    CPPUNIT_TEST(test_age);
    CPPUNIT_TEST(test_next);
    CPPUNIT_TEST_SUITE_END();
};

struct TestCellConway : CppUnit::TestFixture {
    void test_cstr_alive() {
        std::ostringstream ss;
        Cell x = new ConwayCell(STATE_ALIVE);
        ss << x;
        CPPUNIT_ASSERT(ss.str() == "*");
        CPPUNIT_ASSERT(x.state() == STATE_ALIVE);
    }

    void test_cstr_dead() {
        std::ostringstream ss;
        Cell x = new ConwayCell(STATE_DEAD);
        ss << x;
        CPPUNIT_ASSERT(ss.str() == ".");
        CPPUNIT_ASSERT(x.state() == STATE_DEAD);
    }

    void test_die() {
        std::ostringstream ss;
        Cell x = new ConwayCell(STATE_ALIVE);
        ss << x;
        x.die();
        ss << x;
        CPPUNIT_ASSERT(ss.str() == "*.");
        CPPUNIT_ASSERT(x.state() == STATE_DEAD);
    }

    void test_live() {
        std::ostringstream ss;
        Cell x = new ConwayCell(STATE_DEAD);
        ss << x;
        x.live();
        ss << x;
        CPPUNIT_ASSERT(ss.str() == ".*");
        CPPUNIT_ASSERT(x.state() == STATE_ALIVE);
    }

    void test_next() {
        ECellState die1[8] = {
            STATE_ALIVE, STATE_DEAD, STATE_DEAD,
            STATE_ALIVE,             STATE_DEAD,
            STATE_ALIVE, STATE_ALIVE, STATE_DEAD};
        ECellState die2[8] = {
            STATE_ALIVE, STATE_DEAD, STATE_DEAD,
            STATE_DEAD,             STATE_DEAD,
            STATE_DEAD, STATE_DEAD, STATE_DEAD};
        ECellState die3[8] = {
            STATE_ALIVE, STATE_ALIVE, STATE_ALIVE,
            STATE_ALIVE,              STATE_ALIVE,
            STATE_ALIVE, STATE_ALIVE, STATE_ALIVE};
        ECellState live1[8] = {
            STATE_ALIVE, STATE_DEAD, STATE_DEAD,
            STATE_DEAD,              STATE_DEAD,
            STATE_ALIVE, STATE_ALIVE, STATE_DEAD};
        ECellState live2[8] = {
            STATE_ALIVE, STATE_DEAD, STATE_DEAD,
            STATE_DEAD,             STATE_DEAD,
            STATE_DEAD, STATE_ALIVE, STATE_DEAD};

        Cell x = new ConwayCell(STATE_DEAD);
        Cell y = new ConwayCell(STATE_ALIVE);

        CPPUNIT_ASSERT(x.next(die1) == STATE_DEAD);
        CPPUNIT_ASSERT(x.next(die2) == STATE_DEAD);
        CPPUNIT_ASSERT(x.next(die3) == STATE_DEAD);
        CPPUNIT_ASSERT(x.next(live1) == STATE_ALIVE);
        CPPUNIT_ASSERT(x.next(live2) == STATE_DEAD);

        CPPUNIT_ASSERT(y.next(die1) == STATE_DEAD);
        CPPUNIT_ASSERT(y.next(die2) == STATE_DEAD);
        CPPUNIT_ASSERT(y.next(die3) == STATE_DEAD);
        CPPUNIT_ASSERT(y.next(live1) == STATE_ALIVE);
        CPPUNIT_ASSERT(y.next(live2) == STATE_ALIVE);
    }

    CPPUNIT_TEST_SUITE(TestCellConway);
    CPPUNIT_TEST(test_cstr_alive);
    CPPUNIT_TEST(test_cstr_dead);
    CPPUNIT_TEST(test_die);
    CPPUNIT_TEST(test_live);
    CPPUNIT_TEST(test_next);
    CPPUNIT_TEST_SUITE_END();
};

struct TestCellFredkin : CppUnit::TestFixture {
    void test_cstr_alive() {
        std::ostringstream ss;
        Cell x = new FredkinCell(STATE_ALIVE);
        ss << x;
        CPPUNIT_ASSERT(ss.str() == "0");
        CPPUNIT_ASSERT(x.state() == STATE_ALIVE);
    }
    
    void test_cstr_dead() {
        std::ostringstream ss;
        Cell x = new FredkinCell(STATE_DEAD);
        ss << x;
        CPPUNIT_ASSERT(ss.str() == "-");
        CPPUNIT_ASSERT(x.state() == STATE_DEAD);
    }

    void test_die() {
        std::ostringstream ss;
        Cell x = new FredkinCell(STATE_ALIVE);
        ss << x;
        x.die();
        ss << x;
        CPPUNIT_ASSERT(ss.str() == "0-");
        CPPUNIT_ASSERT(x.state() == STATE_DEAD);
    }

    void test_live() {
        std::ostringstream ss;
        Cell x = new FredkinCell(STATE_DEAD);
        ss << x;
        x.live();
        ss << x;
        CPPUNIT_ASSERT(ss.str() == "-0");
        CPPUNIT_ASSERT(x.state() == STATE_ALIVE);
    }

    void test_age() {
        std::ostringstream ss;
        Cell x = new FredkinCell(STATE_ALIVE);
        ss << x;
        x.age();
        ss << x;
        CPPUNIT_ASSERT(ss.str() == "01");
        CPPUNIT_ASSERT(x.state() == STATE_ALIVE);
    }

    void test_evolve_state() {
        std::ostringstream ss;
        Cell x = new FredkinCell(STATE_ALIVE);
        ss << x; x.age();
        CPPUNIT_ASSERT(x.state() == STATE_ALIVE);
        ss << x; x.age();
        CPPUNIT_ASSERT(x.state() == STATE_ALIVE);
        ss << x; x.age();
        CPPUNIT_ASSERT(x.state() == STATE_ALIVE);
        ss << x;
        CPPUNIT_ASSERT(ss.str() == "01**");
    }

    void test_next() {
        ECellState die1[8] = {
            STATE_ALIVE, STATE_DEAD, STATE_DEAD,
            STATE_ALIVE,             STATE_DEAD,
            STATE_ALIVE, STATE_ALIVE, STATE_DEAD};
        ECellState die2[8] = {
            STATE_ALIVE, STATE_DEAD, STATE_DEAD,
            STATE_DEAD,             STATE_DEAD,
            STATE_DEAD, STATE_DEAD, STATE_DEAD};
        ECellState die3[8] = {
            STATE_ALIVE, STATE_ALIVE, STATE_ALIVE,
            STATE_ALIVE,              STATE_ALIVE,
            STATE_ALIVE, STATE_ALIVE, STATE_ALIVE};
        ECellState live1[8] = {
            STATE_ALIVE, STATE_DEAD, STATE_DEAD,
            STATE_DEAD,              STATE_DEAD,
            STATE_ALIVE, STATE_ALIVE, STATE_DEAD};
        ECellState live2[8] = {
            STATE_ALIVE, STATE_DEAD, STATE_DEAD,
            STATE_DEAD,             STATE_DEAD,
            STATE_DEAD, STATE_ALIVE, STATE_DEAD};

        Cell x = new FredkinCell(STATE_DEAD);
        Cell y = new FredkinCell(STATE_ALIVE);

        CPPUNIT_ASSERT(x.next(die1) == STATE_DEAD);
        CPPUNIT_ASSERT(x.next(die2) == STATE_DEAD);
        CPPUNIT_ASSERT(x.next(die3) == STATE_DEAD);
        CPPUNIT_ASSERT(x.next(live1) == STATE_ALIVE);
        CPPUNIT_ASSERT(x.next(live2) == STATE_ALIVE);

        CPPUNIT_ASSERT(y.next(die1) == STATE_DEAD);
        CPPUNIT_ASSERT(y.next(die2) == STATE_DEAD);
        CPPUNIT_ASSERT(y.next(die3) == STATE_DEAD);
        CPPUNIT_ASSERT(y.next(live1) == STATE_ALIVE);
        CPPUNIT_ASSERT(y.next(live2) == STATE_ALIVE);
    }

    CPPUNIT_TEST_SUITE(TestCellFredkin);
    CPPUNIT_TEST(test_cstr_alive);
    CPPUNIT_TEST(test_cstr_dead);
    CPPUNIT_TEST(test_die);
    CPPUNIT_TEST(test_live);
    CPPUNIT_TEST(test_age);
    CPPUNIT_TEST(test_evolve_state);
    CPPUNIT_TEST(test_next);
    CPPUNIT_TEST_SUITE_END();
};

struct TestLifeConway : CppUnit::TestFixture {
    void test_cstr() {
        std::istringstream iss;
        iss.str("6\n"
                "5\n"
                ".....\n"
                ".*.*.\n"
                "..*..\n"
                "..*..\n"
                ".*.*.\n"
                ".....");
        std::ostringstream oss;
        int w = 0, h = 0;
        char a = 0;
        iss >> h >> w;
        CPPUNIT_ASSERT(w == 5);
        CPPUNIT_ASSERT(h == 6);
        Life<ConwayCell> l(w,h);
        for(int r = 0; r < h; ++r)
        {
            for(int c = 0; c < w; ++c)
            {
                iss >> a;
                switch (a) {
                    case '.':
                        l.pushCell(ConwayCell(STATE_DEAD));
                        break;
                    case '*':
                        l.pushCell(ConwayCell(STATE_ALIVE));
                        break;
                }
            }
        }
        oss << l;
        CPPUNIT_ASSERT(oss.str() == "Generation = 0, Population = 6.\n"
                                    ".....\n"
                                    ".*.*.\n"
                                    "..*..\n"
                                    "..*..\n"
                                    ".*.*.\n"
                                    ".....\n");
    }

    void test_simulate() {
        std::istringstream iss;
        iss.str("6\n"
                "5\n"
                "*.*.*\n"
                ".*.*.\n"
                "*.*.*\n"
                ".*.*.\n"
                "*.*.*\n"
                ".*.*.");
        std::ostringstream oss;
        int w = 0, h = 0;
        char a = 0;
        iss >> h >> w;
        CPPUNIT_ASSERT(w == 5);
        CPPUNIT_ASSERT(h == 6);
        Life<ConwayCell> l(w,h);
        for(int r = 0; r < h; ++r)
        {
            for(int c = 0; c < w; ++c)
            {
                iss >> a;
                switch (a) {
                    case '.':
                        l.pushCell(ConwayCell(STATE_DEAD));
                        break;
                    case '*':
                        l.pushCell(ConwayCell(STATE_ALIVE));
                        break;
                }
            }
        }
        oss << l;
        CPPUNIT_ASSERT(oss.str() == "Generation = 0, Population = 15.\n"
                                    "*.*.*\n"
                                    ".*.*.\n"
                                    "*.*.*\n"
                                    ".*.*.\n"
                                    "*.*.*\n"
                                    ".*.*.\n");
        l.simulate(1);
        oss.str("");
        oss << l;
        CPPUNIT_ASSERT(oss.str() == "Generation = 1, Population = 14.\n"
                                    ".***.\n"
                                    "*...*\n"
                                    "*...*\n"
                                    "*...*\n"
                                    "*...*\n"
                                    ".***.\n");
    }

    CPPUNIT_TEST_SUITE(TestLifeConway);
    CPPUNIT_TEST(test_cstr);
    CPPUNIT_TEST(test_simulate);
    CPPUNIT_TEST_SUITE_END();
};

struct TestLifeFredkin : CppUnit::TestFixture {
    void test_cstr() {
        std::istringstream iss;
        iss.str("6\n"
                "5\n"
                "--0--\n"
                "-----\n"
                "--0--\n"
                "--0--\n"
                "-----\n"
                "--0--");
        std::ostringstream oss;
        int w = 0, h = 0;
        char a = 0;
        iss >> h >> w;
        CPPUNIT_ASSERT(w == 5);
        CPPUNIT_ASSERT(h == 6);
        Life<FredkinCell> l(w,h);
        for(int r = 0; r < h; ++r)
        {
            for(int c = 0; c < w; ++c)
            {
                iss >> a;
                switch (a) {
                    case '-':
                        l.pushCell(FredkinCell(STATE_DEAD));
                        break;
                    case '0':
                        l.pushCell(FredkinCell(STATE_ALIVE));
                        break;
                }
            }
        }
        oss << l;
        CPPUNIT_ASSERT(oss.str() == "Generation = 0, Population = 4.\n"
                                    "--0--\n"
                                    "-----\n"
                                    "--0--\n"
                                    "--0--\n"
                                    "-----\n"
                                    "--0--\n");
    }

    void test_simulate() {
        std::istringstream iss;
        iss.str("6\n"
                "5\n"
                "-----\n"
                "-0-0-\n"
                "--0--\n"
                "--0--\n"
                "-0-0-\n"
                "-----");
        std::ostringstream oss;
        int w = 0, h = 0;
        char a = 0;
        iss >> h >> w;
        CPPUNIT_ASSERT(w == 5);
        CPPUNIT_ASSERT(h == 6);
        Life<FredkinCell> l(w,h);
        for(int r = 0; r < h; ++r)
        {
            for(int c = 0; c < w; ++c)
            {
                iss >> a;
                switch (a) {
                    case '-':
                        l.pushCell(FredkinCell(STATE_DEAD));
                        break;
                    case '0':
                        l.pushCell(FredkinCell(STATE_ALIVE));
                        break;
                }
            }
        }
        oss << l;
        CPPUNIT_ASSERT(oss.str() == "Generation = 0, Population = 6.\n"
                                    "-----\n"
                                    "-0-0-\n"
                                    "--0--\n"
                                    "--0--\n"
                                    "-0-0-\n"
                                    "-----\n");
        l.simulate(1);
        oss.str("");
        oss << l;
        CPPUNIT_ASSERT(oss.str() == "Generation = 1, Population = 12.\n"
                                    "-0-0-\n"
                                    "0-0-0\n"
                                    "--1--\n"
                                    "--1--\n"
                                    "0-0-0\n"
                                    "-0-0-\n");
        l.simulate(99);
        oss.str("");
        oss << l;
        CPPUNIT_ASSERT(oss.str() == "Generation = 100, Population = 6.\n"
                                    "-----\n"
                                    "-+-+-\n"
                                    "--+--\n"
                                    "--+--\n"
                                    "-+-+-\n"
                                    "-----\n");
    }

    CPPUNIT_TEST_SUITE(TestLifeFredkin);
    CPPUNIT_TEST(test_cstr);
    CPPUNIT_TEST(test_simulate);
    CPPUNIT_TEST_SUITE_END();
};

struct TestLifeCell : CppUnit::TestFixture {
    void test_cstr() {
        std::istringstream iss;
        std::ostringstream oss;
        int width = 0, height = 0;
        char a = 0;
        iss.str("6\n"
                "5\n"
                "-----\n"
                "-0-0-\n"
                "--0--\n"
                "--0--\n"
                "-0-0-\n"
                "-----");
        iss >> height >> width;
        Life<Cell> l(width,height);
        for(int r = 0; r < height; ++r)
        {
            for(int c = 0; c < width; ++c)
            {
                iss >> a;
                switch (a) {
                    case '-':
                        l.pushCell(new FredkinCell(STATE_DEAD));
                        break;
                    case '0':
                        l.pushCell(new FredkinCell(STATE_ALIVE));
                        break;
                }
            }
        }
        oss << l;
        CPPUNIT_ASSERT(oss.str() == "Generation = 0, Population = 6.\n"
                                    "-----\n"
                                    "-0-0-\n"
                                    "--0--\n"
                                    "--0--\n"
                                    "-0-0-\n"
                                    "-----\n");
    }

    void test_simulate() {
        std::istringstream iss;
        std::ostringstream oss;
        int width = 0, height = 0;
        char a = 0;
        iss.str("6\n"
                "5\n"
                "-----\n"
                "-0-0-\n"
                "--0--\n"
                "--0--\n"
                "-0-0-\n"
                "-----");
        iss >> height >> width;
        Life<Cell> l(width,height);
        for(int r = 0; r < height; ++r)
        {
            for(int c = 0; c < width; ++c)
            {
                iss >> a;
                switch (a) {
                    case '-':
                        l.pushCell(new FredkinCell(STATE_DEAD));
                        break;
                    case '0':
                        l.pushCell(new FredkinCell(STATE_ALIVE));
                        break;
                }
            }
        }
        oss << l;
        CPPUNIT_ASSERT(oss.str() == "Generation = 0, Population = 6.\n"
                                    "-----\n"
                                    "-0-0-\n"
                                    "--0--\n"
                                    "--0--\n"
                                    "-0-0-\n"
                                    "-----\n");
        l.simulate(10);
        oss.str("");
        oss << l;
        CPPUNIT_ASSERT(oss.str() == "Generation = 10, Population = 14.\n"
                                    "0*.*0\n"
                                    ".*.*.\n"
                                    "..*..\n"
                                    "..*..\n"
                                    ".*.*.\n"
                                    "0*.*0\n");
        l.simulate(10);
        oss.str("");
        oss << l;
        CPPUNIT_ASSERT(oss.str() == "Generation = 20, Population = 0.\n"
                                    "-...-\n"
                                    ".....\n"
                                    ".....\n"
                                    ".....\n"
                                    ".....\n"
                                    "-...-\n");
    }

    CPPUNIT_TEST_SUITE(TestLifeCell);
    CPPUNIT_TEST(test_cstr);
    CPPUNIT_TEST(test_simulate);
    CPPUNIT_TEST_SUITE_END();
};

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout << "TestLife.c++\n";

    CppUnit::TextTestRunner tr;
    tr.addTest(TestConway::suite());
    tr.addTest(TestFredkin::suite());
    tr.addTest(TestCellConway::suite());
    tr.addTest(TestCellFredkin::suite());
    tr.addTest(TestLifeConway::suite());
    tr.addTest(TestLifeFredkin::suite());
    tr.addTest(TestLifeCell::suite());
    tr.run();

    cout << "Done.\n";
    return 0;
}
