// ------------
// TestLife.c++
// ------------

// -------
// include
// -------

#define private public

#include <iostream>
#include <sstream>
#include <string>

#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TextTestRunner.h"

#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Life.h"
#include "Cell.h"

struct TestLife : CppUnit::TestFixture {
    
    // ----------------------------
    // Cell::Cell(AbstractCell*)
    // ----------------------------

    void test_cell_constructor_1() {
		Cell c = new ConwayCell(false);
    }
    
    void test_cell_constructor_2() {
		Cell c = new FredkinCell(false);
    }

    void test_cell_constructor_3() {
		Cell c = new ConwayCell(true);
    }
    
    // ----------------------------
    // Cell::get_state()
    // ----------------------------

    void test_cell_get_state_1() {
		Cell c = new ConwayCell(false);
		CPPUNIT_ASSERT(c.get_state() == false);
    }
    
    void test_cell_get_state_2() {
		Cell c = new FredkinCell(false);
		CPPUNIT_ASSERT(c.get_state() == false);
    }

    void test_cell_get_state_3() {
		Cell c = new ConwayCell(true);
		CPPUNIT_ASSERT(c.get_state() == true);
    }
    
    // ----------------------------
    // Cell::change_state()
    // ----------------------------

    void test_cell_change_state_1() {
		Cell c = new ConwayCell(false);
		CPPUNIT_ASSERT(c.get_state() == false);
		c.change_state();
		CPPUNIT_ASSERT(c.get_state() == true);
    }
    
    void test_cell_change_state_2() {
		Cell c = new FredkinCell(false);
		CPPUNIT_ASSERT(c.get_state() == false);
		c.change_state();
		CPPUNIT_ASSERT(c.get_state() == true);
    }

    void test_cell_change_state_3() {
		Cell c = new ConwayCell(true);
		CPPUNIT_ASSERT(c.get_state() == true);
		c.change_state();
		CPPUNIT_ASSERT(c.get_state() == false);
    }
    
    // ----------------------------
    // Cell::write(std::ostream&)
    // ----------------------------
    
    void test_cell_write_1() {
	std::ostringstream w;
	Cell c = new ConwayCell(true);
	c.write(w);
	CPPUNIT_ASSERT(w.str() == "*");
    }
    
    void test_cell_write_2() {
	std::ostringstream w;
	Cell c = new FredkinCell(true);
	c.write(w);
	CPPUNIT_ASSERT(w.str() == "0");
    }
    
    void test_cell_write_3() {
	std::ostringstream w;
	Cell c = new FredkinCell(false);
	c.write(w);
	CPPUNIT_ASSERT(w.str() == "-");
    }
    
    // -------------------------------
    // Cell::read(std::istream&)
    // -------------------------------

    void test_cell_read_1() {
	Cell c = new ConwayCell(true);
	std::istringstream r("false");
	c.read(r);
	CPPUNIT_ASSERT(!c.get_state());
    }

    void test_cell_read_2() {
	Cell c = new ConwayCell(false);
	std::istringstream r("true");
	c.read(r);
	CPPUNIT_ASSERT(c.get_state());
    }

    void test_cell_read_3() {
	Cell c = new FredkinCell(false);
	std::istringstream r("true");
	c.read(r);
	CPPUNIT_ASSERT(c.get_state());
    }
    
    // ----------------------------
    // Cell::increment_age()
    // ----------------------------
    
    void test_cell_increment_age_1() {
	Cell f1 = new FredkinCell(true);
	f1.increment_age();
	CPPUNIT_ASSERT(f1.get_age() == 1);
    }
    
    void test_cell_increment_age_2() {
	Cell f1 = new FredkinCell(true);
	f1.increment_age();
	f1.increment_age();
	CPPUNIT_ASSERT(f1.get_age() == 2);
    }
    
    void test_cell_increment_age_3() {
	Cell f1 = new FredkinCell(true);
	f1.increment_age();
	f1.increment_age();
	f1.increment_age();
	f1.increment_age();
	CPPUNIT_ASSERT(f1.get_age() == 4);
    }
    
    
    // -------------------
    // Cell::clone()
    // -------------------

    void test_cell_clone_1() {
    Cell c1 = new ConwayCell(true);
	Cell c2 = *(c1.clone());
	CPPUNIT_ASSERT(&c1 != &c2);
	CPPUNIT_ASSERT(c1.get_state());
	CPPUNIT_ASSERT(c2.get_state());
    }

