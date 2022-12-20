/*** 
 * @Author: szf
 * @Date: 2022-12-21 01:54:42
 * @LastEditTime: 2022-12-21 02:15:16
 * @LastEditors: szf
 * @Description: string容器
 * @FilePath: \Study-Code\demo_23.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
#include <string>
using namespace std;

// string是一个类，类内部封装了char*
// string内封装了很多成员方法，如find,delete,replace...
// string 构造函数：
// string()
// string(const char*s)
// string(const string& str)
// string(int n,char c)

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

int main()
{
    Test01();

    system("pause");
    return 0;
}