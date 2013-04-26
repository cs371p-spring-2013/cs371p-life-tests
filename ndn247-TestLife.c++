
// --------
// includes
// --------

#define private public
#define protected public

#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <fstream>   // ifstream
#include <sstream>   // istringstream
#include <string>    
#include <stdexcept> // invalid_argument, out_of_range
#include <utility>   // std::pair, std::make_pair
#include <map>   

#include "Life.h"
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

using namespace std;

struct TestLife : CppUnit::TestFixture {
	void test_ConwayIsAlive_1(){
		ConwayCell test(false);
		CPPUNIT_ASSERT(test.is_alive() == false);
	}

	void test_ConwayIsAlive_2(){	
		ConwayCell test(true);
		CPPUNIT_ASSERT(test.is_alive() == true);
	}

	void test_Conway_CountNumNeighbors_1(){
		ConwayCell test(true);
		ConwayCell Alive(true);
		ConwayCell Dead(false);
		test._neighbors.push_back(&Alive);
		test._neighbors.push_back(&Alive);
		test._neighbors.push_back(&Dead);
		test._neighbors.push_back(&Alive);
		test._neighbors.push_back(&Dead);
		test._neighbors.push_back(&Dead);
		test.count_num_neighbors_alive();
		CPPUNIT_ASSERT(test._num_neighbors_alive == 3);
	}

	void test_Conway_CountNumNeighbors_2(){
		ConwayCell test(false);
		CPPUNIT_ASSERT(test._num_neighbors_alive == 0);	
	}

	void test_Conway_CountNumNeighbors_3(){
		ConwayCell test(false);

		ConwayCell Alive(true);
		ConwayCell Dead(false);

		test._neighbors.push_back(&Alive);
		test._neighbors.push_back(&Alive);
		test._neighbors.push_back(&Dead);
		test._neighbors.push_back(&Alive);
		test._neighbors.push_back(&Dead);
		test._neighbors.push_back(&Dead);
		test.count_num_neighbors_alive();
		CPPUNIT_ASSERT(test._num_neighbors_alive == 3);

		test._neighbors.push_back(&Alive);
		test._neighbors.push_back(&Alive);
		test._neighbors.push_back(&Dead);
		test._neighbors.push_back(&Alive);
		test._neighbors.push_back(&Dead);
		test._neighbors.push_back(&Dead);
		test.count_num_neighbors_alive();
		CPPUNIT_ASSERT(test._num_neighbors_alive == 6);
	}
	
	void test_Conway_Evolve_1(){
		ConwayCell test(false);
		CPPUNIT_ASSERT(test._is_alive == false);
		test._num_neighbors_alive = 2;
		test.evolve();
		CPPUNIT_ASSERT(test._is_alive == false);
		CPPUNIT_ASSERT(test._display == '.');
		
	}
	
	void test_Conway_Evolve_2(){
		ConwayCell test(false);
		CPPUNIT_ASSERT(test._is_alive == false);
		test._num_neighbors_alive = 3;
		test.evolve();
		CPPUNIT_ASSERT(test._is_alive == true);
		CPPUNIT_ASSERT(test._display == '*');
	}

	void test_Conway_Evolve_3(){
		ConwayCell test(true);
		CPPUNIT_ASSERT(test._is_alive == true);
		CPPUNIT_ASSERT(test._display == '*');
		test._num_neighbors_alive = 1;
		test.evolve();
		CPPUNIT_ASSERT(test._is_alive == false);
		CPPUNIT_ASSERT(test._display == '.');
	}
	
	void test_Conway_Set_Neighbors_1(){
		ConwayCell test(false);
		ConwayCell Alive(true);
		ConwayCell Dead(false);
		vector<AbstractCell*> NSEW;	
		vector<AbstractCell*> diagonals;
		NSEW.push_back(&Alive);
		NSEW.push_back(&Alive);
		NSEW.push_back(&Dead);
		NSEW.push_back(&Dead);
		diagonals.push_back(&Dead);
		diagonals.push_back(&Alive);
		diagonals.push_back(&Alive);
		diagonals.push_back(&Dead);
		test.set_neighbors(NSEW, diagonals);
		CPPUNIT_ASSERT(test._neighbors.size() == 8);
		CPPUNIT_ASSERT(&Alive == test._neighbors[0]);	
	}

