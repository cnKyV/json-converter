//
// Created by cenka on 1/31/2024.
//

#ifndef JSON_CONVERTER_JSON_HPP
#define JSON_CONVERTER_JSON_HPP

#include <iostream>
#include "details/JsonPair.hpp"
#include "details/JsonReader.hpp"

template <typename T>
class Json {
public:
    Json() = default;
    std::string serialize(T obj) {
        return std::to_string(obj);
    }
    T deserialize(std::string json) {
        return static_cast<T>(std::stoi(json));
    }

private:

    JsonPair jsonReader(std::string& jsonInput)
    {

    }



};




#endif //JSON_CONVERTER_JSON_HPP
