#include "BigInt.h"

BigInt::BigInt() {
	this->vec.push_back((char)0);
}

BigInt::BigInt(char input) {
	int temp = input > 0 ? input : 0;
	do {
		this->vec.push_back((char)(temp % 10));
		temp /= 10;
	} while (temp > 0);
}

BigInt::BigInt(std::string input) {
	for (std::string::reverse_iterator iter = input.rbegin(); iter != input.rend(); ++iter) {
		this->vec.push_back((int)*iter >= 48 && (int)*iter <= 57 ? (char)(*iter - 48) : (char)*iter);
	}
}

BigInt::BigInt(int input) {
	int temp = input > 0 ? input : 0;
	do {
		this->vec.push_back((char)(temp % 10));
		temp /= 10;
	} while (temp > 0);
}

BigInt::BigInt(const BigInt& right) {
	this->vec = right.vec;
}

BigInt::~BigInt() {}

void BigInt::operator=(const BigInt& right) {
	this->vec = right.vec;
}

void BigInt::operator=(const int& right) {
	this->BigInt::BigInt(right);
}

std::ostream& operator<<(std::ostream& output, const BigInt& input) {
	int short_value = 0;
	for (std::vector<char>::const_reverse_iterator iter = input.vec.rbegin(); iter != input.vec.rend(); ++iter) {
		output << (int)*iter;
		if (input.vec.size() > 13) {
			if (iter == input.vec.rbegin()) output << '.';
			if (++short_value == 13) {
				output << 'e' << input.vec.size() - 1;
				break;
			}
		}
	}
	return output;
}

BigInt operator+ (const BigInt& left, const BigInt& right) {
	int iter = 0, carry = 0;
	BigInt result;
	result.vec.clear();
	while (iter < left.vec.size() || iter < right.vec.size()) {
		int left_digit = iter < left.vec.size() ? left.vec[iter] : 0;
		int right_digit = iter < right.vec.size() ? right.vec[iter] : 0;
		result.vec.push_back((left_digit + right_digit + carry) % 10);
		carry = (left_digit + right_digit + carry) / 10;
		iter++;
	}
	if (carry == 1)result.vec.push_back(1);
	return result;
}

BigInt operator- (const BigInt& left, const BigInt& right) {
	int iter = 0, borrow = 0;
	BigInt result;
	result.vec.clear();
	while (iter < left.vec.size() || iter < right.vec.size()) {
		int left_digit = iter < left.vec.size() ? left.vec[iter] : 0;
		int right_digit = iter < right.vec.size() ? right.vec[iter] : 0;
		if (borrow == 1) {
			right_digit++;
			borrow = 0;
		}
		if (left_digit < right_digit && (iter + 1) < left.vec.size()) {
			left_digit += 10;
			borrow = 1;
		}
		result.vec.push_back((left_digit - right_digit) % 10);
		if ((int)result.vec[iter] < 0)
			return BigInt();
		iter++;
	}
	std::vector<char>::iterator digit = --result.vec.end();
	while (*digit == 0 && digit != result.vec.begin()) {
		--digit;
		result.vec.pop_back();
	}
	return result;
}

BigInt operator+ (const BigInt& left, const int& right) {
	int iter = 0, carry = 0, temp = right;
	BigInt result;
	result.vec.clear();
	while (iter < left.vec.size() || temp != 0) {
		int left_digit = iter < left.vec.size() ? left.vec[iter] : 0;
		int right_digit = temp % 10;
		temp /= 10;
		result.vec.push_back((left_digit + right_digit + carry) % 10);
		carry = (left_digit + right_digit + carry) / 10;
		iter++;
	}
	if (carry == 1)result.vec.push_back(1);
	return result;
}