    void test_cell_clone_2() {
    Cell c1 = new ConwayCell(false);
	Cell c2 = *(c1.clone());
	CPPUNIT_ASSERT(&c1 != &c2);
	CPPUNIT_ASSERT(!c1.get_state());
	CPPUNIT_ASSERT(!c2.get_state());
    }

    void test_cell_clone_3() {
    Cell c1 = new FredkinCell(true);
    c1.increment_age();
	Cell c2 = *(c1.clone());
	Cell c3 = *(c2.clone());
	c1.increment_age();
	CPPUNIT_ASSERT(&c1 != &c2);
	CPPUNIT_ASSERT(&c2 != &c3);
	CPPUNIT_ASSERT(&c1 != &c3);
	CPPUNIT_ASSERT(c1.get_age() == 2);
	CPPUNIT_ASSERT(c2.get_age() == 1);
	CPPUNIT_ASSERT(c3.get_age() == 1);
    }
    
    // -------------------
    // Cell::get_type()
    // -------------------

    void test_cell_get_type_1() {
    Cell c1 = new FredkinCell(true);
	CPPUNIT_ASSERT(c1.get_type() == 'f');
    }
    
    void test_cell_get_type_2() {
    Cell c1 = new ConwayCell(true);
	CPPUNIT_ASSERT(c1.get_type() == 's');
    }
    
    void test_cell_get_type_3() {
    Cell c1 = new ConwayCell(false);
	CPPUNIT_ASSERT(c1.get_type() == 's');
    }
    
    // -------------------
    // Cell::get_age()
    // -------------------

    void test_cell_get_age_1() {
    Cell c1 = new FredkinCell(true);
    c1.increment_age();
	CPPUNIT_ASSERT(c1.get_age() == 1);
    }
    
    void test_cell_get_age_2() {
    Cell c1 = new FredkinCell(true);
	CPPUNIT_ASSERT(c1.get_age() == 0);
    }
    
    void test_cell_get_age_3() {
    Cell c1 = new ConwayCell(false);
	CPPUNIT_ASSERT(c1.get_age() == 0);
    }
    
    // -------------------
    // Cell::mutate()
    // -------------------

    void test_cell_mutate_1() {
    	Cell c1 = new FredkinCell(true);
    	Cell c2 = *(c1.mutate());
	std::ostringstream w;
	CPPUNIT_ASSERT(c2.get_age() == 0);
	c2.write(w);
	CPPUNIT_ASSERT(w.str() == "*");
	CPPUNIT_ASSERT(c2.get_state());
    }
    
    void test_cell_mutate_2() {
    	Cell c1 = new FredkinCell(false);
    	c1.increment_age();
    	Cell c2 = *(c1.mutate());
	CPPUNIT_ASSERT(c2.get_age() == 0);
	CPPUNIT_ASSERT(!c2.get_state());
    }
    
    void test_cell_mutate_3() {
    	Cell c1 = new FredkinCell(false);
    	Cell c2 = *(c1.mutate());
	std::ostringstream w;
	CPPUNIT_ASSERT(c2.get_age() == 0);
	c2.write(w);
	CPPUNIT_ASSERT(w.str() == ".");
    }
    
    // ----------------------------
    // ConwayCell::ConwayCell(bool)
    // ----------------------------

    void test_conway_default_constructor_1() {
	ConwayCell c(true);
	CPPUNIT_ASSERT(c.get_state());
    }
    
    void test_conway_default_constructor_2() {
	ConwayCell c(false);
	CPPUNIT_ASSERT(!c.get_state());
    }

    void test_conway_default_constructor_3() {
	ConwayCell c1(false);
	ConwayCell c2(true);
	CPPUNIT_ASSERT(!c1.get_state());
	CPPUNIT_ASSERT(c2.get_state());
    }

    // -----------------------------------------------
    // ConwayCell::ConwayCell(const ConwayCell* const)
    // -----------------------------------------------

    void test_conway_copy_constructor_1() {
	ConwayCell c1(true);
	ConwayCell c2(&c1);
	CPPUNIT_ASSERT(c2.get_state());
    }

    void test_conway_copy_constructor_2() {
	ConwayCell c1(false);
	ConwayCell c2(&c1);
	CPPUNIT_ASSERT(!c2.get_state());
    }

