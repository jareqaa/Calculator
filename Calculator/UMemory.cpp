#pragma once
#include <string>
#include "UANumber.h"
#include <memory>

class TMemory
{
public:
    enum State { On, Off };

private:
    std::unique_ptr<TANumber> f_number;  // Храним число в unique_ptr
    State state;

public:
    // Конструктор принимает unique_ptr для явного управления памятью
    explicit TMemory(std::unique_ptr<TANumber> num = nullptr) : f_number(num ? std::move(num) : nullptr), state(State::Off) {}

    // Запись числа в память
    void write(std::unique_ptr<TANumber> num) 
    {
        f_number = std::move(num);
        state = State::On;
    }

    // Получение числа из памяти (с проверкой состояния)
    std::unique_ptr<TANumber> read() const 
    {
        if (state == State::Off || !f_number) 
        {
            return nullptr;
        }
        return f_number->clone();  // Возвращаем копию числа
    }

    // Добавление числа к содержимому памяти
    void add(const TANumber& num) 
    {
        if (state == State::Off || !f_number) 
        {
            throw TException("Memory is empty or disabled");
        }
        *f_number = *(*f_number + num);
    }

    // Очистка памяти
    void clear() 
    {
        f_number.reset();
        state = State::Off;
    }

    // Получение состояния памяти в виде строки
    std::string getState() const 
    {
        return state == State::On ? "On" : "Off";
    }

    // Установка состояния памяти
    void setState(State st) 
    {
        state = st;
        if (state == State::Off) 
        {
            f_number.reset();
        }
    }

    // Проверка, есть ли число в памяти
    bool isEmpty() const 
    {
        return !f_number;
    }
};