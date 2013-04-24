// ---------------
// TestLife.c++
// Matt A. Johnson
// ---------------

//Based on Glenn P. Downing's TestCollatz.c++ file


/*
To test the program:
% ls /usr/include/cppunit/
...
TestFixture.h
...
% locate libcppunit.a
/usr/lib/libcppunit.a
% g++ -pedantic -std=c++0x -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz -lcppunit -ldl
% valgrind TestCollatz >& TestCollatz.out
*/

// --------
// includes
// --------

#define private public
#define protected public
//#define class struct

#include <iostream> // cout, endl, ios_base
#include <sstream> // istringtstream, ostringstream
#include <string> // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TextTestRunner

#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Life.h"


// --------
// TestLife
// --------

struct TestLife : CppUnit::TestFixture {
  
	//NOTE: AbstractCell implicitly tested by testing children
		
	//AbstractCell
	//AbstractCell - ==
	void test_abstract_friend_equal_1 () {
        ConwayCell cc = ConwayCell();
        ConwayCell c2 = ConwayCell();
        CPPUNIT_ASSERT(cc == c2);
    }
    
    void test_abstract_friend_equal_2 () {
        FredkinCell fc = FredkinCell();
        FredkinCell f2 = FredkinCell();
        CPPUNIT_ASSERT(fc == f2);
    }
    
    void test_abstract_friend_equal_3 () {
        ConwayCell cc = ConwayCell();
        FredkinCell f2 = FredkinCell();
        CPPUNIT_ASSERT(!(cc == f2));
    }
    
    //AbstractCell - !=
    void test_abstract_friend_notequal_1 () {
        ConwayCell cc = ConwayCell();
        ConwayCell c2 = ConwayCell('*');
        CPPUNIT_ASSERT(cc != c2);
    }
    
    void test_abstract_friend_notequal_2 () {
        FredkinCell fc = FredkinCell();
        FredkinCell f2 = FredkinCell('0');
        CPPUNIT_ASSERT(fc != f2);
    }
    
    void test_abstract_friend_notequal_3 () {
        ConwayCell cc = ConwayCell();
        FredkinCell f2 = FredkinCell();
        CPPUNIT_ASSERT(cc != f2);
    }
    
    //AbstractCell - >>
    void test_abstract_friend_opin_1 () {
        std::istringstream in ("b");
        ConwayCell cc = ConwayCell('*');
        in >> cc;
        CPPUNIT_ASSERT(cc._visual == 'b');
    }
    
    void test_abstract_friend_opin_2 () {
        std::istringstream in ("j");
        ConwayCell cc = ConwayCell('*');
        in >> cc;
        CPPUNIT_ASSERT(cc._visual == 'j');
    }
    
    void test_abstract_friend_opin_3 () {
        std::istringstream in ("k");
        ConwayCell cc = ConwayCell('*');
        in >> cc;
        CPPUNIT_ASSERT(cc._visual == 'k');
    }
    
    //AbstractCell - <<
    void test_abstract_friend_opout_1 () {
        std::ostringstream wout;
        ConwayCell cc = ConwayCell('*');
        wout << cc;
        CPPUNIT_ASSERT(wout.str() == "*");
    }
    
    void test_abstract_friend_opout_2 () {
        std::ostringstream wout;
        ConwayCell cc = ConwayCell('.');
        wout << cc;
        CPPUNIT_ASSERT(wout.str() == ".");
    }
    
    void test_abstract_friend_opout_3 () {
        std::ostringstream wout;
        FredkinCell fc = FredkinCell('0');
        wout << fc;
        CPPUNIT_ASSERT(wout.str() == "0");
    }
    
    //AbstractCell - =
    void test_abstract_friend_assign_1 () {
        ConwayCell cc = ConwayCell('*');
        ConwayCell c2 = ConwayCell('.');
        c2 = cc;
        CPPUNIT_ASSERT(c2._state == ALIVE);
    }
    
    void test_abstract_friend_assign_2 () {
        ConwayCell cc = ConwayCell('.');
        ConwayCell c2 = ConwayCell('*');
        c2 = cc;
        CPPUNIT_ASSERT(c2._state == DEAD);
    }
    
    void test_abstract_friend_assign_3 () {
        FredkinCell fc = FredkinCell('0');
        FredkinCell f2 = FredkinCell('-');
        f2 = fc;
        CPPUNIT_ASSERT(f2._state == ALIVE);
    }
    
    //AbstractCell - isAlive
    void test_abstract_friend_isAlive_1 () {
        ConwayCell cc = ConwayCell('*');
        CPPUNIT_ASSERT(cc.isAlive());
    }
    
    void test_abstract_friend_isAlive_2 () {
        ConwayCell cc = ConwayCell('.');
        CPPUNIT_ASSERT(!cc.isAlive());
    }
    
