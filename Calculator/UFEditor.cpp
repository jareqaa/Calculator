#pragma once
#include "UFEditor.h"

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