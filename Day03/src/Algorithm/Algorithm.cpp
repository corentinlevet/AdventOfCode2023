// CLevetDev, 03/12/2023

#include "Algorithm.hpp"

#include <algorithm>
#include <iostream>

/* Constructor & Destructor */

AdventOfCode::Algorithm::Algorithm(const std::vector<std::string> &fileContent) : _sumOfAllPartNumbers(0), _sumOfAllGearRatios(0), _fileContent(fileContent)
{
    this->calculateSumOfAllPartNumbers();
    this->calculateSumOfAllGearRatios();
}

/* Getter(s) */

int AdventOfCode::Algorithm::getSumOfAllPartNumbers() const
{
    return (_sumOfAllPartNumbers);
}

int AdventOfCode::Algorithm::getSumOfAllGearRatios() const
{
    return (_sumOfAllGearRatios);
}

/* Private method(s) */

std::map<std::tuple<int, int>, std::string> AdventOfCode::Algorithm::findAllNumbersInEngineSchematic(void) const
{
    std::map<std::tuple<int, int>, std::string> numbers;

    for (const auto &line : _fileContent)
    {
        std::string number;

        int startPosition = -1;

        for (auto it = line.begin(); it != line.end(); it++)
        {
            if (std::isdigit(*it))
            {
                if (startPosition == -1)
                {
                    startPosition = std::distance(line.begin(), it);
                }

                number += *it;
            }

            if ((!std::isdigit(*it) && !number.empty()) || it == line.end() - 1)
            {
                const std::tuple<int, int> position(std::distance(_fileContent.begin(), std::find(_fileContent.begin(), _fileContent.end(), line)), startPosition);

                numbers[position] = number;
                number.clear();
                startPosition = -1;
            }
        }
    }

    return (numbers);
}

std::map<std::tuple<int, int>, char> AdventOfCode::Algorithm::findAllSymbolsInEngineSchematic(void) const
{
    std::map<std::tuple<int, int>, char> symbols;

    for (const auto &line : _fileContent)
    {
        for (auto it = line.begin(); it != line.end(); it++)
        {
            if (!std::isdigit(*it) && *it != '.')
            {
                const std::tuple<int, int> position(std::distance(_fileContent.begin(), std::find(_fileContent.begin(), _fileContent.end(), line)), std::distance(line.begin(), it));

                symbols[position] = *it;
            }
        }
    }

    return (symbols);
}

std::vector<std::string> AdventOfCode::Algorithm::getLinesToCheck(const std::tuple<int, int> &position) const
{
    std::vector<std::string> linesToCheck;

    if (std::get<0>(position) > 0)
    {
        linesToCheck.push_back(_fileContent[std::get<0>(position) - 1]);
    } else {
        linesToCheck.push_back("");
    }

    linesToCheck.push_back(_fileContent[std::get<0>(position)]);

    if (std::get<0>(position) < (int) _fileContent.size() - 1)
    {
        linesToCheck.push_back(_fileContent[std::get<0>(position) + 1]);
    } else {
        linesToCheck.push_back("");
    }

    return (linesToCheck);
}

bool AdventOfCode::Algorithm::isNumberAdjacentToSymbol(const std::tuple<int, int> &position, const std::string &number) const
{
    std::vector<std::string> linesToCheck = this->getLinesToCheck(position);

    // Check if the number is adjacent to a symbol (all characters except numbers and dots are symbols)

    const int startPosition = std::get<1>(position);
    const int endPosition = startPosition + number.length() - 1;

    for (const auto &line : linesToCheck)
    {
        if (line.empty())
            continue;

        for (int i = startPosition - 1; i <= endPosition + 1; i++)
        {
            if (i < 0 || i >= (int) line.length())
                continue;

            if (line[i] != '.' && !std::isdigit(line[i]))
                return (true);
        }
    }

    return (false);
}

std::vector<std::string> AdventOfCode::Algorithm::getNumbersAroundSymbol(const std::tuple<int, int> &position, const std::map<std::tuple<int, int>, std::string> &numbers) const
{
    std::map<std::tuple<int, int>, std::string> numbersToCheck;

    for (const auto &number : numbers)
    {
        if (std::get<0>(number.first) == std::get<0>(position) - 1 || std::get<0>(number.first) == std::get<0>(position) || std::get<0>(number.first) == std::get<0>(position) + 1)
        {
            numbersToCheck[number.first] = number.second;
        }
    }

    std::vector<std::string> numbersAroundSymbol;

    for (const auto &number : numbersToCheck)
    {
        std::vector<std::string> linesToCheck = this->getLinesToCheck(number.first);

        // Check if the number is adjacent to a symbol (all characters except numbers and dots are symbols)

        const int startPosition = std::get<1>(number.first);
        const int endPosition = startPosition + number.second.length() - 1;

        for (int j = 0; j < 3; j++)
        {
            const std::string &line = linesToCheck[j];

            if (line.empty())
                continue;

            for (int i = startPosition - 1; i <= endPosition + 1; i++)
            {
                if (i < 0 || i >= (int) line.length())
                    continue;

                if (line[i] != '.' && !std::isdigit(line[i]) && i == std::get<1>(position))
                {
                    numbersAroundSymbol.push_back(number.second);
                    break;
                }
            }
        }
    }

    return (numbersAroundSymbol);
}

void AdventOfCode::Algorithm::calculateSumOfAllPartNumbers()
{
    const std::map<std::tuple<int, int>, std::string> numbers = this->findAllNumbersInEngineSchematic();

    int sum = 0;

    for (const auto &number : numbers)
    {
        if (this->isNumberAdjacentToSymbol(number.first, number.second))
        {
            sum += std::stoi(number.second);
        }
    }

    _sumOfAllPartNumbers = sum;
}

void AdventOfCode::Algorithm::calculateSumOfAllGearRatios()
{
    const std::map<std::tuple<int, int>, std::string> numbers = this->findAllNumbersInEngineSchematic();
    const std::map<std::tuple<int, int>, char> symbols = this->findAllSymbolsInEngineSchematic();

    int sum = 0;

    for (const auto &symbol : symbols)
    {
        if (symbol.second == '*')
        {
            const std::vector<std::string> numbersToMultiply = this->getNumbersAroundSymbol(symbol.first, numbers);

            if (numbersToMultiply.size() == 2)
            {
                sum += std::stoi(numbersToMultiply[0]) * std::stoi(numbersToMultiply[1]);
            }
        }
    }

    _sumOfAllGearRatios = sum;
}
