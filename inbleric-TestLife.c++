
// --------
// includes
// --------

#include <algorithm> //count
#include <iostream> // ios_base
#include <memory> //allocator
#include <sstream> //string stream
#include <stdexcept> //exceptions

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner



#define protected public
#define private public

#include "Life.h"
#include "AbstractCell.h"
#include "FredkinCell.h"
#include "ConwayCell.h"
#include "Cell.h"

// -------------
// TestLife
// -------------

struct TestLife : CppUnit::TestFixture {


    void testLife1() {
    	vector<vector<ConwayCell> > v = vector<vector<ConwayCell> >(0);
    	Life<ConwayCell> L = Life<ConwayCell>(5,5,v);
    	CPPUNIT_ASSERT(L._x == 5);
    	CPPUNIT_ASSERT(L._y == 5);
    	CPPUNIT_ASSERT(L._generation == 0);
    	CPPUNIT_ASSERT(L._population == 0);
    }
    
    void testLife2() {
    	vector<vector<ConwayCell> > v = vector<vector<ConwayCell> >(0);    	
    	v.resize(5);
    	for(int i = 0; i < 5; ++i) 
    		v[i].resize(1);
    	v[0][0] = ConwayCell(0,0,'*');
    	Life<ConwayCell> L = Life<ConwayCell>(5,5,v);    	
    	CPPUNIT_ASSERT(L._x == 5);
    	CPPUNIT_ASSERT(L._y == 5);
    	CPPUNIT_ASSERT(L._generation == 0);
    	CPPUNIT_ASSERT(L._population == 1);
    }
    
    void testLife3() {
    	vector<vector<ConwayCell> > v = vector<vector<ConwayCell> >(0);
    	Life<ConwayCell> L = Life<ConwayCell>(5,10,v);
    	CPPUNIT_ASSERT(L._y == 5);
    	CPPUNIT_ASSERT(L._x == 10);
    	CPPUNIT_ASSERT(L._generation == 0);
    	CPPUNIT_ASSERT(L._population == 0);
    }

    void testDoMoves1() {
    	vector<vector<ConwayCell> > v = vector<vector<ConwayCell> >(0);
    	v.resize(5);
    	for(int i = 0; i < 5; ++i) 
    		v[i].resize(1);
    	Life<ConwayCell> L = Life<ConwayCell>(5,1,v);
    	L.doMoves(0);
    	CPPUNIT_ASSERT(L._generation == 0);
    }

    void testDoMoves2() {
    	vector<vector<ConwayCell> > v = vector<vector<ConwayCell> >(0);
    	v.resize(5);
    	for(int i = 0; i < 5; ++i) 
    		v[i].resize(1);
    	Life<ConwayCell> L = Life<ConwayCell>(5,1,v);
    	L.doMoves(5);
    	CPPUNIT_ASSERT(L._generation == 5);
    }
    
    void testDoMoves3() {
    	vector<vector<ConwayCell> > v = vector<vector<ConwayCell> >(0);
    	v.resize(5);
    	for(int i = 0; i < 5; ++i) 
    		v[i].resize(1);
    	Life<ConwayCell> L = Life<ConwayCell>(5,1,v);
    	L.doMoves(10);
    	CPPUNIT_ASSERT(L._generation == 10);
    }


    void testFredkinCellD1() {
    	FredkinCell f = FredkinCell();
    	CPPUNIT_ASSERT(f._x == 0);
	CPPUNIT_ASSERT(f._y == 0);	
    }

    void testFredkinCellD2() {
    	FredkinCell f = FredkinCell();	
	CPPUNIT_ASSERT(f._c=='-');
    }
    
    void testFredkinCellD3() {
    	FredkinCell f = FredkinCell();
	CPPUNIT_ASSERT(f._alive == false);
    }
    
    void testFredkinCell1() {
    	FredkinCell f = FredkinCell(0,0,'0');
    	CPPUNIT_ASSERT(f._x == 0);
	CPPUNIT_ASSERT(f._y == 0);	
    }
    
    void testFredkinCell2() {
    	FredkinCell f = FredkinCell(0,0,'0');
	CPPUNIT_ASSERT(f._c=='0');
	CPPUNIT_ASSERT(f._alive == true);    	    	
    }
    
