#pragma once
#include "UANumber.h"

// класс комплексных чисел
class TComp : public TANumber
{
	double re;	// действительная часть
	double im;	// мнимая часть

public:
	// конструктор по умолчанию
	TComp() : re(0), im(0) {}

	// конструктор для чисел
	TComp(const double& re_, const double& im_) : re(re_), im(im_) {}

	// конструктор для строк
	TComp(const std::string& str);

	// конструктор копирования
	TComp(const TComp& other) : re(other.re), im(other.im) {}

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

	// взять дробь строка
	std::string getString() const override;

	// получить копию
	std::unique_ptr<TANumber> clone() const override;

	// оператор =
	TANumber& operator=(const TANumber& other) override;

	// модуль
	double abs_() const;

	// угол в радианах
	double angleRad() const;

	// степень
	TComp degree(const int& n) const;

	// корень
	TComp sqrt_(const int& n, const int& i) const;
};