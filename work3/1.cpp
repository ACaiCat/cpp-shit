/*
一、请写一个程序举例说明为什么应将数据成员的访问限定符设置为private。在源代码中用注释说明理由。
*/

#include <iostream>
#include <chrono>

using time_point = std::chrono::time_point<std::chrono::system_clock>;
using duration = std::chrono::duration<double>;

class Timer
{
private:
    time_point start_time_ = std::chrono::system_clock::now(); // 避免外部修改导致计时器状态异常
    time_point end_time_ = std::chrono::system_clock::now();   // 同上
    bool is_running_ = false;                                  // 同上
public:
    Timer() = default;

    void Start()
    {
        if (is_running_)
        {
            throw std::logic_error("计时器正在运行!");
        }
        is_running_ = true;
        start_time_ = std::chrono::system_clock::now();
    }

    void Stop()
    {
        if (!is_running_)
        {
            throw std::logic_error("计时器未运行!");
        }
        is_running_ = false;
        end_time_ = std::chrono::system_clock::now();
    }

    duration GetElapsedTime()
    {
        auto elapsed = end_time_ - start_time_;
        return elapsed;
    }
};

int main()
{
    /*
    私有成员体现类的封装性，外部代码只能通过公共成员与计时器交互
    这里外部使用者使用计时器只需要关注计时器暴露的方法，而不需要关注计时器内部的状态
    私有成员可以保护计时器内部状态，防止被外部代码修改，导致计时器行为异常
    C++不能反射强健私有成员，没意思
    */

    Timer timer;
    timer.Start();
    // 这里volatile禁止编译器优化，不然开编译优化可能会被编译成棍母
    for (volatile int i = 0; i < 1000000000; ++i)
    {
        // 棍母，懒得写了，反正有时间
    };
    timer.Stop();

    auto elapsed_time = timer.GetElapsedTime();
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_time).count();

    std::cout << "持续时间: " << milliseconds << "毫秒" << std::endl;
    return 0;
}