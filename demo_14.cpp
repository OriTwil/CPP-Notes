/***
 * @Author: szf
 * @Date: 2022-12-16 21:37:22
 * @LastEditTime: 2022-12-16 21:41:07
 * @LastEditors: szf
 * @Description: 纯虚函数和抽象类
 * @FilePath: \Study-Code\demo_14.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
#include <string>
using namespace std;

// 纯虚函数和抽象类
// 只要有一个纯虚函数，这个类称为抽象类
// 抽象类特点：
// 1.无法实例化对象
// 2.抽象类的子类必须重写父类的纯虚函数，否则也是抽象类
class Base
{
public:
    // 纯虚函数
    virtual void Func() = 0;
};

class Son : public Base
{
public:
    void Func()
    {
        cout << "Son 中 Func 调用" << endl;
    }
};

void Test01()
{
    Base *base = new Son();
    base->Func();
}
int main()
{
    Test01();

    system("pause");
    return 0;
}
