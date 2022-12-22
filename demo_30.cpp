/***
 * @Author: szf
 * @Date: 2022-12-22 18:51:47
 * @LastEditTime: 2022-12-22 19:06:08
 * @LastEditors: szf
 * @Description: set/multiset 集合容器
 * @FilePath: \Study-Code\demo_30.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
#include <set>
using namespace std;

//* set
// 所有元素都在插入时自动排序
// set/multiset 属于关联式容器,底层结构是用二叉树实现
// set不允许重复元素,multiset允许

//* 构造
// set<T> st;
// set(const set &st) // 拷贝构造

//* 赋值
// 重载=

//* 基本函数
// insert()//插入元素,返回pair<set<int>::iterator, bool>
// count()//判断容器中是否存在某个元素
// size()//返回容器的尺寸，也可以元素的个数
// erase()//删除集合中某个元素
// clear()//清空集合
// empty()//判断是否为空
// begin()//返回第一个节点的迭代器
// end()//返回最后一个节点加1的迭代器
// rbegin()//反向迭代器
// rend()//反向迭代器

//* 功能函数
// find()//查找某个指定元素的迭代器
// lower_bound()//二分查找第一个不小于某个值的元素的迭代器
// get_allocator()//返回集合的分配器
// swap()//交换两个集合的变量
// max_size()//返回集合能容纳元素的最大限值

//* pair对组创建
// pair<type,type> p(value1,value2)
// pair<type,type> p = make_pair(value1,value2)

//*set排序
// 利用仿函数(重载()),修改排序规则
// 自定义数据类型,必须利用仿函数提前规定排序类型    飓风等级哦v的     

void PrintSet(const set<int> &s)
{
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "s的大小是 : " << s.size() << endl;
}

void Test01()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    s1.insert(5);
    s1.erase(5);
    PrintSet(s1);

    cout << *s1.lower_bound(4) << endl;
}

void Test02()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(30);
    s1.insert(30);
    s1.insert(30);
    s1.insert(40);

    set<int>::iterator pos = s1.find(30);
    if (pos != s1.end())
    {
        cout << "找到了" << endl;
    }
    else
    {
        cout << "没找到" << endl;
    }

    if (s1.count(30))
    {
        cout << "找到了" << endl;
    }
    else
    {
        cout << "没找到" << endl;
    }
}

void Test03()
{
    set<int> s1;

    pair<set<int>::iterator, bool> ret = s1.insert(10);

    if (ret.second)
    {
        cout << "第一次添加成功" << endl;
    }
    else
    {
        cout << "第一次插入失败" << endl;
    }

    ret = s1.insert(10);
    if (ret.second)
    {
        cout << "第二次添加成功" << endl;
    }
    else
    {
        cout << "第二次插入失败" << endl;
    }
}

void Test04()
{
    multiset<int> ms;
    ms.insert(10);
    ms.insert(10);

    for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void Test05()
{
    pair<string, int> p("Tom", 18);
    p.first = "zhangsan";
    p.second = 15;

    cout << "姓名 : " << p.first << "\t年龄 : " << p.second << endl;

    pair<string, int> p2 = make_pair("Jack", 16);
    cout << "姓名 : " << p2.first << "\t年龄 : " << p2.second << endl;
}

class MyCompare
{
public:
    bool operator()(const int &v1, const int &v2) const
    {
        return v1 > v2;
    }
};

void Test06()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(50);
    s1.insert(60);
    s1.insert(30);
    s1.insert(70);
    s1.insert(40);

    set<int, MyCompare> s2;
    s2.insert(10);
    s2.insert(20);
    s2.insert(50);
    s2.insert(60);
    s2.insert(30);
    s2.insert(70);
    s2.insert(40);

    for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

class Person
{
public:
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }

public:
    string m_name;
    int m_age;
};

class ComparePerson
{
public:
    bool operator()(const Person &p1, const Person &p2) const
    {
        return p1.m_age < p2.m_age;
    }
};

void Test07()
{
    set<Person, ComparePerson> s;

    Person p1("刘备", 24);
    Person p2("关羽", 28);
    Person p3("张飞", 25);
    Person p4("赵云", 21);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    for (set<Person, ComparePerson>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << "姓名 : " << it->m_name << "  年龄 : " << it->m_age << endl;
    }
}

int main()
{
    // Test01();
    // Test02();
    // Test04();
    // Test05();
    // Test06();
    Test07();

    system("pause");
    return 0;
}
