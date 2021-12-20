#ifndef _KP3_INCLUDE_KP3_DATE_H_
#define _KP3_INCLUDE_KP3_DATE_H_

#include <iostream>

class Date
{
public:
  Date();
  Date(int day, int month, int year);
  Date(const Date &copy);
  ~Date();

  // Getters
  int GetDay();
  int GetMonth();
  int GetYear();

  // Selectors
  Date &SetDay(int day);
  Date &SetMonth(int month);
  Date &SetYear(int year);

  // Extra functions
  void Print();
  static bool IsYearLeap(int year);

  // Operators
  bool operator==(const Date &copy);
  bool operator!=(const Date &copy);

  Date operator+(const Date &obj);

  friend std::ostream &operator<<(std::ostream &out, const Date &obj);
  friend std::istream &operator>>(std::istream &in, Date &obj);

private:
  int day_, month_, year_;
}; // Class (Date)

#endif // Header Guard