// CLevetDev, 01/12/2023

#ifndef PARSER_HPP_
    #define PARSER_HPP_

    #include <string>
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
                */
                Parser(const std::string &filePath = "");

                /*
                ** @brief Destroys the Parser object
                */
                ~Parser() = default;

                /* Getter(s) */

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

            private:
                /* Private member(s) */

                bool _isFileValid;
                std::string _filePath;

                std::vector<std::string> _fileContent;

                /* Private method(s) */

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
