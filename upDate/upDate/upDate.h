#pragma once
#include <string>
#include <iostream>

class upDate
{
private:
	int *ptr = new int[3];
	static int count;

public:
	upDate();					 // Default constructor
	upDate(int M, int D, int Y); // Overloaded constructor with gregorian date
	upDate(int);				 // Overloaded constructor with julian date
	upDate(const upDate &);		 // Overloaded constructor with upDate
	~upDate();					 // Destructor
	void setDate(int, int, int);
	// void display();
	// void increaseDate(int);
	// void decreaseDate(int);
	// void addMonth();
	// int daysBetween(upDate);
	int getMonth();
	int getDay();
	int getYear();
	// int dayOfYear();
	// std::string dayName();
	std::string getMonthName();
	static int GetDateCount();
	upDate &operator=(upDate);
	upDate &operator+=(int);
	upDate& operator-=(int);
	friend upDate operator+(upDate, int);
	friend upDate operator-(upDate, int);
	friend upDate operator+(int, upDate);
	friend int operator-(upDate, upDate);
	friend std::ostream &operator<<(std::ostream &, upDate);
	friend upDate operator++(upDate&);
	friend upDate operator++(upDate&, int);
	friend upDate operator--(upDate&);
	friend upDate operator--(upDate&, int);
	int julian();
	friend bool operator==(upDate, upDate);
	friend bool operator<(upDate, upDate);
	friend bool operator>(upDate, upDate);
};