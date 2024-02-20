//
// Created by cenka on 2/2/2024.
//

#ifndef JSON_CONVERTER_JSONREADER_HPP
#define JSON_CONVERTER_JSONREADER_HPP

#include <iostream>
#include <vector>
#include <variant>
#include <map>
#include "defines.hpp"
#include "JsonPair.hpp"
#include "JsonSchema.hpp"
#include "JsonValueTypes.hpp"

template <typename T>
class JsonReader{
size_t indent;
size_t arrayElement;

bool isKey = true;
bool inArray = false;
bool inObject = false;
bool isCommaObjectSeperator = false;
bool closingCurlyBracketRead = false;
bool openingCurlyBracketRead = true;
bool beginRead = false;
bool readValue = false;

std::string currentWord;
std::vector<std::string> previousKeysList;
std::vector<std::variant<int, double, std::string, T>> previousValuesList;
JsonTypeValues valueType;

enum class CurrentStage{
Is
};

void ResetCurrentWord()
{
    if (isKey) previousKeysList.push_back(currentWord);
    else
        switch (valueType) {
            case STRING:
                previousValuesList.emplace_back(currentWord);
                break;

            case INT:
                previousValuesList.emplace_back(std::stoi(currentWord));
                break;

            case DECIMAL:
                previousValuesList.emplace_back(std::stod(currentWord));
                break;

            case OBJECT:
                break;
        }

    currentWord = "";
}

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
                    if (!beginRead)
                    {
                        beginRead = true;
                        if (readValue)
                        {
                            valueType = STRING;
                            readValue = false;
                        }
                    }
                    else if(beginRead && currentWord.back() == '\\' || !currentWord.empty()) continue;
                    else
                    {
                        beginRead = false;
                        ResetCurrentWord();
                    }

                    break;

                case ASCII_JSON_COLON:
                    if (isKey)
                    {
                        isKey = false;
                        readValue = true;
                    }
                    else if(!isKey && beginRead) continue;
                    else isKey = true;
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

    int GetIndent()
    {

    }

    std::map<int, std::string> GetIndentPath()
    {

    }

};

#endif //JSON_CONVERTER_JSONREADER_HPP