    void test_abstract_friend_isAlive_3 () {
        FredkinCell fc = FredkinCell('0');
		CPPUNIT_ASSERT(fc.isAlive());
    }
	
	
	//ConwayCell
	//Conway Constructor - bool
	void test_conway_constructor_bool_1 () {
        ConwayCell cc = ConwayCell();
        CPPUNIT_ASSERT(cc._state == DEAD);
        CPPUNIT_ASSERT(cc._visual == '.');
    }
    
    void test_conway_constructor_bool_2 () {
        ConwayCell cc = ConwayCell(true);
        CPPUNIT_ASSERT(cc._state == ALIVE);
        CPPUNIT_ASSERT(cc._visual == '*');
    }
    
    void test_conway_constructor_bool_3 () {
        ConwayCell cc = ConwayCell(false);
        CPPUNIT_ASSERT(cc._state == DEAD);
        CPPUNIT_ASSERT(cc._visual == '.');
    }
    
    
    //Conway Constructor - char
	void test_conway_constructor_char_1 () {
        ConwayCell cc = ConwayCell('*');
        CPPUNIT_ASSERT(cc._state == ALIVE);
        CPPUNIT_ASSERT(cc._visual == '*');
    }
    
    void test_conway_constructor_char_2 () {
        ConwayCell cc = ConwayCell('.');
        CPPUNIT_ASSERT(cc._state == DEAD);
        CPPUNIT_ASSERT(cc._visual == '.');
    }
    
    void test_conway_constructor_char_3 () {
        ConwayCell cc = ConwayCell('Q');
        CPPUNIT_ASSERT(cc._state == DEAD);
        CPPUNIT_ASSERT(cc._visual == '.');
    }
    
    
    //Conway action
	void test_conway_action_1 () {
        ConwayCell cc = ConwayCell('*');
        cc.action(2);
        CPPUNIT_ASSERT(cc._state == ALIVE);
        CPPUNIT_ASSERT(cc._visual == '*');
    }
    
    void test_conway_action_2 () {
        ConwayCell cc = ConwayCell('.');
        cc.action(4);
        CPPUNIT_ASSERT(cc._state == DEAD);
        CPPUNIT_ASSERT(cc._visual == '.');
    }
    
    void test_conway_action_3 () {
        ConwayCell cc = ConwayCell('.');
        cc.action(3);
        CPPUNIT_ASSERT(cc._state == ALIVE);
        CPPUNIT_ASSERT(cc._visual == '*');
    }
    
    
    //Conway isNeighbor
	void test_conway_isNeighbor_1 () {
        ConwayCell cc = ConwayCell('*');
        CPPUNIT_ASSERT(cc.isNeighbor(NE));
        CPPUNIT_ASSERT(cc.isNeighbor(NW));
        CPPUNIT_ASSERT(cc.isNeighbor(SE));
        CPPUNIT_ASSERT(cc.isNeighbor(SW));
    }
    
    void test_conway_isNeighbor_2 () {
        ConwayCell cc = ConwayCell('.');
        CPPUNIT_ASSERT(cc.isNeighbor(N));
        CPPUNIT_ASSERT(cc.isNeighbor(W));
        CPPUNIT_ASSERT(cc.isNeighbor(S));
        CPPUNIT_ASSERT(cc.isNeighbor(E));
    }
    
    void test_conway_isNeighbor_3 () {
        ConwayCell cc = ConwayCell('.');
        CPPUNIT_ASSERT(!cc.isNeighbor(6980));
    }
    
    
    //Conway clone
	void test_conway_clone_1 () {
        ConwayCell cc = ConwayCell('*');
        ConwayCell *c2 = cc.clone();
        CPPUNIT_ASSERT(c2->_state == ALIVE);
        CPPUNIT_ASSERT(c2->_visual == '*');
        CPPUNIT_ASSERT(c2 != &cc);
        
        //NOTE: delete used outside of handle, but I believe its use is
        //appropriate as there would be leaks otherwise.
        delete c2;
        
    }
    
    void test_conway_clone_2 () {
        ConwayCell cc = ConwayCell('.');
        ConwayCell *c2 = cc.clone();
        CPPUNIT_ASSERT(c2->_state == DEAD);
        CPPUNIT_ASSERT(c2->_visual == '.');
        CPPUNIT_ASSERT(c2 != &cc);
        
        //NOTE: delete used outside of handle, but I believe its use is
        //appropriate as there would be leaks otherwise.
        delete c2;
    }
    
    void test_conway_clone_3 () {
        ConwayCell cc = ConwayCell();
        ConwayCell *c2 = cc.clone();
        CPPUNIT_ASSERT(c2->_state == DEAD);
        CPPUNIT_ASSERT(c2->_visual == '.');
        CPPUNIT_ASSERT(c2 != &cc);
        
        //NOTE: delete used outside of handle, but I believe its use is
        //appropriate as there would be leaks otherwise.
        delete c2;
    }
    
    
    //Conway equals
	void test_conway_equals_1 () {
        ConwayCell cc = ConwayCell('*');
        ConwayCell c2 = ConwayCell('*');
        CPPUNIT_ASSERT(cc.equals(c2));
        CPPUNIT_ASSERT(c2.equals(cc));
    }
    
