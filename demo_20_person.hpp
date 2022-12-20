/***
 * @Author: szf
 * @Date: 2022-12-20 14:03:46
 * @LastEditTime: 2022-12-20 14:03:52
 * @LastEditors: szf
 * @Description:Person
 * @FilePath: \Study-Code\demo_20_person.hpp
 * @@WeChat:szf13373959031
 */

//  类模板

// 类模板分文件编写
// 类模板中成员函数在调用时才创建，故不可直接包含.h
// 解决方法1：直接包含.cpp文件（无意义）
// 解决方法2: 将.h和.cpp合并为.hpp文件
#pragma once
#include <iostream>
using namespace std;

// 类模板与友元
template <class AgeType, class HeightType, class NameType, class PetType, class WifeType> //->模板参数列表
class Person;

template <class AgeType, class HeightType, class NameType, class PetType, class WifeType> //->模板参数列表
void ShowFriend(Person<AgeType, HeightType, NameType, PetType, WifeType> &p)
{
    cout << "妻子是：" << p.m_wife << endl;
    cout << "友元函数调用" << endl;
}

template <class AgeType, class HeightType, class NameType, class PetType, class WifeType = string> //->模板参数列表
class Person
{

    // 类外实现
    friend void ShowFriend<>(Person<AgeType, HeightType, NameType, PetType, WifeType> &p); // 加空模板参数列表
    // 类内实现
    friend void ShowFriend2(Person<AgeType, HeightType, NameType, PetType, WifeType> &p)
    {
        cout << "妻子是：" << p.m_wife << endl;
        cout << "友元函数类内实现" << endl;
    }

public:
    Person(AgeType age, HeightType height, NameType name, PetType pet, WifeType wife) : m_age(age), m_height(height), m_name(name), m_pet(pet), m_wife(wife) {}

    void ShowPerson();

    void ShowCat();

    void ShowDog();

public:
    AgeType m_age;
    HeightType m_height;
    NameType m_name;
    PetType m_pet;

private:
    string m_wife;
};

template <class AgeType, class HeightType, class NameType, class PetType, class WifeType> //->模板参数列表
void Person<AgeType, HeightType, NameType, PetType, WifeType>::ShowPerson()
{
    cout << "name = " << this->m_name << endl;
    cout << "age = " << this->m_age << endl;
    cout << "height = " << this->m_height << endl;
}

template <class AgeType, class HeightType, class NameType, class PetType, class WifeType> //->模板参数列表
void Person<AgeType, HeightType, NameType, PetType, WifeType>::ShowCat()
{
    m_pet.ShowCat();
}

template <class AgeType, class HeightType, class NameType, class PetType, class WifeType> //->模板参数列表
void Person<AgeType, HeightType, NameType, PetType, WifeType>::ShowDog()
{
    m_pet.ShowDog();
}