    void test_conway_copy_constructor_3() {
	ConwayCell c1(false);
	ConwayCell c2(&c1);
	ConwayCell c3(&c2);
	CPPUNIT_ASSERT(!c2.get_state());
	CPPUNIT_ASSERT(!c3.get_state());
    }

    // -------------------
    // ConwayCell::clone()
    // -------------------

    void test_conway_clone_1() {
	ConwayCell c1(true);
	ConwayCell& c2 = *(c1.clone());
	CPPUNIT_ASSERT(&c1 != &c2);
	CPPUNIT_ASSERT(c1.get_state());
	CPPUNIT_ASSERT(c2.get_state());
    }

    void test_conway_clone_2() {
	ConwayCell c1(false);
	ConwayCell& c2 = *(c1.clone());
	CPPUNIT_ASSERT(&c1 != &c2);
	CPPUNIT_ASSERT(!c1.get_state());
	CPPUNIT_ASSERT(!c2.get_state());
    }

    void test_conway_clone_3() {
	ConwayCell c1(true);
	ConwayCell& c2 = *(c1.clone());
	ConwayCell& c3 = *(c2.clone());
	CPPUNIT_ASSERT(&c1 != &c2);
	CPPUNIT_ASSERT(&c2 != &c3);
	CPPUNIT_ASSERT(&c1 != &c3);
	CPPUNIT_ASSERT(c1.get_state());
	CPPUNIT_ASSERT(c2.get_state());
	CPPUNIT_ASSERT(c3.get_state());
    }

    // ---------------------------------------
    // ConwayCell::equals(const AbstractCell&)
    // ---------------------------------------

    void test_conway_equals_1() {
	ConwayCell c1(true);
	ConwayCell c2(true);
	CPPUNIT_ASSERT(c1.equals(c2));
	CPPUNIT_ASSERT(c1.get_state());
	CPPUNIT_ASSERT(c2.get_state());
    }

    void test_conway_equals_2() {
	ConwayCell c1(true);
	ConwayCell c2(false);
	CPPUNIT_ASSERT(!c1.equals(c2));
	CPPUNIT_ASSERT(c1.get_state());
	CPPUNIT_ASSERT(!c2.get_state());
    }

    void test_conway_equals_3() {
	ConwayCell c1(true);
	ConwayCell c2(&c1);
	CPPUNIT_ASSERT(c1.equals(c2));
	CPPUNIT_ASSERT(c1.get_state());
	CPPUNIT_ASSERT(c2.get_state());
    }

    // -------------------------------
    // ConwayCell::read(std::istream&)
    // -------------------------------

    void test_conway_read_1() {
	ConwayCell c(true);
	std::istringstream r("false");
	c.read(r);
	CPPUNIT_ASSERT(!c.get_state());
    }

    void test_conway_read_2() {
	ConwayCell c(false);
	std::istringstream r("true");
	c.read(r);
	CPPUNIT_ASSERT(c.get_state());
    }

    void test_conway_read_3() {
	ConwayCell c(true);
	std::istringstream r("true");
	c.read(r);
	CPPUNIT_ASSERT(c.get_state());
    }

    // --------------------------------
    // ConwayCell::write(std::ostream&)
    // --------------------------------

    void test_conway_write_1() {
	std::ostringstream w;
	ConwayCell c(true);
	c.write(w);
	CPPUNIT_ASSERT(w.str() == "*");
    }

    void test_conway_write_2() {
	std::ostringstream w;
	ConwayCell c(false);
	c.write(w);
	CPPUNIT_ASSERT(w.str() == ".");
    }

    void test_conway_write_3() {
	std::ostringstream w;
	ConwayCell c1(true);
	ConwayCell c2(false);
	c1.write(w);
	c2.write(w);
	CPPUNIT_ASSERT(w.str() == "*.");
    }
    
    // -------------------
    // ConwayCell::get_type()
    // -------------------

    void test_conway_get_type_1() {
	ConwayCell c1(true);
	CPPUNIT_ASSERT(c1.get_type() == 's');
    }
    
    void test_conway_get_type_2() {
	ConwayCell c1(false);
	CPPUNIT_ASSERT(c1.get_type() == 's');
    }
    
