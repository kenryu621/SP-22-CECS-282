#ifndef MYDATE_H
#define MYDATE_H
#include <string>
class myDate {
 private:
  int day;
  int month;
  int year;

 public:
  myDate();
  myDate(int, int, int);
  void display();
  void increaseDate(int);
  void decreaseDate(int);
  void addMonth();
  int daysBetween(myDate);
  int getMonth();
  int getDay();
  int getYear();
  int dayOfYear();
  std::string dayName();
  std::string getDate();
  bool operator>(myDate);
  bool operator<(myDate);
  bool operator==(myDate);
};
#endif
