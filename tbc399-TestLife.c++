#ifndef TEST_LIFE
#define TEST_LIFE

#define private public
#define protected public
//--------------------
// includes
//---------------------
#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <string>
#include <sstream>
#include <ios>
#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>
#include <istream>

#include <cppunit/extensions/HelperMacros.h> // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include <cppunit/TestFixture.h>             // TestFixture
#include <cppunit/TextTestRunner.h>
#include <cppunit/ui/text/TestRunner.h>          // TextTestRunner
#include <cppunit/CompilerOutputter.h>

#include "Life.h"
#include "AbstractCell.h"
#include "Cell.h"
#include "Handle.h"
#include "ConwayCell.h"
#include "FredkinCell.h"

using namespace std;

// -----------
// TestLife
// -----------

struct TestLife : CppUnit::TestFixture {
    
    // Life::play()
    
    	// test 1
    	void test_play_1() {
    		vector<ConwayCell> x(5, ConwayCell(true));
    		vector<vector<ConwayCell>> y(5, x);
    		Life<ConwayCell> life(y);
    		life.play(1);
    		CPPUNIT_ASSERT(life.generation == 1);
    		CPPUNIT_ASSERT(life.population == 4);
    	}
    	
    	// test 2
    	void test_play_2() {
    		vector<ConwayCell> x(4, ConwayCell(false));
    		vector<vector<ConwayCell>> y(4, x);
    		Life<ConwayCell> life(y);
    		life.play(5);
    		CPPUNIT_ASSERT(life.generation == 5);
    		CPPUNIT_ASSERT(life.population == 0);
    	}
    	
    	// test 3
    	void test_play_3() {
    		vector<ConwayCell> x(2, ConwayCell(true));
    		vector<vector<ConwayCell>> y(2, x);
    		Life<ConwayCell> life(y);
    		life.play(1);
    		CPPUNIT_ASSERT(life.generation == 1);
    		CPPUNIT_ASSERT(life.population == 4);
    	}
    
    // Life::act()
    
    	// test 1
    	void test_act_1() {
    		ConwayCell cc(false);
    		bool neighbors[] = {0,1,0,0,1,0,1,0};
    		Life<ConwayCell> life;
    		life.act(cc, neighbors);
    		CPPUNIT_ASSERT(cc.state == true);
    	}
    	
    	// test 2
    	void test_act_2() {
    		FredkinCell fc(true);
    		bool neighbors[] = {0,0,0,0,0,0,0,0};
    		Life<FredkinCell> life;
    		life.act(fc, neighbors);
    		CPPUNIT_ASSERT(fc.state == false);
    	}
    	
    	// test 3
    	void test_act_3() {
    		Cell c(new ConwayCell(true));
    		bool neighbors[] = {1,1,1,1,1,1,1,1};
    		Life<Cell> life;
    		life.act(c, neighbors);
    		CPPUNIT_ASSERT(c.get()->state == false);
    	}
    
    // Life::operator<<()
    
    	// test 1
    	void test_life_operator_out_1() {
    		vector<ConwayCell> x(5, ConwayCell(true));
    		vector<vector<ConwayCell>> y(5, x);
    		Life<ConwayCell> life(y);
    		string s("Generation = 0, Population = 25.\n*****\n*****\n*****\n*****\n*****\n");
    		ostringstream oss;
    		oss << life;
    		CPPUNIT_ASSERT(!oss.str().compare(s));
    	}
    	
    	// test 2
    	void test_life_operator_out_2() {
    		vector<ConwayCell> x(4, ConwayCell(false));
    		vector<vector<ConwayCell>> y(4, x);
    		Life<ConwayCell> life(y);
    		string s("Generation = 0, Population = 0.\n....\n....\n....\n....\n");
    		ostringstream oss;
    		oss << life;
    		CPPUNIT_ASSERT(!oss.str().compare(s));
    	}
    	
