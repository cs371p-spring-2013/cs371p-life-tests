// --------
// includes
// --------

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <ostream>
#include <vector>

#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TextTestRunner.h"


#define private public
#define protected public

#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

using namespace std;

// ----------
// TestDarwin
// ----------

struct TestLife : CppUnit::TestFixture {
 
   // ----------------
  // TestLife
  // ----------------


    

    void test_life_constructor_1() {
      vector<char> v; 
    for(int i = 0; i < 5; i++)
      v.push_back('.');
    
    vector<vector<char> > temp_board;
    vector<vector<char> > temp_board1;
    
    temp_board.push_back(v);
    temp_board.push_back(v);
    temp_board.push_back(v);
    v[2] = '*';
    temp_board1.push_back(v); 
    temp_board1.push_back(v);
    temp_board1.push_back(v);
    Life<ConwayCell> l(3, 5, temp_board);
    CPPUNIT_ASSERT(l.pop == 0);

  }

  void test_life_constructor_2() {
     vector<char> v; 
    for(int i = 0; i < 5; i++)
      v.push_back('.');
    
    vector<vector<char> > temp_board;
    vector<vector<char> > temp_board1;
    
    temp_board.push_back(v);
    temp_board.push_back(v);
    temp_board.push_back(v);
    v[2] = '*';
    temp_board1.push_back(v); 
    temp_board1.push_back(v);
    temp_board1.push_back(v);
    Life<ConwayCell> l(3, 5, temp_board1);
    CPPUNIT_ASSERT(l.pop == 3);

  }

  void test_life_constructor_3() {
     vector<char> v; 
    for(int i = 0; i < 5; i++)
      v.push_back('.');
    
    vector<vector<char> > temp_board;
    vector<vector<char> > temp_board1;
    
    temp_board.push_back(v);
    temp_board.push_back(v);
    temp_board.push_back(v);
    v[2] = '*';
    temp_board1.push_back(v); 
    temp_board1.push_back(v);
    temp_board1.push_back(v);
    Life<ConwayCell> l(1, 5, temp_board1);
    CPPUNIT_ASSERT(l.pop == 1);

  }

  void test_life_play_1(){
     vector<char> v; 
    for(int i = 0; i < 5; i++)
      v.push_back('.');
    
    vector<vector<char> > temp_board;
    vector<vector<char> > temp_board1;
    
    temp_board.push_back(v);
    temp_board.push_back(v);
    temp_board.push_back(v);
    v[2] = '*';
    temp_board1.push_back(v); 
    temp_board1.push_back(v);
    temp_board1.push_back(v);
    Life<ConwayCell> l(3, 5, temp_board);
    l.play(1);
    l.play(1);
    CPPUNIT_ASSERT(l.pop == 0);
  }

  void test_life_play_2(){
     vector<char> v; 
    for(int i = 0; i < 5; i++)
      v.push_back('.');
    
    vector<vector<char> > temp_board;
    vector<vector<char> > temp_board1;
    
    temp_board.push_back(v);
    temp_board.push_back(v);
    temp_board.push_back(v);
    v[2] = '*';
    temp_board1.push_back(v); 
    temp_board1.push_back(v);
    temp_board1.push_back(v);
    Life<ConwayCell> l(3, 5, temp_board1);
    l.play(1);
    l.play(1);
    CPPUNIT_ASSERT(l.pop == 3);
  }

void test_life_play_3() {
   vector<char> v; 
    for(int i = 0; i < 5; i++)
      v.push_back('.');
    
    vector<vector<char> > temp_board;
    vector<vector<char> > temp_board1;
    
    temp_board.push_back(v);
    temp_board.push_back(v);
    temp_board.push_back(v);
    v[2] = '*';
    temp_board1.push_back(v); 
    temp_board1.push_back(v);
    temp_board1.push_back(v);
    Life<ConwayCell> l(1, 5, temp_board1);
    l.play(1);
    l.play(1);
    CPPUNIT_ASSERT(l.pop == 0);

  }
  // ----------------
  // ConwayCell
  // ----------------

void test_conway_get_char1(){
    ConwayCell c('.');
    CPPUNIT_ASSERT(c.get_char() == '.');

}

void test_conway_get_char2(){
    ConwayCell c('*');
    CPPUNIT_ASSERT(c.get_char() == '*');

}

void test_conway_get_char3(){
    ConwayCell c('.');
    CPPUNIT_ASSERT(c.get_char() == '.');

}

void test_conway_is_alive1(){
    ConwayCell c('*');
    CPPUNIT_ASSERT(c.is_alive() == true);

}

void test_conway_is_alive2(){
    ConwayCell c('.');
    CPPUNIT_ASSERT(c.is_alive() == false);

}

void test_conway_is_alive3(){
    ConwayCell c('.');
    CPPUNIT_ASSERT(c.is_alive() == false);

}

void test_conway_set_alive1(){
    ConwayCell c('*');
    c.set_alive();
    CPPUNIT_ASSERT(c.is_alive() == false);

}

void test_conway_set_alive2(){
    ConwayCell c('.');
    c.set_alive();
    CPPUNIT_ASSERT(c.is_alive() == true);

}

void test_conway_set_alive3(){
    ConwayCell c('.');
    c.set_alive();
    c.set_alive();
    CPPUNIT_ASSERT(c.is_alive() == false);

}
  // ----------------
  // FredkinCell
  // ----------------
void test_fredkin_get_char1(){
    FredkinCell c('0');
    CPPUNIT_ASSERT(c.get_char() == '0');

}

void test_fredkin_get_char2(){
    FredkinCell c('-');
    CPPUNIT_ASSERT(c.get_char() == '-');

}

void test_fredkin_get_char3(){
    FredkinCell c('+');
    CPPUNIT_ASSERT(c.get_char() == '0');

}

void test_fredkin_is_alive1(){
    FredkinCell c('0');
    CPPUNIT_ASSERT(c.is_alive() == true);

}

void test_fredkin_is_alive2(){
    FredkinCell c('-');
    c.set_alive();
    c.set_alive();
    CPPUNIT_ASSERT(c.is_alive() == false);

}

void test_fredkin_is_alive3(){
    FredkinCell c('-');
    CPPUNIT_ASSERT(c.is_alive() == false);

}

void test_fredkin_set_alive1(){
    FredkinCell c('0');
    c.set_alive();
    CPPUNIT_ASSERT(c.is_alive() == false);

}

void test_fredkin_set_alive2(){
    FredkinCell c('-');
    c.set_alive();
    CPPUNIT_ASSERT(c.is_alive() == true);

}

void test_fredkin_set_alive3(){
    FredkinCell c('0');
    c.set_alive();
    c.set_alive();
    c.set_alive();
    CPPUNIT_ASSERT(c.is_alive() == false);

}

