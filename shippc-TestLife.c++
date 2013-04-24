// ------------------------------------
// cs371p-life/TestLife.c++
// Copyright (C) 2013
// Glenn P. Downing
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

#include <algorithm> // count
#include <iostream>  // ios_base
#include <memory>    // allocator
#include <vector>
#include <utility>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define private public
#define protected public
#define class struct

#include "AbstractCell.h"
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Handle.h"
#include "Life.h"

// -------------
// TestLife
// -------------

struct TestLife : CppUnit::TestFixture {


    // --------------------
    // test_ConwayCell
    // --------------------

    void test_ConwayCell() {
      ConwayCell cell(true);

      CPPUNIT_ASSERT(cell.character == '*');
      CPPUNIT_ASSERT(cell.alive == true);
      CPPUNIT_ASSERT(cell.next_character == '*');
      CPPUNIT_ASSERT(cell.next_alive == true);
    }

    // --------------------
    // test_ConwayCell2
    // --------------------

    void test_ConwayCell2() {
      ConwayCell cell(false);

      CPPUNIT_ASSERT(cell.character == '.');
      CPPUNIT_ASSERT(cell.alive == false);
      CPPUNIT_ASSERT(cell.next_character == '.');
      CPPUNIT_ASSERT(cell.next_alive == false);
    }

    // --------------------
    // test_ConwayCell3
    // --------------------

    void test_ConwayCell3() {
      ConwayCell cell(true);

      CPPUNIT_ASSERT(cell.next_character == '*');
      CPPUNIT_ASSERT(cell.next_alive == true);
    }

    // --------------------
    // test_ConwayEquals
    // --------------------

    void test_ConwayEquals() {
      ConwayCell cell(true);
      ConwayCell cell2(true);

      CPPUNIT_ASSERT(cell == cell2);
    }

    // --------------------
    // test_ConwayEquals2
    // --------------------

    void test_ConwayEquals2() {
      ConwayCell cell(false);
      ConwayCell cell2(false);

      CPPUNIT_ASSERT(cell == cell2);
    }

    // --------------------
    // test_ConwayEquals3
    // --------------------

    void test_ConwayEquals3() {
      ConwayCell cell(true);
      ConwayCell cell2(false);

      CPPUNIT_ASSERT(!(cell == cell2));
    }

    // --------------------
    // test_ConwayAssignment
    // --------------------

    void test_ConwayAssignment() {
      ConwayCell cell(true);

      CPPUNIT_ASSERT(cell.character == '*');
      CPPUNIT_ASSERT(cell.alive == true);

      ConwayCell cell2(false);
      cell = cell2;

      CPPUNIT_ASSERT(cell.character == '.');
      CPPUNIT_ASSERT(cell.alive == false);
    }

    // --------------------
    // test_ConwayAssignment2
    // --------------------

    void test_ConwayAssignment2() {
      ConwayCell cell(false);

      CPPUNIT_ASSERT(cell.character == '.');
      CPPUNIT_ASSERT(cell.alive == false);

      ConwayCell cell2(true);
      cell = cell2;

      CPPUNIT_ASSERT(cell.character == '*');
      CPPUNIT_ASSERT(cell.alive == true);
    }

    // --------------------
    // test_ConwayAssignment3
    // --------------------

    void test_ConwayAssignment3() {
      ConwayCell cell(true);

      CPPUNIT_ASSERT(cell.character == '*');
      CPPUNIT_ASSERT(cell.alive == true);

      ConwayCell cell2(false);
      cell = cell2;

      CPPUNIT_ASSERT(cell.next_character == '.');
      CPPUNIT_ASSERT(cell.next_alive == false);
    }

    // --------------------
    // test_ConwayOlder
    // --------------------

    void test_ConwayOlder() {
      ConwayCell cell(true);
      cell.older();

      CPPUNIT_ASSERT(cell.character = '*');
      CPPUNIT_ASSERT(cell.alive == true);
    }

    // --------------------
    // test_ConwayOlder2
    // --------------------

    void test_ConwayOlder2() {
      ConwayCell cell(false);
      cell.older();

      CPPUNIT_ASSERT(cell.character = '.');
      CPPUNIT_ASSERT(cell.alive == false);
    }

    // --------------------
    // test_ConwayOlder3
    // --------------------

    void test_ConwayOlder3() {
      ConwayCell cell(true);
      cell.older();

      CPPUNIT_ASSERT(cell.next_character = '*');
      CPPUNIT_ASSERT(cell.next_alive == true);
    }

    // --------------------
    // test_ConwayStep
    // --------------------

    void test_ConwayStep() {
      ConwayCell cell(true);
      cell.next_alive = false;
      cell.next_character = '.';

      cell.step();

      CPPUNIT_ASSERT(cell.character = '.');
      CPPUNIT_ASSERT(cell.alive == false);
    }

    // --------------------
    // test_ConwayStep2
    // --------------------

    void test_ConwayStep2() {
      ConwayCell cell(false);
      cell.next_alive = false;
      cell.next_character = '.';

      cell.step();

      CPPUNIT_ASSERT(cell.character = '.');
      CPPUNIT_ASSERT(cell.alive == false);
    }

    // --------------------
    // test_ConwayStep3
    // --------------------

    void test_ConwayStep3() {
      ConwayCell cell(false);
      cell.next_alive = true;
      cell.next_character = '*';

      cell.step();

      CPPUNIT_ASSERT(cell.character = '*');
      CPPUNIT_ASSERT(cell.alive == true);
    }

    // --------------------
    // test_ConwayMutate
    // --------------------

    void test_ConwayMutate() {
      ConwayCell cell(true);

      AbstractCell* ac = cell.mutate();

      CPPUNIT_ASSERT(ac == 0);
    }

    // --------------------
    // test_ConwayMutate2
    // --------------------

    void test_ConwayMutate2() {
      ConwayCell cell(false);

      AbstractCell* ac = cell.mutate();

      CPPUNIT_ASSERT(ac == 0);
    }

    // --------------------
    // test_ConwayMutate3
    // --------------------

    void test_ConwayMutate3() {
      ConwayCell cell(false);
      ConwayCell cell2 = cell;

      AbstractCell* ac = cell.mutate();

      CPPUNIT_ASSERT(ac == 0);
      CPPUNIT_ASSERT(cell == cell2);
    }

    // --------------------
    // test_ConwayClone
    // --------------------

    void test_ConwayClone() {
      ConwayCell cell(true);
      ConwayCell* cp = cell.clone();

      CPPUNIT_ASSERT(*cp == cell);
    }

    // --------------------
    // test_ConwayClone2
    // --------------------

    void test_ConwayClone2() {
      ConwayCell cell(false);
      ConwayCell* cp = cell.clone();

      CPPUNIT_ASSERT(*cp == cell);
    }

