// -------------------------
// projects/life/RunLife.c++
// Copyright (C) 2013
// Glenn P. Downing
// -------------------------

/*
To run the program:
% make RunLife
% make run

To configure Doxygen:
doxygen -g
That creates the file Doxyfile.
Make the following edits:
EXTRACT_ALL            = YES
EXTRACT_PRIVATE        = YES
EXTRACT_STATIC         = YES
GENERATE_LATEX         = NO

To document the program:
doxygen Doxyfile
*/

// --------
// includes
// --------

#include <cassert>   // assert
#include <string>
#include <iostream>  // cout, endl
#include <istream>
#include <fstream>
#include <stdexcept> // invalid_argument, out_of_range
#include <sstream>

#include "Life.h"
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"


using std::string;
using std::istream;
using std::ifstream;
using std::stringstream;
using std::cout;
using std::endl;


void populate_conway(istream& file, Life<ConwayCell>& life, int rows, int cols) {
  char c;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      file >> c;
      life.add_cell(i, j, ConwayCell(c));
    }
  }
}

void populate_fredkin(istream& file, Life<FredkinCell>& life, int rows, int cols) {
  char c;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      file >> c;
      life.add_cell(i, j, FredkinCell(c));
    }
  }
}

void populate_cell(istream& file, Life<Cell>& life, int rows, int cols) {
  char c;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      file >> c;
      life.add_cell(i, j, new FredkinCell(c));
    }
  }
}

// ----
// main
// ----

