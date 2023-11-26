#pragma once
#include <string>
#include <iostream>
class Flight
{
public:
	std::string getAirCompany() const;
	unsigned getFlightNumber() const;
	std::string getFlightDestination() const;
	void setAirCompany(const std::string& air_company);
	void setFlightNumber(const unsigned flight_number);
	void setFlightDestination(const std::string& destination);
	void beautifulPrint(std::ostream& out = std::cout) const;
	Flight(const std::string air_company, const unsigned flight_number, const std::string& destination);
	Flight();
	Flight(const Flight& flight);
	~Flight();
private:
	std::string flight_air_company;
	unsigned flight_flight_number;
	std::string flight_destination;
};

std::ostream& operator<<(std::ostream& out, const Flight& flight);
std::istream& operator>>(std::istream& in, Flight& flight);
void viewFlightsTo(Flight* ALL_FLIGHTS, const unsigned len, const std::string destination, std::ostream& out = std::cout);
void viewFlightsVia(Flight* ALL_FLIGHTS, const unsigned len, const std::string air_company, std::ostream& out = std::cout);
void sortFlights(Flight* ALL_FLIGHTS, const unsigned len);