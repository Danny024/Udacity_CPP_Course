#include <cassert>
#include <string>
#include <vector>

using std::vector;
using std::string;
// Header File
class Date {
 public:
  Date(int day, int month, int year);
  int Day() const ;
  void Day(int day);
  int Month() const ;
  void Month(int month);
  int Year() const;
  void Year(int year);
  std::string String() const;

 private:
  bool LeapYear(int year) const;
  int DaysInMonth(int month, int year) const;
  int day_;
  int month_;
  int year_;
};

// Implementation File
Date::Date(int day, int month, int year) {
  Year(year);
  Month(month);
  Day(day);
}

int Date::Day() const {
    return this->day_;
}

int Date::Month() const {
    return this->month_;
}

int Date::Year() const {
    return this->year_;
}

bool Date::LeapYear(int year) const {
  if (year % 4 != 0)
    return false;
  else if (year % 100 != 0)
    return true;
  else if (year % 400 != 0)
    return false;
  else
    return true;
}

// Implementation File 

int Date::DaysInMonth(int month, int year) const {
  if (month == 2)
    return LeapYear(year) ? 29 : 28;
  else if (month == 4 || month == 6 || month == 9 || month == 11)
    return 30;
  else
    return 31;
}

void Date::Day(int day) {
  if (day >= 1 && day <= DaysInMonth(Month(), Year())) day_ = day;
}

void Date::Month(int month) {
  if (month >= 1 && month <= 12) month_ = month;
}

void Date::Year(int year) {
  year_ = year;
}

std::string Date::String ()  const {
    vector <string> months {"January", "February", "March", "April", "May", "June","July","August", "September","October","November","December"};
    return months[Month()-1] + " " + std::to_string(Day()) + ", " + std::to_string(Year());

}

// Test File 
int main() {
  Date date(29, 8, 1981);
  assert(date.String() == "August 29, 1981");
  return 0;
}