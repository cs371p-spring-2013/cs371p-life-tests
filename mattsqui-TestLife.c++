// ---
// includes
// ---

#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>

#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TextTestRunner.h"

#define protected public
#define private public

#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Life.h"

using namespace std;

// ---
// TestLife
// ---

struct TestLife : CppUnit::TestFixture {
  // test functions

  //conway default constructor
  void test_conwayConstructor () {
    ConwayCell c = ConwayCell();
    CPPUNIT_ASSERT(c.isAlive == false);
    CPPUNIT_ASSERT(c.rep == '.');
    CPPUNIT_ASSERT(c.aliveNeighbors == 0);
  }

  // conway char constructor
  void test_conwayCharConstructor1 () {
    ConwayCell c = ConwayCell('*');
    CPPUNIT_ASSERT(c.isAlive == true);
    CPPUNIT_ASSERT(c.rep == '*');
    CPPUNIT_ASSERT(c.aliveNeighbors == 0);
  }
  
  void test_conwayCharConstructor2 () {
    ConwayCell c = ConwayCell('.');
    CPPUNIT_ASSERT(c.isAlive == false);
    CPPUNIT_ASSERT(c.rep == '.');
    CPPUNIT_ASSERT(c.aliveNeighbors == 0);
  }

  // conway canMutate
  void test_conway_canMutate1 () {
    ConwayCell c = ConwayCell();
    CPPUNIT_ASSERT(!c.canMutate());
  }

  void test_conway_canMutate2 () {
    ConwayCell c = ConwayCell('.');
    CPPUNIT_ASSERT(!c.canMutate());
  }

  void test_conway_canMutate3 () {
    ConwayCell c = ConwayCell('*');
    CPPUNIT_ASSERT(!c.canMutate());
  }

  // conway canMutate2
  void test_conway_canMutate21 () {
    ConwayCell c = ConwayCell();
    CPPUNIT_ASSERT(!c.canMutate2());
  }

  void test_conway_canMutate22 () {
    ConwayCell c = ConwayCell('.');
    CPPUNIT_ASSERT(!c.canMutate2());
  }

  void test_conway_canMutate23 () {
    ConwayCell c = ConwayCell('*');
    CPPUNIT_ASSERT(!c.canMutate2());
  }

  // conway evolve
  void test_conway_evolve1 () {
    ConwayCell c = ConwayCell('*');
    c.aliveNeighbors = 1;
    c.evolve();
    CPPUNIT_ASSERT(c.isAlive == false);
    CPPUNIT_ASSERT(c.rep == '.');
  }

  void test_conway_evolve2 () {
    ConwayCell c = ConwayCell('.');
    c.aliveNeighbors = 3;
    c.evolve();
    CPPUNIT_ASSERT(c.isAlive == true);
    CPPUNIT_ASSERT(c.rep == '*');
  }
  
  void test_conway_evolve3 () {
    ConwayCell c = ConwayCell('.');
    c.aliveNeighbors = 4;
    c.evolve();
    CPPUNIT_ASSERT(c.isAlive == false);
    CPPUNIT_ASSERT(c.rep == '.');
  }

  // conway checkNeighbors
  void test_conway_checkNeighbors1 () {
    ConwayCell c = ConwayCell('*');

    AbstractCell* p = new ConwayCell('*');
    c.neighbors.push_back(p);
    p = new ConwayCell('*');
    c.neighbors.push_back(p);
    p = new ConwayCell('.');
    c.neighbors.push_back(p);
    p = new ConwayCell('.');
    c.neighbors.push_back(p);

    c.checkNeighbors();
    CPPUNIT_ASSERT(c.aliveNeighbors == 2);

  }
    
  void test_conway_checkNeighbors2 () {
    ConwayCell c = ConwayCell('*');

    AbstractCell* p = new ConwayCell('*');
    c.neighbors.push_back(p);
    p = new ConwayCell('*');
    c.neighbors.push_back(p);
    p = new ConwayCell('*');
    c.neighbors.push_back(p);
    p = new ConwayCell('.');
    c.neighbors.push_back(p);

    c.checkNeighbors();
    CPPUNIT_ASSERT(c.aliveNeighbors == 3);

  }
  void test_conway_checkNeighbors3 () {
    ConwayCell c = ConwayCell('*');

    AbstractCell* p = new ConwayCell('*');
    c.neighbors.push_back(p);
    p = new ConwayCell('*');
    c.neighbors.push_back(p);
    p = new ConwayCell('*');
    c.neighbors.push_back(p);
    p = new ConwayCell('*');
    c.neighbors.push_back(p);

    c.checkNeighbors();
    CPPUNIT_ASSERT(c.aliveNeighbors == 4);

  }

  // conway clone
  void test_conway_clone1 () {
    ConwayCell c = ConwayCell('*');
    AbstractCell* p = c.clone();
    CPPUNIT_ASSERT(p->isAlive == true);
    CPPUNIT_ASSERT(p->rep == '*');
    CPPUNIT_ASSERT(p->aliveNeighbors == 0);
  }  
 