    void test_conway_equals_2 () {
        ConwayCell cc = ConwayCell('.');
        ConwayCell c2 = ConwayCell('.');
        CPPUNIT_ASSERT(cc.equals(c2));
        CPPUNIT_ASSERT(c2.equals(cc));
    }
    
    void test_conway_equals_3 () {
        ConwayCell cc = ConwayCell('*');
        ConwayCell c2 = ConwayCell('.');
        CPPUNIT_ASSERT(!cc.equals(c2));
        CPPUNIT_ASSERT(!c2.equals(cc));
    }
    
    
    //Conway read
	void test_conway_read_1 () {
		std::istringstream in ("b");
        ConwayCell cc = ConwayCell('*');
        cc.read(in);
        CPPUNIT_ASSERT(cc._visual == 'b');
    }
    
    void test_conway_read_2 () {
        std::istringstream in (".");
        ConwayCell cc = ConwayCell('*');
        cc.read(in);
        CPPUNIT_ASSERT(cc._visual == '.');
    }
    
    void test_conway_read_3 () {
        std::istringstream in ("o");
        ConwayCell cc = ConwayCell('*');
        cc.read(in);
        CPPUNIT_ASSERT(cc._visual == 'o');
    }
    
    
    //Conway write
	void test_conway_write_1 () {
		std::ostringstream wout;
        ConwayCell cc = ConwayCell('*');
        cc.write(wout);
        CPPUNIT_ASSERT(wout.str() == "*");
    }
    
    void test_conway_write_2 () {
        std::ostringstream wout;
        ConwayCell cc = ConwayCell('.');
        cc.write(wout);
        CPPUNIT_ASSERT(wout.str() == ".");
    }
    
    void test_conway_write_3 () {
        std::ostringstream wout;
        ConwayCell cc = ConwayCell(true);
        cc.write(wout);
        CPPUNIT_ASSERT(wout.str() == "*");
    }
    
    
    
    //FredkinCell
	//Fredkin Constructor - bool
	void test_fredkin_constructor_bool_1 () {
        FredkinCell fc = FredkinCell();
        CPPUNIT_ASSERT(fc._state == DEAD);
        CPPUNIT_ASSERT(fc._visual == '-');
        CPPUNIT_ASSERT(fc._age == 0);
    }
    
    void test_fredkin_constructor_bool_2 () {
        FredkinCell fc = FredkinCell(true);
        CPPUNIT_ASSERT(fc._state == ALIVE);
        CPPUNIT_ASSERT(fc._visual == '0');
        CPPUNIT_ASSERT(fc._age == 0);
    }
    
    void test_fredkin_constructor_bool_3 () {
        FredkinCell fc = FredkinCell(false);
        CPPUNIT_ASSERT(fc._state == DEAD);
        CPPUNIT_ASSERT(fc._visual == '-');
        CPPUNIT_ASSERT(fc._age == 0);
    }
    
    
    //Fredkin Constructor - char
	void test_fredkin_constructor_char_1 () {
        FredkinCell fc = FredkinCell('0');
        CPPUNIT_ASSERT(fc._state == ALIVE);
        CPPUNIT_ASSERT(fc._visual == '0');
        CPPUNIT_ASSERT(fc._age == 0);
    }
    
    void test_fredkin_constructor_char_2 () {
        FredkinCell fc = FredkinCell('-');
        CPPUNIT_ASSERT(fc._state == DEAD);
        CPPUNIT_ASSERT(fc._visual == '-');
        CPPUNIT_ASSERT(fc._age == 0);
    }
    
    void test_fredkin_constructor_char_3 () {
        FredkinCell fc = FredkinCell('Q');
        CPPUNIT_ASSERT(fc._state == DEAD);
        CPPUNIT_ASSERT(fc._visual == '-');
        CPPUNIT_ASSERT(fc._age == 0);
    }
    
    
    //Fredkin action
	void test_fredkin_action_1 () {
        FredkinCell fc = FredkinCell('0');
        fc.action(3);
        CPPUNIT_ASSERT(fc._state == ALIVE);
        CPPUNIT_ASSERT(fc._visual == '1');
    }
    
    void test_fredkin_action_2 () {
        FredkinCell fc = FredkinCell('-');
        fc.action(4);
        CPPUNIT_ASSERT(fc._state == DEAD);
        CPPUNIT_ASSERT(fc._visual == '-');
    }
    
