// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream> // istringtstream, ostringstream
#include <string> // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TextTestRunner

#define private   public
#define protected   public

#include "AbstractCell.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Life.h"

using namespace std;
// -----------
// TestLife
// -----------

struct TestLife : CppUnit::TestFixture {

    //Testing the tester
    void test_1(){
        CPPUNIT_ASSERT(1);
    }

    void test_constructor_1(){
        ConwayCell cc(true);
        CPPUNIT_ASSERT(cc.is_alive == true);
    }

    void test_constructor_2(){
        FredkinCell fc(true);
        CPPUNIT_ASSERT(fc.is_alive == true);
        CPPUNIT_ASSERT(fc.age == 0);
    }


    //Dyanmic Binding Constructor Test Cases

    void test_constructor_3(){
        AbstractCell* ac = new FredkinCell(true);
        CPPUNIT_ASSERT(ac->toString() == "0");
    }

    void test_constructor_4(){
        AbstractCell* ac = new ConwayCell(true);
        CPPUNIT_ASSERT(ac->toString() == "*");
    }

    void test_constructor_5(){
        Cell c = new ConwayCell(true);
        CPPUNIT_ASSERT(c.isAlive() == true);
        CPPUNIT_ASSERT(c.toString() == "*");
    }

    void test_constructor_6(){
        Cell c = new ConwayCell(false);
        CPPUNIT_ASSERT(c.isAlive() == false);
        CPPUNIT_ASSERT(c.toString() == ".");
    }

    void test_constructor_7(){
        Cell c = new FredkinCell(true);
        CPPUNIT_ASSERT(c.isAlive() == true);
        CPPUNIT_ASSERT(c.toString() == "0");
    }

    void test_constructor_8(){
        Cell c = new FredkinCell(false);
        CPPUNIT_ASSERT(c.isAlive() == false);
        CPPUNIT_ASSERT(c.toString() == "-");
    }


    /**Does the default constructor of cell create a FredkinCell?
    * Does it follow the same rules as Fredkin Cells?
    **/
    void test_default_constructor_cell(){
        Cell x;
        CPPUNIT_ASSERT(x.isAlive() == false);
        CPPUNIT_ASSERT(x.toString() == "-");
        x.toggle_life_death(true);
        CPPUNIT_ASSERT(x.isAlive() == true);
        CPPUNIT_ASSERT(x.toString() == "0");
    }

    /**Does the default constructor of cell create a FredkinCell?
    * Does it follow the same rules as Fredkin Cells?
    * Does the default constructor work when used in the gameboard's context?
    **/
    void test_default_constructor_cell_in_life(){
        Life<Cell> l(4,4);
        Cell& x = l.getCell(0,0);
        CPPUNIT_ASSERT(x.isAlive() == false);
        x.toggle_life_death(true);
        CPPUNIT_ASSERT(x.isAlive() == true);
        CPPUNIT_ASSERT(x.toString() == "0");
        Cell& y = l.getCell(0,0); //Pull cell out of board again to make sure value was written
        CPPUNIT_ASSERT(y.isAlive() == true);
    }


    //------------
    // Test Conway
    //------------
        //IsAlive();
            void test_isAlive_1(){
                ConwayCell cc(true);
                CPPUNIT_ASSERT(cc.isAlive() == true);
            }

            void test_isAlive_2(){
                ConwayCell cc(false);
                CPPUNIT_ASSERT(cc.isAlive() == false);
            }

            void test_isAlive_3(){

                try{
                    ConwayCell cc();
                    CPPUNIT_ASSERT(false);
                }
                catch(...){
                    CPPUNIT_ASSERT(true);
                }
            }
        //ToString();
            void test_toString_1(){
                ConwayCell c(true);
                CPPUNIT_ASSERT(c.toString() == "*");
            }
            void test_toString_2(){
                ConwayCell c(false);
                CPPUNIT_ASSERT(c.toString() == ".");
            }
        //toggle_life_death();
            void test_toggle_life_death_2(){
                ConwayCell cc(true);
                CPPUNIT_ASSERT(cc.is_alive == true);
                cc.toggle_life_death(false);
                CPPUNIT_ASSERT(cc.is_alive == false);
        
            }

