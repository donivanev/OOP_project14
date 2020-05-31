#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include "DateTime.h"
using namespace std;

class Ticket
{
private:
    int row, seat;
    DateTime date;
    string name, note, status;

public:
    Ticket(const int _r = 1, const int _s = 1, const DateTime _d = DateTime(), const string _note = "", 
        const string _name = "", const string stat = "");
    Ticket(const Ticket& other);
    void changeSettings(int r, int s, DateTime d, string _note, string _name, string stat);
    Ticket& operator=(const Ticket& other);

    int getRow();
    int getSeat();
    DateTime getDate();
    string getNote();
    string getName();
    string getStatus();

    friend ostream& operator << (ostream& output, const Ticket& ticket);
};
