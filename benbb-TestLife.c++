// -----------------------------
// Ben Bowley-Bryant
// benbb
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
    % g++ -pedantic -std=c++0x -Wall Darwin.c++ TestDarwin.c++ -o TestAllocator -lcppunit -ldl
    % valgrind TestDarwin >& TestDarwin.out
*/

// --------
// includes
// --------

#include <algorithm> // count
#include <iostream>  // ios_base
#include <sstream>
#include <memory>    // allocator

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define private public
#define protected public 

#include "AbstractCell.h"
#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"


//For convienence
#define FOOD 0
#define HOPPER 1
#define ROVER 2
#define TRAP 3
#define BEST 4


// -------------
// TestLife
// -------------

using namespace std;

struct TestLife : CppUnit::TestFixture {
    // --------
    // typedefs
    // --------
    
    // --------
    // test_nothing
    // --------

	void test_nothing () {
        CPPUNIT_ASSERT(true);
    }
    
    // --------
	// ConwayCell Tests
	// --------
	
	void test_CC_output_DEAD () {
		ostringstream s;
		ConwayCell c(0);
		s << c;
        CPPUNIT_ASSERT(s.str() == ".");
    }
    
    void test_CC_output_ALIVE () {
		ostringstream s;
		ConwayCell c(1);
		s << c;
        CPPUNIT_ASSERT(s.str() == "*");
    }
    
    void test_CC_input_DEAD () {
		stringstream s;
		s << '.';
		ConwayCell c(1);
		s >> c;
        CPPUNIT_ASSERT(c._status == 0);
    }
    
    void test_CC_input_ALIVE () {
		stringstream s;
		s << '*';
		ConwayCell c(0);
		s >> c;
        CPPUNIT_ASSERT(c._status == 1);
    }
    
    void test_CC_decide_revive()
    {
    	ConwayCell c(0);
    	ConwayCell c1(1), c2(1), c3(1);
    	c.add_neighbor(0,c1);
    	c.add_neighbor(1,c2);
    	c.add_neighbor(2,c3);
    	c.decide();
    	CPPUNIT_ASSERT(c._next_status == 1);
    }
    
    void test_CC_decide_die_too_few()
    {
    	ConwayCell c(1);
    	ConwayCell c1(0), c2(0), c3(1);
    	c.add_neighbor(0,c1);
    	c.add_neighbor(1,c2);
    	c.add_neighbor(2,c3);
    	c.decide();
    	CPPUNIT_ASSERT(c._next_status == 0);
    }
    
    void test_CC_decide_die_too_many()
    {
    	ConwayCell c(1);
    	ConwayCell c1(1), c2(1), c3(1), c4(1);
    	c.add_neighbor(0,c1);
    	c.add_neighbor(1,c2);
    	c.add_neighbor(2,c3);
    	c.add_neighbor(3,c4);
    	c.decide();
    	CPPUNIT_ASSERT(c._next_status == 0);
    }
    
    void test_CC_act_revive()
    {
    	ConwayCell c(0);
    	ConwayCell c1(1), c2(1), c3(1);
    	c.add_neighbor(0,c1);
    	c.add_neighbor(1,c2);
    	c.add_neighbor(2,c3);
    	c.decide();
    	c.act();
    	CPPUNIT_ASSERT(c._status == 1);
    }
    
    void test_CC_act_die_too_few()
    {
    	ConwayCell c(1);
    	ConwayCell c1(0), c2(0), c3(1);
    	c.add_neighbor(0,c1);
    	c.add_neighbor(1,c2);
    	c.add_neighbor(2,c3);
    	c.decide();
    	c.act();
    	CPPUNIT_ASSERT(c._status == 0);
    }
    
    void test_CC_act_die_too_many()
    {
    	ConwayCell c(1);
    	ConwayCell c1(1), c2(1), c3(1), c4(1);
    	c.add_neighbor(0,c1);
    	c.add_neighbor(1,c2);
    	c.add_neighbor(2,c3);
    	c.add_neighbor(3,c4);
    	c.decide();
    	c.act();
    	CPPUNIT_ASSERT(c._status == 0);
    }
    
	// --------
	// FredkinCell Tests
	// --------
	
