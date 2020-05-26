#pragma once

#include <cstring>
#include <iostream>
using namespace std;

class DateTime
{
    int year, month, day;

public:
    DateTime(const int _y = 1, const int _m = 1, const int _d = 1);

    bool operator == (DateTime otherDateTime);
    bool operator < (DateTime otherDateTime);
    bool operator > (DateTime otherDateTime);
    bool operator <= (DateTime otherDateTime);
    bool operator >= (DateTime otherDateTime);
    int operator + (DateTime otherDateTime);
    int operator - (DateTime otherDateTime);

    int getDay();
    int getMonth();
    int getYear();

    friend ostream& operator << (ostream& output, const DateTime& dt);
};