BigInt operator- (const BigInt& left, const int& right) {
	int iter = 0, borrow = 0, temp = right;
	BigInt result;
	result.vec.clear();
	while (iter < left.vec.size() || temp != 0) {
		int left_digit = iter < left.vec.size() ? left.vec[iter] : 0;
		int right_digit = temp % 10;
		temp /= 10;
		if (borrow == 1) {
			right_digit++;
			borrow = 0;
		}
		if (left_digit < right_digit && (iter + 1) < left.vec.size()) {
			left_digit += 10;
			borrow = 1;
		}
		result.vec.push_back((left_digit - right_digit) % 10);
		if ((int)result.vec[iter] < 0)
			return BigInt();
		iter++;
	}
	std::vector<char>::iterator digit = --result.vec.end();
	while (*digit == 0 && digit != result.vec.begin()) {
		--digit;
		result.vec.pop_back();
	}
	return result;
}

BigInt operator+ (const int& left, const BigInt& right) {
	int iter = 0, carry = 0, temp = left;
	BigInt result;
	result.vec.clear();
	while (temp != 0 || iter < right.vec.size()) {
		int left_digit = temp % 10;
		temp /= 10;
		int right_digit = iter < right.vec.size() ? right.vec[iter] : 0;
		result.vec.push_back((left_digit + right_digit + carry) % 10);
		carry = (left_digit + right_digit + carry) / 10;
		iter++;
	}
	if (carry == 1)result.vec.push_back(1);
	return result;
}

BigInt operator- (const int& left, const BigInt& right) {
	int iter = 0, carry = 0, borrow = 0, temp = left;
	BigInt result;
	result.vec.clear();
	while (temp != 0 || iter < right.vec.size()) {
		int left_digit = temp % 10;
		temp /= 10;
		int right_digit = iter < right.vec.size() ? right.vec[iter] : 0;
		if (borrow == 1) {
			right_digit++;
			borrow = 0;
		}
		if (left_digit < right_digit && temp != 0) {
			left_digit += 10;
			borrow = 1;
		}
		result.vec.push_back((left_digit - right_digit) % 10);
		if ((int)result.vec[iter] < 0)
			return BigInt();
		iter++;
	}
	std::vector<char>::iterator digit = --result.vec.end();
	while (*digit == 0 && digit != result.vec.begin()) {
		--digit;
		result.vec.pop_back();
	}
	return result;
}

void BigInt::operator+=(const BigInt& right) {
	*this = *this + right;
}

void BigInt::operator+=(const int& right) {
	*this = *this + right;
}

void BigInt::operator-=(const BigInt& right) {
	*this = *this - right;
}

void BigInt::operator-=(const int& right) {
	*this = *this - right;
}

BigInt BigInt::operator++() {
	*this = *this + 1;
	return *this;
}

BigInt BigInt::operator++(int) {
	BigInt temp(*this);
	++* this;
	return temp;
}

BigInt BigInt::operator--() {
	*this = *this - 1;
	return *this;
}

BigInt BigInt::operator--(int) {
	BigInt temp(*this);
	--* this;
	return temp;
}

bool operator<(const BigInt& left, const BigInt& right) {
	if (left.vec.size() < right.vec.size()) {
		return true;
	}
	else if (left.vec.size() > right.vec.size()) {
		return false;
	}
	else {
		std::vector<char>::const_reverse_iterator left_digit = left.vec.rbegin();
		std::vector<char>::const_reverse_iterator right_digit = right.vec.rbegin();
		while (left_digit != left.vec.rend() && right_digit != right.vec.rend()) {
			if (*left_digit < *right_digit) {
				return true;
			}
			else if (*left_digit > *right_digit) {
				return false;
			}
			else {
				++left_digit;
				++right_digit;
				continue;
			}
		}
		return false;
	}
}

bool operator<(const int& left, const BigInt& right) {
	int temp = left, temp_size = 1;
	while ((temp /= 10) != 0) {
		++temp_size;
	}
	if (temp_size < right.vec.size()) {
		return true;
	}
	else if (temp_size > right.vec.size()) {
		return false;
	}
	else {
		temp = left;
		int left_digit;
		std::vector<char>::const_reverse_iterator right_digit = right.vec.rbegin();
		while (temp != 0 && right_digit != right.vec.rend()) {
			left_digit = temp % 10;
			if (left_digit < *right_digit) {
				return true;
			}
			else if (left_digit > *right_digit) {
				return false;
			}
			else {
				temp /= 10;
				++right_digit;
				continue;
			}
		}
		return false;
	}
}

