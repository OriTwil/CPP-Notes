/***
 * @Author: szf
 * @Date: 2022-12-17 20:17:54
 * @LastEditTime: 2022-12-17 20:20:06
 * @LastEditors: szf
 * @Description: boss
 * @FilePath: \Study-Code\demo_18_boss.cpp
 * @@WeChat:szf13373959031
 */
#include "demo_18_boss.h"

Boss::Boss(int id, string name, int did)
{
    this->m_id = id;
    this->m_name = name;
    this->m_deptid = did;
}

void Boss::ShowInfo()
{
    cout << "职工编号:" << this->m_id
         << "\t职工性命:" << this->m_name
         << "\t岗位:" << this->GetDeptName()
         << "\t岗位职责:下发任务给经理,管理员工" << endl;
}

string Boss::GetDeptName()
{
    return string("老板");
}
