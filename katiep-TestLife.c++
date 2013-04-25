// ------------------------------------
// projects/life/TestLife.c++
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
    % g++ -pedantic -std=c++0x -Wall AbstractCell.c++ ConwayCell.c++ FredkinCell.c++ TestLife.c++ -o TestLife -lcppunit -ldl
    % valgrind TestDarwin >& TestDarwin.out
*/

// --------
// includes
// --------

#include <algorithm> // count
#include <iostream>  // ios_base
#include <sstream>   // istringtstream, ostringstream
#include <string>    // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define private public
#define protected public

#include "Handle.h"
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Life.h"

using namespace std;

// ----------
// TestDarwin
// ----------

struct TestLife : CppUnit::TestFixture {
	
	// ----------
	// ConwayCell
	// ----------
	
	void test_conwaycell () {
		ConwayCell cell;
		
		// is_alive
		CPPUNIT_ASSERT(!cell.is_alive());
		
		// num_neighbors
		CPPUNIT_ASSERT(cell.num_neighbors() == conway_neighbors);
		
		// write: dead
		std::ostringstream out;
		cell.write(out);
		CPPUNIT_ASSERT(out.str() == ".");
		
		// toggle_state
		cell.toggle_state();
		CPPUNIT_ASSERT(cell.is_alive());
		
		// write: alive
		cell.write(out);
		CPPUNIT_ASSERT(out.str() == ".*");
		
		// lives: alive
		cell.lives();
		CPPUNIT_ASSERT(cell.is_alive());
		
		// dies: alive
		cell.dies();
		CPPUNIT_ASSERT(!cell.is_alive());
		
		// dies: dead
		cell.dies();
		CPPUNIT_ASSERT(!cell.is_alive());
		
		// lives: dead
		cell.lives();
		CPPUNIT_ASSERT(cell.is_alive());
		
		// clone
		ConwayCell clone = cell.clone();
		CPPUNIT_ASSERT(clone.is_alive());
	}
	
	// -----------
	// FredkinCell
	// -----------
	
	void test_fredkincell () {
		FredkinCell cell;
		
		// is_alive
		CPPUNIT_ASSERT(!cell.is_alive());
		
		// get_age
		CPPUNIT_ASSERT(cell.get_age() == 0);
		
		// num_neighbors
		CPPUNIT_ASSERT(cell.num_neighbors() == fredkin_neighbors);
		
		// write: dead
		std::ostringstream out;
		string comp = "-";
		cell.write(out);
		CPPUNIT_ASSERT(out.str() == comp);
		
		// toggle_state
		cell.toggle_state();
		CPPUNIT_ASSERT(cell.is_alive());
		
		// write: alive
		for (int i = 0; i < 10; i++) {
			cell.write(out);
			string i_str = static_cast<ostringstream*>(&(ostringstream() << i))->str();
			comp = comp + i_str;
			CPPUNIT_ASSERT(out.str() == comp);
			CPPUNIT_ASSERT(cell.get_age() == i);
			cell.incr_age();
		}
		cell.write(out);
		comp = comp + "+";
		CPPUNIT_ASSERT(out.str() == comp);
		CPPUNIT_ASSERT(cell.get_age() == 10);
		
		// age between deaths
		cell.toggle_state();
		cell.toggle_state();
		CPPUNIT_ASSERT(cell.get_age() == 10);
		
		// lives: alive
		cell.lives();
		CPPUNIT_ASSERT(cell.is_alive());
		CPPUNIT_ASSERT(cell.get_age() == 11);
		
		// dies: alive
		cell.dies();
		CPPUNIT_ASSERT(!cell.is_alive());
		CPPUNIT_ASSERT(cell.get_age() == 11);
		
		// dies: dead
		cell.dies();
		CPPUNIT_ASSERT(!cell.is_alive());
		CPPUNIT_ASSERT(cell.get_age() == 11);
		
		// lives: dead
		cell.lives();
		CPPUNIT_ASSERT(cell.is_alive());
		CPPUNIT_ASSERT(cell.get_age() == 11);
		
		// clone
		FredkinCell clone = cell.clone();
		CPPUNIT_ASSERT(clone.is_alive());
	}
	
	// ----
	// Cell
	// ----
	
