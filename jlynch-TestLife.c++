#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner

#define private public
#define protected public

#include <sstream>

#include "Life.h"

struct TestAbstractCell: CppUnit::TestFixture{
  //No sense writing multiple tests of the default constructor
  void test_default_constructor1(){
    //Test via FredkinCell
    FredkinCell c;
    AbstractCell& cp = c;
    CPPUNIT_ASSERT_EQUAL(0, cp.live_neighbors);
    CPPUNIT_ASSERT_EQUAL(true, cp.alive);
  }
  void test_default_constructor2(){
    ConwayCell c;
    AbstractCell& cp = c;
    CPPUNIT_ASSERT_EQUAL(true, cp.alive);
  }

  void test_live_constructor1(){
    //Test via FredkinCell
    FredkinCell c(true);
    AbstractCell& cp = c;
    CPPUNIT_ASSERT_EQUAL(0, cp.live_neighbors);
    CPPUNIT_ASSERT_EQUAL(true, cp.alive);
  }
  void test_live_constructor2(){
    ConwayCell c(true);
    AbstractCell& cp = c;
    CPPUNIT_ASSERT_EQUAL(0, cp.live_neighbors);
    CPPUNIT_ASSERT_EQUAL(true, cp.alive);
  }
  void test_live_constructor3(){
    ConwayCell c(false);
    AbstractCell& cp = c;
    CPPUNIT_ASSERT_EQUAL(0, cp.live_neighbors);
    CPPUNIT_ASSERT_EQUAL(false , cp.alive);
  }
  void test_live_constructor4(){
    FredkinCell c(false);
    AbstractCell& cp = c;
    CPPUNIT_ASSERT_EQUAL(0, cp.live_neighbors);
    CPPUNIT_ASSERT_EQUAL(false, cp.alive);
  }


  //Same for getters and setters

  void test_set_alive(){
    FredkinCell c;
    AbstractCell& cp = c;
    CPPUNIT_ASSERT_EQUAL(true, cp.alive);
    cp.set_alive(false);
    CPPUNIT_ASSERT_EQUAL(false, cp.alive);
  }

  void test_get_live_neighbors(){
    FredkinCell c;
    AbstractCell& cp = c;
    cp.live_neighbors = 7;
    CPPUNIT_ASSERT_EQUAL(7, cp.get_live_neighbors());
  }

  void test_set_live_neighbors(){
    FredkinCell c;
    AbstractCell& cp = c;
    cp.set_live_neighbors(7);
    CPPUNIT_ASSERT_EQUAL(7, cp.live_neighbors);
  }

  void test_is_alive(){
    FredkinCell c;
    AbstractCell& cp = c;
    cp.alive = true;
    CPPUNIT_ASSERT_EQUAL(true, cp.is_alive());
    cp.alive = false;
    CPPUNIT_ASSERT_EQUAL(false, cp.is_alive());
  }

  CPPUNIT_TEST_SUITE(TestAbstractCell);

  CPPUNIT_TEST(test_default_constructor1);
  CPPUNIT_TEST(test_default_constructor2);

  CPPUNIT_TEST(test_live_constructor1);
  CPPUNIT_TEST(test_live_constructor2);
  CPPUNIT_TEST(test_live_constructor3);
  CPPUNIT_TEST(test_live_constructor4);

  CPPUNIT_TEST(test_set_alive);
  CPPUNIT_TEST(test_set_live_neighbors);
  CPPUNIT_TEST(test_get_live_neighbors);
  CPPUNIT_TEST(test_is_alive);
  CPPUNIT_TEST_SUITE_END();
};

struct TestFredkinCell : CppUnit::TestFixture{

  //I've only written one default constructor test because there's not
  //much sense in testing the same behavior three times
  void test_default_constructor(){
    FredkinCell c;
    CPPUNIT_ASSERT_EQUAL(0, c.age);
    CPPUNIT_ASSERT_EQUAL(true, c.is_alive());
  }

  void test_live_constructor1(){
    FredkinCell c(true);
    CPPUNIT_ASSERT_EQUAL(0, c.age);
    CPPUNIT_ASSERT_EQUAL(true, c.is_alive());
  }
  void test_live_constructor2(){
    FredkinCell c(false);
    CPPUNIT_ASSERT_EQUAL(0, c.age);
    CPPUNIT_ASSERT_EQUAL(false, c.is_alive());
  }

  //Test << on cells under the age of 9
  void test_double_angle_bracket1(){
    FredkinCell c;
    std::ostringstream o;
    std::stringstream int_stream;
    for(int i=0; i<10; i++){
      c.age = i;
      CPPUNIT_ASSERT_EQUAL(true, c.is_alive());
      o << c;
      int_stream << i;

      CPPUNIT_ASSERT_EQUAL(int_stream.str(), o.str());
      o.str(std::string());
      o.clear();
      int_stream.str(std::string());
      int_stream.clear();
    }
  }

  //Test << on a cell over the age of 9
  void test_double_angle_bracket2(){
    FredkinCell c;
    std::ostringstream o;

    c.age = 10;
    CPPUNIT_ASSERT_EQUAL(true, c.is_alive());
    o << c;
    CPPUNIT_ASSERT_EQUAL((std::string) "+", o.str());
  }

  //Test << on a dead cell
  void test_double_angle_bracket3(){
    FredkinCell c;
    std::ostringstream o;

    c.alive = false;

    for(int i=0; i<11; i++){
      c.age = i;
      o << c;
      CPPUNIT_ASSERT_EQUAL(false, c.is_alive());
      CPPUNIT_ASSERT_EQUAL((std::string) "-", o.str());
      o.str(std::string());
      o.clear();
    }
  }

