
// --------
// includes
// --------

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TextTestRunner.h"

#define protected public
#define private public

#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Life.h"
#include "Cell.h"

// --------
// TestLife
// --------

struct TestLife : CppUnit::TestFixture {


    // -----------------------
    // ConwayCell::Constructor
    // -----------------------
    void test_conway_constructor_1(){
        ConwayCell c('.');
        CPPUNIT_ASSERT(c.areYouAlive() == false);
    }

    void test_conway_constructor_2(){
        try{
            ConwayCell c('t');
            CPPUNIT_ASSERT(false);
        } catch(std::invalid_argument& e){
            CPPUNIT_ASSERT(strcmp(e.what(), "ConwayCell(char): t") == 0);
        }
    }

    void test_conway_constructor_3(){
        ConwayCell c('*');
        CPPUNIT_ASSERT(c.areYouAlive() == true);
    }

    void test_conway_constructor_4() {
        ConwayCell c;
        CPPUNIT_ASSERT(c.areYouAlive() == false);
        CPPUNIT_ASSERT(c.symbol == '.');
    }

    // ------------------------
    // FredkinCell::Constructor
    // ------------------------
    void test_fredkin_constructor_1(){
        FredkinCell c('-');
        CPPUNIT_ASSERT(c.areYouAlive() == false);
        CPPUNIT_ASSERT(c.age == 0);
    }

    void test_fredkin_constructor_2(){
        try{
            FredkinCell c('t');
            CPPUNIT_ASSERT(false);
        } catch(std::invalid_argument& e){
            CPPUNIT_ASSERT(strcmp(e.what(), "FredkinCell(char): t") == 0);
        }
    }

    void test_fredkin_constructor_3(){
        FredkinCell c('0');
        CPPUNIT_ASSERT(c.areYouAlive() == true);
        CPPUNIT_ASSERT(c.age == 0);
    }

    void test_fredkin_constructor_4() {
        FredkinCell c;
        CPPUNIT_ASSERT(c.areYouAlive() == false);
        CPPUNIT_ASSERT(c.symbol == '-');
    }

    // -----------------
    // Cell::constructor
    // -----------------
    void test_cell_constructor_1(){
        Cell c;
        CPPUNIT_ASSERT(c.areYouAlive() == false);
        CPPUNIT_ASSERT(c.get()->symbol == '.');
    }

    void test_cell_constructor_2(){
        Cell c('*');
        CPPUNIT_ASSERT(c.areYouAlive() == true);
        CPPUNIT_ASSERT(c.get()->symbol == '*');
    }

    void test_cell_constructor_3(){
        Cell c('0');
        CPPUNIT_ASSERT(c.areYouAlive() == true);
        CPPUNIT_ASSERT(c.get()->symbol == '0');
    }

    // -----------------------
    // ConwayCell::validSymbol
    // -----------------------
    void test_conway_validSymbol_1(){
        ConwayCell c;
        CPPUNIT_ASSERT(c.validSymbol('.') == true);
    }

    void test_conway_validSymbol_2(){
        ConwayCell c;
        CPPUNIT_ASSERT(c.validSymbol('*') == true);
    }

    void test_conway_validSymbol_3(){
        ConwayCell c;
        CPPUNIT_ASSERT(c.validSymbol('-') == false);
    }

    // ------------------------
    // FredkinCell::validSymbol
    // ------------------------
    void test_fredkin_validSymbol_1(){
        FredkinCell c;
        CPPUNIT_ASSERT(c.validSymbol('-') == true);
    }

    void test_fredkin_validSymbol_2(){
        FredkinCell c;
        CPPUNIT_ASSERT(c.validSymbol('0') == true);
    }

    void test_fredkin_validSymbol_3(){
        FredkinCell c;
        CPPUNIT_ASSERT(c.validSymbol('.') == false);
    }

    // ------------------
    // ConwayCell::update
    // ------------------
    void test_conway_update_1(){
        ConwayCell c;
        c.update(0, 3);
        CPPUNIT_ASSERT(c.symbol == '*');
        c.update(1, 0);
        CPPUNIT_ASSERT(c.symbol == '.');
    }

