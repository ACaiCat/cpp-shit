/*
四、定义一个时钟类Clock，用于表示由小时、分、秒组成的时间，并支持以下程序的运行。
主函数如下：
int main()
{
    Clock c(10, 12, 24);     // 初始化为10点12分24秒
    c.tick();                // 秒针走一秒
    c.print("hh点mm分ss秒");  // 打印输出：10点12分25秒
    c.print("hh-mm-ss");     // 打印输出：10-12-25
    c.print("hh:mm:ss");     // 打印输出：10:12:25
    c.print("hh:mm");        // 打印输出：10:12
    c.print("mm:ss");        // 打印输出：12:25
}
*/
#include <iostream>
#include <string>

class Clock
{
private:
    int hour;
    int minute;
    int second;

public:
    Clock(int h, int m, int s)
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
    void print(std::string format)
    {
        std::string output = format;
        size_t pos;

        while ((pos = output.find("hh")) != std::string::npos)
        {
            output.replace(pos, 2, std::to_string(hour));
        }

        while ((pos = output.find("mm")) != std::string::npos)
        {
            output.replace(pos, 2, std::to_string(minute));
        }

        while ((pos = output.find("ss")) != std::string::npos)
        {
            output.replace(pos, 2, std::to_string(second));
        }

        std::cout << output << std::endl;
    }
};

int main()
{
    Clock c(10, 12, 24);     // 初始化为10点12分24秒
    c.tick();                // 秒针走一秒
    c.print("hh点mm分ss秒"); // 打印输出：10点12分25秒
    c.print("hh-mm-ss");     // 打印输出：10-12-25
    c.print("hh:mm:ss");     // 打印输出：10:12:25
    c.print("hh:mm");        // 打印输出：10:12
    c.print("mm:ss");        // 打印输出：12:25
}