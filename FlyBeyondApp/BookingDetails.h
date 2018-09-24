#pragma once
#include "FlightDetails.h"
#include "FileHelper.h"
#include <stdlib.h>
#include "random.h"


namespace FlyBeyondApp {
	//const int kFirstBookingID = 1001;
	class BookingDetails {
	public:
		std::string FlightID;
		std::string PNR;
		std::string PassengerID;
		std::string PassengerName;
		std::string BookingID;
		BookingDetails StoreBookingDetails(std::string Input,std::string PID );
		std::vector<BookingDetails> GetBookingDetails();
	};
}