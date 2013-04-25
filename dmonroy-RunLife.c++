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
#include "Life.h"
#include "Cell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Handle.h"
#include "AbstractCell.h"

#define COUT_ON 0
#define PRINT_COUT(x) if(COUT_ON) x
#define PRINT_FILE(x) if(!COUT_ON) x

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    // ------------------
    // 1 Conway Cell 5x5
    // ------------------

    try {
       cout << "1 *** Life<ConwayCell> 5x5 ***" << endl << endl;
        /*
        read own.in // assume all Conway cells
        Simulate 10 moves.
        Print the first 10 grids (i.e. 0, 1, 2...9).
        Print the 283rd grid.
        Simulate 40 moves.
        Print the 323rd grid.
        Simulate 2177 moves.
        Print the 2500th grid.
        
        */
        ifstream read("own.in");
        ofstream write("Conway1.out");
        Life<ConwayCell> l = Life<ConwayCell>(read);

        //Print to file
        PRINT_FILE(l.print(write << "1 *** Life<ConwayCell> 5x5 ***" << endl<<endl));
        for(int i = 1; i <= 10; i++)
        {
           PRINT_FILE(l.execute(1));
           PRINT_FILE(l.print(write));
        }
        PRINT_FILE(l.execute(273)); //283 -10
        PRINT_FILE(l.print(write));
        PRINT_FILE(l.execute(40));
        PRINT_FILE(l.print(write));
        PRINT_FILE(l.execute(2177));
        PRINT_FILE(l.print(write));

        //Print to cout
        PRINT_COUT(l.print(cout));
        for(int i = 1; i <= 10; i++)
        {
           l.execute(1);
           PRINT_COUT(l.print(cout));
        }
        l.execute(273); //283 -10
        PRINT_COUT(l.print(cout));
        l.execute(40);
        PRINT_COUT(l.print(cout));
        l.execute(2177);
        PRINT_COUT(l.print(cout));


    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // 2 Conway Cell 5x5
    // ------------------

    try {
        cout << "2 *** Life<ConwayCell> 5x5 ***" << endl << endl;
        /*
        read own.in // assume all Conway cells
        Simulate 10 moves.
        Print the first 10 grids (i.e. 0, 1, 2...9).
        */


        ifstream read("own.in");
        ofstream write("Conway2.out");
        Life<ConwayCell> l = Life<ConwayCell>(read);

        //Print to file
        PRINT_FILE(l.print(write << "2 *** Life<ConwayCell> 5x5 ***" << endl<<endl));
        for(int i = 1; i <= 10; i++)
        {
           PRINT_FILE(l.execute(1));
           PRINT_FILE(l.print(write));
        }
        

        //Print to cout
        PRINT_COUT(l.print(cout));
        for(int i = 1; i <= 10; i++)
        {
           l.execute(1);
           PRINT_COUT(l.print(cout));
        }
        


    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // 3 Conway Cell 1x1
    // ------------------

    try {
        cout << "3 *** Life<ConwayCell> 1x1 ***" << endl<< endl;
        /*
        read own.in // assume all Conway cells
        Simulate 10 moves.
        Print the first 10 grids (i.e. 0, 1, 2...9).
        */


        ofstream read1("temp.in");
        read1 << 1 << endl;
        read1 << 1 << endl;
        read1 << '.' << endl;
        ifstream read("temp.in");
        ofstream write("Conway3.out");
        Life<ConwayCell> l = Life<ConwayCell>(read);

        //Print to file
        PRINT_FILE(l.print(write << "3 *** Life<ConwayCell> 1x1 ***" << endl<<endl));
        for(int i = 1; i <= 10; i++)
        {
           PRINT_FILE(l.execute(1));
           PRINT_FILE(l.print(write));
        }
        

        //Print to cout
        PRINT_COUT(l.print(cout));
        for(int i = 1; i <= 10; i++)
        {
           l.execute(1);
           PRINT_COUT(l.print(cout));
        }
        


    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // 4 Conway Cell 1x1
    // ------------------

    try {
        cout << "4 *** Life<ConwayCell> 1x1 ***" << endl<< endl;
        /*
        read own.in // assume all Conway cells
        Simulate 10 moves.
        Print the first 10 grids (i.e. 0, 1, 2...9).
        */


        ofstream read1("temp.in");
        read1 << 1 << endl;
        read1 << 1 << endl;
        read1 << '*' << endl;
        ifstream read("temp.in");
        ofstream write("Conway4.out");
        Life<ConwayCell> l = Life<ConwayCell>(read);

        //Print to file
        PRINT_FILE(l.print(write << "4 *** Life<ConwayCell> 1x1 ***" << endl<<endl));
        for(int i = 1; i <= 10; i++)
        {
           PRINT_FILE(l.execute(1));
           PRINT_FILE(l.print(write));
        }
        

        //Print to cout
        PRINT_COUT(l.print(cout));
        for(int i = 1; i <= 10; i++)
        {
           l.execute(1);
           PRINT_COUT(l.print(cout));
        }
        


    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // 5 Conway Cell 3x3
    // ------------------

    try {
        cout << "5 *** Life<ConwayCell> 3x3 ***" << endl<< endl;
        /*
        read own.in // assume all Conway cells
        Simulate 10 moves.
        Print the first 10 grids (i.e. 0, 1, 2...9).
        */


        ofstream read1("temp.in");
        read1 << 3 << endl;
        read1 << 3 << endl;
        read1 << '.' << '.' <<'*' << endl;
        read1 << '.' <<'*'<<'.' << endl;
        read1 << '.'<<'*'<<'.' << endl;
        ifstream read("temp.in");
        ofstream write("Conway5.out");
        Life<ConwayCell> l = Life<ConwayCell>(read);

        //Print to file
        PRINT_FILE(l.print(write << "5 *** Life<ConwayCell> 3x3 ***" << endl<<endl));
        for(int i = 1; i <= 10; i++)
        {
           PRINT_FILE(l.execute(1));
           PRINT_FILE(l.print(write));
        }
        

        //Print to cout
        PRINT_COUT(l.print(cout));
        for(int i = 1; i <= 10; i++)
        {
           l.execute(1);
           PRINT_COUT(l.print(cout));
        }
        


    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}



    // ------------------
    // 1 Fredkin Cell 3x3
    // ------------------

    try {
        cout << "1 *** Life<FredkinCell> 3x3 ***" << endl<< endl;
        /*
        read own.in // assume all Fredkin cells
        Simulate 10 moves.
        Print the first 10 grids (i.e. 0, 1, 2...9).
        */


        ofstream read1("temp.in");
        read1 << 3 << endl;
        read1 << 3 << endl;
        read1 << '-' << '-' <<'0' << endl;
        read1 << '-' <<'0'<<'-' << endl;
        read1 << '-'<<'0'<<'-' << endl;
        ifstream read("temp.in");
        ofstream write("Fredkin1.out");
        Life<FredkinCell> l = Life<FredkinCell>(read);

        //Print to file
        PRINT_FILE(l.print(write << "1 *** Life<FredkinCell> 3x3 ***" << endl<<endl));
        for(int i = 1; i <= 10; i++)
        {
           PRINT_FILE(l.execute(1));
           PRINT_FILE(l.print(write));
        }
        

        //Print to cout
        PRINT_COUT(l.print(cout));
        for(int i = 1; i <= 10; i++)
        {
           l.execute(1);
           PRINT_COUT(l.print(cout));
        }
        


    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // 2 Fredkin Cell 3x3
    // ------------------

    try {
        cout << "2 *** Life<FredkinCell> 3x3 ***" << endl<< endl;
        /*
        read own.in // assume all Fredkin cells
        Simulate 10 moves.
        Print the first 10 grids (i.e. 0, 1, 2...9).
        */


        ofstream read1("temp.in");
        read1 << 3 << endl;
        read1 << 3 << endl;
        read1 << '9' << '1' <<'0' << endl;
        read1 << '9' <<'-'<<'2' << endl;
        read1 << '9'<<'0'<<'3' << endl;
        ifstream read("temp.in");
        ofstream write("Fredkin2.out");
        Life<FredkinCell> l = Life<FredkinCell>(read);

        //Print to file
        PRINT_FILE(l.print(write << "2 *** Life<FredkinCell> 3x3 ***" << endl<<endl));
        for(int i = 1; i <= 10; i++)
        {
           PRINT_FILE(l.execute(1));
           PRINT_FILE(l.print(write));
        }
        

        //Print to cout
        PRINT_COUT(l.print(cout));
        for(int i = 1; i <= 10; i++)
        {
           l.execute(1);
           PRINT_COUT(l.print(cout));
        }
        


    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // 3 Fredkin Cell 3x3
    // ------------------

    try {
        cout << "3 *** Life<FredkinCell> 3x3 ***" << endl<< endl;
        /*
        read own.in // assume all Fredkin cells
        Simulate 10 moves.
        Print the first 10 grids (i.e. 0, 1, 2...9).
        */


        ofstream read1("temp.in");
        read1 << 3 << endl;
        read1 << 3 << endl;
        read1 << '9' << '-' <<'+' << endl;
        read1 << '-' <<'-'<<'-' << endl;
        read1 << '9'<<'0'<<'3' << endl;
        ifstream read("temp.in");
        ofstream write("Fredkin3.out");
        Life<FredkinCell> l = Life<FredkinCell>(read);

        //Print to file
        PRINT_FILE(l.print(write << "3 *** Life<FredkinCell> 3x3 ***" << endl<<endl));
        for(int i = 1; i <= 10; i++)
        {
           PRINT_FILE(l.execute(1));
           PRINT_FILE(l.print(write));
        }
        

        //Print to cout
        PRINT_COUT(l.print(cout));
        for(int i = 1; i <= 10; i++)
        {
           l.execute(1);
           PRINT_COUT(l.print(cout));
        }
        


    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // 4 Fredkin Cell 1x1
    // ------------------

    try {
        cout << "4 *** Life<FredkinCell> 1x1 ***" << endl<< endl;
        /*
        read own.in // assume all Fredkin cells
        Simulate 10 moves.
        Print the first 10 grids (i.e. 0, 1, 2...9).
        */


        ofstream read1("temp.in");
        read1 << 1 << endl;
        read1 << 1 << endl;
        read1 << '-' << endl;
        ifstream read("temp.in");
        ofstream write("Fredkin4.out");
        Life<FredkinCell> l = Life<FredkinCell>(read);

        //Print to file
        PRINT_FILE(l.print(write << "4 *** Life<FredkinCell> 1x1 ***" << endl<<endl));
        for(int i = 1; i <= 10; i++)
        {
           PRINT_FILE(l.execute(1));
           PRINT_FILE(l.print(write));
        }
        

        //Print to cout
        PRINT_COUT(l.print(cout));
        for(int i = 1; i <= 10; i++)
        {
           l.execute(1);
           PRINT_COUT(l.print(cout));
        }
        


    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // 5 Fredkin Cell 1x1
    // ------------------

    try {
        cout << "5 *** Life<FredkinCell> 1x1 ***" << endl<< endl;
        /*
        read own.in // assume all Fredkin cells
        Simulate 10 moves.
        Print the first 10 grids (i.e. 0, 1, 2...9).
        */


        ofstream read1("temp.in");
        read1 << 1 << endl;
        read1 << 1 << endl;
        read1 << '5' << endl;
        ifstream read("temp.in");
        ofstream write("Fredkin5.out");
        Life<FredkinCell> l = Life<FredkinCell>(read);

        //Print to file
        PRINT_FILE(l.print(write << "5 *** Life<FredkinCell> 1x1 ***" << endl<<endl));
        for(int i = 1; i <= 10; i++)
        {
           PRINT_FILE(l.execute(1));
           PRINT_FILE(l.print(write));
        }
        

        //Print to cout
        PRINT_COUT(l.print(cout));
        for(int i = 1; i <= 10; i++)
        {
           l.execute(1);
           PRINT_COUT(l.print(cout));
        }
        


    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // 1 Cell 3x3
    // ------------------

    try {
        cout << "1 *** Life<Cell> 3x3 ***" << endl<< endl;
        /*
        read own.in // assume all Fredkin cells
        Simulate 10 moves.
        Print the first 10 grids (i.e. 0, 1, 2...9).
        */


        ofstream read1("temp.in");
        read1 << 3 << endl;
        read1 << 3 << endl;
        read1 << '9' << '-' <<'+' << endl;
        read1 << '-' <<'.'<<'-' << endl;
        read1 << '*'<<'0'<<'3' << endl;
        ifstream read("temp.in");
        ofstream write("Cell1.out");
        Life<Cell> l = Life<Cell>(read);

        //Print to file
        PRINT_FILE(l.print(write << "1 *** Life<Cell> 3x3 ***" << endl<<endl));
        for(int i = 1; i <= 10; i++)
        {
           PRINT_FILE(l.execute(1));
           PRINT_FILE(l.print(write));
        }
        

        //Print to cout
        PRINT_COUT(l.print(cout));
        for(int i = 1; i <= 10; i++)
        {
           l.execute(1);
           PRINT_COUT(l.print(cout));
        }
        


    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}


    // ------------------
    // 2 Cell 3x3 //tests mutate on lower right corner
    // ------------------

    try {
        cout << "2 *** Life<Cell> 3x3 ***" << endl<< endl;
        /*
        read own.in // assume all Fredkin cells
        Simulate 10 moves.
        Print the first 10 grids (i.e. 0, 1, 2...9).
        */


        ofstream read1("temp.in");
        read1 << 3 << endl;
        read1 << 3 << endl;
        read1 << '9' << '-' <<'+' << endl;
        read1 << '-' <<'.'<<'-' << endl;
        read1 << '*'<<'0'<<'1' << endl;
        ifstream read("temp.in");
        ofstream write("Cell2.out");
        Life<Cell> l = Life<Cell>(read);

        //Print to file
        PRINT_FILE(l.print(write << "2 *** Life<Cell> 3x3 ***" << endl<<endl));
        for(int i = 1; i <= 10; i++)
        {
           PRINT_FILE(l.execute(1));
           PRINT_FILE(l.print(write));
        }
        

        //Print to cout
        PRINT_COUT(l.print(cout));
        for(int i = 1; i <= 10; i++)
        {
           l.execute(1);
           PRINT_COUT(l.print(cout));
        }
        


    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // 3 Cell 3x3
    // ------------------

    try {
        cout << "3 *** Life<Cell> 3x3 ***" << endl<< endl;
        /*
        read own.in // assume all Fredkin cells
        Simulate 10 moves.
        Print the first 10 grids (i.e. 0, 1, 2...9).
        */


        ofstream read1("temp.in");
        read1 << 3 << endl;
        read1 << 3 << endl;
        read1 << '+' << '+' <<'+' << endl;
        read1 << '.' <<'.'<<'.' << endl;
        read1 << '0'<<'*'<<'0' << endl;
        ifstream read("temp.in");
        ofstream write("Cell3.out");
        Life<Cell> l = Life<Cell>(read);

        //Print to file
        PRINT_FILE(l.print(write << "3 *** Life<Cell> 3x3 ***" << endl<<endl));
        for(int i = 1; i <= 10; i++)
        {
           PRINT_FILE(l.execute(1));
           PRINT_FILE(l.print(write));
        }
        

        //Print to cout
        PRINT_COUT(l.print(cout));
        for(int i = 1; i <= 10; i++)
        {
           l.execute(1);
           PRINT_COUT(l.print(cout));
        }
        


    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // 4 Cell 1x1
    // ------------------

    try {
        cout << "4 *** Life<Cell> 1x1 ***" << endl<< endl;
        /*
        read own.in // assume all Fredkin cells
        Simulate 10 moves.
        Print the first 10 grids (i.e. 0, 1, 2...9).
        */


        ofstream read1("temp.in");
        read1 << 1 << endl;
        read1 << 1 << endl;
        read1 << '.' << endl;
        ifstream read("temp.in");
        ofstream write("Cell4.out");
        Life<Cell> l = Life<Cell>(read);

        //Print to file
        PRINT_FILE(l.print(write << "4 *** Life<Cell> 1x1 ***" << endl<<endl));
        for(int i = 1; i <= 10; i++)
        {
           PRINT_FILE(l.execute(1));
           PRINT_FILE(l.print(write));
        }
        

        //Print to cout
        PRINT_COUT(l.print(cout));
        for(int i = 1; i <= 10; i++)
        {
           l.execute(1);
           PRINT_COUT(l.print(cout));
        }
        


    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ------------------
    // 5 Cell 1x2
    // ------------------

    try {
        cout << "5 *** Life<Cell> 1x2 ***" << endl<< endl;
        /*
        read own.in // assume all Fredkin cells
        Simulate 10 moves.
        Print the first 10 grids (i.e. 0, 1, 2...9).
        */


        ofstream read1("temp.in");
        read1 << 1 << endl;
        read1 << 2 << endl;
        read1 << '1' << '-' << endl;
        ifstream read("temp.in");
        ofstream write("Cell5.out");
        Life<Cell> l = Life<Cell>(read);

        //Print to file
        PRINT_FILE(l.print(write << "5 *** Life<Cell> 1x2 ***" << endl<<endl));
        for(int i = 1; i <= 10; i++)
        {
           PRINT_FILE(l.execute(1));
           PRINT_FILE(l.print(write));
        }
        

        //Print to cout
        PRINT_COUT(l.print(cout));
        for(int i = 1; i <= 10; i++)
        {
           l.execute(1);
           PRINT_COUT(l.print(cout));
        }
        


    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
//Dr. Downing's tests -------------------------------------------------------


    // ------------------
    // Conway Cell 109x69
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 109x69 *** Takes a while, be patient" << endl;
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

        ifstream read("RunLifeConway.in");
        ofstream write("RunLifeConway.out");
        Life<ConwayCell> l = Life<ConwayCell>(read);
        l.print(write);
        for(int i = 1; i <= 10; i++)
        {
           l.execute(1);
           l.print(write);
        }
        l.execute(273); //283 -10
        l.print(write);
        l.execute(40);
        l.print(write);
        l.execute(2177);
        l.print(write);
    
 

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
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        

*/
        ifstream read("RunLifeFredkin.in");
        ofstream write("RunLifeFredkin.out");
        Life<FredkinCell> l = Life<FredkinCell>(read);
        l.print(write);
        for(int i = 1; i <= 5; i++)
        {
           l.execute(1);
           l.print(write);
        }

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
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        ifstream read("RunLifeCell.in");
        ofstream write("RunLifeCell.out");
        
        Life<Cell> l = Life<Cell>(read);
        l.print(write);
        for(int i = 1; i <= 5; i++)
        {
           l.execute(1);
           l.print(write);
        }
         

    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;}
