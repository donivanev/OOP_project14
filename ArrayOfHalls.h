#pragma once
#include "Hall.h"

const int halls = 10;

class ArrayOfHalls
{

private:
    vector<Ticket> tickets;
    vector<Event> events;
    Hall halls[halls];

public:

    void loadHalls();
    bool doEventExistsOnThisDate(DateTime d);
    void addEvent(DateTime d, int h, string n);
    void freeseats(DateTime d, string n);
    void book(int r, int s, DateTime d, string _name, string _note);
    void unbook(int r, int s, DateTime d, string n);
    void buy(int r, int s, DateTime d, string n);
    void bookings(DateTime d, string n, bool withoutName, bool withoutDate);
    void check(int r, int s);
    void report(DateTime dateFrom, DateTime dateTo, int h, int isHallNumberEmpty);

    friend ostream& operator << (ostream& output, const ArrayOfHalls& allHalls);
};

