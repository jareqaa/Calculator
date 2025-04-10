#pragma once
#include <string>

class Editor
{
protected:
	std::string number;	// строковое представление числа

public:
	// проверка является ли число нулем
	virtual bool isZero() const = 0;

	// добавление минуса
	virtual std::string addSign() = 0;

	// забой символа
	virtual std::string Bs() = 0;

	// очистить
	virtual std::string clear() = 0;

	// писать строку
	virtual void set(const std::string& str) = 0;

	// читать строку
	virtual std::string get() const = 0;

	// добавить цифру
	virtual std::string addDigit(const int& digit) = 0;

	// добавить ноль
	virtual std::string addZero() = 0;
};