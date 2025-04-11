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
    virtual bool isZero() const = 0;

    // Добавление/удаление знака
    virtual std::string addSign() = 0;

    // Удаление последнего символа
    virtual std::string Bs() = 0;

    // Очистка редактора
    virtual std::string clear() = 0;

    // Установка значения
    virtual void set(const std::string& num) = 0;

    // Получение значения
    virtual std::string get() const = 0;

    // Добавление цифры (абстрактный метод)
    virtual std::string addDigit(int digit) = 0;

    // Добавление нуля
    virtual std::string addZero() = 0;

    // Добавление разделителя (абстрактный метод)
    virtual std::string addSeparator() = 0;
};