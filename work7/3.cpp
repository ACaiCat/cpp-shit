/*
三、第一题中，商品类和交通工具类有较多的相似之处。
请抽象出这两个类的共同点，设计它们的共同基类：物体类。
根据现在的继承结构，采用虚继承的办法实现汽车类。
*/

#include <iostream>
#include <string>

class Object
{
protected:
    std::string name_;
    double weight_;
    double length_;
    double width_;

public:
    Object(std::string name, double weight, double length, double width)
        : name_(name), weight_(weight), length_(length), width_(width) {}
    virtual void displayInfo() = 0;
};

class Product : virtual public Object
{
private:
    double price_;
    std::string brand_;

public:
    Product(std::string name, double weight, double length, double width, double price,
            std::string brand)
        : Object(name, weight, length, width), price_(price), brand_(brand) {}
    void displayInfo() override
    {
        std::cout << "商品名: " << name_ << std::endl;
        std::cout << "重量: " << weight_ << " kg" << std::endl;
        std::cout << "长度: " << length_ << " cm" << std::endl;
        std::cout << "宽度: " << width_ << " cm" << std::endl;
        std::cout << "价格: $" << price_ << std::endl;
        std::cout << "品牌: " << brand_ << std::endl;
    }
};

class Vehicle : virtual public Object
{
private:
    double speed_;

public:
    Vehicle(std::string name, double weight, double length, double width, double speed)

        : Object(name, weight, length, width), speed_(speed)
    {
    }
    void displayInfo() override
    {
        std::cout << "交通工具名: " << name_ << std::endl;
        std::cout << "重量: " << weight_ << " kg" << std::endl;
        std::cout << "速度: " << speed_ << " km/h" << std ::endl;
        std::cout << "长度: " << length_ << " cm" << std::endl;
        std::cout << "宽度: " << width_ << " cm" << std::endl;
    }
};
