// CLevetDev, 02/12/2023

#include "Utils.hpp"

#include <sstream>

/* Static method(s) */

std::vector<std::string> AdventOfCode::Utils::split(const std::string &str, const char &delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);

    while (std::getline(tokenStream, token, delimiter))
        tokens.push_back(token);

    return (tokens);
}
