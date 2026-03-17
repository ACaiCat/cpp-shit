/*
四、某多项式的形式为 ax^m+bx^n+c，请编写程序求多项式的值。
输入：x, a, b, c,m,n的值
输出：多项式的值
如：
输入：x=1, a=2, b=1, c=0,m=0,n=0
输出：3
*/

#include <iostream>
#include <cmath>

int caculate(int x, int a, int b, int c, int m, int n)
{
    return a * std::pow(x, m) + b * std::pow(x, n) + c;
}

int main()
{
    int x, a, b, c, m, n;
    std::cin >> x >> a >> b >> c >> m >> n;

    int result = caculate(x, a, b, c, m, n);
    std::cout << result << std::endl;

    return 0;
}