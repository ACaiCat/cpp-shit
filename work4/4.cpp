/*
四、有如下学生数据，请编写程序按照总分从大到小输出学生信息，如果总分相同，则按学号从小到大排列。
学号	姓名	班级	物理   化学
20001	张三	1	   80	  85
20002	李四	2	   82	  75
20003	王五	3	   73	  68
20004	马六	3	   85	  80
20005	陈七	4	   90	  88
*/

#include <iostream>
#include <algorithm>

struct Student
{
    int id;
    std::string name;
    int class_id;
    int physics;
    int chemistry;

    int TotalScore() const {
        return physics + chemistry;
    }
};

int main()
{
    Student students[] = {
        {20001, "张三", 1, 80, 85},
        {20002, "李四", 2, 82, 75},
        {20003, "王五", 3, 73, 68},
        {20004, "马六", 3, 85, 80},
        {20005, "陈七", 4, 90, 88}
    };

    std::sort(std::begin(students), std::end(students), [](const Student &a, const Student &b) {
        if (a.TotalScore() == b.TotalScore()) {
            return a.id < b.id;
        }
        return a.TotalScore() > b.TotalScore();
    });

    for (const auto &student : students)
    {
        std::cout 
        << student.id << "\t" 
        << student.name << "\t" 
        << student.class_id << "\t" 
        << student.physics << "\t" 
        << student.chemistry 
        << std::endl;
    }

    return 0;
}