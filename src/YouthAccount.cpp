/*
 * YouthAccount.cpp
 *
 *  Created on: Jun. 19, 2019
 *      Author: roynul
 */

#include "YouthAccount.h"
#include <fstream>

using namespace std;

Youth_Account::Youth_Account(string holder_n, Date d, int account_n) {
	balance = 0;
	transactions = 0;
	account_num = account_n;
	account_type = "Youth Account";
	holder_name = holder_n;
	date_created = d;
}

void Youth_Account::deposit(float amount, Date d) {
	transactions++;
	balance += amount + (amount * interest);

	cout << "\nDeposited $" << fixed << setprecision(2) << amount << ".\n";

	if (amount * interest > 0) {
		cout << "\nInterest of $" << fixed << setprecision(2)
				<< amount * interest << " earned.\n";
	}

	fstream fout(file_path, ios::out | ios::app);
	// Truncates file if it already exists

	if (fout.fail()) {
		// fout.fail() returns true on failure
		cout << "Error opening file" << endl;
		exit(1);
	}

	fout << "\nTransaction #" << transactions << " | " << d << " | +$"
			<< fixed << setprecision(2) << amount << " | Interest of +$"
			<< fixed << setprecision(2) << amount * interest
			<< " | New Balance: $" << fixed << setprecision(2) << balance;

	if (fout.fail()) {
		cout << "Error writing file" << endl;
		exit(1);
	}

	fout.close();

	if (fout.fail()) {
		cout << "Error closing file" << endl;
		exit(1);
	}
}

void Youth_Account::withdraw(float amount, Date d) {
	transactions++;
	balance -= amount;

	cout << "\nWithdrawed $" << fixed << setprecision(2) << amount << ".\n";

	fstream fout(file_path, ios::out | ios::app);
	// Truncates file if it already exists

	if (fout.fail()) {
		// fout.fail() returns true on failure
		cout << "Error opening file" << endl;
		exit(1);
	}

	fout << "\nTransaction #" << transactions << " | " << d << " | -$"
			<< fixed << setprecision(2) << amount << " | New Balance: $"
			<< fixed << setprecision(2) << balance;

	if (fout.fail()) {
		cout << "Error writing file" << endl;
		exit(1);
	}

	fout.close();

	if (fout.fail()) {
		cout << "Error closing file" << endl;
		exit(1);
	}
}