    	// test 3
    	void test_life_operator_out_3() {
    		vector<ConwayCell> x(2, ConwayCell(true));
    		vector<vector<ConwayCell>> y(2, x);
    		Life<ConwayCell> life(y);
    		string s("Generation = 0, Population = 4.\n**\n**\n");
    		ostringstream oss;
    		oss << life;
    		CPPUNIT_ASSERT(!oss.str().compare(s));
    	}
    	
    // Cell::evolve()
    
    	// test 1
    	void test_cell_evolve_1() {
    		Cell c = new ConwayCell(true);
    		bool neighbors[] = {1,0,1,0,1,0,1,0};
    		c.evolve(neighbors, false);
    		CPPUNIT_ASSERT(c.get()->state == false);
    	}
    	
    	// test 2
    	void test_cell_evolve_2() {
    		Cell c = new FredkinCell(false);
    		bool neighbors[] = {1,0,1,0,1,0,0,0};
    		c.evolve(neighbors, true);
    		CPPUNIT_ASSERT(c.get()->state == true);
    	}
    	
    	// test 3
    	void test_cell_evolve_3() {
    		Cell c = new FredkinCell(false);
    		bool neighbors[] = {1,0,1,0,1,0,1,0};
    		c.evolve(neighbors, true);
    		CPPUNIT_ASSERT(c.get()->state == false);
    	}
    
    // Cell::isAlive()
    
    	// test 1
    	void test_cell_isAlive_1() {
    		Cell c = new ConwayCell(true);
    		CPPUNIT_ASSERT(c.isAlive() == true);
    	}
    		
    	// test 2
    	void test_cell_isAlive_2() {
    		Cell c = new FredkinCell(false);
    		CPPUNIT_ASSERT(c.isAlive() == false);
    	}
    	
    	// test 3
    	void test_cell_isAlive_3() {
    		Cell c = new FredkinCell(false);
    		Life<Cell> life;
    		bool neighbors[] = {1,1,0,0,0,0,0,0};
    		life.act(c, neighbors);
    		CPPUNIT_ASSERT(c.isAlive() == true);
    	}
    
    // Cell::get() const
    
    	// test 1
    	void test_cell_get_const_1() {
    		ConwayCell* cc = new ConwayCell(true);
    		const Cell c(cc);
    		CPPUNIT_ASSERT(cc == c.get());
    	}
    	
    	// test 2
    	void test_cell_get_const_2() {
    		FredkinCell* cc = new FredkinCell(false);
    		const Cell c(cc);
    		CPPUNIT_ASSERT(0 != c.get());
    	}
    	
    	// test 3
    	void test_cell_get_const_3() {
    		FredkinCell* cc = new FredkinCell(true);
    		const Cell c(cc);
    		CPPUNIT_ASSERT(cc == c.get());
    	}
    	
    // Cell::get()
    
    	// test 1
    	void test_cell_get_1() {
    		ConwayCell* cc = new ConwayCell(true);
    		Cell c(cc);
    		CPPUNIT_ASSERT(cc == c.get());
    	}
    	
    	// test 2
    	void test_cell_get_2() {
    		FredkinCell* cc = new FredkinCell(false);
    		Cell c(cc);
    		CPPUNIT_ASSERT(0 != c.get());
    	}
    	
    	// test 3
    	void test_cell_get_3() {
    		FredkinCell* cc = new FredkinCell(true);
    		Cell c(cc);
    		CPPUNIT_ASSERT(cc == c.get());
    	}
    	
    // Cell::operator=()
    
    	// test 1
    	void test_cell_operator_assignment_1() {
    		Cell x = new ConwayCell(true);
    		Cell y = new ConwayCell(false);
    		y = x;
    		CPPUNIT_ASSERT(y.get()->state == true);
    	}
    	
    	// test 2
    	void test_cell_operator_assignment_2() {
    		Cell x = new ConwayCell(true);
    		Cell y = new FredkinCell(false);
    		y = x;
    		CPPUNIT_ASSERT(y.get()->state == true);
    	}
    	
    	// test 3
    	void test_cell_operator_assignment_3() {
    		Cell x = new FredkinCell(false);
    		Cell y = new FredkinCell(true);
    		y = x;
    		CPPUNIT_ASSERT(y.get()->state == false);
    	}
    	