	void test_FC_output_DEAD () {
		ostringstream s;
		FredkinCell c(0);
		s << c;
        CPPUNIT_ASSERT(s.str() == "-");
    }
    
    void test_FC_output_ALIVE () {
		ostringstream s;
		FredkinCell c(1);
		s << c;
        CPPUNIT_ASSERT(s.str() == "0");
    }
    
    void test_FC_output_ALIVE_age () {
		ostringstream s;
		FredkinCell c(1);
		++c._age;
		s << c;
		
        CPPUNIT_ASSERT(s.str() == "1");
    }
    
    void test_FC_output_ALIVE_age_ten () {
		ostringstream s;
		FredkinCell c(1);
		c._age = 10;
		s << c;
		
        CPPUNIT_ASSERT(s.str() == "+");
    }
    
    void test_FC_input_DEAD () {
		stringstream s;
		s << '-';
		FredkinCell c(1);
		s >> c;
        CPPUNIT_ASSERT(c._status == 0);
    }
    
    void test_FC_input_ALIVE () {
		stringstream s;
		s << '0';
		FredkinCell c(0);
		s >> c;
        CPPUNIT_ASSERT(c._status == 1);
    }
    
    void test_FC_input_ALIVE_age () {
		stringstream s;
		s << '5';
		FredkinCell c(0);
		s >> c;
        CPPUNIT_ASSERT(c.is_alive());
        CPPUNIT_ASSERT(c._age == 5);
    }
    
    void test_FC_input_ALIVE_age_ten () {
		stringstream s;
		s << '+';
		FredkinCell c(0);
		s >> c;
        CPPUNIT_ASSERT(c.is_alive());
        CPPUNIT_ASSERT(c._age == 10);
    }
    
    void test_FC_decide_revive_3()
    {
    	FredkinCell c(0);
    	FredkinCell c1(1), c2(1), c3(1);
    	c.add_neighbor(N,c1);
    	c.add_neighbor(E,c2);
    	c.add_neighbor(W,c3);
    	c.decide();
    	c.act();
    	CPPUNIT_ASSERT(c._next_status == 1);
    }
    
    void test_FC_decide_revive_1()
    {
    	FredkinCell c(0);
    	FredkinCell c1(1), c2(0), c3(0);
    	c.add_neighbor(N,c1);
    	c.add_neighbor(E,c2);
    	c.add_neighbor(W,c3);
    	c.decide();
    	c.act();
    	CPPUNIT_ASSERT(c._next_status == 1);
    }
    
    void test_FC_decide_die_zero()
    {
    	FredkinCell c(1);
    	FredkinCell c1(0), c2(0), c3(0);
    	c.add_neighbor(N,c1);
    	c.add_neighbor(E,c2);
    	c.add_neighbor(W,c3);
    	c.decide();
    	c.act();
    	CPPUNIT_ASSERT(c._next_status == 0);
    }
    
    void test_FC_decide_die_two()
    {
    	FredkinCell c(1);
    	FredkinCell c1(0), c2(1), c3(1);
    	c.add_neighbor(N,c1);
    	c.add_neighbor(E,c2);
    	c.add_neighbor(W,c3);
    	c.decide();
    	c.act();
    	CPPUNIT_ASSERT(c._next_status == 0);
    }
    
    void test_FC_decide_die_four()
    {
    	FredkinCell c(1);
    	FredkinCell c1(1), c2(1), c3(1), c4(1);
    	c.add_neighbor(N,c1);
    	c.add_neighbor(E,c2);
    	c.add_neighbor(W,c3);
    	c.add_neighbor(S,c4);
    	c.decide();
    	c.act();
    	CPPUNIT_ASSERT(c._next_status == 0);
    }
    
    void test_FC_act_revive_3()
    {
    	FredkinCell c(0);
    	FredkinCell c1(1), c2(1), c3(1);
    	c.add_neighbor(N,c1);
    	c.add_neighbor(E,c2);
    	c.add_neighbor(W,c3);
    	c.decide();
    	c.act();
    	CPPUNIT_ASSERT(c._status == 1);
    }
    
