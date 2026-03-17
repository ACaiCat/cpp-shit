#include <iostream>

class Stack
{
private:
    int data[100];
    int len = 0;

public:
    void print()
    {
        if (len == 0)
        {
            std::cout << "Empty" << std::endl;
            return;
        }

        for (int i = 0; i < len; i++)
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
    stack.print(); // 打印栈中的所有元素，打印顺序为从栈底到栈顶；打印格式自拟
    stack.pop();   // 出栈 (Why?)
    stack.push(1); // 入栈
    stack.push(2);
    stack.print();
    stack.pop();
    stack.print();
}