bool operator<(const BigInt& left, const int& right) {
	int temp = right, temp_size = 1;
	while ((temp /= 10) != 0) {
		++temp_size;
	}
	if (left.vec.size() < temp_size) {
		return true;
	}
	else if (left.vec.size() > temp_size) {
		return false;
	}
	else {
		temp = right;
		std::vector<char>::const_reverse_iterator left_digit = left.vec.rbegin();
		int right_digit;
		while (left_digit != left.vec.rend() && temp != 0) {
			right_digit = temp % 10;
			if (*left_digit < right_digit) {
				return true;
			}
			else if (*left_digit > right_digit) {
				return false;
			}
			else {
				++left_digit;
				temp /= 10;
				continue;
			}
		}
		return false;
	}
}

bool operator>(const BigInt& left, const BigInt& right) {
	return !(left < right) && !(left == right);
}

bool operator>(const int& left, const BigInt& right) {
	return !(left < right) && !(left == right);
}

bool operator>(const BigInt& left, const int& right) {
	return !(left < right) && !(left == right);
}

bool operator==(const BigInt& left, const BigInt& right) {
	if (left.vec.size() != right.vec.size()) {
		return false;
	}
	else {
		std::vector<char>::const_reverse_iterator left_digit = left.vec.rbegin();
		std::vector<char>::const_reverse_iterator right_digit = right.vec.rbegin();
		while (left_digit != left.vec.rend() && right_digit != right.vec.rend()) {
			if (*left_digit != *right_digit) {
				return false;
			}
			else {
				++left_digit;
				++right_digit;
				continue;
			}
		}
		return true;
	}
}

bool operator==(const int& left, const BigInt& right) {
	int temp = left, temp_size = 1;
	while ((temp /= 10) != 0) {
		++temp_size;
	}
	if (temp_size != right.vec.size()) {
		return false;
	}
	else {
		temp = left;
		int left_digit;
		std::vector<char>::const_reverse_iterator right_digit = right.vec.rbegin();
		while (temp != 0 && right_digit != right.vec.rend()) {
			left_digit = temp % 10;
			if (left_digit != *right_digit) {
				return false;
			}
			else {
				temp /= 10;
				++right_digit;
				continue;
			}
		}
		return true;
	}
}

bool operator==(const BigInt& left, const int& right) {
	int temp = right, temp_size = 1;
	while ((temp /= 10) != 0) {
		++temp_size;
	}
	if (left.vec.size() != temp_size) {
		return false;
	}
	else {
		temp = right;
		std::vector<char>::const_reverse_iterator left_digit = left.vec.rbegin();
		int right_digit;
		while (left_digit != left.vec.rend() && temp != 0) {
			right_digit = temp % 10;
			if (*left_digit != right_digit) {
				return false;
			}
			else {
				++left_digit;
				temp /= 10;
				continue;
			}
		}
		return true;
	}
}

bool operator<=(const BigInt& left, const BigInt& right) {
	return (left < right) || (left == right);
}

bool operator<=(const int& left, const BigInt& right) {
	return (left < right) || (left == right);
}

bool operator<=(const BigInt& left, const int& right) {
	return (left < right) || (left == right);
}

bool operator>=(const BigInt& left, const BigInt& right) {
	return (left > right) || (left == right);
}

bool operator>=(const int& left, const BigInt& right) {
	return (left > right) || (left == right);
}

bool operator>=(const BigInt& left, const int& right) {
	return (left > right) || (left == right);
}

void BigInt::print() {
	for (std::vector<char>::const_reverse_iterator iter = this->vec.rbegin(); iter != this->vec.rend(); ++iter) {
		std::cout << (int)*iter;
	}
	std::cout << std::endl;
}