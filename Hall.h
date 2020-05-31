#pragma once
#include <vector>
#include "Ticket.h"
#include "Event.h"

class Hall
{
private:

	int number;
	vector<vector<string>> ticketMatrix;

public:

	Hall(const int number = 1);
	Hall(const Hall& other);
	Hall& operator=(const Hall& other);

	int getNumber();
	int getRows();
	int getSeats();
	int getCapacity();

	string getStatus(int row, int seat);
	int getFreeSeats();
	int getReservedTickets();
	int getBoughtTickets();

	void changeStatus(int row, int seat, string stat);
	void addBooking(int row, int seat);
	void addBuying(int row, int seat);

	void printSeats();
	friend ostream& operator << (ostream& output, const Hall& hall);
};

