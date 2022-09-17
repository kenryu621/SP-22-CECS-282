#include<iostream>
#include<iomanip>
#include<cstring>
#include"myDate.h"

const int SIZE = 10;

struct Movie {
	char name[100] = "";
	int movie_length = 0;
	float rating = 0;
	myDate release_date = myDate();
	std::string actor = "";
} *mov[SIZE];

void display(Movie* arr[]);
void allocate_movie(Movie* arr[]);
void sort_by_name(Movie* arr[]);
void sort_by_len(Movie* arr[]);
void sort_by_rate(Movie* arr[]);
void sort_by_date(Movie* arr[]);
void sort_by_actor(Movie* arr[]);

int main() {
	allocate_movie(mov);
	std::string user_input;
	int user_input_int = 0;
	while (user_input_int != 6) {
		std::cout << "1) Display list sorted by Name\n";
		std::cout << "2) Display list sorted by Running Time\n";
		std::cout << "3) Display list sorted by IMDB Rating\n";
		std::cout << "4) Display list sorted by Release Date\n";
		std::cout << "5) Display list sorted by Main Actor\n";
		std::cout << "6) Exit\nEnter your choice between 1 to 6: ";
		std::getline(std::cin, user_input, '\n');
		std::cout << "\n";
		try { user_input_int = std::stoi(user_input); }
		catch (...) { user_input_int = -1; }
		switch (user_input_int) {
		case 1:
			sort_by_name(mov);
			display(mov);
			break;
		case 2:
			sort_by_len(mov);
			display(mov);
			break;
		case 3:
			sort_by_rate(mov);
			display(mov);
			break;
		case 4:
			sort_by_date(mov);
			display(mov);
			break;
		case 5:
			sort_by_actor(mov);
			display(mov);
			break;
		case 6:
			std::cout << "Exiting program...\n";
			break;
		default:
			std::cout << "Invalid input, please try again.\n\n";
		}
	}
	return 0;
}

void display(Movie* arr[]) {
	std::cout << std::left << std::setw(30) << "Name" << std::left << std::setw(15) << "Running Time" << std::left << std::setw(15) << "IMDB Rating" << std::left << std::setw(20) << "Release Date" << std::left << std::setw(30) << "Actor" << std::endl;
	for (int i = 0; i < SIZE; i++) {
		std::string time = std::to_string(arr[i]->movie_length / 60) + "h";
		if (arr[i]->movie_length % 60 != 0)
			time += " " + std::to_string(arr[i]->movie_length % 60) + "m";
		std::cout << std::left << std::setw(30) << arr[i]->name << std::left << std::setw(15) << time << std::left << std::setw(15) << arr[i]->rating << std::left << std::setw(20) << arr[i]->release_date.getDate() << std::left << std::setw(30) << arr[i]->actor << std::endl;
	}
	std::cout << "\n";
}

