// CLevetDev, 02/12/2023

#ifndef PARSER_HPP_
    #define PARSER_HPP_

    #include <string>
    #include <tuple>
    #include <vector>

    namespace AdventOfCode
    {
        class Parser
        {
            public:
                /* Constructor & Destructor */

                /*
                ** @brief Constructs a new Parser object
                **
                ** @param filePath The path of the file to parse
                ** @param nbRedCubes The number of red cubes
                ** @param nbGreenCubes The number of green cubes
                ** @param nbBlueCubes The number of blue cubes
                */
                Parser(const std::string &filePath = "", const std::string &nbRedCubes = "0", const std::string &nbGreenCubes = "0", const std::string &nbBlueCubes = "0");

                /*
                ** @brief Destroys the Parser object
                */
                ~Parser() = default;

                /* Getter(s) */

                /*
                ** @brief Checks if the number of cubes is valid
                **
                ** @return true if the number of cubes is valid, false otherwise
                */
                bool isNbCubesValid() const;

                /*
                ** @brief Checks if the file is valid
                **
                ** @return true if the file is valid, false otherwise
                */
                bool isFileValid() const;

                /*
                ** @brief Gets the content of the file
                **
                ** @return The content of the file
                */
                const std::vector<std::string> &getFileContent();

                /*
                ** @brief Gets the number of cubes
                **
                ** @return The number of cubes
                */
                const std::tuple<int, int, int> &getNbCubes();

            private:
                /* Private member(s) */

                bool _isFileValid;
                bool _isNbCubesValid;
                std::string _filePath;

                std::vector<std::string> _fileContent;
                std::tuple<int, int, int> _nbCubes;

                /* Private method(s) */

                /*
                ** @brief Checks if the number of cubes is valid
                */
                void checkNbCubesValidity();

                /*
                ** @brief Checks if the file is valid
                */
                void checkFileValidity();

                /*
                ** @brief Fills the _fileContent vector with the content of the file
                */
                void fillFileContent();
        };
    }

#endif /* !PARSER_HPP_ */
