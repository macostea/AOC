#include "DayTwo.h"
#include <string>
#include <fstream>
#include <sstream>
#include <map>

std::map<char, int> points{ {'A', 1}, {'B', 2}, {'C', 3} };
std::map<char, int> outcomePoints{ {'X', 0}, {'Y', 3}, {'Z', 6} };

std::map<char, char> winner{ {'A', 'B'}, {'B', 'C'}, {'C', 'A'} };
std::map<char, char> loser{ {'A', 'C'}, {'B', 'A'}, {'C', 'B'} };

char requiredPlayer(char opponent, char outcome) {
	switch (outcome) {
	case 'X':
		return loser[opponent];
	case 'Y':
		return opponent;
	case 'Z':
		return winner[opponent];
	default:
		throw std::runtime_error("Unknown value");
	}
}

int DayTwo::solution(std::string input) {
	std::ifstream inputFile(input);
	if (!inputFile.good()) {
		return -1;
	}

	std::string line;
	int score = 0;

	while (std::getline(inputFile, line)) {
		std::istringstream iss(line);

		char opponent, outcome;
		if (!(iss >> opponent >> outcome)) {
			break;
		}

		score += outcomePoints[outcome];
		score += points[requiredPlayer(opponent, outcome)];
	}

	return score;
}
