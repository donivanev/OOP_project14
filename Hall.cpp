#include "Hall.h"

Hall::Hall(const int n)
{
	this->number = n;

	ticketMatrix.resize(10);
	for (int i = 0; i < ticketMatrix.size(); i++)
	{
		ticketMatrix[i].resize(10);
		for (int j = 0; j < ticketMatrix[i].size(); j++)
		{
			ticketMatrix[i][j] = "free";
		}
	}
}

Hall::Hall(const Hall& other)
{
	number = other.number;
	ticketMatrix = other.ticketMatrix;
}

Hall& Hall::operator=(const Hall& other)
{
	if (this != &other)
	{
		number = other.number;
		ticketMatrix = other.ticketMatrix;
	}

	return *this;
}

int Hall::getNumber()
{
	return this->number;
}

int Hall::getRows()
{
	return 10;
}

int Hall::getSeats()
{
	return 10;
}

int Hall::getCapacity()
{
	return 100;
}

string Hall::getStatus(int row, int seat)
{
	return ticketMatrix[row - 1][seat - 1];
}

int Hall::getFreeSeats()
{
	int freeSeats = 0;

	for (int i = 0; i < ticketMatrix.size(); i++)
	{
		for (int j = 0; j < ticketMatrix[i].size(); j++)
		{
			if (ticketMatrix[i][j] == "free")
			{
				freeSeats++;
			}
		}
	}

	return freeSeats;
}

int Hall::getReservedTickets()
{
	int reservedTickets = 0;

	for (int i = 0; i < ticketMatrix.size(); i++)
	{
		for (int j = 0; j < ticketMatrix[i].size(); j++)
		{
			if (ticketMatrix[i][j] == "reserved")
			{
				reservedTickets++;
			}
		}
	}

	return reservedTickets;
}

int Hall::getBoughtTickets()
{
	int boughtTickets = 0;

	for (int i = 0; i < ticketMatrix.size(); i++)
	{
		for (int j = 0; j < ticketMatrix[i].size(); j++)
		{
			if (ticketMatrix[i][j] == "bought")
			{
				boughtTickets++;
			}
		}
	}

	return boughtTickets;
}

void Hall::changeStatus(int row, int seat, string stat)
{
	ticketMatrix[row - 1][seat - 1] = stat;
}

void Hall::addBooking(int row, int seat)
{
	ticketMatrix[row - 1][seat - 1] = "reserved";
}

void Hall::addBuying(int row, int seat)
{
	ticketMatrix[row - 1][seat - 1] = "bought";
}

void Hall::printSeats()
{
	for (int i = 0; i < ticketMatrix.size(); i++)
	{
		for (int j = 0; j < ticketMatrix[i].size(); j++)
		{
			cout << ticketMatrix[i][j];
		}
		cout << endl;
	}
}

ostream& operator << (ostream& output, const Hall& hall)
{
	output << "Hall number: " << hall.number << '\n' << "Hall rows: " << 10 << "\nHall seats: " << 10 << '\n';

	return output;
}