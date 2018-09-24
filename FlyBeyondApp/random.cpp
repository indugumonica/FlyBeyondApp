#include "pch.h"
#include <bits.h>
#include <string>
#include "random.h"
#include <ctime>

namespace FlyBeyondApp {

	std::string RandomGenerator::gen_random(int len) {
		static const char alphanum[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

		std::string s;
		srand(time(0));
		for (int i = 0; i < len; ++i) {
			s = s + alphanum[rand() % (sizeof(alphanum) - 1)];
		}
		
		return s;
	}
}