	void test_Conway_Set_Neighbors_2(){
		ConwayCell test(false);
		ConwayCell Alive(true);
		ConwayCell Dead(false);
		vector<ConwayCell*> NSEW;	
		vector<ConwayCell*> diagonals;
		NSEW.push_back(&Alive);
		NSEW.push_back(&Alive);
		NSEW.push_back(&Dead);
		NSEW.push_back(&Dead);
		diagonals.push_back(&Dead);
		diagonals.push_back(&Alive);
		diagonals.push_back(&Alive);
		diagonals.push_back(&Dead);
		test.set_neighbors(NSEW, diagonals);
		CPPUNIT_ASSERT(test._neighbors.size() == 8);
		CPPUNIT_ASSERT(&Alive == test._neighbors[0]);	
	}

	void test_Conway_Set_Neighbors_3(){	
		ConwayCell test(false);
		vector<ConwayCell*> NSEW;	
		vector<ConwayCell*> diagonals;
		test.set_neighbors(NSEW, diagonals);
		CPPUNIT_ASSERT(test._neighbors.size() == 0);
	}

	void test_Conway_Count_Neighbors_1(){
		ConwayCell test(false);
		ConwayCell Alive(true);
		ConwayCell Dead(false);
		vector<AbstractCell*> NSEW;	
		vector<AbstractCell*> diagonals;
		NSEW.push_back(&Alive);
		NSEW.push_back(&Alive);
		NSEW.push_back(&Dead);
		NSEW.push_back(&Dead);
		diagonals.push_back(&Dead);
		diagonals.push_back(&Alive);
		diagonals.push_back(&Alive);
		diagonals.push_back(&Dead);
		test.set_neighbors(NSEW, diagonals);
		test.count_num_neighbors_alive();
		CPPUNIT_ASSERT(test._num_neighbors_alive == 4);
	}

	void test_Conway_Count_Neighbors_2(){
		ConwayCell test(false);
		ConwayCell Alive(true);
		ConwayCell Dead(false);
		vector<AbstractCell*> NSEW;	
		vector<AbstractCell*> diagonals;
		NSEW.push_back(&Alive);
		NSEW.push_back(&Alive);
		NSEW.push_back(&Dead);
		NSEW.push_back(&Dead);
		diagonals.push_back(&Alive);
		diagonals.push_back(&Alive);
		diagonals.push_back(&Alive);
		diagonals.push_back(&Alive);
		test.set_neighbors(NSEW, diagonals);
		test.count_num_neighbors_alive();
		CPPUNIT_ASSERT(test._num_neighbors_alive == 6);
	}

	void test_Conway_Count_Neighbors_3(){
		ConwayCell test(false);
		vector<ConwayCell*> NSEW;	
		vector<ConwayCell*> diagonals;
		test.set_neighbors(NSEW, diagonals);
		test.count_num_neighbors_alive();
		CPPUNIT_ASSERT(test._num_neighbors_alive == 0);
	}

	void test_Conway_die_1(){
		ConwayCell test(true);
		CPPUNIT_ASSERT(test._display == '*');
		CPPUNIT_ASSERT(test._is_alive == true);
		test.die();
		CPPUNIT_ASSERT(test._display == '.');
		CPPUNIT_ASSERT(test._is_alive == false);
	}
	void test_Conway_die_2(){
		ConwayCell test(false);
		CPPUNIT_ASSERT(test._display == '.');
		CPPUNIT_ASSERT(test._is_alive == false);
		test.die();
		CPPUNIT_ASSERT(test._display == '.');
		CPPUNIT_ASSERT(test._is_alive == false);
	}
	void test_Conway_die_3(){
		ConwayCell test(true);
		test.die();
		CPPUNIT_ASSERT(test._display == '.');
		CPPUNIT_ASSERT(test._is_alive == false);
	}
	void test_Conway_resurrect_1(){
		ConwayCell test(true);
		CPPUNIT_ASSERT(test._display == '*');
		CPPUNIT_ASSERT(test._is_alive == true);
		test.resurrect();
		CPPUNIT_ASSERT(test._display == '*');
		CPPUNIT_ASSERT(test._is_alive == true);
	}
	void test_Conway_resurrect_2(){
		ConwayCell test(false);
		CPPUNIT_ASSERT(test._display == '.');
		CPPUNIT_ASSERT(test._is_alive == false);
		test.resurrect();
		CPPUNIT_ASSERT(test._display == '*');
		CPPUNIT_ASSERT(test._is_alive == true);
	}
	void test_Conway_resurrect_3(){
		ConwayCell test(false);	
		test.resurrect();
		CPPUNIT_ASSERT(test._display == '*');
		CPPUNIT_ASSERT(test._is_alive == true);
	}
	void test_FredkinIsAlive_1(){
		FredkinCell test(false);
		CPPUNIT_ASSERT(test.is_alive() == false);
	}

