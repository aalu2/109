#include <iostream>
using namespace std;

class Date
{
private:
  int day;
  int month;
  int year;

public:
  Date(int d, int m, int y);
  void setDay(int d);
  void setMonth(int m);
  void setYear(int y);
  int getDay() const;
  int getMonth() const;
  int getYear() const;
  void display() const;
};

Date::Date(int d, int m, int y)
{
  // Ensure month is in the range 1-12
  month = (m >= 1 && m <= 12) ? m : 1;

  // Ensure day is in the range 1-31
  day = (d >= 1 && d <= 31) ? d : 1;

  year = y;
}

void Date::setDay(int d)
{
  // Ensure day is in the range 1-31
  day = (d >= 1 && d <= 31) ? d : 1;
}

void Date::setMonth(int m)
{
  // Ensure month is in the range 1-12
  month = (m >= 1 && m <= 12) ? m : 1;
}

void Date::setYear(int y)
{
  year = y;
}

int Date::getDay() const
{
  return day;
}

int Date::getMonth() const
{
  return month;
}

int Date::getYear() const
{
  return year;
}

void Date::display() const
{
  cout << day << "/" << month << "/" << year << endl;
}

int main()
{
  int day, month, year;

  cout << "Please enter day: ";
  cin >> day;

  cout << "Please enter month: ";
  cin >> month;

  cout << "Please enter year: ";
  cin >> year;

  Date date(day, month, year);

  date.display();

  system("pause");
  return 0;
}