    void test_fredkin_action_3 () {
        FredkinCell fc = FredkinCell('-');
        fc.action(3);
        CPPUNIT_ASSERT(fc._state == ALIVE);
        CPPUNIT_ASSERT(fc._visual == '0');
    }
    
    
    //Fredkin isNeighbor
	void test_fredkin_isNeighbor_1 () {
        FredkinCell fc = FredkinCell('0');
        CPPUNIT_ASSERT(!fc.isNeighbor(NE));
        CPPUNIT_ASSERT(!fc.isNeighbor(NW));
        CPPUNIT_ASSERT(!fc.isNeighbor(SE));
        CPPUNIT_ASSERT(!fc.isNeighbor(SW));
    }
    
    void test_fredkin_isNeighbor_2 () {
        FredkinCell fc = FredkinCell('-');
        CPPUNIT_ASSERT(fc.isNeighbor(N));
        CPPUNIT_ASSERT(fc.isNeighbor(W));
        CPPUNIT_ASSERT(fc.isNeighbor(S));
        CPPUNIT_ASSERT(fc.isNeighbor(E));
    }
    
    void test_fredkin_isNeighbor_3 () {
        FredkinCell fc = FredkinCell('-');
        CPPUNIT_ASSERT(!fc.isNeighbor(6980));
    }
    
    
    //Fredkin clone
	void test_fredkin_clone_1 () {
        FredkinCell fc = FredkinCell('0');
        FredkinCell *f2 = fc.clone();
        CPPUNIT_ASSERT(f2->_state == ALIVE);
        CPPUNIT_ASSERT(f2->_visual == '0');
        CPPUNIT_ASSERT(f2 != &fc);
        
        //NOTE: delete used outside of handle, but I believe its use is
        //appropriate as there would be leaks otherwise.
        delete f2;
        
    }
    
    void test_fredkin_clone_2 () {
        FredkinCell fc = FredkinCell('-');
        FredkinCell *f2 = fc.clone();
        CPPUNIT_ASSERT(f2->_state == DEAD);
        CPPUNIT_ASSERT(f2->_visual == '-');
        CPPUNIT_ASSERT(f2 != &fc);
        
        //NOTE: delete used outside of handle, but I believe its use is
        //appropriate as there would be leaks otherwise.
        delete f2;
    }
    
    void test_fredkin_clone_3 () {
        FredkinCell fc = FredkinCell();
        FredkinCell *f2 = fc.clone();
        CPPUNIT_ASSERT(f2->_state == DEAD);
        CPPUNIT_ASSERT(f2->_visual == '-');
        CPPUNIT_ASSERT(f2 != &fc);
        
        //NOTE: delete used outside of handle, but I believe its use is
        //appropriate as there would be leaks otherwise.
        delete f2;
    }
    
    
    //Fredkin equals
	void test_fredkin_equals_1 () {
        FredkinCell fc = FredkinCell('0');
        FredkinCell f2 = FredkinCell('0');
        CPPUNIT_ASSERT(fc.equals(f2));
        CPPUNIT_ASSERT(f2.equals(fc));
    }
    
    void test_fredkin_equals_2 () {
        FredkinCell fc = FredkinCell('-');
        FredkinCell f2 = FredkinCell('-');
        CPPUNIT_ASSERT(fc.equals(f2));
        CPPUNIT_ASSERT(f2.equals(fc));
    }
    
    void test_fredkin_equals_3 () {
        FredkinCell fc = FredkinCell('0');
        FredkinCell f2 = FredkinCell('-');
        CPPUNIT_ASSERT(!fc.equals(f2));
        CPPUNIT_ASSERT(!f2.equals(fc));
    }
    
    
    //Fredkin read
	void test_fredkin_read_1 () {
		std::istringstream in ("b");
        FredkinCell fc = FredkinCell('0');
        fc.read(in);
        CPPUNIT_ASSERT(fc._visual == 'b');
    }
    
    void test_fredkin_read_2 () {
        std::istringstream in ("-");
        FredkinCell fc = FredkinCell('0');
        fc.read(in);
        CPPUNIT_ASSERT(fc._visual == '-');
    }
    
    void test_fredkin_read_3 () {
        std::istringstream in ("o");
        FredkinCell fc = FredkinCell('0');
        fc.read(in);
        CPPUNIT_ASSERT(fc._visual == 'o');
    }
    
    
    //Fredkin write
	void test_fredkin_write_1 () {
		std::ostringstream wout;
        FredkinCell fc = FredkinCell('0');
        fc.write(wout);
        CPPUNIT_ASSERT(wout.str() == "0");
    }
    
    void test_fredkin_write_2 () {
        std::ostringstream wout;
        FredkinCell fc = FredkinCell('-');
        fc.write(wout);
        CPPUNIT_ASSERT(wout.str() == "-");
    }
    
    void test_fredkin_write_3 () {
        std::ostringstream wout;
        FredkinCell fc = FredkinCell(true);
        fc.write(wout);
        CPPUNIT_ASSERT(wout.str() == "0");
    }
	
	
	
