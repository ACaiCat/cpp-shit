#include <iostream>

int main()
{
    int highPressure, lowPressure;

    std::cin >> highPressure >> lowPressure;

    if (highPressure >= 160 || lowPressure >= 100)
    {
        std::cout << "1期高血压" << std::endl;
    }
    else if (highPressure >= 140 || lowPressure >= 90)
    {
        std::cout << "2期高血压" << std::endl;
    }
    else if (highPressure >= 120 || lowPressure >= 80)
    {
        std::cout << "高血压前期" << std::endl;
    }
    else
    {
        std::cout << "正常血压" << std::endl;
    }

    return 0;
}