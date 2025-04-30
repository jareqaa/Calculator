#pragma once
#include <memory>
#include <string>

class TANumber
{
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
	virtual std::string getString() const = 0;

	// получить копию
	virtual std::unique_ptr<TANumber> clone() const = 0;

	// оператор =
	virtual TANumber& operator=(const TANumber& other) = 0;
};