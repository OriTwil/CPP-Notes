/***
 * @Author: szf
 * @Date: 2022-12-17 10:48:14
 * @LastEditTime: 2022-12-17 12:36:59
 * @LastEditors: szf
 * @Description:demo_17
 * @FilePath: \Study-Code\demo_17.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// 文件操作

// 操作文件三大类:
//  ofstream、ifstream、fstream

// 写文件步骤
// 1.包含头文件
// 2.创建流对象
//  ofstream ofs;
// 打开文件
//  ofs.open("文件路径",打开方式);
// 写数据
//  ofs<<"写入的数据";
// 关闭文件
//  ofs.close();

// 文件打开方式
// ios::in读、ios::out写、ios::ate文件尾、ios::app追加、ios::binary二进制、ios::trunc先删除再创建

// 读文件本骤
//  1.包含头文件
//  2.创建流对象
//   ifstream ifs;
//  打开文件
//   ifs.open("文件路径",打开方式);
//  写数据
//   ifs<<"写入的数据";
//  关闭文件
//   ifs.close();

// 二进制文件
class Person
{
public:
    char m_name[64];
    int m_age;
};

// 写文件
void Test01()
{
    ofstream ofs;
    ofs.open("demo_17.txt", ios::out);
    ofs << "姓名:李四" << endl;
    ofs << "性别:男" << endl;
    ofs << "年龄:18" << endl;
    ofs.close();
}
// 读文件
void Test02()
{
    ifstream ifs;
    ifs.open("demo_17.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    // 第一种
    //  char buf[1024] = {0};
    //  while(ifs >> buf)
    //  {
    //      cout << buf << endl;
    //  }
    // 第二种
    char buf2[1024] = {0};
    while (ifs.getline(buf2, sizeof(buf2)))
    {
        cout << buf2 << endl;
    }
    // 第三种
    // string buf3;
    // while (getline(ifs, buf3))
    // {
    //     cout << buf3 << endl;
    // }
    // 第四种
    // char c;
    // while((c =ifs.get()) != EOF)
    // {
    //     cout << c;
    // }
    ifs.close();
}
// 二进制写文件
void Test03()
{
    ofstream ofs;
    // ofstream ofs("demo_17.txt", ios::out | ios::binary)
    ofs.open("demo_17.txt", ios::out | ios::binary);

    Person p = {"张三", 18};
    ofs.write((const char *)&p, sizeof(Person));
    ofs.close();
}
// 二进制读文件
void Test04()
{
    ifstream ifs;
    ifs.open("demo_17.txt", ios::in | ios::binary);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
    }
    Person p;
    ifs.read((char *)&p, sizeof(Person));
    cout << "姓名：" << p.m_name << endl;
    cout << "年龄：" << p.m_age << endl;
    ifs.close();
}
int main()
{
    Test01();
    Test02();
    // Test03();
    // Test04();

    system("pause");

    return 0;
}