	void test_FredkinIsAlive_2(){	
		FredkinCell test(true);
		CPPUNIT_ASSERT(test.is_alive() == true);
	}

	void test_Fredkin_CountNumNeighbors_1(){
		FredkinCell test(true);
		FredkinCell Alive(true);
		FredkinCell Dead(false);
		test._neighbors.push_back(&Alive);
		test._neighbors.push_back(&Alive);
		test._neighbors.push_back(&Dead);
		test._neighbors.push_back(&Alive);
		test._neighbors.push_back(&Dead);
		test._neighbors.push_back(&Dead);
		test.count_num_neighbors_alive();
		CPPUNIT_ASSERT(test._num_neighbors_alive == 3);
	}

	void test_Fredkin_CountNumNeighbors_2(){
		FredkinCell test(true);
		CPPUNIT_ASSERT(test._num_neighbors_alive == 0);	
	}

	void test_Fredkin_CountNumNeighbors_3(){
		FredkinCell test(true);

		FredkinCell Alive(true);
		FredkinCell Dead(false);

		test._neighbors.push_back(&Alive);
		test._neighbors.push_back(&Alive);
		test._neighbors.push_back(&Dead);
		test._neighbors.push_back(&Alive);
		test._neighbors.push_back(&Dead);
		test._neighbors.push_back(&Dead);
		test.count_num_neighbors_alive();
		CPPUNIT_ASSERT(test._num_neighbors_alive == 3);

		test._neighbors.push_back(&Alive);
		test._neighbors.push_back(&Alive);
		test._neighbors.push_back(&Dead);
		test._neighbors.push_back(&Alive);
		test._neighbors.push_back(&Dead);
		test._neighbors.push_back(&Dead);
		test.count_num_neighbors_alive();
		CPPUNIT_ASSERT(test._num_neighbors_alive == 6);
	}
	
	void test_Fredkin_Evolve_1(){
		FredkinCell test(false);
		CPPUNIT_ASSERT(test._is_alive == false);
		test._num_neighbors_alive = 1;
		test.evolve();
		CPPUNIT_ASSERT(test._is_alive == true);
		CPPUNIT_ASSERT(test._display == '0');
		
	}
	
	void test_Fredkin_Evolve_2(){
		FredkinCell test(false);
		CPPUNIT_ASSERT(test._is_alive == false);
		test._num_neighbors_alive = 3;
		test._age = 10;
		test.evolve();
		CPPUNIT_ASSERT(test._is_alive == true);
		CPPUNIT_ASSERT(test._display == '+');
	}

	void test_Fredkin_Evolve_3(){
		FredkinCell test(true);
		CPPUNIT_ASSERT(test._is_alive == true);
		CPPUNIT_ASSERT(test._display == '0');
		test._num_neighbors_alive = 1;
		test._age = 1;
		test.evolve();
		CPPUNIT_ASSERT(test._is_alive == true);
		CPPUNIT_ASSERT(test._display == '2');
	}
	
	void test_Fredkin_Set_Neighbors_1(){
		FredkinCell test(false);
		FredkinCell Alive(true);
		FredkinCell Dead(false);
		vector<AbstractCell*> NSEW;	
		vector<AbstractCell*> diagonals;
		NSEW.push_back(&Alive);
		NSEW.push_back(&Alive);
		NSEW.push_back(&Dead);
		NSEW.push_back(&Dead);
		diagonals.push_back(&Dead);
		diagonals.push_back(&Alive);
		diagonals.push_back(&Alive);
		diagonals.push_back(&Dead);
		test.set_neighbors(NSEW, diagonals);
		CPPUNIT_ASSERT(test._neighbors.size() == 4);
		CPPUNIT_ASSERT(&Alive == test._neighbors[0]);	
	}

	void test_Fredkin_Set_Neighbors_2(){
		FredkinCell test(false);
		FredkinCell Alive(true);
		FredkinCell Dead(false);
		vector<FredkinCell*> NSEW;	
		vector<FredkinCell*> diagonals;
		NSEW.push_back(&Alive);
		NSEW.push_back(&Alive);
		NSEW.push_back(&Dead);
		NSEW.push_back(&Dead);
		diagonals.push_back(&Dead);
		diagonals.push_back(&Alive);
		diagonals.push_back(&Alive);
		diagonals.push_back(&Dead);
		test.set_neighbors(NSEW, diagonals);
		CPPUNIT_ASSERT(test._neighbors.size() == 4);
		CPPUNIT_ASSERT(&Alive == test._neighbors[0]);	
	}

