#include "ArrayOfHalls.h"

void ArrayOfHalls::loadHalls()
{
    for (int i = 0; i < 10; i++)
    {
        Hall hall(i + 1);
        halls[i] = hall;
    }
}

bool ArrayOfHalls::doEventExistsOnThisDate(DateTime d)
{
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i].getDate() == d)
        {
            return true;
        }
    }

    return false;
}

void ArrayOfHalls::addEvent(DateTime d, int h, string n)
{
    if (doEventExistsOnThisDate(d))
    {
        cout << "There is already such event on this date" << endl;
    }
    else
    {
        Event event(d, n, h);
        events.push_back(event);
        cout << "Event added." << endl;
    }

    cout << endl;
}

void ArrayOfHalls::freeseats(DateTime d, string n)
{
    bool isValid = false;

    for (int i = 0; i < events.size(); i++)
    {
        if (events[i].getDate() == d && events[i].getName() == n)
        {
            isValid = true;
            cout << "The performance \"" << events[i].getName() << "\" on " << events[i].getDate() << " has "
                << halls[events[i].getNumberOfHall() - 1].getFreeSeats() << " free tickets." << endl;
        }
    }

    if (isValid != true)
    {
        cout << "No such event." << endl;
    }

    cout << endl;
}

void ArrayOfHalls::book(int r, int s, DateTime d, string _name, string _note)
{
    bool isValid = false;

    for (int i = 0; i < events.size(); i++)
    {
        if (events[i].getName() == _name && r <= 10 && s <= 10)
        {
            Ticket ticket(r, s, d, _name, _note, "reserved");
            tickets.push_back(ticket);
            halls[events[i].getNumberOfHall() - 1].addBooking(r, s);
            isValid = true;
        }
    }

    if (isValid == true)
    {
        cout << "You successfully booked a ticket." << endl;
    }
    else
    {
        if (r > 10)
        {
            cout << "Sorry no such row in this hall." << endl;
        }
        else if (s > 10)
        {
            cout << "Sorry no such row in this hall." << endl;
        }
        else
        {
            cout << "Sorry. There isn't an event called \"" << _name << "\"." << endl;
        }
    }

    cout << endl;
}

void ArrayOfHalls::unbook(int r, int s, DateTime d, string n)
{
    bool isValid = false;

    for (int i = 0; i < events.size(); i++)
    {
        if (events[i].getName() == n && halls[events[i].getNumberOfHall() - 1].getStatus(r, s) == "reserved")
        {
            halls[events[i].getNumberOfHall() - 1].changeStatus(r, s, "free");
            isValid = true;
        }
    }

    if (isValid == true)
    {
        cout << "You successfully unbooked a ticket." << endl;
    }
    else
    {
        cout << "Something went wrong. Try unbooking a ticket with valid data." << endl;
    }

    cout << endl;
}

void ArrayOfHalls::buy(int r, int s, DateTime d, string n)
{
    bool isValid = false;

    for (int i = 0; i < events.size(); i++)
    {
        if (events[i].getName() == n && r <= 10 && s <= 10)
        {
            if (halls[events[i].getNumberOfHall() - 1].getStatus(r, s) == "free")
            {
                Ticket ticket(r, s, d, n, " ", "bought");
                tickets.push_back(ticket);
                halls[events[i].getNumberOfHall() - 1].addBuying(r, s);
            }
            else if (halls[events[i].getNumberOfHall() - 1].getStatus(r, s) == "reserved")
            {
                halls[events[i].getNumberOfHall() - 1].changeStatus(r, s, "bought");
            }
            isValid = true;
        }
    }

    if (isValid == true)
    {
        cout << "You successfully bought a ticket." << endl;
    }
    else
    {
        if (r > 10)
        {
            cout << "Sorry no such row in this hall." << endl;
        }
        else if (s > 10)
        {
            cout << "Sorry no such row in this hall." << endl;
        }
        else
        {
            cout << "Sorry. There isn't an event called \"" << n << "\"." << endl;
        }
    }

    cout << endl;
}

void ArrayOfHalls::bookings(DateTime d, string n, bool withoutName, bool withoutDate)
{
    if (withoutName == true || withoutDate == true)
    {
        if (withoutName == true && withoutDate == true)
        {
            // No name and date
            cout << "Please enter at least date or a name." << endl;
            cout << endl;
        }
        else if (withoutName == true)
        {
            // No name
            // Ако <name> е пропуснато, извежда информация за всички представления на дадената дата 
            for (int i = 0; i < events.size(); i++)
            {
                if (events[i].getDate() == d)
                {
                    cout << events[i] << endl;
                }
            }
            cout << endl;
        }
        else if (withoutDate == true)
        {
            // No date
            // Ако <date> е пропуснато, извежда информация за всички дати.
            for (int i = 0; i < events.size(); i++)
            {
                cout << events[i] << endl;
            }
            cout << endl;
        }
    }
    else
    {
        //Has name and date
        int counter = 0;
        for (int i = 0; i < events.size(); i++)
        {
            if (events[i].getDate() == d && events[i].getName() == n)
            {
                for (int j = 2; j < 11; j++)
                {
                    for (int k = 2; k < 11; k++)
                    {
                        if (halls[events[i].getNumberOfHall() - 1].getStatus(j, k) == "reserved")
                        {
                            counter++;
                        }
                    }
                }
            }
        }

        cout << "There are " << counter << " tickets reserved for the \"" << n << "\" event on " << d << endl;
        cout << endl;
    }
}

void ArrayOfHalls::check(int r, int s)
{
    int row = r, seat = s;
    bool isValid = false;

    for (int i = 0; i < events.size(); i++)
    {
        for (int j = 2; j < 11; j++)
        {
            for (int k = 2; k < 11; k++)
            {
                if (r == j && s == k)
                {
                    if (halls[events[i].getNumberOfHall() - 1].getStatus(r, s) == "bought")
                    {
                        isValid = true;
                    }
                }
            }
        }
    }

    if (isValid)
    {
        cout << "This ticket is valid." << endl;
    }
    else
    {
        cout << "This ticket is invalid." << endl;
    }

    cout << endl;
}

void ArrayOfHalls::report(DateTime dateFrom, DateTime dateTo, int h, int isHallNumberEmpty)
{
    if (isHallNumberEmpty)
    {
        for (int i = 0; i < events.size(); i++)
        {
            if (events[i].getDate() >= dateFrom && events[i].getDate() <= dateTo)
            {
                cout << events[i] << "Number of bought tickets: " << halls[events[i].getNumberOfHall() - 1].getBoughtTickets() << endl;
            }
        }
    }
    else
    {
        for (int i = 0; i < events.size(); i++)
        {
            if (events[i].getDate() >= dateFrom && events[i].getDate() <= dateTo)
            {
                if (events[i].getNumberOfHall() == h)
                {
                    cout << events[i] << "Number of bought tickets: " << halls[events[i].getNumberOfHall() - 1].getBoughtTickets() << endl;
                }
            }
        }
    }

    cout << endl;
}

ostream& operator << (ostream& output, const ArrayOfHalls& allHalls)
{
    for (int i = 0; i < 10; i++)
    {
        output << allHalls.halls[i] << endl;
    }

    for (Event e : allHalls.events)
    {
        output << e << endl;
    }

    for (Ticket t : allHalls.tickets)
    {
        output << t << endl;
    }

    return output;
}
