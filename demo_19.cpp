/***
 * @Author: szf
 * @Date: 2022-12-19 03:51:58
 * @LastEditTime: 2022-12-19 03:53:50
 * @LastEditors: szf
 * @Description: 模板
 * @FilePath: \Study-Code\demo_19.cpp
 * @@WeChat:szf13373959031
 */

// MOOC 选课 模电实验

// 泛型编程 主要技术为模板(类型参数化)

// 模板机制：函数模板、类模板

// 语法：template<typename T>
// 函数声明或定义

// 两种方式使用函数模板：
// 1.自动类型推导
// 2.显示指定类型

// 函数模板注意事项
// 1.自动类型推导，必须推导出一致的数据类型T
// 2.模板必须要确定出T的数据类型，才可以使用

// 普通函数与函数模板的区别
// 1.普通函数可以发生隐式类型转换
// 2.函数模板 用自动类型推导，不可以发生隐式类型转换
//? 3.函数模板 用显示指定类型，可以发生隐式类型转换

// 普通函数与函数模板的调用规则
// 1.如果普通函数和函数模板都可以调用，优先调用普通函数
// 2.可以通过空模板参数列表 强制调用函数模板
// 3.函数模板可以发生函数重载
// 4.如果函数模板可以产生更好的匹配，优先调用函数模板

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person(int age, float height) : m_age(age), m_height(height) {}
    int m_age;
    float m_height;
};
// 交换模板
// template <typename T>
template <class T>
void MySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 具体化实现
template <>
void MySwap(Person &a, Person &b)
{
    Person index = a;
    a = b;
    b = index;
}

// 函数模板
template <class T>
void Func()
{
    cout << "func的调用" << endl;
}

// 排序模板
template <class T>
void MySort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] > arr[j])
            {
                MySwap(arr[i], arr[j]);
            }
        }
    }
}

// 数组打印模板
template <class T>
void MyPrint(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void MyTest(int a, int b)
{
    cout << "普通函数的调用" << endl;
}

template <class T>
void MyTest(T a, T b)
{
    cout << "函数模板的调用" << endl;
}

template <class T>
void MyTest(T a, T b, T c)
{
    cout << "函数模板重载的调用" << endl;
}

void Test01()
{
    int a = 10;
    int b = 20;

    MySwap(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

void Test02()
{
    double a = 10.6;
    double b = 29.1;

    MySwap<double>(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

void Test03()
{
    Func<int>();
}

void Test04()
{
    char charArr[] = "qwertyuiopasdfghjklzxcvbnm";
    int lenCharArr = sizeof(charArr) / sizeof(char);
    MySort<char>(charArr, lenCharArr);
    MyPrint<char>(charArr, lenCharArr);

    int intArr[] = {1, 4, 7, 8, 5, 2, 3, 6, 9};
    int lenIntArr = sizeof(intArr) / sizeof(int);
    MySort<int>(intArr, lenIntArr);
    MyPrint<int>(intArr, lenIntArr);
}

void Test05()
{
    int a = 0;
    int b = 9;

    MyTest(a, b);
    MyTest<>(a, b); // 空模板
    MyTest(1, 1, 1);
}

void Test06()
{
    char a = 'a';
    char b = 'b';

    MyTest(a, b);
}

void Test07()
{
    Person p1(18, 180.0);
    Person p2(49, 183.2);

    MySwap(p1, p2);
    cout << "p1_age:" << p1.m_age << endl
         << "p1_height:" << p1.m_height << endl;
    cout << "p2_age:" << p2.m_age << endl
         << "p2_height:" << p2.m_height << endl;
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