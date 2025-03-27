#include "UPNumber.h"
#include <stdexcept>
#include "Convertor.h"

// конструктор для вещественного числа
TPNumber::TPNumber(const double& a, const int& cc_, const int& acc_) :
	cc(cc_ < 2 || cc_ > 16 ? throw TException("Ошибка! Неверное основание системы счисления...\n") : cc_),
	acc(acc_ < 0 ? throw TException("Ошибка! Точность не может быть отрицательной...\n") : acc_)
{
	std::string number = Convertor::dbl_to_str(a, cc, acc);

	// проверка что число существует в заданной системе счисления
	for (int i = 0; i < number.size(); i++)
	{
		if (number[i] != '-' && number[i] != '.' && Convertor::char_To_num(number[i]) >= cc)
		{
			throw TException("Ошибка! Число не существует в заданной системе счисления...\n");
		}
	}

	n = a;
}

// конструктор для строкового числа
TPNumber::TPNumber(const std::string& a, const std::string& cc_, const std::string& acc_) :
	cc(stoi(cc_) < 2 || stoi(cc_) > 16 ? throw TException("Ошибка! Неверное основание системы счисления...\n") : stoi(cc_)),
	acc(stoi(acc_) < 0 ? throw TException("Ошибка! Точность не может быть отрицательной...\n") : stoi(acc_))
{

	// проверка что число существует в заданной системе счисления
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != '-' && a[i] != '.' && Convertor::char_To_num(a[i]) >= cc)
		{
			throw TException("Ошибка! Число не существует в заданной системе счисления...\n");
		}
	}

	n = std::stod(a);		// получение числа
}

// операция сложить
TPNumber TPNumber::operator+(const TPNumber& other) const
{
	if (cc != other.cc || acc != other.acc)
	{
		throw TException("Ошибка! Неверный операнд...\n");
	}

	return TPNumber(n + other.n, cc, acc);
}

// операция умножить
TPNumber TPNumber::operator*(const TPNumber& other) const
{
	if (cc != other.cc || acc != other.acc)
	{
		throw TException("Ошибка! Неверный операнд...\n");
	}

	return TPNumber(n * other.n, cc, acc);
}

// операция вычесть
TPNumber TPNumber::operator-(const TPNumber& other) const
{
	if (cc != other.cc || acc != other.acc)
	{
		throw TException("Ошибка! Неверный операнд...\n");
	}

	auto g = n - other.n;
	return TPNumber(n - other.n, cc, acc);
}

// операция делить
TPNumber TPNumber::operator/(const TPNumber& other) const
{
	if (cc != other.cc || acc != other.acc)
	{
		throw TException("Ошибка! Неверный операнд...\n");
	}

	if (other.n == 0)
	{
		throw TException("Ошибка! Деление на ноль...\n");
	}

	return TPNumber(n / other.n, cc, acc);
}

// взять число в виде строки
std::string TPNumber::getStringN() const
{
	return Convertor::dbl_to_str(n, cc, acc);
}