  void test_conway_clone2 () {
    ConwayCell c = ConwayCell('.');
    AbstractCell* p = c.clone();
    CPPUNIT_ASSERT(p->isAlive == false);
    CPPUNIT_ASSERT(p->rep == '.');
    CPPUNIT_ASSERT(p->aliveNeighbors == 0);
  }
  void test_conway_clone3() {
    ConwayCell c = ConwayCell();
    AbstractCell* p = c.clone();
    CPPUNIT_ASSERT(p->isAlive == false);
    CPPUNIT_ASSERT(p->rep == '.');
    CPPUNIT_ASSERT(p->aliveNeighbors == 0);
  }

  // conway toChar
  void test_conway_toChar1 () {
    ConwayCell c  = ConwayCell('*');
    CPPUNIT_ASSERT(c.toChar() == '*');
  } 

  void test_conway_toChar2 () {
    ConwayCell c  = ConwayCell('.');
    CPPUNIT_ASSERT(c.toChar() == '.');
  }

  void test_conway_toChar3 () {
    ConwayCell c  = ConwayCell();
    CPPUNIT_ASSERT(c.toChar() == '.');
  }


  // conway getNeighbors
  void test_conway_getNeighbors1 () {
    ConwayCell c = ConwayCell('*');
    AbstractCell* p = new ConwayCell('*');
    c.neighbors.push_back(p);
    p = new ConwayCell('*');
    c.neighbors.push_back(p);
    p = new ConwayCell('*');
    c.neighbors.push_back(p);
    p = new ConwayCell('.');
    c.neighbors.push_back(p);
    
    CPPUNIT_ASSERT(c.getNeighbors() == c.neighbors);
  }

  void test_conway_getNeighbors2 () {
    ConwayCell c = ConwayCell('.');
    AbstractCell* p = new ConwayCell('.');
    c.neighbors.push_back(p);
    p = new ConwayCell('*');
    c.neighbors.push_back(p);
    p = new ConwayCell('*');
    c.neighbors.push_back(p);

    CPPUNIT_ASSERT(c.getNeighbors() == c.neighbors);
  }

  void test_conway_getNeighbors3 () {
    ConwayCell c = ConwayCell('*');
    AbstractCell* p = new ConwayCell('*');
    c.neighbors.push_back(p);
    p = new ConwayCell('.');
    c.neighbors.push_back(p);

    CPPUNIT_ASSERT(c.getNeighbors() == c.neighbors);
  }

  // conway getp
  void test_conway_getp1 () {
    ConwayCell c = ConwayCell();
    AbstractCell* p = c.getp();
    CPPUNIT_ASSERT(p->isAlive == false);
    CPPUNIT_ASSERT(p->aliveNeighbors == 0);
    CPPUNIT_ASSERT(p->rep == '.');
  }

  void test_conway_getp2 () {
    ConwayCell c = ConwayCell('.');
    AbstractCell* p = c.getp();
    CPPUNIT_ASSERT(p->isAlive == false);
    CPPUNIT_ASSERT(p->aliveNeighbors == 0);
    CPPUNIT_ASSERT(p->rep == '.');
  }
  
  void test_conway_getp3 () {
    ConwayCell c = ConwayCell('*');
    AbstractCell* p = c.getp();
    CPPUNIT_ASSERT(p->isAlive == true);
    CPPUNIT_ASSERT(p->aliveNeighbors == 0);
    CPPUNIT_ASSERT(p->rep == '*');
  }
  
  // fredkin default constructor
  void test_fredkinConstructor () {
    FredkinCell c = FredkinCell();
    CPPUNIT_ASSERT(c.aliveNeighbors == 0);
    CPPUNIT_ASSERT(c.isAlive == false);
    CPPUNIT_ASSERT(c.rep == '-');
    CPPUNIT_ASSERT(c.age == 0);
  }

  // fredkin char constructor
  void test_fredkinCharConstructor1 () {
    FredkinCell c = FredkinCell('-');
    CPPUNIT_ASSERT(c.aliveNeighbors == 0);
    CPPUNIT_ASSERT(c.isAlive == false);
    CPPUNIT_ASSERT(c.rep == '-');
    CPPUNIT_ASSERT(c.age == 0);
  }

  void test_fredkinCharConstructor2 () {
    FredkinCell c = FredkinCell('0');
    CPPUNIT_ASSERT(c.aliveNeighbors == 0);
    CPPUNIT_ASSERT(c.isAlive == true);
    CPPUNIT_ASSERT(c.rep == '0');
    CPPUNIT_ASSERT(c.age == 0);
  }

  // fredkin canMutate
  void test_fredkin_canMutate1 () {
    FredkinCell c = FredkinCell();
    CPPUNIT_ASSERT(!c.canMutate());
  }

  void test_fredkin_canMutate2 () {
    FredkinCell c = FredkinCell('-');
    CPPUNIT_ASSERT(!c.canMutate());
  }

