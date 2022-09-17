#pragma once
#ifndef DECK_H
#define DECK_H
#include "Card.h"

class Deck {
private:
	int size = 0;
	int top_idx = 0;
	Card cards[52];
public:
	Deck();
	void refreshDeck();
	Card deal();
	void shuffle();
	bool isEmpty();
	void display();
};

#endif