  //Basic test of get_dead
  void test_get_dead(){
    FredkinCell c;
    c.alive = false;
    CPPUNIT_ASSERT_EQUAL('-', c.getDead());
  }

  //Verify that - is returned fo all values below 10
  void test_get_dead2(){
    FredkinCell c;
    c.alive = false;
    for(int i=1; i<10; i++){
      c.age = i;
      CPPUNIT_ASSERT_EQUAL('-', c.getDead());
    }
  }

  //Verify that - is returned for representative values above 10
  void test_get_dead3(){
    FredkinCell c;
    c.alive = false;
    for(int i=10; i<20; i++){
      c.age = i;
      CPPUNIT_ASSERT_EQUAL('-', c.getDead());
    }
  }

  void test_get_live(){
    FredkinCell c;
    char current;
    for(int i=0; i < 10;i++){
      c.age = i;
      current ='0'+i;
      CPPUNIT_ASSERT_EQUAL(current, c.getLive());
    }
  }

  void test_get_live2(){
    FredkinCell c;
    c.age = 10;
    CPPUNIT_ASSERT_EQUAL('+', c.getLive());
  }

  void test_get_live3(){
    FredkinCell c;
    c.age = 10;
    for(int i=10; i<20; i++){
      c.age = i;
      CPPUNIT_ASSERT_EQUAL('+', c.getLive());
    }
  }

  void test_want_meta1(){
    FredkinCell c;
    CPPUNIT_ASSERT_EQUAL(false, c.want_meta());
  }

  void test_want_meta2(){
    FredkinCell c;
    c.age = 2;
    CPPUNIT_ASSERT_EQUAL(true, c.want_meta());
  }

  void test_want_meta3(){
    FredkinCell c;
    c.alive = false;
    c.age = 4;
    CPPUNIT_ASSERT_EQUAL(true, c.want_meta());
  }

  void test_clone1(){
    FredkinCell c1;

    FredkinCell* cp2 = c1.clone();
    CPPUNIT_ASSERT(&c1 != cp2);

    delete cp2;
  }

  void test_clone2(){
    FredkinCell c1;
    c1.age = 5;
    c1.alive = false;

    FredkinCell* cp2 = c1.clone();
    CPPUNIT_ASSERT(&c1 != cp2);
    CPPUNIT_ASSERT_EQUAL(c1.age, cp2->age);
    CPPUNIT_ASSERT_EQUAL(c1.alive, cp2->alive);

    delete cp2;
  }

  void test_clone3(){
    FredkinCell c1;
    c1.age = 5;
    c1.alive = false;

    FredkinCell* cp2 = c1.clone();

    c1.age = 11;
    c1.alive = true;
    
    CPPUNIT_ASSERT(c1.age != cp2->age);
    CPPUNIT_ASSERT(c1.alive != cp2->alive);

    delete cp2;
  }

  //a live cell becomes a dead cell, if 0, 2, or 4 neighbors are alive 
  void test_commit1(){
    FredkinCell c;
    c.live_neighbors = 0;
    c.commit();

    CPPUNIT_ASSERT_EQUAL(false, c.alive);

    c.alive = true;
    c.live_neighbors = 2;
    c.commit();
    CPPUNIT_ASSERT_EQUAL(false, c.alive);

    c.alive = true;
    c.live_neighbors = 4;
    c.commit();
    CPPUNIT_ASSERT_EQUAL(false, c.alive);
  }

  //a dead cell becomes a live cell, if 1 or 3 neighbors are alive
  void test_commit2(){
    FredkinCell c;

    c.live_neighbors = 1;
    c.commit();
    CPPUNIT_ASSERT_EQUAL(true, c.alive);

    c.alive = false;
    c.live_neighbors = 3;
    c.commit();
    CPPUNIT_ASSERT_EQUAL(true, c.alive);
  }

  //Verify that nothing happens when neither condition is met
  void test_commit3(){
    FredkinCell c;

    //Start dead and stay dead
    c.live_neighbors = 0;
    c.alive = false;
    c.commit();

    CPPUNIT_ASSERT_EQUAL(false, c.alive);

    c.live_neighbors = 2;
    c.commit();
    CPPUNIT_ASSERT_EQUAL(false, c.alive);

    c.live_neighbors = 4;
    c.commit();
    CPPUNIT_ASSERT_EQUAL(false, c.alive);

    //Start alive and stay alive 
    c.alive = true;
    c.live_neighbors = 1;
    c.commit();
    CPPUNIT_ASSERT_EQUAL(true, c.alive);

    c.live_neighbors = 3;
    c.commit();
    CPPUNIT_ASSERT_EQUAL(true, c.alive);
  }

  //Test that commit handles age appropriately
  void test_commit4(){
    FredkinCell c;
    c.age = 0;
    c.alive = true;
    //And odd number of neighbors will keep the cell alive
    c.live_neighbors = 3;
    c.commit();
    CPPUNIT_ASSERT_EQUAL(true, c.alive);
    CPPUNIT_ASSERT_EQUAL(1, c.age);
  }

  void test_commit5(){
    FredkinCell c;
    c.age = 0;
    c.alive = true;
    //And even number of neighbors will kill the cell
    c.live_neighbors = 2;
    c.commit();
    CPPUNIT_ASSERT_EQUAL(false, c.alive);
    //Age shouldn't have changed
    CPPUNIT_ASSERT_EQUAL(0, c.age);
  }

  void test_commit6(){
    FredkinCell c;
    c.age = 0;
    c.alive = false;
    //And even number of neighbors will keep the cell dead
    c.live_neighbors = 2;
    c.commit();
    CPPUNIT_ASSERT_EQUAL(false, c.alive);
    //Age shouldn't have changed
    CPPUNIT_ASSERT_EQUAL(0, c.age);
  }