	//Cell
	//Cell Constructor - pointer
	void test_cell_constructor_pointer_1 () {
        Cell c = Cell();
        CPPUNIT_ASSERT(c._p == 0);
    }
    
    void test_cell_constructor_pointer_2 () {
        Cell c = Cell(new ConwayCell());
        CPPUNIT_ASSERT(c._p != 0);
        CPPUNIT_ASSERT(dynamic_cast<ConwayCell*>(c._p)->_state == DEAD);
        CPPUNIT_ASSERT(dynamic_cast<ConwayCell*>(c._p)->_visual == '.');
    }
    
    void test_cell_constructor_pointer_3 () {
        Cell c = Cell(new FredkinCell());
        CPPUNIT_ASSERT(c._p != 0);
        CPPUNIT_ASSERT(dynamic_cast<FredkinCell*>(c._p)->_state == DEAD);
        CPPUNIT_ASSERT(dynamic_cast<FredkinCell*>(c._p)->_visual == '-');
        CPPUNIT_ASSERT(dynamic_cast<FredkinCell*>(c._p)->_age == 0);
    }
    
    
    //Cell - action
    void test_cell_action_1 () {
    	Cell c = Cell(new ConwayCell('*'));
        c.action(2);
        CPPUNIT_ASSERT(dynamic_cast<ConwayCell*>(c._p)->_state == ALIVE);
        CPPUNIT_ASSERT(dynamic_cast<ConwayCell*>(c._p)->_visual == '*');
    }
    
    void test_cell_action_2 () {
    	Cell c = Cell(new ConwayCell('.'));
        c.action(3);
        CPPUNIT_ASSERT(dynamic_cast<ConwayCell*>(c._p)->_state == ALIVE);
        CPPUNIT_ASSERT(dynamic_cast<ConwayCell*>(c._p)->_visual == '*');
    }
    
    void test_cell_action_3 () {
    	Cell c = Cell(new FredkinCell('1'));
        c.action(1);
        CPPUNIT_ASSERT(dynamic_cast<ConwayCell*>(c._p)->_state == ALIVE);
        CPPUNIT_ASSERT(dynamic_cast<ConwayCell*>(c._p)->_visual == '*');
    }
    
    
    //Cell - isNeighbor
    void test_cell_isNeighbor_1 () {
    	Cell c = Cell(new ConwayCell('*'));
        CPPUNIT_ASSERT(c.isNeighbor(N));
        CPPUNIT_ASSERT(c.isNeighbor(S));
        CPPUNIT_ASSERT(c.isNeighbor(E));
        CPPUNIT_ASSERT(c.isNeighbor(W));
        CPPUNIT_ASSERT(c.isNeighbor(NE));
        CPPUNIT_ASSERT(c.isNeighbor(NW));
        CPPUNIT_ASSERT(c.isNeighbor(SE));
        CPPUNIT_ASSERT(c.isNeighbor(SW));
    }
    
    void test_cell_isNeighbor_2 () {
    	Cell c = Cell(new FredkinCell('0'));
        CPPUNIT_ASSERT(c.isNeighbor(N));
        CPPUNIT_ASSERT(c.isNeighbor(S));
        CPPUNIT_ASSERT(c.isNeighbor(E));
        CPPUNIT_ASSERT(c.isNeighbor(W));
        CPPUNIT_ASSERT(!c.isNeighbor(NE));
        CPPUNIT_ASSERT(!c.isNeighbor(NW));
        CPPUNIT_ASSERT(!c.isNeighbor(SE));
        CPPUNIT_ASSERT(!c.isNeighbor(SW));
    }
    
    void test_cell_isNeighbor_3 () {
    	Cell c = Cell(new FredkinCell('1'));
    	c.action(1);
        CPPUNIT_ASSERT(c.isNeighbor(N));
        CPPUNIT_ASSERT(c.isNeighbor(S));
        CPPUNIT_ASSERT(c.isNeighbor(E));
        CPPUNIT_ASSERT(c.isNeighbor(W));
        CPPUNIT_ASSERT(c.isNeighbor(NE));
        CPPUNIT_ASSERT(c.isNeighbor(NW));
        CPPUNIT_ASSERT(c.isNeighbor(SE));
        CPPUNIT_ASSERT(c.isNeighbor(SW));
    }
    
    
    //Cell - isAlive
    void test_cell_isAlive_1 () {
    	Cell c = Cell(new ConwayCell('*'));
        CPPUNIT_ASSERT(c.isAlive());
    }
    
    void test_cell_isAlive_2 () {
    	Cell c = Cell(new FredkinCell('0'));
        CPPUNIT_ASSERT(c.isAlive());
    }
    
