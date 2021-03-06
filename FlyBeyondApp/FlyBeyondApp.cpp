// FlyBeyondApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include"FileHelper.h"
#include"FlightDetails.h"
#include "BookingDetails.h"
#include "random.h"
#include "PassengerDetails.h"

using namespace FlyBeyondApp;
using namespace std;

int displayMenu();
void ReserveASeat();
int FlightSchedule();
void PassengerInformation();
void UserTicketInformation();
void FlightDetailsList();
void newUserSignin();
int mainExecution();
void ShowBackOption();
void newUserSigninWithBackOption();
void BackOptionforFD();
void FlightDetailsListWithBackOption();
void BackOptionforUTI();
void BackOptionforPI();
void FlightSchedulewithBackOption();

int main()
{
	return mainExecution();
}

int mainExecution()
{
	while (true) {
		int selection = displayMenu();
		switch (selection) {
		case 0:
			return 0;
		case 1:
			ReserveASeat();
			break;
		case 2:
			FlightSchedulewithBackOption();
			break;
		case 3:
			PassengerInformation();
			break;
		case 4:
			UserTicketInformation();
			break;
		case 5:
			FlightDetailsListWithBackOption();
			break;
		case 6:
			newUserSigninWithBackOption();
			break;
		default:
			cerr << "Unknown Command. Try Again." << endl;
			break;
		}
		return 0;
	}
}

int displayMenu() {
	int selection;

	cout << endl;
	cout << "Welcome to Fly Beyond Airlines" << endl;
	cout << "________________________________" << endl;
	cout << "1.Reserve a Seat" << endl;
	cout << "2.Flight Schedule" << endl;
	cout << "3.Passenger Information" << endl;
	cout << "4.User Ticket Information" << endl;
	cout << "5.Flight Details" << endl;
	cout << "6.New User SignIn" << endl;
	cout << "0.Quit" << endl;
	cout << "________________________________" << endl;
	cout << "--------> ";
	cin >> selection;

	return selection;
}


void ReserveASeat() {
	auto f = new FlightDetails();
	auto FD = f->GetFlightDetails();
	
	string flightid;
	string passengername;
	
	
	cout << "Enter the Passenger Name " << endl;
	cout << "----------->";
	cin >> passengername;
	auto p = new PassengerDetails();
	auto PD = p->GetPassengerDetails();
	bool isFlightID = false;
	bool isSignIn = false;
	for (vector<PassengerDetails>::iterator EachPD = PD.begin(); EachPD != PD.end(); EachPD++) {
		if (passengername == EachPD->PassengerName) {
			isSignIn = true;
			cout << "Enter a FLIGHT ID for booking a seat " << endl;
			cout << "_______________________________________" << endl;
			FlightDetailsList();
			cout << "---------------> ";
			cin >> flightid;
			for (vector<FlightDetails>::iterator EachFD = FD.begin(); EachFD != FD.end(); EachFD++) {
				if (flightid == EachFD->FlightID) {
					isFlightID = true;
					auto b = new BookingDetails();
					string PIDInput;
					b->StoreBookingDetails(flightid,passengername);
					auto BD = b->GetBookingDetails();
					for (vector<BookingDetails>::iterator EachBD = BD.begin(); EachBD != BD.end(); EachBD++) 
						if (flightid == EachBD->FlightID & passengername == EachBD->PassengerName)
						{
							cout << "PaasengerID:" << EachBD->PassengerID << endl;
							cout << "Passenger Name:" << EachBD->PassengerName << endl;
							cout << "BookingID:" << EachBD->BookingID << endl;
							cout << "FlightID:" << EachBD->FlightID << endl;
							cout << "PNR:" << EachBD->PNR << endl;
							ShowBackOption();

						}
						break;
					
				}
				
				}
			if (!isFlightID) {
				cout << "Flight ID not found" << endl;
				ReserveASeat();

			}
			break;
		}
	
	}
	if (!isSignIn) {
		string choice;
		cout << "Passenger Name not found" << endl;
		cout << "Please enter 'SignIn' for new account or 'Back' for Main Menu" << endl;
		cout << "----------> ";
		cin >> choice;
		if (choice == "Back") {
			mainExecution();
		}
		else if (choice == "SignIn") {
			newUserSigninWithBackOption();
		}
		else {
			cout << "Oops wrong Input!! Heading to MainMenu" << endl;
			mainExecution();
		}
	}
	
}

int FlightSchedule() {
	auto f = new FlightDetails();
	auto FD = f->GetFlightDetails();
	cout << "Enter the Flight ID to get the Flight Schedule" << endl;
	cout << "________________________________________________" << endl;

	for (vector<FlightDetails>::iterator EachFD = FD.begin(); EachFD != FD.end(); EachFD++) {
		cout << EachFD->FlightID << endl;
	}
	std::string selection;
	cout << "----------->";
	cin >> selection;
	bool isFound = false;

	for (vector<FlightDetails>::iterator EachFD = FD.begin(); EachFD != FD.end(); EachFD++) {
		if (selection == EachFD->FlightID) {
			isFound = true;
			cout << EachFD->FlightID << " ";
			cout << EachFD->Itinerary << " ";
			cout << EachFD->DepartureTime << endl;
			break;
		}
	}
	if (!isFound) {
		cout << "Flight ID not found" << endl;
		FlightSchedule();
	}
	return 0;

}

void FlightSchedulewithBackOption() {
	FlightSchedule();
	ShowBackOption();
}

