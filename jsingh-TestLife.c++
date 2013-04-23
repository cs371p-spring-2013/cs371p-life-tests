// ------------
// TestLife
// -----------


// add 3rd
// add printBoard 2 + 3
// add AbstractCell::equals
// add CownayCell::equals

#include <iostream>
#include <string>
#include <sstream>


#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TextTestRunner.h"


#define private public
#define protected public
#define class struct


#include "AbstractCell.h"
#include "ConwayCell.h"
#include "Cell.h"
#include "Life.h"

using namespace std;

struct TestLife : CppUnit::TestFixture {

    void test_AbstractCell_Constructor1(){
        
        AbstractCell* test = new ConwayCell(State::ALIVE);
        CPPUNIT_ASSERT(test->state == State::ALIVE);
    }

    void test_AbstractCell_Constructor2(){
        AbstractCell* test = new ConwayCell(State::DEAD);
        CPPUNIT_ASSERT(test->state == State::DEAD);
    }

    void test_AbstractCell_Constructor3(){
        AbstractCell* test = new FredkinCell(State::ALIVE);
        CPPUNIT_ASSERT(test->state == State::ALIVE);
    }

    void test_switchState1(){
        AbstractCell* test = new ConwayCell(State::ALIVE);
        test->switchState();
        CPPUNIT_ASSERT(test->state == State::DEAD);
    }

    void test_switchState2(){
        AbstractCell* test = new ConwayCell(State::DEAD);
        test->switchState();
        CPPUNIT_ASSERT(test->state == State::ALIVE);
    }

    void test_switchState3(){
        AbstractCell* test = new FredkinCell(State::ALIVE);
        test->switchState();
        CPPUNIT_ASSERT(test->state == State::DEAD);
    }

    void test_isMutationAllowed1(){
        AbstractCell* test = new FredkinCell();
        CPPUNIT_ASSERT(test->isMutationAllowed() == false);
    }

    void test_isMutationAllowed2(){
        ConwayCell test(State::ALIVE);
        CPPUNIT_ASSERT(test.isMutationAllowed() == false);
    }

    void test_isMutationAllowed3(){
        Cell test = new ConwayCell(State::ALIVE);
        CPPUNIT_ASSERT(test.isMutationAllowed()== true);
    }

    void test_isAlive1(){
        AbstractCell* test = new ConwayCell(State::ALIVE);
        CPPUNIT_ASSERT(test->isAlive() == true);
    }

    void test_isAlive2(){
        AbstractCell* test = new ConwayCell(State::DEAD);
        CPPUNIT_ASSERT(test->isAlive() == false);
    }

    void test_isAlive3(){
        AbstractCell* test = new FredkinCell(State::ALIVE);
        CPPUNIT_ASSERT(test->isAlive() == true);
    }

    void test_lessless1(){
        AbstractCell* test = new ConwayCell(State::ALIVE);
        ostringstream w;
        w << *test;
        CPPUNIT_ASSERT(w.str() == "*");
    }

    void test_lessless2(){
        AbstractCell* test = new ConwayCell(State::DEAD);
        ostringstream w;
        w << *test;
        CPPUNIT_ASSERT(w.str() == ".");
    }

    void test_lessless3(){
        AbstractCell* test = new FredkinCell(State::DEAD);
        ostringstream w;
        w << *test;
        CPPUNIT_ASSERT(w.str() == "-");
    }

    void test_mutate1(){
        AbstractCell* test = new FredkinCell(State::ALIVE);
        test->mutate();
        AbstractCell* test1 = new FredkinCell(State::ALIVE);
        CPPUNIT_ASSERT(*test == *test1);
    }

    void test_mutate2(){
        ConwayCell test(State::ALIVE);
        test.mutate();
        CPPUNIT_ASSERT(test == ConwayCell(State::ALIVE));
    }

    void test_mutate3(){
        Cell test = new FredkinCell(State::ALIVE);
        dynamic_cast<FredkinCell*>(test.get())->age = 2;
        test.mutate();
        Cell test1 = new ConwayCell(State::ALIVE);
        CPPUNIT_ASSERT(test == test1);
    }

    void test_equalequal1(){
        AbstractCell* test = new ConwayCell(State::DEAD);
        CPPUNIT_ASSERT(*test == *(new ConwayCell(State::DEAD)));
    }

    void test_equalequal2(){
        AbstractCell* test = new ConwayCell(State::DEAD);
        CPPUNIT_ASSERT(!(*test == *(new ConwayCell(State::ALIVE))));
    }

