#include"../inc/date.hpp"

date::date(){}
date::~date(){}
date::date(date const &src)
{
    *this = src;
}


date& date::operator=(const date& src)
{
	_year_ = src._year_;
	_month_ = src._month_;
	_day_ = src._day_;
	return *this;
}

bool date::operator>(const date &rhs) const
{
	if (_year_ > rhs._year_)
		return true;
	if (_year_ < rhs._year_)
		return false;
	if (_month_ > rhs._month_)
		return true;
	if (_month_ < rhs._month_)
		return false;
	if (_day_ > rhs._day_)
		return true;
	return false;
}

bool date::operator<(const date &rhs) const
{
	if (_year_ < rhs._year_)
		return true;
	if (_year_ > rhs._year_)
		return false;
	if (_month_ < rhs._month_)
		return true;
	if (_month_ > rhs._month_)
		return false;
	if (_day_ < rhs._day_)
		return true;
	return false;
}

bool date::operator<=(const date &rhs) const
{
	return (*this < rhs || *this == rhs);
}

bool date::operator==(const date &rhs) const
{
	return _year_ == rhs._year_ && _month_ == rhs._month_ && _day_ == rhs._day_;
}

bool date::operator!=(const date &rhs) const
{
	return !(*this == rhs);
}

int date::getYear() const
{
	return (_year_);
}

int date::getMonth() const
{
	return (_month_);
}

int date::getDay() const
{
	return(_day_);
}

void date::setYear(int year)
{
    _year_ = year;
}

void date::setMonth(int month)
{
    _month_ = month;
}

void date::setDay(int day)
{
    _day_ = day;
}
