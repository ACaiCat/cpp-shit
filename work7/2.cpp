/*
二、请基于上题的两个类，实现汽车类，使得该类能描述汽车的名称、
重量、长、宽、价格、品牌、速度等信息，并能将前述信息打印输出。
*/

#include <iostream>
#include <string>

class Product
{
private:
    std::string name_;
    double weight_;
    double length_;
    double width_;
    double price_;
    std::string brand_;

public:
    Product(std::string name, double weight, double length, double width, double price, std::string brand)
        : name_(name), weight_(weight), length_(length), width_(width), price_(price), brand_(brand) {}

    void displayInfo()
    {
        std::cout << "商品名: " << name_ << std::endl;
        std::cout << "重量: " << weight_ << " kg" << std::endl;
        std::cout << "长度: " << length_ << " cm" << std::endl;
        std::cout << "宽度: " << width_ << " cm" << std::endl;
        std::cout << "价格: $" << price_ << std::endl;
        std::cout << "品牌: " << brand_ << std::endl;
    }
};

class Vehicle
{
private:
    std::string name_;
    double weight_;
    double speed_;
    double length_;
    double width_;

public:
    Vehicle(std::string name, double weight, double speed, double length, double width)
        : name_(name), weight_(weight), speed_(speed), length_(length), width_(width) {}

    void displayInfo()
    {
        std::cout << "交通工具名: " << name_ << std::endl;
        std::cout << "重量: " << weight_ << " kg" << std::endl;
        std::cout << "速度: " << speed_ << " km/h" << std ::endl;
        std::cout << "长度: " << length_ << " cm" << std::endl;
        std::cout << "宽度: " << width_ << " cm" << std::endl;
    }
};

class Car : public Product, public Vehicle
{
public:
    Car(std::string name, double weight, double length, double width, double price, std::string brand, double speed)
        : Product(name, weight, length, width, price, brand), Vehicle(name, weight, speed, length, width) {}

    void displayInfo()
    {
        Product::displayInfo();
        Vehicle::displayInfo();
    }
};