    void testFredkinCell3() {
    	FredkinCell f = FredkinCell(0,0,'0');
    	CPPUNIT_ASSERT(f._age==0);
    }
    
    void testFredkinUpdate1() {
    	vector<vector<FredkinCell> > v = vector<vector<FredkinCell> >(0);    	
    	v.resize(5);
    	for(int i = 0; i < 5; ++i) 
    		v[i].resize(1);
    	v[0][0] = FredkinCell(0,0,'*');
    	vector<vector<bool> > b = vector<vector<bool> >(0);    	
    	b.resize(5);
    	for(int i = 0; i < 5; ++i) 
    		b[i].resize(1);
    	b[0][0] = true;
    	Life<FredkinCell> L = Life<FredkinCell>(5,1,v); 
    	CPPUNIT_ASSERT(L._cells[0][0].update(b) == false);
    }
    
    void testFredkinUpdate2() {
    	vector<vector<FredkinCell> > v = vector<vector<FredkinCell> >(0);    	
    	v.resize(5);
    	for(int i = 0; i < 5; ++i) 
    		v[i].resize(2);
    	v[0][0] = FredkinCell(0,0,'*');
    	vector<vector<bool> > b = vector<vector<bool> >(0);    	
    	b.resize(5);
    	for(int i = 0; i < 5; ++i) 
    		b[i].resize(2);
    	b[0][0] = true;
    	b[0][1] = true;
    	b[1][0] = true;
    	Life<FredkinCell> L = Life<FredkinCell>(5,2,v); 
    	CPPUNIT_ASSERT(L._cells[1][1].update(b) == false);
    }
    
    void testFredkinUpdate3() {
    	vector<vector<FredkinCell> > v = vector<vector<FredkinCell> >(0);    	
    	v.resize(5);
    	for(int i = 0; i < 5; ++i) 
    		v[i].resize(2);
    	v[0][0] = FredkinCell(0,0,'*');
    	vector<vector<bool> > b = vector<vector<bool> >(0);    	
    	b.resize(5);
    	for(int i = 0; i < 5; ++i) 
    		b[i].resize(2);
    	b[0][0] = true;
    	b[0][1] = true;
    	b[1][0] = true;
    	Life<FredkinCell> L = Life<FredkinCell>(5,2,v); 
    	CPPUNIT_ASSERT(L._cells[0][0].update(b) == false);
    }
    
    void testFredkinAlive1() {
    	FredkinCell f = FredkinCell();
    	CPPUNIT_ASSERT(!f.isAlive());
    }
    
    void testFredkinAlive2() {
	FredkinCell f = FredkinCell(1,1,'-');
    	CPPUNIT_ASSERT(!f.isAlive());
    }
    
    void testFredkinAlive3() {
 	FredkinCell f = FredkinCell(1,1,'0');
    	CPPUNIT_ASSERT(f.isAlive());
    }
    
    void testFredkinCheckEvolve1() {
    	FredkinCell f = FredkinCell();    	
    	CPPUNIT_ASSERT(!f.checkEvolve());
    }
    
    void testFredkinCheckEvolve2() {
    	FredkinCell f = FredkinCell();
    	f._c = '1';
    	CPPUNIT_ASSERT(!f.checkEvolve());
    }
    
    void testFredkinCheckEvolve3() {
    	FredkinCell f = FredkinCell();
    	f._c = '2';
    	CPPUNIT_ASSERT(f.checkEvolve());
    }
    
    
    void testFredkinClone1() {
    	FredkinCell f = FredkinCell();
    	FredkinCell* f2 = f.clone();
    	CPPUNIT_ASSERT((*f2)._c == '-');
    	delete f2;
    }
    
    void testFredkinClone2() {
    	FredkinCell f = FredkinCell();
    	FredkinCell* f2 = f.clone();
    	CPPUNIT_ASSERT((*f2)._age == 0);   
    	delete f2; 
    }
    
