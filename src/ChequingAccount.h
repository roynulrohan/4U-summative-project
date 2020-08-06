/*
 * ChequingAccount.h
 *
 *  Created on: Jun. 19, 2019
 *      Author: roynul
 */

#ifndef SRC_CHEQUINGACCOUNT_H_
#define SRC_CHEQUINGACCOUNT_H_

#include "Account.h"

using namespace std;

class Chequing_Account: public Account {
private:
	const float cashback = .02;
public:
	Chequing_Account(string holder_n, Date d, int account_n);

	virtual void deposit(float amount, Date d);

	virtual void withdraw(float amount, Date d);
};



#endif /* SRC_CHEQUINGACCOUNT_H_ */
