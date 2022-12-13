/***
 * @Author: szf
 * @Date: 2022-12-13 22:51:53
 * @LastEditTime: 2022-12-13 23:29:33
 * @LastEditors: szf
 * @Description: 对象的初始化和清理
 * @FilePath: \Study-Code\note\demo_6.cpp
 * @@WeChat:szf13373959031
 */

#include <iostream>
using namespace std;

class Person
{
private:

public:
    // 1.构造函数 进行初始化操作
    // 没有返回值，也没有void
    // 函数名与类名相同
    // 可以有参数，可以重载
    // 创建对象时自动调用构造函数一次
    // 分类：无参（默认）与有参、普通与拷贝
    // 编译器默认有无参、有参、拷贝，
    // 如果自己写了有参构造函数，则编译器不再提供默认构造函数
    // 如果自己写拷贝，则编译器不提供构造函数了
    int m_age;
    int *m_height;

    Person()
    {
        cout << "invocation of parameterless constructor " << endl;
    }
    Person(int age)
    {
        m_age = age;
        cout << "invocation of parametric constructor " << endl;
    }
    Person(int age, int height)
    {
        m_age = age;
        m_height = new int(height);
        cout << "invocation of parametric constructor " << endl;
    }
    // 拷贝函数调用时机
    // 1.用一个创建完毕的对像初始化一个新对象
    // 2.值传递的方式给函数参数传值
    // 3.以值方式返回对象

    Person(const Person &p) // 注意：不要利用拷贝构造函数创建匿名对象
    {
        m_age = p.m_age;
        // m_height = p.m_height;//浅拷贝
        m_height = new int(*p.m_height);
        cout << "invocation of copy constructor " << endl;
    }

    void showAge()
    {
        cout << "age is " << m_age << endl;
    }

    void showHeight()
    {
        cout << "height is " << *m_height << endl;
    }

    // 析构函数 清理操作
    // 没有返回值
    // 函数名与类相同，加~
    // 无参数，无法重载
    // 销毁对象时自动调用函数一次
    ~Person()
    {
        //浅拷贝会导致内存重复释放
        if(m_height != NULL)
        {
            // delete m_height;
            m_height = NULL;
        }
        cout << "invocation of destructor" << endl;
    }
};
// 调用函数
void Test01()
{
    // 1.括号法
    Person p1;          // 无参,默认构造函数的调用不要加（）
    Person p2(10); // 有参
    Person p3(p2);      // 拷贝
    p3.showAge();

    // 2.显式法
    Person p4 = Person(20, 180);
    Person p5 = Person(p4);
    p5.showAge();
    p5.showHeight();

    // 3.隐式转换法
    Person p6 = 30;
    p6.showAge();

    Person(30, 180); // 匿名对象，当前行执行结束后结束对象
}

void Test02(Person p) // 2.值传递的方式给函数参数传值
{
}

Person Test03()
{
    Person p1;

    cout << (long long)&p1 << endl;
    return p1; // 3.以值方式返回对象
}

void Test04()
{
    Person p = Test03();

    cout << (long long)&p << endl;
}

int main()
{
    Test01();

    system("pause");
    return 0;
}
