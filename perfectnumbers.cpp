// Agui Navarro
// Perfect Numbers

#include <iostream>
#include <cmath>
using namespace std;

void pncalculator();
void nthpn();
void pnupton();
bool isPrime(int x);

int main() {
	cout << "A perfect number is a positive integer that is equal to the sum "
	     << "of its divisors, excluding itself." << endl;
	cout << "This program performs perfect number-related tasks." << endl
		 << endl;

	int choice;
	do {
		cout << "Menu:" << endl;
		cout << "1 - Perfect Number Calculator" << endl;
		cout << "2 - Nth Perfect Number" << endl;
		cout << "3 - Perfect Numbers up to N" << endl;
		cout << "4 - Exit" << endl;
		cout << "Input: ";
		cin >> choice;
		cout << endl;

		switch (choice) {
			case 1:
				pncalculator();
				break;
			case 2:
				nthpn();
				break;
			case 3:
				pnupton();
				break;
			case 4:
				break;
			default:
				cout << "Enter a number between 1 and 4." << endl;
				break;
		}
	} while (choice != 4);

	return 0;
}

void pncalculator() {

	unsigned long long int n;

	do {
		cout << "Enter a positive integer: ";
		cin >> n;
	} while (n < 1);

	if (n < 6) {
		cout << n << " is not a perfect number." << endl << endl;
		return;
	}

	unsigned long long int mp, pn;

	for (int i = 2; i <= 61; i++) {
		if (isPrime(i)) {
			mp = pow(2, i) - 1;
			if (isPrime(mp)) {
				pn = (mp * pow(2, i-1));
				if (n == pn) {
					cout << n << " is a perfect number." << endl << endl;
					return;
				}
			}
		}
	}
	cout << n << " is not a perfect number." << endl << endl;
}

void nthpn() {

	int n, count = 0;
	unsigned long long int mp, pn;

	do {
		cout << "Enter a positive integer: ";
		cin >> n;
	} while (n < 1);

	for (int i = 2; i <= 61; i++) {
		if (isPrime(i)) {
			mp = pow(2, i) - 1;
			if (isPrime(mp)) {
				count++;
			}
			if (count == n) {
				pn = (mp * pow(2, i-1));
				switch (n) {
					case 1:
						cout << "The " << n << "st perfect number is " << pn <<
						"." << endl << endl;
						return;
					case 2:
						cout << "The " << n << "nd perfect number is " << pn <<
						"." << endl << endl;
						return;
					case 3:
						cout << "The " << n << "rd perfect number is " << pn <<
						"." << endl << endl;
						return;
					default:
						if (pn == 0) {
							cout << "NUMBER TOO HIGH!!!" << endl << endl;
							return;
						}
						cout << "The " << n << "th perfect number is " << pn <<
						"." << endl << endl;
						return;
				}
			}
		}
	}
}
void pnupton() {

	unsigned long long int n;

	do {
		cout << "Enter a positive integer: ";
		cin >> n;
	} while (n < 1);

	if (n < 6) {
		cout << "There are no perfect numbers under 6." << endl << endl;
		return;
	}

	unsigned long long int mp, pn;

	cout << endl << "Perfect numbers under " << n << ": " << endl;

	for (int i = 2; i <= 61; i++) {
		if (isPrime(i)) {
			mp = pow(2, i) - 1;
			if (isPrime(mp)) {
				pn = (mp * pow(2, i-1));
				if (pn > n) {
					cout << endl;
					return;
				}
				cout << pn << endl;
			}
		}
	}
}

bool isPrime(int x) {
	for (int i = 2; i < x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
