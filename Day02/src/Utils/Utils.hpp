// CLevetDev, 02/12/2023

#ifndef UTILS_HPP_
    #define UTILS_HPP_

    #include <string>
    #include <vector>

    namespace AdventOfCode {
        class Utils {
            public:
                /* Static method(s) */

                /*
                ** @brief Splits a string with a delimiter
                **
                ** @param str The string to split
                ** @param delimiter The delimiter
                **
                ** @return A vector containing the splitted string
                */
                static std::vector<std::string> split(const std::string &str, const char &delimiter);
        };
    }

#endif /* !UTILS_HPP_ */
