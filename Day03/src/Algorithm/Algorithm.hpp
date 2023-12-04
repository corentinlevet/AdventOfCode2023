// CLevetDev, 03/12/2023

#ifndef ALGORITHM_HPP_
    #define ALGORITHM_HPP_

    #include <map>
    #include <string>
    #include <tuple>
    #include <vector>

    namespace AdventOfCode
    {
        class Algorithm
        {
            public:
                /* Constructor & Destructor */

                /*
                ** @brief Constructs a new Algorithm object
                **
                ** @param fileContent The content of the file to parse
                */
                Algorithm(const std::vector<std::string> &fileContent = {});

                /*
                ** @brief Destroys the Algorithm object
                */
                ~Algorithm() = default;

                /* Getter(s) */

                /*
                ** @brief Gets the sum of all part numbers in the engine schematic
                **
                ** @return The sum of all part numbers in the engine schematic
                */
                int getSumOfAllPartNumbers() const;

                /*
                ** @brief Gets the sum of all gear ratios in the engine schematic
                **
                ** @return The sum of all gear ratios in the engine schematic
                */
                int getSumOfAllGearRatios() const;

            private:
                /* Private member(s) */

                int _sumOfAllPartNumbers;
                int _sumOfAllGearRatios;
                std::vector<std::string> _fileContent;

                /* Private method(s) */

                /*
                ** @brief Finds all numbers in the engine schematic
                **
                ** @return A map containing all numbers in the engine schematic
                */
                std::map<std::tuple<int, int>, std::string> findAllNumbersInEngineSchematic(void) const;

                /*
                ** @brief Finds all symbols in the engine schematic
                **
                ** @return A map containing all symbols in the engine schematic
                */
                std::map<std::tuple<int, int>, char> findAllSymbolsInEngineSchematic(void) const;

                std::vector<std::string> getLinesToCheck(const std::tuple<int, int> &position) const;

                /*
                ** @brief Gets all numbers around a symbol
                **
                ** @param position The position of the symbol
                ** @param numbers The map containing all numbers in the engine schematic
                **
                ** @return A vector containing all numbers around the symbol
                */
                std::vector<std::string> getNumbersAroundSymbol(const std::tuple<int, int> &position, const std::map<std::tuple<int, int>, std::string> &numbers) const;

                /*
                ** @brief Checks if a number is adjacent to a symbol
                **
                ** @param position The position of the number
                ** @param number The number to check
                **
                ** @return true if the number is adjacent to a symbol, false otherwise
                */
                bool isNumberAdjacentToSymbol(const std::tuple<int, int> &position, const std::string &number) const;

                /*
                ** @brief Calculates the sum of all part numbers in the engine schematic
                */
                void calculateSumOfAllPartNumbers();

                /*
                ** @brief Calculates the sum of all gear ratios in the engine schematic
                */
                void calculateSumOfAllGearRatios();
        };
    }

#endif /* !ALGORITHM_HPP_ */
