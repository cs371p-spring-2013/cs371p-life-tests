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
#include <vector>

#include "Life.h"
#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

// ----
// main
// ----

int main () {
  using namespace std;
  ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
  
  
  // -----------------
  // ConwayCell stable after 1,000,000 runs 
  // -----------------
  
  try {
	cout << "*** Life<ConwayCell> 4x4 ***" << endl;
	
	
	Life<ConwayCell> game(4,4);
	game.add(1,1, ConwayCell(true));
	game.add(2,1, ConwayCell(true));
	game.add(2,2, ConwayCell(true));
	game.add(1,2, ConwayCell(true));
	
	game.print();
	
	for(int i = 0; i < 10; i++) {
	  game.run();
	  game.print();
	}
	// toned it down for the repo
	game.run(5000); //(1000000);
	game.print();
	

  } catch (const invalid_argument&) {
	assert(false);
  } catch (const out_of_range&) {
	assert(false);
  }




  // -----------------
  // ConwayCell Gun
  // -----------------
  
  try {
	cout << "*** Life<ConwayCell> 100x50 ***" << endl;
	
	
	Life<ConwayCell> game(100,50);
	
	vector<int> points({1,5, 2,5, 1,6, 2,6,
		  11,5, 11,6, 11,7, 12,4, 12,8, 13,3, 13,9, 14,3, 14,9, 15,6, 16,4, 16,8, 17,5, 17,6, 17,7, 18,6,
		  21,5, 21,4, 21,3, 22,3, 22,4, 22,5, 23,2, 23,6, 25,6, 25,7, 25,2, 25,1,
		  35,4, 36,4, 35,3, 36,3});

	for (unsigned int i = 0; i < points.size(); i+=2) {
	  game.add(points[i], points[i+1], ConwayCell(true));
	}
	game.print();
	
	int prettypattern = 10; // change to a higher value to see a gun
	for(int i = 0; i < prettypattern; i++) {
	  game.run(61);
	  game.print();
	}
	

  } catch (const invalid_argument&) {
	assert(false);
  } catch (const out_of_range&) {
	assert(false);
  }

  

  
  // -----------------
  // ConwayCell 100x50 
  // -----------------
  
  try {
	cout << "*** Life<ConwayCell> 100x50 ***" << endl;
	
	
	Life<ConwayCell> game(100,50);
	for (int x = 0; x < 100; x++) {
	  for (int y = 0; y < 50; y++) {	
		if ((x+y)%3 == 2) game.add(x,y, ConwayCell(true));
	  }
	}
	
	game.print();
	
	for(int i = 0; i < 10; i++) {
	  game.run(100);
	  game.print();
	}
	

  } catch (const invalid_argument&) {
	assert(false);
  } catch (const out_of_range&) {
	assert(false);
  }

  

  // -----------------
  // FredkinCell 6x6 all
  // -----------------
  
  try {
	cout << "*** Life<FredkinCell> 6x6  ***" << endl;
	
	
	Life<FredkinCell> game(6,6);
	for (int x = 0; x < 6; x++) {
	  for (int y = 0; y < 6; y++) {	
		if ((x+y)%4 <5) game.add(x,y, FredkinCell(true));
	  }
	}
	
	game.print();
	
	for(int i = 0; i < 10; i++) {
	  game.run(50);
	  game.print();
	}
	

  } catch (const invalid_argument&) {
	assert(false);
  } catch (const out_of_range&) {
	assert(false);
  }

  

  // -----------------
  // FredkinCell 12x12
  // -----------------
  
  try {
	cout << "*** Life<FredkinCell> 12x12  ***" << endl;
	
	
	Life<FredkinCell> game(12,12);
	for (int x = 0; x < 12; x++) {
	  for (int y = 0; y < 12; y++) {	
		if ((x+y)%4 == 1) game.add(x,y, FredkinCell(true));
	  }
	}
	
	game.print();
	
	for(int i = 0; i < 10; i++) {
	  game.run(50);
	  game.print();
	}
	

  } catch (const invalid_argument&) {
	assert(false);
  } catch (const out_of_range&) {
	assert(false);
  }

  


  // -----------------
  // FredkinCell 10x10
  // -----------------
  
  try {
	cout << "*** Life<FredkinCell> 11x11  ***" << endl;
	
	
	Life<FredkinCell> game(11,11);
	for (int x = 0; x < 11; x++) {
	  for (int y = 0; y < 11; y++) {	
		if ((x+y)%3 == 1) game.add(x,y, FredkinCell(true));
	  }
	}
	
	game.print();
	
	for(int i = 0; i < 10; i++) {
	  game.run(50);
	  game.print();
	}
	

  } catch (const invalid_argument&) {
	assert(false);
  } catch (const out_of_range&) {
	assert(false);
  }

  


  // -----------------
  // FredkinCell 50x50 line down 24x
  // -----------------

  try {
	cout << "*** Life<FredkinCell> 50x50 line down 24x ***" << endl;
	
	
	Life<FredkinCell> game(50,50);
	for (int y = 0; y < 50; y++) {
	  game.add(24,y, FredkinCell(true));
	}
	
	game.print();
	
	for(int i = 0; i < 10; i++) {
	  game.run(500);
	  game.print();
	}
	

  } catch (const invalid_argument&) {
	assert(false);
  } catch (const out_of_range&) {
	assert(false);
  }

  

  // -----------------
  // FredkinCell 50x50 every other filled
  // -----------------
  
  try {
	cout << "*** Life<FredkinCell> 50x50 every other filled ***" << endl;
	
	
	Life<FredkinCell> game(50,50);
	for (int x = 0; x < 50; x++) {
	  for (int y = 0; y < 50; y++) {
		if ((x+y) % 2 == 0) game.add(x,y, FredkinCell(true));
	  }
	}
	game.print();
	
	for(int i = 0; i < 10; i++) {
	  game.run(500);
	  game.print();
	}
	

  } catch (const invalid_argument&) {
	assert(false);
  } catch (const out_of_range&) {
	assert(false);
  }

  


  // -----------------
  // Cell 30x30 every other filled
  // -----------------
  
  try {
	cout << "*** Life<Cell> 50x50 every other ***" << endl;
	
	
	Life<Cell> game(50,50);
	for (int x = 0; x < 50; x++) {
	  for (int y = 0; y < 50; y++) {
		if ((x+y) % 2 == 0) game.add(x,y, FredkinCell(true).clone());
	  }
	}
	game.print();
	
	for(int i = 0; i < 10; i++) {
	  game.run(500);
	  game.print();
	}
	

  } catch (const invalid_argument&) {
	assert(false);
  } catch (const out_of_range&) {
	assert(false);
  }


  
  // -----------------
  // Cell 30x30 all filled
  // -----------------
  
  try {
	cout << "*** Life<Cell> 30x30 All filled ***" << endl;
	
	
	Life<Cell> game(30,30);
	for (int x = 0; x < 30; x++) {
	  for (int y = 0; y < 30; y++) {
		if (rand() % 10 < 20) game.add(x,y, FredkinCell(true).clone());
	  }
	}
	game.print();
	
	for(int i = 0; i < 5; i++) {
	  game.run(20);
	  game.print();
	}
	

  } catch (const invalid_argument&) {
	assert(false);
  } catch (const out_of_range&) {
	assert(false);
  }


  // -----------------
  // Cell 30x30 random
  // -----------------
  
  try {
	cout << "*** Life<Cell> 30x30 Random ***" << endl;
	
	
	Life<Cell> game(30,30);
	for (int x = 0; x < 30; x++) {
	  for (int y = 0; y < 30; y++) {
		if (rand() % 10 == 1) game.add(x,y, FredkinCell(true).clone());
	  }
	}
	game.print();
	
	for(int i = 0; i < 5; i++) {
	  game.run(10);
	  game.print();
	}
	

  } catch (const invalid_argument&) {
	assert(false);
  } catch (const out_of_range&) {
	assert(false);
  }



  // ----------------
  // Cell 2x2
  // ----------------
  
  try {
	cout << "*** Life<Cell> 2x2 ***" << endl;
	
	
	Life<Cell> game(2,2);
	game.add(0,0, FredkinCell(true).clone());
	game.add(1,0, FredkinCell(true).clone());
	game.add(0,1, FredkinCell(true).clone());
	game.add(1,1, FredkinCell(true).clone());
	game.print();
	
	for(int i = 0; i < 5; i++) {
	  game.run();
	  game.print();
	}
	

  } catch (const invalid_argument&) {
	assert(false);
  } catch (const out_of_range&) {
	assert(false);
  }


  // ----------------
  // Cell 2x1
  // ----------------
  
  try {
	cout << "*** Life<Cell> 2x1 ***" << endl;
	
	
	Life<Cell> game(2,1);
	game.add(0,0, FredkinCell(true).clone());
	game.add(1,0, FredkinCell(true).clone());
	game.print();
	
	for(int i = 0; i < 5; i++) {
	  game.run();
	  game.print();
	}
	

  } catch (const invalid_argument&) {
	assert(false);
  } catch (const out_of_range&) {
	assert(false);
  }



  // ----------------
  // Fredkin Cell 2x1
  // ----------------
  
  try {
	cout << "*** Life<FredkinCell> 2x1 ***" << endl;
	
	
	Life<FredkinCell> game(2,1);
	game.add(0,0, FredkinCell(true));
	game.add(1,0, FredkinCell(true));
	game.print();
	
	for(int i = 0; i < 5; i++) {
	  game.run();
	  game.print();
	}
	

  } catch (const invalid_argument&) {
	assert(false);
  } catch (const out_of_range&) {
	assert(false);
  }



  // ---------------
  // Conway Cell 1x1
  // ---------------
  
  try {
	cout << "*** Life<ConwayCell> 1x1 ***" << endl;
	/* . . . . .
	   . . . * .
       . . . * .
       . . . * .
	   . . . . .
	   . . . . .

	   Should flip back and forth!
	*/
	
	
	Life<ConwayCell> game(1,1);
	game.add(0,0, ConwayCell(true));
	game.print();
	
	for(int i = 0; i < 5; i++) {
	  game.run();
	  game.print();
	}
	

  } catch (const invalid_argument&) {
	assert(false);
  } catch (const out_of_range&) {
	assert(false);
  }


  // ---------------
  // Conway Cell 6x5
  // ---------------
  
  try {
	cout << "*** Life<ConwayCell> 6x5 ***" << endl;
	/* . . . . .
	   . . . * .
       . . . * .
       . . . * .
	   . . . . .
	   . . . . .

	   Should flip back and forth!
	*/
	
	
	Life<ConwayCell> game(5,6);
	game.add(3, 1, ConwayCell(true));
	game.add(3, 2, ConwayCell(true));
	game.add(3, 3, ConwayCell(true));
	game.print();
	
	for(int i = 0; i < 5; i++) {
	  game.run();
	  game.print();
	}	

  } catch (const invalid_argument&) {
	assert(false);
  } catch (const out_of_range&) {
	assert(false);
  }

  // -----------------
  // Conway Cell 30x30
  // -----------------
  
  try {
	cout << "*** Life<ConwayCell> 6x5 ***" << endl;
	/* 
	   Glider starts at top right
	*/

	
	Life<ConwayCell> game(30,30);
	game.add(27, 2, ConwayCell(true));
	game.add(27, 3, ConwayCell(true));
	game.add(27, 4, ConwayCell(true));
	game.add(28, 4, ConwayCell(true));
	game.add(29, 3, ConwayCell(true));
	game.print();
	
	for(int i = 1; i < 4*25; i++) {
	  game.run();
	  if (i % 16 == 0) game.print();
	}
	
  } catch (const invalid_argument&) {
	assert(false);
  } catch (const out_of_range&) {
	assert(false);
  }



  // ------------------
  // Conway Cell 109x69
  // ------------------
  
  try {
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
	
	
	ifstream file;
	int y, x;
	string tmp;
	file.open("RunLifeConway.in");
	file >> y; file >> x;
	Life<ConwayCell> game(x, y);
	
	y = 0;
	while (file >> tmp) {
	  for (unsigned i = 0; i < tmp.length(); i++) {
		if (tmp[i] == '*') game.add(i, y, ConwayCell(true));
	  }
	  //	  cout << tmp << endl;
	  y++;
	}

	game.print();
	game.run(283);
	game.print();
	game.run(323-283);
	game.print();
	game.run(2500-323);
	game.print();
	
  } catch (const invalid_argument&) {
	assert(false);
  } catch (const out_of_range&) {
	assert(false);
  }

  // ------------------
  // Fredkin Cell 20x20
  // ------------------
  
  try {
	cout << "*** Life<FredkinCell> 20x20 ***" << endl;
	/*
	  read RunLifeFredkin.in // assume all Fredkin cells
	  Simulate 5 moves.
	  Print every grid (i.e. 0, 1, 2...5)
	*/

	
	ifstream file;
	int y, x;
	string tmp;
	file.open("RunLifeFredkin.in");
	file >> y; file >> x;
	Life<FredkinCell> game(x, y);
	
	y = 0;
	while (file >> tmp) {
	  for (unsigned i = 0; i < tmp.length(); i++) {
		if (tmp[i] != '-') 
		  game.add(i, y, FredkinCell(true, tmp[i]-'0'));
	  }
	  //	  cout << tmp << endl;
	  y++;
	}
	game.print();
	for (int i = 0; i < 5; i++) {
	  game.run();
	  game.print();
	}
	
	
  } catch (const invalid_argument&) {
	assert(false);
  } catch (const out_of_range&) {
	assert(false);
  }
  
  // ----------
  // Cell 20x20
  // ----------
  
  try {
	cout << "*** Life<Cell> 20x20 ***" << endl;
	/*
	  read RunLifeCell.in // assume all Fredkin cells
	  Simulate 5 moves.
	  Print every grid (i.e. 0, 1, 2...5)
	*/
	
	ifstream file;
	int y, x;
	string tmp;
	file.open("RunLifeCell.in");
	file >> y; file >> x;
	
	Life<Cell> game(x, y);
	y = 0;
	
	while (file >> tmp) {
	  for (unsigned i = 0; i < tmp.length(); i++) {
		if (tmp[i] != '-') 
		  game.add(i, y, FredkinCell(true, tmp[i]-'0').clone());
	  }
	  //	  cout << tmp << endl;
	  y++;
	}
	game.print();

	for (int i = 0; i < 5; i++) {
	  game.run();
	  game.print();
	}

  } catch (const invalid_argument&) {
	assert(false);
  } catch (const out_of_range&) {
	assert(false);
  }
  
  return 0;
}
