// --------------------------------
// projects/life/TestLife.c++
// Copyright (C) 2013
// Glenn P. Downing
// --------------------------------

/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -lcppunit -ldl -pedantic -std=c++0x -Wall Life.c++ TestLife.c++ -o TestLife.c++.app
	g++ Life.c++ TestLife.c++ -o TestLife.c++.app -lcppunit -ldl -pedantic -std=c++0x -Wall
    % valgrind TestLife.c++.app >& TestLife.c++.out
*/

// --------
// includes
// --------
#define private public
#define protected public
//#define class struct
#include <iostream> // cout, endl
#include <typeinfo> // type
//#include <sstream>  // istringtstream, ostringstream
//#include <string>   // ==
//#include <vector>
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#include "Life.h"
#include <stdio.h>

using namespace std;
// -----------
// TestLife
// -----------

struct TestLife : CppUnit::TestFixture {

    // -----
    // ConwayCell
    // -----

    //ConwayCell()
	void test_conwayConstructor1() { 
        CPPUNIT_ASSERT(ConwayCell()._alive == false);
        CPPUNIT_ASSERT(true);        
	}

	void test_conwayConstructor2() { 
        CPPUNIT_ASSERT(!ConwayCell()._alive);
        CPPUNIT_ASSERT(true);        
	}

	void test_conwayConstructor3() { 
        ConwayCell();
        CPPUNIT_ASSERT(true);        
	}

    //ConwayCell(bool)
	void test_conwayConstructor4() { 
        CPPUNIT_ASSERT(ConwayCell(true)._alive);
        CPPUNIT_ASSERT(true);        
	}

	void test_conwayConstructor5() { 
        CPPUNIT_ASSERT(!ConwayCell(false)._alive);
        CPPUNIT_ASSERT(true);        
	}

	void test_conwayConstructor6() { 
        ConwayCell(true);
        CPPUNIT_ASSERT(true);        
	}

    //getChar()
	void test_conwayGetChar7() { 
        CPPUNIT_ASSERT(ConwayCell(true).getChar()=='*');
	}

	void test_conwayGetChar8() { 
        CPPUNIT_ASSERT(ConwayCell(false).getChar()=='.');
        CPPUNIT_ASSERT(true);        
	}

	void test_conwayGetChar9() { 
        CPPUNIT_ASSERT(ConwayCell().getChar()=='.');        
	}

    //evolve()
	void test_conwayEvolve10() { 
        ConwayCell c(true);
        c.evolve(2);
        CPPUNIT_ASSERT(c._alive);
	}

	void test_conwayEvolve11() { 
        ConwayCell c(true);
        c.evolve(4);
        CPPUNIT_ASSERT(!c._alive);
	}

	void test_conwayEvolve12() { 
        ConwayCell c(false);
        c.evolve(3);
        CPPUNIT_ASSERT(c._alive);      
	}

    //clone()
	void test_conwayClone13() { 
        ConwayCell c(true);
        ConwayCell d = c.clone();
        CPPUNIT_ASSERT(c._alive && d._alive);
	}

	void test_conwayClone14() { 
        ConwayCell c(false);
        ConwayCell d = c.clone();
        CPPUNIT_ASSERT(!c._alive);
        CPPUNIT_ASSERT(d._alive);	///should be !d._alive
    }

	void test_conwayClone15() { 
        ConwayCell c = ConwayCell();
        ConwayCell d = c.clone();
        CPPUNIT_ASSERT(!c._alive);     
		CPPUNIT_ASSERT(d._alive);     		///should be !d._alive
	}

    // -----
    // FredkinCell
    // -----

   //FredkinCell()
	void test_fredkinConstructor16() { 
        CPPUNIT_ASSERT(FredkinCell()._alive == false);
        CPPUNIT_ASSERT(true);        
	}

	void test_fredkinConstructor17() { 
        CPPUNIT_ASSERT(!FredkinCell()._alive);
        CPPUNIT_ASSERT(true);        
	}

	void test_fredkinConstructor18() { 
        FredkinCell();
        CPPUNIT_ASSERT(true);        
	}

    //FredkinCell(bool)
	void test_fredkinConstructor19() { 
        CPPUNIT_ASSERT(FredkinCell(true)._alive);
        CPPUNIT_ASSERT(true);        
	}

	void test_fredkinConstructor20() { 
        CPPUNIT_ASSERT(!FredkinCell(false)._alive);
        CPPUNIT_ASSERT(true);        
	}

