#pragma once
#include "UComp.h"
#include "UException.h"

const double PI = 3.14159265358979323846;

// конструктор для строк
TComp::TComp(const std::string& str)
{
    // Удаляем все пробелы из строки для упрощения парсинга
    std::string s = str;
    s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());

    size_t plus_pos = s.find('+');
    size_t minus_pos = s.find('-', 1); // Ищем минус не в начале

    // Определяем позицию оператора между действительной и мнимой частями
    size_t op_pos = (plus_pos != std::string::npos) ? plus_pos : minus_pos;

    // Проверяем наличие 'i*' перед мнимой частью
    size_t imul_pos = s.find("i*");
    if (op_pos == std::string::npos || imul_pos == std::string::npos || imul_pos < op_pos) 
    {
        // Альтернативные форматы: "a", "i*b", "-i*b"
        if (s.find('i') != std::string::npos) 
        {
            // Обработка случаев вида "i*b" или "-i*b"
            if (s[0] == 'i' && s[1] == '*') 
            {
                re = 0;
                try 
                {
                    im = std::stod(s.substr(2));
                }
                catch (...) 
                {
                    throw TException("Ошибка! Неверный ввод...\n");
                }
            }
            else if (s.find("-i*") == 0) 
            {
                re = 0;
                try 
                {
                    im = -std::stod(s.substr(3));
                }
                catch (...) 
                {
                    throw TException("Ошибка! Неверный ввод...\n");
                }
            }
            else {
                throw TException("Ошибка! Некорректный формат комплексного числа");
            }
        }
        else 
        {
            // Только действительная часть
            try 
            {
                re = std::stod(s);
                im = 0;
            }
            catch (...) 
            {
                throw TException("Ошибка! Неверный ввод...\n");
            }
        }
    }
    else 
    {
        // Парсим действительную часть (до оператора)
        try 
        {
            re = std::stod(s.substr(0, op_pos));
        }
        catch (...) 
        {
            throw TException("Ошибка! Неверный ввод...\n");
        }

        // Парсим мнимую часть (после 'i*')
        try 
        {
            std::string im_part = s.substr(imul_pos + 2);
            im = std::stod(im_part);

            // Учитываем знак перед i*
            if (s[op_pos] == '-') 
            {
                im = -im;
            }
        }
        catch (...) 
        {
            throw TException("Ошибка! Неверный ввод...\n");
        }
    }
}

// оператор ==
bool TComp::operator==(const TANumber& other) const
{
	const TComp* otherPtr = dynamic_cast<const TComp*>(&other);

	if (!otherPtr) throw TException("Ошибка! Неверный тип...\n");

	return im == otherPtr->im && re == otherPtr->re;
}

// операция сложить
std::unique_ptr<TANumber> TComp::operator+(const TANumber& other) const
{
	const TComp* otherPtr = dynamic_cast<const TComp*>(&other);

	if (!otherPtr) throw TException("Ошибка! Неверный тип...\n");

	return std::make_unique<TComp>(re + otherPtr->re, im + otherPtr->im);
}

// операция умножить
std::unique_ptr<TANumber> TComp::operator*(const TANumber& other) const
{
	const TComp* otherPtr = dynamic_cast<const TComp*>(&other);

	if (!otherPtr) throw TException("Ошибка! Неверный тип...\n");

	return std::make_unique<TComp>(re * otherPtr->re - im * otherPtr->im, re * otherPtr->im + otherPtr->re * im);
}

// операция вычесть
std::unique_ptr<TANumber> TComp::operator-(const TANumber& other) const
{
	const TComp* otherPtr = dynamic_cast<const TComp*>(&other);

	if (!otherPtr) throw TException("Ошибка! Неверный тип...\n");

	return std::make_unique<TComp>(re - otherPtr->re, im - otherPtr->im);
}

