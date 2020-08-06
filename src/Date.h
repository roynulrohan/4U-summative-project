/*
 * Date.h
 *
 *  Created on: Jun. 19, 2019
 *      Author: roynul
 */

#ifndef SRC_DATE_H_
#define SRC_DATE_H_

#include <iostream>
#include <iomanip>

using namespace std;

class Date {
private:
	int d, m, y;
public:
	Date(int d = 0, int m = 0, int y = 0);

	friend ostream &operator <<(ostream &os, Date &date);

	friend istream &operator >>(istream &is, Date &d);
};

#endif /* SRC_DATE_H_ */
