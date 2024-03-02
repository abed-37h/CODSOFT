#ifndef date
#define date

#include <iostream>
#include <string>
#include <vector>
#include "invalidDate.h"

class Date {
public:
    Date();
    Date(int _year, int _month, int _day, int _hour = 0, int _minute = 0, int _second = 0);
    std::string toString(void) const;
    void year(const int _year);
    void month(const int _month);
    void day(const int _day);
    void hour(const int _hour);
    void minute(const int _minute);
    void second(const int _second);
    const int year(void) const;
    const int month(void) const;
    const int day(void) const;
    const int hour(void) const;
    const int minute(void) const;
    const int second(void) const;
    bool operator==(const Date& _date) const;
    bool operator<(const Date& _date) const;
    bool operator>(const Date& _date) const;
    friend std::istream& operator>>(std::istream& in, Date& _date);
    friend std::ostream& operator<<(std::ostream& out, const Date& _date);
private:
    std::vector<int> _months;
    int _year;
    int _month;
    int _day;
    int _hour;
    int _minute;
    int _second;
};

bool isLeapYear(int);

#endif
