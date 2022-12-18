/***
 * @Author: szf
 * @Date: 2022-12-17 20:17:29
 * @LastEditTime: 2022-12-17 20:18:55
 * @LastEditors: szf
 * @Description: boss
 * @FilePath: \Study-Code\demo_18_boss.h
 * @@WeChat:szf13373959031
 */
#pragma once
#include <iostream>
#include <string>
#include "demo_18_worker.h"
using namespace std;

class Boss : public Worker
{
public:
    Boss(int id, string name, int did);

    virtual void ShowInfo();
    virtual string GetDeptName();
};
