#include "UEditor.h"
#include "Convertor.h"
#include "UException.h"

// добавление минуса
std::string TEditor::addSign()
{
	if (number[0] == '-')
	{
		number.erase(0, 1);
	}
	else
	{
		number.insert(0, "-");
	}

	return number;
}

// добавить p-ичную цифру
std::string TEditor::addDigit(const int& digit)
{
	number += Convertor::int_to_Char(digit);
	return number;
}

// добавить разделитель
std::string TEditor::addDot()
{
	if (Convertor::dotCounter(number) == 0)
	{
		number = number.empty() ? "0." : number + '.';
		return number;
	}
	else
	{
		throw TException("Ошибка! Неверный ввод...\n");
	}
}

// добавить ноль
std::string TEditor::addZero()
{
	number += '0';
	return number;
}

// забой символа
std::string TEditor::Bs()
{
	if (number.empty())
	{
		throw TException("Ошибка! Строка пуста...\n");
	}

	number.erase(number.size() - 1);
	return number;
}

// очистить
std::string TEditor::clear()
{
	number.clear();
	return number;
}

// редактировать
std::string TEditor::edit(const int& i)
{
	switch (i)
	{
	default:
		break;
	}

	return number;
}