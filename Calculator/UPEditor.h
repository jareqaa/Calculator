#pragma once
#include <string>
#include "Editor.h"
#include "UException.h"

class TPEditor : public Editor 
{
public:
    // Проверка на ноль
    bool isZero() const override;

    // Добавление/удаление знака
    std::string addSign() override;

    // Удаление последнего символа
    virtual std::string Bs() override;

    // Очистка редактора
    std::string clear() override;

    // Установка значения
    void set(const std::string& num) override;

    // Получение значения
    std::string get() const override;

    // Добавление цифры
    std::string addDigit(const int& digit) override;
     
    // Добавление нуля
    std::string addZero() override;

    // Добавление разделителя
    virtual std::string addSeparator() override;
};