    void test_equalequal3(){
        AbstractCell* test = new FredkinCell(State::ALIVE);
        CPPUNIT_ASSERT((*test == *(new FredkinCell(State::ALIVE))));
    }

    void test_ConwayGo1(){
        AbstractCell* test = new ConwayCell(State::DEAD);
        CPPUNIT_ASSERT(test->go(2, 1) == 1);

        AbstractCell* test1 = new ConwayCell(State::DEAD);
        CPPUNIT_ASSERT(test1->go(2,2) == 0);
    }

    void test_ConwayGo2(){
        AbstractCell* test = new ConwayCell(State::ALIVE);
        CPPUNIT_ASSERT(test->go(2, 3) == -1);
        CPPUNIT_ASSERT(test->go(1,0) == -1);
        CPPUNIT_ASSERT(test->go(1,1) == 0);
        CPPUNIT_ASSERT(test->go(1,2) == 0);
    }

    void test_ConwayGo3(){
        AbstractCell* test = new ConwayCell(State::ALIVE);
        test->switchState();
        CPPUNIT_ASSERT(test->go(1,0) == 0);
    }

    void test_ConwayPrint1(){
        AbstractCell* test = new ConwayCell(State::DEAD);
        CPPUNIT_ASSERT(test->printCell() == '.');
    }

    void test_ConwayPrint2(){
        AbstractCell* test = new ConwayCell(State::ALIVE);
        CPPUNIT_ASSERT(test->printCell() == '*');
    }

    void test_ConwayPrint3(){
        AbstractCell* test = new ConwayCell(State::DEAD);
        test->switchState();
        CPPUNIT_ASSERT(test->printCell() == '*');
    }

    void test_Conway_clone1(){
        ConwayCell* test = new ConwayCell(State::ALIVE);
        ConwayCell* copy = test->clone();
        CPPUNIT_ASSERT(copy != test);
    }

    void test_Conway_clone2(){
        ConwayCell* test = new ConwayCell(State::DEAD);
        ConwayCell* copy = test->clone();
        CPPUNIT_ASSERT(test->state == copy->state);
    }

    void test_Conway_clone3(){
        AbstractCell* test = new ConwayCell(State::DEAD);
        AbstractCell* copy = test->clone();
        CPPUNIT_ASSERT(test->state == copy->state);
        CPPUNIT_ASSERT(test != copy);
    }

    void test_Fredkin_clone1(){
        FredkinCell* test = new FredkinCell(State::ALIVE);
        FredkinCell* copy = test->clone();
        CPPUNIT_ASSERT(copy != test);
    }

    void test_Fredkin_clone2(){
        FredkinCell* test = new FredkinCell(State::DEAD);
        FredkinCell* copy = test->clone();
        CPPUNIT_ASSERT(test->state == copy->state);
    }

    void test_Fredkin_clone3(){
        AbstractCell* test = new FredkinCell(State::DEAD);
        dynamic_cast<FredkinCell*>(test)->age = 4;
        AbstractCell* copy = test->clone();
        CPPUNIT_ASSERT(test->state == copy->state);
        CPPUNIT_ASSERT(dynamic_cast<FredkinCell*>(test)->age == dynamic_cast<FredkinCell*>(copy)->age);
        CPPUNIT_ASSERT(test != copy);
    }

    void test_Fredkinprint1(){
        FredkinCell test(State::ALIVE);
        test.age = 5;
        CPPUNIT_ASSERT(test.printCell() == '5');
    }

    void test_Fredkinprint2(){
        FredkinCell test(State::DEAD);
        CPPUNIT_ASSERT(test.printCell() == '-');
    }

    void test_Fredkinprint3(){
        FredkinCell test(State::ALIVE);
        test.age = 12;
        CPPUNIT_ASSERT(test.printCell() == '+');
    }

    void test_Fredkin_equal1(){
        AbstractCell* test = new FredkinCell(State::ALIVE);
        dynamic_cast<FredkinCell*>(test)->age = 4;
        AbstractCell* test1 = new FredkinCell(State::ALIVE);
        dynamic_cast<FredkinCell*>(test1)->age = 4;
        CPPUNIT_ASSERT(*test == *test1);
    }

    void test_Fredkin_equal2(){
        AbstractCell* test = new FredkinCell(State::ALIVE);
        AbstractCell* test1 = new FredkinCell(State::DEAD);

        CPPUNIT_ASSERT(!(*test == *test1));
    }
    
    void test_Fredkin_equal3(){
    
        AbstractCell* test = new FredkinCell(State::ALIVE);
        AbstractCell* test1 = new FredkinCell(State::ALIVE);

        CPPUNIT_ASSERT(*test == *test1);
    }

