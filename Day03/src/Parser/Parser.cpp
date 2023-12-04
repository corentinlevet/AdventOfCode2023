// CLevetDev, 03/12/2023

#include "Parser.hpp"

#include <fstream>
#include <iostream>

/* Constructor & Destructor */

AdventOfCode::Parser::Parser(const std::string &filePath) : _isFileValid(true), _filePath(filePath)
{
    this->checkFileValidity();

    if (this->isFileValid())
        this->fillFileContent();
}

/* Getter(s) */

bool AdventOfCode::Parser::isFileValid() const
{
    return (_isFileValid);
}

const std::vector<std::string> &AdventOfCode::Parser::getFileContent()
{
    return (_fileContent);
}

/* Private method(s) */

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
