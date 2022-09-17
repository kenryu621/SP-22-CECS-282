#include "Card.h"
#include <iostream>

Card::Card() {
	this->rank = 'A';
	this->suit = 'S';
}

Card::Card(char r, char s) {
	setCard(r, s);
}

void Card::setCard(char r, char s) {
	if (s != 'S' && s != 'H' && s != 'C' && s != 'D') std::cout << "Error occured in setting suit for the card\n";
	else if ((r - '0' > 9 || r - '0' < 2) && (r != 'A' && r != 'J' && r != 'Q' && r != 'K' && r != 'X')) std::cout << "Error occured in setting rank for the card\n";
	else {
		this->rank = r;
		this->suit = s;
	}
}

int Card::getValue() {
	switch (this->rank) {
	case 'A':
		return 1;
		break;
	case 'J':
	case 'Q':
	case 'K':
	case 'X':
		return 10;
		break;
	default:
		return this->rank - '0';
	}
}

void Card::display() {
	switch (this->suit) {
	case 'S':
		std::cout << '\x06';
		break;
	case 'H':
		std::cout << '\x03';
		break;
	case 'C':
		std::cout << '\x05';
		break;
	case 'D':
		std::cout << '\x04';
		break;
	default:
		std::cout << "(Error Suit)";
	}
	if (this->rank == 'X') std::cout << "10";
	else std::cout << this->rank << " ";
}