  void test_fredkin_cell_increase_age_1() {
    FredkinCell c ;
    CPPUNIT_ASSERT(c.age == 0);
  }

  void test_fredkin_cell_increase_age_2() {
    FredkinCell c('-');
    c.increase_age();
    c.increase_age();
    c.increase_age();
    c.increase_age();
    CPPUNIT_ASSERT(c.age == 0);
  }

  void test_fredkin_cell_increase_age_3() {
    FredkinCell c('+');
    c.increase_age();
    CPPUNIT_ASSERT(c.age == 1);
  }



  
  // ----------------
  // Cell isAlive
  // ----------------
  void test_cell_is_alive_1() {
    Cell c('-');
    CPPUNIT_ASSERT(c.is_alive() == false);
  }

  void test_cell_is_alive_2() {
     Cell c('0');
     c.set_alive();
    CPPUNIT_ASSERT(c.is_alive() == false);
  }

  void test_cell_is_alive_3() {
     Cell c('0');
    CPPUNIT_ASSERT(c.is_alive() == true);
  }


  // ---------
  // TestSuite
  // ---------
  CPPUNIT_TEST_SUITE(TestLife);
  CPPUNIT_TEST(test_life_constructor_1);
  CPPUNIT_TEST(test_life_constructor_2);
  CPPUNIT_TEST(test_life_constructor_3);
  CPPUNIT_TEST(test_life_play_1);
  CPPUNIT_TEST(test_life_play_2);
  CPPUNIT_TEST(test_life_play_3);
  CPPUNIT_TEST(test_conway_get_char1);
  CPPUNIT_TEST(test_conway_get_char2);
  CPPUNIT_TEST(test_conway_get_char3);
  CPPUNIT_TEST(test_conway_is_alive1);
  CPPUNIT_TEST(test_conway_is_alive2);
  CPPUNIT_TEST(test_conway_is_alive3);
  CPPUNIT_TEST(test_conway_set_alive1);
  CPPUNIT_TEST(test_conway_set_alive2);
  CPPUNIT_TEST(test_conway_set_alive3);
  CPPUNIT_TEST(test_fredkin_get_char1);
  CPPUNIT_TEST(test_fredkin_get_char2);
  CPPUNIT_TEST(test_fredkin_get_char3);
  CPPUNIT_TEST(test_fredkin_is_alive1);
  CPPUNIT_TEST(test_fredkin_is_alive2);
  CPPUNIT_TEST(test_fredkin_is_alive3);
  CPPUNIT_TEST(test_fredkin_set_alive1);
  CPPUNIT_TEST(test_fredkin_set_alive2);
  CPPUNIT_TEST(test_fredkin_set_alive3);
  CPPUNIT_TEST(test_fredkin_cell_increase_age_1);
  CPPUNIT_TEST(test_fredkin_cell_increase_age_2);
  CPPUNIT_TEST(test_fredkin_cell_increase_age_3);
  CPPUNIT_TEST(test_cell_is_alive_1);
  CPPUNIT_TEST(test_cell_is_alive_2);
  CPPUNIT_TEST(test_cell_is_alive_3);



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