  void test_update1(){
    FredkinCell c;
    c.update(0, 4);
    //FredkinCells ignore diagonals
    CPPUNIT_ASSERT_EQUAL(0, c.live_neighbors);
  }

  void test_update2(){
    FredkinCell c;
    c.update(4, 0);
    //FredkinCells don't ignore adjacent neighbors
    CPPUNIT_ASSERT_EQUAL(4, c.live_neighbors);
  }

  void test_update3(){
    FredkinCell c;
    c.update(4,4);
    CPPUNIT_ASSERT_EQUAL(4, c.live_neighbors);
  }


  CPPUNIT_TEST_SUITE(TestFredkinCell);
    CPPUNIT_TEST(test_double_angle_bracket1);
    CPPUNIT_TEST(test_double_angle_bracket2);
    CPPUNIT_TEST(test_double_angle_bracket3);

    CPPUNIT_TEST(test_default_constructor);

    CPPUNIT_TEST(test_live_constructor1);
    CPPUNIT_TEST(test_live_constructor2);

    CPPUNIT_TEST(test_want_meta1);
    CPPUNIT_TEST(test_want_meta2);
    CPPUNIT_TEST(test_want_meta3);

    CPPUNIT_TEST(test_clone1);
    CPPUNIT_TEST(test_clone2);
    CPPUNIT_TEST(test_clone3);

    CPPUNIT_TEST(test_commit1);
    CPPUNIT_TEST(test_commit2);
    CPPUNIT_TEST(test_commit3);
    CPPUNIT_TEST(test_commit4);
    CPPUNIT_TEST(test_commit5);
    CPPUNIT_TEST(test_commit6);

    CPPUNIT_TEST(test_update1);
    CPPUNIT_TEST(test_update2);
    CPPUNIT_TEST(test_update3);

    CPPUNIT_TEST(test_get_dead);
    CPPUNIT_TEST(test_get_dead2);
    CPPUNIT_TEST(test_get_dead3);

    CPPUNIT_TEST(test_get_live);
    CPPUNIT_TEST(test_get_live2);
    CPPUNIT_TEST(test_get_live3);
  CPPUNIT_TEST_SUITE_END();
};

struct TestConwayCell : CppUnit::TestFixture{

  void test_default_constructor(){
    ConwayCell c;
    CPPUNIT_ASSERT_EQUAL(true, c.alive);
  }
  
  void test_live_constructor1(){
    ConwayCell c(true);
    CPPUNIT_ASSERT_EQUAL(true, c.alive);
  }
  void test_live_constructor2(){
    ConwayCell c(false);
    CPPUNIT_ASSERT_EQUAL(false, c.alive);
  }

  ////////////////////////
  //<<
  ////////////////////////
  void test_double_angle_bracket1(){
    ConwayCell c;
    std::ostringstream o;
    c.alive = true;
    o << c;
    CPPUNIT_ASSERT_EQUAL((std::string) "*", o.str());
  }

  void test_double_angle_bracket2(){
    ConwayCell c;
    std::ostringstream o;
    c.alive = false;
    o << c;
    CPPUNIT_ASSERT_EQUAL((std::string) ".", o.str());
  }

  void test_double_angle_bracket3(){
    ConwayCell c;
    std::ostringstream o;
    c.alive = false;
    o << c;
    CPPUNIT_ASSERT_EQUAL((std::string) ".", o.str());
    o.str(std::string());
    o.clear();
    c.alive = true;
    o << c;
    CPPUNIT_ASSERT_EQUAL((std::string) "*", o.str());
  }

  ////////////////////////
  //ConwayCell.want_meta()
  ////////////////////////
  void test_want_meta1(){
    ConwayCell c;
    c.alive = true;
    CPPUNIT_ASSERT_EQUAL(false, c.want_meta());
  }
  void test_want_meta2(){
    ConwayCell c;
    c.alive = false;
    CPPUNIT_ASSERT_EQUAL(false, c.want_meta());
  }
  void test_want_meta3(){
    const ConwayCell c;
    CPPUNIT_ASSERT_EQUAL(false, c.want_meta());
  }

  ////////////////////////
  //ConwayCell::clone();
  ////////////////////////
  void test_clone1(){
    ConwayCell c;
    ConwayCell* cp = c.clone();
    CPPUNIT_ASSERT(&c != cp);
    delete cp;
  }

  void test_clone2(){
    ConwayCell c;
    c.alive = false;

    ConwayCell* cp = c.clone();
    CPPUNIT_ASSERT(&c != cp);

    CPPUNIT_ASSERT_EQUAL(c.alive, cp->alive);

    delete cp;
  }

  void test_clone3(){
    ConwayCell c;
    c.alive = false;

    ConwayCell* cp = c.clone();
    CPPUNIT_ASSERT(&c != cp);

    CPPUNIT_ASSERT_EQUAL(false, cp->alive);
    CPPUNIT_ASSERT_EQUAL(false, c.alive);

    c.alive = true;

    CPPUNIT_ASSERT_EQUAL(false, cp->alive);
    CPPUNIT_ASSERT(c.alive != cp->alive);

    delete cp;

  }

  ////////////////////////
  //ConwayCell::commit();
  ////////////////////////
  /*
    a dead cell becomes a live cell, if exactly 3 neighbors are alive
    a live cell becomes a dead cell, if less than 2 or more than 3 neighbors are 
      alive
  */
  void test_commit1(){
    ConwayCell c;
    c.alive = false;
    c.live_neighbors = 3;
    c.commit();
    CPPUNIT_ASSERT_EQUAL(true, c.alive);
  }