  void test_fredkin_canMutate3 () {
    FredkinCell c = FredkinCell('0');
    CPPUNIT_ASSERT(!c.canMutate());
  }

  // fredkin canMutate2
  void test_fredkin_canMutate21 () {
    FredkinCell c = FredkinCell();
    CPPUNIT_ASSERT(!c.canMutate2());
  }

  void test_fredkin_canMutate22 () {
    FredkinCell c = FredkinCell('-');
    CPPUNIT_ASSERT(!c.canMutate2());
  }

  void test_fredkin_canMutate23 () {
    FredkinCell c = FredkinCell('0');
    c.age = 2;
    CPPUNIT_ASSERT(c.canMutate2());
  }

  // fredkin evolve
  void test_fredkin_evolve1 () {
    FredkinCell c = FredkinCell('0');
    c.aliveNeighbors = 2;
    c.evolve();
    CPPUNIT_ASSERT(c.isAlive == false);
    CPPUNIT_ASSERT(c.rep == '-');
  }

  void test_fredkin_evolve2 () {
    FredkinCell c = FredkinCell('-');
    c.aliveNeighbors = 3;
    c.evolve();
    CPPUNIT_ASSERT(c.isAlive == true);
    CPPUNIT_ASSERT(c.rep == '0');
  }

  void test_fredkin_evolve3 () {
    FredkinCell c = FredkinCell('-');
    c.aliveNeighbors = 4;
    c.evolve();
    CPPUNIT_ASSERT(c.isAlive == false);
    CPPUNIT_ASSERT(c.rep == '-');
  }

  // fredkin checkNeighbors
  void test_fredkin_checkNeighbors1 () {
    FredkinCell c = FredkinCell('0');

    AbstractCell* p = new FredkinCell('0');
    c.neighbors.push_back(p);
    p = new FredkinCell('0');
    c.neighbors.push_back(p);
    p = new FredkinCell('-');
    c.neighbors.push_back(p);
    p = new FredkinCell('-');
    c.neighbors.push_back(p);

    c.checkNeighbors();
    CPPUNIT_ASSERT(c.aliveNeighbors == 1);

  }

  void test_fredkin_checkNeighbors2 () {
    FredkinCell c = FredkinCell('0');

    AbstractCell* p = new FredkinCell('0');
    c.neighbors.push_back(p);
    p = new FredkinCell('0');
    c.neighbors.push_back(p);
    p = new FredkinCell('0');
    c.neighbors.push_back(p);
    p = new FredkinCell('-');
    c.neighbors.push_back(p);

    c.checkNeighbors();
    CPPUNIT_ASSERT(c.aliveNeighbors == 2);

  }

  void test_fredkin_checkNeighbors3 () {
    FredkinCell c = FredkinCell('0');

    AbstractCell* p = new FredkinCell('0');
    c.neighbors.push_back(p);
    p = new FredkinCell('0');
    c.neighbors.push_back(p);
    p = new FredkinCell('0');
    c.neighbors.push_back(p);
    p = new FredkinCell('0');
    c.neighbors.push_back(p);
    p = new FredkinCell('0');
    c.neighbors.push_back(p);

    c.checkNeighbors();
    CPPUNIT_ASSERT(c.aliveNeighbors == 3);

  }

  // fredkin clone
  void test_fredkin_clone1 () {
    FredkinCell c = FredkinCell('0');
    AbstractCell* p = c.clone();
    CPPUNIT_ASSERT(p->isAlive == true);
    CPPUNIT_ASSERT(p->rep == '0');
    CPPUNIT_ASSERT(p->aliveNeighbors == 0);
  }

  void test_fredkin_clone2 () {
    FredkinCell c = FredkinCell('-');
    AbstractCell* p = c.clone();
    CPPUNIT_ASSERT(p->isAlive == false);
    CPPUNIT_ASSERT(p->rep == '-');
    CPPUNIT_ASSERT(p->aliveNeighbors == 0);
  }

  void test_fredkin_clone3() { 
    FredkinCell c = FredkinCell();
    AbstractCell* p = c.clone();
    CPPUNIT_ASSERT(p->isAlive == false);
    CPPUNIT_ASSERT(p->rep == '-');
    CPPUNIT_ASSERT(p->aliveNeighbors == 0);
  }

  // fredkin toChar
  void test_fredkin_toChar1 () {
    FredkinCell c  = FredkinCell('0');
    CPPUNIT_ASSERT(c.toChar() == '0');
  }

  void test_fredkin_toChar2 () {
    FredkinCell c  = FredkinCell('-');
    CPPUNIT_ASSERT(c.toChar() == '-');
  }
  
  void test_fredkin_toChar3 () {
    FredkinCell c  = FredkinCell();
    CPPUNIT_ASSERT(c.toChar() == '-');
  }

