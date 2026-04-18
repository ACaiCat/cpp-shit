/*
二、先设计一个圆类Circle，具有计算圆面积的功能。
再以圆类Circle为基础，设计一个圆环类Ring，具有计算圆环面积的功能。
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

    double getRadius() const
    {
        return radius_;
    }

    double calculateArea() const
    {
        return M_PI * radius_ * radius_;
    }
};

class Ring
{
private:
    Circle inner_circle_;
    Circle outer_circle_;

public:
    Ring(double inner, double outer) : inner_circle_(inner), outer_circle_(outer) {}

    double calculateArea() const
    {
        return outer_circle_.calculateArea() - inner_circle_.calculateArea();
    }
};