            void test_toggle_1(){
                ConwayCell c(true);
                CPPUNIT_ASSERT(c.is_alive == true);
                c.toggle_life_death(true);
                CPPUNIT_ASSERT(c.is_alive == true);
            }

            void test_toggle_2(){
                ConwayCell c;
                CPPUNIT_ASSERT(c.is_alive == false);
                c.toggle_life_death(true);
                CPPUNIT_ASSERT(c.is_alive == true);
            }
        //Turn();
            void test_life_turn_2(){
                Life<ConwayCell> l (3,3);
                l.getCell(1,1).toggle_life_death(true);
                l.getCell(1,0).toggle_life_death(true);
                l.getCell(1,2).toggle_life_death(true);
                ostringstream w;
                l.runLife(1,1, w,0);

                CPPUNIT_ASSERT(w.str() == "\nGeneration = 0, Population = 3.\n...\n***\n...\n\nGeneration = 1, Population = 3.\n.*.\n.*.\n.*.\n");
            }

            void test_turn_1(){
                Life<ConwayCell> l (1,1);
                l.getCell(0,0).toggle_life_death(true);
                ostringstream w;
                l.runLife(1,1, w,0);
                CPPUNIT_ASSERT(w.str() == "\nGeneration = 0, Population = 1.\n*\n\nGeneration = 1, Population = 0.\n.\n");
            }

            void test_turn_2(){ //Could also be an acceptance test. The cool moement when NOTHING CHANGES!!!
                Life<ConwayCell> l (2,2);
                l.getCell(0,0).toggle_life_death(true);
                l.getCell(0,1).toggle_life_death(true);
                l.getCell(1,0).toggle_life_death(true);
                l.getCell(1,1).toggle_life_death(true);
                ostringstream w;
                l.runLife(1,1, w,0);
                CPPUNIT_ASSERT(w.str() == "\nGeneration = 0, Population = 4.\n**\n**\n\nGeneration = 1, Population = 4.\n**\n**\n");
            }

        //Clone();
            void test_clone_1(){
                ConwayCell c(true);
                ConwayCell* cc = c.clone();
                CPPUNIT_ASSERT(c.is_alive == cc->is_alive);
                CPPUNIT_ASSERT(&(c.is_alive) != &(cc->is_alive));
            }

            void test_clone_2(){
                ConwayCell c;
                CPPUNIT_ASSERT(c.is_alive == false);
                ConwayCell* cc = c.clone();
                CPPUNIT_ASSERT(cc->is_alive == false);
                CPPUNIT_ASSERT(c.is_alive == cc->is_alive);
                CPPUNIT_ASSERT(&(c.is_alive) != &(cc->is_alive));
               // CPPUNIT_ASSERT(&c != &cc);
            }

            void test_clone_3(){
                ConwayCell c(false);
                ConwayCell* cc = c.clone();
                CPPUNIT_ASSERT(c.is_alive == cc->is_alive);
                CPPUNIT_ASSERT(&(c.is_alive) != &(cc->is_alive));
                c.toggle_life_death(true);
                CPPUNIT_ASSERT(c.is_alive != cc->is_alive);
            }

    //------------
    // Test Fredkin
    //------------

        //IsAlive();
            void test_isAlive_4(){
                FredkinCell fc(true);
                CPPUNIT_ASSERT(fc.isAlive() == true);
            }

            void test_isAlive_5(){
                FredkinCell fc(false);
                CPPUNIT_ASSERT(fc.isAlive() == false);
            }

