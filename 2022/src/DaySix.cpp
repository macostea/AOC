#include <Day.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_set>

int Day::solution6(std::string input) {
	std::ifstream inputFile(input);

	std::string line;
	int count = 0;

	while (std::getline(inputFile, line)) {
		for (int i = 0; i < line.size() - 14; i++) {
			std::unordered_set<char> sequence;
			sequence.insert(line[i]);
			int j = i + 1;
			for (j; j < i + 15; j++) {
				if (!sequence.contains(line[j])) {
					sequence.insert(line[j]);
				} else {
					break;
				}
			}

			if (sequence.size() == 14) {
				return j - 2;
			}
		}
	}

	return -1;
}