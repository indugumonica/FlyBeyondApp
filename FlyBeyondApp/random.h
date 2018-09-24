#pragma once

namespace FlyBeyondApp {
	class RandomGenerator {

	public:
		std::string gen_random(int len);
		static const char alphanum[];
	};
}