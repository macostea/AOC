#include <string>
#include <queue>
#include <fstream>
#include <sstream>
#include <unordered_map>

#include "Day.h"

int Day::solution1(std::string input)
{
    std::ifstream inputFile(input);
    if (!inputFile.good())
    {
        return -1;
    }

    std::string line;

    std::priority_queue<int> left, right;

    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        int leftN, rightN = 0;

        if (!(iss >> leftN >> rightN))
        {
            break;
        }

        left.push(leftN);
        right.push(rightN);
    }

    int sum = 0;

    while (!left.empty() && !right.empty())
    {
        sum += abs(left.top() - right.top());
        left.pop();
        right.pop();
    }

    return sum;
}

int Day::solution2(std::string input)
{
    std::ifstream inputFile(input);
    if (!inputFile.good())
    {
        return -1;
    }

    std::string line;

    std::unordered_map<int, int> mappedNumbers;
    std::vector<int> left;

    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        int leftN, rightN = 0;

        if (!(iss >> leftN >> rightN))
        {
            break;
        }

        auto existingElem = mappedNumbers.find(rightN);

        if (existingElem != mappedNumbers.end())
        {
            mappedNumbers[rightN] += 1;
        }
        else
        {
            mappedNumbers[rightN] = 1;
        }

        left.push_back(leftN);
    }

    int sum = 0;

    for (auto n : left)
    {
        sum += n * mappedNumbers[n];
    }

    return sum;
}