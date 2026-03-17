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