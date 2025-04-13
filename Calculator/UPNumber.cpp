#pragma once
#include "UPNumber.h"
#include "Convertor.h"
#include "UException.h"

// конструктор для вещественного числа
TPNumber::TPNumber(const double& a, const int& cc_, const int& acc_) :
	cc(cc_ < 2 || cc_ > 16 ? throw TException("Ошибка! Неверное основание системы счисления...\n") : cc_),
	acc(acc_ < 0 ? throw TException("Ошибка! Точность не может быть отрицательной...\n") : acc_)
{
	std::string number = Convertor::dbl_to_str(a, cc, acc);

	// проверка что число существует в заданной системе счисления
	for (int i = 0; i < number.size(); i++)
	{
		if (number[i] != '-' && number[i] != '.' && Convertor::char_To_num(number[i]) >= cc)
		{
			throw TException("Ошибка! Число не существует в заданной системе счисления...\n");
		}
	}

	n = a;
	number = getString();
}

// конструктор для строкового числа
TPNumber::TPNumber(const std::string& a, const std::string& cc_, const std::string& acc_) :
	cc(stoi(cc_) < 2 || stoi(cc_) > 16 ? throw TException("Ошибка! Неверное основание системы счисления...\n") : stoi(cc_)),
	acc(stoi(acc_) < 0 ? throw TException("Ошибка! Точность не может быть отрицательной...\n") : stoi(acc_))
{

	// проверка что число существует в заданной системе счисления
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != '-' && a[i] != '.' && Convertor::char_To_num(a[i]) >= cc)
		{
			throw TException("Ошибка! Число не существует в заданной системе счисления...\n");
		}
	}
	
	n = Convertor::dval(a, cc);		// получение числа
	number = getString();
}

// оператор ==
bool TPNumber::operator==(const TANumber& other) const
{
	const TPNumber* otherPtr = dynamic_cast<const TPNumber*>(&other);

	if (!otherPtr) throw TException("Ошибка! Неверный тип...\n");

	return n == otherPtr->n;
}

// операция сложить
std::unique_ptr<TANumber> TPNumber::operator+(const TANumber& other) const
{
	const TPNumber* otherPtr = dynamic_cast<const TPNumber*>(&other);

	if (!otherPtr) throw TException("Ошибка! Неверный тип...\n");

	if (cc != otherPtr->cc)
	{
		throw TException("Ошибка! Неверный операнд...\n");
	}

	return std::make_unique<TPNumber>(n + otherPtr->n, cc, acc);
}

// операция умножить
std::unique_ptr<TANumber> TPNumber::operator*(const TANumber& other) const
{
	const TPNumber* otherPtr = dynamic_cast<const TPNumber*>(&other);

	if (!otherPtr) throw TException("Ошибка! Неверный тип...\n");

	if (cc != otherPtr->cc)
	{
		throw TException("Ошибка! Неверный операнд...\n");
	}

	return std::make_unique<TPNumber>(n * otherPtr->n, cc, acc);
}

// операция вычесть
std::unique_ptr<TANumber> TPNumber::operator-(const TANumber& other) const
{
	const TPNumber* otherPtr = dynamic_cast<const TPNumber*>(&other);

	if (!otherPtr) throw TException("Ошибка! Неверный тип...\n");

	if (cc != otherPtr->cc)
	{
		throw TException("Ошибка! Неверный операнд...\n");
	}

	return std::make_unique<TPNumber>(n - otherPtr->n, cc, acc);
}

// операция делить
std::unique_ptr<TANumber> TPNumber::operator/(const TANumber& other) const
{
	const TPNumber* otherPtr = dynamic_cast<const TPNumber*>(&other);

	if (!otherPtr) throw TException("Ошибка! Неверный тип...\n");

	if (cc != otherPtr->cc)
	{
		throw TException("Ошибка! Неверный операнд...\n");
	}

	return std::make_unique<TPNumber>(n / otherPtr->n, cc, acc);
}

// взять число в виде строки
std::string TPNumber::getString() const
{
	return Convertor::dbl_to_str(n, cc, acc);
}

// операция обратить
std::unique_ptr<TANumber> TPNumber::rev() const
{
	return n != 0 ? std::make_unique<TPNumber>(1 / n, cc, acc) : throw TException("Ошибка! Деление на ноль...\n");
}

// операция возвести в квадрат
std::unique_ptr<TANumber> TPNumber::sqr() const
{
	return std::make_unique<TPNumber>(n * n, cc, acc);
}

// число есть 0
bool TPNumber::isZero() const
{
	return n == 0;
}

// получить копию
std::unique_ptr<TANumber> TPNumber::clone() const
{
	return std::make_unique<TPNumber>(*this);
}

// оператор =
TANumber& TPNumber::operator=(const TANumber& other)
{
	const TPNumber* otherPtr = dynamic_cast<const TPNumber*>(&other);
	if (!otherPtr) throw TException("Invalid type");

	this->n = round(otherPtr->n * pow(10, 10)) / pow (10, 10);
	this->cc = otherPtr->cc;
	this->acc = otherPtr->acc;
	return *this;
}