    // --------------------
    // test_ConwayClone3
    // --------------------

    void test_ConwayClone3() {
      ConwayCell cell(true);
      ConwayCell* cp = cell.clone();
      ConwayCell cell2(false);


      CPPUNIT_ASSERT(!(*cp == cell2));
    }

    // --------------------
    // test_ConwayNeighbors
    // --------------------

    void test_ConwayNeighbors() {
      ConwayCell cell(true);
      std::vector<std::pair<int, int> > neighbors = cell.neighbors(1, 1); // (1, 1) represents the top-left corner.

      std::vector<std::pair<int, int> > tester;
      tester.push_back(std::make_pair(0, 0));
      tester.push_back(std::make_pair(0, 1));
      tester.push_back(std::make_pair(0, 2));
      tester.push_back(std::make_pair(1, 0));
      tester.push_back(std::make_pair(1, 2));
      tester.push_back(std::make_pair(2, 0));
      tester.push_back(std::make_pair(2, 1));
      tester.push_back(std::make_pair(2, 2));

      CPPUNIT_ASSERT(neighbors == tester);
    }

    // --------------------
    // test_ConwayNeighbors2
    // --------------------

    void test_ConwayNeighbors2() {
      ConwayCell cell(true);
      std::vector<std::pair<int, int> > neighbors = cell.neighbors(2, 1); // (2, 1) represents an edge cell.

      std::vector<std::pair<int, int> > tester;
      tester.push_back(std::make_pair(1, 0));
      tester.push_back(std::make_pair(1, 1));
      tester.push_back(std::make_pair(1, 2));
      tester.push_back(std::make_pair(2, 0));
      tester.push_back(std::make_pair(2, 2));
      tester.push_back(std::make_pair(3, 0));
      tester.push_back(std::make_pair(3, 1));
      tester.push_back(std::make_pair(3, 2));

      CPPUNIT_ASSERT(neighbors == tester);
    }

    // --------------------
    // test_ConwayNeighbors3
    // --------------------

    void test_ConwayNeighbors3() {
      ConwayCell cell(true);
      std::vector<std::pair<int, int> > neighbors = cell.neighbors(2, 2);  // (2, 2) represents an interior cell.

      std::vector<std::pair<int, int> > tester;
      tester.push_back(std::make_pair(1, 1));
      tester.push_back(std::make_pair(1, 2));
      tester.push_back(std::make_pair(1, 3));
      tester.push_back(std::make_pair(2, 1));
      tester.push_back(std::make_pair(2, 3));
      tester.push_back(std::make_pair(3, 1));
      tester.push_back(std::make_pair(3, 2));
      tester.push_back(std::make_pair(3, 3));

      CPPUNIT_ASSERT(neighbors == tester);
    }

    // --------------------
    // test_ConwayDecide
    // --------------------

    void test_ConwayDecide() {
      ConwayCell cell(true);
      cell.decide(0);

      CPPUNIT_ASSERT(cell.next_alive == false);
      CPPUNIT_ASSERT(cell.next_character == '.');
    }

    // --------------------
    // test_ConwayDecide2
    // --------------------

    void test_ConwayDecide2() {
      ConwayCell cell(true);
      cell.decide(3);

      CPPUNIT_ASSERT(cell.next_alive == true);
      CPPUNIT_ASSERT(cell.next_character == '*');
    }

    // --------------------
    // test_ConwayDecide3
    // --------------------

    void test_ConwayDecide3() {
      ConwayCell cell(false);
      cell.decide(3);

      CPPUNIT_ASSERT(cell.next_alive == true);
      CPPUNIT_ASSERT(cell.next_character == '*');
    }

    // --------------------
    // test_ConwayDie
    // --------------------

    void test_ConwayDie() {
      ConwayCell cell(true);
      cell.die();

      CPPUNIT_ASSERT(cell.next_alive == false);
    }

    // --------------------
    // test_ConwayDie2
    // --------------------

    void test_ConwayDie2() {
      ConwayCell cell(false);
      cell.die();

      CPPUNIT_ASSERT(cell.next_alive == false);
    }

    // --------------------
    // test_ConwayDie3
    // --------------------

    void test_ConwayDie3() {
      ConwayCell cell(true);
      cell.die();

      CPPUNIT_ASSERT(cell.alive == true);
      CPPUNIT_ASSERT(cell.next_alive == false);
    }

    // --------------------
    // test_ConwayLive
    // --------------------

    void test_ConwayLive() {
      ConwayCell cell(true);
      cell.live();

      CPPUNIT_ASSERT(cell.next_alive == true);
    }

    // --------------------
    // test_ConwayLive2
    // --------------------

    void test_ConwayLive2() {
      ConwayCell cell(false);
      cell.live();

      CPPUNIT_ASSERT(cell.next_alive == true);
    }

    // --------------------
    // test_ConwayLive3
    // --------------------

    void test_ConwayLive3() {
      ConwayCell cell(false);
      cell.live();

      CPPUNIT_ASSERT(cell.next_alive = true);
      CPPUNIT_ASSERT(cell.alive == false);

    }

    // --------------------
    // test_ConwayIsAlive
    // --------------------

    void test_ConwayIsAlive() {
      ConwayCell cell(true);
      CPPUNIT_ASSERT(cell.is_alive());
    }

    // --------------------
    // test_ConwayIsAlive2
    // --------------------

    void test_ConwayIsAlive2() {
      ConwayCell cell(false);
      CPPUNIT_ASSERT(!cell.is_alive());
    }

    // --------------------
    // test_ConwayIsAlive3
    // --------------------

    void test_ConwayIsAlive3() {
      ConwayCell cell(true);
      ConwayCell *cp = cell.clone();;
      CPPUNIT_ASSERT((*cp).is_alive());
    }

    // --------------------
    // test_ConwaySetNextChar
    // --------------------

    void test_ConwaySetNextChar() {
      ConwayCell cell(true);
      cell.die();
      cell.set_nextchar('.');

      CPPUNIT_ASSERT(cell.next_alive == false);
      CPPUNIT_ASSERT(cell.next_character == '.');
    }

    // --------------------
    // test_ConwaySetNextChar2
    // --------------------

    void test_ConwaySetNextChar2() {
      ConwayCell cell(false);
      cell.live();
      cell.set_nextchar('*');

      CPPUNIT_ASSERT(cell.next_alive == true);
      CPPUNIT_ASSERT(cell.next_character == '*');
    }

    // --------------------
    // test_ConwaySetNextChar3
    // --------------------

    void test_ConwaySetNextChar3() {
      ConwayCell cell(false);
      cell.die();
      cell.set_nextchar('.');

      CPPUNIT_ASSERT(cell.next_alive == false);
      CPPUNIT_ASSERT(cell.next_character == '.');
    }