    // Cell::operator<<()
    
    	// test 1
    	void test_cell_operator_out_1() {
    		Cell c = new ConwayCell(true);
    		ostringstream oss;
    		oss << c;
    		CPPUNIT_ASSERT(!oss.str().compare("*"));
    	}
    	
    	// test 2
    	void test_cell_operator_out_2() {
    		Cell c = new FredkinCell(true);
    		ostringstream oss;
    		oss << c;
    		CPPUNIT_ASSERT(!oss.str().compare("0"));
    	}
    	
    	// test 3
    	void test_cell_operator_out_3() {
    		Cell c = new ConwayCell(false);
    		ostringstream oss;
    		oss << c;
    		CPPUNIT_ASSERT(!oss.str().compare("."));
    	}
    	
    // ConwayCell::clone()
    
    	// test 1
    	void test_cc_clone_1() {
    		ConwayCell c(true);
    		ConwayCell* cc = c.clone();
    		CPPUNIT_ASSERT(cc != 0);
    		delete cc;
    	}
    	// test 2
    	void test_cc_clone_2() {
    		ConwayCell c(true);
    		ConwayCell* cc = c.clone();
    		CPPUNIT_ASSERT(cc->state == true);
    		delete cc;
    	}
    	
    	// test 3
    	void test_cc_clone_3() {
    		ConwayCell c(false);
    		ConwayCell* cc = c.clone();
    		CPPUNIT_ASSERT(cc->state == false);
    		delete cc;
    	}
    	
    // ConwayCell::evolve()
    
    	// test 1
    	void test_cc_evolve_1() {
    		ConwayCell c(true);
    		bool neighbors[] = {1,0,1,0,1,0,1,0};
    		c.evolve(neighbors, false);
    		CPPUNIT_ASSERT(c.state == false);
    	}
    	
    	// test 2
    	void test_cc_evolve_2() {
    		ConwayCell c(false);
    		bool neighbors[] = {1,0,0,0,1,0,0,1};
    		c.evolve(neighbors, false);
    		CPPUNIT_ASSERT(c.state == true);
    	}
    	
    	// test 3
    	void test_cc_evolve_3() {
    		ConwayCell c(false);
    		bool neighbors[] = {1,0,0,0,0,0,0,0};
    		c.evolve(neighbors, false);
    		CPPUNIT_ASSERT(c.state == false);
    	}
    	
    // ConwayCell::isAlive()
    
    	// test 1
    	void test_cc_isAlive_1() {
    		ConwayCell c(false);
    		CPPUNIT_ASSERT(c.isAlive() == false);
    	}
    	
    	// test 2
    	void test_cc_isAlive_2() {
    		ConwayCell c(true);
    		CPPUNIT_ASSERT(c.isAlive() == true);
    	}
    	
    	// test 3
    	void test_cc_isAlive_3() {
    		ConwayCell c(false);
    		Life<ConwayCell> life;
    		bool neighbors[] = {1,1,0,0,0,1,0,0};
    		life.act(c, neighbors);
    		CPPUNIT_ASSERT(c.isAlive() == true);
    	}
    	
    // ConwayCell::write()
    
    	// test 1
    	void test_cc_write_1() {
    		ConwayCell c(true);
    		ostringstream oss;
    		c.write(oss);
    		CPPUNIT_ASSERT(!oss.str().compare("*"));
    	}
    	
    	// test 2
    	void test_cc_write_2() {
    		ConwayCell c(false);
    		ostringstream oss;
    		c.write(oss);
    		CPPUNIT_ASSERT(!oss.str().compare("."));
    	}
    	
    	// test 3
    	void test_cc_write_3() {
    		ConwayCell c(true);
    		ostringstream oss;
    		c.write(oss);
    		CPPUNIT_ASSERT(oss.str().compare("."));
    	}
    	
    // ConwayCell::operator<<()
    
    	// test 1
    	void test_cc_operator_out_1() {
    		ConwayCell c(true);
    		ostringstream oss;
    		oss << c;
    		CPPUNIT_ASSERT(!oss.str().compare("*"));
    	}
    	
