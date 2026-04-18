/*
三、设计一个时间类，可以表示含小时、分、秒的时间，如“20:50:12”。
在此基础上，再设计一个日期类，可表示含年、月、日及小时、分、秒的时间，如“2020-01-20 20:50:12”。
在主函数中创建这两个类的实例，并打印输出时间。
*/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class Time
{
private:
    int seconds_;
    int minutes_;
    int hours_;

public:
    Time(int hours, int minutes, int seconds) : seconds_(seconds), minutes_(minutes), hours_(hours) {}

    std::string toTimeString()
    {
        std::ostringstream oss;

        oss << std::setfill('0');
        oss << std::setw(2) << hours_ << ":";
        oss << std::setw(2) << minutes_ << ":";
        oss << std::setw(2) << seconds_;

        return oss.str();
    }
};

class DateTime : public Time
{
private:
    int years_;
    int mounths_;
    int days_;

public:
    DateTime(int years, int mounths, int days, int hours, int minutes, int seconds)
        : years_(years), mounths_(mounths), days_(days), Time(hours, minutes, seconds) {}

    std::string toDateTimeString()
    {
        std::ostringstream oss;

        oss << std::setfill('0');
        oss << std::setw(4) << years_ << "-";
        oss << std::setw(2) << mounths_ << "-";
        oss << std::setw(2) << days_ << " ";

        oss << toTimeString();

        return oss.str();
    }
};

int main()
{
    auto datetime = DateTime(2026, 4, 18, 18, 42, 15);
    std::cout << datetime.toDateTimeString();
}