    // --------------------
    // test_ConwayWillBeAlive
    // --------------------

    void test_ConwayWillBeAlive() {
      ConwayCell cell(true);

      CPPUNIT_ASSERT(cell.willbe_alive());
    }

    // --------------------
    // test_ConwayWillBeAlive2
    // --------------------

    void test_ConwayWillBeAlive2() {
      ConwayCell cell(false);

      CPPUNIT_ASSERT(!cell.willbe_alive());
    }

    // --------------------
    // test_ConwayWillBeAlive3
    // --------------------

    void test_ConwayWillBeAlive3() {
      ConwayCell cell(true);

      cell.next_alive = false;

      CPPUNIT_ASSERT(!cell.willbe_alive());
    }

    // --------------------
    // test_ConwayGetCharacter
    // --------------------

    void test_ConwayGetCharacter() {
      ConwayCell cell(true);

      CPPUNIT_ASSERT(cell.get_character() == '*');
    }

    // --------------------
    // test_ConwayGetCharacter2
    // --------------------

    void test_ConwayGetCharacter2() {
      ConwayCell cell(false);

      CPPUNIT_ASSERT(cell.get_character() == '.');
    }

    // --------------------
    // test_ConwayGetCharacter3
    // --------------------

    void test_ConwayGetCharacter3() {
      ConwayCell cell(true);
      cell.character = '.';

      CPPUNIT_ASSERT(cell.get_character() == '.');
    }

    // --------------------
    // test_FredkinCell
    // --------------------

    void test_FredkinCell() {
      FredkinCell cell(true);

      CPPUNIT_ASSERT(cell.character == '0');
      CPPUNIT_ASSERT(cell.alive == true);
      CPPUNIT_ASSERT(cell.next_character == '0');
      CPPUNIT_ASSERT(cell.next_alive == true);
    }

    // --------------------
    // test_FredkinCell2
    // --------------------

    void test_FredkinCell2() {
      FredkinCell cell(false);

      CPPUNIT_ASSERT(cell.character == '-');
      CPPUNIT_ASSERT(cell.alive == false);
      CPPUNIT_ASSERT(cell.next_character == '-');
      CPPUNIT_ASSERT(cell.next_alive == false);
    }

    // --------------------
    // test_FredkinCell3
    // --------------------

    void test_FredkinCell3() {
      FredkinCell cell(true);

      CPPUNIT_ASSERT(cell.next_character == '0');
      CPPUNIT_ASSERT(cell.next_alive == true);
    }

    // --------------------
    // test_FredkinEquals
    // --------------------

    void test_FredkinEquals() {
      FredkinCell cell(true);
      FredkinCell cell2(true);

      CPPUNIT_ASSERT(cell == cell2);
    }

    // --------------------
    // test_FredkinEquals2
    // --------------------

    void test_FredkinEquals2() {
      FredkinCell cell(false);
      FredkinCell cell2(false);

      CPPUNIT_ASSERT(cell == cell2);
    }

    // --------------------
    // test_FredkinEquals3
    // --------------------

    void test_FredkinEquals3() {
      FredkinCell cell(true);
      FredkinCell cell2(false);

      CPPUNIT_ASSERT(!(cell == cell2));
    }

    // --------------------
    // test_FredkinAssignment
    // --------------------

    void test_FredkinAssignment() {
      FredkinCell cell(true);

      CPPUNIT_ASSERT(cell.character == '0');
      CPPUNIT_ASSERT(cell.alive == true);

      FredkinCell cell2(false);
      cell = cell2;

      CPPUNIT_ASSERT(cell.character == '-');
      CPPUNIT_ASSERT(cell.alive == false);
    }

    // --------------------
    // test_FredkinAssignment2
    // --------------------

    void test_FredkinAssignment2() {
      FredkinCell cell(false);

      CPPUNIT_ASSERT(cell.character == '-');
      CPPUNIT_ASSERT(cell.alive == false);

      FredkinCell cell2(true);
      cell = cell2;

      CPPUNIT_ASSERT(cell.character == '0');
      CPPUNIT_ASSERT(cell.alive == true);
    }

    // --------------------
    // test_FredkinAssignment3
    // --------------------

    void test_FredkinAssignment3() {
      FredkinCell cell(true);

      CPPUNIT_ASSERT(cell.character == '0');
      CPPUNIT_ASSERT(cell.alive == true);

      FredkinCell cell2(false);
      cell = cell2;

      CPPUNIT_ASSERT(cell.next_character == '-');
      CPPUNIT_ASSERT(cell.next_alive == false);
    }

    // --------------------
    // test_FredkinOlder
    // --------------------

    void test_FredkinOlder() {
      FredkinCell cell(true);
      cell.older();

      CPPUNIT_ASSERT(cell.character = '0');
      CPPUNIT_ASSERT(cell.age == 0);
      CPPUNIT_ASSERT(cell.alive == true);
    }

    // --------------------
    // test_FredkinOlder2
    // --------------------

    void test_FredkinOlder2() {
      FredkinCell cell(false);
      cell.older();

      CPPUNIT_ASSERT(cell.character = '-');
      CPPUNIT_ASSERT(cell.alive == false);
    }

    // --------------------
    // test_FredkinOlder3
    // --------------------

    void test_FredkinOlder3() {
      FredkinCell cell(true);
      cell.older();

      CPPUNIT_ASSERT(cell.next_character = '1');
      CPPUNIT_ASSERT(cell.next_age == 1);
      CPPUNIT_ASSERT(cell.next_alive == true);
    }

    // --------------------
    // test_FredkinStep
    // --------------------

    void test_FredkinStep() {
      FredkinCell cell(true);
      cell.next_alive = false;
      cell.next_character = '-';

      cell.step();

      CPPUNIT_ASSERT(cell.character = '-');
      CPPUNIT_ASSERT(cell.alive == false);
      CPPUNIT_ASSERT(cell.age == 0);
    }

    // --------------------
    // test_FredkinStep2
    // --------------------

    void test_FredkinStep2() {
      FredkinCell cell(false);
      cell.next_alive = false;
      cell.next_character = '-';

      cell.step();

      CPPUNIT_ASSERT(cell.character = '-');
      CPPUNIT_ASSERT(cell.alive == false);
      CPPUNIT_ASSERT(cell.age == 0);
    }

    // --------------------
    // test_FredkinStep3
    // --------------------

    void test_FredkinStep3() {
      FredkinCell cell(false);
      cell.next_alive = true;
      cell.next_character = '1';

      cell.step();

      CPPUNIT_ASSERT(cell.character = '1');
      CPPUNIT_ASSERT(cell.alive == true);
      CPPUNIT_ASSERT(cell.age == 0);
    }

