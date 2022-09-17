#include <iostream>
#include "Deck.h"
#include <time.h>
#include <math.h>

bool check_fibonacci(int num) {
	return sqrt(5 * num * num + 4) == (int)sqrt(5 * num * num + 4) || sqrt(5 * num * num - 4) == (int)sqrt(5 * num * num - 4);
}

void play(Deck deck) {
	bool winning = false;
	int curr_sum = 0;
	int pile_count = 1;
	while (!deck.isEmpty()) {
		Card topCard = deck.deal();
		curr_sum += topCard.getValue();
		topCard.display();
		std::cout << ", ";
		if (check_fibonacci(curr_sum)) {
			std::cout << "Fibo: " << curr_sum << std::endl;
			curr_sum = 0;
			pile_count++;
			if (deck.isEmpty()) winning = true;
		}
	}
	if (winning) std::cout << "Winner in " << pile_count << " pile(s)!\n";
	else std::cout << "Last hand value: " << curr_sum << "\nLoser in " << pile_count << " pile(s)!\n";
}

int main() {
	srand(time(0));
	Deck new_deck = Deck();
	char user_input;
	std::cout << "Welcome to Fibonacci Solitaire!\n";
	do {
		std::cout << "1) New deck\n";
		std::cout << "2) Display deck\n";
		std::cout << "3) Shuffle deck\n";
		std::cout << "4) Play Solitaire\n";
		std::cout << "5) Exit\n";
		std::cout << "Please enter an option from the menu above: ";
		std::cin >> user_input;
		switch (user_input) {
		case '1':
			std::cout << "You have a new deck now.\n";
			new_deck.refreshDeck();
			break;
		case'2':
			std::cout << "Displaying your deck.\n";
			new_deck.display();
			break;
		case'3':
			std::cout << "Your deck is shuffled.\n";
			new_deck.shuffle();
			break;
		case'4':
			std::cout << "Playing Fibonacci Solitaire !!!\n\n";
			play(new_deck);
			break;
		case'5':
			std::cout << "Exiting...\n";
			break;
		default:
			std::cout << "Please enter a valid input.\n";
		}
		std::cout << std::endl;
	} while (user_input != '5');
	return 0;
}