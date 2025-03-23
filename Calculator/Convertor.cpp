#include "Convertor.h"
#include "UException.h"

// реверс строки
void reverse_str(std::string& str)
{
	int n = str.size();
	for (int i = 0; i < n / 2; i++)
	{
		std::swap(str[i], str[n - 1 - i]);
	}
}

// подсчет точек в строке
int Convertor::dotCounter(const std::string& str)
{
	int count = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '.')
			count++;
	}
	return count;
}

//Преобразовать десятичное целое в с.сч. с основанием р
std::string Convertor::int_to_P(long long int n, const int& p)
{
	if (p < 2 || p > 16)
		throw TException("Ошибка! Неверное основание системы счисления...\n");

	if (n == 0)
		return "0";

	std::string result = "";
	while (n != 0)
	{
		int tmp = n % p;
		n /= p;
		result += int_to_Char(tmp);
	}
	reverse_str(result);
	return result;
}

//Преобразовать десятичную дробь в с.сч. с основанием р
std::string Convertor::dbl_to_P(double n, const int& p, const int& c)
{
	if (p < 2 || p > 16)
		throw TException("Ошибка! Неверное основание системы счисления...\n");

	if (c < 0)
		throw TException("Ошибка! Точность не может быть отрицательной...\n");

	if (n >= 1)
		throw TException("Ошибка! Неверное входное число...\n");

	std::string result = "";
	for (int i = 0; i < c; i++)
	{
		n *= p;
		int digit = static_cast<int>(n);
		result += int_to_Char(digit);
		n -= digit;
	}
	return result;
}

//Преобразовать десятичное действительное число в с.сч. с осн. р
std::string Convertor::dbl_to_str(const double& n, const int& p, const int& c)
{
	if (p < 2 || p > 16)
		throw TException("Ошибка! Неверное основание системы счисления...\n");

	if (c < 0)
		throw TException("Ошибка! Точность не может быть отрицательной...\n");

	char sign = '\0';
	if (n < 0)
		sign = '-';

	std::string intResult = int_to_P(static_cast<long long int>(abs(n)), p);
	std::string dblResult = c == 0 ? "" : "." + dbl_to_P(abs(n - static_cast<int>(n)), p, c);

	for (int i = dblResult.size() - 1; i >= 0; i--)
	{
		if (dblResult[i] == '0' || dblResult[i] == '.')
			dblResult.erase(i);
		else
			break;
	}

	return sign == '\0' ? intResult + dblResult : sign + intResult + dblResult;
}

//Преобразовать цифру в число
int Convertor::char_To_num(const char& ch)
{
	if (ch <= '9' && ch >= '0')
		return static_cast<int>(ch - 48);
	else if (ch >= 'A' && ch <= 'F')
		return static_cast<int>(ch - 55);
	else
		throw TException("Ошибка! Неверное значение...\n");
}

//Преобразовать целое в символ
char Convertor::int_to_Char(const int& n)
{
	if (n >= 0 && n <= 9)
		return static_cast<char>('0' + n);
	else if (n >= 10 && n < 16)
		return static_cast<char>('A' + n - 10);
	else
		throw TException("Ошибка! Неверное значение...\n");
}

//Преобразовать строку в число
double Convertor::convert(const std::string& p_num, const int& p, const double& weight)
{
	if (p < 2 || p > 16)
		throw TException("Ошибка! Неверное основание системы счисления...\n");

	int integer_digits_number = weight == -1 ? p_num.size() : weight;

	long long int intValue = 0;
	double dblValue = 0.;

	for (int i = 0; i < integer_digits_number; i++)
	{
		int dig = char_To_num(p_num[i]);
		if (dig >= p)
			throw TException("Ошибка! Неверная цифра...\n");
		intValue += dig * pow(p, integer_digits_number - 1 - i);
	}

	for (int i = integer_digits_number; i < p_num.size(); i++)
	{
		int dig = char_To_num(p_num[i]);
		if (dig >= p)
			throw TException("Ошибка! Неверная цифра...\n");
		dblValue += dig * pow(p, -(i - integer_digits_number + 1));
	}

	return static_cast<double>(intValue) + dblValue;
}

//Преобразовать из с.сч. с основанием р в с.сч. с основанием 10
double Convertor::dval(std::string p_num, const int& p)
{
	if (p < 2 || p > 16)
		throw TException("Ошибка! Неверное основание системы счисления...\n");

	if (dotCounter(p_num) > 1)
		throw TException("Ошибка! Неверный ввод...\n");

	if (p_num[0] == '.')
		throw TException("Ошибка! Неверный ввод...\n");

	char sign = '\0';
	if (p_num[0] == '-')
		sign = '-';

	if (p_num[0] == '-')
		p_num.erase(0, 1);

	int dotPosition = p_num.find('.');
	if (dotPosition == -1)
		return sign == '-' ? 0 - convert(p_num, p, -1) : convert(p_num, p, -1);
	else
	{
		p_num.erase(dotPosition, 1);
		return sign == '-' ? 0 - convert(p_num, p, dotPosition) : convert(p_num, p, dotPosition);
	}
}