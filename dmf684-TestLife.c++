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
% g++ -pedantic -std=c++0x -Wall Life.c++ TestLife.c++ -o TestLife -lcppunit -ldl
% valgrind TestLife >& TestLife.out
*/

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream> // stringstream

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TextTestRunner

#include "Life.h"

// -----------
// TestLife
// -----------

struct TestConwayCell : CppUnit::TestFixture {

    void test_isAlive1() {
        ConwayCell cell(false);
        CPPUNIT_ASSERT(!cell.isAlive());}

    void test_isAlive2() {
        ConwayCell cell(true);
        CPPUNIT_ASSERT(cell.isAlive());}

    void test_isAlive3() {
        ConwayCell cell(false);
        std::stringstream ss("*");
        ss >> cell;
        CPPUNIT_ASSERT(cell.isAlive());}

    void test_doLife1() {
        ConwayCell cell(true);
        CPPUNIT_ASSERT(!cell.doLife(2) && cell.isAlive());}

    void test_doLife2() {
        ConwayCell cell(true);
        CPPUNIT_ASSERT(!cell.doLife(1) && !cell.isAlive());}

    void test_doLife3() {
        ConwayCell cell(false);
        CPPUNIT_ASSERT(!cell.doLife(3) && cell.isAlive());}

	CPPUNIT_TEST_SUITE(TestConwayCell);
	CPPUNIT_TEST(test_isAlive1);
	CPPUNIT_TEST(test_isAlive2);
	CPPUNIT_TEST(test_isAlive3);
	CPPUNIT_TEST(test_doLife1);
	CPPUNIT_TEST(test_doLife2);
	CPPUNIT_TEST(test_doLife3);
	CPPUNIT_TEST_SUITE_END();
};

struct TestFredkinCell : CppUnit::TestFixture {

    void test_isAlive1() {
        FredkinCell cell(false);
        CPPUNIT_ASSERT(!cell.isAlive());}

    void test_isAlive2() {
        FredkinCell cell(true);
        CPPUNIT_ASSERT(cell.isAlive());}

    void test_isAlive3() {
        FredkinCell cell(false);
        std::stringstream ss("0");
        ss >> cell;
        CPPUNIT_ASSERT(cell.isAlive());}

    void test_doLife1() {
        FredkinCell cell(true);
        CPPUNIT_ASSERT(!cell.doLife(1) && cell.isAlive());}

    void test_doLife2() {
        FredkinCell cell(true);
        bool mutate = cell.doLife(0);
        CPPUNIT_ASSERT(!mutate && !cell.isAlive());}

    void test_doLife3() {
        FredkinCell cell(false);
        cell.doLife(1);
        cell.doLife(1);
        CPPUNIT_ASSERT(cell.doLife(1) && cell.isAlive());}

	CPPUNIT_TEST_SUITE(TestFredkinCell);
	CPPUNIT_TEST(test_isAlive1);
	CPPUNIT_TEST(test_isAlive2);
	CPPUNIT_TEST(test_isAlive3);
	CPPUNIT_TEST(test_doLife1);
	CPPUNIT_TEST(test_doLife2);
	CPPUNIT_TEST(test_doLife3);
	CPPUNIT_TEST_SUITE_END();
};

struct TestCell : CppUnit::TestFixture {

    void test_isAlive1() {
        Cell cell(new FredkinCell(false));
        CPPUNIT_ASSERT(!cell.isAlive());}

    void test_isAlive2() {
        Cell cell(new FredkinCell(true));
        CPPUNIT_ASSERT(cell.isAlive());}

    void test_isAlive3() {
        Cell cell(new FredkinCell(false));
        std::stringstream ss("0");
        ss >> cell;
        CPPUNIT_ASSERT(cell.isAlive());}

    void test_doLife1() {
        Cell cell(new FredkinCell(true));
        CPPUNIT_ASSERT(!cell.doLife(1) && cell.isAlive());}

    void test_doLife2() {
        Cell cell(new FredkinCell(true));
        bool mutate = cell.doLife(0);
        CPPUNIT_ASSERT(!mutate && !cell.isAlive());}

    void test_doLife3() {
        Cell cell(new FredkinCell(false));
        cell.doLife(1);
        cell.doLife(1);
        CPPUNIT_ASSERT(cell.doLife(1) && cell.isAlive());}

	CPPUNIT_TEST_SUITE(TestCell);
	CPPUNIT_TEST(test_isAlive1);
	CPPUNIT_TEST(test_isAlive2);
	CPPUNIT_TEST(test_isAlive3);
	CPPUNIT_TEST(test_doLife1);
	CPPUNIT_TEST(test_doLife2);
	CPPUNIT_TEST(test_doLife3);
	CPPUNIT_TEST_SUITE_END();
};

struct TestLife : CppUnit::TestFixture {

    void test_simulateMove1() {
        std::stringstream ss("1 \n 1 \n *");
        int row, col;
        ss >> row >> col;
        Life<ConwayCell> life = Life<ConwayCell>(row, col);
        ss >> life;
        life.simulateMove();
        std::stringstream s2;
        s2 << life;
        CPPUNIT_ASSERT(s2.str() == "Generation = 1, Population = 0.\n.\n");}
    void test_simulateMove2() {
        std::stringstream ss("1 \n 1 \n 0");
        int row, col;
        ss >> row >> col;
        Life<FredkinCell> life = Life<FredkinCell>(row, col);
        ss >> life;
        life.simulateMove();
        std::stringstream s2;
        s2 << life;
        CPPUNIT_ASSERT(s2.str() == "Generation = 1, Population = 0.\n-\n");}
    void test_simulateMove3() {
        std::stringstream ss("1 \n 1 \n 0");
        int row, col;
        ss >> row >> col;
        Life<Cell> life = Life<Cell>(row, col, new FredkinCell(false));
        ss >> life;
        life.simulateMove();
        std::stringstream s2;
        s2 << life;
        CPPUNIT_ASSERT(s2.str() == "Generation = 1, Population = 0.\n-\n");}

	CPPUNIT_TEST_SUITE(TestLife);
	CPPUNIT_TEST(test_simulateMove1);
	CPPUNIT_TEST(test_simulateMove2);
	CPPUNIT_TEST(test_simulateMove3);
	CPPUNIT_TEST_SUITE_END();
};

// ----
// main
// ----

int main () {
	using namespace std;
	cout << "TestLife.c++" << endl;

	CppUnit::TextTestRunner tr;
	tr.addTest(TestConwayCell::suite());
	tr.addTest(TestFredkinCell::suite());
	tr.addTest(TestCell::suite());
	tr.addTest(TestLife::suite());

	tr.run();

	cout << "Done." << endl;
	return 0;}