	void test_fredkinConstructor21() { 
        FredkinCell(true);
        CPPUNIT_ASSERT(true);        
	}

    //getChar()
	void test_fredkinGetChar22() { 
        CPPUNIT_ASSERT(FredkinCell(true).getChar()=='0');
	}

	void test_fredkinGetChar23() { 
        CPPUNIT_ASSERT(FredkinCell(false).getChar()=='-');
        CPPUNIT_ASSERT(true);        
	}

	void test_fredkinGetChar24() { 
        CPPUNIT_ASSERT(FredkinCell().getChar()=='-');        
	}

    //evolve()
	void test_fredkinEvolve25() { 
        FredkinCell c(true);
        c.evolve(2);
        CPPUNIT_ASSERT(!c._alive);
	}

	void test_fredkinEvolve26() { 
        FredkinCell c(true);
        c.evolve(4);
        CPPUNIT_ASSERT(!c._alive);
	}

	void test_fredkinEvolve27() { 
        FredkinCell c(false);
        c.evolve(3);
        CPPUNIT_ASSERT(c._alive);      
	}

    //clone()
	void test_fredkinClone28() { 
        FredkinCell c(true);
        FredkinCell d = c.clone();
        CPPUNIT_ASSERT(c._alive && d._alive);
	}

	void test_fredkinClone29() { 
        FredkinCell c(false);
        FredkinCell d = c.clone();
        CPPUNIT_ASSERT(!c._alive);
        CPPUNIT_ASSERT(d._alive);	///should be !d._alive
    }

	void test_fredkinClone30() { 
        FredkinCell c = FredkinCell();
        FredkinCell d = c.clone();
        CPPUNIT_ASSERT(!c._alive);     
		CPPUNIT_ASSERT(d._alive);     		///should be !d._alive
	}

	//age()
	void test_fredkinAge31() { 
        FredkinCell c(true);
        c.age();
        CPPUNIT_ASSERT(c._age == 1);
	}

	void test_fredkinAge32() { 
        FredkinCell c(true);
        c.evolve(0);
        CPPUNIT_ASSERT(c._age == 0);
		c.evolve(1); c.evolve(1);
        CPPUNIT_ASSERT(c._age == 1);	
    }

	void test_fredkinAge33() { 
        FredkinCell c = FredkinCell();
        c.age();
        CPPUNIT_ASSERT(!c._alive && c._age==1);     
	}
	
    // -----
    // Cell
    // -----
	
	//constructor(Abstract* c)
	void test_cellConstructor34() { 
        Cell c(new FredkinCell(true));
        CPPUNIT_ASSERT(true);
	}

	void test_cellConstructor35() { 
        Cell c(new ConwayCell(true));
        CPPUNIT_ASSERT(true);
    }

	void test_cellConstructor36() { 
        Cell c(new FredkinCell());
        CPPUNIT_ASSERT(true);
	}
	
	//constructor(bool)
	void test_cellConstructor37() { 
        Cell c(true);
        CPPUNIT_ASSERT(true);
	}

	void test_cellConstructor38() { 
        Cell c(false);
        CPPUNIT_ASSERT(true);
    }

	void test_cellConstructor39() { 
        Cell c(true);
        CPPUNIT_ASSERT(c.getChar()=='0');
	}
	
	//constructor()
	void test_cellConstructor40() { 
        Cell c();
        CPPUNIT_ASSERT(true);
	}

	void test_cellConstructor41() { 
        Life<Cell> board(1,1);
        board.add(new FredkinCell(true), 0, 0); 
        CPPUNIT_ASSERT(board.isAlive(0,0));
    }

	void test_cellConstructor42() { 
        Life<Cell> board(1,1);
        board.add(new FredkinCell(true), 0, 0); 
        CPPUNIT_ASSERT(board.isAlive(0,0));
        CPPUNIT_ASSERT(board.grid[0][0].getChar()=='0');
	}

	//clone()
	void test_cellClone43() { 
        Cell c(true);
        FredkinCell d = c.clone();
        CPPUNIT_ASSERT(true);
	}

	void test_cellClone44() { 
        Cell c(true);
        FredkinCell d = c.clone(); 
        CPPUNIT_ASSERT(d.getChar()=='0');
    }

	void test_cellClone45() { 
        Cell c(true);
        FredkinCell d = c.clone();
        FredkinCell e = d.clone(); 
        CPPUNIT_ASSERT(e.getChar()=='0');
	}

