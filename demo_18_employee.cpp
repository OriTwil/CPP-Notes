/***
 * @Author: szf
 * @Date: 2022-12-17 19:27:20
 * @LastEditTime: 2022-12-17 19:34:08
 * @LastEditors: szf
 * @Description: employee
 * @FilePath: \Study-Code\demo_18_employee.cpp
 * @@WeChat:szf13373959031
 */
#include "demo_18_employee.h"
#include "demo_18_worker.h"

Employee::Employee(int id, string name, int did)
{
    this->m_id = id;
    this->m_name = name;
    this->m_deptid = did;
}

void Employee::ShowInfo()
{
    cout << "职工编号:" << this->m_id
         << "\t职工姓名:" << this->m_name
         << "\t岗位:" << this->GetDeptName()
         << "\t岗位职责:完成经理的任务" << endl;
}

string Employee::GetDeptName()
{
    return string("员工");
}