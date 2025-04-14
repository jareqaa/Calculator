#pragma once
#include <string>
#include "UANumber.h"
#include <memory>
#include "UException.h"

class TMemory
{
public:
    enum fstate { On, Off };

private:
    std::unique_ptr<TANumber> f_number;  // указатель на число TANumber
    fstate state;                        // состояние памяти

public:
    // Конструктор принимает unique_ptr для явного управления памятью
    TMemory(std::unique_ptr<TANumber> num = nullptr) : f_number(num ? std::move(num) : nullptr), state(fstate::Off) {}

    // Запись числа в память
    void set(std::unique_ptr<TANumber> num);

    // Получение числа из памяти (с проверкой состояния)
    std::unique_ptr<TANumber> get() const;

    // Добавление числа к содержимому памяти
    void add(const std::unique_ptr<TANumber> num);

    // Очистка памяти
    void clear();

    // Получение состояния памяти в виде строки
    std::string getState() const { return state == fstate::On ? "On" : "Off"; }

    // Установка состояния памяти
    void setState(fstate st);

    // Проверка, есть ли число в памяти
    bool isEmpty() const { return !f_number; }
};