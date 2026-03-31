/*
二、某杯子可以装水，初始时杯中存有一些水，且杯子有最大容量（单位：升）限制。

请编写一个杯子类，并编写一个主函数，演示以下功能：
往杯子中加水，每次随机添加一定体积的水，当水杯满时，则结束加水，否则可以继续加水。
程序要输出一共加了几次水、每次加了多少升水。

输入：初始存水量、最大容量
输出：每次加了多少水、一共加了几次水

输入样例1：
1  10

输出样例1：
第1次加水：1升
第2次加水：3升
第3次加水：2升
第4次加水：3升
总共加水次数：4次

输入样例2：
10  10

输出样例2：
总共加水次数：0次

输入样例3：
-2  10

输出样例3：
第1次加水：7升
第2次加水：3升
总共加水次数：2次
*/
#include <iostream>
#include <vector>

class Cup
{
private:
    int cap_;
    int volume_;

public:
    Cup(int initial_volume, int capacity) : cap_(capacity), volume_(initial_volume) {}

    int AddWater(int amount)
    {
        if (volume_ + amount > cap_)
        {
            amount = cap_ - volume_;
        }
        volume_ += amount;
        return amount;
    }

    bool IsFull() const
    {
        return volume_ >= cap_;
    }
};

int main()
{
    int initial_volume, capacity;
    std::cin >> initial_volume >> capacity;

    Cup cup(initial_volume, capacity);
    int add_count = 0;

    while (!cup.IsFull())
    {
        int amount = rand() % capacity + 1;
        int actural_added = cup.AddWater(amount);

        std::cout << "第" << add_count + 1 << "次加水：" << actural_added << "升" 
        << std::endl;

        add_count++;
    }

    std::cout << "总共加水次数：" << add_count << "次" << std::endl;

    return 0;
}