            void test_isAlive_6(){

                try{
                    FredkinCell fc();
                    CPPUNIT_ASSERT(false);
                }
                catch(...){
                    CPPUNIT_ASSERT(true);
                }
            }
        //ToString();
            void test_toString_4(){
                FredkinCell c(true);
                CPPUNIT_ASSERT(c.toString() == "0");
            }
            void test_toString_5(){
                FredkinCell c(false);
                CPPUNIT_ASSERT(c.toString() == "-");
            }
            void test_toString_6(){
                FredkinCell c(true);
                vector<int> aliveNeighbors;
                aliveNeighbors.push_back(0);
                aliveNeighbors.push_back(1);
                aliveNeighbors.push_back(0);
                aliveNeighbors.push_back(1);
                aliveNeighbors.push_back(1);
                aliveNeighbors.push_back(0);
                aliveNeighbors.push_back(0);
                aliveNeighbors.push_back(0);
                c.turn(aliveNeighbors);
                CPPUNIT_ASSERT(c.toString() == "1");
            }
        //toggle_life_death();
            void test_toggle_life_death_1(){
                FredkinCell fc(true);
                CPPUNIT_ASSERT(fc.is_alive == true);
                fc.toggle_life_death(false);
                CPPUNIT_ASSERT(fc.age == 0);
                CPPUNIT_ASSERT(fc.is_alive == false);
            }

            void test_toggle_3(){
                FredkinCell c(true);
                CPPUNIT_ASSERT(c.is_alive == true);
                c.toggle_life_death(true);
                CPPUNIT_ASSERT(c.is_alive == true);
                CPPUNIT_ASSERT(c.age == 0);
            }

            void test_toggle_4(){
                FredkinCell c;
                CPPUNIT_ASSERT(c.is_alive == false);
                c.toggle_life_death(true);
                CPPUNIT_ASSERT(c.is_alive == true);
                CPPUNIT_ASSERT(c.age == 0);
            }
        //Turn();
            void test_life_turn_1(){
                Life<FredkinCell> l (3,3);
                FredkinCell& f = l.getCell(1,1);
                f.toggle_life_death(true);
                ostringstream w;
                l.runLife(1,1, w,0);

                //l.displayGrid(w);
                CPPUNIT_ASSERT(w.str() == "\nGeneration = 0, Population = 1.\n---\n-0-\n---\n\nGeneration = 1, Population = 4.\n-0-\n0-0\n-0-\n");
            }

            void test_turn_3(){
                Life<FredkinCell> l (2,1);
                l.getCell(0,0).toggle_life_death(true);
                l.getCell(0,1).toggle_life_death(true);
                ostringstream w; 
                l.runLife(3,1,w,0);
                CPPUNIT_ASSERT(w.str() == "\nGeneration = 0, Population = 2.\n00\n\nGeneration = 1, Population = 2.\n11\n\nGeneration = 2, Population = 2.\n22\n\nGeneration = 3, Population = 2.\n33\n");
            }

            void test_turn_4(){
                Life<FredkinCell> l (2,1);
                l.getCell(0,0).toggle_life_death(true);
                l.getCell(0,1).toggle_life_death(true);
                ostringstream w; 
                l.runLife(10,1,w,0);
                CPPUNIT_ASSERT(w.str() == "\nGeneration = 0, Population = 2.\n00\n\nGeneration = 1, Population = 2.\n11\n\nGeneration = 2, Population = 2.\n22\n\nGeneration = 3, Population = 2.\n33\n\nGeneration = 4, Population = 2.\n44\n\nGeneration = 5, Population = 2.\n55\n\nGeneration = 6, Population = 2.\n66\n\nGeneration = 7, Population = 2.\n77\n\nGeneration = 8, Population = 2.\n88\n\nGeneration = 9, Population = 2.\n99\n\nGeneration = 10, Population = 2.\n++\n");
            }

        //Clone();
            void test_clone_4(){
                FredkinCell c(true);
                FredkinCell* cc = c.clone();
                CPPUNIT_ASSERT(c.is_alive == cc->is_alive);
                CPPUNIT_ASSERT(&(c.is_alive) != &(cc->is_alive));
            }

