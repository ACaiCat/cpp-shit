/*
三、从键盘输入一个整数，在屏幕打印输出该整数的所有因子。
*/

#include <iostream>

int main()
{
    int x;

    std::cin >> x;

    for (auto i = 1; i <= x; ++i)
    {
        if (x % i == 0)
        {
            std::cout << i << " ";
        }
    }

    return 0;
}