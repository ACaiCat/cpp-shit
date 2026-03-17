/*
四、美国的《美国预防、检测、评估与治疗高血压全国联合委员会第七次报告》，将血压水平分为四类：
    正常血压    （≤120/80mmHg），
    高血压前期　（120—139/80—89mmHg），
    1期高血压  （140—159/90—99mmHg），
    2期高血压　（≥160/100mmHg）。
从键盘输入两个整数值，分别表示收缩压（高压）、舒张压（低压），程序输出其血压水平分类。
说明：取高压、低压两者中高的作为判断血压水平的依据，如高压121\低压92，则可诊断为1期高血压。
*/

#include <iostream>

int main()
{
    int highPressure, lowPressure;

    std::cin >> highPressure >> lowPressure;

    if (highPressure >= 160 || lowPressure >= 100)
    {
        std::cout << "1期高血压" << std::endl;
    }
    else if (highPressure >= 140 || lowPressure >= 90)
    {
        std::cout << "2期高血压" << std::endl;
    }
    else if (highPressure >= 120 || lowPressure >= 80)
    {
        std::cout << "高血压前期" << std::endl;
    }
    else
    {
        std::cout << "正常血压" << std::endl;
    }

    return 0;
}