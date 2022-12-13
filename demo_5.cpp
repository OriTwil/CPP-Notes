/***
 * @Author: szf
 * @Date: 2022-12-13 14:52:33
 * @LastEditTime: 2022-12-13 15:44:00
 * @LastEditors: szf
 * @Description: 类和对象——设计案例
 * @FilePath: \Study-Code\code-cpp\demo_5.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
#include <string>
extern "C"
{
#include "demo_5_point.h"
#include "demo_5_circle.h"
}

using namespace std;

void isInCircle(Point p, Circle c)
{
    float distance = (p.getPointX() - c.getCenter().getPointX()) * (p.getPointX() - c.getCenter().getPointX()) + (p.getPointY() - c.getCenter().getPointY()) * (p.getPointY() - c.getCenter().getPointY());

    if (distance == c.getR() * c.getR())
{
        cout << "is on the circle" << endl;
    }
    else if (distance > c.getR() * c.getR())
    {
        cout << "is out of the circle" << endl;
    }
    else if (distance < c.getR() * c.getR())
    {
        cout << "is in the circle" << endl;
    }
}
int main()
{
    Point p1;
    Circle c1;

    p1.setPoint(10,1);
    c1.setCenter(0,0);
    c1.setR(2);

    isInCircle(p1,c1);

    system("pause");
    return 0;
}