//
// Created by cenka on 1/31/2024.
//

#ifndef JSON_CONVERTER_JSONPAIR_HPP
#define JSON_CONVERTER_JSONPAIR_HPP

#include <iostream>
#include <unordered_map>
#include <variant>

struct JsonPair{
    std::unordered_map<std::string, std::variant<int, double, std::string, JsonPair>> properties;
};

#endif //JSON_CONVERTER_JSONPAIR_HPP
