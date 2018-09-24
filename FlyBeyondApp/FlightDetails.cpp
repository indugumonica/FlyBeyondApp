#include "pch.h"
#include "FlightDetails.h"
#include<iostream>
#include<string>
#include<list>

using namespace std;
namespace FlyBeyondApp {
	
	vector<FlightDetails> FlightDetails::GetFlightDetails() {
		string filepath = "C:/Users/Monica/Desktop/Kal/airline reservation system/FlyBeyondApp/FlyBeyondApp/Debug/FlightDetails.txt";
		auto fileContent = FileHelper<string>::ReadTextFile(filepath);
		auto lines = FileHelper<string>::SplitFile(fileContent, '\n');
		auto flightDetails = new vector<FlightDetails>();

		for (vector<string>::iterator line = lines.begin();
			line!=lines.end(); line++) 
		{
			auto lineparts = FileHelper<string>::SplitFile(*line, ',');
			auto flightDetail = new FlightDetails();
			flightDetail->FlightID = lineparts[0];
			flightDetail->Itinerary = lineparts[1];
			flightDetail->DepartureTime = lineparts[2];
			flightDetails->push_back(*flightDetail);
			
		}
		
		return *flightDetails;
	}
}
