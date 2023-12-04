// CLevetDev, 02/12/2023

#include "Algorithm.hpp"

#include "Cubes.hpp"
#include "Utils.hpp"

#include <algorithm>
#include <iostream>
#include <map>

/* Constructor & Destructor */

AdventOfCode::Algorithm::Algorithm(const std::vector<std::string> &fileContent, const std::tuple<int, int, int> &nbCubes) : _sumOfID(0), _fileContent(fileContent), _nbCubes(nbCubes)
{
    this->calculateSumOfID();
    this->calculateSumOfFewestRequiredCubes();
}

/* Getter(s) */

int AdventOfCode::Algorithm::getSumOfID() const
{
    return (_sumOfID);
}

int AdventOfCode::Algorithm::getSumOfFewestRequiredCubes() const
{
    return (_sumOfFewestRequiredCubes);
}

/* Private method(s) */

std::tuple<int, int, int> AdventOfCode::Algorithm::getMaximumUsedCubes(const std::string &content) const
{
    const static std::map<std::string, AdventOfCode::Cubes> cubesMap = {
        {"red", AdventOfCode::Cubes::RED},
        {"green", AdventOfCode::Cubes::GREEN},
        {"blue", AdventOfCode::Cubes::BLUE}
    };

    std::tuple<int, int, int> maxCubes;

    const std::vector<std::string> &splittedContent = AdventOfCode::Utils::split(content, ';');

    for (auto &throws : splittedContent)
    {
        std::vector<std::string> splittedThrows = AdventOfCode::Utils::split(throws, ',');

        for (auto &t : splittedThrows)
        {
            if (t.at(0) == ' ')
                t.erase(0, 1);
        }

        int maxRed = 0;
        int maxGreen = 0;
        int maxBlue = 0;

        for (auto &t : splittedThrows)
        {
            const std::vector<std::string> &tokens = AdventOfCode::Utils::split(t, ' ');

            const int nb = std::stoi(tokens.at(0));
            const std::string &color = tokens.at(1);

            switch (cubesMap.at(color))
            {
                case AdventOfCode::Cubes::RED:
                    maxRed = std::max(maxRed, nb);
                    break;
                case AdventOfCode::Cubes::GREEN:
                    maxGreen = std::max(maxGreen, nb);
                    break;
                case AdventOfCode::Cubes::BLUE:
                    maxBlue = std::max(maxBlue, nb);
                    break;
            }
        }

        maxCubes = std::make_tuple(std::max(std::get<AdventOfCode::Cubes::RED>(maxCubes), maxRed), std::max(std::get<AdventOfCode::Cubes::GREEN>(maxCubes), maxGreen), std::max(std::get<AdventOfCode::Cubes::BLUE>(maxCubes), maxBlue));
    }

    return (maxCubes);
}

void AdventOfCode::Algorithm::calculateSumOfID()
{
    int sum = 0;

    for (auto &line : _fileContent)
    {
        const int id = std::stoi(line.substr(5, line.find(':') - 5));

        const std::string &content = line.substr(line.find(':') + 2);

        std::tuple<int, int, int> maxCubes = this->getMaximumUsedCubes(content);

        if (std::get<AdventOfCode::Cubes::RED>(_nbCubes) < std::get<AdventOfCode::Cubes::RED>(maxCubes) || std::get<AdventOfCode::Cubes::GREEN>(_nbCubes) < std::get<AdventOfCode::Cubes::GREEN>(maxCubes) || std::get<AdventOfCode::Cubes::BLUE>(_nbCubes) < std::get<AdventOfCode::Cubes::BLUE>(maxCubes))
            continue;

        sum += id;
    }

    _sumOfID = sum;
}

void AdventOfCode::Algorithm::calculateSumOfFewestRequiredCubes()
{
    int sum = 0;

    for (auto &line : _fileContent)
    {
        const std::string &content = line.substr(line.find(':') + 2);

        std::tuple<int, int, int> maxCubes = this->getMaximumUsedCubes(content);

        const int subSum = std::get<AdventOfCode::Cubes::RED>(maxCubes) * std::get<AdventOfCode::Cubes::GREEN>(maxCubes) * std::get<AdventOfCode::Cubes::BLUE>(maxCubes);

        if (subSum == 0)
            continue;

        sum += subSum;
    }

    _sumOfFewestRequiredCubes = sum;
}