// операция делить
std::unique_ptr<TANumber> TComp::operator/(const TANumber& other) const
{
	const TComp* otherPtr = dynamic_cast<const TComp*>(&other);

	if (!otherPtr) throw TException("Ошибка! Неверный тип...\n");

	double denominator = otherPtr->re * otherPtr->re + otherPtr->im * otherPtr->im;
	if (denominator == 0) 
	{
		throw TException("Ошибка! Деление на ноль");
	}

	double new_re = (re * otherPtr->re + im * otherPtr->im) / denominator;
	double new_im = (im * otherPtr->re - re * otherPtr->im) / denominator;

	return std::make_unique<TComp>(new_re, new_im);
}

// операция обратить
std::unique_ptr<TANumber> TComp::rev() const
{
	if (isZero()) 
	{
		throw TException("Ошибка! Деление на ноль");
	}
	double denominator = re * re + im * im;

	return std::make_unique<TComp>(re / denominator, -im / denominator);
}

// операция возвести в квадрат
std::unique_ptr<TANumber> TComp::sqr() const
{
	return std::make_unique<TComp>(re * re - im * im, 2 * re * im);
}

// число есть 0
bool TComp::isZero() const
{
	return re == 0 && im == 0;
}

// взять дробь строка
std::string TComp::getString() const
{
    std::string result;

    // Форматируем части числа
    std::string real_str = std::to_string(re);
    std::string imag_str = std::to_string(abs(im));

    // убираем незначащие нули
    int dot_pos = real_str.find('.');
    if (dot_pos != -1) 
    {
        int last_non_zero = real_str.find_last_not_of('0');
        if (last_non_zero != -1) 
        {
            if (last_non_zero == dot_pos) 
            {
                real_str.erase(dot_pos);
            }
            else 
            {
                real_str.erase(last_non_zero + 1);
            }
        }
    }

    // убираем незначащие нули
    dot_pos = imag_str.find('.');
    if (dot_pos != -1)
    {
        int last_non_zero = imag_str.find_last_not_of('0');
        if (last_non_zero != -1)
        {
            if (last_non_zero == dot_pos)
            {
                imag_str.erase(dot_pos);
            }
            else
            {
                imag_str.erase(last_non_zero + 1);
            }
        }
    }

    // Добавляем действительную часть
    if (re != 0) 
    {
        result += real_str;
    }

    // Добавляем мнимую часть
    if (im != 0) 
    {
        // Определяем знак
        std::string sign;
        if (im > 0)
        {
            sign = result.empty() ? "" : " + ";
        }
        else 
        {
            sign = result.empty() ? "-" : " - ";
        }

        // Формируем мнимую часть
        std::string imag_part;
        if (std::abs(im) == 1) 
        {
            imag_part = "i*1";
        }
        else 
        {
            imag_part = "i*" + imag_str;
        }

        result += sign + imag_part;
        result.insert(0, "(");
        result += ")";
    }

    // Если обе части нулевые
    if (result.empty()) 
    {
        result = "0";
    }

    return result;
}

// модуль
double TComp::abs_() const
{
	return sqrt(re * re + im * im);
}

// угол в радианах
double TComp::angleRad() const
{
	return atan2(im, re);
}

// степень
TComp TComp::degree(const int& n) const
{
	double mod = pow(abs_(), n);
	double angle = angleRad() * n;
	return TComp(mod * cos(angle), mod * sin(angle));
}

// корень
TComp TComp::sqrt_(const int& n, const int& i) const
{
    if (n <= 0) 
    {
        throw TException("Ошибка! Степень корня должна быть положительной");
    }

    if (i < 0 || i >= n) 
    {
        throw TException("Ошибка! Индекс корня должен быть в диапазоне 0..n-1");
    }

    if (isZero()) 
    {
        return TComp(0, 0);
    }

    double mod = pow(abs_(), 1.0 / n);
    double angle = (angleRad() + 2 * PI * i) / n;
    return TComp(mod * cos(angle), mod * sin(angle));
}

// получить копию
std::unique_ptr<TANumber> TComp::clone() const
{
    return std::make_unique<TComp>(*this);
}

// оператор =
TANumber& TComp::operator=(const TANumber& other)
{
    const TComp* otherPtr = dynamic_cast<const TComp*>(&other);
    if (!otherPtr) throw TException("Invalid type");

    this->re = otherPtr->re;
    this->im = otherPtr->im;
    return *this;
}