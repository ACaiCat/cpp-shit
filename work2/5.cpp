#include <iostream>
#include <vector>

class Rectangle
{
public:
    std::pair<double, double> lowerLeft;
    std::pair<double, double> upperRight;
    Rectangle(double x1, double y1, double x2, double y2)
    {
        this->lowerLeft = {x1, y1};
        this->upperRight = {x2, y2};
    }
    bool Contains(Rectangle &rect)
    {
        return this->lowerLeft.first <= rect.lowerLeft.first &&
               this->lowerLeft.second <= rect.lowerLeft.second &&
               this->upperRight.first >= rect.upperRight.first &&
               this->upperRight.second >= rect.upperRight.second;
    }

    bool Intersects(Rectangle &rect)
    {
        return !(this->upperRight.first < rect.lowerLeft.first ||
                 this->lowerLeft.first > rect.upperRight.first ||
                 this->upperRight.second < rect.lowerLeft.second ||
                 this->lowerLeft.second > rect.upperRight.second);
    }

    bool Separate(Rectangle &rect)
    {
        return this->upperRight.first < rect.lowerLeft.first ||
               this->lowerLeft.first > rect.upperRight.first ||
               this->upperRight.second < rect.lowerLeft.second ||
               this->lowerLeft.second > rect.upperRight.second;
    }

    bool Intersect(Rectangle &rect)
    {
        return this->Intersects(rect) && !this->Contains(rect) && !rect.Contains(*this);
    }
};

int main()
{
    int x1, y1, x2, y2;
    std::cout << "请输入第一个矩形的左下角和右上角坐标（x1 y1 x2 y2）：" << std::endl;
    std::cin >> x1 >> y1 >> x2 >> y2;
    Rectangle rect1(x1, y1, x2, y2);
    std::cout << "请输入第二个矩形的左下角和右上角坐标（x1 y1 x2 y2）：" << std::endl;
    std::cin >> x1 >> y1 >> x2 >> y2;
    Rectangle rect2(x1, y1, x2, y2);

    if (rect1.Contains(rect2))
    {
        std::cout << "Rect1包含Rect2" << std::endl;
    }
    else if (rect2.Contains(rect1))
    {
        std::cout << "Rect2包含Rect1" << std::endl;
    }
    else if (rect1.Intersects(rect2))
    {
        std::cout << "Rect1和Rect2相交" << std::endl;
    }
    else if (rect1.Separate(rect2))
    {
        std::cout << "Rect1和Rect2分离" << std::endl;
    }
    else if (rect1.Intersect(rect2))
    {
        std::cout << "Rect1和Rect2相交但不包含" << std::endl;
    }
}