#pragma once
#include <string>
#include "UException.h"
#include <memory>

class TANumber
{
protected:
	std::string number;	// строковое представление числа

public:
	
	// число есть 0
	virtual bool isZero() const = 0;

	// оператор ==
	virtual bool operator==(const TANumber& other) const = 0;

	// оператор +
	virtual std::unique_ptr<TANumber> operator+(const TANumber& other) const = 0;

	// оператор -
	virtual std::unique_ptr<TANumber> operator-(const TANumber& other) const = 0;

	// оператор /
	virtual std::unique_ptr<TANumber> operator/(const TANumber& other) const = 0;

	// оператор *
	virtual std::unique_ptr<TANumber> operator*(const TANumber& other) const = 0;

	// операция обратить 
	virtual std::unique_ptr<TANumber> rev() const = 0;

	// операция возвести в квадрат
	virtual std::unique_ptr<TANumber> sqr() const = 0;

	// взять число в виде строки
	virtual std::string getStringN() const = 0;
};