            void test_clone_5(){
                FredkinCell c;
                CPPUNIT_ASSERT(c.is_alive == false);
                FredkinCell* cc = c.clone();
                CPPUNIT_ASSERT(cc->is_alive == false);
                CPPUNIT_ASSERT(c.is_alive == cc->is_alive);
                CPPUNIT_ASSERT(&(c.is_alive) != &(cc->is_alive));
               // CPPUNIT_ASSERT(&c != &cc);
            }

            void test_clone_6(){
                FredkinCell c(false);
                FredkinCell* cc = c.clone();
                CPPUNIT_ASSERT(c.is_alive == cc->is_alive);
                CPPUNIT_ASSERT(&(c.is_alive) != &(cc->is_alive));
                c.toggle_life_death(true);
                CPPUNIT_ASSERT(c.is_alive != cc->is_alive);
            }

            void test_clone_7(){
                FredkinCell c(false);
                AbstractCell* cc = c.clone();
                try{
                    CPPUNIT_ASSERT(c.age == ((FredkinCell*)cc)->age);
                    CPPUNIT_ASSERT(true);
                }
                catch(...){
                    CPPUNIT_ASSERT(false);
                }
            }


    //------------
    // Test Cell
    //------------

        //IsAlive();
            void test_isAlive_7(){
                Cell c = new FredkinCell(true);
                CPPUNIT_ASSERT(c.isAlive() == true);
            }

            void test_isAlive_8(){
                Cell c = new FredkinCell(false);
                CPPUNIT_ASSERT(c.isAlive() == false);
            }

            void test_isAlive_9(){

                try{
                    Cell c = new FredkinCell();
                    c.isAlive();
                    CPPUNIT_ASSERT(false);
                }
                catch(...){
                    CPPUNIT_ASSERT(true);
                }
            }

            void test_isAlive_10(){
                Cell c = new ConwayCell(true);
                CPPUNIT_ASSERT(c.isAlive() == true);
            }

            void test_isAlive_11(){
                Cell c = new ConwayCell(false);
                CPPUNIT_ASSERT(c.isAlive() == false);
            }

            void test_isAlive_12(){

                try{
                    Cell c = new ConwayCell();
                    c.isAlive();
                    CPPUNIT_ASSERT(false);
                }
                catch(...){
                    CPPUNIT_ASSERT(true);
                }
            }
        //ToString();
            void test_handler_1(){
                Cell c = new FredkinCell(true);
                CPPUNIT_ASSERT(c.toString() == "0");

            }

            void test_handler_2(){
                Cell c = new ConwayCell(true);
                CPPUNIT_ASSERT(c.toString() == "*");
            }

            void test_toString_7(){
                Cell c = new FredkinCell(true);
                vector<int> aliveNeighbors;
                aliveNeighbors.push_back(0);
                aliveNeighbors.push_back(1);
                aliveNeighbors.push_back(0);
                aliveNeighbors.push_back(1);
                aliveNeighbors.push_back(1);
                aliveNeighbors.push_back(0);
                aliveNeighbors.push_back(0);
                aliveNeighbors.push_back(0);
                c.turn(aliveNeighbors);
                CPPUNIT_ASSERT(c.toString() == "1");
                c.turn(aliveNeighbors);
                CPPUNIT_ASSERT(c.toString() == "*");
            }

        //toggle_life_death();
            void test_toggle_life_death_3(){
                Cell c =new FredkinCell(true);
                CPPUNIT_ASSERT(c.isAlive() == true);
                c.toggle_life_death(false);
                CPPUNIT_ASSERT(c.isAlive() == false);
            }

            void test_toggle_5(){
                Cell c = new ConwayCell(true);
                CPPUNIT_ASSERT(c.isAlive() == true);
                c.toggle_life_death(true);
                CPPUNIT_ASSERT(c.isAlive() == true);

            }

