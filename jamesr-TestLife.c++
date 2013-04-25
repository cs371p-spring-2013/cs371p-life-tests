#include <iostream> // cout, endl
#include <sstream> // istringtstream, ostringstream
#include <string> // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TextTestRunner

#define protected public
#define private public
#define class struct
#define dead false
#define alive true

#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#include "Handle.h"

// -----------
// TestLife
// -----------

struct TestLife : CppUnit::TestFixture {
    

    // -----
    // suite
    // -----

    //---------------------------------
    // Test ConwayCells
    //---------------------------------
    void test_Conway_Constructor_1(){
        ConwayCell c(alive);
        CPPUNIT_ASSERT(c._alive == true);
        CPPUNIT_ASSERT(c._state == '*');
    }
    void test_Conway_Constructor_2(){
        ConwayCell c(dead);
        CPPUNIT_ASSERT(c._alive == false);
        CPPUNIT_ASSERT(c._state == '.');
    }
    void test_Conway_Constructor_3(){
        ConwayCell c;
        CPPUNIT_ASSERT(c._alive == false);
        CPPUNIT_ASSERT(c._state == '.');
    }
    void test_Conway_Evolve_1(){
        ConwayCell c(alive);
        int result = c.evolve(1);
        CPPUNIT_ASSERT(c._alive == false);
        CPPUNIT_ASSERT(c._state == '.');
        CPPUNIT_ASSERT(result == -1);
    }
    void test_Conway_Evolve_2(){
        ConwayCell c(alive);
        int result = c.evolve(2);
        CPPUNIT_ASSERT(c._alive == true);
        CPPUNIT_ASSERT(c._state == '*');
        CPPUNIT_ASSERT(result == 0);
    }
    void test_Conway_Evolve_3(){
        ConwayCell c(alive);
        int result = c.evolve(3);
        CPPUNIT_ASSERT(c._alive == true);
        CPPUNIT_ASSERT(c._state == '*');
        CPPUNIT_ASSERT(result == 0);
    }
    void test_Conway_Evolve_4(){
        ConwayCell c(alive);
        int result = c.evolve(4);
        CPPUNIT_ASSERT(c._alive == false);
        CPPUNIT_ASSERT(c._state == '.');
        CPPUNIT_ASSERT(result == -1);
    }
    void test_Conway_Evolve_5(){
        ConwayCell c(dead);
        int result = c.evolve(3);
        CPPUNIT_ASSERT(c._alive == true);
        CPPUNIT_ASSERT(c._state == '*');
        CPPUNIT_ASSERT(result == 1);
    }
    void test_Conway_Evolve_6(){
        ConwayCell c(dead);
        int result = c.evolve(2);
        CPPUNIT_ASSERT(c._alive == false);
        CPPUNIT_ASSERT(c._state == '.');
        CPPUNIT_ASSERT(result == 0);
    }
    void test_Conway_Evolve_7(){
        ConwayCell c(dead);
        int result = c.evolve(4);
        CPPUNIT_ASSERT(c._alive == false);
        CPPUNIT_ASSERT(c._state == '.');
        CPPUNIT_ASSERT(result == 0);
    }
    void test_Conway_CharRep_1(){
        ConwayCell c(alive);
        char result = c.charRep();
        CPPUNIT_ASSERT(result == '*');
    }
    void test_Conway_CharRep_2(){
        ConwayCell c(dead);
        char result = c.charRep();
        CPPUNIT_ASSERT(result == '.');
    }
    
    //----------------------------------
    // Test FredkinCells
    //----------------------------------
    void test_Fredkin_Constructor_1(){
        FredkinCell c(alive);
        CPPUNIT_ASSERT(c._alive == true);
        CPPUNIT_ASSERT(c._state == '0');
    }
    void test_Fredkin_Constructor_2(){
        FredkinCell c(dead);
        CPPUNIT_ASSERT(c._alive == false);
        CPPUNIT_ASSERT(c._state == '-');
    }
    void test_Fredkin_Constructor_3(){
        FredkinCell c;
        CPPUNIT_ASSERT(c._alive == false);
        CPPUNIT_ASSERT(c._state == '-');
    }
    
