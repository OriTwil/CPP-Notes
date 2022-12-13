/*** 
 * @Author: szf
 * @Date: 2022-12-13 16:24:30
 * @LastEditTime: 2022-12-13 16:27:01
 * @LastEditors: szf
 * @Description: circle
 * @FilePath: \Study-Code\code-cpp\demo_5_circle.h
 * @@WeChat:szf13373959031
 */

#pragma once
#include <iostream>
#include "demo_5_point.h"
using namespace std;

class Circle
{
private:
    float c_r;

    Point c_center;

public:
    void setR(float r);

    float getR();

    void setCenter(float x,float y);

    Point getCenter();
};
