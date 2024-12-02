// AdventOfCode.cpp : Defines the entry point for the application.
//

#include <iostream>

#include "Day.h"

using namespace std;

int main(int argc, char **argv)
{
	std::string path = "";
	if (argc > 1)
	{
		path = argv[1];
	}

	Day day;
	auto solution = day.solution4(path);
	// if (solution == -1) {
	//	std::cout << "Failed to get solution" << std::endl;
	//	return -1;
	// }

	std::cout << "Day 2 solution: " << solution << std::endl;
	return 0;
}
