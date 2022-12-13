/***
 * @Author: szf
 * @Date: 2022-12-12 11:02:32
 * @LastEditTime: 2022-12-12 12:38:45
 * @LastEditors: szf
 * @Description: cpp学习 内存四区与new关键字
 * @FilePath: \Study-Code\demo_1.cpp
 * @@WeChat:szf13373959031
 */
#include <iostream>
using namespace std;

int global_a = 0;
int global_b = 0;

const int const_global_a = 0;
const int const_global_b = 0;

int *Func()
{
    int a_func = 10;
    return &a_func; // 错误示范
}
int *Func_2()
{
    // 利用new在堆区开辟数据
    int *a_func_2 = new int(10); // new关键字可以在堆区开辟内存，返回该数据类型的指针
    int *arr = new int[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 10;
        cout << arr[i] << endl;
    }
    delete[] arr; // 释放数组
    return a_func_2;
}
int main()
{

    /*
    全局变量、静态变量、字符串常量、全局常量都在全局区，在程序结束后系统释放
    */

    int a = 0;
    int b = 0;
    // 局部变量
    cout << "局部变量 a 的地址： " << (long long)&a << endl;
    cout << "局部变量 a 的地址： " << (long long)&a << endl;

    // 全局变量
    cout << "全局变量 global_a 的地址： " << (long long)&global_a << endl;
    cout << "全局变量 global_a 的地址： " << (long long)&global_b << endl;

    // 静态变量
    static int static_a = 0;
    static int static_b = 0;
    cout << "静态变量 static_a 的地址： " << (long long)&static_a << endl;
    cout << "静态变量 static_b 的地址： " << (long long)&static_b << endl;

    // 字符串变量
    cout << "字符串常量的地址是：" << (long long)&"hello world" << endl;

    // const 修饰的全局变量
    cout << "全局常量const_global_a 的地址是：" << (long long)&const_global_a << endl;
    cout << "全局常量const_global_b 的地址是：" << (long long)&const_global_b << endl;

    // const修饰的局部变量
    const int const_a = 0;
    const int const_b = 0;
    cout << "局部常量const_a 的地址是：" << (long long)&const_a << endl;
    cout << "局部常量const_b 的地址是：" << (long long)&const_b << endl;

    /*
    局部变量、形参放在栈区，不要返回局部变量的地址
    */

    int *p = Func();
    /*cout << "局部变量a_func 的值是： " << (long long)*p << endl;
    cout << "局部变量a_func 的值是： " << (long long)*p << endl;*/

    /*
    堆区的数据由程序员管理生死
    */
    int *p2 = Func_2(); // p2是指向堆区的地址
    cout << "局部变量a_func_2的值是: " << *p2 << endl;
    delete p2;
    cout << "局部变量a_func_2的值是: " << *p2 << endl;

    system("pause");
    return 0;
}