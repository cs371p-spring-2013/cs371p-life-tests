#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TestRunner

#define class struct
#define private public
#define protected public

#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Handle.h"

// ----------
// TestLife
// ----------

struct TestLife : CppUnit::TestFixture {

void conwayCell_constructor_test_1()
{
	ConwayCell cell;
	CPPUNIT_ASSERT(cell.getCurrentState() == '.');
}

void conwayCell_constructor_test_2()
{
	ConwayCell cell('*');
	CPPUNIT_ASSERT(cell.getCurrentState() == '*');
}

void conwayCell_constructor_test_3()
{
	ConwayCell cell('*');
	CPPUNIT_ASSERT(cell.getAge() == 0);
}

void conwayCell_clone_test_1()
{
	ConwayCell cell('*');
	ConwayCell *newCell = cell.clone();
	CPPUNIT_ASSERT(newCell->getCurrentState() == cell.getCurrentState());
	delete newCell;
}

void conwayCell_clone_test_2()
{
	ConwayCell cell('*');
	ConwayCell *newCell = cell.clone();
	CPPUNIT_ASSERT(newCell->getAge() == cell.getAge());
	delete newCell;
}

void conwayCell_clone_test_3()
{
	ConwayCell cell('*');
	ConwayCell *newCell = cell.clone();
	CPPUNIT_ASSERT(newCell->getCurrentState() == cell.getCurrentState());
	CPPUNIT_ASSERT(newCell->getAge() == cell.getAge());
	delete newCell;
}

void conwayCell_update_test_1()
{
	ConwayCell cell('*');
	cell.update();
	CPPUNIT_ASSERT(cell.getCurrentState() == '*');
}

void conwayCell_update_test_2()
{
	ConwayCell cell('*');
	cell.update();
	CPPUNIT_ASSERT(cell.getAge() == 0);
}

void conwayCell_update_test_3()
{
	ConwayCell cell('.');
	cell.update();
	CPPUNIT_ASSERT(cell.getAge() == 0);
	CPPUNIT_ASSERT(cell.getCurrentState() == '.');
}

void conwayCell_die_test_1()
{
	ConwayCell cell('*');
	cell.die();
	CPPUNIT_ASSERT(cell.getCurrentState() == '.');
}

void conwayCell_die_test_2()
{
	ConwayCell cell('*');
	cell.die();
	CPPUNIT_ASSERT(cell.getCurrentState() == '.');
}

void conwayCell_die_test_3()
{
	ConwayCell cell('*');
	cell.die();
	CPPUNIT_ASSERT(cell.getCurrentState() == '.');
}

void conwayCell_resurrect_test_1()
{
	ConwayCell cell('.');
	cell.resurrect();
	CPPUNIT_ASSERT(cell.getCurrentState() == '*');
}

void conwayCell_resurrect_test_2()
{
	ConwayCell cell('*');
	cell.resurrect();
	CPPUNIT_ASSERT(cell.getCurrentState() == '*');
}

void conwayCell_resurrect_test_3()
{
	ConwayCell cell('.');
	cell.resurrect();
	CPPUNIT_ASSERT(cell.getCurrentState() == '*');
}

void conwayCell_getDeathRule_test_1()
{
	ConwayCell cell;
	unsigned short x = (unsigned short)(~((1 << 2) | (1 << 3)));
	CPPUNIT_ASSERT(cell.getDeathRule() == x);
}

void conwayCell_getDeathRule_test_2()
{
	ConwayCell cell;
	unsigned short x = (unsigned short)(~((1 << 2) | (1 << 3)));
	CPPUNIT_ASSERT(cell.getDeathRule() == x);
}

void conwayCell_getDeathRule_test_3()
{
	ConwayCell cell;
	unsigned short x = (unsigned short)(~((1 << 2) | (1 << 3)));
	CPPUNIT_ASSERT(cell.getDeathRule() == x);
}

void conwayCell_getResurrectionRule_test_1()
{
	ConwayCell cell;
	CPPUNIT_ASSERT(cell.getResurrectionRule()== (1 << 3));
}

void conwayCell_getResurrectionRule_test_2()
{
	ConwayCell cell;
	CPPUNIT_ASSERT(cell.getResurrectionRule()== (1 << 3));
}

void conwayCell_getResurrectionRule_test_3()
{
	ConwayCell cell;
	CPPUNIT_ASSERT(cell.getResurrectionRule()== (1 << 3));
}

void conwayCell_getNeighborRule_test_1()
{
	ConwayCell cell;
	CPPUNIT_ASSERT(cell.getNeighborRule() == 0xFF);
}

void conwayCell_getNeighborRule_test_2()
{
	ConwayCell cell;
	CPPUNIT_ASSERT(cell.getNeighborRule() == 0xFF);
}

void conwayCell_getNeighborRule_test_3()
{
	ConwayCell cell;
	CPPUNIT_ASSERT(cell.getNeighborRule() == 0xFF);
}

void conwayCell_getSymbolKey_test_1()
{
	ConwayCell cell;
	CPPUNIT_ASSERT(cell.getSymbolKey().aliveSymbol == '*');
}

void conwayCell_getSymbolKey_test_2()
{
	ConwayCell cell;
	CPPUNIT_ASSERT(cell.getSymbolKey().deadSymbol == '.');
}

void conwayCell_getSymbolKey_test_3()
{
	ConwayCell cell;
	CPPUNIT_ASSERT(cell.getSymbolKey().aliveSymbol == '*');
	CPPUNIT_ASSERT(cell.getSymbolKey().deadSymbol == '.');
}

void fredkinCell_constructor_test_1()
{
	FredkinCell cell;
	CPPUNIT_ASSERT(cell.getCurrentState() == '-');
}

void fredkinCell_constructor_test_2()
{
	FredkinCell cell('-');
	CPPUNIT_ASSERT(cell.getCurrentState() == '-');
}

void fredkinCell_constructor_test_3()
{
	FredkinCell cell('-');
	CPPUNIT_ASSERT(cell.getAge() == 0);
}

void fredkinCell_clone_test_1()
{
	FredkinCell cell('-');
	FredkinCell *newCell = cell.clone();
	CPPUNIT_ASSERT(newCell->getCurrentState() == cell.getCurrentState());
	delete newCell;
}

void fredkinCell_clone_test_2()
{
	FredkinCell cell('-');
	FredkinCell *newCell = cell.clone();
	CPPUNIT_ASSERT(newCell->getAge() == cell.getAge());
	delete newCell;
}

void fredkinCell_clone_test_3()
{
	FredkinCell cell('-');
	FredkinCell *newCell = cell.clone();
	CPPUNIT_ASSERT(newCell->getCurrentState() == cell.getCurrentState());
	CPPUNIT_ASSERT(newCell->getAge() == cell.getAge());
	delete newCell;
}

void fredkinCell_update_test_1()
{
	FredkinCell cell('-');
	cell.update();
	CPPUNIT_ASSERT(cell.getCurrentState() == '-');
}

void fredkinCell_update_test_2()
{
	FredkinCell cell('-');
	cell.update();
	CPPUNIT_ASSERT(cell.getAge() == 0);
}

void fredkinCell_update_test_3()
{
	FredkinCell cell('-');
	cell.update();
	CPPUNIT_ASSERT(cell.getAge() == 0);
	CPPUNIT_ASSERT(cell.getCurrentState() == '-');
}

void fredkinCell_die_test_1()
{
	FredkinCell cell('-');
	cell.die();
	CPPUNIT_ASSERT(cell.getCurrentState() == '-');
}

void fredkinCell_die_test_2()
{
	FredkinCell cell('-');
	cell.die();
	CPPUNIT_ASSERT(cell.getCurrentState() == '-');
}

void fredkinCell_die_test_3()
{
	FredkinCell cell('-');
	cell.die();
	CPPUNIT_ASSERT(cell.getCurrentState() == '-');
}

void fredkinCell_resurrect_test_1()
{
	FredkinCell cell('-');
	cell.resurrect();
	CPPUNIT_ASSERT(cell.getCurrentState() == '0');
}

void fredkinCell_resurrect_test_2()
{
	FredkinCell cell('-');
	cell.resurrect();
	CPPUNIT_ASSERT(cell.getCurrentState() == '0');
}

void fredkinCell_resurrect_test_3()
{
	FredkinCell cell('-');
	cell.resurrect();
	CPPUNIT_ASSERT(cell.getCurrentState() == '0');
}

void fredkinCell_getDeathRule_test_1()
{
	FredkinCell cell;
	CPPUNIT_ASSERT(cell.getDeathRule() == ((1 << 0) | (1 << 2) | (1 << 4)));
}

void fredkinCell_getDeathRule_test_2()
{
	FredkinCell cell;
	CPPUNIT_ASSERT(cell.getDeathRule() == ((1 << 0) | (1 << 2) | (1 << 4)));
}

void fredkinCell_getDeathRule_test_3()
{
	FredkinCell cell;
	CPPUNIT_ASSERT(cell.getDeathRule() == ((1 << 0) | (1 << 2) | (1 << 4)));
}

void fredkinCell_getResurrectionRule_test_1()
{
	FredkinCell cell;
	CPPUNIT_ASSERT(cell.getResurrectionRule() == ((1 << 1) | (1 << 3)));
}

void fredkinCell_getResurrectionRule_test_2()
{
	FredkinCell cell;
	CPPUNIT_ASSERT(cell.getResurrectionRule() == ((1 << 1) | (1 << 3)));
}

void fredkinCell_getResurrectionRule_test_3()
{
	FredkinCell cell;
	CPPUNIT_ASSERT(cell.getResurrectionRule() == ((1 << 1) | (1 << 3)));
}

void fredkinCell_getNeighborRule_test_1()
{
	FredkinCell cell;
	CPPUNIT_ASSERT(cell.getNeighborRule() == 0xAA);
}

void fredkinCell_getNeighborRule_test_2()
{
	FredkinCell cell('-');
	CPPUNIT_ASSERT(cell.getNeighborRule() == 0xAA);
}

void fredkinCell_getNeighborRule_test_3()
{
	FredkinCell cell;
	CPPUNIT_ASSERT(cell.getNeighborRule() == 0xAA);
}

void fredkinCell_getSymbolKey_test_1()
{
	FredkinCell cell;
	CPPUNIT_ASSERT(cell.getSymbolKey().aliveSymbol == '0');
}

void fredkinCell_getSymbolKey_test_2()
{
	FredkinCell cell;
	CPPUNIT_ASSERT(cell.getSymbolKey().deadSymbol == '-');
}

void fredkinCell_getSymbolKey_test_3()
{
	FredkinCell cell('-');
	CPPUNIT_ASSERT(cell.getSymbolKey().aliveSymbol == '0');
	CPPUNIT_ASSERT(cell.getSymbolKey().deadSymbol == '-');
}

void cell_constructor_test_1()
{
	Cell c = Cell();
	CPPUNIT_ASSERT(c._p == 0);
}

void cell_constructor_test_2()
{
	Cell c = Cell(new FredkinCell());
	CPPUNIT_ASSERT(c.getCurrentState() == '-');
}

void cell_constructor_test_3()
{
	Cell c = Cell(new ConwayCell());
	CPPUNIT_ASSERT(c.getCurrentState() == '.');
}

void cell_getCurrentState_test_1()
{
	Cell c = Cell(new ConwayCell('*'));
	CPPUNIT_ASSERT(c.getCurrentState() == '*');
}

void cell_getCurrentState_test_2()
{
	Cell c = Cell(new FredkinCell());
	CPPUNIT_ASSERT(c.getCurrentState() == '-');
}

void cell_getCurrentState_test_3()
{
	Cell c = Cell(new ConwayCell());
	CPPUNIT_ASSERT(c.getCurrentState() == '.');
}

void cell_setCurrentState_test_1()
{
	Cell c = Cell(new ConwayCell('*'));
	c.setCurrentState('.');
	CPPUNIT_ASSERT(c.getCurrentState() == '.');
}

void cell_setCurrentState_test_2()
{
	Cell c = Cell(new FredkinCell());
	c.setCurrentState('9');
	CPPUNIT_ASSERT(c.getCurrentState() == '9');
}

void cell_setCurrentState_test_3()
{
	Cell c = Cell(new ConwayCell());
	c.setCurrentState('*');
	CPPUNIT_ASSERT(c.getCurrentState() == '*');
}

void cell_die_test_1()
{
	Cell c = Cell(new ConwayCell('*'));
	c.die();
	CPPUNIT_ASSERT(c.getCurrentState() == '.');
}

void cell_die_test_2()
{
	Cell c = Cell(new FredkinCell());
	c.setCurrentState('9');
	c.die();
	CPPUNIT_ASSERT(c.getCurrentState() == '-');
}

void cell_die_test_3()
{
	Cell c = Cell(new ConwayCell());
	c.setCurrentState('*');
	c.die();
	CPPUNIT_ASSERT(c.getCurrentState() == '.');
}

void cell_resurrect_test_1()
{
	Cell c = Cell(new ConwayCell('.'));
	c.resurrect();
	CPPUNIT_ASSERT(c.getCurrentState() == '*');
}

void cell_resurrect_test_2()
{
	Cell c = Cell(new FredkinCell());
	c.resurrect();
	CPPUNIT_ASSERT(c.getCurrentState() == '0');
}

void cell_resurrect_test_3()
{
	Cell c = Cell(new FredkinCell());
	c.setCurrentState('-');
	c.resurrect();
	CPPUNIT_ASSERT(c.getCurrentState() == '0');
}

void cell_update_test_1()
{
	Cell c = Cell(new ConwayCell('.'));
	c.update();
	CPPUNIT_ASSERT(c.getCurrentState() == '.');
}

void cell_update_test_2()
{
	Cell c = Cell(new FredkinCell());
	c.update();
	CPPUNIT_ASSERT(c.getCurrentState() == '-');
}

void cell_update_test_3()
{
	Cell c = Cell(new FredkinCell('0'));
	c.update();
	c.update();
	c.update();
	c.update();
	CPPUNIT_ASSERT(c.getCurrentState() == '*');
}

void cell_getDeathRule_test_1()
{
	Cell cell = Cell(new ConwayCell());
	unsigned short x = (unsigned short)(~((1 << 2) | (1 << 3)));
	CPPUNIT_ASSERT(cell.getDeathRule() == x);
}

void cell_getDeathRule_test_2()
{
	Cell cell = Cell(new FredkinCell());
	CPPUNIT_ASSERT(cell.getDeathRule() == ((1 << 0) | (1 << 2) | (1 << 4)));
}

void cell_getDeathRule_test_3()
{
	Cell cell = Cell(new ConwayCell());
	CPPUNIT_ASSERT(cell.getDeathRule() != ((1 << 0) | (1 << 2) | (1 << 4)));
}

void cell_getResurrectionRule_test_1()
{
	Cell cell = Cell(new ConwayCell());
	CPPUNIT_ASSERT(cell.getResurrectionRule() == (1 << 3));
}

void cell_getResurrectionRule_test_2()
{
	Cell cell = Cell(new FredkinCell());
	CPPUNIT_ASSERT(cell.getResurrectionRule() == ((1 << 1) | (1 << 3)));
}

void cell_getResurrectionRule_test_3()
{
	Cell cell = Cell(new ConwayCell());
	CPPUNIT_ASSERT(cell.getResurrectionRule() != ((1 << 1) | (1 << 3)));
}

void cell_getNeighborRule_test_1()
{
	Cell cell = Cell(new ConwayCell());
	CPPUNIT_ASSERT(cell.getNeighborRule() == 0xFF);
}

void cell_getNeighborRule_test_2()
{
	Cell cell = Cell(new FredkinCell());
	CPPUNIT_ASSERT(cell.getNeighborRule() == 0xAA);
}

void cell_getNeighborRule_test_3()
{
	Cell cell = Cell(new ConwayCell());
	CPPUNIT_ASSERT(cell.getNeighborRule() != 0xAA);
}

void cell_getSymbolKey_test_1()
{
	Cell cell = Cell(new ConwayCell());
	CPPUNIT_ASSERT(cell.getSymbolKey().aliveSymbol == '*');
}

void cell_getSymbolKey_test_2()
{
	Cell cell = Cell(new FredkinCell());
	CPPUNIT_ASSERT(cell.getSymbolKey().deadSymbol == '-');
}

void cell_getSymbolKey_test_3()
{
	Cell cell = Cell(new FredkinCell());
	CPPUNIT_ASSERT(cell.getSymbolKey().aliveSymbol == '0');
	CPPUNIT_ASSERT(cell.getSymbolKey().deadSymbol == '-');
}

void cell_clone_test_1()
{
	Cell cell = Cell(new FredkinCell());
	// FredkinCell cell('-');
	// FredkinCell *newCell = cell.clone();
	CPPUNIT_ASSERT(cell.clone()->getCurrentState() == cell.getCurrentState());
}

void cell_clone_test_2()
{
	Cell cell = Cell(new ConwayCell());
	CPPUNIT_ASSERT(cell.clone()->getCurrentState() == cell.getCurrentState());
}

void cell_clone_test_3()
{
	Cell cell = Cell(new FredkinCell());
	CPPUNIT_ASSERT(cell.clone()->getCurrentState() == cell.getCurrentState());
}

void make_pair_test_1()
{
	Pair x = make_pair(1, 2);
	CPPUNIT_ASSERT(x.first == 1);
}

void make_pair_test_2()
{
	Pair x = make_pair(1, 2);
	CPPUNIT_ASSERT(x.second == 2);
}

void make_pair_test_3()
{
	Pair x = make_pair(1, 2);
	CPPUNIT_ASSERT(x.first == 1);
	CPPUNIT_ASSERT(x.second == 2);
}

void life_constructor_test_1()
{
	Life<Cell> life = Life <Cell> (1, 2);
	CPPUNIT_ASSERT(life._numRows == 1);
}

void life_constructor_test_2()
{
	Life<Cell> life = Life <Cell> (1, 2);
	CPPUNIT_ASSERT(life._numColumns == 2);
}

void life_constructor_test_3()
{
	Life<Cell> life = Life <Cell> (1, 2);
	CPPUNIT_ASSERT(life._numRows == 1);
	CPPUNIT_ASSERT(life._numColumns == 2);
}

void life_addAbstractCell_test_1()
{
	Life<ConwayCell> life = Life <ConwayCell> (1, 2);
	life.addAbstractCell('*', 0, 0);
	CPPUNIT_ASSERT(life._grid[0][0].getCurrentState() == '*');
}

void life_addAbstractCell_test_2()
{
	Life<FredkinCell> life = Life <FredkinCell> (1, 2);
	life.addAbstractCell('-', 0, 0);
	CPPUNIT_ASSERT(life._grid[0][0].getCurrentState() == '-');
}

void life_addAbstractCell_test_3()
{
	Life<ConwayCell> life = Life <ConwayCell> (1, 2);
	life.addAbstractCell('.', 0, 0);
	CPPUNIT_ASSERT(life._grid[0][0].getCurrentState() == '.');
}

void life_addCell_test_1()
{
	Life<Cell> life = Life <Cell> (1, 2);
	life.addCell('*', 0, 0);
	CPPUNIT_ASSERT(life._grid[0][0].getCurrentState() == '*');
}

void life_addCell_test_2()
{
	Life<Cell> life = Life <Cell> (1, 2);
	life.addCell('-', 0, 0);
	CPPUNIT_ASSERT(life._grid[0][0].getCurrentState() == '-');
}

void life_addCell_test_3()
{
	Life<Cell> life = Life <Cell> (1, 2);
	life.addCell('.', 0, 0);
	CPPUNIT_ASSERT(life._grid[0][0].getCurrentState() == '.');
}

// ---------
// TestSuite
// ---------

CPPUNIT_TEST_SUITE(TestLife);

/// ConwayCell
CPPUNIT_TEST(conwayCell_constructor_test_1);
CPPUNIT_TEST(conwayCell_constructor_test_2);
CPPUNIT_TEST(conwayCell_constructor_test_3);

CPPUNIT_TEST(conwayCell_clone_test_1);
CPPUNIT_TEST(conwayCell_clone_test_2);
CPPUNIT_TEST(conwayCell_clone_test_3);

CPPUNIT_TEST(conwayCell_update_test_1);
CPPUNIT_TEST(conwayCell_update_test_2);
CPPUNIT_TEST(conwayCell_update_test_3);

CPPUNIT_TEST(conwayCell_die_test_1);
CPPUNIT_TEST(conwayCell_die_test_2);
CPPUNIT_TEST(conwayCell_die_test_3);

CPPUNIT_TEST(conwayCell_resurrect_test_1);
CPPUNIT_TEST(conwayCell_resurrect_test_2);
CPPUNIT_TEST(conwayCell_resurrect_test_3);

CPPUNIT_TEST(conwayCell_getDeathRule_test_1);
CPPUNIT_TEST(conwayCell_getDeathRule_test_2);
CPPUNIT_TEST(conwayCell_getDeathRule_test_3);

CPPUNIT_TEST(conwayCell_getResurrectionRule_test_1);
CPPUNIT_TEST(conwayCell_getResurrectionRule_test_2);
CPPUNIT_TEST(conwayCell_getResurrectionRule_test_3);

CPPUNIT_TEST(conwayCell_getNeighborRule_test_1);
CPPUNIT_TEST(conwayCell_getNeighborRule_test_2);
CPPUNIT_TEST(conwayCell_getNeighborRule_test_3);

CPPUNIT_TEST(conwayCell_getSymbolKey_test_1);
CPPUNIT_TEST(conwayCell_getSymbolKey_test_2);
CPPUNIT_TEST(conwayCell_getSymbolKey_test_3);

CPPUNIT_TEST(fredkinCell_constructor_test_1);
CPPUNIT_TEST(fredkinCell_constructor_test_2);
CPPUNIT_TEST(fredkinCell_constructor_test_3);

CPPUNIT_TEST(fredkinCell_clone_test_1);
CPPUNIT_TEST(fredkinCell_clone_test_2);
CPPUNIT_TEST(fredkinCell_clone_test_3);

CPPUNIT_TEST(fredkinCell_update_test_1);
CPPUNIT_TEST(fredkinCell_update_test_2);
CPPUNIT_TEST(fredkinCell_update_test_3);

CPPUNIT_TEST(fredkinCell_die_test_1);
CPPUNIT_TEST(fredkinCell_die_test_2);
CPPUNIT_TEST(fredkinCell_die_test_3);

CPPUNIT_TEST(fredkinCell_resurrect_test_1);
CPPUNIT_TEST(fredkinCell_resurrect_test_2);
CPPUNIT_TEST(fredkinCell_resurrect_test_3);

CPPUNIT_TEST(fredkinCell_getDeathRule_test_1);
CPPUNIT_TEST(fredkinCell_getDeathRule_test_2);
CPPUNIT_TEST(fredkinCell_getDeathRule_test_3);

CPPUNIT_TEST(fredkinCell_getResurrectionRule_test_1);
CPPUNIT_TEST(fredkinCell_getResurrectionRule_test_2);
CPPUNIT_TEST(fredkinCell_getResurrectionRule_test_3);

CPPUNIT_TEST(fredkinCell_getNeighborRule_test_1);
CPPUNIT_TEST(fredkinCell_getNeighborRule_test_2);
CPPUNIT_TEST(fredkinCell_getNeighborRule_test_3);

CPPUNIT_TEST(fredkinCell_getSymbolKey_test_1);
CPPUNIT_TEST(fredkinCell_getSymbolKey_test_2);
CPPUNIT_TEST(fredkinCell_getSymbolKey_test_3);

CPPUNIT_TEST(cell_constructor_test_1);
CPPUNIT_TEST(cell_constructor_test_2);
CPPUNIT_TEST(cell_constructor_test_3);

CPPUNIT_TEST(cell_getCurrentState_test_1);
CPPUNIT_TEST(cell_getCurrentState_test_2);
CPPUNIT_TEST(cell_getCurrentState_test_3);

CPPUNIT_TEST(cell_setCurrentState_test_1);
CPPUNIT_TEST(cell_setCurrentState_test_2);
CPPUNIT_TEST(cell_setCurrentState_test_3);

CPPUNIT_TEST(cell_die_test_1);
CPPUNIT_TEST(cell_die_test_2);
CPPUNIT_TEST(cell_die_test_3);

CPPUNIT_TEST(cell_resurrect_test_1);
CPPUNIT_TEST(cell_resurrect_test_2);
CPPUNIT_TEST(cell_resurrect_test_3);

CPPUNIT_TEST(cell_update_test_1);
CPPUNIT_TEST(cell_update_test_2);
CPPUNIT_TEST(cell_update_test_3);

CPPUNIT_TEST(cell_getDeathRule_test_1);
CPPUNIT_TEST(cell_getDeathRule_test_2);
CPPUNIT_TEST(cell_getDeathRule_test_3);

CPPUNIT_TEST(cell_getResurrectionRule_test_1);
CPPUNIT_TEST(cell_getResurrectionRule_test_2);
CPPUNIT_TEST(cell_getResurrectionRule_test_3);

CPPUNIT_TEST(cell_getNeighborRule_test_1);
CPPUNIT_TEST(cell_getNeighborRule_test_2);
CPPUNIT_TEST(cell_getNeighborRule_test_3);

CPPUNIT_TEST(cell_getSymbolKey_test_1);
CPPUNIT_TEST(cell_getSymbolKey_test_2);
CPPUNIT_TEST(cell_getSymbolKey_test_3);

CPPUNIT_TEST(cell_clone_test_1);
CPPUNIT_TEST(cell_clone_test_2);
CPPUNIT_TEST(cell_clone_test_3);

CPPUNIT_TEST(make_pair_test_1);
CPPUNIT_TEST(make_pair_test_2);
CPPUNIT_TEST(make_pair_test_3);

CPPUNIT_TEST(life_constructor_test_1);
CPPUNIT_TEST(life_constructor_test_2);
CPPUNIT_TEST(life_constructor_test_3);

CPPUNIT_TEST(life_addAbstractCell_test_1);
CPPUNIT_TEST(life_addAbstractCell_test_2);
CPPUNIT_TEST(life_addAbstractCell_test_3);

CPPUNIT_TEST(life_addCell_test_1);
CPPUNIT_TEST(life_addCell_test_2);
CPPUNIT_TEST(life_addCell_test_3);

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
