/*
二、email地址的格式：账户名+@+服务器域名，请编写一个类表示email地址
*/

#include <iostream>
#include <string>

class Email
{
    private:
        std::string username;
        std::string host;
        
    public:
        Email(std::string username, std::string host){
            this->username = username;
            this->host = host;
        }

        std::string GetAddress()
        {
            return this->username + "@" + this->host;
        }
};

int main()
{
    Email email("13110818005", "qq.com");
    std::cout << email.GetAddress() << std::endl;

    return 0;
}