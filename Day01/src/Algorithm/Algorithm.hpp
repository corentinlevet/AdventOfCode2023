// CLevetDev, 01/12/2023

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
                Algorithm(const std::vector<std::string> &fileContent = {});

                /*
                ** @brief Destroys the Algorithm object
                */
                ~Algorithm() = default;

                /* Getter(s) */

                /*
                ** @brief Gets the score of the input file
                **
                ** @return The score of the input file
                */
                int getScore() const;

            private:
                /* Private member(s) */

                int _score;
                std::vector<std::string> _fileContent;

                /* Private method(s) */

                /*
                ** @brief Calculates the score of the input file
                */
                void calculateScore();
        };
    }

#endif /* !ALGORITHM_HPP_ */