    void test_Fredkin_go1(){
        FredkinCell test(State::ALIVE);
        CPPUNIT_ASSERT(test.go(4, 0) == -1);
        CPPUNIT_ASSERT(test.go(3, 0) == 0);
    }

    void test_Fredkin_go2(){
        FredkinCell test(State::DEAD);
        CPPUNIT_ASSERT(test.go(3, 2) == 1);
        CPPUNIT_ASSERT(test.go(4, 3) == 0);
    }

    void test_Fredkin_go3(){
        FredkinCell test(State::ALIVE);
        test.go(3, 0);
        CPPUNIT_ASSERT(test.go(3, 2) == 3);
    }


    void test_CellMutation(){
        Cell test = new ConwayCell(State::ALIVE);
        CPPUNIT_ASSERT(test.isMutationAllowed() == true);

    }


    void test_Life1(){
        Life<ConwayCell> game(5, 6);
        CPPUNIT_ASSERT(game._height == 5);
        CPPUNIT_ASSERT(game._width == 6);
        CPPUNIT_ASSERT(game.generation == 0);
        CPPUNIT_ASSERT(game.population == 0);
    }

   
    void test_Life2(){
        Life<ConwayCell> game(7,9);
        CPPUNIT_ASSERT(game.board.size() == 7);
        CPPUNIT_ASSERT(game.board[0].size() == 9);
    }

    void test_Life3(){
        Life<Cell> game(7,9);
        CPPUNIT_ASSERT(game.board.size() == 7);
        CPPUNIT_ASSERT(game.board[0].size() == 9);
    }


    void test_LifeAdd1(){
        Life<ConwayCell> game(1,1);
        ConwayCell test(State::ALIVE);
        game.addCell(0,0, test);
        CPPUNIT_ASSERT(game.board[0][0] == test);
        CPPUNIT_ASSERT(game.population == 1);
    }

    void test_LifeAdd2(){
        Life<ConwayCell> game(2,2);
        ConwayCell test(State::ALIVE);
        ConwayCell test2(State::ALIVE);
        game.addCell(0,0, test);
        game.addCell(1,1, test2);
        CPPUNIT_ASSERT(game.board[0][0] == test);
        CPPUNIT_ASSERT(game.board[1][1] == test2);
        CPPUNIT_ASSERT(game.population == 2);
    }

    void test_LifeAdd3(){

        Life<FredkinCell> game(2,2);
        FredkinCell test(State::ALIVE);
        FredkinCell test2(State::ALIVE);
        game.addCell(0,0, test);
        game.addCell(1,1, test2);
        CPPUNIT_ASSERT(game.board[0][0] == test);
        CPPUNIT_ASSERT(game.board[1][1] == test2);
        CPPUNIT_ASSERT(game.population == 2);
    }

    void test_ortho1(){
        Life<ConwayCell> game(2,2);
        ConwayCell test(State::ALIVE);
        ConwayCell test2(State::ALIVE);
        game.addCell(0,0, test);
        game.addCell(1,1, test2);
        CPPUNIT_ASSERT(game.calculateAliveOrthoNeighbors(0,0) == 0);
    }

    void test_ortho2(){
        
        Life<ConwayCell> game(2,2);
        ConwayCell test(State::ALIVE);
        ConwayCell test2(State::ALIVE);
        game.addCell(0,0, test);
        game.addCell(1,1, test2);
        CPPUNIT_ASSERT(game.calculateAliveOrthoNeighbors(1,0) == 2);
    }

    void test_ortho3(){
        Life<FredkinCell> game(2,2);
        game.addCell(0,0, FredkinCell(State::ALIVE));
        game.addCell(0,1, FredkinCell(State::ALIVE));
        game.addCell(1,1, FredkinCell(State::ALIVE));
        game.addCell(1,0, FredkinCell(State::ALIVE));
        CPPUNIT_ASSERT(game.calculateAliveOrthoNeighbors(1,1) == 2);
    }


    void test_diag1(){

        Life<ConwayCell> game(2,2);
        ConwayCell test(State::ALIVE);
        ConwayCell test2(State::ALIVE);
        game.addCell(0,0, test);
        game.addCell(1,1, test2);
        CPPUNIT_ASSERT(game.calculateAliveDiagNeighbors(0,0) == 1);
    }

    void test_diag2(){
        
        Life<ConwayCell> game(2,2);
        ConwayCell test(State::ALIVE);
        ConwayCell test2(State::ALIVE);
        game.addCell(0,0, test);
        game.addCell(1,1, test2);
        CPPUNIT_ASSERT(game.calculateAliveDiagNeighbors(1,0) == 0);
    }


