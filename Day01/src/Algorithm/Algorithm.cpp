// CLevetDev, 01/12/2023

#include "Algorithm.hpp"

#include <algorithm>
#include <map>
#include <iostream>

/* Constructor & Destructor */

AdventOfCode::Algorithm::Algorithm(const std::vector<std::string> &fileContent) : _score(0), _fileContent(fileContent)
{
    this->calculateScore();
}

/* Getter(s) */

int AdventOfCode::Algorithm::getScore() const
{
    return (_score);
}

/* Private method(s) */

void AdventOfCode::Algorithm::calculateScore()
{
    const static std::map<std::string, int> numbers = {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
    };

    int score = 0;

    for (const auto &line : _fileContent)
    {
        if (line.empty())
            continue;

        int firstNumber = -1;

        for (auto it = line.begin(); it != line.end(); ++it)
        {
            if (std::isdigit(*it))
            {
                firstNumber = *it - '0';
                break;
            }

            std::string substring = line.substr(it - line.begin());

            for (const auto &number : numbers)
            {
                if (substring.rfind(number.first, 0) == 0)
                {
                    firstNumber = number.second;
                    break;
                }
            }

            if (firstNumber != -1)
                break;
        }

        int lastNumber = -1;

        for (auto it = line.rbegin(); it != line.rend(); ++it)
        {
            if (std::isdigit(*it))
            {
                lastNumber = *it - '0';
                break;
            }

            std::string substring = line.substr(0, line.size() - (it - line.rbegin()));

            for (const auto &number : numbers)
            {
                if (std::equal(number.first.rbegin(), number.first.rend(), substring.rbegin()))
                {
                    lastNumber = number.second;
                    break;
                }
            }

            if (lastNumber != -1)
                break;
        }

        if (firstNumber == -1 || lastNumber == -1)
        {
            _score = -1;
            return;
        }

        std::string concatenatedNumbers = std::to_string(firstNumber) + std::to_string(lastNumber);

        int concatenatedNumbersAsInt = std::stoi(concatenatedNumbers);

        score += concatenatedNumbersAsInt;
    }

    _score = score;
}
