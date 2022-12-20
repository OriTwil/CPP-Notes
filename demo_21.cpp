/***
 * @Author: szf
 * @Date: 2022-12-20 15:51:43
 * @LastEditTime: 2022-12-20 15:51:47
 * @LastEditors: szf
 * @Description:类模板案例——通用的数组类
 * @FilePath: \Study-Code\demo_21.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
#include <string>
#include "demo_21_array.hpp"
using namespace std;

class Person
{
public:
    Person(){};
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    string m_name;
    int m_age;
};

ostream &operator<<(ostream &cout, Person &p)
{
    cout << "name : " << p.m_name << "    "
         << "age = " << p.m_age;

    return cout;
}

void PrintIntArray(MyArray<int> &arr)
{
    for (int i = 0; i < arr.GetSize(); i++)
    {
        cout << arr[i] << endl;
    }
}

void Test01()
{
    MyArray<int> arr(5);
    // cout << "sizeof(arr) = " << sizeof(arr) << endl;

    MyArray<int> arr2(arr);
    // cout << "sizeof(arr2) = " << sizeof(arr2) << endl;

    MyArray<int> arr3(12);
    arr3 = arr;
    // cout << "sizeof(arr3) = " << sizeof(arr3) << endl;

    for (int i = 0; i < 5; i++)
    {
        arr.PushBack(i);
    }

    // PrintIntArray(arr);
    arr.ShowArr();

    cout << "arr2的容量大小:" << arr2.GetCapacity() << endl;
    cout << "arr2的数据量:" << arr2.GetSize() << endl;
    arr2 = arr;
    cout << "arr2的容量大小:" << arr2.GetCapacity() << endl;
    cout << "arr2的数据量:" << arr2.GetSize() << endl;
    arr2.PobBack();
    arr2.ShowArr();
    cout << "arr2的容量大小:" << arr2.GetCapacity() << endl;
    cout << "arr2的数据量:" << arr2.GetSize() << endl;
}

void Test02()
{
    MyArray<Person> arr(10);

    Person p1("张三", 12);
    Person p2("李四", 15);
    Person p3("王五", 12);
    Person p4("吴六", 15);
    Person p5("赵七", 12);
    Person p6("陈八", 15);

    arr.PushBack(p1);
    arr.PushBack(p2);
    arr.PushBack(p3);
    arr.PushBack(p4);
    arr.PushBack(p5);
    arr.PushBack(p6);

    arr.ShowArr();

    cout << "arr的容量为 : " << arr.GetCapacity() << endl;
    cout << "arr的大小为 : " << arr.GetSize() << endl;
}

int main()
{
    // Test01();
    Test02();

    system("pause");
    return 0;
}