	void test_cell () {
		Cell con_cell = new ConwayCell();
		Cell fred_cell = new FredkinCell();
		
		// is_alive
		CPPUNIT_ASSERT(!con_cell.is_alive());
		CPPUNIT_ASSERT(!fred_cell.is_alive());
		
		// num_neighbors
		CPPUNIT_ASSERT(con_cell.num_neighbors() == conway_neighbors);
		CPPUNIT_ASSERT(fred_cell.num_neighbors() == fredkin_neighbors);
		
		// write: dead
		std::ostringstream con_out;
		con_cell.write(con_out);
		CPPUNIT_ASSERT(con_out.str() == ".");
		std::ostringstream fred_out;
		fred_cell.write(fred_out);
		CPPUNIT_ASSERT(fred_out.str() == "-");
		
		// toggle_state
		con_cell.toggle_state();
		CPPUNIT_ASSERT(con_cell.is_alive());
		fred_cell.toggle_state();
		CPPUNIT_ASSERT(fred_cell.is_alive());
		
		// write: alive
		con_cell.write(con_out);
		CPPUNIT_ASSERT(con_out.str() == ".*");
		fred_cell.write(fred_out);
		CPPUNIT_ASSERT(fred_out.str() == "-0");
		
		// lives: alive
		con_cell.lives();
		CPPUNIT_ASSERT(con_cell.is_alive());
		fred_cell.lives();
		CPPUNIT_ASSERT(fred_cell.is_alive());
		
		// dies: alive
		con_cell.lives();
		CPPUNIT_ASSERT(con_cell.is_alive());
		fred_cell.lives();
		CPPUNIT_ASSERT(fred_cell.is_alive());
		
		// dies: dead
		con_cell.lives();
		CPPUNIT_ASSERT(con_cell.is_alive());
		fred_cell.lives();
		CPPUNIT_ASSERT(fred_cell.is_alive());
		
		// lives: dead
		con_cell.lives();
		CPPUNIT_ASSERT(con_cell.is_alive());
		fred_cell.lives();
		CPPUNIT_ASSERT(fred_cell.is_alive());
		
		// clone
		Cell con_clone = con_cell.clone();
		CPPUNIT_ASSERT(con_clone.is_alive());
		Cell fred_clone = fred_cell.clone();
		CPPUNIT_ASSERT(fred_clone.is_alive());
	}
	
	// ----
	// Life
	// ----
	
	void test_life_1 () {
		int height = 1;
		int width = 1;
		
		Life<ConwayCell> life(height, width);
	
		CPPUNIT_ASSERT(life._width == height + 2);
		CPPUNIT_ASSERT(life._height == width + 2);
		
		CPPUNIT_ASSERT(!life._board[0].is_alive());
		CPPUNIT_ASSERT(!life._board[1].is_alive());
		CPPUNIT_ASSERT(!life._board[2].is_alive());
		
		CPPUNIT_ASSERT(!life._board[3].is_alive());
		CPPUNIT_ASSERT(!life._board[4].is_alive());
		CPPUNIT_ASSERT(!life._board[5].is_alive());
		
		CPPUNIT_ASSERT(!life._board[6].is_alive());
		CPPUNIT_ASSERT(!life._board[7].is_alive());
		CPPUNIT_ASSERT(!life._board[8].is_alive());
		
		CPPUNIT_ASSERT(life._generation == 0);
		CPPUNIT_ASSERT(life._population == 0);
	}
	
	void test_life_2 () {
		int height = 1;
		int width = 1;
		
		Life<FredkinCell> life(height, width);
	
		CPPUNIT_ASSERT(life._width == height + 2);
		CPPUNIT_ASSERT(life._height == width + 2);
		
		CPPUNIT_ASSERT(!life._board[0].is_alive());
		CPPUNIT_ASSERT(!life._board[1].is_alive());
		CPPUNIT_ASSERT(!life._board[2].is_alive());
		
		CPPUNIT_ASSERT(!life._board[3].is_alive());
		CPPUNIT_ASSERT(!life._board[4].is_alive());
		CPPUNIT_ASSERT(!life._board[5].is_alive());
		
		CPPUNIT_ASSERT(!life._board[6].is_alive());
		CPPUNIT_ASSERT(!life._board[7].is_alive());
		CPPUNIT_ASSERT(!life._board[8].is_alive());
		
		CPPUNIT_ASSERT(life._generation == 0);
		CPPUNIT_ASSERT(life._population == 0);
	}
	