    void test_conway_get_type_3() {
	ConwayCell c1(true);
	ConwayCell c2(c1);
	CPPUNIT_ASSERT(c2.get_type() == 's');
    }
    
    // ----------------------------
    // FredkinCell:FredkinCell(bool, int)
    // ----------------------------

    void test_fredkin_default_constructor_1() {
		FredkinCell f(false	);
		CPPUNIT_ASSERT(!f.get_state());
		CPPUNIT_ASSERT(f.get_age() == 0);
    }
    
    void test_fredkin_default_constructor_2() {
		FredkinCell f(false);
		CPPUNIT_ASSERT(!f.get_state());
		CPPUNIT_ASSERT(f.get_age() == 0);
    }

    void test_fredkin_default_constructor_3() {
    	FredkinCell f1(true);
		CPPUNIT_ASSERT(f1.get_state());
		CPPUNIT_ASSERT(f1.get_age() == 0);
		FredkinCell f2(false);
		CPPUNIT_ASSERT(!f2.get_state());
		CPPUNIT_ASSERT(f2.get_age() == 0);
    }
    
    // -----------------------------------------------
    // FredkinCell::FredkinCell(const FredkinCell* const)
    // -----------------------------------------------

    void test_fredkin_copy_constructor_1() {
	FredkinCell f1(true);
	FredkinCell f2(&f1);
	CPPUNIT_ASSERT(f2.get_state());
	CPPUNIT_ASSERT(f2.get_age() == 0);
    }

    void test_fredkin_copy_constructor_2() {
	FredkinCell f1(false);
	FredkinCell f2(&f1);
	CPPUNIT_ASSERT(!f2.get_state());
	CPPUNIT_ASSERT(f2.get_age() == 0);
    }

    void test_fredkin_copy_constructor_3() {
	FredkinCell f1(false);
	FredkinCell f2(&f1);
	FredkinCell f3(&f2);
	CPPUNIT_ASSERT(!f2.get_state());
	CPPUNIT_ASSERT(f2.get_age() == 0);	
	CPPUNIT_ASSERT(!f3.get_state());
	CPPUNIT_ASSERT(f3.get_age() == 0);	
    }
    
    // -------------------
    // FredkinCell::clone()
    // -------------------

    void test_fredkin_clone_1() {
	FredkinCell f1(true);
	FredkinCell& f2 = *(f1.clone());
	CPPUNIT_ASSERT(&f1 != &f2);
	CPPUNIT_ASSERT(f1.get_state());
	CPPUNIT_ASSERT(f2.get_state());
	CPPUNIT_ASSERT(f1.get_age() == 0);
	CPPUNIT_ASSERT(f2.get_age() == 0);
    }

    void test_fredkin_clone_2() {
	FredkinCell f1(false);
	FredkinCell& f2 = *(f1.clone());
	CPPUNIT_ASSERT(&f1 != &f2);
	CPPUNIT_ASSERT(!f1.get_state());
	CPPUNIT_ASSERT(!f2.get_state());
	CPPUNIT_ASSERT(f1.get_age() == 0);
	CPPUNIT_ASSERT(f2.get_age() == 0);
    }

    void test_fredkin_clone_3() {
	FredkinCell f1(true);
	FredkinCell& f2 = *(f1.clone());
	FredkinCell& f3 = *(f2.clone());
	CPPUNIT_ASSERT(&f1 != &f2);
	CPPUNIT_ASSERT(&f2 != &f3);
	CPPUNIT_ASSERT(&f1 != &f3);
	CPPUNIT_ASSERT(f1.get_state());
	CPPUNIT_ASSERT(f2.get_state());
	CPPUNIT_ASSERT(f3.get_state());
	CPPUNIT_ASSERT(f1.get_age() == 0);
	CPPUNIT_ASSERT(f2.get_age() == 0);
	CPPUNIT_ASSERT(f3.get_age() == 0);
    }
    
    // -------------------
    // FredkinCell::get_age()
    // -------------------

    void test_fredkin_get_age_1() {
	FredkinCell f1(true);
	CPPUNIT_ASSERT(f1.get_age() == 0);
    }
    
    void test_fredkin_get_age_2() {
	FredkinCell f1(false);
	CPPUNIT_ASSERT(f1.get_age() == 0);
    }
    
    void test_fredkin_get_age_3() {
	FredkinCell f1(true);
	CPPUNIT_ASSERT(f1.get_age() == 0);
    }
    