    void test_FC_act_revive_1()
    {
    	FredkinCell c(0);
    	FredkinCell c1(1), c2(0), c3(0);
    	c.add_neighbor(N,c1);
    	c.add_neighbor(E,c2);
    	c.add_neighbor(W,c3);
    	c.decide();
    	c.act();
    	CPPUNIT_ASSERT(c._status == 1);
    }
    
    void test_FC_act_die_zero()
    {
    	FredkinCell c(1);
    	FredkinCell c1(0), c2(0), c3(0);
    	c.add_neighbor(N,c1);
    	c.add_neighbor(E,c2);
    	c.add_neighbor(W,c3);
    	c.decide();
    	c.act();
    	CPPUNIT_ASSERT(c._status == 0);
    }
    
    void test_FC_act_die_two()
    {
    	FredkinCell c(1);
    	FredkinCell c1(0), c2(1), c3(1);
    	c.add_neighbor(N,c1);
    	c.add_neighbor(E,c2);
    	c.add_neighbor(W,c3);
    	c.decide();
    	c.act();
    	CPPUNIT_ASSERT(c._status == 0);
    }
    
    void test_FC_act_die_four()
    {
    	FredkinCell c(1);
    	FredkinCell c1(1), c2(1), c3(1), c4(1);
    	c.add_neighbor(N,c1);
    	c.add_neighbor(E,c2);
    	c.add_neighbor(W,c3);
    	c.add_neighbor(S,c4);
    	c.decide();
    	c.act();
    	CPPUNIT_ASSERT(c._status == 0);
    }
    
    void test_FC_act_die_bad_neighbors()
    {
    	FredkinCell c(1);
    	FredkinCell c1(1), c2(1), c3(1);
    	c.add_neighbor(NE,c1);
    	c.add_neighbor(SE,c2);
    	c.add_neighbor(NW,c3);
    	c.decide();
    	c.act();
    	CPPUNIT_ASSERT(c._status == 0);
    }
	
	// --------
	// Cell Tests
	// --------
    
    void test_Cell_Conway_DEAD () {
		ostringstream s;
		Cell c = new ConwayCell(0);
		s << c;
        CPPUNIT_ASSERT(s.str() == ".");
    }
    
    void test_Cell_Fredkin_ALIVE () {
		ostringstream s;
		Cell c = new FredkinCell(1);
		s << c;
        CPPUNIT_ASSERT(s.str() == "0");
    }
    
    void test_Cell_Mutate()
    {
    	ostringstream s;
		Cell c = new ConwayCell(0);
		c.mutate();
		s << c;
        CPPUNIT_ASSERT(s.str() == ".");
    }
    
    void test_Cell_Mutate_no_change()
    {
    	ostringstream s;
		Cell c = new ConwayCell(1);
		c.mutate();
		s << c;
        CPPUNIT_ASSERT(s.str() == "*");
    }
    
    void test_Cell_Mutate_change()
    {
    	ostringstream s;
		Cell c = new FredkinCell(1);
		c.mutate();
		s << c;
        CPPUNIT_ASSERT(s.str() == "*");
    }
    
    void test_Cell_Mutate_at_age_2()
    {
    	stringstream s;
    	ostringstream s2;
    	s << '1';
		Cell c = new FredkinCell(1);
		ConwayCell c1(1);
		c.add_neighbor(N,c1);
		s >> c;
		c.decide();
		c.act();
		s2 << c;
        CPPUNIT_ASSERT(s2.str() == "*");
    }
    
    void test_Cell_Mutate_failure_too_old()
    {
    	stringstream s;
    	ostringstream s2;
    	s << '2';
		Cell c = new FredkinCell(1);
		ConwayCell c1(1);
		c.add_neighbor(N,c1);
		s >> c;
		c.decide();
		c.act();
		s2 << c;
        CPPUNIT_ASSERT(s2.str() == "3");
    }
    
    void test_Cell_Fredkin_decide_revive_3()
    {
    	Cell c = new FredkinCell(0);
    	FredkinCell c1(1), c2(1), c3(1);
    	c.add_neighbor(N,c1);
    	c.add_neighbor(E,c2);
    	c.add_neighbor(W,c3);
    	c.decide();
    	c.act();
    	CPPUNIT_ASSERT(c.get()->_next_status == 1);
    }
    