  void test_commit2(){
    ConwayCell c;
    for(int i = 0; i<10; i++){
      c.alive = true;
      c.live_neighbors = i;
      c.commit();
      CPPUNIT_ASSERT_EQUAL(i == 3 || i==2, c.alive);
    }
  }

  void test_commit3(){
    ConwayCell c;
    for(int i = 0; i<10; i++){
      c.alive = false;
      c.live_neighbors = i;
      c.commit();
      CPPUNIT_ASSERT_EQUAL(i == 3, c.alive);
    }

  }

  ///////////////////////////////////////
  //ConwayCell::update(int adj, int diag)
  ///////////////////////////////////////
  void test_update1(){
    ConwayCell c; 
    c.live_neighbors = -1;
    c.update(3, 4);
    CPPUNIT_ASSERT_EQUAL(7, c.live_neighbors);
  }

  void test_update2(){
    ConwayCell c; 
    c.live_neighbors = -1;
    c.update(4, 3);
    CPPUNIT_ASSERT_EQUAL(7, c.live_neighbors);
  }

  void test_update3(){
    ConwayCell c; 
    c.live_neighbors = -1;
    c.update(0, 4);
    CPPUNIT_ASSERT_EQUAL(4, c.live_neighbors);
  }

  void test_update4(){
    ConwayCell c; 
    c.live_neighbors = -1;
    c.update(4, 0);
    CPPUNIT_ASSERT_EQUAL(4, c.live_neighbors);
  }

  ////////////////////////
  //ConwayCell::getLead()
  ////////////////////////

  void test_get_live1(){
    ConwayCell c;
    char expected = '*';
    CPPUNIT_ASSERT_EQUAL(expected, c.getLive());
  }

  void test_get_live2(){
    ConwayCell c;
    c.alive = false;
    char expected = '*';
    CPPUNIT_ASSERT_EQUAL(expected, c.getLive());
  }

  void test_get_live3(){
    const ConwayCell c;
    char expected = '*';
    CPPUNIT_ASSERT_EQUAL(expected, c.getLive());
  }

  ////////////////////////
  //ConwayCell::getDead()
  ////////////////////////

  void test_get_dead1(){
    ConwayCell c; 
    c.alive = false;
    char expected = '.';
    CPPUNIT_ASSERT_EQUAL(expected, c.getDead());
  }

  void test_get_dead2(){
    ConwayCell c; 
    c.alive = true;
    char expected = '.';
    CPPUNIT_ASSERT_EQUAL(expected, c.getDead());
  }

  void test_get_dead3(){
    const ConwayCell c; 
    char expected = '.';
    CPPUNIT_ASSERT_EQUAL(expected, c.getDead());
  }


  CPPUNIT_TEST_SUITE(TestConwayCell);

    CPPUNIT_TEST(test_default_constructor);
    
    CPPUNIT_TEST(test_live_constructor1);
    CPPUNIT_TEST(test_live_constructor2);

    CPPUNIT_TEST(test_double_angle_bracket1);
    CPPUNIT_TEST(test_double_angle_bracket2);
    CPPUNIT_TEST(test_double_angle_bracket3);

    CPPUNIT_TEST(test_want_meta1);
    CPPUNIT_TEST(test_want_meta2);
    CPPUNIT_TEST(test_want_meta3);

    CPPUNIT_TEST(test_clone1);
    CPPUNIT_TEST(test_clone2);
    CPPUNIT_TEST(test_clone3);

    CPPUNIT_TEST(test_commit1);
    CPPUNIT_TEST(test_commit2);
    CPPUNIT_TEST(test_commit3);

    CPPUNIT_TEST(test_update1);
    CPPUNIT_TEST(test_update2);
    CPPUNIT_TEST(test_update3);
    CPPUNIT_TEST(test_update4);

    CPPUNIT_TEST(test_get_live1);
    CPPUNIT_TEST(test_get_live2);
    CPPUNIT_TEST(test_get_live3);

    CPPUNIT_TEST(test_get_dead1);
    CPPUNIT_TEST(test_get_dead2);
    CPPUNIT_TEST(test_get_dead3);

  CPPUNIT_TEST_SUITE_END();
};

struct TestCell: CppUnit::TestFixture{

  void test_default_constructor1(){
    Cell c = new FredkinCell();
    CPPUNIT_ASSERT_EQUAL(true, c.get()->alive);
    FredkinCell* fp = dynamic_cast<FredkinCell*>(c.get());
    CPPUNIT_ASSERT_EQUAL(0, fp->age);
  }
  void test_default_constructor2(){
    Cell c = new ConwayCell();
    CPPUNIT_ASSERT_EQUAL(true, c.get()->alive);
  }

  void test_double_angle_brackets1(){
    Cell c = new FredkinCell();
    FredkinCell* fp = dynamic_cast<FredkinCell*>(c.get());
    CPPUNIT_ASSERT_EQUAL(0, fp->age);

    std::ostringstream o;
    o << c;
    CPPUNIT_ASSERT_EQUAL((std::string) "0",o.str());
    o.str(std::string());
    o.clear();
    
    fp->age = 1;
    o << c;

    CPPUNIT_ASSERT_EQUAL((std::string) "1", o.str());
    o.str(std::string());
    o.clear();

    fp->age = 10;
    o << c;

    CPPUNIT_ASSERT_EQUAL((std::string) "+",o.str());
  }
  void test_double_angle_brackets2(){
    Cell c = new ConwayCell();
    std::ostringstream o;

    c.get()->alive = true;

    o << c;

    CPPUNIT_ASSERT_EQUAL((std::string) "*",o.str());

  }
  void test_double_angle_brackets3(){
    Cell c = new ConwayCell();
    std::ostringstream o;

    c.get()->alive = false;

    o << c;
    CPPUNIT_ASSERT_EQUAL((std::string) ".",o.str());
    o.str(std::string());
    o.clear();

    c = new FredkinCell();
    c.get()->alive = false;

    o << c;
    CPPUNIT_ASSERT_EQUAL((std::string) "-",o.str());
  }

