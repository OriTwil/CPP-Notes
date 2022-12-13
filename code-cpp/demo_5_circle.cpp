/*** 
 * @Author: szf
 * @Date: 2022-12-13 16:24:44
 * @LastEditTime: 2022-12-13 17:36:30
 * @LastEditors: szf
 * @Description: circle
 * @FilePath: \Study-Code\code-cpp\demo_5_circle.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
#include "demo_5_point.h"
#include "demo_5_circle.h"
using namespace std;

void Circle::setR(float r)//
{
    c_r = r;
}

float Circle::getR()
{
    return c_r;
}

void Circle::setCenter(float x,float y)
{
    c_center.Point::setPoint(x,y);
}

Point Circle::getCenter()
{
    return c_center;
}