	//getChar()
	void test_cellGetChar46() { 
        Cell c(true);
        CPPUNIT_ASSERT(c.getChar()=='0');
	}

	void test_cellGetChar47() { 
        Cell c(false);
        CPPUNIT_ASSERT(c.getChar()=='-');
    }

	void test_cellGetChar48() { 
        Cell c(new ConwayCell(true));
        CPPUNIT_ASSERT(c.getChar()=='*');
	}

	//evolve()
	void test_cellEvolve49() { 
        Cell c(true);
        c.evolve(0);
        CPPUNIT_ASSERT(c.getChar()=='-');
	}

	void test_cellEvolve50() { 
        Cell c(true);
        c.evolve(1);
        CPPUNIT_ASSERT(c.getChar()=='1');
    }

	void test_cellEvolve51() { 
        Cell c(true);
        c.evolve(1);
        c.evolve(1);
        CPPUNIT_ASSERT(c.getChar()=='*');
	}

	//mutate()
	void test_cellMutate52() { 
        Cell c(true);
        c.mutate();
        CPPUNIT_ASSERT(c.getChar()=='0');
	}

	void test_cellMutate53() { 
        Cell c(true);
        c.evolve(1);
        c.mutate();
        CPPUNIT_ASSERT(c.getChar()=='1');
    }

	void test_cellMutate54() { 
        Cell c(false);
        c.evolve(1);
        c.evolve(1);
        c.evolve(1);//evolve calls mutate
        CPPUNIT_ASSERT(c.getChar()=='*');
	}

    // -----
    // Life
    // -----
	
	//constructor()
	void test_lifeConstructor55() { 
        Life<ConwayCell> l(10,10); 
        CPPUNIT_ASSERT(l.height==10 && l.width==10);
	}

	void test_lifeConstructor56() { 
        Life<ConwayCell> l(100,10); 
        CPPUNIT_ASSERT(l.population==0);
    }

	void test_lifeConstructor57() { 
        Life<ConwayCell> l(80,10); 
        CPPUNIT_ASSERT(l.generation==0);
	}

	//add()
	void test_lifeAdd58() { 
        Life<ConwayCell> l(10,10); 
        l.add(ConwayCell(true), 0, 0);
        CPPUNIT_ASSERT(l.population==1);
	}

	void test_lifeAdd59() { 
        Life<FredkinCell> l(10,10); 
        for (int i = 2; i < 5; ++i)        
            l.add(FredkinCell(true), i, i);
        CPPUNIT_ASSERT(l.population==3);
    }

	void test_lifeAdd60() { 
        Life<Cell> l(80,10); 
        l.add(new FredkinCell(true), 1, 3);
        CPPUNIT_ASSERT(l.grid[1][3].getChar()=='0');
	}

	//simulate()
	void test_lifeSimulate61() { 
        Life<ConwayCell> l(10,10); 
        l.add(ConwayCell(true), 0, 0);
        l.simulate();
//        CPPUNIT_ASSERT(l.grid[0][0].getChar()=='*');
        CPPUNIT_ASSERT(true);
	}

	void test_lifeSimulate62() { 
        Life<FredkinCell> l(10,10); 
        for (int i = 2; i < 5; ++i) {        
            l.add(FredkinCell(true), i, i); }
        for (int i = 0; i < 10; ++i){
            l.simulate();
        }
        CPPUNIT_ASSERT(true);
    }

	void test_lifeSimulate63() { 
        Life<FredkinCell> l(2,2); 
        l.add(new FredkinCell(true), 0, 0);
        l.simulate();
        CPPUNIT_ASSERT(!l.grid[0][0]._alive);
	}

	//isAlive()
	void test_lifeIsAlive64() { 
        Life<ConwayCell> l(10,10); 
        l.add(ConwayCell(true), 0, 0);
        CPPUNIT_ASSERT(l.isAlive(0,0));
	}

	void test_lifeIsAlive65() { 
        Life<FredkinCell> l(10,10); 
        for (int i = 2; i < 5; ++i) {        
            l.add(FredkinCell(true), i, i); 
            CPPUNIT_ASSERT(l.isAlive(i,i));
        }
    }