    void test_Cell_Fredkin_decide_revive_1()
    {
    	Cell c = new FredkinCell(0);
    	FredkinCell c1(1), c2(0), c3(0);
    	c.add_neighbor(N,c1);
    	c.add_neighbor(E,c2);
    	c.add_neighbor(W,c3);
    	c.decide();
    	c.act();
    	CPPUNIT_ASSERT(c.get()->_next_status == 1);
    }
    
    void test_Cell_Fredkin_decide_die_zero()
    {
    	Cell c = new FredkinCell(1);
    	FredkinCell c1(0), c2(0), c3(0);
    	c.add_neighbor(N,c1);
    	c.add_neighbor(E,c2);
    	c.add_neighbor(W,c3);
    	c.decide();
    	c.act();
    	CPPUNIT_ASSERT(c.get()->_next_status == 0);
    }
    
    void test_Cell_Fredkin_decide_die_two()
    {
    	Cell c = new FredkinCell(1);
    	FredkinCell c1(0), c2(1), c3(1);
    	c.add_neighbor(N,c1);
    	c.add_neighbor(E,c2);
    	c.add_neighbor(W,c3);
    	c.decide();
    	c.act();
    	CPPUNIT_ASSERT(c.get()->_next_status == 0);
    }
    
    void test_Cell_Fredkin_decide_die_four()
    {
    	Cell c = new FredkinCell(1);
    	FredkinCell c1(1), c2(1), c3(1), c4(1);
    	c.add_neighbor(N,c1);
    	c.add_neighbor(E,c2);
    	c.add_neighbor(W,c3);
    	c.add_neighbor(S,c4);
    	c.decide();
    	c.act();
    	CPPUNIT_ASSERT(c.get()->_next_status == 0);
    }
    
    void test_Cell_Conway_act_revive()
    {
    	Cell c = new ConwayCell(0);
    	ConwayCell c1(1), c2(1), c3(1);
    	c.add_neighbor(0,c1);
    	c.add_neighbor(1,c2);
    	c.add_neighbor(2,c3);
    	c.decide();
    	c.act();
    	CPPUNIT_ASSERT(c.is_alive());
    }
    
    void test_Cell_Conway_act_die_too_few()
    {
    	Cell c = new ConwayCell(1);
    	ConwayCell c1(0), c2(0), c3(1);
    	c.add_neighbor(0,c1);
    	c.add_neighbor(1,c2);
    	c.add_neighbor(2,c3);
    	c.decide();
    	c.act();
    	CPPUNIT_ASSERT(!c.is_alive());
    }
    
    void test_Cell_Conway_act_die_too_many()
    {
    	Cell c = new ConwayCell(1);
    	ConwayCell c1(1), c2(1), c3(1), c4(1);
    	c.add_neighbor(0,c1);
    	c.add_neighbor(1,c2);
    	c.add_neighbor(2,c3);
    	c.add_neighbor(3,c4);
    	c.decide();
    	c.act();
    	CPPUNIT_ASSERT(!c.is_alive());
    }
    
    // --------
	// Life Tests
	// --------
	
	void test_Life_Conway_output()
	{
		stringstream s;
		Life<ConwayCell> l(10,10);
		s << l;
		CPPUNIT_ASSERT(s.str() == "Generation = 0, Population = 0.\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n");
	}
	
	void test_Life_Fredkin_output()
	{
		stringstream s;
		Life<FredkinCell> l(10,10);
		s << l;
		CPPUNIT_ASSERT(s.str() == "Generation = 0, Population = 0.\n----------\n----------\n----------\n----------\n----------\n----------\n----------\n----------\n----------\n----------\n");
	}
	
	void test_Life_Cell_output()
	{
		stringstream s;
		Life<Cell> l(10,10,new FredkinCell(1));
		s << l;
		CPPUNIT_ASSERT(s.str() == "Generation = 0, Population = 100.\n0000000000\n0000000000\n0000000000\n0000000000\n0000000000\n0000000000\n0000000000\n0000000000\n0000000000\n0000000000\n");
	}
	
	void test_Life_Cell_output_2()
	{
		stringstream s;
		Life<Cell> l(10,10,new ConwayCell(1));
		s << l;
		CPPUNIT_ASSERT(s.str() == "Generation = 0, Population = 100.\n**********\n**********\n**********\n**********\n**********\n**********\n**********\n**********\n**********\n**********\n");
	}
	