    void test_diag3(){
        Life<FredkinCell> game(2,2);
        game.addCell(0,0, FredkinCell(State::ALIVE));
        game.addCell(0,1, FredkinCell(State::ALIVE));
        game.addCell(1,1, FredkinCell(State::ALIVE));
        game.addCell(1,0, FredkinCell(State::ALIVE));
        CPPUNIT_ASSERT(game.calculateAliveDiagNeighbors(1,1) == 1);
    }

    void test_printBoard(){
        Life<ConwayCell> game(4, 4);
        ostringstream w;
        game.printBoard(w);
        CPPUNIT_ASSERT(w.str() == "Generation = 0, Population = 0.\n....\n....\n....\n....\n\n");
    }  


    CPPUNIT_TEST_SUITE(TestLife);

    CPPUNIT_TEST(test_AbstractCell_Constructor1);
    CPPUNIT_TEST(test_AbstractCell_Constructor2);
    CPPUNIT_TEST(test_AbstractCell_Constructor3);
    CPPUNIT_TEST(test_switchState1);
    CPPUNIT_TEST(test_switchState2);
    CPPUNIT_TEST(test_switchState3);
    CPPUNIT_TEST(test_isMutationAllowed1);
    CPPUNIT_TEST(test_isMutationAllowed2);
    CPPUNIT_TEST(test_isMutationAllowed3);
    CPPUNIT_TEST(test_isAlive1);
    CPPUNIT_TEST(test_isAlive2);
    CPPUNIT_TEST(test_isAlive3);
    CPPUNIT_TEST(test_lessless1);
    CPPUNIT_TEST(test_lessless2);
    CPPUNIT_TEST(test_lessless3);
    CPPUNIT_TEST(test_mutate1);
    CPPUNIT_TEST(test_mutate2);
    CPPUNIT_TEST(test_mutate3);
    CPPUNIT_TEST(test_equalequal1);
    CPPUNIT_TEST(test_equalequal2);
    CPPUNIT_TEST(test_equalequal3);
    CPPUNIT_TEST(test_ConwayGo1);
    CPPUNIT_TEST(test_ConwayGo2);
    CPPUNIT_TEST(test_ConwayGo3);
    CPPUNIT_TEST(test_ConwayPrint1);    
    CPPUNIT_TEST(test_ConwayPrint2);
    CPPUNIT_TEST(test_ConwayPrint3);
    CPPUNIT_TEST(test_Conway_clone1);
    CPPUNIT_TEST(test_Conway_clone2);
    CPPUNIT_TEST(test_Conway_clone3);
    CPPUNIT_TEST(test_Fredkin_equal1);
    CPPUNIT_TEST(test_Fredkin_equal2);
    CPPUNIT_TEST(test_Fredkin_equal3);
    CPPUNIT_TEST(test_Fredkin_clone1);
    CPPUNIT_TEST(test_Fredkin_clone2);
    CPPUNIT_TEST(test_Fredkin_clone3);
    CPPUNIT_TEST(test_Fredkin_go1);
    CPPUNIT_TEST(test_Fredkin_go2);
    CPPUNIT_TEST(test_Fredkin_go3);
    CPPUNIT_TEST(test_Fredkinprint1);
    CPPUNIT_TEST(test_Fredkinprint2);
    CPPUNIT_TEST(test_Fredkinprint3);
    CPPUNIT_TEST(test_CellMutation);
    CPPUNIT_TEST(test_Life1);
    CPPUNIT_TEST(test_Life2);
    CPPUNIT_TEST(test_Life3);
    CPPUNIT_TEST(test_LifeAdd1);
    CPPUNIT_TEST(test_LifeAdd2);
    CPPUNIT_TEST(test_LifeAdd3);
    CPPUNIT_TEST(test_ortho1);
    CPPUNIT_TEST(test_ortho2);
    CPPUNIT_TEST(test_ortho3);
    CPPUNIT_TEST(test_diag1);
    CPPUNIT_TEST(test_diag2);
    CPPUNIT_TEST(test_diag3);
    CPPUNIT_TEST(test_printBoard);
    CPPUNIT_TEST_SUITE_END();
    

};

int main(){
    
    ios_base::sync_with_stdio(false);
    cout << "TestLife.c++" << endl;

    CppUnit::TextTestRunner tr;

    tr.addTest(TestLife::suite());
    tr.run();
    cout << "Done." << endl;

    return 0;
}



