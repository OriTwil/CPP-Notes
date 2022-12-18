/***
 * @Author: szf
 * @Date: 2022-12-14 23:30:15
 * @LastEditTime: 2022-12-14 23:30:16
 * @LastEditors: szf
 * @Description:test
 * @FilePath: \Study-Code\demo_10_test.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
#include "demo_10_person.h"

using namespace std;

void Test01()
{
    Person p1(0, 0);
    p1.m_a = 10;
    p1.m_b = 20;

    Person p2(0, 0);
    p2.m_a = 15;
    p2.m_b = 25;

    Person p3 = p1 + p2;
    cout << p3;

    Person p4 = p1 + 10;
    cout << p4;
}

void Test02()
{
    Person p1(0, 0);
    cout << ++(++p1) << --(--p1);
    p1++;
    cout << p1; //?
}

void Test03()
{
    Person p1(0, 1);
    Person p2(10, 11);
    Person p3(100, 101);

    p1 = p2 = p3;
    cout << p1 << p2 << p3;
}

void Test04()
{
    Person p1(0, 0);
    Person p2(0, 0);

    if (p1 == p2)
    {
        cout << "相等" << endl;
    }
    else
    {
        cout << "不相等" << endl;
    }
}

void Test05()
{
    Person p1(0,0);
    p1("hello world");//使用起来像函数

}