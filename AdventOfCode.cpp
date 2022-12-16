// AdventOfCode.cpp : Defines the entry point for the application.
//

#include "AdventOfCode.h"
#include "DayThree.h"

using namespace std;

int main(int argc, char **argv)
{
	std::string path = "";
	if (argc > 1) {
		path = argv[1];
	}

	Day *day = new DayThree();
	int solution = day->solution(path);
	if (solution == -1) {
		std::cout << "Failed to get solution" << std::endl;
		return -1;
	}

	std::cout << "Day 3 solution: " << solution << std::endl;
	return 0;
}
