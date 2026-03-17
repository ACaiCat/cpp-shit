/*
六、设计一个函数，实现指数运算。如输入 2和3，则该函数输出8。要求：输入参数均为整数。
*/

#include <iostream>
#include <cmath>

using int64 = long long;

int64 power(int64 a, int64 b)
{
    int64 result = a;
    for (int64 i = 1; i < b; ++i)
    {
        result *= a;
    }
    return result;
}

int main()
{
    int a, b;
    std::cin >> a >> b;

    std::cout << power(a, b) << std::endl;

    return 0;
}