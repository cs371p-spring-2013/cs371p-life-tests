// -----------------------------
// TestLife.c++
// Marcella Nguyen & Shan Gupta
// -----------------------------

// ---------
// includes
// ---------
#define private public
#define protected public

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#include "Life.h"

using namespace std;

struct TestLife : CppUnit::TestFixture {
    // Conway
    // Constructor
    void test_ConwayCell1() {
        ConwayCell c('*');
        assert(c._rep == '*');
        assert(c._state == true);
        assert(c._checkDiagonal == true);}

    void test_ConwayCell2() {
        ConwayCell c('.');
        assert(c._rep == '.');
        assert(c._state == false);
        assert(c._checkDiagonal == true);}

    void test_ConwayCell3() {
        ConwayCell c('*');
        ConwayCell d(c);
        assert(d._rep == c._rep);
        assert(d._state == c._state);
        assert(d._checkDiagonal == c._checkDiagonal);}

    // checkState
    void test_conwayCheckState1() {
        ConwayCell c('*');
        pair<int, bool> state = c.checkState();

        assert(state.first == 1);
        assert(state.second == c._checkDiagonal);}

    void test_conwayCheckState2() {
        ConwayCell c('.');
        pair<int, bool> state = c.checkState();

        assert(state.first == 0);
        assert(state.second == c._checkDiagonal);}

    void test_conwayCheckState3() {
        ConwayCell c('.');
        ConwayCell d('*');
        pair<int, bool> state1 = c.checkState();
        pair<int, bool> state2 = d.checkState();

        assert(state1.first != state2.first);
        assert(state1.second == state2.second);}

    // evolve
    void test_conwayEvolve1() {
        ConwayCell c('*');

        pair<bool, bool> e = c.evolve(0);
        assert(e.first == false);
        assert(e.second == false);}

    void test_conwayEvolve2() {
        ConwayCell c('.');

        pair<bool, bool> e = c.evolve(3);
        assert(e.first == true);
        assert(e.second == false);}

    void test_conwayEvolve3() {
        ConwayCell c('*');

        pair<bool, bool> e = c.evolve(2);
        assert(e.first == true);
        assert(e.second == false);

        e = c.evolve(1);
        assert(e.first == false);
        assert(e.second == false);}


    // Fredkin
    // Constructor
    void test_FredkinCell1() {
        FredkinCell c('0');
        assert(c._rep == '0');
        assert(c._state == true);
        assert(c._checkDiagonal == false);
        assert(c._age == 0);}

    void test_FredkinCell2() {
        FredkinCell c('-');
        assert(c._rep == '-');
        assert(c._state == false);
        assert(c._checkDiagonal == false);
        assert(c._age == 0);}

    void test_FredkinCell3() {
        FredkinCell c('0');
        FredkinCell d(c);
        assert(d._rep == c._rep);
        assert(d._state == c._state);
        assert(d._checkDiagonal == c._checkDiagonal);
        assert(c._age == d._age);}

    // checkState
    void test_fredkinCheckState1() {
        FredkinCell c('0');
        pair<int, bool> state = c.checkState();

        assert(state.first == 1);
        assert(state.second == c._checkDiagonal);}

    void test_fredkinCheckState2() {
        FredkinCell c('-');
        pair<int, bool> state = c.checkState();

        assert(state.first == 0);
        assert(state.second == c._checkDiagonal);}

    void test_fredkinCheckState3() {
        FredkinCell c('-');
        FredkinCell d('0');
        pair<int, bool> state1 = c.checkState();
        pair<int, bool> state2 = d.checkState();

        assert(state1.first != state2.first);
        assert(state1.second == state2.second);}

    // evolve
    void test_fredkinEvolve1() {
        FredkinCell c('0');

        pair<bool, bool> e = c.evolve(0);
        assert(e.first == false);
        assert(e.second == false);
        assert(c._age == 0);

        e = c.evolve(1);
        assert(e.first == true);
        assert(e.second == false);
        assert(c._age == 0);

        e = c.evolve(4);
        assert(e.first == false);
        assert(e.second == false);
        assert(c._age == 0);}

