// CLevetDev, 01/12/2023

#include <iostream>

#include "Algorithm.hpp"
#include "Parser.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <file>" << std::endl;
        return (1);
    }

    AdventOfCode::Parser parser(argv[1]);

    if (!parser.isFileValid())
        return (1);

    AdventOfCode::Algorithm algorithm(parser.getFileContent());

    const int score = algorithm.getScore();

    if (score == -1)
    {
        std::cout << "Invalid file" << std::endl;
        return (1);
    }

    std::cout << "Score: " << score << std::endl;

    return (0);
}
