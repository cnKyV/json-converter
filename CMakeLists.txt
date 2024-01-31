cmake_minimum_required(VERSION 3.26)
project(json_converter)

set(CMAKE_CXX_STANDARD 17)

add_executable(json_converter main.cpp
        include/json.hpp
        include/details/deserializer.hpp
        include/details/serializer.hpp
        include/details/defines.hpp)
