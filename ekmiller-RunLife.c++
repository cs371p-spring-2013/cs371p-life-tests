#include "Life.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Life<ConwayCell> readLifeConway(ifstream& f) {
	int rows;
	f >> rows;
	int cols;
	f >> cols;
	char c;
	Life<ConwayCell> conway(rows, cols, ConwayCell(false));
	for(int row = 0; row < rows; ++row) {
		for(int col = 0; col < cols; ++col) {
			c = f.get();
			if(c == '\n')
				c = f.get();
			if(c == '.') { }
			if(c == '*')
				conway.setState(true, row, col); } } 
	return conway; }

Life<FredkinCell> readLifeFredkin(ifstream& f) {
	int rows;
	f >> rows;
	int cols;
	f >> cols;
	char c;
	int a;
	Life<FredkinCell> fredkin(rows, cols, FredkinCell(false));
	for(int row = 0; row < rows; ++row) {
		for(int col = 0; col < cols; ++col) {
			c = f.get();
			if(c == '\n')
				c = f.get();
			if(c == '-') { }
			else {
				a = c - '0';
				fredkin.setState(true, row, col);
				fredkin.setAge(a, row, col); } } } 
		return fredkin; }

Life<Cell> readLifeCell(ifstream& f) {
	int rows;
	f >> rows;
	int cols;
	f >> cols;
	char c;
	int a;
	Life<Cell> cell(rows, cols, new FredkinCell(false));
	for(int row = 0; row < rows; ++row) {
		for(int col = 0; col < cols; ++col) {
			c = f.get();
			if(c == '\n')
				c = f.get();
			if(c == '-') { }
			else {
				a = c - '0';
				cell.setState(true, row, col);
				cell.setAge(a, row, col); } } } 
	return cell; }

