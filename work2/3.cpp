/*
三、栈是一种先进后出的数据结构。请编写一个实现栈功能的类，可存储int数据，可打印栈中元素，执行出栈、入栈操作。
出栈：把栈顶元素删除；
入栈：把元素加入栈种，且处于栈顶位置；
注：关于栈数据结构，可参看：https://baike.baidu.com/item/%E6%A0%88/12808149?fr=aladdin
主函数如下：
int main()
{
    Stack stack;
    stack.print();  //打印栈中的所有元素，打印顺序为从栈底到栈顶；打印格式自拟
    stack.pop();    //出栈
    stack.push(1);  //入栈
    stack.push(2);
    stack.print();
    stack.pop();
    stack.print();
}
*/

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