#include <sstream>
#include <vector>
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#define private public
#define protected public
//#define class struct

#include "Life.h"

using namespace std;

struct TestLife : CppUnit::TestFixture {


	void test_conway_constructor_1() {
		ConwayCell conway = ConwayCell('.');
		CPPUNIT_ASSERT(!conway.isAlive());

		CPPUNIT_ASSERT(conway == '.');

	}

	void test_conway_constructor_2() {
		ConwayCell conway = ConwayCell('*');

		CPPUNIT_ASSERT(conway.isAlive());

		CPPUNIT_ASSERT(conway == '*');
	}

	void test_conway_constructor_3() {

		ConwayCell conway = ConwayCell('.');

		CPPUNIT_ASSERT(conway == '.');

		CPPUNIT_ASSERT(!conway.isAlive());
	}

	void test_conway_donext_1() {
	
		ConwayCell conway = ConwayCell('*');
		conway.doNext(3, 3);
		
		CPPUNIT_ASSERT(conway.futureAlive == false);
	
	}

	void test_conway_donext_2() {
		ConwayCell conway = ConwayCell('*');
		conway.doNext(2, 0);
		
		CPPUNIT_ASSERT(conway.futureAlive == true);
	}

	void test_conway_donext_3() {
		ConwayCell conway = ConwayCell('.');
		conway.doNext(2, 1);

		
		CPPUNIT_ASSERT(conway.futureAlive == true);
	}

	void test_conway_finalize_1() {
		ConwayCell conway = ConwayCell('.');
		conway.doNext(2, 0);
		CellDesire desire = conway.finalize();

		CPPUNIT_ASSERT(desire == NONE);
		CPPUNIT_ASSERT(!conway.isAlive());
		CPPUNIT_ASSERT(conway == '.');
	}

	
	void test_conway_finalize_2() {
		ConwayCell conway = ConwayCell('.');
		conway.doNext(3, 0);
		CellDesire desire = conway.finalize();
	
		CPPUNIT_ASSERT(desire == NONE);
		CPPUNIT_ASSERT(conway.isAlive());
		CPPUNIT_ASSERT(conway == '*');
	}

	void test_conway_finalize_3() {
		ConwayCell conway = ConwayCell('*');
		conway.doNext(1, 0);
		CellDesire desire = conway.finalize();

		
		CPPUNIT_ASSERT(desire == NONE);
		CPPUNIT_ASSERT(!conway.isAlive());
		CPPUNIT_ASSERT(conway == '.');
	}

	void test_fredkin_constructor_1() {
		FredkinCell fredkin = FredkinCell('-');

		CPPUNIT_ASSERT(fredkin == '-');
		CPPUNIT_ASSERT(!fredkin.isAlive());
		CPPUNIT_ASSERT(fredkin.age == 0);
	}

	void test_fredkin_constructor_2() {
		FredkinCell fredkin = FredkinCell('0');

		CPPUNIT_ASSERT(fredkin == '0');
		CPPUNIT_ASSERT(fredkin.isAlive());
		CPPUNIT_ASSERT(fredkin.age == 0);
	}
	
	void test_fredkin_constructor_3() {
		FredkinCell fredkin = FredkinCell('2');
		
		CPPUNIT_ASSERT(fredkin.isAlive());
		CPPUNIT_ASSERT(fredkin.age == 2);
	}

	void test_fredkin_donext_1() {
		FredkinCell fredkin = FredkinCell('0');

		fredkin.doNext(2, 100);
		CPPUNIT_ASSERT(fredkin.age         == 0);
		CPPUNIT_ASSERT(fredkin.futureAlive == false);
		CPPUNIT_ASSERT(fredkin == '0');


	}

	void test_fredkin_donext_2() {

		FredkinCell fredkin = FredkinCell('-');

		fredkin.doNext(3, 0);
		CPPUNIT_ASSERT(fredkin.futureAlive == true);
		CPPUNIT_ASSERT(fredkin.age         == 0);
	
	}

	void test_fredkin_donext_3() {

		FredkinCell fredkin = FredkinCell('0');
	
		fredkin.doNext(1, 0);

		CPPUNIT_ASSERT(fredkin.futureAlive == true);
		CPPUNIT_ASSERT(fredkin.age         == 0);
	}

	void test_fredkin_finalize_1() {
		FredkinCell fredkin = FredkinCell('0');
		
		fredkin.doNext(1, 0);
		CPPUNIT_ASSERT(fredkin.futureAlive == true);
		CellDesire desire = fredkin.finalize();
		CPPUNIT_ASSERT(desire == NONE);
		CPPUNIT_ASSERT(fredkin.age == 1);
		CPPUNIT_ASSERT(fredkin == '1');
	}

