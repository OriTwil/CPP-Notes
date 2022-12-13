/***
 * @Author: szf
 * @Date: 2022-12-13 16:20:01
 * @LastEditTime: 2022-12-13 16:22:45
 * @LastEditors: szf
 * @Description: 分文件操作
 * @FilePath: \Study-Code\code-cpp\demo_5_point.cpp
 * @@WeChat:szf13373959031
 */

#include <iostream>
#include "demo_5_point.h"
#include "demo_5_circle.h"
using namespace std;

void Point::setPoint(float x, float y)
{
    p_x = x;
    p_y = y;
}

float Point::getPointX()
{
    return p_x;
}

float Point::getPointY()
{
    return p_y;
}
