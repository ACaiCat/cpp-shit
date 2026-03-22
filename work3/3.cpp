/*
三、修改“作业2”的第3题，使以下的程序输出：
Copy stack
2, 1
4, 3, 2, 1
Delete stack, size=4
Delete stack, size=2

主函数如下：
int main()
{
    Stack stack;
    stack.push(1);
    stack.push(2);

    Stack stack2=stack;  //打印输出：Copy stack
    stack2.push(3);
    stack2.push(4);

    stack.print();       //打印输出：2, 1
    stack2.print();     //打印输出：4, 3, 2, 1
    }
}
*/

#include <iostream>
#include <cstring>

class Stack
{
private:
    int data[100];
    int len = 0;

public:
    Stack() = default;

    Stack(const Stack &other)
    {
        std::cout << "Copy stack" << std::endl;
        this->len = other.len;
        std::memcpy(this->data, other.data, sizeof(int) * len);
    }

    ~Stack()
    {
        std::cout << "Delete stack, size=" << len << std::endl;
    }

    void print()
    {
        if (len == 0)
        {
            std::cout << "Empty" << std::endl;
            return;
        }

        for (int i = len - 1; i >= 0; i--)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    int pop()
    {
        if (len == 0)
        {
            // throw "Stack is empty";
            return -1;
        }
        return data[--len];
    }
    void push(int x)
    {
        this->data[len++] = x;
    }
};

int main()
{
    Stack stack;
    stack.push(1);
    stack.push(2);

    Stack stack2 = stack; // 打印输出：Copy stack
    stack2.push(3);
    stack2.push(4);

    stack.print();  // 打印输出：2, 1
    stack2.print(); // 打印输出：4, 3, 2, 1
}