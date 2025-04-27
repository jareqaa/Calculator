#pragma once
#include "UPEditor.h"

// Проверка на ноль
bool TPEditor::isZero() const
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

// Добавление/удаление знака
std::string TPEditor::addSign()
{
    if (!number.empty() && number[0] == '-')
    {
        number.erase(0, 1);
    }
    else
    {
        number.insert(0, "-");
    }
    return number;
}

// Удаление последнего символа
std::string TPEditor::Bs()
{
    if (number.empty())
    {
        throw TException("Empty string");
    }
    number.pop_back();
    if (number.empty() || number == "-")
    {
        number = "";
    }
    return number;
}

// Очистка редактора
std::string TPEditor::clear()
{
    number.clear();
    return number;
}

// Установка значения
void TPEditor::set(const std::string& num)
{
    number = num.empty() ? "0" : num;
    if (!number.empty() && number[0] == '(' && number[number.size() - 1] == ')')
    {
        number.erase(0, 1);
        number.erase(number.size() - 1);
    }
}

// Получение значения
std::string TPEditor::get() const
{
    return number.empty() ? "0" : number;
}

// Добавление цифры
std::string TPEditor::addDigit(const int& digit)
{
    if (number.size() == 1 && number[0] == '0' || number.size() == 2 && number[1] == '0' && number[0] == '-')
    {
        number.pop_back();
    }
    number += Convertor::int_to_Char(digit);
    return number;
}

// Добавление нуля
std::string TPEditor::addZero()
{
    if (number.empty() || number == "0")
    {
        number = "0";
    }
    else {
        number += "0";
    }
    return number;
}

// Добавление разделителя
std::string TPEditor::addSeparator()
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