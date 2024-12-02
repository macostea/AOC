#include <Day.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

int Day::solution4(std::string input) {
	std::ifstream inputFile(input);
	if (!inputFile.good()) {
		return -1;
	}

	std::string line;
	int count = 0;

	while (std::getline(inputFile, line)) {
		std::istringstream iss(line);

		int elf1[2]{ 0, 0 };
		int elf2[2]{ 0, 0 };

		char separator;
		iss >> elf1[0] >> separator >> elf1[1] >> separator >> elf2[0] >> separator >> elf2[1];

		if ((elf1[0] >= elf2[0] && elf1[0] <= elf2[1]) ||
			(elf2[0] >= elf1[0] && elf2[0] <= elf1[1])) {
			count++;
		}
	}

	return count;
}