/***
 * @Author: szf
 * @Date: 2022-12-14 15:11:12
 * @LastEditTime: 2022-12-14 15:19:42
 * @LastEditors: szf
 * @Description: 对象模型和this指针、const修饰成员函数
 * @FilePath: \Study-Code\demo_8.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
using namespace std;

// 对象模型
// 成员变量和成员函数分开存储
// 只有非静态成员变量是属于类的对象上

// this 指针
// 1.解决名称冲突
// 2.返回对象本身用*this

// 空指针调用成员函数

// 常函数

class Person
{
public:
    Person(int age) : m_age(age)
    {
        cout << this->m_age << endl;
    }

public:
    int m_age;

    mutable int m_id; // 特殊变量，即使在常函数里也能修改

    static int m_grade;

    void Func() {}

    static void Func2() {}

    Person &PersonAddAge(const Person &p)
    {
        // this指针的本质是指针常量，指针的指向是不能修改的
        this->m_age += p.m_age;
        return *this;
    }
    void shoWPersonAge()
    {
        // 判断是否为空指针，提高代码的健壮性
        if (this == NULL)
        {
            cout << "this = NULL" << endl;
            return;
        }
        cout << "age = " << this->m_age << endl;
    }

    void setAge(int age) const // 成员函数后加const，修饰的是this指向，让指针指向的值也不能修改
    {
        // this->m_age = age;//
    }

    void setId(int id) const
    {
        this->m_id = id;
    }
};

int Person::m_grade = 1;

void Test01()
{
    Person p1(18);
    // 空对象也有一个独一无二的1个字节，区分不同对象
    cout << "size of p = " << sizeof(p1) << endl;
}

void Test02()
{
    Person p1(18);
    cout << "p1的年龄为: " << p1.m_age << endl;

    Person p2(15);
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
    cout << "p2的年龄为: " << p2.m_age << endl;
}
void Test03()
{
    Person *p = NULL;
    p->shoWPersonAge();
}

void Test04()
{
    const Person p1(21); // 常对象
    //常对象只能调用常函数
    p1.setId(1);
    cout << p1.m_id << endl;
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