void allocate_movie(Movie* arr[]) {
	for (int i = 0; i < SIZE; i++) {
		arr[i] = new Movie();
		switch (i) {
		case 0:
			strcpy_s(arr[i]->name, "Spider-Man: No Way Home");
			arr[i]->movie_length = 148;
			arr[i]->rating = float(8.7);
			arr[i]->release_date = myDate(12, 13, 2021);
			arr[i]->actor = "Tom Holland";
			break;
		case 1:
			strcpy_s(arr[i]->name, "Dune");
			arr[i]->movie_length = 155;
			arr[i]->rating = float(8.1);
			arr[i]->release_date = myDate(9, 3, 2021);
			arr[i]->actor = "Timothee Chalamet";
			break;
		case 2:
			strcpy_s(arr[i]->name, "Free Guy");
			arr[i]->movie_length = 115;
			arr[i]->rating = float(7.2);
			arr[i]->release_date = myDate(8, 13, 2021);
			arr[i]->actor = "Ryan Reynolds";
			break;
		case 3:
			strcpy_s(arr[i]->name, "Joker");
			arr[i]->movie_length = 122;
			arr[i]->rating = float(8.4);
			arr[i]->release_date = myDate(9, 28, 2019);
			arr[i]->actor = "Joaquin Phoenix";
			break;
		case 4:
			strcpy_s(arr[i]->name, "Avengers: Endgame");
			arr[i]->movie_length = 181;
			arr[i]->rating = float(8.4);
			arr[i]->release_date = myDate(4, 22, 2019);
			arr[i]->actor = "Robert Downey Jr.";
			break;
		case 5:
			strcpy_s(arr[i]->name, "Avengers: Infinity War");
			arr[i]->movie_length = 149;
			arr[i]->rating = float(8.5);
			arr[i]->release_date = myDate(4, 23, 2018);
			arr[i]->actor = "Robert Downey Jr.";
			break;
		case 6:
			strcpy_s(arr[i]->name, "Shang-Chi");
			arr[i]->movie_length = 132;
			arr[i]->rating = float(7.5);
			arr[i]->release_date = myDate(8, 16, 2021);
			arr[i]->actor = "Simu Liu";
			break;
		case 7:
			strcpy_s(arr[i]->name, "The Wolf of Wall Street");
			arr[i]->movie_length = 180;
			arr[i]->rating = float(8.2);
			arr[i]->release_date = myDate(12, 17, 2013);
			arr[i]->actor = "Leonardo DiCarpio";
			break;
		case 8:
			strcpy_s(arr[i]->name, "Just Mercy");
			arr[i]->movie_length = 137;
			arr[i]->rating = float(7.6);
			arr[i]->release_date = myDate(10, 3, 2019);
			arr[i]->actor = "Michael B. Jordan";
			break;
		case 9:
			strcpy_s(arr[i]->name, "Dunkirk");
			arr[i]->movie_length = 106;
			arr[i]->rating = float(7.8);
			arr[i]->release_date = myDate(7, 19, 2017);
			arr[i]->actor = "Fionn Whitehead";
			break;
		default:
			strcpy_s(arr[i]->name, "The Matrix");
			arr[i]->movie_length = 136;
			arr[i]->rating = float(8.7);
			arr[i]->release_date = myDate(3, 24, 1999);
			arr[i]->actor = "Keanu Reeves";
		}
	}
}

void sort_by_name(Movie* arr[]) {
	for (int i = 0; i < SIZE - 1; i++)
		if (int(arr[i]->name[0]) > int(arr[i + 1]->name[0]))
			for (int j = i + 1; j > 0; j--) {
				if (int(arr[j]->name[0]) < int(arr[j - 1]->name[0])) {
					Movie* temp = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = temp;
				}
				else { break; }
			}
}

void sort_by_len(Movie* arr[]) {
	for (int i = 0; i < SIZE - 1; i++)
		if (arr[i]->movie_length < arr[i + 1]->movie_length)
			for (int j = i + 1; j > 0; j--) {
				if (arr[j]->movie_length > arr[j - 1]->movie_length) {
					Movie* temp = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = temp;
				}
				else { break; }
			}
}

void sort_by_rate(Movie* arr[]) {
	for (int i = 0; i < SIZE - 1; i++)
		if (arr[i]->rating < arr[i + 1]->rating)
			for (int j = i + 1; j > 0; j--) {
				if (arr[j]->rating > arr[j - 1]->rating) {
					Movie* temp = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = temp;
				}
				else { break; }
			}
}

void sort_by_date(Movie* arr[]) {
	for (int i = 0; i < SIZE - 1; i++)
		if (arr[i]->release_date > arr[i + 1]->release_date)
			for (int j = i + 1; j > 0; j--) {
				if (arr[j]->release_date < arr[j - 1]->release_date) {
					Movie* temp = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = temp;
				}
				else { break; }
			}
}

void sort_by_actor(Movie* arr[]) {
	for (int i = 0; i < SIZE - 1; i++)
		if (int(arr[i]->actor[0]) > int(arr[i + 1]->actor[0]))
			for (int j = i + 1; j > 0; j--) {
				if (int(arr[j]->actor[0]) < int(arr[j - 1]->actor[0])) {
					Movie* temp = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = temp;
				}
				else { break; }
			}
}