#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TextTestRunner.h"

#define private public
#define protected public

#include "AbstractCell.h"
#include "ConwayCell.h"
#include "Cell.h"
#include "FredkinCell.h"
#include "Life.h"

#include <iostream>
#include <unordered_set>
#include <sstream>
#include <vector>

using namespace std;

struct TestLife : CppUnit::TestFixture
{
    Life<ConwayCell>* life;
    vector<ConwayCell> cellArray;

    void test_toString_1()
    {
        //Arrange
        ConwayCell conwayCell(0,0,false);

        //Act
        string pic = conwayCell.toString();

        //Assert
        CPPUNIT_ASSERT(pic == ".");
    }

    void test_toString_2()
    {
        //Arrange
        FredkinCell fredkinCell(0,0,true,5);

        //Act
        string pic = fredkinCell.toString();

        //Assert
        CPPUNIT_ASSERT(pic == "5");
    }

    void test_toString_3()
    {
        //Arrange
        Cell cell = new ConwayCell(0,0,true);

        //Act
        string pic = cell.toString();

        //Assert
        CPPUNIT_ASSERT(pic == "*");
    }

    void test_clone_1()
    {
        //Arrange
        ConwayCell conwayCell(1,2,false);

        //Act
        ConwayCell* clone = conwayCell.clone();

        //Assert
        CPPUNIT_ASSERT(conwayCell.isAlive() == clone->isAlive());
        CPPUNIT_ASSERT(conwayCell.getX() == clone->getX());
        CPPUNIT_ASSERT(conwayCell.getY() == clone->getY());

        //TearDown
        delete clone;
    }

    void test_clone_2()
    {
        //Arrange
        FredkinCell fredkinCell(1,2,false, 2);

        //Act
        FredkinCell* clone = fredkinCell.clone();

        //Assert
        CPPUNIT_ASSERT(fredkinCell.isAlive() == clone->isAlive());
        CPPUNIT_ASSERT(fredkinCell.getX() == clone->getX());
        CPPUNIT_ASSERT(fredkinCell.getY() == clone->getY());
        CPPUNIT_ASSERT(fredkinCell._age == clone->_age);

        //TearDown
        delete clone;
    }

    void test_clone_3()
    {
        //Arrange
        AbstractCell* fredkinCell = new FredkinCell(1,2,false, 2);

        //Act
        AbstractCell* clone = fredkinCell->clone();

        //Assert
        CPPUNIT_ASSERT(fredkinCell->isAlive() == clone->isAlive());
        CPPUNIT_ASSERT(fredkinCell->getX() == clone->getX());
        CPPUNIT_ASSERT(fredkinCell->getY() == clone->getY());

        //TearDown
        delete fredkinCell;
        delete clone;
    }

    void test_isAlive_1()
    {
        //Arrange
        ConwayCell conwayCell(1,1,false);

        //Act
        bool isAlive = conwayCell.isAlive();

        //Assert
        CPPUNIT_ASSERT(isAlive == false);
    }

    void test_isAlive_2()
    {
        //Arrange
        FredkinCell fredkinCell(1,1,true, 0);

        //Act
        bool isAlive = fredkinCell.isAlive();

        //Assert
        CPPUNIT_ASSERT(isAlive == true);
    }

    void test_isAlive_3()
    {
        //Arrange
        Cell cell = new FredkinCell(1,1,true,0);

        //Act
        bool isAlive = cell.isAlive();

        //Assert
        CPPUNIT_ASSERT(isAlive == true);
    }

    void test_DetermineFate_1()
    {
        //Arrange
        ConwayCell conwayCell(1,1,false);

        //Act
        conwayCell.DetermineFate(2, 1);

        //Assert
        CPPUNIT_ASSERT(conwayCell._aliveNextTurn == true);
    }

    void test_DetermineFate_2()
    {
        //Arrange
        FredkinCell fredkinCell(1,1,false, 2);

        //Act
        fredkinCell.DetermineFate(2, 1);

        ///Assert
        CPPUNIT_ASSERT(fredkinCell._aliveNextTurn == false);
    }

    void test_DetermineFate_3()
    {
        //Arrange
        Cell cell = new FredkinCell(1,1,false, 2);

        //Act
        cell.DetermineFate(2, 1);

        //Assert
        CPPUNIT_ASSERT(cell.isAlive() == false);
    }

    void test_mutate_1()
    {
        //Arrange
        ConwayCell conwayCell(1,1,false);

        //Act
        conwayCell.mutate();

        //Assert
        CPPUNIT_ASSERT(conwayCell.toString() == ".");
    }

    void test_mutate_2()
    {
        //Arrange
        FredkinCell fredkinCell(1,1,false,2);

        //Act
        fredkinCell.mutate();

        //Assert
        CPPUNIT_ASSERT(fredkinCell.toString() == "-");
    }

    void test_mutate_3()
    {
        //Arrange
        Cell cell = new FredkinCell(1,1,false,2);

        //Act
        cell.mutate();

        //Assert
        CPPUNIT_ASSERT(cell.toString() == "*");
    }

