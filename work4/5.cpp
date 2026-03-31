/*
五、请设计一个类Foo，可以统计当前已生成且处于活动状态的对象个数：
 以下为程序输出:
创建第1个对象
创建第2个对象
当前对象数：2
创建第3个对象
当前对象数：2

#include <iostream>
using namespace std;

请在此处补充代码；

void func(Foo obj)
{
}

int main()
{
    Foo obj1;
    Foo obj2;
    cout << "当前对象数：" << Foo::getNum() << endl;
    func(obj1);
    cout << "当前对象数：" << Foo::getNum() << endl;
    return 0;
}
*/

#include <iostream>

class Foo
{
private:
    inline static int object_count_ = 0;
public:
    Foo()
    {
        object_count_++;
        std::cout << "创建第" << object_count_ << "个对象" << std::endl;
    }

    ~Foo()
    {
        object_count_--;
    }

    static int getNum()
    {
        return object_count_;
    }
};

void func(Foo obj)
{
}

int main()
{
    Foo obj1;
    Foo obj2;
    std::cout << "当前对象数：" << Foo::getNum() << std::endl;
    func(obj1);
    std::cout << "当前对象数：" << Foo::getNum() << std::endl;
    return 0;
}