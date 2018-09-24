#pragma once
#include <string>
#include "FileHelper.h"
#include <stdlib.h>
#include "random.h"

namespace FlyBeyondApp {
	class PassengerDetails {

	public:
		std::string PassengerID;
		std::string PassengerName;
		PassengerDetails StorePassengerDetails(std::string PassengerName);
		std::vector<PassengerDetails> GetPassengerDetails();
	};
}
