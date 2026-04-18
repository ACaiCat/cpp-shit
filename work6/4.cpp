/*
四、对第5次作业第2题动态数组类IntArray进行扩展，
使其成为存储int数据的集合类IntSet,并增加一个成员函数insert(int)，
用于向集合中增加新的数据元素。集合的特性是其包含的数据不能重复。
例如，假设集合中已含有数据元素{1，2，3}，若还要增加数据元素3，则程序应提示不能增加。
*/

#include <iostream>
#include <stdexcept>
#include <algorithm>

class IntSet
{
private:
    // 存储数组元素的指针
    int *data_;
    int size_;

public:
    IntSet() : data_(nullptr), size_(0) {}
    IntSet(int size) : data_(new int[size]), size_(size) {}
    IntSet(const IntSet &other) : data_(new int[other.size_]), size_(other.size_)
    {
        for (auto i = 0; i < size_; ++i)
        {
            data_[i] = other.data_[i];
        }
    }

    // 析构时释放data_指向的内存空间
    ~IntSet()
    {
        delete[] data_;
    }

    // 这里需要重写赋值运算符深拷贝，不然默认浅拷贝，析构时双重释放直接爆
    IntSet &operator=(const IntSet &other)
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

    bool contains(int element)
    {
        return std::find(data_, data_ + size_, element) != data_ + size_;
    }

    void insert(int element)
    {
        if (contains(element))
        {
            return;
        }

        resize(size_ + 1);
        data_[size_ - 1] = element;
    }

    void print()
    {
        std::string sep;
        for (auto i = 0; i < size_; i++)
        {
            std::cout << sep << i;
            sep = ", ";
        }
        std::cout << "\n";
    }
};

int main()
{
    IntSet arr(2);

    arr[0] = 1;
    arr[1] = 2;

    arr.print();
    arr.insert(2);
    arr.print();
    arr.insert(3);
    arr.print();

    return 0;
}