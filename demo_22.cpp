/***
 * @Author: szf
 * @Date: 2022-12-20 21:11:03
 * @LastEditTime: 2022-12-20 21:13:22
 * @LastEditors: szf
 * @Description: STL(标准模板库)
 * @FilePath: \Study-Code\demo_22.cpp
 * @@WeChat:szf13373959031
 */

//* STL
// STL 建立数据结构与算法的一套标准
// STL广义分为容器、算法、迭代器
// 容器和算法通过迭代器无缝衔接
// STL几乎所有代码都采用模板类或模板函数
// STL溜达组件：容器、算法、迭代器、仿函数、适配器、空间配置器

//* 容器
// STL容器就是将运用最广的一些数据结构实现出来
// 常见数据结构：数组，链表、数、栈、队列、集合、映射表
// 分为序列式容器（强调值的排序）、关联式容器（二叉树结构）

//* 算法（Algorithms）
// 有限的步骤，解决逻辑或数学上的问题
// 分为质变算法（更改区间元素的内容）和非质变算法（不改变内容）

//* 迭代器
// 输入、输出、前向、双向（常用）、随机访问迭代器（常用）

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void MyPrint(int val)
{
    cout << val << endl;
}

// vector存放内置数据类型
void Test01()
{
    // 创建容器
    vector<int> v;
    // 尾插入数据
    for (int i = 0; i < 10; i++)
    {
        v.push_back(10 * i);
    }
    // 通过迭代器访问容器中的数据
    vector<int>::iterator itBegin = v.begin(); // 起始迭代器，指向容器中第一个元素
    vector<int>::iterator itEnd = v.end();     // 结束迭代器 指向容器的对后一个元素

    // 第一种遍历方式
    while (itBegin != itEnd)
    {
        cout << *itBegin << endl;
        itBegin++;
    }
    // 第二种遍历方式
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
    // 第三种方式
    for_each(v.begin(), v.end(), MyPrint);
}

// vector存放自定义数据类型
class Person
{
public:
    Person(string name, int age) : m_name(name), m_age(age) {}

    string m_name;
    int m_age;
};

void Test02()
{
    vector<Person> v;

    Person p1("zhangsan", 15);
    Person p2("lisi", 16);
    Person p3("wangwu", 17);
    Person p4("wuliu", 18);
    Person p5("xieqi", 19);
    Person p6("chenba", 20);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    v.push_back(p6);

    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名:" << (*it).m_name << "\t年龄:" << it->m_age << endl;
    }
}

// 存放自定义数据类型指针
void Test03()
{
    vector<Person *> v;

    Person p1("zhangsan", 15);
    Person p2("lisi", 16);
    Person p3("wangwu", 17);
    Person p4("wuliu", 18);
    Person p5("xieqi", 19);
    Person p6("chenba", 20);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
    v.push_back(&p6);

    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名为 " << (*it)->m_name << "\t年龄 : " << (*it)->m_age << endl;
    }
}

// 容器嵌套容器
void Test04()
{
    vector<vector<int>> v;

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    for (int i = 0; i < 4; i++)
    {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        for (vector<int>::iterator it_ = it->begin(); it_ != it->end(); it_++)
        {
            cout << (*it_) << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Test01();
    // Test02();
    // Test03();
    Test04();

    system("pause");
    return 0;
}