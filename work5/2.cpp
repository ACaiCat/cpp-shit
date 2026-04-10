/*
二、设计动态数组类IntArray，可以模拟整型数组的行为，并实现按下标访问、重置数组大小等功能。
所设计的类应支持深拷贝及以下主函数的运行。

主函数如下：

int main()
{
    IntArray arr;      // 建立存储空间为0的数组对象
    arr[1] = 10;       // 对下标1位置的数组元素进行赋值操作；程序应提示越界访问
    arr.resize(10);    // 把存储空间增大为10，即可以存10个整型数值；注：存储空间的大小可增大，也可缩小
    IntArray arr2(20); // 建立存储空间为20的数组对象
    for (int i = 0; i < arr2.size(); i++)
        arr2[i] = i;
    arr = arr2;                          // 把arr2对象的内容复制给arr对象
    for (int i = 0; i < arr.size(); i++) // 打印输出arr里的数据，即0,1,2,3…19
        cout << arr[i] << ",";

    return 0;
}
*/

#include <iostream>
#include <stdexcept>

class IntArray
{
private:
    // 存储数组元素的指针
    int *data_;
    int size_;

public:
    IntArray() : data_(nullptr), size_(0) {}
    IntArray(int size) : data_(new int[size]), size_(size) {}
    IntArray(const IntArray &other) : data_(new int[other.size_]), size_(other.size_)
    {
        for (auto i = 0; i < size_; ++i)
        {
            data_[i] = other.data_[i];
        }
    }

    // 析构时释放data_指向的内存空间
    ~IntArray()
    {
        delete[] data_;
    }

    // 这里需要重写赋值运算符深拷贝，不然默认浅拷贝，析构时双重释放直接爆
    IntArray &operator=(const IntArray &other)
    {
        if (this != &other)
        {
            delete[] data_;
            size_ = other.size_;
            data_ = new int[size_];
            for (int i = 0; i < size_; ++i)
                data_[i] = other.data_[i];
        }
        return *this;
    }

    int &operator[](int index)
    {
        if (index < 0 || index >= size_)
        {
            // 我觉得应该抛异常，而不是print
            throw std::out_of_range("越界访问");
        }
        return data_[index];
    }

    void resize(int new_size)
    {
        int *new_data = new int[new_size];
        for (auto i = 0; i < size_ && i < new_size; ++i)
        {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        size_ = new_size;
    }

    size_t size() const
    {
        return size_;
    }
};

int main()
{
    IntArray arr; // 建立存储空间为0的数组对象
    // arr[1] = 10;       // 对下标1位置的数组元素进行赋值操作；程序应提示越界访问
    arr.resize(10);    // 把存储空间增大为10，即可以存10个整型数值；注：存储空间的大小可增大，也可缩小
    IntArray arr2(20); // 建立存储空间为20的数组对象
    for (int i = 0; i < arr2.size(); i++)
        arr2[i] = i;
    arr = arr2;                          // 把arr2对象的内容复制给arr对象
    for (int i = 0; i < arr.size(); i++) // 打印输出arr里的数据，即0,1,2,3…19
        std::cout << arr[i] << ",";

    return 0;
}