            void test_toggle_6(){
                Cell c;
                CPPUNIT_ASSERT(c.isAlive() == false);
                c.toggle_life_death(true);
                CPPUNIT_ASSERT(c.isAlive() == true);
                CPPUNIT_ASSERT(c.toString() == "0");
            }
        //Turn();
            void test_life_turn_3(){
                Life<Cell> l (3,3);
                Cell& f = l.getCell(1,1);
                f.toggle_life_death(true);
                Cell&f2 = l.getCell(1,0);
                f2.toggle_life_death(true);
                Cell&f3 = l.getCell(1,2);
                f3.toggle_life_death(true);
                ostringstream w;
                //l.displayGrid(w);

               l.runLife(1,1,w,0);
                CPPUNIT_ASSERT(w.str() == "\nGeneration = 0, Population = 3.\n---\n000\n---\n\nGeneration = 1, Population = 8.\n000\n1-1\n000\n");
            }


            void test_turn_5(){
                Life<Cell> l(2,1);
                l.getCell(0,0).toggle_life_death(true);
                l.getCell(0,1).toggle_life_death(true);
                ostringstream w; 
                l.runLife(2,1,w,0);
                CPPUNIT_ASSERT(w.str() == "\nGeneration = 0, Population = 2.\n00\n\nGeneration = 1, Population = 2.\n11\n\nGeneration = 2, Population = 2.\n**\n");
            }
        
            void test_turn_6(){
                Life<Cell> l(3,3);
                l.getCell(0,1).toggle_life_death(true);
                l.getCell(1,1).toggle_life_death(true);
                l.getCell(2,1).toggle_life_death(true);
                ostringstream w; 
                l.runLife(2,1,w,0);
                CPPUNIT_ASSERT(w.str() == "\nGeneration = 0, Population = 3.\n-0-\n-0-\n-0-\n\nGeneration = 1, Population = 8.\n010\n0-0\n010\n\nGeneration = 2, Population = 0.\n---\n---\n---\n");
            }

        //Clone();
            void test_clone_8(){
                Cell c =new  ConwayCell(true);
                Cell cc = c.clone();
                CPPUNIT_ASSERT(c.isAlive() == cc.isAlive());
            }

            void test_clone_9(){
                Cell c;
                CPPUNIT_ASSERT(c.isAlive() == false);
                Cell cc = c.clone();
                CPPUNIT_ASSERT(cc.isAlive() == false);
                CPPUNIT_ASSERT(c.isAlive() == cc.isAlive());
            }

            void test_clone_10(){
                Cell c = new FredkinCell(false);
                Cell cc = c.clone();
                CPPUNIT_ASSERT(c.isAlive() == cc.isAlive());
                c.toggle_life_death(true);
                CPPUNIT_ASSERT(c.isAlive() != cc.isAlive());
            }

        //Mutate();
            void test_mutate_1(){
                Cell x= new FredkinCell(false);
                std::vector<int> n;
                n.push_back(0);
                n.push_back(1);
                n.push_back(0);n.push_back(0);n.push_back(0);n.push_back(0);n.push_back(0);n.push_back(0);
                x.turn(n);
                x.turn(n);
                x.turn(n);
                CPPUNIT_ASSERT(x.toString() == "*");
            }

            void test_mutate_2(){
                Cell x= new FredkinCell(true);
                CPPUNIT_ASSERT(x.toString() == "0");
                std::vector<int> n;
                n.push_back(0);
                n.push_back(1);
                n.push_back(0);n.push_back(0);n.push_back(0);n.push_back(0);n.push_back(0);n.push_back(0);
                x.turn(n);
                x.turn(n);
                CPPUNIT_ASSERT(x.toString() == "*");
                
            }