	void test_fredkin_finalize_2() {

		FredkinCell fredkin = FredkinCell('1');
		fredkin.doNext(3, 44);
		CellDesire desire = fredkin.finalize();
		CPPUNIT_ASSERT(desire == CONWAY);
		CPPUNIT_ASSERT(fredkin.age == 2);
		CPPUNIT_ASSERT(fredkin == '2');

	}

	void test_fredkin_finalize_3() {

		FredkinCell fredkin = FredkinCell('-');
		fredkin.doNext(1, 44);
		CellDesire desire = fredkin.finalize();
		CPPUNIT_ASSERT(desire == NONE);
		CPPUNIT_ASSERT(fredkin.age == 0);
		CPPUNIT_ASSERT(fredkin.isAlive());

	}

	void test_cell_constructor_1() {
		Cell cell = Cell('.');
		
		CPPUNIT_ASSERT(cell == '.');
		CPPUNIT_ASSERT(!cell.isAlive());
	}

	void test_cell_constructor_2() {
		Cell cell = Cell('0');
		
		CPPUNIT_ASSERT(cell.isAlive());
	}

	void test_cell_constructor_3() {
		Cell cell = Cell('*');

		CPPUNIT_ASSERT(cell.isAlive());
		CPPUNIT_ASSERT(cell == '*');
	}

	void test_cell_donext_1() {
		Cell cell = Cell('0');

		cell.doNext(2, 0);
		CPPUNIT_ASSERT(cell.isAlive());

	}

	void test_cell_donext_2() {
		Cell cell = Cell('.');

		cell.doNext(2, 1);
		CPPUNIT_ASSERT(!cell.isAlive());
	}

	void test_cell_donext_3() {
		Cell cell = Cell('1');

		cell.doNext(3, 3);
		CPPUNIT_ASSERT(cell.isAlive());
	}
 
	void test_cell_finalize_1() {
		Cell cell = Cell('.');
		cell.doNext(2, 1);
		cell.finalize();
		CPPUNIT_ASSERT(cell.isAlive());
		CPPUNIT_ASSERT(cell == '*');
	}

	void test_cell_finalize_2() {
		Cell cell = Cell('0');
		cell.doNext(1, 0);
		cell.finalize();
		CPPUNIT_ASSERT(cell == '1');
	}

	void test_cell_finalize_3() {
		Cell cell  = Cell('1');
		cell.doNext(3, 999);
		cell.finalize();
		CPPUNIT_ASSERT(cell == '*');
		CPPUNIT_ASSERT(cell.isAlive());
	}

	void test_clone_1() {
		ConwayCell conway = ConwayCell('*');
		AbstractCell* p = conway.clone();

		CPPUNIT_ASSERT(p->isAlive());
		CPPUNIT_ASSERT(*p == '*');
	}

	void test_clone_2() {
		FredkinCell fredkin = FredkinCell('0');
		AbstractCell* p = fredkin.clone();
		
		CPPUNIT_ASSERT(p->isAlive());
		CPPUNIT_ASSERT(*p == '0');
	}

	void test_clone_3() {
		FredkinCell fredkin = FredkinCell('-');
		AbstractCell* p = fredkin.clone();

		CPPUNIT_ASSERT(!p->isAlive());
		CPPUNIT_ASSERT(*p == '-');
	}

	void test_life_pop_1() {
	    istringstream r("5\n5\n.....\n..*..\n..*..\n..*..\n.....\n");
	
		Life<ConwayCell> lc(r);

		CPPUNIT_ASSERT(lc.population() == 3);
	}

	void test_life_pop_2() {

		istringstream r("3\n3\n...\n...\n...\n");
		
		Life<ConwayCell> lc(r);

		CPPUNIT_ASSERT(lc.population() == 0);

	}

	void test_life_pop_3() {

		istringstream r("3\n3\n---\n012\n---\n");
	
		Life<FredkinCell> fc(r);

		CPPUNIT_ASSERT(fc.population() == 3);

	}

	void test_life_angle_1() {
		istringstream r("1\n1\n*\n");

		Life<ConwayCell> lc(r);

		CPPUNIT_ASSERT(lc.countAngleNeighbors(0,0) == 0);
	}

	void test_life_angle_2() {
		istringstream r("3\n3\n.*.\n.*.\n...\n");

		Life<ConwayCell> lc(r);

		CPPUNIT_ASSERT(lc.countAngleNeighbors(0,0) == 1);
		CPPUNIT_ASSERT(lc.countAngleNeighbors(1,1) == 0);
		CPPUNIT_ASSERT(lc.countAngleNeighbors(2,0) == 1);
	}

	void test_life_angle_3() {

		istringstream r("3\n3\n000\n000\n000\n");

		Life<FredkinCell> lf(r);
		
		CPPUNIT_ASSERT(lf.countAngleNeighbors(1,1) == 4);
		CPPUNIT_ASSERT(lf.countAngleNeighbors(0,0) == 1);
		CPPUNIT_ASSERT(lf.countAngleNeighbors(1,0) == 2);
	
	}

