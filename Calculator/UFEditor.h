#pragma once
#include "Convertor.h"
#include "UException.h"
#include "Editor.h"

class FEditor : public Editor 
{
private:
    bool isNumerator = true;

public:
    std::string addDigit(int digit) override 
    {
        if (number.size() == 1 && number[0] == '0' || number.size() == 2 && number[1] == '0')
        {
            number.pop_back();
        }
        number += Convertor::int_to_Char(digit);
        return number;
    }

    std::string addSeparator() override 
    {
        if (number.find('/') == std::string::npos) 
        {
            if (number.empty() || number == "-") 
            {
                number += "0/";
            }
            else 
            {
                number += "/";
            }
            isNumerator = false;
        }
        return number;
    }

    std::string backspace() override 
    {
        Editor::backspace();
        if (!number.empty() && number.back() == '/') 
        {
            isNumerator = true;
        }
        return number;
    }

    std::string clear() override
    {
        Editor::clear();
        isNumerator = true;
        return number;
    }
};