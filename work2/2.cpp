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