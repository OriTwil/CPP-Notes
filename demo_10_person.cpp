/***
 * @Author: szf
 * @Date: 2022-12-14 23:27:32
 * @LastEditTime: 2022-12-14 23:36:19
 * @LastEditors: szf
 * @Description: person
 * @FilePath: \Study-Code\demo_10_person.cpp
 * @@WeChat:szf13373959031
 */
#include "demo_10_person.h"
#include <string>

// 运算符重载：对已有运算符重定义，赋予其另一种功能，适应不同的数据类型
// 运算符重载也能发生函数重载

// 加号运算符重载
// 1.成员函数重载
// 2.全局函数重载

// 左移运算符
// 一般用全局函数重载左移运算符

// 重载递增运算符

// 赋值运算符的重载

// 关系运算符的重载

// 函数调用运算符重载
// 本质就是重载了小括号
// 也称为仿函数

// 成员函数重载 +
Person Person::operator+(const Person &p)
{
    Person temp(0, 0);
    temp.m_a = this->m_a + p.m_a;
    temp.m_b = this->m_a + p.m_b;
    return temp;
}
// 运算符重载 函数重载 +
Person Person::operator+(int a)
{
    Person temp(0, 0);
    temp.m_a = this->m_a + a;
    temp.m_b = this->m_a + a;

    return temp;
}

// 全局函数重载 +
Person operator+(Person &p1, Person &p2)
{
    Person temp(0, 0);
    temp.m_a = p1.m_a + p2.m_a;
    temp.m_b = p1.m_a + p2.m_b;
    return temp;
}

// 全局函数重载左移运算符
ostream &operator<<(ostream &cout, Person &p)
{
    cout << "m_a = " << p.m_a << endl
         << "m_b = " << p.m_b << endl;

    return cout;
}

// 重载++运算符
Person &Person::operator++()
{
    this->m_a++;
    this->m_b++;
    return *this;
}

// 重载后置++运算符
Person Person::operator++(int)
{
    Person p_temp = *this;
    this->m_a++;
    this->m_b++;
    return p_temp; // 后置要返回值
}

// 重载--运算符
Person &Person::operator--()
{
    this->m_a--;
    this->m_b--;
    return *this;
}

// 重载=运算符
Person &Person::operator=(const Person &p)
{
    this->m_a = p.m_a;
    this->m_b = p.m_b;
    return *this;
}

// 重载==判断运算符
bool Person::operator==(Person &p)
{
    if (this->m_a == p.m_a && this->m_b == p.m_b)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// 重载（）运算符
void Person::operator()(string test)
{
    cout << test << endl;
}
