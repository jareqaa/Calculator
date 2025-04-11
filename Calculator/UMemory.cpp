#pragma once
#include "UMemory.h"

// Запись числа в память
void TMemory::set(std::unique_ptr<TANumber> num)
{
    f_number = std::move(num);
    state = fstate::On;
}

// Получение числа из памяти (с проверкой состояния)
std::unique_ptr<TANumber> TMemory::get() const
{
    if (state == fstate::Off || !f_number)
    {
        return nullptr;
    }
    return f_number->clone();  // Возвращаем копию числа
}

// Добавление числа к содержимому памяти
void TMemory::add(const std::unique_ptr<TANumber> num)
{
    if (state == fstate::Off || !f_number)
    {
        throw TException("Memory is empty or disabled");
    }
    *f_number = *(*f_number + *num);
}

// Очистка памяти
void TMemory::clear()
{
    f_number.reset();
    state = fstate::Off;
}

// Установка состояния памяти
void TMemory::setState(fstate st)
{
    state = st;
    if (state == fstate::Off)
    {
        f_number.reset();
    }
}