            void test_mutate_3(){ //Will not mutate, due 
                Cell x= new FredkinCell(false);
                std::vector<int> n;
                n.push_back(0);n.push_back(0); n.push_back(0);n.push_back(0);n.push_back(0);n.push_back(0);n.push_back(0);n.push_back(0);
                x.turn(n);
                x.turn(n);
                x.turn(n);
                CPPUNIT_ASSERT(x.toString() != "*");
            }

    //-----------
    // Test Life
    //-----------

        //Grid Constructor:
            void test_life_1 (){
                Life<FredkinCell> l (5,5);
                CPPUNIT_ASSERT(l.grid.at(0).at(0).toString() == "-");
            }
            void test_life_2 (){
                Life<ConwayCell> l (5,5);
                CPPUNIT_ASSERT(l.grid.at(0).at(0).toString() == ".");
            }
            void test_life_3 (){
                Life<Cell> l (5,5);
                CPPUNIT_ASSERT(l.grid.at(0).at(0).toString() == "-");
            }

        //Get Cell:
            void test_getCell_1(){
                Life<FredkinCell> l (5,5);
                FredkinCell& f = l.getCell(1,1);
                f.toggle_life_death(true);
                CPPUNIT_ASSERT(f.is_alive == true);
                FredkinCell& f2 = l.getCell(0,0);
                CPPUNIT_ASSERT(f2.is_alive == false);
            }

            //Is change being written to grid?
            void test_getCell_2(){
                Life<ConwayCell> l (5,5);
                ConwayCell& f = l.getCell(1,1);
                f.toggle_life_death(true);
                CPPUNIT_ASSERT(f.is_alive == true);
                ConwayCell& f2 = l.getCell(1,1);
                CPPUNIT_ASSERT(f2.is_alive == true);
            }

            //Is change being written to grid?
            void test_getCell_3(){
                Life<Cell> l (5,5);
                Cell& f = l.getCell(1,1);
                f.toggle_life_death(true);
                CPPUNIT_ASSERT(f.isAlive() == true);
                Cell& f2 = l.getCell(1,1);
                CPPUNIT_ASSERT(f2.isAlive() == true);
            }

        //Display Grid:
            //Display all dead grid
            void test_displayGrid_1(){
                std::ostringstream w;
                Life<FredkinCell> l (2,2);
                l.displayGrid(w);
                CPPUNIT_ASSERT(w.str() == "--\n--\n");
            }

            void test_displayGrid_2(){
                std::ostringstream w;
                Life<FredkinCell> l (2,2);
                FredkinCell& f = l.getCell(1,1);
                f.toggle_life_death(true);
                CPPUNIT_ASSERT(f.is_alive == true);
                l.displayGrid(w);
                CPPUNIT_ASSERT(w.str() == "--\n-0\n");
            }

            void test_displayGrid_3(){
                std::ostringstream w;
                Life<Cell> l (2,2);
                Cell& f = l.getCell(1,1);
                f.toggle_life_death(true);
                CPPUNIT_ASSERT(f.isAlive() == true);
                l.displayGrid(w);
                CPPUNIT_ASSERT(w.str() == "--\n-0\n");
            }

