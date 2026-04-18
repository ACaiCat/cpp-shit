/*
一、请编写一个商品类，用于描述商品的名称、重量、长、宽、价格、品牌等信息，
并实现读取商品相关信息的成员函数以及构造函数。再编写一个交通工具类，用于描述交通工具的
名称、重量、速度、长、宽等信息，并实现读取交通工具相关信息的成员函数以及构造函数。
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