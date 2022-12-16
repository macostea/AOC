#include "Day.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <numeric>
#include <Day.h>

int Day::solution1(std::string input) {
	std::ifstream inputFile(input);
	if (!inputFile.good()) {
		return -1;
	}

	std::string line;

	std::vector<int> sums{ 0, 0, 0 };
	int currentSum = 0;

	while (std::getline(inputFile, line)) {
		std::istringstream iss(line);
		int number = 0;

		if (line == "") {
			if (currentSum > sums[2]) {
				sums[0] = sums[1];
				sums[1] = sums[2];
				sums[2] = currentSum;
			} else if (currentSum > sums[1]) {
				sums[0] = sums[1];
				sums[1] = currentSum;

			} else if (currentSum > sums[0]) {
				sums[0] = currentSum;
			}
			
			currentSum = 0;
			continue;
		}

		if (!(iss >> number)) {
			break;
		}

		currentSum += number;
	}

	return std::accumulate(sums.begin(), sums.end(), 0);
}