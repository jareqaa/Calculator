#pragma once
#include "UANumber.h"
#include <memory>

class TProc
{
public:
    enum TOptn { None, Add, Sub, Mul, Dvd };  // двухоперандные операции
    enum TFunc { Rev, Sqr };                  // однооперандные операции

private:
    std::unique_ptr<TANumber> Lop_Res;        // левый операнд и результат
    std::unique_ptr<TANumber> Rop;            // правый операнд
    TOptn operation;                          // текущая операция

public:
    // Конструктор по умолчанию
    TProc() : operation(None) 
    {
        resetProc();
    }

    // Сброс процессора
    void resetProc() 
    {
        Lop_Res = nullptr;  // Дефолтное значение
        Rop = nullptr;      // Дефолтное значение
        operation = None;
    }

    // Сброс операции
    void resetOperation() 
    {
        operation = None;
    }

    // Выполнить операцию
    void doOperation() 
    {
        if (!Lop_Res || !Rop) return;

        switch (operation) 
        {
        case Add: *Lop_Res = *(*Lop_Res + *Rop); break;
        case Sub: *Lop_Res = *(*Lop_Res - *Rop); break;
        case Mul: *Lop_Res = *(*Lop_Res * *Rop); break;
        case Dvd: *Lop_Res = *(*Lop_Res / *Rop); break;
        default: break;
        }
    }

    // Вычислить функцию
    void doFunction(const TFunc& func) 
    {
        if (!Rop) return;

        switch (func) 
        {
        case Rev: *Rop = *Rop->rev(); break;
        case Sqr: *Rop = *Rop->sqr(); break;
        default: break;
        }
    }

    // Чтение левого операнда (возвращает копию)
    std::unique_ptr<TANumber> getLop() const 
    {
        return Lop_Res ? Lop_Res->clone() : nullptr;
    }

    // Запись левого операнда
    void setLop(std::unique_ptr<TANumber> num) 
    {
        Lop_Res = std::move(num);
    }

    // Чтение правого операнда (возвращает копию)
    std::unique_ptr<TANumber> getRop() const 
    {
        return Rop ? Rop->clone() : nullptr;
    }

    // Запись правого операнда
    void setRop(std::unique_ptr<TANumber> num) 
    {
        Rop = std::move(num);
    }

    // Чтение состояния
    TOptn getOperation() const 
    {
        return operation;
    }

    // Запись состояния
    void setOperation(const TOptn& optn) {
        operation = optn;
    }
};