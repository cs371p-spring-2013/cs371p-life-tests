// --------
// includes
// --------

#include <algorithm> // count
#include <iostream>  // ios_base
#include <memory>    // allocator
#include <stdio.h>
#include <string>
#include <string.h>
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TestRunner
#include <sstream>
#include "Life.h"
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"
#define protected public
#define private public
#define class struct


struct TestLife : CppUnit::TestFixture {
    
void testlife_1(){
    Life<ConwayCell> a(10, 10);
    CPPUNIT_ASSERT(a.cells.size() == 12);
    CPPUNIT_ASSERT(a.cells[0].size() == 12);
}

void testlife_2(){
    Life<ConwayCell> a(10, 10);
    CPPUNIT_ASSERT(a.generation == 0);
    CPPUNIT_ASSERT(a.population == 0);
}

void testlife_3(){
    Life<ConwayCell> a(10, 10);
    a.pushcell(ConwayCell('.'), 1, 1);
    CPPUNIT_ASSERT(a.population == 0);
    a.pushcell(ConwayCell('*'), 2, 2);
    CPPUNIT_ASSERT(a.population == 1);
    
}

void testconway_1() {
    ConwayCell a('.');
    CPPUNIT_ASSERT(a.status == '.');
}

void testconway_2() {
    ConwayCell a('*');
    CPPUNIT_ASSERT(a.status == '*');
    CPPUNIT_ASSERT(a.alive == true);
}

void testconway_3() {
    ConwayCell a('.');
    CPPUNIT_ASSERT(a.alive == false);
}


void testfredkin_1() {
    FredkinCell a('-');
    CPPUNIT_ASSERT(a.status == '-');
    CPPUNIT_ASSERT(a.alive == false);
}

void testfredkin_2() {
    FredkinCell a('0');
    CPPUNIT_ASSERT(a.status == '0');
    CPPUNIT_ASSERT(a.alive == true);
}

void testfredkin_3() {
    FredkinCell a('0');
    CPPUNIT_ASSERT(a.age == 0);
}

void testupdate_1() {
    ConwayCell a('*');
    CPPUNIT_ASSERT(a.alive == true);
    int pop = 10;
    a.update(0, 0, pop);
    CPPUNIT_ASSERT(a.alive == false);
    CPPUNIT_ASSERT(pop == 9);
}

void testupdate_2() {
    FredkinCell a('0');
    CPPUNIT_ASSERT(a.alive == true);
    int pop = 10;
    a.update(1, 1, pop);
    CPPUNIT_ASSERT(a.alive == true);
    CPPUNIT_ASSERT(pop == 10);
    CPPUNIT_ASSERT(a.age == 1);
}

void testupdate_3() {
    ConwayCell a('.');
    CPPUNIT_ASSERT(a.alive == false);
    int pop = 10;
    a.update(3, 0, pop);
    CPPUNIT_ASSERT(a.alive == true);
    CPPUNIT_ASSERT(pop == 11);
}

void testcell_1() {
    int pop = 10;
    Cell a(new ConwayCell('*'));
    CPPUNIT_ASSERT(a.isAlive() == true);
    a.update(3, 0, pop);
    CPPUNIT_ASSERT(a.isAlive() == true);
    CPPUNIT_ASSERT(pop == 10);

}

void testcell_2() {
    int pop = 10;
    Cell a(new FredkinCell('0'));
    CPPUNIT_ASSERT(a.isAlive() == true);
    a.update(0, 3, pop);
    CPPUNIT_ASSERT(a.isAlive() == true);
    a.update(0, 3, pop);//change from Fredkin cell to conway cell
    CPPUNIT_ASSERT(a.isAlive() == true);
    a.update(0, 3, pop); // conway cell dying only can happen if its now a conway cell
    CPPUNIT_ASSERT(a.isAlive() == false);
    CPPUNIT_ASSERT(pop == 9);

}

void testcell_3() {
    int pop = 10;
    Cell a(new ConwayCell('*'));
    CPPUNIT_ASSERT(a.isAlive() == true);
    a.update(3, 0, pop);
    CPPUNIT_ASSERT(a.isAlive() == true);
    CPPUNIT_ASSERT(pop == 10);

}

void testwrite_1() {
	FredkinCell a('0');
	string d;
	ostringstream b;
	b << a;
	d = b.str();
	CPPUNIT_ASSERT(d[0]=='0');
}

void testwrite_2() {
	ConwayCell a('*');
	string d;
	ostringstream b;
	a.write(b);
	d = b.str();
	CPPUNIT_ASSERT(d[0]=='*');
}


void testwrite_3() {
	Cell a(new FredkinCell('0'));
	int pop = 10;
	string d;
	ostringstream b;
	a.update(0, 3, pop);
	b << a;
	d = b.str();
	CPPUNIT_ASSERT(d[0]=='1');
	a.update(0, 3, pop); // change from fredkin to conway also test the clone method
	a.write(b);
	d = b.str();
	CPPUNIT_ASSERT(d[1]=='*');
}

void testgetlettter_1 () {
	FredkinCell a('0');
	CPPUNIT_ASSERT(a.getletter() == '0');
}

void testgetlettter_2 () {
	FredkinCell a('0');
	int pop = 10;
	a.update(0, 3, pop);
	a.update(0, 3, pop);
	a.update(0, 3, pop);
	a.update(0, 3, pop);
	a.update(0, 3, pop);
	a.update(0, 3, pop);
	a.update(0, 3, pop);
	a.update(0, 3, pop);
	a.update(0, 3, pop);
	a.update(0, 3, pop);
	a.update(0, 3, pop);
	a.update(0, 3, pop);
	a.update(0, 3, pop);
	CPPUNIT_ASSERT(a.getletter() == '+');
}

void testgetlettter_3 () {
	FredkinCell a('-');
	CPPUNIT_ASSERT(a.getletter() == '-');
	int pop = 10;
	a.update(0, 3, pop);
	CPPUNIT_ASSERT(a.getletter() == '0');
	a.update(0, 3, pop);
	a.update(0, 3, pop);
	a.update(0, 3, pop);
	CPPUNIT_ASSERT(a.getletter() == '3');
	a.update(0, 0, pop);
	CPPUNIT_ASSERT(a.getletter() == '-');
	a.update(0, 3, pop);
	CPPUNIT_ASSERT(a.getletter() == '3');
}
    
    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST(testlife_1);
    CPPUNIT_TEST(testlife_2);
    CPPUNIT_TEST(testlife_3);
    CPPUNIT_TEST(testconway_1);
    CPPUNIT_TEST(testconway_2);
    CPPUNIT_TEST(testconway_3);
    CPPUNIT_TEST(testfredkin_1);
    CPPUNIT_TEST(testfredkin_2);
    CPPUNIT_TEST(testfredkin_3);
    CPPUNIT_TEST(testupdate_1);
    CPPUNIT_TEST(testupdate_2);
    CPPUNIT_TEST(testupdate_3);
    CPPUNIT_TEST(testcell_1);
    CPPUNIT_TEST(testcell_2);
    CPPUNIT_TEST(testcell_3);
    CPPUNIT_TEST(testcell_3);
    CPPUNIT_TEST(testwrite_1);
    CPPUNIT_TEST(testwrite_2);
    CPPUNIT_TEST(testwrite_3);
    CPPUNIT_TEST(testgetlettter_1);
    CPPUNIT_TEST(testgetlettter_2);
    CPPUNIT_TEST(testgetlettter_3);
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
