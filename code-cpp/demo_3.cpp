/***
 * @Author: szf
 * @Date: 2022-12-13 01:56:03
 * @LastEditTime: 2022-12-13 11:03:05
 * @LastEditors: szf
 * @Description: 函数提高
 * @FilePath: \Study-Code\demo_3.cpp
 * @@WeChat:szf13373959031
 */

#include <iostream>
using namespace std;
// 函数的默认参数

// 如果传入数据则用自己的数据，如果没有，用默认值
// 如果某个位置有默认值，则这个位置向后，从左到右都必须有
// 如果函数声明有默认参数，则函数实现不能有 默认参数
int Func01(int a, int b = 10, int c = 10)
{
    return a + b + c;
}

// 占位参数
// 占位参数也可以有默认参数
void Func02(int a, int = 10)
{
    cout << "Func02" << endl;
}

// 函数重载
// 作用：函数名称相同，提高复用性
// 条件:
// 1.同一个作用域
// 2.函数名相同
// 3.函数参数类型不同，或顺序不同，或个数不同
// 4.函数返回值不同不可以做函数重载的条件
// 注意事项
// 1.引用作为重载的条件
// 2.函数重载与默认参数

void Func03(double a)
{
    cout << "Func03 double" << endl;
}

void Func03(int &a)
{
    cout << "Func03 int&" << endl;
}

void Func03(const int &a)
{
    cout << "Func03 const int&" << endl;
}

void Func03(int a,int b)//加默认参数会出现二义性，尽量不要出现默认参数
{
    cout << "Func03 int a,int b = 10" << endl;
}

int main()
{
    cout << Func01(10, 20) << endl;

    Func02(10);

    int a = 5;
    Func03(10.1);
    Func03(a);
    Func03(10);
    Func03(10,20);

    system("pause");
    return 0;
}
