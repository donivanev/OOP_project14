#include "DateTime.h"

DateTime::DateTime(const int _y, const int _m, const int _d)
{
    this->year = _y;
    this->month = _m;
    this->day = _d;
}

bool DateTime::operator == (DateTime otherDateTime)
{
    if (this->year == otherDateTime.year && this->month == otherDateTime.month && this->day == otherDateTime.day)
    {
        return true;
    }
    return false;
}

bool DateTime::operator < (DateTime otherDateTime)
{
    if (this->year < otherDateTime.year)
    {
        return true;
    }
    else if (this->year == otherDateTime.year && this->month < otherDateTime.month)
    {
        return true;
    }
    else if (this->year == otherDateTime.year && this->month == otherDateTime.month && this->day < otherDateTime.day)
    {
        return true;
    }

    return false;
}

bool DateTime::operator <= (DateTime otherDateTime)
{
    if (this->year < otherDateTime.year)
    {
        return true;
    }
    else if (this->year == otherDateTime.year && this->month < otherDateTime.month)
    {
        return true;
    }
    else if (this->year == otherDateTime.year && this->month == otherDateTime.month && this->day <= otherDateTime.day)
    {
        return true;
    }

    return false;
}

bool DateTime::operator > (DateTime otherDateTime)
{
    if (this->year > otherDateTime.year)
    {
        return true;
    }
    else if (this->year == otherDateTime.year && this->month > otherDateTime.month)
    {
        return true;
    }
    else if (this->year == otherDateTime.year && this->month == otherDateTime.month && this->day > otherDateTime.day)
    {
        return true;
    }

    return false;
}

bool DateTime::operator >= (DateTime otherDateTime)
{
    if (this->year > otherDateTime.year)
    {
        return true;
    }
    else if (this->year == otherDateTime.year && this->month > otherDateTime.month)
    {
        return true;
    }
    else if (this->year == otherDateTime.year && this->month == otherDateTime.month && this->day >= otherDateTime.day)
    {
        return true;
    }

    return false;
}

int DateTime::operator + (DateTime otherDateTime)
{
    bool isLeap = false;
    if (this->year % 4 == 0) if (this->year % 100 == 0) if (this->year % 400 == 0) isLeap = true;

    if (this->year == otherDateTime.year && this->month == otherDateTime.month)
    {
        return this->day + otherDateTime.day;
    }
    else if (this->year == otherDateTime.year)
    {
        int monthInDays = 0, otherMonthInDays = 0;

        if (this->month % 2 == 0)
        {
            if (this->month == 2)
            {
                if (isLeap)
                {
                    monthInDays = this->month * 29;
                }
                else
                {
                    monthInDays = this->month * 28;
                }
            }
            else
            {
                monthInDays = this->month * 30;
            }
        }
        else
        {
            monthInDays = this->month * 31;
        }

        isLeap = false;
        if (otherDateTime.year % 4 == 0) if (otherDateTime.year % 100 == 0) if (otherDateTime.year % 400 == 0) isLeap = true;

        if (otherDateTime.month % 2 == 0)
        {
            if (otherDateTime.month == 2)
            {
                if (isLeap)
                {
                    otherMonthInDays = otherDateTime.month * 29;
                }
                else
                {
                    otherMonthInDays = otherDateTime.month * 28;
                }
            }
            else
            {
                otherMonthInDays = otherDateTime.month * 30;
            }
        }
        else
        {
            otherMonthInDays = otherDateTime.month * 31;
        }

        return (monthInDays + this->day) + (otherMonthInDays + otherDateTime.day);

    }
    else if (this->year == otherDateTime.year && this->month == otherDateTime.month && this->day > otherDateTime.day)
    {
        cout << "One year in the hotel is too much!" << endl;
    }
}


int DateTime::operator - (DateTime otherDateTime)
{
    bool isLeap = false;
    if (this->year % 4 == 0) if (this->year % 100 == 0) if (this->year % 400 == 0) isLeap = true;

    if (this->year == otherDateTime.year && this->month == otherDateTime.month)
    {
        return this->day - otherDateTime.day;
    }
    else if (this->year == otherDateTime.year)
    {
        int monthInDays = 0, otherMonthInDays = 0;

        if (this->month % 2 == 0)
        {
            if (this->month == 2)
            {
                if (isLeap)
                {
                    monthInDays = this->month * 29;
                }
                else
                {
                    monthInDays = this->month * 28;
                }
            }
            else
            {
                monthInDays = this->month * 30;
            }
        }
        else
        {
            monthInDays = this->month * 31;
        }

        isLeap = false;
        if (otherDateTime.year % 4 == 0) if (otherDateTime.year % 100 == 0) if (otherDateTime.year % 400 == 0) isLeap = true;

        if (otherDateTime.month % 2 == 0)
        {
            if (otherDateTime.month == 2)
            {
                if (isLeap)
                {
                    otherMonthInDays = otherDateTime.month * 29;
                }
                else
                {
                    otherMonthInDays = otherDateTime.month * 28;
                }
            }
            else
            {
                otherMonthInDays = otherDateTime.month * 30;
            }
        }
        else
        {
            otherMonthInDays = otherDateTime.month * 31;
        }

        return (monthInDays + this->day) - (otherMonthInDays + otherDateTime.day);

    }
    else if (this->year == otherDateTime.year && this->month == otherDateTime.month && this->day > otherDateTime.day)
    {
        cout << "One year in the hotel is too much!" << endl;
    }
}

int DateTime::getDay()
{
    return this->day;
}

int DateTime::getMonth()
{
    return this->month;
}

int DateTime::getYear()
{
    return this->year;
}

ostream& operator << (ostream& output, const DateTime& dt)
{
    output << dt.year << " " << dt.month << " " << dt.day;
    return output;
}