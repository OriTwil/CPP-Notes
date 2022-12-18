/***
 * @Author: szf
 * @Date: 2022-12-17 14:37:23
 * @LastEditTime: 2022-12-17 17:26:49
 * @LastEditors: szf
 * @Description: 职工管理系统
 * @FilePath: \Study-Code\demo_18.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
#include <string>
#include <fstream>
#include "demo_18_workmanager.h"
#include "demo_18_worker.h"
#include "demo_18_employee.h"
#include "demo_18_manager.h"
#include "demo_18_boss.h"
using namespace std;

void Test01()
{
    // 测试代码
    Worker *worker = NULL;
    worker = new Employee(1, "张三", 1);
    worker->ShowInfo();
    delete worker;

    cout << "\t---------------------------------------------" << endl;
    worker = new Manager(2, "张三", 2);
    worker->ShowInfo();
    delete worker;

    cout << "\t---------------------------------------------" << endl;
    worker = new Boss(3, "张三", 3);
    worker->ShowInfo();
    delete worker;
}

int main()
{
    // 实例化一个管理者
    WorkManager WorkManager;
    int choice;

    while (true)
    {
        WorkManager.ShowMenu();
        cin >> choice;

        switch (choice)
        {
        case 0:
            WorkManager.ExitSystem();
            // cout << "退出" << endl;
            break;
        case 1:
            WorkManager.AddEmp();
            // cout << "增加" << endl;
            break;
        case 2:
            // cout << "显示" << endl;
            WorkManager.ShowEmp();
            break;
        case 3:
        {
            // cout << "删除" << endl;
            WorkManager.DeleteEmp();
            break;
        }
        case 4:
            // cout << "修改" << endl;
            WorkManager.ModExp();
            break;
        case 5:
            // cout << "查找" << endl;
            WorkManager.FindEmp();
            break;
        case 6:
            // cout << "排序" << endl;
            WorkManager.SortEmp();
            break;
        case 7:
            // cout << "清空" << endl;
            WorkManager.CleanFile();
            break;
        default:
            // system("cls"); // 清屏
            cout << "输入错误" << endl;
            break;
        }
    }

    system("pause");
    return 0;
}