    void test_Fredkin_Evolve_1(){
        FredkinCell c(alive);
        int result = c.evolve(0);
        CPPUNIT_ASSERT(c._alive == false);
        CPPUNIT_ASSERT(c._state == '-');
        CPPUNIT_ASSERT(c._age == 0);
        CPPUNIT_ASSERT(result == -1);
    }
    void test_Fredkin_Evolve_2(){
        FredkinCell c(alive);
        int result = c.evolve(2);
        CPPUNIT_ASSERT(c._alive == false);
        CPPUNIT_ASSERT(c._state == '-');
        CPPUNIT_ASSERT(c._age == 0);
        CPPUNIT_ASSERT(result == -1);
    }
    void test_Fredkin_Evolve_3(){
        FredkinCell c(alive);
        int result = c.evolve(4);
        CPPUNIT_ASSERT(c._alive == false);
        CPPUNIT_ASSERT(c._state == '-');
        CPPUNIT_ASSERT(c._age == 0);
        CPPUNIT_ASSERT(result == -1);
    }
    void test_Fredkin_Evolve_4(){
        FredkinCell c(alive);
        int result = c.evolve(6);
        CPPUNIT_ASSERT(c._alive == true);
        CPPUNIT_ASSERT(c._state == '1');
        CPPUNIT_ASSERT(c._age == 1);
        CPPUNIT_ASSERT(result == 0);
    }
    void test_Fredkin_Evolve_5(){
        FredkinCell c(alive);
        int result = c.evolve(6);
        CPPUNIT_ASSERT(c._alive == true);
        CPPUNIT_ASSERT(c._state == '1');
        CPPUNIT_ASSERT(c._age == 1);
        CPPUNIT_ASSERT(result == 0);
        c.evolve(8);
        CPPUNIT_ASSERT(c._alive == true);
        CPPUNIT_ASSERT(c._state == '2');
        CPPUNIT_ASSERT(c._age == 2);
    }
    void test_Fredkin_Evolve_6(){
        FredkinCell c(alive);
        int result = c.evolve(6);
        CPPUNIT_ASSERT(c._alive == true);
        CPPUNIT_ASSERT(c._state == '1');
        CPPUNIT_ASSERT(c._age == 1);
        CPPUNIT_ASSERT(result == 0);
        c.evolve(2);
        CPPUNIT_ASSERT(c._alive == false);
        CPPUNIT_ASSERT(c._state == '-');
        CPPUNIT_ASSERT(c._age == 1);
        c.evolve(3);
        CPPUNIT_ASSERT(c._alive == true);
        CPPUNIT_ASSERT(c._state == '1');
        CPPUNIT_ASSERT(c._age == 1);
    }
    void test_Fredkin_Evolve_7(){
        FredkinCell c(dead);
        int result = c.evolve(1);
        CPPUNIT_ASSERT(c._alive == true);
        CPPUNIT_ASSERT(c._state == '0');
        CPPUNIT_ASSERT(c._age == 0);
        CPPUNIT_ASSERT(result == 1);
    }
    void test_Fredkin_Evolve_8(){
        FredkinCell c(dead);
        int result = c.evolve(3);
        CPPUNIT_ASSERT(c._alive == true);
        CPPUNIT_ASSERT(c._state == '0');
        CPPUNIT_ASSERT(c._age == 0);
        CPPUNIT_ASSERT(result == 1);
    }
    void test_Fredkin_Evolve_9(){
        FredkinCell c(alive);
        c._age = 8;
        int result = c.evolve(8);
        CPPUNIT_ASSERT(c._alive == true);
        CPPUNIT_ASSERT(c._state == '9');
        CPPUNIT_ASSERT(c._age == 9);
        CPPUNIT_ASSERT(result == 0);
        result = c.evolve(8);
        CPPUNIT_ASSERT(c._alive == true);
        CPPUNIT_ASSERT(c._state == '+');
        CPPUNIT_ASSERT(c._age == 10);
        CPPUNIT_ASSERT(result == 0);
    }
    
    void test_Fredkin_CharRep_1(){
        FredkinCell c(alive);
        char result = c.charRep();
        CPPUNIT_ASSERT(result == '0');
    }
    void test_Fredkin_CharRep_2(){
        FredkinCell c(dead);
        char result = c.charRep();
        CPPUNIT_ASSERT(result == '-');
    }
    
    //---------------------------------
    // TestLife
    //---------------------------------
    
