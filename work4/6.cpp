/*
六、在上题的基础上，重新设计Foo类，使得该类的对象最多不能超过3个。
提示：在主函数中，不能通过构造函数来创建对象，要禁止以下的代码编译通过：

Foo obj;
如果允许这样的代码，则无法控制生成的对象个数（因为以上的代码重复写N行，就能创建N个Foo对象）。
*/

#include <iostream>

class Foo
{
private:
    inline static int object_count_ = 0;
    Foo()
    {
        object_count_++;
        std::cout << "创建第" << object_count_ << "个对象" << std::endl;
    }
public:
    // 禁止赋值和拷贝
    Foo(const Foo &) = delete;
    Foo &operator=(const Foo &) = delete;

    // 使用工厂函数
    static Foo* GetInstance()
    {
        if (object_count_ >= 3)
        {
            std::cout << "对象数量已达上限，无法创建新对象" << std::endl;
            return nullptr;
        }
        return new Foo();
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

void func(Foo* obj)
{
}

int main()
{
    auto obj1 = Foo::GetInstance();
    auto obj2 = Foo::GetInstance();
    auto obj3 = Foo::GetInstance();

    // 应该是棍母空指针
    auto obj4 = Foo::GetInstance();

    if (obj4 == nullptr) {
        std::cout << "空指针" << std::endl;
    }

    std::cout << "当前对象数：" << Foo::getNum() << std::endl;
    func(obj1);
    std::cout << "当前对象数：" << Foo::getNum() << std::endl;

    // 释放对象，防止内存泄漏
    delete obj1;
    delete obj2;
    delete obj3;
    
    return 0;
}