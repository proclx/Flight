#include <string>
#include <iostream>
#include "Flight.h"

Flight::Flight(const std::string air_company, const unsigned flight_number, const std::string& destination)
{
	flight_air_company = air_company;
	flight_flight_number = flight_number;
	flight_destination = destination;
}

Flight::Flight()
{
	flight_air_company = "";
	flight_flight_number = 0;
	flight_destination = "";
}

Flight::Flight(const Flight& flight)
{
	flight_air_company = flight.flight_air_company;
	flight_destination = flight.flight_destination;
	flight_flight_number = flight.flight_flight_number;
}

Flight::~Flight()
{
	flight_air_company = "";
	flight_flight_number = 0;
	flight_destination = "";
}

std::string Flight::getAirCompany() const
{
	return flight_air_company;
}

unsigned Flight::getFlightNumber() const
{
	return flight_flight_number;
}

std::string Flight::getFlightDestination() const
{
	return flight_destination;
}

void Flight::setAirCompany(const std::string& air_company)
{
	flight_air_company = air_company;
}

void Flight::setFlightNumber(const unsigned flight_number)
{
	flight_flight_number = flight_number;
}

void Flight::setFlightDestination(const std::string& destination)
{
	flight_destination = destination;
}

void Flight::beautifulPrint(std::ostream& out) const
{
	out << getAirCompany() << " #";
	for (unsigned i = 10000; i > 1; i /= 10)
	{
		if (i >= getFlightNumber())
		{
			out << '0';
		}
		else
		{
			out << getFlightNumber();
			break;
		}
	}
	out << ' ' << getFlightDestination() << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Flight& flight)
{
	out << flight.getAirCompany() << ' ' << flight.getFlightNumber() << ' ' << flight.getFlightDestination();
	return out;
}

std::istream& operator>>(std::istream& in, Flight& flight)
{
	std::string air_company; in >> air_company;
	unsigned flight_number; in >> flight_number;
	std::string destination; in >> destination;
	flight.setAirCompany(air_company);
	flight.setFlightNumber(flight_number);
	flight.setFlightDestination(destination);
	return in;
}

void viewFlightsTo(Flight* ALL_FLIGHTS, const unsigned len, const std::string destination, std::ostream& out)
{
	for (unsigned i = 0; i < len; ++i)
	{
		if (ALL_FLIGHTS[i].getFlightDestination() == destination)
		{
			ALL_FLIGHTS[i].beautifulPrint(out);
		}
	}
}

void viewFlightsVia(Flight* ALL_FLIGHTS, const unsigned len, const std::string air_company, std::ostream& out)
{
	for (unsigned i = 0; i < len; ++i)
	{
		if (ALL_FLIGHTS[i].getAirCompany() == air_company)
		{
			ALL_FLIGHTS[i].beautifulPrint(out);
		}
	}
}

void sortFlights(Flight* ALL_FLIGHTS, const unsigned len)
{
	Flight maxFlightNumber;
	unsigned maxFlightNumberIndex;
	for (unsigned i = 0; i < len; ++i)
	{
		maxFlightNumber = ALL_FLIGHTS[0];
		maxFlightNumberIndex = 0;
		for (unsigned j = 1; j < len - i - 1; ++j)
		{
			if (ALL_FLIGHTS[j].getFlightNumber() > maxFlightNumber.getFlightNumber())
			{
				maxFlightNumber = ALL_FLIGHTS[j];
				maxFlightNumberIndex = j;
			}
		}
		Flight temp = ALL_FLIGHTS[len - i - 1];
		ALL_FLIGHTS[len - i - 1] = maxFlightNumber;
		ALL_FLIGHTS[maxFlightNumberIndex] = temp;
	}
}