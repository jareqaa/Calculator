#pragma once
#include "UANumber.h"

// класс простых дробей
class TFrac : public TANumber
{
	int a;	// числитель
	int b;	// знаменатель

	void reduce(); // сокращение дроби

public:
	// конструктор по умолчанию
	TFrac() : a(0), b(1) { number = getString(); }

	// конструктор для чисел
	TFrac(const int& a_, const int& b_);

	// конструктор для строк
	TFrac(const std::string& str);

	// конструктор копирования
	TFrac(const TFrac& other) : a(other.a), b(other.b) { number = getString(); }

	// оператор ==
	bool operator==(const TANumber& other) const override;

	// операция сложить
	std::unique_ptr<TANumber> operator+(const TANumber& other) const override;

	// операция умножить
	std::unique_ptr<TANumber> operator*(const TANumber& other) const override;

	// операция вычесть
	std::unique_ptr<TANumber> operator-(const TANumber& other) const override;

	// операция делить
	std::unique_ptr<TANumber> operator/(const TANumber& other) const override;

	// операция обратить
	std::unique_ptr<TANumber> rev() const override;

	// операция возвести в квадрат
	std::unique_ptr<TANumber> sqr() const override;

	// получить копию
	std::unique_ptr<TANumber> clone() const override;

	// оператор =
	TANumber& operator=(const TANumber& other) override;

	// число есть 0
	bool isZero() const override;

	// взять числитель
	int getA() const { return a; }

	// взять знаменатель
	int getB() const { return b; }

	// взять дробь строка
	std::string getString() const override;
};

// конструктор для чисел
TFrac::TFrac(const int& a_, const int& b_) : a(a_), b(b_ == 0 ? throw TException("Ошибка! Деление на 0...\n") : b_)
{
	reduce();  // Сокращаем дробь
	number = getString();
}

// конструктор для строк
TFrac::TFrac(const std::string& str)
{
	size_t slashPos = str.find('/');
	if (slashPos == std::string::npos)
	{
		throw TException("Ошибка! Некорректный формат дроби. Ожидается a/b");
	}

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

	if (b == 0)
	{
		throw TException("Ошибка! Знаменатель не может быть нулём!");
	}
	reduce();
	number = getString();
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
	return std::to_string(a) + "/" + std::to_string(b);
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