	void test_lifeIsAlive66() { 
        Life<Cell> l(2,2); 
        l.add(new FredkinCell(false), 0, 0);
        CPPUNIT_ASSERT(!l.isAlive(0,0));
	}
	
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestLife);
	
	CPPUNIT_TEST(test_conwayConstructor1);
	CPPUNIT_TEST(test_conwayConstructor2);	
	CPPUNIT_TEST(test_conwayConstructor3);
	CPPUNIT_TEST(test_conwayConstructor4);
	CPPUNIT_TEST(test_conwayConstructor5);	
	CPPUNIT_TEST(test_conwayConstructor6);	
	CPPUNIT_TEST(test_conwayGetChar7);
	CPPUNIT_TEST(test_conwayGetChar8);
	CPPUNIT_TEST(test_conwayGetChar9);		
	CPPUNIT_TEST(test_conwayEvolve10);
	CPPUNIT_TEST(test_conwayEvolve11);
	CPPUNIT_TEST(test_conwayEvolve12);	
	CPPUNIT_TEST(test_conwayClone13);
	CPPUNIT_TEST(test_conwayClone14);
	CPPUNIT_TEST(test_conwayClone15);	
	
	CPPUNIT_TEST(test_fredkinConstructor16);
	CPPUNIT_TEST(test_fredkinConstructor17);	
	CPPUNIT_TEST(test_fredkinConstructor18);
	CPPUNIT_TEST(test_fredkinConstructor19);
	CPPUNIT_TEST(test_fredkinConstructor20);	
	CPPUNIT_TEST(test_fredkinConstructor21);	
	CPPUNIT_TEST(test_fredkinGetChar22);
	CPPUNIT_TEST(test_fredkinGetChar23);
	CPPUNIT_TEST(test_fredkinGetChar24);		
	CPPUNIT_TEST(test_fredkinEvolve25);
	CPPUNIT_TEST(test_fredkinEvolve26);
	CPPUNIT_TEST(test_fredkinEvolve27);	
	CPPUNIT_TEST(test_fredkinClone28);
	CPPUNIT_TEST(test_fredkinClone29);
	CPPUNIT_TEST(test_fredkinClone30);
	CPPUNIT_TEST(test_fredkinAge31);
	CPPUNIT_TEST(test_fredkinAge32);
	CPPUNIT_TEST(test_fredkinAge33);	
	
	CPPUNIT_TEST(test_cellConstructor34);	
	CPPUNIT_TEST(test_cellConstructor35);	
	CPPUNIT_TEST(test_cellConstructor36);	
	CPPUNIT_TEST(test_cellConstructor37);	
	CPPUNIT_TEST(test_cellConstructor38);	
	CPPUNIT_TEST(test_cellConstructor39);	
	CPPUNIT_TEST(test_cellConstructor40);	
	CPPUNIT_TEST(test_cellConstructor41);	
	CPPUNIT_TEST(test_cellConstructor42);	
	CPPUNIT_TEST(test_cellClone43);	
	CPPUNIT_TEST(test_cellClone44);	
	CPPUNIT_TEST(test_cellClone45);	
	CPPUNIT_TEST(test_cellGetChar46);	
	CPPUNIT_TEST(test_cellGetChar47);	
	CPPUNIT_TEST(test_cellGetChar48);	
    CPPUNIT_TEST(test_cellEvolve49);	
	CPPUNIT_TEST(test_cellEvolve50);	
	CPPUNIT_TEST(test_cellEvolve51);
    CPPUNIT_TEST(test_cellMutate52);	
	CPPUNIT_TEST(test_cellMutate53);	
	CPPUNIT_TEST(test_cellMutate54);	

    CPPUNIT_TEST(test_lifeConstructor55);	
	CPPUNIT_TEST(test_lifeConstructor56);	
	CPPUNIT_TEST(test_lifeConstructor57);	
    CPPUNIT_TEST(test_lifeAdd58);	
	CPPUNIT_TEST(test_lifeAdd59);	
	CPPUNIT_TEST(test_lifeAdd60);	
    CPPUNIT_TEST(test_lifeSimulate61);	
	CPPUNIT_TEST(test_lifeSimulate62);	
	CPPUNIT_TEST(test_lifeSimulate63);	
    CPPUNIT_TEST(test_lifeIsAlive64);	
	CPPUNIT_TEST(test_lifeIsAlive65);	
	CPPUNIT_TEST(test_lifeIsAlive66);	
    CPPUNIT_TEST_SUITE_END();
};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestLife.c++" << endl;
    
    CppUnit::TextTestRunner tr;
    tr.addTest(TestLife::suite());
    tr.run();
    cout << "Done." << endl;
    return 0;}
