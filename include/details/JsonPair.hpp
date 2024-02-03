//
// Created by cenka on 1/31/2024.
//

#ifndef JSON_CONVERTER_JSONPAIR_HPP
#define JSON_CONVERTER_JSONPAIR_HPP

#include <iostream>
#include <unordered_map>
#include <variant>
#include <vector>

struct JsonPair{
    std::unordered_map<std::string, std::variant<int, double, std::string, JsonPair, std::vector<int>, std::vector<std::string>, std::vector<double>>> properties;
};

#endif //JSON_CONVERTER_JSONPAIR_HPP