	void test_Life_Conway_input()
	{
		stringstream s("..........\n..........\n...***....\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n");
		stringstream s2;
		Life<ConwayCell> l(10,10);
		s >> l;
		s2 << l;
		CPPUNIT_ASSERT(s2.str() == "Generation = 0, Population = 3.\n..........\n..........\n...***....\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n");
	}
	
	void test_Life_Fredkin_input()
	{
		stringstream s;
		stringstream s2("--000-----\n----------\n----------\n----------\n---00-----\n----------\n----------\n----------\n----000---\n----------\n");
		Life<FredkinCell> l(10,10);
		s2 >> l;
		s << l;
		CPPUNIT_ASSERT(s.str() == "Generation = 0, Population = 8.\n--000-----\n----------\n----------\n----------\n---00-----\n----------\n----------\n----------\n----000---\n----------\n");
	}
	
	void test_Life_Cell_input()
	{
		stringstream s;
		stringstream s2("--000-----\n----------\n----------\n----------\n---00-----\n----------\n----------\n----------\n----000---\n----------\n");
		Life<Cell> l(10,10,new FredkinCell(1));
		s2 >> l;
		s << l;
		CPPUNIT_ASSERT(s.str() == "Generation = 0, Population = 8.\n--000-----\n----------\n----------\n----------\n---00-----\n----------\n----------\n----------\n----000---\n----------\n");
	}
	
	void test_Life_Cell_input_2()
	{
		stringstream s;
		stringstream s2("..........\n..........\n...***....\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n");
		Life<Cell> l(10,10,new ConwayCell(1));
		s2 >> l;
		s << l;
		CPPUNIT_ASSERT(s.str() == "Generation = 0, Population = 3.\n..........\n..........\n...***....\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n");
	}
	
	void test_Life_assign_neighbors_2x2()
	{
		Life<ConwayCell> l(2,2);
		l.set_up();
		CPPUNIT_ASSERT(l.contents[0]._neighbors[0] == 0);
		CPPUNIT_ASSERT(l.contents[0]._neighbors[1] == 0);
		CPPUNIT_ASSERT(l.contents[0]._neighbors[2] == &l.contents[1]);
		CPPUNIT_ASSERT(l.contents[0]._neighbors[3] == &l.contents[3]);
		CPPUNIT_ASSERT(l.contents[0]._neighbors[4] == &l.contents[2]);
		CPPUNIT_ASSERT(l.contents[0]._neighbors[5] == 0);
		CPPUNIT_ASSERT(l.contents[0]._neighbors[6] == 0);
		CPPUNIT_ASSERT(l.contents[0]._neighbors[7] == 0);
		
		
			
		CPPUNIT_ASSERT(l.contents[1]._neighbors[0] == 0);
		CPPUNIT_ASSERT(l.contents[1]._neighbors[1] == 0);
		CPPUNIT_ASSERT(l.contents[1]._neighbors[2] == 0);
		CPPUNIT_ASSERT(l.contents[1]._neighbors[3] == 0);
		CPPUNIT_ASSERT(l.contents[1]._neighbors[4] == &l.contents[3]);
		CPPUNIT_ASSERT(l.contents[1]._neighbors[5] == &l.contents[2]);
		CPPUNIT_ASSERT(l.contents[1]._neighbors[6] == &l.contents[0]);
		CPPUNIT_ASSERT(l.contents[1]._neighbors[7] == 0);
		
		CPPUNIT_ASSERT(l.contents[2]._neighbors[0] == &l.contents[0]);
		CPPUNIT_ASSERT(l.contents[2]._neighbors[1] == &l.contents[1]);
		CPPUNIT_ASSERT(l.contents[2]._neighbors[2] == &l.contents[3]);
		CPPUNIT_ASSERT(l.contents[2]._neighbors[3] == 0);
		CPPUNIT_ASSERT(l.contents[2]._neighbors[4] == 0);
		CPPUNIT_ASSERT(l.contents[2]._neighbors[5] == 0);
		CPPUNIT_ASSERT(l.contents[2]._neighbors[6] == 0);
		CPPUNIT_ASSERT(l.contents[2]._neighbors[7] == 0);
		
		/*for(int i = 0;i<8;++i)
			cout << i << ": " << l.contents[1]._neighbors[i] << endl;*/
		
		CPPUNIT_ASSERT(l.contents[3]._neighbors[0] == &l.contents[1]);
		CPPUNIT_ASSERT(l.contents[3]._neighbors[1] == 0);
		CPPUNIT_ASSERT(l.contents[3]._neighbors[2] == 0);
		CPPUNIT_ASSERT(l.contents[3]._neighbors[3] == 0);
		CPPUNIT_ASSERT(l.contents[3]._neighbors[4] == 0);
		CPPUNIT_ASSERT(l.contents[3]._neighbors[5] == 0);
		CPPUNIT_ASSERT(l.contents[3]._neighbors[6] == &l.contents[2]);
		CPPUNIT_ASSERT(l.contents[3]._neighbors[7] == &l.contents[0]);
	}
	