  // fredkin getNeighbors
  void test_fredkin_getNeighbors1 () {
    FredkinCell c = FredkinCell('0');
    AbstractCell* p = new FredkinCell('0');
    c.neighbors.push_back(p);
    p = new FredkinCell('0');
    c.neighbors.push_back(p);
    p = new FredkinCell('0');
    c.neighbors.push_back(p);
    p = new FredkinCell('-');
    c.neighbors.push_back(p);

    CPPUNIT_ASSERT(c.getNeighbors() == c.neighbors);
  }

  void test_fredkin_getNeighbors2 () {
    FredkinCell c = FredkinCell('-');
    AbstractCell* p = new FredkinCell('-');
    c.neighbors.push_back(p);
    p = new FredkinCell('0');
    c.neighbors.push_back(p);
    p = new FredkinCell('0');
    c.neighbors.push_back(p);

    CPPUNIT_ASSERT(c.getNeighbors() == c.neighbors);
  }

  void test_fredkin_getNeighbors3 () {
    FredkinCell c = FredkinCell('0');
    AbstractCell* p = new FredkinCell('0');
    c.neighbors.push_back(p);
    p = new FredkinCell('-');
    c.neighbors.push_back(p);

    CPPUNIT_ASSERT(c.getNeighbors() == c.neighbors);
  }
  
  // fredkin getp
  void test_fredkin_getp1 () {
    FredkinCell c = FredkinCell();
    AbstractCell* p = c.getp();
    CPPUNIT_ASSERT(p->isAlive == false);
    CPPUNIT_ASSERT(p->aliveNeighbors == 0);
    CPPUNIT_ASSERT(p->rep == '-');
  }

  void test_fredkin_getp2 () {
    FredkinCell c = FredkinCell('-');
    AbstractCell* p = c.getp();
    CPPUNIT_ASSERT(p->isAlive == false);
    CPPUNIT_ASSERT(p->aliveNeighbors == 0);
    CPPUNIT_ASSERT(p->rep == '-');  
  }
 
  void test_fredkin_getp3 () {
    FredkinCell c = FredkinCell('0');
    AbstractCell* p = c.getp();
    CPPUNIT_ASSERT(p->isAlive == true);
    CPPUNIT_ASSERT(p->aliveNeighbors == 0);
    CPPUNIT_ASSERT(p->rep == '0');
  }

  // cell default constructor
  void test_cellConstructor () {
    Cell c = Cell();
    CPPUNIT_ASSERT(c.get()->rep == '-');
    CPPUNIT_ASSERT(c.get()->isAlive == false);
    CPPUNIT_ASSERT(c.get()->aliveNeighbors == 0);
  }

  // cell pointer constructor
  void test_cellPointConstructor1 () {
    AbstractCell* p = new ConwayCell('.');
    Cell c = Cell(p);
    CPPUNIT_ASSERT(c.get()->rep == '.');
    CPPUNIT_ASSERT(c.get()->isAlive == false);
    CPPUNIT_ASSERT(c.get()->aliveNeighbors == 0);
  }

  void test_cellPointConstructor2 () {
    AbstractCell* p = new FredkinCell('-');
    Cell c = Cell(p);
    CPPUNIT_ASSERT(c.get()->rep == '-');
    CPPUNIT_ASSERT(c.get()->isAlive == false);
    CPPUNIT_ASSERT(c.get()->aliveNeighbors == 0);
  }

  void test_cellPointConstructor3 () {
    AbstractCell* p = new FredkinCell('0');
    Cell c = Cell(p);
    CPPUNIT_ASSERT(c.get()->rep == '0');
    CPPUNIT_ASSERT(c.get()->isAlive == true);
    CPPUNIT_ASSERT(c.get()->aliveNeighbors == 0);
  }

  // cell char constructor
  void test_cellCharConstructor1 () {
    Cell c = Cell('0');
    CPPUNIT_ASSERT(c.get()->rep == '0');
    CPPUNIT_ASSERT(c.get()->isAlive == true);
    CPPUNIT_ASSERT(c.get()->aliveNeighbors == 0);
  }

  void test_cellCharConstructor2 () {
    Cell c = Cell('-');
    CPPUNIT_ASSERT(c.get()->rep == '-');
    CPPUNIT_ASSERT(c.get()->isAlive == false);
    CPPUNIT_ASSERT(c.get()->aliveNeighbors == 0);
  }

  // cell int constructor
  void test_cellIntConstructor () {
    Cell c = Cell(3);
    CPPUNIT_ASSERT(c.get()->rep == '*');
    CPPUNIT_ASSERT(c.get()->isAlive == true);
    CPPUNIT_ASSERT(c.get()->aliveNeighbors == 0);
  }

  // cell tochar
  void test_cell_toChar1 () {
    AbstractCell* p = new ConwayCell('.');
    Cell c = Cell(p);
    CPPUNIT_ASSERT(c.toChar() == '.');
  }

  void test_cell_toChar2 () {
    AbstractCell* p = new FredkinCell('-');
    Cell c = Cell(p);
    CPPUNIT_ASSERT(c.toChar() == '-');
  }

