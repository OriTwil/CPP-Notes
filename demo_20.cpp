/***
 * @Author: szf
 * @Date: 2022-12-20 06:57:31
 * @LastEditTime: 2022-12-20 07:00:01
 * @LastEditors: szf
 * @Description: 类模板
 * @FilePath: \Study-Code\demo_20.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
#include <string>
#include "demo_20_person.hpp"
using namespace std;

// 类模板与函数模板区别
// 1.类模板没有自动类型推导的使用方式
// 2.类模板在模板的参数列表中可以有默认参数

// 类模板中成员函数的创建时机
// 类模板中成员函数在调用时才创建

// 类模板对象做函数参数
// 1.指定传入类型
// 2.参数模板化
// 3.整个类模板化

//? 类模板与继承
// 1.当子类继承的父类是类模板时，子类在声明时要指定父类中T的类型
// 2.如果子类想要灵活继承,必须也写为类模板

// 类模板成员函数的类外实现

class Cat
{
public:
    void ShowCat();
};

void Cat::ShowCat()
{
    cout << "Show Cat" << endl;
}

class Dog
{
public:
    void ShowDog();
};

void Dog::ShowDog()
{
    cout << "Show Dog" << endl;
}
// class Son : public Person<int, float, string, Dog>
// {
// public:
//     Son();
// };
// template <class AgeType, class HeightType, class NameType, class PetType,class WorkType>
// class Daughter : public Person<AgeType, HeightType, NameType, PetType>
// {
// public:
//     // Daughter(AgeType age, HeightType height, NameType name, PetType pet,WorkType work) : m_age(age), m_height(height), m_name(name), m_pet(pet), m_homework(work){}
//     Daughter()
//     {
//         cout << "daughter 构造函数" << endl;
//     }
// public:
//     WorkType m_homework;

//     void ShowHomework()
//     {
//         cout<< "Homework is " << m_homework << endl;
//     }
// };

// 1.指定传入类型
void Test02(Person<int, float, string, Cat> &p)
{
    p.ShowPerson();
}
// 2.参数模板化
template <class AgeType, class HeightType, class NameType, class PetType>
void Test03(Person<AgeType, HeightType, NameType, PetType> &p)
{
    p.ShowPerson();
    cout << "PetType的类型:" << typeid(PetType).name() << endl;
    cout << "NameType的类型:" << typeid(NameType).name() << endl;
}
// 3.整个类模板化
template <class ClassType>
void Test04(ClassType &p)
{
    p.ShowPerson();
    cout << "ClassType的类型" << typeid(ClassType).name() << endl;
}

void Test01()
{
    Cat cat;
    Person<int, float, string, Cat> p1(18, 180.2, "Tom", cat, "lili");
    // p1.ShowPerson();
    Test02(p1);
    p1.ShowCat();
    cout << endl;

    Dog dog;
    Person<int, float, string, Dog> p2(19, 175.2, "Jack", dog, "marry");
    // p2.ShowPerson();
    // Test03(p2);
    Test04(p2);
    p2.ShowDog();
}

void Test05()
{
    // Cat c;
    // // Daughter<int,float,string,Cat,string> d1(1,60,"ice",c,"zuoye");
    // Daughter<int,float,string,Cat,string> d1;
    // d1.ShowPerson();
    // d1.ShowCat();
    // d1.ShowHomework();
    // Dog d;
    // Son s1;
}


void Test06()
{
    Dog dog;
    Person<int, float, string, Dog> p2(19, 175.2, "Jack", dog, "marry");
    ShowFriend(p2);
    ShowFriend2(p2);
}

int main()
{
    // Test01();
    // Test05();
    Test06();

    system("pause");
    return 0;
}
