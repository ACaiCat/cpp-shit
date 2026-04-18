/*
五、修改上题中的Rectangle类，使得主程序有以下的输出。
int main()
{
    Rectangle rec(5,10);
    int area=rec;
    std::cout<<"矩形的面积是："<<(int)rec<<std::endl;   //程序输出：矩形的面积是：50
    std::cout<<"矩形新的面积是："<<(int)++rec++<<std::endl; //程序输出：矩形新的面积是：66
    std::cout<<"矩形新的面积是："<<(int)rec<<std::endl;  //程序输出：矩形新的面积是：66
    std::cin.get();
}
*/

#include <iostream>

class Rectangle
{
private:
    int width_;
    int height_;

public:
    Rectangle(int width, int height) : width_(width), height_(height) {}

    operator int() const
    {
        return width_ * height_;
    }

    Rectangle &operator++()
    {
        ++width_;
        ++height_;
        return *this;
    }

    Rectangle operator++(int)
    {
        auto temp = *this;
        (*this)++;
        return temp;
    }
};

int main()
{
    Rectangle rec(5, 10);
    int area = rec;
    std::cout << "矩形的面积是：" << (int)rec << std::endl;       // 程序输出：矩形的面积是：50
    std::cout << "矩形新的面积是：" << (int)++rec++ << std::endl; // 程序输出：矩形新的面积是：66
    std::cout << "矩形新的面积是：" << (int)rec << std::endl;     // 程序输出：矩形新的面积是：66
    std::cin.get();
}