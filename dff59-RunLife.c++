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
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include <fstream>
#include <string.h>

#include "Cell.h"
#include "Life.h"

// ----
// main
// ----

int main ()
{
  using namespace std;
  ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
  string rowString, colString, fileLine;
  int digitNdx, rows, cols, rowNum, colNum, generationNdx;
  string::iterator rowNdx, colNdx, lineNdx;

  // ------------------
  // Conway Cell 109x69
  // ------------------

  try
  {
    cout << "*** Life<ConwayCell> 109x69 ***" << endl;
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

    ifstream conwayStream;
    conwayStream.open ("RunLifeConway.in");
    conwayStream >> rowString;
    conwayStream >> colString;
    rows = 0;
    cols = 0;
    digitNdx = 1;
    rowNdx = rowString.end();
    for (--rowNdx; rowNdx >= rowString.begin (); --rowNdx)
    {
      rows += ((int) *rowNdx - 48) * digitNdx;
      digitNdx *= 10;
    }

    digitNdx = 1;
    colNdx = colString.end();
    for (--colNdx; colNdx >= colString.begin (); --colNdx)
    {
      cols += ((int) *colNdx - 48) * digitNdx;
      digitNdx *= 10;
    }

    Life <ConwayCell> conwayLife (rows, cols);

    rowNum = -1;
    colNum = -1;
    while (!conwayStream.eof ())
    {
      ++rowNum;
      conwayStream >> fileLine;
      for (lineNdx = fileLine.begin (); lineNdx < fileLine.end (); ++lineNdx)
      {
        ++colNum;
        if (*lineNdx == '.')
        {
          ;
        }
        else
        {
          conwayLife.animate (rowNum, colNum, *lineNdx);
        }
      }

      colNum = -1;
    }
    conwayStream.close ();

    cout << endl << conwayLife << endl;

    for (generationNdx = 0; generationNdx < 283; ++generationNdx)
    {
      conwayLife.simulate ();
    }

    cout << conwayLife << endl;

    for (generationNdx = 0; generationNdx < 40; ++generationNdx)
    {
      conwayLife.simulate ();
    }

    cout << conwayLife << endl;

    for (generationNdx = 0; generationNdx < 2177; ++generationNdx)
    {
      conwayLife.simulate ();
    }

    cout << conwayLife << endl;
  }
  catch (const invalid_argument&)
  {
    assert (false);
  }
  catch (const out_of_range&) 
  {
    assert (false);
  }

  // ------------------
  // Fredkin Cell 20x20
  // ------------------

  try 
  {
    cout << "*** Life<FredkinCell> 20x20 ***" << endl;
    /*
     read RunLifeFredkin.in // assume all Fredkin cells
     Simulate 5 moves.
     Print every grid (i.e. 0, 1, 2...5)
    */
    ifstream fredkinStream;
    fredkinStream.open ("RunLifeFredkin.in");
    fredkinStream >> rowString;
    fredkinStream >> colString;
    rows = 0;
    cols = 0;
    digitNdx = 1;
    rowNdx = rowString.end();
    for (--rowNdx; rowNdx >= rowString.begin (); --rowNdx)
    {
      rows += ((int) *rowNdx - 48) * digitNdx;
      digitNdx *= 10;
    }

    digitNdx = 1;
    colNdx = colString.end();
    for (--colNdx; colNdx >= colString.begin (); --colNdx)
    {
      cols += ((int) *colNdx - 48) * digitNdx;
      digitNdx *= 10;
    }

    Life <FredkinCell> fredkinLife (rows, cols);

    rowNum = -1;
    colNum = -1;
    while (!fredkinStream.eof ())
    {
      ++rowNum;
      fredkinStream >> fileLine;
      for (lineNdx = fileLine.begin (); lineNdx < fileLine.end (); ++lineNdx)
      {
        ++colNum;
        if (*lineNdx == '-')
        {
          ;
        }
        else
        {
          fredkinLife.animate (rowNum, colNum, *lineNdx);
        }
      }

      colNum = -1;
    }
    fredkinStream.close ();

    cout << endl << fredkinLife << endl;

    for (generationNdx = 0; generationNdx < 5; ++generationNdx)
    {
      fredkinLife.simulate ();
      cout << fredkinLife << endl;
    }
  }
  catch (const invalid_argument&)
  {
    assert (false);
  }
  catch (const out_of_range&)
  {
    assert (false);
  }

  // ----------
  // Cell 20x20
  // ----------

  try
  {
    cout << "*** Life<Cell> 20x20 ***" << endl;
    /*
     read RunLifeCell.in // assume all Fredkin cells
     Simulate 5 moves.
     Print every grid (i.e. 0, 1, 2...5)
    */

    ifstream cellStream;
    cellStream.open ("RunLifeCell.in");
    cellStream >> rowString;
    cellStream >> colString;
    rows = 0;
    cols = 0;
    digitNdx = 1;
    rowNdx = rowString.end();
    for (--rowNdx; rowNdx >= rowString.begin (); --rowNdx)
    {
      rows += ((int) *rowNdx - 48) * digitNdx;
      digitNdx *= 10;
    }

    digitNdx = 1;
    colNdx = colString.end();
    for (--colNdx; colNdx >= colString.begin (); --colNdx)
    {
      cols += ((int) *colNdx - 48) * digitNdx;
      digitNdx *= 10;
    }

    Cell aCell = new FredkinCell ();
    Life <Cell> cellLife (rows, cols, aCell);

    rowNum = -1;
    colNum = -1;
    while (!cellStream.eof ())
    {
      ++rowNum;
      cellStream >> fileLine;
      for (lineNdx = fileLine.begin (); lineNdx < fileLine.end (); ++lineNdx)
      {
        ++colNum;
        if (*lineNdx == '-')
        {
          ;
        }
        else
        {
          cellLife.animate (rowNum, colNum, *lineNdx);
        }
      }

      colNum = -1;
    }
    cellStream.close ();

    cout << endl << cellLife << endl;

    for (generationNdx = 0; generationNdx < 5; ++generationNdx)
    {
      cellLife.simulate ();
      cout << cellLife << endl;
    }
  }
  catch (const invalid_argument&)
  {
    assert(false);
  }
  catch (const out_of_range&)
  {
    assert(false);
  }

  try
  {
    cout << "*** Life<ConwayCell> #1 ***" << endl;

    Life <ConwayCell> aLife (5, 5);

    aLife.animate (0, 0, '*');
    aLife.animate (1, 1, '*');
    aLife.animate (2, 2, '*');
    aLife.animate (3, 3, '*');
    aLife.animate (4, 4, '*');

    cout << endl << aLife << endl;

    for (generationNdx = 0; generationNdx < 5; ++generationNdx)
    {
      aLife.simulate ();
      cout << aLife << endl;
    }
  }
  catch (const invalid_argument&)
  {
    assert(false);
  }
  catch (const out_of_range&)
  {
    assert(false);
  }

  try
  {
    cout << "*** Life<ConwayCell> #2 ***" << endl;

    Life <ConwayCell> aLife (21, 21);

    aLife.animate (10, 5, '*');
    aLife.animate (10, 6, '*');
    aLife.animate (10, 7, '*');
    aLife.animate (10, 8, '*');
    aLife.animate (10, 9, '*');
    aLife.animate (10, 10, '*');
    aLife.animate (10, 11, '*');
    aLife.animate (10, 12, '*');
    aLife.animate (10, 13, '*');
    aLife.animate (10, 14, '*');

    cout << endl << aLife << endl;

    for (generationNdx = 0; generationNdx < 16; ++generationNdx)
    {
      aLife.simulate ();
      cout << aLife << endl;
    }
  }
  catch (const invalid_argument&)
  {
    assert(false);
  }
  catch (const out_of_range&)
  {
    assert(false);
  }

  try
  {
    cout << "*** Life<ConwayCell> #3 ***" << endl;

    Life <ConwayCell> aLife (21, 21);

    aLife.animate (9, 10, '*');
    aLife.animate (10, 11, '*');
    aLife.animate (11, 9, '*');
    aLife.animate (11, 10, '*');
    aLife.animate (11, 11, '*');

    cout << endl << aLife << endl;

    for (generationNdx = 0; generationNdx < 5; ++generationNdx)
    {
      aLife.simulate ();
      cout << aLife << endl;
    }
  }
  catch (const invalid_argument&)
  {
    assert(false);
  }
  catch (const out_of_range&)
  {
    assert(false);
  }

  try
  {
    cout << "*** Life<ConwayCell> #4 ***" << endl;

    Life <ConwayCell> aLife (21, 21);

    aLife.animate (8, 10, '*');
    aLife.animate (9, 9, '*');
    aLife.animate (9, 10, '*');
    aLife.animate (9, 11, '*');
    aLife.animate (10, 9, '*');
    aLife.animate (10, 11, '*');
    aLife.animate (11, 10, '*');

    cout << endl << aLife << endl;

    for (generationNdx = 0; generationNdx < 15; ++generationNdx)
    {
      aLife.simulate ();
      cout << aLife << endl;
    }
  }
  catch (const invalid_argument&)
  {
    assert(false);
  }
  catch (const out_of_range&)
  {
    assert(false);
  }

  try
  {
    cout << "*** Life<ConwayCell> #5 ***" << endl;

    Life <ConwayCell> aLife (10, 30);

    aLife.animate (4, 1, '*');
    aLife.animate (4, 2, '*');
    aLife.animate (4, 3, '*');
    aLife.animate (4, 4, '*');
    aLife.animate (5, 0, '*');
    aLife.animate (5, 4, '*');
    aLife.animate (6, 4, '*');
    aLife.animate (7, 0, '*');
    aLife.animate (7, 3, '*');

    cout << endl << aLife << endl;

    for (generationNdx = 0; generationNdx < 15; ++generationNdx)
    {
      aLife.simulate ();
      cout << aLife << endl;
    }
  }
  catch (const invalid_argument&)
  {
    assert(false);
  }
  catch (const out_of_range&)
  {
    assert(false);
  }

  try
  {
    cout << "*** Life<FredkinCell> #1 ***" << endl;

    Life <FredkinCell> aLife (5, 5);

    aLife.animate (0, 0, '0');
    aLife.animate (1, 1, '0');
    aLife.animate (2, 2, '0');
    aLife.animate (3, 3, '0');
    aLife.animate (4, 4, '0');

    cout << endl << aLife << endl;

    for (generationNdx = 0; generationNdx < 5; ++generationNdx)
    {
      aLife.simulate ();
      cout << aLife << endl;
    }
  }
  catch (const invalid_argument&)
  {
    assert(false);
  }
  catch (const out_of_range&)
  {
    assert(false);
  }

  try
  {
    cout << "*** Life<FredkinCell> #2 ***" << endl;

    Life <FredkinCell> aLife (21, 21);

    aLife.animate (10, 5, '0');
    aLife.animate (10, 6, '0');
    aLife.animate (10, 7, '0');
    aLife.animate (10, 8, '0');
    aLife.animate (10, 9, '0');
    aLife.animate (10, 10, '0');
    aLife.animate (10, 11, '0');
    aLife.animate (10, 12, '0');
    aLife.animate (10, 13, '0');
    aLife.animate (10, 14, '0');

    cout << endl << aLife << endl;

    for (generationNdx = 0; generationNdx < 16; ++generationNdx)
    {
      aLife.simulate ();
      cout << aLife << endl;
    }
  }
  catch (const invalid_argument&)
  {
    assert(false);
  }
  catch (const out_of_range&)
  {
    assert(false);
  }

  try
  {
    cout << "*** Life<FredkinCell> #3 ***" << endl;

    Life <FredkinCell> aLife (21, 21);

    aLife.animate (9, 10, '0');
    aLife.animate (10, 11, '0');
    aLife.animate (11, 9, '0');
    aLife.animate (11, 10, '0');
    aLife.animate (11, 11, '0');

    cout << endl << aLife << endl;

    for (generationNdx = 0; generationNdx < 5; ++generationNdx)
    {
      aLife.simulate ();
      cout << aLife << endl;
    }
  }
  catch (const invalid_argument&)
  {
    assert(false);
  }
  catch (const out_of_range&)
  {
    assert(false);
  }

  try
  {
    cout << "*** Life<FredkinCell> #4 ***" << endl;

    Life <FredkinCell> aLife (21, 21);

    aLife.animate (8, 10, '0');
    aLife.animate (9, 9, '0');
    aLife.animate (9, 10, '0');
    aLife.animate (9, 11, '0');
    aLife.animate (10, 9, '0');
    aLife.animate (10, 11, '0');
    aLife.animate (11, 10, '0');

    cout << endl << aLife << endl;

    for (generationNdx = 0; generationNdx < 15; ++generationNdx)
    {
      aLife.simulate ();
      cout << aLife << endl;
    }
  }
  catch (const invalid_argument&)
  {
    assert(false);
  }
  catch (const out_of_range&)
  {
    assert(false);
  }

  try
  {
    cout << "*** Life<FredkinCell> #5 ***" << endl;

    Life <FredkinCell> aLife (10, 30);

    aLife.animate (4, 1, '0');
    aLife.animate (4, 2, '0');
    aLife.animate (4, 3, '0');
    aLife.animate (4, 4, '0');
    aLife.animate (5, 0, '0');
    aLife.animate (5, 4, '0');
    aLife.animate (6, 4, '0');
    aLife.animate (7, 0, '0');
    aLife.animate (7, 3, '0');

    cout << endl << aLife << endl;

    for (generationNdx = 0; generationNdx < 15; ++generationNdx)
    {
      aLife.simulate ();
      cout << aLife << endl;
    }
  }
  catch (const invalid_argument&)
  {
    assert(false);
  }
  catch (const out_of_range&)
  {
    assert(false);
  }

  try
  {
    cout << "*** Life<Cell> #1 ***" << endl;

    Cell aCell = new FredkinCell ();
    Life <Cell> aLife (5, 5, aCell);

    aLife.animate (0, 0, '*');
    aLife.animate (1, 1, '*');
    aLife.animate (2, 2, '*');
    aLife.animate (3, 3, '*');
    aLife.animate (4, 4, '*');

    cout << endl << aLife << endl;

    for (generationNdx = 0; generationNdx < 5; ++generationNdx)
    {
      aLife.simulate ();
      cout << aLife << endl;
    }
  }
  catch (const invalid_argument&)
  {
    assert(false);
  }
  catch (const out_of_range&)
  {
    assert(false);
  }

  try
  {
    cout << "*** Life<Cell> #2 ***" << endl;

    Cell aCell = new FredkinCell ();
    Life <Cell> aLife (21, 21, aCell);

    aLife.animate (10, 5, '0');
    aLife.animate (10, 6, '0');
    aLife.animate (10, 7, '0');
    aLife.animate (10, 8, '0');
    aLife.animate (10, 9, '0');
    aLife.animate (10, 10, '0');
    aLife.animate (10, 11, '0');
    aLife.animate (10, 12, '0');
    aLife.animate (10, 13, '0');
    aLife.animate (10, 14, '0');

    cout << endl << aLife << endl;

    for (generationNdx = 0; generationNdx < 16; ++generationNdx)
    {
      aLife.simulate ();
      cout << aLife << endl;
    }
  }
  catch (const invalid_argument&)
  {
    assert(false);
  }
  catch (const out_of_range&)
  {
    assert(false);
  }

  try
  {
    cout << "*** Life<Cell> #3 ***" << endl;

    Cell aCell = new FredkinCell ();
    Life <Cell> aLife (21, 21, aCell);

    aLife.animate (9, 10, '0');
    aLife.animate (10, 11, '0');
    aLife.animate (11, 9, '0');
    aLife.animate (11, 10, '0');
    aLife.animate (11, 11, '0');

    cout << endl << aLife << endl;

    for (generationNdx = 0; generationNdx < 5; ++generationNdx)
    {
      aLife.simulate ();
      cout << aLife << endl;
    }
  }
  catch (const invalid_argument&)
  {
    assert(false);
  }
  catch (const out_of_range&)
  {
    assert(false);
  }

  try
  {
    cout << "*** Life<Cell> #4 ***" << endl;

    Cell aCell = new FredkinCell ();
    Life <Cell> aLife (21, 21, aCell);

    aLife.animate (8, 10, '0');
    aLife.animate (9, 9, '0');
    aLife.animate (9, 10, '0');
    aLife.animate (9, 11, '0');
    aLife.animate (10, 9, '0');
    aLife.animate (10, 11, '0');
    aLife.animate (11, 10, '0');

    cout << endl << aLife << endl;

    for (generationNdx = 0; generationNdx < 15; ++generationNdx)
    {
      aLife.simulate ();
      cout << aLife << endl;
    }
  }
  catch (const invalid_argument&)
  {
    assert(false);
  }
  catch (const out_of_range&)
  {
    assert(false);
  }

  try
  {
    cout << "*** Life<Cell> #5 ***" << endl;

    Cell aCell = new FredkinCell ();
    Life <Cell> aLife (10, 30, aCell);

    aLife.animate (4, 1, '0');
    aLife.animate (4, 2, '0');
    aLife.animate (4, 3, '0');
    aLife.animate (4, 4, '0');
    aLife.animate (5, 0, '0');
    aLife.animate (5, 4, '0');
    aLife.animate (6, 4, '0');
    aLife.animate (7, 0, '0');
    aLife.animate (7, 3, '0');

    cout << endl << aLife << endl;

    for (generationNdx = 0; generationNdx < 15; ++generationNdx)
    {
      aLife.simulate ();
      cout << aLife << endl;
    }
  }
  catch (const invalid_argument&)
  {
    assert(false);
  }
  catch (const out_of_range&)
  {
    assert(false);
  }

  return 0;
  }
