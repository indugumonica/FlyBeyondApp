#include "pch.h"
#include "BookingDetails.h"
#include "random.h"
#include "PassengerDetails.h"
#include <stdlib.h>

using namespace std;
namespace FlyBeyondApp {

	BookingDetails BookingDetails::StoreBookingDetails(string Input, string PName) {
		string filepath = "C:/Users/Monica/Desktop/Kal/airline reservation system/FlyBeyondApp/FlyBeyondApp/Debug/BookingDetails.txt";
		auto b = new BookingDetails();
		b->FlightID = Input;
		auto r = new RandomGenerator();
		b->BookingID = r->gen_random(4);
		b->PNR = r->gen_random(8);
		auto p = new PassengerDetails();
		auto PD = p->GetPassengerDetails();
		string passengername;
		p->PassengerName = PName;
		for (vector<PassengerDetails>::iterator EachPD = PD.begin(); EachPD != PD.end(); EachPD++) {
			if (p->PassengerName == EachPD->PassengerName) {
				p->PassengerID = EachPD->PassengerID;
			}
			
		};

		string entry = b->FlightID + "," +b->BookingID+","+ b->PNR + "," + p->PassengerID + "," + p->PassengerName;
		auto fileContent = FileHelper<string>::WriteTextFile(filepath, entry);
		return *b;
	

	}
	vector<BookingDetails> BookingDetails::GetBookingDetails() {
		string filepath = "C:/Users/Monica/Desktop/Kal/airline reservation system/FlyBeyondApp/FlyBeyondApp/Debug/BookingDetails.txt";
		auto fileContent = FileHelper<string>::ReadTextFile(filepath);
		auto lines = FileHelper<string>::SplitFile(fileContent, '\n');
		auto bookingDetails = new vector<BookingDetails>();
		for (vector<string>::iterator line = lines.begin();
			line != lines.end(); line++)
		{
			auto lineparts = FileHelper<string>::SplitFile(*line, ',');
			auto bookingDetail = new BookingDetails();
			bookingDetail->FlightID = lineparts[0];
			bookingDetail->BookingID = lineparts[1];
			bookingDetail->PNR = lineparts[2];
			bookingDetail->PassengerID = lineparts[3];
			bookingDetail->PassengerName = lineparts[4];

			bookingDetails->push_back(*bookingDetail);

		}

		return *bookingDetails;
	}
}