#include "pch.h"
#include "PassengerDetails.h"
#include <stdlib.h>
#include "random.h"
#include <ctime>

using namespace std;
namespace FlyBeyondApp{
	PassengerDetails PassengerDetails::StorePassengerDetails(string PassengerName) {
		string filepath = "C:/Users/Monica/Desktop/Kal/airline reservation system/FlyBeyondApp/FlyBeyondApp/Debug/PassengerDetails.txt";
		auto p = new PassengerDetails();
		auto r = new RandomGenerator();
		p->PassengerName = PassengerName;
		p->PassengerID = r->gen_random(5);
		string entry =  p->PassengerID + "," + p->PassengerName;
		auto fileContent = FileHelper<string>::WriteTextFile(filepath, entry);
		return *p;
	}
	vector<PassengerDetails> PassengerDetails::GetPassengerDetails() {
		string filepath = "C:/Users/Monica/Desktop/Kal/airline reservation system/FlyBeyondApp/FlyBeyondApp/Debug/PassengerDetails.txt";
		auto fileContent = FileHelper<string>::ReadTextFile(filepath);
		auto lines = FileHelper<string>::SplitFile(fileContent, '\n');
		auto passengerDetails = new vector<PassengerDetails>();
		for (vector<string>::iterator line = lines.begin();
			line != lines.end(); line++)
		{
			auto lineparts = FileHelper<string>::SplitFile(*line, ',');
			auto passengerDetail = new PassengerDetails();
			passengerDetail->PassengerID = lineparts[0];
			passengerDetail->PassengerName = lineparts[1];
		
			passengerDetails->push_back(*passengerDetail);

		}

		return *passengerDetails;
	}
}

