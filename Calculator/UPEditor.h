#pragma once
#include <string>
#include "Editor.h"

class TPEditor : public Editor
{
public:
	// конструктор по умолчанию
	TPEditor() { number = ""; }

	// проверка является ли число нулем
	bool isZero() const override { return 0 == stod(number) ? true : false; }

	// добавление минуса
	std::string addSign() override;

	// добавить p-ичную цифру
	std::string addDigit(const int& digit) override;

	// добавить разделитель
	virtual std::string addSeparator();

	// добавить ноль
	std::string addZero() override;

	// забой символа
	std::string Bs() override;

	// очистить
	std::string clear() override;

	// редактировать
	std::string edit(const int& i);

	// читать строку
	std::string get() const override { return number; }

	// писать строку
	void set(const std::string& str) override { number = str; }
};