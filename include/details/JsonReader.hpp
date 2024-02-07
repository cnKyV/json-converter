//
// Created by cenka on 2/2/2024.
//

#ifndef JSON_CONVERTER_JSONREADER_HPP
#define JSON_CONVERTER_JSONREADER_HPP

#include <iostream>
#include <vector>
#include <map>
#include "defines.hpp"

template <typename T>
class JsonReader{
size_t indent;
size_t arrayElement;

bool isKey = NULL;
bool inArray = NULL;
bool inObject = NULL;
bool isCommaObjectSeperator = NULL;
bool closingCurlyBracketRead = NULL;
bool openingCurlyBracketRead = NULL;

std::vector<char> currentWord;
std::vector<std::string> previousKeysList;
std::variant<int, double, std::string, T> valueType;

enum class CurrentStage{
Is
};

public:
    void ReceiveInput(std::string& input)
    {
        if (input[0] != ASCII_JSON_OPENING_CURLY_BRACKET)
        {
            throw std::bad_cast();
        }




        for(char& c : input)
        {
            switch (c) {
                case ASCII_JSON_OPENING_CURLY_BRACKET:
                    openingCurlyBracketRead = true;
                    closingCurlyBracketRead = false;

                    if (openingCurlyBracketRead) ++indent;


                    break;

                case ASCII_JSON_CLOSING_CURLY_BRACKET:
                    closingCurlyBracketRead = true;
                    openingCurlyBracketRead = false;

                    if (indent > 0 && closingCurlyBracketRead) --indent;

                    else
                    {

                    }

                    break;

                case ASCII_JSON_DOUBLE_QUOTE:
                    if (isKey)
                    {

                    }
                    else
                    {

                    }


                    break;

                case ASCII_JSON_COLON:
                    isKey = false;
                    break;

                case ASCII_JSON_OPENING_SQUARE_BRACKETS:
                    inArray = true;
                    break;

                case ASCII_JSON_CLOSING_SQUARE_BRACKETS:
                    inArray = false;
                    break;

                case ASCII_JSON_OPENING_PARANTHESIS:

                    break;

                case ASCII_JSON_CLOSING_PARANTHESIS:

                    break;

                case ASCII_JSON_COMMA:
                    if (inArray)
                    {

                    }

                    else
                    {

                    }
                    break;

                default:

                    break;


            }
        }
    }

    CurrentStage GetStage()
    {
        CurrentStage stage;

        return stage;
    }

    int GetIndent()
    {

    }

    std::map<int, std::string> GetIndentPath()
    {

    }

};

#endif //JSON_CONVERTER_JSONREADER_HPP
