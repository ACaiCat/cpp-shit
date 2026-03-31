/*
一、某多项式是由多个简单项构成的，可能的形式为 axm+bxn+c或ax或bxm或c等，请编写程序求多项式的值。
输入：x的值以及多项式表达式（如2x^2-6x^3）；
输出：多项式的值
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

class Term
{
private:
    double coefficient_;
    int exponent_;
    int constant_;

public:

    /*
    1141
    x
    114x
    114x^514
    */
    Term(const std::string &term)
    {

        coefficient_ = 0;
        exponent_ = 0;
        constant_ = 0;

        auto is_number = std::all_of(term.begin(), term.end(), ::isdigit);

        if (is_number)
        {
            constant_ = std::stod(term);
            return;
        }

        coefficient_ = 1;
        exponent_ = 1;

        auto x_pos = term.find('x');
        auto caret_pos = term.find('^');

        auto coefficient_str = term.substr(0, x_pos);

        if (!coefficient_str.empty())
        {
            coefficient_ = std::stod(coefficient_str);
        }

        if (caret_pos != std::string::npos)
        {
            auto exponent_str = term.substr(caret_pos + 1);
            exponent_ = std::stoi(exponent_str);
        }
    }

    double Calculate(double x) const
    {
        return coefficient_ * std::pow(x, exponent_) + constant_;
    }
};

int main()
{
    double x;
    std::string polynomial;

    std::cin >> x;
    std::cin >> polynomial;

    auto value = 0.0;
    while (!polynomial.empty())
    {
        auto is_minus = polynomial[0] == '-';
        if (is_minus)
        {
            polynomial = polynomial.substr(1);
        }

        auto plus_pos = polynomial.find('+');
        auto minus_pos = polynomial.find('-');

        auto term_end_pos = std::min(plus_pos, minus_pos);

        std::string term_str = polynomial.substr(0, term_end_pos);
        Term term(term_str);

        if (is_minus)
        {
            value -= term.Calculate(x);
        }
        else
        {
            value += term.Calculate(x);
        }

        if (term_end_pos == std::string::npos)
        {
            break;
        }

        polynomial = polynomial.substr(term_end_pos + 1);
    }

    std::cout << "多项式的值: " << value << std::endl;

    return 0;
}