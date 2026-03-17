/*
五、输入一个整数，将各位数字反转后输出。例如，输入123，则程序输出321。
*/

#include <iostream>
#include <string>

int main()
{
    std::string num;

    std::cin >> num;

    for (auto i = num.end() - 1; i >= num.begin(); --i)
    {
        std::cout << *i;
    }

    return 0;
}