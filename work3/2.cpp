/*
二、请补充完整程序，使程序的输出为：

The default constructor has been called: 1
The copy constructor has been called: 2
The copy constructor has been called: 3

#include <iostream>
using namespace std;

Foo method(Foo obj)
{
    return obj;
}

int main()
{
    Foo obj;
    method(obj);
}
*/

#include <iostream>


// 赛这里也可以，C#写习惯了还是塞在类里面好看一些
// static int count = 0;

class Foo{
private:
    // C++ 17的语法，其实可以写类外面的
    inline static int count_ = 0;
public:
    Foo() {
        count_++;
        std::cout << "The default constructor has been called: " << count_ << std::endl;
    }
    Foo(const Foo& other) {
        count_++;
        std::cout << "The copy constructor has been called: " << count_ << std::endl;
    }
};

Foo method(Foo obj)
{
    // 返回值调用复制构造函数
    // count_ = 3
    return obj;
}

void method2(Foo& obj)
{
}

int main()
{
    // 默认构建函数被调用  
    // count_ = 1
    Foo obj;

    // 传参时调用复制构造函数
    // count_ = 2
    method(obj);

    // 传引用时不调用复制构造函数
    // 棍母
    method2(obj);
}