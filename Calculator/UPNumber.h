#pragma once
#include "UANumber.h"

class TPNumber : public TANumber
{
	double n;	// само число
	int cc;		// система счисления
	int acc;	// точность представления числа

public:
	// конструктор по умолчанию
	TPNumber() : n(0), cc(10), acc(0) { number = getString(); }

	// конструктор для вещественного числа
	TPNumber(const double&, const int& cc_, const int& acc_);

	// конструктор для строкового числа
	TPNumber(const std::string& a, const std::string& cc_, const std::string& acc_);

	// конструктор копирования
	TPNumber(const TPNumber& other) : n(other.n), cc(other.cc), acc(other.acc) { number = getString(); }

	// оператор ==
	bool operator==(const TANumber& other) const override;

	// операция сложить
	std::unique_ptr<TANumber> operator+(const TANumber& other) const override;

	// операция умножить
	std::unique_ptr<TANumber> operator*(const TANumber& other) const override;

	// операция вычесть
	std::unique_ptr<TANumber> operator-(const TANumber& other) const override;

	// операция делить
	std::unique_ptr<TANumber> operator/(const TANumber& other) const override;

	// операция обратить
	std::unique_ptr<TANumber> rev() const override;

	// операция возвести в квадрат
	std::unique_ptr<TANumber> sqr() const override;

	// число есть 0
	bool isZero() const override;

	// взять число
	double getN() const { return n; }

	// взять число в виде строки
	std::string getString() const;

	// взять число в виде строки
	std::string getStringN() const { return number; }

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