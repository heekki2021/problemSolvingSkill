#include <iostream>
#include <string>
#include <unordered_map>

int romanToInt(const std::string &roman){
	std::unordered_map<char, int> romanValues = {
		{'l', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000}
	};

	int result = 0;
	int preValue = 0;

	for (int i = roman.size() - 1; i >= 0; --i) {
		char currentChar = roman[i];
		int currentValue = romanValues[currentChar];

		if (currentValue < preValue) {
			result -= currentValue;
		}
	}
}
