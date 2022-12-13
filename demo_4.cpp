/***
 * @Author: szf
 * @Date: 2022-12-13 11:33:22
 * @LastEditTime: 2022-12-13 11:36:46
 * @LastEditors: szf
 * @Description: 类和对象——封装与访问权限
 * @FilePath: \Study-Code\code-cpp\demo_4.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
#include <string>

using namespace std;
#define PI 3.1415926

// 封装
// 意义：属性与行为作为整体，加以权限控制

// 设计一个圆类
class Circle
{
    // 访问权限
public:
    // 属性
    int m_r;

    // 行为
    double Calculate()
    {
        return 2 * PI * m_r;
    }
};

// 访问权限
// public 类内外都可以访问
// protected 类内可以访问，类外不能访问
// private 类内可以访问，类外不能访问
// 注意：
// 1. struct 默认公共权限；class 默认私有权限
// 2. 成员私有化可以控制读写权限、检测数据有效性

// 设计一个学生类
class Student
{
public:
    // 成员属性、成员变量
    int m_id;

    string m_name;

protected:
    float m_height;

private:
    // 对于私有成员，一般有公共的函数负责读写

    int m_password;

    int m_age;

    string m_lover;

public:
    // 成员函数、成员方法
    void showStudent()
    {
        cout << "name is " << m_name << endl
             << "id is : " << m_id << endl
             << "height is : " << m_height << endl
             << "password is : " << m_password << endl;
    }

    void setStudent(int id, string name, float height, int password)
    {
        m_id = id;
        m_name = name;
        m_height = height;
        m_password = password;
    }

    void showAge() // 只读的
    {
        cout << "age is " << m_age << endl;
    }

    void setAge(int age)
    {
        if (age < 0 || age > 100)
        {
            m_age = 0;
            cout << "ERROR!" << endl;
            return;
        }//可以检验数据有效性
        m_age = age;
    }

    void setLover(string lover) // 只写的
    {
        m_lover = lover;
    }
};

int main()
{
    // 创建类(实例化)
    Circle c1;
    // 属性赋值
    c1.m_r = 10;
    // 行为
    cout << "周长为：" << c1.Calculate() << endl;

    // 实例化学生
    Student stu;

    stu.m_name = "lisi";
    stu.m_id = 2;
    stu.showStudent();

    stu.setStudent(1, "zhangsan", 1.80, 2103303);
    stu.showStudent();

    stu.setLover("wangwu");
    stu.setAge(10);
    stu.showAge();

    system("pause");
}