  void test_update1(){
    Cell c = new ConwayCell();
    c.update(1,2);
    CPPUNIT_ASSERT_EQUAL(3, c.get()->live_neighbors);
  }
  void test_update2(){
    Cell c = new FredkinCell();
    c.update(1,2);
    CPPUNIT_ASSERT_EQUAL(1, c.get()->live_neighbors);
  }
  void test_update3(){
    Cell c = new FredkinCell();
    c.update(4,2);
    CPPUNIT_ASSERT_EQUAL(4, c.get()->live_neighbors);
  }

  void test_commit1(){
    Cell c = new ConwayCell();
    c.get()->live_neighbors = 2;
    CPPUNIT_ASSERT_EQUAL(true, c.get()->alive);
    c.commit();
    CPPUNIT_ASSERT_EQUAL(true, c.get()->alive);
    c.get()->live_neighbors = 1;
    c.commit();
    CPPUNIT_ASSERT_EQUAL(false, c.get()->alive);
  }
  void test_commit2(){
    Cell c = new FredkinCell();
    c.get()->live_neighbors = 2;
    CPPUNIT_ASSERT_EQUAL(true, c.get()->alive);
    c.commit();
    CPPUNIT_ASSERT_EQUAL(false, c.get()->alive);
    c.get()->live_neighbors = 1;
    c.commit();
    CPPUNIT_ASSERT_EQUAL(true, c.get()->alive);
  }

  void test_commit3(){
    Cell c = new FredkinCell();
    FredkinCell* fp = dynamic_cast<FredkinCell*>(c.get());

    c.get()->live_neighbors = 1;
    CPPUNIT_ASSERT_EQUAL(true, c.get()->alive);
    CPPUNIT_ASSERT_EQUAL(0, fp->age);

    c.commit();
    fp = dynamic_cast<FredkinCell*>(c.get());

    CPPUNIT_ASSERT(fp != 0);
    CPPUNIT_ASSERT_EQUAL(true, c.get()->alive);
    CPPUNIT_ASSERT_EQUAL(1, fp->age);

    c.commit();
    ConwayCell* cp = dynamic_cast<ConwayCell*>(c.get());

    CPPUNIT_ASSERT(cp != 0);
    CPPUNIT_ASSERT_EQUAL(true, c.get()->alive);
    CPPUNIT_ASSERT_EQUAL(true, cp->alive);
  }

  CPPUNIT_TEST_SUITE(TestCell);
  

  CPPUNIT_TEST(test_default_constructor1);
  CPPUNIT_TEST(test_default_constructor2);

  CPPUNIT_TEST(test_double_angle_brackets1);
  CPPUNIT_TEST(test_double_angle_brackets2);
  CPPUNIT_TEST(test_double_angle_brackets3);

  CPPUNIT_TEST(test_update1);
  CPPUNIT_TEST(test_update2);
  CPPUNIT_TEST(test_update3);

  CPPUNIT_TEST(test_commit1);
  CPPUNIT_TEST(test_commit2);
  CPPUNIT_TEST(test_commit3);

  CPPUNIT_TEST_SUITE_END();
};

struct TestLife : CppUnit::TestFixture{

  //ignore adjacent
  //  zero diag should have zero even if there are adj
  //don't ignore diag
  //  four diag should have four even if there are no adj
  //test mix
  void test_get_diag_neighbors1(){
    std::vector<std::vector<ConwayCell> > cellVect(3, std::vector<ConwayCell>(3, ConwayCell(false)));
    cellVect[0][0].alive = true;;
    cellVect[2][2].alive = true;;
    cellVect[0][2].alive = true;;
    cellVect[2][0].alive = true;;
    Life<ConwayCell> life(cellVect);
    CPPUNIT_ASSERT_EQUAL(4, life.getDiagNeighbors(1,1));
  }
  void test_get_diag_neighbors2(){
    std::vector<std::vector<ConwayCell> > cellVect(3, std::vector<ConwayCell>(3, ConwayCell(false)));
    cellVect[0][1].alive = true;;
    cellVect[2][1].alive = true;;
    cellVect[1][2].alive = true;;
    cellVect[1][0].alive = true;;
    Life<ConwayCell> life(cellVect);
    CPPUNIT_ASSERT_EQUAL(0, life.getDiagNeighbors(1,1));
  }
  void test_get_diag_neighbors3(){
    std::vector<std::vector<ConwayCell> > cellVect(3, std::vector<ConwayCell>(3, ConwayCell(false)));
    cellVect[0][0].alive = true;;
    cellVect[2][2].alive = true;;
    cellVect[1][2].alive = true;;
    cellVect[1][0].alive = true;;
    Life<ConwayCell> life(cellVect);
    CPPUNIT_ASSERT_EQUAL(2, life.getDiagNeighbors(1,1));
  }