int main () {
  using namespace std;
  ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

  // FredkinCell c = new FredkinCell('-');

  // ------------------
  // Conway Cell 109x69
  // ------------------

  try {
    cout << "*** Life<ConwayCell> 109x69 ***" << endl << endl;
    ifstream file("RunLifeConway.in");
    int rows, cols;
    file >> rows;
    file >> cols;
    Life<ConwayCell> life(rows, cols, ConwayCell());
    populate_conway(file, life, rows, cols);
    file.close();
    int gen = 0;
    cout << life;
    for (; gen < 9; ++gen) {
      life.run(1);
      cout << life;
    }
    life.run(274);
    cout << life;
    life.run(40);
    cout << life;
    life.run(2177);
    cout << life;
    /*
    read RunLifeConway.in // assume all Conway cells
    Simulate 283 moves.
    Print the first 10 grids (i.e. 0, 1, 2...9).
    Print the 283rd grid.
    Simulate 40 moves.
    Print the 323rd grid.
    Simulate 2177 moves.
    Print the 2500th grid.
    */
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

  // ------------------
  // Fredkin Cell 20x20
  // ------------------

  try {
    cout << "*** Life<FredkinCell> 20x20 ***" << endl << endl;
    ifstream file("RunLifeFredkin.in");
    int rows, cols;
    file >> rows;
    file >> cols;
    Life<FredkinCell> life(rows, cols, FredkinCell());
    populate_fredkin(file, life, rows, cols);
    file.close();
    int gen = 0;
    cout << life;
    for (; gen < 5; ++gen) {
      life.run(1);
      cout << life;
    }

    /*
    read RunLifeFredkin.in // assume all Fredkin cells
    Simulate 5 moves.
    Print every grid (i.e. 0, 1, 2...5)
    */
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

  // ----------
  // Cell 20x20
  // ----------

  try {
    cout << "*** Life<Cell> 20x20 ***" << endl << endl;
    ifstream file("RunLifeCell.in");
    int rows, cols;
    file >> rows;
    file >> cols;
    Life<Cell> life(rows, cols, new FredkinCell());
    populate_cell(file, life, rows, cols);
    file.close();
    int gen = 0;
    cout << life;
    for (; gen < 5; ++gen) {
      life.run(1);
      cout << life;
    }
    /*
    read RunLifeCell.in // assume all Fredkin cells
    Simulate 5 moves.
    Print every grid (i.e. 0, 1, 2...5)
    */
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

  // ***CONWAY TESTS***

  // --------------
  // ConwayCell 1x1
  // --------------

  try {
    cout << "*** Life<ConwayCell> 1x1 ***" << endl << endl;
    stringstream ss;
    ss << "1" << endl;
    ss << "1" << endl;
    ss << "*" << endl;
    int rows, cols;
    ss >> rows;
    ss >> cols;
    Life<ConwayCell> life(rows, cols, ConwayCell());
    populate_conway(ss, life, rows, cols);
    int gen = 0;
    cout << life;
    for(; gen < 2; ++gen) {
      life.run(1);
      cout << life;
    }
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

  // --------------
  // ConwayCell 2x2
  // --------------

  try {
    cout << "*** Life<ConwayCell> 2x2 ***" << endl << endl;
    stringstream ss;
    ss << "2" << endl;
    ss << "2" << endl;
    ss << "**" << endl;
    ss << "**" << endl;
    int rows, cols;
    ss >> rows;
    ss >> cols;
    Life<ConwayCell> life(rows, cols, ConwayCell());
    populate_conway(ss, life, rows, cols);
    int gen = 0;
    cout << life;
    for(; gen < 2; ++gen) {
      life.run(1);
      cout << life;
    }
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

  // --------------
  // ConwayCell 5x1
  // --------------

  try {
    cout << "*** Life<ConwayCell> 5x1 ***" << endl << endl;
    stringstream ss;
    ss << "5" << endl;
    ss << "1" << endl;
    ss << "*" << endl;
    ss << "*" << endl;
    ss << "*" << endl;
    ss << "*" << endl;
    ss << "*" << endl;
    int rows, cols;
    ss >> rows;
    ss >> cols;
    Life<ConwayCell> life(rows, cols, ConwayCell());
    populate_conway(ss, life, rows, cols);
    int gen = 0;
    cout << life;
    for(; gen < 4; ++gen) {
      life.run(1);
      cout << life;
    }
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

  // --------------
  // ConwayCell 5x2
  // --------------

  try {
    cout << "*** Life<ConwayCell> 5x2 ***" << endl << endl;
    stringstream ss;
    ss << "5" << endl;
    ss << "2" << endl;
    ss << "**" << endl;
    ss << "**" << endl;
    ss << ".." << endl;
    ss << "**" << endl;
    ss << "**" << endl;
    int rows, cols;
    ss >> rows;
    ss >> cols;
    Life<ConwayCell> life(rows, cols, ConwayCell());
    populate_conway(ss, life, rows, cols);
    int gen = 0;
    cout << life;
    for(; gen < 2; ++gen) {
      life.run(1);
      cout << life;
    }
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

  // ---------------
  // ConwayCell 1x5
  // ---------------

  try {
    cout << "*** Life<ConwayCell> 1x5 ***" << endl << endl;
    stringstream ss;
    ss << "1" << endl;
    ss << "5" << endl;
    ss << "*****" << endl;
    int rows, cols;
    ss >> rows;
    ss >> cols;
    Life<ConwayCell> life(rows, cols, ConwayCell());
    populate_conway(ss, life, rows, cols);
    int gen = 0;
    cout << life;
    for(; gen < 4; ++gen) {
      life.run(1);
      cout << life;
    }
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

  // ---------------
  // ConwayCell 2x5
  // ---------------

  try {
    cout << "*** Life<ConwayCell> 2x5 ***" << endl << endl;
    stringstream ss;
    ss << "2" << endl;
    ss << "5" << endl;
    ss << "**.**" << endl;
    ss << "**.**" << endl;
    int rows, cols;
    ss >> rows;
    ss >> cols;
    Life<ConwayCell> life(rows, cols, ConwayCell());
    populate_conway(ss, life, rows, cols);
    int gen = 0;
    cout << life;
    for(; gen < 2; ++gen) {
      life.run(1);
      cout << life;
    }
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

  // ***FREDKIN TESTS***

  // ---------------
  // FredkinCell 1x1
  // ---------------

  try {
    cout << "*** Life<FredkinCell> 1x1 ***" << endl << endl;
    stringstream ss;
    ss << "1" << endl;
    ss << "1" << endl;
    ss << "0" << endl;
    int rows, cols;
    ss >> rows;
    ss >> cols;
    Life<FredkinCell> life(rows, cols, FredkinCell());
    populate_fredkin(ss, life, rows, cols);
    int gen = 0;
    cout << life;
    for(; gen < 1; ++gen) {
      life.run(1);
      cout << life;
    }
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

  // ---------------
  // FredkinCell 2x2
  // ---------------

  try {
    cout << "*** Life<FredkinCell> 2x2 ***" << endl << endl;
    stringstream ss;
    ss << "2" << endl;
    ss << "2" << endl;
    ss << "00" << endl;
    ss << "00" << endl;
    int rows, cols;
    ss >> rows;
    ss >> cols;
    Life<FredkinCell> life(rows, cols, FredkinCell());
    populate_fredkin(ss, life, rows, cols);
    int gen = 0;
    cout << life;
    for(; gen < 1; ++gen) {
      life.run(1);
      cout << life;
    }
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

  // ---------------
  // FredkinCell 5x1
  // ---------------

  try {
    cout << "*** Life<FredkinCell> 5x1 ***" << endl << endl;
    stringstream ss;
    ss << "5" << endl;
    ss << "1" << endl;
    ss << "0" << endl;
    ss << "0" << endl;
    ss << "0" << endl;
    ss << "0" << endl;
    ss << "0" << endl;
    int rows, cols;
    ss >> rows;
    ss >> cols;
    Life<FredkinCell> life(rows, cols, FredkinCell());
    populate_fredkin(ss, life, rows, cols);
    int gen = 0;
    cout << life;
    for(; gen < 4; ++gen) {
      life.run(1);
      cout << life;
    }
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

  // ---------------
  // FredkinCell 5x2
  // ---------------

  try {
    cout << "*** Life<FredkinCell> 5x2 ***" << endl << endl;
    stringstream ss;
    ss << "5" << endl;
    ss << "2" << endl;
    ss << "00" << endl;
    ss << "00" << endl;
    ss << "00" << endl;
    ss << "00" << endl;
    ss << "00" << endl;
    int rows, cols;
    ss >> rows;
    ss >> cols;
    Life<FredkinCell> life(rows, cols, FredkinCell());
    populate_fredkin(ss, life, rows, cols);
    int gen = 0;
    cout << life;
    for(; gen < 10; ++gen) {
      life.run(1);
      cout << life;
    }
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

  // ---------------
  // FredkinCell 1x5
  // ---------------

  try {
    cout << "*** Life<FredkinCell> 1x5 ***" << endl << endl;
    stringstream ss;
    ss << "1" << endl;
    ss << "5" << endl;
    ss << "00000" << endl;
    int rows, cols;
    ss >> rows;
    ss >> cols;
    Life<FredkinCell> life(rows, cols, FredkinCell());
    populate_fredkin(ss, life, rows, cols);
    int gen = 0;
    cout << life;
    for(; gen < 4; ++gen) {
      life.run(1);
      cout << life;
    }
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

  // ---------------
  // FredkinCell 2x5
  // ---------------

  try {
    cout << "*** Life<FredkinCell> 2x5 ***" << endl << endl;
    stringstream ss;
    ss << "2" << endl;
    ss << "5" << endl;
    ss << "00000" << endl;
    ss << "00000" << endl;
    int rows, cols;
    ss >> rows;
    ss >> cols;
    Life<FredkinCell> life(rows, cols, FredkinCell());
    populate_fredkin(ss, life, rows, cols);
    int gen = 0;
    cout << life;
    for(; gen < 10; ++gen) {
      life.run(1);
      cout << life;
    }
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

  // ***CELL TESTS***

  // --------
  // Cell 1x1
  // --------

  try {
    cout << "*** Life<Cell> 1x1 ***" << endl << endl;
    stringstream ss;
    ss << "1" << endl;
    ss << "1" << endl;
    ss << "0" << endl;
    int rows, cols;
    ss >> rows;
    ss >> cols;
    Life<Cell> life(rows, cols, new FredkinCell());
    populate_cell(ss, life, rows, cols);
    int gen = 0;
    cout << life;
    for(; gen < 1; ++gen) {
      life.run(1);
      cout << life;
    }
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

  // ---------------
  // Cell 2x2
  // ---------------

  try {
    cout << "*** Life<Cell> 2x2 ***" << endl << endl;
    stringstream ss;
    ss << "2" << endl;
    ss << "2" << endl;
    ss << "00" << endl;
    ss << "00" << endl;
    int rows, cols;
    ss >> rows;
    ss >> cols;
    Life<Cell> life(rows, cols, new FredkinCell());
    populate_cell(ss, life, rows, cols);
    int gen = 0;
    cout << life;
    for(; gen < 1; ++gen) {
      life.run(1);
      cout << life;
    }
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

  // ---------------
  // Cell 5x1
  // ---------------

  try {
    cout << "*** Life<Cell> 5x1 ***" << endl << endl;
    stringstream ss;
    ss << "5" << endl;
    ss << "1" << endl;
    ss << "0" << endl;
    ss << "0" << endl;
    ss << "0" << endl;
    ss << "0" << endl;
    ss << "0" << endl;
    int rows, cols;
    ss >> rows;
    ss >> cols;
    Life<Cell> life(rows, cols, new FredkinCell());
    populate_cell(ss, life, rows, cols);
    int gen = 0;
    cout << life;
    for(; gen < 4; ++gen) {
      life.run(1);
      cout << life;
    }
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

  // ---------------
  // Cell 5x2
  // ---------------

  try {
    cout << "*** Life<Cell> 5x2 ***" << endl << endl;
    stringstream ss;
    ss << "5" << endl;
    ss << "2" << endl;
    ss << "00" << endl;
    ss << "00" << endl;
    ss << "00" << endl;
    ss << "00" << endl;
    ss << "00" << endl;
    int rows, cols;
    ss >> rows;
    ss >> cols;
    Life<Cell> life(rows, cols, new FredkinCell());
    populate_cell(ss, life, rows, cols);
    int gen = 0;
    cout << life;
    for(; gen < 8; ++gen) {
      life.run(1);
      cout << life;
    }
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

  // ---------------
  // Cell 1x5
  // ---------------

  try {
    cout << "*** Life<Cell> 1x5 ***" << endl << endl;
    stringstream ss;
    ss << "1" << endl;
    ss << "5" << endl;
    ss << "00000" << endl;
    int rows, cols;
    ss >> rows;
    ss >> cols;
    Life<Cell> life(rows, cols, new FredkinCell());
    populate_cell(ss, life, rows, cols);
    int gen = 0;
    cout << life;
    for(; gen < 4; ++gen) {
      life.run(1);
      cout << life;
    }
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

  // ---------------
  // Cell 2x5
  // ---------------

  try {
    cout << "*** Life<Cell> 2x5 ***" << endl << endl;
    stringstream ss;
    ss << "2" << endl;
    ss << "5" << endl;
    ss << "00000" << endl;
    ss << "00000" << endl;
    int rows, cols;
    ss >> rows;
    ss >> cols;
    Life<Cell> life(rows, cols, new FredkinCell());
    populate_cell(ss, life, rows, cols);
    int gen = 0;
    cout << life;
    for(; gen < 8; ++gen) {
      life.run(1);
      cout << life;
    }
  }
  catch (const invalid_argument&) {
    assert(false);
  }
  catch (const out_of_range&) {
    assert(false);
  }

  return 0;
}