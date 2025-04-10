#pragma once
#include <string>
#include "UException.h"
#include "Convertor.h"

class Editor
{
protected:
	std::string number;	// строковое представление числа

public:
    // Проверка на ноль
    virtual bool isZero() const 
    {
        return number.empty() || number == "0" || number == "0." || number == "0/";
    }

    // Добавление/удаление знака
    virtual std::string addSign() 
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
    virtual std::string Bs()
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
    virtual std::string clear() 
    {
        number.clear();
        return number;
    }

    // Установка значения
    virtual void set(const std::string& num) 
    {
        number = num.empty() ? "0" : num;
    }

    // Получение значения
    virtual std::string get() const 
    {
        return number.empty() ? "0" : number;
    }

    // Добавление цифры (абстрактный метод)
    virtual std::string addDigit(int digit) = 0;

    // Добавление нуля
    virtual std::string addZero() {
        if (number.empty() || number == "0") 
        {
            number = "0";
        }
        else {
            number += "0";
        }
        return number;
    }

    // Добавление разделителя (абстрактный метод)
    virtual std::string addSeparator() = 0;
};