  void test_get_adj_neighbors1(){
    std::vector<std::vector<ConwayCell> > cellVect(3, std::vector<ConwayCell>(3, ConwayCell(false)));
    cellVect[0][0].alive = true;;
    cellVect[2][2].alive = true;;
    cellVect[0][2].alive = true;;
    cellVect[2][0].alive = true;;
    Life<ConwayCell> life(cellVect);
    CPPUNIT_ASSERT_EQUAL(0, life.getAdjNeighbors(1,1));
  }
  void test_get_adj_neighbors2(){
    std::vector<std::vector<ConwayCell> > cellVect(3, std::vector<ConwayCell>(3, ConwayCell(false)));
    cellVect[0][1].alive = true;;
    cellVect[2][1].alive = true;;
    cellVect[1][2].alive = true;;
    cellVect[1][0].alive = true;;
    Life<ConwayCell> life(cellVect);
    CPPUNIT_ASSERT_EQUAL(4, life.getAdjNeighbors(1,1));
  }
  void test_get_adj_neighbors3(){
    std::vector<std::vector<ConwayCell> > cellVect(3, std::vector<ConwayCell>(3, ConwayCell(false)));
    cellVect[0][0].alive = true;;
    cellVect[2][2].alive = true;;
    cellVect[1][2].alive = true;;
    cellVect[1][0].alive = true;;
    Life<ConwayCell> life(cellVect);
    CPPUNIT_ASSERT_EQUAL(2, life.getAdjNeighbors(1,1));
  }


  //Things to test
  //verify that l/w are getting set properly
  //verify that things are the correct type
  //population is correct
  //generation is correct
  void test_life_constructor1(){
    typedef ConwayCell cell_type;
    std::vector<std::vector<cell_type> > cellVect(3, std::vector<cell_type>(3, cell_type(false)));
    Life<cell_type> life(cellVect);
    CPPUNIT_ASSERT_EQUAL(0, life.population);
    CPPUNIT_ASSERT_EQUAL(3, life.height);
    CPPUNIT_ASSERT_EQUAL(3, life.width);
    CPPUNIT_ASSERT_EQUAL(0, life.generation);
  }
  void test_life_constructor2(){
    typedef ConwayCell cell_type;
    std::vector<std::vector<cell_type> > cellVect(3, std::vector<cell_type>(3, cell_type(true)));
    Life<cell_type> life(cellVect);
    CPPUNIT_ASSERT_EQUAL(9, life.population);
    CPPUNIT_ASSERT_EQUAL(3, life.height);
    CPPUNIT_ASSERT_EQUAL(3, life.width);
    CPPUNIT_ASSERT_EQUAL(0, life.generation);
  }
  void test_life_constructor3(){
    typedef ConwayCell cell_type;
    std::vector<std::vector<cell_type> > cellVect(5, std::vector<cell_type>(2, cell_type(true)));
    Life<cell_type> life(cellVect);
    CPPUNIT_ASSERT_EQUAL(10, life.population);
    CPPUNIT_ASSERT_EQUAL(5, life.height);
    CPPUNIT_ASSERT_EQUAL(2, life.width);
    CPPUNIT_ASSERT_EQUAL(0, life.generation);
  }

  void test_life_constructor4(){
    typedef FredkinCell cell_type;
    std::vector<std::vector<cell_type> > cellVect(3, std::vector<cell_type>(3, cell_type(false)));
    Life<cell_type> life(cellVect);
    CPPUNIT_ASSERT_EQUAL(0, life.population);
    CPPUNIT_ASSERT_EQUAL(3, life.height);
    CPPUNIT_ASSERT_EQUAL(3, life.width);
    CPPUNIT_ASSERT_EQUAL(0, life.generation);
  }
  void test_life_constructor5(){
    typedef FredkinCell cell_type;
    std::vector<std::vector<cell_type> > cellVect(3, std::vector<cell_type>(3, cell_type(true)));
    Life<cell_type> life(cellVect);
    CPPUNIT_ASSERT_EQUAL(9, life.population);
    CPPUNIT_ASSERT_EQUAL(3, life.height);
    CPPUNIT_ASSERT_EQUAL(3, life.width);
    CPPUNIT_ASSERT_EQUAL(0, life.generation);
  }
  void test_life_constructor6(){
    typedef FredkinCell cell_type;
    std::vector<std::vector<cell_type> > cellVect(5, std::vector<cell_type>(2, cell_type(true)));
    Life<cell_type> life(cellVect);
    CPPUNIT_ASSERT_EQUAL(10, life.population);
    CPPUNIT_ASSERT_EQUAL(5, life.height);
    CPPUNIT_ASSERT_EQUAL(2, life.width);
    CPPUNIT_ASSERT_EQUAL(0, life.generation);
  }

  void test_life_constructor7(){
    typedef Cell cell_type;
    std::vector<std::vector<cell_type> > cellVect(3, std::vector<cell_type>(3, new FredkinCell(false)));
    Life<cell_type> life(cellVect);
    CPPUNIT_ASSERT_EQUAL(0, life.population);
    CPPUNIT_ASSERT_EQUAL(3, life.height);
    CPPUNIT_ASSERT_EQUAL(3, life.width);
    CPPUNIT_ASSERT_EQUAL(0, life.generation);
  }
  void test_life_constructor8(){
    typedef Cell cell_type;
    std::vector<std::vector<cell_type> > cellVect(3, std::vector<cell_type>(3, new FredkinCell(true)));
    Life<cell_type> life(cellVect);
    CPPUNIT_ASSERT_EQUAL(9, life.population);
    CPPUNIT_ASSERT_EQUAL(3, life.height);
    CPPUNIT_ASSERT_EQUAL(3, life.width);
    CPPUNIT_ASSERT_EQUAL(0, life.generation);
  }
  void test_life_constructor9(){
    typedef Cell cell_type;
    std::vector<std::vector<cell_type> > cellVect(5, std::vector<cell_type>(2, new FredkinCell(true)));
    Life<cell_type> life(cellVect);
    CPPUNIT_ASSERT_EQUAL(10, life.population);
    CPPUNIT_ASSERT_EQUAL(5, life.height);
    CPPUNIT_ASSERT_EQUAL(2, life.width);
    CPPUNIT_ASSERT_EQUAL(0, life.generation);
  }

