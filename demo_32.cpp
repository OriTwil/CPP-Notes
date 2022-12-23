/***
 * @Author: szf
 * @Date: 2022-12-23 11:39:31
 * @LastEditTime: 2022-12-23 11:40:52
 * @LastEditors: szf
 * @Description: STL案例2——员工分组
 * @FilePath: \Study-Code\demo_32.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <list>
#include <set>
#include <ctime>
using namespace std;

class Worker
{
public:
    string m_name;
    int m_salary;
};

void CreateWorker(vector<Worker> &v)
{
    // string nameseed = "ABCDEF";
    for (int i = 0; i < 10; i++)
    {
        Worker worker;
        worker.m_name = "员工";
        worker.m_name.append("ABCDEFGHIJ", i, 1);
        worker.m_salary = rand() % 10001 + 10000;

        v.push_back(worker);
    }
}

void SetGroup(vector<Worker> &v, multimap<int, Worker> &m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        int depid = rand() % 3;
        m.insert(make_pair(depid, *it));
    }
}

void ShowWorkerByGroup(multimap<int, Worker> &m)
{
    cout << "策划部门 : " << endl;
    multimap<int, Worker>::iterator pos = m.find(0);
    int count = m.count(0);
    for (int index = 0; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名 : " << pos->second.m_name << " 工资 : " << pos->second.m_salary << endl;
    }

    cout << "------------------------------" << endl;
    cout << "美术部门 : " << endl;
    pos = m.find(1);
    count = m.count(1);
    for (int index = 0; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名 : " << pos->second.m_name << " 工资 : " << pos->second.m_salary << endl;
    }

    cout << "------------------------------" << endl;
    cout << "研发部门 : " << endl;
    pos = m.find(2);
    count = m.count(2);
    for (int index = 0; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名 : " << pos->second.m_name << " 工资 : " << pos->second.m_salary << endl;
    }
}


int main()
{
    srand((unsigned int)time(NULL));

    vector<Worker> worker;
    CreateWorker(worker);

    multimap<int, Worker> map;
    SetGroup(worker, map);

    ShowWorkerByGroup(map);
    // for (vector<Worker>::iterator it = worker.begin(); it != worker.end(); it++)
    // {
    //     cout << "姓名 : " << it->m_name << " 工资 : " << it->m_salary << endl;
    // }

    system("pause");
    return 0;
}