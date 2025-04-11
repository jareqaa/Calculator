#pragma once
#include "UCEditor.h"

std::string CEditor::addDot()
{
    if (Convertor::dotCounter(number) >= 1)
        throw TException("Ошибка! Неверный ввод");
    else
        number += '.';
    return number;
}

std::string CEditor::addDigit(int digit)
{
    if (number.size() == 1 && number[0] == '0' || number.size() == 2 && number[1] == '0')
    {
        number.pop_back();
    }
    number += Convertor::int_to_Char(digit);
    return number;
}

std::string CEditor::addSeparator()
{
    if (number.find('i') == std::string::npos)
    {
        if (number.empty() || number == "-")
        {
            number += "0 + i*";
        }
        else
        {
            number += " + i*";
        }
        isRealPart = false;
    }
    return number;
}

std::string CEditor::Bs()
{
    TPEditor::Bs();
    if (!number.empty() && number.back() == '+')
    {
        isRealPart = true;
    }
    return number;
}

std::string CEditor::clear()
{
    TPEditor::clear();
    isRealPart = true;
    return number;
}