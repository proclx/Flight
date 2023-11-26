#include <iostream>
#include "Flight.h"
#include <fstream>

/*
    Methods
.getAirCompany()               returns string with the name of aircompany
.getFlightNumber()             returns unsigned int with the number of flight
.getFlightDestination()        returns string with the destination
.setAirCompany(string)         sets aircompany to selected object 
.setFlightNumber(unsigned)     sets flight number to selected object
.setFlightDestination(string)  sets flight destination to selected object
.beautifulPrint([optional])    beautiful output of object [optional] == cout, can be any ostream object
    Functions
viewFlightsTo(Flight*, unsigned, string, [optional])   beautiful output of all Flight* (lenght of array == unsigned) objects which destination == string, [optional] == cout, can be any ostream object
viewFlightsVia(Flight*, unsigned, string, [optional])  beautiful output of all Flight* (lenght of array == unsigned) objects which aircompany == string, [optional] == cout, can be any ostream object
sortFlights(Flight*, unsigned)                         sorts all Flight* (lenght of array == unsigned) objects from min to max key = flight number
*/

int main()
{
	std::ifstream fin("readData.txt");
	unsigned len; fin >> len;
	Flight* ALL_FLIGHTS = new Flight[len];
	for (unsigned i = 0; i < len; ++i)
	{
		fin >> ALL_FLIGHTS[i];
	}
	fin.close();
	std::cout << "-----ALL FLIGHTS AVAILIBLE-----\n";
	for (unsigned i = 0; i < len; ++i)
	{
		ALL_FLIGHTS[i].beautifulPrint();
	}
	std::cout << "-----ALL FLIGHTS TO LVIV-----\n";
	viewFlightsTo(ALL_FLIGHTS, len, "Lviv");
	std::cout << "-----ALL FLIGHTS VIA AirUkraine-----\n";
	viewFlightsVia(ALL_FLIGHTS, len, "AirUkraine");
	sortFlights(ALL_FLIGHTS, len);
	std::ofstream fout("writeData.txt");
	for (unsigned i = 0; i < len; ++i)
	{
		fout << ALL_FLIGHTS[i] << std::endl;
	}
	fout.close();
	return 0;
}