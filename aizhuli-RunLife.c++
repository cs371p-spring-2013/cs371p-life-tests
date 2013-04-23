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
	EXTRACT_ALL = YES
	EXTRACT_PRIVATE = YES
	EXTRACT_STATIC = YES
	GENERATE_LATEX = NO

	To document the program:
	doxygen Doxyfile
	*/

	// --------
	// includes
	// --------

	#include <cassert> // assert
	#include <iostream> // cout, endl
	#include <stdexcept> // invalid_argument, out_of_range
	#include <fstream>

	#include "Life.h"
	#include "ConwayCell.h"
	#include "FredkinCell.h"
	#include "Cell.h"


	template <typename T>
	Life<T> defaultSetup(int _r, int _c){
		Life<T> life(_r, _c);

		for(int row = 0; row < _r; ++row){
			for(int col = 0; col < _c; ++col){
				T cell;
				life.addCell(row, col, cell, false);
			}
		}

		return life;
	}

	template <typename T>
	Life<T> setupLife(int _r, int _c, vector<string> lines){
		Life<T> life(_r, _c);

		for(int row = 0; row < _r; ++row){
			string s = lines[row];
			for(int col = 0; col < _c; ++col){
				char c = s.at(col);
				T cell;
				if(c != '.' && c != '-'){ //alive
					life.addCell(row, col, cell, true);
				}
				else { // dead
					life.addCell(row, col, cell, false);
				}
			}
		}

		return life;
	}

	template <typename T>
	Life<T> setupLifeWithCell(int _r, int _c, vector<string> lines){
		Life<T> life(_r, _c);

		for(int row = 0; row < _r; ++row){
			string s = lines[row];
			for(int col = 0; col < _c; ++col){
				char c = s.at(col);
			
				FredkinCell * f = new FredkinCell();
				T cell(f);
				if(c != '.' && c != '-'){ //alive
					life.addCell(row, col, cell, true);
				}
				else { // dead
					life.addCell(row, col, cell, false);
				}
			}
		}

		return life;
	}

	void readfile(string filename, int &r, int &c, vector<string> &lines){
		ifstream myfile (filename);
		string line;

		if(myfile.is_open()){
			getline(myfile, line);
			r = atoi(line.c_str());
			getline(myfile, line);
			c = atoi(line.c_str());
			while(myfile.good()){
				getline(myfile, line);
				lines.push_back(line);
			}
			myfile.close();
		}
	}

	template <typename T>
	Life<T> setupLifeFromFile(string filename){
		vector<string> lines;
		int r;
		int c;
		readfile(filename, r, c, lines);
		return setupLife<T>(r, c, lines);
	}

	template <typename T>
	Life<T> setupLifeWithCellFromFile(string filename){
		vector<string> lines;
		int r;
		int c;
		readfile(filename, r, c, lines);
		return setupLifeWithCell<T>(r, c, lines);
	}


// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    // ------------------
    // Conway Cell 5x5
    // ------------------


    try {
        cout << "*** Life<ConwayCell> 5x5 ***" << endl;
	cout << endl;

	int generations = 5;
	vector<bool> to_be_printed(generations + 1, true);

	Life<ConwayCell> life = defaultSetup<ConwayCell>(5, 5);
	life.addCell(4, 4);
	life.addCell(3, 3);
	life.addCell(2, 2);
	life.addCell(1, 1);
	life.addCell(0, 0);

	life.run(generations, to_be_printed, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    // ------------------
    // Conway Cell 5x5
    // ------------------


    try {
        cout << "*** Life<ConwayCell> 5x5 ***" << endl;
	cout << endl;

	int generations = 5;
	vector<bool> to_be_printed(generations + 1, true);

	Life<ConwayCell> life = defaultSetup<ConwayCell>(5, 5);
	life.addCell(2, 2);
	life.addCell(3, 1);
	life.addCell(1, 3);
	life.addCell(2, 3);

	life.run(generations, to_be_printed, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    

    // ------------------
    // Conway Cell 6x7
    // ------------------


    try {
        cout << "*** Life<ConwayCell> 6x7 ***" << endl;
	cout << endl;

	int generations = 55;
	vector<bool> to_be_printed(generations + 1, false);
	to_be_printed[0] = true;
	to_be_printed[10] = true;
	to_be_printed[20] = true;
	to_be_printed[30] = true;
	to_be_printed[55] = true;

	Life<ConwayCell> life = defaultSetup<ConwayCell>(6, 7);
	life.addCell(2, 3);
	life.addCell(2, 4);
	life.addCell(3, 3);
	life.addCell(3, 4);

	life.run(generations, to_be_printed, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Conway Cell 10x10
    // ------------------


    try {
        cout << "*** Life<ConwayCell> 10x10 ***" << endl;
	cout << endl;

	int generations = 5;
	vector<bool> to_be_printed(generations + 1, false);
	to_be_printed[0] = true;
	to_be_printed[1] = true;
	to_be_printed[2] = true;
	to_be_printed[3] = true;
	to_be_printed[4] = true;

	Life<ConwayCell> life = defaultSetup<ConwayCell>(10, 10);
	life.addCell(2, 3);
	life.addCell(2, 4);
	life.addCell(3, 3);
	life.addCell(3, 4);
	life.addCell(4, 5);
	life.addCell(4, 4);
 	life.addCell(3, 2);
	life.addCell(4, 7);
	life.run(generations, to_be_printed, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Conway Cell 30x30
    // ------------------


    try {
        cout << "*** Life<ConwayCell> 30x30 ***" << endl;
	cout << endl;

	int generations = 30;
	vector<bool> to_be_printed(generations + 1, false);
	to_be_printed[0] = true;
	to_be_printed[10] = true;
	to_be_printed[20] = true;
	to_be_printed[30] = true;

	Life<ConwayCell> life = defaultSetup<ConwayCell>(30, 30);
	life.addCell(15, 14);
	life.addCell(15, 15);
	life.addCell(15, 16);
	life.addCell(14, 15);
	life.addCell(16, 14);
	life.addCell(16, 16);
	life.addCell(17, 15);

	life.run(generations, to_be_printed, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Conway Cell 31x30
    // ------------------


    try {
        cout << "*** Life<ConwayCell> 30x30 ***" << endl;
	cout << endl;

	int generations = 30;
	vector<bool> to_be_printed(generations + 1, false);
	to_be_printed[0] = true;
	to_be_printed[1] = true;
	to_be_printed[2] = true;
	to_be_printed[10] = true;
	to_be_printed[20] = true;
	to_be_printed[30] = true;

	Life<ConwayCell> life = defaultSetup<ConwayCell>(31, 30);
	life.addCell(15, 14);
	life.addCell(15, 15);
	life.addCell(15, 16);
	life.addCell(14, 16);
	life.addCell(13, 15);

	life.run(generations, to_be_printed, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // Conway Cell 109x69
    // ------------------
    try {
        cout << "*** Life<ConwayCell> 109x69 ***" << endl;
	cout << endl;
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

	int generations = 2500;
	vector<bool> to_be_printed(generations + 1, false);
	to_be_printed[0] = true;
	to_be_printed[283] = true;
	to_be_printed[323] = true;
	to_be_printed[2500] = true;

	setupLifeFromFile<ConwayCell>("RunLifeConway.in").run(generations, to_be_printed, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
	cout << endl;
        /*
	read RunLifeFredkin.in // assume all Fredkin cells
	Simulate 5 moves.
	Print every grid (i.e. 0, 1, 2...5)
	*/
	int generations = 5;
	vector<bool> to_be_printed(generations + 1, true);

	setupLifeFromFile<FredkinCell>("RunLifeFredkin.in").run(generations, to_be_printed, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    
    
    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
	cout << endl;
	
	int generations = 5;
	vector<bool> to_be_printed(generations + 1, true);
 	Life<FredkinCell> life = defaultSetup<FredkinCell>(20, 20);

	life.addCell(7, 8);
	life.addCell(7, 9);
	life.addCell(8, 9);

	life.run(generations, to_be_printed, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
   
   
    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
	cout << endl;
	
	int generations = 4;
	vector<bool> to_be_printed(generations + 1, true);
 	Life<FredkinCell> life = defaultSetup<FredkinCell>(20, 20);

	life.addCell(5, 5);
	life.addCell(6, 5);
	life.addCell(7, 9);

	life.run(generations, to_be_printed, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
    
    
    // ------------------
    // Fredkin Cell 6x6
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 6x6 ***" << endl;
	cout << endl;
	
	int generations = 5;
	vector<bool> to_be_printed(generations + 1, true);
 	Life<FredkinCell> life = defaultSetup<FredkinCell>(6, 6);

	life.addCell(0, 0);
	life.addCell(0, 1);
	life.addCell(0, 2);
	life.addCell(0, 3);
	life.addCell(0, 4);
	life.addCell(0, 5);
	life.addCell(5, 0);
	life.addCell(5, 1);
	life.addCell(5, 2);
	life.addCell(5, 3);
	life.addCell(5, 4);
	life.addCell(5, 5);


	life.run(generations, to_be_printed, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
	cout << endl;
	
	int generations = 5;
	vector<bool> to_be_printed(generations + 1, true);
 	Life<FredkinCell> life = defaultSetup<FredkinCell>(20, 20);

	life.addCell(5, 5);

	life.run(generations, to_be_printed, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
	cout << endl;
	
	int generations = 5;
	vector<bool> to_be_printed(generations + 1, true);
 	Life<FredkinCell> life = defaultSetup<FredkinCell>(20, 20);

	life.addCell(19, 19);

	life.run(generations, to_be_printed, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}



    // ----------
    // Cell 20x20
    // ----------

    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;
	cout << endl;
        /*
	read RunLifeCell.in // assume all Fredkin cells
	Simulate 5 moves.
	Print every grid (i.e. 0, 1, 2...5)
	*/
        int generations = 5;
	vector<bool> to_be_printed(generations + 1, true);

	setupLifeWithCellFromFile<Cell>("RunLifeCell.in").run(generations, to_be_printed, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 10x10
    // ----------

    try {
        cout << "*** Life<Cell> 10x10 ***" << endl;
	cout << endl;
        int generations = 4;
	vector<bool> to_be_printed(generations + 1, true);
	
	vector<string> lines;
	lines.push_back("----------");
	lines.push_back("----------");
	lines.push_back("----------");
	lines.push_back("--+-------");
	lines.push_back("--+-------");
	lines.push_back("----------");
	lines.push_back("----------");
	lines.push_back("----------");
	lines.push_back("----------");
	lines.push_back("----------");


 	Life<Cell> life = setupLifeWithCell<Cell>(10, 10, lines);

	life.run(generations, to_be_printed, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
     
     
     // ----------
     // Cell 10x10
     // ----------

    try {
        cout << "*** Life<Cell> 10x10 ***" << endl;
	cout << endl;
        int generations = 4;
	vector<bool> to_be_printed(generations + 1, true);
	
	vector<string> lines;
	lines.push_back("----------");
	lines.push_back("----------");
	lines.push_back("----------");
	lines.push_back("--+----+--");
	lines.push_back("--+----+--");
	lines.push_back("--+----+--");
	lines.push_back("--+----+--");
	lines.push_back("----------");
	lines.push_back("----------");
	lines.push_back("----------");


 	Life<Cell> life = setupLifeWithCell<Cell>(10, 10, lines);

	life.run(generations, to_be_printed, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
   
   
    // ----------
    // Cell 20x20
    // ----------

    try {
        cout << "*** Life<Cell> 10x10 ***" << endl;
	cout << endl;
        int generations = 3;
	vector<bool> to_be_printed(generations + 1, true);
	
	vector<string> lines;
	lines.push_back("----------");
	lines.push_back("----------");
	lines.push_back("----------");
	lines.push_back("----------");
	lines.push_back("--+-------");
	lines.push_back("---+------");
	lines.push_back("----------");
	lines.push_back("----------");
	lines.push_back("----------");
	lines.push_back("----------");


 	Life<Cell> life = setupLifeWithCell<Cell>(10, 10, lines);

	life.run(generations, to_be_printed, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 10x10
    // ----------

    try {
        cout << "*** Life<Cell> 10x10 ***" << endl;
	cout << endl;
        int generations = 4;
	vector<bool> to_be_printed(generations + 1, true);
	
	vector<string> lines;
	lines.push_back("----------");
	lines.push_back("----------");
	lines.push_back("----------");
	lines.push_back("---+------");
	lines.push_back("--+-+-----");
	lines.push_back("----------");
	lines.push_back("----------");
	lines.push_back("----------");
	lines.push_back("----------");
	lines.push_back("----------");


 	Life<Cell> life = setupLifeWithCell<Cell>(10, 10, lines);

	life.run(generations, to_be_printed, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 10x10
    // ----------

    try {
        cout << "*** Life<Cell> 10x10 ***" << endl;
	cout << endl;
        int generations = 4;
	vector<bool> to_be_printed(generations + 1, true);
	
	vector<string> lines;
	lines.push_back("----------");
	lines.push_back("----------");
	lines.push_back("----------");
	lines.push_back("----------");
	lines.push_back("--+-------");
	lines.push_back("--+-------");
	lines.push_back("--+-------");
	lines.push_back("--+-------");
	lines.push_back("----------");
	lines.push_back("----------");


 	Life<Cell> life = setupLifeWithCell<Cell>(10, 10, lines);

	life.run(generations, to_be_printed, cout);
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}



    return 0;}
