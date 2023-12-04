// CLevetDev, 02/12/2023

#ifndef ALGORITHM_HPP_
    #define ALGORITHM_HPP_

    #include <string>
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
                Algorithm(const std::vector<std::string> &fileContent = {}, const std::tuple<int, int, int> &nbCubes = std::make_tuple(0, 0, 0));

                /*
                ** @brief Destroys the Algorithm object
                */
                ~Algorithm() = default;

                /* Getter(s) */

                /*
                ** @brief Gets the sum of the ID
                **
                ** @return The sum of the ID
                */
                int getSumOfID() const;

                /*
                ** @brief Gets the sum of the fewest required cubes multiplied between them
                **
                ** @return The sum of the fewest required cubes multiplied between them
                */
                int getSumOfFewestRequiredCubes() const;

            private:
                /* Private member(s) */

                int _sumOfID;
                int _sumOfFewestRequiredCubes;
                std::vector<std::string> _fileContent;
                std::tuple<int, int, int> _nbCubes;

                /* Private method(s) */

                /*
                ** @brief Gets the maximum used cubes
                **
                ** @param content The line to parse
                **
                ** @return The maximum used cubes
                */
                std::tuple<int, int, int> getMaximumUsedCubes(const std::string &content) const;

                /*
                ** @brief Calculates the sum of the valid games IDs
                */
                void calculateSumOfID();

                /*
                ** @brief Calculates the sum of the fewest required cubes multiplied between them
                */
                void calculateSumOfFewestRequiredCubes();
        };
    }

#endif /* !ALGORITHM_HPP_ */