    void testFredkinClone3() {
    	FredkinCell f = FredkinCell(1,1,'0');
    	FredkinCell* f2 = f.clone();
    	CPPUNIT_ASSERT((*f2)._x == 1);    
    	CPPUNIT_ASSERT((*f2)._y == 1);        	
    	delete f2;
    }
    
    void testFredkinEvY1() {
    	FredkinCell f = FredkinCell(1,1,'-');
    	CPPUNIT_ASSERT(f.getEvolvex() == 1);  
    }
    
    void testFredkinEvY2() {
    	FredkinCell f = FredkinCell(2,1,'-');
    	CPPUNIT_ASSERT(f.getEvolvex() == 2); 
    }
    
    void testFredkinEvY3() {
    	FredkinCell f = FredkinCell(3,1,'-');
    	CPPUNIT_ASSERT(f.getEvolvex() == 3); 
    }
    void testFredkinEvX1() {
    	FredkinCell f = FredkinCell(1,1,'-');
    	CPPUNIT_ASSERT(f.getEvolvey() == 1); 
    }
    
    void testFredkinEvX2() {
    	FredkinCell f = FredkinCell(1,2,'-');
    	CPPUNIT_ASSERT(f.getEvolvey() == 2); 
    }
    
    void testFredkinEvX3() {
    	FredkinCell f = FredkinCell(1,3,'-');
    	CPPUNIT_ASSERT(f.getEvolvey() == 3); 
    }
    
    void testConwayCellD1() {
    	ConwayCell f = ConwayCell();
    	CPPUNIT_ASSERT(f._x == 0);
	CPPUNIT_ASSERT(f._y == 0);	
    }

    void testConwayCellD2() {
    	ConwayCell f = ConwayCell();	
	CPPUNIT_ASSERT(f._c=='.');
    }
    
    void testConwayCellD3() {
    	ConwayCell f = ConwayCell();
	CPPUNIT_ASSERT(f._alive == false);
    }
    
    void testConwayCell1() {
    	ConwayCell f = ConwayCell(0,0,'*');
    	CPPUNIT_ASSERT(f._x == 0);	
    }
    
    void testConwayCell2() {
    	ConwayCell f = ConwayCell(0,0,'*');
	CPPUNIT_ASSERT(f._c=='*');
	CPPUNIT_ASSERT(f._alive == true);    	    	
    }
    
    void testConwayCell3() {
    	ConwayCell f = ConwayCell(0,0,'*');
    	CPPUNIT_ASSERT(f._y == 0);
    }
    
    void testConwayUpdate1() {
    	vector<vector<ConwayCell> > v = vector<vector<ConwayCell> >(0);    	
    	v.resize(5);
    	for(int i = 0; i < 5; ++i) 
    		v[i].resize(1);
    	v[0][0] = ConwayCell(0,0,'*');
    	vector<vector<bool> > b = vector<vector<bool> >(0);    	
    	b.resize(5);
    	for(int i = 0; i < 5; ++i) 
    		b[i].resize(1);
    	b[0][0] = true;
    	Life<ConwayCell> L = Life<ConwayCell>(5,1,v); 
    	CPPUNIT_ASSERT(L._cells[0][0].update(b) == false);
    }
    
    void testConwayUpdate2() {
    	vector<vector<ConwayCell> > v = vector<vector<ConwayCell> >(0);    	
    	v.resize(5);
    	for(int i = 0; i < 5; ++i) 
    		v[i].resize(2);
    	v[0][0] = ConwayCell(0,0,'*');
    	vector<vector<bool> > b = vector<vector<bool> >(0);    	
    	b.resize(5);
    	for(int i = 0; i < 5; ++i) 
    		b[i].resize(2);
    	b[0][0] = true;
    	b[0][1] = true;
    	b[1][0] = true;
    	Life<ConwayCell> L = Life<ConwayCell>(5,2,v); 
    	CPPUNIT_ASSERT(L._cells[1][1].update(b) == true);
    }
    
