/*
 * Date.cpp
 *
 *  Created on: Jun. 19, 2019
 *      Author: roynul
 */

#include "Date.h"
#include <iostream>
#include <iomanip>

using namespace std;

Date::Date(int d, int m, int y) {
	this->d = d;
	this->m = m;
	this->y = y;
}

// https://stackoverflow.com/questions/530614/print-leading-zeros-with-c-output-operator

ostream &operator <<(ostream &os, Date &date) {
	os << setw(2) << setfill('0') << date.d << "\\" << setw(2) << setfill('0') << date.m << "\\"<< setw(4) << setfill('0') << date.y;

	return os;
}

istream &operator >>(istream &is, Date &d) {
	cout << "\n\nDate (DD): ";
	is >> d.d;
	cout << "Month (MM): ";
	is >> d.m;
	cout << "Year (YYYY): ";
	is >> d.y;

	return is;
}