void PassengerInformation() {
	string PNameInput;
	auto p =new PassengerDetails();
	auto PD = p->GetPassengerDetails();
	cout << "Enter Passenger Name to get passenger Information" << endl;
	cout << "--------------> ";
	cin >> PNameInput;
	bool isPID = false;
	for (vector<PassengerDetails>::iterator EachPD = PD.begin(); EachPD != PD.end(); EachPD++) {
		if (PNameInput == EachPD->PassengerName)
		{
			isPID = true;
			cout << "PaasengerID:" << EachPD->PassengerID << endl;
			cout << "Passenger Name:" << EachPD->PassengerName << endl;
			cout << "Upcoming Booking Details List: " << endl;
			auto b = new BookingDetails();
			auto allBookingDetails = b->GetBookingDetails();
			for (vector<BookingDetails>::iterator EachBD = allBookingDetails.begin();
				EachBD != allBookingDetails.end(); EachBD++) {
				if (EachBD->PassengerID == EachPD->PassengerID) {
					cout << "Booking ID: " + EachBD->BookingID << endl;
				}
			}

			ShowBackOption();
		}
	};
	if (!isPID) {
		cout << "Passenger Name not found !!" << endl;
		BackOptionforPI();
		
	}

};

void BackOptionforPI() {
	string choice;
	cout << "Please type 're-enter' to enter the Passenger Name or 'Back' to go to main Menu" << endl;
	cout << "----------> ";
	cin >> choice;
	if (choice == "Back") {
		mainExecution();
	}
	else if(choice =="re-enter")
	{
		PassengerInformation();
	}
	else {
		cout << "Oops wrong Input!! Heading to MainMenu" << endl;
		mainExecution();
	}
}

void UserTicketInformation() {
	string BIDInput;
	auto b = new BookingDetails();
	auto BD = b->GetBookingDetails();
	cout << "Enter Booking ID to get User Ticket Information" << endl;
	cout << "-------------->" << endl;
	cin >> BIDInput;
	bool isPID = false;
	for (vector<BookingDetails>::iterator EachBD = BD.begin(); EachBD != BD.end(); EachBD++)
		if (BIDInput == EachBD->BookingID)
		{
			isPID = true;
			cout << "PaasengerID:" << EachBD->PassengerID << endl;
			cout << "Passenger Name:" << EachBD->PassengerName << endl;
			cout << "BookingID: " << EachBD->BookingID << endl;
			cout << "FlightID:" << EachBD->FlightID << endl;
			cout << "PNR:" << EachBD->PNR << endl;
			ShowBackOption();
		}
	if (!isPID) {
		cout << "Booking ID not found !!" << endl;
		BackOptionforUTI();
	}
	ShowBackOption();
		
};

void BackOptionforUTI() {
	string choice;
	cout << "Please type 're-enter' to enter the Booking ID or 'Back' to go to main Menu" << endl;
	cout << "---------->";
	cin >> choice;
	if (choice == "Back") {
		mainExecution();
	}
	else if (choice =="re-enter") {
		UserTicketInformation();
	}
	else {
		cout<< "Oops wrong Input!! Heading to MainMenu" << endl;
		mainExecution();
	}
}



void FlightDetailsList() {

	auto f = new FlightDetails();
	auto FD=f->GetFlightDetails() ;
	for (vector<FlightDetails>::iterator EachFD = FD.begin(); EachFD != FD.end(); EachFD++) {
		cout <<  EachFD->FlightID << " " ;
		cout << EachFD->Itinerary << " ";
		cout << EachFD->DepartureTime<< endl;;
	};
	
};


void BackOptionforFD() {
	string choice;
	cout << "Please type 'Back' to go to main Menu or 'Book_Ticket' for booking a new Ticket" << endl;
	cout << "--------->";
	cin >> choice;
	if (choice == "Back") {
		mainExecution();
	}
	else if (choice == "Book_Ticket") {
		ReserveASeat();
	}
	else {
		cout << "Oops wrong Input!! Heading to MainMenu" << endl;
		mainExecution();
	}
}
void FlightDetailsListWithBackOption() {
	FlightDetailsList();
	BackOptionforFD();

}


void newUserSigninWithBackOption()
{
	newUserSignin();
	ShowBackOption();
}

void ShowBackOption()
{
	string choice;
	cout << "Please enter 'Back' to go to main Menu" << endl;
	cout << "--------------->";
	cin >> choice;
	if (choice == "Back") {
		mainExecution();
	}
	else {
		cout << "Oops wrong Input!! Heading to MainMenu" << endl;
		mainExecution();
	}
}

void newUserSignin() {
	string name;
	cout << "Enter your name: " << endl;
	cout << "---------->";
	cin >> name;
	auto p = new PassengerDetails();
	auto PD = p->GetPassengerDetails();
	bool NameExists = false;
	for (vector<PassengerDetails>::iterator EachPD = PD.begin(); EachPD != PD.end(); EachPD++) {
		if (name == EachPD->PassengerName) {
			NameExists = true;
			cout << "This name already exits. Please enter a new name" << endl;
			newUserSignin();
			break;
		}
	}

	if (!NameExists) {
		p->StorePassengerDetails(name);
		auto PD = p->GetPassengerDetails();
		for (vector<PassengerDetails>::iterator EachPD = PD.begin(); EachPD != PD.end(); EachPD++) {
			if (name == EachPD->PassengerName) {
				cout << "This is your Passenger ID: " << EachPD->PassengerID << endl;
				cout << "Plese note this for future use" << endl;
				break;
			}
		}
	}
}


