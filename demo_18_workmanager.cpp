/***
 * @Author: szf
 * @Date: 2022-12-17 16:47:47
 * @LastEditTime: 2022-12-17 17:23:07
 * @LastEditors: szf
 * @Description: workmanager
 * @FilePath: \Study-Code\demo_18_workmanager.cpp
 * @@WeChat:szf13373959031
 */
#include "demo_18_workmanager.h"
#include "demo_18_employee.h"
#include "demo_18_manager.h"
#include "demo_18_boss.h"

WorkManager::WorkManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    // 文件不存在
    if (!ifs.is_open())
    {
        // cout << "文件不存在" << endl;
        this->m_empnum = 0;
        this->m_emparray = NULL;
        this->m_fileisempty = true;
        ifs.close();
        return;
    }
    // 文件存在但数据为空
    char ch;
    ifs >> ch;

    if (ifs.eof())
    {
        // cout << "文件为空" << endl;
        this->m_empnum = 0;
        this->m_emparray = NULL;
        this->m_fileisempty = true;
        ifs.close();
        return;
    }
    // 文件数据存在
    int num = this->GetEmpNum();
    // cout << "职工人数为" << num << endl;

    this->m_empnum = num;
    this->m_emparray = new Worker *[this->m_empnum];

    this->InitEmp();
}

WorkManager::~WorkManager()
{
    if (this->m_emparray != NULL)
    {
        delete[] this->m_emparray;
        this->m_emparray = NULL;
    }
}

void WorkManager::ShowMenu()
{
    cout << "                                 " << endl;
    cout << "       欢迎使用职工管理系统        " << endl;
    cout << "*            0.退出             *" << endl;
    cout << "*            1.增加             *" << endl;
    cout << "*            2.显示             *" << endl;
    cout << "*            3.删除             *" << endl;
    cout << "*            4.修改             *" << endl;
    cout << "*            5.查找             *" << endl;
    cout << "*            6.排序             *" << endl;
    cout << "*            7.清空             *" << endl;
    cout << "*                                " << endl;
    cout << "          请输入您的选择         " << endl;
    cout << endl;
}

void WorkManager::ExitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}

void WorkManager::AddEmp()
{
    cout << "请输入添加职工数量" << endl;
    int addnum = 0;
    cin >> addnum;

    if (addnum > 0)
    {
        // 计算添加新空间大小
        int newsize = m_empnum + addnum;
        // 开辟新空间
        Worker **newspace = new Worker *[newsize];
        // 拷贝原来数据
        if (this->m_emparray != NULL)
        {
            for (int i = 0; i < this->m_empnum; i++)
            {
                newspace[i] = this->m_emparray[i];
            }
        }
        // 添加新数据
        for (int i = 0; i < addnum; i++)
        {
            int id;
            string name;
            int did;

            cout << "请输入第 " << i + 1 << " 个新职工的id" << endl;
            cin >> id;

            int ret = this->IsExist(id);
            if (ret != -1)
            {
                cout << "id已经被占用,请重新输入" << endl
                     << endl;
                ;
                i--;
            }
            else
            {

                cout << "请输入第 " << i + 1 << " 个新职工的姓名" << endl;
                cin >> name;

                cout << "请输入第 " << i + 1 << " 个新职工的职位" << endl;
                cout << "1.普通职员" << endl
                     << "2.经理" << endl
                     << "3.老板" << endl;
                cin >> did;

                Worker *worker = NULL;
                switch (did)
                {
                case 1:
                    worker = new Employee(id, name, did);
                    break;
                case 2:
                    worker = new Manager(id, name, did);
                    break;
                case 3:
                    worker = new Boss(id, name, did);
                    break;
                default:
                    cout << "输入错误" << endl;
                    i--;
                    break;
                }

                newspace[this->m_empnum + i] = worker;
            }
        }

        delete[] this->m_emparray;
        this->m_emparray = newspace;
        this->m_empnum = newsize;

        this->SaveFile();

        this->m_fileisempty = false;
        // delete[] newspace;
        cout << "成功添加 " << addnum << " 名员工" << endl;
    }
    else
    {
        cout << "添加有误" << endl;
    }
}

void WorkManager::SaveFile()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < this->m_empnum; i++)
    {
        ofs << this->m_emparray[i]->m_id << " "
            << this->m_emparray[i]->m_name << " "
            << this->m_emparray[i]->m_deptid << endl;
    }

    ofs.close();
}

int WorkManager::GetEmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int did;

    int num = 0;

    while ((ifs >> id && ifs >> name && ifs >> did))
    {
        num++;
    }
    return num;
}

void WorkManager::InitEmp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int did;

    int index = 0;

    while (ifs >> id && ifs >> name && ifs >> did)
    {
        Worker *worker = NULL;

        if (did == 1)
        {
            worker = new Employee(id, name, did);
        }
        else if (did == 2)
        {
            worker = new Manager(id, name, did);
        }
        else
        {
            worker = new Boss(id, name, did);
        }

        this->m_emparray[index] = worker;
        index++;
    }
}

void WorkManager::ShowEmp()
{
    if (this->m_fileisempty)
    {
        cout << "文件不存在或文件为空" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_empnum; i++)
        {
            this->m_emparray[i]->ShowInfo();
            cout << "--------------------------------------------------------------------------------------------" << endl; // 利用多态调用程序接口
        }
    }
}