  void test_cell_toChar3 () {
    AbstractCell* p = new ConwayCell('0');
    Cell c = Cell(p);
    CPPUNIT_ASSERT(c.toChar() == '0');
  }

  // cell getNeighbors
  void test_cell_getNeighbors1 () {
    AbstractCell* p = new ConwayCell('.');
    Cell c = Cell(p);
    CPPUNIT_ASSERT(c.getNeighbors() == p->neighbors);
  }

  void test_cell_getNeighbors2 () {
    AbstractCell* p = new ConwayCell('*');
    Cell c = Cell(p);
    CPPUNIT_ASSERT(c.getNeighbors() == p->neighbors);
  }

  void test_cell_getNeighbors3 () {
    AbstractCell* p = new FredkinCell('0');
    Cell c = Cell(p);
    CPPUNIT_ASSERT(c.getNeighbors() == p->neighbors);
  }

  // cell getp
  void test_cell_getp1 () {
    AbstractCell* p = new ConwayCell('.');
    Cell c = Cell(p);
    CPPUNIT_ASSERT(c.getp() == p);
  }

  void test_cell_getp2 () {
    AbstractCell* p = new FredkinCell('-');
    Cell c = Cell(p);
    CPPUNIT_ASSERT(c.getp() == p);
  }

  void test_cell_getp3 () {
    AbstractCell* p = new FredkinCell('0');
    Cell c = Cell(p);
    CPPUNIT_ASSERT(c.getp() == p);
  }

  // cell canMutate
  void test_cell_canMutate1 () {
    AbstractCell* p = new ConwayCell('.');
    Cell c = Cell(p);
    CPPUNIT_ASSERT(c.canMutate() == false);
  }

  void test_cell_canMutate2 () {
    AbstractCell* p = new FredkinCell('-');
    Cell c = Cell(p);
    CPPUNIT_ASSERT(c.canMutate() == false);
  }

  void test_cell_canMutate3 () {
    FredkinCell* f = new FredkinCell('0');
    f->age = 2;
    AbstractCell* p = f;
    Cell c = Cell(p);
    CPPUNIT_ASSERT(c.canMutate() == true);
  }

  // cell evolve
  void test_cell_evolve1 () { 
    AbstractCell* p = new ConwayCell('.');
    p->aliveNeighbors = 3;
    Cell c = Cell(p);
    c.evolve();
    CPPUNIT_ASSERT(c.get()->isAlive == true);
    CPPUNIT_ASSERT(c.get()->rep == '*');
  }

  void test_cell_evolve2 () {
    AbstractCell* p = new FredkinCell('0');
    p->aliveNeighbors = 2;
    Cell c = Cell(p);
    c.evolve();
    CPPUNIT_ASSERT(c.get()->isAlive == false);
    CPPUNIT_ASSERT(c.get()->rep == '-');
  }

  void test_cell_evolve3 () {
    AbstractCell* p = new FredkinCell('-');
    p->aliveNeighbors = 1;
    Cell c = Cell(p);
    c.evolve();
    CPPUNIT_ASSERT(c.get()->isAlive == true);
    CPPUNIT_ASSERT(c.get()->rep == '0');
  }

  // cell checkNeighbors
  void test_cell_checkNeighbors1 () {
    AbstractCell* p = new ConwayCell('*');

    AbstractCell* p1 = new ConwayCell('*');
    p->neighbors.push_back(p1);
    p1 = new ConwayCell('*');
    p->neighbors.push_back(p1);
    p1 = new ConwayCell('*');
    p->neighbors.push_back(p1);
    p1 = new ConwayCell('*');
    p->neighbors.push_back(p1);

    Cell s = Cell(p);

    s.checkNeighbors();
    CPPUNIT_ASSERT(s.get()->aliveNeighbors == 4);
}

  void test_cell_checkNeighbors2 () {
    AbstractCell* p = new FredkinCell('0');

    AbstractCell* p1 = new FredkinCell('0');
    p->neighbors.push_back(p1);
    p1 = new FredkinCell('0');
    p->neighbors.push_back(p1);
    p1 = new FredkinCell('0');
    p->neighbors.push_back(p1);
    p1 = new FredkinCell('-');
    p->neighbors.push_back(p1);

    Cell s = Cell(p);

    s.checkNeighbors();
    CPPUNIT_ASSERT(s.get()->aliveNeighbors == 2);

  }

  void test_cell_checkNeighbors3 () {
    AbstractCell* p = new FredkinCell('0');

    AbstractCell* p1 = new FredkinCell('0');
    p->neighbors.push_back(p1);
    p1 = new FredkinCell('0');
    p->neighbors.push_back(p1);
    p1 = new FredkinCell('0');
    p->neighbors.push_back(p1);
    p1 = new FredkinCell('-');
    p->neighbors.push_back(p1);
    p1 = new FredkinCell('0');
    p->neighbors.push_back(p1);

    Cell s = Cell(p);

    s.checkNeighbors();
    CPPUNIT_ASSERT(s.get()->aliveNeighbors == 3);
  }



