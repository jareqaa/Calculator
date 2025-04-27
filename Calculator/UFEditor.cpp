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
    }
    return number;
}