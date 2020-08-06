/*
 * ChequingAccount.cpp
 *
 *  Created on: Jun. 19, 2019
 *      Author: roynul
 */

#include "ChequingAccount.h"
#include <fstream>

using namespace std;

	Chequing_Account::Chequing_Account(string holder_n, Date d, int account_n) {
		balance = 0;
		transactions = 0;
		account_num = account_n;
		account_type = "Chequing Account";
		holder_name = holder_n;
		date_created = d;
	}

	void Chequing_Account::deposit(float amount, Date d) {
		transactions++;
		balance += amount;

		cout << "\nDeposited $" << fixed << setprecision(2) << amount
				<< ".\n";

		fstream fout(file_path, ios::out | ios::app);
		// Truncates file if it already exists

		if (fout.fail()) {
			// fout.fail() returns true on failure
			cout << "Error opening file" << endl;
			exit(1);
		}

		fout << "\nTransaction #" << transactions << " | " << d << " | +$"
				<< fixed << setprecision(2) << amount
				<< " | New Balance: $" << fixed << setprecision(2)
				<< balance;

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

	void Chequing_Account::withdraw(float amount, Date d) {
		transactions++;
		balance -= amount - (amount * cashback);

		cout << "\nWithdrawed $" << fixed << setprecision(2) << amount
				<< ".\n";

		if (amount * cashback > 0) {
			cout << "\nCashback of $" << fixed << setprecision(2)
					<< amount * cashback << " earned.\n";
		}

		fstream fout(file_path, ios::out | ios::app);
		// Truncates file if it already exists

		if (fout.fail()) {
			// fout.fail() returns true on failure
			cout << "Error opening file" << endl;
			exit(1);
		}

		fout << "\nTransaction #" << transactions << " | " << d << " | -$"
				<< fixed << setprecision(2) << amount
				<< " | Cashback of +$" << fixed << setprecision(2)
				<< amount * cashback << " | New Balance: $" << fixed
				<< setprecision(2) << balance;

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