	void test_Fredkin_Set_Neighbors_3(){	
		FredkinCell test(false);
		FredkinCell Alive(true);
		FredkinCell Dead(false);
		vector<FredkinCell*> NSEW;	
		vector<FredkinCell*> diagonals;
		diagonals.push_back(&Dead);
		diagonals.push_back(&Alive);
		diagonals.push_back(&Alive);
		diagonals.push_back(&Dead);
		test.set_neighbors(NSEW, diagonals);
		CPPUNIT_ASSERT(test._neighbors.size() == 0);
	}

	void test_Fredkin_Count_Neighbors_1(){
		FredkinCell test(false);
		FredkinCell Alive(true);
		FredkinCell Dead(false);
		vector<AbstractCell*> NSEW;	
		vector<AbstractCell*> diagonals;
		NSEW.push_back(&Alive);
		NSEW.push_back(&Alive);
		NSEW.push_back(&Dead);
		NSEW.push_back(&Dead);
		diagonals.push_back(&Dead);
		diagonals.push_back(&Alive);
		diagonals.push_back(&Alive);
		diagonals.push_back(&Dead);
		test.set_neighbors(NSEW, diagonals);
		test.count_num_neighbors_alive();
		CPPUNIT_ASSERT(test._num_neighbors_alive == 2);
	}

	void test_Fredkin_Count_Neighbors_2(){
		FredkinCell test(false);
		FredkinCell Alive(true);
		FredkinCell Dead(false);
		vector<AbstractCell*> NSEW;	
		vector<AbstractCell*> diagonals;
		NSEW.push_back(&Alive);
		NSEW.push_back(&Dead);
		NSEW.push_back(&Dead);
		NSEW.push_back(&Dead);
		diagonals.push_back(&Alive);
		diagonals.push_back(&Alive);
		diagonals.push_back(&Alive);
		diagonals.push_back(&Alive);
		test.set_neighbors(NSEW, diagonals);
		test.count_num_neighbors_alive();
		CPPUNIT_ASSERT(test._num_neighbors_alive == 1);
	}

	void test_Fredkin_Count_Neighbors_3(){
		FredkinCell test(false);
		vector<FredkinCell*> NSEW;	
		vector<FredkinCell*> diagonals;
		test.set_neighbors(NSEW, diagonals);
		test.count_num_neighbors_alive();
		CPPUNIT_ASSERT(test._num_neighbors_alive == 0);
	}

	void test_Fredkin_die_1(){
		FredkinCell test(true);
		CPPUNIT_ASSERT(test._display == '0');
		CPPUNIT_ASSERT(test._is_alive == true);
		test.die();
		CPPUNIT_ASSERT(test._display == '-');
		CPPUNIT_ASSERT(test._is_alive == false);
	}
	void test_Fredkin_die_2(){
		FredkinCell test(false);
		CPPUNIT_ASSERT(test._display == '-');
		CPPUNIT_ASSERT(test._is_alive == false);
		test.die();
		CPPUNIT_ASSERT(test._display == '-');
		CPPUNIT_ASSERT(test._is_alive == false);
	}
	void test_Fredkin_die_3(){
		FredkinCell test(true);
		test.die();
		CPPUNIT_ASSERT(test._display == '-');
		CPPUNIT_ASSERT(test._is_alive == false);
	}
	void test_Fredkin_resurrect_1(){
		FredkinCell test(true);
		CPPUNIT_ASSERT(test._display == '0');
		CPPUNIT_ASSERT(test._is_alive == true);
		test.resurrect();
		CPPUNIT_ASSERT(test._display == '0');
		CPPUNIT_ASSERT(test._is_alive == true);
	}
	void test_Fredkin_resurrect_2(){
		FredkinCell test(false);
		test._age = 1;
		CPPUNIT_ASSERT(test._display == '-');
		CPPUNIT_ASSERT(test._is_alive == false);
		test.resurrect();
		CPPUNIT_ASSERT(test._display == '1');
		CPPUNIT_ASSERT(test._is_alive == true);
	}
	void test_Fredkin_resurrect_3(){
		FredkinCell test(false);
		test._age = 10;
		test.resurrect();
		CPPUNIT_ASSERT(test._display == '+');
		CPPUNIT_ASSERT(test._is_alive == true);
	}

