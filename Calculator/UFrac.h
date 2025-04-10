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

	// число есть 0
	bool isZero() const override;

	// взять числитель
	int getA() const { return a; }

	// взять знаменатель
	int getB() const { return b; }

	// взять дробь строка
	std::string getString() const override;
};