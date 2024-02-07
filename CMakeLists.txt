cmake_minimum_required(VERSION 3.26)
project(json_converter)

set(CMAKE_CXX_STANDARD 17)

add_executable(json_converter main.cpp
        include/details/defines.hpp
        include/Json.cpp
        include/Json.hpp
        include/details/JsonPair.hpp
        include/details/JsonReader.hpp)