    void test_Life_Constructor_1(){
        Life<ConwayCell> grid(5,5);
        CPPUNIT_ASSERT(grid._numRow == 5);
        CPPUNIT_ASSERT(grid._numCol == 5);
        CPPUNIT_ASSERT(grid._population == 0);
        CPPUNIT_ASSERT(grid._generation == 0);
    }
    void test_Life_Constructor_2(){
        Life<FredkinCell> grid(5,5);
        CPPUNIT_ASSERT(grid._numRow == 5);
        CPPUNIT_ASSERT(grid._numCol == 5);
        CPPUNIT_ASSERT(grid._population == 0);
        CPPUNIT_ASSERT(grid._generation == 0);
    }
    void test_Life_Constructor_3(){
        Life<Cell> grid(5,5);
        CPPUNIT_ASSERT(grid._numRow == 5);
        CPPUNIT_ASSERT(grid._numCol == 5);
        CPPUNIT_ASSERT(grid._population == 0);
        CPPUNIT_ASSERT(grid._generation == 0);
    }
        
    void test_Life_isAlive_1(){
    	Life<Cell> grid(5,5);
        CPPUNIT_ASSERT(grid.isAlive('*'));
        CPPUNIT_ASSERT(grid.isAlive('+'));
        CPPUNIT_ASSERT(grid.isAlive('0'));
        CPPUNIT_ASSERT(grid.isAlive('1'));
        CPPUNIT_ASSERT(grid.isAlive('2'));
        CPPUNIT_ASSERT(grid.isAlive('3'));
        CPPUNIT_ASSERT(grid.isAlive('4'));
        CPPUNIT_ASSERT(grid.isAlive('5'));
        CPPUNIT_ASSERT(grid.isAlive('6'));
        CPPUNIT_ASSERT(grid.isAlive('7'));
        CPPUNIT_ASSERT(grid.isAlive('8'));
        CPPUNIT_ASSERT(grid.isAlive('9'));
    }
    void test_Life_isAlive_2(){
    	Life<Cell> grid(5,5);
        CPPUNIT_ASSERT(!grid.isAlive('.'));
        CPPUNIT_ASSERT(!grid.isAlive('-'));
        CPPUNIT_ASSERT(!grid.isAlive('j'));
    }
    void test_Life_addCell_1(){
    	Life<ConwayCell> grid(4,4);
    	ConwayCell c(alive);
    	grid.addCell(c,0,0,'*');
    	CPPUNIT_ASSERT(grid._grid[0][0]._alive == true);
    }
    void test_Life_addCell_2(){
    	Life<ConwayCell> grid(4,4);
    	ConwayCell c(alive);
    	grid.addCell(c,1,3,'*');
    	CPPUNIT_ASSERT(grid._grid[1][3]._alive == true);
    }
    void test_Life_addCell_3(){
    	Life<ConwayCell> grid(4,4);
    	ConwayCell c(dead);
    	grid.addCell(c,0,0,'.');
    	CPPUNIT_ASSERT(grid._grid[0][0]._alive == false);
    }
    
