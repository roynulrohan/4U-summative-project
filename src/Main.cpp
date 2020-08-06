#include <iostream>
#include <string.h>
#include <fstream>
#include <ctype.h>

#include "Date.h"
#include "Account.h"
#include "ChequingAccount.h"
#include "SavingsAccount.h"
#include "YouthAccount.h"

using namespace std;

/*
 * This program will let the user pick between 3 bank accounts with unique features. Each account
 * gets written down in the working directory. Each transaction gets written as well. If accounts
 * already exist in selected directory then they get read into the array;
 * The way I made the accounts was I have an abstract base account class. Then 3 unique
 * account classes that inherit from it. The way I implemented composition is by making a Date class.
 * It is kind of impractical because my program doesn't check if dates of transactions are in chronological order.
 * That would be too much unnecessary work. A lot of things aren't error proofed.
 */

string directory; // working directory

// creates one account and writes it
void create_account(Account** a, int account_num) {
	string name;
	int choice;
	Date d;

	cout << "\nOpening new account...\n\nSelect account type.\n\n1 - Chequing Account\n  - 2% Cashback\n\n2 - Savings Account\n  - $2 Withdraw Fee\n\n3 - Youth Account\n  - 1% Interest on every deposit\n\nEnter choice: ";
	do {
		cin >> choice;
		if (choice < 1 || choice > 3) {
			cout << "\nInvalid Option. Try Again: ";
		}
	} while (choice < 1 || choice > 3);

	cout << "\nEnter your name: ";
	cin.ignore();
	getline(cin, name);
	cout << "\nEnter today date";
	cin >> d;

	if (choice == 1) {
		*a = new Chequing_Account(name, d, account_num + 1);
	} else if (choice == 2) {
		*a = new Savings_Account(name, d, account_num + 1);
	} else if (choice == 3) {
		*a = new Youth_Account(name, d, account_num + 1);
	}
}

#define MAX_ACCOUNTS 10

int main() {
	Account* accounts[MAX_ACCOUNTS]; // accounts list
	int count = 0; // accounts count
	string input; // user's input

	cout << "Enter path of a folder: ";
	getline(cin, directory);

	int transactions, x; // number of transactions, x is for the number of lines in the file
	string line, account[3]; // line var for every line read, account[] to store the base info
	string name, temp;
	int d, m, y;

	for (int i = 0; i < MAX_ACCOUNTS; i++) {
		transactions = 0;
		x = 0;

		// checks if that file exists first
		fstream fin(directory + "\\Account#" + to_string(i) + ".txt", ios::in);
		if (!fin.fail()) {
			//if it does then it reads it line by line into the array to store the base information,
			// then it keeps count of how many transactions there are
			while (!fin.eof()) {
				getline(fin, line);

				if (fin.fail() && !fin.eof()) {
					cout << "Error reading file" << endl;
					return 0;
				}

				if (!fin.eof()) {
					if (x < 3) {
						account[x] = line;
					}
				}

				x++;

				if (x > 4)
					transactions++;
			}

			fin.close();

			if (fin.fail() && !fin.eof()) {
				cout << "Error closing file" << endl;
				return 0;
			}

			// name
			name = account[1].substr(7, account[1].length() - 1);

			// date
			temp = account[2].substr(14, account[2].length() - 1);

			d = atoi(temp.substr(0, 2).c_str());
			m = atoi(temp.substr(4, 6).c_str());
			y = atoi(temp.substr(8, 12).c_str());

			if (account[0][6] == 'C') {
				accounts[count] = new Chequing_Account(name, Date(d, m, y), count + 1);
			} else if (account[0][6] == 'S') {
				accounts[count] = new Savings_Account(name, Date(d, m, y), count + 1);
			} else {
				accounts[count] = new Youth_Account(name, Date(d, m, y), count + 1);
			}

			(*accounts[count]).set_path(directory + "\\Account#" + to_string(i) + ".txt");

			// if there were transactions then it checks the very end for a final balance and stores that in
			if (transactions != 0) {
				int index;

				for (int x = 0; x < (int) line.length(); x++)
					if (line[x] == 'B')
						index = x + 10;

				float balance = atof(line.substr(index, line.length() - 1).c_str());

				(*accounts[count]).set_balance(balance);

				(*accounts[count]).set_transactions(transactions);
			}

			count++;
		}
	}

	// grammar
	if (count == 1) {
		cout << "\n" << count << " account found.\n";
	} else if (count > 1) {
		cout << "\n" << count << " accounts found.\n";
	} else {
		cout << "\nNo accounts found.\n";
	}

	// actual program
	do {
		cout << "\nnew \\ view \\ withdraw \\ deposit \\ exit\n\nenter: ";
		cin >> input;

		// new account
		if (input == "new") {

			if (count < MAX_ACCOUNTS) {
				create_account(&accounts[count], count);

				(*accounts[count]).set_path(directory + "//Account#" + to_string(count + 1) + ".txt");
				//https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c

				fstream fout((*accounts[count]).get_path(), ios::out);
				// Truncates file if it already exists

				if (fout.fail()) {
					// fout.fail() returns true on failure
					cout << "Error opening file" << endl;
					exit(1);
				}

				fout << (*accounts[count]) << endl;

				if (fout.fail()) {
					cout << "Error writing file" << endl;
					exit(1);
				}

				fout.close();

				if (fout.fail()) {
					cout << "Error closing file" << endl;
					exit(1);

				}
				count++;
			} else {
				cout << "\nMax Accounts Reached.\n";
			}

		} else if (input == "withdraw") {
			/*
			 * Withdraw and deposit methods open the account file for app
			 * and writes each transaction
			 */
			if (count != 0) {
				int num; // account number
				float amount;
				Date d; // date of transaction

				// error proofing
				do {
					cout << "\nEnter account #: ";
					cin >> num;
					if (num < 1 || num > count) {
						cout << "\nError. Try again\n";
					}
				} while (num < 1 || num > count);

				cout << "\nCurrent Balance: $" << (*accounts[num - 1]).get_balance() << "\n";
				cout << "\nEnter withdrawal amount: $";
				cin >> amount;
				cout << "\nEnter today's date";
				cin >> d;

				(*accounts[num - 1]).withdraw(amount, d);

			} else {
				cout << "\nCreate an account first.\n";
			}

		} else if (input == "deposit") {

			if (count != 0) {
				int num;
				float amount;
				Date d;

				do {
					cout << "\nEnter account #: ";
					cin >> num;
					if (num < 1 || num > count) {
						cout << "\nError. Try again\n";
					}
				} while (num < 1 || num > count);

				cout << "\nCurrent Balance: $" << (*accounts[num - 1]).get_balance() << "\n";
				cout << "\nEnter deposit amount: $";
				cin >> amount;
				cout << "\nEnter today's date";
				cin >> d;

				(*accounts[num - 1]).deposit(amount, d);
			} else {
				cout << "\nCreate an account first.\n";
			}

		} else if (input == "view") {
			for (int i = 0; i < count; i++)
				cout << "\nAccount #" << i + 1 << "\n" << *accounts[i] << "\nBalance: $" << (*accounts[i]).get_balance() << "\n";

		} else if (input != "exit") {
			cout << "\nInvalid Command.\n";
		}

	} while (input != "exit");

	cout << "\nProgram Closed.\n";

	return 0;
}
