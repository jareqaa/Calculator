#pragma once
#include <string>
#include "Editor.h"
#include "UException.h"

class TPEditor : public Editor 
{
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
        if (number.find('.') == std::string::npos) 
        {
            if (number.empty() || number == "-") 
            {
                number += "0.";
            }
            else 
            {
                number += ".";
            }
        }
        return number;
    }

    bool isZero() const override 
    {
        if (number.empty() || number == "0" || number == "0." || number == "-0.") 
        {
            return true;
        }
        try 
        {
            return std::stod(number) == 0.0;
        }
        catch (...) 
        {
            return false;
        }
    }
};