/***
 * @Author: szf
 * @Date: 2022-12-21 01:54:42
 * @LastEditTime: 2022-12-21 13:37:52
 * @LastEditors: szf
 * @Description: string容器 了解即可,现用现查
 * @FilePath: \Study-Code\demo_23.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
#include <string>
using namespace std;

//* string容器
// string是一个类，类内部封装了char*
// string内封装了很多成员方法，如find,delete,replace...

//* string 构造函数：
// string()
// string(const char*s)
// string(const string& str)
// string(int n,char c)

//* string赋值
// string& operator=(const char*s);
// string& operator=(const string &s);
// string& operator=(char c);
// string& assign(cosnt char*s);
// string& assign(const char *s,int n);
// string& assign(const string &s);
// string& assign(int n,char c);

//* string拼接
// string& operator+=(const char* str)
// string& operator+=(const char c)
// string& operator+=(const string& str)
// string append(const char*s)
// string append(const char*s,int n)
// string append(const string &s)
// string append(const string &s,int pos,int n)

//* 查找与替换
// int find(const string& str, int pos = 0) const; //查找str第一次出现位置，从pos开始查找
// int find(const char* s, int pos = 0) const; //查找s第一次出现位置，从pos开始查找
// int find(const char* s, int pos, int n) const; //从pos位置查找s的前n个字符第一次位置
// int find(const char c, int pos = 0)const; //查找字符c第一次出现的位置
// rfind 是从右往左查找
// string& replace(int pos,int n,const string &str); //从pos开始n个字符换为str

//* 字符串比较
// int compare(const string &s) const;
// int compare(const char*s) const;
// >返回1 <返回-1 =返回0
// 主要为了比较字符串是否相等

//* 字符存取
// char&operator[](int n) //重载[]
// char& at(int n)

//* 插入与删除
// string& insert(int pos,const char* s);
// string& insert(int pos,const string& str);
// string& insert(int pos,int n,char c);
// string& erase(int pos,int n = npos);

//* string子串
// string substr(int pos = 0,int n = npos) const //返回由pos开始的n个字符组成的字符串

// 构造
void Test01()
{
    // 默认构造
    string s1;
    // 构造函数
    const char *str = "hello world";
    string s2(str);
    cout << "s2 = " << s2 << endl;
    // 拷贝构造
    string s3(s2);
    cout << "s3 = " << s3 << endl;
    // 构造
    string s4(10, 'a');
    cout << "s4 = " << s4 << endl;
}
// 赋值
void Test02()
{
    string str1;

    str1 = "hello world";
    cout << "str1 = " << str1 << endl;

    string str2 = str1;
    cout << "str2 = " << str2 << endl;

    string str3;
    str3 = 'a';
    cout << "str3 = " << str3 << endl;

    string str4;
    str4.assign("hello Cpp");
    cout << "str4 = " << str4 << endl;

    string str5;
    str5.assign("hello c++", 5);
    cout << "str5 = " << str5 << endl;

    string str6;
    str6.assign(str4);
    cout << "str6 = " << str6 << endl;

    string str7;
    str7.assign(10, 'w');
    cout << "str7 = " << str7 << endl;
}
// 字符串拼接
void Test03()
{
    string str1 = "我";
    str1 += "爱玩";
    cout << "str1 = " << str1 << endl;

    str1 += ":";
    cout << "str1 = " << str1 << endl;

    string str2 = "LOL";
    str1 += str2;
    cout << "str1 = " << str1 << endl;

    string str3 = "I";
    str3.append(" love");
    cout << "str3 = " << str3 << endl;

    str3.append("game: qascqsac", 6);
    cout << "str3 = " << str3 << endl;

    str3.append(str2);
    cout << "str3 = " << str3 << endl;

    str3.append(str2, 1, 2); // 从第二个开始,截取两位
    cout << "str3 = " << str3 << endl;
}

// 查找与替换
void Test04()
{
    string str1 = "abcdef";

    int pos = str1.find("def");

    if (pos == -1)
    {
        cout << "未找到字符串" << endl;
    }
    else
    {
        cout << "字符串位置为 : " << pos << endl;
    }

    str1.replace(1, 3, "1111");
    cout << "str1为 : " << str1 << endl;
}

void Test05()
{
    string str1 = "hello";

    for (int i = 0; i < str1.size(); i++)
    {
        cout << str1[i];
    }
    cout << endl;

    str1[0] = 'x';
    for (int i = 0; i < str1.size(); i++)
    {
        cout << str1.at(i);
    }
    cout << endl;
}

void Test06()
{
    string str1 = "hello";

    str1.insert(1, "111");
    cout << "str1 = " << str1 << endl;

    str1.erase(1, 3);
    cout << "str1 = " << str1 << endl;
}

void Test07()
{
    string email = "zhangsan@sina.com";

    int pos = email.find('@');

    string name = email.substr(0, pos);
    cout << "name is " << name << endl;
}

int main()
{
    // Test01();
    // Test02();
    // Test03();
    // Test04();
    // Test05();
    // Test06();
    Test07();

    system("pause");
    return 0;
}