    void test_conway_update_2(){
        ConwayCell c;
        c.update(1, 2);
        CPPUNIT_ASSERT(c.symbol == '*');
        c.update(2, 3);
        CPPUNIT_ASSERT(c.symbol == '.');
    }

    void test_conway_update_3(){
        ConwayCell c('*');
        c.update(0, 3);
        CPPUNIT_ASSERT(c.symbol == '*');
        c.update(1, 0);
        CPPUNIT_ASSERT(c.symbol == '.');
        c.update(1, 0);
        CPPUNIT_ASSERT(c.symbol == '.');
    }

    // -------------------
    // FredkinCell::update
    // -------------------
    void test_fredkin_update_1(){
        FredkinCell c;
        CPPUNIT_ASSERT(c.age == 0);
        c.update(0, 3);
        CPPUNIT_ASSERT(c.symbol == '-');
        c.update(1, 0);
        CPPUNIT_ASSERT(c.symbol == '0');
        CPPUNIT_ASSERT(c.age == 0);
    }

    void test_fredkin_update_2(){
        FredkinCell c;
        c.update(1, 2);
        CPPUNIT_ASSERT(c.symbol == '0');
        c.update(2, 3);
        CPPUNIT_ASSERT(c.symbol == '-');
        CPPUNIT_ASSERT(c.age == 0);
    }

    void test_fredkin_update_3(){
        FredkinCell c('0');
        c.update(1, 3);
        CPPUNIT_ASSERT(c.symbol == '1');
        c.update(0, 0);
        CPPUNIT_ASSERT(c.symbol == '-');
        c.update(1, 0);
        CPPUNIT_ASSERT(c.symbol == '1');
        CPPUNIT_ASSERT(c.age == 1);
    }

    // ------------
    // Cell::mutate
    // ------------
    void test_cell_mutate_1(){
        Cell c('0');
        c.mutate();
        CPPUNIT_ASSERT(c.get()->symbol == '*');
    }

    void test_cell_mutate_2(){
        Cell c('*');
        c.mutate();
        CPPUNIT_ASSERT(c.get()->symbol == '*');
    }

    void test_cell_mutate_3(){
        Cell c('-');
        c.mutate();
        CPPUNIT_ASSERT(c.get()->symbol == '*');
    }

    // ------------
    // Cell::update
    // ------------
    void test_cell_upadate_1(){
        Cell c('.');
        c.update(1, 2);
        CPPUNIT_ASSERT(c.get()->symbol == '*');
    }

    void test_cell_upadate_2(){
        Cell c('-');
        c.update(1, 2);
        CPPUNIT_ASSERT(c.get()->symbol == '0');
    }

    void test_cell_upadate_3(){
        Cell c('0');
        c.update(1, 2);
        c.update(1, 2);
        CPPUNIT_ASSERT(c.get()->symbol == '*');
    }

    // -----------------
    // ConwayCell::clone
    // -----------------
    void test_conway_clone_1(){
        ConwayCell* c1 = new ConwayCell('*');
        ConwayCell* c2 = c1->clone();
        CPPUNIT_ASSERT(c1->areYouAlive() == true);
        CPPUNIT_ASSERT(c2->areYouAlive() == true);
        delete c1;
        delete c2;
    }

    void test_conway_clone_2(){
        ConwayCell* c1 = new ConwayCell;
        ConwayCell* c2 = c1->clone();
        CPPUNIT_ASSERT(c1->areYouAlive() == false);
        CPPUNIT_ASSERT(c2->areYouAlive() == false);
        delete c1;
        delete c2;
    }

    void test_conway_clone_3(){
        ConwayCell* c1 = new ConwayCell('*');
        ConwayCell* c2 = c1->clone();
        c2->symbol = '.';
        CPPUNIT_ASSERT(c1->areYouAlive() == true);
        CPPUNIT_ASSERT(c2->areYouAlive() == false);
        delete c1;
        delete c2;
    }

