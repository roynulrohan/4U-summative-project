/*
 * SavingsAccount.h
 *
 *  Created on: Jun. 19, 2019
 *      Author: roynul
 */

#ifndef SRC_SAVINGSACCOUNT_H_
#define SRC_SAVINGSACCOUNT_H_

#include "Account.h"

using namespace std;

class Savings_Account: public Account {
private:
	const float withdraw_fee = 2;
public:
	Savings_Account(string holder_n, Date d, int account_n);

	virtual void deposit(float amount, Date d);

	virtual void withdraw(float amount, Date d);
};


#endif /* SRC_SAVINGSACCOUNT_H_ */
