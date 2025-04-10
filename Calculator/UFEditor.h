#pragma once
#include "UPEditor.h"
#include "Convertor.h"
#include "UException.h"

class TFEditor : public TPEditor
{
	// добавить разделитель
	std::string addSeparator()
	{
		if (Convertor::dotCounter(number) == 0)
		{
			number = number.empty() ? "0." : number + '/';
			return number;
		}
		else
		{
			throw TException("Ошибка! Неверный ввод...\n");
		}
	}
};