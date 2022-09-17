#include "Deck.h"
#include <iostream>

Deck::Deck() {
	char temp_rank, temp_suit;
	for (int s = 0; s < 4; s++) {
		for (int r = 1; r <= 13; r++) {
			switch (s) {
			case 0:
				temp_suit = 'S';
				break;
			case 1:
				temp_suit = 'H';
				break;
			case 2:
				temp_suit = 'C';
				break;
			case 3:
				temp_suit = 'D';
				break;
			}
			switch (r) {
			case 1:
				temp_rank = 'A';
				break;
			case 11:
				temp_rank = 'J';
				break;
			case 12:
				temp_rank = 'Q';
				break;
			case 13:
				temp_rank = 'K';
				break;
			case 10:
				temp_rank = 'X';
				break;
			default:
				temp_rank = r + '0';
			}
			this->cards[size].setCard(temp_rank, temp_suit);
			this->size++;
		}
	}
}

void Deck::refreshDeck() {
	*this = {};
}

Card Deck::deal() {
	return this->cards[this->top_idx++];
}

bool Deck::isEmpty() {
	return this->top_idx == this->size;
}

void Deck::display() {
	for (int i = top_idx; i < this->size; i++) {
		this->cards[i].display();
		if ((i + 1) % 13 == 0 || i + 1 == this->size) std::cout << "\n";
		else std::cout << " ";
	}
}

void Deck::shuffle() {
	for (int i = this->top_idx; i < this->size; i++) {
		int second_idx = rand() % (this->size - this->top_idx) + this->top_idx;
		Card first_card = this->cards[i];
		this->cards[i] = this->cards[second_idx];
		this->cards[second_idx] = first_card;
	}
}