    void testConwayUpdate3() {
    	vector<vector<ConwayCell> > v = vector<vector<ConwayCell> >(0);    	
    	v.resize(5);
    	for(int i = 0; i < 5; ++i) 
    		v[i].resize(2);
    	v[0][0] = ConwayCell(0,0,'*');
    	vector<vector<bool> > b = vector<vector<bool> >(0);    	
    	b.resize(5);
    	for(int i = 0; i < 5; ++i) 
    		b[i].resize(2);
    	b[0][0] = true;
    	b[0][1] = true;
    	b[1][0] = true;
    	Life<ConwayCell> L = Life<ConwayCell>(5,2,v); 
    	CPPUNIT_ASSERT(L._cells[0][0].update(b) == true);
    }
    
    void testConwayAlive1() {
    	ConwayCell f = ConwayCell();
    	CPPUNIT_ASSERT(!f.isAlive());
    }
    
    void testConwayAlive2() {
	ConwayCell f = ConwayCell(1,1,'.');
    	CPPUNIT_ASSERT(!f.isAlive());
    }
    
    void testConwayAlive3() {
 	ConwayCell f = ConwayCell(1,1,'*');
    	CPPUNIT_ASSERT(f.isAlive());
    }
    
    void testConwayCheckEvolve1() {
    	ConwayCell f = ConwayCell();
    	CPPUNIT_ASSERT(!f.checkEvolve());
    }
    
    void testConwayCheckEvolve2() {
    	ConwayCell f = ConwayCell(1,1,'.');
    	CPPUNIT_ASSERT(!f.checkEvolve());
    }
    
    void testConwayCheckEvolve3() {
    	ConwayCell f = ConwayCell(1,1,'*');
    	CPPUNIT_ASSERT(!f.checkEvolve());
    }
    
    
    void testConwayClone1() {
    	ConwayCell f = ConwayCell();
    	ConwayCell* f2 = f.clone();
    	CPPUNIT_ASSERT((*f2)._c == '.');
    	delete f2;
    }
    
    void testConwayClone2() {
    	ConwayCell f = ConwayCell(1,1,'*');
    	ConwayCell* f2 = f.clone();
    	CPPUNIT_ASSERT((*f2)._x == 1);     
    	delete f2;
    }
    
    void testConwayClone3() {
    	ConwayCell f = ConwayCell(1,1,'*');
    	ConwayCell* f2 = f.clone();    	   
    	CPPUNIT_ASSERT((*f2)._y == 1);    
    	delete f2;    	
    }
    
    void testConwayEvY1() {
    	ConwayCell f = ConwayCell(1,1,'*');
    	CPPUNIT_ASSERT(f.getEvolvex() == 1);  
    }
    
    void testConwayEvY2() {
    	ConwayCell f = ConwayCell(2,1,'*');
    	CPPUNIT_ASSERT(f.getEvolvex() == 2); 
    }
    
    void testConwayEvY3() {
    	ConwayCell f = ConwayCell(3,1,'*');
    	CPPUNIT_ASSERT(f.getEvolvex() == 3); 
    }
    void testConwayEvX1() {
    	ConwayCell f = ConwayCell(1,1,'*');
    	CPPUNIT_ASSERT(f.getEvolvey() == 1); 
    }
    
    void testConwayEvX2() {
    	ConwayCell f = ConwayCell(1,2,'*');
    	CPPUNIT_ASSERT(f.getEvolvey() == 2); 
    }
    
    void testConwayEvX3() {
    	ConwayCell f = ConwayCell(1,3,'*');
    	CPPUNIT_ASSERT(f.getEvolvey() == 3); 
    }
    
    
    
    
    
    
    
    
    
    
    
    void testCell1() {
    	Cell c = Cell();
    	CPPUNIT_ASSERT(c._p == 0);
    }
    
    void testCell2() {
    	Cell c = Cell();
    	CPPUNIT_ASSERT(c.get() == 0);
    }
    
    void testCell3() {
    	Cell c = Cell();
    	CPPUNIT_ASSERT(c._p == c.get());
    }
    
    void testCellUpdate1() {	
    	Cell c = Cell(new ConwayCell(0,0,'*'));
    	vector<vector<bool> > b = vector<vector<bool> >(0);    	
    	b.resize(5);
    	for(int i = 0; i < 5; ++i) 
    		b[i].resize(1);
    	b[0][0] = true;
	
    	CPPUNIT_ASSERT(c.update(b) == false);
    }
    
