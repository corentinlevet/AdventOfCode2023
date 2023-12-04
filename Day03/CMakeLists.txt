cmake_minimum_required(VERSION 3.14)

set(BIN gearRatios)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -std=c++17")

project(${BIN} LANGUAGES CXX)

set(SRC
    src/Main.cpp
    src/Algorithm/Algorithm.cpp
    src/Parser/Parser.cpp
)

add_executable(${BIN} ${SRC})

target_include_directories(${BIN}
    PRIVATE
        src
        src/Algorithm
        src/Parser
)