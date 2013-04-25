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
#include "Life.h"
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <fstream>
#include <stdexcept> // invalid_argument, out_of_range

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    // ------------------
    // Conway Cell 109x69
    // ------------------

    try {
		string line;
		ifstream myfile ("RunLifeConway.in");
	//Set rows and Columns
		int rows= 0;
		int cols= 0;
		getline(myfile,line);
		rows = stoi(line);
		getline(myfile,line);
		cols = stoi(line);
	//----
        cout << "*** Life<ConwayCell>"<< rows<<"x"<<cols<< " ***" << endl;
		Life<ConwayCell> x  = Life<ConwayCell>(rows,cols);
		int count = 0;
		while(!line.empty()){
			getline(myfile,line);
			if(!line.empty()){
				x.AddRow(line,count);
			}
			count++;
		}
		int counter = 0;
		while(counter < 10){
			x.PrintBoard();
			x.Generation();
			counter++;
		}
		while(counter<283){
			x.Generation();
			counter++;
		}
		x.PrintBoard();
		while(counter<323){
			x.Generation();
			counter++;
		}
		x.PrintBoard();
		while(counter<2500){
			x.Generation();
			counter++;
		}
		x.PrintBoard();
		cout<<endl;
		//do other acceptance tests
		while(myfile.good()){
			getline(myfile,line);
			rows = stoi(line);
			getline(myfile,line);
			cols = stoi(line);
        	cout << "*** Life<ConwayCell>"<< rows<<"x"<<cols<< " ***" << endl;
			Life<ConwayCell> x  = Life<ConwayCell>(rows,cols);
			while(!line.empty()){
				getline(myfile,line);
				if(!line.empty()){
					x.AddRow(line,count);
				}
			}
			int counter = 0;
			while(counter <10){
				x.PrintBoard();
				x.Generation();
				counter++;
			}
			cout<<endl;
		}
		myfile.close();
     }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    try {
		string line;
		ifstream myfile ("RunLifeFredkin.in");
	//Set rows and Columns
		int rows= 0;
		int cols= 0;
		getline(myfile,line);
		rows = stoi(line);
		getline(myfile,line);
		cols = stoi(line);
	//----
        cout << "*** Life<FredkinCell>"<< rows<<"x"<<cols<< " ***" << endl;
		Life<FredkinCell> y  = Life<FredkinCell>(rows,cols);
		int count = 0;
		while(!line.empty()){
			getline(myfile,line);
			if(!line.empty()){
				y.AddRow(line,count);
			}
			count++;
		}
		int counter = 0;
		while(counter < 6){
			y.PrintBoard();
			y.Generation();
			counter++;
		}
		//do other acceptance tests
		while(myfile.good()){
			getline(myfile,line);
			rows = stoi(line);
			getline(myfile,line);
			cols = stoi(line);
        	cout << "*** Life<FredkinCell>"<< rows<<"x"<<cols<< " ***" << endl;
			Life<FredkinCell> x  = Life<FredkinCell>(rows,cols);
			while(!line.empty()){
				getline(myfile,line);
				if(!line.empty()){
					x.AddRow(line,count);
				}
			}
			int counter = 0;
			while(counter <10){
				x.PrintBoard();
				x.Generation();
				counter++;
			}
			cout<<endl;
		}
		myfile.close();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 20x20
    // ----------

    try {
		string line;
		ifstream myfile ("RunLifeCell.in");
	//Set rows and Columns
		int rows= 0;
		int cols= 0;
		getline(myfile,line);
		rows = stoi(line);
		getline(myfile,line);
		cols = stoi(line);
	//----
        cout << "*** Life<Cell>"<< rows<<"x"<<cols<< " ***" << endl;
		Life<Cell> y  = Life<Cell>(rows,cols);
		int count = 0;
		while(!line.empty()){
			getline(myfile,line);
			if(!line.empty()){
				y.AddRow(line,count);
			}
			count++;
		}
		int counter = 0;
		while(counter < 6){
			y.PrintBoard();
			y.Generation();
			counter++;
		}
		//do other acceptance tests
		while(myfile.good()){
			getline(myfile,line);
			rows = stoi(line);
			getline(myfile,line);
			cols = stoi(line);
        	cout << "*** Life<Cell>"<< rows<<"x"<<cols<< " ***" << endl;
			Life<Cell> x  = Life<Cell>(rows,cols);
			while(!line.empty()){
				getline(myfile,line);
				if(!line.empty()){
					x.AddRow(line,count);
				}
			}
			int counter = 0;
			while(counter <10){
				x.PrintBoard();
				x.Generation();
				counter++;
			}
			cout<<endl;
		}
		myfile.close();
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}