    void test_getX_1()
    {
        //Arrange
        ConwayCell conwayCell(1,2,false);

        //Act
        int x = conwayCell.getX();

        //Assert
        CPPUNIT_ASSERT(x == 1);
    }

    void test_getX_2()
    {
        //Arrange
        FredkinCell fredkinCell(1,2,false,0);

        //Act
        int x = fredkinCell.getX();

        //Assert
        CPPUNIT_ASSERT(x == 1);
    }

    void test_getX_3()
    {
        //Arrange
        Cell cell = new FredkinCell(1,2,false,0);

        //Act
        int x = cell.getX();

        //Act
        CPPUNIT_ASSERT(x == 1);
    }

    void test_getY_1()
    {
        //Arrange
        ConwayCell conwayCell(1,2,false);

        //Act
        int y = conwayCell.getY();

        //Assert
        CPPUNIT_ASSERT(y == 2);
    }

    void test_getY_2()
    {
        //Arrange
        FredkinCell fredkinCell(1,2,false,0);

        //Act
        int y = fredkinCell.getY();

        //Assert
        CPPUNIT_ASSERT(y == 2);
    }

    void test_getY_3()
    {
        //Arrange
        Cell cell = new FredkinCell(1,2,false,0);

        //Act
        int y = cell.getY();

        //Assert
        CPPUNIT_ASSERT(y == 2);
    }

    void test_Add_1()
    {
        //Arrange
        Life<ConwayCell> life(5,5);
        ConwayCell conwayCell(1,1,false);

        //Act
        life.Add(conwayCell);
        ConwayCell* pointer = life.grid[1][1];

        //Assert
        CPPUNIT_ASSERT(pointer->getX() == 1);
    }

    void test_Add_2()
    {
        //Arrange
        Life<FredkinCell> life(5,5);
        FredkinCell fredkinCell(1,1,false,0);

        //Act
        life.Add(fredkinCell);
        FredkinCell* pointer = life.grid[1][1];

        //Assert
        CPPUNIT_ASSERT(pointer->getX() == 1);
    }

    void test_Add_3()
    {
        //Arrange
        Life<Cell> life(5,5);
        Cell cell = new FredkinCell(1,1,false,0);

        //Act
        life.Add(cell);
        Cell* pointer = life.grid[1][1];

        //Assert
        CPPUNIT_ASSERT(pointer->getX() == 1);
    }

    void test_CheckNeighbor_1()
    {
        //Arrange
        Life<ConwayCell> life(5,5);
        ConwayCell conwayCell(1,1,false);
        life.Add(conwayCell);
        int numNeighbors = 0;

        //Act
        life.CheckNeighbor(1,1,numNeighbors);

        //Assert
        CPPUNIT_ASSERT(numNeighbors == 0);
    }

    void test_CheckNeighbor_2()
    {
        //Arrange
        Life<ConwayCell> life(5,5);
        ConwayCell conwayCell(1,1,false);
        life.Add(conwayCell);
        conwayCell._x = -1;
        int numNeighbors = 0;

        //Act
        life.CheckNeighbor(-1,1,numNeighbors);

        //Assert
        CPPUNIT_ASSERT(numNeighbors == 0);
    }

    void test_CheckNeighbor_3()
    {
        //Arrange
        Life<ConwayCell> life(5,5);
        ConwayCell conwayCell(1,1,true);
        life.Add(conwayCell);
        int numNeighbors = 0;

        //Act
        life.CheckNeighbor(1,1,numNeighbors);

        //Assert
        CPPUNIT_ASSERT(numNeighbors == 1);
    }

    void test_GetCardinalNeighborsCount_1()
    {
        //Arrange
        ConwayCell* cellUnderTest = life->grid[1][2];

        //Act
        int numCardinalNeighbors = life->GetCardinalNeighborsCount(*cellUnderTest);

        //Assert
        CPPUNIT_ASSERT(numCardinalNeighbors == 0);
    }

    void test_GetCardinalNeighborsCount_2()
    {
        //Arrange
        ConwayCell* cellUnderTest = life->grid[3][2];

        //Act
        int numCardinalNeighbors = life->GetCardinalNeighborsCount(*cellUnderTest);

        //Assert
        CPPUNIT_ASSERT(numCardinalNeighbors == 2);
    }

    void test_GetCardinalNeighborsCount_3()
    {
        //Arrange
        ConwayCell* cellUnderTest = life->grid[2][3];

        //Act
        int numCardinalNeighbors = life->GetCardinalNeighborsCount(*cellUnderTest);

        //Assert
        CPPUNIT_ASSERT(numCardinalNeighbors == 1);
    }

    void test_GetOrdinalNeighborsCount_1()
    {
        //Arrange
        ConwayCell* cellUnderTest = life->grid[1][2];

        //Act
        int numOrdinalNeighbors = life->GetOrdinalNeighborsCount(*cellUnderTest);

        //Assert
        CPPUNIT_ASSERT(numOrdinalNeighbors == 1);
    }

