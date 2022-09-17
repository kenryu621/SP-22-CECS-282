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
	BigInt(std::string);
	BigInt(int);
	~BigInt();
	friend BigInt operator-(const BigInt&, const BigInt&);
	//friend BigInt operator-(const int&, const BigInt&);
	friend BigInt operator-(const BigInt&, const int&);
	friend BigInt operator+(const BigInt&, const BigInt&);
	//friend BigInt operator+(const int&, const BigInt&);
	friend BigInt operator+(const BigInt&, const int&);
	BigInt operator++();
	BigInt operator++(int);
	BigInt operator--();
	BigInt operator--(int);
	friend bool operator<(const BigInt&, const BigInt&);
	friend bool operator>(const BigInt&, const BigInt&);
	friend bool operator==(const BigInt&, const BigInt&);
	friend bool operator<=(const BigInt&, const BigInt&);
	friend bool operator>=(const BigInt&, const BigInt&);
	friend std::ostream& operator<<(std::ostream&, const BigInt&);
	void print();
};