    // --------------------
    // test_FredkinMutate
    // --------------------

    void test_FredkinMutate() {
      FredkinCell cell(true);
      // cell.next_age == 2;
      // cell.next_alive == true;

      AbstractCell* ac = cell.mutate();

      CPPUNIT_ASSERT((*ac) == cell);
    }

    // --------------------
    // test_FredkinMutate2
    // --------------------

    void test_FredkinMutate2() {
      FredkinCell cell(true);
      // cell.next_age == 2;
      // cell.next_alive == true;

      AbstractCell* ac = cell.mutate();

      CPPUNIT_ASSERT((*ac) == cell);
    }

    // --------------------
    // test_FredkinMutate2
    // --------------------

    void test_FredkinMutate3() {
      FredkinCell cell(true);
      // cell.next_age == 1;
      // cell.next_alive == true;

      AbstractCell* ac = cell.mutate();

      CPPUNIT_ASSERT((*ac) == cell);
    }

    // --------------------
    // test_FredkinClone
    // --------------------

    void test_FredkinClone() {
      FredkinCell cell(true);
      FredkinCell* cp = cell.clone();

      CPPUNIT_ASSERT(*cp == cell);
    }

    // --------------------
    // test_FredkinClone2
    // --------------------

    void test_FredkinClone2() {
      FredkinCell cell(false);
      FredkinCell* cp = cell.clone();

      CPPUNIT_ASSERT(*cp == cell);
    }

    // --------------------
    // test_FredkinClone3
    // --------------------

    void test_FredkinClone3() {
      FredkinCell cell(true);
      FredkinCell* cp = cell.clone();
      FredkinCell cell2(false);


      CPPUNIT_ASSERT(!(*cp == cell2));
    }

    // --------------------
    // test_FredkinNeighbors
    // --------------------

    void test_FredkinNeighbors() {
      FredkinCell cell(true);
      std::vector<std::pair<int, int> > neighbors = cell.neighbors(1, 1); // (1, 1) represents the top-left corner.

      std::vector<std::pair<int, int> > tester;

      tester.push_back(std::make_pair(0, 1));

      tester.push_back(std::make_pair(1, 0));
      tester.push_back(std::make_pair(1, 2));

      tester.push_back(std::make_pair(2, 1));


      CPPUNIT_ASSERT(neighbors == tester);
    }

    // --------------------
    // test_FredkinNeighbors2
    // --------------------

    void test_FredkinNeighbors2() {
      FredkinCell cell(true);
      std::vector<std::pair<int, int> > neighbors = cell.neighbors(2, 1); // (2, 1) represents an edge cell.

      std::vector<std::pair<int, int> > tester;

      tester.push_back(std::make_pair(1, 1));

      tester.push_back(std::make_pair(2, 0));
      tester.push_back(std::make_pair(2, 2));

      tester.push_back(std::make_pair(3, 1));


      CPPUNIT_ASSERT(neighbors == tester);
    }

    // --------------------
    // test_FredkinNeighbors3
    // --------------------

    void test_FredkinNeighbors3() {
      FredkinCell cell(true);
      std::vector<std::pair<int, int> > neighbors = cell.neighbors(2, 2);  // (2, 2) represents an interior cell.

      std::vector<std::pair<int, int> > tester;

      tester.push_back(std::make_pair(1, 2));

      tester.push_back(std::make_pair(2, 1));
      tester.push_back(std::make_pair(2, 3));

      tester.push_back(std::make_pair(3, 2));


      CPPUNIT_ASSERT(neighbors == tester);
    }

    // --------------------
    // test_FredkinDecide
    // --------------------

    void test_FredkinDecide() {
      FredkinCell cell(true);
      cell.decide(0);

      CPPUNIT_ASSERT(cell.next_alive == false);
      // CPPUNIT_ASSERT(cell.next_character == '-');  // not set in this method.
    }

    // --------------------
    // test_FredkinDecide2
    // --------------------

    void test_FredkinDecide2() {
      FredkinCell cell(true);
      cell.decide(3);

      CPPUNIT_ASSERT(cell.next_alive == true);
      CPPUNIT_ASSERT(cell.next_character == '0');
    }

    // --------------------
    // test_FredkinDecide3
    // --------------------

    void test_FredkinDecide3() {
      FredkinCell cell(false);
      cell.decide(3);

      CPPUNIT_ASSERT(cell.next_alive == true);
      // CPPUNIT_ASSERT(cell.next_character == '0');  // not set in this method.
    }

    // --------------------
    // test_FredkinDie
    // --------------------

    void test_FredkinDie() {
      FredkinCell cell(true);
      cell.die();

      CPPUNIT_ASSERT(cell.next_alive == false);
    }

    // --------------------
    // test_FredkinDie2
    // --------------------

    void test_FredkinDie2() {
      FredkinCell cell(false);
      cell.die();

      CPPUNIT_ASSERT(cell.next_alive == false);
    }

    // --------------------
    // test_FredkinDie3
    // --------------------

    void test_FredkinDie3() {
      FredkinCell cell(true);
      cell.die();

      CPPUNIT_ASSERT(cell.alive == true);
      CPPUNIT_ASSERT(cell.next_alive == false);
    }

    // --------------------
    // test_FredkinLive
    // --------------------

    void test_FredkinLive() {
      FredkinCell cell(true);
      cell.live();

      CPPUNIT_ASSERT(cell.next_alive == true);
    }

    // --------------------
    // test_FredkinLive2
    // --------------------

    void test_FredkinLive2() {
      FredkinCell cell(false);
      cell.live();

      CPPUNIT_ASSERT(cell.next_alive == true);
    }

    // --------------------
    // test_FredkinLive3
    // --------------------

    void test_FredkinLive3() {
      FredkinCell cell(false);
      cell.live();

      CPPUNIT_ASSERT(cell.next_alive = true);
      CPPUNIT_ASSERT(cell.alive == false);

    }

    // --------------------
    // test_FredkinIsAlive
    // --------------------

    void test_FredkinIsAlive() {
      FredkinCell cell(true);
      CPPUNIT_ASSERT(cell.is_alive());
    }

    // --------------------
    // test_FredkinIsAlive2
    // --------------------

    void test_FredkinIsAlive2() {
      FredkinCell cell(false);
      CPPUNIT_ASSERT(!cell.is_alive());
    }

    // --------------------
    // test_FredkinIsAlive3
    // --------------------

    void test_FredkinIsAlive3() {
      FredkinCell cell(true);
      FredkinCell *cp = cell.clone();;
      CPPUNIT_ASSERT((*cp).is_alive());
    }

    // --------------------
    // test_FredkinSetNextChar
    // --------------------