	void test_Life_assign_neighbors_center()
	{
		Life<FredkinCell> l(3,3);
		l.set_up();
		CPPUNIT_ASSERT(l.contents[4]._neighbors[0] == &l.contents[1]);
		CPPUNIT_ASSERT(l.contents[4]._neighbors[1] == &l.contents[2]);
		CPPUNIT_ASSERT(l.contents[4]._neighbors[2] == &l.contents[5]);
		CPPUNIT_ASSERT(l.contents[4]._neighbors[3] == &l.contents[8]);
		CPPUNIT_ASSERT(l.contents[4]._neighbors[4] == &l.contents[7]);
		CPPUNIT_ASSERT(l.contents[4]._neighbors[5] == &l.contents[6]);
		CPPUNIT_ASSERT(l.contents[4]._neighbors[6] == &l.contents[3]);
		CPPUNIT_ASSERT(l.contents[4]._neighbors[7] == &l.contents[0]);
	}
	
	void test_Life_run_once()
	{
		stringstream s2(".*\n**\n");
		stringstream s;
		Life<ConwayCell> l(2,2);
		s2 >> l;
		s << l;
		CPPUNIT_ASSERT(s.str() == "Generation = 0, Population = 3.\n.*\n**\n");
		
		s.str("");
		l.set_up();
		l.run_n_generations(1);
		s << l;
		CPPUNIT_ASSERT(s.str() == "Generation = 1, Population = 4.\n**\n**\n");
		
	}
	
	void test_Life_run_twice()
	{
		stringstream s2(".*\n**\n");
		stringstream s;
		Life<ConwayCell> l(2,2);
		s2 >> l;
		s << l;
		CPPUNIT_ASSERT(s.str() == "Generation = 0, Population = 3.\n.*\n**\n");
		
		s.str("");
		l.set_up();
		l.run_n_generations(2);
		s << l;
		
		CPPUNIT_ASSERT(s.str() == "Generation = 2, Population = 4.\n**\n**\n");
	}
	
	void test_Life_run_2x2_Fredkin()
	{
		stringstream s2("--\n-0\n");
		stringstream s;
		Life<FredkinCell> l(2,2);
		s2 >> l;
		s << l;
		CPPUNIT_ASSERT(s.str() == "Generation = 0, Population = 1.\n--\n-0\n");
		
		s.str("");
		l.set_up();
		l.run_n_generations(1);
		s << l;
		
		CPPUNIT_ASSERT(s.str() == "Generation = 1, Population = 2.\n-0\n0-\n");
		
		l.run_n_generations(1);
		s.str("");
		s << l;

		CPPUNIT_ASSERT(s.str() == "Generation = 2, Population = 0.\n--\n--\n");
	}
	
