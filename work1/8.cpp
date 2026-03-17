#include <iostream>

using uint64 = unsigned long long;

const int RED_COUNT = 6;
const int BLUE_COUNT = 1;
const int RED_MAX = 33;
const int BLUE_MAX = 16;

uint64 combination(uint64 n, uint64 k)
{
    // 处理棍母，其实无所谓，反正这里用的数都是合法的
    if (k > n)
    {
        return 0;
    }
    if (k == 0 || k == n)
    {
        return 1;
    }

    // C(n, k) = C(n, n-k) 减少循环次数
    if (k > n / 2)
    {
        k = n - k;
    }

    uint64 res = 1;
    for (uint64 i = 1; i <= k; ++i)
    {
        res *= (n - i + 1);
        
        // 变乘边除，防止溢出
        res /= i;
    }
    return res;
}

int main()
{
    uint64 prize = 0;

    std::cin >> prize;

    uint64 total = combination(RED_MAX, RED_COUNT) * combination(BLUE_MAX, BLUE_COUNT);
    switch (prize)
    {
    case 1:
    {
        uint64 first_prize = 1;
        std::cout << "一等奖: " << first_prize << "/" << total << std::endl;
        break;
    }

    case 2:
    {
        uint64 second_prize = combination(RED_COUNT, RED_COUNT) * combination(BLUE_MAX - 1, 1);
        std::cout << "二等奖: " << second_prize << "/" << total << std::endl;
        break;
    }

    case 3:
    {
        uint64 third_prize = combination(RED_COUNT, RED_COUNT - 1) * combination(BLUE_MAX - 1, 1);
        std::cout << "三等奖: " << third_prize << "/" << total << std::endl;
        break;
    }
    case 4:
    {
        uint64 fourth_prize = combination(RED_COUNT, RED_COUNT - 1) * combination(BLUE_COUNT, BLUE_COUNT) +
                              combination(RED_COUNT, RED_COUNT - 2) * combination(BLUE_MAX - 1, 1);
        std::cout << "四等奖: " << fourth_prize << "/" << total << std::endl;
        break;
    }

    case 5:
    {
        uint64 fifth_prize = combination(RED_COUNT, RED_COUNT - 2) * combination(BLUE_COUNT, BLUE_COUNT) +
                             combination(RED_COUNT, RED_COUNT - 3) * combination(BLUE_MAX - 1, 1);
        std::cout << "五等奖: " << fifth_prize << "/" << total << std::endl;
        break;
    }

    case 6:
    {
        uint64 sixth_prize = combination(RED_COUNT, RED_COUNT - 3) * combination(BLUE_MAX - 1, 1) +
                             combination(RED_COUNT, RED_COUNT - 4) * combination(BLUE_MAX - 1, 1) +
                             combination(RED_COUNT, RED_COUNT - 5) * combination(BLUE_MAX - 1, 1);
        std::cout << "六等奖: " << sixth_prize << "/" << total << std::endl;
        break;
    }

    default:
        std::cout << "无效的奖项编号" << std::endl;
        break;
    }

    return 0;
}