  // life constructor 
  void test_lifeConstructor1 () {
    Life<ConwayCell> l = Life<ConwayCell>(10, 10);
    CPPUNIT_ASSERT(l._generation == 0);
    CPPUNIT_ASSERT(l._population == 0);
    CPPUNIT_ASSERT(l.grid.size() == 10);
    CPPUNIT_ASSERT(l.grid[0].size() == 10);
  }

  void test_lifeConstructor2 () {
    Life<FredkinCell> l = Life<FredkinCell>(5, 10);
    CPPUNIT_ASSERT(l._generation == 0);
    CPPUNIT_ASSERT(l._population == 0);
    CPPUNIT_ASSERT(l.grid.size() == 5);
    CPPUNIT_ASSERT(l.grid[0].size() == 10);
  }

  void test_lifeConstructor3 () {
    Life<Cell> l = Life<Cell>(5, 5);
    CPPUNIT_ASSERT(l._generation == 0);
    CPPUNIT_ASSERT(l._population == 0);
    CPPUNIT_ASSERT(l.grid.size() == 5);
    CPPUNIT_ASSERT(l.grid[0].size() == 5);
  }

  // life createCell
  void test_life_createCell1 () {
    Life<ConwayCell> l = Life<ConwayCell>(10, 10);
    l.createCell(0, 0, '.');
    ConwayCell c = l.grid[0][0];
    CPPUNIT_ASSERT(c.rep == '.');
    CPPUNIT_ASSERT(c.isAlive == false);
    CPPUNIT_ASSERT(c.aliveNeighbors == 0);
    CPPUNIT_ASSERT(l._population == 0);
  }

  void test_life_createCell2 () {
    Life<FredkinCell> l = Life<FredkinCell>(10, 10);
    l.createCell(2, 3, '0');
    FredkinCell c = l.grid[2][3];
    CPPUNIT_ASSERT(c.rep == '0');
    CPPUNIT_ASSERT(c.isAlive == true);
    CPPUNIT_ASSERT(c.aliveNeighbors == 0);
    CPPUNIT_ASSERT(c.age == 0);
    CPPUNIT_ASSERT(l._population == 1);
  }

  void test_life_createCell3 () {
    Life<Cell> l = Life<Cell>(10, 10);
    l.createCell(1, 1, '-');
    Cell c = l.grid[1][1];
    CPPUNIT_ASSERT(c.get()->rep == '-');
    CPPUNIT_ASSERT(c.get()->isAlive == false);
    CPPUNIT_ASSERT(c.get()->aliveNeighbors == 0);
    CPPUNIT_ASSERT(l._population == 0);
  }
 
  // life setNeighbors
  void test_life_setNeighbors1 () {
    Life<ConwayCell> l = Life<ConwayCell>(3, 3);

    l.createCell(0, 0, '.');
    l.createCell(0, 1, '*');
    l.createCell(0, 2, '*');
    l.createCell(1, 0, '*');
    l.createCell(1, 1, '.');
    l.createCell(1, 2, '*');
    l.createCell(2, 0, '.');
    l.createCell(2, 1, '*');
    l.createCell(2, 2, '.');

    ConwayCell c = l.grid[1][1];
    l.setNeighbors(c, 1, 1);
    CPPUNIT_ASSERT(c.neighbors[0]->isAlive == true);
    CPPUNIT_ASSERT(c.neighbors[1]->isAlive == false);
    CPPUNIT_ASSERT(c.neighbors[2]->isAlive == true);
    CPPUNIT_ASSERT(c.neighbors[3]->isAlive == true);
    CPPUNIT_ASSERT(c.neighbors[4]->isAlive == true);
    CPPUNIT_ASSERT(c.neighbors[5]->isAlive == false);
    CPPUNIT_ASSERT(c.neighbors[6]->isAlive == true);
    CPPUNIT_ASSERT(c.neighbors[7]->isAlive == false);

  }
 
  void test_life_setNeighbors2 () {
    Life<FredkinCell> l = Life<FredkinCell>(3, 3);

    l.createCell(0, 0, '-');
    l.createCell(0, 1, '0');
    l.createCell(0, 2, '0');
    l.createCell(1, 0, '0');
    l.createCell(1, 1, '-');
    l.createCell(1, 2, '0');
    l.createCell(2, 0, '-');
    l.createCell(2, 1, '0');
    l.createCell(2, 2, '-');

    FredkinCell c = l.grid[1][2];
    l.setNeighbors(c, 1, 2);
    CPPUNIT_ASSERT(c.neighbors[0]->isAlive == false);
    CPPUNIT_ASSERT(c.neighbors[1]->isAlive == true);
    CPPUNIT_ASSERT(c.neighbors[2]->isAlive == false);
    CPPUNIT_ASSERT(c.neighbors[3]->isAlive == true);
    CPPUNIT_ASSERT(c.neighbors[4]->isAlive == true);

  }

