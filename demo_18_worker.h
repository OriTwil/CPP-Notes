/***
 * @Author: szf
 * @Date: 2022-12-17 19:17:13
 * @LastEditTime: 2022-12-17 19:18:53
 * @LastEditors: szf
 * @Description: worker
 * @FilePath: \Study-Code\demo_18_worker.h
 * @@WeChat:szf13373959031
 */
#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Worker
{
public:
    int m_id;
    string m_name;
    int m_deptid;

public:
    virtual void ShowInfo() = 0;
    virtual string GetDeptName() = 0;
};