    	// test 2
    	void test_cc_operator_out_2() {
    		ConwayCell c(false);
    		ostringstream oss;
    		oss << c;
    		CPPUNIT_ASSERT(!oss.str().compare("."));
    	}
    	
    	// test 3
    	void test_cc_operator_out_3() {
    		ConwayCell c(true);
    		ostringstream oss;
    		oss << c;
    		CPPUNIT_ASSERT(oss.str().compare("."));
    	}
    	
    // FredkinCell::clone()
    
    	// test 1
    	void test_fc_clone_1() {
    		FredkinCell c(true);
    		FredkinCell* cc = c.clone();
    		CPPUNIT_ASSERT(cc != 0);
    		delete cc;
    	}
    	// test 2
    	void test_fc_clone_2() {
    		FredkinCell c(true);
    		FredkinCell* cc = c.clone();
    		CPPUNIT_ASSERT(cc->state == true);
    		delete cc;
    	}
    	
    	// test 3
    	void test_fc_clone_3() {
    		FredkinCell c(false);
    		FredkinCell* cc = c.clone();
    		CPPUNIT_ASSERT(cc->state == false);
    		delete cc;
    	}
    
    // FredkinCell::evolve()
    
    	// test 1
    	void test_fc_evolve_1() {
    		FredkinCell c(true);
    		bool neighbors[] = {1,0,1,0,1,0,1,0};
    		c.evolve(neighbors, true);
    		CPPUNIT_ASSERT(c.state == false);
    	}
    	
    	// test 2
    	void test_fc_evolve_2() {
    		FredkinCell c(false);
    		bool neighbors[] = {1,0,0,0,1,0,0,1};
    		c.evolve(neighbors, true);
    		CPPUNIT_ASSERT(c.state == false);
    	}
    	
    	// test 3
    	void test_fc_evolve_3() {
    		FredkinCell c(false);
    		bool neighbors[] = {1,0,0,0,0,0,0,0};
    		c.evolve(neighbors, false);
    		CPPUNIT_ASSERT(c.state == true);
    	}
    
    // FredkinCell::isAlive()
    
    	// test 1
    	void test_fc_isAlive_1() {
    		FredkinCell c(false);
    		CPPUNIT_ASSERT(c.isAlive() == false);
    	}
    	
    	// test 2
    	void test_fc_isAlive_2() {
    		FredkinCell c(true);
    		CPPUNIT_ASSERT(c.isAlive() == true);
    	}
    	
    	// test 3
    	void test_fc_isAlive_3() {
    		FredkinCell c(false);
    		Life<FredkinCell> life;
    		bool neighbors[] = {1,1,0,0,0,1,0,0};
    		life.act(c, neighbors);
    		CPPUNIT_ASSERT(c.isAlive() == true);
    	}
    
    // FredkinCell::write()
    
    	// test 1
    	void test_fc_write_1() {
    		FredkinCell c(true);
    		ostringstream oss;
    		c.write(oss);
    		CPPUNIT_ASSERT(!oss.str().compare("0"));
    	}
    	
    	// test 2
    	void test_fc_write_2() {
    		FredkinCell c(false);
    		ostringstream oss;
    		c.write(oss);
    		CPPUNIT_ASSERT(!oss.str().compare("-"));
    	}
    	
    	// test 3
    	void test_fc_write_3() {
    		FredkinCell c(true);
    		ostringstream oss;
    		c.write(oss);
    		CPPUNIT_ASSERT(oss.str().compare("-"));
    	}
    
    // FredkinCell::operator<<()
    
    	// test 1
    	void test_fc_operator_out_1() {
    		FredkinCell c(true);
    		ostringstream oss;
    		oss << c;
    		CPPUNIT_ASSERT(!oss.str().compare("0"));
    	}
    	
    	// test 2
    	void test_fc_operator_out_2() {
    		FredkinCell c(false);
    		ostringstream oss;
    		oss << c;
    		CPPUNIT_ASSERT(!oss.str().compare("-"));
    	}
    	
