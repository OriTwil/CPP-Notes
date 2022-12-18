/***
 * @Author: szf
 * @Date: 2022-12-14 23:25:53
 * @LastEditTime: 2022-12-15 01:33:27
 * @LastEditors: szf
 * @Description: person
 * @FilePath: \Study-Code\demo_10_person.h
 * @@WeChat:szf13373959031
 */
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person(int a, int b) : m_a(a), m_b(b){};

public:
    int m_a;

    int m_b;

public:
    Person operator+(const Person &p);

    Person operator+(int a);

    Person &operator++();

    Person operator++(int);

    Person &operator--();

    Person &operator=(const Person &p);

    bool operator==(Person &p);

public:
    void operator()(string test);
};

ostream &operator<<(ostream &cout, Person &p);
