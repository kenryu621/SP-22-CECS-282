#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <string>

class BigInt
{
private:
	std::vector<char> vec;

public:
	BigInt();
	BigInt(char);
	BigInt(std::string);
	BigInt(int);
	BigInt(const BigInt&);
	~BigInt();
	void operator=(const BigInt&);
	void operator=(const int&);
	void operator+=(const BigInt&);
	void operator+=(const int&);
	void operator-=(const BigInt&);
	void operator-=(const int&);
	friend BigInt operator-(const BigInt&, const BigInt&);
	friend BigInt operator-(const int&, const BigInt&);
	friend BigInt operator-(const BigInt&, const int&);
	friend BigInt operator+(const BigInt&, const BigInt&);
	friend BigInt operator+(const int&, const BigInt&);
	friend BigInt operator+(const BigInt&, const int&);
	BigInt operator++();
	BigInt operator++(int);
	BigInt operator--();
	BigInt operator--(int);
	friend bool operator<(const BigInt&, const BigInt&);
	friend bool operator<(const int&, const BigInt&);
	friend bool operator<(const BigInt&, const int&);
	friend bool operator>(const BigInt&, const BigInt&);
	friend bool operator>(const int&, const BigInt&);
	friend bool operator>(const BigInt&, const int&);
	friend bool operator==(const BigInt&, const BigInt&);
	friend bool operator==(const int&, const BigInt&);
	friend bool operator==(const BigInt&, const int&);
	friend bool operator<=(const BigInt&, const BigInt&);
	friend bool operator<=(const int&, const BigInt&);
	friend bool operator<=(const BigInt&, const int&);
	friend bool operator>=(const BigInt&, const BigInt&);
	friend bool operator>=(const int&, const BigInt&);
	friend bool operator>=(const BigInt&, const int&);
	friend std::ostream& operator<<(std::ostream&, const BigInt&);
	void print();
};