    void test_GetOrdinalNeighborsCount_2()
    {
        //Arrange
        ConwayCell* cellUnderTest = life->grid[0][0];

        //Act
        int numOrdinalNeighbors = life->GetOrdinalNeighborsCount(*cellUnderTest);

        //Assert
        CPPUNIT_ASSERT(numOrdinalNeighbors == 0);
    }

    void test_GetOrdinalNeighborsCount_3()
    {
        //Arrange
        ConwayCell* cellUnderTest = life->grid[3][2];

        //Act
        int numOrdinalNeighbors = life->GetOrdinalNeighborsCount(*cellUnderTest);

        //Assert
        CPPUNIT_ASSERT(numOrdinalNeighbors == 1);
    }

    void test_Simulate_1()
    {
        //Arrange
        ConwayCell* cellUnderTest = life->grid[0][0];
        unordered_set<int> specificGrids;

        //Act
        life->Simulate(1, -1, -1, specificGrids);

        //Assert
        CPPUNIT_ASSERT(cellUnderTest->isAlive() == false);
    }

    void test_Simulate_2()
    {
        //Arrange
        ConwayCell* cellUnderTest = life->grid[3][2];
        unordered_set<int> specificGrids;

        //Act
        life->Simulate(5,-1,-1,specificGrids);

        //Assert
        CPPUNIT_ASSERT(cellUnderTest->isAlive() == true);
    }

    void test_Simulate_3()
    {
        //Arrange
        ConwayCell* cellUnderTest = life->grid[2][3];
        unordered_set<int> specificGrids;

        //Act
        life->Simulate(5, -1, -1, specificGrids);

        //Assert
        CPPUNIT_ASSERT(cellUnderTest->isAlive() == false);
    }

    void setUp()
    {
	istringstream cells;
        cells.str(".....\n"
                "..*..\n"
                "...*.\n"
                ".***.\n"
                ".....\n");

        int rows = 5;
        int columns = 5;
        char cell;

        life = new Life<ConwayCell>(rows, columns);
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<columns; j++)
            {
                cells >> cell;
                switch(cell)
                {
                    case '.':
                        cellArray.push_back(ConwayCell(i,j,false));
                        break;
                    case '*':
                        cellArray.push_back(ConwayCell(i,j,true));
                        break;
                }
            }
        }

        int size = cellArray.size();
        for(int i=0; i<size; i++)
        {
            life->Add(cellArray[i]);
        }
    }

    void tearDown()
    {
        delete life;
        cellArray.clear();
    }

    CPPUNIT_TEST_SUITE(TestLife);

    CPPUNIT_TEST(test_toString_1);
    CPPUNIT_TEST(test_toString_2);
    CPPUNIT_TEST(test_toString_3);

    CPPUNIT_TEST(test_clone_1);
    CPPUNIT_TEST(test_clone_2);
    CPPUNIT_TEST(test_clone_3);

    CPPUNIT_TEST(test_isAlive_1);
    CPPUNIT_TEST(test_isAlive_2);
    CPPUNIT_TEST(test_isAlive_3);

    CPPUNIT_TEST(test_CheckNeighbor_1);
    CPPUNIT_TEST(test_CheckNeighbor_2);
    CPPUNIT_TEST(test_CheckNeighbor_3);

    CPPUNIT_TEST(test_getX_1);
    CPPUNIT_TEST(test_getX_2);
    CPPUNIT_TEST(test_getX_3);

    CPPUNIT_TEST(test_getY_1);
    CPPUNIT_TEST(test_getY_2);
    CPPUNIT_TEST(test_getY_3);

    CPPUNIT_TEST(test_Add_1);
    CPPUNIT_TEST(test_Add_2);
    CPPUNIT_TEST(test_Add_3);

    CPPUNIT_TEST(test_mutate_1);
    CPPUNIT_TEST(test_mutate_2);
    CPPUNIT_TEST(test_mutate_3);

    CPPUNIT_TEST(test_DetermineFate_1);
    CPPUNIT_TEST(test_DetermineFate_2);
    CPPUNIT_TEST(test_DetermineFate_3);


    CPPUNIT_TEST(test_GetCardinalNeighborsCount_1);
    CPPUNIT_TEST(test_GetCardinalNeighborsCount_2);
    CPPUNIT_TEST(test_GetCardinalNeighborsCount_3);

    CPPUNIT_TEST(test_GetOrdinalNeighborsCount_1);
    CPPUNIT_TEST(test_GetOrdinalNeighborsCount_2);
    CPPUNIT_TEST(test_GetOrdinalNeighborsCount_3);


    CPPUNIT_TEST(test_Simulate_1);
    CPPUNIT_TEST(test_Simulate_2);
    CPPUNIT_TEST(test_Simulate_3);

    CPPUNIT_TEST_SUITE_END();
};

int main()
{
    ios_base::sync_with_stdio(false);
    cout << "TestLife.c++" << endl;

    CppUnit::TextTestRunner tr;

    tr.addTest(TestLife::suite());
    tr.run();
    cout << "Done." << endl;

    return 0;
}
