#include "Day.h"
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>
#include <algorithm>
#include <numeric>

int Day::solution3(std::string input) {
	std::ifstream inputFile(input);
	if (!inputFile.good()) {
		return -1;
	}

	std::string line;
	std::set<char> sets[3];
	int group = 0;
	int score = 0;

	while (std::getline(inputFile, line)) {
		for (size_t i = 0; i < line.size(); i++) {
			sets[group].insert(line[i]);
		}

		if (group == 2) {
			group = 0;

			std::vector<char> v(sets[0].size());

			auto it = std::set_intersection(sets[0].begin(), sets[0].end(), sets[1].begin(), sets[1].end(), v.begin());
			v.resize(it - v.begin());

			std::vector<char> v2(v.size());

			it = std::set_intersection(v.begin(), v.end(), sets[2].begin(), sets[2].end(), v2.begin());
			v2.resize(it - v2.begin());

			score += std::transform_reduce(v2.begin(), v2.end(), 0, [](char l, char r) { return l + r; }, [](char i) { if (i > 96) return i - 96; else return i - 38; });

			for (int i = 0; i < 3; i++) {
				sets[i].clear();
			}
		} else {
			++group;
		}
	}

	return score;
}
