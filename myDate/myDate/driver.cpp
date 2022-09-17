// testdate.cpp
// Author: Steven H Gold
// CECS 282-04 (Tues/Thurs)
// Program #2 due date: March 1, 2022
//
//
//

#include "myDate.h" // X-code users change this to myDate.hpp
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  myDate Bday;
  myDate duedate(3, 1, 2022);

  int x;
  int month, day, year;
  int counter = 0;
  cout << "Test file for CECS 282 Section 4\n";
  Bday.display();
  cout << endl;
  duedate.display();
  cout << endl;
  x = Bday.daysBetween(duedate);
  cout << "Master Gold is " << x << " day old today";
  cout << endl;

  Bday.increaseDate(x);

  cout << "Now these 2 dates should be the same:";
  Bday.display();
  cout << '\t';
  duedate.display();
  cout << "\n\n";

  Bday.decreaseDate(x); // setting Bday back to original value

  month = duedate.getMonth();
  day = duedate.getDay();
  year = duedate.getYear();

  duedate.display();
  cout << " is also equal to " << month << "/" << day << "/" << year << endl;

  myDate July4(7, 4, 1776);
  cout << "The birth of the US was " << (July4.dayOfYear() - 1)
       << "days after New Years\n\n";

  myDate bogus(23, 12, 2007);
  cout << "The value of the bogus date is:";
  bogus.display();
  cout << endl;

  myDate D5(8, 21, 2019);
  x = D5.dayOfYear();
  D5.decreaseDate(x - 1);
  cout << "Happy Newyear 2019 happened on:";
  D5.display();
  cout << endl;

  cout << "Program is due on " << duedate.dayName() << endl;
  cout << "Master Gold was born on " << Bday.dayName() << endl;

  myDate today = duedate;
  cout << "\nHere are the dates for the next week:\n";
  for (int i = 0; i < 7; i++) {
    today.display();
    cout << ":" << today.dayName() << endl;
    today.increaseDate(1);
  }

  // find Friday the 13th
  myDate startDate(1, 1, 2010), endDate(12, 31, 2022), dayCounter(startDate);

  cout << "\n\nShow all unlucky days between ";
  startDate.display();
  cout << " and ";
  endDate.display();
  cout << endl;
  counter = 0;
  while (dayCounter.daysBetween(endDate) != 0) {
    int day = dayCounter.getDay();
    string dayName = dayCounter.dayName();
    if (dayName == "Friday" && day == 13) {
      cout << dayCounter.dayName() << " ";
      dayCounter.display();
      cout << endl;
      counter += 1;
    }
    dayCounter.increaseDate(1);
  }
  cout << "-------------------\nThat's " << counter << " unlucky days!\n";

  myDate test1(1, 31, 2024);
  myDate test2(test1);
  test2.addMonth();
  cout << "\nAdd one month to ";
  test1.display();
  cout << " and you get ";
  test2.display();
  cout << endl;

  test1 = myDate(5, 31, 2022);
  test2 = test1;
  test2.addMonth();
  cout << "\nAdd one month to ";
  test1.display();
  cout << " and you get ";
  test2.display();
  cout << endl;

  // find all the leap years since 1500
  counter = 1; // used for formatting output, 12 cols per row
  int leapSum = 0;
  cout << "\n\nLeap Years from 1500 to 2022\n\n";
  for (int y = 1500; y <= 2022; y++) {

    myDate leapYear = myDate(12, 31, y);
    // leapYear.display();
    // cout << ": ";
    // leapYear.dayOfYear();
    // cout << endl;
    if (leapYear.dayOfYear() == 366) {
      cout << y << ", ";
      leapSum++;
      if (counter++ % 12 == 0) {
        cout << endl;
      }
    }
  }
  cout << "\b\b "; // get rid of the last comma
  cout << "\n\nHere's the number of the above leapyears: " << leapSum << endl;
  cout << "\n\nPress enter to continue";
  getchar();
  return 0;
}
