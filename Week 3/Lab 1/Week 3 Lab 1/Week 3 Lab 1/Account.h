#pragma once
class Account
{
private:
	int balance;
	void penalty();

public:
	Account();
	Account(int amount);
	void deposit(int amount);
	void withdraw(int amount);
	int get_balance();
};

