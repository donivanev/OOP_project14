#include "Event.h"

Event::Event(const DateTime _d, const string _name, const int num)
{
    this->date = _d;
    this->name = _name;
    this->numberOfHall = num;
}

Event::Event(const Event& other)
{
    date = other.date;
    name = other.name;
    numberOfHall = other.numberOfHall;
}

void Event::changeSettings(DateTime _d, int _hall, string _name)
{
    this->date = _d;
    this->name = _name;
    this->numberOfHall = _hall;
}

Event& Event::operator=(const Event& other)
{
    if (this != &other)
    {
        date = other.date;
        name = other.name;
        numberOfHall = other.numberOfHall;
    }

    return *this;
}

DateTime Event::getDate()
{
    return this->date;
}

string Event::getName()
{
    return this->name;
}

int Event::getNumberOfHall()
{
	return this->numberOfHall;
}

ostream& operator << (ostream& output, const Event& events)
{
    output << "Date: " << events.date << "\nNumber of hall: " << events.numberOfHall << "\nName of the event: " << events.name << endl;
   
    return output;
}