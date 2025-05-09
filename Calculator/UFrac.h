#pragma once
#include "UANumber.h"
#include "UException.h"

// класс простых дробей
class TFrac : public TANumber
{
	int a;	// числитель
	int b;	// знаменатель

	void reduce(); // сокращение дроби

public:
	// конструктор по умолчанию
	TFrac() : a(0), b(1) {}

	// конструктор для чисел
	TFrac(const int& a_, const int& b_) : a(a_), b(b_ == 0 ? throw TException("Ошибка! Деление на 0...\n") : b_) { reduce(); }

	// конструктор для строк
	TFrac(const std::string& str);

	// конструктор копирования
	TFrac(const TFrac& other) : a(other.a), b(other.b) {}

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