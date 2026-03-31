/*
三、请设计一个学生类Student，可以统计所有学生的平均成绩
以下程序输出：
平均成绩为：75


#include <iostream>
using namespace std;


请在此处补充代码；


int main()
{
    Student s1(90);
    Student s2(80);
    Student s3(70);
    Student s4(60);
    cout << "平均成绩为：" << Student::getAvgScore() << endl;
    return 0;
}
*/

#include <iostream>

class Student {
private:
    inline static int total_score_ = 0;
    inline static int student_count_ = 0;
    int score_;
public:
    Student(int score) : score_(score) {
        total_score_ += score_;
        student_count_++;
    }

    static double getAvgScore() {
        return total_score_ / (double)(student_count_);
    }
};

int main()
{
    Student s1(90);
    Student s2(80);
    Student s3(70);
    Student s4(60);
    
    std::cout << "平均成绩为：" << Student::getAvgScore() << std::endl;

    return 0;
}