    // ----------------------------
    // FredkinCell::increment_age()
    // ----------------------------
    
    void test_fredkin_increment_age_1() {
	FredkinCell f1(true);
	f1.increment_age();
	CPPUNIT_ASSERT(f1.get_age() == 1);
    }
    
    void test_fredkin_increment_age_2() {
	FredkinCell f1(false);
	f1.increment_age();
	f1.increment_age();
	CPPUNIT_ASSERT(f1.get_age() == 2);
    }
    
    void test_fredkin_increment_age_3() {
	FredkinCell f1(true);
	f1.increment_age();
	f1.increment_age();
	f1.increment_age();
	f1.increment_age();
	CPPUNIT_ASSERT(f1.get_age() == 4);
    }
    
    // -------------------
    // FredkinCell::get_type()
    // -------------------

    void test_fredkin_get_type_1() {
	FredkinCell f1(true);
	CPPUNIT_ASSERT(f1.get_type() == 'f');
    }
    
    void test_fredkin_get_type_2() {
	FredkinCell f1(false);
	CPPUNIT_ASSERT(f1.get_type() == 'f');
    }
    
    void test_fredkin_get_type_3() {
	FredkinCell f1(true);
	FredkinCell f2(f1);
	CPPUNIT_ASSERT(f2.get_type() == 'f');
    }
    
    
    // ---------------------------------------
    // FredkinCell::equals(const AbstractCell&)
    // ---------------------------------------

    void test_fredkin_equals_1() {
	FredkinCell f1(true);
	FredkinCell f2(true);
	CPPUNIT_ASSERT(f1.equals(f2));
    }

    void test_fredkin_equals_2() {
	FredkinCell f1(true);
	FredkinCell f2(false);
	CPPUNIT_ASSERT(!f1.equals(f2));
    }

    void test_fredkin_equals_3() {
	FredkinCell f1(true);
	FredkinCell f2(&f1);
	CPPUNIT_ASSERT(f1.equals(f2));
    }
    
    // -------------------------------
    // ConwayCell::read(std::istream&)
    // -------------------------------

    void test_fredkin_read_1() {
	FredkinCell f(true);	
	CPPUNIT_ASSERT(f.get_state());
	CPPUNIT_ASSERT(f.get_age() == 0);
	std::istringstream r("false 5");
	f.read(r);
	CPPUNIT_ASSERT(!f.get_state());
	CPPUNIT_ASSERT(f.get_age() == 5);
    }
    
    void test_fredkin_read_2() {
	FredkinCell f(false);
	std::istringstream r("true 5");
	CPPUNIT_ASSERT(!f.get_state());
	CPPUNIT_ASSERT(f.get_age() == 0);
	f.read(r);
	CPPUNIT_ASSERT(f.get_state());
	CPPUNIT_ASSERT(f.get_age() == 5);
    }

    void test_fredkin_read_3() {
	FredkinCell f(true);
	std::istringstream r("true 5");
	CPPUNIT_ASSERT(f.get_state());
	CPPUNIT_ASSERT(f.get_age() == 0);
	f.read(r);
	CPPUNIT_ASSERT(f.get_state());
	CPPUNIT_ASSERT(f.get_age() == 5);
    }
    
    // --------------------------------
    // FredkinCell::write(std::ostream&)
    // --------------------------------

    void test_fredkin_write_1() {
	std::ostringstream w;
	FredkinCell f(true);
	std::istringstream r("true 10");
	f.read(r);
	f.write(w);
	CPPUNIT_ASSERT(w.str() == "+");
    }

    void test_fredkin_write_2() {
	std::ostringstream w;
	FredkinCell f(false);
	f.write(w);
	CPPUNIT_ASSERT(w.str() == "-");
    }

    void test_fredkin_write_3() {
	std::ostringstream w;
	FredkinCell f(true);
	std::istringstream r("true 5");
	f.read(r);
	f.write(w);
	CPPUNIT_ASSERT(w.str() == "5");
    }

    // --------------------------------
    // Life<T>::print_board()
    // --------------------------------
    void test_print_board_1() {
		std::istringstream in("1\n1\n.");
		Life<Cell> l(in, 'c');
		std::ostringstream w;
		l.print_board(w);
		CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 0\n.\n");
	}
	
