#ifndef date_h
# define date_h
#include<iostream>
class date
{
    public:
        date();
        ~date();
        date(date const &src);
		date &operator=(const date&);
		bool operator<(const date&) const;
		bool operator>(const date&) const;
		bool operator==(const date &rhs) const;
		bool operator<=(const date &rhs) const;
		bool operator!=(const date &rhs) const;
        int getYear() const;
        int getMonth() const;
        int getDay() const;
        void setYear(int year);
        void setMonth(int month);
        void setDay(int day);
        std::string flag;
    private:
		int _year_;
		int _month_;
		int _day_;
};

#endif
