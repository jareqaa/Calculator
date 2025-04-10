#include "UPEditor.h"
#include "Convertor.h"
#include "UException.h"

// добавление минуса
std::string TPEditor::addSign()
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
std::string TPEditor::addDigit(const int& digit)
{
	if (number.size() == 1 && number[0] == '0' || number.size() == 2 && number[1] == '0')
	{
		number.pop_back();
	}
	number += Convertor::int_to_Char(digit);
	return number;
}

// добавить разделитель
std::string TPEditor::addSeparator()
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
std::string TPEditor::addZero()
{
	number += '0';
	return number;
}

// забой символа
std::string TPEditor::Bs()
{
	if (number.empty())
	{
		throw TException("Ошибка! Строка пуста...\n");
	}

	number.erase(number.size() - 1);
	return number;
}

// очистить
std::string TPEditor::clear()
{
	number.clear();
	return number;
}

// редактировать
std::string TPEditor::edit(const int& i)
{
	switch (i)
	{
	default:
		break;
	}

	return number;
}