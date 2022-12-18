/*** 
 * @Author: szf
 * @Date: 2022-12-17 20:04:18
 * @LastEditTime: 2022-12-17 20:16:26
 * @LastEditors: szf
 * @Description: manager
 * @FilePath: \Study-Code\demo_18_manager.h
 * @@WeChat:szf13373959031
 */
#pragma once
#include <iostream>
#include <string>
#include "demo_18_worker.h"
using namespace std;

class Manager:public Worker
{
public:
    Manager(int id,string name,int did);
    
    virtual void ShowInfo();
    virtual string GetDeptName();
};
