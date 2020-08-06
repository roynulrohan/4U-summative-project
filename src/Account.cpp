/*
 * Account.cpp
 *
 *  Created on: Jun. 19, 2019
 *      Author: roynul
 */

#include "Account.h"
#include <string.h>
#include "Date.h"

using namespace std;

Account::~Account() {

}

void Account::set_transactions(int t) {
	transactions = t;
}

void Account::set_balance(float b) {
	balance = b;
}

float Account::get_balance() {
	return balance;
}

void Account::set_path(string p) {
	file_path = p;
}

string Account::get_path() {
	return file_path;
}

// http://www.cplusplus.com/forum/beginner/5381/

ostream &operator <<(ostream &os, Account &a) {
	os << "Type: " << a.account_type
			<< "\nHolder: " << a.holder_name << "\nDate Created: "
			<< a.date_created;

	return os;
}