    // ------------------
    // FredkinCell::clone
    // ------------------
    void test_fredkin_clone_1(){
        FredkinCell* c1 = new FredkinCell('0');
        FredkinCell* c2 = c1->clone();
        CPPUNIT_ASSERT(c1->areYouAlive() == true);
        CPPUNIT_ASSERT(c2->areYouAlive() == true);
        delete c1;
        delete c2;
    }

    void test_fredkin_clone_2(){
        FredkinCell* c1 = new FredkinCell;
        FredkinCell* c2 = c1->clone();
        CPPUNIT_ASSERT(c1->areYouAlive() == false);
        CPPUNIT_ASSERT(c2->areYouAlive() == false);
        delete c1;
        delete c2;
    }

    void test_fredkin_clone_3(){
        FredkinCell* c1 = new FredkinCell('0');
        FredkinCell* c2 = c1->clone();
        c2->update(1, 0);
        CPPUNIT_ASSERT(c1->age == 0);
        CPPUNIT_ASSERT(c2->age == 1);
        delete c1;
        delete c2;
    }

    // -----------------
    // Life::constructor
    // -----------------
    
    // helper funtion
    template<class T>
    std::vector<std::vector< T > > loadBoard(const int r, const int c, std::istream& in) {
        std::vector<std::vector< T > > board;
        for(int i = 0; i < r; ++i){
            std::vector<T> row;
            for(int j = 0; j < c; ++j)
                row.push_back(in.get());
            in.get(); // get rid of newline
            board.push_back(row);
        }       
        return board;
    }

    // helper function
    std::vector<std::vector< Cell > > loadCellBoard(const int r, const int c, std::istream& in) {
        std::vector<std::vector< Cell > > board;
        char ch;
        for(int i = 0; i < r; ++i){
            std::vector<Cell> row;
            for(int j = 0; j < c; ++j){
                ch = in.get();
                if(ch == '.' || ch == '*')
                    row.push_back(new ConwayCell(ch));
                else
                    row.push_back(new FredkinCell(ch));
            }
            in.get(); // get rid of newline
            board.push_back(row);
        }  
        return board;
    }



    void test_life_constructor_1(){
        Life<ConwayCell> l(0, 0, std::vector<std::vector< ConwayCell > >());
        CPPUNIT_ASSERT(l.generation == 0);
    }

    void test_life_constructor_2(){
        std::istringstream r("...\n.*.\n...\n");
        Life<ConwayCell> l(3, 3, loadBoard<ConwayCell>(3, 3, r));
        CPPUNIT_ASSERT(l.board[0][1].symbol == '.');
        CPPUNIT_ASSERT(l.board[0][1].areYouAlive() == false);
        CPPUNIT_ASSERT(l.board[1][1].symbol == '*');
        CPPUNIT_ASSERT(l.board[1][1].areYouAlive() == true);
        CPPUNIT_ASSERT(l.board[2][1].symbol == '.');
        CPPUNIT_ASSERT(l.board[2][1].areYouAlive() == false);
    }

    void test_life_constructor_3(){
        std::istringstream r("---\n-0-\n---\n000\n0-0");
        Life<FredkinCell> l(5, 3, loadBoard<FredkinCell>(5, 3, r));
        CPPUNIT_ASSERT(l.board[0][1].symbol == '-');
        CPPUNIT_ASSERT(l.board[0][1].areYouAlive() == false);
        CPPUNIT_ASSERT(l.board[4][2].symbol == '0');
        CPPUNIT_ASSERT(l.board[4][2].areYouAlive() == true);
        CPPUNIT_ASSERT(l.board[4][2].age == 0);
        CPPUNIT_ASSERT(l.board[4][1].symbol == '-');
        CPPUNIT_ASSERT(l.board[4][1].areYouAlive() == false);
    }

    void test_life_constructor_4(){
        std::istringstream r("-.-\n-0-\n-.-\n0*0\n0-0");
        Life<Cell> l(5, 3, loadCellBoard(5, 3, r));
        CPPUNIT_ASSERT(l.board[0][1].get()->symbol == '.');
        CPPUNIT_ASSERT(l.board[0][1].get()->areYouAlive() == false);
        CPPUNIT_ASSERT(l.board[4][2].get()->symbol == '0');
        CPPUNIT_ASSERT(l.board[4][2].get()->areYouAlive() == true);
        CPPUNIT_ASSERT(l.board[4][1].get()->symbol == '-');
        CPPUNIT_ASSERT(l.board[4][1].get()->areYouAlive() == false);
    }