    void testCellUpdate2() {
    	Cell c = Cell(new ConwayCell(1,1,'*'));
    	vector<vector<bool> > b = vector<vector<bool> >(0);    	
    	b.resize(5);
    	for(int i = 0; i < 5; ++i) 
    		b[i].resize(2);
    	b[0][0] = true;
    	b[0][1] = true;
    	b[1][0] = true;    	
	
    	CPPUNIT_ASSERT(c.update(b) == true);
    }
    
    void testCellUpdate3() {
    	Cell c = Cell(new ConwayCell(0,0,'*'));
    	vector<vector<bool> > b = vector<vector<bool> >(0);    	
    	b.resize(5);
    	for(int i = 0; i < 5; ++i) 
    		b[i].resize(2);
    	b[0][0] = true;
    	b[0][1] = true;
    	b[1][0] = true;   
    	b[1][1] = true; 	
	
    	CPPUNIT_ASSERT(c.update(b) == true);
    }
    
    void testCellAlive1() {
    	Cell c = Cell(new ConwayCell(1,1,'*'));
    	CPPUNIT_ASSERT(c.isAlive());
    }
    
    void testCellAlive2() {
    	Cell c = Cell(new ConwayCell(1,1,'0'));
    	CPPUNIT_ASSERT(c.isAlive());
    }
    
    void testCellAlive3() {
    	Cell c = Cell(new ConwayCell(1,1,'.'));
    	CPPUNIT_ASSERT(!c.isAlive());
	Cell c2 = Cell(new ConwayCell(1,1,'-'));
    	CPPUNIT_ASSERT(!c2.isAlive());
    }
    
    void testCellEvolve1() {
    	Cell c = Cell(new ConwayCell(1,1,'*'));
    	CPPUNIT_ASSERT(!c.checkEvolve());
    }
    
    void testCellEvolve2() {
    	Cell c = Cell(new FredkinCell(1,1,'0'));
    	CPPUNIT_ASSERT(!c.checkEvolve());
    }
    
    void testCellEvolve3() {
    	Cell c = Cell(new FredkinCell(1,1,'2'));
    	CPPUNIT_ASSERT(c.checkEvolve());
    }
    
    
    
    
    
    
    
    
    void testAbstractCell1() {
    	AbstractCell* a = new ConwayCell();
    	CPPUNIT_ASSERT((*a)._x == 0);
	CPPUNIT_ASSERT((*a)._y == 0);
	CPPUNIT_ASSERT((*a)._c == '.');
	CPPUNIT_ASSERT(!(*a).isAlive());
	delete a;
    }
    
    void testAbstractCell2() {
    	AbstractCell* a = new FredkinCell();
    	CPPUNIT_ASSERT((*a)._x == 0);
	CPPUNIT_ASSERT((*a)._y == 0);
	CPPUNIT_ASSERT((*a)._c == '-');
	CPPUNIT_ASSERT(!(*a).isAlive());
	delete a;
    }
    
    void testAbstractCell3() {
    	AbstractCell* a = new FredkinCell();
    	AbstractCell* b = new ConwayCell();
    	CPPUNIT_ASSERT(a!=b);
    	delete a;
    	delete b;
    }		
    
    void testAbAlive1() {
    	AbstractCell* a = new ConwayCell();
    	CPPUNIT_ASSERT(!(*a).isAlive());
    	delete a;
    }
    
    void testAbAlive2() {
    	AbstractCell* a = new FredkinCell();
    	CPPUNIT_ASSERT(!(*a).isAlive());
    	delete a;
    }
    
