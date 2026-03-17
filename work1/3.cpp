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