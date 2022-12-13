/*** 
 * @Author: szf
 * @Date: 2022-12-13 16:12:15
 * @LastEditTime: 2022-12-13 16:15:44
 * @LastEditors: szf
 * @Description: 分文件操作
 * @FilePath: \Study-Code\code-cpp\demo_5_point.h
 * @@WeChat:szf13373959031
 */
#pragma once
#include <iostream>
using namespace std;

class Point
{
private:
    float p_x;

    float p_y;

public:
    void setPoint(float x, float y);

    float getPointX();

    float getPointY();

protected:
};