    void test_FredkinSetNextChar() {
      FredkinCell cell(true);
      cell.die();
      cell.set_nextchar('-');

      CPPUNIT_ASSERT(cell.next_alive == false);
      CPPUNIT_ASSERT(cell.next_character == '-');
    }

    // --------------------
    // test_FredkinSetNextChar2
    // --------------------

    void test_FredkinSetNextChar2() {
      FredkinCell cell(false);
      cell.live();
      cell.set_nextchar('0');

      CPPUNIT_ASSERT(cell.next_alive == true);
      CPPUNIT_ASSERT(cell.next_character == '0');
    }

    // --------------------
    // test_FredkinSetNextChar3
    // --------------------

    void test_FredkinSetNextChar3() {
      FredkinCell cell(false);
      cell.die();
      cell.set_nextchar('-');

      CPPUNIT_ASSERT(cell.next_alive == false);
      CPPUNIT_ASSERT(cell.next_character == '-');
    }

    // --------------------
    // test_FredkinWillBeAlive
    // --------------------

    void test_FredkinWillBeAlive() {
      FredkinCell cell(true);

      CPPUNIT_ASSERT(cell.willbe_alive());
    }

    // --------------------
    // test_FredkinWillBeAlive2
    // --------------------

    void test_FredkinWillBeAlive2() {
      FredkinCell cell(false);

      CPPUNIT_ASSERT(!cell.willbe_alive());
    }

    // --------------------
    // test_FredkinWillBeAlive3
    // --------------------

    void test_FredkinWillBeAlive3() {
      FredkinCell cell(true);

      cell.next_alive = false;

      CPPUNIT_ASSERT(!cell.willbe_alive());
    }

    // --------------------
    // test_FredkinGetCharacter
    // --------------------

    void test_FredkinGetCharacter() {
      FredkinCell cell(true);

      CPPUNIT_ASSERT(cell.get_character() == '0');
    }

    // --------------------
    // test_FredkinGetCharacter2
    // --------------------

    void test_FredkinGetCharacter2() {
      FredkinCell cell(false);

      CPPUNIT_ASSERT(cell.get_character() == '-');
    }

    // --------------------
    // test_FredkinGetCharacter3
    // --------------------

    void test_FredkinGetCharacter3() {
      FredkinCell cell(true);
      cell.character = '-';

      CPPUNIT_ASSERT(cell.get_character() == '-');
    }

    // --------------------
    // test_Cell
    // --------------------

    void test_Cell() {
      Cell cell(new FredkinCell(true));

      CPPUNIT_ASSERT(cell.get()->character == '0');
      CPPUNIT_ASSERT(cell.get()->alive == true);
      CPPUNIT_ASSERT(cell.get()->next_character == '0');
      CPPUNIT_ASSERT(cell.get()->next_alive == true);
    }

    // --------------------
    // test_Cell2
    // --------------------

    void test_Cell2() {
      Cell cell(new FredkinCell(false));

      CPPUNIT_ASSERT(cell.get()->character == '-');
      CPPUNIT_ASSERT(cell.get()->alive == false);
      CPPUNIT_ASSERT(cell.get()->next_character == '-');
      CPPUNIT_ASSERT(cell.get()->next_alive == false);
    }

    // --------------------
    // test_Cell3
    // --------------------

    void test_Cell3() {
      Cell cell(new FredkinCell(true));

      CPPUNIT_ASSERT(cell.get()->next_character == '0');
      CPPUNIT_ASSERT(cell.get()->next_alive == true);
    }

    // --------------------
    // test_CellOlder
    // --------------------

    void test_CellOlder() {
      Cell cell(new FredkinCell(true));
      cell.older();

      CPPUNIT_ASSERT(cell.get()->character = '0');
      // CPPUNIT_ASSERT(cell.get()->age == 0);
      CPPUNIT_ASSERT(cell.get()->alive == true);
    }

    // --------------------
    // test_CellOlder2
    // --------------------

    void test_CellOlder2() {
      Cell cell(new FredkinCell(false));
      cell.older();

      CPPUNIT_ASSERT(cell.get()->character = '-');
      CPPUNIT_ASSERT(cell.get()->alive == false);
    }

    // --------------------
    // test_CellOlder3
    // --------------------

    void test_CellOlder3() {
      Cell cell(new FredkinCell(true));
      cell.older();

      CPPUNIT_ASSERT(cell.get()->next_character = '1');
      // CPPUNIT_ASSERT(cell.get()->next_age == 1);
      CPPUNIT_ASSERT(cell.get()->next_alive == true);
    }

    // --------------------
    // test_CellStep
    // --------------------

    void test_CellStep() {
      Cell cell(new FredkinCell(true));
      cell.get()->next_alive = false;
      cell.get()->next_character = '-';

      cell.step();

      CPPUNIT_ASSERT(cell.get()->character = '-');
      CPPUNIT_ASSERT(cell.get()->alive == false);
      // CPPUNIT_ASSERT(cell.get()->age == 0);
    }

    // --------------------
    // test_CellStep2
    // --------------------

    void test_CellStep2() {
      Cell cell(new FredkinCell(false));
      cell.get()->next_alive = false;
      cell.get()->next_character = '-';

      cell.step();

      CPPUNIT_ASSERT(cell.get()->character = '-');
      CPPUNIT_ASSERT(cell.get()->alive == false);
      // CPPUNIT_ASSERT(cell.get()->age == 0);
    }

    // --------------------
    // test_CellStep3
    // --------------------

    void test_CellStep3() {
      Cell cell(new FredkinCell(false));
      cell.get()->next_alive = true;
      cell.get()->next_character = '1';

      cell.step();

      CPPUNIT_ASSERT(cell.get()->character = '1');
      CPPUNIT_ASSERT(cell.get()->alive == true);
      // CPPUNIT_ASSERT(cell.get()->age == 0);
    }

    // --------------------
    // test_CellMutate
    // --------------------

    void test_CellMutate() {
      Cell cell(new FredkinCell(true));
      // cell.get()->next_age == 2;
      // cell.get()->next_alive == true;
      Cell cell2(new FredkinCell(true));
      cell.mutate();

      CPPUNIT_ASSERT(*(cell2.get()) == *(cell.get()));
    }

    // --------------------
    // test_CellMutate2
    // --------------------

    void test_CellMutate2() {
      Cell cell(new FredkinCell(true));
      // cell.get()->next_age == 2;
      // cell.get()->next_alive == true;
      Cell cell2(new FredkinCell(true));
      cell.mutate();

      CPPUNIT_ASSERT(*(cell2.get()) == *(cell.get()));
    }

    // --------------------
    // test_CellMutate2
    // --------------------