    // --------------
    // Life::inBounds
    // --------------
    void test_life_inBounds_1(){
        int r, c;
        std::ifstream in;
        in.open("RunLifeConway.in");
        in >> r;
        in >> c;
        in.get();
        Life<ConwayCell> l(r, c, loadBoard<ConwayCell>(r, c, in));
        CPPUNIT_ASSERT(l.aliveAt(-1, 43) == false);
        CPPUNIT_ASSERT(l.aliveAt(43, -1) == false);
        CPPUNIT_ASSERT(l.aliveAt(43, 43) == false);
        CPPUNIT_ASSERT(l.aliveAt(38, 34) == true);
    }

    void test_life_inBounds_2(){
        int r, c;
        std::ifstream in;
        in.open("RunLifeFredkin.in");
        in >> r;
        in >> c;
        in.get();
        Life<FredkinCell> l(r, c, loadBoard<FredkinCell>(r, c, in));
        CPPUNIT_ASSERT(l.aliveAt(-1, 8) == false);
        CPPUNIT_ASSERT(l.aliveAt(8, -1) == false);
        CPPUNIT_ASSERT(l.aliveAt(2, 2) == false);
        CPPUNIT_ASSERT(l.aliveAt(9, 9) == true);
    }

    void test_life_inBounds_3(){
        int r, c;
        std::ifstream in;
        in.open("RunLifeCell.in");
        in >> r;
        in >> c;
        in.get();
        Life<Cell> l(r, c, loadCellBoard(r, c, in));
        CPPUNIT_ASSERT(l.aliveAt(-1, 8) == false);
        CPPUNIT_ASSERT(l.aliveAt(8, -1) == false);
        CPPUNIT_ASSERT(l.aliveAt(2, 2) == false);
        CPPUNIT_ASSERT(l.aliveAt(9, 9) == true);
    }

    // ----------------------
    // Life::getSideNeighbors
    // ----------------------
    void test_life_getSideNeighbors_1(){
        std::istringstream in(".......\n..***..\n..***..\n..***..\n.......\n");
        Life<ConwayCell> l(5, 7, loadBoard<ConwayCell>(5, 7, in));
        CPPUNIT_ASSERT(l.getSideNeighbors(0, 0) == 0);
        CPPUNIT_ASSERT(l.getSideNeighbors(2, 3) == 4);
        CPPUNIT_ASSERT(l.getSideNeighbors(1, 2) == 2);
    }

    void test_life_getSideNeighbors_2(){
        std::istringstream in("-------\n--000--\n--000--\n--000--\n-------\n");
        Life<FredkinCell> l(5, 7, loadBoard<FredkinCell>(5, 7, in));
        CPPUNIT_ASSERT(l.getSideNeighbors(0, 0) == 0);
        CPPUNIT_ASSERT(l.getSideNeighbors(2, 3) == 4);
        CPPUNIT_ASSERT(l.getSideNeighbors(1, 2) == 2);
    }

    void test_life_getSideNeighbors_3(){
        std::istringstream in(".......\n--000--\n..***..\n--000--\n.......\n");
        Life<Cell> l(5, 7, loadCellBoard(5, 7, in));
        CPPUNIT_ASSERT(l.getSideNeighbors(0, 0) == 0);
        CPPUNIT_ASSERT(l.getSideNeighbors(2, 3) == 4);
        CPPUNIT_ASSERT(l.getSideNeighbors(1, 2) == 2);
    }

    // ----------------------
    // Life::getDiagNeighbors
    // ----------------------
    void test_life_getDiagNeighbors_1(){
        std::istringstream in(".......\n..***..\n..***..\n..***..\n.......\n");
        Life<ConwayCell> l(5, 7, loadBoard<ConwayCell>(5, 7, in));
        CPPUNIT_ASSERT(l.getDiagNeighbors(0, 0) == 0);
        CPPUNIT_ASSERT(l.getDiagNeighbors(2, 3) == 4);
        CPPUNIT_ASSERT(l.getDiagNeighbors(2, 2) == 2);
    }