    void test_fredkinEvolve2() {
        FredkinCell c('-');

        pair<bool, bool> e = c.evolve(1);
        assert(e.first == true);
        assert(e.second == false);
        assert(c._age == 0);}

    void test_fredkinEvolve3() {
        FredkinCell c('0');

        pair<bool, bool> e = c.evolve(1);
        assert(e.first == true);
        assert(e.second == false);
        assert(c._age == 1);

        e = c.evolve(3);
        assert(e.first == true);
        assert(e.second == true);
        assert(c._age == 2);}

    // Cell
    // Constructor
    void test_Cell1() {
        Cell c(new FredkinCell('0'));
        assert(c.get()->_rep == '0');
        assert(c.get()->_state == true);
        assert(c.get()->_checkDiagonal == false);
        assert(((FredkinCell*)c.get())->_age == 0);}

    void test_Cell2() {
        Cell c(new FredkinCell('-'));
        assert(c.get()->_rep == '-');
        assert(c.get()->_state == false);
        assert(c.get()->_checkDiagonal == false);
        assert(((FredkinCell*)c.get())->_age == 0);}

    void test_Cell3() {
        Cell c(new FredkinCell('0'));
        Cell d(c);
        assert(c.get()->_rep == d.get()->_rep);
        assert(c.get()->_state == d.get()->_state);
        assert(c.get()->_checkDiagonal == d.get()->_checkDiagonal);
        assert(((FredkinCell*)c.get())->_age == ((FredkinCell*)d.get())->_age);}

    // checkState
    void test_cellCheckState1() {
        Cell c(new FredkinCell('0'));
        pair<int, bool> state = c.checkState();

        assert(state.first == 1);
        assert(state.second == c.get()->_checkDiagonal);}

    void test_cellCheckState2() {
        Cell c(new FredkinCell('-'));
        pair<int, bool> state = c.checkState();

        assert(state.first == 0);
        assert(state.second == c.get()->_checkDiagonal);}

    void test_cellCheckState3() {
        Cell c(new FredkinCell('-'));
        Cell d(new FredkinCell('0'));
        pair<int, bool> state1 = c.checkState();
        pair<int, bool> state2 = d.checkState();

        assert(state1.first != state2.first);
        assert(state1.second == state2.second);}

    // evolve
    void test_cellEvolve1() {
        Cell c(new FredkinCell('0'));

        pair<bool, bool> e = c.evolve(0);
        assert(e.first == false);
        assert(e.second == false);
        assert(((FredkinCell*)c.get())->_age == 0);

        e = c.evolve(1);
        assert(e.first == true);
        assert(e.second == false);
        assert(((FredkinCell*)c.get())->_age == 0);

        e = c.evolve(4);
        assert(e.first == false);
        assert(e.second == false);
        assert(((FredkinCell*)c.get())->_age == 0);}

    void test_cellEvolve2() {
        Cell c(new FredkinCell('-'));

        pair<bool, bool> e = c.evolve(1);
        assert(e.first == true);
        assert(e.second == false);
        assert(((FredkinCell*)c.get())->_age == 0);}

    void test_cellEvolve3() {
        Cell c(new FredkinCell('0'));

        pair<bool, bool> e = c.evolve(1);
        assert(e.first == true);
        assert(e.second == false);
        assert(((FredkinCell*)c.get())->_age == 1);}

    // mutate
    void test_cellMutate1() {
        Cell c(new FredkinCell('0'));

        pair<bool, bool> e = c.evolve(1);
        assert(e.first == true);
        assert(e.second == false);
        assert(((FredkinCell*)c.get())->_age == 1);

        e = c.evolve(4);
        assert(e.first == false);
        assert(e.second == false);
        assert(((FredkinCell*)c.get())->_age == 1);}