    void test_CellMutate3() {
      Cell cell(new FredkinCell(true));
      // cell.get()->next_age == 1;
      // cell.get()->next_alive == true;
      Cell cell2(new FredkinCell(true));
      cell.mutate();

      CPPUNIT_ASSERT(*(cell2.get()) == *(cell.get()));
    }

    // --------------------
    // test_CellClone
    // --------------------

    void test_CellClone() {
      Cell cell(new FredkinCell(true));
      AbstractCell* cp = cell.clone();

      CPPUNIT_ASSERT(*cp == *(cell.get()));
    }

    // --------------------
    // test_CellClone2
    // --------------------

    void test_CellClone2() {
      Cell cell(new FredkinCell(false));
      AbstractCell* cp = cell.clone();

      CPPUNIT_ASSERT(*cp == *(cell.get()));
    }

    // --------------------
    // test_CellClone3
    // --------------------

    void test_CellClone3() {
      Cell cell(new FredkinCell(true));
      AbstractCell* cp = cell.clone();
      Cell cell2(new FredkinCell(false));


      CPPUNIT_ASSERT(!(cp == cell2.get()));
    }

    // --------------------
    // test_CellNeighbors
    // --------------------

    void test_CellNeighbors() {
      Cell cell(new FredkinCell(true));
      std::vector<std::pair<int, int> > neighbors = cell.neighbors(1, 1); // (1, 1) represents the top-left corner.

      std::vector<std::pair<int, int> > tester;

      tester.push_back(std::make_pair(0, 1));

      tester.push_back(std::make_pair(1, 0));
      tester.push_back(std::make_pair(1, 2));

      tester.push_back(std::make_pair(2, 1));


      CPPUNIT_ASSERT(neighbors == tester);
    }

    // --------------------
    // test_CellNeighbors2
    // --------------------

    void test_CellNeighbors2() {
      Cell cell(new FredkinCell(true));
      std::vector<std::pair<int, int> > neighbors = cell.neighbors(2, 1); // (2, 1) represents an edge cell.

      std::vector<std::pair<int, int> > tester;

      tester.push_back(std::make_pair(1, 1));

      tester.push_back(std::make_pair(2, 0));
      tester.push_back(std::make_pair(2, 2));

      tester.push_back(std::make_pair(3, 1));


      CPPUNIT_ASSERT(neighbors == tester);
    }

    // --------------------
    // test_CellNeighbors3
    // --------------------

    void test_CellNeighbors3() {
      Cell cell(new FredkinCell(true));
      std::vector<std::pair<int, int> > neighbors = cell.neighbors(2, 2);  // (2, 2) represents an interior cell.

      std::vector<std::pair<int, int> > tester;

      tester.push_back(std::make_pair(1, 2));

      tester.push_back(std::make_pair(2, 1));
      tester.push_back(std::make_pair(2, 3));

      tester.push_back(std::make_pair(3, 2));


      CPPUNIT_ASSERT(neighbors == tester);
    }

    // --------------------
    // test_CellDecide
    // --------------------

    void test_CellDecide() {
      Cell cell(new FredkinCell(true));
      cell.decide(0);

      CPPUNIT_ASSERT(cell.get()->next_alive == false);
      // CPPUNIT_ASSERT(cell.get()->next_character == '-');  // not set in this method.
    }

    // --------------------
    // test_CellDecide2
    // --------------------

    void test_CellDecide2() {
      Cell cell(new FredkinCell(true));
      cell.decide(3);

      CPPUNIT_ASSERT(cell.get()->next_alive == true);
      CPPUNIT_ASSERT(cell.get()->next_character == '0');
    }

    // --------------------
    // test_CellDecide3
    // --------------------

    void test_CellDecide3() {
      Cell cell(new FredkinCell(false));
      cell.decide(3);

      CPPUNIT_ASSERT(cell.get()->next_alive == true);
      // CPPUNIT_ASSERT(cell.get()->next_character == '0');  // not set in this method.
    }
    
    // --------------------
    // test_CellIsAlive
    // --------------------

    void test_CellIsAlive() {
      Cell cell(new FredkinCell(true));
      CPPUNIT_ASSERT(cell.is_alive());
    }

    // --------------------
    // test_CellIsAlive2
    // --------------------

    void test_CellIsAlive2() {
      Cell cell(new FredkinCell(false));
      CPPUNIT_ASSERT(!cell.is_alive());
    }

    // --------------------
    // test_CellIsAlive3
    // --------------------

    void test_CellIsAlive3() {
      Cell cell(new FredkinCell(true));
      AbstractCell *cp = cell.clone();
      CPPUNIT_ASSERT((*cp).is_alive());
    }

    // --------------------
    // test_Life
    // --------------------

    void test_Life() {
      Life<ConwayCell> life(3, 3, ConwayCell(false));

      CPPUNIT_ASSERT(life.rows == 3);
      CPPUNIT_ASSERT(life.cols == 3);
    }

    // --------------------
    // test_Life2
    // --------------------

    void test_Life2() {
      Life<ConwayCell> life(3, 3, ConwayCell(false));

      CPPUNIT_ASSERT(life.num_alive == 0);
    }

    // --------------------
    // test_Life3
    // --------------------

    void test_Life3() {
      Life<ConwayCell> life(3, 3, ConwayCell(false));
      
      CPPUNIT_ASSERT((int)life.board.size() == 5);
      CPPUNIT_ASSERT((int)life.board[0].size() == 5);
    }

    // --------------------
    // test_LifePlaceCell
    // --------------------

    void test_LifePlaceCell() {
      Life<ConwayCell> life(3, 3, ConwayCell(false));
        
      life.place_cell(0, 1, ConwayCell(true));
      life.place_cell(1, 0, ConwayCell(true));
      life.place_cell(1, 1, ConwayCell(true));

      CPPUNIT_ASSERT(life.num_alive == 3);
    }

    // --------------------
    // test_LifePlaceCell2
    // --------------------

    void test_LifePlaceCell2() {
      Life<ConwayCell> life(3, 3, ConwayCell(false));
        
      life.place_cell(0, 1, ConwayCell(true));
      life.place_cell(1, 0, ConwayCell(true));
      life.place_cell(1, 1, ConwayCell(true));

      CPPUNIT_ASSERT(life.board[1][2] == ConwayCell(true));
    }

    // --------------------
    // test_LifePlaceCell3
    // --------------------

    void test_LifePlaceCell3() {
      Life<ConwayCell> life(3, 3, ConwayCell(false));
        
      life.place_cell(0, 1, ConwayCell(true));
      life.place_cell(1, 0, ConwayCell(true));
      life.place_cell(1, 1, ConwayCell(true));

      CPPUNIT_ASSERT(life.board[1][3] == ConwayCell(false));
    }

    // --------------------
    // test_LifeStep
    // --------------------

