#include "Account.h"
using namespace std;

Account::Account() {
	this->balance = 0;
}

Account::Account(int amount) {
	this->balance = amount;
}