void WorkManager::DeleteEmp()
{
    if (this->m_fileisempty)
    {
        cout << "文件不存在或者为空" << endl;
    }
    else
    {
        cout << "请输入删除员工的id" << endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);
        if (index != -1)
        {
            for (int i = index; i < this->m_empnum - 1; i++)
            {
                this->m_emparray[i] = this->m_emparray[i + 1];
            }
            this->m_empnum--;

            this->SaveFile();
            cout << "删除成功" << endl;
        }
        else
        {
            cout << "员工不存在" << endl;
        }
    }
}

int WorkManager::IsExist(int id)
{
    int index = -1;

    for (int i = 0; i < this->m_empnum; i++)
    {
        if (this->m_emparray[i]->m_id == id)
        {
            index = i;
            break;
        }
    }

    return index;
}

void WorkManager::ModExp()
{
    if (this->m_fileisempty)
    {
        cout << "文件不存在" << endl;
    }
    else
    {
        cout << "请输入修改职工的id" << endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);
        if (ret != -1)
        {
            delete this->m_emparray[ret];

            int newid = 0;
            string newname = "";
            int newdid = 0;

            cout << "查询到第" << ret + 1 << "号职工";
            cout << "请输入新的id:" << endl;
            cin >> newid;
            cout << "请输入新的职工姓名" << endl;
            cin >> newname;
            cout << "请输入新的职工岗位" << endl;
            cout << "1.普通职员" << endl
                 << "2.经理" << endl
                 << "3.老板" << endl;
            cin >> newdid;

            Worker *worker = NULL;
            if (newdid == 1)
            {
                worker = new Employee(newid, newname, newdid);
            }
            else if (newdid == 2)
            {
                worker = new Manager(newid, newname, newdid);
            }
            else if (newdid == 3)
            {
                worker = new Boss(newid, newname, newdid);
            }
            else
            {
                cout << "输入职位错误" << endl;
            }

            this->m_emparray[ret] = worker;
            cout << "修改成功" << endl;

            this->SaveFile();
        }
        else
        {
            cout << "职工不存在,修改失败" << endl;
        }
    }
}

void WorkManager::FindEmp()
{
    if (this->m_fileisempty)
    {
        cout << "文件不存在或记录为空" << endl;
    }
    else
    {
        cout << "请输入查找方式" << endl;
        cout << "1.按照职工id查找" << endl
             << "2.按照职工姓名查找" << endl;
        int select = 0;
        cin >> select;

        if (select == 1)
        {
            int id;
            cout << "请输入查找编号：" << endl;
            cin >> id;

            int ret = this->IsExist(id);
            if (ret != -1)
            {
                cout << "查找成功!该职工信息如下:" << endl;
                this->m_emparray[ret]->ShowInfo();
            }
            else
            {
                cout << "查找失败!" << endl;
            }
        }
        else if (select == 2)
        {
            string name;
            cout << "请输入查找的姓名" << endl;
            cin >> name;
            bool flag = false;

            for (int i = 0; i < this->m_empnum; i++)
            {
                if (this->m_emparray[i]->m_name == name)
                {
                    cout << "查找成功!" << endl;
                    this->m_emparray[i]->ShowInfo();
                    flag = true;

                    break;
                }
            }
            if (flag == false)
            {
                cout << "查找失败,没有此职工" << endl;
            }
        }
        else
        {
            cout << "查找方式输入失败" << endl;
        }
    }
}

void WorkManager::SortEmp()
{
    if (this->m_fileisempty)
    {
        cout << "文件不存在或文件为空" << endl;
    }
    else
    {
        cout << "请选择排序方式：" << endl
             << "1.升序" << endl
             << "2.降序" << endl;

        int select = 0;
        cin >> select;

        if (select == 1)
        {
            for (int i = 0; i < this->m_empnum; i++)
            {
                for (int j = i + 1; j < this->m_empnum; j++)
                {
                    if (this->m_emparray[i]->m_id > this->m_emparray[j]->m_id)
                    {
                        Worker *index;
                        index = this->m_emparray[i];
                        this->m_emparray[i] = this->m_emparray[j];
                        this->m_emparray[j] = index;
                    }
                }
            }
            SaveFile();
            cout << "已按照id完成升序排序" << endl;
        }
        else if (select == 2)
        {
            for (int i = 0; i < this->m_empnum; i++)
            {
                for (int j = i + 1; j < this->m_empnum; j++)
                {
                    if (this->m_emparray[i]->m_id < this->m_emparray[j]->m_id)
                    {
                        Worker *index;
                        index = this->m_emparray[i];
                        this->m_emparray[i] = this->m_emparray[j];
                        this->m_emparray[j] = index;
                    }
                }
            }
            SaveFile();
            cout << "已按照id完成降序排序" << endl;
        }
        else
        {
            cout << "输入错误！" << endl;
        }
    }
}

void WorkManager::CleanFile()
{
    cout << "确定清空？" << endl;
    cout << "1. 确定" << endl
         << "2. 返回" << endl;
    int select = 0;
    cin >> select;

    if (select == 1)
    {
        ofstream ofs;
        ofs.open(FILENAME, ios::trunc);
        ofs.close();

        if (this->m_emparray != NULL)
        {
            for (int i = 0; i < this->m_empnum; i++)
            {
                delete this->m_emparray[i];
                this->m_emparray[i] = NULL;
            }

            delete[] this->m_emparray;
            this->m_emparray = NULL;
            this->m_empnum = 0;
            this->m_fileisempty = true;

            cout << "清除完毕" << endl;
        }
        else
        {
            cout << "文件为空或不存在" << endl;
        }
    }
    else if (select == 2)
    {
        return;
    }
    else
    {
        cout << "输入选择错误" << endl;
        return;
    }
}