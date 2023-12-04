// CLevetDev, 02/12/2023

#include <iostream>

#include "Algorithm.hpp"
#include "Parser.hpp"

int main(int argc, char** argv)
{
    if (argc < 2 || argc > 5)
    {
        std::cout << "Usage: " << argv[0] << " <file> <nbRedCubes> <nbGreenCubes> <nbBlueCubes>" << std::endl;
        return (1);
    }

    AdventOfCode::Parser parser(argv[1], argc >= 3 ? argv[2] : "0", argc >= 4 ? argv[3] : "0", argc >= 5 ? argv[4] : "0");

    if (!parser.isNbCubesValid() || !parser.isFileValid())
        return (1);

    AdventOfCode::Algorithm algorithm(parser.getFileContent(), parser.getNbCubes());

    const int sumOfID = algorithm.getSumOfID();

    if (sumOfID == -1)
    {
        std::cout << "Invalid file" << std::endl;
        return (1);
    }

    std::cout << "Sum of ID: " << sumOfID << std::endl;

    const int sumOfFewestRequiredCubes = algorithm.getSumOfFewestRequiredCubes();

    if (sumOfFewestRequiredCubes == -1)
    {
        std::cout << "Invalid file" << std::endl;
        return (1);
    }

    std::cout << "Sum of fewest required cubes: " << sumOfFewestRequiredCubes << std::endl;

    return (0);
}
