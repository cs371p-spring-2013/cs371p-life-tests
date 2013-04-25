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
#include <sstream>
#include <string>
#include "Life.h"
#include "AbstractCell.h"
#include "Cell.h"


// ----
// main
// ----

int main () {
    using namespace std;
      
    // -----------
    // Conway Cell
    // -----------

    try {
        
    	std::ifstream in;
	  	in.open ("RunLifeConway.in", std::ifstream::in);
	  	
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
        
		int height, width;
		in >> height;
		in >> width;
		Life<ConwayCell> Board0 = Life<ConwayCell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board0.place(h, w, ConwayCell(c));
			}
		}
        Board0.print();
        for(int i = 0; i < 10; i++){
        	Board0.evolve();
        	Board0.print();
        }
        Board0.evolve(273);
        Board0.print();
        Board0.evolve(40);
        Board0.print();
        for(int i = 0; i < 2177; i++){
        	Board0.evolve();
        }
        Board0.print();
	  	
	  	
	  	
	  	
		cout << "*** Life<ConwayCell> 10x10 ***" << endl;
        /*
        Create Conway 10x10
        Simulate 4 moves.
        Print every grid (i.e. 0, 1, 2...4)
        */
        
		in >> height;
		in >> width;
	
		Life<ConwayCell> Board1 = Life<ConwayCell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board1.place(h, w, ConwayCell(c));
			}
		}
		
		Board1.print();
		for(int i = 0; i < 4; i++){
			Board1.evolve();
			Board1.print();
		}
        
        
        
        
        cout << "*** Life<ConwayCell> 11x10 ***" << endl;
        /*
        Create Conway 11x10
        Simulate 9 moves.
        Print every grid (i.e. 0, 1, 2...9)
        */

		in >> height;
		in >> width;
	
		Life<ConwayCell> Board2 = Life<ConwayCell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board2.place(h, w, ConwayCell(c));
			}
		}
		
		Board2.print();
		for(int i = 0; i < 9; i++){
			Board2.evolve();
			Board2.print();
		}
        
        
        
        
        cout << "*** Life<ConwayCell> 5x5 ***" << endl;
        /*
        Create Conway 5x5
        Simulate 10 moves.
        Print every grid (i.e. 0, 1, 2...10)
        */

	  	
		in >> height;
		in >> width;
	
		Life<ConwayCell> Board3 = Life<ConwayCell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board3.place(h, w, ConwayCell(c));
			}
		}
		
		Board3.print();
		for(int i = 0; i < 10; i++){
			Board3.evolve();
			Board3.print();
		}
        
        
        
        
        cout << "*** Life<ConwayCell> 10x20 ***" << endl;
        /*
        Create Conway 10x20
        Simulate 4 moves.
        Print every grid (i.e. 0, 1, 2..4)
        */

	  	
		in >> height;
		in >> width;
	
		Life<ConwayCell> Board4 = Life<ConwayCell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board4.place(h, w, ConwayCell(c));
			}
		}
		
		Board4.print();
		for(int i = 0; i < 4; i++){
			Board4.evolve();
			Board4.print();
		}
        
        
        
        
        cout << "*** Life<ConwayCell> 3x3 ***" << endl;
        /*
        Create Conway 3x3
        Simulate 6 moves.
        Print every grid (i.e. 0, 1, 2..6)
        */

	  	
		in >> height;
		in >> width;
	
		Life<ConwayCell> Board5 = Life<ConwayCell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board5.place(h, w, ConwayCell(c));
			}
		}
		
		Board5.print();
		for(int i = 0; i < 6; i++){
			Board5.evolve();
			Board5.print();
		}
        
        in.close();
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
  
    // ------------
    // Fredkin Cell
    // ------------

    try {
    	std::ifstream in;
        in.open ("RunLifeFredkin.in", std::ifstream::in);
    
    	cout << "*** Life<FredkinCell> 20x20 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        
        
		int height, width;
		in >> height;
		in >> width;
		Life<FredkinCell> Board0 = Life<FredkinCell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board0.place(h, w, FredkinCell(c));
			}
		}
        Board0.print();
        for(int i = 0; i < 5; i++){
        	Board0.evolve();
        	Board0.print();
        }
    
    
    
    
        cout << "*** Life<FredkinCell> 3x3 ***" << endl;
        /*
        Create Fredkin 3x3
        Simulate 2 moves.
        Print every grid (i.e. 0, 1, 2)
        */

		in >> height;
		in >> width;
	
		Life<FredkinCell> Board1 = Life<FredkinCell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board1.place(h, w, FredkinCell(c));
			}
		}
		
		Board1.print();
		for(int i = 0; i < 2; i++){
			Board1.evolve();
			Board1.print();
		}
		
		
		
		
		cout << "*** Life<FredkinCell> 5x10 ***" << endl;
        /*
        Create Fredkin 5x10
        Simulate 10 moves.
        Print every grid (i.e. 0, 1, 2..10)
        */

	  	
		in >> height;
		in >> width;
	
		Life<FredkinCell> Board2 = Life<FredkinCell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board2.place(h, w, FredkinCell(c));
			}
		}
		
		Board2.print();
		for(int i = 0; i < 10; i++){
			Board2.evolve();
			Board2.print();
		}
		
		
		
		
		cout << "*** Life<FredkinCell> 5x10 ***" << endl;
        /*
        Create Fredkin 5x10
        Simulate 10 moves.
        Print every grid (i.e. 0, 1, 2..10)
        */

		in >> height;
		in >> width;
	
		Life<FredkinCell> Board3 = Life<FredkinCell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board3.place(h, w, FredkinCell(c));
			}
		}
		
		Board3.print();
		for(int i = 0; i < 10; i++){
			Board3.evolve();
			Board3.print();
		}
        
        
        
        
        cout << "*** Life<FredkinCell> 5x10 ***" << endl;
        /*
        Create Fredkin 5x10
        Simulate 10 moves.
        Print every grid (i.e. 0, 1, 2..10)
        */

	  	
		in >> height;
		in >> width;
	
		Life<FredkinCell> Board4 = Life<FredkinCell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board4.place(h, w, FredkinCell(c));
			}
		}
		
		Board4.print();
		for(int i = 0; i < 10; i++){
			Board4.evolve();
			Board4.print();
		}
        
        
        
        
        cout << "*** Life<FredkinCell> 1x2 ***" << endl;
        /*
        Create Fredkin 1x2
        Simulate 10 moves.
        Print every grid (i.e. 0, 1, 2..10)
        */

	  	
		in >> height;
		in >> width;
	
		Life<FredkinCell> Board5 = Life<FredkinCell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board5.place(h, w, FredkinCell(c));
			}
		}
		
		Board5.print();
		for(int i = 0; i < 10; i++){
			Board5.evolve();
			Board5.print();
		}
        
        in.close();
        
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        
   
    // ----
    // Cell
    // ----

    try {
    	std::ifstream in;
	  	in.open ("RunLifeCell.in", std::ifstream::in);
	  	
	  	
    	cout << "*** Life<Cell> 20x20 ***" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        
		int height, width;
		in >> height;
		in >> width;
	
		Life<Cell> Board0 = Life<Cell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board0.place(h, w, Cell(new FredkinCell(c)));
			}
		}
		
		Board0.print();
		for(int i = 0; i < 5; i++){
			Board0.evolve();
			Board0.print();
		}
        
        
    	
        
        cout << "*** Life<Cell> 5x10 ***" << endl;
        /*
        Create Cell 5x10
        Simulate 10 moves.
        Print every grid (i.e. 0, 1, 2..10)
        */

		in >> height;
		in >> width;
	
		Life<Cell> Board1 = Life<Cell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board1.place(h, w, Cell(new FredkinCell(c)));
			}
		}
		
		Board1.print();
		for(int i = 0; i < 10; i++){
			Board1.evolve();
			Board1.print();
		}
        
        
        
        cout << "*** Life<Cell> 2x10 ***" << endl;
        /*
        Create Cell 2x10
        Simulate 10 moves.
        Print every grid (i.e. 0, 1, 2..10)
        */
 
	  	
		in >> height;
		in >> width;
	
		Life<Cell> Board2 = Life<Cell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board2.place(h, w, Cell(new FredkinCell(c)));
			}
		}
		
		Board2.print();
		for(int i = 0; i < 10; i++){
			Board2.evolve();
			Board2.print();
		}
		
		
		
		
		cout << "*** Life<Cell> 2x4 ***" << endl;
        /*
        Create Cell 2x4
        Simulate 10 moves.
        Print every grid (i.e. 0, 1, 2..10)
        */
        
	  	
		in >> height;
		in >> width;
	
		Life<Cell> Board3 = Life<Cell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board3.place(h, w, Cell(new FredkinCell(c)));
			}
		}
		
		Board3.print();
		for(int i = 0; i < 10; i++){
			Board3.evolve();
			Board3.print();
		}
		
		
		
		
        cout << "*** Life<Cell> 2x4 ***" << endl;
        /*
        Create Cell 2x4
        Simulate 10 moves.
        Print every grid (i.e. 0, 1, 2..10)
        */

	  	
		in >> height;
		in >> width;
	
		Life<Cell> Board4 = Life<Cell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board4.place(h, w, Cell(new FredkinCell(c)));
			}
		}
		
		Board4.print();
		for(int i = 0; i < 10; i++){
			Board4.evolve();
			Board4.print();
		}
		
		
		
		
		cout << "*** Life<Cell> 2x4 ***" << endl;
        /*
        Create Cell 1x2
        Simulate 3 moves.
        Print every grid (i.e. 0, 1, 2..3)
        */

	  	
		in >> height;
		in >> width;
	
		Life<Cell> Board5 = Life<Cell>(height, width);
		for(int h = 0; h < height; h++){
			for(int w = 0; w < width; w++){
				char c;
				in >> c;
				Board5.place(h, w, Cell(new FredkinCell(c)));
			}
		}
		
		Board5.print();
		for(int i = 0; i < 3; i++){
			Board5.evolve();
			Board5.print();
		}
        
        
        in.close();
        
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
        

    return 0;}