    void test_LifeStep() {
      Life<ConwayCell> life(3, 3, ConwayCell(false));
        
      life.place_cell(0, 1, ConwayCell(true));
      life.place_cell(1, 0, ConwayCell(true));
      life.place_cell(1, 1, ConwayCell(true));
      life.place_cell(1, 2, ConwayCell(true));
      life.place_cell(2, 1, ConwayCell(true));

      life.step();

      CPPUNIT_ASSERT(life.board[1][2] == ConwayCell(true));
    }

    // --------------------
    // test_LifeStep2
    // --------------------

    void test_LifeStep2() {
      Life<ConwayCell> life(3, 3, ConwayCell(false));
        
      life.place_cell(0, 1, ConwayCell(true));
      life.place_cell(1, 0, ConwayCell(true));
      life.place_cell(1, 1, ConwayCell(true));
      life.place_cell(1, 2, ConwayCell(true));
      life.place_cell(2, 1, ConwayCell(true));

      CPPUNIT_ASSERT(life.num_alive == 5);

      life.step();

      CPPUNIT_ASSERT(life.board[2][2] != ConwayCell(true));
      CPPUNIT_ASSERT(life.num_alive == 8);
    }

    // --------------------
    // test_LifeStep3
    // --------------------

    void test_LifeStep3() {
      Life<ConwayCell> life(3, 3, ConwayCell(false));
        
      life.place_cell(0, 1, ConwayCell(true));
      life.place_cell(1, 0, ConwayCell(true));
      life.place_cell(1, 1, ConwayCell(true));
      life.place_cell(1, 2, ConwayCell(true));
      life.place_cell(2, 1, ConwayCell(true));

      CPPUNIT_ASSERT(life.num_alive == 5);

      life.step();
      life.step();

      CPPUNIT_ASSERT(life.board[1][2] != ConwayCell(true));
      CPPUNIT_ASSERT(life.num_alive == 4);
    }

    // --------------------
    // test_LifeCountNeighbors
    // --------------------

    void test_LifeCountNeighbors() {
      Life<ConwayCell> life(3, 3, ConwayCell(false));
        
      life.place_cell(0, 1, ConwayCell(true));
      life.place_cell(1, 0, ConwayCell(true));
      life.place_cell(1, 1, ConwayCell(true));
      life.place_cell(1, 2, ConwayCell(true));
      life.place_cell(2, 1, ConwayCell(true));

      CPPUNIT_ASSERT(life.count_neighbors(1, 2) == 3);
    }

    // --------------------
    // test_LifeCountNeighbors2
    // --------------------

    void test_LifeCountNeighbors2() {
      Life<ConwayCell> life(3, 3, ConwayCell(false));
        
      life.place_cell(0, 1, ConwayCell(true));
      life.place_cell(1, 0, ConwayCell(true));
      life.place_cell(1, 1, ConwayCell(true));
      life.place_cell(1, 2, ConwayCell(true));
      life.place_cell(2, 1, ConwayCell(true));

      life.step();

      CPPUNIT_ASSERT(life.count_neighbors(1, 2) == 4);
    }

    // --------------------
    // test_LifeCountNeighbors3
    // --------------------

    void test_LifeCountNeighbors3() {
      Life<ConwayCell> life(3, 3, ConwayCell(false));
        
      life.place_cell(0, 1, ConwayCell(true));
      life.place_cell(1, 0, ConwayCell(true));
      life.place_cell(1, 1, ConwayCell(true));
      life.place_cell(1, 2, ConwayCell(true));
      life.place_cell(2, 1, ConwayCell(true));

      life.step();
      life.step();

      CPPUNIT_ASSERT(life.count_neighbors(1, 2) == 2);
    }

    // --------------------
    // test_LifeCountAlive
    // --------------------

    void test_LifeCountAlive() {
      Life<ConwayCell> life(3, 3, ConwayCell(false));
        
      life.place_cell(0, 1, ConwayCell(true));
      life.place_cell(1, 0, ConwayCell(true));
      life.place_cell(1, 1, ConwayCell(true));
      life.place_cell(1, 2, ConwayCell(true));
      life.place_cell(2, 1, ConwayCell(true));

      CPPUNIT_ASSERT(life.count_alive() == 5);
    }

    // --------------------
    // test_LifeCountAlive2
    // --------------------

    void test_LifeCountAlive2() {
      Life<ConwayCell> life(3, 3, ConwayCell(false));
        
      life.place_cell(0, 1, ConwayCell(true));
      life.place_cell(1, 0, ConwayCell(true));
      life.place_cell(1, 1, ConwayCell(true));
      life.place_cell(1, 2, ConwayCell(true));
      life.place_cell(2, 1, ConwayCell(true));

      life.step();

      CPPUNIT_ASSERT(life.count_alive() == 8);
    }

    // --------------------
    // test_LifeCountAlive3
    // --------------------