  void test_life_setNeighbors3 () {
    Life<Cell> l = Life<Cell>(3, 3);

    l.createCell(0, 0, '.');
    l.createCell(0, 1, '*');
    l.createCell(0, 2, '*');
    l.createCell(1, 0, '*');
    l.createCell(1, 1, '.');
    l.createCell(1, 2, '*');
    l.createCell(2, 0, '.');
    l.createCell(2, 1, '*');
    l.createCell(2, 2, '.');

    Cell c = l.grid[2][0];
    l.setNeighbors(c, 2, 0);
    CPPUNIT_ASSERT(c.getNeighbors()[0]->isAlive == true);
    CPPUNIT_ASSERT(c.getNeighbors()[1]->isAlive == false);
    CPPUNIT_ASSERT(c.getNeighbors()[2]->isAlive == true);

  }
  
  // life play
  void test_life_play1 () {
    Life<ConwayCell> l = Life<ConwayCell>(2, 2);
    
    l.createCell(0, 0, '*');
    l.createCell(0, 1, '*');
    l.createCell(1, 0, '*');
    l.createCell(1, 1, '.');

    l.play();
    CPPUNIT_ASSERT(l.grid[0][0].isAlive == true);
    CPPUNIT_ASSERT(l.grid[0][1].isAlive == true);
    CPPUNIT_ASSERT(l.grid[1][0].isAlive == true);
    CPPUNIT_ASSERT(l.grid[1][1].isAlive == true);
  }

  void test_life_play2 () {
    Life<FredkinCell> l = Life<FredkinCell>(2, 2);

    l.createCell(0, 0, '0');
    l.createCell(0, 1, '-');
    l.createCell(1, 0, '-');
    l.createCell(1, 1, '-');

    l.play();
    CPPUNIT_ASSERT(l.grid[0][0].isAlive == false);
    CPPUNIT_ASSERT(l.grid[0][1].isAlive == true);
    CPPUNIT_ASSERT(l.grid[1][0].isAlive == true);
    CPPUNIT_ASSERT(l.grid[1][1].isAlive == false);
  }

  void test_life_play3 () {
    Life<Cell> l = Life<Cell>(2, 2);  

    l.createCell(0, 0, '0');
    l.createCell(0, 1, '-');
    l.createCell(1, 0, '-');
    l.createCell(1, 1, '-');

    l.play();
    CPPUNIT_ASSERT(l.grid[0][0].get()->isAlive == false);
    CPPUNIT_ASSERT(l.grid[0][1].get()->isAlive == true);
    CPPUNIT_ASSERT(l.grid[1][0].get()->isAlive == true);
    CPPUNIT_ASSERT(l.grid[1][1].get()->isAlive == false);
  }


  // life mutate
  void test_life_mutate () {
    Life<Cell> l = Life<Cell>(3, 3);
    
    l.createCell(0, 0, '0');
    l.createCell(0, 1, '0');
    l.createCell(0, 2, '0');
    l.createCell(1, 0, '0');
    l.createCell(1, 1, '-');
    l.createCell(1, 2, '0');
    l.createCell(2, 0, '0');
    l.createCell(2, 1, '-');
    l.createCell(2, 2, '0');

    Cell c = l.grid[2][2];
    CPPUNIT_ASSERT(c.get()->rep == '0');

    l.mutate(2, 2);
    c = l.grid[2][2];
    CPPUNIT_ASSERT(c.get()->rep == '*');
  }

  // ---
  // suite
  // ---

