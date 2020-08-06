/*
 * YouthAccount.h
 *
 *  Created on: Jun. 19, 2019
 *      Author: roynul
 */

#ifndef SRC_YOUTHACCOUNT_H_
#define SRC_YOUTHACCOUNT_H_

#include "Account.h"

using namespace std;

class Youth_Account: public Account {
private:
	const float interest = .01;
public:
	Youth_Account(string holder_n, Date d, int account_n);

	virtual void deposit(float amount, Date d);

	virtual void withdraw(float amount, Date d);
};



#endif /* SRC_YOUTHACCOUNT_H_ */
