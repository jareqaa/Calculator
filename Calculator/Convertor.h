#pragma once
#include <string>

class Convertor
{
public:
    // подсчет точек в строке
    static int dotCounter(const std::string& str);

    //Преобразовать целое в символ
    static char int_to_Char(const int& n);

    //Преобразовать десятичное целое в с.сч. с основанием р
    static std::string int_to_P(long long int n, const int& p);

    //Преобразовать десятичную дробь в с.сч. с основанием р
    static std::string dbl_to_P(double n, const int& p, const int& c);

    //Преобразовать десятичное действительное число в с.сч. с осн. р
    static std::string dbl_to_str(const double& n, const int& p, const int& c);

    //Преобразовать цифру в число
    static int char_To_num(const char& ch);

    //Преобразовать строку в число
    static double convert(const std::string& p_num, const int& p, const double& weight);

    //Преобразовать из с.сч. с основанием р в с.сч. с основанием 10
    static double dval(std::string p_num, const int& p);
};