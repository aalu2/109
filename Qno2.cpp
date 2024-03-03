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

  // Test Case 1
  cout << "Test Case 1 - Valid Date:\n";
  cout << "Please enter day: ";
  cin >> day;
  cout << "Please enter month: ";
  cin >> month;
  cout << "Please enter year: ";
  cin >> year;

  Date date1(day, month, year);
  date1.display();

  // Test Case 2
  cout << "\nTest Case 2 - Invalid Date (Defaulted to day/month=1/year):\n";
  cout << "Please enter day: ";
  cin >> day;
  cout << "Please enter month: ";
  cin >> month;
  cout << "Please enter year: ";
  cin >> year;

  Date date2(day, month, year);
  date2.display();

  system("pause");
  return 0;
}