	void test_life_run_Cell_age()
	{		
		stringstream s2("00\n-2\n--");
		stringstream s;
		Life<Cell> l(3,2,new FredkinCell(0));
		s2 >> l;
		l.run_n_generations(6);
		s << l;
		CPPUNIT_ASSERT(s.str() == "Generation = 6, Population = 3.\n.-\n-8\n1*\n");
		s.str("");
		
		//l.run_n_generations(94);
	//	s << l;
		//CPPUNIT_ASSERT(s.str() == "Generation = 100, Population = 1.\n..\n-9\n..\n");
	}
    
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);
    //ConwayCell Tests
    CPPUNIT_TEST(test_nothing);
    CPPUNIT_TEST(test_CC_output_DEAD);
    CPPUNIT_TEST(test_CC_input_DEAD);
    CPPUNIT_TEST(test_CC_input_ALIVE);
    CPPUNIT_TEST(test_CC_output_ALIVE);
    CPPUNIT_TEST(test_CC_decide_revive);
    CPPUNIT_TEST(test_CC_decide_die_too_few);
    CPPUNIT_TEST(test_CC_decide_die_too_many);
    CPPUNIT_TEST(test_CC_act_revive);
    CPPUNIT_TEST(test_CC_act_die_too_few);
    CPPUNIT_TEST(test_CC_act_die_too_many);
    //FredkinCell Tests
    CPPUNIT_TEST(test_FC_output_DEAD);
    CPPUNIT_TEST(test_FC_input_DEAD);
    CPPUNIT_TEST(test_FC_input_ALIVE);
    CPPUNIT_TEST(test_FC_input_ALIVE_age);
    CPPUNIT_TEST(test_FC_input_ALIVE_age_ten);
    CPPUNIT_TEST(test_FC_output_ALIVE);
    CPPUNIT_TEST(test_FC_output_ALIVE_age);
    CPPUNIT_TEST(test_FC_output_ALIVE_age_ten);
    CPPUNIT_TEST(test_FC_decide_revive_1);
    CPPUNIT_TEST(test_FC_decide_revive_3);
    CPPUNIT_TEST(test_FC_decide_die_zero);
    CPPUNIT_TEST(test_FC_decide_die_two);
    CPPUNIT_TEST(test_FC_decide_die_four);
    CPPUNIT_TEST(test_FC_act_revive_1);
    CPPUNIT_TEST(test_FC_act_revive_3);
    CPPUNIT_TEST(test_FC_act_die_zero);
    CPPUNIT_TEST(test_FC_act_die_two);
    CPPUNIT_TEST(test_FC_act_die_four);
    CPPUNIT_TEST(test_FC_act_die_bad_neighbors);
    //Cell Tests
    CPPUNIT_TEST(test_Cell_Conway_DEAD);
    CPPUNIT_TEST(test_Cell_Fredkin_ALIVE);
    CPPUNIT_TEST(test_Cell_Mutate);
    CPPUNIT_TEST(test_Cell_Mutate_no_change);
    CPPUNIT_TEST(test_Cell_Mutate_change);
    CPPUNIT_TEST(test_Cell_Mutate_at_age_2);
    CPPUNIT_TEST(test_Cell_Mutate_failure_too_old);
    CPPUNIT_TEST(test_Cell_Fredkin_decide_revive_1);
    CPPUNIT_TEST(test_Cell_Fredkin_decide_revive_3);
    CPPUNIT_TEST(test_Cell_Fredkin_decide_die_zero);
    CPPUNIT_TEST(test_Cell_Fredkin_decide_die_two);
    CPPUNIT_TEST(test_Cell_Fredkin_decide_die_four);
    CPPUNIT_TEST(test_Cell_Conway_act_revive);
    CPPUNIT_TEST(test_Cell_Conway_act_die_too_few);
    CPPUNIT_TEST(test_Cell_Conway_act_die_too_many);
    //Life Tests
    CPPUNIT_TEST(test_Life_Conway_output);
    CPPUNIT_TEST(test_Life_Fredkin_output);
    CPPUNIT_TEST(test_Life_Cell_output);
    CPPUNIT_TEST(test_Life_Cell_output_2);
    CPPUNIT_TEST(test_Life_Conway_input);
    CPPUNIT_TEST(test_Life_Fredkin_input);
    CPPUNIT_TEST(test_Life_Cell_input);
    CPPUNIT_TEST(test_Life_Cell_input_2);
    CPPUNIT_TEST(test_Life_assign_neighbors_2x2);
    CPPUNIT_TEST(test_Life_assign_neighbors_center);
    CPPUNIT_TEST(test_Life_run_once);
    CPPUNIT_TEST(test_Life_run_twice);
    CPPUNIT_TEST(test_Life_run_2x2_Fredkin);
    CPPUNIT_TEST(test_life_run_Cell_age);
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