    //initSnapshot
    void test_initSnapshot_1(){
        Life<FredkinCell> l (5,5);
        FredkinCell& f = l.getCell(1,1);
        f.toggle_life_death(true);
        vector< vector<int> > snapShot;
        snapShot.resize(5);
            for(int i=0; i<5; i++){
                snapShot.at(i).resize(5);
            }
        l.initSnapshot(snapShot);

        vector< vector<int> > correct;
        correct.resize(5);
            for(int i=0; i<5; i++){
                correct.at(i).resize(5);
            }

        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                correct.at(i).at(j) = 0;
            }
        }
        correct.at(1).at(1) = 1;

        CPPUNIT_ASSERT(correct == snapShot);
    }



    void test_initSnapshot_2(){
        Life<FredkinCell> l (5,5);
        FredkinCell& f = l.getCell(1,2);
        f.toggle_life_death(true);
        vector< vector<int> > snapShot;
        snapShot.resize(5);
            for(int i=0; i<5; i++){
                snapShot.at(i).resize(5);
            }
        l.initSnapshot(snapShot);

        vector< vector<int> > correct;
        correct.resize(5);
            for(int i=0; i<5; i++){
                correct.at(i).resize(5);
            }

        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                correct.at(i).at(j) = 0;
            }
        }
        correct.at(1).at(2) = 1;

        CPPUNIT_ASSERT(correct == snapShot);
    }

    

    void test_initSnapshot_3(){
        Life<Cell> l (5,5);
        Cell& f = l.getCell(1,2);
        f.toggle_life_death(true);
        vector< vector<int> > snapShot;
        snapShot.resize(5);
            for(int i=0; i<5; i++){
                snapShot.at(i).resize(5);
            }
        l.initSnapshot(snapShot);

        vector< vector<int> > correct;
        correct.resize(5);
            for(int i=0; i<5; i++){
                correct.at(i).resize(5);
            }

        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                correct.at(i).at(j) = 0;
            }
        }
        correct.at(1).at(2) = 1;

        CPPUNIT_ASSERT(correct == snapShot);
    }

    //runLife









    //getAliveNeighbors
    //vector<int> getAliveNeighbors(int row, int col, vector< vector<int> >& gridSnapshot)