    void test_life_getDiagNeighbors_2(){
        std::istringstream in("-------\n--000--\n--000--\n--000--\n-------\n");
        Life<FredkinCell> l(5, 7, loadBoard<FredkinCell>(5, 7, in));
        CPPUNIT_ASSERT(l.getDiagNeighbors(0, 0) == 0);
        CPPUNIT_ASSERT(l.getDiagNeighbors(2, 3) == 4);
        CPPUNIT_ASSERT(l.getDiagNeighbors(2, 2) == 2);
    }

    void test_life_getDiagNeighbors_3(){
        std::istringstream in(".......\n--000--\n..***..\n--000--\n.......\n");
        Life<Cell> l(5, 7, loadCellBoard(5, 7, in));
        CPPUNIT_ASSERT(l.getDiagNeighbors(0, 0) == 0);
        CPPUNIT_ASSERT(l.getDiagNeighbors(2, 3) == 4);
        CPPUNIT_ASSERT(l.getDiagNeighbors(2, 2) == 2);
    }

    // --------------
    // Life::runRound
    // --------------
    void test_life_runRound_1(){
        std::istringstream in(".......\n..***..\n..***..\n..***..\n.......\n");
        Life<ConwayCell> l(5, 7, loadBoard<ConwayCell>(5, 7, in));
        CPPUNIT_ASSERT(l.population == 9);
        l.runRound();
        CPPUNIT_ASSERT(l.population == 8);
    }

    void test_life_runRound_2(){
        std::istringstream in("-------\n--000--\n--000--\n--000--\n-------\n");
        Life<FredkinCell> l(5, 7, loadBoard<FredkinCell>(5 ,7, in));
        CPPUNIT_ASSERT(l.population == 9);
        l.runRound();
        CPPUNIT_ASSERT(l.population == 16);
    }

    void test_life_runRound_3(){
        std::istringstream in(".......\n--000--\n..***..\n--000--\n.......\n");
        Life<Cell> l(5, 7, loadCellBoard(5, 7, in));
        CPPUNIT_ASSERT(l.population == 9);
        l.runRound();
        CPPUNIT_ASSERT(l.population == 10);
    }



    // ----------------
    // Life::printBoard
    // ----------------
    void test_life_printBoard_1(){
        std::ostringstream w1, w2;
        std::istringstream in(".......\n..***..\n..***..\n..***..\n.......\n");
        Life<ConwayCell> l(5, 7, loadBoard<ConwayCell>(5, 7, in));
        l.printBoard(w1);
        CPPUNIT_ASSERT(w1.str() == "Generation = 0, Population = 9.\n.......\n..***..\n"
                "..***..\n..***..\n.......\n\n");
        l.runRound();
        l.printBoard(w2);
        CPPUNIT_ASSERT(w2.str() == "Generation = 1, Population = 8.\n...*...\n..*.*..\n"
                ".*...*.\n..*.*..\n...*...\n\n");
    }

    void test_life_printBoard_2(){
        std::ostringstream w1, w2;
        std::istringstream in("-------\n--000--\n--000--\n--000--\n-------\n");
        Life<FredkinCell> l(5, 7, loadBoard<FredkinCell>(5, 7, in));
        l.printBoard(w1);
        CPPUNIT_ASSERT(w1.str() == "Generation = 0, Population = 9.\n-------\n--000--"
                    "\n--000--\n--000--\n-------\n\n");
        l.runRound();
        l.printBoard(w2);
        CPPUNIT_ASSERT(w2.str() == "Generation = 1, Population = 16.\n--000--\n-0-1-0-"
                    "\n-01-10-\n-0-1-0-\n--000--\n\n");
    }

