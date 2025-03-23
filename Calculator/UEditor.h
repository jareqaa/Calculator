#pragma once
#include <string>

class TEditor
{
	std::string number;	// строкове представление p-ичного числа

public:
	// конструктор по умолчанию
	TEditor() : number("") {}

	// проверка является ли число нулем
	bool isZero() const { return 0 == stod(number) ? true : false; }

	// добавление минуса
	std::string addSign();

	// добавить p-ичную цифру
	std::string addDigit(const int& digit);

	// добавить разделитель
	std::string addDot();

	// добавить ноль
	std::string addZero();

	// забой символа
	std::string Bs();

	// очистить
	std::string clear();

	// редактировать
	std::string edit(const int& i);

	// читать строку
	std::string get() const { return number; }

	// писать строку
	void set(const std::string& str) { number = str; }
};