// CLevetDev, 02/12/2023

#include "Parser.hpp"

#include "Cubes.hpp"

#include <fstream>
#include <iostream>

/* Constructor & Destructor */

AdventOfCode::Parser::Parser(const std::string &filePath, const std::string &nbRedCubes, const std::string &nbGreenCubes, const std::string &nbBlueCubes) : _isFileValid(true), _filePath(filePath)
{
    _nbCubes = std::make_tuple(std::stoi(nbRedCubes), std::stoi(nbGreenCubes), std::stoi(nbBlueCubes));

    this->checkFileValidity();
    if (!this->isFileValid())
        return;

    this->checkNbCubesValidity();
    if (!this->isNbCubesValid())
        return;

    this->fillFileContent();
}

/* Getter(s) */

bool AdventOfCode::Parser::isNbCubesValid() const
{
    return (_isNbCubesValid);
}

bool AdventOfCode::Parser::isFileValid() const
{
    return (_isFileValid);
}

const std::vector<std::string> &AdventOfCode::Parser::getFileContent()
{
    return (_fileContent);
}

const std::tuple<int, int, int> &AdventOfCode::Parser::getNbCubes()
{
    return (_nbCubes);
}

/* Private method(s) */

void AdventOfCode::Parser::checkNbCubesValidity()
{
    if (std::get<Cubes::RED>(_nbCubes) < 0 || std::get<Cubes::GREEN>(_nbCubes) < 0 || std::get<Cubes::BLUE>(_nbCubes) < 0)
    {
        std::cerr << "Error: Invalid number of cubes" << std::endl;
        _isNbCubesValid = false;
        return;
    }
    _isNbCubesValid = true;
}

void AdventOfCode::Parser::checkFileValidity()
{
    std::ifstream fileStream(_filePath);

    if (!fileStream.is_open())
    {
        std::cerr << "Error: " << _filePath << ": No such file or directory" << std::endl;
        _isFileValid = false;
        return;
    }
    fileStream.close();
}

void AdventOfCode::Parser::fillFileContent()
{
    std::ifstream fileStream(_filePath);
    std::string line;

    while (std::getline(fileStream, line))
        _fileContent.push_back(line);
    fileStream.close();
}
