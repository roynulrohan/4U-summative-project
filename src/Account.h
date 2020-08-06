/*
 * Account.h
 *
 *  Created on: Jun. 19, 2019
 *      Author: roynul
 */

#ifndef SRC_ACCOUNT_H_
#define SRC_ACCOUNT_H_

#include <iostream>
#include "Date.h"

using namespace std;

class Account {
protected:
	int account_num;
	string account_type;
	string holder_name;
	float balance;
	int transactions;
	Date date_created;
	string file_path;
public:
	virtual ~Account();

	virtual void deposit(float amount, Date d) = 0;

	virtual void withdraw(float amount, Date d) = 0;

	void set_balance(float b);

	float get_balance();

	void set_transactions(int t);

	void set_path(string p);

	string get_path();

	friend ostream &operator <<(ostream &os, Account &a);
};



#endif /* SRC_ACCOUNT_H_ */
