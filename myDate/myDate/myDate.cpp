#include "myDate.h"

#include <iostream>
#include <string>

int Greg_to_Jul(int yr, int mh, int dy) {
  return dy - 32075 + 1461 * (yr + 4800 + (mh - 14) / 12) / 4 +
         367 * (mh - 2 - (mh - 14) / 12 * 12) / 12 -
         3 * ((yr + 4900 + (mh - 14) / 12) / 100) / 4;
}

void Jul_to_Greg(int julian_date, int& yr, int& mh, int& dy) {
  julian_date += 68569;
  int temp = 4 * julian_date / 146097;
  julian_date = julian_date - (146097 * temp + 3) / 4;
  yr = 4000 * (julian_date + 1) / 1461001;
  julian_date = julian_date - 1461 * yr / 4 + 31;
  mh = 80 * julian_date / 2447;
  dy = julian_date - 2447 * mh / 80;
  julian_date = mh / 11;
  mh = mh + 2 - 12 * julian_date;
  yr = 100 * (temp - 49) + yr + julian_date;
}

myDate::myDate() {
  this->day = 11;
  this->month = 5;
  this->year = 1959;
}

myDate::myDate(int m, int d, int y) {
  int temp_year, temp_month, temp_day;
  Jul_to_Greg(Greg_to_Jul(y, m, d), temp_year, temp_month, temp_day);
  if (temp_year != y || temp_month != m || temp_day != d)
    this->myDate::myDate();
  else {
    this->day = d;
    this->month = m;
    this->year = y;
  }
}

void myDate::display() {
  std::string month_name;
  switch (this->month) {
    case 1:
      month_name = "January";
      break;
    case 2:
      month_name = "February";
      break;
    case 3:
      month_name = "March";
      break;
    case 4:
      month_name = "April";
      break;
    case 5:
      month_name = "May";
      break;
    case 6:
      month_name = "June";
      break;
    case 7:
      month_name = "July";
      break;
    case 8:
      month_name = "August";
      break;
    case 9:
      month_name = "September";
      break;
    case 10:
      month_name = "October";
      break;
    case 11:
      month_name = "November";
      break;
    case 12:
      month_name = "December";
      break;
    default:
      month_name = "N/A";
  }
  std::cout << month_name << " " << this->day << ", " << this->year;
}

void myDate::increaseDate(int num) {
  Jul_to_Greg(Greg_to_Jul(this->year, this->month, this->day) + num, this->year,
              this->month, this->day);
}

void myDate::decreaseDate(int num) {
  Jul_to_Greg(Greg_to_Jul(this->year, this->month, this->day) - num, this->year,
              this->month, this->day);
}

void myDate::addMonth() {
  int temp_month = this->month;
  Jul_to_Greg(Greg_to_Jul(this->year, ++this->month, this->day), this->year,
              this->month, this->day);
  if (this->month > temp_month % 12 + 1) this->myDate::decreaseDate(this->day);
}

int myDate::daysBetween(myDate second_date) {
  return Greg_to_Jul(second_date.getYear(), second_date.getMonth(),
                     second_date.getDay()) -
         Greg_to_Jul(this->year, this->month, this->day);
}

int myDate::getYear() { return this->year; }

int myDate::getMonth() { return this->month; }

int myDate::getDay() { return this->day; }

int myDate::dayOfYear() {
  return Greg_to_Jul(this->year, this->month, this->day) -
         Greg_to_Jul(this->year - 1, 12, 31);
}

std::string myDate::dayName() {
  switch (Greg_to_Jul(this->year, this->month, this->day) % 7) {
    case 0:
      return "Monday";
      break;
    case 1:
      return "Tuesday";
      break;
    case 2:
      return "Wednesday";
      break;
    case 3:
      return "Thursday";
      break;
    case 4:
      return "Friday";
      break;
    case 5:
      return "Saturday";
      break;
    case 6:
      return "Sunday";
      break;
    default:
      return "Error";
  }
}