    void test_Life_numberOfNeighborsAlive_1(){
    	Life<ConwayCell> grid(4,4);
    	for(int i=0;i<4;++i){
    		for(int j=0;j<4;++j){
    			if(j == 1){
    				ConwayCell c(alive);
    				grid.addCell(c,i,j,'*');
    			}
    			else{
    				ConwayCell c(dead);
    				grid.addCell(c,i,j,'.');
    			}
    		}
    	}
    	CPPUNIT_ASSERT(grid._grid[0][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[1][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[0][0]._alive == false);
    	CPPUNIT_ASSERT(grid.numberOfNeighborsAlive(0,1) == 1);
    	CPPUNIT_ASSERT(grid.numberOfNeighborsAlive(0,0) == 2);
    	CPPUNIT_ASSERT(grid.numberOfNeighborsAlive(1,0) == 3);
    }
    void test_Life_numberOfNeighborsAlive_2(){
    	Life<ConwayCell> grid(4,4);
    	for(int i=0;i<4;++i){
    		for(int j=0;j<4;++j){
    			if(j == 1 || j ==3){
    				ConwayCell c(alive);
    				grid.addCell(c,i,j,'*');
    			}
    			else{
    				ConwayCell c(dead);
    				grid.addCell(c,i,j,'.');
    			}
    		}
    	}
    	CPPUNIT_ASSERT(grid._grid[0][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[1][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[0][0]._alive == false);
    	CPPUNIT_ASSERT(grid.numberOfNeighborsAlive(0,1) == 1);
    	CPPUNIT_ASSERT(grid.numberOfNeighborsAlive(0,0) == 2);
    	CPPUNIT_ASSERT(grid.numberOfNeighborsAlive(1,0) == 3);
    	CPPUNIT_ASSERT(grid.numberOfNeighborsAlive(0,2) == 4);
    	CPPUNIT_ASSERT(grid.numberOfNeighborsAlive(1,2) == 6);
    }
    void test_Life_numberOfNeighborsAlive_3(){
    	Life<ConwayCell> grid(4,4);
    	for(int i=0;i<4;++i){
    		for(int j=0;j<4;++j){
    			if(i == 0 || j == 0){
    				ConwayCell c(alive);
    				grid.addCell(c,i,j,'*');
    			}
    			else{
    				ConwayCell c(dead);
    				grid.addCell(c,i,j,'.');
    			}
    		}
    	}
    	CPPUNIT_ASSERT(grid._grid[0][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[1][1]._alive == false);
    	CPPUNIT_ASSERT(grid._grid[0][0]._alive == true);
    	CPPUNIT_ASSERT(grid.numberOfNeighborsAlive(0,1) == 3);
    	CPPUNIT_ASSERT(grid.numberOfNeighborsAlive(0,0) == 2);
    	CPPUNIT_ASSERT(grid.numberOfNeighborsAlive(1,0) == 3);
    	CPPUNIT_ASSERT(grid.numberOfNeighborsAlive(0,2) == 2);
    	CPPUNIT_ASSERT(grid.numberOfNeighborsAlive(1,1) == 5);
    }
    void test_Life_increasePopulation_1(){
    	Life<ConwayCell> grid(4,4);
    	CPPUNIT_ASSERT(grid._population == 0);
    	grid.increasePopulation();
    	CPPUNIT_ASSERT(grid._population == 1);
    }
    void test_Life_print_1(){
    	Life<ConwayCell> grid(4,4);
    	for(int i=0;i<4;++i){
    		for(int j=0;j<4;++j){
    			if(j == 1){
    				ConwayCell c(alive);
    				grid.addCell(c,i,j,'*');
    				grid.increasePopulation();
    			}
    			else{
    				ConwayCell c(dead);
    				grid.addCell(c,i,j,'.');
    			}
    		}
    	}
    	CPPUNIT_ASSERT(grid._grid[0][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[1][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[0][0]._alive == false);
    	ostringstream o;
        grid.print(o);
        CPPUNIT_ASSERT(o.str() == 
            "Generation = 0, Population = 4.\n.*..\n.*..\n.*..\n.*..\n\n");
    }
   	void test_Life_print_2(){
    	Life<ConwayCell> grid(4,4);
    	for(int i=0;i<4;++i){
    		for(int j=0;j<4;++j){
    			if(j == 1 || j ==3){
    				ConwayCell c(alive);
    				grid.addCell(c,i,j,'*');
    				grid.increasePopulation();
    			}
    			else{
    				ConwayCell c(dead);
    				grid.addCell(c,i,j,'.');
    			}
    		}
    	}
    	CPPUNIT_ASSERT(grid._grid[0][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[1][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[0][0]._alive == false);
    	ostringstream o;
        grid.print(o);
        CPPUNIT_ASSERT(o.str() == 
            "Generation = 0, Population = 8.\n"
            ".*.*\n"
            ".*.*\n"
            ".*.*\n"
            ".*.*\n\n");
    }
    void test_Life_print_3(){
    	Life<ConwayCell> grid(4,4);
    	for(int i=0;i<4;++i){
    		for(int j=0;j<4;++j){
    			if(i == 0 || j == 0){
    				ConwayCell c(alive);
    				grid.addCell(c,i,j,'*');
    				grid.increasePopulation();
    			}
    			else{
    				ConwayCell c(dead);
    				grid.addCell(c,i,j,'.');
    			}
    		}
    	}
    	CPPUNIT_ASSERT(grid._grid[0][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[1][1]._alive == false);
    	CPPUNIT_ASSERT(grid._grid[0][0]._alive == true);
    	ostringstream o;
        grid.print(o);
        CPPUNIT_ASSERT(o.str() == 
            "Generation = 0, Population = 7.\n"
            "****\n"
            "*...\n"
            "*...\n"
            "*...\n\n");
    }
    void test_Life_printCharMap_1(){
    	Life<ConwayCell> grid(4,4);
    	for(int i=0;i<4;++i){
    		for(int j=0;j<4;++j){
    			if(j == 1){
    				ConwayCell c(alive);
    				grid.addCell(c,i,j,'*');
    				grid.increasePopulation();
    			}
    			else{
    				ConwayCell c(dead);
    				grid.addCell(c,i,j,'.');
    			}
    		}
    	}
    	CPPUNIT_ASSERT(grid._grid[0][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[1][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[0][0]._alive == false);
    	ostringstream o;
        grid.printCharMap(o);
        CPPUNIT_ASSERT(o.str() == 
            "Generation = 0, Population = 4.\n.*..\n.*..\n.*..\n.*..\n\n");
    }
   	void test_Life_printCharMap_2(){
    	Life<ConwayCell> grid(4,4);
    	for(int i=0;i<4;++i){
    		for(int j=0;j<4;++j){
    			if(j == 1 || j ==3){
    				ConwayCell c(alive);
    				grid.addCell(c,i,j,'*');
    				grid.increasePopulation();
    			}
    			else{
    				ConwayCell c(dead);
    				grid.addCell(c,i,j,'.');
    			}
    		}
    	}
    	CPPUNIT_ASSERT(grid._grid[0][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[1][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[0][0]._alive == false);
    	ostringstream o;
        grid.print(o);
        CPPUNIT_ASSERT(o.str() == 
            "Generation = 0, Population = 8.\n"
            ".*.*\n"
            ".*.*\n"
            ".*.*\n"
            ".*.*\n\n");
    }
    void test_Life_printCharMap_3(){
    	Life<ConwayCell> grid(4,4);
    	for(int i=0;i<4;++i){
    		for(int j=0;j<4;++j){
    			if(i == 0 || j == 0){
    				ConwayCell c(alive);
    				grid.addCell(c,i,j,'*');
    				grid.increasePopulation();
    			}
    			else{
    				ConwayCell c(dead);
    				grid.addCell(c,i,j,'.');
    			}
    		}
    	}
    	CPPUNIT_ASSERT(grid._grid[0][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[1][1]._alive == false);
    	CPPUNIT_ASSERT(grid._grid[0][0]._alive == true);
    	ostringstream o;
        grid.print(o);
        CPPUNIT_ASSERT(o.str() == 
            "Generation = 0, Population = 7.\n"
            "****\n"
            "*...\n"
            "*...\n"
            "*...\n\n");
    }
    void test_Life_updateCharMap_1(){
    	Life<FredkinCell> grid(4,4);
    	for(int i=0;i<4;++i){
    		for(int j=0;j<4;++j){
    			if(j == 1){
    				FredkinCell c(alive);
    				grid.addCell(c,i,j,'0');
    				grid.increasePopulation();
    			}
    			else{
    				FredkinCell c(dead);
    				grid.addCell(c,i,j,'-');
    			}
    		}
    	}
    	CPPUNIT_ASSERT(grid._grid[0][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[1][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[0][0]._alive == false);
    	grid._grid[0][1].evolve(1);
    	ostringstream o;
        grid.printCharMap(o);
        CPPUNIT_ASSERT(o.str() == 
            "Generation = 0, Population = 4.\n"
            "-0--\n"
            "-0--\n"
            "-0--\n"
            "-0--\n\n");
        grid.updateCharMap();
        o.str("");
		o.clear();
        grid.printCharMap(o);
        CPPUNIT_ASSERT(o.str() == 
            "Generation = 0, Population = 4.\n"
            "-1--\n"
            "-0--\n"
            "-0--\n"
            "-0--\n\n");
    }
    void test_Life_updateCharMap_2(){
    	Life<FredkinCell> grid(4,4);
    	for(int i=0;i<4;++i){
    		for(int j=0;j<4;++j){
    			if(j == 1 || j == 3){
    				FredkinCell c(alive);
    				grid.addCell(c,i,j,'0');
    				grid.increasePopulation();
    			}
    			else{
    				FredkinCell c(dead);
    				grid.addCell(c,i,j,'-');
    			}
    		}
    	}
    	CPPUNIT_ASSERT(grid._grid[0][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[1][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[0][0]._alive == false);
    	grid._grid[0][1].evolve(1);
    	ostringstream o;
        grid.printCharMap(o);
        CPPUNIT_ASSERT(o.str() == 
            "Generation = 0, Population = 8.\n"
            "-0-0\n"
            "-0-0\n"
            "-0-0\n"
            "-0-0\n\n");
        grid.updateCharMap();
        o.str("");
		o.clear();
        grid.printCharMap(o);
        CPPUNIT_ASSERT(o.str() == 
            "Generation = 0, Population = 8.\n"
            "-1-0\n"
            "-0-0\n"
            "-0-0\n"
            "-0-0\n\n");
    }
    void test_Life_updateCharMap_3(){
    	Life<FredkinCell> grid(4,4);
    	for(int i=0;i<4;++i){
    		for(int j=0;j<4;++j){
    			if(j == 0 || i == 0){
    				FredkinCell c(alive);
    				grid.addCell(c,i,j,'0');
    				grid.increasePopulation();
    			}
    			else{
    				FredkinCell c(dead);
    				grid.addCell(c,i,j,'-');
    			}
    		}
    	}
    	CPPUNIT_ASSERT(grid._grid[0][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[1][1]._alive == false);
    	CPPUNIT_ASSERT(grid._grid[0][0]._alive == true);
    	grid._grid[0][1].evolve(1);
    	ostringstream o;
        grid.printCharMap(o);
        CPPUNIT_ASSERT(o.str() == 
            "Generation = 0, Population = 7.\n"
            "0000\n"
            "0---\n"
            "0---\n"
            "0---\n\n");
        grid.updateCharMap();
        o.str("");
		o.clear();
        grid.printCharMap(o);
        CPPUNIT_ASSERT(o.str() == 
            "Generation = 0, Population = 7.\n"
            "0100\n"
            "0---\n"
            "0---\n"
            "0---\n\n");
    }
    
    void test_Life_simulate_1(){
    	Life<FredkinCell> grid(4,4);
    	for(int i=0;i<4;++i){
    		for(int j=0;j<4;++j){
    			if(j == 1){
    				FredkinCell c(alive);
    				grid.addCell(c,i,j,'0');
    				grid.increasePopulation();
    			}
    			else{
    				FredkinCell c(dead);
    				grid.addCell(c,i,j,'-');
    			}
    		}
    	}
    	CPPUNIT_ASSERT(grid._grid[0][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[1][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[0][0]._alive == false);
    	ostringstream o;
        grid.printCharMap(o);
        CPPUNIT_ASSERT(o.str() == 
            "Generation = 0, Population = 4.\n"
            "-0--\n"
            "-0--\n"
            "-0--\n"
            "-0--\n\n");
        grid.simulate(1);
        o.str("");
		o.clear();
        grid.printCharMap(o);
        CPPUNIT_ASSERT(o.str() == 
            "Generation = 1, Population = 10.\n"
            "010-\n"
            "0-0-\n"
            "0-0-\n"
            "010-\n\n");
    }
    void test_Life_simulate_2(){
    	Life<FredkinCell> grid(4,4);
    	for(int i=0;i<4;++i){
    		for(int j=0;j<4;++j){
    			if(j == 1 || j == 3){
    				FredkinCell c(alive);
    				grid.addCell(c,i,j,'0');
    				grid.increasePopulation();
    			}
    			else{
    				FredkinCell c(dead);
    				grid.addCell(c,i,j,'-');
    			}
    		}
    	}
    	CPPUNIT_ASSERT(grid._grid[0][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[1][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[0][0]._alive == false);
    	ostringstream o;
        grid.printCharMap(o);
        CPPUNIT_ASSERT(o.str() == 
            "Generation = 0, Population = 8.\n"
            "-0-0\n"
            "-0-0\n"
            "-0-0\n"
            "-0-0\n\n");
        grid.simulate(1);
        o.str("");
		o.clear();
        grid.printCharMap(o);
        CPPUNIT_ASSERT(o.str() == 
            "Generation = 1, Population = 8.\n"
            "01-1\n"
            "0---\n"
            "0---\n"
            "01-1\n\n");
    }
    void test_Life_simulate_3(){
    	Life<FredkinCell> grid(4,4);
    	for(int i=0;i<4;++i){
    		for(int j=0;j<4;++j){
    			if(j == 0 || i == 0){
    				FredkinCell c(alive);
    				grid.addCell(c,i,j,'0');
    				grid.increasePopulation();
    			}
    			else{
    				FredkinCell c(dead);
    				grid.addCell(c,i,j,'-');
    			}
    		}
    	}
    	CPPUNIT_ASSERT(grid._grid[0][1]._alive == true);
    	CPPUNIT_ASSERT(grid._grid[1][1]._alive == false);
    	CPPUNIT_ASSERT(grid._grid[0][0]._alive == true);
    	ostringstream o;
        grid.printCharMap(o);
        CPPUNIT_ASSERT(o.str() == 
            "Generation = 0, Population = 7.\n"
            "0000\n"
            "0---\n"
            "0---\n"
            "0---\n\n");
        grid.simulate(1);
        o.str("");
		o.clear();
        grid.printCharMap(o);
        CPPUNIT_ASSERT(o.str() == 
            "Generation = 1, Population = 6.\n"
            "---1\n"
            "--00\n"
            "-0--\n"
            "10--\n\n");
    }
    
    
    
    
    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST(test_Conway_Constructor_1);
    CPPUNIT_TEST(test_Conway_Constructor_2);
    CPPUNIT_TEST(test_Conway_Constructor_3);
    CPPUNIT_TEST(test_Conway_Evolve_1);
    CPPUNIT_TEST(test_Conway_Evolve_2);
    CPPUNIT_TEST(test_Conway_Evolve_3);
    CPPUNIT_TEST(test_Conway_Evolve_4);
    CPPUNIT_TEST(test_Conway_Evolve_5);
    CPPUNIT_TEST(test_Conway_Evolve_6);
    CPPUNIT_TEST(test_Conway_Evolve_7);
    CPPUNIT_TEST(test_Conway_CharRep_1);
    CPPUNIT_TEST(test_Conway_CharRep_2);
    
    CPPUNIT_TEST(test_Fredkin_Constructor_1);
    CPPUNIT_TEST(test_Fredkin_Constructor_2);
    CPPUNIT_TEST(test_Fredkin_Constructor_3);
    CPPUNIT_TEST(test_Fredkin_Evolve_1);
    CPPUNIT_TEST(test_Fredkin_Evolve_2);
    CPPUNIT_TEST(test_Fredkin_Evolve_3);
    CPPUNIT_TEST(test_Fredkin_Evolve_4);
    CPPUNIT_TEST(test_Fredkin_Evolve_5);
    CPPUNIT_TEST(test_Fredkin_Evolve_6);
    CPPUNIT_TEST(test_Fredkin_Evolve_7);
    CPPUNIT_TEST(test_Fredkin_Evolve_8);
    CPPUNIT_TEST(test_Fredkin_Evolve_9);
    CPPUNIT_TEST(test_Fredkin_CharRep_1);
    CPPUNIT_TEST(test_Fredkin_CharRep_2);
    
    CPPUNIT_TEST(test_Life_Constructor_1);
    CPPUNIT_TEST(test_Life_Constructor_2);
    CPPUNIT_TEST(test_Life_Constructor_3);
    CPPUNIT_TEST(test_Life_isAlive_1);
    CPPUNIT_TEST(test_Life_isAlive_2);
    CPPUNIT_TEST(test_Life_addCell_1);
    CPPUNIT_TEST(test_Life_addCell_2);
    CPPUNIT_TEST(test_Life_addCell_3);
    CPPUNIT_TEST(test_Life_numberOfNeighborsAlive_1);
    CPPUNIT_TEST(test_Life_numberOfNeighborsAlive_2);
    CPPUNIT_TEST(test_Life_numberOfNeighborsAlive_3);
    CPPUNIT_TEST(test_Life_increasePopulation_1);
    CPPUNIT_TEST(test_Life_print_1);
    CPPUNIT_TEST(test_Life_print_2);
    CPPUNIT_TEST(test_Life_print_3);
    CPPUNIT_TEST(test_Life_printCharMap_1);
    CPPUNIT_TEST(test_Life_printCharMap_2);
    CPPUNIT_TEST(test_Life_printCharMap_3);
    CPPUNIT_TEST(test_Life_updateCharMap_1);
    CPPUNIT_TEST(test_Life_updateCharMap_2);
    CPPUNIT_TEST(test_Life_updateCharMap_3);
    CPPUNIT_TEST(test_Life_simulate_1);
    CPPUNIT_TEST(test_Life_simulate_2);
    CPPUNIT_TEST(test_Life_simulate_3);
    CPPUNIT_TEST_SUITE_END();
};

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
    return 0;
}
