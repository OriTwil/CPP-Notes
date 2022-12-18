/***
 * @Author: szf
 * @Date: 2022-12-17 19:22:13
 * @LastEditTime: 2022-12-17 19:24:06
 * @LastEditors: szf
 * @Description: employee
 * @FilePath: \Study-Code\demo_18_employee.h
 * @@WeChat:szf13373959031
 */
#pragma once

#include <iostream>
using namespace std;
#include "demo_18_worker.h"

class Employee : public Worker
{
public:
    Employee(int id, string name, int did);
    void ShowInfo();
    string GetDeptName();
};