  CPPUNIT_TEST_SUITE(TestLife);
  // CONWAYCELL
  CPPUNIT_TEST(test_conwayConstructor);
  CPPUNIT_TEST(test_conwayCharConstructor1);
  CPPUNIT_TEST(test_conwayCharConstructor2);
  CPPUNIT_TEST(test_conway_canMutate1);
  CPPUNIT_TEST(test_conway_canMutate2);
  CPPUNIT_TEST(test_conway_canMutate3);
  CPPUNIT_TEST(test_conway_canMutate21);
  CPPUNIT_TEST(test_conway_canMutate22);
  CPPUNIT_TEST(test_conway_canMutate23);
  CPPUNIT_TEST(test_conway_evolve1);
  CPPUNIT_TEST(test_conway_evolve2);
  CPPUNIT_TEST(test_conway_evolve3);
  CPPUNIT_TEST(test_conway_checkNeighbors1);
  CPPUNIT_TEST(test_conway_checkNeighbors2);
  CPPUNIT_TEST(test_conway_checkNeighbors3);
  CPPUNIT_TEST(test_conway_clone1);
  CPPUNIT_TEST(test_conway_clone2);
  CPPUNIT_TEST(test_conway_clone3);
  CPPUNIT_TEST(test_conway_toChar1);
  CPPUNIT_TEST(test_conway_toChar2);
  CPPUNIT_TEST(test_conway_toChar3);
  CPPUNIT_TEST(test_conway_getNeighbors1);
  CPPUNIT_TEST(test_conway_getNeighbors2);
  CPPUNIT_TEST(test_conway_getNeighbors3);
  CPPUNIT_TEST(test_conway_getp1);
  CPPUNIT_TEST(test_conway_getp2);
  CPPUNIT_TEST(test_conway_getp3);
  // FREDKINCELL
  CPPUNIT_TEST(test_fredkinConstructor);
  CPPUNIT_TEST(test_fredkinCharConstructor1);
  CPPUNIT_TEST(test_fredkinCharConstructor2);
  CPPUNIT_TEST(test_fredkin_canMutate1);
  CPPUNIT_TEST(test_fredkin_canMutate2);
  CPPUNIT_TEST(test_fredkin_canMutate3);
  CPPUNIT_TEST(test_fredkin_canMutate21);
  CPPUNIT_TEST(test_fredkin_canMutate22);
  CPPUNIT_TEST(test_fredkin_canMutate23);
  CPPUNIT_TEST(test_fredkin_evolve1);
  CPPUNIT_TEST(test_fredkin_evolve2);
  CPPUNIT_TEST(test_fredkin_evolve3);
  CPPUNIT_TEST(test_fredkin_checkNeighbors1);
  CPPUNIT_TEST(test_fredkin_checkNeighbors2);
  CPPUNIT_TEST(test_fredkin_checkNeighbors3);
  CPPUNIT_TEST(test_fredkin_clone1);
  CPPUNIT_TEST(test_fredkin_clone2);
  CPPUNIT_TEST(test_fredkin_clone3);
  CPPUNIT_TEST(test_fredkin_toChar1);
  CPPUNIT_TEST(test_fredkin_toChar2);
  CPPUNIT_TEST(test_fredkin_toChar3);
  CPPUNIT_TEST(test_fredkin_getNeighbors1);
  CPPUNIT_TEST(test_fredkin_getNeighbors2);
  CPPUNIT_TEST(test_fredkin_getNeighbors3);
  CPPUNIT_TEST(test_fredkin_getp1);
  CPPUNIT_TEST(test_fredkin_getp2);
  CPPUNIT_TEST(test_fredkin_getp3);
  // CELL
  CPPUNIT_TEST(test_cellConstructor);
  CPPUNIT_TEST(test_cellPointConstructor1);
  CPPUNIT_TEST(test_cellPointConstructor2);
  CPPUNIT_TEST(test_cellPointConstructor3);
  CPPUNIT_TEST(test_cellCharConstructor1);
  CPPUNIT_TEST(test_cellCharConstructor2);
  CPPUNIT_TEST(test_cellIntConstructor);
  CPPUNIT_TEST(test_cell_toChar1);
  CPPUNIT_TEST(test_cell_toChar2);
  CPPUNIT_TEST(test_cell_toChar3);
  CPPUNIT_TEST(test_cell_getNeighbors1);
  CPPUNIT_TEST(test_cell_getNeighbors2);
  CPPUNIT_TEST(test_cell_getNeighbors3);
  CPPUNIT_TEST(test_cell_getp1);
  CPPUNIT_TEST(test_cell_getp2);
  CPPUNIT_TEST(test_cell_getp3);
  CPPUNIT_TEST(test_cell_canMutate1);
  CPPUNIT_TEST(test_cell_canMutate2);
  CPPUNIT_TEST(test_cell_canMutate3);
  CPPUNIT_TEST(test_cell_evolve1);
  CPPUNIT_TEST(test_cell_evolve2);
  CPPUNIT_TEST(test_cell_evolve3);
  CPPUNIT_TEST(test_cell_checkNeighbors1);
  CPPUNIT_TEST(test_cell_checkNeighbors2);
  CPPUNIT_TEST(test_cell_checkNeighbors3);
  // LIFE
  CPPUNIT_TEST(test_lifeConstructor1);
  CPPUNIT_TEST(test_lifeConstructor2);
  CPPUNIT_TEST(test_lifeConstructor3);
  CPPUNIT_TEST(test_life_createCell1);
  CPPUNIT_TEST(test_life_createCell2);
  CPPUNIT_TEST(test_life_createCell3); 
  CPPUNIT_TEST(test_life_setNeighbors1);
  CPPUNIT_TEST(test_life_setNeighbors2);
  CPPUNIT_TEST(test_life_setNeighbors3);
  CPPUNIT_TEST(test_life_play1);
  CPPUNIT_TEST(test_life_play2);
  CPPUNIT_TEST(test_life_play3);
  CPPUNIT_TEST(test_life_mutate);
  CPPUNIT_TEST_SUITE_END();
};

// ---
// main
// ---

int main () {
  ios_base::sync_with_stdio(false);
  cout << "TestLife.c++" << endl;

  CppUnit::TextTestRunner tr;
  tr.addTest(TestLife::suite());
  tr.run();

  cout << "Done." << endl;
  return 0;
}
