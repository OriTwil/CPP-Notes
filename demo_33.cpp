/***
 * @Author: szf
 * @Date: 2022-12-23 13:39:47
 * @LastEditTime: 2022-12-23 14:49:46
 * @LastEditors: szf
 * @Description: 函数对象
 * @FilePath: \Study-Code\demo_33.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

//* 函数对象(仿函数)
// 使用时可以像普通函数一样,有参数,有返回值
// 函数对象超出普通函数的概念,函数对象有自己的状态
// 函数对象可以作为参数传递

//* 谓词
// 返回bool类型的仿函数称为谓词
// operator()接受一个参数为一元谓词,两个参数为二元谓词

//* 内建函数对象——算术仿函数
// #include <functional>
// 实现四则运算，其中negate是一元运算，其他都是二元运算
// template<class T> T plus<T>    //加法仿函数
// template<class T> T minus<T>    //减法仿函数
// template<class T> T multiplies<T> //乘法仿函数
// template<class T> T divides<T>   //除法仿函数
// template<class T>T modulus<T>   //取模仿函数
// template<class T> T negate<T>    //取反仿函数

//* 内建函数对象——关系仿函数
// template<class T> bool equal_to<T>//等于
// template<class T> bool not_equal_to<T>//不等于
// template<class T> bool greater<T>//大于
// template<class T> bool greater_equal<T>//大于等于
// template<class T> bool less<T>//小于
// template<class T> bool less_equal<T>//小于等于

//* 内建函数对象——关系仿函数
// template<class T> bool logical_and<T> //逻辑与
// template<class T> bool logical_or<T> //逻辑或
// template<class T> bool logical_not<T> //逻辑非

class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

class MyPrint
{
public:
    void operator()(string test)
    {
        cout << test << endl;
        this->m_count++;
    }

    int m_count;
};

void Test01()
{
    MyAdd myadd;
    cout << myadd(10, 10) << endl;
}

void Test02()
{
    MyPrint print;
    print("hello");
    print("hello");
    print("hello");
    print("hello");
    print("hello");

    cout << "调用了" << print.m_count << "次" << endl;
}

void DoPrint(MyPrint &print, string test)
{
    print(test);
}

void Test03()
{
    MyPrint print;
    DoPrint(print, "hello world!");
}

class GreaterFive
{
public:
    bool operator()(int vel)
    {
        return vel > 5;
    }
};

void Test04()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    vector<int>::iterator pos = find(v1.begin(), v1.end(), 6);
    pos = v1.erase(pos);
    pos = v1.erase(pos);
    pos = v1.erase(pos);
    // pos = v1.erase(pos);

    vector<int>::iterator it = find_if(v1.begin(), v1.end(), GreaterFive()); // 匿名函数对象
    if (it == v1.end())
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "找到了大于5的数为 : " << *it << endl;
    }
}

class MyCompare
{
public:
    bool operator()(int val1, int val2)
    {
        return val1 > val2;
    }
};

void Test05()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    sort(v1.begin(), v1.end(), MyCompare());

    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;
}

void Test06()
{
    negate<int> n;
    cout << n(50) << endl;

    plus<int> p;
    cout << p(30, 40) << endl;

    greater<int> g;
    if (g(n(-50), p(5, 40)))
    {
        cout << "大于" << endl;
    }
}

void Test07()
{
    vector<bool> v1;
    v1.push_back(true);
    v1.push_back(false);
    v1.push_back(true);
    v1.push_back(false);
    v1.push_back(true);
    v1.push_back(true);
    for (vector<bool>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<bool> v2;
    v2.resize(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());
    for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    // Test01();
    // Test02();
    // Test03();
    // Test04();
    // Test05();
    // Test06();
    Test07();

    system("pause");
    return 0;
}
