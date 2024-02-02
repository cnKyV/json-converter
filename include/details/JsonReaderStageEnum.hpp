//
// Created by cenka on 2/2/2024.
//

#ifndef JSON_CONVERTER_JSONREADERSTAGEENUM_HPP
#define JSON_CONVERTER_JSONREADERSTAGEENUM_HPP

#include <iostream>
#include "defines.hpp"

class JsonReaderRecordKeeper{
size_t indent;
size_t arrayElement;
bool isKey;
bool inArray;
bool inObject;
bool isCommaObjectSeperator;

enum CurrentStage{

};

public:
    void ReceiveInput(char& input)
    {

    }

    CurrentStage GetStage()
    {
        CurrentStage stage;

        return stage;
    }

    int GetIndent()
    {

    }

    int GetElementNumber()
    {

    }
};

#endif //JSON_CONVERTER_JSONREADERSTAGEENUM_HPP
