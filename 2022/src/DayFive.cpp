#include <Day.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>

std::string Day::solution5(std::string input) {
	std::ifstream inputFile(input);

	std::string line;
	int count = 0;

	std::vector<std::string> ship;

	while (std::getline(inputFile, line)) {
		if (line == "") {
			break;
		}

		ship.push_back(line);
	}

	// Build the ship
	std::vector<std::stack<char>> stacks;

	for (auto it = ship.rbegin(); it != ship.rend(); ++it) {
		std::string &row = *it;
		row.erase(remove(row.begin(), row.end(), '['), row.end());
		row.erase(remove(row.begin(), row.end(), ']'), row.end());

		size_t pos = 0;
		size_t count = 0;
		while ((pos = row.find(" ")) != std::string::npos) {
			char token = row.substr(0, pos)[0];
			if (stacks.size() <= count) {
				stacks.push_back(std::stack<char>());
			}
			if (token != '\0') {
				stacks[count].push(token);
			} else {
				pos += 3;
			}
			
			row.erase(0, pos + 1);
			if (row.size() != 0) {
				count++;
			}
		}

		if (stacks.size() <= count) {
			stacks.push_back(std::stack<char>());
		}
		if (row[0] != '\0') {
			stacks[count].push(row[0]);
		}
	}

	// Get moves
	while (std::getline(inputFile, line)) {
		std::istringstream iss(line);
		std::string move;
		size_t count = 0;
		std::string from;
		uint16_t fromColumn = 0;
		std::string to;
		uint16_t toColumn = 0;

		iss >> move >> count >> from >> fromColumn >> to >> toColumn;

		std::stack<char> temp;

		for (int i = 0; i < count; i++) {
			auto elem = stacks[fromColumn - 1].top();

			temp.push(elem);
			stacks[fromColumn - 1].pop();
		}

		while (!temp.empty()) {
			auto elem = temp.top();
			stacks[toColumn - 1].push(elem);
			temp.pop();
		}
	}

	std::ostringstream oss;
	for (auto it = stacks.begin(); it != stacks.end(); ++it) {
		oss << it->top();
	}

	return oss.str();
}
