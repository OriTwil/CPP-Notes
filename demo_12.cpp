/***
 * @Author: szf
 * @Date: 2022-12-15 04:22:34
 * @LastEditTime: 2022-12-15 12:10:45
 * @LastEditors: szf
 * @Description: 多态
 * @FilePath: \Study-Code\demo_12.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
using namespace std;

// 静态多态：函数重载、运算符重载，复用函数名
// 动态多态：派生类和虚函数实现运行时多态

// 静态多态的函数地址早绑定，编译阶段确定函数地址
// 动态多态的函数地址晚绑定，运行阶段确定函数地址

// 动态多态满足条件
// 1.有继承多态
// 2.子类要重写父类的虚函数（函数返回值、名称、参数列表 完全相同）
// 3.父类的指针或者引用指向子类对象

/*
vfptr 虚函数（表）指针，指向一个虚函数表（vftable）,
表内部会记录虚函数地址，当子类重写虚函数时，内部虚函数表中的虚函数地址
会替换为子函数的虚函数地址
*/

// 虚析构与纯虚析构
// 父类指针在析构时，不会调用子类的虚构函数，
// 导致子类如果有堆区属性，会出现内存泄露
// 纯虚析构需要声明也需要实现

class Animal
{
public:
    Animal()
    {
        cout << "Animal 构造函数" << endl;
    }
    // virtual ~Animal()
    // {
    //     cout << "Animal 析构函数" << endl;
    // }
    virtual ~Animal() = 0;


public:
    virtual void Speak() // 虚函数
    {
        cout << "动物在说话" << endl;
    }
};

Animal::~Animal()
{
    cout << "Animal 纯虚析构" << endl;
}

class Cat : public Animal
{
public:
    Cat(string name)
    {
        m_name = new string(name);
        cout << "Cat 构造函数" << endl;
    }
    ~Cat()
    {
        if (m_name != NULL)
        {
            delete m_name;
            m_name = NULL;
        }
        cout << "Cat 析构函数" << endl;
    }

public:
    void Speak()
    {
        cout << *m_name << "小猫在说话" << endl;
    }

public:
    string *m_name;
};

class Dog : public Animal
{
public:
    void Speak()
    {
        cout << "小狗在说话" << endl;
    }
};

void doSpeak(Animal &animal) // 地址早绑定，在编译阶段确定函数地址
{
    animal.Speak();
}

void Test01()
{
    Cat cat("Tom");
    doSpeak(cat);
    Dog dog;
    doSpeak(dog);
}

void Test02()
{
    cout << "size of Animal = " << sizeof(Animal) << endl;
    cout << "size of int* = " << sizeof(int *) << endl;
}
void Test03()
{
    Animal *animal = new Cat("Tom");
    animal->Speak();
    delete animal;
}

int main()
{
    // Test01();
    // Test02();
    Test03();

    system("pause");
    return 0;
}
