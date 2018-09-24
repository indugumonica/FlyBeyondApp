#pragma once
#include <string>
#include <fstream>
#include "FileHelper.h"


namespace FlyBeyondApp {
	class FlightDetails {

	public:
		std::string FlightID;
		std::string Itinerary;
		std::string DepartureTime;
		std::vector<FlightDetails> GetFlightDetails();
			

	};
	
}