	void test_print_board_2() {
		std::istringstream in("2\n2\n.*\n.*");
		Life<Cell> l(in, 'c');
		std::ostringstream w;
		l.print_board(w);
		CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 2\n.*\n.*\n");
	}
    
	void test_print_board_3() {
		std::istringstream in("3\n3\n0-0\n00-\n000");
		Life<FredkinCell> l(in, 'f');
		std::ostringstream w;
		l.print_board(w);
		CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 7\n0-0\n00-\n000\n");
	}
	
    // --------------------------------
    // Life<T>::Life(int, int)
    // --------------------------------

	void test_life_constructor_1() {
		std::istringstream in("1\n1\n.");
		Life<Cell> l(in, 'c');
		CPPUNIT_ASSERT(l._population == 0);
		std::ostringstream w;
		l.print_board(w);
		CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 0\n.\n");
	}

	void test_life_constructor_2() {
		std::istringstream in("2\n2\n.*\n.*");
		Life<Cell> l(in, 'c');
		CPPUNIT_ASSERT(l._population == 2);
		std::ostringstream w;
		l.print_board(w);
		CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 2\n.*\n.*\n");
	}
    
	void test_life_constructor_3() {
		std::istringstream in("3\n3\n0-0\n00-\n000");
		Life<FredkinCell> l(in, 'f');
		CPPUNIT_ASSERT(l._population == 7);
		std::ostringstream w;
		l.print_board(w);
		CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 7\n0-0\n00-\n000\n");
	}

	void test_life_constructor_4() {
		std::istringstream in("5\n5\n*...*\n.....\n*****\n.*.*.\n.*.*.");
		Life<ConwayCell> l(in, 's');
		CPPUNIT_ASSERT(l._population == 11);
		std::ostringstream w;
		l.print_board(w);
		CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 11\n*...*\n.....\n*****\n.*.*.\n.*.*.\n");
	}

	void test_life_constructor_5() {
		std::istringstream in("3\n3\n0*0\n.0-\n-*.");
		Life<Cell> l(in, 'c');	
		CPPUNIT_ASSERT(l._population == 5);
		std::ostringstream w;
		l.print_board(w);
		CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 5\n0*0\n.0-\n-*.\n");
	}
	
    // --------------------------------
    // Life<T>::set_neighbors()
    // --------------------------------
    
	void test_set_neighbors_1() {
		std::istringstream in("1\n1\n.");
		Life<Cell> l(in, 'c');
		CPPUNIT_ASSERT(l._neighbors[0][0] == 0);
	}

	void test_set_neighbors_2() {
		std::istringstream in("2\n2\n.*\n.*");
		Life<Cell> l(in, 'c');
		CPPUNIT_ASSERT(l._neighbors[0][0] == 2);
		CPPUNIT_ASSERT(l._neighbors[0][1] == 1);
		CPPUNIT_ASSERT(l._neighbors[1][0] == 2);
		CPPUNIT_ASSERT(l._neighbors[1][1] == 1);
	}

	void test_set_neighbors_3() {
		std::istringstream in("3\n4\n0-00\n00--\n000-");
		Life<FredkinCell> l(in, 'f');
		CPPUNIT_ASSERT(l._neighbors[0][0] == 1);
		CPPUNIT_ASSERT(l._neighbors[0][1] == 3);
		CPPUNIT_ASSERT(l._neighbors[0][2] == 1);
		CPPUNIT_ASSERT(l._neighbors[0][3] == 1);
		CPPUNIT_ASSERT(l._neighbors[1][0] == 3);
		CPPUNIT_ASSERT(l._neighbors[1][1] == 2);
		CPPUNIT_ASSERT(l._neighbors[1][2] == 3);
		CPPUNIT_ASSERT(l._neighbors[1][3] == 1);
		CPPUNIT_ASSERT(l._neighbors[2][0] == 2);
		CPPUNIT_ASSERT(l._neighbors[2][1] == 3);
		CPPUNIT_ASSERT(l._neighbors[2][2] == 1);
		CPPUNIT_ASSERT(l._neighbors[2][3] == 1);
	}
	
	// --------------------------------
	// Life::evolution(int, char)
	// --------------------------------

