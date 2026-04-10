/*
一、先设计一个圆类Circle，具有计算圆面积的功能。
再以圆类Circle为基础，设计一个圆柱体类Cylinder，具有计算圆柱体积的功能。
（以类组合的方式实现）
*/

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

class Circle
{
private:
    double radius_;

public:
    Circle(double radius) : radius_(radius) {}

    double Area() const
    {
        return M_PI * radius_ * radius_;
    }
};

class Cylinder
{
private:
    Circle base_;
    double height_;

public:
    Cylinder(double radius, double height) : base_(radius), height_(height) {}

    double Volume() const
    {
        return base_.Area() * height_;
    }
};

int main()
{
    double radius, height;

    std::cout << "请输入圆柱体的半径和高度：";
    std::cin >> radius >> height;

    Cylinder cylinder(radius, height);
    std::cout << "圆柱体的体积为: " << cylinder.Volume() << std::endl;

    return 0;
}