#pragma once
#include <string>
#include "UException.h"

class TPNumber
{
	double n;	// само число
	int cc;		// система счисления
	int acc;	// точность представления числа

public:
	// конструктор по умолчанию
	TPNumber() : n(0), cc(10), acc(0) {}

	// конструктор для вещественного числа
	TPNumber(const double&, const int& cc_, const int& acc_);

	// конструктор для строкового числа
	TPNumber(const std::string& a, const std::string& cc_, const std::string& acc_);

	// конструктор копирования
	TPNumber(const TPNumber& other) : n(round(other.n * pow(10, 10)) / pow(10, 10)), cc(other.cc), acc(other.acc) {}

	// операция сложить
	TPNumber operator+(const TPNumber& other) const;

	// операция умножить
	TPNumber operator*(const TPNumber& other) const;

	// операция вычесть
	TPNumber operator-(const TPNumber& other) const;

	// операция делить
	TPNumber operator/(const TPNumber& other) const;

	// операция обратить
	TPNumber rev() const { return n != 0 ? TPNumber(1 / n, cc, acc) : throw TException("Ошибка! Деление на ноль...\n"); }

	// операция возвести в квадрат
	TPNumber sqr() const { return TPNumber(n * n, cc, acc); }

	// взять число
	double getN() const { return n; }

	// взять число в виде строки
	std::string getStringN() const;

	// взять основание сс
	int getCC() const { return cc; }

	// взять основание сс в виде строки
	std::string getStrCC() const { return std::to_string(cc); }

	// взять точность представления
	int getACC() const { return acc; }

	// взять точность представления как строку
	std::string getStrACC() const { return std::to_string(acc); }

	// установить основание
	void setCC(const int& cc_) { cc = cc_; }

	// установить основание (строка)
	void setCC(const std::string& cc_) { cc = stoi(cc_); }

	// установить точность
	void setACC(const int& acc_) { acc = acc_; }
	
	// установить точность (строка)
	void setACC(const std::string& acc_) { acc = stoi(acc_); }
};