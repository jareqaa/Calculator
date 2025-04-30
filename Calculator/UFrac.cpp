#pragma once
#include "UFrac.h"
#include "UException.h"

// конструктор для строк
TFrac::TFrac(const std::string& str)
{
	size_t slashPos = str.find('/');
	if (slashPos == std::string::npos)
	{
		try
		{
			a = std::stoi(str);
		}
		catch (...)
		{
			throw TException("Ошибка! Неверный числитель");
		}
		b = 1;
	}
	else
	{
		// парсим числитель
		try
		{
			a = std::stoi(str.substr(0, slashPos));
		}
		catch (...)
		{
			throw TException("Ошибка! Неверный числитель");
		}

		// парсим знаменатель
		try
		{
			b = std::stoi(str.substr(slashPos + 1));
		}
		catch (...)
		{
			throw TException("Ошибка! Неверный знаменатель");
		}
	}

	if (b == 0)
	{
		throw TException("Ошибка! Знаменатель не может быть нулём!");
	}
	reduce();
}

// НОД
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

// сокращение дроби
void TFrac::reduce()
{
	int gcd_ = gcd(a, b);
	a /= gcd_;
	b /= gcd_;

	if (b < 0)
	{
		a *= -1;
		b *= -1;
	}
}

// оператор ==
bool TFrac::operator==(const TANumber& other) const
{
	const TFrac* otherPtr = dynamic_cast<const TFrac*>(&other);

	if (!otherPtr) throw TException("Ошибка! Неверный тип...\n");

	return a == otherPtr->a && b == otherPtr->b;
}

// операция сложить
std::unique_ptr<TANumber> TFrac::operator+(const TANumber& other) const
{
	const TFrac* otherPtr = dynamic_cast<const TFrac*>(&other);

	if (!otherPtr) throw TException("Ошибка! Неверный тип...\n");

	return std::make_unique<TFrac>(a * otherPtr->b + otherPtr->a * b, b * otherPtr->b);
}

// операция умножить
std::unique_ptr<TANumber> TFrac::operator*(const TANumber& other) const
{
	const TFrac* otherPtr = dynamic_cast<const TFrac*>(&other);

	if (!otherPtr) throw TException("Ошибка! Неверный тип...\n");

	return std::make_unique<TFrac>(a * otherPtr->a, b * otherPtr->b);
}

// операция вычесть
std::unique_ptr<TANumber> TFrac::operator-(const TANumber& other) const
{
	const TFrac* otherPtr = dynamic_cast<const TFrac*>(&other);

	if (!otherPtr) throw TException("Ошибка! Неверный тип...\n");

	return std::make_unique<TFrac>(a * otherPtr->b - otherPtr->a * b, b * otherPtr->b);
}

// операция делить
std::unique_ptr<TANumber> TFrac::operator/(const TANumber& other) const
{
	const TFrac* otherPtr = dynamic_cast<const TFrac*>(&other);

	if (!otherPtr) throw TException("Ошибка! Неверный тип...\n");

	return std::make_unique<TFrac>(a * otherPtr->b, b * otherPtr->a);
}

// операция обратить
std::unique_ptr<TANumber> TFrac::rev() const
{
	return std::make_unique<TFrac>(b, a);
}

// операция возвести в квадрат
std::unique_ptr<TANumber> TFrac::sqr() const
{
	return std::make_unique<TFrac>(a * a, b * b);
}

// число есть 0
bool TFrac::isZero() const
{
	return a == 0;
}

// взять дробь строка
std::string TFrac::getString() const
{
	std::string str = std::to_string(a) + "/" + std::to_string(b);
	if (str[0] == '-')
	{
		str = "(" + str + ")";
	}
	return str;
}

// получить копию
std::unique_ptr<TANumber> TFrac::clone() const
{
	return std::make_unique<TFrac>(*this);
}

// оператор =
TANumber& TFrac::operator=(const TANumber& other)
{
	const TFrac* otherPtr = dynamic_cast<const TFrac*>(&other);
	if (!otherPtr) throw TException("Invalid type");

	this->a = otherPtr->a;
	this->b = otherPtr->b;
	return *this;
}