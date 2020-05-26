#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include "DateTime.h"

class Event
{

private:
    DateTime date;
    string name;
    int numberOfHall;

public:

    Event(const DateTime _d = DateTime(), const string _name = "", const int halls = 1);
    Event(const Event& other);
    void changeSettings(DateTime _d, int _hall, string _name);
    Event& operator=(const Event& other);

    DateTime getDate();
    string getName();
    int getNumberOfHall();

    friend ostream& operator << (ostream& output, const Event& events);
};
