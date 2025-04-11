#pragma once
#include "UProc.h"

// Сброс процессора
void TProc::resetProc()
{
    Lop_Res = nullptr;
    Rop = nullptr;
    operation = None;
}

// Выполнить операцию
void TProc::doOperation()
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
void TProc::doFunction(const TFunc& func)
{
    if (!Rop) return;

    switch (func)
    {
    case Rev: *Rop = *Rop->rev(); break;
    case Sqr: *Rop = *Rop->sqr(); break;
    default: break;
    }
}