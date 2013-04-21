/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -lcppunit -ldl -pedantic -std=c++0x -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz.c++.app
    % valgrind TestCollatz.c++.app >& TestCollatz.c++.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <vector>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#include "Life.h"


struct TestLife : CppUnit::TestFixture {


  void test_constructor_1() {
	Life<ConwayCell> game(5, 5);
	CPPUNIT_ASSERT(true);
  }


  void test_constructor_2() {
	Life<FredkinCell> game(5, 5);
	CPPUNIT_ASSERT(true);
  }


  void test_constructor_3() {
	Life<Cell> game(5, 5);
	CPPUNIT_ASSERT(true);
  }

  void test_add_1() {
	Life<ConwayCell> game(5, 5);
	game.add(1,1, ConwayCell(true));
	CPPUNIT_ASSERT(game.population() == 1);
	CPPUNIT_ASSERT(true);
  }


  void test_add_2() {
	Life<FredkinCell> game(5, 5);
	game.add(1,1, FredkinCell(true));
	CPPUNIT_ASSERT(game.population() == 1);
	CPPUNIT_ASSERT(true);
  }


  void test_add_3() {
	Life<Cell> game(5, 5);
	game.add(1,1, ConwayCell(true).clone());
	game.add(1,2, FredkinCell(true).clone());
	CPPUNIT_ASSERT(game.population() == 2);
	CPPUNIT_ASSERT(true);
  }


  void test_population_1() {
	Life<ConwayCell> game(5, 5);
	game.add(1,1, ConwayCell(true));
	game.run(); // should kill the 1 conwaycell
	CPPUNIT_ASSERT(game.population() == 0);
	CPPUNIT_ASSERT(true);
  }


  void test_population_2() {
	Life<FredkinCell> game(5, 5);
	game.add(1,1, FredkinCell(true));
	game.add(1,1, FredkinCell(true)); // shouldn't add to population
	CPPUNIT_ASSERT(game.population() == 1);
	CPPUNIT_ASSERT(true);
  }


  void test_population_3() {
	Life<Cell> game(5, 5);
	game.add(1,1, ConwayCell(true).clone());
	game.add(1,2, FredkinCell(true).clone());
	CPPUNIT_ASSERT(game.population() == 2);
	CPPUNIT_ASSERT(true);
  }


  void test_run_1() {
	Life<ConwayCell> game(5, 5);
	game.add(1,1, ConwayCell(true));
	game.add(1,2, ConwayCell(true));
	game.add(1,3, ConwayCell(true));
	
	for (int i = 0; i < 40; i++) {
	  CPPUNIT_ASSERT(game.population() == 3);
	  game.run(); 
	}
	CPPUNIT_ASSERT(game.population() == 3);
	CPPUNIT_ASSERT(true);
  }

  void test_run_2() {
	Life<FredkinCell> game(5, 5);
	game.add(1,1, FredkinCell(true));
	game.add(1,2, FredkinCell(true));
	game.add(1,3, FredkinCell(true));
	Life<FredkinCell> game2(5, 5);
	game2.add(1,1, FredkinCell(true));
	game2.add(1,2, FredkinCell(true));
	game2.add(1,3, FredkinCell(true));
	
	for (int i = 0; i < 40; i++) {
	  CPPUNIT_ASSERT(game.population() == game2.population());
	  game.run(i);
	  for(int j = 0; j < i; j++) game2.run();
	}
	CPPUNIT_ASSERT(game.population() == game2.population());
	CPPUNIT_ASSERT(true);
  }

  void test_run_3() {
	Life<Cell> game(5, 5);
	game.add(1,1, ConwayCell(true).clone());
	game.add(1,2, FredkinCell(true).clone());
	game.add(1,3, ConwayCell(true).clone());
	
	game.run(10000); // test lots of runs
	
	CPPUNIT_ASSERT(game.population() <= 25);
	CPPUNIT_ASSERT(true);
  }

  void test_print_1() {
	Life<ConwayCell> game(5, 5);
	game.add(1,1, ConwayCell(true));
	game.add(1,2, ConwayCell(true));
	game.add(2,1, ConwayCell(true));
	game.add(2,2, ConwayCell(true));
	
	std::ostringstream w;
	for(int i = 0; i < 10; i++){
	  game.run(); // test lots of runs
	  w.str(""); w.clear();
	  game.print(w);
	  std::stringstream s;
	  s << "Generation = ";
	  s << (i+1);
	  s << ", Population = ";
	  s << game.population();
	  s << ".\n";
	  s << ".....\n";
	  s << ".**..\n";
	  s <<  ".**..\n";
	  s << ".....\n";
	  s << ".....\n\n";
	  
	  CPPUNIT_ASSERT(w.str() == s.str());
	}

	CPPUNIT_ASSERT(game.population() == 4);
	CPPUNIT_ASSERT(true);
  }
  
  void test_print_2() {
	Life<FredkinCell> game(5, 5);
	game.add(1,1, FredkinCell(true));
	game.add(1,2, FredkinCell(true));
	game.add(2,1, FredkinCell(true));
	game.add(2,2, FredkinCell(true));
	
	std::ostringstream w;

	game.run(); // test lots of runs
	game.print(w);

	std::stringstream s;
	s << "Generation = ";
	s << 1;
	s << ", Population = ";
	s << 8;
	s << ".\n";
	s << "-00--\n";
	s << "0--0-\n";
	s << "0--0-\n";
	s << "-00--\n";
	s << "-----\n\n";
	
	CPPUNIT_ASSERT(w.str() == s.str());

	CPPUNIT_ASSERT(game.population() == 8);
	CPPUNIT_ASSERT(true);
  }
  
  void test_print_3() {
	Life<Cell> game(5, 5);
	game.add(2,2, FredkinCell(true).clone());
	
	std::ostringstream w;

	game.run(); // test lots of runs
	game.print(w);

	std::stringstream s;
	s << "Generation = ";
	s << 1;
	s << ", Population = ";
	s << 4;
	s << ".\n";
	s << "-----\n";
	s << "--0--\n";
	s << "-0-0-\n";
	s << "--0--\n";
	s << "-----\n\n";
	
	CPPUNIT_ASSERT(w.str() == s.str());

	CPPUNIT_ASSERT(game.population() == 4);
	CPPUNIT_ASSERT(true);
  }


  CPPUNIT_TEST_SUITE(TestLife);

  CPPUNIT_TEST(test_constructor_1);
  CPPUNIT_TEST(test_constructor_2);
  CPPUNIT_TEST(test_constructor_3);
  
  CPPUNIT_TEST(test_add_1);
  CPPUNIT_TEST(test_add_2);
  CPPUNIT_TEST(test_add_3);
  
  CPPUNIT_TEST(test_population_1);
  CPPUNIT_TEST(test_population_2);
  CPPUNIT_TEST(test_population_3);
  
  CPPUNIT_TEST(test_run_1);
  CPPUNIT_TEST(test_run_2);
  CPPUNIT_TEST(test_run_3);
  
  CPPUNIT_TEST(test_print_1);
  CPPUNIT_TEST(test_print_2);
  CPPUNIT_TEST(test_print_3);
  
  
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
