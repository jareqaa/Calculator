#pragma once
#include "UCEditor.h"

std::string CEditor::addIm(const int& j)
{
    if (number.find('i') == std::string::npos)
    {
        if (number.empty() || number == "-")
        {
            number += j == 0 ? "i*" : "- i*";
        }
        else
        {
            number += j == 0 ? "+ i*" : "- i*";
        }
        isRealPart = false;
    }
    else
    {
        throw TException("Ошибка! Неверный ввод...\n");
    }

    return number;
}

std::string CEditor::addSeparator()
{
    if (number.find('i') == std::string::npos)
    {
        if (Convertor::dotCounter(number) >= 1)
        {
            throw TException("Ошибка! Неверный ввод...\n");
        }
        else
        {
            number += '.';
        }
    }
    else
    {
        if (Convertor::dotCounter(number.substr(number.find('i'))) >= 1)
        {
            throw TException("Ошибка! Неверный ввод...\n");
        }
        else
        {
            number += '.';
        }
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