	void test_evolution_1() {
		std::istringstream in("1\n2\n00");
		Life<Cell> l(in, 'c');
		std::ostringstream w;
		l.evolution(1, 'c');
		l.print_board(w);
		CPPUNIT_ASSERT(w.str() == "Generation = 1, Population = 2\n11\n");
		l.evolution(1, 'c');
		w.str("");
		l.print_board(w);
		CPPUNIT_ASSERT(w.str() == "Generation = 2, Population = 2\n**\n");
		CPPUNIT_ASSERT(l._population == 2);
	} 
	
	void test_evolution_2() {
		std::istringstream in("3\n3\n0.0\n0*-\n***");
		Life<Cell> l(in, 'c');
		std::ostringstream w;
		l.evolution(2, 'c');
		l.print_board(w);
		CPPUNIT_ASSERT(w.str() == "Generation = 2, Population = 4\n**0\n-.1\n...\n");
		CPPUNIT_ASSERT(l._neighbors[0][0] == 1);
		CPPUNIT_ASSERT(l._neighbors[0][1] == 3);
		CPPUNIT_ASSERT(l._neighbors[0][2] == 2);
		CPPUNIT_ASSERT(l._neighbors[1][0] == 1);
		CPPUNIT_ASSERT(l._neighbors[1][1] == 4);
		CPPUNIT_ASSERT(l._neighbors[1][2] == 1);
		CPPUNIT_ASSERT(l._neighbors[2][0] == 0);
		CPPUNIT_ASSERT(l._neighbors[2][1] == 1);
		CPPUNIT_ASSERT(l._neighbors[2][2] == 1);
		l.evolution(1, 'c');
		w.str("");
		l.print_board(w);
		CPPUNIT_ASSERT(w.str() == "Generation = 3, Population = 3\n.*-\n1.*\n...\n");
		CPPUNIT_ASSERT(l._population == 3);
	} 
	
	void test_evolution_3() {
		std::istringstream in("4\n4\n....\n.**.\n.**.\n....");
		Life<ConwayCell> l(in, 'c');
		std::ostringstream w;
		l.evolution(10);
		l.print_board(w);
		CPPUNIT_ASSERT(w.str() == "Generation = 10, Population = 4\n....\n.**.\n.**.\n....\n");
		CPPUNIT_ASSERT(l._population == 4);
	} 
	
	void test_evolution_4() {
		std::istringstream in("6\n6\n000000\n000000\n000000\n000000\n000000\n000000\n");
		Life<FredkinCell> l(in, 'c');
		std::ostringstream w;
		l.evolution(50);
		l.print_board(w);
		CPPUNIT_ASSERT(w.str() == "Generation = 50, Population = 16\n-++++-\n+----+\n+----+\n+----+\n+----+\n-++++-\n");
		CPPUNIT_ASSERT(l._population == 16);
	} 

	void test_evolution_5() {
		std::istringstream in("7\n7\n.......\n...*...\n...*...\n...*...\n...*...\n...*...\n.......");
		Life<ConwayCell> l(in, 'c');
		std::ostringstream w;
		l.evolution(7);
		l.print_board(w);
		CPPUNIT_ASSERT(w.str() == "Generation = 7, Population = 8\n...*...\n...*...\n.......\n**...**\n.......\n...*...\n...*...\n");
		CPPUNIT_ASSERT(l._population == 8);
	} 

