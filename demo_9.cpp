/***
 * @Author: szf
 * @Date: 2022-12-14 16:31:24
 * @LastEditTime: 2022-12-14 16:32:50
 * @LastEditors: szf
 * @Description: 友元
 * @FilePath: \Study-Code\demo_9.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
#include <string>
using namespace std;

class Building;

class GoodGay
{
public:
    GoodGay();

public:
    void visit();

    Building *building;
};

class Building
{
    friend void goodGay(Building *building); // 全局函数作友元

    friend class GoodGay; // 友元类

    friend void GoodGay::visit(); // 成员函数作友元

public:
    Building() : m_Bedroom("卧室"), m_SittingRoom("客厅") {}

public:
    string m_SittingRoom;

private:
    string m_Bedroom;
};

GoodGay::GoodGay()
{
    building = new Building;
}

void GoodGay::visit()
{
    cout << "goodgay 正在访问" << building->m_SittingRoom << "、" << building->m_Bedroom << endl;
}

void goodGay(Building *building)
{
    cout << "goodGay正在访问" << building->m_SittingRoom << "、" << building->m_Bedroom << endl;
}

void Test01()
{
    Building building;
    goodGay(&building);
}

void Test02()
{
    GoodGay gg;
    gg.visit();
}

int main()
{
    // Test01();
    Test02();

    system("pause");
    return 0;
}
