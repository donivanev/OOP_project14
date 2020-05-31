#include "Ticket.h"

Ticket::Ticket(const int _r, const int _s, const DateTime _d, const string _note, const string _name, string stat)
{
    this->row = _r;
    this->seat = _s;
    this->date = _d;
    this->note = _note;
    this->name = _name;
    this->status = stat;
}

Ticket::Ticket(const Ticket& other)
{
    row = other.row;
    seat = other.seat;
    date = other.date;
    note = other.note;
    name = other.name;
    status = other.status;
}

void Ticket::changeSettings(int r, int s, DateTime d, string _note, string _name, string stat)
{
    row = r;
    seat = s;
    date = d;
    note = _note;
    name = _name;
    status = stat;
}

Ticket& Ticket::operator=(const Ticket& other)
{
    if (this != &other)
    {
        row = other.row;
        seat = other.seat;
        date = other.date;
        note = other.note;
        name = other.name;
        status = other.status;
    }

    return *this;
}

int Ticket::getRow()
{
    return this->row;
}

int Ticket::getSeat()
{
    return this->seat;
}

DateTime Ticket::getDate()
{
    return this->date;
}

string Ticket::getNote()
{
    return this->note;
}

string Ticket::getName()
{
    return this->name;
}

string Ticket::getStatus()
{
    return this->status;
}

ostream& operator << (ostream& output, const Ticket& ticket)
{
    output << "Ticket row: " << ticket.row << '\n' << "Ticket seat: " << ticket.seat << 
        "\nTicket date: " << ticket.date << '\n' << "Note: " << ticket.note << "\nName: " << ticket.name << endl;

    return output;
}