	void test_life_direct_1() {
		
		istringstream r("3\n3\n.*.\n.*.\n...");

		Life<ConwayCell> lc(r);

		CPPUNIT_ASSERT(lc.countDirectNeighbors(2,2) == 0);
		CPPUNIT_ASSERT(lc.countDirectNeighbors(0,0) == 1);
		CPPUNIT_ASSERT(lc.countDirectNeighbors(1,1) == 1);
	}

	void test_life_direct_2() {

		istringstream r("3\n3\n000\n000\n00-");

		Life<FredkinCell> lc(r);

		CPPUNIT_ASSERT(lc.countDirectNeighbors(1, 1) == 4);
		CPPUNIT_ASSERT(lc.countDirectNeighbors(2, 1) == 2);
	}

	void test_life_direct_3() {
	
		istringstream r("1\n1\n.");

		Life<Cell> lc(r);

		CPPUNIT_ASSERT(lc.countDirectNeighbors(0,0) == 0);
	}


	void test_life_move_1(){
		istringstream in("5\n7\n.......\n..***..\n..***..\n..***..\n.......\n");
		Life<ConwayCell> l(in);
		CPPUNIT_ASSERT(l.population() == 9);
		l.move();
		CPPUNIT_ASSERT(l.population() == 8);
	}

	void test_life_move_2(){
		istringstream in("5\n7\n-------\n--000--\n--000--\n--000--\n-------\n");
		Life<FredkinCell> l(in);
		CPPUNIT_ASSERT(l.population() == 9);
		l.move();
		CPPUNIT_ASSERT(l.population() == 16);
	}

	void test_life_move_3(){
		std::istringstream in("5\n7\n.......\n--000--\n..***..\n--000--\n.......\n");
		Life<Cell> l(in);
		CPPUNIT_ASSERT(l.population() == 9);
		l.move();
		CPPUNIT_ASSERT(l.population() == 10);
	}





    CPPUNIT_TEST_SUITE(TestLife);

	CPPUNIT_TEST(test_conway_constructor_1);
	CPPUNIT_TEST(test_conway_constructor_2);
	CPPUNIT_TEST(test_conway_constructor_3);   
	CPPUNIT_TEST(test_conway_donext_1);
	CPPUNIT_TEST(test_conway_donext_2);
	CPPUNIT_TEST(test_conway_donext_3);
	CPPUNIT_TEST(test_conway_finalize_1);
	CPPUNIT_TEST(test_conway_finalize_2);
	CPPUNIT_TEST(test_conway_finalize_3);
	CPPUNIT_TEST(test_fredkin_constructor_1);
	CPPUNIT_TEST(test_fredkin_constructor_2);
	CPPUNIT_TEST(test_fredkin_constructor_3);
	CPPUNIT_TEST(test_fredkin_donext_1);
	CPPUNIT_TEST(test_fredkin_donext_2);
	CPPUNIT_TEST(test_fredkin_donext_3);
	CPPUNIT_TEST(test_fredkin_finalize_1);
	CPPUNIT_TEST(test_fredkin_finalize_2);
	CPPUNIT_TEST(test_fredkin_finalize_3);
	CPPUNIT_TEST(test_cell_constructor_1);
	CPPUNIT_TEST(test_cell_constructor_2);
	CPPUNIT_TEST(test_cell_constructor_3);
	CPPUNIT_TEST(test_cell_donext_1);
	CPPUNIT_TEST(test_cell_donext_2);
	CPPUNIT_TEST(test_cell_donext_3);
	CPPUNIT_TEST(test_cell_finalize_1);
	CPPUNIT_TEST(test_cell_finalize_2);
	CPPUNIT_TEST(test_cell_finalize_3);

	CPPUNIT_TEST(test_clone_1);
	CPPUNIT_TEST(test_clone_2);
	CPPUNIT_TEST(test_clone_3);

	CPPUNIT_TEST(test_life_pop_1);
	CPPUNIT_TEST(test_life_pop_2);
	CPPUNIT_TEST(test_life_pop_3);
	CPPUNIT_TEST(test_life_angle_1);
	CPPUNIT_TEST(test_life_angle_2);
	CPPUNIT_TEST(test_life_angle_3);
	CPPUNIT_TEST(test_life_direct_1);
	CPPUNIT_TEST(test_life_direct_2);
	CPPUNIT_TEST(test_life_direct_3);
	CPPUNIT_TEST(test_life_move_1);
	CPPUNIT_TEST(test_life_move_2);
	CPPUNIT_TEST(test_life_move_3);	

 
    CPPUNIT_TEST_SUITE_END();
};

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout << "TestLife.c++" << endl;
    
    CppUnit::TextTestRunner tr;
    tr.addTest(TestLife::suite());
    tr.run();
   
    cout << "Done." << endl;
    return 0;
}
