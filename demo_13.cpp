/***
 * @Author: szf
 * @Date: 2022-12-16 20:05:33
 * @LastEditTime: 2022-12-16 20:39:46
 * @LastEditors: szf
 * @Description: 多态——案例1——计算机类
 * @FilePath: \Study-Code\demo_13.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
#include <string>
using namespace std;

// 多态优点
// 1.代码组织结构清晰
// 2.可读性强
// 3.利于前期和后期的扩展和维护

// 开闭原则：
// 对扩展进行开发，对修改进行关闭

// 普通方法
class Calculator
{
public:
    int m_num1;
    int m_num2;

public:
    int getResult(string oper)
    {
        if (oper == "+")
        {
            return m_num1 + m_num2;
        }
        else if (oper == "-")
        {
            return m_num1 - m_num2;
        }
        else if (oper == "*")
        {
            return m_num1 * m_num2;
        }
    }
};

// 多态方法
class AbstractCalculator
{
public:
    int m_num1;
    int m_num2;

public:
    virtual int getResult()
    {
        return 0;
    }
};

class AddCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_num1 + m_num2;
    }
};

class SubCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_num1 - m_num2;
    }
};

class MulCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_num1 * m_num2;
    }
};

void Test01()
{
    Calculator c;
    c.m_num1 = 10;
    c.m_num2 = 15;

    cout << c.m_num1 << " * " << c.m_num2 << " = " << c.getResult("*") << endl;
}

void Test02()
{
    // 多态使用条件
    // 父类指针或引用指向子类对象

    // 加法
    AbstractCalculator *abc = new AddCalculator();
    abc->m_num1 = 10;
    abc->m_num2 = 15;

    cout << abc->m_num1 << " + " << abc->m_num2 << " = " << abc->getResult() << endl;

    delete abc;

    // 减法
    abc = new SubCalculator();
    abc->m_num1 = 10;
    abc->m_num2 = 15;

    cout << abc->m_num1 << " - " << abc->m_num2 << " = " << abc->getResult() << endl;

    delete abc;

    // 乘法
    abc = new MulCalculator();
    abc->m_num1 = 10;
    abc->m_num2 = 15;

    cout << abc->m_num1 << " * " << abc->m_num2 << " = " << abc->getResult() << endl;

    delete abc;
}

int main()
{
    // Test01();
    Test02();

    system("pause");
    return 0;
}