  //Test flipper across a couple phases
  void test_evolve1(){
    std::vector<std::vector<ConwayCell> > cellVect(3, std::vector<ConwayCell>(3, ConwayCell(false)));
    cellVect[1][0].alive = true;
    cellVect[1][1].alive = true;
    cellVect[1][2].alive = true;
    Life<ConwayCell> life(cellVect);

    for(int i=0; i<10; i++){
      if(i%2==0){
        CPPUNIT_ASSERT(life.grid[0][0].alive == false);
        CPPUNIT_ASSERT(life.grid[0][1].alive == false);
        CPPUNIT_ASSERT(life.grid[0][2].alive == false);

        CPPUNIT_ASSERT(life.grid[1][0].alive == true);
        CPPUNIT_ASSERT(life.grid[1][1].alive == true);
        CPPUNIT_ASSERT(life.grid[1][2].alive == true);

        CPPUNIT_ASSERT(life.grid[2][0].alive == false);
        CPPUNIT_ASSERT(life.grid[2][1].alive == false);
        CPPUNIT_ASSERT(life.grid[2][2].alive == false);
      } else {
        CPPUNIT_ASSERT(life.grid[0][0].alive == false);
        CPPUNIT_ASSERT(life.grid[1][0].alive == false);
        CPPUNIT_ASSERT(life.grid[2][0].alive == false);

        CPPUNIT_ASSERT(life.grid[0][1].alive == true);
        CPPUNIT_ASSERT(life.grid[1][1].alive == true);
        CPPUNIT_ASSERT(life.grid[2][1].alive == true);

        CPPUNIT_ASSERT(life.grid[0][2].alive == false);
        CPPUNIT_ASSERT(life.grid[1][2].alive == false);
        CPPUNIT_ASSERT(life.grid[2][2].alive == false);
      }
        life.evolve();
    }
  }
  //Test static square across a couple phases
  void test_evolve2(){
    std::vector<std::vector<ConwayCell> > cellVect(4, std::vector<ConwayCell>(4, ConwayCell(false)));
    cellVect[1][1].alive = true;
    cellVect[1][2].alive = true;
    cellVect[2][1].alive = true;
    cellVect[2][2].alive = true;

    Life<ConwayCell> life(cellVect);

    //Test that outer ring is dead while inner square remains alive
    for(int i=0; i<10; i++){
      for(int k =0; k<3; k++){
        CPPUNIT_ASSERT(life.grid[0][k].alive == false);
        CPPUNIT_ASSERT(life.grid[3][k].alive == false);
        CPPUNIT_ASSERT(life.grid[k][0].alive == false);
        CPPUNIT_ASSERT(life.grid[k][0].alive == false);
      }

      CPPUNIT_ASSERT(life.grid[1][1].alive == true);
      CPPUNIT_ASSERT(life.grid[1][2].alive == true);
      CPPUNIT_ASSERT(life.grid[2][1].alive == true);
      CPPUNIT_ASSERT(life.grid[2][2].alive == true);
      
    }


  }

  void test_evolve3(){
    std::vector<std::vector<FredkinCell> > cellVect(3, std::vector<FredkinCell>(3, FredkinCell(false)));
    cellVect[1][1].alive = true;
    Life<FredkinCell> life(cellVect);

    CPPUNIT_ASSERT_EQUAL(1, life.population);
    life.evolve();
    CPPUNIT_ASSERT_EQUAL(4, life.population);
    CPPUNIT_ASSERT(life.grid[1][1].alive == false);
    CPPUNIT_ASSERT(life.grid[0][1].alive == true);
    CPPUNIT_ASSERT(life.grid[1][0].alive == true);
    CPPUNIT_ASSERT(life.grid[1][2].alive == true);
    CPPUNIT_ASSERT(life.grid[2][1].alive == true);

    life.evolve();

    CPPUNIT_ASSERT_EQUAL(0, life.population);
    for(int h = 0; h<3; h++){
      for(int w = 0; w<3; w++){
        CPPUNIT_ASSERT(life.grid[h][w].alive == false);
      }
    }
  }

  //need fredkin evolve tests

  //Print tests:
  //verify that order is proper in x
  //verify that order is proper in y
  //verifty that structure is correct
    //correct gen, etc
  //copy paste some stuff

  //Fredkin
  void test_print1(){
    std::vector<std::vector<ConwayCell> > cellVect(3, std::vector<ConwayCell>(3, ConwayCell(false)));
    cellVect[1][0].alive = true;
    cellVect[1][1].alive = true;
    cellVect[1][2].alive = true;
    Life<ConwayCell> life(cellVect);

    std::string expected1 = 
      "Generation = 0, Population = 3.\n"
      "...\n"
      "***\n"
      "...\n\n";
    std::string expected2 = 
      "Generation = 1, Population = 3.\n"
      ".*.\n"
      ".*.\n"
      ".*.\n\n";
    std::string expected3 = 
      "Generation = 2, Population = 3.\n"
      "...\n"
      "***\n"
      "...\n\n";

    std::stringstream o;
    life.print(o);
    CPPUNIT_ASSERT_EQUAL(expected1, o.str());
    o.str(std::string());
    o.clear();

    life.evolve();
    life.print(o);
    CPPUNIT_ASSERT_EQUAL(expected2, o.str());
    o.str(std::string());
    o.clear();

    life.evolve();
    life.print(o);
    CPPUNIT_ASSERT_EQUAL(expected3, o.str());
    o.str(std::string());
    o.clear();
  }

