#include <iostream>
#include <cmath>

int main()
{
    int x, result = 0;

    std::cin >> x;

    int pos = 0;
    while (x > 0)
    {
        if (x % 2 == 1)
        {
            result += std::pow(2, pos);
        }

        x /= 10;
        ++pos;
    }

    std::cout << result << std::endl;

    return 0;
}