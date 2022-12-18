/***
 * @Author: szf
 * @Date: 2022-12-16 21:51:40
 * @LastEditTime: 2022-12-17 08:49:36
 * @LastEditors: szf
 * @Description: 多态——案例2——制作饮品
 * @FilePath: \Study-Code\demo_15.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
#include <string>
using namespace std;

class AbstructDrinking
{
public:
    virtual void Boil() = 0;

    virtual void Brew() = 0;

    virtual void PourInCup() = 0;

    virtual void AddSomething() = 0;

public:
    void MakeDrink()
    {
        Boil();
        Brew();
        PourInCup();
        AddSomething();
    }
};

class Coffee : public AbstructDrinking
{
public:
    void Boil()
    {
        cout << "烧开水" << endl;
    }
    void Brew()
    {
        cout << "冲泡雀巢咖啡" << endl;
    }
    void PourInCup()
    {
        cout << "倒入杯中" << endl;
    }
    void AddSomething()
    {
        cout << "加糖和牛奶" << endl;
    }
};

class Tea : public AbstructDrinking
{
public:
    void Boil()
    {
        cout << "烧开农夫山泉" << endl;
    }
    void Brew()
    {
        cout << "冲泡金骏眉" << endl;
    }
    void PourInCup()
    {
        cout << "倒入茶杯中" << endl;
    }
    void AddSomething()
    {
        cout << "加辅料" << endl;
    }
};

void DoWork(AbstructDrinking *drinking)
{
    drinking->MakeDrink();
}

void Test01()
{
    DoWork(new Coffee());
}

void Test02()
{
    DoWork(new Tea());
}

int main()
{
    // Test01();
    Test02();

    system("pause");
    return 0;
}