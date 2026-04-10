/*
三、改造上题，使之成为存储正方形对象的数组类SquareArray，并可按正方形边长从小到大的顺序对正方形对象进行排序。
所设计的正方形类Square、数组类SquareArray应支持深拷贝及以下主函数的运行。

主函数如下：

int main()
{
    Square s1(4);
    Square s2(6);
    SquareArray arr(2); // 建立存储空间为2的数组对象
    arr[0] = s2;
    arr[1] = s1;
    arr.sort();                          // 按正方形边长从小到大的顺序对数组元素进行排序
    for (int i = 0; i < arr.size(); i++) // 打印输出arr里的各个正方形对象的边长，即4,6
        arr[i].print();

    return 0;
}
*/

#include <iostream>
#include <stdexcept>
#include <algorithm>

class Square
{
private:
    int side_length_;

public:
    Square() : side_length_(0) {}
    Square(int side_length) : side_length_(side_length) {}
    int getSideLength() const { return side_length_; }
    void print() const { std::cout << side_length_ << ","; }
};

class SquareArray
{
private:
    // 存储数组元素的指针
    Square *data_;
    int size_;

public:
    SquareArray() : data_(nullptr), size_(0) {}
    SquareArray(int size) : data_(new Square[size]), size_(size) {}
    SquareArray(const SquareArray &other) : data_(new Square[other.size_]), size_(other.size_)
    {
        for (auto i = 0; i < size_; ++i)
        {
            data_[i] = other.data_[i];
        }
    }

    // 析构时释放data_指向的内存空间
    ~SquareArray()
    {
        delete[] data_;
    }

    // 这里需要重写赋值运算符深拷贝，不然默认浅拷贝，析构时双重释放直接爆
    SquareArray &operator=(const SquareArray &other)
    {
        if (this != &other)
        {
            delete[] data_;
            size_ = other.size_;
            data_ = new Square[size_];
            for (auto i = 0; i < size_; ++i)
                data_[i] = other.data_[i];
        }
        return *this;
    }

    Square &operator[](int index)
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
        Square *new_data = new Square[new_size];
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

    void sort()
    {
        std::sort(
            data_, data_ + size_, [](const auto &a, const auto &b)
            { return a.getSideLength() < b.getSideLength(); });
    }
};

int main()
{
    Square s1(4);
    Square s2(6);
    SquareArray arr(2); // 建立存储空间为2的数组对象
    arr[0] = s2;
    arr[1] = s1;
    arr.sort();                          // 按正方形边长从小到大的顺序对数组元素进行排序
    for (int i = 0; i < arr.size(); i++) // 打印输出arr里的各个正方形对象的边长，即4,6
        arr[i].print();

    return 0;
}