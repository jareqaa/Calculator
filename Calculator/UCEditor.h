#pragma once
#include "Convertor.h"
#include "UException.h"
#include "Editor.h"

class CEditor : public Editor 
{
private:
    bool isRealPart = true;

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
        if (number.find('i') == std::string::npos) 
        {
            if (number.empty() || number == "-") 
            {
                number += "0+i";
            }
            else 
            {
                number += "+i";
            }
            isRealPart = false;
        }
        return number;
    }

    std::string Bs() override
    {
        Editor::Bs();
        if (!number.empty() && number.back() == '+') 
        {
            isRealPart = true;
        }
        return number;
    }

    std::string clear() override 
    {
        Editor::clear();
        isRealPart = true;
        return number;
    }
};