    void test_cellMutate2() {
        Cell c(new FredkinCell('-'));
        c.mutate();

        assert(c.get()->_state == true);
        assert(c.get()->_rep == '*');
        assert(c.get()->_checkDiagonal == true);}

    void test_cellMutate3() {
        Cell c(new FredkinCell('0'));

        pair<bool, bool> e = c.evolve(1);
        assert(e.first == true);
        assert(e.second == false);
        assert(((FredkinCell*)c.get())->_age == 1);

        e = c.evolve(3);
        assert(e.first == true);
        assert(e.second == true);
        assert(c.get()->_state == true);
        assert(c.get()->_rep == '*');
        assert(c.get()->_checkDiagonal == true);}

    // Life
    // updateNeighbors
    void test_updateNeighbors1() {
        string conwayInput = "5\n5\n";
        conwayInput += "..*..\n";
        conwayInput += ".***.\n";
        conwayInput += "*****\n";
        conwayInput += ".***.\n";
        conwayInput += "..*..\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<ConwayCell> > input;

        istringstream r (conwayInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<ConwayCell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '*')
                        ++p;
                    rows.push_back(z);}
                input.push_back(rows);
                ++l;}

        Life<ConwayCell> cc(input, p);
        cc.updateNeighbors();
        assert(cc.Neighbors[2][2] == 8);
        assert(cc.Neighbors[0][0] == 1);
        assert(cc.Neighbors[4][4] == 1);
        assert(cc.Neighbors[2][4] == 3);}

    void test_updateNeighbors2() {
        string FredkinInput = "5\n5\n";
        FredkinInput += "--0--\n";
        FredkinInput += "-000-\n";
        FredkinInput += "00000\n";
        FredkinInput += "-000-\n";
        FredkinInput += "--0--\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<FredkinCell> > input;

        istringstream r (FredkinInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<FredkinCell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '0')
                        ++p;
                    rows.push_back(z);}
                input.push_back(rows);
                ++l;}

        Life<FredkinCell> cc(input, p);
        cc.updateNeighbors();
        assert(cc.Neighbors[2][2] == 4);
        assert(cc.Neighbors[0][0] == 0);
        assert(cc.Neighbors[4][4] == 0);
        assert(cc.Neighbors[2][4] == 1);}

    void test_updateNeighbors3() {
        string CellInput = "5\n5\n";
        CellInput += "--0--\n";
        CellInput += "-000-\n";
        CellInput += "00000\n";
        CellInput += "-000-\n";
        CellInput += "--0--\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<Cell> > input;

        istringstream r (CellInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<Cell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '0')
                        ++p;
                    rows.push_back(new FredkinCell(z));}
                input.push_back(rows);
                ++l;}

        Life<Cell> cc(input, p);
        cc.updateNeighbors();
        assert(cc.Neighbors[2][2] == 4);
        assert(cc.Neighbors[0][0] == 0);
        assert(cc.Neighbors[4][4] == 0);
        assert(cc.Neighbors[2][4] == 1);}

    // updateLife
    void test_updateLife1() {
    	string conwayInput = "5\n5\n";
        conwayInput += "..*..\n";
        conwayInput += ".***.\n";
        conwayInput += "*****\n";
        conwayInput += ".***.\n";
        conwayInput += "..*..\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<ConwayCell> > input;

        istringstream r (conwayInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<ConwayCell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '*')
                        ++p;
                    rows.push_back(z);}
                input.push_back(rows);
                ++l;}

        Life<ConwayCell> cc(input, p);
        cc.updateNeighbors();
        cc.updateLife();
        assert(cc.Cells[2][2]._state == false);
        assert(cc.Cells[2][2]._rep == '.');
        assert(cc.Cells[1][3]._state == false);
        assert(cc.Cells[1][3]._rep == '.');
        assert(cc.Cells[0][3]._state == true);
        assert(cc.Cells[0][3]._rep == '*');
        assert(cc.Cells[3][2]._state == false);
        assert(cc.Cells[3][2]._rep == '.');}

    void test_updateLife2() {
        string FredkinInput = "5\n5\n";
        FredkinInput += "--0--\n";
        FredkinInput += "-000-\n";
        FredkinInput += "00000\n";
        FredkinInput += "-000-\n";
        FredkinInput += "--0--\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<FredkinCell> > input;

        istringstream r (FredkinInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<FredkinCell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '0')
                        ++p;
                    rows.push_back(z);}
                input.push_back(rows);
                ++l;}

        Life<FredkinCell> cc(input, p);
        cc.updateNeighbors();
        cc.updateLife();
        assert(cc.Cells[2][2]._state == false);
        assert(cc.Cells[2][2]._rep == '-');
        assert(cc.Cells[1][3]._state == false);
        assert(cc.Cells[1][3]._rep == '-');
        assert(cc.Cells[0][3]._state == false);
        assert(cc.Cells[0][3]._rep == '-');
        assert(cc.Cells[4][2]._state == true);
        assert(cc.Cells[4][2]._rep == '1');}

    void test_updateLife3() {
        string CellInput = "5\n5\n";
        CellInput += "--0--\n";
        CellInput += "-000-\n";
        CellInput += "00000\n";
        CellInput += "-000-\n";
        CellInput += "--0--\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<Cell> > input;

        istringstream r (CellInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<Cell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '0')
                        ++p;
                    rows.push_back(new FredkinCell(z));}
                input.push_back(rows);
                ++l;}

        Life<Cell> cc(input, p);
        cc.updateNeighbors();
        cc.updateLife();
        assert(cc.Cells[2][2].get()->_state == false);
        assert(cc.Cells[2][2].get()->_rep == '-');
        assert(cc.Cells[1][3].get()->_state == false);
        assert(cc.Cells[1][3].get()->_rep == '-');
        assert(cc.Cells[0][3].get()->_state == false);
        assert(cc.Cells[0][3].get()->_rep == '-');
        assert(cc.Cells[4][2].get()->_state == true);
        assert(cc.Cells[4][2].get()->_rep == '1');}

    // printGrid
    void test_printGrid1() {
        string conwayInput = "5\n5\n";
        conwayInput += "..*..\n";
        conwayInput += ".***.\n";
        conwayInput += "*****\n";
        conwayInput += ".***.\n";
        conwayInput += "..*..\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<ConwayCell> > input;

        istringstream r (conwayInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<ConwayCell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '*')
                        ++p;
                    rows.push_back(z);}
                input.push_back(rows);
                ++l;}

        Life<ConwayCell> cc(input, p);
        ostringstream w1;
        ostringstream w2;

        w1 << "\nGeneration = 0, Population = 13.\n";
        w1 << "..*..\n";
        w1 << ".***.\n";
        w1 << "*****\n";
        w1 << ".***.\n";
        w1 << "..*..\n";

        cc.printGrid(w2);
        assert(w1.str() == w2.str());}

    void test_printGrid2() {
        string FredkinInput = "5\n5\n";
        FredkinInput += "--0--\n";
        FredkinInput += "-000-\n";
        FredkinInput += "00000\n";
        FredkinInput += "-000-\n";
        FredkinInput += "--0--\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<FredkinCell> > input;

        istringstream r (FredkinInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<FredkinCell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '0')
                        ++p;
                    rows.push_back(z);}
                input.push_back(rows);
                ++l;}

        Life<FredkinCell> cc(input, p);
        ostringstream w1;
        ostringstream w2;

        w1 << "\nGeneration = 0, Population = 13.\n";
        w1 << "--0--\n";
        w1 << "-000-\n";
        w1 << "00000\n";
        w1 << "-000-\n";
        w1 << "--0--\n";

        cc.printGrid(w2);
        assert(w1.str() == w2.str());}


    void test_printGrid3() {
    	string CellInput = "5\n5\n";
        CellInput += "--0--\n";
        CellInput += "-000-\n";
        CellInput += "00000\n";
        CellInput += "-000-\n";
        CellInput += "--0--\n";

        // variables
        int i, j;
        int l = 0;
        int p = 0;
        vector< vector<Cell> > input;

        istringstream r (CellInput);
            r >> i;
            r >> j;
            r.get();

            string line;
            while (l < i) {
                getline(r, line);

                char z;
                vector<Cell> rows;

                for (int x = 0; x < j; ++x) {
                    z = line[x];
                    if (z == '0')
                        ++p;
                    rows.push_back(new FredkinCell(z));}
                input.push_back(rows);
                ++l;}

        Life<Cell> cc(input, p);
        ostringstream w1;
        ostringstream w2;

        w1 << "\nGeneration = 0, Population = 13.\n";
        w1 << "--0--\n";
        w1 << "-000-\n";
        w1 << "00000\n";
        w1 << "-000-\n";
        w1 << "--0--\n";

        cc.printGrid(w2);
        assert(w1.str() == w2.str());

        cc.updateNeighbors();
        cc.updateLife();
        w1 << "\nGeneration = 1, Population = 4.\n";
        w1 << "--1--\n";
        w1 << "-----\n";
        w1 << "1---1\n";
        w1 << "-----\n";
        w1 << "--1--\n";

        cc.printGrid(w2);
        assert(w1.str() == w2.str());}

	CPPUNIT_TEST_SUITE(TestLife);

    CPPUNIT_TEST(test_ConwayCell1);
    CPPUNIT_TEST(test_ConwayCell2);
    CPPUNIT_TEST(test_ConwayCell3);
    CPPUNIT_TEST(test_conwayCheckState1);
    CPPUNIT_TEST(test_conwayCheckState2);
    CPPUNIT_TEST(test_conwayCheckState3);
    CPPUNIT_TEST(test_conwayEvolve1);
    CPPUNIT_TEST(test_conwayEvolve2);
    CPPUNIT_TEST(test_conwayEvolve3);
    CPPUNIT_TEST(test_FredkinCell1);
    CPPUNIT_TEST(test_FredkinCell2);
    CPPUNIT_TEST(test_FredkinCell3);
    CPPUNIT_TEST(test_fredkinCheckState1);
    CPPUNIT_TEST(test_fredkinCheckState2);
    CPPUNIT_TEST(test_fredkinCheckState3);
    CPPUNIT_TEST(test_fredkinEvolve1);
    CPPUNIT_TEST(test_fredkinEvolve2);
    CPPUNIT_TEST(test_fredkinEvolve3);
    CPPUNIT_TEST(test_Cell1);
    CPPUNIT_TEST(test_Cell2);
    CPPUNIT_TEST(test_Cell3);
    CPPUNIT_TEST(test_cellCheckState1);
    CPPUNIT_TEST(test_cellCheckState2);
    CPPUNIT_TEST(test_cellCheckState3);
    CPPUNIT_TEST(test_cellEvolve1);
    CPPUNIT_TEST(test_cellEvolve2);
    CPPUNIT_TEST(test_cellEvolve3);
    CPPUNIT_TEST(test_cellMutate1);
    CPPUNIT_TEST(test_cellMutate2);
    CPPUNIT_TEST(test_cellMutate3);
    CPPUNIT_TEST(test_updateNeighbors1);
    CPPUNIT_TEST(test_updateNeighbors2);
    CPPUNIT_TEST(test_updateNeighbors3);
    CPPUNIT_TEST(test_updateLife1);
    CPPUNIT_TEST(test_updateLife2);
    CPPUNIT_TEST(test_updateLife3);
    CPPUNIT_TEST(test_printGrid1);
    CPPUNIT_TEST(test_printGrid2);
    CPPUNIT_TEST(test_printGrid3);

	CPPUNIT_TEST_SUITE_END();};

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestLife.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestLife::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}