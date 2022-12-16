#pragma once
#include <string>

class Day {
public:
	virtual int solution(std::string input) = 0;
};

class DayOne : public Day {
public:
	int solution(std::string input) override;
};

class DayTwo : public Day {
public:
	int solution(std::string input) override;
};

class DayThree : public Day {
public:
	int solution(std::string input) override;
};

class DayFour : public Day {
public:
	int solution(std::string input) override;
};