    void testAbAlive3() {
    	AbstractCell* a = new ConwayCell(0,0,'*');
    	CPPUNIT_ASSERT((*a).isAlive());
    	delete a;
    }
    
    
    
    

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST(testLife1);
    CPPUNIT_TEST(testLife2);
    CPPUNIT_TEST(testLife3);
    CPPUNIT_TEST(testDoMoves1);
    CPPUNIT_TEST(testDoMoves2);
    CPPUNIT_TEST(testDoMoves3);
    
    
    CPPUNIT_TEST(testFredkinCellD1);
    CPPUNIT_TEST(testFredkinCellD2);
    CPPUNIT_TEST(testFredkinCellD3);        
    CPPUNIT_TEST(testFredkinCell1);
    CPPUNIT_TEST(testFredkinCell2);
    CPPUNIT_TEST(testFredkinCell3); 
    CPPUNIT_TEST(testFredkinUpdate1);
    CPPUNIT_TEST(testFredkinUpdate2);
    CPPUNIT_TEST(testFredkinUpdate3);
    CPPUNIT_TEST(testFredkinAlive1);
    CPPUNIT_TEST(testFredkinAlive2);
    CPPUNIT_TEST(testFredkinAlive3);
    CPPUNIT_TEST(testFredkinCheckEvolve1);
    CPPUNIT_TEST(testFredkinCheckEvolve2);
    CPPUNIT_TEST(testFredkinCheckEvolve3);
    CPPUNIT_TEST(testFredkinClone1);
    CPPUNIT_TEST(testFredkinClone2);
    CPPUNIT_TEST(testFredkinClone3);
    CPPUNIT_TEST(testFredkinEvY1);
    CPPUNIT_TEST(testFredkinEvY2);
    CPPUNIT_TEST(testFredkinEvY3);
    CPPUNIT_TEST(testFredkinEvX1);
    CPPUNIT_TEST(testFredkinEvX2);
    CPPUNIT_TEST(testFredkinEvX3);
    
    CPPUNIT_TEST(testConwayCellD1);
    CPPUNIT_TEST(testConwayCellD2);
    CPPUNIT_TEST(testConwayCellD3);        
    CPPUNIT_TEST(testConwayCell1);
    CPPUNIT_TEST(testConwayCell2);
    CPPUNIT_TEST(testConwayCell3); 
    CPPUNIT_TEST(testConwayUpdate1);
    CPPUNIT_TEST(testConwayUpdate2);
    CPPUNIT_TEST(testConwayUpdate3);
    CPPUNIT_TEST(testConwayAlive1);
    CPPUNIT_TEST(testConwayAlive2);
    CPPUNIT_TEST(testConwayAlive3);
    CPPUNIT_TEST(testConwayCheckEvolve1);
    CPPUNIT_TEST(testConwayCheckEvolve2);
    CPPUNIT_TEST(testConwayCheckEvolve3);
    CPPUNIT_TEST(testConwayClone1);
    CPPUNIT_TEST(testConwayClone2);
    CPPUNIT_TEST(testConwayClone3);
    CPPUNIT_TEST(testConwayEvY1);
    CPPUNIT_TEST(testConwayEvY2);
    CPPUNIT_TEST(testConwayEvY3);
    CPPUNIT_TEST(testConwayEvX1);
    CPPUNIT_TEST(testConwayEvX2);
    CPPUNIT_TEST(testConwayEvX3);
    
    
    
    CPPUNIT_TEST(testCell1);
    CPPUNIT_TEST(testCell2);
    CPPUNIT_TEST(testCell3);
    CPPUNIT_TEST(testCellUpdate1);
    CPPUNIT_TEST(testCellUpdate2);
    CPPUNIT_TEST(testCellUpdate3);
    CPPUNIT_TEST(testCellAlive1);
    CPPUNIT_TEST(testCellAlive2);
    CPPUNIT_TEST(testCellAlive3);
    CPPUNIT_TEST(testCellEvolve1);
    CPPUNIT_TEST(testCellEvolve2);
    CPPUNIT_TEST(testCellEvolve3);
    
    
    
    CPPUNIT_TEST(testAbstractCell1);
    CPPUNIT_TEST(testAbstractCell2);
    CPPUNIT_TEST(testAbstractCell3);
    CPPUNIT_TEST(testAbAlive1);
    CPPUNIT_TEST(testAbAlive2);
    CPPUNIT_TEST(testAbAlive3);
    
    
    
    CPPUNIT_TEST_SUITE_END();
};


// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);    // turn off synchronization with C I/O
    cout << "TestLife.c++" << endl;

    CppUnit::TextTestRunner tr;

    tr.addTest(TestLife::suite());

    tr.run();

    cout << "Done." << endl;
    return 0;}