    // -----
    // Tests
    // -----

    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST(test_cell_constructor_1);
    CPPUNIT_TEST(test_cell_constructor_2);
    CPPUNIT_TEST(test_cell_constructor_3);
    CPPUNIT_TEST(test_cell_change_state_1);
    CPPUNIT_TEST(test_cell_change_state_2);  
    CPPUNIT_TEST(test_cell_change_state_3);
    CPPUNIT_TEST(test_cell_get_state_1);
    CPPUNIT_TEST(test_cell_get_state_2);  
    CPPUNIT_TEST(test_cell_get_state_3);
    CPPUNIT_TEST(test_cell_write_1);
    CPPUNIT_TEST(test_cell_write_2);
    CPPUNIT_TEST(test_cell_write_3);
    CPPUNIT_TEST(test_cell_read_1);
    CPPUNIT_TEST(test_cell_read_2);
    CPPUNIT_TEST(test_cell_read_3);
    CPPUNIT_TEST(test_cell_clone_1);
    CPPUNIT_TEST(test_cell_clone_2);
    CPPUNIT_TEST(test_cell_clone_3);     
    CPPUNIT_TEST(test_cell_increment_age_1);
    CPPUNIT_TEST(test_cell_increment_age_2);
    CPPUNIT_TEST(test_cell_increment_age_3);
    CPPUNIT_TEST(test_cell_get_type_1);
    CPPUNIT_TEST(test_cell_get_type_2);
    CPPUNIT_TEST(test_cell_get_type_3); 
    CPPUNIT_TEST(test_cell_get_age_1);
    CPPUNIT_TEST(test_cell_get_age_2);
    CPPUNIT_TEST(test_cell_get_age_3); 
    CPPUNIT_TEST(test_cell_mutate_1);
    CPPUNIT_TEST(test_cell_mutate_2);
    CPPUNIT_TEST(test_cell_mutate_3);       
    CPPUNIT_TEST(test_conway_default_constructor_1);
    CPPUNIT_TEST(test_conway_default_constructor_2);
    CPPUNIT_TEST(test_conway_default_constructor_3);
    CPPUNIT_TEST(test_conway_copy_constructor_1);
    CPPUNIT_TEST(test_conway_copy_constructor_2);
    CPPUNIT_TEST(test_conway_copy_constructor_3);
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
    CPPUNIT_TEST(test_conway_get_type_1);
    CPPUNIT_TEST(test_conway_get_type_2);
    CPPUNIT_TEST(test_conway_get_type_3);
    CPPUNIT_TEST(test_fredkin_default_constructor_1);
    CPPUNIT_TEST(test_fredkin_default_constructor_2);
    CPPUNIT_TEST(test_fredkin_default_constructor_3);
    CPPUNIT_TEST(test_fredkin_copy_constructor_1);
    CPPUNIT_TEST(test_fredkin_copy_constructor_2);
    CPPUNIT_TEST(test_fredkin_copy_constructor_3);
    CPPUNIT_TEST(test_fredkin_clone_1);
    CPPUNIT_TEST(test_fredkin_clone_2);
    CPPUNIT_TEST(test_fredkin_clone_3);
    CPPUNIT_TEST(test_fredkin_get_age_1);
    CPPUNIT_TEST(test_fredkin_get_age_2);
    CPPUNIT_TEST(test_fredkin_get_age_3);
    CPPUNIT_TEST(test_fredkin_get_type_1);
    CPPUNIT_TEST(test_fredkin_get_type_2);
    CPPUNIT_TEST(test_fredkin_get_type_3);
    CPPUNIT_TEST(test_fredkin_increment_age_1);
    CPPUNIT_TEST(test_fredkin_increment_age_2);
    CPPUNIT_TEST(test_fredkin_increment_age_3);
    CPPUNIT_TEST(test_fredkin_equals_1);
    CPPUNIT_TEST(test_fredkin_equals_2);
    CPPUNIT_TEST(test_fredkin_equals_3);
    CPPUNIT_TEST(test_fredkin_read_1);
    CPPUNIT_TEST(test_fredkin_read_2);
    CPPUNIT_TEST(test_fredkin_read_3);
    CPPUNIT_TEST(test_fredkin_write_1);
    CPPUNIT_TEST(test_fredkin_write_2);
    CPPUNIT_TEST(test_fredkin_write_3);
    CPPUNIT_TEST(test_print_board_1);
    CPPUNIT_TEST(test_print_board_2);
    CPPUNIT_TEST(test_print_board_3);
    CPPUNIT_TEST(test_life_constructor_1);
    CPPUNIT_TEST(test_life_constructor_2);
    CPPUNIT_TEST(test_life_constructor_3);
    CPPUNIT_TEST(test_life_constructor_4);
    CPPUNIT_TEST(test_life_constructor_5);
    CPPUNIT_TEST(test_set_neighbors_1);
    CPPUNIT_TEST(test_set_neighbors_2);
    CPPUNIT_TEST(test_set_neighbors_3);
    CPPUNIT_TEST(test_evolution_1);
    CPPUNIT_TEST(test_evolution_2);
    CPPUNIT_TEST(test_evolution_3);
    CPPUNIT_TEST(test_evolution_4);
    CPPUNIT_TEST(test_evolution_5);
    CPPUNIT_TEST_SUITE_END();

};

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout << "TestLife.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestLife::suite());
    tr.run();
}
