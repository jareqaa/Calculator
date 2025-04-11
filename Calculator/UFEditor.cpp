#pragma once
#include "UFEditor.h"

std::string FEditor::addDigit(int digit)
{
    if (number.size() == 1 && number[0] == '0' || number.size() == 2 && number[1] == '0')
    {
        number.pop_back();
    }
    number += Convertor::int_to_Char(digit);
    return number;
}

std::string FEditor::addSeparator()
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

std::string FEditor::Bs()
{
    TPEditor::Bs();
    if (!number.empty() && number.back() == '/')
    {
        isNumerator = true;
    }
    return number;
}

std::string FEditor::clear()
{
    TPEditor::clear();
    isNumerator = true;
    return number;
}