    void test_cell_isAlive_3 () {
    	Cell c = Cell(new FredkinCell('-'));
        CPPUNIT_ASSERT(!c.isAlive());
    }
    
    
    //Cell - mutate
    void test_cell_mutate_1 () {
    	Cell c = Cell(new FredkinCell('3'));
    	c.mutate();
        CPPUNIT_ASSERT(dynamic_cast<ConwayCell*>(c._p));
    }
    
    void test_cell_mutate_2 () {
    	Cell c = Cell(new FredkinCell('0'));
    	c.mutate();
        CPPUNIT_ASSERT(dynamic_cast<ConwayCell*>(c._p));
    }
    
    void test_cell_mutate_3 () {
    	Cell c = Cell(new FredkinCell('-'));
    	c.mutate();
        CPPUNIT_ASSERT(dynamic_cast<ConwayCell*>(c._p));
    }
    
    
      
    //Life
	//Life - constructor
	void test_life_constructor_1 () {
        Life<ConwayCell> l = Life<ConwayCell>(10, 10);
        CPPUNIT_ASSERT(l._height == 10);
        CPPUNIT_ASSERT(l._width == 10);
        CPPUNIT_ASSERT(l._gen == 0);
        CPPUNIT_ASSERT(l._pop == 0);
    }
    
    void test_life_constructor_2 () {
        Life<ConwayCell> l = Life<ConwayCell>(11, 10);
        CPPUNIT_ASSERT(l._height == 11);
        CPPUNIT_ASSERT(l._width == 10);
        CPPUNIT_ASSERT(l._gen == 0);
        CPPUNIT_ASSERT(l._pop == 0);
    }
    
    void test_life_constructor_3 () {
        Life<ConwayCell> l = Life<ConwayCell>(10, 11);
        CPPUNIT_ASSERT(l._height == 10);
        CPPUNIT_ASSERT(l._width == 11);
        CPPUNIT_ASSERT(l._gen == 0);
        CPPUNIT_ASSERT(l._pop == 0);
    }
    
    
    //Life - place
	void test_life_place_1 () {
        Life<ConwayCell> l = Life<ConwayCell>(10, 10);
        ConwayCell cc = ConwayCell('*');
        l.place(3, 3, cc); 
        CPPUNIT_ASSERT(l._pop == 1);
        CPPUNIT_ASSERT(l._board[3][3] == cc);
    }
    
    void test_life_place_2 () {
        Life<FredkinCell> l = Life<FredkinCell>(10, 10);
        FredkinCell fc = FredkinCell('0');
        l.place(4, 4, fc); 
        CPPUNIT_ASSERT(l._pop == 1);
        CPPUNIT_ASSERT(l._board[4][4] == fc);
    }
    