int main() {
	{
	cout << "*** Life<ConwayCell> 109x69 ***" << endl;
	string filename = "RunLifeConway.in";
	filename.c_str();
	ifstream f(filename);
	Life<ConwayCell> one = readLifeConway(f);
	one.print();
	for(int i = 0; i < 9; ++i) {
		one.next();
		one.print(); }
	for(int i = 9; i != 283; ++i)
		one.next();
	one.print();
	for(int i = 0; i < 40; ++i)
		one.next();
	one.print();
	for(int i = 0; i < 2177; ++i)
		one.next();
	one.print();
	}

	{
	cout << "*** Life<FredkinCell> 20x20 ***" << endl;
	string filename = "RunLifeFredkin.in";
	filename.c_str();
	ifstream f(filename);
	Life<FredkinCell> two = readLifeFredkin(f);
	two.print();
	for(int i = 0; i < 5; ++i) {
		two.next();
		two.print(); }
	}

	{
	cout << "*** Life<FredkinCell> 20x20 ***" << endl;
	string filename = "RunLifeCell.in";
	filename.c_str();
	ifstream f(filename);
	Life<Cell> three = readLifeCell(f);
	three.print();
	for(int i = 0; i < 5; ++i) {
		three.next();
		three.print(); }
	}

	{
	cout << "*** Life<ConwayCell> 10x10 ***" << endl;
	Life<ConwayCell> four(10,10,ConwayCell(false));
	four.setState(true,0,1);
	four.setState(true,1,2);
	four.setState(true,2,0);
	four.setState(true,2,1);
	four.setState(true,2,2);
	four.print();
	for(int i = 0; i < 4; ++i) {
		four.next();
		four.print(); }
	for(int i = 0; i < 6; ++i) {
		for(int i = 0; i < 4; ++i)
			four.next();
		four.print(); }
	}

	{
	cout << "*** Life<FredkinCell> 10x10 ***" << endl;
	Life<FredkinCell> five(10,10,FredkinCell(false));
	five.setState(true,0,1);
	five.setState(true,1,2);
	five.setState(true,2,0);
	five.setState(true,2,1);
	five.setState(true,2,2);
	five.print();
	for(int i = 0; i < 10; ++i) {
		five.next();
		five.print(); }
	}

	{
	cout << "*** Life<ConwayCell> 15x15 ***" << endl;
	Life<ConwayCell> six(15,15,ConwayCell(false));
	six.setState(true,1,3);
	six.setState(true,1,4);
	six.setState(true,1,5);
	six.setState(true,1,9);
	six.setState(true,1,10);
	six.setState(true,1,11);
	six.setState(true,6,3);
	six.setState(true,6,4);
	six.setState(true,6,5);
	six.setState(true,6,9);
	six.setState(true,6,10);
	six.setState(true,6,11);
	six.setState(true,8,3);
	six.setState(true,8,4);
	six.setState(true,8,5);
	six.setState(true,8,9);
	six.setState(true,8,10);
	six.setState(true,8,11);
	six.setState(true,13,3);
	six.setState(true,13,4);
	six.setState(true,13,5);
	six.setState(true,13,9);
	six.setState(true,13,10);
	six.setState(true,13,11);
	six.setState(true,3,1);
	six.setState(true,4,1);
	six.setState(true,5,1);
	six.setState(true,9,1);
	six.setState(true,10,1);
	six.setState(true,11,1);
	six.setState(true,3,6);
	six.setState(true,4,6);
	six.setState(true,5,6);
	six.setState(true,9,6);
	six.setState(true,10,6);
	six.setState(true,11,6);
	six.setState(true,3,8);
	six.setState(true,4,8);
	six.setState(true,5,8);
	six.setState(true,9,8);
	six.setState(true,10,8);
	six.setState(true,11,8);
	six.setState(true,3,13);
	six.setState(true,4,13);
	six.setState(true,5,13);
	six.setState(true,9,13);
	six.setState(true,10,13);
	six.setState(true,11,13);
	six.print();
	for(int i = 0; i < 3; ++i) {
		six.next();
		six.print(); }
	}

	{
	cout << "*** Life<Cell> 15x15 ***" << endl;
	Life<Cell> seven(15,15,new FredkinCell(false));
	seven.setState(true,1,3);
	seven.setState(true,1,4);
	seven.setState(true,1,5);
	seven.setState(true,1,9);
	seven.setState(true,1,10);
	seven.setState(true,1,11);
	seven.setState(true,6,3);
	seven.setState(true,6,4);
	seven.setState(true,6,5);
	seven.setState(true,6,9);
	seven.setState(true,6,10);
	seven.setState(true,6,11);
	seven.setState(true,8,3);
	seven.setState(true,8,4);
	seven.setState(true,8,5);
	seven.setState(true,8,9);
	seven.setState(true,8,10);
	seven.setState(true,8,11);
	seven.setState(true,13,3);
	seven.setState(true,13,4);
	seven.setState(true,13,5);
	seven.setState(true,13,9);
	seven.setState(true,13,10);
	seven.setState(true,13,11);
	seven.setState(true,3,1);
	seven.setState(true,4,1);
	seven.setState(true,5,1);
	seven.setState(true,9,1);
	seven.setState(true,10,1);
	seven.setState(true,11,1);
	seven.setState(true,3,6);
	seven.setState(true,4,6);
	seven.setState(true,5,6);
	seven.setState(true,9,6);
	seven.setState(true,10,6);
	seven.setState(true,11,6);
	seven.setState(true,3,8);
	seven.setState(true,4,8);
	seven.setState(true,5,8);
	seven.setState(true,9,8);
	seven.setState(true,10,8);
	seven.setState(true,11,8);
	seven.setState(true,3,13);
	seven.setState(true,4,13);
	seven.setState(true,5,13);
	seven.setState(true,9,13);
	seven.setState(true,10,13);
	seven.setState(true,11,13);
	seven.print();
	for(int i = 0; i < 10; ++i) {
		seven.next();
		seven.print(); }
	}

	{
	cout << "*** Life<FredkinCell> 15x15 ***" << endl;
	Life<FredkinCell> eight(15,15,FredkinCell(false));
	eight.setState(true,1,3);
	eight.setState(true,1,4);
	eight.setState(true,1,5);
	eight.setState(true,1,9);
	eight.setState(true,1,10);
	eight.setState(true,1,11);
	eight.setState(true,6,3);
	eight.setState(true,6,4);
	eight.setState(true,6,5);
	eight.setState(true,6,9);
	eight.setState(true,6,10);
	eight.setState(true,6,11);
	eight.setState(true,8,3);
	eight.setState(true,8,4);
	eight.setState(true,8,5);
	eight.setState(true,8,9);
	eight.setState(true,8,10);
	eight.setState(true,8,11);
	eight.setState(true,13,3);
	eight.setState(true,13,4);
	eight.setState(true,13,5);
	eight.setState(true,13,9);
	eight.setState(true,13,10);
	eight.setState(true,13,11);
	eight.setState(true,3,1);
	eight.setState(true,4,1);
	eight.setState(true,5,1);
	eight.setState(true,9,1);
	eight.setState(true,10,1);
	eight.setState(true,11,1);
	eight.setState(true,3,6);
	eight.setState(true,4,6);
	eight.setState(true,5,6);
	eight.setState(true,9,6);
	eight.setState(true,10,6);
	eight.setState(true,11,6);
	eight.setState(true,3,8);
	eight.setState(true,4,8);
	eight.setState(true,5,8);
	eight.setState(true,9,8);
	eight.setState(true,10,8);
	eight.setState(true,11,8);
	eight.setState(true,3,13);
	eight.setState(true,4,13);
	eight.setState(true,5,13);
	eight.setState(true,9,13);
	eight.setState(true,10,13);
	eight.setState(true,11,13);
	eight.print();
	for(int i = 0; i < 7; ++i) {
		eight.next();
		eight.print(); }
	}

	{
	cout << "*** Life<ConwayCell> 9x9 ***" << endl;
	Life<ConwayCell> nine(9,9,ConwayCell(false));
	nine.setState(true,0,2);
	nine.setState(true,0,3);
	nine.setState(true,0,5);
	nine.setState(true,0,6);
	nine.setState(true,1,1);
	nine.setState(true,1,3);
	nine.setState(true,1,5);
	nine.setState(true,1,7);
	nine.setState(true,2,0);
	nine.setState(true,2,3);
	nine.setState(true,2,5);
	nine.setState(true,2,8);
	nine.setState(true,3,0);
	nine.setState(true,3,1);
	nine.setState(true,3,2);
	nine.setState(true,3,3);
	nine.setState(true,3,5);
	nine.setState(true,3,6);
	nine.setState(true,3,7);
	nine.setState(true,3,8);
	nine.setState(true,5,0);
	nine.setState(true,5,1);
	nine.setState(true,5,2);
	nine.setState(true,5,3);
	nine.setState(true,5,5);
	nine.setState(true,5,6);
	nine.setState(true,5,7);
	nine.setState(true,5,8);
	nine.setState(true,6,0);
	nine.setState(true,6,3);
	nine.setState(true,6,5);
	nine.setState(true,6,8);
	nine.setState(true,7,1);
	nine.setState(true,7,3);
	nine.setState(true,7,5);
	nine.setState(true,7,7);
	nine.setState(true,8,2);
	nine.setState(true,8,3);
	nine.setState(true,8,5);
	nine.setState(true,8,6);
	nine.print();
	nine.next();
	nine.print();
	}

	{
	cout << "*** Life<Cell> 9x9 ***" << endl;
	Life<Cell> ten(9,9,new FredkinCell(false));
	ten.setState(true,0,2);
	ten.setState(true,0,3);
	ten.setState(true,0,5);
	ten.setState(true,0,6);
	ten.setState(true,1,1);
	ten.setState(true,1,3);
	ten.setState(true,1,5);
	ten.setState(true,1,7);
	ten.setState(true,2,0);
	ten.setState(true,2,3);
	ten.setState(true,2,5);
	ten.setState(true,2,8);
	ten.setState(true,3,0);
	ten.setState(true,3,1);
	ten.setState(true,3,2);
	ten.setState(true,3,3);
	ten.setState(true,3,5);
	ten.setState(true,3,6);
	ten.setState(true,3,7);
	ten.setState(true,3,8);
	ten.setState(true,5,0);
	ten.setState(true,5,1);
	ten.setState(true,5,2);
	ten.setState(true,5,3);
	ten.setState(true,5,5);
	ten.setState(true,5,6);
	ten.setState(true,5,7);
	ten.setState(true,5,8);
	ten.setState(true,6,0);
	ten.setState(true,6,3);
	ten.setState(true,6,5);
	ten.setState(true,6,8);
	ten.setState(true,7,1);
	ten.setState(true,7,3);
	ten.setState(true,7,5);
	ten.setState(true,7,7);
	ten.setState(true,8,2);
	ten.setState(true,8,3);
	ten.setState(true,8,5);
	ten.setState(true,8,6);
	ten.print();
	for(int i = 0; i < 7; ++i) {
		ten.next();
		ten.print(); }
	}
}