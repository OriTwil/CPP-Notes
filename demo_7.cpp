/***
 * @Author: szf
 * @Date: 2022-12-14 13:40:30
 * @LastEditTime: 2022-12-14 13:42:50
 * @LastEditors: szf
 * @Description: 静态成员
 * @FilePath: \Study-Code\demo_7.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
using namespace std;

// 静态成员

// 静态成员变量：
// 所有对象共享数据
// 再编译阶段分配内存
// 类内声明，类外初始化

// 静态成员函数：
// 所有对象共享一个函数
// 静态成员函数只能访问静态成员变量

class Person
{
public:
    static int m_age;
    int m_id;

    static void Func()
    {
        cout << "static Func " << endl;
    }

private:
    static int m_height;
};

//类外初始化
int Person::m_age = 100; // 1.通过类名访问
int Person::m_height = 180;

void Test01()
{
    Person p1;
    cout << p1.m_age << endl;

    Person p2;
    p2.m_age = 200; // 2.通过对象访问
    cout << Person::m_age << endl;

    // cout << Person::m_height << endl;//静态变量也有权限

    p1.Func();
    Person::Func();
}

int main()
{
    Test01();

    system("pause");
    return 0;
}