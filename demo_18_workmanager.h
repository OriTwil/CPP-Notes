/***
 * @Author: szf
 * @Date: 2022-12-17 16:46:06
 * @LastEditTime: 2022-12-17 16:49:19
 * @LastEditors: szf
 * @Description: workmanager
 * @FilePath: \Study-Code\demo_18_workmanager.h
 * @@WeChat:szf13373959031
 */
#pragma once
#include <iostream>
#include <fstream>
#include "demo_18_worker.h"
#define FILENAME "D:/code/Study-Code/demo_18.txt"

using namespace std;

class WorkManager
{
public:
    WorkManager();

    ~WorkManager();

    void ShowMenu();

    void ExitSystem();

    void AddEmp();

    void SaveFile();

    int GetEmpNum();

    void InitEmp();

    void ShowEmp();

    void DeleteEmp();

    int IsExist(int id);

    void ModExp();

    void FindEmp();

    void SortEmp();

    void CleanFile();

public:
    int m_empnum;
    Worker **m_emparray;
    bool m_fileisempty;
};