	void test_life_3 () {
		int height = 1;
		int width = 1;
		
		Life<Cell> life(height, width);
	
		CPPUNIT_ASSERT(life._width == height + 2);
		CPPUNIT_ASSERT(life._height == width + 2);
		
		CPPUNIT_ASSERT(!life._board[0].is_alive());
		CPPUNIT_ASSERT(!life._board[1].is_alive());
		CPPUNIT_ASSERT(!life._board[2].is_alive());
		
		CPPUNIT_ASSERT(!life._board[3].is_alive());
		CPPUNIT_ASSERT(!life._board[4].is_alive());
		CPPUNIT_ASSERT(!life._board[5].is_alive());
		
		CPPUNIT_ASSERT(!life._board[6].is_alive());
		CPPUNIT_ASSERT(!life._board[7].is_alive());
		CPPUNIT_ASSERT(!life._board[8].is_alive());
		
		CPPUNIT_ASSERT(life._generation == 0);
		CPPUNIT_ASSERT(life._population == 0);
		
		int loc = 4;
		life._board[loc] = new ConwayCell();
		CPPUNIT_ASSERT(life._board[loc].num_neighbors() == conway_neighbors);
		life._board[loc] = new FredkinCell();
		CPPUNIT_ASSERT(life._board[loc].num_neighbors() == fredkin_neighbors);
	}
	
	// int live_hori_vert (int loc)
	
	void test_live_hor_vert_1 () {
		int height = 1;
		int width = 1;
		int loc = 4;
		
		Life<ConwayCell> life(height, width);
		CPPUNIT_ASSERT(life.live_hori_vert(loc) == 0);
		life._board[1].toggle_state();
		CPPUNIT_ASSERT(life.live_hori_vert(loc) == 1);
		life._board[0].toggle_state();
		CPPUNIT_ASSERT(life.live_hori_vert(loc) == 1);
	}
	
	void test_live_hor_vert_2 () {
		int height = 1;
		int width = 1;
		int loc = 4;
		
		Life<FredkinCell> life(height, width);
		CPPUNIT_ASSERT(life.live_hori_vert(loc) == 0);
		life._board[1].toggle_state();
		CPPUNIT_ASSERT(life.live_hori_vert(loc) == 1);
		life._board[0].toggle_state();
		CPPUNIT_ASSERT(life.live_hori_vert(loc) == 1);
	}
	
	void test_live_hor_vert_3 () {
		int height = 1;
		int width = 1;
		int loc = 4;
		
		Life<Cell> life(height, width);
		CPPUNIT_ASSERT(life.live_hori_vert(loc) == 0);
		life._board[1].toggle_state();
		CPPUNIT_ASSERT(life.live_hori_vert(loc) == 1);
		life._board[0].toggle_state();
		CPPUNIT_ASSERT(life.live_hori_vert(loc) == 1);
	}
	
	// int live_diag (int loc)
	
	void test_live_diag_1 () {
		int height = 1;
		int width = 1;
		int loc = 4;
		
		Life<ConwayCell> life(height, width);
		CPPUNIT_ASSERT(life.live_diag(loc) == 0);
		life._board[1].toggle_state();
		CPPUNIT_ASSERT(life.live_diag(loc) == 0);
		life._board[0].toggle_state();
		CPPUNIT_ASSERT(life.live_diag(loc) == 1);
	}
	
	void test_live_diag_2 () {
		int height = 1;
		int width = 1;
		int loc = 4;
		
		Life<FredkinCell> life(height, width);
		CPPUNIT_ASSERT(life.live_diag(loc) == 0);
		life._board[1].toggle_state();
		CPPUNIT_ASSERT(life.live_diag(loc) == 0);
		life._board[0].toggle_state();
		CPPUNIT_ASSERT(life.live_diag(loc) == 1);
	}
	
	void test_live_diag_3 () {
		int height = 1;
		int width = 1;
		
		Life<Cell> life(height, width);
		int loc = 4;
		CPPUNIT_ASSERT(life.live_diag(loc) == 0);
		life._board[1].toggle_state();
		CPPUNIT_ASSERT(life.live_diag(loc) == 0);
		life._board[0].toggle_state();
		CPPUNIT_ASSERT(life.live_diag(loc) == 1);
	}
	
	// int live_neighbors (int loc)
	
