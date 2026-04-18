/*
四、请根据下列程序中的主函数，补充完整Rectangle类，使程序能正常运行，并得到预期结果。

#include <iostream>
using namespace std;

class Rectangle
{
};

int main()
{
    Rectangle rec(5,10); //5是宽度，10是高度；
    cout<<"矩形的面积是："<<(int)rec<<endl; //程序输出：矩形的面积是：50
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
};

int main()
{
    Rectangle rec(5, 10);                                   // 5是宽度，10是高度；
    std::cout << "矩形的面积是：" << (int)rec << std::endl; // 程序输出：矩形的面积是：50
}