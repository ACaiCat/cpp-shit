/*
五、定义一个字符串类MyString，实现求字符串长度、取子串、查找子串、串接、打印字符串等操作，并支持以下程序的运行。
主函数如下：
int main()
{
    MyString str;                                   // 初始化为空字符串
    MyString str2("abc");                           // 初始化为字符串“abc”
    std::cout << str2.length() << std::endl;        // 打印输出：3
    std::cout << str2.subString(1, 2) << std::endl; // 从位置1开始，连续取2个字符，打印输出：bc
    std::cout << str2.indexOf("bc") << std::endl;   // 找到待查找子串”bc”在原字符串中第一次出现的位置，打印输出：1
    std::cout << str2.indexOf("bcd") << std::endl;  // 查找不到子串，打印输出：-1
    str.concatenate(str2);                          // 将str2串接到str中
    str.print();                                    // 打印输出:abc
    MyString str3(str);
    str3.print(); // 打印输出:abc
}
*/

#include <iostream>

class MyString
{
private:
    std::string str_;

public:
    MyString() : str_("") {}
    MyString(const std::string &s) : str_(s) {}

    size_t length() const
    {
        return str_.length();
    }

    std::string subString(size_t pos, size_t len) const
    {
        if (pos < str_.length())
        {
            return str_.substr(pos, len);
        }
        return "";
    }

    int indexOf(const std::string &substr) const
    {
        size_t pos = str_.find(substr);
        return (pos != std::string::npos) ? pos : -1;
    }

    void concatenate(const MyString &other)
    {
        str_ += other.str_;
    }

    void print() const
    {
        std::cout << str_ << std::endl;
    }
};

int main()
{
    MyString str;                                   // 初始化为空字符串
    MyString str2("abc");                           // 初始化为字符串“abc”
    std::cout << str2.length() << std::endl;        // 打印输出：3
    std::cout << str2.subString(1, 2) << std::endl; // 从位置1开始，连续取2个字符，打印输出：bc
    std::cout << str2.indexOf("bc") << std::endl;   // 找到待查找子串”bc”在原字符串中第一次出现的位置，打印输出：1
    std::cout << str2.indexOf("bcd") << std::endl;  // 查找不到子串，打印输出：-1
    str.concatenate(str2);                          // 将str2串接到str中
    str.print();                                    // 打印输出:abc
    MyString str3(str);
    str3.print(); // 打印输出:abc
}