	void test_live_neighbors_1 () {
		int height = 1;
		int width = 1;
		int loc = 4;
		
		Life<ConwayCell> life(height, width);
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 0);
		life._board[0].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 1);
		life._board[1].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 2);
		life._board[2].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 3);
		life._board[3].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 4);
		life._board[5].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 5);
		life._board[6].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 6);
		life._board[7].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 7);
		life._board[8].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 8);
	}
	
	void test_live_neighbors_2 () {
		int height = 1;
		int width = 1;
		int loc = 4;
		
		Life<FredkinCell> life(height, width);
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 0);
		life._board[0].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 0);
		life._board[1].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 1);
		life._board[2].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 1);
		life._board[3].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 2);
		life._board[5].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 3);
		life._board[6].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 3);
		life._board[7].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 4);
		life._board[8].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 4);
	}
	
	void test_live_neighbors_3 () {
		int height = 1;
		int width = 1;
		int loc = 4;
		
		Life<Cell> life(height, width);
		life._board[loc] = new ConwayCell();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 0);
		life._board[0].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 1);
		life._board[1].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 2);
		life._board[2].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 3);
		life._board[3].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 4);
		life._board[5].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 5);
		life._board[6].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 6);
		life._board[7].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 7);
		life._board[8].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 8);
		
		life._board[loc] = new FredkinCell();
		for (int i = 0; i < 9; i++) {
			life._board[i].toggle_state();
		}
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 0);
		life._board[0].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 0);
		life._board[1].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 1);
		life._board[2].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 1);
		life._board[3].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 2);
		life._board[5].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 3);
		life._board[6].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 3);
		life._board[7].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 4);
		life._board[8].toggle_state();
		CPPUNIT_ASSERT(life.live_neighbors(loc) == 4);
	}
	
	// void turn_live_cell ()
	
	void test_turn_live_cell_1 () {
		int height = 1;
		int width = 1;
		int loc = 4;
		
		Life<ConwayCell> life(height, width);
		life._board[loc].toggle_state();
		
		// alive, 2<=x<=3 --> alive
		life.turn_live_cell(loc, 2);
		CPPUNIT_ASSERT(life._board[loc].is_alive());
		
		// alive, 2<=x<=3 --> alive
		life.turn_live_cell(loc, 3);
		CPPUNIT_ASSERT(life._board[loc].is_alive());
		
		// alive, x<2 --> dead
		life.turn_live_cell(loc, 0);
		CPPUNIT_ASSERT(!life._board[loc].is_alive());
		
		// alive, x>3 --> dead
		life._board[loc].toggle_state();
		life.turn_live_cell(loc, 4);
		CPPUNIT_ASSERT(!life._board[loc].is_alive());
	}
	
	void test_turn_live_cell_2 () {
		int height = 1;
		int width = 1;
		int loc = 4;
		
		Life<FredkinCell> life(height, width);
		life._board[loc].toggle_state();
		
		// alive, x=1 --> alive
		life.turn_live_cell(loc, 1);
		CPPUNIT_ASSERT(life._board[loc].is_alive());
		
		// alive, x=3 --> alive
		life.turn_live_cell(loc, 3);
		CPPUNIT_ASSERT(life._board[loc].is_alive());
		
		// alive, x=0 --> dead
		life.turn_live_cell(loc, 0);
		CPPUNIT_ASSERT(!life._board[loc].is_alive());
		
		// alive, x=2 --> dead
		life._board[loc].toggle_state();
		life.turn_live_cell(loc, 2);
		CPPUNIT_ASSERT(!life._board[loc].is_alive());
		
		// alive, x=4 --> dead
		life._board[loc].toggle_state();
		life.turn_live_cell(loc, 4);
		CPPUNIT_ASSERT(!life._board[loc].is_alive());
	}
	
	void test_turn_live_cell_3 () {
		int height = 1;
		int width = 1;
		int loc = 4;
		
		Life<Cell> life(height, width);
		
	// CONWAY
		life._board[loc] = new ConwayCell(true);
		
		// alive, 2<=x<=3 --> alive
		life.turn_live_cell(loc, 2);
		CPPUNIT_ASSERT(life._board[loc].is_alive());
		
		// alive, 2<=x<=3 --> alive
		life.turn_live_cell(loc, 3);
		CPPUNIT_ASSERT(life._board[loc].is_alive());
		
		// alive, x<2 --> dead
		life.turn_live_cell(loc, 0);
		CPPUNIT_ASSERT(!life._board[loc].is_alive());
		
		// alive, x>3 --> dead
		life._board[loc].toggle_state();
		life.turn_live_cell(loc, 4);
		CPPUNIT_ASSERT(!life._board[loc].is_alive());
		
	// FREDKIN
		life._board[loc] = new FredkinCell(true);
		
		// alive, x=1 --> alive
		life.turn_live_cell(loc, 1);
		CPPUNIT_ASSERT(life._board[loc].is_alive());
		
		// alive, x=3 --> alive
		life.turn_live_cell(loc, 3);
		CPPUNIT_ASSERT(life._board[loc].is_alive());
		
		// alive, x=0 --> dead
		life.turn_live_cell(loc, 0);
		CPPUNIT_ASSERT(!life._board[loc].is_alive());
		
		// alive, x=2 --> dead --> live ConwayCell
		life._board[loc].toggle_state();
		life.turn_live_cell(loc, 2);
		CPPUNIT_ASSERT(life._board[loc].is_alive());
		
		// alive, x=4 --> dead
		life.turn_live_cell(loc, 4);
		CPPUNIT_ASSERT(!life._board[loc].is_alive());
	}
	
	// void turn_dead_cell ()
	
	void test_turn_dead_cell_1 () {
		int height = 1;
		int width = 1;
		int loc = 4;
		
		Life<ConwayCell> life(height, width);
		
		// dead, x<3 --> dead
		life.turn_dead_cell(loc, 2);
		CPPUNIT_ASSERT(!life._board[loc].is_alive());
		
		// dead, x>3 --> dead
		life.turn_dead_cell(loc, 4);
		CPPUNIT_ASSERT(!life._board[loc].is_alive());
		
		// dead, x=3 --> alive
		life.turn_dead_cell(loc, 3);
		CPPUNIT_ASSERT(life._board[loc].is_alive());
	}
	
	void test_turn_dead_cell_2 () {
		int height = 1;
		int width = 1;
		int loc = 4;
		
		Life<FredkinCell> life(height, width);
		
		// dead, x=0 --> dead
		life.turn_dead_cell(loc, 0);
		CPPUNIT_ASSERT(!life._board[loc].is_alive());
		
		// dead, x=2 --> dead
		life.turn_dead_cell(loc, 2);
		CPPUNIT_ASSERT(!life._board[loc].is_alive());
		
		// dead, x=4 --> dead
		life.turn_dead_cell(loc, 4);
		CPPUNIT_ASSERT(!life._board[loc].is_alive());
		
		// dead, x=1 --> alive
		life.turn_dead_cell(loc, 1);
		CPPUNIT_ASSERT(life._board[loc].is_alive());
		
		// dead, x=3 --> alive
		life._board[loc].toggle_state();
		life.turn_dead_cell(loc, 3);
		CPPUNIT_ASSERT(life._board[loc].is_alive());
	}
	
	void test_turn_dead_cell_3 () {
		int height = 1;
		int width = 1;
		int loc = 4;
		
		Life<Cell> life(height, width);
		
	// CONWAY
		life._board[loc] = new ConwayCell(false);
		
		// dead, x<3 --> dead
		life.turn_dead_cell(loc, 2);
		CPPUNIT_ASSERT(!life._board[loc].is_alive());
		
		// dead, x>3 --> dead
		life.turn_dead_cell(loc, 4);
		CPPUNIT_ASSERT(!life._board[loc].is_alive());
		
		// dead, x=3 --> alive
		life.turn_dead_cell(loc, 3);
		CPPUNIT_ASSERT(life._board[loc].is_alive());
		
	// FREDKIN
		life._board[loc] = new FredkinCell(false);
		
		// dead, x=0 --> dead
		life.turn_dead_cell(loc, 0);
		CPPUNIT_ASSERT(!life._board[loc].is_alive());
		
		// dead, x=2 --> dead
		life.turn_dead_cell(loc, 2);
		CPPUNIT_ASSERT(!life._board[loc].is_alive());
		
		// dead, x=4 --> dead
		life.turn_dead_cell(loc, 4);
		CPPUNIT_ASSERT(!life._board[loc].is_alive());
		
		// dead, x=1 --> alive
		life.turn_dead_cell(loc, 1);
		CPPUNIT_ASSERT(life._board[loc].is_alive());
		
		// dead, x=3 --> alive
		life._board[loc].toggle_state();
		life.turn_dead_cell(loc, 3);
		CPPUNIT_ASSERT(life._board[loc].is_alive());
	}
	
	// void add_cell (int r, int c, cell_type type, bool is_alive, int age = -1)
	
	void test_add_cell_1 () {
		int height = 1;
		int width = 1;
		
		Life<ConwayCell> life(height, width);
		
		life.add_cell(0, 0, CONWAY, true);
		CPPUNIT_ASSERT(life._board[4].is_alive());
	}
	
	void test_add_cell_2 () {
		int height = 1;
		int width = 1;
		
		Life<FredkinCell> life(height, width);
		
		life.add_cell(0, 0, FREDKIN, true, 4);
		CPPUNIT_ASSERT(life._board[4].is_alive());
		CPPUNIT_ASSERT(life._board[4].get_age() == 4);
	}
	
	void test_add_cell_3 () {
		int height = 1;
		int width = 1;
		
		Life<Cell> life(height, width);
		
		life.add_cell(0, 0, FREDKIN, true, 4);
		CPPUNIT_ASSERT(life._board[4].is_alive());
		CPPUNIT_ASSERT(life._board[4].get_age() == 4);
		CPPUNIT_ASSERT(life._board[4].num_neighbors() == 4);
	}
	
	// void print (std::ostream& out)
	
	void test_print_1 () {
		int height = 1;
		int width = 1;
		
		Life<ConwayCell> con_life(height, width);
		ostringstream con_out;
		con_life.print(con_out);
		CPPUNIT_ASSERT(con_out.str() == "Generation = 0, Population = 0.\n.\n\n");
		
		Life<FredkinCell> fred_life(height, width);
		ostringstream fred_out;
		fred_life.print(fred_out);
		CPPUNIT_ASSERT(fred_out.str() == "Generation = 0, Population = 0.\n-\n\n");
		
		Life<Cell> cell_life(height, width);
		ostringstream cell_out;
		cell_life.print(cell_out);
		CPPUNIT_ASSERT(cell_out.str() == "Generation = 0, Population = 0.\n.\n\n");
	}
	
	void test_print_2 () {
		int height = 3;
		int width = 3;
		
		Life<ConwayCell> con_life(height, width);
		ostringstream con_out;
		con_life.print(con_out);
		CPPUNIT_ASSERT(con_out.str() == "Generation = 0, Population = 0.\n...\n...\n...\n\n");
		
		Life<FredkinCell> fred_life(height, width);
		ostringstream fred_out;
		fred_life.print(fred_out);
		CPPUNIT_ASSERT(fred_out.str() == "Generation = 0, Population = 0.\n---\n---\n---\n\n");
		
		Life<Cell> cell_life(height, width);
		ostringstream cell_out;
		cell_life.print(cell_out);
		CPPUNIT_ASSERT(cell_out.str() == "Generation = 0, Population = 0.\n...\n...\n...\n\n");
	}
	
	void test_print_3 () {
		int height = 3;
		int width = 3;
		
		Life<ConwayCell> con_life(height, width);
		ostringstream con_out;
		con_life._board[12].toggle_state();
		con_life.print(con_out);
		CPPUNIT_ASSERT(con_out.str() == "Generation = 0, Population = 0.\n...\n.*.\n...\n\n");
		
		Life<FredkinCell> fred_life(height, width);
		ostringstream fred_out;
		fred_life._board[12].toggle_state();
		fred_life._board[13].toggle_state();
		fred_life._board[13]._age = 10;
		fred_life.print(fred_out);
		CPPUNIT_ASSERT(fred_out.str() == "Generation = 0, Population = 0.\n---\n-0+\n---\n\n");
		
		Life<Cell> cell_life(height, width);
		ostringstream cell_out;
		cell_life._board[12] = new FredkinCell();
		cell_life._board[12].toggle_state();
		cell_life._board[13] = new FredkinCell();
		cell_life._board[13].toggle_state();
		cell_life._board[13].lives();
		cell_life._board[13].lives();
		cell_life._board[13].lives();
		cell_life._board[13].lives();
		cell_life._board[13].lives();
		cell_life._board[13].lives();
		cell_life._board[13].lives();
		cell_life._board[13].lives();
		cell_life._board[13].lives();
		cell_life._board[13].lives();
		cell_life.print(cell_out);
		CPPUNIT_ASSERT(cell_out.str() == "Generation = 0, Population = 0.\n...\n.0+\n...\n\n");
	}
	
	void test_print_4 () {
		int height = 100;
		int width = 100;
		
		Life<ConwayCell> con_life(height, width);
		ostringstream con_out;
		con_life.print(con_out);
		CPPUNIT_ASSERT(con_out.str() == "Generation = 0, Population = 0.\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n....................................................................................................\n\n");
	}
	
	// void turn ()
	
	void test_turn_1 () {
		int height = 13;
		int width = 3;
		
		Life<ConwayCell> life(height, width);
		
		life.add_cell(1, 1, CONWAY, true);
		life.add_cell(2, 1, CONWAY, true);
		life.add_cell(3, 1, CONWAY, true);
		life.add_cell(4, 1, CONWAY, true);
		life.add_cell(5, 1, CONWAY, true);
		
		life.add_cell(7, 1, CONWAY, true);
		life.add_cell(8, 1, CONWAY, true);
		life.add_cell(9, 1, CONWAY, true);
		life.add_cell(10, 1, CONWAY, true);
		life.add_cell(11, 1, CONWAY, true);
		
		ostringstream out;
		life.print(out);
		CPPUNIT_ASSERT(out.str() == "Generation = 0, Population = 10.\n...\n.*.\n.*.\n.*.\n.*.\n.*.\n...\n.*.\n.*.\n.*.\n.*.\n.*.\n...\n\n");
		
		life.turn();
		life.print(out);
		CPPUNIT_ASSERT(out.str() == "Generation = 0, Population = 10.\n...\n.*.\n.*.\n.*.\n.*.\n.*.\n...\n.*.\n.*.\n.*.\n.*.\n.*.\n...\n\nGeneration = 1, Population = 18.\n...\n...\n***\n***\n***\n...\n...\n...\n***\n***\n***\n...\n...\n\n");
		
		life.turn();
		life.print(out);
		CPPUNIT_ASSERT(out.str() == "Generation = 0, Population = 10.\n...\n.*.\n.*.\n.*.\n.*.\n.*.\n...\n.*.\n.*.\n.*.\n.*.\n.*.\n...\n\nGeneration = 1, Population = 18.\n...\n...\n***\n***\n***\n...\n...\n...\n***\n***\n***\n...\n...\n\nGeneration = 2, Population = 12.\n...\n.*.\n*.*\n...\n*.*\n.*.\n...\n.*.\n*.*\n...\n*.*\n.*.\n...\n\n");
		
		life.turn();
		life.print(out);
		CPPUNIT_ASSERT(out.str() == "Generation = 0, Population = 10.\n...\n.*.\n.*.\n.*.\n.*.\n.*.\n...\n.*.\n.*.\n.*.\n.*.\n.*.\n...\n\nGeneration = 1, Population = 18.\n...\n...\n***\n***\n***\n...\n...\n...\n***\n***\n***\n...\n...\n\nGeneration = 2, Population = 12.\n...\n.*.\n*.*\n...\n*.*\n.*.\n...\n.*.\n*.*\n...\n*.*\n.*.\n...\n\nGeneration = 3, Population = 8.\n...\n.*.\n.*.\n...\n.*.\n.*.\n...\n.*.\n.*.\n...\n.*.\n.*.\n...\n\n");
	}
	
	void test_turn_2 () {
		int height = 4;
		int width = 4;
		
		Life<FredkinCell> life(height, width);
		
		life.add_cell(1, 1, FREDKIN, true);
		life.add_cell(2, 1, FREDKIN, true);
		life.add_cell(1, 2, FREDKIN, true);
		life.add_cell(2, 2, FREDKIN, true);
		
		ostringstream out;
		life.print(out);
		CPPUNIT_ASSERT(out.str() == "Generation = 0, Population = 4.\n----\n-00-\n-00-\n----\n\n");		
		
		life.turn();
		life.print(out);
		CPPUNIT_ASSERT(out.str() == "Generation = 0, Population = 4.\n----\n-00-\n-00-\n----\n\nGeneration = 1, Population = 8.\n-00-\n0--0\n0--0\n-00-\n\n");		
		
		life.turn();
		life.print(out);
		CPPUNIT_ASSERT(out.str() == "Generation = 0, Population = 4.\n----\n-00-\n-00-\n----\n\nGeneration = 1, Population = 8.\n-00-\n0--0\n0--0\n-00-\n\nGeneration = 2, Population = 8.\n-11-\n1--1\n1--1\n-11-\n\n");		
		
		life.turn();
		life.print(out);
		
		CPPUNIT_ASSERT(out.str() == "Generation = 0, Population = 4.\n----\n-00-\n-00-\n----\n\nGeneration = 1, Population = 8.\n-00-\n0--0\n0--0\n-00-\n\nGeneration = 2, Population = 8.\n-11-\n1--1\n1--1\n-11-\n\nGeneration = 3, Population = 8.\n-22-\n2--2\n2--2\n-22-\n\n");		
	}
	
	void test_turn_3 () {
		int height = 4;
		int width = 6;
		
		Life<Cell> life(height, width);
		
		for (int r = 0; r < height; r++) {
			for (int c = 0; c < width; c++) {
				life.add_cell(r, c, FREDKIN, false);
			}
		}
		
		life.add_cell(1, 2, FREDKIN, true);
		life.add_cell(1, 3, FREDKIN, true);
		life.add_cell(2, 1, FREDKIN, true);
		life.add_cell(2, 2, FREDKIN, true);
		life.add_cell(2, 3, FREDKIN, true);
		life.add_cell(2, 4, FREDKIN, true);
		
		ostringstream out;
		life.print(out);
		CPPUNIT_ASSERT(out.str() == "Generation = 0, Population = 6.\n------\n--00--\n-0000-\n------\n\n");
		
		life.turn();
		life.print(out);
		CPPUNIT_ASSERT(out.str() == "Generation = 0, Population = 6.\n------\n--00--\n-0000-\n------\n\nGeneration = 1, Population = 12.\n--00--\n------\n011110\n-0000-\n\n");
		
		life.turn();
		life.print(out);
		CPPUNIT_ASSERT(out.str() == "Generation = 0, Population = 6.\n------\n--00--\n-0000-\n------\n\nGeneration = 1, Population = 12.\n--00--\n------\n011110\n-0000-\n\nGeneration = 2, Population = 16.\n-0110-\n00--00\n1****1\n--11--\n\n");
		
		life.turn();
		life.print(out);
		CPPUNIT_ASSERT(out.str() == "Generation = 0, Population = 6.\n------\n--00--\n-0000-\n------\n\nGeneration = 1, Population = 12.\n--00--\n------\n011110\n-0000-\n\nGeneration = 2, Population = 16.\n-0110-\n00--00\n1****1\n--11--\n\nGeneration = 3, Population = 6.\n------\n-1001-\n-....-\n0----0\n\n");
		
		life.turn();
		life.print(out);
		CPPUNIT_ASSERT(out.str() == "Generation = 0, Population = 6.\n------\n--00--\n-0000-\n------\n\nGeneration = 1, Population = 12.\n--00--\n------\n011110\n-0000-\n\nGeneration = 2, Population = 16.\n-0110-\n00--00\n1****1\n--11--\n\nGeneration = 3, Population = 6.\n------\n-1001-\n-....-\n0----0\n\nGeneration = 4, Population = 16.\n-0110-\n0*--*0\n1****1\n-0--0-\n\n");
		
		life.turn();
		life.print(out);
		
		CPPUNIT_ASSERT(out.str() == "Generation = 0, Population = 6.\n------\n--00--\n-0000-\n------\n\nGeneration = 1, Population = 12.\n--00--\n------\n011110\n-0000-\n\nGeneration = 2, Population = 16.\n-0110-\n00--00\n1****1\n--11--\n\nGeneration = 3, Population = 6.\n------\n-1001-\n-....-\n0----0\n\nGeneration = 4, Population = 16.\n-0110-\n0*--*0\n1****1\n-0--0-\n\nGeneration = 5, Population = 4.\n------\n-.00.-\n-....-\n-1--1-\n\n");
	}
	
	// -----
	// suite
	// -----

	CPPUNIT_TEST_SUITE(TestLife);

	CPPUNIT_TEST(test_conwaycell);
	CPPUNIT_TEST(test_fredkincell);
	CPPUNIT_TEST(test_cell);
	
	CPPUNIT_TEST(test_life_1);
	CPPUNIT_TEST(test_life_2);
	CPPUNIT_TEST(test_life_3);
	
	CPPUNIT_TEST(test_live_hor_vert_1);
	CPPUNIT_TEST(test_live_hor_vert_2);
	CPPUNIT_TEST(test_live_hor_vert_3);
	
	CPPUNIT_TEST(test_live_diag_1);
	CPPUNIT_TEST(test_live_diag_2);
	CPPUNIT_TEST(test_live_diag_3);
	
	CPPUNIT_TEST(test_live_neighbors_1);
	CPPUNIT_TEST(test_live_neighbors_2);
	CPPUNIT_TEST(test_live_neighbors_3);
	
	CPPUNIT_TEST(test_turn_live_cell_1);
	CPPUNIT_TEST(test_turn_live_cell_2);
	CPPUNIT_TEST(test_turn_live_cell_3);
	
	CPPUNIT_TEST(test_turn_dead_cell_1);
	CPPUNIT_TEST(test_turn_dead_cell_2);
	CPPUNIT_TEST(test_turn_dead_cell_3);
	
	CPPUNIT_TEST(test_add_cell_1);
	CPPUNIT_TEST(test_add_cell_2);
	CPPUNIT_TEST(test_add_cell_3);
	
	CPPUNIT_TEST(test_print_1);
	CPPUNIT_TEST(test_print_2);
	CPPUNIT_TEST(test_print_3);
	CPPUNIT_TEST(test_print_4);
	
	CPPUNIT_TEST(test_turn_1);
	CPPUNIT_TEST(test_turn_2);
	CPPUNIT_TEST(test_turn_3);
	
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