    void test_life_printBoard_3(){
        std::ostringstream w1, w2;
        std::istringstream in(".......\n--000--\n..***..\n--000--\n.......\n");
        Life<Cell> l(5, 7, loadCellBoard(5, 7, in));
        l.printBoard(w1);
        CPPUNIT_ASSERT(w1.str() == "Generation = 0, Population = 9.\n.......\n--000--"
                    "\n..***..\n--000--\n.......\n\n");
        l.runRound();
        l.printBoard(w2);
        CPPUNIT_ASSERT(w2.str() == "Generation = 1, Population = 10.\n...*...\n-0-1-0-"
                    "\n.*...*.\n-0-1-0-\n...*...\n\n");
    }


    // ----------
    // Tests Done
    // ----------


    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST(test_conway_constructor_1);
    CPPUNIT_TEST(test_conway_constructor_2);
    CPPUNIT_TEST(test_conway_constructor_3);
    CPPUNIT_TEST(test_conway_constructor_4);
    CPPUNIT_TEST(test_fredkin_constructor_1);
    CPPUNIT_TEST(test_fredkin_constructor_2);
    CPPUNIT_TEST(test_fredkin_constructor_3);
    CPPUNIT_TEST(test_fredkin_constructor_4);
    CPPUNIT_TEST(test_cell_constructor_1);
    CPPUNIT_TEST(test_cell_constructor_2);
    CPPUNIT_TEST(test_cell_constructor_3);
    CPPUNIT_TEST(test_conway_validSymbol_1);
    CPPUNIT_TEST(test_conway_validSymbol_2);
    CPPUNIT_TEST(test_conway_validSymbol_3);
    CPPUNIT_TEST(test_fredkin_validSymbol_1);
    CPPUNIT_TEST(test_fredkin_validSymbol_2);
    CPPUNIT_TEST(test_fredkin_validSymbol_3);
    CPPUNIT_TEST(test_conway_update_1);
    CPPUNIT_TEST(test_conway_update_2);
    CPPUNIT_TEST(test_conway_update_3);
    CPPUNIT_TEST(test_fredkin_update_1);
    CPPUNIT_TEST(test_fredkin_update_2);
    CPPUNIT_TEST(test_fredkin_update_3);
    CPPUNIT_TEST(test_cell_mutate_1);
    CPPUNIT_TEST(test_cell_mutate_2);
    CPPUNIT_TEST(test_cell_mutate_3);
    CPPUNIT_TEST(test_cell_upadate_1);
    CPPUNIT_TEST(test_cell_upadate_2);
    CPPUNIT_TEST(test_cell_upadate_3);
    CPPUNIT_TEST(test_conway_clone_1);
    CPPUNIT_TEST(test_conway_clone_2);
    CPPUNIT_TEST(test_conway_clone_3);
    CPPUNIT_TEST(test_fredkin_clone_1);
    CPPUNIT_TEST(test_fredkin_clone_2);
    CPPUNIT_TEST(test_fredkin_clone_3);
    CPPUNIT_TEST(test_life_constructor_1);
    CPPUNIT_TEST(test_life_constructor_2);
    CPPUNIT_TEST(test_life_constructor_3);
    CPPUNIT_TEST(test_life_constructor_4);
    CPPUNIT_TEST(test_life_inBounds_1);
    CPPUNIT_TEST(test_life_inBounds_2);
    CPPUNIT_TEST(test_life_inBounds_3);
    CPPUNIT_TEST(test_life_getSideNeighbors_1);
    CPPUNIT_TEST(test_life_getSideNeighbors_2);
    CPPUNIT_TEST(test_life_getSideNeighbors_3);
    CPPUNIT_TEST(test_life_getDiagNeighbors_1);
    CPPUNIT_TEST(test_life_getDiagNeighbors_2);
    CPPUNIT_TEST(test_life_getDiagNeighbors_3);
    CPPUNIT_TEST(test_life_runRound_1);
    CPPUNIT_TEST(test_life_runRound_2);
    CPPUNIT_TEST(test_life_runRound_3);
    CPPUNIT_TEST(test_life_printBoard_1);
    CPPUNIT_TEST(test_life_printBoard_2);
    CPPUNIT_TEST(test_life_printBoard_3);
    CPPUNIT_TEST_SUITE_END();

};

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout << "TestLife.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestLife::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;
}