	void test_Fredkin_live_1(){
		FredkinCell test(true);
		test.live();
		CPPUNIT_ASSERT(test._display == '1');
		CPPUNIT_ASSERT(test._is_alive == true);
	}
	void test_Fredkin_live_2(){
		FredkinCell test(true);
		test._age = 9;
		test._is_alive = true;
		test.live();
		CPPUNIT_ASSERT(test._display == '+');
		CPPUNIT_ASSERT(test._is_alive == true);		
	}
	void test_Fredkin_live_3(){
		FredkinCell test(true);
		test._age = 100;
		test.live();
		CPPUNIT_ASSERT(test._display == '+');
	}
	
	void test_Cell_evolve_1(){
		Cell test = new ConwayCell(true);
		test.get()->_num_neighbors_alive = 2;
		test.evolve();
		CPPUNIT_ASSERT(test.get()->_display == '*');
		CPPUNIT_ASSERT(test.get()->_mutated == false);
	}

	void test_Cell_evolve_2(){
		Cell test = new FredkinCell(true);
		FredkinCell& c = *dynamic_cast<FredkinCell*>(test.get());
		c._age = 1;
		test.get()->_num_neighbors_alive = 4;
		test.evolve();
		CPPUNIT_ASSERT(test.get()->_display == '-');
		CPPUNIT_ASSERT(test.get()->_mutated == false);
	}

	void test_Cell_evolve_3(){
		Cell test = new FredkinCell(true);
		FredkinCell& c = *dynamic_cast<FredkinCell*>(test.get());
		c._age = 1;
		test.get()->_num_neighbors_alive = 3;
		test.evolve();
		CPPUNIT_ASSERT(test.get()->_display == '*');
		CPPUNIT_ASSERT(test.get()->_mutated == true);		
	}
	
	void test_Cell_set_neighbors_1(){
		Cell test = new ConwayCell(false);
		Cell Alive = new ConwayCell(true);
		Cell Dead = new ConwayCell(false);
		vector<Cell*> NSEW;	
		vector<Cell*> diagonals;
		NSEW.push_back(&Alive);
		NSEW.push_back(&Alive);
		NSEW.push_back(&Dead);
		diagonals.push_back(&Dead);
		diagonals.push_back(&Alive);
		diagonals.push_back(&Alive);
		diagonals.push_back(&Dead);
		test.set_neighbors(NSEW, diagonals);
		CPPUNIT_ASSERT(test._NSEW.size() == 3);
		CPPUNIT_ASSERT(test._diagonals.size() == 4);
		CPPUNIT_ASSERT(&Alive == test._NSEW[0]);
		CPPUNIT_ASSERT(&Dead == test._diagonals[0]);
	}
	
	void test_Life_Neighbor_Table_1(){
		map<pair<int,int>, ConwayCell> grid;
		pair<int, int> p(0,0);
		grid.insert(make_pair(p, ConwayCell(true)));
		grid.insert(make_pair(make_pair(0,1), ConwayCell(true)));
		Life<ConwayCell> test(grid);
		test.set_cell_neighbor_table(p);
		CPPUNIT_ASSERT(test._grid[p]._neighbors.size() == 1);
	}
	void test_Life_Neighbor_Table_2(){
		map<pair<int,int>, FredkinCell> grid;
		pair<int, int> p(0,0);
		grid.insert(make_pair(p, FredkinCell(true)));
		grid.insert(make_pair(make_pair(0,1), FredkinCell(false)));
		grid.insert(make_pair(make_pair(1,1), FredkinCell(false)));
		grid.insert(make_pair(make_pair(1,0), FredkinCell(false)));
		Life<FredkinCell> test(grid);
		test.set_cell_neighbor_table(p);
		CPPUNIT_ASSERT(test._grid[p]._neighbors.size() == 2);				
	}
	void test_Life_Neighbor_Table_3(){
		map<pair<int,int>, Cell> grid;
		pair<int, int> p(1,1);
		grid.insert(make_pair(make_pair(0,0), Cell(new ConwayCell(true))));
		grid.insert(make_pair(make_pair(0,1), Cell(new ConwayCell(true))));
		grid.insert(make_pair(make_pair(0,2), Cell(new ConwayCell(true))));
		grid.insert(make_pair(p, Cell(new ConwayCell(true))));
		grid.insert(make_pair(make_pair(1,0), Cell(new ConwayCell(true))));
		grid.insert(make_pair(make_pair(1,2), Cell(new ConwayCell(true))));
		grid.insert(make_pair(make_pair(2,0), Cell(new ConwayCell(true))));
		grid.insert(make_pair(make_pair(2,1), Cell(new ConwayCell(true))));
		grid.insert(make_pair(make_pair(2,2), Cell(new ConwayCell(true))));
		Life<Cell> test(grid);
		test.set_cell_neighbor_table(p);
		CPPUNIT_ASSERT(test._grid[p]._NSEW.size() == 4);
		CPPUNIT_ASSERT(test._grid[p]._diagonals.size() == 4);
	}