    void test_life_place_3 () {
        Life<Cell> l = Life<Cell>(10, 10);
        Cell c = Cell(new ConwayCell('*'));
        l.place(5, 5, c); 
        CPPUNIT_ASSERT(l._pop == 1);
        CPPUNIT_ASSERT(l._board[5][5] == c);
    }
    
    
    //Life - print
	void test_life_print_1 () {
        std::string input = "2\n4\n";
	  		   input += "0--0\n";
	  		   input += "-00-\n";
	  		   std::istringstream in (input);
	  		   std::ostringstream wout;
		int height, width;
		in >> height;
		in >> width;
	
		Life<Cell> Board = Life<Cell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board.place(h, w, Cell(new FredkinCell(c)));
			}
		}
		
		input = "Generation = 0, Population = 4.\n0--0\n-00-\n\n";
		
		Board.print(wout);
		CPPUNIT_ASSERT(wout.str() == input);
    }
    
    void test_life_print_2 () {
        std::string input = "2\n4\n";
	  		   input += "0000\n";
	  		   input += "0000\n";
	  		   std::istringstream in (input);
	  		   std::ostringstream wout;
		int height, width;
		in >> height;
		in >> width;
	
		Life<Cell> Board = Life<Cell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board.place(h, w, Cell(new FredkinCell(c)));
			}
		}
		
		input = "Generation = 0, Population = 8.\n0000\n0000\n\n";
		
		Board.print(wout);
		CPPUNIT_ASSERT(wout.str() == input);
    }
    
    void test_life_print_3 () {
        std::string input = "2\n4\n";
	  		   input += "0---\n";
	  		   input += "----\n";
	  		   std::istringstream in (input);
	  		   std::ostringstream wout;
		int height, width;
		in >> height;
		in >> width;
	
		Life<Cell> Board = Life<Cell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board.place(h, w, Cell(new FredkinCell(c)));
			}
		}
		
		input = "Generation = 0, Population = 1.\n0---\n----\n\n";
		
		Board.print(wout);
		CPPUNIT_ASSERT(wout.str() == input);
    }
    
    
    //Life - evolve
    void test_life_evolve_1 () {
        std::string input = "2\n4\n";
	  		   input += "0---\n";
	  		   input += "----\n";
	  		   std::istringstream in (input);
	  		   std::ostringstream wout;
		int height, width;
		in >> height;
		in >> width;
	
		Life<Cell> Board = Life<Cell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board.place(h, w, Cell(new FredkinCell(c)));
			}
		}
		
		Board.evolve();
		Board.print(wout);
		input = "Generation = 1, Population = 2.\n-0--\n0---\n\n";
		
		CPPUNIT_ASSERT(wout.str() == input);
    }
    
    void test_life_evolve_2 () {
        std::string input = "2\n4\n";
	  		   input += "0---\n";
	  		   input += "0---\n";
	  		   std::istringstream in (input);
	  		   std::ostringstream wout;
		int height, width;
		in >> height;
		in >> width;
	
		Life<Cell> Board = Life<Cell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board.place(h, w, Cell(new FredkinCell(c)));
			}
		}
		
		Board.evolve();
		Board.print(wout);
		input = "Generation = 1, Population = 4.\n10--\n10--\n\n";
		
		CPPUNIT_ASSERT(wout.str() == input);
    }
    
    void test_life_evolve_3 () {
        std::string input = "2\n4\n";
	  		   input += "0---\n";
	  		   input += "---0\n";
	  		   std::istringstream in (input);
	  		   std::ostringstream wout;
		int height, width;
		in >> height;
		in >> width;
	
		Life<Cell> Board = Life<Cell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board.place(h, w, Cell(new FredkinCell(c)));
			}
		}
		
		Board.evolve();
		Board.print(wout);
		input = "Generation = 1, Population = 4.\n-0-0\n0-0-\n\n";
		
		CPPUNIT_ASSERT(wout.str() == input);
    }
    
    
    //Life - checkNeighbors
    void test_life_checkNeighbors_1 () {
        std::string input = "2\n4\n";
	  		   input += "0---\n";
	  		   input += "---0\n";
	  		   std::istringstream in (input);
		int height, width;
		in >> height;
		in >> width;
	
		Life<Cell> Board = Life<Cell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board.place(h, w, Cell(new FredkinCell(c)));
			}
		}
		
		CPPUNIT_ASSERT(Board.checkNeighbors(0,0) == 0);
    }
    
    void test_life_checkNeighbors_2 () {
        std::string input = "2\n4\n";
	  		   input += "0---\n";
	  		   input += "---0\n";
	  		   std::istringstream in (input);
		int height, width;
		in >> height;
		in >> width;
	
		Life<Cell> Board = Life<Cell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board.place(h, w, Cell(new FredkinCell(c)));
			}
		}
		
		CPPUNIT_ASSERT(Board.checkNeighbors(0,1) == 1);
    }
    
    void test_life_checkNeighbors_3 () {
        std::string input = "2\n4\n";
	  		   input += "0-0-\n";
	  		   input += "---0\n";
	  		   std::istringstream in (input);
		int height, width;
		in >> height;
		in >> width;
	
		Life<Cell> Board = Life<Cell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board.place(h, w, Cell(new FredkinCell(c)));
			}
		}
		
		CPPUNIT_ASSERT(Board.checkNeighbors(1,2) == 2);
    }
    
    
    
	// -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);
    
    CPPUNIT_TEST(test_abstract_friend_equal_1);
    CPPUNIT_TEST(test_abstract_friend_equal_2);
    CPPUNIT_TEST(test_abstract_friend_equal_3);
    
    CPPUNIT_TEST(test_abstract_friend_notequal_1);
    CPPUNIT_TEST(test_abstract_friend_notequal_2);
    CPPUNIT_TEST(test_abstract_friend_notequal_3);
    
    CPPUNIT_TEST(test_abstract_friend_opin_1);
    CPPUNIT_TEST(test_abstract_friend_opin_2);
    CPPUNIT_TEST(test_abstract_friend_opin_3);
    
    CPPUNIT_TEST(test_abstract_friend_opout_1);
    CPPUNIT_TEST(test_abstract_friend_opout_2);
    CPPUNIT_TEST(test_abstract_friend_opout_3);
    
    CPPUNIT_TEST(test_abstract_friend_assign_1);
    CPPUNIT_TEST(test_abstract_friend_assign_2);
    CPPUNIT_TEST(test_abstract_friend_assign_3);
    
    CPPUNIT_TEST(test_abstract_friend_isAlive_1);
    CPPUNIT_TEST(test_abstract_friend_isAlive_2);
    CPPUNIT_TEST(test_abstract_friend_isAlive_3);
    
    
    CPPUNIT_TEST(test_conway_constructor_bool_1);
    CPPUNIT_TEST(test_conway_constructor_bool_2);
    CPPUNIT_TEST(test_conway_constructor_bool_3);
    
    CPPUNIT_TEST(test_conway_constructor_char_1);
    CPPUNIT_TEST(test_conway_constructor_char_2);
    CPPUNIT_TEST(test_conway_constructor_char_3);
    
    CPPUNIT_TEST(test_conway_action_1);
    CPPUNIT_TEST(test_conway_action_2);
    CPPUNIT_TEST(test_conway_action_3);
    
    CPPUNIT_TEST(test_conway_isNeighbor_1);
    CPPUNIT_TEST(test_conway_isNeighbor_2);
    CPPUNIT_TEST(test_conway_isNeighbor_3);
    
    CPPUNIT_TEST(test_conway_clone_1);
    CPPUNIT_TEST(test_conway_clone_2);
    CPPUNIT_TEST(test_conway_clone_3);
    
    CPPUNIT_TEST(test_conway_equals_1);
    CPPUNIT_TEST(test_conway_equals_2);
    CPPUNIT_TEST(test_conway_equals_3);
    
    CPPUNIT_TEST(test_conway_read_1);
    CPPUNIT_TEST(test_conway_read_2);
    CPPUNIT_TEST(test_conway_read_3);
    
    CPPUNIT_TEST(test_conway_write_1);
    CPPUNIT_TEST(test_conway_write_2);
    CPPUNIT_TEST(test_conway_write_3);
    
    
    CPPUNIT_TEST(test_fredkin_constructor_bool_1);
    CPPUNIT_TEST(test_fredkin_constructor_bool_2);
    CPPUNIT_TEST(test_fredkin_constructor_bool_3);
    
    CPPUNIT_TEST(test_fredkin_constructor_char_1);
    CPPUNIT_TEST(test_fredkin_constructor_char_2);
    CPPUNIT_TEST(test_fredkin_constructor_char_3);
    
    CPPUNIT_TEST(test_fredkin_action_1);
    CPPUNIT_TEST(test_fredkin_action_2);
    CPPUNIT_TEST(test_fredkin_action_3);
    
    CPPUNIT_TEST(test_fredkin_isNeighbor_1);
    CPPUNIT_TEST(test_fredkin_isNeighbor_2);
    CPPUNIT_TEST(test_fredkin_isNeighbor_3);
    
    CPPUNIT_TEST(test_fredkin_clone_1);
    CPPUNIT_TEST(test_fredkin_clone_2);
    CPPUNIT_TEST(test_fredkin_clone_3);
    
    CPPUNIT_TEST(test_fredkin_equals_1);
    CPPUNIT_TEST(test_fredkin_equals_2);
    CPPUNIT_TEST(test_fredkin_equals_3);
    
    CPPUNIT_TEST(test_fredkin_read_1);
    CPPUNIT_TEST(test_fredkin_read_2);
    CPPUNIT_TEST(test_fredkin_read_3);
    
    CPPUNIT_TEST(test_fredkin_write_1);
    CPPUNIT_TEST(test_fredkin_write_2);
    CPPUNIT_TEST(test_fredkin_write_3);
    
    CPPUNIT_TEST(test_cell_constructor_pointer_1);
    CPPUNIT_TEST(test_cell_constructor_pointer_2);
    CPPUNIT_TEST(test_cell_constructor_pointer_3);
    
    CPPUNIT_TEST(test_cell_action_1);
    CPPUNIT_TEST(test_cell_action_2);
    CPPUNIT_TEST(test_cell_action_3);
    
    CPPUNIT_TEST(test_cell_isNeighbor_1);
    CPPUNIT_TEST(test_cell_isNeighbor_2);
    CPPUNIT_TEST(test_cell_isNeighbor_3);
    
    CPPUNIT_TEST(test_cell_isAlive_1);
    CPPUNIT_TEST(test_cell_isAlive_2);
    CPPUNIT_TEST(test_cell_isAlive_3);
    
    CPPUNIT_TEST(test_cell_mutate_1);
    CPPUNIT_TEST(test_cell_mutate_2);
    CPPUNIT_TEST(test_cell_mutate_3);
    
    CPPUNIT_TEST(test_life_constructor_1);
    CPPUNIT_TEST(test_life_constructor_2);
    CPPUNIT_TEST(test_life_constructor_3);
    
    CPPUNIT_TEST(test_life_place_1);
    CPPUNIT_TEST(test_life_place_2);
    CPPUNIT_TEST(test_life_place_3);
    
    CPPUNIT_TEST(test_life_print_1);
    CPPUNIT_TEST(test_life_print_2);
    CPPUNIT_TEST(test_life_print_3);
    
    CPPUNIT_TEST(test_life_evolve_1);
    CPPUNIT_TEST(test_life_evolve_2);
    CPPUNIT_TEST(test_life_evolve_3);
    
    CPPUNIT_TEST(test_life_checkNeighbors_1);
    CPPUNIT_TEST(test_life_checkNeighbors_2);
    CPPUNIT_TEST(test_life_checkNeighbors_3);
    
	CPPUNIT_TEST_SUITE_END();
};

// ----
// main
// ----

int main () {
    using namespace std;
    //ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestLife.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestLife::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;
}
