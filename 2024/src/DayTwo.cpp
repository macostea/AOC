#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Day.h"

int Day::solution3(std::string input)
{
    std::ifstream inputFile(input);
    if (!inputFile.good())
    {
        return -1;
    }

    std::string line;
    int safeNo = 0;

    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);

        int prev = 0;
        int curr = 0;
        bool increasing = true;

        iss >> prev;
        iss >> curr;

        if (curr - prev < 0)
        {
            increasing = false;
        }

        if (!(abs(curr - prev) >= 1 && abs(curr - prev) <= 3))
        {
            continue;
        }

        prev = curr;
        bool safe = true;

        while (iss >> curr)
        {
            if ((!increasing && curr - prev > 0) ||
                (increasing && curr - prev < 0))
            {
                safe = false;
                break;
            }

            if (!(abs(curr - prev) >= 1 && abs(curr - prev) <= 3))
            {
                safe = false;
                break;
            }

            prev = curr;
        }

        if (safe)
        {
            safeNo++;
        }
    }

    return safeNo;
}

int Day::solution4(std::string input)
{
    std::ifstream inputFile(input);
    if (!inputFile.good())
    {
        return -1;
    }

    std::string line;
    int safeNo = 0;

    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);

        int prev = 0;
        int curr = 0;
        bool increasing = true;
        std::vector<int> unsafeLevel;

        iss >> prev;
        iss >> curr;

        if (curr - prev < 0)
        {
            increasing = false;
        }

        bool safe = true;

        if (!(abs(curr - prev) >= 1 && abs(curr - prev) <= 3))
        {
            safe = false;
        }

        unsafeLevel.push_back(prev);
        unsafeLevel.push_back(curr);

        prev = curr;

        while (iss >> curr)
        {
            unsafeLevel.push_back(curr);
            if ((!increasing && curr - prev > 0) ||
                (increasing && curr - prev < 0))
            {
                safe = false;
            }

            if (!(abs(curr - prev) >= 1 && abs(curr - prev) <= 3))
            {
                safe = false;
            }

            prev = curr;
        }

        if (safe)
        {
            safeNo++;
        }
        else
        {
            bool potentiallySafe = false;
            for (int i = 0; i < unsafeLevel.size(); i++)
            {
                std::vector<int> levelCopy = unsafeLevel;

                levelCopy.erase(levelCopy.begin() + i);

                int prev = 0;
                int curr = 0;
                bool increasing = true;

                prev = levelCopy[0];
                curr = levelCopy[1];

                if (curr - prev < 0)
                {
                    increasing = false;
                }

                bool safe = true;

                if (!(abs(curr - prev) >= 1 && abs(curr - prev) <= 3))
                {
                    continue;
                }

                prev = curr;

                for (int j = 2; j < levelCopy.size(); j++)
                {
                    curr = levelCopy[j];

                    if ((!increasing && curr - prev > 0) ||
                        (increasing && curr - prev < 0))
                    {
                        safe = false;
                        break;
                    }

                    if (!(abs(curr - prev) >= 1 && abs(curr - prev) <= 3))
                    {
                        safe = false;
                        break;
                    }

                    prev = curr;
                }

                if (safe)
                {
                    potentiallySafe = true;
                    break;
                }
            }

            if (potentiallySafe)
            {
                safeNo++;
            }
        }
    }

    return safeNo;
}