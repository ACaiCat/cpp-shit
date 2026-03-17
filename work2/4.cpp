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