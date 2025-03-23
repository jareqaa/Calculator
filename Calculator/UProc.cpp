#pragma once
#include "UPNumber.h"

template<class T>
class TProc
{
public:
	enum TOptn { None, Add, Sub, Mul, Dvd };	// двухоперандные операции

	enum TFunc { Rev, Sqr };					// однооперандные операции

private:

	T Lop_Res;									// левый операнд и результат операции

	T Rop;										//правый операнд

	TOptn operation;						// состояние процессора

public:
	
	// конструктор по умолчаниию
	TProc() : Lop_Res(T()), Rop(T()), operation(TOptn::None) {}

	// сброс процессора
	void resetProc() { Lop_Res = T(), Rop = T(), operation = TOptn::None; }

	// сброс операции
	void resetOperation() { operation = TOptn::None; }

	// выполнить операцию
	void doOperation();

	// вычислить функцию
	void doFunction(const TFunc& func);

	// читать левый операнд
	T getLop() const { return Lop_Res; }

	// записать левый операнд
	void setLop(const T& operand) { Lop_Res = operand; }

	// читать правый операнд
	T getRop() const { return Rop; }

	// записать правый операнд
	void setRop(const T& operand) { Rop = operand; }

	// изменить систему счисления
	void setCC(const int& cc_) { Rop.setCC(cc_); Lop_Res.setCC(cc_); }

	// изменить точность
	void setACC(const int& cc_) { Rop.setACC(cc_); Lop_Res.setACC(cc_); }

	// читать состояние
	TOptn getOperation() const { return operation; }

	// записать состояние
	void setOperation(const TOptn& optn) { operation = optn; }
};

// выполнить операцию
template<class T>
void TProc<T>::doOperation()
{
	switch (operation)
	{
	case TOptn::None:
		break;

	case TOptn::Add:
		Lop_Res = Lop_Res + Rop;
		break;

	case TOptn::Sub:
		Lop_Res = Lop_Res - Rop;
		break;

	case TOptn:: Mul:
		Lop_Res = Lop_Res * Rop;
		break;

	case TOptn::Dvd:
		Lop_Res = Lop_Res / Rop;
		break;

	default:
		break;
	}
}

// вычислить функцию
template<class T>
void TProc<T>::doFunction(const TFunc& func)
{
	switch (func)
	{
	case TFunc::Rev:
		Rop = TPNumber(1, Rop.getCC(), Rop.getACC()) / Rop;
		break;

	case TFunc::Sqr:
		Rop = Rop * Rop;
		break;

	default:
		break;
	}
}