	CPPUNIT_TEST_SUITE(TestLife);
	CPPUNIT_TEST(test_Life_Neighbor_Table_1);
	CPPUNIT_TEST(test_Life_Neighbor_Table_2);
	CPPUNIT_TEST(test_Life_Neighbor_Table_3);
	CPPUNIT_TEST(test_Cell_evolve_1);
	CPPUNIT_TEST(test_Cell_evolve_2);
	CPPUNIT_TEST(test_Cell_evolve_3);
	CPPUNIT_TEST(test_Cell_set_neighbors_1);
	CPPUNIT_TEST(test_ConwayIsAlive_1);
	CPPUNIT_TEST(test_ConwayIsAlive_2);
	CPPUNIT_TEST(test_Conway_CountNumNeighbors_1);
	CPPUNIT_TEST(test_Conway_CountNumNeighbors_2);
	CPPUNIT_TEST(test_Conway_CountNumNeighbors_3);
	CPPUNIT_TEST(test_Conway_Evolve_1);
	CPPUNIT_TEST(test_Conway_Evolve_2);
	CPPUNIT_TEST(test_Conway_Evolve_3);
	CPPUNIT_TEST(test_Conway_Set_Neighbors_1);
	CPPUNIT_TEST(test_Conway_Set_Neighbors_2);
	CPPUNIT_TEST(test_Conway_Set_Neighbors_3);
	CPPUNIT_TEST(test_Conway_Count_Neighbors_1);
	CPPUNIT_TEST(test_Conway_Count_Neighbors_2);
	CPPUNIT_TEST(test_Conway_Count_Neighbors_3);
	CPPUNIT_TEST(test_Conway_resurrect_1);
	CPPUNIT_TEST(test_Conway_resurrect_2);
	CPPUNIT_TEST(test_Conway_resurrect_3);	
	CPPUNIT_TEST(test_Conway_die_1);
	CPPUNIT_TEST(test_Conway_die_2);
	CPPUNIT_TEST(test_Conway_die_3);
	CPPUNIT_TEST(test_FredkinIsAlive_1);
	CPPUNIT_TEST(test_FredkinIsAlive_2);
	CPPUNIT_TEST(test_Fredkin_CountNumNeighbors_1);
	CPPUNIT_TEST(test_Fredkin_CountNumNeighbors_2);
	CPPUNIT_TEST(test_Fredkin_CountNumNeighbors_3);
	CPPUNIT_TEST(test_Fredkin_Evolve_1);
	CPPUNIT_TEST(test_Fredkin_Evolve_2);
	CPPUNIT_TEST(test_Fredkin_Evolve_3);
	CPPUNIT_TEST(test_Fredkin_Set_Neighbors_1);
	CPPUNIT_TEST(test_Fredkin_Set_Neighbors_2);
	CPPUNIT_TEST(test_Fredkin_Set_Neighbors_3);
	CPPUNIT_TEST(test_Fredkin_Count_Neighbors_1);
	CPPUNIT_TEST(test_Fredkin_Count_Neighbors_2);
	CPPUNIT_TEST(test_Fredkin_Count_Neighbors_3);
	CPPUNIT_TEST(test_Fredkin_resurrect_1);
	CPPUNIT_TEST(test_Fredkin_resurrect_2);
	CPPUNIT_TEST(test_Fredkin_resurrect_3);	
	CPPUNIT_TEST(test_Fredkin_live_1);
	CPPUNIT_TEST(test_Fredkin_live_2);
	CPPUNIT_TEST(test_Fredkin_live_3);
	CPPUNIT_TEST(test_Fredkin_die_1);
	CPPUNIT_TEST(test_Fredkin_die_2);
	CPPUNIT_TEST(test_Fredkin_die_3);
	CPPUNIT_TEST_SUITE_END();
};
// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestLife.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestLife::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
