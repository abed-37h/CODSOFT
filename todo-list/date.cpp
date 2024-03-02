#include <sstream>
#include <regex>
#include "date.h"

Date::Date() {
    time_t secondsSinceEpoch = time(0);
    tm now = *localtime(&secondsSinceEpoch);

    this->year(now.tm_year + 1900);
    this->month(now.tm_mon + 1);
    this->day(now.tm_mday);
    this->hour(now.tm_hour);
    this->minute(now.tm_min);
    this->second(now.tm_sec);
}

Date::Date(int _year, int _month, int _day, int _hour, int _minute, int _second)  {
    this->year(_year);
    this->month(_month);
    this->day(_day);
    this->hour(_hour);
    this->minute(_minute);
    this->second(_second);
}

std::string Date::toString(void) const {
    return std::to_string(this->_year) + "/" + std::to_string(this->_month) + "/" + std::to_string(this->_day) + "-"
        + std::to_string(this->_hour) + ":" + std::to_string(this->_minute) + ":" + std::to_string(this->_second);
}

void Date::year(const int _year) {
    if (_year < 0)
        throw InvalidDate(YEAR_OUT_OF_BOUND);

    this->_months = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(_year)) this->_months[1] = 29;
    else this->_months[1] = 28;
    
    this->_year = _year;
}

void Date::month(const int _month) {
    if (_month < 1 || _month > 12)
        throw InvalidDate(MONTH_OUT_OF_BOUND);

    this->_month = _month;
}

void Date::day(const int _day) {
    if (_month < 1 || _month > 12)
        throw InvalidDate(MONTH_OUT_OF_BOUND);
    if (isLeapYear(_year) && _month == 2 && (_day < 1 || _day > 29))
        throw InvalidDate(DAY_OUT_OF_BOUND_29);
    if (!isLeapYear(_year) && _month == 2 && (_day < 1 || _day > 28))
        throw InvalidDate(DAY_OUT_OF_BOUND_28);
    if (this->_months[_month] == 30 && (_day < 1 || _day > 30))
        throw InvalidDate(DAY_OUT_OF_BOUND_30);
    if (this->_months[_month] == 31 && (_day < 1 || _day > 31))
        throw InvalidDate(DAY_OUT_OF_BOUND_31);

    this->_day = _day;
}

void Date::hour(const int _hour) {
    if (_hour < 0 || _hour > 23)
        throw InvalidDate(HOUR_OUT_OF_BOUND);
    
    this->_hour = _hour;
}

void Date::minute(const int _minute) {
    if (_minute < 0 || _minute > 59)
        throw InvalidDate(MINUTE_OUT_OF_BOUND);
    
    this->_minute = _hour;
}

void Date::second(const int _second) {
    if (_second < 0 || _second > 59)
        throw InvalidDate(SECOND_OUT_OF_BOUND);
    
    this->_second = _second;
}

const int Date::year(void)const {
    return this->_year;
}

const int Date::month(void)const {
    return this->_month;
}

const int Date::day(void)const {
    return this->_day;
}

const int Date::hour(void) const {
    return this->_hour;
}

const int Date::minute(void) const {
    return this->_minute;
}

const int Date::second(void) const {
    return this->_second;
}

bool Date::operator==(const Date& _date) const {
    return (this->_year == _date._year && this->_month == _date._month && this->_day == _date._day
        && this->_hour == _date._hour && this->_minute == _date._minute && this->_second == _date._second);
}

bool Date::operator<(const Date& _date) const {
    if (this->_year != _date._year) return this->_year < _date._year;
    if (this->_month != _date._month) return this->_month < _date._month;
    if (this->_day != _date._day) return this->_day < _date._day;
    if (this->_hour != _date._hour) return this->_hour > _date._hour;
    if (this->_minute != _date._minute) return this->_minute < _date._minute;
    return this->_second < _date._second;
}

bool Date::operator>(const Date& _date) const {
    if (this->_year != _date._year) return this->_year > _date._year;
    if (this->_month != _date._month) return this->_month > _date._month;
    if (this->_day != _date._day) return this->_day > _date._day;
    if (this->_hour != _date._hour) return this->_hour > _date._hour;
    if (this->_minute != _date._minute) return this->_minute > _date._minute;
    return this->_second > _date._second;
}

std::istream& operator>>(std::istream& in, Date& _date) {
    char delim;
    in >> _date._year >> delim >> _date._month >> delim >> _date._day;
    
    _date._hour = _date._minute = _date._second = 0;

    if (in.peek() != '-') return in;

    in >> delim;
    in >> _date._hour;
    
    if (in.peek() != ':') return in;

    in >> delim;
    in >> _date._minute;

    if (in.peek() != ':') return in;

    in >> delim;
    in >> _date._second;

    return in;
}

std::ostream& operator<<(std::ostream& out, const Date& _date) {
    out << _date._year << '/' << _date._month << '/' << _date._day << '-'
        << _date._hour << ':' << _date._minute << ':' << _date._second;
    return out;
}

bool isLeapYear(int _year) {
    return (_year % 4 == 0 || _year % 400 == 0);
}