    void test_LifeCountAlive3() {
      Life<ConwayCell> life(3, 3, ConwayCell(false));
        
      life.place_cell(0, 1, ConwayCell(true));
      life.place_cell(1, 0, ConwayCell(true));
      life.place_cell(1, 1, ConwayCell(true));
      life.place_cell(1, 2, ConwayCell(true));
      life.place_cell(2, 1, ConwayCell(true));

      life.step();
      life.step();

      CPPUNIT_ASSERT(life.count_alive() == 4);
    }



    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);

    // CONWAY CELL TESTS

    CPPUNIT_TEST(test_ConwayCell);
    CPPUNIT_TEST(test_ConwayCell2);
    CPPUNIT_TEST(test_ConwayCell3); 

    CPPUNIT_TEST(test_ConwayEquals);
    CPPUNIT_TEST(test_ConwayEquals2);
    CPPUNIT_TEST(test_ConwayEquals3);

    CPPUNIT_TEST(test_ConwayAssignment);
    CPPUNIT_TEST(test_ConwayAssignment2);
    CPPUNIT_TEST(test_ConwayAssignment3);

    CPPUNIT_TEST(test_ConwayOlder);
    CPPUNIT_TEST(test_ConwayOlder2);
    CPPUNIT_TEST(test_ConwayOlder3);

    CPPUNIT_TEST(test_ConwayStep);
    CPPUNIT_TEST(test_ConwayStep2);
    CPPUNIT_TEST(test_ConwayStep3);

    CPPUNIT_TEST(test_ConwayMutate);
    CPPUNIT_TEST(test_ConwayMutate2);
    CPPUNIT_TEST(test_ConwayMutate3);

    CPPUNIT_TEST(test_ConwayClone);
    CPPUNIT_TEST(test_ConwayClone2);
    CPPUNIT_TEST(test_ConwayClone3);

    CPPUNIT_TEST(test_ConwayNeighbors);
    CPPUNIT_TEST(test_ConwayNeighbors2);
    CPPUNIT_TEST(test_ConwayNeighbors3);

    CPPUNIT_TEST(test_ConwayDecide);
    CPPUNIT_TEST(test_ConwayDecide2);
    CPPUNIT_TEST(test_ConwayDecide3);

    CPPUNIT_TEST(test_ConwayDie);
    CPPUNIT_TEST(test_ConwayDie2);
    CPPUNIT_TEST(test_ConwayDie3);

    CPPUNIT_TEST(test_ConwayLive);
    CPPUNIT_TEST(test_ConwayLive2);
    CPPUNIT_TEST(test_ConwayLive3);

    CPPUNIT_TEST(test_ConwayIsAlive);
    CPPUNIT_TEST(test_ConwayIsAlive2);
    CPPUNIT_TEST(test_ConwayIsAlive3);

    CPPUNIT_TEST(test_ConwaySetNextChar);
    CPPUNIT_TEST(test_ConwaySetNextChar2);
    CPPUNIT_TEST(test_ConwaySetNextChar3);

    CPPUNIT_TEST(test_ConwayWillBeAlive);
    CPPUNIT_TEST(test_ConwayWillBeAlive2);
    CPPUNIT_TEST(test_ConwayWillBeAlive3);

    CPPUNIT_TEST(test_ConwayGetCharacter);
    CPPUNIT_TEST(test_ConwayGetCharacter2);
    CPPUNIT_TEST(test_ConwayGetCharacter3);

    // FREDKIN CELL TESTS

    CPPUNIT_TEST(test_FredkinCell);
    CPPUNIT_TEST(test_FredkinCell2);
    CPPUNIT_TEST(test_FredkinCell3); 

    CPPUNIT_TEST(test_FredkinEquals);
    CPPUNIT_TEST(test_FredkinEquals2);
    CPPUNIT_TEST(test_FredkinEquals3);

    CPPUNIT_TEST(test_FredkinAssignment);
    CPPUNIT_TEST(test_FredkinAssignment2);
    CPPUNIT_TEST(test_FredkinAssignment3);

    CPPUNIT_TEST(test_FredkinOlder);
    CPPUNIT_TEST(test_FredkinOlder2);
    CPPUNIT_TEST(test_FredkinOlder3);

    CPPUNIT_TEST(test_FredkinStep);
    CPPUNIT_TEST(test_FredkinStep2);
    CPPUNIT_TEST(test_FredkinStep3);

    CPPUNIT_TEST(test_FredkinMutate);
    CPPUNIT_TEST(test_FredkinMutate2);
    CPPUNIT_TEST(test_FredkinMutate3);

    CPPUNIT_TEST(test_FredkinClone);
    CPPUNIT_TEST(test_FredkinClone2);
    CPPUNIT_TEST(test_FredkinClone3);

    CPPUNIT_TEST(test_FredkinNeighbors);
    CPPUNIT_TEST(test_FredkinNeighbors2);
    CPPUNIT_TEST(test_FredkinNeighbors3);

    CPPUNIT_TEST(test_FredkinDecide);
    CPPUNIT_TEST(test_FredkinDecide2);
    CPPUNIT_TEST(test_FredkinDecide3);

    CPPUNIT_TEST(test_FredkinDie);
    CPPUNIT_TEST(test_FredkinDie2);
    CPPUNIT_TEST(test_FredkinDie3);

    CPPUNIT_TEST(test_FredkinLive);
    CPPUNIT_TEST(test_FredkinLive2);
    CPPUNIT_TEST(test_FredkinLive3);

    CPPUNIT_TEST(test_FredkinIsAlive);
    CPPUNIT_TEST(test_FredkinIsAlive2);
    CPPUNIT_TEST(test_FredkinIsAlive3);

    CPPUNIT_TEST(test_FredkinSetNextChar);
    CPPUNIT_TEST(test_FredkinSetNextChar2);
    CPPUNIT_TEST(test_FredkinSetNextChar3);

    CPPUNIT_TEST(test_FredkinWillBeAlive);
    CPPUNIT_TEST(test_FredkinWillBeAlive2);
    CPPUNIT_TEST(test_FredkinWillBeAlive3);

    CPPUNIT_TEST(test_FredkinGetCharacter);
    CPPUNIT_TEST(test_FredkinGetCharacter2);
    CPPUNIT_TEST(test_FredkinGetCharacter3);

    // CELL TESTS

    CPPUNIT_TEST(test_Cell);
    CPPUNIT_TEST(test_Cell2);
    CPPUNIT_TEST(test_Cell3); 

    CPPUNIT_TEST(test_CellOlder);
    CPPUNIT_TEST(test_CellOlder2);
    CPPUNIT_TEST(test_CellOlder3);

    CPPUNIT_TEST(test_CellStep);
    CPPUNIT_TEST(test_CellStep2);
    CPPUNIT_TEST(test_CellStep3);

    CPPUNIT_TEST(test_CellMutate);
    CPPUNIT_TEST(test_CellMutate2);
    CPPUNIT_TEST(test_CellMutate3);

    CPPUNIT_TEST(test_CellClone);
    CPPUNIT_TEST(test_CellClone2);
    CPPUNIT_TEST(test_CellClone3);

    CPPUNIT_TEST(test_CellNeighbors);
    CPPUNIT_TEST(test_CellNeighbors2);
    CPPUNIT_TEST(test_CellNeighbors3);

    CPPUNIT_TEST(test_CellDecide);
    CPPUNIT_TEST(test_CellDecide2);
    CPPUNIT_TEST(test_CellDecide3);

    CPPUNIT_TEST(test_CellIsAlive);
    CPPUNIT_TEST(test_CellIsAlive2);
    CPPUNIT_TEST(test_CellIsAlive3);

    // LIFE TESTS

    CPPUNIT_TEST(test_Life);
    CPPUNIT_TEST(test_Life2);
    CPPUNIT_TEST(test_Life3);

    CPPUNIT_TEST(test_LifePlaceCell);
    CPPUNIT_TEST(test_LifePlaceCell2);
    CPPUNIT_TEST(test_LifePlaceCell3);

    CPPUNIT_TEST(test_LifeStep);
    CPPUNIT_TEST(test_LifeStep2);
    CPPUNIT_TEST(test_LifeStep3);

    CPPUNIT_TEST(test_LifeCountNeighbors);
    CPPUNIT_TEST(test_LifeCountNeighbors2);
    CPPUNIT_TEST(test_LifeCountNeighbors3);

    CPPUNIT_TEST(test_LifeCountAlive);
    CPPUNIT_TEST(test_LifeCountAlive2);
    CPPUNIT_TEST(test_LifeCountAlive3);

    CPPUNIT_TEST_SUITE_END();
};

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
    return 0;
}