    	// test 3
    	void test_fc_operator_out_3() {
    		FredkinCell c(true);
    		ostringstream oss;
    		oss << c;
    		CPPUNIT_ASSERT(oss.str().compare("-"));
    	}
    
    // -----
    // suite
    // -----
	
    CPPUNIT_TEST_SUITE(TestLife);

    CPPUNIT_TEST(test_play_1);
    CPPUNIT_TEST(test_play_2);
    CPPUNIT_TEST(test_play_3);

    CPPUNIT_TEST(test_act_1);
    CPPUNIT_TEST(test_act_2);
    CPPUNIT_TEST(test_act_3);
    
    CPPUNIT_TEST(test_life_operator_out_1);
    CPPUNIT_TEST(test_life_operator_out_2);
    CPPUNIT_TEST(test_life_operator_out_3);
    
    CPPUNIT_TEST(test_cell_evolve_1);
    CPPUNIT_TEST(test_cell_evolve_2);
    CPPUNIT_TEST(test_cell_evolve_3);
    
    CPPUNIT_TEST(test_cell_isAlive_1);
    CPPUNIT_TEST(test_cell_isAlive_2);
    CPPUNIT_TEST(test_cell_isAlive_3);
    
    CPPUNIT_TEST(test_cell_get_const_1);
    CPPUNIT_TEST(test_cell_get_const_2);
    CPPUNIT_TEST(test_cell_get_const_3);
    
    CPPUNIT_TEST(test_cell_get_1);
    CPPUNIT_TEST(test_cell_get_2);
    CPPUNIT_TEST(test_cell_get_3);
    
    CPPUNIT_TEST(test_cell_operator_assignment_1);
    CPPUNIT_TEST(test_cell_operator_assignment_2);
    CPPUNIT_TEST(test_cell_operator_assignment_3);
    
    CPPUNIT_TEST(test_cell_operator_out_1);
    CPPUNIT_TEST(test_cell_operator_out_2);
    CPPUNIT_TEST(test_cell_operator_out_3);

	CPPUNIT_TEST(test_cc_clone_1);
    CPPUNIT_TEST(test_cc_clone_2);
    CPPUNIT_TEST(test_cc_clone_3);	
    
    CPPUNIT_TEST(test_cc_evolve_1);
    CPPUNIT_TEST(test_cc_evolve_2);
    CPPUNIT_TEST(test_cc_evolve_3);	
    
    CPPUNIT_TEST(test_cc_isAlive_1);
    CPPUNIT_TEST(test_cc_isAlive_2);
    CPPUNIT_TEST(test_cc_isAlive_3);	
    
    CPPUNIT_TEST(test_cc_write_1);
    CPPUNIT_TEST(test_cc_write_2);
    CPPUNIT_TEST(test_cc_write_3);
    
    CPPUNIT_TEST(test_cc_operator_out_1);
    CPPUNIT_TEST(test_cc_operator_out_2);
    CPPUNIT_TEST(test_cc_operator_out_3);
    
    CPPUNIT_TEST(test_fc_clone_1);
    CPPUNIT_TEST(test_fc_clone_2);
    CPPUNIT_TEST(test_fc_clone_3);	
    
    CPPUNIT_TEST(test_fc_evolve_1);
    CPPUNIT_TEST(test_fc_evolve_2);
    CPPUNIT_TEST(test_fc_evolve_3);	
    
    CPPUNIT_TEST(test_fc_isAlive_1);
    CPPUNIT_TEST(test_fc_isAlive_2);
    CPPUNIT_TEST(test_fc_isAlive_3);	
    
    CPPUNIT_TEST(test_fc_write_1);
    CPPUNIT_TEST(test_fc_write_2);
    CPPUNIT_TEST(test_fc_write_3);
    
    CPPUNIT_TEST(test_fc_operator_out_1);
    CPPUNIT_TEST(test_fc_operator_out_2);
    CPPUNIT_TEST(test_fc_operator_out_3);
    
	
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
    return 0;
}

#endif