  //Conway
  void test_print2(){
    std::vector<std::vector<FredkinCell> > cellVect(3, std::vector<FredkinCell>(3, FredkinCell(false)));
    cellVect[1][1].alive = true;
    Life<FredkinCell> life(cellVect);

    std::string expected1 = 
      "Generation = 0, Population = 1.\n"
      "---\n"
      "-0-\n"
      "---\n\n";
    std::string expected2 = 
      "Generation = 1, Population = 4.\n"
      "-0-\n"
      "0-0\n"
      "-0-\n\n";
    std::string expected3 = 
      "Generation = 2, Population = 0.\n"
      "---\n"
      "---\n"
      "---\n\n";

    std::stringstream o;
    life.print(o);
    CPPUNIT_ASSERT_EQUAL(expected1, o.str());
    o.str(std::string());
    o.clear();

    life.evolve();
    life.print(o);
    CPPUNIT_ASSERT_EQUAL(expected2, o.str());
    o.str(std::string());
    o.clear();

    life.evolve();
    life.print(o);
    CPPUNIT_ASSERT_EQUAL(expected3, o.str());
    o.str(std::string());
    o.clear();
  }

  //Both
  void test_print3(){
    std::vector<std::vector<Cell> > cellVect(3, std::vector<Cell>(3, new FredkinCell(false)));
    cellVect[0][0] = new ConwayCell(true);
    cellVect[2][2] = new FredkinCell(true);

    Life<Cell> life(cellVect);

    std::string expected1 = 
      "Generation = 0, Population = 2.\n"
      "*--\n"
      "---\n"
      "--0\n\n";

    std::string expected2 = 
      "Generation = 1, Population = 4.\n"
      ".0-\n"
      "0-0\n"
      "-0-\n\n";
    std::string expected3 = 
      "Generation = 2, Population = 0.\n"
      ".--\n"
      "---\n"
      "---\n\n";
    
    std::stringstream o;
    life.print(o);
    CPPUNIT_ASSERT_EQUAL(expected1, o.str());
    o.str(std::string());
    o.clear();

    life.evolve();
    life.print(o);
    CPPUNIT_ASSERT_EQUAL(expected2, o.str());
    o.str(std::string());
    o.clear();

    life.evolve();
    life.print(o);
    CPPUNIT_ASSERT_EQUAL(expected3, o.str());
    o.str(std::string());
    o.clear();
  }
  void test_print4(){
    std::vector<std::vector<Cell> > cellVect(2, std::vector<Cell>(3, new FredkinCell(false)));
    cellVect[1][2] = new FredkinCell(true);
    cellVect[1][1] = new FredkinCell(true);

    Life<Cell> life(cellVect);
    CPPUNIT_ASSERT_EQUAL(2, life.height);
    CPPUNIT_ASSERT_EQUAL(3, life.width);

    std::string expected1 = 
      "Generation = 0, Population = 2.\n"
      "---\n"
      "-00\n\n";
    std::string expected2 = 
      "Generation = 1, Population = 5.\n"
      "-00\n"
      "011\n\n";
    std::string expected3 = 
      "Generation = 2, Population = 2.\n"
      "---\n"
      "1*-\n\n";

    std::stringstream o;
    life.print(o);
    CPPUNIT_ASSERT_EQUAL(expected1, o.str());
    o.str(std::string());
    o.clear();

    CPPUNIT_ASSERT_EQUAL(true, life.grid[1][1].is_alive());

    life.evolve();

    CPPUNIT_ASSERT_EQUAL(1, life.grid[1][1].get()->live_neighbors);
    CPPUNIT_ASSERT_EQUAL(true, life.grid[1][1].is_alive());

    life.print(o);
    CPPUNIT_ASSERT_EQUAL(expected2, o.str());
    o.str(std::string());
    o.clear();

    life.evolve();
    life.print(o);
    CPPUNIT_ASSERT_EQUAL(expected3, o.str());
    o.str(std::string());
    o.clear();
  }

  CPPUNIT_TEST_SUITE(TestLife);

  CPPUNIT_TEST(test_get_diag_neighbors1);
  CPPUNIT_TEST(test_get_diag_neighbors2);
  CPPUNIT_TEST(test_get_diag_neighbors3);

  CPPUNIT_TEST(test_get_adj_neighbors1);
  CPPUNIT_TEST(test_get_adj_neighbors2);
  CPPUNIT_TEST(test_get_adj_neighbors3);

  CPPUNIT_TEST(test_life_constructor1);
  CPPUNIT_TEST(test_life_constructor2);
  CPPUNIT_TEST(test_life_constructor3);
  CPPUNIT_TEST(test_life_constructor4);
  CPPUNIT_TEST(test_life_constructor5);
  CPPUNIT_TEST(test_life_constructor6);
  CPPUNIT_TEST(test_life_constructor7);
  CPPUNIT_TEST(test_life_constructor8);
  CPPUNIT_TEST(test_life_constructor9);

  CPPUNIT_TEST(test_print1);
  CPPUNIT_TEST(test_print2);
  CPPUNIT_TEST(test_print3);
  CPPUNIT_TEST(test_print4);

  CPPUNIT_TEST(test_evolve1);
  CPPUNIT_TEST(test_evolve2);
  CPPUNIT_TEST(test_evolve3);

  CPPUNIT_TEST_SUITE_END();
};

int main(){
  CppUnit::TextTestRunner tr;
  tr.addTest(TestLife::suite());
  tr.addTest(TestAbstractCell::suite());
  tr.addTest(TestFredkinCell::suite());
  tr.addTest(TestConwayCell::suite());
  tr.addTest(TestCell::suite());
  tr.run();
  return 0;
}
