/***
 * @Author: szf
 * @Date: 2022-12-17 20:03:26
 * @LastEditTime: 2022-12-18 20:56:16
 * @LastEditors: szf
 * @Descriptio:manager
 * @FilePath: \Study-Code\demo_18_manager.cpp
 * @@WeChat:szf13373959031
 */
#include "demo_18_manager.h"

Manager::Manager(int id, string name, int did)
{
    this->m_id = id;
    this->m_name = name;
    this->m_deptid = did;
}

void Manager::ShowInfo()
{
    cout << "职工编号:" << this->m_id
         << "\t职工性命:" << this->m_name
         << "\t岗位:" << this->GetDeptName()
         << "\t岗位职责:完成老板完成的任务,并下发任务给员工" << endl;
}

string Manager::GetDeptName()
{
    return string("经理");
}