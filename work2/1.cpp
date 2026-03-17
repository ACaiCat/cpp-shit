/*
一、根据以下的主函数，写出相关的类。
主函数如下：
int main()
{
    clock clo1;
    cout<<"CLOCK A:"<<endl;
    clo1.set(2,30,0); //设置时钟的当前时间
    for (int i=0;i<10;i++)
    {
        clo1.tick(); //时钟增加1秒
        clo1.show(); //第一次循环打印输出：2:30:1
    }
}
*/

#include <iostream>

class Clock
{
private:
    int hour;
    int minute;
    int second;
public:
    void set(int h, int m, int s)
    {
        this->hour = h;
        this->minute = m;
        this->second = s;
    }
    void tick()
    {
        this->second++;
        if (this->second == 60)
        {
            this->second = 0;
            this->minute++;
            if (this->minute == 60)
            {
                this->minute = 0;
                this->hour++;
                if (this->hour == 24)
                {
                    this->hour = 0;
                }
            }
        }
    }
    void show()
    {
        std::cout << this->hour << ":" << this->minute << ":" << this->second << std::endl;
    }
};


int main()
{
    Clock clockA;
    std::cout << "CLOCK A:" << std::endl;
    clockA.set(2, 29, 58); // 设置时钟的当前时间
    for (int i = 0; i < 10; i++)
    {
        clockA.tick(); // 时钟增加1秒
        clockA.show(); // 第一次循环打印输出：2:30:1
    }
}