//top left[0], top middle[1], top right[2], middle left[3], middle right[4]
        //bottom left[5], bottom middle[6], bottom right[7]

    void test_neighbors_1(){
      Life<Cell> l (3,3);
      Cell& f = l.getCell(1,1);
      f.toggle_life_death(true);
      vector< vector<int> > snapShot;
      snapShot.resize(3);
          for(int i=0; i<3; i++){
              snapShot.at(i).resize(3);
          }
      l.initSnapshot(snapShot);
      vector<int> aliveNeighbors = l.getAliveNeighbors(0,0, snapShot);
      CPPUNIT_ASSERT(aliveNeighbors.at(7) == 1);
      
    }
    void test_neighbors_2(){
      Life<FredkinCell> l (3,3);
      FredkinCell& f = l.getCell(1,1);
      f.toggle_life_death(true);
      FredkinCell& f2 = l.getCell(0,1);
      f2.toggle_life_death(true);
      vector< vector<int> > snapShot;
      snapShot.resize(3);
          for(int i=0; i<3; i++){
              snapShot.at(i).resize(3);
          }
      l.initSnapshot(snapShot);
      vector<int> aliveNeighbors = l.getAliveNeighbors(0,0, snapShot);
      CPPUNIT_ASSERT(aliveNeighbors.at(7) == 1);
      CPPUNIT_ASSERT(aliveNeighbors.at(4) == 1);
    }

    void test_neighbors_3(){
      Life<ConwayCell> l (3,3);
      ConwayCell& f = l.getCell(1,1);
      f.toggle_life_death(true);
      ConwayCell& f2 = l.getCell(0,1);
      f2.toggle_life_death(true);
      vector< vector<int> > snapShot;
      snapShot.resize(3);
          for(int i=0; i<3; i++){
              snapShot.at(i).resize(3);
          }
      l.initSnapshot(snapShot);
      vector<int> aliveNeighbors = l.getAliveNeighbors(0,0, snapShot);
      CPPUNIT_ASSERT(aliveNeighbors.at(7) == 1);
      CPPUNIT_ASSERT(aliveNeighbors.at(4) == 1);
    }



    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST(test_1);

    //Test constructors
    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_constructor_3);
    CPPUNIT_TEST(test_constructor_4);
    CPPUNIT_TEST(test_constructor_5);
    CPPUNIT_TEST(test_constructor_6);
    CPPUNIT_TEST(test_constructor_7);
    CPPUNIT_TEST(test_constructor_8);
    CPPUNIT_TEST(test_default_constructor_cell);
    CPPUNIT_TEST(test_default_constructor_cell_in_life);
    CPPUNIT_TEST(test_life_1);
    CPPUNIT_TEST(test_life_2);
    CPPUNIT_TEST(test_life_3);


     //IsAlive()
    CPPUNIT_TEST(test_isAlive_1);
    CPPUNIT_TEST(test_isAlive_2);
    CPPUNIT_TEST(test_isAlive_3);
    CPPUNIT_TEST(test_isAlive_4);
    CPPUNIT_TEST(test_isAlive_5);
    CPPUNIT_TEST(test_isAlive_6);
    CPPUNIT_TEST(test_isAlive_7);
    CPPUNIT_TEST(test_isAlive_8);
    CPPUNIT_TEST(test_isAlive_9);
    CPPUNIT_TEST(test_isAlive_10);
    CPPUNIT_TEST(test_isAlive_11);
    CPPUNIT_TEST(test_isAlive_12);

    //ToString()
    CPPUNIT_TEST(test_toString_1);
    CPPUNIT_TEST(test_toString_2);
    CPPUNIT_TEST(test_toString_4);
    CPPUNIT_TEST(test_toString_5);
    CPPUNIT_TEST(test_toString_6);
    CPPUNIT_TEST(test_handler_1);
    CPPUNIT_TEST(test_handler_2);
    CPPUNIT_TEST(test_toString_7);

    //Toggle_Life_Death()
    CPPUNIT_TEST(test_toggle_life_death_1);
    CPPUNIT_TEST(test_toggle_life_death_2);
    CPPUNIT_TEST(test_toggle_life_death_3);
    CPPUNIT_TEST(test_toggle_1);
    CPPUNIT_TEST(test_toggle_2);
    CPPUNIT_TEST(test_toggle_3);
    CPPUNIT_TEST(test_toggle_4);
    CPPUNIT_TEST(test_toggle_5);
    CPPUNIT_TEST(test_toggle_6);


    //Turn()
    CPPUNIT_TEST(test_life_turn_1);
    CPPUNIT_TEST(test_turn_1);
    CPPUNIT_TEST(test_turn_2);
    CPPUNIT_TEST(test_life_turn_2);
    CPPUNIT_TEST(test_turn_3);
    CPPUNIT_TEST(test_turn_4);
    CPPUNIT_TEST(test_life_turn_3);
    CPPUNIT_TEST(test_turn_5);
    CPPUNIT_TEST(test_turn_6);

    //Clone()
    CPPUNIT_TEST(test_clone_1);
    CPPUNIT_TEST(test_clone_2);
    CPPUNIT_TEST(test_clone_3);
    CPPUNIT_TEST(test_clone_4);
    CPPUNIT_TEST(test_clone_5);
    CPPUNIT_TEST(test_clone_6);
    CPPUNIT_TEST(test_clone_7);
    CPPUNIT_TEST(test_clone_8);
    CPPUNIT_TEST(test_clone_9);
    CPPUNIT_TEST(test_clone_10);

    //Mutate
    CPPUNIT_TEST(test_mutate_1);
    CPPUNIT_TEST(test_mutate_2);
    CPPUNIT_TEST(test_mutate_3);


    //Test getCell
    CPPUNIT_TEST(test_getCell_1);
    CPPUNIT_TEST(test_getCell_2);
    CPPUNIT_TEST(test_getCell_3);

    //Test Display Board
    CPPUNIT_TEST(test_displayGrid_1);
    CPPUNIT_TEST(test_displayGrid_2);
    CPPUNIT_TEST(test_displayGrid_3);

    //Test initSnapshot
    CPPUNIT_TEST(test_initSnapshot_1);
    CPPUNIT_TEST(test_initSnapshot_2);
    CPPUNIT_TEST(test_initSnapshot_3);

    //Test getAliveNeighbors
    CPPUNIT_TEST(test_neighbors_1);
    CPPUNIT_TEST(test_neighbors_2);
    CPPUNIT_TEST(test_neighbors_3);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestLife.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestLife::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
